DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Què està de moda? Doncs ha de ser\n"
	.string "“{STR_VAR_1}”!\p"
	.string "No m'imagino com seria la vida\n"
	.string "sense “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Què està de moda? Doncs ha de ser\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Però ja me n'estic cansant una mica.\p"
	.string "Hauria de buscar la propera gran cosa.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Estic ensenyant al meu POKéMON sobre\n"
	.string "“{STR_VAR_1},”\l"
	.string "però no va gaire bé.\p"
	.string "Crec que és massa per a ell.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Ara estic estudiant el modern\n"
	.string "“{STR_VAR_1}”.\p"
	.string "És veritat que hi ha una connexió\n"
	.string "profunda entre “{STR_VAR_1}”\l"
	.string "i “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh!\n"
	.string "Així que la meva intuïció era certa!\p"
	.string "Estic un pas més a prop de ser modern\n"
	.string "i estar al dia!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Què?!\n"
	.string "És això cert?!\p"
	.string "No és fàcil per a algú gran com jo\n"
	.string "seguir les tendències!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Tot aquest tema de\n"
	.string "“{STR_VAR_1}”…\l"
	.string "No hi ha un programa de TV sobre això?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "A l'altra banda del mar…\p"
	.string "“{STR_VAR_1}”\n"
	.string "és encara més popular?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Col·lecciono productes oficials\n"
	.string "de “{STR_VAR_1}”\l"
	.string "amb llicència.\p"
	.string "Tinc NINES oficials\n"
	.string "de “{STR_VAR_1}”…\p"
	.string "Roba de marca oficial\n"
	.string "de “{STR_VAR_1}”…\p"
	.string "I llibres il·lustrats\n"
	.string "de “{STR_VAR_1}”\l"
	.string "amb llicència oficial.\p"
	.string "Heheh, és tot meu!\n"
	.string "No compartiré res amb tu!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "IDENTIFICAR BON\n"
	.string "“{STR_VAR_1}” &\l"
	.string "MAL “{STR_VAR_1}”…\p"
	.string "LA CONNEXIÓ ENTRE\n"
	.string "“{STR_VAR_1}” I\l"
	.string "POKéMON…\p"
	.string "“{STR_VAR_1}”\n"
	.string "ÚTIL…\p"
	.string "Està ben ple de llibres sobre\n"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“EL CRIT DE\n"
	.string "{STR_VAR_1}” és el títol.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“EL SOMRIURE DE\n"
	.string "{STR_VAR_1}” és el títol.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Es titula “L'ÚLTIM\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Es titula “EL NAIXEMENT DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "He vist “{STR_VAR_1}”!\n"
	.string "Genial, eh?\p"
	.string "És, com, el més genial que hi ha!\p"
	.string "Era al·lucinant!\n"
	.string "Era l'autèntic, sí senyor!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, no, no, no.\p"
	.string "Aquesta suposada\n"
	.string "“{STR_VAR_1}”\l"
	.string "que dius haver vist, no ho és.\p"
	.string "L'article autèntic és molt més…\n"
	.string "Com ho diria?\l"
	.string "Més agut, però més suau!\p"
	.string "Bé, tant se val. És sorprenent!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ei, escolta, he compost una cançó\n"
	.string "per a “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "és molt popular ara mateix.\p"
	.string "D'acord, escolta!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Meravellós\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Gosaria dir, amic, que et convindrà\n"
	.string "treballar el teu cant abans de\l"
	.string "dedicar-te a\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "De tota manera, com deia abans,\n"
	.string "hauríem de reunir-nos i organitzar\l"
	.string "una festa de “{STR_VAR_1}”\l"
	.string "a l'illa.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, una idea fantàstica!\p"
	.string "Decidirà d'una vegada per totes\n"
	.string "qui és el millor en\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Brillant, de debò!\p"
	.string "A partir d'avui, les nostres vides\n"
	.string "giraran al voltant de “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Estava pensant, però…\p"
	.string "No estaries d'acord que\n"
	.string "“{STR_VAR_1}” ha\l"
	.string "passat de ser alguna cosa de moda a\l"
	.string "ser part de les nostres vides?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Perdona?\n"
	.string "Tant, què?\p"
	.string "Tanmateix, és veritat que\n"
	.string "“{STR_VAR_1}”\l"
	.string "pesa molt al cap, tant si estàs\l"
	.string "despert com adormit.\p"
	.string "Absolutament, tu ets el\n"
	.string "PROFESSOR de\l"
	.string "“{STR_VAR_1}”, amic!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Si tu i jo fem equip,\n"
	.string "serem invencibles en tot el que\l"
	.string "tingui a veure amb “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Exacte, amic meu!\p"
	.string "Serem el DUO de\n"
	.string "“{STR_VAR_1}”!\p"
	.string "No és una imatge fantàstica?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Per a mi, BOMBA LLOT està al cim\n"
	.string "de la popularitat. És el moviment.\p"
	.string "Eh? Em dius que no coneixes\n"
	.string "BOMBA LLOT?\p"
	.string "Això és francament trist.\n"
	.string "Et donaré una.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "M'encanta BOMBA LLOT.\p"
	.string "Però els POKéMON amb el moviment\n"
	.string "“{STR_VAR_1}”\l"
	.string "també estan de moda.$"

