GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Ei, tu.\n"
	.string "Més endavant es torna molt fosc.\l"
	.string "Serà difícil explorar.\p"
	.string "Aquell noi que va passar abans…\n"
	.string "STEVEN, crec que es deia.\p"
	.string "Sabia usar FLAIX, així que hauria\n"
	.string "d'estar bé, però…\p"
	.string "Bé, per a nosaltres els EXCURSIONISTES,\n"
	.string "ajudar els que trobem és el nostre lema.\p"
	.string "Aquí tens, et donaré això.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Ensenya el moviment ocult FLAIX\n"
	.string "a un POKéMON i usa'l.\p"
	.string "Il·lumina fins i tot la foscor més\n"
	.string "absoluta de les coves.\p"
	.string "Però, per usar-lo, necessites la MEDALLA\n"
	.string "del GIMNÀS POKéMON de PUEBLO.$"

