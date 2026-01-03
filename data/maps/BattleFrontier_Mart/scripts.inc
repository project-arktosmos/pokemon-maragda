BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "Hem vingut a acompanyar el nostre\n"
	.string "nét.\p"
	.string "Però ja que hi som, hem pensat\n"
	.string "que hauríem de comprar algun regal.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Carinyo, què et sembla això?\n"
	.string "No seria un bon regal?\p"
	.string "És…PRO…TE…Ï…NA?\n"
	.string "Sona deliciós, oi?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "Moltes instal·lacions de la FRONTERA\n"
	.string "COMBAT no permeten l'ús d'objectes\l"
	.string "durant els combats.\p"
	.string "Aquesta regla fa les coses encara\n"
	.string "més difícils!$"

