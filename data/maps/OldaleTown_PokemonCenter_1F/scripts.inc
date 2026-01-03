OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Aquell PC del racó és perquè\n"
	.string "qualsevol ENTRENADOR POKéMON el faci servir.\p"
	.string "Naturalment, això vol dir que tu també\n"
	.string "el pots usar.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Els CENTRES POKéMON són genials!\p"
	.string "Pots usar els seus serveis tant\n"
	.string "com vulguis, i tot és gratis.\l"
	.string "Mai t'has de preocupar!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "El CLUB SENSE FILS POKéMON al\n"
	.string "segon pis es va construir fa poc.\p"
	.string "Però diuen que encara estan fent\n"
	.string "ajustos.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "El CLUB SENSE FILS POKéMON al\n"
	.string "segon pis es va construir fa poc.\p"
	.string "Vaig intercanviar POKéMON de seguida.$"

