BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "On es posa a prova l'esperit de combat\n"
	.string "dels ENTRENADORS!\p"
	.string "Et dono la benvinguda a l'ARENA COMBAT!\p"
	.string "Sóc la teva guia al Torneig KO Establert!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Ara, vols acceptar el repte de\n"
	.string "l'ARENA COMBAT?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Esperem el teu repte en una\n"
	.string "altra ocasió!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "A l'ARENA COMBAT, fem el\n"
	.string "Torneig KO Establert.\p"
	.string "Tots els participants entren amb un\n"
	.string "equip de tres POKéMON.\p"
	.string "Els tres POKéMON s'han de col·locar\n"
	.string "en l'ordre en què apareixeran.\p"
	.string "Durant el combat, els POKéMON apareixeran\n"
	.string "d'un en un en l'ordre preestablert.\p"
	.string "Un cop un POKéMON entra en combat, ha de\n"
	.string "romandre fins que el combat es decideixi.\p"
	.string "Si un combat no es decideix en tres\n"
	.string "torns, va a judici.\p"
	.string "Si vols interrompre el repte,\n"
	.string "si us plau, desa la partida.\p"
	.string "Si no deses, no podràs continuar\n"
	.string "amb el teu repte.\p"
	.string "Si aconsegueixes vèncer set\n"
	.string "ENTRENADORS seguits,\l"
	.string "et donarem Punts de Combat.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Abans de portar-te a l'ARENA COMBAT,\n"
	.string "has de desar. D'acord?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "L'ARENA COMBAT ofereix dos nivells\n"
	.string "de repte, Nivell 50 i Nivell Obert.\l"
	.string "Quin tries?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Molt bé, ara selecciona els\n"
	.string "teus tres POKéMON, si us plau.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Estimat lluitador!\p"
	.string "No tens els tres POKéMON\n"
	.string "requerits per entrar.\p"
	.string "Per qualificar-te, has de portar tres\n"
	.string "tipus diferents de POKéMON.\p"
	.string "Tampoc han de portar els mateixos\n"
	.string "tipus d'objectes.\p"
	.string "ELS OUS{STR_VAR_1} no són elegibles.\p"
	.string "Quan hagis fet els teus preparatius,\n"
	.string "si us plau, torna.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Estimat lluitador!\p"
	.string "No tens els tres POKéMON\n"
	.string "requerits per entrar.\p"
	.string "Per qualificar-te, has de portar tres\n"
	.string "tipus diferents de POKéMON.\p"
	.string "Els tres POKéMON diferents\n"
	.string "han de ser de Nivell 50 o inferior.\p"
	.string "Tampoc han de portar els mateixos\n"
	.string "tipus d'objectes.\p"
	.string "ELS OUS{STR_VAR_1} no són elegibles.\p"
	.string "Quan hagis fet els teus preparatius,\n"
	.string "si us plau, torna.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Ara et guiaré a\n"
	.string "l'ARENA COMBAT.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Estimat lluitador!\p"
	.string "No vas desar la partida abans\n"
	.string "d'apagar, oi?\p"
	.string "És desafortunat, però això ha\n"
	.string "resultat en la teva desqualificació\l"
	.string "del teu repte.\p"
	.string "Pots, és clar, començar amb un repte\n"
	.string "nou.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Et felicitem per la teva esplèndida\n"
	.string "ratxa de victòries sobre set ENTRENADORS!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "La teva fita s'enregistrarà.\n"
	.string "Espera mentre deso la partida.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "En commemoració de la teva ratxa de 7,\n"
	.string "et donem aquest premi.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} ha rebut el premi\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh?\n"
	.string "La teva MOTXILLA sembla plena.\p"
	.string "Et recomano fer espai i tornar\n"
	.string "pel teu premi.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Moltes gràcies per participar!\p"
	.string "Espera mentre deso la partida.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Esperem el teu repte en una\n"
	.string "altra ocasió!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Hem estat esperant la teva\n"
	.string "arribada.\p"
	.string "Abans de portar-te a l'ARENA COMBAT,\n"
	.string "he de desar la partida.\l"
	.string "Si us plau, espera.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Vols enregistrar l'últim combat de\n"
	.string "l'ARENA COMBAT al PASSI FRONTERA?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Vaig perdre per decisió de l'ÀRBITRE…\p"
	.string "No crec que fos bona idea usar només\n"
	.string "moviments defensius i no atacar…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Vaig guanyar per judici!\p"
	.string "Encertar cops de manera consistent\n"
	.string "als POKéMON de l'oponent va funcionar!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "El nostre combat es va declarar empat.\p"
	.string "Quan es va acabar el temps, tant el meu\n"
	.string "POKéMON com el de l'oponent tenien\l"
	.string "aproximadament els mateixos PS restants.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "A l'ARENA COMBAT, l'ordre dels\n"
	.string "POKéMON és totalment important.\p"
	.string "Per exemple, si el teu primer POKéMON\n"
	.string "té certs desavantatges de tipus,\l"
	.string "intenta que el teu segon POKéMON tingui\l"
	.string "moviments que siguin súper eficaços\l"
	.string "contra el primer.\p"
	.string "Crec que serà una bona manera de\n"
	.string "fer un equip efectiu.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Les regles del Torneig KO Establert.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Quin apartat vols llegir?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "El Torneig KO Establert té regles\n"
	.string "especials, a diferència dels combats normals.\p"
	.string "Primer, un combat dura només\n"
	.string "tres torns.\p"
	.string "Si el resultat no es decideix després\n"
	.string "de tres torns, va a judici.\p"
	.string "L'ÀRBITRE triarà el guanyador\n"
	.string "basant-se en com van combatre els POKéMON.\p"
	.string "A més, un POKéMON no es pot canviar\n"
	.string "fins que es decideixi el seu combat.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "El primer factor de judici és “Ment.”\n"
	.string "Aquest factor avalua com d'agressius\l"
	.string "van ser els lluitadors.\p"
	.string "El judici es basa en la freqüència amb\n"
	.string "què els ENTRENADORS van ordenar l'ús\l"
	.string "de moviments ofensius.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "El segon factor de judici és “Habilitat.”\n"
	.string "Aquest factor avalua com d'efectivament\l"
	.string "es van usar els moviments POKéMON.\p"
	.string "Si un moviment va funcionar bé,\n"
	.string "la puntuació d'Habilitat puja.\p"
	.string "Si un moviment va fallar, la puntuació\n"
	.string "d'Habilitat baixa.\p"
	.string "Si va ser un moviment ofensiu, la puntuació\n"
	.string "puja si va ser “súper eficaç” i baixa\l"
	.string "si va ser “poc eficaç.”\p"
	.string "La puntuació d'Habilitat no pujarà per\n"
	.string "moviments com PROTECCIÓ i DETECCIÓ.\p"
	.string "Si l'oponent va usar PROTECCIÓ o\n"
	.string "DETECCIÓ, i el teu POKéMON no va encertar,\l"
	.string "la seva puntuació d'Habilitat no baixarà.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "El tercer factor de judici és “Cos.”\n"
	.string "Aquest factor es basa en quants PS\l"
	.string "quedaven al final del combat.\p"
	.string "La puntuació té en compte quants PS\n"
	.string "tenia un POKéMON a l'inici del combat,\l"
	.string "i els que quedaven al final.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Una victòria arrabassada al MAGNAT\n"
	.string "DE L'ARENA, i una escombrada de set!\p"
	.string "Et felicitem pel teu repte\n"
	.string "més esplèndid!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Estimat lluitador, en reconeixement\n"
	.string "del teu esperit infatigable, si us plau\l"
	.string "accepta aquests Punt(s) de Combat.$"
