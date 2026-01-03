FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Escolta, nen, estàs treballant\n"
	.string "en una POKéDEX?\p"
	.string "Hmm… Vés al ZONA SAFARI.\n"
	.string "Aquesta és la meva suggerència.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Has fet alguna cosa al RACÓ\n"
	.string "DE REGISTRES?\p"
	.string "És força interessant. Barreja i\n"
	.string "combina els registres dels ENTRENADORS.\p"
	.string "No sé ben bé com funciona, però\n"
	.string "mola. Fins i tot és emocionant!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, uau, tens un POKéNAV!\n"
	.string "I és just com el meu!\p"
	.string "Saps del sistema de TRUCADA\n"
	.string "del POKéNAV?\p"
	.string "Accedeix-hi, i pots xatejar amb\n"
	.string "ENTRENADORS registrats en qualsevol\l"
	.string "moment.\p"
	.string "També et mostra quins ENTRENADORS\n"
	.string "volen una revenja amb tu.\p"
	.string "És molt pràctic! Aquests nois de DEVON\n"
	.string "segur que saben el que fan!$"

