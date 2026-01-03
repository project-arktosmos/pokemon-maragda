PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Aquest Sistema d'Emmagatzematge\n"
	.string "POKéMON basat en PC…\p"
	.string "Qui el va fer ha de ser una mena\n"
	.string "de mag científic!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Quan el meu POKéMON va menjar una\n"
	.string "BAIA TERAM, va recuperar PS!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Hi ha molts tipus de POKéMON.\p"
	.string "Tots els tipus tenen els seus punts forts\n"
	.string "i febles contra altres tipus.\p"
	.string "Segons els tipus de POKéMON,\n"
	.string "un combat pot ser fàcil o difícil.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Per exemple, el teu TREECKO\n"
	.string "és de tipus PLANTA.\p"
	.string "És fort contra els tipus AIGUA\n"
	.string "i TERRA.\p"
	.string "Però és feble contra POKéMON\n"
	.string "de tipus FOC.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Per exemple, el teu TORCHIC\n"
	.string "és de tipus FOC.\p"
	.string "És fort contra els tipus PLANTA\n"
	.string "i BICHO.\p"
	.string "Però és feble contra POKéMON\n"
	.string "de tipus AIGUA.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Per exemple, el teu MUDKIP\n"
	.string "és de tipus AIGUA.\p"
	.string "És fort contra el tipus FOC.\p"
	.string "Però és feble contra POKéMON de\n"
	.string "tipus PLANTA i ELÈCTRIC.$"

