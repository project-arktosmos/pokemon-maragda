RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Als meus POKéMON, els hi poso\n"
	.string "malnoms perfectament adequats!\p"
	.string "És la meva expressió de, ehm…\n"
	.string "originalitat, sí, això és!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Però posar el nom PEKACHU a\n"
	.string "un PIKACHU? Sembla inútil.\p"
	.string "Suposo que està bé usar un nom\n"
	.string "fàcil d'entendre, però…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peca!$"

