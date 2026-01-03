SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Qui ets?\n"
	.string "Per on has entrat?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "He perdut…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "No puc trobar la sortida!\p"
	.string "No tinc por. No m'entenguis malament!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Qui ets?\n"
	.string "On et penses que vas?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "No he aconseguit guanyar!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "El meu company ha oblidat el mapa\n"
	.string "al submarí!\p"
	.string "Que n'és d'inútil!$"

