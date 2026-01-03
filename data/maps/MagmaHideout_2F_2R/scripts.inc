MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "No tinc res contra tu.\n"
	.string "Només segueixo ordres!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Potser he perdut, però…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Hem desenterrat alguna cosa increïble!\n"
	.string "I hem aconseguit l'ORB BLAU!\p"
	.string "Ara només falta que el nostre líder…\n"
	.string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "No suporto la calor. Potser m'hauria\n"
	.string "d'haver unit a l'EQUIP AQUA…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Sí, potser no estic fet per a\n"
	.string "l'EQUIP MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "No trobes a faltar el mar estant\n"
	.string "en un lloc com aquest?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "De vegades es poden sentir tremolors aquí.\p"
	.string "Serà el volcà que tremola?\n"
	.string "O serà GROU…\p"
	.string "Ui!\n"
	.string "No, no, oblida-ho!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Ets un lluitador ardent.\n"
	.string "Com un volcà!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Has guanyat per casualitat aquesta vegada,\n"
	.string "però no importa.\p"
	.string "L'objectiu de l'EQUIP MAGMA està a punt\n"
	.string "de ser assolit!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Un dels nostres estava espantat perquè\n"
	.string "havia perdut el seu EMBLEMA MAGMA…\p"
	.string "Espera un moment!\n"
	.string "L'has trobat tu?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Em costa creure-ho…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Tinc la sensació que el nostre pla\n"
	.string "acabarà en un fracàs…$"

