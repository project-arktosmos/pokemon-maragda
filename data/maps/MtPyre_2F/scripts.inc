MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Records del meu estimat SKITTY…\n"
	.string "Em ploren els ulls només de pensar-hi.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ai, ai… Hi ha forats al terra\n"
	.string "per tot arreu.\p"
	.string "No me n'he adonat i he caigut\n"
	.string "del pis de dalt.$"

MtPyre_2F_Text_MarkIntro:
	.string "Ei! Estàs buscant POKéMON?\n"
	.string "Has vingut darrere meu! Quin morro!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Aiiiii!\n"
	.string "Ho sento, perdona'm, si us plau!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "La gent no sol venir aquí, així que\n"
	.string "pensava que hi hauria POKéMON rars.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: Som aquí per una aposta.\p"
	.string "Jejej, si li ensenyo com de guai sóc,\n"
	.string "s'enamorarà de mi. Ho sé!\p"
	.string "Ja ho tinc! Et destrossaré i li\n"
	.string "ensenyaré com de guai sóc!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Upa!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: Bé, hem perdut però no passa res!\n"
	.string "Estic aquí al teu costat.\l"
	.string "Superarem aquesta aposta junts!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Si vols enfrontar-te a mi,\n"
	.string "porta més POKéMON.\p"
	.string "Si no, no podré lluir-me davant\n"
	.string "la meva noia!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: He vingut aquí per una aposta\n"
	.string "amb el meu nòvio.\p"
	.string "Fa molta por, però estic amb el\n"
	.string "meu nòvio. Tot bé.\p"
	.string "Ja ho tinc! Faré que el meu nòvio\n"
	.string "quedi bé guanyant-te!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Buaaa! Tinc por!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: Estem enamoradíssims, així que\n"
	.string "no ens importa perdre!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Si vols desafiar-nos, hauries\n"
	.string "de portar almenys dos POKéMON.\p"
	.string "El meu nòvio és fort.\n"
	.string "Un sol POKéMON no serà suficient.$"

MtPyre_2F_Text_LeahIntro:
	.string "Ets una cara desconeguda…\n"
	.string "Marxa abans que et passi res!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Ets resistent.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "La nostra família ha estat ENTRENADORA\n"
	.string "aquí des de la meva besàvia…\p"
	.string "És el meu deure protegir\n"
	.string "aquesta muntanya…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah!\n"
	.string "Estic aterrit!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Nooooooo!\n"
	.string "He perdut els nervis!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "M'espanto cada vegada que veig\n"
	.string "alguna cosa moure's…\p"
	.string "No hauria d'haver vingut a entrenar aquí…$"

