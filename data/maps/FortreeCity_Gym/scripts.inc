FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Ei, com va, {PLAYER} futur\n"
	.string "CAMPIÓ?\p"
	.string "La LÍDER DEL GIMNÀS DE BOIREBOSCADA,\n"
	.string "l'ALÍCIA, és una mestra de POKéMON VOLADORS.\p"
	.string "T'espera al fons d'aquest GIMNÀS,\n"
	.string "darrere de les portes giratòries.\p"
	.string "Espera nous desafiadors\n"
	.string "que volen alçar el vol!\p"
	.string "D'acord, endavant!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Ho has aconseguit!\n"
	.string "Has enlairat el vol!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Contempla l'elegant estil de batalla\n"
	.string "dels POKéMON OCELL!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Tu…\n"
	.string "Ets fort…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Un ENTRENADOR ha de ser intel·ligent per\n"
	.string "seguir el ritme dels girs inesperats.\p"
	.string "Tens la intel·ligència per arribar\n"
	.string "a la nostra LÍDER?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Els amants dels POKéMON OCELL aspiren\n"
	.string "a unir-se a aquest GIMNÀS.\p"
	.string "Com a membre del GIMNÀS DE BOIREBOSCADA,\n"
	.string "no puc perdre!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Ha estat massa per a mi\n"
	.string "suportar-ho…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "El món és enorme, i hi ha\n"
	.string "innombrables ENTRENADORS forts.\p"
	.string "Continuaré entrenant i em faré\n"
	.string "encara més fort.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "No cal que l'ALÍCIA, la nostra LÍDER\n"
	.string "DE GIMNÀS, s'ocupi de tu!\p"
	.string "Jo sóc més que suficient per a tu!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "ALÍCIA, jo…\n"
	.string "He perdut!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "L'ALÍCIA és maca i és forta.\n"
	.string "És la LÍDER definitiva!\p"
	.string "Em poso vermell…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "L'ALÍCIA m'ha ensenyat personalment!\n"
	.string "No em pots guanyar fàcilment!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "M'han guanyat…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Gràcies a l'ALÍCIA, la gent de\n"
	.string "BOIREBOSCADA pot viure sense por.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Quan l'ALÍCIA combat, la seva cara\n"
	.string "brilla amb una determinació bonica…\p"
	.string "No deixaré que vegis aquesta\n"
	.string "vista tan encantadora!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk!\n"
	.string "No t'he pogut aturar.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Més et val vigilar!\n"
	.string "No et distreguis mirant l'ALÍCIA\l"
	.string "o cauràs estrepitosament!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Més et val saber que hi ha tot\n"
	.string "tipus de POKéMON VOLADORS.\p"
	.string "Ho saps, oi?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Sembla que saps del que parles!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Sí, m'has guanyat.\n"
	.string "Però compte! Els POKéMON de la nostra\l"
	.string "LÍDER ALÍCIA van de debò.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Sóc l'ALÍCIA. Sóc la LÍDER del\n"
	.string "GIMNÀS POKéMON DE BOIREBOSCADA.\p"
	.string "M'he convertit en una amb els POKéMON\n"
	.string "OCELL i he volat pels cels…\p"
	.string "Per molt dura que sigui la batalla,\n"
	.string "hem triomfat amb gràcia…\p"
	.string "Contempla l'elegant coreografia\n"
	.string "dels POKéMON OCELL i jo!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Mai abans havia vist un ENTRENADOR\n"
	.string "comandar POKéMON amb més gràcia\l"
	.string "que jo…\p"
	.string "En reconeixement de la teva destresa,\n"
	.string "et presento aquesta MEDALLA DE GIMNÀS.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} ha rebut la MEDALLA PLOMA\n"
	.string "de l'ALÍCIA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Amb la MEDALLA PLOMA, tots els POKéMON\n"
	.string "fins a NV 70, fins i tot els rebuts\l"
	.string "per intercanvi, t'obeiran.\p"
	.string "També podràs usar el moviment MO\n"
	.string "VOLAR fora del combat.\p"
	.string "I això…\n"
	.string "Això és un regal de part meva.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "El MT40 conté AS AERI.\p"
	.string "La seva velocitat…\n"
	.string "Cap POKéMON hauria de poder evitar-lo.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Has registrat la LÍDER DE GIMNÀS ALÍCIA\n"
	.string "al POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Tot i que he caigut davant teu, seguiré\n"
	.string "dedicada als POKéMON OCELL.$"

FortreeCity_Gym_Text_GymStatue:
	.string "GIMNÀS POKéMON DE CIUTAT BOIREBOSCADA$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "GIMNÀS POKéMON DE CIUTAT BOIREBOSCADA\p"
	.string "ENTRENADORS CERTIFICATS PER L'ALÍCIA:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "ALÍCIA: Els humans mai podem escapar\n"
	.string "de l'atracció de la gravetat.\p"
	.string "Però esforçant-nos per l'excel·lència,\n"
	.string "tenim el poder de volar!\p"
	.string "Has escalat el cim com a\n"
	.string "CAMPIÓ regnant.\p"
	.string "Si us plau, deixa'm veure el teu poder\n"
	.string "a ple vol!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "No he pogut arribar a la teva alçada…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "ALÍCIA: Tot i que he perdut,\n"
	.string "les ales del meu cor romanen intactes.\p"
	.string "Puc aixecar-me i volar de nou\n"
	.string "una i altra vegada.\p"
	.string "N'estic convençuda!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "ALÍCIA: Els humans mai podem escapar\n"
	.string "de l'atracció de la gravetat.\p"
	.string "Però esforçant-nos per l'excel·lència,\n"
	.string "tenim el poder de volar!\p"
	.string "Has escalat el cim com a\n"
	.string "CAMPIÓ regnant.\p"
	.string "Si us plau, deixa'm veure el teu poder\n"
	.string "a ple vol!\p"
	.string "Oh, no… Només tens un\n"
	.string "POKéMON amb tu?\p"
	.string "Si us plau, torna amb dos POKéMON\n"
	.string "com a mínim.$"
