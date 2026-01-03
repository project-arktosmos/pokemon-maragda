Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} ha escrit el codi secret\n"
	.string "a la porta.\p"
	.string "“El MESTRE DELS TRUCS és la meva vida.”\n"
	.string "… … … … … … … …\p"
	.string "El pany s'ha obert!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Quan vaig sentir que hi havia una casa\n"
	.string "estranya, havia de venir a veure-la.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "He descobert un ENTRENADOR dur!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "M'ho estic passant molt bé explorant\n"
	.string "aquest lloc.\p"
	.string "És un desafiament que val la pena\n"
	.string "repetir!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Potser podria fer que el meu POKéMON\n"
	.string "OCELL volés per sobre la paret…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! L'he pifiat!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… Suposo que he perdut perquè\n"
	.string "intentava fer trampes.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Em mareja amb aquestes portes\n"
	.string "giratòries…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Tot dona voltes i voltes.\n"
	.string "No aguanto més…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Sembla que no t'afecta gens.\n"
	.string "O tens cara de pòquer?$"

