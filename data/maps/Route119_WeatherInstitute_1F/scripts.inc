Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "El CAP s'ha interessat per la recerca\n"
	.string "que fan aquí, així que ens ha enviat.\p"
	.string "Deixa de ficar-te on no et demanen!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Maleït…\n"
	.string "Derrotat per una criatura…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "El nostre CAP ho sap tot.\p"
	.string "Però jo només sóc un RECLUTU. Com puc\n"
	.string "saber què pensa?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Eh?\n"
	.string "Què fa una criatura aquí?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Eh?\n"
	.string "He perdut?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, no…\n"
	.string "Em renyaran per perdre contra un nen…\p"
	.string "Hauria de fer una migdiada al llit…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Mentre dormia, tothom ha pujat\n"
	.string "a dalt!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Uau, ets molt fort!\p"
	.string "M'agradaria ser un ENTRENADOR POKéMON\n"
	.string "com tu!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Al PROFESSOR li encanta la pluja.\n"
	.string "Això és un fet.\p"
	.string "Però si segueix plovent, la gent\n"
	.string "tindrà problemes. Això és un altre fet.\p"
	.string "Per tant, el PROFESSOR estudia\n"
	.string "si es pot treure profit de la pluja.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Al 2n pis de l'INSTITUT, estudiem\n"
	.string "els patrons meteorològics de\l"
	.string "la regió de HOENN.\p"
	.string "Hem notat casos temporals i aïllats\n"
	.string "de sequeres i pluges intenses\l"
	.string "últimament…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Hola!\n"
	.string "Ens has salvat amb les teves accions!\p"
	.string "El que no entenc és què dimonis\n"
	.string "tramaven els AQUA.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Hi ha un llit…\n"
	.string "Descansem una mica.$"

