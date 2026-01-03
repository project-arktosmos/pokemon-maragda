RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Ei, com va?\p"
	.string "Escolta, amic!\n"
	.string "T'agradaria ser el CAMPIÓ?\p"
	.string "Jo no sóc ENTRENADOR, però et puc\n"
	.string "donar consells per guanyar.\p"
	.string "Doncs decidit! Apuntarem al CAMPIONAT\n"
	.string "POKéMON junts!\p"
	.string "La teva feina com a ENTRENADOR és\n"
	.string "col·leccionar MEDALLES DE GIMNÀS, oi?\p"
	.string "Però els LÍDERS DE GIMNÀS no són fàcils!\p"
	.string "I aquí és on entro jo!\n"
	.string "Estic aquí per donar consells experts!\p"
	.string "PETRA, la LÍDER DE GIMNÀS, utilitza\n"
	.string "POKéMON de tipus ROCA.\p"
	.string "El tipus ROCA és molt resistent, però\n"
	.string "no aguanta els moviments de tipus\l"
	.string "AIGUA i PLANTA.\p"
	.string "Vine a veure'm després, si vences\n"
	.string "la LÍDER DE GIMNÀS.\p"
	.string "Bé, endavant!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Uau! Quina victòria impressionant!\n"
	.string "Els meus ànims han funcionat!\p"
	.string "Genial!\n"
	.string "Mira la teva TARGETA D'ENTRENADOR.\p"
	.string "La MEDALLA PEDRA que has aconseguit\n"
	.string "hauria d'estar registrada.\p"
	.string "En altres paraules…\p"
	.string "Has pujat el primer graó de l'escala\n"
	.string "cap al CAMPIONAT!\p"
	.string "Ha de ser una sensació increïble!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "No et prenguis els ENTRENADORS DE\n"
	.string "GIMNÀS a la lleugera! Et mostraré\l"
	.string "per què som millors!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Eres massa bo per a mi…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Encara no has vist res del poder\n"
	.string "terrorífic del tipus ROCA!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Si no em pots vèncer, no tindràs\n"
	.string "cap oportunitat contra la PETRA!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Uau! Tens potencial!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "La PETRA és diverses vegades\n"
	.string "més forta que jo.\p"
	.string "Millor que vagis amb compte!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Potser estem al mig de la ciutat,\n"
	.string "però i què?\p"
	.string "Els meus POKéMON ROCA necessiten\n"
	.string "espai per fer destrosses!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, ostres!\n"
	.string "El nostre aspirant és un client difícil!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "He de reconèixer-ho a la nostra LÍDER.\p"
	.string "Va fer falta intel·ligència i sentit comú\n"
	.string "per triar el tipus ROCA a la seva edat.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hola, sóc la PETRA, la LÍDER DE\n"
	.string "GIMNÀS POKéMON de FERRÍFERA.\p"
	.string "Em vaig fer LÍDER DE GIMNÀS per poder\n"
	.string "aplicar el que vaig aprendre a l'ESCOLA\l"
	.string "D'ENTRENADORS POKéMON en combat.\p"
	.string "Podries demostrar-me com lluites\n"
	.string "i amb quins POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Bé…\n"
	.string "He perdut…\p"
	.string "Sembla que encara tinc molt\n"
	.string "per aprendre…\p"
	.string "Ho entenc.\p"
	.string "Les regles de la LLIGA POKéMON diuen\n"
	.string "que els ENTRENADORS han de rebre això\l"
	.string "si vencen un LÍDER DE GIMNÀS.\p"
	.string "Sisplau, accepta la MEDALLA PEDRA\n"
	.string "oficial de la LLIGA POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} ha rebut la MEDALLA PEDRA\n"
	.string "de la PETRA.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "La MEDALLA PEDRA augmenta el poder\n"
	.string "d'ATAC dels teus POKéMON.\p"
	.string "També els permet usar el moviment MO\n"
	.string "TALLAR fora de combat.\p"
	.string "Sisplau, emporta't això també.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Aquesta MÀQUINA TÈCNICA, MT39,\n"
	.string "conté TOMBA ROCAS.\p"
	.string "No només infligeix dany deixant caure\n"
	.string "roques, també redueix la VELOCITAT.\p"
	.string "Si uses una MT, ensenyarà el moviment\n"
	.string "a un POKéMON al moment.\p"
	.string "Recorda, una MT només es pot usar un cop,\n"
	.string "així que pensa abans d'usar-la.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Com que ets tan fort, hauries de\n"
	.string "desafiar altres LÍDERS DE GIMNÀS.\p"
	.string "Lluitant contra molts ENTRENADORS,\n"
	.string "hauries d'aprendre moltes coses.$"

RustboroCity_Gym_Text_GymStatue:
	.string "GIMNÀS POKéMON CIUTAT FERRÍFERA$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "GIMNÀS POKéMON CIUTAT FERRÍFERA\p"
	.string "ENTRENADORS CERTIFICATS DE PETRA:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "PETRA: Oh, hola, {PLAYER}?\n"
	.string "Sóc la PETRA de CIUTAT FERRÍFERA.\p"
	.string "He sentit pel MARCIAL que estàs\n"
	.string "pujant pels rangs dels ENTRENADORS\l"
	.string "a una velocitat increïble.\p"
	.string "Bé, prefereixo no pensar que\n"
	.string "no et puc vèncer.\p"
	.string "Et prometo que prepararé el meu GIMNÀS\n"
	.string "perquè ens puguis desafiar de nou.\p"
	.string "Espero que esperis aquesta ocasió\n"
	.string "tant com jo!\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "S'ha registrat la LÍDER PETRA\n"
	.string "al POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "PETRA: M'alegro molt de tornar-te a veure.\n"
	.string "Sóc la PETRA, la LÍDER DE GIMNÀS.\p"
	.string "Segur que tots dos hem viscut molts\n"
	.string "combats des que ens vam veure.\p"
	.string "M'agradaria veure quant hem millorat.\n"
	.string "Lluitem!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Un altre cop he perdut…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "PETRA: Encara tinc molt a aprendre\n"
	.string "quan es tracta de lluitar amb POKéMON.\p"
	.string "Aquesta consciència fa que m'agradin\n"
	.string "encara més els combats!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "PETRA: M'alegro molt de tornar-te a veure.\n"
	.string "Sóc la PETRA, la LÍDER DE GIMNÀS.\p"
	.string "Segur que tots dos hem viscut molts\n"
	.string "combats des que ens vam veure.\p"
	.string "M'agradaria veure quant hem\n"
	.string "millorat…\p"
	.string "Oh, no…\n"
	.string "Només tens un POKéMON amb tu?\p"
	.string "Sisplau, torna amb almenys un POKéMON\n"
	.string "més.$"
