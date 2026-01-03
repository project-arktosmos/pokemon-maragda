RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Sóc el SR. STONE, el PRESIDENT de\n"
	.string "la CORPORACIÓ DEVON.\p"
	.string "Acabo de rebre notícies teves!\p"
	.string "Has salvat el nostre personal no una,\n"
	.string "sinó dues vegades!\p"
	.string "Tinc un favor per demanar a una persona\n"
	.string "increïble com tu.\p"
	.string "Tinc entès que estàs lliurant\n"
	.string "un paquet a les DRASSANES de PORTLAVANDA.\p"
	.string "Bé, pel camí, podries parar a\n"
	.string "POBLE OROMAR?\p"
	.string "Esperava que lliuressis una\n"
	.string "CARTA a l'STEVEN a OROMAR.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "SR. STONE: Ara, hauries de saber que\n"
	.string "sóc un gran PRESIDENT.\p"
	.string "Així que mai seria tan mesquí com per\n"
	.string "demanar un favor sense res a canvi.\p"
	.string "Per això vull que tinguis això!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} ha rebut un POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "SR. STONE: Aquell dispositiu…\p"
	.string "És un NAVEGADOR POKéMON, o POKéNAV\n"
	.string "per abreujar.\p"
	.string "És una eina indispensable per a qualsevol\n"
	.string "ENTRENADOR en una aventura.\p"
	.string "Té un mapa de la regió de HOENN.\p"
	.string "Pots comprovar les ubicacions de\n"
	.string "OROMAR i PORTLAVANDA fàcilment!\p"
	.string "Per cert, he sentit que criminals\n"
	.string "sinistres--MAGMA i AQUA, crec--\l"
	.string "han estat causant problemes pertot.\p"
	.string "Crec que seria millor que descansessis\n"
	.string "abans de continuar el teu camí.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "SR. STONE: Bé, doncs, {PLAYER}{KUN},\n"
	.string "ves amb precaució i cura!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "SR. STONE: Compto amb tu!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "SR. STONE: Has lliurat la meva CARTA?\n"
	.string "Moltes gràcies!\p"
	.string "Aquesta és la meva manera d'agrair-t'ho.\n"
	.string "Hauria d'ajudar-te, com a ENTRENADOR.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "SR. STONE: Un POKéMON que porti aquell\n"
	.string "REPARTIR EXP rebrà part dels\l"
	.string "Punts EXP del combat.\p"
	.string "Obtindrà Punts EXP encara que no\n"
	.string "hagi lluitat realment.\p"
	.string "Diria que el REPARTIR EXP és força útil\n"
	.string "per criar POKéMON febles.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "SR. STONE: Des de la meva joventut, m'he\n"
	.string "submergit en la feina.\p"
	.string "En conseqüència, no estic familiaritzat\n"
	.string "amb les tendències i coses així.\p"
	.string "Però tots els joves volen ser\n"
	.string "ENTRENADORS a la LLIGA POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Aquesta és la tercera planta de la\n"
	.string "CORPORACIÓ DEVON.\p"
	.string "El DESPATX del nostre PRESIDENT és\n"
	.string "en aquesta planta.\p"
	.string "De totes maneres, no et puc dir com\n"
	.string "estic d'agraït pel que has fet.\p"
	.string "Um… Per cert, aquell paquet\n"
	.string "que has recuperat per a nosaltres…\p"
	.string "Podries lliurar-lo a\n"
	.string "les DRASSANES de PORTLAVANDA?\p"
	.string "Seria terrible si aquells lladres\n"
	.string "intentessin prendre'l de nou.\p"
	.string "Uh… Hehehe, així que, uh, podria comptar\n"
	.string "amb tu per fer-ho?\p"
	.string "Oh, és veritat.\n"
	.string "Pots esperar aquí un moment?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "El nostre PRESIDENT voldria parlar\n"
	.string "amb tu.\p"
	.string "Sisplau, vine amb mi.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Sisplau, endavant.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Si visites les DRASSANES de PORTLAVANDA,\n"
	.string "hauries d'anar a veure el CAPITÀ STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Els nous productes de DEVON, la BALL\n"
	.string "REPETICIÓ i la BALL TEMPS, s'han fet\l"
	.string "molt populars entre els ENTRENADORS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "És una col·lecció de roques i pedres\n"
	.string "rares reunida pel PRESIDENT.$"

