MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.\p"
	.string "La teva TARGETA DE COMBATS fa\n"
	.string "un seguiment del teu historial de\l"
	.string "combats contra ENTRENADORS amb la\l"
	.string "mateixa TARGETA.\p"
	.string "Busca i combat ENTRENADORS que\n"
	.string "tinguin la mateixa TARGETA que tu.\p"
	.string "Pots consultar la classificació\n"
	.string "general llegint les NOTÍCIES.\p"
	.string "Prova-ho, si us plau!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.\p"
	.string "Felicitats!\p"
	.string "Has guanyat un premi per guanyar\n"
	.string "tres combats!\p"
	.string "Esperem que t'inspiri a\n"
	.string "combatre una mica més.$"
