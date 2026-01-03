Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} ha escrit el codi secret\n"
	.string "a la porta.\p"
	.string "“Al MESTRE DELS TRUCS estimo.”\n"
	.string "… … … … … … … …\p"
	.string "El pany s'ha obert!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "No molts ENTRENADORS han arribat\n"
	.string "tan lluny.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Això vol dir que tu també ets dur…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Has vençut el CAMPIÓ DE LA LLIGA\n"
	.string "POKéMON? És massa!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Considera't afortunat de\n"
	.string "combatre contra mi!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Això no és just!\n"
	.string "No puc perdre!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "És un miracle que m'hagis vençut.\n"
	.string "Pots presumir-ne.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Tu també has lluitat pel desafiament\n"
	.string "de la CASA DELS TRUCS.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Ja veig…\n"
	.string "Tens un estil extraordinari.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Veure algú com tu hauria d'agradar\n"
	.string "al MESTRE DELS TRUCS.$"

