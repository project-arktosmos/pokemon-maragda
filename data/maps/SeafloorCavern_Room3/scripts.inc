SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Com has aconseguit arribar fins aquí\n"
	.string "sense submarí?\l"
	.string "Quin nen més impressionant!\p"
	.string "Però… No puc deixar que et fiquis\n"
	.string "aquí al mig.\p"
	.string "A més, vull revenja pel que va passar\n"
	.string "a l'INSTITUT METEOROLÒGIC…\p"
	.string "Et faré tastar una mica de dolor!\n"
	.string "Resigna't!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Au!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "Ets increïblement fort.\p"
	.string "És molt decebedor que no siguis\n"
	.string "membre de l'EQUIP AQUA.\p"
	.string "Podries haver gaudit del món fabulós\n"
	.string "que el nostre CAP ha promès com\l"
	.string "un de nosaltres…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Perquè el nostre somni es faci realitat,\n"
	.string "necessitem el poder dels POKéMON.\p"
	.string "Però entrometuts com tu utilitzen el\n"
	.string "poder dels POKéMON per molestar-nos\l"
	.string "fins i tot en un lloc com aquest!\p"
	.string "La vida no funciona com\n"
	.string "necessitem!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Saps, no ens atrevim a qüestionar\n"
	.string "els motius del nostre líder.\p"
	.string "Però aquí ets tu, només un marrec,\n"
	.string "enfrontant-te al nostre CAP.\p"
	.string "Potser…\n"
	.string "Has de ser algú especial…$"

