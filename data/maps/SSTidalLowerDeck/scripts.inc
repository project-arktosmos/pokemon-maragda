SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! Estic tip i mort de netejat\n"
	.string "aquest lloc tan gran!\p"
	.string "Fem un combat ràpid!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Germanet, he perdut!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Som els GERMANS DE LA NETEJA!\p"
	.string "El gran tira el detergent,\n"
	.string "i el petit fa el fregall!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Això és el fons del buc del vaixell.\n"
	.string "Hi ha molt d'espai.\l"
	.string "Anirà bé per un combat POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Germà gran, he perdut!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Som els GERMANS DE LA NETEJA!\p"
	.string "El gran tira el detergent,\n"
	.string "i el petit fa el fregall!$"

