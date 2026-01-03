MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Ei, com va, futur CAMPIÓ\n"
	.string "{PLAYER}?\p"
	.string "Els LÍDERS DE GIMNÀS d'aquí usen\n"
	.string "POKéMON de tipus PSÍQUIC.\p"
	.string "Si t'hi enfrontes amb POKéMON de\n"
	.string "tipus LLUITA o VERÍ, et faran\l"
	.string "un mal horrible!\p"
	.string "A més, t'atacaran amb atacs\n"
	.string "de combinació excepcionals.\p"
	.string "Si vols guanyar, hauràs de mostrar-los\n"
	.string "com de bé us enteneu, tu i els teus\l"
	.string "POKéMON. Endavant!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Uau, ets sorprenent!\n"
	.string "Ets un ENTRENADOR genial!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Els combats depenen de la força del\n"
	.string "teu esperit! Els dèbils mai no guanyen!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "He perdut!\n"
	.string "Haig de temperar el meu esperit!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Els indecisos perden.\n"
	.string "Això és el meu avís per a tu.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Deixa'm veure el teu talent!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Posseeixes un talent espectacular!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Si hi ha prodigis al món,\n"
	.string "els nostres LÍDERS DE GIMNÀS ho són!\p"
	.string "Tanmateix, potser tens encara més\n"
	.string "talent que ells…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Mira'm fer levitar una\n"
	.string "POKé BALL telecinèticament!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "A vegades, no estic sincronitzat…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Les meves habilitats de combat\n"
	.string "POKéMON tampoc estan sincronitzades!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Una POKé BALL era massa pesada per\n"
	.string "aixecar psíquicament. Però aquesta borrissol…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "No, no faig trampes!\n"
	.string "No l'he bufat! De veritat!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Quan perdis contra mi, no siguis\n"
	.string "massa dur amb tu mateix.\p"
	.string "No és que siguis dèbil--és que jo\n"
	.string "sóc massa forta!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Ets massa fort!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "No em desanimaré per perdre.\n"
	.string "Només he d'entrenar més.\p"
	.string "Pensament positiu--aquest és el meu\n"
	.string "punt fort!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Ho veig…\n"
	.string "Veig el teu futur…\p"
	.string "Si em pots guanyar, et diré\n"
	.string "el teu futur!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Em rendeixo!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Tindràs un combat terriblement intens\n"
	.string "amb els nostres LÍDERS DE GIMNÀS…\p"
	.string "El resultat…\n"
	.string "No l'escoltaràs de mi!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Els camins que has recorregut…\n"
	.string "El que has experimentat…\p"
	.string "Vine cap a mi amb tot el que\n"
	.string "has après!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Has recorregut un camí de grandesa!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Un futur brillant espera aquells que\n"
	.string "han treballat amb diligència.\p"
	.string "Per aquells que han mandriejat, només\n"
	.string "hi ha desesperació al final.\p"
	.string "El que sembres, reculls…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Fins i tot arriscant la vida, guanyaré\n"
	.string "aquest combat!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "El que fas…\n"
	.string "M'horrifitza…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Com goses guanyar-me…\p"
	.string "No serà culpa meva si et passa\n"
	.string "alguna cosa horrible…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Necessites que et mostri com de\n"
	.string "tenaç pot ser el tipus PSÍQUIC.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Oh! Vaja, vaja!\n"
	.string "El teu estil de combat és fantàstic!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Jo… No deixo que la derrota m'afecti,\n"
	.string "per molt greu que sigui.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Deixa'm mostrar-te una estona\n"
	.string "perfectament horrible i aterridora!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-nooooo!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "La teva vitalitat és contagiosa!\n"
	.string "Allunya't de mi ràpidament!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Potser ja he passat el meu millor\n"
	.string "moment, però et suggereixo que\l"
	.string "no em subestimis.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, reboses del poder\n"
	.string "de la joventut!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Sembla que no he pogut superar\n"
	.string "la teva energia juvenil.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "No arribaràs al final!\n"
	.string "No si puc evitar-ho!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Com pots ser tan ridículament\n"
	.string "fort?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Bah! Potser ets fort, però no ets\n"
	.string "adequat pel tipus PSÍQUIC!\p"
	.string "La manera com lluites és brutal!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Wroooar! Tasta el meu súper\n"
	.string "poder de combat POKéMON dur!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh!\n"
	.string "M'han derrotat!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "D'acord! Crec que desenvoluparé un\n"
	.string "poder POKéMON invencible especial!$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "VIV: Hehehe… T'has sorprès?\p"
	.string "TICA: Fufufu… T'has sorprès?\p"
	.string "VIV: Que hi ha dos LÍDERS DE GIMNÀS?\n"
	.string "TICA: Que hi ha dos LÍDERS DE GIMNÀS?\p"
	.string "VIV: Som bessons!\n"
	.string "TICA: Som bessons!\p"
	.string "VIV: No necessitem parlar perquè…\n"
	.string "TICA: Cadascú pot determinar el que…\p"
	.string "VIV: L'altre està pensant…\n"
	.string "TICA: Tot amb les nostres ments!\p"
	.string "VIV: Aquesta combinació nostra…\n"
	.string "TICA: Pots guanyar-la?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "VIV: Què?! La nostra combinació…\n"
	.string "TICA: Ha estat destruïda!\p"
	.string "VIV: No s'hi pot fer res. Has guanyat…\n"
	.string "TICA: Així que, en reconeixement, pren això.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} ha rebut la MEDALLA MENT\n"
	.string "del VIV i la TICA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "VIV: La MEDALLA MENT millora l'\n"
	.string "AT. ESP. i la DEF. ESP. dels POKéMON.\p"
	.string "TICA: També et permet usar el moviment\n"
	.string "MO BUSSEIG fora de combat.\p"
	.string "VIV: També hauries d'agafar això.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "VIV: Aquesta MT04 conté…\n"
	.string "TICA: PAU MENTAL!\p"
	.string "VIV: Augmenta l'AT. ESP. i…\n"
	.string "TICA: Augmenta la DEF. ESP.!\p"
	.string "VIV: És un moviment perfecte…\n"
	.string "TICA: Pels POKéMON PSÍQUICS!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Has registrat els LÍDERS DE GIMNÀS\n"
	.string "VIV i TICA al POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "VIV: Sembla que el vincle entre tu\n"
	.string "i els teus POKéMON és molt més fort\l"
	.string "que el vincle que compartim com bessons.\p"
	.string "TICA: Et faràs encara més fort!\n"
	.string "Hem lluitat contra tu, així que ho sabem.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "VIV: Hehehe… T'has sorprès?\p"
	.string "TICA: Que hi ha dos LÍDERS DE GIMNÀS?\p"
	.string "VIV: Upa, només tens un…\n"
	.string "TICA: POKéMON que pugui lluitar.\p"
	.string "VIV: No podem lluitar així!\p"
	.string "TICA: Si vols desafiar-nos,\n"
	.string "porta més POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "GIMNÀS POKéMON D'ALGALÀLIA$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "GIMNÀS POKéMON D'ALGALÀLIA\p"
	.string "ENTRENADORS CERTIFICATS DE VIV I TICA:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "VIV: POKéMON…\n"
	.string "TICA: POKéMON…\p"
	.string "VIV: Canviant la composició de l'equip…\n"
	.string "TICA: L'estil de combat canvia.\p"
	.string "VIV: Però jo…\n"
	.string "TICA: Però jo…\p"
	.string "VIV: Sempre estaré amb la TICA!\n"
	.string "TICA: Sempre estaré amb el VIV!\p"
	.string "VIV: La nostra combinació…\n"
	.string "TICA: Te la mostrarem una i altra vegada!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "VIV: Tu i els teus POKéMON…\n"
	.string "TICA: És com si fóssiu germans!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "VIV: Ens pots fer caure,\n"
	.string "però mai no ens quedarem a terra!\p"
	.string "TICA: Perquè nosaltres dos,\n"
	.string "sempre ens donem suport l'un a l'altre!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "VIV: Has tornat…\n"
	.string "TICA: Has tornat…\p"
	.string "VIV: Per donar-nos la revenja.\n"
	.string "TICA: Per donar-nos la revenja.\p"
	.string "VIV: Però…\n"
	.string "TICA: Pel nostre combat…\p"
	.string "VIV: Has portat només un POKéMON!\n"
	.string "TICA: Has portat només un POKéMON!\p"
	.string "VIV: Necessitem que portis almenys…\n"
	.string "TICA: Dos POKéMON quan tornis.$"
