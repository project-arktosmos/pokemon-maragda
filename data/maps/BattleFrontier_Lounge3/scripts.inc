BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…Què vols?\p"
	.string "No veus que estem una mica ocupats?\n"
	.string "No pot esperar el teu assumpte?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Eh?\n"
	.string "Em sembla que ets un ENTRENADOR fort.\p"
	.string "Heheh…\n"
	.string "Escolta, tinc una proposta.\p"
	.string "Tenim un petit grup aquí,\n"
	.string "i juguem un petit joc amb el que\l"
	.string "passa a la FRONTERA COMBAT.\p"
	.string "Les regles són molt simples.\p"
	.string "Primer, triem una de les instal·lacions\n"
	.string "de la FRONTERA COMBAT.\p"
	.string "Després, cadascú tria un ENTRENADOR\n"
	.string "diferent que accepti el repte d'aquella\l"
	.string "instal·lació, i apostem Punts de Combat.\p"
	.string "Qui aposti per l'ENTRENADOR amb\n"
	.string "el millor rècord s'emporta tots els\l"
	.string "Punts de Combat del pot.\p"
	.string "Sona simple, eh?\n"
	.string "Així que, en fi…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a desafiar les SALES DE COMBAT\l"
	.string "INDIVIDUAL de la TORRE COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a desafiar les SALES DE COMBAT\l"
	.string "DOBLE de la TORRE COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a desafiar les SALES DE COMBAT\l"
	.string "MULTI de la TORRE COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a entrar al Torneig de COMBAT\l"
	.string "INDIVIDUAL de la CÚPULA COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a entrar al Torneig de COMBAT\l"
	.string "DOBLE de la CÚPULA COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a entrar al Torneig d'Intercanvi\l"
	.string "Individual de la FÀBRICA COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a entrar al Torneig d'Intercanvi\l"
	.string "Doble de la FÀBRICA COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a desafiar les SALES DE COMBAT\l"
	.string "INDIVIDUAL del PALAU COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a desafiar les SALES DE COMBAT\l"
	.string "DOBLE del PALAU COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a entrar al Torneig de KO Seguit\l"
	.string "de l'ARENA COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a entrar a l'Elecció de Combat\l"
	.string "del LLAC COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "El que busco és un ENTRENADOR que\n"
	.string "vagi a entrar a la Cerca de Combat\l"
	.string "de la PIRÀMIDE COMBAT.\p"
	.string "Però fins ara, no he vist cap ENTRENADOR\n"
	.string "amb aquella qualitat guanyadora.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Em preocuparé que tu també en beneficiïs.\n"
	.string "Així que, què et sembla?\l"
	.string "Què tal si entres a aquell event per mi?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "D'acord, perfecte.\n"
	.string "Així que, mm… Què tal si em deixes\l"
	.string "uns Punts de Combat?\p"
	.string "Confia en mi, et mostraré la meva\n"
	.string "gratitud després.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Genial, genial!\n"
	.string "Quants em pots deixar?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, no, no, no!\n"
	.string "No tens prou Punts de Combat!\p"
	.string "M'agradaria que no perdis el temps\n"
	.string "de tothom!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Heheh! Moltes gràcies!\n"
	.string "Així que, endavant!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Ves a les SALES DE COMBAT INDIVIDUAL\n"
	.string "de la TORRE COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Ves a les SALES DE COMBAT DOBLE\n"
	.string "de la TORRE COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Ves a les SALES DE COMBAT MULTI\n"
	.string "de la TORRE COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Ves al Torneig de COMBAT INDIVIDUAL\n"
	.string "de la CÚPULA COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Ves al Torneig de COMBAT DOBLE\n"
	.string "de la CÚPULA COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Ves al Torneig d'Intercanvi Individual\n"
	.string "de la FÀBRICA COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Ves al Torneig d'Intercanvi Doble\n"
	.string "de la FÀBRICA COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Ves a les SALES DE COMBAT INDIVIDUAL\n"
	.string "del PALAU COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Ves a les SALES DE COMBAT DOBLE\n"
	.string "del PALAU COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Ves al Torneig de KO Seguit\n"
	.string "de l'ARENA COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Ves a l'Elecció de Combat\n"
	.string "del LLAC COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Ves a la Cerca de Combat\n"
	.string "de la PIRÀMIDE COMBAT de pressa!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No la fiquis!\l"
	.string "El nostre futur depèn de tu!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, ets tu…\n"
	.string "Bona provatura…\p"
	.string "Em sap greu dir-t'ho, però no puc\n"
	.string "tornar-te els Punts de Combat…\p"
	.string "Suposo que haurem de deixar que ens\n"
	.string "motivi per esforçar-nos més la propera!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, sí!\n"
	.string "Hola, campió!\p"
	.string "Sabia que podies!\n"
	.string "Sabia que ho faries!\l"
	.string "Tots dos som grans guanyadors!\p"
	.string "Et tornaré els Punts de Combat i,\n"
	.string "és clar, una miqueta extra de part meva!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} ha obtingut\n"
	.string "{STR_VAR_1} Punts de Combat.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Si vols un altre repte,\n"
	.string "siusplau, pensa en mi!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "No t'interessa?! No hauries de tenir\n"
	.string "tanta por d'arriscar-te!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "He apostat per l'ENTRENADOR equivocat\n"
	.string "una altra vegada!\p"
	.string "Potser hauria de combatre normalment\n"
	.string "com tothom…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Aquell ENTRENADOR…\p"
	.string "És bo, però es posa massa nerviós\n"
	.string "per sobreviure a la CÚPULA COMBAT…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Ji, ji!\n"
	.string "Sé reconèixer un guanyador quan el veig!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Aquells ENTRENADORS…\n"
	.string "Què estan fent?\l"
	.string "Haurien d'acceptar reptes.$"
