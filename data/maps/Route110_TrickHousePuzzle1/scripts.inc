Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} ha escrit el codi secret\n"
	.string "a la porta.\p"
	.string "“El MESTRE DELS TRUCS és fabulós.”\n"
	.string "… … … … … … … …\p"
	.string "El pany s'ha obert!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "M'obriré pas cap a la victòria\n"
	.string "amb el TALLAR que acabem d'aprendre!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Per què ets tan seriós?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Mai em canso de tallar\n"
	.string "i retallar!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "He entrat a aquesta casa estranya\n"
	.string "per accident…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "I ara he perdut…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "M'he perdut, he perdut un combat, i ara\n"
	.string "estic més perdut… No puc sortir…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Qui és el MESTRE DELS TRUCS?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "He perdut mentre estava distret!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Ets fort!\n"
	.string "Qui ets tu?$"

