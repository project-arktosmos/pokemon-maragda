BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "Ara mateix no s'hi nota, però jo era\n"
	.string "una ENTRENADORA molt dura.\p"
	.string "Tenia fama de ser la BELLESA més\n"
	.string "dura de la zona, t'ho asseguro!\p"
	.string "… … … … … …\p"
	.string "Què passa?\n"
	.string "No em creus.\p"
	.string "No sóc com aquella fanfarrona d'allà.\n"
	.string "Jo realment tinc talent!\p"
	.string "Deixa que t'ho demostri.\n"
	.string "Puc ensenyar als teus POKéMON\l"
	.string "moviments especials i alhora macs.\p"
	.string "Però les meves lliçons no són gratuïtes.\n"
	.string "Què et sembla pagar els moviments\l"
	.string "amb uns quants Punts de Combat?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Has tornat per aprendre moviments\n"
	.string "especials i macs per als POKéMON?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Molt bé, mira aquí!\n"
	.string "Quin moviment t'he d'ensenyar?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "El moviment {STR_VAR_1}, oi?\n"
	.string "Seran {STR_VAR_2} Punts de Combat, d'acord?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Molt bé, ara tria el POKéMON al qual\n"
	.string "he d'ensenyar el moviment.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Què…\n"
	.string "No tens prou Punts de Combat!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Ara ja veus el meva habilitat, oi?\n"
	.string "Em quedo els Punts de Combat, gràcies!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Què?\n"
	.string "No vols…\p"
	.string "Si vols veure la meva habilitat,\n"
	.string "vine a veure'm quan vulguis!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "Sé que ara és difícil de veure, però jo\n"
	.string "era una ENTRENADORA fantàstica.\p"
	.string "Tenia fama de ser la NEDADORA més\n"
	.string "invencible de la zona, t'ho asseguro!\p"
	.string "… … … … … …\p"
	.string "Què passa?\n"
	.string "No em creus.\p"
	.string "No sóc com aquella bufona d'allà.\n"
	.string "Jo realment tinc experiència!\p"
	.string "Deixa que t'ho demostri.\n"
	.string "Puc ensenyar als teus POKéMON\l"
	.string "moviments durs i alhora bonics.\p"
	.string "Però les meves lliçons no són gratuïtes.\n"
	.string "Què et sembla pagar els moviments\l"
	.string "amb uns quants Punts de Combat?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Has vingut per aprendre moviments\n"
	.string "durs i bonics per als POKéMON?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Aquestes senyores, per com parlen\n"
	.string "malament l'una de l'altra, deus pensar\l"
	.string "que no es porten bé.\p"
	.string "Però si fos veritat, no estarien\n"
	.string "aquí juntes, oi?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quan jo era un petit JOVENET,\n"
	.string "aquestes senyores eren fortes i belles.\p"
	.string "Eren ídols entre nosaltres ENTRENADORS.\p"
	.string "Fins i tot ara, l'edat no ha apagat\n"
	.string "les seves habilitats.\p"
	.string "De fet, els seus moviments POKéMON\n"
	.string "s'han perfeccionat encara més.\p"
	.string "Però… Per alguna raó, no puc\n"
	.string "evitar pensar…\p"
	.string "El temps és tan cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Recupera fins a\n"
	.string "la meitat dels PS\n"
	.string "màxims de l'usuari.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Infligeix dany\n"
	.string "idèntic al nivell\n"
	.string "de l'usuari.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Recupera la meitat\n"
	.string "del dany infligit\n"
	.string "a un rival dormint.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un cop de puny\n"
	.string "fort llançat amb\n"
	.string "poder increïble.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Una potada\n"
	.string "extremadament\n"
	.string "poderosa.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Un cop de cos\n"
	.string "que pot causar\n"
	.string "paràlisi.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Llança roques\n"
	.string "grans. Pot fer\n"
	.string "retrocedir.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Torna qualsevol\n"
	.string "cop físic amb\n"
	.string "doble poder.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Una descàrrega\n"
	.string "feble que\n"
	.string "paralitza el rival.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Una dansa de\n"
	.string "combat que puja\n"
	.string "molt l'ATAC.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "S'enrosca per\n"
	.string "amagar punts febles\n"
	.string "i pujar DEFENSA.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Atac sonor que\n"
	.string "només es pot usar\n"
	.string "mentre dorm.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Llança fang a la\n"
	.string "cara del rival per\n"
	.string "reduir precisió.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Dispara raigs\n"
	.string "en forma d'estel\n"
	.string "que mai fallen.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Un atac gelat que\n"
	.string "redueix la VELOCITAT\n"
	.string "del rival.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Aguanta qualsevol\n"
	.string "atac 1 torn,\n"
	.string "deixant 1PS.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copia els efectes\n"
	.string "del rival i els\n"
	.string "dóna a l'usuari.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Un cop de puny\n"
	.string "gelat que pot\n"
	.string "congelar el rival.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Un cop de puny\n"
	.string "elèctric que pot\n"
	.string "paralitzar el rival.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Un cop de puny\n"
	.string "de foc que pot\n"
	.string "cremar el rival.$"
