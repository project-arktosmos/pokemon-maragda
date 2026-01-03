MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "No! Aquells babaus de l'EQUIP MAGMA\n"
	.string "han arribat abans que nosaltres!\p"
	.string "No podem quedar-nos enrere!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Pensava que eres un dels MAGMA\n"
	.string "que havia tornat per casualitat…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Sí, ja veig que ets fort…\n"
	.string "Però som molts!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Ha!\n"
	.string "Quina mala sort la teva!\p"
	.string "Si haguessis vingut abans, només\n"
	.string "hauries hagut de lluitar contra\l"
	.string "el fluixet EQUIP MAGMA.\p"
	.string "Però com que has arribat ara, has\n"
	.string "d'enfrontar-te als durs!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… Hauria d'haver deixat que\n"
	.string "primer lluités contra l'EQUIP MAGMA…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "No saps res de res!\n"
	.string "Per què et fiques amb nosaltres?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Tu…\n"
	.string "Et vam veure al MT. XEMENEIA.\p"
	.string "No pertanys a cap EQUIP,\n"
	.string "així que per què ets aquí?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Si t'has de ficar amb algú,\n"
	.string "que sigui amb l'EQUIP MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, no importa!\n"
	.string "Hem guanyat temps!\p"
	.string "El CAP ja haurà aconseguit\n"
	.string "el que buscava!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, ja ho sé!\n"
	.string "Vas intentar unir-te a l'EQUIP MAGMA,\l"
	.string "però no et van voler!\p"
	.string "Bé, no creguis que et deixarem\n"
	.string "unir-te al nostre EQUIP AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Si vols unir-te a l'EQUIP AQUA tant,\n"
	.string "podem considerar-ho…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Tenim una gran combinació entre\n"
	.string "nosaltres els membres i el nostre líder.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIBALD: El MAXIMÍ de l'EQUIP MAGMA\n"
	.string "se'ns ha avançat, però també hem\l"
	.string "aconseguit el que volíem.\p"
	.string "L'ORB VERMELL conservat al MT. PÍRA…\n"
	.string "Jo, ARCHIBALD, ara el tinc en possessió!\p"
	.string "Fufufu… Ara podem portar el nostre\n"
	.string "objectiu final a bon port!\p"
	.string "D'acord, EQUIP!\n"
	.string "Ens retirem!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, no…\n"
	.string "Això no pot passar…\p"
	.string "No només l'ORB BLAU, sinó fins i tot\n"
	.string "l'ORB VERMELL han estat presos…\p"
	.string "L'ORB BLAU i l'ORB VERMELL mai s'haurien\n"
	.string "de separar. Han d'estar junts.\p"
	.string "Què intenten fer aquells homes amb\n"
	.string "els dos ORBS?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, sí. Va ser l'EQUIP MAGMA qui va\n"
	.string "venir i es va endur l'ORB BLAU primer?\p"
	.string "Bé, amb les presses, van deixar\n"
	.string "això enrere.\p"
	.string "No podia imaginar què podia ser\n"
	.string "exactament.\p"
	.string "M'agradaria que ho tinguessis.\n"
	.string "Potser serà útil d'alguna manera.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "L'ORB BLAU i l'ORB VERMELL presos\n"
	.string "per aquells homes sinistres…\p"
	.string "Mai han d'estar separats…\n"
	.string "Temo que passarà alguna cosa terrible…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, Déu meu…\p"
	.string "Dius que tant GROUDON com KYOGRE\n"
	.string "han despertat?\p"
	.string "Es diu que l'ORB BLAU i l'ORB VERMELL\n"
	.string "van calmar la ira dels\l"
	.string "dos POKéMON…\p"
	.string "També es diu que el veritable\n"
	.string "propietari dels ORBS encara existeix.\p"
	.string "Tanmateix, ningú sap qui, o què\n"
	.string "exactament, posseeix els ORBS.\p"
	.string "Podria ser un humà, o potser\n"
	.string "un POKéMON, però ningú ho sap.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Els dos homes que es van endur els ORBS\n"
	.string "van tornar a retornar-los pel seu compte.\p"
	.string "Aquells homes…\n"
	.string "Potser no són tan malvats després de tot…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Les encarnacions de la terra, el mar\n"
	.string "i el cel…\p"
	.string "Es diu que aquestes són les identitats\n"
	.string "dels POKéMON super-antics…\p"
	.string "De la mateixa manera que els humans i\n"
	.string "els POKéMON tenim vida, el nostre món\l"
	.string "també és viu…\p"
	.string "Els POKéMON super-antics ens han\n"
	.string "ensenyat això…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "El MT. PÍRA és on calmem els esperits\n"
	.string "dels POKéMON que han traspassat…\p"
	.string "Aquest és un lloc elevat des d'on\n"
	.string "es pot veure tot HOENN…\p"
	.string "Els esperits incorpòris dels POKéMON\n"
	.string "han de trobar consol aquí…\p"
	.string "És coincidència que siguis aquí…\p"
	.string "Vols escoltar la meva història? Una\n"
	.string "història contada a la regió de HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Va passar fa molt, molt de temps…\p"
	.string "El món es va veure sacsejat per un\n"
	.string "ferotge xoc entre el POKéMON de la\l"
	.string "terra i el POKéMON del mar…\p"
	.string "El POKéMON de la terra va aixecar\n"
	.string "muntanyes i va crear continents…\p"
	.string "El POKéMON del mar va aixecar ones\n"
	.string "gegants i va esculpir oceans…\p"
	.string "El seu ferotge duel va continuar\n"
	.string "sense fi.\p"
	.string "El món es va veure engolat per\n"
	.string "inferns massius i tempestes vicioses.\p"
	.string "L'ORB BLAU i l'ORB VERMELL van posar\n"
	.string "fi a la calamitat.\p"
	.string "La llum va brollar dels dos ORBS i\n"
	.string "va calmar els adversaris enfurismats.\p"
	.string "La parella, tornada dòcil, es va enfonsar\n"
	.string "profundament al mar on finalment van\l"
	.string "desaparèixer…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Entenc…\n"
	.string "Bé, això també està bé…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIMÍ: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "La meva funció és transmetre les\n"
	.string "llegendes de HOENN a futures generacions.\p"
	.string "I la crisi que acaba d'acabar a\n"
	.string "CALAGUA va reescriure una llegenda…\p"
	.string "Tens temps per escoltar la nova\n"
	.string "llegenda de HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Va passar fa molt, molt de temps…\p"
	.string "El món es va veure sacsejat per un\n"
	.string "ferotge xoc entre el POKéMON de la\l"
	.string "terra i el POKéMON del mar…\p"
	.string "El POKéMON de la terra va aixecar\n"
	.string "muntanyes i va crear continents…\p"
	.string "El POKéMON del mar va aixecar ones\n"
	.string "gegants i va esculpir oceans…\p"
	.string "El seu ferotge duel va continuar\n"
	.string "sense fi.\p"
	.string "El món es va veure engolat per\n"
	.string "focs massius i tempestes vicioses.\p"
	.string "Va ser llavors quan el POKéMON del\n"
	.string "cel va descendir d'una tempesta.\p"
	.string "El POKéMON, brillant d'un verd viu,\n"
	.string "va calmar els dos POKéMON enfurismats.\p"
	.string "Després, amb el seu deure complert,\n"
	.string "el POKéMON verd va volar cap a\l"
	.string "l'immens cel blau…$"

