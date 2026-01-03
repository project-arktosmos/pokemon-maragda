MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Entenc tot el que diu el nostre líder.\n"
	.string "Però saps què?\p"
	.string "Fer coses com desenterrar un POKéMON\n"
	.string "superantic i robar el METEORIT\l"
	.string "d'algú…\p"
	.string "Crec que ens estem passant una mica.\n"
	.string "Tu què en penses?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Sí, crec que estem fent alguna cosa\n"
	.string "malament d'alguna manera.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Saps, perdre contra tu m'ha aclarit\n"
	.string "les idees.\p"
	.string "La pròxima vegada que vegi el nostre\n"
	.string "líder, li preguntaré sobre el que fem.$"

