BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Si us plau, troba un company d'entre\n"
	.string "els ENTRENADORS reunits aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, no has trobat un company\n"
	.string "per al teu equip.\p"
	.string "Vols deixar de buscar i tornar\n"
	.string "al mostrador de recepció?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Llavors, si us plau, troba un company\n"
	.string "d'entre els ENTRENADORS d'aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Gràcies per triar un company.\p"
	.string "Ara et portaré a la teva\n"
	.string "SALA DE COMBAT MÚLTIPLE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}.\n"
	.string "Em pots dir {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Seguint el consell d'{STR_VAR_1}, porto\n"
	.string "un {STR_VAR_3} amb {STR_VAR_2} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Si us plau, deixa'm unir-me a tu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Gràcies!\n"
	.string "Vaig a registrar-me ara mateix.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Realment volia fer equip\n"
	.string "amb tu, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}.\n"
	.string "Em dic {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Vaig rebre consell d'{STR_VAR_1} i vaig triar\n"
	.string "un {STR_VAR_3} amb {STR_VAR_2} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Si us plau, fem equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Moltes gràcies!\n"
	.string "Acabaré el registre ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, esperava poder\n"
	.string "fer equip amb tu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Em… em dic {STR_VAR_3}, i sóc\n"
	.string "l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}.\p"
	.string "Snif…\p"
	.string "Ho sento!\n"
	.string "Aquesta tensió em fa plorar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} em va aconsellar, i porto\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Snif…\n"
	.string "Si us plau, fes equip amb mi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, de veritat? Ho faràs?\n"
	.string "Genial! Fantàstic! Uauuu!\p"
	.string "Oh… Ho sento…\n"
	.string "Estic tan content que ploro…\p"
	.string "Vaig a registrar-me ara mateix.\n"
	.string "Si us plau, no marxis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, p-però…\n"
	.string "Snif… Buaaa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Ei, hola! Sóc {STR_VAR_3}!\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} em va recomanar l'equip.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1},\n"
	.string "això és el que tinc! Mola, eh?\p"
	.string "Vinga!\n"
	.string "Fem equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Bé! Genial!\n"
	.string "D'acord, vaig a registrar-me, vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Oh, per què?\n"
	.string "Volia fer equip amb tu, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Sóc {STR_VAR_3}, l'aprenent núm. {STR_VAR_2}\n"
	.string "del famós {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Vaig demanar consell a {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "i un {STR_VAR_2} amb {STR_VAR_1},\n"
	.string "és la meva parella.\p"
	.string "Si us plau, t'uniries a mi\n"
	.string "en un equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Gràcies!\n"
	.string "Vaig a registrar-me ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, esperava unir-me\n"
	.string "a tu en un equip…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Em… Estic molt content que\n"
	.string "tinguis temps per parlar amb mi.\p"
	.string "Sóc {STR_VAR_3}.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} em va donar consells.\n"
	.string "N'estic molt agraït.\p"
	.string "Tinc un equip d'un {STR_VAR_2}\n"
	.string "amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "Sé que demano molt…\p"
	.string "No crec que vulguis, però\n"
	.string "podria unir-me a tu com a company?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "De veritat? No m'ho puc creure!\n"
	.string "No em crec que em deixis unir-me!\l"
	.string "No… no et decebré!\p"
	.string "Em… Si realment està bé, vaig a\n"
	.string "registrar-me ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "No pensava que fos prou bo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hola, sóc {STR_VAR_3}.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} em va dir que seria bo\n"
	.string "fer aquest equip:\l"
	.string "un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "i un {STR_VAR_2} que sap\n"
	.string "usar {STR_VAR_1}.\p"
	.string "No està malament, eh?\n"
	.string "Vols que faci equip amb tu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "D'acord, encantat d'unir-me!\n"
	.string "Espero que no ho facis malament!\l"
	.string "Vaig a registrar-me ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Eh? Per què m'has rebutjat?\n"
	.string "No saps jutjar el caràcter!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Sóc {STR_VAR_3} i sóc TRIATLETA.\n"
	.string "Estic ocupat cada dia amb córrer,\l"
	.string "entrenar i fer rap.\p"
	.string "També resulta que sóc\n"
	.string "l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Això és el que {STR_VAR_3} va recomanar.\n"
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Hi he posat molt esforç en criar-los,\n"
	.string "tot i estar ocupat.\p"
	.string "Fem equip\n"
	.string "i provem-ho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Gràcies, així es parla!\n"
	.string "Espera mentre vaig a registrar-me, vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "He tret temps de la meva agenda\n"
	.string "per ser aquí! Dóna'm un descans!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Ei!\n"
	.string "Com va?\p"
	.string "Sóc {STR_VAR_3}, l'aprenent núm. {STR_VAR_2}\n"
	.string "d'{STR_VAR_1}. Encantat de conèixer-te!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Escolta, escolta! Has de sentir\n"
	.string "els POKéMON que {STR_VAR_3} va recomanar.\l"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "És clar que els he criat superbé!\p"
	.string "Llavors, vols fer equip?\n"
	.string "Segur que serem un gran combo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Bé, crec que serà divertit!\n"
	.string "Vaig a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, ets dolent!\n"
	.string "Vinc recomanat, ho saps.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Si us plau, deixa'm presentar-me.\n"
	.string "Sóc {STR_VAR_3}.\p"
	.string "Serveixo com a aprenent núm. {STR_VAR_2}\n"
	.string "d'{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Vaig buscar el savi consell de\n"
	.string "{STR_VAR_3} i vaig criar l'equip\l"
	.string "d'un {STR_VAR_2} amb {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "i un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Si us plau, accepta fer equip amb mi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… Estic encantat!\n"
	.string "Et prometo donar-ho tot!\p"
	.string "És clar que ens registraré!\n"
	.string "Si us plau, espera!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Esperava poder unir-me a tu,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Ui! M'has parlat!\n"
	.string "Jo… estic molt content!\p"
	.string "Sóc {STR_VAR_3}! Sóc l'aprenent\n"
	.string "núm. {STR_VAR_2} d'{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Seguint el consell de {STR_VAR_3}, vaig\n"
	.string "entrenar un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Si us plau, pots complir el meu desig?\n"
	.string "Vull ser el teu company d'equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Ui! Jo… em sento marejat!\n"
	.string "Moltes gràcies!\l"
	.string "Vaig a registrar-nos ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Buaaa! No sents cap pena?\n"
	.string "Però això et fa més guai…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Iuhuuu! Sóc l'aprenent núm. {STR_VAR_2}\n"
	.string "d'{STR_VAR_1}!\p"
	.string "Em dic {STR_VAR_3}, hola, hola!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "El meu mentor {STR_VAR_3} va recomanar\n"
	.string "un {STR_VAR_2} mestre en {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "i un {STR_VAR_2} mestre\n"
	.string "en {STR_VAR_1}.\p"
	.string "Mola, eh?\n"
	.string "Faràs equip amb mi, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "D'acord, excel·lent!\n"
	.string "Faré el registre ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Aaaarg!\n"
	.string "Ets molt calculador, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Ei! Hi ha un gran problema! És\n"
	.string "l'últim dia de la TORRE COMBAT!\p"
	.string "… … … … … …\n"
	.string "Només era broma!\p"
	.string "La gent em diu {STR_VAR_3} i jo també!\n"
	.string "Sóc l'aprenent 1.000 d'{STR_VAR_1}!\l"
	.string "En realitat, sóc el núm. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} em va donar consells.\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "En tinc deu de cada tipus!\l"
	.string "En realitat, només un de cada!\p"
	.string "Què et sembla?\n"
	.string "Vols provar combats en equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Bé!\n"
	.string "Et donaré un POKéMON com a gràcies!\p"
	.string "Era broma! Però sí que aniré a fer\n"
	.string "el registre, d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, què fred! Hauré de destrossar\n"
	.string "la TORRE COMBAT per això!\p"
	.string "És clar que no ho faré!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Ei, aquí estic, fent rock and roll!\n"
	.string "POKéMON, sota el meu control!\p"
	.string "Sóc {STR_VAR_3}, el MARINER raper.\n"
	.string "No em confonguis amb cap ploramiques!\p"
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}.\n"
	.string "A mi no em pots pas ignorar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Amb el consell de {STR_VAR_3} vaig\n"
	.string "seguir, l'equip d'orgull vaig reunir!\l"
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}!\p"
	.string "La nostra trobada hem de commemorar,\n"
	.string "amb una victòria en equip a celebrar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Ei, ei, m'agrada el teu estil!\n"
	.string "El registre ara aniré a arxivar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, ei, {PLAYER}, què fred ets!\n"
	.string "Si puc ser tan atrevit!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Iupiiii!\n"
	.string "Oh, no fugis! Només m'estava divertint!\p"
	.string "Ei! Sóc {STR_VAR_3}!\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} em va dir què fer.\n"
	.string "Així que un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}, vaig triar.\p"
	.string "Llavors, què em dius?\n"
	.string "Vinga, fes-me el dia!\p"
	.string "Si us plau, t'ho suplico!\n"
	.string "Deixa'm unir-me, no em deixis trist!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Sí! La sort m'acompanya!\n"
	.string "Això em fa molt feliç!\p"
	.string "Abans d'anar a la batalla,\n"
	.string "vaig a registrar-me de seguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Em rebutges?\n"
	.string "{PLAYER}, em fas posar trist!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Tos!\p"
	.string "Oh, perdona, tinc un refredat.\n"
	.string "Els meus POKéMON estan bé, però.\p"
	.string "Em dic {STR_VAR_3}, l'aprenent núm. {STR_VAR_2}\n"
	.string "d'{STR_VAR_1}. Tos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Vaig prendre el consell de {STR_VAR_3}\n"
	.string "de cor i vaig muntar l'equip amb\l"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Els vaig entrenar cada dia,\n"
	.string "fins i tot amb vent i pluja.\p"
	.string "Per això tinc aquest refredat,\n"
	.string "crec.\p"
	.string "Així sóc jo.\n"
	.string "Vols ser el meu company d'equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Gràcies, t'ho agraeixo!\n"
	.string "Tos, tos!\l"
	.string "Espera mentre vaig a registrar-me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, no vols?\n"
	.string "{PLAYER}, crec que faríem bona parella.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, hola!\n"
	.string "Això em posa nerviós.\p"
	.string "Sóc {STR_VAR_3}.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} va dir que aquest equip aniria bé:\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Em sento una mica cohibit,\n"
	.string "però em deixaràs unir-me a tu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, vaja, gràcies!\n"
	.string "Em sento tímid, però ho donaré tot!\p"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, si us plau, no diguis que no!\n"
	.string "Ja em sento prou cohibit…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Sóc {STR_VAR_3}, i no és cap mentida.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} d'{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} va recomanar el meu equip.\p"
	.string "Com que el consell semblava sincer,\n"
	.string "vaig decidir portar amb mi\l"
	.string "el meu {STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "el meu {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Si és possible, m'agradaria que\n"
	.string "m'acceptessis com a company d'equip.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "De veritat m'acceptaràs?\n"
	.string "Seria terrible si no.\p"
	.string "Però com que has acceptat, està bé.\n"
	.string "Aniré a registrar-nos a tots dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Per què et negaries?\n"
	.string "És una broma?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Sóc {STR_VAR_1}, i sóc una NOIA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "El que tinc és un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\n"
	.string "Això és el que porto amb mi.\p"
	.string "Vols ser el meu company?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Gràcies!\n"
	.string "Vaig a fer el registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "No vols ser el meu company?\n"
	.string "Te'n penediràs!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Hola!\p"
	.string "Sóc el JOVENET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Vols saber què tinc?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Seràs el meu company d'equip,\n"
	.string "oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Bé!\n"
	.string "Vaig a registrar-me, d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Oh! Si fessis equip amb\n"
	.string "els meus POKéMON, seríem imparables!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Iuhuuu!\n"
	.string "Sóc l'EXCURSIONISTA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Saps què porto amb mi?\n"
	.string "El meu {STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "el meu {STR_VAR_2} que usa {STR_VAR_1}!\p"
	.string "Sona bé, eh?\n"
	.string "Vols fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Iuhuuu!\n"
	.string "Vaig a fer el registre, doncs.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "M'hauria agradat combatre\n"
	.string "amb tu al meu costat.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hola!\n"
	.string "Sóc {STR_VAR_1}, i sóc una BELLESA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Saps què he estat criant?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què en penses?\n"
	.string "Vols fer equip junts?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Meravellós!\n"
	.string "Vaig a fer el registre ara!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Quina decepció!\p"
	.string "Nosaltres dos junts hauríem estat\n"
	.string "els millors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Ei!\p"
	.string "Saps qui sóc?\n"
	.string "Sóc el PESCADOR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Porto amb mi un equip d'un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Llavors, què et sembla?\n"
	.string "Combatràs al meu costat?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bé, bé!\n"
	.string "Deixa-ho en les meves mans!\p"
	.string "Vaig a registrar-nos ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Encaixàvem perfectament…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Encantada de conèixer-te.\n"
	.string "Sóc {STR_VAR_1}, una DAMA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "M'acompanya un equip format per\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Espero comptar amb la teva aprovació.\n"
	.string "Ja que desitjo tenir-te com a company.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "T'ho agraeixo sincerament.\n"
	.string "M'encarregaré del registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Estic segura que et penediràs\n"
	.string "de no tenir-me com a companya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Sóc la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "El que tinc…\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\n"
	.string "Aquesta és la meva parella!\p"
	.string "Si us plau?\n"
	.string "Vols fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Vaja, gràcies!\n"
	.string "Vaig a registrar-me al mostrador.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Nosaltres dos junts hauríem estat\n"
	.string "durs de veritat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Ei!\n"
	.string "Sóc el CAÇAINSECTES {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Mira què tinc!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Escolta!\n"
	.string "Vols fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Entesos!\p"
	.string "Vaig a fer el registre\n"
	.string "al mostrador.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Vaja, els meus POKéMON són genials.\n"
	.string "Espero que no te'n penedeixis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Bon dia!\n"
	.string "Sóc l'ESTUDIANT {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "El que he estat criant és un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "No està malament, no creus?\n"
	.string "T'agradaria fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Moltes gràcies!\n"
	.string "Faré el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Quina llàstima…\p"
	.string "Esperava poder aprendre\n"
	.string "de tu com a company…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Ei! Deixa'm dir-te qui sóc!\n"
	.string "Sóc el NIÑO RIC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Endevina què tinc!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Estic disposat a oferir-te l'oportunitat\n"
	.string "de fer equip amb mi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Bona decisió!\p"
	.string "Acabaré el registre\n"
	.string "ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Em rebutjaries a mi, de totes les persones?\n"
	.string "Segur que et penediràs d'aquesta decisió!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiiiia!\n"
	.string "Sóc el CINTURÓ NEGRE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Com a companys, tinc\n"
	.string "un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Si us plau, compleix el meu desig!\n"
	.string "Deixa'm ser el teu company d'equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiiiia!\n"
	.string "Vaig a registrar-me de seguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Entenc… Espero tenir una oportunitat\n"
	.string "la propera vegada que ens veiem…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Ei, hola!\n"
	.string "Sóc {STR_VAR_1}, i sóc una NEDADORA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Et diré què tinc.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\n"
	.string "Si us plau, puc ser del teu equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Gràcies!\n"
	.string "Vaig a registrar-nos ara!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Si haguéssim fet equip, hauríem\n"
	.string "estat tan forts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Salutacions…\n"
	.string "Sóc la BRUIXA {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Porto amb mi un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} juntament amb un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}…\p"
	.string "T'ho suplico…\n"
	.string "Uneix-te a mi en un equip…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "T'ho agraeixo…\n"
	.string "Ens registraré…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Anhelava tant unir-me a tu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Com estàs? Sóc {STR_VAR_1},\n"
	.string "i sóc un CRIADOR POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Estic criant uns de ben bons!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què et sembla?\n"
	.string "Et ve de gust fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Moltes gràcies!\p"
	.string "M'encarregaré del registre,\n"
	.string "així que espera't aquí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Tenia ganes de ser\n"
	.string "el teu company…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Bé, hola!\n"
	.string "Sóc la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Vols saber amb què corro?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "I bé?\n"
	.string "Vols fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Ben fet!\p"
	.string "Seré ràpida i faré el registre\n"
	.string "de seguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Tu i jo, hauríem estat els millors.\n"
	.string "Quina llàstima…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Ei, hola! Em dic {STR_VAR_1}!\n"
	.string "Sóc un TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Corro amb el meu equip resistent:\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "No està malament, eh?\n"
	.string "Hauríem de fer equip junts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "D'acord!\n"
	.string "Vaig a registrar-me en un moment!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Tenia moltes ganes de combatre com\n"
	.string "el teu company d'equip…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Sóc la NOIA COMBAT {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "He estat endurint un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}!\p"
	.string "T'agrada aquesta combinació?\n"
	.string "Què et sembla si fem equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Oh, gràcies!\p"
	.string "Faré el registre\n"
	.string "ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Amb tu, pensava que podríem formar\n"
	.string "l'equip definitiu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Sóc el TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "He estat corrent amb un {STR_VAR_2}\n"
	.string "que sap usar {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "i un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Podríem fer equip.\n"
	.string "No seria genial?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Gràcies!\p"
	.string "Vaig a registrar-nos, i és\n"
	.string "ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Oh, quina llàstima. Hauríem estat\n"
	.string "l'equip més dur de tots!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Jo?\n"
	.string "Sóc el NEDADOR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Què tinc amb mi?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Ei?\n"
	.string "Faràs equip amb mi, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "D'acord!\p"
	.string "Vaig a registrar-me!\n"
	.string "Siguem excel·lents junts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Els meus POKéMON són durs de debò…\n"
	.string "Quina llàstima que no vulguis fer equip.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Ei-ei!\n"
	.string "Digues-me el GUITARRISTA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Mira el meu seguici!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Ei-ei! Molt salvatge, eh?\n"
	.string "Haurem de fer un duet en equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Ei-ei! Ben dit!\n"
	.string "Faré el registre ara!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Els meus POKéMON són molt rockers!\n"
	.string "Te'n penediràs, t'ho dic!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Encantat de conèixer-te.\n"
	.string "Sóc {STR_VAR_1}, un CAVALLER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "M'acompanya el meu fidel\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Puc demanar-te que t'uneixis a mi\n"
	.string "en una associació d'equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, t'agraeixo la teva confiança.\n"
	.string "M'encarregaré del registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Això és molt desafortunat…\p"
	.string "Esperaré amb il·lusió la propera\n"
	.string "oportunitat…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hola, sóc {STR_VAR_1},\n"
	.string "i sóc un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Tinc ara amb mi un {STR_VAR_2}\n"
	.string "que coneix el moviment {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "T'agrada el que veus?\n"
	.string "Per què no ets el meu company d'equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Gràcies!\n"
	.string "M'encarregaré del registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Els meus POKéMON són de primera…\n"
	.string "Llàstima que no ho puguis apreciar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\n"
	.string "Sóc {STR_VAR_1}, i sóc un EXPERT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Els POKéMON que he endurit són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què em dius de fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm!\n"
	.string "Ens registraré de seguida!\l"
	.string "Donem-ho tot tots dos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Espero que la teva elecció sigui\n"
	.string "realment correcta…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hola, hola.\n"
	.string "Sóc {STR_VAR_1}, i sóc una EXPERTA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "He criat els meus POKéMON a fons.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}:\n"
	.string "això és el que tinc.\p"
	.string "No t'agradaria fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bé, bé.\n"
	.string "M'encarregaré del registre de seguida.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Potser podem fer equip la propera\n"
	.string "vegada que ens veiem.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Sóc el DOMADOR DRACS {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "L'equip que he estat endurint és\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què et sembla?\n"
	.string "Vols ser el meu company?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "D'acord, ho donaré tot!\n"
	.string "Vaig a registrar-me, d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "No trobaràs gaires companys\n"
	.string "més durs que jo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Sóc l'ORNITÒLEG {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quins POKéMON tinc?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "No creus que faríem un bon\n"
	.string "equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Genial, gràcies!\n"
	.string "M'encarregaré del registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Els meus POKéMON i jo som forts.\n"
	.string "Quina decepció.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Sóc el NEN NINJA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "El meu equip POKéMON consta d'un\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Fem equip junts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Bé!\n"
	.string "Deixa'm anar a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Te'n penediràs de no tenir els meus\n"
	.string "durs POKéMON al teu costat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Hola!\n"
	.string "Sóc la SENYORA PARA-SOL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "M'acompanyen ara el meu {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "No són genials?\n"
	.string "Vols unir-te a nosaltres en un equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Moltes gràcies!\p"
	.string "Vaig a registrar-me al mostrador.\n"
	.string "No ens decebem mútuament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Els meus POKéMON són tremendament forts.\n"
	.string "Quina decepció…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hola.\n"
	.string "Sóc {STR_VAR_1}, i sóc un ENTUSIASTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "He trobat els meus POKéMON, sí.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}:\n"
	.string "són els que he trobat.\p"
	.string "T'interessaria formar\n"
	.string "un equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "D'acord!\n"
	.string "Entès!\p"
	.string "No trigaré gaire amb el registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Amb els POKéMON que he trobat, no hauríem\n"
	.string "perdut…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoi!\n"
	.string "Sóc el MARINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Deixa'm ensenyar-te el meu orgull!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "És clar que no em rebutjaràs.\n"
	.string "Farem equip, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "No n'esperava menys!\n"
	.string "Vaig a registrar-me ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Hauríem arrassat amb\n"
	.string "l'oposició! Quina llàstima!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hola, sóc {STR_VAR_1}.\n"
	.string "Sóc un COL·LECCIONISTA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Les joies de la meva col·lecció són\n"
	.string "el meu {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Genial, eh?\n"
	.string "Hauríem de fer equip junts.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, sí!\p"
	.string "Bé, no perdem temps.\n"
	.string "Vaig a registrar-nos a tots dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Bé, això és decebedor.\n"
	.string "No aprecies els meus POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Hola, sóc {STR_VAR_1}.\n"
	.string "Sóc un GUARDABOSC POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "M'acompanyen un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "No creus que faríem un equip\n"
	.string "impressionant?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Fantàstic!\n"
	.string "M'encarregaré del registre ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La propera vegada, tria els meus POKéMON,\n"
	.string "d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Em dic {STR_VAR_1}.\n"
	.string "Sóc una GUARDABOSC POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Deixa'm parlar-te del meu equip. Tinc\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "T'agradaria fer equip\n"
	.string "amb la meva petita colla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Ho donarem tot!\n"
	.string "Faré el registre ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Espero que triïs els meus POKéMON\n"
	.string "la propera vegada.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Encantada de conèixer-te. Sóc {STR_VAR_1}.\n"
	.string "Em considero una SENYORA AROMA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Viatjo amb un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Espero que et facin gràcia.\n"
	.string "T'agradaria ser el meu company?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Estic honorada per la teva acceptació.\n"
	.string "Vaig a registrar-me ara mateix.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Seria meravellós si poguéssim fer equip\n"
	.string "la propera vegada que ens veiem.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Vols saber qui sóc?\n"
	.string "Sóc {STR_VAR_1}, l'EXPLORADOR DE RUÏNES!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Els POKéMON que tinc amb mi són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Intrigant, eh?\n"
	.string "Què et sembla si ens associem?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Bona decisió!\n"
	.string "Vaig a fer el paperot del registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "Crec que els meus POKéMON són durs…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Sóc l'ENTRENADOR TOP {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Els POKéMON que tinc ara són un\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "Genial, eh?\p"
	.string "No creus que seria molt genial\n"
	.string "si féssim equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Genial!\n"
	.string "Faré el registre en un moment!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Pensava que hauríem format\n"
	.string "el millor equip de tots els temps.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Sóc l'ENTRENADORA TOP {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "L'equip que he estat criant té un\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Sona bé?\n"
	.string "Què et sembla si ens fem companys?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Sona genial!\n"
	.string "Millor que faci el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Estava pensant com seríem\n"
	.string "un equip dur de debò…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Eiii!\n"
	.string "Sóc {STR_VAR_1}, el POKéMANÍAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Què té un tio com jo?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1},\n"
	.string "això és el que tinc!\p"
	.string "Anem-hi!\n"
	.string "Arrassarem com a equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Bona decisió!\n"
	.string "Ens registraré a tots dos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Els meus POKéMON són brutals!\n"
	.string "No és culpa meva si te'n penediràs!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Ei, hola!\n"
	.string "Sóc l'EXCURSIONISTA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Saps què ha cuinat el meu entrenament?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Bé, què em dius?\n"
	.string "Vols fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "D'acord!\n"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promet-me que faràs equip amb mi\n"
	.string "la propera vegada que ens trobem.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Sóc {STR_VAR_1}, i sóc un CAMPISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "He estat criant un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Creus que seria divertit fer equip?\n"
	.string "Segur que sí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Sí!\n"
	.string "Vaig a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "La propera vegada, d'acord?\n"
	.string "Vull estar al teu equip.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Hola!\n"
	.string "Sóc {STR_VAR_1}, i sóc una PÍCNIC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Els POKéMON que he estat portant són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "T'interessa unir-te a mi\n"
	.string "en un equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Oh, gràcies!\n"
	.string "Faré el registre ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Seria genial si pogués unir-me a tu\n"
	.string "en una altra ocasió.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Sóc el PSÍQUIC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "La parella que he estat criant són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "T'agradaria formar un equip\n"
	.string "amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Per descomptat!\n"
	.string "M'encarregaré del registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Si ens tornem a trobar, m'agradaria\n"
	.string "fer equip amb tu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Sóc {STR_VAR_1}.\n"
	.string "Sóc una PSÍQUICA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}:\n"
	.string "són els meus deixebles.\p"
	.string "No t'intriga la idea de formar\n"
	.string "una associació d'equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Gràcies.\n"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Espero que hi haurà una altra ocasió\n"
	.string "per forjar una aliança.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Sóc l'ESTUDIANT {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} són la meva parella POKéMON.\p"
	.string "Si us plau, puc ser la teva\n"
	.string "companya d'equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, gràcies!\n"
	.string "Vaig a registrar-me al mostrador ara!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Si us plau?\n"
	.string "Puc unir-me a tu la propera vegada?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hola! Em dic {STR_VAR_1}!\n"
	.string "Sóc una CRIADORA POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Els POKéMON que he criat són un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Sona interessant?\n"
	.string "Què et sembla si fem equip, doncs?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "D'acord!\n"
	.string "Deixa'm el registre a mi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Has de fer equip amb mi la propera vegada,\n"
	.string "d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Sóc {STR_VAR_1}, i estic orgullosa de dir\n"
	.string "que sóc una POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Els adorables POKéMON que he criat són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "No són els més macs?\n"
	.string "Hauríem de fer equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Gràcies, bonic!\n"
	.string "Vaig a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Els meus adorables POKéMON són els millors,\n"
	.string "que ho sàpigues. Que molest!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hola, sóc la NEDADORA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} són els que he entrenat.\p"
	.string "Tu i jo, fem equip.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Genial!\n"
	.string "Ens registraré a tots dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Si ens tornem a trobar, em deus\n"
	.string "fer equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Què passa?\n"
	.string "Sóc {STR_VAR_1}, i sóc un TRIATLETA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Tinc un parell de POKéMON decents.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Seria genial fer equip junts,\n"
	.string "què et sembla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Ben dit!\n"
	.string "Espera mentre em registro, d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Espero que em deixis unir-me a tu\n"
	.string "la propera vegada, què et sembla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Sóc la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "un altre {STR_VAR_2} que sap\n"
	.string "usar {STR_VAR_1}. Aquesta és la meva parella.\p"
	.string "Què en penses?\n"
	.string "Faríem un bon equip, jo diria.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "M'agrada aquesta resposta!\n"
	.string "Faré el registre ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Em donaràs una altra oportunitat per formar\n"
	.string "una associació, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Ei, hola! Hola!\n"
	.string "Sóc {STR_VAR_1}, i sóc un NEDADOR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Mira què he estat criant!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Genial, eh?\n"
	.string "Seria genial fer equip també!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Molt agraït!\n"
	.string "Faré això del registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Si ens tornem a trobar, has de fer equip\n"
	.string "amb mi. Ho faràs, oi?$"

