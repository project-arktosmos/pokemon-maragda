MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "L'atmosfera rica de la muntanya\n"
	.string "ha elevat el meu poder psíquic!\p"
	.string "Un simple nen com tu…\n"
	.string "Somies en guanyar?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "M'ofego en l'autocompassió…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Els meus poders psíquics segurament\n"
	.string "han crescut diverses vegades, però…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Aquest no és lloc per a nens,\n"
	.string "i menys per a tu!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "He perdut clarament…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Això vol dir que el meu entrenament\n"
	.string "encara no és suficient…\p"
	.string "He de continuar treballant cap al\n"
	.string "cim…\p"
	.string "Som-hi, jo!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Per què has vingut aquí?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Ha estat increïble!\n"
	.string "Ets un ENTRENADOR molt especial.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON que ja no són d'aquest món.\n"
	.string "POKéMON que ara són amb tu.\p"
	.string "I els POKéMON que coneixeràs\n"
	.string "en el futur…\p"
	.string "Tots mereixen ser estimats per igual.\n"
	.string "Si us plau, recorda-ho.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "M'agradaria veure els teus POKéMON\n"
	.string "quan hagin crescut una mica més…\p"
	.string "Si us plau, necessito veure el POKéNAV.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, ets tu…\p"
	.string "Has vingut a ensenyar-me els teus\n"
	.string "POKéMON crescuts?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Increïble!\n"
	.string "Ets una persona especial.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON que ja no són d'aquest món.\n"
	.string "POKéMON que ara són amb tu.\p"
	.string "I els POKéMON que coneixeràs\n"
	.string "en el futur…\p"
	.string "Tots mereixen ser estimats per igual.\n"
	.string "Veig que ho has recordat.$"

