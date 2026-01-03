MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Què, què, què?\p"
	.string "Només els membres de l'EQUIP MAGMA\n"
	.string "haurien de ser aquí!\p"
	.string "Però no portes l'uniforme de\n"
	.string "l'EQUIP MAGMA…\p"
	.string "Em despertes sospites!\n"
	.string "Combat amb mi!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiaiai…\n"
	.string "El meu orgull com a membre de l'EQUIP MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Si pateixes de fred, hauries d'unir-te\n"
	.string "a l'EQUIP MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Para aquí!\p"
	.string "No t'esperis que em quedi callat\n"
	.string "i et deixi passar com si res?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Oh, uau!\n"
	.string "Em rendeixo!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Potser hauria estat millor si t'hagués\n"
	.string "deixat passar sense desafiar-te…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahà!\n"
	.string "Un intrús!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ja he perdut.\p"
	.string "De debò he de seguir corrent\n"
	.string "en cercles?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh!\n"
	.string "Un intrús!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Mmmf…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "En realitat, no sóc cap expert en combats…$"

