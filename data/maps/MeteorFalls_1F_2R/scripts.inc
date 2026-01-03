MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Aquí és on els que usem tipus DRAC\n"
	.string "entrenem.\p"
	.string "Fins i tot el CAMPIÓ ens visita.\n"
	.string "Ara veus com d'especial és aquest lloc?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "No esperava que fossis tan fort!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "El camí que queda és llarg i dur.\p"
	.string "Quan els meus POKéMON i jo\n"
	.string "serem els millors?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Vull saber més del teu poder.\n"
	.string "Deixa'm registrar-te al POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Des que ens vam conèixer, hem entrenat\n"
	.string "fort amb la vista al número u.\p"
	.string "Ajuda'ns a veure com de forts ens hem\n"
	.string "fet!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh!\n"
	.string "No esperava que fossis tan fort!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Òbviament has continuat entrenant\n"
	.string "els teus POKéMON.\p"
	.string "Mentre tu siguis fort, jo també\n"
	.string "puc fer-me més fort!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOAN: Sempre hem lluitat amb POKéMON\n"
	.string "junts, com a parella.\l"
	.string "Tenim confiança en nosaltres.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOAN: Oh, vaja.\n"
	.string "Hem perdut, estimada esposa.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOAN: Portem cinquanta anys casats.\p"
	.string "Pensant-ho bé, encara no he guanyat\n"
	.string "a la meva estimada esposa en combat.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOAN: Vaja, vaja, quin ENTRENADOR\n"
	.string "tan jove!\p"
	.string "Vols lluitar amb nosaltres? Si és així,\n"
	.string "hauràs de tornar amb més POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOAN: Jove ENTRENADOR, si sorgeix\n"
	.string "l'ocasió, lluites amb nosaltres altre cop?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JOANA: Portem cinquanta anys casats.\p"
	.string "El vincle que compartim com a parella\n"
	.string "mai es podria trencar.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JOANA: Oh, vaja.\n"
	.string "Hem perdut, estimat marit.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JOANA: Cinquanta anys de matrimoni…\p"
	.string "Si mai ens barallàvem, sempre ho\n"
	.string "resolíem amb un combat POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JOANA: Vaja, vaja, no ets un\n"
	.string "ENTRENADOR jove?\p"
	.string "Si vols lluitar amb nosaltres, hauràs\n"
	.string "de tornar amb més POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOAN: Sempre hem lluitat amb POKéMON\n"
	.string "junts, com a parella.\l"
	.string "Tenim confiança en nosaltres.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOAN: Oh, vaja.\n"
	.string "Hem perdut, estimada esposa.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOAN: Cinquanta anys de casats…\p"
	.string "Pensant-ho bé, la meva estimada esposa\n"
	.string "i jo, lluitàvem dia rere dia…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOAN: Vaja, vaja, quin ENTRENADOR\n"
	.string "tan jove!\p"
	.string "Vols lluitar amb nosaltres? Si és així,\n"
	.string "hauràs de tornar amb més POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JOANA: Portem cinquanta anys casats.\p"
	.string "Ens hem recolzat tot aquest temps.\n"
	.string "Ens hem fet forts.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JOANA: Oh, vaja.\n"
	.string "Hem perdut, estimat marit.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JOANA: Cinquanta anys de matrimoni…\n"
	.string "Han passat moltes coses.\p"
	.string "Espero que continuem creant\n"
	.string "records feliços junts.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JOANA: Vaja, vaja, no ets un\n"
	.string "ENTRENADOR jove?\p"
	.string "Si vols lluitar amb nosaltres, hauràs\n"
	.string "de tornar amb més POKéMON.$"

