RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Eh? El meu POKéMON és bonic?\n"
	.string "Sí, ja ho sabia.\p"
	.string "Però si realment vols, estic disposat\n"
	.string "a intercanviar-te'l.\p"
	.string "T'intercanviaré el meu {STR_VAR_2} per\n"
	.string "un {STR_VAR_1} si vols.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh…\n"
	.string "Sisplau, cuida bé el meu POKéMON.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Eh? Això no s'assembla gens a\n"
	.string "un {STR_VAR_1} per a mi.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, si no vols, està bé.\n"
	.string "Però el meu POKéMON és bonic, saps…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Qualsevol POKéMON pot ser bonic si\n"
	.string "el cries amb cura i amabilitat.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "A tot tipus de llocs, hi ha tot\n"
	.string "tipus de POKéMON i persones.\p"
	.string "Trobo això fascinant, així que vaig\n"
	.string "a tot tipus de llocs.$"

