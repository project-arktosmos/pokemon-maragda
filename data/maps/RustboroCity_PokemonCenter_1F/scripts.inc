RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "El meu POKéMON té una natura INGÈNUA,\n"
	.string "i el del meu amic té una natura ALEGRE.\p"
	.string "És fascinant com els POKéMON tenen\n"
	.string "personalitats!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Igual que les persones, hi ha POKéMON\n"
	.string "mascles i femelles.\p"
	.string "Però ningú sembla tenir cap idea de\n"
	.string "com són diferents.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "L'home del costat m'ha donat una MO!\p"
	.string "L'he usat per ensenyar al meu POKéMON\n"
	.string "a TALLAR arbres prims.$"

