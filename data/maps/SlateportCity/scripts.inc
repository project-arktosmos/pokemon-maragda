SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Sóc el GURU DE L'ENERGIA! Donaré el\n"
	.string "màxim i et vendré el que necessitis!$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "El teu {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "S'ha esforçat increïblement!\p"
	.string "Com a recompensa, si us plau\n"
	.string "dona-li aquesta CINTA ESFORÇ.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} ha rebut la CINTA ESFORÇ.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} ha posat la CINTA ESFORÇ\n"
	.string "a {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Has d'esforçar-te una mica més.\p"
	.string "Si ho fas, donaré al teu POKéMON\n"
	.string "alguna cosa bonica.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! El teu {STR_VAR_1}, la CINTA\n"
	.string "ESFORÇ li queda molt bé!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La llum del far arriba a desenes\n"
	.string "de quilòmetres.\p"
	.string "Em pregunto si no espanta els POKéMON\n"
	.string "del mar.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Ooh, mira això!\p"
	.string "Les algues que pots trobar per aquí\n"
	.string "són fresques i plenes de vida.\p"
	.string "Sembla que fins i tot puguin alçar-se\n"
	.string "i atacar!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "On l'aigua és neta, s'apleguen els\n"
	.string "fruits d'una collita abundant.\p"
	.string "I on s'aplega la gent, aviat\n"
	.string "comença un mercat.\p"
	.string "Així és com una ciutat neix i creix.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Comprar on pots respirar l'olor\n"
	.string "de l'oceà…\p"
	.string "PORTLAVANDA és un lloc meravellós!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Si poses NINES o COIXINS al terra,\n"
	.string "s'embruten.\p"
	.string "Compraré uns MAONS perquè les meves\n"
	.string "NINES i COIXINS no s'embrutin\l"
	.string "quan els deixi fora.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar! Jo també competiré a\n"
	.string "la CARPA DE COMBAT!\p"
	.string "Però abans d'això, he d'atrapar\n"
	.string "alguns POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Uf… Estic rebentada…\p"
	.string "He caminat des de CIUTAT MALVALONA.\n"
	.string "Però, noi, aquesta ciutat és enorme.\p"
	.string "Si ho hagués sabut, hauria vingut\n"
	.string "amb la meva BICI.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, el tipus que va construir\n"
	.string "el MUSEU, resulta que també és el líder\l"
	.string "d'un equip d'exploració submarina.\p"
	.string "Per això, tothom el diu CAPITÀ STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Què és allò d'allà?\n"
	.string "Aquella cua tan llarga…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Quan era petit, visitava\n"
	.string "el MUSEU sovint.\p"
	.string "Somiava amb els misteris del mar\n"
	.string "després de veure les exposicions.$"

SlateportCity_Text_QuitPushing:
	.string "Ei, tu! Deixa d'empènyer!\n"
	.string "Això és la cua, no ho veus?$"

SlateportCity_Text_AquaHasPolicy:
	.string "L'EQUIP AQUA té una política de\n"
	.string "reunir-se i dispersar-se al lloc\l"
	.string "de l'operació.$"

SlateportCity_Text_BossIsBrilliant:
	.string "El nostre CAP és brillant.\p"
	.string "Què voldrà fer amb\n"
	.string "un MUSEU ara?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Quin és el nou pla, em pregunto?\p"
	.string "El nostre CAP fa por quan s'enfada,\n"
	.string "així que més val que no la cagui…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Si hi ha alguna cosa que necessitem\n"
	.string "al MUSEU, ho hauríem d'agafar tot!$"

SlateportCity_Text_DontButtIn:
	.string "Ei, tu!\n"
	.string "No t'hi fiquis!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Una cua llarga, eh?\p"
	.string "Em recorda les vegades que feia cua\n"
	.string "per comprar jocs supervendes…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Per què estem fent cua i pagant?\n"
	.string "Hauríem d'entrar directament!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Què?\n"
	.string "Què vols?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Vols llegir aquest cartell?\n"
	.string "T'ho llegiré!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "A veure…\p"
	.string "Um… Crec que diu alguna cosa com\n"
	.string "“la vida al mar és infinita.”\p"
	.string "Sí, estic bastant segur que diu\n"
	.string "això.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grr…\p"
	.string "Hauria d'haver portat la meva Game Boy\n"
	.string "Advance per no avorrir-me a la cua…\p"
	.string "Grr…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Quan acabi aquesta operació, us portaré\n"
	.string "a un balneari d'aigües termals!\p"
	.string "Això és el que ha dit el nostre líder.\n"
	.string "No puc esperar!$"

SlateportCity_Text_SeaIsSoWet:
	.string "El mar és tan immens…\p"
	.string "Podria ser que el mar fos fet amb\n"
	.string "les llàgrimes dels POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Saps què fan amb els vaixells vells\n"
	.string "que ja no poden navegar?\p"
	.string "Els enfonsen al mar perquè\n"
	.string "es converteixin en hàbitats per a POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Sempre que vinc aquí, em deixo portar\n"
	.string "i compro massa.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Si vols canviar el malnom del teu\n"
	.string "POKéMON, hauràs de demanar ajuda\l"
	.string "al JUTGE DE NOMS.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Qualsevol POKéMON que obtinguis en\n"
	.string "un intercanvi, no pots canviar-li el nom.\p"
	.string "L'amor de l'ENTRENADOR original per\n"
	.string "aquell POKéMON està en el malnom.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Recentment, s'ha construït una CARPA\n"
	.string "DE COMBAT a PORTLAVANDA.\p"
	.string "Els GIMNASOS són divertits, però la\n"
	.string "CARPA DE COMBAT és impressionant.\p"
	.string "Hauries d'anar a buscar POKéMON forts\n"
	.string "per a la CARPA DE COMBAT!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Esperava que fos una estrella famosa\n"
	.string "per poder aconseguir un autògraf.\p"
	.string "Però qui és aquest que entrevisten?\n"
	.string "No és el CAPITÀ STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Aquella entrevistadora és tan\n"
	.string "elegant i bonica.\p"
	.string "Quan sigui gran, seré\n"
	.string "una periodista internacional!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "El CAPITÀ STERN diu que han descobert\n"
	.string "alguna cosa al fons del mar.\p"
	.string "Què deu ser?\n"
	.string "Què pot ser?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Què passa aquí?\p"
	.string "El bon CAPITÀ ha tornat amb un\n"
	.string "peix gros del fons de l'oceà?$"

SlateportCity_Text_AmIOnTV:
	.string "Ei! Esteu mirant?\n"
	.string "Surto a la TV?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Una entrevista de TV! Aquí!\n"
	.string "El CAPITÀ és una celebritat!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: D'acord, CAPITÀ STERN, un gran\n"
	.string "somriure per a la càmera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Ja veig, ja veig. Heu tingut una\n"
	.string "experiència de valor incalculable…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPITÀ STERN: Sí, efectivament. Tenim\n"
	.string "previst continuar amb l'exploració.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Fantàstic, CAPITÀ STERN!\n"
	.string "Gràcies per dedicar-nos temps de la\l"
	.string "seva agenda tan ocupada.\p"
	.string "Esperem poder entrevistar-lo de nou\n"
	.string "amb notícies de més descobriments!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPITÀ STERN: Uf…\p"
	.string "Era la primera vegada que em\n"
	.string "filmaven per TV. Quina tensió.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "Tens molt bon aspecte!\p"
	.string "Hem fet un gran descobriment a la\n"
	.string "nostra última exploració submarina.\p"
	.string "Hem trobat una caverna submarina\n"
	.string "a la RUTA 128.\p"
	.string "Creiem que és l'hàbitat d'un POKéMON\n"
	.string "que es deia que feia molt que s'havia extingit.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "CAPITÀ STERN, suposo.\p"
	.string "Nosaltres, l'EQUIP AQUA, assumirem\n"
	.string "el control del seu submarí!\p"
	.string "Les seves objeccions no serveixen de res!\n"
	.string "Esperem la seva total cooperació!\p"
	.string "Fufufu…\n"
	.string "Mireu i apreneu què té planejat\l"
	.string "l'EQUIP AQUA!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPITÀ STERN: Què ha estat això?\p"
	.string "Semblava algú usant\n"
	.string "un megàfon…\p"
	.string "D'on venia?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "És del PORT!\p"
	.string "El submarí!\n"
	.string "Intenten robar-lo!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Si us plau, vine amb mi!$"

SlateportCity_Text_BattleTentSign:
	.string "CARPA DE COMBAT SEU DE PORTLAVANDA\n"
	.string "“Troba'l! El POKéMON definitiu!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "DRASSANES STERN\p"
	.string "“Es busca: Un mariner capaç de navegar\n"
	.string "en tots els corrents.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "DRASSANES STERN\p"
	.string "“El ferri S.S. MAREAL s'apropa\n"
	.string "a la seva finalització per servir\l"
	.string "els ports de PORTLAVANDA i LLIRINESA.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "DRASSANES STERN\p"
	.string "“L'embarcament al ferri S.S. MAREAL\n"
	.string "de PORTLAVANDA a LLIRINESA es gestiona\l"
	.string "al PORT.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "CLUB DE FANS POKéMON\n"
	.string "“Cridem a tots els fans de POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“El mar infinit sosté\n"
	.string "tota la vida.”\p"
	.string "MUSEU OCEÀNIC$"

SlateportCity_Text_CitySign:
	.string "CIUTAT PORTLAVANDA\p"
	.string "“El port on persones i POKéMON\n"
	.string "creuen camins.”$"

SlateportCity_Text_MarketSign:
	.string "MERCAT DE PORTLAVANDA\n"
	.string "“Articles únics que no trobaràs enlloc més!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PORT DE PORTLAVANDA\p"
	.string "“El ferri S.S. MAREAL està en\n"
	.string "construcció a les DRASSANES.\p"
	.string "“El servei està programat per començar\n"
	.string "aviat.”$"

SlateportCity_Text_HarborSign:
	.string "PORT DE PORTLAVANDA\p"
	.string "“Gaudeix d'un creuer deliciós al\n"
	.string "ferri S.S. MAREAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "CASA DEL JUTGE DE NOMS\n"
	.string "“Avaluem malnoms de POKéMON.”$"

SlateportCity_Text_ExplainBerries:
	.string "Si un POKéMON salvatge es fa mal, es\n"
	.string "cura mossegant BAIES.\p"
	.string "Ho sabies?\p"
	.string "Algú va veure això i va tenir la idea\n"
	.string "de fer medicines a partir de BAIES.\p"
	.string "Ho sabies?\p"
	.string "Per convertir BAIES en medicina,\n"
	.string "s'han de triturar fins fer-ne pols.\p"
	.string "Ho sabies?\p"
	.string "Sembla que t'interessen\n"
	.string "les BAIES!\p"
	.string "Tinc alguna cosa bona per a algú\n"
	.string "com tu.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Recentment he fet instal·lar màquines\n"
	.string "als CENTRES POKéMON per triturar BAIES.\p"
	.string "Les màquines TRITURABAIES són\n"
	.string "al RACÓ DIRECTE del pis de dalt.\p"
	.string "Ho sabies?\p"
	.string "Podries fer-me POLS DE BAIES\n"
	.string "usant aquestes màquines?\p"
	.string "Puc fer-te tota mena de medicines\n"
	.string "si em portes molta POLS DE BAIES.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "M'has portat\n"
	.string "POLS DE BAIES?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Per què vols canviar-la?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "D'acord, vols canviar la teva\n"
	.string "POLS DE BAIES per un/a {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oh, vaja. No tens prou\n"
	.string "POLS DE BAIES.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Aquesta és una POLS DE BAIES excel·lent.\n"
	.string "Farà una medicina magnífica.\p"
	.string "Vols canviar més de la teva\n"
	.string "POLS DE BAIES per alguna altra cosa?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "D'acord! Quan tinguis més\n"
	.string "POLS DE BAIES, porta-me-la, si us plau!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Torna si vols canviar la teva\n"
	.string "POLS DE BAIES per alguna medicina.\p"
	.string "Sempre tinc una paradeta aquí.\p"
	.string "Ho sabies?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Eh?\n"
	.string "Estic segur que t'he vist abans.\p"
	.string "M'he presentat?\n"
	.string "Si no ho he fet, em dic SCOTT.\p"
	.string "Acabo de veure l'EQUIP AQUA fugir\n"
	.string "d'aquí com si els haguessin picat.\p"
	.string "Deixa'm endevinar, els has fet fora?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hmm…\n"
	.string "Potser, només potser, aquest ENTRENADOR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: D'acord! Crec que serem\n"
	.string "bons amics.\p"
	.string "Doncs, registrem-nos mútuament\n"
	.string "als POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "S'ha registrat en SCOTT\n"
	.string "al POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: M'agradaria acompanyar-te,\n"
	.string "però també vull vigilar el talent\l"
	.string "d'altres persones.\p"
	.string "Així que me n'aniré a voltar per\n"
	.string "altres ciutats una mica més.\p"
	.string "Ens veiem, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Oh, ei!\n"
	.string "Però si és {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, deixa'm endevinar, vas a\n"
	.string "acceptar el repte de la CARPA DE COMBAT?\p"
	.string "Sí! És una bona idea!\n"
	.string "És una idea fantàstica!\p"
	.string "Després de tot, un ENTRENADOR dur\n"
	.string "és perfecte per a la CARPA DE COMBAT!\p"
	.string "Dóna-ho tot!$"
