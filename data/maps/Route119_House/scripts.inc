Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "He sentit parlar d'una cova anomenada\n"
	.string "la COVA ANCESTRAL.\p"
	.string "Diuen que els esperits dels POKéMON\n"
	.string "reviuen allà. Podria passar alguna\l"
	.string "cosa així de veritat?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

