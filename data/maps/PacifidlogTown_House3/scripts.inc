PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Mira aquest {STR_VAR_2}!\p"
	.string "És el {STR_VAR_2} que vaig capturar\n"
	.string "ahir per celebrar el meu aniversari!\p"
	.string "Oh, veig que el vols!\n"
	.string "Després de tot, no té preu!\p"
	.string "Et diré una cosa. Potser estaria\n"
	.string "disposat a canviar-lo per un {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, així que això és un {STR_VAR_1}?\p"
	.string "És com un {STR_VAR_2},\n"
	.string "però subtilment diferent.\p"
	.string "Gràcies!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! No acceptaré res\n"
	.string "menys que un {STR_VAR_1} de veritat!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, així que no vols fer l'intercanvi?\p"
	.string "Està bé. No estic desesperat per fer\n"
	.string "un intercanvi ni res.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Sé que podria anar a buscar-ne un\n"
	.string "pel meu compte, però…\p"
	.string "Però realment volia aconseguir un BAGON\n"
	.string "que hagués capturat un altre ENTRENADOR…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Això és una POKéDEX?\p"
	.string "Has pogut conèixer molts POKéMON\n"
	.string "diferents?\p"
	.string "M'agradaria ser com tu.$"

