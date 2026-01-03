LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Ei, com va, {PLAYER}, futur\n"
	.string "CAMPIÓ?\p"
	.string "La LÍDER DE GIMNÀS de LAVACALDA, CANDELA,\n"
	.string "usa POKéMON de tipus FOC.\p"
	.string "La seva passió pels POKéMON crema\n"
	.string "més forta i calenta que un volcà.\p"
	.string "No t'hi acostis massa--et cremaràs!\n"
	.string "Refresca-la amb aigua i després\l"
	.string "endavant!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Uau! Ha estat un combat abrasador!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Ai ai ai ai ai!\n"
	.string "Quina calor!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Tinc els ulls cecs per la suor…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Estar enterrat a la sorra calenta\n"
	.string "promou la circulació.\p"
	.string "És efectiu per alleujar el dolor\n"
	.string "de les articulacions.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Intento alleujar l'estrès.\n"
	.string "No vinguis a estressar-me!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Espero que la CANDELA et cremi bé!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Uf…\p"
	.string "Si passes massa temps enterrat a la\n"
	.string "sorra calenta, et quedes exhaurit…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Ja deus estar cansat.\n"
	.string "T'agradaria descansar a la sorra\l"
	.string "calenta, oi?\p"
	.string "Però has de saber que mantenir\n"
	.string "la força de voluntat és una habilitat\l"
	.string "important per a tots els ENTRENADORS.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Juga amb foc, i et cremaràs…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "La teva habilitat és real…\n"
	.string "Però la nostra LÍDER CANDELA és forta.\p"
	.string "Si no vas amb compte, et cremaràs\n"
	.string "seriosament.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Poden els teus POKéMON suportar\n"
	.string "una calor de 200 graus?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "No ha cremat prou…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La temperatura del magma és de\n"
	.string "200 graus.\p"
	.string "Els teus POKéMON m'han guanyat, així\n"
	.string "que haurien de sobreviure al magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Hm…\n"
	.string "D'acord, combatré amb tu.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, però ets massa fort.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Seré una ENTRENADORA bonica i forta\n"
	.string "com la CANDELA.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Vinga, prepara't!\n"
	.string "Comencem abans que em refredi!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Fa tanta calor, però el meu cor\n"
	.string "és atrapat pel gel…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "La manera com crema l'esperit de\n"
	.string "combat dins teu, potser tens\l"
	.string "opcions contra la nostra LÍDER.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Veus com cremen les flames?\n"
	.string "S'encenen anticipant la meva victòria!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Alguna cosa no ha anat bé.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Bé, i què? Jo dic i què?\n"
	.string "Puc caminar descalç sobre brases!\p"
	.string "…Ni se t'acudeixi provar-ho!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Tant com m'agraden les muntanyes,\n"
	.string "m'agraden especialment els volcans.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Bé, sembla que he perdut sense\n"
	.string "haver tingut mai el control.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Em quedo aquí perquè sóc fan\n"
	.string "del poder de la CANDELA.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Benvingut… No, espera.\p"
	.string "Petit ENTRENADOR, quina alegria\n"
	.string "que hagis arribat fins aquí!\p"
	.string "Se m'ha confiat la…\n"
	.string "No, espera.\p"
	.string "Sóc la CANDELA, i sóc la LÍDER\n"
	.string "del GIMNÀS!\p"
	.string "Mm…\n"
	.string "No gosis subestimar-me, tot i que\l"
	.string "fa poc temps que sóc LÍDER!\p"
	.string "Amb les habilitats heretades del meu\n"
	.string "avi, et… demostro els moviments\l"
	.string "ardents que hem perfeccionat aquí!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Crec que m'estava esforçant massa…\p"
	.string "Jo… fa poc que m'he convertit\n"
	.string "en LÍDER DE GIMNÀS.\p"
	.string "M'esforçava massa per ser algú\n"
	.string "que no sóc.\p"
	.string "He de fer les coses a la meva manera.\n"
	.string "Si no, els meus POKéMON es confondran.\p"
	.string "Gràcies per ensenyar-m'ho.\n"
	.string "Per això, et mereixes això.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} ha rebut la MEDALLA CALOR\n"
	.string "de la CANDELA.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Si tens la MEDALLA CALOR, tots els\n"
	.string "POKéMON fins al Nivell 50, fins i tot\l"
	.string "els que aconsegueixis en intercanvis\l"
	.string "amb altres persones, t'obeiran.\p"
	.string "A més, permet als POKéMON usar el\n"
	.string "moviment MO FORÇA fora de combat.\p"
	.string "Això és una mostra del meu agraïment.\n"
	.string "No tinguis vergonya d'agafar-ho!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "Aquesta MT50 conté SOBREESCALFAR.\p"
	.string "Aquest moviment infligeix un dany\n"
	.string "seriós a l'oponent.\p"
	.string "Però també redueix molt l'AT. ESP.\n"
	.string "del POKéMON que l'utilitza. Pot no\l"
	.string "ser adequat per a combats llargs.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "S'ha registrat la LÍDER CANDELA\n"
	.string "al POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "El teu poder em recorda a algú…\p"
	.string "Oh! Ja ho sé! Lluitres com en NORMAN,\n"
	.string "el LÍDER de CIUTAT PETÀLIA.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "GIMNÀS POKéMON DE LAVACALDA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "GIMNÀS POKéMON DE LAVACALDA\p"
	.string "ENTRENADORS CERTIFICATS PER CANDELA:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "CANDELA: Perdre un combat no em\n"
	.string "desanimarà.\p"
	.string "M'encanten els POKéMON.\n"
	.string "M'encanta lluitar.\l"
	.string "I… m'encanta aquest GIMNÀS!\p"
	.string "Intercanviem moviments superardents\n"
	.string "en un altre combat!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Uf!\n"
	.string "A punt d'entrar en erupció!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "CANDELA: He perdut el combat,\n"
	.string "però estic completament satisfeta.\p"
	.string "No sovint puc gaudir d'un combat\n"
	.string "tan ardent com aquest.\p"
	.string "Fem-ne un altre així\n"
	.string "un altre dia!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "CANDELA: Perdre un combat no em\n"
	.string "desanimarà.\p"
	.string "M'encanten els POKéMON.\n"
	.string "M'encanta lluitar.\l"
	.string "I… m'encanta aquest GIMNÀS!\p"
	.string "Intercanviem moviments superardents\n"
	.string "en un altre combat!\p"
	.string "Oh, espera. Només tens un POKéMON\n"
	.string "que pot lluitar?\p"
	.string "Em sap greu dir-ho, però quan vinguis\n"
	.string "a veure'm, porta almenys dos POKéMON.$"
