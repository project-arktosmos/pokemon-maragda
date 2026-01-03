VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "BLAI: Hola! {PLAYER}!\p"
	.string "Aposto que et sorprèn veure'm aquí!\p"
	.string "He arribat fins aquí, i tot\n"
	.string "és gràcies a tu!\p"
	.string "{PLAYER}, perdre contra tu aquella vegada\n"
	.string "em va fer més fort!\p"
	.string "Però ja no perdré més!\p"
	.string "Guanyaré! Pels POKéMON que\n"
	.string "em van donar coratge i força!\p"
	.string "D'acord… Aquí vinc!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Uau!\n"
	.string "{PLAYER}, ets fort, al cap i a la fi!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "BLAI: No t'he pogut guanyar avui,\n"
	.string "{PLAYER}, però algun dia,\l"
	.string "t'atraparé!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "BLAI: Hola! {PLAYER}!\p"
	.string "M'he fet més fort des de l'última\n"
	.string "vegada! Volia ensenyar-t'ho, {PLAYER}!\p"
	.string "D'acord… Aquí vinc!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Uau!\n"
	.string "{PLAYER}, ets fort, al cap i a la fi!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "BLAI: Tampoc t'he pogut guanyar aquest\n"
	.string "cop… Però algun dia, {PLAYER},\l"
	.string "t'atraparé…\p"
	.string "I desafiaré la LLIGA POKéMON!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "He arribat fins aquí un parell de cops,\n"
	.string "però l'últim tram és tan llarg…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "El meu somni acaba aquí un altre cop…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Has arribat fins aquí. Continua amb\n"
	.string "l'impuls i converteix-te en el\l"
	.string "CAMPIÓ! Si algú pot, ets tu!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "No he vingut fins aquí per perdre ara.\n"
	.string "Aquesta possibilitat no existeix!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Impossible…\n"
	.string "He perdut?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "He perdut aquí…\p"
	.string "Això vol dir que no tinc els requisits\n"
	.string "per convertir-me en CAMPIÓ…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Aquest camí aparentment infinit i dur\n"
	.string "fa honor al seu nom de VICTÒRIA.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "El teu estil de combat és fantàstic…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Sembla que tens el potencial per\n"
	.string "convertir-te en CAMPIÓ.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Què és el CAMÍ DE LA VICTÒRIA?\n"
	.string "T'ho diré si guanyes!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "D'acord!\n"
	.string "Ben fet!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Passar per aquí sa i estalvi--aquesta és\n"
	.string "la prova final per qualsevol ENTRENADOR\l"
	.string "que vulgui ser CAMPIÓ POKéMON.\p"
	.string "Per això s'anomena CAMÍ DE\n"
	.string "LA VICTÒRIA.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "No tinc res a dir a ningú\n"
	.string "que hagi arribat tan lluny. Endavant!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Això és una desgràcia…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Hmph, tira endavant.\n"
	.string "Tant m'és.$"
