AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Què té de divertit portar el meu\n"
	.string "flotador dins del vaixell?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Vaja, m'has aclaparat!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "No és fàcil llançar POKé BALLS\n"
	.string "mentre t'agafes a un flotador!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "No és divertit aquí?\n"
	.string "M'emociono només de ser-hi!$"
