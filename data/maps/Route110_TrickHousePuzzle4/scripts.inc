Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} ha escrit el codi secret\n"
	.string "a la porta.\p"
	.string "“El MESTRE DELS TRUCS mola.”\n"
	.string "… … … … … … … …\p"
	.string "El pany s'ha obert!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "És massa feina pensar en això.\n"
	.string "Jo només volia combatre!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Tot i que he perdut, encara m'agrada\n"
	.string "combatre més que res!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "No hi estàs d'acord? Tu aniràs\n"
	.string "on sigui si hi ha ENTRENADORS.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Eh! Roques com aquestes, les puc\n"
	.string "apartar amb un dit!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Puc empènyer roques, però no puc\n"
	.string "resoldre el trencaclosques…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "No n'hi ha prou amb ser fort…\n"
	.string "Has de fer servir el cap. Ser llest!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La CASA DELS TRUCS es torna més\n"
	.string "complicada, oi?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaak!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Algú ha arribat al final?$"

