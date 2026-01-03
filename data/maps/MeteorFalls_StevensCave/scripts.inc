MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, vaja, {PLAYER}{KUN}.\n"
	.string "M'impressiona que sabessis on trobar-me.\p"
	.string "Potser… em veus només com un\n"
	.string "maníac de les pedres?\p"
	.string "No, això no pot ser.\p"
	.string "Vam lluitar junts al CENTRE ESPACIAL\n"
	.string "de CALAGUA.\p"
	.string "Hauries de tenir una molt bona idea\n"
	.string "de com de bo sóc.\p"
	.string "D'acord, {PLAYER}{KUN}, si vols muntar un\n"
	.string "desafiament seriós, prepara't pel pitjor!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Tu…\n"
	.string "No tenia ni idea que et faries tan fort…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Pensant-ho bé, des que els\n"
	.string "nostres camins es van creuar a la\l"
	.string "COVA GRANIT de PUEBLO, vaig tenir\l"
	.string "aquest pressentiment.\p"
	.string "Pensava que acabaries convertint-te\n"
	.string "en el CAMPIÓ.\p"
	.string "Les meves prediccions normalment\n"
	.string "es compleixen.\p"
	.string "I on aniràs a partir d'ara?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, ni jo podria dir-t'ho.$"

