MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Mestre…\n"
	.string "Si us plau, vetlleu pel meu progrés!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Mestre…\n"
	.string "Si us plau, perdoneu-me!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Fins que millori, el meu mestre, que\n"
	.string "reposa aquí, mai trobarà pau veritable…$"

