AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Mentre buscàvem tresors,\n"
	.string "hem descobert un ENTRENADOR!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: No hem pogut guanyar ni\n"
	.string "treballant junts…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: No trobem cap tresor…\n"
	.string "Potser algú ja se'ls ha endut?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Ni tan sols tens dos POKéMON.\n"
	.string "No pots esperar guanyar-nos així.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Oh?\n"
	.string "Estàvem buscant tresors.\l"
	.string "Però hem descobert un ENTRENADOR!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Uau, quin fort!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: On deuen ser els tresors?\p"
	.string "Ja he decidit què em compraré\n"
	.string "quan trobem els tresors!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Oh, no tens dos POKéMON?\n"
	.string "Haurem de lluitar un altre dia!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Oh, m'has fet enfadar molt!\n"
	.string "Per això et registraré!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Hem estat buscant tresors\n"
	.string "tot aquest temps.\p"
	.string "Els nostres POKéMON també s'han\n"
	.string "fet més forts. Deixa'ns ensenyar-t'ho!$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Ets fort, com sempre!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: No trobem tresors,\n"
	.string "perdem als combats POKéMON…\p"
	.string "Vull tornar a casa… Però si ho dic,\n"
	.string "ella s'enfada amb mi…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Ni tan sols tens dos POKéMON.\n"
	.string "No pots esperar guanyar-nos així.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Oh? Ens tornem a trobar!\p"
	.string "Com nosaltres, tu tampoc has deixat\n"
	.string "de buscar tresors, oi?\p"
	.string "Vols fer que el perdedor hagi\n"
	.string "de deixar de buscar?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Oh, hem perdut altra vegada…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: No marxarem fins que entrenem\n"
	.string "més els nostres POKéMON i trobem\l"
	.string "els tresors d'aquí!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Oh, no tens dos POKéMON?\n"
	.string "Haurem de lluitar un altre dia!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "No sé nedar gaire bé,\n"
	.string "però els combats se'm donen bé!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Ups.\n"
	.string "No ha anat gaire bé.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Caminar descalça per aquest vaixell\n"
	.string "és una mica desagradable.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Força i compassió…\n"
	.string "Aquests són els tresors d'un ENTRENADOR!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, hi ha alguna cosa en tu\n"
	.string "que brilla.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "En una cabina d'algun lloc a bord,\n"
	.string "vaig veure alguna cosa brillar.$"
