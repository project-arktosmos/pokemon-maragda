CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, així que ets {PLAYER}{KUN}?\n"
	.string "He sentit històries de les teves gestes.\p"
	.string "Em dic WALLACE.\p"
	.string "Abans era el LÍDER DE GIMNÀS de\n"
	.string "CALAGUA, però va sorgir un imprevist.\p"
	.string "Així que ara, he confiat al meu mentor\n"
	.string "JUAN la gestió del GIMNÀS.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON i KYOGRE, els dos POKéMON\n"
	.string "que causen estralls aquí, es consideren\l"
	.string "POKéMON super-antics.\p"
	.string "Però no hi ha només dos POKéMON\n"
	.string "super-antics.\p"
	.string "N'hi ha un més en algun lloc.\p"
	.string "En algun lloc, hi ha un POKéMON\n"
	.string "super-antic anomenat RAYQUAZA.\p"
	.string "Es diu que va ser RAYQUAZA qui va\n"
	.string "calmar els dos combatents en\l"
	.string "el passat llunyà.\p"
	.string "Però ni jo tinc ni idea del parador\n"
	.string "de RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, potser\n"
	.string "saps on és RAYQUAZA ara?\p"
	.string "Si ho saps, si us plau, digues-m'ho.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: La COVA ANCESTRAL?\p"
	.string "Però si és aquí mateix!\n"
	.string "Necessito que ho pensis millor!\p"
	.string "Si us plau, necessito que pensis\n"
	.string "on podria ser RAYQUAZA ara.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: El MT. PÍRA?\p"
	.string "Però quan vaig trobar l'àvia allà\n"
	.string "abans, no va mencionar res d'això.\p"
	.string "Dubto molt que l'àvia intenti\n"
	.string "amagar-me alguna cosa…\p"
	.string "{PLAYER}{KUN}, podries pensar-ho\n"
	.string "amb més cura?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Eh? No te'n recordes?\n"
	.string "Hmm… Això és un problema…\p"
	.string "No pots recordar-ho d'alguna manera?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: El PILAR CELESTE?\p"
	.string "Això és!\n"
	.string "Ha de ser el PILAR CELESTE!\p"
	.string "{PLAYER}{KUN}, no hi ha temps a perdre!\n"
	.string "Anem cap al PILAR CELESTE ara mateix!$"

