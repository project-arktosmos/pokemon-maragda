FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Ningú em creu, però vaig veure un\n"
	.string "POKéMON gegant al cel.\p"
	.string "Semblava que es retorcia mentre volava\n"
	.string "cap a la RUTA 131.\p"
	.string "Per cert… Sniff…\n"
	.string "Um… Tu, eh…fas olor de cremat.\p"
	.string "Has estat a un volcà o què?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Vull anar al GIMNÀS POKéMON,\n"
	.string "però alguna cosa bloqueja el camí.\p"
	.string "Després de tot l'esforç que vaig fer\n"
	.string "entrenant a la RUTA 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Tinc el meu POKéMON del qual estic\n"
	.string "més orgullós. Aquesta vegada guanyaré l'ALÍCIA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "El terra absorbeix l'aigua de pluja, i\n"
	.string "els arbres creixen bevent aquesta aigua…\p"
	.string "La nostra CIUTAT BOIREBOSCADA existeix\n"
	.string "perquè hi ha aigua i terra.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "La CIUTAT consisteix en cases construïdes\n"
	.string "als arbres.\p"
	.string "Potser per aquest estil de vida,\n"
	.string "tothom està sa i alegre.\p"
	.string "Jo mateix em sento com si hagués\n"
	.string "rejovenit trenta anys.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Viure als arbres està bé.\p"
	.string "Però a vegades els POKéMON de tipus\n"
	.string "BICHO entren per les finestres.\l"
	.string "Pot ser molt sorprenent.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Hi ha POKéMON que evolucionen quan\n"
	.string "els intercanvies! Això m'han dit.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Alguna cosa invisible bloqueja el pas.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Alguna cosa invisible bloqueja el pas.\p"
	.string "Vols usar el VISOR DEVON?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} ha usat el VISOR DEVON.\p"
	.string "Un POKéMON invisible s'ha tornat\n"
	.string "completament visible!\p"
	.string "El POKéMON espantat ha fugit!$"

FortreeCity_Text_CitySign:
	.string "CIUTAT BOIREBOSCADA\n"
	.string "“La ciutat als arbres que juga amb\l"
	.string "la natura.”$"

FortreeCity_Text_GymSign:
	.string "GIMNÀS POKéMON DE CIUTAT BOIREBOSCADA\n"
	.string "LÍDER: ALÍCIA\p"
	.string "“La mestra d'ocells que vola cap\n"
	.string "al món.”$"

