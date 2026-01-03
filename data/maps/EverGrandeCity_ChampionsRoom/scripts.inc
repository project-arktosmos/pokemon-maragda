EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "BLASCO: Benvingut, {PLAYER}{KUN}.\p"
	.string "Aquell incident a ALGÈPOLIS…\n"
	.string "Va ser una feina superba, posar fi\l"
	.string "a aquella crisi tot sol.\p"
	.string "Oi!\p"
	.string "No seria just dir que tu sol\n"
	.string "vas acabar amb la crisi.\p"
	.string "Vas superar aquella situació difícil\n"
	.string "treballant com un de sol amb els POKéMON.\p"
	.string "Els ENTRENADORS criem POKéMON donant-los\n"
	.string "objectes i ensenyant-los noves\l"
	.string "tècniques de combat.\p"
	.string "Però nosaltres també aprenem moltes\n"
	.string "coses dels POKéMON.\p"
	.string "I aquí és on els teus assoliments\n"
	.string "es posen a prova contra el que\l"
	.string "altres com tu han aconseguit.\p"
	.string "Ara!\p"
	.string "Qui pot ballar més elegantment amb\n"
	.string "els seus POKéMON a HOENN?\p"
	.string "Ensenya-m'ho aquí i ara!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Jo, el CAMPIÓ, caic derrotat…\p"
	.string "Ha estat una feina meravellosa.\n"
	.string "Has estat elegant, exasperantment.\l"
	.string "I tanmateix ha estat absolutament gloriós!\p"
	.string "Felicitats, {PLAYER}{KUN}!\p"
	.string "Ets un ENTRENADOR POKéMON\n"
	.string "veritablement noble!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "BLASCO: Els POKéMON que has enviat\n"
	.string "a combatre…\p"
	.string "A vegades ballaven com una brisa\n"
	.string "de primavera, i a vegades colpejaven\l"
	.string "com un llamp.\p"
	.string "Va ser amb elegància lleugera, però\n"
	.string "segura, que vas guiar els teus POKéMON.\p"
	.string "Fins i tot jo em vaig sentir enlluernat\n"
	.string "per la teva actuació magistral!\p"
	.string "Ara et trobes al cim gloriós\n"
	.string "de la LLIGA POKéMON.\p"
	.string "Ara et proclamo el nou\n"
	.string "de la regió HOENN…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAIRA: {PLAYER}{KUN}!\p"
	.string "Aquí tens un consell abans de desafiar\n"
	.string "al CAMPIÓ…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAIRA: Eh?\n"
	.string "Què, què, què?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Pot ser que…\l"
	.string "Ja ha acabat?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BLAI: {PLAYER}!\p"
	.string "T'agradaria un consell abans\n"
	.string "de desafiar al CAMPIÓ?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BLAI: {PLAYER}…\p"
	.string "M'estàs dient…\n"
	.string "Que has guanyat al CAMPIÓ?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BEDOLL: Veus?\n"
	.string "Què et vaig dir, {RIVAL}?\p"
	.string "No et vaig dir que no calia\n"
	.string "preocupar-se per {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, finalment ho has aconseguit.\p"
	.string "Quan vaig sentir que havies derrotat\n"
	.string "el teu propi pare al GIMNÀS PETÀLIA,\l"
	.string "vaig pensar que potser tenies una oportunitat…\p"
	.string "Però pensar que realment t'has convertit\n"
	.string "en el CAMPIÓ!\p"
	.string "Ah, sí!\p"
	.string "Què ha passat amb la teva POKéDEX?\n"
	.string "Deixa-m'ho veure.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BEDOLL: De tota manera,\n"
	.string "felicitats!\p"
	.string "Ara, entra amb orgull a la sala final!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "BLASCO: {PLAYER}{KUN}…\p"
	.string "No, deixa que ho reformuli bé.\p"
	.string "El nou CAMPIÓ!\p"
	.string "Vine amb mi.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "BLASCO: Ho sento, però…\p"
	.string "A partir d'aquí, només els ENTRENADORS\n"
	.string "que s'han convertit en CAMPIONS poden entrar.\p"
	.string "Haureu d'esperar fora amb\n"
	.string "el PROF. BEDOLL.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAIRA: Uf…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Només estic broma! Està bé!\n"
	.string "Són les regles!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Sincerament, felicitats!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BLAI: Què?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "No s'hi pot fer res si són les regles.\p"
	.string "{PLAYER}, ben fet!\n"
	.string "Felicitats!$"

