BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "És el teu primer cop aquí?\n"
	.string "Si us plau, vine per aquí!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "La primera línia dels combats POKéMON!\n"
	.string "Benvingut a la FRONTERA COMBAT!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Per als visitants nous, emetem\n"
	.string "el PASSI FRONTERA.\p"
	.string "Serveix per a totes les instal·lacions\n"
	.string "de la FRONTERA COMBAT.\p"
	.string "Aquí el tens!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} ha obtingut\n"
	.string "el PASSI FRONTERA.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} ha posat la TARGETA ENTRENADOR\n"
	.string "al PASSI FRONTERA.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Esperem que gaudeixis de tot el que\n"
	.string "la FRONTERA COMBAT pot oferir!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Vaja, però si és {PLAYER}{KUN}!\n"
	.string "Has vingut fins aquí!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIA: Oh! SR. SCOTT!\n"
	.string "Bon dia, senyor!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: És genial veure't aquí,\n"
	.string "de debò!\p"
	.string "Espero que et prenguis el teu temps\n"
	.string "i exploris per tot arreu.\p"
	.string "Naturalment, espero que també experimentis\n"
	.string "l'essència pura del combat.\p"
	.string "També tinc les meves habitacions aquí,\n"
	.string "així que visita'm si tens temps.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Sóc el teu guia de les diverses\n"
	.string "instal·lacions de la FRONTERA COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Sobre quina vols aprendre?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "És la torre gegantina considerada\n"
	.string "el símbol de la FRONTERA COMBAT.\p"
	.string "Hi ha quatre tipus de SALES DE COMBAT\n"
	.string "a la torre per a combats INDIVIDUALS,\l"
	.string "DOBLES, MULTI i LINK MULTI.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "La CÚPULA COMBAT és l'edifici gran\n"
	.string "amb forma d'ou gegant.\p"
	.string "S'hi celebren esdeveniments anomenats\n"
	.string "Tornejos de Combat.\p"
	.string "Els Tornejos de Combat s'ofereixen en\n"
	.string "dos modes--per a combats INDIVIDUALS\l"
	.string "i DOBLES.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "El PALAU COMBAT és l'edifici vermell\n"
	.string "a la dreta de la FRONTERA COMBAT.\p"
	.string "Hi ha dos tipus de SALES DE COMBAT\n"
	.string "per a combats INDIVIDUALS i DOBLES.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "L'ARENA COMBAT és l'edifici estil dojo\n"
	.string "al centre-dreta de la FRONTERA\l"
	.string "COMBAT.\p"
	.string "S'hi celebra un esdeveniment anomenat\n"
	.string "el Torneig K.O.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "La FÀBRICA COMBAT és l'edifici gran\n"
	.string "més proper a nosaltres.\p"
	.string "S'hi celebra un esdeveniment anomenat\n"
	.string "l'Intercanvi de Combat.\p"
	.string "L'Intercanvi de Combat s'ofereix en\n"
	.string "dos modes per a combats INDIVIDUALS\l"
	.string "i DOBLES.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "El SERP COMBAT és l'edifici amb forma\n"
	.string "de POKéMON al centre-esquerra de\l"
	.string "la FRONTERA COMBAT.\p"
	.string "S'hi celebra un esdeveniment anomenat\n"
	.string "l'Elecció de Combat.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "La PIRÀMIDE COMBAT és l'enorme\n"
	.string "piràmide.\p"
	.string "S'hi celebra un esdeveniment anomenat\n"
	.string "la Cerca de Combat.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "La SALA DE RÀNQUING es troba prop\n"
	.string "de la TORRE COMBAT.\p"
	.string "Allà, pots veure els rècords més\n"
	.string "fantàstics dels ENTRENADORS que\l"
	.string "han afrontat els molts desafiaments\l"
	.string "de la FRONTERA COMBAT.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "El RACÓ D'INTERCANVI es troba prop\n"
	.string "de la TORRE COMBAT.\p"
	.string "Els Punts de Combat que has guanyat a\n"
	.string "la FRONTERA COMBAT es poden canviar\l"
	.string "per premis fabulosos allà.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Sóc el teu guia de les regles bàsiques\n"
	.string "comunes a tots els desafiaments\l"
	.string "oferts per les instal·lacions de\l"
	.string "la FRONTERA COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Sobre què vols aprendre?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Tots els desafiaments a les instal·lacions\n"
	.string "de la FRONTERA COMBAT tenen dos\l"
	.string "modes--Nivell 50 i Nivell Obert.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "El mode Nivell 50 està obert a POKéMON\n"
	.string "fins al Nivell 50 inclòs.\p"
	.string "Tingues en compte, però, que cap\n"
	.string "ENTRENADOR que enfrontis tindrà\l"
	.string "cap POKéMON per sota del Nivell 50.\p"
	.string "Aquest mode és el nivell d'entrada\n"
	.string "per a combats a la FRONTERA COMBAT.\p"
	.string "Per començar, esperem que desafiïs\n"
	.string "aquest mode.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "El mode Nivell Obert no posa cap límit\n"
	.string "als nivells dels POKéMON que entren\l"
	.string "als desafiaments.\p"
	.string "Els nivells dels teus oponents\n"
	.string "s'ajustaran per coincidir amb els\l"
	.string "nivells dels teus POKéMON.\p"
	.string "Tanmateix, cap ENTRENADOR que enfrontis\n"
	.string "tindrà cap POKéMON per sota del Nivell 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Pràcticament qualsevol tipus de POKéMON\n"
	.string "pot afrontar els desafiaments.\p"
	.string "Els OUS i certs tipus de POKéMON,\n"
	.string "però, no estan permesos.\p"
	.string "El nombre de POKéMON requerits per als\n"
	.string "desafiaments depèn de la instal·lació.\p"
	.string "A totes les instal·lacions, però, no es\n"
	.string "permeten dos o més POKéMON del\l"
	.string "mateix tipus.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Quan entris a un desafiament d'una\n"
	.string "instal·lació de la FRONTERA COMBAT,\l"
	.string "els POKéMON no poden portar el mateix\l"
	.string "tipus d'objecte.\p"
	.string "Assegura't que tots els POKéMON que\n"
	.string "entren al desafiament portin\l"
	.string "objectes diferents.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Sóc el teu guia del PASSI FRONTERA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Sobre quina vols aprendre?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Hi ha set instal·lacions a la\n"
	.string "FRONTERA COMBAT.\p"
	.string "Els ENTRENADORS que guanyin reconeixement\n"
	.string "per les seves habilitats poden ser\l"
	.string "recompensats amb símbols de cada\l"
	.string "instal·lació.\p"
	.string "Per guanyar un símbol, els ENTRENADORS\n"
	.string "poden haver de derrotar altres\l"
	.string "ENTRENADORS seguits, i guanyar\l"
	.string "esdeveniments repetidament.\p"
	.string "No és fàcil guanyar símbols.\n"
	.string "Et desitjo molta sort!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "És possible gravar un combat\n"
	.string "al teu PASSI FRONTERA.\p"
	.string "Pots gravar un combat que hagis tingut\n"
	.string "amb un amic o amics.\p"
	.string "O pots gravar un combat realitzat\n"
	.string "a la FRONTERA COMBAT excloent\l"
	.string "els combats al SERP COMBAT o a\l"
	.string "la PIRÀMIDE COMBAT.\p"
	.string "Pots triar gravar el teu combat\n"
	.string "al final d'una batalla.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Els Punts de Combat són recompenses\n"
	.string "per als ENTRENADORS que hagin lluitat\l"
	.string "excel·lentment a la FRONTERA COMBAT.\p"
	.string "Pots canviar els teus Punts de Combat\n"
	.string "per premis al RACÓ D'INTERCANVI.$"

