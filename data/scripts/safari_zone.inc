SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Vols sortir de la ZONA\n"
	.string "SAFARI ara mateix?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! S'ha acabat el temps!\n"
	.string "El teu Joc SAFARI ha acabat.$"

SafariZone_Text_OutOfBalls:
	.string "T'has quedat sense SAFARI BALLS.\n"
	.string "El teu Joc SAFARI ha acabat.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Vols posar un {POKEBLOCK}\n"
	.string "al DISPENSADOR de {POKEBLOCK}S?$"

SafariZone_Text_PokeblockStillHere:
	.string "El {STR_VAR_1} que vas deixar\n"
	.string "abans encara és aquí.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "El {STR_VAR_1} s'ha posat\n"
	.string "al DISPENSADOR de {POKEBLOCK}S.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Benvingut a la ZONA SAFARI!\p"
	.string "Aquí podràs veure moltes espècies\n"
	.string "de POKéMON poc comunes a HOENN.\p"
	.string "A més, els veuràs en el seu estat\n"
	.string "salvatge en hàbitats naturals.\p"
	.string "I el més important, hem obert les\n"
	.string "portes als ENTRENADORS POKéMON.\p"
	.string "T'animem a capturar POKéMON\n"
	.string "per quedar-te'ls!\p"
	.string "Entra i gaudeix de la ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Benvingut a la ZONA SAFARI!\n"
	.string "És la teva primera vegada aquí?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Entra i gaudeix de la ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Quan entres a la ZONA SAFARI,\n"
	.string "comences amb 30 SAFARI BALLS per\l"
	.string "capturar POKéMON.\p"
	.string "El Joc SAFARI acaba quan et quedes\n"
	.string "sense SAFARI BALLS, o quan has\l"
	.string "caminat 500 passos.\p"
	.string "Entra i gaudeix de la ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Benvingut a la ZONA SAFARI!\p"
	.string "Tot el que puguis capturar per 500¥!\n"
	.string "Vols jugar un Joc SAFARI?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "D'acord.\n"
	.string "Si us plau, juga un altre cop!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "No tens prou diners.\n"
	.string "Ho sento.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Seran 500¥, si us plau.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Aquí tens les teves SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} ha rebut 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "T'avisarem quan el teu joc\n"
	.string "s'hagi acabat.\p"
	.string "Fins llavors, passa-t'ho bé!\n"
	.string "Endavant amb la teva excursió salvatge!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Disculpa!\n"
	.string "La teva CAIXA del PC està plena.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Disculpa!\n"
	.string "Sembla que no tens un ESTOIG {POKEBLOCK}.\p"
	.string "El teu Joc SAFARI serà molt més\n"
	.string "fructífer si fas servir {POKEBLOCK}S.\p"
	.string "Si us plau, torna amb un ESTOIG {POKEBLOCK}.\p"
	.string "Pots obtenir un ESTOIG {POKEBLOCK} a la\n"
	.string "SALA DE CONCURSOS de CIUTAT LILYCOVE.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Encara et queda temps. Vols sortir\n"
	.string "de la ZONA SAFARI ara?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Si us plau, gaudeix de la resta de la\n"
	.string "teva aventura salvatge!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "D'acord.\p"
	.string "Em quedaré les teves SAFARI\n"
	.string "BALLS restants.\p"
	.string "Gràcies per jugar.\n"
	.string "Esperem tornar-te a veure.$"

SafariZone_South_Text_GoodLuck:
	.string "Bona sort!\p"
	.string "Si necessites res, no dubtis\n"
	.string "a dir-m'ho, si us plau!$"

SafariZone_South_Text_Boy:
	.string "Ho sabies?\p"
	.string "Si poses un {POKEBLOCK} en aquella caixa\n"
	.string "quadrada, els POKéMON s'hi acosten.$"

SafariZone_South_Text_Man:
	.string "Vull continuar endinsant-me, però\n"
	.string "m'he oblidat de portar una BICI.\p"
	.string "Alguna cosa em diu que POKéMON rars\n"
	.string "viuen a les zones exteriors.$"

SafariZone_Southwest_Text_Woman:
	.string "A vegades, quan llenço un {POKEBLOCK}\n"
	.string "als POKéMON, m'ignoren.\p"
	.string "Els POKéMON tenen gustos i aversions\n"
	.string "sobre el que mengen?$"

SafariZone_Northwest_Text_Man:
	.string "Buf… Buf…\n"
	.string "He… arribat fins aquí… però…\p"
	.string "Estic esgotat… No tinc energia\n"
	.string "per capturar POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "Estic en una missió per trobar POKéMON\n"
	.string "d'AIGUA que no es veuen a HOENN.\p"
	.string "Tens alguna idea d'on és el llac?$"

SafariZone_North_Text_Man:
	.string "Capturaré molts POKéMON rars aquí\n"
	.string "i els intercanviaré amb els meus amics!$"

SafariZone_South_Text_Youngster:
	.string "He posat un {POKEBLOCK} al DISPENSADOR.\n"
	.string "Però sembla que ha desaparegut.\p"
	.string "Suposo que els POKéMON se l'han\n"
	.string "menjat sense que me n'adonés.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "CONSELL D'ENTRENADOR DE LA ZONA SAFARI!\p"
	.string "Llença {POKEBLOCK}S als POKéMON salvatges\n"
	.string "perquè sigui menys probable que fugin.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Descansa els teus peus cansats.”\n"
	.string "CASA DE DESCANS$"

SafariZone_RestHouse_Text_Youngster:
	.string "No tinc cap {POKEBLOCK}, però he capturat\n"
	.string "un bon nombre de POKéMON.\p"
	.string "Pots millorar les teves opcions de\n"
	.string "captura acostant-te més a ells\l"
	.string "abans de llençar una SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Si fas servir {POKEBLOCK}S, els POKéMON\n"
	.string "salvatges no fugiran tan ràpid.\p"
	.string "No té gaire sentit donar {POKEBLOCK}S a\n"
	.string "POKéMON que no fugen fàcilment.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Si poses un {POKEBLOCK} al DISPENSADOR,\n"
	.string "els POKéMON s'hi senten atrets.\p"
	.string "Crec que POKéMON amb un tipus de\n"
	.string "naturalesa similar són atrets per\l"
	.string "un cert {POKEBLOCK}.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Aquesta zona encara està en obres.\n"
	.string "És una zona restringida, ho sento!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "El projecte d'expansió de la ZONA\n"
	.string "SAFARI ja està acabat.\p"
	.string "Esperem que gaudeixis de la nova zona.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Aquesta zona encara està en obres.\n"
	.string "És una zona restringida, ho sento!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Uau! Visca! No havia vist cap\n"
	.string "d'aquests POKéMON abans!$"

SafariZone_Southeast_Text_FatMan:
	.string "Els POKéMON d'aquesta zona són\n"
	.string "tots nous per a mi.\p"
	.string "I puc capturar aquests POKéMON\n"
	.string "rars! Massa genial!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Els POKéMON d'aquí semblen ser\n"
	.string "d'algun lloc fora de HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Només em queden un parell de\n"
	.string "SAFARI BALLS.\p"
	.string "M'està costant decidir\n"
	.string "què hauria de capturar.$"

SafariZone_Northeast_Text_Woman:
	.string "He sentit que pots veure PIKACHU aquí.\n"
	.string "On pot estar?$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, vaja!\n"
	.string "Sembla que no puc capturar res!\p"
	.string "Acabaré malgastant el preu d'entrada\n"
	.string "si no capturo alguna cosa!$"
