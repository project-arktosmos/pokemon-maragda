MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quan sóc aquí…\n"
	.string "Un poder curiós flueix dins meu…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "El poder s'esvaeix…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Potser el poder és dels esperits\n"
	.string "dels POKéMON en son inquiet aquí…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… He perdut el combat, però…\n"
	.string "Tinc aquesta petita habilitat…\p"
	.string "Sense ni tocar el teu\n"
	.string "POKéNAV… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Darrere teu…\n"
	.string "Què és…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Alguna cosa s'ha esvaït…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Els POKéMON que reposen aquí…\n"
	.string "De vegades, juguen…$"

MtPyre_6F_Text_CedricIntro:
	.string "T'has perdut?\n"
	.string "No tinguis por, jo sóc aquí!$"

MtPyre_6F_Text_CedricDefeat:
	.string "No t'havies perdut?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Tenia la sensació que un ENTRENADOR\n"
	.string "perdut estaria espantat i seria fàcil.\p"
	.string "És brut i no ho tornaré a intentar…$"

