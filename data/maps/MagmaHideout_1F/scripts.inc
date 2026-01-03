MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Quan l'EQUIP MAGMA passa llista, rebem\n"
	.string "les tasques de vigilància importants\l"
	.string "en l'ordre en què fem fila.\p"
	.string "Per això estic aquí atrapat en aquest racó.\n"
	.string "Sempre arribo tard a la llista!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "També arribo sempre tard als\n"
	.string "entrenaments!\p"
	.string "M'ho dic jo, però sóc un ploricó…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "D'acord, intentaré posar-hi una mica\n"
	.string "més d'esforç a partir d'ara…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "El nostre líder ens va dir que\n"
	.string "excavéssim al MT. XEMENEIA, així que vam\l"
	.string "excavar i excavar.\p"
	.string "I en el procés d'excavar, vam trobar\n"
	.string "alguna cosa que ens va deixar al·lucinats!\p"
	.string "Què vam trobar?\p"
	.string "Fuhahaha!\n"
	.string "T'ho diré si em guanyes!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh!\n"
	.string "M'han vençut!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Al final no t'ho diré.\n"
	.string "Ho descobriràs quan hi arribis!\p"
	.string "No seria millor guardar les sorpreses\n"
	.string "per al final, no creus?$"

