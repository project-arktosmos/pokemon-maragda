OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Quan els POKéMON combaten, amb el temps\n"
	.string "pugen de nivell i es fan més forts.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Si els POKéMON que tens es fan\n"
	.string "més forts, podràs anar més lluny\l"
	.string "d'aquí.$"

