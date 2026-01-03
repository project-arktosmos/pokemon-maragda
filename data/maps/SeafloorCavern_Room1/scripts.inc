SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "No necessitem nens aquí!\n"
	.string "Vés-te'n a casa d'una vegada!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Vull anar a casa…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Vull aconseguir un ascens per poder\n"
	.string "manar als RECLUTES…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Aquell submarí… És molt petit per dins.\n"
	.string "Em fa mal tot!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Perdre em fa mal!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Aquell submarí que hem robat, tio,\n"
	.string "és brutal com a vehicle.\l"
	.string "És massa estret per dins!$"

