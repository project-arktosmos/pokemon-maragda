@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Aquest POKéMON va guanyar el CONCURS\n"
	.string "DE BELLESA aquí abans.\p"
	.string "Bé, saps què? Avui, l'he fet\n"
	.string "guanyar un CONCURS D'ENGINY!\p"
	.string "Les meves habilitats fins i tot\n"
	.string "m'espanten…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "He participat en molts CONCURSOS,\n"
	.string "així que estic veient com funcionen.\p"
	.string "Si ets en un CONCURS DE CARISMA,\n"
	.string "els moviments carismàtics triomfen.\p"
	.string "Però els moviments intel·ligents i\n"
	.string "bonics no funcionen bé, per exemple.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Aquell jove que ha guanyat abans tenia\n"
	.string "un munt de {POKEBLOCK}S diferents.\p"
	.string "Pots guanyar si tens tants\n"
	.string "d'aquests?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Uau, aquest lloc no és enorme!\p"
	.string "La tensió a l'aire… No és com\n"
	.string "una sala de CONCURSOS d'un poblet.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "PRESENTADOR: D'acord, POKéMON\n"
	.string "ENGINYOSOS i els seus ENTRENADORS,\l"
	.string "esteu a punt?!\p"
	.string "Feu la millor exhibició!\n"
	.string "Exhibim-nos!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JURAT: Estàs gaudint d'aquest CONCURS?\p"
	.string "Torna amb tres amics, i tots podreu\n"
	.string "entrar en un CONCURS!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ai, ai, ai…\n"
	.string "He entrat al CONCURS equivocat.\p"
	.string "He inscrit aquest POKéMON dur al\n"
	.string "CONCURS D'ENGINY…\p"
	.string "Vinga, impressiona'ls amb un\n"
	.string "TRENCAMENT intel·ligent.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "He passat molts anys, i tota la meva\n"
	.string "saviesa, criant aquest POKéMON\l"
	.string "perquè fos enginyós.\p"
	.string "No serà fàcilment vençut pel POKéMON\n"
	.string "d'algun jovenet.\p"
	.string "Estimada esposa, ho estàs veient?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Aquí està!\p"
	.string "Si el meu POKéMON fa un moviment\n"
	.string "enginyós ara, l'emoció del públic\l"
	.string "arribarà al màxim!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, no!\p"
	.string "La SANGONERA del meu ZUBAT és tan\n"
	.string "bonica que l'he usat una i altra vegada!\p"
	.string "Però aquesta gent tan dolenta no\n"
	.string "l'aprecia gens!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! Ets preciós, avi!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Fins i tot quan ENTRENADORS inscriuen\n"
	.string "el mateix tipus de POKéMON, tots\l"
	.string "semblen usar moviments diferents.\p"
	.string "És igual que la manera com la gent té\n"
	.string "estils diferents per combatre.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Penso que els POKéMON semblen més\n"
	.string "llestos que els seus ENTRENADORS. Molt.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Quan tot està dit i fet, encara adoro\n"
	.string "els CONCURSOS D'ENGINY.\p"
	.string "Aquest color verd intel·lectual…\n"
	.string "És tan… Tan… Guai.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "PRESENTADOR: Tu també entres al\n"
	.string "CONCURS DE BELLESA? Bona sort!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JURAT: Ah, cada POKéMON aquí és\n"
	.string "un model de bellesa prístina!\p"
	.string "Ui, gairebé m'oblido de puntuar-los!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un POKéMON tan bell…\n"
	.string "No n'hi ha cap altre com ell.\p"
	.string "Tots els ulls estaran enganxats\n"
	.string "a la meva bellesa.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Uaaaaah!\p"
	.string "He raspallat i arreglat el meu POKéMON\n"
	.string "amb cura per a aquest CONCURS…\p"
	.string "Però m'he passat…\n"
	.string "El pelatge del meu POKéMON s'ha fet\l"
	.string "malbé…\p"
	.string "Què hauria de fer?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Aquest RAIG AURORA és tan enlluernador\n"
	.string "que el JURAT no el podrà veure.\p"
	.string "Eh, espera un moment…\n"
	.string "Això no tindrà sentit, llavors!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Aquest POKéMON tan bonic s'assembla\n"
	.string "a mi quan era més jove.\p"
	.string "Just quan vaig dir això, el meu marit\n"
	.string "va escopir el cafè que bevia.\p"
	.string "He dit alguna cosa divertida?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Saps, si guanyo un CONCURS DE\n"
	.string "BELLESA, és clar que em fa\l"
	.string "feliç. Més del normal, almenys.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Uahahahah!\p"
	.string "Mira tots aquests POKéMON tan\n"
	.string "bonics!\l"
	.string "M'encanta aquest tipus de glamur!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "No sempre pots guanyar només amb\n"
	.string "la bellesa.\p"
	.string "Has d'arreglar el teu POKéMON perquè\n"
	.string "sigui brillant com el meu.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "PRESENTADOR: Ep! Hola!\n"
	.string "Estem enmig d'un CONCURS!\p"
	.string "Si us plau, inscriu-te al mostrador\n"
	.string "i surt per allà, d'acord?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JURAT: Oh, quines exhibicions tan\n"
	.string "encantadores i boniques!\p"
	.string "Mare meva! Quina exhibició de JOC\n"
	.string "AQUÀTIC tan perfectament adorable!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, no… El meu dolç AZURILL s'ha\n"
	.string "distret amb un altre POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "El meu POKéMON mai ha guanyat un\n"
	.string "combat, però en un CONCURS, alerta!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "La DANSA PÈTALS del meu POKéMON\n"
	.string "és una meravella d'elegància.\p"
	.string "No deixaré que ningú pertorbi\n"
	.string "la seva actuació.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Els POKéMON de tothom són molt bonics.\p"
	.string "Però, si el meu POKéMON fes una\n"
	.string "exhibició bonica…\p"
	.string "Estic segur que seria molt més\n"
	.string "bonic que els altres.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "El meu fill és en aquest CONCURS.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Vinga, cielo. A per ells!\n"
	.string "El teu POKéMON és el millor!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Crec que aquella noia d'allà és\n"
	.string "la més bonica de totes.\p"
	.string "Què? Estan jutjant els POKéMON\n"
	.string "per la seva aparença?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, veient tots aquests POKéMON\n"
	.string "tan bonics, em fan voler tenir-ne un!\p"
	.string "Vaig a atrapar-ne alguns!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "ESCENARI CONCURS BELLESA\n"
	.string "DEIXA'T SEDUIR PELS POKéMON BELLS!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "ESCENARI CONCURS SIMPATIA\n"
	.string "DEIXA'T ENCANTAR PELS POKéMON BONICS!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "ESCENARI CONCURS D'ENGINY\n"
	.string "DEIXA'T IMPRESSIONAR PELS POKéMON\l"
	.string "ENGINYOSOS!$"

