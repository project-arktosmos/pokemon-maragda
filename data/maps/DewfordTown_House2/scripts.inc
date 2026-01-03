DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Mira bé això!\p"
	.string "És una BUFANDA SEDA. Està a l'avantguarda\n"
	.string "de la moda, sí senyor!\p"
	.string "Oh, veig que et brillen els ulls!\n"
	.string "Aprècies el meu estil enlluernador!\p"
	.string "Oh, ets un encant!\n"
	.string "Ves, vull que la tinguis tu!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, no tens lloc?\p"
	.string "Escolta bé, aquesta BUFANDA és\n"
	.string "imprescindible! Jo vendria tots els\l"
	.string "meus objectes per aconseguir-la!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "La BUFANDA SEDA augmenta la potència\n"
	.string "dels moviments de tipus NORMAL.\p"
	.string "És una BUFANDA meravellosa que va\n"
	.string "bé amb gairebé tots els POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Uau, t'has molestat a creuar el mar\n"
	.string "per visitar POBLE OROMAR?\p"
	.string "Potser has vingut perquè has sentit\n"
	.string "parlar de MARCIAL?\p"
	.string "És tan genial…\n"
	.string "Tothom l'idolatra.$"

