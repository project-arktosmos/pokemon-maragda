SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Hi ha un llit…\n"
	.string "Fem un descans.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Sovint navego a CALAGUA.\p"
	.string "M'agrada anar als CONCURSOS,\n"
	.string "ja saps.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Ha estat un combat agradable!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "M'emociono tant imaginant quins tipus\n"
	.string "de POKéMON veuré al proper CONCURS.\l"
	.string "L'anticipació m'entusiasma!$"

SSTidalRooms_Text_MicahIntro:
	.string "Els teus amics són forts?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Els teus amics són, certament, forts.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Els amics no han de ser humans.\n"
	.string "Per a mi, els POKéMON són amics valuosos!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Nen…\n"
	.string "Has trucat a la porta?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Una derrota s'ha d'acceptar sense pressa\n"
	.string "ni pànic.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "No alterar-se mai en cap situació és\n"
	.string "el codi de conducta del CAVALLER.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Em fa una mica de vergonya, però…\n"
	.string "Et mostrarem el nostre poder amorós!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Ai…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: És la primera vegada que el nostre\n"
	.string "poder amorós no ha pogut prevaler!\l"
	.string "Deus ser un ENTRENADOR increïble!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Només tens un POKéMON?\n"
	.string "No és massa solitari, això?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Em fa una mica de vergonya, però…\n"
	.string "Et mostrarem el nostre poder amorós!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Oh, vaja!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: No m'ho puc creure!\n"
	.string "El nostre poder amorós ha fallat…\l"
	.string "Deus ser un ENTRENADOR increïble!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Volia combatre…\n"
	.string "Però ni tan sols tens dos POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, has arribat just a temps.\p"
	.string "M'avorreixo, ja saps.\n"
	.string "Pots entretenir-me.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Ja està bé.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Potser faré que el Pare m'aconsegueixi\n"
	.string "un iot.\l"
	.string "Un iot per a mi i els POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, ets un ENTRENADOR adorable.\n"
	.string "T'agradaria prendre un te?\l"
	.string "O prefereixes combatre?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Ja veig.\n"
	.string "Ets del tipus actiu.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Un creuer mundial en un transatlàntic\n"
	.string "de luxe té el seu encant, he de dir…\p"
	.string "Però, admetré que recórrer HOENN\n"
	.string "en ferri té el seu atractiu.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Eh… Hola! Jo… No estic fent res\n"
	.string "sospitós! Eh… Pots quedar-te això! Gratis!\p"
	.string "Jo… Sincerament, no ho he ROBAT a\n"
	.string "ningú! Mai faria una cosa així!\l"
	.string "És net! Pots usar-lo!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "ROB roba els efectes beneficiosos\n"
	.string "de certs moviments abans que els\l"
	.string "pugui usar un enemic o aliat.$"

