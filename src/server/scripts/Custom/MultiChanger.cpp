/*
* Copyright (C) 2012-2013 HTCore <http://cata.vfire-core.com/>
* by Shee Shen
*/

#include "ScriptPCH.h"

enum Costs
{
	TokenID = 71998,
	TokenAmountNameChange = 10,
	TokenAmountRaceChange = 20,
	TokenAmountFactionChange = 50,
	TokenAmountCustomize = 30,
};


class multi_changer : public CreatureScript
{
	public:
      multi_changer() : CreatureScript("multi_changer") { }

		bool OnGossipHello(Player * player, Creature * creature)
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Change my name for 10 tokens", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Change my race for 20 tokens", GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Change my faction for 50 tokens", GOSSIP_SENDER_MAIN, 3);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Let me customize my character for 30 tokens", GOSSIP_SENDER_MAIN, 4);
			player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
			return true;
		}
      
		bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
		{
			player->PlayerTalkClass->ClearMenus();
            
			switch(uiAction)
			{
				case 1:
						if (player->HasItemCount(TokenID, TokenAmountNameChange))
						{
							player->DestroyItemCount(TokenID, TokenAmountNameChange, true);
							player->SetAtLoginFlag(AT_LOGIN_RENAME);
							player->GetSession()->SendAreaTriggerMessage("Relog to get a namechange.");
							creature->MonsterWhisper("Relog to get a namechange.", player->GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						else
						{
							player->GetSession()->SendAreaTriggerMessage("You don't have enough tokens.");
							creature->MonsterWhisper("You don't have enough tokens", player->GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						break;

				case 2:
						if (player->HasItemCount(TokenID, TokenAmountRaceChange))
						{
							player->DestroyItemCount(TokenID, TokenAmountRaceChange, true);
							player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
							player->GetSession()->SendAreaTriggerMessage("Relog to change your race.");
							creature->MonsterWhisper("Relog to change your race.", player->GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						else
						{
							player->GetSession()->SendAreaTriggerMessage("You don't have enough tokens.");
							creature->MonsterWhisper("You don't have enough tokens.", player -> GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						break;

				case 3:
						if (player->HasItemCount(TokenID, TokenAmountFactionChange))
						{
							player->DestroyItemCount(TokenID, TokenAmountFactionChange, true);
							player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
							player->GetSession()->SendAreaTriggerMessage("Relog to change your faction.");
							creature->MonsterWhisper("Relog to change your faction.", player->GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						else
						{
							player->GetSession()->SendAreaTriggerMessage("You don't have enough tokens.");
							creature->MonsterWhisper("You don't have enough tokens", player->GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						break;

				case 4:
						if (player->HasItemCount(TokenID, TokenAmountCustomize))
						{
							player->DestroyItemCount(TokenID, TokenAmountCustomize, true);
							player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
							player->GetSession()->SendAreaTriggerMessage("Relog to customize your character.");
							creature->MonsterWhisper("Relog to customize your character.", player->GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						else
						{
							player->GetSession()->SendAreaTriggerMessage("You don't have enough tokens.");
							creature->MonsterWhisper("You don't have enough tokens", player->GetGUID());
							player->PlayerTalkClass->SendCloseGossip();
						}
						break;
			}
			return true;
		}
};

void AddSC_multi_changer()
{
   new multi_changer;
}