Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Sóc el MANÍAC DELS FÒSSILS…\n"
	.string "Sóc un bon noi que li encanten\l"
	.string "els FÒSSILS…\p"
	.string "Vols un FÒSSIL?\p"
	.string "Però tots els FÒSSILS d'aquesta zona\n"
	.string "són meus… Cap per a tu…\p"
	.string "Si no pots viure sense un FÒSSIL,\n"
	.string "busca en un desert on hi hagi roques\l"
	.string "i sorra que puguin amagar FÒSSILS…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Has trobat un FÒSSIL, oi?\n"
	.string "Què bonic… És tan somniador…\p"
	.string "Què faràs amb aquest FÒSSIL?\p"
	.string "Pel que he sentit, DEVON està fent\n"
	.string "recerca sobre reviure POKéMON\l"
	.string "a partir de FÒSSILS…\p"
	.string "Estimo els meus FÒSSILS, així que\n"
	.string "mai faria una cosa així…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Els FÒSSILS són tan… Meravellosos…\n"
	.string "És tan somniador…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "Per allà no és segur…\p"
	.string "Estava excavant, saps…\n"
	.string "Quan tota la paret va caure…\p"
	.string "Crec que hi ha una caverna gegant\n"
	.string "a sota ara…\p"
	.string "Però l'he deixat estar perquè no\n"
	.string "crec que hi hagi FÒSSILS allà…$"

