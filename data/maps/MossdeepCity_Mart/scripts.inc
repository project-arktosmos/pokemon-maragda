MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "El REVISCOLA és fantàstic!\p"
	.string "Dóna-li'l a un POKéMON desmaia,\n"
	.string "i el POKéMON ressuscitarà.\p"
	.string "Però ves amb compte, el REVISCOLA no\n"
	.string "restaura els PP gastats dels moviments.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "El MÀXIM REPEL manté lluny tots\n"
	.string "els POKéMON febles.\p"
	.string "De tots els aerosols REPEL, és el\n"
	.string "que dura més.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Les BALL XARXA i BUSSEIG són POKé\n"
	.string "BALLS rares que només es fan a\l"
	.string "ALGUERSUARI.\p"
	.string "Una BALL XARXA és efectiva contra\n"
	.string "POKéMON de tipus INSECTE i AIGUA.\p"
	.string "Una BALL BUSSEIG funciona millor amb\n"
	.string "POKéMON al fons del mar.$"

