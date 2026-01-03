LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MAMA: Veus, {PLAYER}?\n"
	.string "No està bé aquí dins també?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Els POKéMON dels de la mudança fan tota\n"
	.string "la feina de traslladar-nos i netejar.\l"
	.string "Això és molt pràctic!\p"
	.string "{PLAYER}, la teva habitació és a dalt.\n"
	.string "Ves a veure-la, filla!\p"
	.string "El PAPA et va comprar un rellotge nou\n"
	.string "per commemorar la nostra mudança.\l"
	.string "No t'oblidis de posar-lo en hora!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAMA: Bé, {PLAYER}?\p"
	.string "No tens ganes de veure\n"
	.string "la teva pròpia habitació?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAMA: {PLAYER}.\p"
	.string "Ves a posar el rellotge en hora, filla.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAMA: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Ràpid! Vine de pressa!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAMA: Mira! És el GIMNÀS PETÀLIA!\n"
	.string "Potser sortirà el PAPA!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAMA: Oh… S'ha acabat.\p"
	.string "Crec que el PAPA hi era, però ens\n"
	.string "l'hem perdut. Quina llàstima.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Ah, sí.\n"
	.string "Un amic del PAPA viu al poble.\p"
	.string "Es diu PROF. BEDOLL.\p"
	.string "Viu just al costat, així que hauries\n"
	.string "d'anar a presentar-te.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAMA: Fins després, filla!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAMA: T'has presentat al\n"
	.string "PROF. BEDOLL?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAMA: Com estàs, {PLAYER}?\n"
	.string "Et veig una mica cansada.\p"
	.string "Crec que hauries de descansar una mica.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAMA: Cuida't, filla!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAMA: Oh? El PAPA t'ha donat la INSÍGNIA?\p"
	.string "Doncs aquí tens una cosa de la MAMA!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "No t'esforcis massa, filla.\n"
	.string "Sempre pots tornar a casa.\p"
	.string "Endavant, filla!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAMA: Què és això, filla? Un POKéNAV?\n"
	.string "Algú de DEVON te l'ha donat?\p"
	.string "Bé, filla, què et sembla si registres\n"
	.string "la teva mare?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Has registrat la MAMA\n"
	.string "al POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "ENTREVISTADOR: …Us portem aquest\n"
	.string "reportatge des de davant del GIMNÀS PETÀLIA.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Hi ha una pel·lícula a la tele.\p"
	.string "Dos homes estan ballant sobre un\n"
	.string "teclat de piano gegant.\p"
	.string "Millor que em mogui!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "És el manual d'instruccions de les\n"
	.string "BAMBAS PER CÓRRER.\p"
	.string "“Prem el Botó B per córrer mentre\n"
	.string "portes les BAMBAS PER CÓRRER.\p"
	.string "“Lliga't les BAMBAS PER CÓRRER i\n"
	.string "surt a córrer!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAPA: Hm?\p"
	.string "Ei, és {PLAYER}!\p"
	.string "Fa temps que no et veia,\n"
	.string "però sembla que estàs… més forta.\p"
	.string "Aquesta és la impressió que tinc.\n"
	.string "Però el teu vell pare encara no es rendeix!\p"
	.string "Ah, sí, tinc una cosa per a tu.\n"
	.string "Això t'ha arribat d'algú anomenat\l"
	.string "SR. AIGUAMAR.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAPA: Hm, un BITLLET per al ferri?\p"
	.string "Si no recordo malament, hi ha ports de\n"
	.string "ferri a PORTLAMAR i LLILAPORT.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Millor que torni al GIMNÀS PETÀLIA.\p"
	.string "MAMA, gràcies per cuidar la casa\n"
	.string "mentre sóc fora.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAMA: Aquest PAPA teu…\p"
	.string "Torna a casa per primera vegada en molt\n"
	.string "de temps, però només parla de POKéMON.\p"
	.string "Hauria de relaxar-se i quedar-se més temps.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MAMA: Això són notícies d'última hora?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Us portem aquesta notícia\n"
	.string "d'emergència!\p"
	.string "En diversos llocs de HOENN, s'han\n"
	.string "rebut informes d'un POKéMON de\l"
	.string "color BZZT… volant.\p"
	.string "La identitat d'aquest POKéMON és\n"
	.string "actualment desconeguda.\p"
	.string "Ara tornem a la programació\n"
	.string "regular de pel·lícules.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAMA: {PLAYER}, ho has sentit?\p"
	.string "De quin color ha dit el presentador\n"
	.string "que era aquell POKéMON?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAMA: Vaja, mira tu!\n"
	.string "Encara hi ha POKéMON desconeguts.$"
