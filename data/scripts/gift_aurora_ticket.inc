MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.\p"
	.string "Tu deus ser {PLAYER}.\n"
	.string "Hi ha un bitllet aquí per a tu.$"

sText_AuroraTicketUseAtPort:
	.string "Sembla que és per usar-lo al port\n"
	.string "de CALAGUA.\p"
	.string "Per què no ho proves i veus\n"
	.string "de què es tracta?$"

sText_AuroraTicketThankYou:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.$"

sText_AuroraTicketBagFull:
	.string "Oh, ho sento, {PLAYER}.\n"
	.string "La BUTXACA D'OBJ. CLAU està plena.\p"
	.string "Si us plau, guarda alguna cosa al PC,\n"
	.string "i després torna a buscar això.$"
