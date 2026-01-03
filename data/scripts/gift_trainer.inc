MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.\p"
	.string "Si tens aquesta TARGETA PRODIGI,\n"
	.string "pots participar en una enquesta\l"
	.string "a una BOTIGA POKéMON.\p"
	.string "Fes servir les enquestes per convidar\n"
	.string "ENTRENADORS a ARRECIFE.\p"
	.string "…Et donaré una contrasenya\n"
	.string "secreta per a una enquesta:\p"
	.string "“DÓNA'M UN\n"
	.string "ENTRENADOR GENIAL”\p"
	.string "Escriu això en una enquesta i\n"
	.string "envia-la al SISTEMA DE\l"
	.string "COMUNICACIÓ SENSE FILS.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.\p"
	.string "Un ENTRENADOR ha arribat a\n"
	.string "ARRECIFE buscant-te.\p"
	.string "Esperem que gaudeixis combatent\n"
	.string "contra l'ENTRENADOR visitant.\p"
	.string "Pots convidar altres ENTRENADORS\n"
	.string "introduint altres contrasenyes.\p"
	.string "Prova de buscar altres contrasenyes\n"
	.string "que puguin funcionar.$"
