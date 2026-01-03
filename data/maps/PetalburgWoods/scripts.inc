PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "No n'he trobat cap…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hola, has vist algun POKéMON\n"
	.string "anomenat SHROOMISH per aquí?\p"
	.string "M'encanta aquest POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Anava a tendir-te una emboscada, però\n"
	.string "t'has entretingut al BOSC PETÀLIA\l"
	.string "una eternitat, oi?\p"
	.string "M'he cansat d'esperar, així que aquí estic!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Tu! INVESTIGADOR DE DEVON!\p"
	.string "Dona'm aquests papers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aaaaah!\p"
	.string "Ets un ENTRENADOR POKéMON, oi?\n"
	.string "M'has d'ajudar, si us plau!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Eh? Què et penses que fas?\n"
	.string "Què, el protegiràs?\p"
	.string "Ningú que es creui amb l'EQUIP AQUA\n"
	.string "rep pietat, ni tan sols un nen!\p"
	.string "Vine i lluita contra mi!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "No m'ho puc creure! Ets dur!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Tens molta barra\n"
	.string "ficant-te amb l'EQUIP AQUA!\l"
	.string "Vine i lluita contra mi una altra vegada!\p"
	.string "M'agradaria poder dir-ho, però m'he\n"
	.string "quedat sense POKéMON…\p"
	.string "I, ei, els de l'EQUIP AQUA també\n"
	.string "busquem alguna cosa a FERRORELL.\p"
	.string "Avui et deixaré marxar!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Uf…\n"
	.string "Ha estat molt ajustat!\p"
	.string "Gràcies a tu, no m'ha robat\n"
	.string "aquests papers importants.\p"
	.string "Ja ho sé, et donaré una SUPER BALL\n"
	.string "com a agraïment!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "No ha dit aquell malfactor de\n"
	.string "l'EQUIP AQUA que també buscaven\l"
	.string "alguna cosa a FERRORELL?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh, no! És una crisi!\n"
	.string "No puc perdre el temps!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Vas carregat d'objectes.\n"
	.string "No et puc donar aquesta SUPER BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "He capturat un munt de POKéMON!\p"
	.string "Endavant, endavant, endavant!\n"
	.string "El meu equip de POKéMON INSECTE!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Tinc tots aquests POKéMON,\n"
	.string "però no he pogut guanyar…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "He capturat un munt de POKéMON.\n"
	.string "Ara m'he quedat sense POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Si portes POKéMON INSECTE a l'escola,\n"
	.string "et fas popular a l'instant!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "No puc ser popular si perdo.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Si tens un POKéMON INSECTE gran,\n"
	.string "la gent et respecta per això.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Vull una revenja quan els meus\n"
	.string "POKéMON INSECTE creixin!\p"
	.string "T'estic registrant al meu POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Vull una revenja quan els meus\n"
	.string "POKéMON INSECTE creixin!\p"
	.string "T'estic registrant al meu POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Els meus POKéMON INSECTE han crescut.\n"
	.string "Tornaré a ser popular.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "No puc ser popular si perdo.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Et fas popular si tens POKéMON\n"
	.string "forts, oi?\l"
	.string "Així que he estat entrenant dur.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Ep, tu!\n"
	.string "Els teus POKéMON estan bé?\p"
	.string "Si els teus POKéMON són febles i vols\n"
	.string "evitar combats, hauries d'evitar\l"
	.string "l'herba alta.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "De vegades, hi ha coses a terra\n"
	.string "encara que no les puguis veure.\p"
	.string "Per això sempre miro per on\n"
	.string "camino.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, genial!\n"
	.string "Aquesta és la MEDALLA del GIMNÀS FERRORELL!\p"
	.string "Deus ser un ENTRENADOR.\n"
	.string "Hauries de provar d'usar aquest objecte.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "És una LLAVOR MIRACLE.\n"
	.string "Si un POKéMON porta aquest objecte,\l"
	.string "els moviments de tipus PLANTA es reforcen.\p"
	.string "A part de la LLAVOR MIRACLE, crec que hi ha\n"
	.string "altres objectes útils que els POKéMON\l"
	.string "poden portar.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "CONSELLS D'ENTRENADOR\p"
	.string "Qualsevol POKéMON que aparegui encara\n"
	.string "que sigui una vegada rep Punts EXP.\p"
	.string "Per pujar un POKéMON feble, posa'l a\n"
	.string "l'esquerra de la llista de l'equip.\p"
	.string "Quan comenci el combat, canvia'l.\n"
	.string "Guanyarà Punts EXP sense estar\l"
	.string "exposat a cap perill.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "CONSELLS D'ENTRENADOR\p"
	.string "A més dels Punts de Salut (PS), els\n"
	.string "POKéMON tenen Punts de Poder (PP) que\l"
	.string "s'usen per fer moviments en combat.\p"
	.string "Si un POKéMON es queda sense PP, s'ha\n"
	.string "de portar a un CENTRE POKéMON.$"

