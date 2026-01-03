MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Si tingués una BICI, seria fàcil anar\n"
	.string "a PORTLAVANDA a comprar.\p"
	.string "Podria comprar CARTA PORTUÀRIA a la\n"
	.string "BOTIGA POKéMON de PORTLAVANDA…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! Tens CARTA PORTUÀRIA?\n"
	.string "La canviaries per un MONEDER?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, estic tan contenta!\n"
	.string "D'acord, et canvio per un MONEDER!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Aquest MONEDER es pot usar\n"
	.string "a la SALA DE JOCS.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, quin desencís.\p"
	.string "Es necessita un MONEDER per a la\n"
	.string "SALA DE JOCS.$"

