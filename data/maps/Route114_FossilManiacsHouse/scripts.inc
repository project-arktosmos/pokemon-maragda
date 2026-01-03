Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "El meu germà gran és el MANÍAC\n"
	.string "DELS FÒSSILS… És un bon noi que\l"
	.string "li encanten els FÒSSILS…\p"
	.string "Li encanta excavar forats també…\n"
	.string "Ha excavat aquest forat ell sol…\p"
	.string "Pots quedar-te això, perquè puguis\n"
	.string "EXCAVAR forats com el meu germà…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Si fas que un POKéMON EXCAVI dins\n"
	.string "d'una cova, tornaràs a l'entrada…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Roques de formes peculiars omplen\n"
	.string "la vitrina…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSICIÓ DELS ESTRATS…\n"
	.string "COM LA PLUJA MODELA LA TERRA…\l"
	.string "PEDRES, TERRA I ROCA…\p"
	.string "Està ple de llibres.$"

