FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Les persones… Els POKéMON…\p"
	.string "Els seus poders ocults es desperten\n"
	.string "vivint en entorns naturals…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Deixa que aquesta vella vegi si el teu\n"
	.string "poder ocult s'ha despertat…\p"
	.string "Tinc una moneda a la mà.\p"
	.string "Ara, digues-me, l'he amagat a\n"
	.string "la mà dreta? O a l'esquerra?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Sí, correcte!\p"
	.string "Ho tornarem a provar.\p"
	.string "A quina mà he amagat la moneda?\n"
	.string "La dreta o l'esquerra?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Sí, correcte!\p"
	.string "Ho tornarem a provar.\p"
	.string "A quina mà he amagat la moneda?\n"
	.string "La dreta o l'esquerra?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Esplèndid!\n"
	.string "El teu poder ocult s'ha despertat!\p"
	.string "Aquí tens, pren això i desperta el\n"
	.string "poder ocult del teu POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "PODER OCULT és un moviment que canvia\n"
	.string "segons el POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "No, llàstima.\n"
	.string "Has fallat.$"

