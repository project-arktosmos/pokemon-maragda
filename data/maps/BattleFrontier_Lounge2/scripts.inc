BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Hola! Quan es tracta de notícies sobre\n"
	.string "la FRONTERA COMBAT, sóc el número 1.\p"
	.string "Pots pensar en mi com\n"
	.string "el MANIAC DE LA FRONTERA.\p"
	.string "Només comprovo, però ets un ENTRENADOR,\n"
	.string "oi?\p"
	.string "Compartiré amb gust les notícies més\n"
	.string "fresques que he recopilat de la FRONTERA.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Hola! Has vingut per saber les últimes\n"
	.string "notícies? D'acord!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "I bé? I bé? I bé?\p"
	.string "Segur que la meva informació t'ha\n"
	.string "estat molt útil, oi?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "A veure…\p"
	.string "Sembla que la {STR_VAR_1}\n"
	.string "és el lloc més calent ara mateix.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "A veure…\p"
	.string "Sembla que la TORRE COMBAT\n"
	.string "{STR_VAR_1} és el més calent.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels millors ENTRENADORS que SCOTT\n"
	.string "anomena CERVELLS DE LA FRONTERA hi és.\p"
	.string "És una ENTRENADORA misteriosa anomenada\n"
	.string "la DAMA DEL SALÓ que dirigeix el lloc.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Has combatut amb la DAMA DEL SALÓ?\p"
	.string "Quan mesura el seu oponent,\n"
	.string "aparentment usa aquests POKéMON:\p"
	.string "Un POKéMON PSI de tipus PSÍQUIC,\n"
	.string "un POKéMON VOLCÀ de tipus FOC,\l"
	.string "i un POKéMON DORMILEGA de tipus NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Has combatut amb la DAMA DEL SALÓ\n"
	.string "quan va de seriós?\p"
	.string "Quan combat a fons,\n"
	.string "aparentment usa aquests POKéMON:\p"
	.string "Un POKéMON EON de tipus DRAC & PSÍQUIC,\n"
	.string "un POKéMON TRON de tipus ELÈCTRIC,\l"
	.string "i un POKéMON DORMILEGA de tipus NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels millors ENTRENADORS que SCOTT\n"
	.string "anomena CERVELLS DE LA FRONTERA hi és.\p"
	.string "És un ENTRENADOR flamenc anomenat\n"
	.string "l'AS DE LA CÚPULA que dirigeix el lloc.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Has combatut amb l'AS DE LA CÚPULA?\p"
	.string "Quan tracta l'oponent a la lleugera,\n"
	.string "usa aquests tres POKéMON:\p"
	.string "Un POKéMON DRAC de tipus DRAC & VOLADOR,\n"
	.string "un POKéMON PEIX FANG de tipus AIGUA & TERRA,\l"
	.string "i un POKéMON FLAMA de tipus FOC & VOLADOR.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Has combatut amb l'AS DE LA CÚPULA\n"
	.string "quan va de seriós?\p"
	.string "Quan demostra la seva estratègia,\n"
	.string "usa aquests tres POKéMON:\p"
	.string "Un POKéMON EON de tipus DRAC & VOLADOR,\n"
	.string "un POKéMON PEIX FANG de tipus AIGUA & TERRA,\l"
	.string "i un POKéMON CAMES FERRO de tipus ACER\l"
	.string "& PSÍQUIC.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels millors ENTRENADORS que SCOTT\n"
	.string "anomena CERVELLS DE LA FRONTERA hi és.\p"
	.string "És un ENTRENADOR estrany anomenat\n"
	.string "el CAP DE LA FÀBRICA que dirigeix el lloc.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Has combatut amb el CAP DE LA FÀBRICA\n"
	.string "ja?\p"
	.string "Deixa'm pensar… Quan va a combatre,\n"
	.string "simplement agafa tres POKéMON de lloguer.\p"
	.string "Combat pràcticament amb les mateixes\n"
	.string "condicions que tu.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Has combatut amb el CAP DE LA FÀBRICA\n"
	.string "quan va de seriós?\p"
	.string "Quan combat seriosament,\n"
	.string "encara agafa tres POKéMON de lloguer.\p"
	.string "Combat virtualment amb les mateixes\n"
	.string "condicions que tu.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels millors ENTRENADORS que SCOTT\n"
	.string "anomena CERVELLS DE LA FRONTERA hi és.\p"
	.string "És una ENTRENADORA que fa por anomenada\n"
	.string "la REINA DEL LLAC que dirigeix el lloc.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Has combatut amb la REINA DEL LLAC\n"
	.string "abans?\p"
	.string "Quan està de bon humor, diuen que\n"
	.string "usa aquests tres POKéMON:\p"
	.string "Un POKéMON SERP ULLAL de tipus VERÍ,\n"
	.string "un POKéMON MOTLLE de tipus INSECTE & ROCA,\l"
	.string "i un POKéMON TENDRE de tipus AIGUA.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Has combatut amb la REINA DEL LLAC\n"
	.string "quan va de seriós?\p"
	.string "Quan està molt molesta, diuen que\n"
	.string "usa aquests tres POKéMON:\p"
	.string "Un POKéMON SERP ULLAL de tipus VERÍ,\n"
	.string "un POKéMON SERP FERRO de tipus ACER & TERRA,\l"
	.string "i un POKéMON ATROÇ de tipus AIGUA\l"
	.string "& VOLADOR.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels millors ENTRENADORS que SCOTT\n"
	.string "anomena CERVELLS DE LA FRONTERA hi és.\p"
	.string "És una ENTRENADORA maca anomenada\n"
	.string "la MAGNATA DE L'ARENA que dirigeix el lloc.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Has combatut amb la MAGNATA DE L'ARENA\n"
	.string "abans?\p"
	.string "Quan avalua l'habilitat del rival,\n"
	.string "suposadament usa aquests POKéMON:\p"
	.string "Un POKéMON BANYA de tipus INSECTE & LLUITA,\n"
	.string "un POKéMON LLUM LUNAR de tipus FOSC,\l"
	.string "i un POKéMON MUDA de tipus INSECTE & FANTASMA.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Has combatut amb la MAGNATA DE L'ARENA\n"
	.string "quan va de seriós?\p"
	.string "Quan combat de debò,\n"
	.string "suposadament usa aquests POKéMON:\p"
	.string "Un POKéMON LLUM LUNAR de tipus FOSC,\n"
	.string "un POKéMON OMBRA de tipus FANTASMA & VERÍ\l"
	.string "i un POKéMON BOLET de tipus PLANTA\l"
	.string "& LLUITA.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels millors ENTRENADORS que SCOTT\n"
	.string "anomena CERVELLS DE LA FRONTERA hi és.\p"
	.string "És un ENTRENADOR sinistre anomenat\n"
	.string "el MESTRE DEL PALAU que dirigeix el lloc.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Has combatut amb el MESTRE DEL PALAU\n"
	.string "abans?\p"
	.string "Quan posa a prova l'esperit de l'oponent,\n"
	.string "diuen que usa aquests POKéMON:\p"
	.string "Un POKéMON RAT PENAT de tipus VERÍ & VOLADOR,\n"
	.string "un POKéMON GANDUL de tipus NORMAL, i un\l"
	.string "POKéMON TRANSPORT de tipus AIGUA & GEL.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Has combatut amb el MESTRE DEL PALAU\n"
	.string "quan va de seriós?\p"
	.string "Quan posa tota la seva força en el\n"
	.string "combat, diuen que usa aquests POKéMON:\p"
	.string "Un POKéMON LLEGENDARI de tipus FOC,\n"
	.string "un POKéMON GANDUL de tipus NORMAL,\l"
	.string "i un POKéMON AURORA de tipus AIGUA.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels millors ENTRENADORS que SCOTT\n"
	.string "anomena CERVELLS DE LA FRONTERA hi és.\p"
	.string "És un ENTRENADOR ardent anomenat\n"
	.string "el REI DE LA PIRÀMIDE que dirigeix el lloc.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Has combatut amb el REI DE LA PIRÀMIDE\n"
	.string "abans?\p"
	.string "Quan comprova el poder del rival,\n"
	.string "aparentment usa aquests POKéMON:\p"
	.string "Un POKéMON CIM ROCA de tipus ROCA,\n"
	.string "un POKéMON ICEBERG de tipus GEL,\l"
	.string "i un POKéMON FERRO de tipus ACER.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Has combatut amb el REI DE LA PIRÀMIDE\n"
	.string "quan va de seriós?\p"
	.string "Quan està carregat de poder ardent,\n"
	.string "aparentment usa aquests POKéMON:\p"
	.string "Un POKéMON CONGELACIÓ de tipus GEL & VOLADOR,\n"
	.string "un POKéMON ELÈCTRIC de tipus ELÈCTRIC & VOLADOR,\l"
	.string "i un POKéMON FLAMA de tipus FOC\l"
	.string "& VOLADOR.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Clar, hi ha diversos llocs on pots\n"
	.string "entrar en COMBATS DOBLES.\p"
	.string "Però les SALES DE COMBAT DOBLE de\n"
	.string "la TORRE COMBAT són, bàsicament, bàsiques!\p"
	.string "És on hauries d'aprendre com es juguen\n"
	.string "els COMBATS DOBLES aquí a la\l"
	.string "FRONTERA COMBAT.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Vigila en els combats d'aquí.\p"
	.string "He sentit que hi ha ENTRENADORS que tenen\n"
	.string "estratègies desenvolupades només per\l"
	.string "COMBATS DOBLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Un cop et sentis segur i còmode\n"
	.string "amb els COMBATS DOBLES aquí, hauries\l"
	.string "de pensar a desafiar altres llocs\l"
	.string "que ofereixen COMBATS DOBLES.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Tot tipus d'ENTRENADORS es reuneixen\n"
	.string "al SALÓ COMBAT.\p"
	.string "Pensa-hi: pots trobar-te amb els teus\n"
	.string "amics o seguidors!\l"
	.string "Hauries de mirar amb atenció!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Si ets amb un amic, ves a la\n"
	.string "SALA DE COMBAT MULTI LINK.\p"
	.string "Si jugues amb un amic fort,\n"
	.string "pots esperar veure rivals durs!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Quin poder de recollir notícies!\n"
	.string "El meu mentor no s'assembla a ningú!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Quins poders d'observació més increïbles!\n"
	.string "El meu mentor no s'assembla a ningú!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Quin poder de persuasió més increïble!\n"
	.string "El meu mentor no s'assembla a ningú!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Què és aquest lloc?\n"
	.string "Em fa por…$"

