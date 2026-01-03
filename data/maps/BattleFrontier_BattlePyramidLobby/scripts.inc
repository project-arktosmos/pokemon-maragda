BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "On es posa a prova el coratge\n"
	.string "dels ENTRENADORS!\p"
	.string "Benvingut a la PIRÀMIDE COMBAT!\p"
	.string "Sóc la teva guia a la\n"
	.string "Cerca de Combat.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Tens el coratge d'embarcar-te en\n"
	.string "el repte de la Cerca de Combat?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Esperem el teu repte en el futur!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "La Cerca de Combat és un event\n"
	.string "de combat on has d'explorar la\l"
	.string "PIRÀMIDE i intentar arribar al cim.\p"
	.string "A la PIRÀMIDE hi ha set pisos de\n"
	.string "laberints, tots plens no només\l"
	.string "d'ENTRENADORS hàbils sinó també\l"
	.string "de POKéMON salvatges.\p"
	.string "Has d'entrar amb tres POKéMON,\n"
	.string "cap d'ells portant un objecte.\p"
	.string "Durant l'ascens, se't proporcionarà\n"
	.string "una MOTXILLA DE COMBAT per objectes.\p"
	.string "Si falles en el repte, qualsevol\n"
	.string "objecte posat a la MOTXILLA DE\l"
	.string "COMBAT desapareixerà.\p"
	.string "Si vols interrompre el repte,\n"
	.string "has de seleccionar “DESCANS”\l"
	.string "i desar la partida.\p"
	.string "Si no deses abans d'interrompre,\n"
	.string "seràs desqualificat.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "La PIRÀMIDE ofereix dos cursos,\n"
	.string "Nivell 50 i Nivell Obert.\l"
	.string "A quin entraràs?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Molt bé. Ara, si us plau selecciona\n"
	.string "els tres POKéMON que vols que\l"
	.string "t'acompanyin.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Un petit problema, aventurer!\p"
	.string "Sembla que no tens els tres POKéMON\n"
	.string "qualificats per al repte.\p"
	.string "Si us plau, recorda també treure\n"
	.string "tots els objectes dels teus POKéMON.\p"
	.string "ELS OUS{STR_VAR_1} no són elegibles.\p"
	.string "Quan estiguis a punt, si us plau\n"
	.string "parla amb mi.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Un petit problema, aventurer!\p"
	.string "Sembla que no tens els tres POKéMON\n"
	.string "qualificats per al repte.\p"
	.string "Els tres POKéMON han de ser diferents\n"
	.string "i cap superior al Nivell 50.\p"
	.string "Si us plau, recorda també treure\n"
	.string "tots els objectes dels teus POKéMON.\p"
	.string "ELS OUS{STR_VAR_1} no són elegibles.\p"
	.string "Quan estiguis a punt, si us plau\n"
	.string "parla amb mi.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Abans d'entrar a la PIRÀMIDE COMBAT,\n"
	.string "s'ha de desar la partida. Et sembla bé?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Molt bé. Ara t'acompanyaré\n"
	.string "a la PIRÀMIDE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Guardarem la teva MOTXILLA mentre\n"
	.string "explores, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "A canvi, si us plau agafa aquesta\n"
	.string "MOTXILLA DE COMBAT, la que vas\l"
	.string "usar abans.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "A canvi, si us plau agafa aquesta\n"
	.string "MOTXILLA DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} ha intercanviat la MOTXILLA\n"
	.string "per la MOTXILLA DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Quan trepitgis aquest panell,\n"
	.string "seràs transportat a un pis superior\l"
	.string "de la PIRÀMIDE.\p"
	.string "Espero que la teva cerca\n"
	.string "vagi amb seguretat!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Un problema greu, explorador!\p"
	.string "No vas desar abans d'acabar\n"
	.string "el repte l'últim cop.\p"
	.string "En conseqüència, el teu repte ha\n"
	.string "estat desqualificat, ho lamento.\p"
	.string "Aquí tens la MOTXILLA que havíem\n"
	.string "guardat per a tu.\p"
	.string "{PLAYER} ha recuperat la MOTXILLA.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Excel·lent veure't de tornada!\p"
	.string "Has conquerit la PIRÀMIDE!\n"
	.string "Què esplèndid!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, un petit problema.\p"
	.string "Almenys un POKéMON porta un\n"
	.string "objecte.\p"
	.string "Ho lamento, però els objectes obtinguts\n"
	.string "a la PIRÀMIDE no es poden endur.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Tots els objectes portats pels teus\n"
	.string "POKéMON es mouran a la teva MOTXILLA\l"
	.string "DE COMBAT, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "La MOTXILLA DE COMBAT no pot guardar\n"
	.string "tots els objectes, ho lamento.\p"
	.string "Si us plau, tria els objectes que\n"
	.string "guardaràs a la MOTXILLA DE COMBAT\l"
	.string "i amb els teus POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Almenys un POKéMON encara porta\n"
	.string "un objecte.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Si us plau, tria els objectes que\n"
	.string "guardaràs a la MOTXILLA DE COMBAT\l"
	.string "i amb els teus POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} ha retornat tot el que\n"
	.string "portaven els POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "La MOTXILLA DE COMBAT que has usat\n"
	.string "es guardarà per al teu pròxim repte.\p"
	.string "{PLAYER} ha lliurat la MOTXILLA DE\n"
	.string "COMBAT per recuperar la MOTXILLA.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "He d'enregistrar els teus resultats.\n"
	.string "Si us plau, espera.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Com a record per conquerir la\n"
	.string "PIRÀMIDE COMBAT, si us plau agafa això.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} ha rebut el premi\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah…\n"
	.string "Sembla que la teva MOTXILLA és plena.\p"
	.string "Si us plau, torna després d'haver\n"
	.string "organitzat el contingut de la MOTXILLA.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Quina decepció per a tu…\p"
	.string "Aquí tens la MOTXILLA que havíem\n"
	.string "guardat per a tu.\p"
	.string "{PLAYER} ha recuperat la MOTXILLA.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Esperem el teu pròxim repte!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Estàvem esperant la teva\n"
	.string "arribada!\p"
	.string "Aquí tens el teu premi per conquerir\n"
	.string "la PIRÀMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Benvingut…\p"
	.string "Em complaurà dir-te quines\n"
	.string "desgràcies t'esperen a la PIRÀMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Veig una pluja d'espurnes…\p"
	.string "…I en ella, veig els teus POKéMON\n"
	.string "lluitant amb la paràlisi…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Veig verí…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "els efectes del verí…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Veig flames de color vermell viu…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "cremades…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Sento la tremenda pressió de la\n"
	.string "ira no corresposta…\p"
	.string "És una maledicció…\p"
	.string "…I veig els teus POKéMON exhaurits\n"
	.string "de Punts de Poder i sense més recurs\l"
	.string "que usar FORCEJEO…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Veig POKéMON planant alt…\p"
	.string "…I veig els teus POKéMON frustrats\n"
	.string "per moviments de tipus TERRA\l"
	.string "sense poder…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Sento una energia terrible sorgint\n"
	.string "de terra…\p"
	.string "…I veig els teus POKéMON incapaços\n"
	.string "d'escapar de les urpes del poder…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Veig POKéMON de tipus GEL…\p"
	.string "…I veig els teus POKéMON lluitant\n"
	.string "contra els efectes congeladors del gel…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Veig una ràfega de moviments que\n"
	.string "posen en perill l'usuari…\p"
	.string "…I veig els teus POKéMON caient\n"
	.string "davant d'ells…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Veig POKéMON de tipus PSÍQUIC…\p"
	.string "…I veig els teus POKéMON turmentats\n"
	.string "per moviments PSÍQUICS…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Veig POKéMON de tipus ROCA…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "dels moviments de ROCA…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Veig POKéMON de tipus LLUITA…\p"
	.string "…I veig els teus POKéMON colpejats\n"
	.string "per moviments de LLUITA…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "DANSA PLUJA… DIA ASSOLELLAT…\n"
	.string "TEMPESTA DE SORRA… CALAMARSA…\p"
	.string "Veig POKéMON que es fan més forts\n"
	.string "amb el temps…\p"
	.string "…I veig els teus POKéMON confosos\n"
	.string "per diferents tipus de moviments…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Veig POKéMON de tipus INSECTE…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "de diferents tipus d'atacs…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Veig POKéMON de tipus FOSC…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "dels moviments de tipus FOSC…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Veig POKéMON de tipus AIGUA…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "dels moviments de tipus AIGUA…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Veig POKéMON de tipus FANTASMA…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "dels moviments de tipus FANTASMA…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Veig POKéMON de tipus ACER…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "de moviments enormement poderosos…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Veig POKéMON voladors…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "de moviments enormement poderosos…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Veig aquells que han evolucionat\n"
	.string "pel poder de les pedres…\p"
	.string "També sento foc, aigua\n"
	.string "i electricitat…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "d'aquests tres poders…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Veig POKéMON de tipus NORMAL…\p"
	.string "…I veig els teus POKéMON patint\n"
	.string "de moviments enormement poderosos…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Si creus les meves prediccions o no,\n"
	.string "l'elecció és teva…\p"
	.string "El futur pot canviar-se en qualsevol\n"
	.string "moment… Et desitjo un viatge segur…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Ho sabies?\p"
	.string "Si corres ràpid, els ENTRENADORS\n"
	.string "et poden notar i venir a combatre.\p"
	.string "Així que, si vols evitar ENTRENADORS,\n"
	.string "no els miris als ulls, però passa\l"
	.string "amb cautela i silenciosament.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Arrrrrrgh!\p"
	.string "Tenia molts objectes, però els vaig\n"
	.string "perdre tots quan vaig perdre!\p"
	.string "Arrrrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Benvingut de tornada!\n"
	.string "Has fet l'impensable!\p"
	.string "Has derrotat el REI DE LA PIRÀMIDE\n"
	.string "i has conquerit la PIRÀMIDE COMBAT!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Jove explorador!\n"
	.string "En reconeixement del teu coratge,\l"
	.string "et donem aquests Punts de Combat!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Les regles de la Cerca de Combat\n"
	.string "estan llistades.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Quina secció vols llegir?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Quan es conqueri la PIRÀMIDE,\n"
	.string "els POKéMON salvatges que hi apareixen\l"
	.string "són substituïts per tipus diferents.\p"
	.string "Explora, observa i aprèn quins tipus\n"
	.string "de POKéMON salvatges et pots trobar.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Els ENTRENADORS t'esperen amagats\n"
	.string "dins de la PIRÀMIDE.\p"
	.string "A cada pis, hi ha fins a vuit\n"
	.string "ENTRENADORS.\p"
	.string "Quan derrotis un ENTRENADOR, rebràs\n"
	.string "una pista útil per a la teva aventura.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Els laberints de la PIRÀMIDE es\n"
	.string "reorganitzen cada cop que hi entres.\p"
	.string "Els laberints tenen poca llum.\n"
	.string "Has d'avançar amb precaució.\p"
	.string "La llum creix cada cop que derrotes\n"
	.string "un POKéMON salvatge o un ENTRENADOR.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "La MOTXILLA DE COMBAT serveix com a\n"
	.string "MOTXILLA mentre ets a la PIRÀMIDE.\p"
	.string "Hi ha dues MOTXILLES DE COMBAT\n"
	.string "separades, una per a Nivell 50\l"
	.string "i una per a Nivell Obert.\p"
	.string "Cadascuna pot guardar fins a 99\n"
	.string "unitats de deu tipus d'objectes.\p"
	.string "El contingut de la MOTXILLA DE COMBAT\n"
	.string "es perd si falles en la cerca.$"

