FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Rooooooar! El necessito!\n"
	.string "He d'aconseguir un {STR_VAR_1}!\l"
	.string "Faré el que sigui per aconseguir-lo!\p"
	.string "…Uh… Has sentit això?\n"
	.string "El meu crit des del fons del cor?\p"
	.string "Havent sentit això, canviaràs\n"
	.string "el teu {STR_VAR_1} pel meu {STR_VAR_2},\l"
	.string "oi que sí?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Oh, sí, genial!\p"
	.string "{STR_VAR_1}, benvingut!\n"
	.string "{STR_VAR_2}, cuida't!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Uh, no, no ho crec.\n"
	.string "Això no és un {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "No? No vols fer l'intercanvi?\n"
	.string "Fins i tot després d'obrir-te el cor?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Faré que VOLBEAT sigui super\n"
	.string "fort a partir d'ara!\p"
	.string "Espero que facis el mateix amb PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Intercanviar POKéMON amb altres…\p"
	.string "És com si estiguessis intercanviant\n"
	.string "els teus propis records amb altra gent.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

