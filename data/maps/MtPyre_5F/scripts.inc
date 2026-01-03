MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "M'encanten les coses horripilants…\n"
	.string "És com una malaltia…\p"
	.string "Quan sóc aquí…\n"
	.string "Tremolo de por…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Perdre, no m'agrada…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Vull veure coses espantoses…\n"
	.string "No puc marxar…\p"
	.string "Queda't…\n"
	.string "No et quedaràs amb mi?$"

