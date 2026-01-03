MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.\p"
	.string "Tu deus ser {PLAYER}.\n"
	.string "Hi ha un bitllet aquí per a tu.$"

sText_MysticTicketUseAtPort:
	.string "Sembla que és per usar-lo al port\n"
	.string "de CALAGUA.\p"
	.string "Per què no ho proves i veus\n"
	.string "de què es tracta?$"

sText_MysticTicketThankYou:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.$"

sText_MysticTicketBagFull:
	.string "Oh, ho sento, {PLAYER}.\n"
	.string "La BUTXACA D'OBJ. CLAU està plena.\p"
	.string "Si us plau, guarda alguna cosa al PC,\n"
	.string "i després torna a buscar això.$"
