/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Common.h"
#include "GuildMgr.h"

GuildMgr::GuildMgr() : NextGuildId(1)
{ }

GuildMgr::~GuildMgr()
{
    for (GuildContainer::iterator itr = GuildStore.begin(); itr != GuildStore.end(); ++itr)
        delete itr->second;
}

void GuildMgr::AddGuild(Guild* guild)
{
    GuildStore[guild->GetId()] = guild;
}

void GuildMgr::RemoveGuild(uint32 guildId)
{
    GuildStore.erase(guildId);
}

void GuildMgr::SaveGuilds()
{
    for (GuildContainer::iterator itr = GuildStore.begin(); itr != GuildStore.end(); ++itr)
        itr->second->SaveToDB();
}

uint32 GuildMgr::GenerateGuildId()
{
    if (NextGuildId >= 0xFFFFFFFE)
    {
        sLog->outError(LOG_FILTER_GUILD, "Guild ids overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return NextGuildId++;
}

// Guild collection
Guild* GuildMgr::GetGuildById(uint32 guildId) const
{
    GuildContainer::const_iterator itr = GuildStore.find(guildId);
    if (itr != GuildStore.end())
        return itr->second;

    return NULL;
}

Guild* GuildMgr::GetGuildByGuid(uint64 guid) const
{
    // Full guids are only used when receiving/sending data to client
    // everywhere else guild id is used
    if (IS_GUILD_GUID(guid))
        if (uint32 guildId = GUID_LOPART(guid))
            return GetGuildById(guildId);

    return NULL;
}

Guild* GuildMgr::GetGuildByName(const std::string& guildName) const
{
    std::string search = guildName;
    std::transform(search.begin(), search.end(), search.begin(), ::toupper);
    for (GuildContainer::const_iterator itr = GuildStore.begin(); itr != GuildStore.end(); ++itr)
    {
        std::string gname = itr->second->GetName();
        std::transform(gname.begin(), gname.end(), gname.begin(), ::toupper);
        if (search == gname)
            return itr->second;
    }
    return NULL;
}

std::string GuildMgr::GetGuildNameById(uint32 guildId) const
{
    if (Guild* guild = GetGuildById(guildId))
        return guild->GetName();

    return "";
}

Guild* GuildMgr::GetGuildByLeader(uint64 guid) const
{
    for (GuildContainer::const_iterator itr = GuildStore.begin(); itr != GuildStore.end(); ++itr)
        if (itr->second->GetLeaderGUID() == guid)
            return itr->second;

    return NULL;
}

uint32 GuildMgr::GetXPForGuildLevel(uint8 level) const
{
    if (level < GuildXPperLevel.size())
        return GuildXPperLevel[level];
    return 0;
}

void GuildMgr::LoadGuilds()
{
    // 1. Load all guilds
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading guilds definitions...");
    {
        uint32 oldMSTime = getMSTime();

                                                     //          0          1       2             3              4              5              6
        QueryResult result = CharacterDatabase.Query("SELECT g.guildid, g.name, g.leaderguid, g.EmblemStyle, g.EmblemColor, g.BorderStyle, g.BorderColor, "
                                                     //   7                  8       9       10            11          12        13                14                 15
                                                     "g.BackgroundColor, g.info, g.motd, g.createdate, g.BankMoney, g.level, g.experience, g.todayExperience, COUNT(gbt.guildid), "
                                                     //      16                 17                18
                                                     "g.DungeonChallenge, g.RaidChallenge, g.RatedBGChallenge "
                                                     "FROM guild g LEFT JOIN guild_bank_tab gbt ON g.guildid = gbt.guildid GROUP BY g.guildid ORDER BY g.guildid ASC");

        if (!result)
        {
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild definitions. DB table `guild` is empty.");
            return;
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                Guild* guild = new Guild();

                if (!guild->LoadFromDB(fields))
                {
                    delete guild;
                    continue;
                }

                AddGuild(guild);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 2. Load all guild ranks
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading guild ranks...");
    {
        uint32 oldMSTime = getMSTime();

        // Delete orphaned guild rank entries before loading the valid ones
        CharacterDatabase.DirectExecute("DELETE gr FROM guild_rank gr LEFT JOIN guild g ON gr.guildId = g.guildId WHERE g.guildId IS NULL");

        //                                                         0    1      2       3                4
        QueryResult result = CharacterDatabase.Query("SELECT guildid, rid, rname, rights, BankMoneyPerDay FROM guild_rank ORDER BY guildid ASC, rid ASC");

        if (!result)
        {
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild ranks. DB table `guild_rank` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadRankFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild ranks in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 3. Load all guild members
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading guild members...");
    {
        uint32 oldMSTime = getMSTime();

        // Delete orphaned guild member entries before loading the valid ones
        CharacterDatabase.DirectExecute("DELETE gm FROM guild_member gm LEFT JOIN guild g ON gm.guildId = g.guildId WHERE g.guildId IS NULL");
        CharacterDatabase.DirectExecute("DELETE gm FROM guild_member_withdraw gm LEFT JOIN guild_member g ON gm.guid = g.guid WHERE g.guid IS NULL");

                                                //           0           1        2     3      4        5       6       7       8       9       10
        QueryResult result = CharacterDatabase.Query("SELECT gm.guildid, gm.guid, rank, pnote, offnote, w.tab0, w.tab1, w.tab2, w.tab3, w.tab4, w.tab5, "
                                                //    11      12      13       14      15       16       17      18         19					20
                                                     "w.tab6, w.tab7, w.money, c.name, c.level, c.class, c.zone, c.account, c.logout_time, gm.activity, "
                                                //		21                   22                23            24					25
                                                     "gm.weekActivity, c.achievementPoint, r.standing, gm.weekReputation, gm.profession1_level, "
                                                //			26						27						28						29					30
                                                     "gm.profession1_skillID, gm.profession1_rank, gm.profession2_level, gm.profession2_skillID, gm.profession2_rank "
                                                     "FROM guild_member gm "
                                                     "LEFT JOIN guild_member_withdraw w ON gm.guid = w.guid "
                                                     "LEFT JOIN character_reputation r ON gm.guid = r.guid AND r.faction = 1168 "
                                                     "LEFT JOIN characters c ON c.guid = gm.guid ORDER BY gm.guildid ASC");

        if (!result)
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild members. DB table `guild_member` is empty.");
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadMemberFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild members int %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 4. Load all guild bank tab rights
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading bank tab rights...");
    {
        uint32 oldMSTime = getMSTime();

        // Delete orphaned guild bank right entries before loading the valid ones
        CharacterDatabase.DirectExecute("DELETE gbr FROM guild_bank_right gbr LEFT JOIN guild g ON gbr.guildId = g.guildId WHERE g.guildId IS NULL");

                                                     //      0        1      2    3        4
        QueryResult result = CharacterDatabase.Query("SELECT guildid, TabId, rid, gbright, SlotPerDay FROM guild_bank_right ORDER BY guildid ASC, TabId ASC");

        if (!result)
        {
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild bank tab rights. DB table `guild_bank_right` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadBankRightFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u bank tab rights in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 5. Load all event logs
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading guild event logs...");
    {
        uint32 oldMSTime = getMSTime();

        CharacterDatabase.DirectPExecute("DELETE FROM guild_eventlog WHERE LogGuid > %u", sWorld->getIntConfig(CONFIG_GUILD_EVENT_LOG_COUNT));

                                                     //          0        1        2          3            4            5        6
        QueryResult result = CharacterDatabase.Query("SELECT guildid, LogGuid, EventType, PlayerGuid1, PlayerGuid2, NewRank, TimeStamp FROM guild_eventlog ORDER BY TimeStamp DESC, LogGuid DESC");

        if (!result)
        {
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild event logs. DB table `guild_eventlog` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadEventLogFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild event logs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 6. Load all bank event logs
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading guild bank event logs...");
    {
        uint32 oldMSTime = getMSTime();

        // Remove log entries that exceed the number of allowed entries per guild
        CharacterDatabase.DirectPExecute("DELETE FROM guild_bank_eventlog WHERE LogGuid > %u", sWorld->getIntConfig(CONFIG_GUILD_BANK_EVENT_LOG_COUNT));

                                                     //          0        1      2        3          4           5            6               7          8
        QueryResult result = CharacterDatabase.Query("SELECT guildid, TabId, LogGuid, EventType, PlayerGuid, ItemOrMoney, ItemStackCount, DestTabId, TimeStamp FROM guild_bank_eventlog ORDER BY TimeStamp DESC, LogGuid DESC");

        if (!result)
        {
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild bank event logs. DB table `guild_bank_eventlog` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadBankEventLogFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild bank event logs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 7. Load all news event logs
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading Guild News...");
    {
        uint32 oldMSTime = getMSTime();

        CharacterDatabase.DirectPExecute("DELETE FROM guild_newslog WHERE LogGuid > %u", sWorld->getIntConfig(CONFIG_GUILD_NEWS_LOG_COUNT));

                                                     //      0        1        2          3           4      5      6
        QueryResult result = CharacterDatabase.Query("SELECT guildid, LogGuid, EventType, PlayerGuid, Flags, Value, Timestamp FROM guild_newslog ORDER BY TimeStamp DESC, LogGuid DESC");

        if (!result)
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild event logs. DB table `guild_newslog` is empty.");
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadGuildNewsLogFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild new logs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }


    // 8. Load all guild bank tabs
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading guild bank tabs...");
    {
        uint32 oldMSTime = getMSTime();

        // Delete orphaned guild bank tab entries before loading the valid ones
        CharacterDatabase.DirectExecute("DELETE gbt FROM guild_bank_tab gbt LEFT JOIN guild g ON gbt.guildId = g.guildId WHERE g.guildId IS NULL");

                                                     //         0        1      2        3        4
        QueryResult result = CharacterDatabase.Query("SELECT guildid, TabId, TabName, TabIcon, TabText FROM guild_bank_tab ORDER BY guildid ASC, TabId ASC");

        if (!result)
        {
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild bank tabs. DB table `guild_bank_tab` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadBankTabFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild bank tabs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 9. Fill all guild bank tabs
    sLog->outInfo(LOG_FILTER_GUILD, "Filling bank tabs with items...");
    {
        uint32 oldMSTime = getMSTime();

        // Delete orphan guild bank items
        CharacterDatabase.DirectExecute("DELETE gbi FROM guild_bank_item gbi LEFT JOIN guild g ON gbi.guildId = g.guildId WHERE g.guildId IS NULL");

                                                     //          0            1                2      3         4        5      6             7                 8           9           10
        QueryResult result = CharacterDatabase.Query("SELECT creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, "
                                                     //   11       12     13      14         15
                                                     "guildid, TabId, SlotId, item_guid, itemEntry FROM guild_bank_item gbi INNER JOIN item_instance ii ON gbi.item_guid = ii.guid");

        if (!result)
        {
            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild bank tab items. DB table `guild_bank_item` or `item_instance` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[11].GetUInt32();

                if (Guild* guild = GetGuildById(guildId))
                    guild->LoadBankItemFromDB(fields);

                ++count;
            }
            while (result->NextRow());

            sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild bank tab items in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // 10. Load guild achievements
    {
        PreparedQueryResult achievementResult;
        PreparedQueryResult criteriaResult;
        for (GuildContainer::const_iterator itr = GuildStore.begin(); itr != GuildStore.end(); ++itr)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_ACHIEVEMENT);
            stmt->setUInt32(0, itr->first);
            achievementResult = CharacterDatabase.Query(stmt);
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_ACHIEVEMENT_CRITERIA);
            stmt->setUInt32(0, itr->first);
            criteriaResult = CharacterDatabase.Query(stmt);

            itr->second->GetAchievementMgr().LoadFromDB(achievementResult, criteriaResult);
        }
    }

    // 11. Validate loaded guild data
    sLog->outInfo(LOG_FILTER_GENERAL, "Validating data of loaded guilds...");
    {
        uint32 oldMSTime = getMSTime();
        std::set<Guild*> rm; // temporary storage to avoid modifying GuildStore with RemoveGuild() while iterating

        for (GuildContainer::iterator itr = GuildStore.begin(); itr != GuildStore.end(); ++itr)
        {
            Guild* guild = itr->second;
            if (guild && !guild->Validate())
                rm.insert(guild);
        }

        for (std::set<Guild*>::iterator itr = rm.begin(); itr != rm.end(); ++itr)
        {
            Guild* guild = *itr;
            RemoveGuild(guild->GetId());
            delete guild;
        }

        sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Validated data of loaded guilds in %u ms", GetMSTimeDiffToNow(oldMSTime));
    }
}

void GuildMgr::LoadGuildXpForLevel()
{
    uint32 oldMSTime = getMSTime();

    GuildXPperLevel.resize(sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL));
    for (uint8 level = 0; level < sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL); ++level)
        GuildXPperLevel[level] = 0;

    //                                                 0         1
    QueryResult result  = WorldDatabase.Query("SELECT lvl, xp_for_next_level FROM guild_xp_for_level");

    if (!result)
    {
        sLog->outError(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 xp for guild level definitions. DB table `guild_xp_for_level` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 level        = fields[0].GetUInt8();
        uint32 requiredXP   = fields[1].GetUInt64();

        if (level >= sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL))
        {
            sLog->outInfo(LOG_FILTER_GENERAL, "Unused (> Guild.MaxLevel in worldserver.conf) level %u in `guild_xp_for_level` table, ignoring.", uint32(level));
            continue;
        }

        GuildXPperLevel[level] = requiredXP;
        ++count;

    } while (result->NextRow());

    // fill level gaps
    for (uint8 level = 1; level < sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL); ++level)
    {
        if (!GuildXPperLevel[level])
        {
            sLog->outError(LOG_FILTER_SQL, "Level %i does not have XP for guild level data. Using data of level [%i] + 1660000.", level+1, level);
            GuildXPperLevel[level] = GuildXPperLevel[level - 1] + 1660000;
        }
    }

    sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u xp for guild level definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void GuildMgr::LoadGuildRewards()
{
    uint32 oldMSTime = getMSTime();

    //                                                 0     1         2         3      4
    QueryResult result  = WorldDatabase.Query("SELECT entry, standing, racemask, price, achievement FROM guild_rewards");

    if (!result)
    {
        sLog->outError(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 guild reward definitions. DB table `guild_rewards` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        GuildReward reward;
        Field* fields = result->Fetch();
        reward.Entry         = fields[0].GetUInt32();
        reward.Standing      = fields[1].GetUInt8();
        reward.Racemask      = fields[2].GetInt32();
        reward.Price         = fields[3].GetUInt64();
        reward.AchievementId = fields[4].GetUInt32();

        if (!sObjectMgr->GetItemTemplate(reward.Entry))
        {
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Guild rewards constains not existing item entry %u", reward.Entry);
            continue;
        }

        if (reward.AchievementId != 0 && (!sAchievementMgr->GetAchievement(reward.AchievementId)))
        {
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Guild rewards constains not existing achievement entry %u", reward.AchievementId);
            continue;
        }

        if (reward.Standing >= MAX_REPUTATION_RANK)
        {
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Guild rewards contains wrong reputation standing %u, max is %u", uint32(reward.Standing), MAX_REPUTATION_RANK - 1);
            continue;
        }

        GuildRewards.push_back(reward);
        ++count;
    } while (result->NextRow());

    sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u guild reward definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void GuildMgr::ResetTimes(bool week)
{
    CharacterDatabase.Execute(CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RESET_TODAY_EXPERIENCE));
    CharacterDatabase.Execute(CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBER_WITHDRAW));

    // Delete too old old guild member
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_OLD_OLD_GUILD_MEMBER);
    stmt->setUInt32(0, uint32(time(NULL) - time_t(30 * DAY)));
    CharacterDatabase.Execute(stmt);

    // Reset week reputation for old guild member
    if (week)
        CharacterDatabase.Execute(CharacterDatabase.GetPreparedStatement(CHAR_RESET_OLD_GUILD_WEEK_REPUTATION));

    for (GuildContainer::const_iterator itr = GuildStore.begin(); itr != GuildStore.end(); ++itr)
        if (Guild* guild = itr->second)
            guild->ResetTimes(week);
}
