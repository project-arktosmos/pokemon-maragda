DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Ei, com va, {PLAYER},\n"
	.string "futur CAMPIÓ?\p"
	.string "El LÍDER de GIMNÀS d'OROMAR, MARCIAL,\n"
	.string "comanda POKéMON de tipus LLUITA.\p"
	.string "Enfrontar-s'hi amb POKéMON de tipus\n"
	.string "NORMAL és buscar-se problemes.\p"
	.string "Els POKéMON LLUITA destrossaran els\n"
	.string "POKéMON NORMAL, així que ves amb\l"
	.string "compte!\p"
	.string "Pitjor encara, el GIMNÀS és tan fosc\n"
	.string "com el fons de l'oceà.\p"
	.string "Però s'il·luminarà després de derrotar\n"
	.string "els ENTRENADORS del teu camí.\p"
	.string "Ei, endavant, a per ells!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Uau! Ara aquí dins hi ha massa llum!\p"
	.string "El teu futur també és brillant!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "La força és la raó!\n"
	.string "Vine!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "No prou força…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "La teva habilitat ha superat la meva\n"
	.string "força! La teva tècnica és admirable!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "No cal que MARCIAL s'hi fiqui!\p"
	.string "T'aixafaré!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Però… Com?\n"
	.string "Com he pogut perdre tan fàcilment?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "No malbaratàré aquesta derrota.\n"
	.string "La faré servir per motivar-me!\p"
	.string "Algun dia seré LÍDER DE GIMNÀS…\p"
	.string "No, seré el CAMPIÓ de la LLIGA\n"
	.string "POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "No et atreveixis a ignorar-me!\n"
	.string "No serà culpa meva si plores!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Buaaaaaa!\n"
	.string "He perdut!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Combato a la foscor per fer-me\n"
	.string "el cor més fort.\p"
	.string "Però com que és tan fosc, mai puc\n"
	.string "veure la cara de MARCIAL…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Vas fent tombs a la foscor?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, tu…\n"
	.string "No et vull conèixer!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Et mereixes perdre't i acabar\n"
	.string "a l'entrada una altra vegada!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Et mostraré la valentia d'un\n"
	.string "home de mar!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Com ha passat?\n"
	.string "No és propi meu perdre així!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh, sí! Et mereixes veure\n"
	.string "el nostre LÍDER DE GIMNÀS.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Si vols passar, haurà de ser\n"
	.string "a través meu!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "M'has superat de llarg!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Has guanyat!\n"
	.string "A per aquella MEDALLA!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Sóc MARCIAL!\n"
	.string "El LÍDER DE GIMNÀS d'OROMAR!\p"
	.string "M'he forjat a les onades braves\n"
	.string "d'aquestes parts, i m'he fet fort\l"
	.string "a la cova més fosca!\p"
	.string "Així que volies desafiar-me?\n"
	.string "Deixa'm veure de quina pasta estàs!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Uau! Has fet un esquitx molt més\n"
	.string "gran del que esperava!\p"
	.string "M'has enfantat!\p"
	.string "D'acord, m'has guanyat.\n"
	.string "Pren aquesta MEDALLA DE GIMNÀS!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} ha rebut la MEDALLA PUNY\n"
	.string "de MARCIAL.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "La MEDALLA PUNY fa que tots els\n"
	.string "POKéMON fins al Nivell 30, fins i tot\l"
	.string "els d'intercanvi, t'obeixin.\p"
	.string "I podràs usar el moviment MO FLASH\n"
	.string "fora del combat.\p"
	.string "Si vols, fes servir també aquesta\n"
	.string "MÀQUINA TÈCNICA.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Aquesta MT08 conté CORPULÈNCIA.\p"
	.string "És un moviment que augmenta tant\n"
	.string "l'ATAC com la DEFENSA.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "S'ha registrat el LÍDER MARCIAL\n"
	.string "al POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Veig el teu talent convertint-se en una\n"
	.string "onada gegant que causarà una tempesta\l"
	.string "d'asombrament entre ENTRENADORS!$"

DewfordTown_Gym_Text_GymStatue:
	.string "GIMNÀS POKéMON DE POBLE OROMAR$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "GIMNÀS POKéMON DE POBLE OROMAR\p"
	.string "ENTRENADORS CERTIFICATS DE MARCIAL:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "MARCIAL: Una onada pot retrocedir,\n"
	.string "però sempre torna a la riba.\p"
	.string "Una onada gegant de talent com tu…\n"
	.string "Sabia que tornaries!\p"
	.string "Mostra'm com de lluny\n"
	.string "has arribat!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Uau!\n"
	.string "M'has tornat a enfangar!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "MARCIAL: El combat és vast i profund.\n"
	.string "No se'n veu el fons.\l"
	.string "És com el mar de HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "MARCIAL: Una onada pot retrocedir,\n"
	.string "però sempre torna a la riba.\p"
	.string "Una onada gegant de talent com tu…\n"
	.string "Sabia que tornaries!\p"
	.string "Oh? Només tens un POKéMON\n"
	.string "que pot combatre.\p"
	.string "Ho sento, però m'agradaria que\n"
	.string "tornessis amb almenys dos POKéMON.$"
