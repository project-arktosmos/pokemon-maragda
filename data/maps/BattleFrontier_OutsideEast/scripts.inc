BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Aquesta és la TORRE COMBAT!\n"
	.string "Mantén la ratxa de victòries com\l"
	.string "l'ENTRENADOR més dur!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Aquest és el PALAU COMBAT!\n"
	.string "Mantén els ulls en els combats POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Aquesta és l'ARENA COMBAT!\n"
	.string "Que es reuneixin els equips més durs!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Aquesta és la PIRÀMIDE COMBAT!\n"
	.string "Avança a través de la Cerca de Combat!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "SALA DE CLASSIFICACIÓ DE LA FRONTERA\n"
	.string "Apunta als nous rècords!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "RACÓ D'INTERCANVI DE PUNTS DE COMBAT\n"
	.string "Intercanvia els teus Punts de Combat!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Uau!\n"
	.string "És enorme!\p"
	.string "La TORRE COMBAT sembla especial.\n"
	.string "És diferent de les altres.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "La meva gran ambició és conquerir\n"
	.string "tant la FRONTERA COMBAT com la\l"
	.string "LLIGA POKéMON.\p"
	.string "I si el meu somni es fa realitat…\p"
	.string "Jo… Li preguntaré a la MIMI del costat\n"
	.string "si vol ser amiga meva!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La PIRÀMIDE COMBAT és massa dura!\n"
	.string "No puc arribar al cim!\p"
	.string "Com que no tinc opcions, potser puc\n"
	.string "escalar per fora…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Prospero en la foscor…\n"
	.string "Sí… Què és digne de mi?\l"
	.string "Res més que la PIRÀMIDE COMBAT…\p"
	.string "Què et sembla vagar en la foscor\n"
	.string "i en total i absoluta desesperació?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "No vaig dormir en una setmana, però\n"
	.string "vaig crear l'equip definitiu!\p"
	.string "No em veig perdent, de veritat.\n"
	.string "Assaltarem l'ARENA COMBAT!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "L'SCOTT et va portar aquí també?\n"
	.string "Què passa amb aquest home?\p"
	.string "Sembla que realment sap com detectar\n"
	.string "ENTRENADORS talentosos, però…\p"
	.string "Mai l'he vist combatre en persona.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "Confio en tu, company!\p"
	.string "Faré qualsevol llaminadura que\n"
	.string "t'agradi al meu petit ZIGG si guanyes!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON sembla absent…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "La gent em diu tafaner,\n"
	.string "però no ho puc evitar.\p"
	.string "Tens la gorra torta!\n"
	.string "Oh, no, escombraries a terra!\l"
	.string "Ui, gairebé és hora de sopar!\p"
	.string "No sé si podré només mirar\n"
	.string "al PALAU COMBAT…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Potser no semblo impressionant ara,\n"
	.string "però un cop vaig guanyar un LÍDER\l"
	.string "DE GIMNÀS.\p"
	.string "Qui sap, potser hauria de donar-li\n"
	.string "una altra oportunitat a la glòria.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Sóc ràpida amb la BICI, i això també\n"
	.string "va per la manera com combato.\p"
	.string "Guanyo combats en un tancar i\n"
	.string "obrir d'ulls!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Sóc millor que el meu papa\n"
	.string "als POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Endavant, boniqueta meva!\n"
	.string "Acumula victòries per al papa!\p"
	.string "Ets igual que la teva mare,\n"
	.string "així que dominaràs!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "No va ser fàcil arribar aquí,\n"
	.string "però havia sentit parlar d'una noia\l"
	.string "preciosa a l'ARENA COMBAT.\p"
	.string "En lloc d'ella, saps què\n"
	.string "vaig trobar?\p"
	.string "Una munió de suats, pudents\n"
	.string "i primitius artistes marcials!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "A vegades veig un home gran d'aspecte\n"
	.string "molt important entrant allà.\p"
	.string "Té uns POKéMON increïbles.\n"
	.string "Sembla molt amable, però.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "La coneixes?\n"
	.string "La llegenda de la PIRÀMIDE COMBAT?\p"
	.string "Quan arribi un ENTRENADOR confiat\n"
	.string "que busqui el cim daurat,\l"
	.string "apareixerà un home entre homes.\p"
	.string "No coneixes la llegenda?\n"
	.string "Bé, és clar que no!\l"
	.string "Me l'acabo d'inventar!\p"
	.string "Què se suposa que significa?\n"
	.string "Això, amic meu, no t'ho puc dir!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Home! Oh, home!\n"
	.string "Mai havia perdut abans!\p"
	.string "Però em van escombrar sense cap\n"
	.string "mena de gràcia!\p"
	.string "I després em diuen que no tinc\n"
	.string "talent?! Home!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Aquest noi es va trobar un ENTRENADOR\n"
	.string "terriblement dur mentre estava\l"
	.string "al repte de la TORRE COMBAT.\p"
	.string "Ara mira'l…\p"
	.string "Has de tenir precaució si mai\n"
	.string "decideixes anar a la TORRE COMBAT.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Sí!\n"
	.string "Per fi tinc prou Punts de Combat!\p"
	.string "Suposo que intercanviaré per una altra\n"
	.string "NINA de peluix gegant!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, sí, d'acord!\n"
	.string "Així que aquesta és la SALA DE\l"
	.string "CLASSIFICACIÓ!\p"
	.string "M'agradaria passar a la història com\n"
	.string "un supercampió i tenir el meu nom\l"
	.string "enregistrat aquí per a la posteritat.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Amb tu al meu costat, puc fer el que sigui.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, estimat, ets tan meravellós!\p"
	.string "Ooh, ja no puc esperar més!\p"
	.string "Anem a una SALA DE COMBAT MÚLTIPLE\n"
	.string "ara mateix!\p"
	.string "Si ens ajuntem al SALÓ DE COMBAT,\n"
	.string "el poder del nostre amor superarà\l"
	.string "a tots els que ens trobem.\p"
	.string "Davant nostre, estimat, tot\n"
	.string "caurà com fitxes de dòmino!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "La FRONTERA COMBAT no és exclusivament\n"
	.string "per a ENTRENADORS durs.\p"
	.string "Moltes persones amb habilitats\n"
	.string "especials han estat convidades.\p"
	.string "Aquell home, SCOTT…\p"
	.string "Potser va construir aquest lloc per\n"
	.string "servir un objectiu més gran…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Perdona, jove.\n"
	.string "Tens bona vista?\p"
	.string "Hi ha un arbre estrany més enllà,\n"
	.string "i als meus ulls cansats sembla que\l"
	.string "es mou.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Perdona, jove.\n"
	.string "Tens bona memòria?\p"
	.string "Tinc la sensació que un cop hi havia\n"
	.string "un arbre estrany més enllà.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Jo…\n"
	.string "Ho vaig veure!\p"
	.string "Hi havia una mena de POKéMON enganxós\n"
	.string "amb una cua llarga més endavant!\p"
	.string "S'amagava sota una roca, i\n"
	.string "no parava de mirar-me!$"
