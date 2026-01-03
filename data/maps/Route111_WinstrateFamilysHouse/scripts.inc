Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Ets el primer ENTRENADOR que veig que\n"
	.string "utilitza els POKéMON tan magistralment.\p"
	.string "Però, t'ho haig de dir: el meu fill és\n"
	.string "més fort que tu.\p"
	.string "Fins i tot va participar al desafiament\n"
	.string "de la LLIGA POKéMON, per si no ho sabies.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Utilitzem aquest MUSCULADOR per enfortir\n"
	.string "els nostres POKéMON de manera més\l"
	.string "efectiva durant l'entrenament.\p"
	.string "Com que ens has vençut a tots,\n"
	.string "no sé si el necessites, però ens\l"
	.string "agradaria donar-te el nostre MUSCULADOR.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Quan es tracta de combats POKéMON,\n"
	.string "solem ser bastant apassionats.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "La mamà és més forta que el papà.\p"
	.string "Jo sóc més forta que la mamà.\p"
	.string "I l'àvia és més forta que jo!\p"
	.string "Però el meu germà gran és encara\n"
	.string "més fort que l'àvia.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "No hi ha dubte que ets fort.\p"
	.string "Però si lluitessis contra el meu nét,\n"
	.string "acabaries plorant de frustració.\p"
	.string "És molt més fort que qualsevol\n"
	.string "ENTRENADOR que coneix la família.\p"
	.string "Ara mateix deu estar desafiant el\n"
	.string "CAMPIÓ DE LA LLIGA POKéMON.\p"
	.string "Coneixent el meu nét, podria ser\n"
	.string "que ja sigui el CAMPIÓ!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "El meu nét ara mateix deu estar\n"
	.string "desafiant el CAMPIÓ DE LA LLIGA POKéMON.\p"
	.string "Coneixent el meu nét, podria ser\n"
	.string "que ja sigui el CAMPIÓ!$"

