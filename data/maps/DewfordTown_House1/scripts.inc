DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Hi ha molt a dir sobre viure en una\n"
	.string "illa petita com aquesta en harmonia\l"
	.string "amb els POKéMON i la família.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Vaig deixar el gran port de CIUTAT\n"
	.string "PORTUAL quan em vaig casar amb el\l"
	.string "meu marit aquí.\p"
	.string "La vida passa a poc a poc en aquesta\n"
	.string "petita illa. Però estar envoltada del\l"
	.string "bell mar, això també és felicitat.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

