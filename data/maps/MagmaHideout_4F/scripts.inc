MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Jo també vull veure GROUDON, però no\n"
	.string "em deixen veure ni la seva cua…\p"
	.string "M'està frustrant molt.\p"
	.string "Oh, no!\n"
	.string "He parlat de GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Suposo que és impossible guanyar si\n"
	.string "un no té la ment tranquil·la…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Em pregunto si GROUDON té cua?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Aviat! Molt aviat!\l"
	.string "El nostre gran objectiu serà assolit!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "Haver arribat tan lluny, i ara això?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MÀXIM, senyor!\n"
	.string "Un intrús va cap a vós!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Encara no has acabat!\n"
	.string "No passaràs fàcilment per aquí!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Ha estat tan fàcil tombar-me?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "V-vinga, una altra revenja…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "Has arribat fins aquí, així que t'ho diré!\p"
	.string "Així és!\n"
	.string "Més endavant, GROUDON està dormint!\p"
	.string "MÀXIM ha anat cap a GROUDON fa només\n"
	.string "uns segons!\p"
	.string "Despertarà molt aviat!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "M'han tombat una altra vegada…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…I mentre perdies el temps amb mi,\n"
	.string "MÀXIM ja haurà despertat GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MÀXIM: GROUDON…\p"
	.string "Res no podia despertar-te del teu\n"
	.string "son banyat en magma…\p"
	.string "Aquest ORB BLAU és el que buscaves.\n"
	.string "No és així?\p"
	.string "T'he portat l'ORB BLAU.\n"
	.string "Que la seva llum et desperti!\p"
	.string "I mostra'm…\n"
	.string "Mostra'm tot l'abast del teu poder!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MÀXIM: GROUDON!\n"
	.string "Què passa?\p"
	.string "No era l'ORB BLAU la clau?\p"
	.string "GROUDON!\n"
	.string "On has anat…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MÀXIM: Oh, eres tu?\p"
	.string "T'he vist ficant els nassos sense\n"
	.string "permís per aquí i per allà…\p"
	.string "Ara ho entenc!\n"
	.string "Has fet alguna jugada bruta!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Què et fa tan hàbil amb els\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MÀXIM: Hi ha d'haver alguna raó\n"
	.string "per la qual GROUDON ha fugit…\p"
	.string "Això és el que intentes dir,\n"
	.string "oi?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "Et penses que no ho sabia?\p"
	.string "Amb GROUDON marxat, ja no hi ha\n"
	.string "cap necessitat d'aquest maleït volcà.\p"
	.string "Aniré a buscar GROUDON, així que\n"
	.string "aquí ens separem!$"
