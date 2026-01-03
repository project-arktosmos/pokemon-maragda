MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Uhu!\p"
	.string "Sento que la gent em diu el TIO\n"
	.string "TRENCA-ROQUES, però ho trobo degradant.\p"
	.string "Crec que em mereixo una mica més de\n"
	.string "respecte, com MESTRE TRENCA-ROQUES.\p"
	.string "Uhu!\p"
	.string "De totes maneres, els teus POKéMON\n"
	.string "semblen bastant forts.\p"
	.string "M'agrada això!\n"
	.string "Aquí tens, agafa aquesta MO!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Aquesta MO conté TRENCA-ROQUES.\p"
	.string "Si et trobes amb grans roques\n"
	.string "que et bloquegen el pas…\p"
	.string "Bé, usa aquest moviment de MO i\n"
	.string "trenca-les per apartar-les del camí!\p"
	.string "Sí, senyor! Trenca roques, et dic!\n"
	.string "Uhu!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh, sí, si trenques una roca, un POKéMON\n"
	.string "podria sortir volant del seu amagatall.\p"
	.string "Uhu!$"

