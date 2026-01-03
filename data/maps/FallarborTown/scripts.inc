FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Està passant alguna cosa,\n"
	.string "i no m'agrada!\p"
	.string "He vist personatges dubtosos entrant\n"
	.string "i sortint de casa del PROF. COSMO…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Aquesta regió ha sigut coneguda pels\n"
	.string "meteors des de temps antics.\p"
	.string "Diuen que la CASCADA METEÒRICA va ser\n"
	.string "excavada per un meteorit fa molt temps.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Mira! Mira això!\n"
	.string "Aquest és el meu preciós AZURILL!\p"
	.string "És suau, llis i molt esponjós!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Ruriluuu.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Ja has desafiat la CANDELA,\n"
	.string "la LÍDER del GIMNÀS DE TERMA?\p"
	.string "L'avi de la noia era famós.\n"
	.string "Va ser un de l'ALT COMANDAMENT a la\l"
	.string "LLIGA POKéMON en un moment.\p"
	.string "No em sorprendria veure la CANDELA\n"
	.string "convertir-se en una gran ENTRENADORA\l"
	.string "pel seu propi mèrit.$"

FallarborTown_Text_BattleTentSign:
	.string "CARPA DE COMBAT SEU DE CENDRAFOC\n"
	.string "“Que es reuneixin els millors equips!”$"

FallarborTown_Text_TownSign:
	.string "POBLE CENDRAFOC\n"
	.string "“Una comunitat agrícola amb petits horts.”$"

FallarborTown_Text_MoveTutorSign:
	.string "CASA DEL TUTOR DE MOVIMENTS\n"
	.string "“S'ensenyen moviments nous als POKéMON.”$"

