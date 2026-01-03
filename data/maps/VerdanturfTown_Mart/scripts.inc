VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Per a qualsevol combat POKéMON,\n"
	.string "l'ESPECIAL X és crucial.\p"
	.string "Augmenta el poder d'alguns moviments\n"
	.string "tot i que només dura un combat.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Sembla que no venen cap guia\n"
	.string "d'estratègia per a la CARPA DE BATALLA…\p"
	.string "Sembla que un ha de confiar en la seva\n"
	.string "pròpia intel·ligència, al cap i a la fi…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "La BALL NIU funciona millor amb\n"
	.string "POKéMON afeblits.\p"
	.string "VERGÈLIA és l'únic lloc on es pot\n"
	.string "comprar.$"

