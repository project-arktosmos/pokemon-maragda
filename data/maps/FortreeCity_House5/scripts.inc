FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Les cases als arbres de BOIREBOSCADA\n"
	.string "són genials!\p"
	.string "Crec que és el poble número u per\n"
	.string "viure juntament amb POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "Els POKéMON i la gent s'han adaptat\n"
	.string "a la natura per sobreviure.\p"
	.string "No cal fer que la natura s'adapti\n"
	.string "a la manera com volem viure.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: Bufuu!$"

