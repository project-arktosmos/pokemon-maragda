PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "El mar entre PACÍFIC i PORTLAVANDA\n"
	.string "té una marea molt ràpida.\p"
	.string "Si decideixes usar SURF, podries acabar\n"
	.string "arrossegat a un altre lloc.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Mira, no és genial?\n"
	.string "Aquestes cases estan sobre l'aigua!\p"
	.string "Jo vaig néixer aquí!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "El PILAR CELESTE?\p"
	.string "…Ah, deus voler dir aquella torre\n"
	.string "altíssima una mica més enllà.\p"
	.string "Si em preguntessis, no l'escalaria.\n"
	.string "Em fa massa por pujar tan amunt.\p"
	.string "La vida a nivell del mar a PACÍFIC,\n"
	.string "això m'escau perfectament.$"

PacifidlogTown_Text_TownSign:
	.string "POBLE PACÍFIC\p"
	.string "“On el sol del matí somriu sobre\n"
	.string "les aigües.”$"

