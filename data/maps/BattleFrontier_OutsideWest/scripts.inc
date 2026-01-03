BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Aquesta és la CÚPULA COMBAT!\n"
	.string "El teu camí cap a la superestrella invencible!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Aquesta és la FÀBRICA COMBAT!\n"
	.string "Cerca els POKéMON més durs!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Aquest és el LLAC COMBAT!\n"
	.string "Tria un de tres camins!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Aquesta és la TORRE COMBAT.\p"
	.string "Els ENTRENADORS porten els seus POKéMON\n"
	.string "millor entrenats per a combats\l"
	.string "d'eliminació.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Hola, véns pel ferri?\n"
	.string "Em deixes veure el TIQUET?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} no té el TIQUET…\p"
	.string "Ho sento molt.\p"
	.string "Necessites un TIQUET per pujar\n"
	.string "al ferri.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} ha mostrat el TIQUET.\p"
	.string "Perfecte! Això és tot el que necessites!\p"
	.string "I on voldries anar?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "CIUTAT PORTUAL doncs!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "CIUTAT LLIRISFLOR doncs!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Si us plau, navega amb nosaltres\n"
	.string "un altre cop!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Si us plau, puja al ferri i espera\n"
	.string "la sortida.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Llavors, on voldries anar?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Sóc el millor de tots els meus amics.\n"
	.string "Però aquí…\l"
	.string "He estat inútil!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Vull anar a la TORRE COMBAT,\n"
	.string "però no la trobo tot i que tinc\l"
	.string "un mapa de la FRONTERA COMBAT.\p"
	.string "Aquest lloc és massa gran!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Volia acceptar un repte tan aviat\n"
	.string "com arribés aquí.\p"
	.string "Però pel camí, em vaig marejar…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "No és que qualsevol pugui venir\n"
	.string "aquí, ho saps?\p"
	.string "Només aquells ENTRENADORS reconeguts\n"
	.string "com a durs són portats aquí.\p"
	.string "Per això molts ENTRENADORS ni tan sols\n"
	.string "saben de la FRONTERA COMBAT.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Ei, germà…\p"
	.string "Estàs segur que podem fer reptes\n"
	.string "encara que no tinguem POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Eh…\n"
	.string "Segur que estarà bé.\p"
	.string "Crec…\p"
	.string "Però recordes aquell home gran que feia por?\n"
	.string "Va dir: “Us deixaré POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Aquesta és la FÀBRICA COMBAT.\n"
	.string "Pots llogar POKéMON forts allà.\p"
	.string "Però em fa pensar.\n"
	.string "Qui cria aquests POKéMON de lloguer?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Em fa por entrar al LLAC COMBAT\n"
	.string "per culpa de SEVIPER…\p"
	.string "P-però he vingut fins aquí, així que\n"
	.string "intentaré conquerir-ho tot!\l"
	.string "…Esgarrifança…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Juguem a pedra, paper, tisores!\n"
	.string "Un, dos, tres!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Bé! He guanyat!\n"
	.string "Acceptaré el repte del LLAC COMBAT!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, no…\n"
	.string "He perdut.\p"
	.string "Suposo que avui no tinc gaire sort.\n"
	.string "Deixaré el repte del LLAC COMBAT\l"
	.string "per a demà.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Crec que sóc l'única persona aquí que,\n"
	.string "per alguna raó desconeguda, triaria\l"
	.string "pescar abans que combatre.\p"
	.string "Eh? No pots pescar res aquí?\n"
	.string "Quina decepció…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Avui seguiré combatent, passi el\n"
	.string "que passi, fins que aconsegueixi\l"
	.string "un Símbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Vas a desafiar la CÚPULA\n"
	.string "COMBAT?\p"
	.string "Et desitjo molta sort.\n"
	.string "Que tots dos guanyem i ens\l"
	.string "trobem en els reptes.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Avi, aquí!\n"
	.string "La CÚPULA COMBAT és aquí!\l"
	.string "Endavant, avi!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, això és la CÚPULA COMBAT?\n"
	.string "No deixaré que em guanyin els\l"
	.string "CAVALLERS!\p"
	.string "Però on és l'entrada?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Aquí no hi havia res no fa gaire\n"
	.string "temps.\p"
	.string "Però ara mira aquest lloc! Increïble!\n"
	.string "Portaré la meva mare a veure-ho.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Per fi he arribat a la FRONTERA\n"
	.string "COMBAT!\p"
	.string "Segur que cridaré l'atenció amb\n"
	.string "el meu aspecte i habilitat!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Nyam, nyam…\p"
	.string "Sembla que aquesta plaça està plena\n"
	.string "de gent dura.\p"
	.string "Nyam, nyam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Crec, nyam…\p"
	.string "Fa un temps, vaig conèixer una noia\n"
	.string "més gran al LLAC COMBAT.\p"
	.string "Tenia uns ulls que feien por\n"
	.string "d'una manera molt rara.\p"
	.string "Crec, nyam…\p"
	.string "Es va enfadar molt: “Vols deixar de\n"
	.string "menjar!” I em va colpejar.\p"
	.string "Va ser una experiència de por\n"
	.string "que posava els pèls de punta.\p"
	.string "Crec, nyam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Eh? T'estàs escoltant?\n"
	.string "Això no és res!\p"
	.string "L'últim cop que el vaig animar,\n"
	.string "les nostres mirades es van creuar\l"
	.string "i van saltar espurnes!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Quèèèè?!\n"
	.string "Pfft!\p"
	.string "Això només va passar perquè\n"
	.string "jo estava asseguda al teu costat!\p"
	.string "L'AS DE LA CÚPULA només va mirar\n"
	.string "cap a nosaltres perquè els meus\l"
	.string "ànims eren molt forts!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, calla!\n"
	.string "Baixa el soroll!\p"
	.string "Les aficionades d'un dia hauríeu\n"
	.string "d'animar algun LÍDER DE GIMNÀS!\p"
	.string "L'AS DE LA CÚPULA és meu!\n"
	.string "L'únic ídol per a mi!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Aquella gent que es baralla allà…\p"
	.string "És difícil de creure, però un cop\n"
	.string "van ser ENTRENADORS, i bons.\p"
	.string "Eren increïblement durs i\n"
	.string "també eren famosos.\p"
	.string "Però van ser aniquilats per un cert\n"
	.string "ENTRENADOR en un torneig.\p"
	.string "Van ser tan derrotats que es\n"
	.string "van enamorar de l'ENTRENADOR.\p"
	.string "Ara són fans de l'ENTRENADOR.\n"
	.string "Van a animar el seu ídol a la\l"
	.string "CÚPULA COMBAT cada dia.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "He sentit un rumor que algú va veure\n"
	.string "un POKéMON amb una cua inusualment\l"
	.string "llarga en algun lloc de la FRONTERA.\p"
	.string "Ha de ser adorable. N'estic segura…\p"
	.string "Oh, els reptes poden esperar. Em sento\n"
	.string "impulsada a trobar la criatura!$"

