AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Vaixells d'aquest tipus són rars,\n"
	.string "així que estic fent una ullada.\p"
	.string "Hmhm…\n"
	.string "Sembla que hi ha altres cabines…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Què t'ha impulsat a venir aquí?\n"
	.string "Deus ser molt curiós!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "No només curiós, sinó també fort…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "L'home de la porta del costat…\p"
	.string "Diu que només està fent turisme,\n"
	.string "però no n'estic segura.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Ets un ENTRENADOR molt dur!\n"
	.string "Deixa'm registrar-te com a record!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Què t'ha impulsat a tornar?\n"
	.string "Deus ser molt curiós de debò!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "No ets massa fort?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Estic segura que aquell home trama\n"
	.string "alguna cosa! Actua tan sospitosament!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Aaaah!\n"
	.string "M'han trobat! …Eh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, no ets la meva mare.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Estic en problemes amb la mare, i he\n"
	.string "fugit. Mantén en secret on sóc!$"

