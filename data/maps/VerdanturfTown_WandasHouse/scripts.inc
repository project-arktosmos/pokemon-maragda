VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "BLAI: He perdut contra tu, {PLAYER}, però\n"
	.string "ja no em sento malament.\p"
	.string "Perquè tinc un nou propòsit a la vida.\n"
	.string "Juntament amb el meu RALTS, desafiaré\l"
	.string "GIMNASOS POKéMON i em convertiré en\l"
	.string "un gran ENTRENADOR.\p"
	.string "Si us plau, vigila'm, {PLAYER}.\n"
	.string "Seré més fort que tu.\p"
	.string "Quan ho sigui, et desafiaré\n"
	.string "a un altre combat.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "BLAI: Si us plau, vigila'm, {PLAYER}.\n"
	.string "Em faré més fort que tu.\p"
	.string "Quan ho sigui, et desafiaré\n"
	.string "a un altre combat.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "ONCLE: Oh! {PLAYER}{KUN}!\n"
	.string "En BLAI és a la porta del costat.\p"
	.string "Però, noi, hi ha una cosa que he de\n"
	.string "dir-te.\p"
	.string "Aquest entorn natural està fent\n"
	.string "meravelles per la salut del BLAI.\p"
	.string "Potser no és només l'entorn.\n"
	.string "Podrien ser els POKéMON qui donen\l"
	.string "esperança al noi.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "En BLAI ha marxat…\n"
	.string "Se n'ha anat sol sense dir res…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "ONCLE: Ah, sí?\n"
	.string "En BLAI ha anat tan lluny ell sol…\p"
	.string "Bé, li he de reconèixer el mèrit: és\n"
	.string "el fill del meu germà petit.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "ALBA: Tu ets?\n"
	.string "Oh, és clar, ja ho entenc!\p"
	.string "Ets {PLAYER}, de qui el BLAI\n"
	.string "em parlava.\p"
	.string "Sóc la cosina del BLAI.\n"
	.string "Encantada de conèixer-te!\p"
	.string "Crec que el BLAI ha tornat molt més viu\n"
	.string "i sa des que va arribar aquí.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "ALBA: No et preocupis pel BLAI.\n"
	.string "Estarà bé.\p"
	.string "Conec el meu cosinet, i té\n"
	.string "POKéMON amb ell, també.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Gràcies a tu, puc veure la meva nòvia\n"
	.string "cada dia.\l"
	.string "Feliç? I tant que sí!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "El nòvio de la meva filla és una persona\n"
	.string "molt motivada i apassionada.\p"
	.string "Ha estat excavant un túnel sense parar\n"
	.string "només per poder veure la meva filla.\p"
	.string "La meva filla està una mica preocupada,\n"
	.string "així que va sovint al túnel.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "És increïble. El nòvio de la meva filla\n"
	.string "estava excavant el túnel amb les mans!\p"
	.string "És tan impressionant!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Si li passés alguna cosa al BLAI,\n"
	.string "no podria mai mirar els seus\l"
	.string "pares de PETÀLIA als ulls…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "En BLAI era a POKÈPOLIS?\p"
	.string "Els seus pares de PETÀLIA quedarien\n"
	.string "sorpresos de sentir això!$"

