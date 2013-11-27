/*
* Copyright (C) 2012-2013 HTCore <http://cata.vfire-core.com/>
* by Shee Shen
*/

#include "ScriptPCH.h"

class Reset_OnDuelEnd : public PlayerScript
{
	public:
		Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {}

	void OnDuelEnd (Player* winner, Player* loser, DuelCompleteType type)
	{
		// reset cooldowns (in order) Elwyn, Durotar, Tirisfal, Tendrasil, Dun Morogh, Gurubashi Arena, Exodar, Mulgore
		if (winner->GetZoneId() == 12 || winner->GetZoneId() == 14 || winner->GetZoneId() == 85 || winner->GetZoneId() == 141 || winner->GetZoneId() == 1 || winner->GetZoneId() == 5287 || winner->GetZoneId() == 3524 || winner->GetZoneId() == 215)
		{
			// Winner
			winner->SetHealth(winner->GetMaxHealth());
			winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
			winner->RemoveArenaSpellCooldowns();
			winner->GetSession()->SendNotification("Ban nhan duoc 50 Silver tu He Thong vi chien thang trong tran Duel! Hay giu vung phong do!");
			winner->SetMoney(winner->GetMoney() + 5000); // 50 sil
			// Loser
			loser->RemoveArenaSpellCooldowns();
			loser->SetHealth(loser->GetMaxHealth());
			loser->SetPower(POWER_MANA, loser->GetMaxPower(POWER_MANA));
			loser->GetSession()->SendNotification("Dung buon vi da thua! Hay tiep tuc co gang hon nua! Ban nhan duoc 25 Silver tu He Thong.");
			loser->SetMoney(loser->GetMoney() + 2500); // 25 sil
		}
	}
};

void AddSC_Reset()
{
	new Reset_OnDuelEnd;
}