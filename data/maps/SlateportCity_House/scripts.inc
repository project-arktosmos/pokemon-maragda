SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "El meu POKéMON té una natura MALDESTRE.\p"
	.string "Té més VELOCITAT comparada amb\n"
	.string "els meus altres POKéMON.\p"
	.string "Potser la seva natura té alguna cosa a\n"
	.string "veure amb el creixement d'estadístiques.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Ets ENTRENADOR, oi?\p"
	.string "Ja que has vingut a PORTAINA,\n"
	.string "deus anar a la TENDA COMBAT.$"

