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

/*
 * All Creature text can be moved to creature text will be done Soon!
 */ 
 
#include "ScriptMgr.h"
#include "ScriptedFollowerAI.h"

class npc_elemental_energy_quest : public CreatureScript
{
    public:
        npc_elemental_energy_quest() : CreatureScript("npc_elemental_energy_quest") { }

        struct npc_elemental_energy_questAI : public ScriptedAI
        {
            npc_elemental_energy_questAI(Creature* creature) : ScriptedAI(creature) { }

            void JustDied(Unit * who)
            {
                printf("\n ! just died ! \n ");
                if (Creature * totem = GetClosestCreatureWithEntry(me, 45088, 25.0f))
                {
                    printf("\n ! casting spell on totem ! \n ");
                    //if(Player * plr = totem->GetCharmerOrOwnerPlayerOrPlayerItself())
                        totem->CastSpell(totem, 84170, true);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_elemental_energy_questAI(creature);
        }
};

class npc_imposing_confrontation_quest : public CreatureScript
{
    public:
        npc_imposing_confrontation_quest() : CreatureScript("npc_imposing_confrontation_quest") { }

        struct npc_imposing_confrontation_questAI : public ScriptedAI
        {
            npc_imposing_confrontation_questAI(Creature* creature) : ScriptedAI(creature) { Reset(); }

            bool eventStarted;
            uint8 phase;
            int32 phaseTimer;
            uint64 initiator;

            void Reset()
            {
                eventStarted = false;
                uint8 phase = 0;
                phaseTimer = 0;
                initiator = 0;
            }

            void SpellHit(Unit* caster, const SpellInfo* spell)
            {
                if(spell->Id == 79715)
                {
                    caster->MonsterSay("Boden the Imposing. I come on behalf of the Earthen Ring. We wish your kind no harm. We seek to repair the rift between our worlds. Why do you attack us?", 0,0);
                    eventStarted = true;
                    phaseTimer = 7000;
                    initiator = caster->GetGUID();
                    me->GetMotionMaster()->MoveIdle();
                    me->SetFacingToObject(caster);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if(eventStarted)
                {
                    if((phaseTimer -= diff) <= 0)
                    switch(phase++)
                    {
                        case 0:
                            me->MonsterYell("Hah! Did you mistake me for Diamant ? Or perhaps some other whimpering, compliant, stone trogg who cares?", 0,0);
                            phaseTimer = 9000;
                            break;
                        case 1:
                            me->MonsterYell("If you seek peace, relinquish the World Pillar and leave Deepholm. This is our realm. Your only welcome here shall be found underneath my stone foot.", 0,0);
                            phaseTimer = 13000;
                            break;
                        case 2:
                            if(Player * player = Unit::GetPlayer(*me, initiator))
                            {
                                me->CastSpell(player, 79843, true);
                                me->GetMotionMaster()->InitDefault();
                            }
                            Reset();
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_imposing_confrontation_questAI(creature);
        }
};

enum eQuest26861Data
{
   QUEST_A_RETURN_TO_RESTING       = 26861,

   NPC_DOOR_1_CREDIT               = 44930,
   NPC_DOOR_2_CREDIT               = 44931,
};

class spell_q26861_door_dummy : public SpellScriptLoader
{
    public:
        spell_q26861_door_dummy() : SpellScriptLoader("spell_q26861_door_dummy") { }
 
        class spell_q26861_door_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_q26861_door_dummy_SpellScript)
 
            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Creature* unitTarget = GetHitCreature())
                {
                    if (Player* player = GetCaster()->ToPlayer())
                    {
                        if (player->GetQuestStatus(QUEST_A_RETURN_TO_RESTING) == QUEST_STATUS_INCOMPLETE)
                        {
                            switch (unitTarget->GetEntry())
                            {
                                 case NPC_DOOR_1_CREDIT:
                                     player->KilledMonsterCredit(NPC_DOOR_1_CREDIT, 0);
                                     break;
                                 case NPC_DOOR_2_CREDIT:
                                     player->KilledMonsterCredit(NPC_DOOR_2_CREDIT, 0);
                                     break;
                                 default:
                                     break;
                            }
                        }
                    }
                }
            }
 
            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_q26861_door_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };
 
        SpellScript* GetSpellScript() const
        {
            return new spell_q26861_door_dummy_SpellScript();
        }
};

class AreaTrigger_at_deepholm_flyover : public AreaTriggerScript
{
     public:
         AreaTrigger_at_deepholm_flyover() : AreaTriggerScript("at_deepholm_flyover") {}
    enum
    {
        QUEST_FLY_OVER_A             = 27006,
        QUEST_FLY_OVER_H             = 27008,
        NPC_GENERIC_TRIGGER             = 44839,
    };

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
    {
        if (player->GetQuestStatus(QUEST_FLY_OVER_A) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature * trigger = player->FindNearestCreature(NPC_GENERIC_TRIGGER, 25.0f))
                player->KilledMonsterCredit(NPC_GENERIC_TRIGGER);
        }
        return true;
        
        if (player->GetQuestStatus(QUEST_FLY_OVER_H) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature * trigger = player->FindNearestCreature(NPC_GENERIC_TRIGGER, 25.0f))
                player->KilledMonsterCredit(NPC_GENERIC_TRIGGER);
        }
        return true;
    }
};

class npc_lodestone : public CreatureScript
{
    public:
        npc_lodestone() : CreatureScript("npc_lodestone") { }

    struct npc_lodestoneAI : public ScriptedAI
    {
        npc_lodestoneAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* killer)
        {
            if(Player* player = killer->ToPlayer())
            {
                if(player->GetQuestStatus(27136) == QUEST_STATUS_INCOMPLETE)
                {
                    if(Creature* totem = me->FindNearestCreature(45088, 20.0f, true))
                    {
                        totem->CastSpell(totem, 84163, true);
                        player->KilledMonsterCredit(45091, 0);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new npc_lodestoneAI(creature);
    }
};

#define CREW_SAY_1 "They poisoned our supplies... we had cultists onboard all along..."
#define CREW_SAY_2 "Everyone started dropping like flies... everyone who ate the rations."
#define CREW_SAY_3 "They tricked us into ambushing the Horde gunship... but why?"
#define CREW_SAY_4 "I heard them praying to their dark gods as everything went black... the Twilight's Hammer did this!"
#define CREW_SAY_5 "Twilight scum! You did this to us!"
class npc_slaincrewmember : public CreatureScript
{
    public:
        npc_slaincrewmember() : CreatureScript("npc_slaincrewmember") { }

    struct npc_slaincrewmemberAI : public ScriptedAI
    {
        npc_slaincrewmemberAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 playerGUID;
        bool QuestInProgress;
        uint32 sayTimer;

        void Reset()
        {
            playerGUID = 0;
            QuestInProgress = false;
            sayTimer = 3000;
        }
        void SetData(uint32 Id,  uint32 Value)
        {
            switch(Id)
            {
                case 1: // Set the GUID of the player
                {
                    playerGUID = Value;
                    QuestInProgress = true;
                    break;
                }
            }
        }
        void UpdateAI(uint32 const diff)
        {
            if(!QuestInProgress)
                return;

            Player* player = Unit::GetPlayer(*me, playerGUID);

            if(!player)
                return;

            if(sayTimer <= diff)
            {
                switch(RAND(0, 1, 2, 3, 4))
                {
                    case 0:
                        me->MonsterSay(CREW_SAY_1, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 1:
                        me->MonsterSay(CREW_SAY_2, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 2:
                        me->MonsterSay(CREW_SAY_3, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 3:
                        me->MonsterSay(CREW_SAY_4, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 4:
                        me->MonsterSay(CREW_SAY_5, LANG_UNIVERSAL, NULL);
                        me->setFaction(14);
                        me->AddThreat(player, 53.0f);
                        me->AI()->AttackStart(player);
                        QuestInProgress = false;
                        break;
                }
            }
            else sayTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_slaincrewmemberAI(creature);
    }
};

enum eFlint
{
    QUEST_TAKE_HIM_TO_THE_EARTHCALLER = 26413,
    NPC_YEVAA = 42573,
};

/* ToDo
- Maybe there is a dialog between Flint and Yeeva
*/

class npc_flint_oremantle : public CreatureScript
{
public:
    npc_flint_oremantle() : CreatureScript("npc_flint_oremantle") { }

    
    bool OnGossipHello(Player* pPlayer, Creature* creature)
    {
        
        if(creature->isInCombat() || pPlayer->GetQuestStatus(QUEST_TAKE_HIM_TO_THE_EARTHCALLER) != QUEST_STATUS_INCOMPLETE)
        return false;
        
        char const* _message = "Follow me to the Earthcaller!";    
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,_message,GOSSIP_SENDER_MAIN ,GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(68,creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        pPlayer->CLOSE_GOSSIP_MENU();

         if (npc_flint_oremantleAI* npc_flint_oremantleAI = CAST_AI(npc_flint_oremantle::npc_flint_oremantleAI, creature->AI()))
         {
                creature->SetStandState(UNIT_STAND_STATE_STAND);
                npc_flint_oremantleAI->StartFollow(pPlayer, 35, 0);

                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
         }
    
        return true;
    }
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_flint_oremantleAI(creature);
    }

    struct npc_flint_oremantleAI : public FollowerAI
    {
        npc_flint_oremantleAI(Creature* creature) : FollowerAI(creature), HomePosition(creature->GetHomePosition()) { }

        Position HomePosition;

        void Reset()
        {
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void MoveInLineOfSight(Unit* who)
        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && who->GetEntry() == NPC_YEVAA)
            {
                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
                {
                    if (Player* player = GetLeaderForFollower())
                    {
                        if (player->GetQuestStatus(QUEST_TAKE_HIM_TO_THE_EARTHCALLER) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(44207, 0);

                        me->DespawnOrUnsummon(30000);
                    }

                    SetFollowComplete(true);
                }
            }
        }
    };
};

// Boden the Imposing for Quest: 26315
enum eBoden
{
    QUEST_IMPOSING_CONFRONTATION = 26315,
    SPELL_EARTHEN_RING_PROCLAMATION = 79715,
    SPELL_IMPOSING_CONFRONTATION_CREDIT = 79843,
};

class npc_boden_the_imposing : public CreatureScript
{
public:
    npc_boden_the_imposing() : CreatureScript("npc_boden_the_imposing") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_boden_the_imposingAI (creature);
    }

    struct npc_boden_the_imposingAI : public ScriptedAI
    {
        npc_boden_the_imposingAI(Creature* creature) : ScriptedAI(creature), DialogNumber(0), SpeakPlayer(NULL) {}

        uint16 DialogNumber;
        uint64 uiProcessDialog;
        Unit* SpeakPlayer;

        void SpellHit(Unit* Caster,const SpellInfo* Spell)
        {
            if(Spell->Id != SPELL_EARTHEN_RING_PROCLAMATION/* || Caster->ToPlayer()->GetQuestStatus(QUEST_TAKE_HIM_TO_THE_EARTHCALLER) != QUEST_STATUS_INCOMPLETE*/) // The Quest if clause didn't work^^ don#t know why
                return;

            Caster->ToPlayer()->Say("Boden the Imposing. I come on behalf of the Earthen Ring. We wish your kind no harm. We seek to repair the rift between our worlds. Why do you attack us?", LANG_UNIVERSAL);

            DialogNumber = 1;
            uiProcessDialog = 2000;

            SpeakPlayer = Caster;
        }

        void UpdateAI(const uint32 diff)
        {
            if(DialogNumber == NULL)
                return;

            if (uiProcessDialog <= diff)
            {
                switch(DialogNumber)
                {
                
                case 1:
                    me->MonsterYell("Hah! Did you mistake me for Diamant, $r? Or perhaps some other whimpering, complaint stone trogg who cares?",LANG_UNIVERSAL,0);
                    uiProcessDialog = 4000;
                    break;

                case 2:
                    me->MonsterYell("If you seek peace, relinquish the World Pillar and leave Deepholm. This is our realm. Your only welcome here shall be found underneath my stone foot.",LANG_UNIVERSAL,0);
                    uiProcessDialog = 1200;
                    break;
                    
                case 3:
                    if(SpeakPlayer)
                    me->CastSpell(SpeakPlayer,SPELL_IMPOSING_CONFRONTATION_CREDIT,true);
                    break;
                }

                if(DialogNumber != 3)
                {
                    DialogNumber++;
                }else
                    DialogNumber = 0;

            } else uiProcessDialog -= diff;
        }
    };
};

// Ricket Ticker for Quest: Underground Ecomomy (27048)

enum eRicketTicker
{
    SPELL_EXPLODE = 91981,

    NPC_DEEP_CELESTITE_BUNNY = 49865,
    NPC_DEEP_AMETHYST_BUNNY = 49866,
    NPC_DEEP_GRANAT_BUNNY = 49867,
    NPC_DEEP_ALABASTER_BUNNY = 49824,
    
    ITEM_DEEP_CELESTITE_CRYSTAL = 65507,
    ITEM_DEEP_AMETHYST_CRYSTAL = 65508,
    ITEM_DEEP_GRANAT_CRYSTAL = 65510,
    ITEM_DEEP_ALABASTER_CRYSTAL = 65504,
};

class npc_ricket_ticker : public CreatureScript
{
public:
    npc_ricket_ticker() : CreatureScript("npc_ricket_ticker") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ricket_tickerAI (creature);
    }

    struct npc_ricket_tickerAI : public ScriptedAI
    {
        npc_ricket_tickerAI(Creature* creature) : ScriptedAI(creature), uiExplode(NULL) { }

        uint32 uiExplode;    
        Player* player;

        void Reset()
        {
            uiExplode = 0;
        }

        void IsSummonedBy(Unit* summoner)
        {
            uiExplode = 3500;
            player = summoner->ToPlayer();
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiExplode == NULL)
                return;

            if (uiExplode <= diff)
            {    
                DoCastAOE(SPELL_EXPLODE,true);
            
                // Checks weather a Deep Crystal is in Range
                if(me->FindNearestCreature(NPC_DEEP_CELESTITE_BUNNY, 7.0f, true))
                        player->AddItem(ITEM_DEEP_CELESTITE_CRYSTAL,1);

                if(me->FindNearestCreature(NPC_DEEP_AMETHYST_BUNNY, 7.0f, true))
                        player->AddItem(ITEM_DEEP_AMETHYST_CRYSTAL,1);

                if(me->FindNearestCreature(NPC_DEEP_GRANAT_BUNNY, 7.0f, true))
                        player->AddItem(ITEM_DEEP_GRANAT_CRYSTAL,1);

                if(me->FindNearestCreature(NPC_DEEP_ALABASTER_BUNNY, 7.0f, true))
                        player->AddItem(ITEM_DEEP_ALABASTER_CRYSTAL,1);

                me->DespawnOrUnsummon();

            } else uiExplode -= diff;
        }
    };
};

// Stonefather's Banner for Quest Stonefathers Boon

enum eBanner
{
    NPC_STONEHEART_DEFENDER = 43138,
    SPELL_BUFF_OF_THE_STONEFATHER = 80668,
};

class npc_stonefathers_banner : public CreatureScript
{
public:
    npc_stonefathers_banner() : CreatureScript("npc_stonefathers_banner") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_stonefathers_bannerAI (creature);
    }

    struct npc_stonefathers_bannerAI : public ScriptedAI
    {
        npc_stonefathers_bannerAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE    | UNIT_FLAG_NOT_SELECTABLE);
        }

        void IsSummonedBy(Unit* summoner)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, NPC_STONEHEART_DEFENDER, 10.0f /*Range is official*/);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                if(!(*iter)->HasAura(SPELL_BUFF_OF_THE_STONEFATHER))
                {
                    (*iter)->CastSpell((*iter),SPELL_BUFF_OF_THE_STONEFATHER, true);
                    summoner->ToPlayer()->KilledMonsterCredit(NPC_STONEHEART_DEFENDER, 0);
                }
        }
    };
};

void AddSC_deepholm()
{
    new npc_elemental_energy_quest();
    new npc_imposing_confrontation_quest();
    new spell_q26861_door_dummy();
    new AreaTrigger_at_deepholm_flyover();
    new npc_lodestone();
    new npc_slaincrewmember();
    new npc_flint_oremantle();
    new npc_boden_the_imposing();
    new npc_ricket_ticker();
    new npc_stonefathers_banner();    
}
