SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Ei! Com va, {PLAYER}, futur\n"
	.string "CAMPIÓ?\p"
	.string "El LÍDER DE GIMNÀS D'ALGÈPOLIS, JAUME,\n"
	.string "és un mestre dels POKéMON de tipus AIGUA.\p"
	.string "I per arribar a JAUME, un terra gelat\n"
	.string "dificultarà el teu progrés…\p"
	.string "Escolta, ho sento, però això és tot\n"
	.string "el consell que tinc per a tu.\p"
	.string "La resta del camí, l'has de\n"
	.string "fer tu sol!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Uau! Has derrotat fins i tot JAUME, que\n"
	.string "suposadament era el millor de HOENN!\p"
	.string "Molt bé! Mira la teva TARGETA D'ENTRENADOR.\p"
	.string "Si tens totes les MEDALLES, estàs\n"
	.string "preparat per al repte de la LLIGA POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Deixa'm preguntar-te.\n"
	.string "Ho sabies?\l"
	.string "Ah, no hauria de ser tan esquiu.\p"
	.string "Vaig ser jo qui va ensenyar a BLASCO tot\n"
	.string "el que hi ha per saber sobre POKéMON.\p"
	.string "Un cop, vaig renunciar al meu càrrec\n"
	.string "com a LÍDER DE GIMNÀS.\p"
	.string "Al meu lloc, vaig confiar el GIMNÀS\n"
	.string "a BLASCO.\p"
	.string "No obstant això, va sorgir una raó\n"
	.string "convincent per tornar.\p"
	.string "Ah, però prou xerrada.\n"
	.string "Comencem el nostre combat, d'acord?\p"
	.string "Si us plau, seràs testimoni de\n"
	.string "la nostra artesania.\p"
	.string "Una gran il·lusió d'aigua esculpida\n"
	.string "pels POKéMON i per mi!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, excel·lent!\n"
	.string "Molt bé, ets el guanyador.\p"
	.string "De tu, percebo la brillantor\n"
	.string "d'habilitat que tot ho superarà.\p"
	.string "No obstant, comparat amb mi o fins\n"
	.string "i tot BLASCO, et falta elegància.\p"
	.string "Potser hauria de deixar-te\n"
	.string "el meu vestit?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha, només era broma!\p"
	.string "En lloc de la meva roba, et recompensaré\n"
	.string "amb això, la MEDALLA PLUJA!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} ha rebut la MEDALLA PLUJA\n"
	.string "de JAUME.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Tenir la MEDALLA PLUJA t'assegurarà\n"
	.string "l'obediència total de tots els teus\l"
	.string "POKéMON a cada ordre teva.\p"
	.string "La MEDALLA PLUJA també permet l'ús\n"
	.string "del moviment MO CASCADA per escalar\l"
	.string "parets d'aigua que cau.\p"
	.string "I, perquè mai no oblidis el combat\n"
	.string "que hem compartit, pren això…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La MÀQUINA TÈCNICA que t'he donat\n"
	.string "conté POLS D'AIGUA.\p"
	.string "En usar-la, ocasionalment confon\n"
	.string "l'objectiu amb ones ultrasòniques.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "S'ha registrat el LÍDER JAUME\n"
	.string "al POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Els ENTRENADORS que han reunit totes\n"
	.string "les MEDALLES DE GIMNÀS de HOENN haurien\l"
	.string "de dirigir-se a la destinació definitiva.\p"
	.string "La LLIGA POKéMON.\p"
	.string "Viatja als confins més orientals\n"
	.string "de HOENN, a l'illa SEMPREGRANDE.\p"
	.string "Allà trobaràs la LLIGA\n"
	.string "POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Només queda una MEDALLA per\n"
	.string "obtenir a HOENN.\p"
	.string "Si vols desafiar la LLIGA POKéMON,\n"
	.string "has d'obtenir l'última MEDALLA\l"
	.string "del GIMNÀS d'ARBORADA.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "GIMNÀS POKéMON D'ALGÈPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "GIMNÀS POKéMON D'ALGÈPOLIS\p"
	.string "ENTRENADORS CERTIFICATS PER JAUME:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JAUME: Ah, aquest GIMNÀS havia tornat\n"
	.string "al seu estat habitual de serenitat…\p"
	.string "Però el nostre jove tifó ha tornat\n"
	.string "per posar-nos a prova de nou!\p"
	.string "Bé, amic meu, sens dubte!\p"
	.string "Serà un plaer ballar amb tu\n"
	.string "tan sovint com vulguis!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, ets el guanyador!\n"
	.string "M'has derrotat un altre cop!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JAUME: Si et digués que fossis el meu\n"
	.string "aprenent, refusaries, n'estic segur.\p"
	.string "M'agradaria regalar-te la meva\n"
	.string "jaqueta.\p"
	.string "Però de nou, refusaries.\n"
	.string "M'imagino que és així.\p"
	.string "I això, amic meu, és un signe cert\n"
	.string "de noblesa!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JAUME: Ah, aquest GIMNÀS havia tornat\n"
	.string "al seu estat habitual de serenitat…\p"
	.string "Però el nostre jove tifó ha tornat\n"
	.string "per posar-nos a prova de nou!\p"
	.string "Bé, amic meu, sens dubte!\n"
	.string "Serà un plaer ballar amb tu…\p"
	.string "Ah, no, no, no.\n"
	.string "Només tens un POKéMON amb tu.\p"
	.string "Desitjaria que tornessis amb\n"
	.string "dos, potser més, POKéMON, si us plau.$"

