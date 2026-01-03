JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "El SENDER ESQUERP del MT. XEMENEIES…\p"
	.string "Això és el que sempre havia volgut\n"
	.string "d'una muntanya.\p"
	.string "Aquesta rugositat aspra…\n"
	.string "Em commou l'ànima!$"

JaggedPass_Text_EricDefeat:
	.string "Perdre m'ha deixat amargat!$"

JaggedPass_Text_EricPostBattle:
	.string "Sí, he perdut al combat POKéMON…\p"
	.string "Però, pel que fa a l'amor per\n"
	.string "les muntanyes, et supero!$"

JaggedPass_Text_DianaIntro:
	.string "Aquest lloc no és un passeig qualsevol.\n"
	.string "No és adequat per un pícnic.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, no!\n"
	.string "El terreny és massa irregular…$"

JaggedPass_Text_DianaPostBattle:
	.string "Ho sabies?\p"
	.string "Algunes persones pugen hàbilment\n"
	.string "aquest sender horrible amb bicicleta.$"

JaggedPass_Text_DianaRegister:
	.string "Tornaràs mai per aquesta zona?\n"
	.string "Si tornes, m'agradaria la revenja.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Els pícnics són divertits arreu.\n"
	.string "Igual que els POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Només he perdut perquè el terreny\n"
	.string "és massa irregular!$"

JaggedPass_Text_DianaPostRematch:
	.string "Oblidaré la derrota i simplement\n"
	.string "gaudiré d'aquesta excursió accidentada.$"

JaggedPass_Text_EthanIntro:
	.string "El SENDER ESQUERP és difícil de caminar.\n"
	.string "És un bon lloc per entrenar.$"

JaggedPass_Text_EthanDefeat:
	.string "Tot va acabar mentre encara\n"
	.string "intentàvem trobar bon suport…$"

JaggedPass_Text_EthanPostBattle:
	.string "Si tingués una BICI ACROBÀTICA,\n"
	.string "podria saltar les vores!$"

JaggedPass_Text_EthanRegister:
	.string "Quan m'acostumi més a aquesta rugositat,\n"
	.string "segur que guanyaré!\p"
	.string "Em pots registrar al POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "M'he acostumat a aquesta rugositat.\n"
	.string "Ara canto mentre pujo.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Encara no és fàcil combatre en\n"
	.string "aquest terreny tan irregular…$"

JaggedPass_Text_EthanPostRematch:
	.string "Hauria d'aconseguir una BICI ACROBÀTICA\n"
	.string "d'en RODA a MALVALUNA…$"

JaggedPass_Text_GruntIntro:
	.string "Uah!\n"
	.string "Què fas aquí?\p"
	.string "Què faig jo en un lloc com aquest?\p"
	.string "I tu què tens a veure amb això?$"

JaggedPass_Text_GruntDefeat:
	.string "Arrrgh…\p"
	.string "Hauria haver entrat al nostre\n"
	.string "AMAGATALL de seguida…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "D'acord, d'acord!\n"
	.string "Ho admeto: ets fort!\p"
	.string "No et preocupis per mi.\n"
	.string "Vés on vulguis!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Aquesta roca tremola en resposta\n"
	.string "a l'EMBLEMA MAGMA!$"

JaggedPass_Text_JulioIntro:
	.string "Aiii! Fa molta por baixar per\n"
	.string "la muntanya d'un cop!$"

JaggedPass_Text_JulioDefeat:
	.string "Em sento com si em fes a trossos…$"

JaggedPass_Text_JulioPostBattle:
	.string "La bici m'ha rebotat tant que\n"
	.string "tinc el cul adolorit…$"

JaggedPass_Text_AutumnIntro:
	.string "Pujo aquest turó cada dia.\n"
	.string "Confio en la meva força!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "Què ha anat malament?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Què és aquella estranya protuberància\n"
	.string "rocosa una mica més amunt?$"

