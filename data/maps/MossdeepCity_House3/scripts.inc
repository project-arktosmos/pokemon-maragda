MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Ei, ENTRENADOR!\n"
	.string "Una SUPERCANYA és realment super!\p"
	.string "Diguis el que diguis, aquesta bellesa\n"
	.string "pot pescar POKéMON del fons del mar!\p"
	.string "Què en penses?\n"
	.string "La vols, oi?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Ben segur, ben segur!\n"
	.string "Al cap i a la fi, una SUPERCANYA és super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Si hi ha aigua, prova de llançar-hi\n"
	.string "la CANYA i mira què pica!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Eh?\n"
	.string "No t'agrada pescar?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Persegueix els POKéMON del fons marí\n"
	.string "amb la teva SUPERCANYA.$"

