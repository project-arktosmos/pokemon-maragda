MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Què he fet per merèixer aquest lloc\n"
	.string "de guàrdia?\p"
	.string "L'orella esquerra em crema!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Estic patint un cop de calor…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "No trobes estrany que portem caputxes\n"
	.string "en aquest volcà ple de magma?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Ens hem unit per ajudar el nostre líder\n"
	.string "a assolir la seva visió fantàstica.\p"
	.string "M'és igual si ets de l'EQUIP AQUA\n"
	.string "o només un nen que passava per aquí.\p"
	.string "Ningú no s'interposa en el nostre camí\n"
	.string "i se n'escapa!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, no!\n"
	.string "No es pot confiar gens en tu!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Escolta'm.\n"
	.string "L'EQUIP MAGMA té raó!\p"
	.string "No escoltis l'EQUIP AQUA.\n"
	.string "No creguis les seves mentides!$"

