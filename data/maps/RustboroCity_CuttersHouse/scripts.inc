RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Aquesta expressió decidida…\n"
	.string "Aquesta manera àgil de moure't…\l"
	.string "I els teus POKéMON ben entrenats…\p"
	.string "Òbviament ets un ENTRENADOR hàbil!\p"
	.string "No, espera, no diguis res.\n"
	.string "Ho puc dir només mirant-te.\p"
	.string "Estic segur que pots fer bon ús\n"
	.string "d'aquesta MÀQUINA OCULTA.\p"
	.string "No cal que siguis modest o tímid.\n"
	.string "Vinga, agafa-la!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Aquesta MÀQUINA OCULTA, o MO per\n"
	.string "abreujar, és TALLAR.\p"
	.string "Un moviment MO és un que pot ser usat\n"
	.string "pels POKéMON fora de combat.\p"
	.string "Qualsevol POKéMON que hagi après TALLAR\n"
	.string "pot talar arbres prims si l'ENTRENADOR\l"
	.string "té la MEDALLA PEDRA.\p"
	.string "I, a diferència d'una MT, una MO pot\n"
	.string "ser usada més d'una vegada.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Quan estaven expandint la ciutat de\n"
	.string "FERRÍFERA, el meu pare va ajudar.\p"
	.string "Va fer que el seu POKéMON usés TALLAR\n"
	.string "per netejar el terreny d'arbres.$"

