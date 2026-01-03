SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Escolta bé, i t'explicaré una cosa\n"
	.string "interessant.\p"
	.string "Diuen que hi ha unes ruïnes antigues\n"
	.string "al mar d'aquí a prop.\p"
	.string "Podrien haver-hi tresors esperant\n"
	.string "ser descoberts allà baix.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Tresors antics…\p"
	.string "Estaria bé que existissin, però\n"
	.string "fins i tot si no, seria tan bonic\l"
	.string "fer un passeig submarí amb\l"
	.string "el meu POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

