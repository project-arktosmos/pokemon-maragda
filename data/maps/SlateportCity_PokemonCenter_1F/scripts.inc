SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Vols un consell per combatre?\p"
	.string "Jo diria que és criar diferents tipus\n"
	.string "de POKéMON de manera equilibrada.\p"
	.string "No és bo fer només un POKéMON\n"
	.string "fort.\p"
	.string "Si té desavantatge de tipus,\n"
	.string "potser no tindrà cap oportunitat.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Intercanvio POKéMON amb els meus amics.\p"
	.string "Si un POKéMON intercanviat porta un\n"
	.string "objecte, em fa el doble de feliç!$"

