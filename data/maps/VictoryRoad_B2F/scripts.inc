VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "He entrenat amb tota la meva família,\n"
	.string "tots i cadascun!\l"
	.string "No perdré contra ningú!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Millor que la meva família?!\n"
	.string "Això és possible?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Era millor que tots a la meva\n"
	.string "família. Mai havia perdut…\p"
	.string "He perdut la confiança…\n"
	.string "Potser tornaré a casa…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Havia sentit que hi havia un nen\n"
	.string "dur per aquí. Ets tu?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "El petit és dur!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Segons els rumors que he sentit, el\n"
	.string "nen dur és de PETÀLIA.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Deus estar una mica cansat.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Cap senyal de cansament!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "El CAMÍ DE LA VICTÒRIA i la LLIGA\n"
	.string "POKéMON són desafiaments llargs\l"
	.string "i esgotadors. Vigila la fatiga!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "No et confïis només perquè\n"
	.string "tens moltes MEDALLES DE GIMNÀS.\p"
	.string "Sempre hi haurà algú\n"
	.string "que serà millor que tu!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Ets millor que jo!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Mira les MEDALLES que has col·leccionat\n"
	.string "i recorda els ENTRENADORS que has afrontat.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "He arribat fins aquí, però la tensió\n"
	.string "m'està donant un mal d'estómac horrible…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ai…\n"
	.string "Em fa mal…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "No puc evitar posar-me tens sabent\n"
	.string "que m'apropo a la LLIGA POKéMON.\p"
	.string "És tot el que puc fer per fingir calma.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "L'elit entre l'elit es reuneix en\n"
	.string "aquesta cova.\p"
	.string "Com ho trobes?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Ni una mica nerviós!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Sí que tens valor! M'agrada!\n"
	.string "Continua així!$"

