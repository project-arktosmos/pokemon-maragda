Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Aquest TÚNEL VERD-FERRI d'aquí…\p"
	.string "Al principi, teníem una gran plantilla\n"
	.string "perforant la roca amb la maquinària\l"
	.string "més moderna. Però vam haver de parar.\p"
	.string "Resulta que hauríem tingut un efecte\n"
	.string "negatiu sobre els POKéMON salvatges\l"
	.string "de la zona.\p"
	.string "Així que no tenim res a fer més que\n"
	.string "estar aquí sense fer res.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Hi ha un home cavant cap a VERDEGAL\n"
	.string "tot sol. Està desesperat per passar.\p"
	.string "Diu que si cava poc a poc sense usar\n"
	.string "màquines, no molestarà els POKéMON,\l"
	.string "i evitarà fer mal al medi ambient.\p"
	.string "Em pregunto si ja haurà passat.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Per arribar a VERDEGAL sense usar\n"
	.string "aquest TÚNEL, hauries de creuar el\l"
	.string "mar fins a PUEBLO, navegar fins a\l"
	.string "PORTLAVANDA, i després passar per\l"
	.string "MALVALONA.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Ho has sentit? El TÚNEL a VERDEGAL\n"
	.string "s'ha obert!\p"
	.string "A vegades, si esperes prou fort,\n"
	.string "els somnis es fan realitat.$"

