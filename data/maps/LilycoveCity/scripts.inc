LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "AURA: Oh, ei?\n"
	.string "{PLAYER}{KUN}, també estàs de compres?\p"
	.string "He comprat un munt de NINES i\n"
	.string "PÒSTERS.\p"
	.string "És clar, també he atrapat molts\n"
	.string "POKéMON, i els estic criant\l"
	.string "bé, també.\p"
	.string "De fet, m'amoïna més si tu estàs\n"
	.string "criant bé els POKéMON, {PLAYER}{KUN}.\p"
	.string "Lluitem, així pots ensenyar-me\n"
	.string "els teus POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "AURA: Oh, per què? {PLAYER}{KUN}, no has\n"
	.string "estat criant els teus POKéMON?\p"
	.string "Això no és gaire bo per ser\n"
	.string "ENTRENADOR…$"

LilycoveCity_Text_MayBattleMe:
	.string "AURA: Vinga, lluita amb mi, així puc\n"
	.string "veure els teus POKéMON!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "AURA: Els POKéMON que he criat no seran\n"
	.string "vençuts pels teus POKéMON, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Recordo el combat que vaig tenir amb tu,\n"
	.string "{PLAYER}{KUN}, a la RUTA 103.\p"
	.string "Aquell combat t'ha ajudat a fer-te\n"
	.string "tan fort, {PLAYER}{KUN}, oi?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "AURA: Estic pensant en tornar a\n"
	.string "LLAÇADA aviat.\p"
	.string "He atrapat un bon grup de POKéMON,\n"
	.string "i el meu POKéDEX progressa, així que\l"
	.string "vaig a casa a ensenyar-ho al meu pare.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, què faràs?\p"
	.string "Aconseguir totes les MEDALLES DE GIMNÀS\n"
	.string "i acceptar el repte de la LLIGA POKéMON?\p"
	.string "Bé, mentre tu reculls MEDALLES,\n"
	.string "{PLAYER}{KUN}, jo treballaré en el meu\l"
	.string "POKéDEX. El completaré abans que tu!\p"
	.string "Ens veiem!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, què faràs?\p"
	.string "Acceptaràs el repte de la\n"
	.string "LLIGA POKéMON?\p"
	.string "O completaràs el teu\n"
	.string "POKéDEX?\p"
	.string "Potser t'he perdut en combat,\n"
	.string "però acabaré el meu POKéDEX abans que tu!\p"
	.string "Ens veiem!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, què faràs?\p"
	.string "Acceptaràs el repte de la\n"
	.string "ZONA DE COMBAT?\p"
	.string "O completaràs el teu\n"
	.string "POKéDEX?\p"
	.string "Potser t'he perdut en combat,\n"
	.string "però acabaré el meu POKéDEX abans que tu!\p"
	.string "Ens veiem!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BLAI: Oh, ei, ets tu, {PLAYER}.\p"
	.string "Estic fent un encàrrec pel meu pare.\n"
	.string "No, no estic comprant NINES.\p"
	.string "De totes maneres, fa temps.\p"
	.string "Vols fer un combat per veure qui ha\n"
	.string "criat millor els POKéMON?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BLAI: Oh, què passa?\n"
	.string "No tens confiança?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BLAI: Vols lluitar per veure qui ha\n"
	.string "criat millor els POKéMON?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BLAI: Bah, però saps que no perdré\n"
	.string "contra cap {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Hmph…\n"
	.string "Has entrenat molt.\p"
	.string "Això em sap greu, jo vaig començar\n"
	.string "abans com a ENTRENADOR…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BLAI: Jo…\n"
	.string "Tinc previst tornar a casa a LLAÇADA.\p"
	.string "Saps que estic ajudant el meu pare amb\n"
	.string "el POKéDEX. Va bastant bé,\l"
	.string "així que hauria d'anar a ensenyar-li.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, què faràs?\p"
	.string "Aconseguir totes les MEDALLES DE GIMNÀS\n"
	.string "i acceptar el repte de la LLIGA POKéMON?\p"
	.string "Potser jo també ho faré…\p"
	.string "Bé, de totes maneres, ànims!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, què faràs?\p"
	.string "Com que ets tan fort, acceptaràs\n"
	.string "el repte de la LLIGA POKéMON?\p"
	.string "Heh, fins i tot jo, si entreno una mica\n"
	.string "més els meus POKéMON, hauria de ser\l"
	.string "més fort que tu, {PLAYER}.\p"
	.string "Bé, de totes maneres, ànims!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, què faràs?\p"
	.string "Acceptaràs el repte de la\n"
	.string "ZONA DE COMBAT?\p"
	.string "O completaràs el teu\n"
	.string "POKéDEX?\p"
	.string "Com que ets tan fort, hauries de\n"
	.string "considerar la ZONA DE COMBAT.\p"
	.string "Heh, si entreno una mica més els meus\n"
	.string "POKéMON, seré més fort que tu, {PLAYER}.\p"
	.string "Potser hauria d'anar a la ZONA\n"
	.string "DE COMBAT.\p"
	.string "Bé, de totes maneres, ànims!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "Avui hem mogut més botí al nostre\n"
	.string "AMAGATALL secret…\p"
	.string "Q-qui ets tu?!\n"
	.string "Estava parlant sol!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Només sóc un RECLUTA, així que no sé\n"
	.string "què pensa el CAP…\p"
	.string "Però sent de l'EQUIP AQUA, sé que tindré\n"
	.string "l'oportunitat de fer grans coses!\p"
	.string "Q-qui ets tu?!\n"
	.string "Estava parlant sol!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Ei, tu!\p"
	.string "No t'acostis a la cova de la cala!\p"
	.string "Per què? No necessites saber per què!\n"
	.string "Sóc un adult, així que fes-me cas!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Si tot aquest món es torna nostre,\n"
	.string "de l'EQUIP AQUA, serà un lloc més\l"
	.string "feliç també per als POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Aquí! WAILMER!\n"
	.string "Salta de l'aigua ara!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Eh? Què vols?\p"
	.string "Estàs molestant el nostre entrenament,\n"
	.string "pots, com si res, fotre el camp?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Hi ha una SALA DE CONCURSOS POKéMON\n"
	.string "aquí mateix a la ciutat.\p"
	.string "Això vol dir que POKéMON ben criats\n"
	.string "vindran de tot el país.\p"
	.string "El meu cor s'omple d'emoció!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Has vist aquella cova estranya a la\n"
	.string "cala als afores de la ciutat?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Ensenyaré al meu POKéMON uns moviments\n"
	.string "nous per participar en un CONCURS.\p"
	.string "Així que aniré a veure l'OBLIDADOR\n"
	.string "per fer-li oblidar els moviments MO.$"

LilycoveCity_Text_ImFromKanto:
	.string "Vinc de KANTO.\p"
	.string "La regió de HOENN és preciosa amb\n"
	.string "tota la seva aigua i natura verda.\p"
	.string "Eh? Espera un moment…\p"
	.string "Podria haver-hi POKéMON rars que només\n"
	.string "viuen en aquesta zona?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "L'EQUIP AQUA ha estat entrenant els\n"
	.string "seus WAILMER a la cala.\p"
	.string "Els MARINERS no podem treure els vaixells\n"
	.string "al mar amb ells enmig!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ei, ho sabies?\p"
	.string "Algú ha fet fora l'EQUIP AQUA\n"
	.string "per nosaltres!\p"
	.string "Això ha tret els WAILMER de la cala,\n"
	.string "així que podem treure els vaixells de nou.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Estava fent una becaina relaxant a\n"
	.string "l'hostal de la platja amb el so de les onades…\p"
	.string "Quan algú m'ha robat el POKéMON!\p"
	.string "Qui és el segrestador?\n"
	.string "L'EQUIP AQUA? És l'EQUIP AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "El meu POKéMON desaparegut…\n"
	.string "Ha tornat sense que me n'adonés!$"

LilycoveCity_Text_ImArtDealer:
	.string "Sóc un MARXANT D'ART.\p"
	.string "Sóc comprador i venedor d'art de qualitat,\n"
	.string "especialment pintures.\p"
	.string "He sentit que el MUSEU d'aquí té\n"
	.string "obres magnífiques exposades…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Fins i tot mentre ens fem vells i arrugats,\n"
	.string "el mar es manté eternament jove amb\l"
	.string "la brillantor viva de la vida…\p"
	.string "Fuhoho fuhohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Fa seixanta anys que el meu marit\n"
	.string "em va demanar en matrimoni aquí.\l"
	.string "El mar segueix tan bonic com sempre.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, coneixes la cova peculiar\n"
	.string "d'aquesta cala?\p"
	.string "Era una formació natural,\n"
	.string "però llavors l'EQUIP AQUA va arribar\l"
	.string "i va fer les seves reformes.\p"
	.string "Es diuen a ells mateixos\n"
	.string "“l'EQUIP AQUA amant de la natura”!\p"
	.string "Però el que fan i el que diuen\n"
	.string "no coincideixen gens!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Aquella cova de la cala…\p"
	.string "No me'n vaig adonar de seguida,\n"
	.string "però ara està completament buida.\p"
	.string "L'EQUIP AQUA, deuen haver-se'n\n"
	.string "anat per sempre.$"

LilycoveCity_Text_CitySign:
	.string "CIUTAT LLIRINESA\p"
	.string "“On la terra acaba i el\n"
	.string "mar comença.”$"

LilycoveCity_Text_ContestHallSign:
	.string "SALA DE CONCURSOS POKéMON\n"
	.string "“El punt de trobada dels ENTRENADORS!”$"

LilycoveCity_Text_MotelSign:
	.string "MOTEL LLIRI DE CALA\p"
	.string "“Recordeu-nos com el LLIRI DE CALA\n"
	.string "de LLIRINESA.”$"

LilycoveCity_Text_MuseumSign:
	.string "MUSEU DE LLIRINESA\p"
	.string "“Col·lecció d'obres mestres POKéMON\n"
	.string "en exhibició!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSEU DE LLIRINESA\p"
	.string "“Col·lecció POKéMON de {PLAYER}\n"
	.string "en exhibició!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "PORT DE LLIRINESA\p"
	.string "“El ferri S.S. MAREAL està en\n"
	.string "construcció a CIUTAT PORTLAVANDA.\p"
	.string "“El servei està programat per començar\n"
	.string "aviat.”$"

LilycoveCity_Text_HarborSign:
	.string "PORT DE LLIRINESA\p"
	.string "“Gaudeix d'un creuer deliciós al\n"
	.string "ferri S.S. MAREAL.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "CLUB DE FANS D'ENTRENADORS POKéMON\p"
	.string "Els noms d'ENTRENADORS estan\n"
	.string "gargotejats per tot el cartell…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "GRANS MAGATZEMS DE LLIRINESA\p"
	.string "“Desbordant de bones mercaderies\n"
	.string "i emoció!\p"
	.string "“Un lloc genial per trobar allò que\n"
	.string "necessites!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "CASA DE L'OBLIDADOR\p"
	.string "“S'eliminen moviments POKéMON no desitjats.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Coneixes la màquina\n"
	.string "BATEDORA DE BAIES?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "La gent ha de treballar junta per fer-la\n"
	.string "girar més ràpid.\p"
	.string "Com més ràpid la facis girar, millors\n"
	.string "{POKEBLOCK}S pots obtenir, m'han dit.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "S'utilitza per fer un tipus de dolç\n"
	.string "anomenat {POKEBLOCK}.\p"
	.string "Si dones un bon {POKEBLOCK} a un POKéMON,\n"
	.string "la seva condició millorarà molt.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "He sentit que hi ha una torre en algun\n"
	.string "lloc de les rutes marítimes.\p"
	.string "Es diu el PILAR CELESTE, m'han dit.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "He vist una torre alta en algun lloc\n"
	.string "al voltant de la RUTA 131.\p"
	.string "Podria ser que…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Acabem d'arribar de la nostra\n"
	.string "lluna de mel.\p"
	.string "Hem vist un POKéMON de tipus DRAC\n"
	.string "volant molt amunt al cel.\p"
	.string "Viuen POKéMON tan macos com aquest\n"
	.string "a la regió de HOENN?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "A la nostra lluna de mel, vam prometre veure\n"
	.string "tants POKéMON rars com poguéssim.\p"
	.string "Així que ens va encantar veure un POKéMON\n"
	.string "rar tan bon punt vam arribar.\p"
	.string "Vull dir, estem totalment contents!$"

