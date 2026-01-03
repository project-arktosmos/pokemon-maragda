VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "No et pots considerar un ENTRENADOR\n"
	.string "de veritat si no tens fe en els teus\l"
	.string "POKéMON.\p"
	.string "Només aquells que poden creure\n"
	.string "en els seus POKéMON de combat poden\l"
	.string "guanyar fins al final.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "La raó per la qual qualsevol visitaria\n"
	.string "VERGÈLIA…\p"
	.string "És la CARPA DE BATALLA. Ni cal\n"
	.string "dir-ho.\p"
	.string "O potser hi ha algú aquí que has\n"
	.string "vingut a veure?$"

