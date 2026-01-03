MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "El poder contingut en el METEORIT…\p"
	.string "Amplificant el seu poder amb aquesta\n"
	.string "màquina, l'activitat volcànica del\l"
	.string "MT. XEMENEIA s'intensificarà…\p"
	.string "La seva energia creixerà a l'interior\n"
	.string "del cràter i…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MÀXIM: Hm?\n"
	.string "Qui ets?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "He sentit l'ARCHIBALD queixant-se d'un\n"
	.string "nen que s'ha estat ficant en els\l"
	.string "assumptes de l'EQUIP AQUA.\p"
	.string "Deus ser tu a qui es referia.\p"
	.string "Bah! Així que penses interferir\n"
	.string "amb nosaltres, l'EQUIP MAGMA?\p"
	.string "Escolta'm bé.\n"
	.string "Fa molt de temps, els éssers vius\l"
	.string "van usar la terra per viure i créixer.\p"
	.string "Per això la terra és tan important!\n"
	.string "És el bressol de tot!\p"
	.string "Per això l'EQUIP MAGMA es dedica\n"
	.string "a l'expansió de la massa terrestre.\p"
	.string "És per l'avenç de la humanitat\n"
	.string "i dels POKéMON!\p"
	.string "I per això, necessitem el poder del\n"
	.string "que dorm dins d'aquesta muntanya…\p"
	.string "Oh! No calia que sabessis\n"
	.string "tot això.\p"
	.string "Però, tant és!\n"
	.string "T'ensenyaré les conseqüències de\l"
	.string "ficar-te en el nostre gran disseny!$"

MtChimney_Text_MaxieDefeat:
	.string "Què?!\p"
	.string "Jo, MÀXIM, m'han agafat desprevingut?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MÀXIM: Però, prou.\n"
	.string "Aquesta vegada em retiraré.\p"
	.string "Però no pensis que aquesta és l'última\n"
	.string "vegada que veuràs l'EQUIP MAGMA.\p"
	.string "Fufufu…\p"
	.string "Fins i tot sense el METEORIT, si\n"
	.string "obtenim aquell ORB… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "Així que has arribat fins aquí!\p"
	.string "Però ja és massa tard!\n"
	.string "Ja he lliurat el METEORIT\l"
	.string "de les CASCADES METEÒRIQUES al CAP!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe…\p"
	.string "Tot i que he perdut, si el nostre líder\n"
	.string "desperta allò…$"

MtChimney_Text_TabithaPostBattle:
	.string "CAP, afanya't!\n"
	.string "Dóna-li l'energia del METEORIT!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro:
	.string "Nosaltres, l'EQUIP MAGMA, treballem dur\n"
	.string "pel bé de tothom.\p"
	.string "Si el poder d'allò fes més terra,\n"
	.string "hi hauria més llocs per viure.\p"
	.string "Tothom seria feliç!$"

MtChimney_Text_Grunt2Defeat:
	.string "Eh?\n"
	.string "Com que he perdut?$"

MtChimney_Text_Grunt2PostBattle:
	.string "El nostre CAP diu: “Farà que tothom\n"
	.string "sigui feliç.”\p"
	.string "Però per què tothom s'entossudeix\n"
	.string "a posar-se al nostre camí?$"

MtChimney_Text_Grunt1Intro:
	.string "Si hi hagués més terra, podria tenir\n"
	.string "una casa gran per a mi sol!\p"
	.string "La construiré sobre lava endurida!$"

MtChimney_Text_Grunt1Defeat:
	.string "El meu somni d'una casa gran…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Un nen com tu hauria d'estar\n"
	.string "xipollant entre les onades!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Aquest EQUIP AQUA tan molest…\n"
	.string "Sempre s'emboliquen amb els plans!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "Els METEORITS tenen un poder increïble!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Millor que no et fiquis amb nosaltres!\p"
	.string "Estem intentant despertar allò\n"
	.string "pel bé de tothom!$"

MtChimney_Text_AquasNameSimilar:
	.string "Nosaltres som l'EQUIP MAGMA!\p"
	.string "Ells són l'EQUIP AQUA!\p"
	.string "Em molesta molt que facin servir\n"
	.string "un nom tan semblant al nostre!$"

MtChimney_Text_DouseThemInFire:
	.string "Sí!\n"
	.string "Cremeu-los amb foc!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Continuarem fent més terra!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIBALD: Grr, {PLAYER}!\n"
	.string "Hauria d'haver endevinat que vindries!\p"
	.string "Mira tu mateix què fan els fanàtics\n"
	.string "de l'EQUIP MAGMA!\p"
	.string "Estan intentant injectar el poder del\n"
	.string "METEORIT robat al volcà!\p"
	.string "Fer una cosa així provocarà\n"
	.string "l'erupció del volcà!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIBALD: Grrr…\p"
	.string "Vull aturar en MÀXIM,\n"
	.string "però no puc!\p"
	.string "No quan estic ocupat lluitant\n"
	.string "contra tres oponents alhora!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIBALD: {PLAYER}!\n"
	.string "Gràcies!\p"
	.string "Amb la teva ajuda, hem frustrat\n"
	.string "el pla destructiu de l'EQUIP MAGMA!\p"
	.string "Però… Tu…\n"
	.string "De quin costat estàs?\p"
	.string "Ah, tant és.\p"
	.string "Seguirem vigilants i continuarem\n"
	.string "perseguint l'EQUIP MAGMA.\p"
	.string "{PLAYER}, ens tornarem a trobar!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Maleït sigui… L'EQUIP MAGMA ens supera!\n"
	.string "No podem seguir-los el ritme!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Si expandeixen la terra, hi haurà\n"
	.string "menys hàbitats pels POKéMON D'AIGUA!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Nosaltres som l'EQUIP AQUA!\p"
	.string "Ells són l'EQUIP MAGMA!\p"
	.string "Em crema que facin servir un nom\n"
	.string "tan confús!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "Les GALETES DE LAVA són l'especialitat\n"
	.string "local del MT. XEMENEIA.\p"
	.string "Prova'n una. Només costa ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Gràcies, bonica!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, bonica. No pots comprar res si\n"
	.string "no tens diners.$"

MtChimney_Text_OhFineThen:
	.string "Ah, doncs res.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "Hi ha un METEORIT col·locat en una\n"
	.string "màquina misteriosa…\p"
	.string "Sembla que la màquina està emmagatzemant\n"
	.string "energia al METEORIT.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Hi ha un METEORIT col·locat en una\n"
	.string "màquina misteriosa…\p"
	.string "Vols treure el METEORIT?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} ha tret el METEORIT de la\n"
	.string "màquina misteriosa.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} ha deixat el METEORIT\n"
	.string "on era.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Aquesta màquina misteriosa…\n"
	.string "No dona cap resposta.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} CAMÍ ESCARPAT\n"
	.string "POBLE LAVACALDA ENDAVANT$"

MtChimney_Text_ShelbyIntro:
	.string "He estat a les termes i m'he refrescat\n"
	.string "els ossos cansats.\l"
	.string "Ara mateix em sento fort!$"

MtChimney_Text_ShelbyDefeat:
	.string "Oh, mare meva.\n"
	.string "Però si ets algú de veritat!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Bé, bé, he perdut. Ja no em puc dir\n"
	.string "un EXPERT, oi?$"

MtChimney_Text_ShelbyRegister:
	.string "Gràcies, criatura. Ha estat divertit,\n"
	.string "com si lluités contra el meu nét.\p"
	.string "Si us plau, vine a veure'm de nou\n"
	.string "per una revenja.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Si pots unir el teu cor amb els dels\n"
	.string "teus POKéMON, hauries de poder\l"
	.string "aconseguir grans coses.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Oh, mare meva.\n"
	.string "Però si ets algú de veritat!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Potser el teu cor s'ha unit\n"
	.string "amb els cors dels teus POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "Tinc el foc dins meu, bonica.\n"
	.string "No ho puc suportar! He de lluitar!$"

MtChimney_Text_MelissaDefeat:
	.string "Uuh, ha estat un combat abrasador!$"

MtChimney_Text_MelissaPostBattle:
	.string "La calor del MT. XEMENEIA m'encalenteix,\n"
	.string "bonica!$"

MtChimney_Text_SheilaIntro:
	.string "Per fi he arribat al MT. XEMENEIA.\n"
	.string "Vull fer lluitar els meus POKéMON!$"

MtChimney_Text_SheilaDefeat:
	.string "La manera com lluites…\n"
	.string "És com una erupció del MT. XEMENEIA!$"

MtChimney_Text_SheilaPostBattle:
	.string "Com he dit, per fi he arribat al\n"
	.string "MT. XEMENEIA. Seria una pena si\l"
	.string "només fes una mica de turisme…\p"
	.string "Vull lluitar una mica i comprar\n"
	.string "GALETES com a records.$"

MtChimney_Text_ShirleyIntro:
	.string "Des que m'he banyat a les termes,\n"
	.string "m'he sentit genial!\l"
	.string "Estic segura que guanyaré!$"

MtChimney_Text_ShirleyDefeat:
	.string "Ai!\n"
	.string "Em refreda fora de l'aigua.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Hauré de fer un altre bany a les\n"
	.string "termes. Vols venir amb mi?\p"
	.string "Era broma!$"

MtChimney_Text_SawyerIntro:
	.string "Quina muntanya tan bonica! Molta gent\n"
	.string "atractiva per fer companyia!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, tu també ets un llamp!$"

MtChimney_Text_SawyerPostBattle:
	.string "Crec que necessito un bany a les\n"
	.string "TERMES DE LAVACALDA amb els locals!$"

MtChimney_Text_SawyerRegister:
	.string "M'agraden els petits llamps com tu.\n"
	.string "Deixa'm registrar-te al POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Estic feliçment envoltat de gent\n"
	.string "atractiva per aquí. No perdré!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Caram, encara ets el mateix\n"
	.string "llamp de sempre!$"

MtChimney_Text_SawyerPostRematch:
	.string "De fet, aquí fa molta calor.\n"
	.string "Vaig massa abrigat per aquí.$"

