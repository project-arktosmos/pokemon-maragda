VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "A quin CONCURS entres?\n"
	.string "Vols un consell?\p"
	.string "En qualsevol CONCURS, per exemple, un\n"
	.string "CONCURS DE SIMPATIA, no crec que\l"
	.string "et jutgin només per simpatia a la\l"
	.string "primera ronda.\p"
	.string "Has de trobar maneres de crear\n"
	.string "POKéMON millor.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "He criat el meu POKéMON perquè\n"
	.string "fos bonic.\p"
	.string "He descobert que pots posar POKéMON\n"
	.string "en un CONCURS de simpatia!\p"
	.string "Estic tan content d'haver criat el meu\n"
	.string "POKéMON amb estima…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "El meu POKéMON mana!\p"
	.string "És guai, dur però bell, bonic,\n"
	.string "i llest. És complet!\p"
	.string "Igual puc anar a guanyar en tots\n"
	.string "els CONCURSOS.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "CONCURSOS POKéMON\n"
	.string "ESCENARI DE RANG NORMAL!$"

