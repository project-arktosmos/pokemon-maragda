SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Vols un petit consell sucós per als\n"
	.string "CONCURSOS?\p"
	.string "Usar un cert moviment després d'un\n"
	.string "altre tipus de moviment de vegades\l"
	.string "t'aconsegueix atenció extra.\p"
	.string "Si saps el que fas, pots aconseguir\n"
	.string "molts punts en l'exhibició.\p"
	.string "És clar, els teus oponents podrien\n"
	.string "intentar pertorbar el teu POKéMON.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "El meu papa és un JURAT DE CONCURS.\p"
	.string "Em pregunto què hauria de ser quan\n"
	.string "sigui gran, JURAT o LÍDER DE GIMNÀS?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Ei, tio, estic com super emprenyat,\n"
	.string "saps. Com, saps, només volia\l"
	.string "saber per què el meu POKéMON\l"
	.string "mai no guanyava, saps, com, eh?\p"
	.string "Llavors, com, vaig donar al JURAT la\n"
	.string "meva opinió, saps, és gratis.\p"
	.string "I no em va escoltar, com, eh!\n"
	.string "Llavors, com, quin pal, tio!\p"
	.string "Ei, com, tu! Calla, saps?\n"
	.string "Només, saps, pren això!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Això és, com, la MT41, saps?\n"
	.string "Ei, és TURMENT, m'escoltes?\p"
	.string "Com, no deixa que l'altre tio usi\n"
	.string "el mateix moviment dos cops seguits.\p"
	.string "Ei, ara, escolta'm bé, com,\n"
	.string "no t'estic turmentant a tu!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "PRESENTADOR: Oh, mare meva!\n"
	.string "Això no és un POKéMON fantàstic?\p"
	.string "Si us plau! Vine i participa\n"
	.string "en els nostres esplèndids CONCURSOS!\p"
	.string "Ho faràs bé! N'estic segur!\n"
	.string "Els meus ulls mai no m'han fallat!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JURAT: Bé, hola!\n"
	.string "Veig que ets un ENTRENADOR!\p"
	.string "Doncs, no estaria bé que et\n"
	.string "perdessis un CONCURS POKéMON!\p"
	.string "Aconsegueix un PASSI CONCURS a\n"
	.string "POBLE VERD i entra quan vulguis!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "És hora de l'exhibició!\n"
	.string "Amb què hauria de començar?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "No han prestat gaire atenció a\n"
	.string "l'exhibició del meu POKéMON…\p"
	.string "Bah, aquest JURAT no reconeix\n"
	.string "una cosa bona quan la veu.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, hola! Has de ser un fan seriós per\n"
	.string "arribar tan a prop de l'acció.\p"
	.string "Recompensaré el teu entusiasme amb\n"
	.string "aquest consell savi.\p"
	.string "Si un moviment funciona molt bé,\n"
	.string "el públic s'emocionarà.\p"
	.string "El POKéMON que fa la seva exhibició\n"
	.string "just quan tothom està emocionat…\p"
	.string "Bé, pensaries que alguna cosa bona\n"
	.string "ha de passar!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "No puc fer-ho! Estic més nerviós\n"
	.string "que el meu POKéMON.\p"
	.string "Estic tremolant i el cor em batega!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Un combat i un CONCURS no són el\n"
	.string "mateix, però també s'assemblen.\p"
	.string "Has de treballar dur i creure\n"
	.string "en el POKéMON que has criat.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Aquell POKéMON sembla que està en\n"
	.string "plena forma, eh?\p"
	.string "Un POKéMON que ho fa bé en la\n"
	.string "segona ronda sembla més relaxat\l"
	.string "quan fa les exhibicions.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Mira quin espectacle tan trist?\p"
	.string "Heh, el meu POKéMON és absolutament\n"
	.string "millor que tots aquests!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "No tens ganes de moure't amb els\n"
	.string "POKéMON si estan fent una exhibició\l"
	.string "energètica?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "CONCURSOS POKéMON\n"
	.string "ESCENARI RANG HYPER!$"

