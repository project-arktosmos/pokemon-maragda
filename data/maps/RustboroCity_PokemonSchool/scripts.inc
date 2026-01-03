RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "La pissarra llista els canvis d'estat\n"
	.string "que poden afectar els POKéMON en combat.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Quin tema vols llegir?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON està enverinat, perdrà\n"
	.string "PS constantment.\p"
	.string "Els efectes del verí romanen després\n"
	.string "d'un combat.\p"
	.string "Els PS d'un POKéMON enverinat baixaran\n"
	.string "mentre viatja.\p"
	.string "Cura l'enverinament amb un ANTÍDOT.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON queda paralitzat,\n"
	.string "la seva VELOCITAT baixa.\p"
	.string "També pot no poder moure's mentre\n"
	.string "està en combat.\p"
	.string "La paràlisi roman després del combat.\n"
	.string "Cura-la amb un ANTIPARÀLISIS.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON s'adorm, no podrà\n"
	.string "atacar.\p"
	.string "Un POKéMON pot despertar-se sol,\n"
	.string "però si el combat acaba mentre\l"
	.string "dorm, es quedarà adormit.\p"
	.string "Desperta'l amb un DESPERTADOR.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Una cremada redueix el poder d'ATAC,\n"
	.string "i redueix constantment els PS de la víctima.\p"
	.string "Una cremada roman després del combat.\n"
	.string "Cura-la amb un ANTICREMADA.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Si un POKéMON és congelat, queda\n"
	.string "completament indefens.\p"
	.string "Romandrà congelat després del combat.\n"
	.string "Descongela'l amb un ANTIGEL.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Els estudiants que no estudien proven\n"
	.string "una mica de la meva URPA RÀPIDA.\p"
	.string "Si ets o no bon estudiant es veurà\n"
	.string "per com uses aquest objecte.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON que porti l'URPA RÀPIDA\n"
	.string "de vegades accelerarà i es mourà\l"
	.string "abans que el seu oponent.\p"
	.string "Hi ha molts altres objectes pensats\n"
	.string "perquè els portin els POKéMON.\p"
	.string "Només aquests et donaran molts\n"
	.string "temes per estudiar!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Estic intercanviant POKéMON amb\n"
	.string "el meu amic ara mateix.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Sempre havia volgut un SEEDOT,\n"
	.string "i finalment n'estic aconseguint un!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Els POKéMON poden portar objectes,\n"
	.string "però no saben què fer amb objectes\l"
	.string "artificials com POCIÓ i ANTÍDOT.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Saps que alguns moviments POKéMON\n"
	.string "poden confondre un POKéMON?\p"
	.string "Un POKéMON confós de vegades\n"
	.string "s'atacarà a si mateix sense voler.\p"
	.string "Però un cop surt del combat,\n"
	.string "tornarà a la normalitat.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON que porti una BAIA es\n"
	.string "curarà a si mateix…\p"
	.string "Hi ha molts tipus d'objectes que\n"
	.string "els POKéMON poden portar…\p"
	.string "Noi, que difícil és prendre\n"
	.string "apunts…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "És la llibreta d'aquest estudiant…\p"
	.string "Els POKéMON s'han d'atrapar usant\n"
	.string "POKé BALLS.\p"
	.string "Fins a sis POKéMON poden acompanyar\n"
	.string "un ENTRENADOR.\p"
	.string "Un ENTRENADOR és algú que atrapa\n"
	.string "POKéMON, els cria i lluita\l"
	.string "amb ells.\p"
	.string "La missió d'un ENTRENADOR és derrotar\n"
	.string "els ENTRENADORS forts que esperen\l"
	.string "desafiadors als GIMNASOS POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Hola? No ens hem vist abans?\n"
	.string "Crec que a CIUTAT PETÀLIA.\p"
	.string "Deixa'm presentar-me.\n"
	.string "Em dic SCOTT.\p"
	.string "He estat viatjant pertot arreu\n"
	.string "buscant ENTRENADORS destacats.\p"
	.string "Més específicament, busco\n"
	.string "experts en combat POKéMON.\p"
	.string "I tu, què et porta a aquesta ESCOLA?\n"
	.string "També ets ENTRENADOR?\p"
	.string "El primer que hauries de fer és\n"
	.string "fer que un POKéMON aprengui TALLAR.\p"
	.string "Si no recordo malament, algú\n"
	.string "d'aquesta ciutat té TALLAR.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "El nivell de talent dels estudiants\n"
	.string "d'aquí és desconegut. El potencial hi és.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Oh, què és això?\p"
	.string "És una MEDALLA PEDRA, oi?\n"
	.string "Diria que és força impressionant.\p"
	.string "Però, saps, m'hauria agradat veure't\n"
	.string "en combat.\p"
	.string "És difícil saber com ets com a\n"
	.string "ENTRENADOR per una MEDALLA DE LLIGA.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Hola? No ens hem vist abans?\n"
	.string "Crec que a CIUTAT PETÀLIA.\p"
	.string "Deixa'm presentar-me.\n"
	.string "Em dic SCOTT.\p"
	.string "He estat viatjant pertot arreu\n"
	.string "buscant ENTRENADORS destacats.\p"
	.string "Més específicament, busco\n"
	.string "experts en combat POKéMON.\p"
	.string "Oh, què és això?\n"
	.string "És una MEDALLA PEDRA, oi?\p"
	.string "Diria que és força impressionant per\n"
	.string "a un ENTRENADOR principiant com tu.\p"
	.string "Però, saps, m'hauria agradat veure't\n"
	.string "en combat.\p"
	.string "És difícil saber com ets com a\n"
	.string "ENTRENADOR per una MEDALLA DE LLIGA.$"

