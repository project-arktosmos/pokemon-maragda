AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe…\p"
	.string "Ja has arribat fins aquí?\n"
	.string "T'hem subestimat!\p"
	.string "Però això s'acaba aquí!\p"
	.string "Estic un nivell per sobre dels RECLUTES\n"
	.string "que has vist fins ara.\p"
	.string "No estic fent temps.\n"
	.string "Et faré pols!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe…\n"
	.string "Jo també he perdut…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Mentre jugava amb tu, el nostre CAP\n"
	.string "ha acabat els seus preparatius!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "El nostre CAP ja ha marxat cap a\n"
	.string "una cova sota el mar!\p"
	.string "Si vols perseguir-lo, més val que\n"
	.string "busquis al gran i ample mar més enllà\l"
	.string "de LLIRINESA.\p"
	.string "Però el trobaràs?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, m'he cansat d'esperar!\n"
	.string "Tu també em deus un combat!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Cansat d'esperar…\n"
	.string "Perdut i confús…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "CAP…\n"
	.string "Ja n'hi ha prou?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Panells de teletransport, l'orgull\n"
	.string "de l'AMAGATALL!\p"
	.string "No tens ni idea d'on ets,\n"
	.string "oi?\p"
	.string "Confondre i cansar l'enemic, i després\n"
	.string "rematar-lo! Aquest és el nostre pla!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Què et passa?\n"
	.string "No estàs gens cansat!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Ara que ho penso… no recordo\n"
	.string "on vaig deixar la MASTER BALL.\p"
	.string "Si fallo en vigilar-la, el nostre CAP\n"
	.string "m'escridasserà…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Quan em vaig unir a l'EQUIP AQUA, el\n"
	.string "primer que vaig haver d'aprendre era\l"
	.string "com es connectaven aquests panells.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Estava massa ocupat pensant en\n"
	.string "els panells de teletransport…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Hauré d'aprendre a lluitar\n"
	.string "més eficaçment…$"
