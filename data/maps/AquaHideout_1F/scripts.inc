AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Què? Què? Què vols de\n"
	.string "l'EQUIP AQUA?\p"
	.string "El nostre CAP no és aquí! Ha anat\n"
	.string "a agafar alguna cosa important!\p"
	.string "… …\n"
	.string "On ha anat?\p"
	.string "Wahaha! De debò creus que et diria\n"
	.string "alguna cosa tan crucial?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Què? Què?\n"
	.string "Ets un recluta de l'EQUIP MAGMA?\p"
	.string "He sentit que l'EQUIP MAGMA intenta\n"
	.string "despertar un POKéMON impressionant al\l"
	.string "seu AMAGATALL.\p"
	.string "Però on deu ser el seu AMAGATALL?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Què? Què? Què vols de\n"
	.string "l'EQUIP AQUA?\p"
	.string "El nostre CAP no és aquí!\n"
	.string "Ha anat a segrestar un submarí!\p"
	.string "… …\n"
	.string "On ha anat?\p"
	.string "Wahaha! De debò creus que et diria\n"
	.string "alguna cosa tan crucial?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Què? Què? Què vols de\n"
	.string "l'EQUIP AQUA?\p"
	.string "El nostre CAP no és aquí! És de camí\n"
	.string "al MT. PÍRA a la RUTA 122!\p"
	.string "… …\n"
	.string "Per què hi ha anat?\p"
	.string "Wahaha! De debò creus que et diria\n"
	.string "alguna cosa tan crucial?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Què? Què?\n"
	.string "Ets un recluta de l'EQUIP MAGMA?\p"
	.string "He sentit que l'EQUIP MAGMA busca\n"
	.string "un POKéMON impressionant al MT. XEMENEIA.\p"
	.string "Però com és aquest POKéMON?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Què? Què? Què vols de\n"
	.string "l'EQUIP AQUA?\p"
	.string "El nostre CAP no és aquí!\n"
	.string "És de camí a CIUTAT PORTLAVANDA!\p"
	.string "… …\n"
	.string "Per què hi ha anat?\p"
	.string "Wahaha! De debò creus que et diria\n"
	.string "alguna cosa tan crucial?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Aiiiii!\n"
	.string "Personatge sospitós detectat!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "He perdut!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "He perdut per l'EQUIP,\n"
	.string "però he fet la meva feina…$"

