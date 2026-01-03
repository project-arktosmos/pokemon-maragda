Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Sóc el propietari de la CASA DE LA RIBA.\n"
	.string "Però pots dir-me SR. MAR!\p"
	.string "El que més m'agrada és veure batalles\n"
	.string "POKéMON ben calentes.\p"
	.string "Deixa'm veure que el teu cor crema!\p"
	.string "Si pots derrotar tots els ENTRENADORS\n"
	.string "d'aquí, et recompensaré pels esforços.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Mostra'm partits ben calents!\p"
	.string "Porto aquesta CASA DE LA RIBA només\n"
	.string "per aquesta raó!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Estàs que cremes!\n"
	.string "Aquestes batalles han estat de foc!\l"
	.string "Estic més que satisfet!\p"
	.string "Com a agraïment per mostrar-me la\n"
	.string "teva ratxa calenta, vull que agafis això.\p"
	.string "Són mitja dotzena d'ampolles de REFRESC!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, però la teva MOTXILLA està plena.\n"
	.string "T'ho guardaré.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Vols comprar REFRESC?\n"
	.string "Als POKéMON els encanta!\p"
	.string "Només ¥300 l'ampolla!\n"
	.string "Compra'n!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Aquí tens!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "No tens prou diners.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "No?\n"
	.string "Quina llàstima.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Si busques una batalla a la\n"
	.string "CASA DE LA RIBA, no trobaràs\l"
	.string "cap ENTRENADOR més calent que jo, amic!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Ha estat una batalla calenta!\n"
	.string "Puc acceptar aquesta derrota, amic!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Sempre que sóc a PORTLAVANDA, gaudeixo\n"
	.string "de batalles calentes i REFRESC ben fred!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Les batalles avorrides no valen la pena.\p"
	.string "Les batalles de foc són les que\n"
	.string "enforteixen ENTRENADORS i POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Això és calent!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Uf, tinc molta set.\n"
	.string "Potser prendré un REFRESC.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Et mostraré com de genials són\n"
	.string "els meus POKéMON, però no ploris!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…He perdut, però no ploraré…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Si un dels meus POKéMON sabés el\n"
	.string "moviment per portar-me per l'aigua\l"
	.string "a l'esquena, podria desfer-me d'aquest flotador.$"

