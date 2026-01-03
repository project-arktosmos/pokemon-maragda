MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Vaig aconseguir això del SEBI, però no\n"
	.string "sé per a què serveix.\p"
	.string "Crec que es diu ROCA DEL REI.\n"
	.string "La vols?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Per què la voldries?\n"
	.string "Ets estrany.\p"
	.string "Te la pots quedar, però guarda-ho en\n"
	.string "secret del SEBI.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "La casa del SEBI és just allà!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Sí, tu també ho creus! Què se suposa\n"
	.string "que has de fer amb una roca estranya?$"

MossdeepCity_Text_WailmerWatching:
	.string "Al voltant de MUSGOCEL, pots veure\n"
	.string "WAILMER salvatges.\p"
	.string "Es diu, eh…\n"
	.string "Com era ara…\p"
	.string "WAI, WAI, WAI…\p"
	.string "Avistar WAILMER!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "El CENTRE ESPACIAL de l'illa ha estat\n"
	.string "llançant coets enormes.\p"
	.string "Hi ha hagut una mena d'enrenou\n"
	.string "per una carta que van rebre recentment.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "El CENTRE ESPACIAL de l'illa ha estat\n"
	.string "llançant coets enormes.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "He sentit d'un amic MARINER que l'EQUIP\n"
	.string "AQUA s'ha instal·lat a LLIRINESA.\p"
	.string "També he sentit que algú va arribar\n"
	.string "i els va vèncer completament!\p"
	.string "Però MUSGOCEL ha estat objectiu\n"
	.string "d'aquell EQUIP MAGMA.\p"
	.string "Si vols saber què estan tramant,\n"
	.string "visita el CENTRE ESPACIAL.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Sóc MARINER, així que el mar és\n"
	.string "òbviament més important per a mi.\p"
	.string "Però saps què? Quan torno a terra\n"
	.string "després d'un llarg viatge, sento alleujament!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "No seria bonic?\p"
	.string "Si tot el món estigués cobert de\n"
	.string "plantes i flors com aquesta illa?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Tota vida necessita el mar per viure,\n"
	.string "tot i que fa la seva llar a la terra.\p"
	.string "La vida, havent completat el seu curs,\n"
	.string "es converteix en terra i hi torna.\p"
	.string "I el mar sempre està connectat\n"
	.string "amb la terra.\p"
	.string "Sí, com aquesta mateixa línia de costa.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Un viatge en vaixell està bé.\p"
	.string "Però creuar el mar amb POKéMON\n"
	.string "usant SURF…\p"
	.string "Això sí que és un viatge emocionant!\n"
	.string "No hi estàs d'acord, jove?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Aquesta roca té un significat especial\n"
	.string "per a la gent del CENTRE ESPACIAL.\p"
	.string "La van posar aquí com a desig perquè\n"
	.string "els seus coets volin amb seguretat.\p"
	.string "Quan demanes un desig, què uses?\n"
	.string "Demanes el desig a un estel?\p"
	.string "Jo uso una etiqueta de desig per fer-ho.\n"
	.string "Això és el que faig.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "És una roca blanca.$"

MossdeepCity_Text_GymSign:
	.string "GIMNÀS POKéMON DE CIUTAT MUSGOCEL\n"
	.string "LÍDERS: LISA I TAT\p"
	.string "“La combinació mística!”$"

MossdeepCity_Text_CitySign:
	.string "CIUTAT MUSGOCEL\n"
	.string "“El nostre lema: Estima els POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "CENTRE ESPACIAL DE MUSGOCEL\n"
	.string "“El lloc més a prop de l'espai.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, et sents bé?\n"
	.string "Jo estic genial!\p"
	.string "Havia sentit que el LÍDER DE GIMNÀS\n"
	.string "de MUSGOCEL és bastant fort, així que\l"
	.string "vaig decidir venir a fer-hi un cop d'ull.\p"
	.string "Però hi ha alguna cosa estranya en\n"
	.string "aquesta ciutat.\p"
	.string "La gent parla d'una carta d'avís\n"
	.string "i del CENTRE ESPACIAL…\p"
	.string "No crec que em concerneixi de cap\n"
	.string "manera, però.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… És genial deixar que les onades\n"
	.string "em passin per sobre dels peus…\p"
	.string "Parlant d'onades, coneixes aquella\n"
	.string "ciutat illa ARÍTROPOLIS?\p"
	.string "Crec que el GIMNÀS d'allà té un\n"
	.string "LÍDER nou.\p"
	.string "La gent diu que el nou LÍDER va\n"
	.string "entrenar en PLÀCID.$"

