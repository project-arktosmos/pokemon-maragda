PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "La gent deia que van veure un POKéMON\n"
	.string "volant molt alt sobre HOENN.\p"
	.string "Està volant tot el temps?\n"
	.string "No necessita descansar en algun lloc?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Un POKéMON del cel!\n"
	.string "Un POKéMON del cel!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "D'on véns?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Sí?\n"
	.string "POBLE SÍ?\p"
	.string "Mai he sentit parlar d'un lloc així.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "No? Això no té sentit.\n"
	.string "Has de venir d'algun lloc.\p"
	.string "Oh! Espera! No em diràs que vas néixer\n"
	.string "al fons del mar?$"

