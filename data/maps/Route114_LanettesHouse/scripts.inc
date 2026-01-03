Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Ho sento, tot està tan desordenat…\n"
	.string "Quan m'endinso en la recerca,\l"
	.string "les coses acaben així…\p"
	.string "Quina vergonya… Sisplau guarda\n"
	.string "el secret a canvi d'això.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Puc oferir-te un consell sobre el meu\n"
	.string "Sistema d'Emmagatzematge POKéMON?\p"
	.string "Hauries d'organitzar les teves CAIXES\n"
	.string "per saber quins POKéMON hi tens.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Són les notes de recerca de la LANETTE.\n"
	.string "Hi ha informació sobre les CAIXES.\p"
	.string "Dissenyar CAIXES per a 30 POKéMON cada.\p"
	.string "Cada ENTRENADOR hauria de poder\n"
	.string "emmagatzemar 420 POKéMON al PC.\p"
	.string "Continuar llegint?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "S'hauria d'afegir un sistema de marques\n"
	.string "per organitzar els POKéMON més fàcilment.\p"
	.string "El nom i el disseny del fons de cada\n"
	.string "CAIXA es podran canviar per alegrar\l"
	.string "els POKéMON emmagatzemats.\p"
	.string "Continuar llegint?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Quan s'emmagatzemi un POKéMON, s'ha\n"
	.string "d'enviar a l'última CAIXA inspeccionada.\p"
	.string "Si aquesta CAIXA és plena, el POKéMON\n"
	.string "rebut s'emmagatzema a la següent CAIXA.\p"
	.string "En altres paraules, quan s'examina una\n"
	.string "CAIXA, queda seleccionada automàticament\l"
	.string "com la CAIXA on s'envien els POKéMON.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} ha tancat la llibreta.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Hi ha un correu electrònic d'algú\n"
	.string "al PC.\p"
	.string "“… … … … … … …\p"
	.string "“El teu Sistema d'Emmagatzematge és\n"
	.string "més convenient que el meu.\p"
	.string "“Té moltes funcions fàcils d'usar\n"
	.string "que el fan divertit i útil també.\p"
	.string "“Em fa sentir orgullós d'haver participat\n"
	.string "en el seu desenvolupament.\p"
	.string "“Esperant que continuïs la recerca\n"
	.string "en Sistemes d'Emmagatzematge.\p"
	.string "“De part de BILL\n"
	.string "… … … … … … … …”$"

