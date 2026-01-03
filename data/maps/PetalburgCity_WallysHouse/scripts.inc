PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Tu ets…\n"
	.string "Ah, deus ser {PLAYER}{KUN}, oi?\p"
	.string "Gràcies per jugar amb en BLASI\n"
	.string "fa una estona.\p"
	.string "Ha estat fràgil i malaltís\n"
	.string "des que era un nadó.\p"
	.string "L'hem enviat a quedar-se amb els meus parents\n"
	.string "a POBLE VERD durant un temps.\p"
	.string "L'aire és molt més net allà\n"
	.string "que aquí.\p"
	.string "Què dius? On és en BLASI?\n"
	.string "Ja ha marxat, el nostre BLASI.\p"
	.string "Em pregunto on deu haver\n"
	.string "arribat a hores d'ara?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Com deu estar el nostre BLASI?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Perdona'ns per\n"
	.string "arrossegar-te aquí d'aquesta manera.\p"
	.string "Però el nostre BLASI s'ha posat molt sa\n"
	.string "des que va anar a POBLE VERD.\p"
	.string "T'ho devem tot a tu!\p"
	.string "Quan en BLASI va marxar de la ciutat, el vas\n"
	.string "ajudar a atrapar un POKéMON, oi?\p"
	.string "Crec que això va fer en BLASI molt\n"
	.string "feliç.\p"
	.string "De fet, no només en BLASI.\n"
	.string "A mi, el seu pare, també em va fer feliç.\p"
	.string "Feliç que hagi guanyat un amic\n"
	.string "tan genial com tu.\p"
	.string "Això no és cap suborn ni res, però\n"
	.string "m'agradaria molt que tinguessis això.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Si el teu POKéMON pot fer SURF, podràs\n"
	.string "anar a tota mena de llocs.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "En BLASI tornarà a casa aviat.\n"
	.string "Tinc ganes que arribi.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? Has trobat en BLASI a\n"
	.string "CIUTAT SEMPREVERD?\p"
	.string "Oh, {PLAYER}{KUN}, no diguis ximpleries.\p"
	.string "Pot haver-se posat sa, però no pot\n"
	.string "anar a un lloc tan llunyà\l"
	.string "tot sol.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "En BLASI estava molt content quan ens va\n"
	.string "explicar que havia atrapat un POKéMON.\p"
	.string "Feia temps que no el veia\n"
	.string "somriure així.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Vull que guardis això en secret\n"
	.string "del meu marit…\p"
	.string "Però el nostre BLASI va marxar de POBLE VERD\n"
	.string "sense dir-ho a ningú.\p"
	.string "Ja saps, en BLASI és fràgil, però\n"
	.string "és sorprenentment tenaç.\p"
	.string "Estic segura que tornarà sa\n"
	.string "i estalvi algun dia!$"

