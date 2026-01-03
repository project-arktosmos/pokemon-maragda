SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Coneixes el POKéMON SEEDOT?\n"
	.string "Gairebé mai es veu a ALGÈPOLIS.\p"
	.string "De tota manera, m'encanten els SEEDOT grans.\n"
	.string "Com més grans millor.\p"
	.string "Però el meu germà petit diu que\n"
	.string "LOTAD és més gran.\p"
	.string "Quina bobobada.\n"
	.string "SEEDOT ha de ser més gran que això!\p"
	.string "Eh? Tens un SEEDOT amb tu?\n"
	.string "S-si us plau, ensenya-me'l!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} polzades!\n"
	.string "Oh, mare meva, és enorme!\p"
	.string "Podria fins i tot superar el LOTAD gran\n"
	.string "que va veure el meu germà petit!\p"
	.string "Gràcies per ensenyar-me'l.\n"
	.string "Aquí tens el meu agraïment!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} ha rebut una POCIÓ.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Eh?\n"
	.string "La MOTXILLA està plena de gom a gom.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} polzades, oi?\p"
	.string "Hmm… He vist un SEEDOT més gran\n"
	.string "que aquest.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Oh, això sí que és una cosa…\n"
	.string "Però no és un SEEDOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "No tens un SEEDOT gran?\n"
	.string "Quina llàstima…\p"
	.string "Si aconsegueixes un SEEDOT gran,\n"
	.string "si us plau, vine a ensenyar-me'l.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "El SEEDOT més gran de la història!\n"
	.string "El gegant de {STR_VAR_3} polzades de {STR_VAR_2}!\p"
	.string "Un SEEDOT més gran que un LOTAD\n"
	.string "sempre he volgut!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Coneixes el POKéMON LOTAD?\n"
	.string "Rarament es veu a ALGÈPOLIS.\p"
	.string "M'encanten, però m'encanten els LOTAD grans!\p"
	.string "El meu germà gran diu que SEEDOT és\n"
	.string "més gran.\p"
	.string "Però això és fals! Tothom sap que\n"
	.string "LOTAD és molt més gran.\p"
	.string "Eh? Tens un LOTAD?\n"
	.string "S-si us plau, ensenya-me'l!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} polzades!\n"
	.string "Uau, això sí que és gran!\p"
	.string "Podria ser fins i tot més gran que l'enorme\n"
	.string "SEEDOT que va veure el meu germà gran.\p"
	.string "Gràcies per ensenyar-me'l!\n"
	.string "Aquí tens el meu agraïment!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} ha rebut una POCIÓ.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Eh?\n"
	.string "La MOTXILLA està plena de gom a gom.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} polzades?\p"
	.string "Hmm… He vist un LOTAD més gran\n"
	.string "que aquest d'aquí.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Vaja, això sí que és quelcom!\n"
	.string "Però no és cap LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "No tens un LOTAD gran?\n"
	.string "Quina decepció…\p"
	.string "Si aconsegueixes un LOTAD gran,\n"
	.string "si us plau, vine a ensenyar-me'l!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "El LOTAD més gran de la història!\n"
	.string "El colós de {STR_VAR_3} polzades de {STR_VAR_2}!\p"
	.string "Un LOTAD més gran que un SEEDOT\n"
	.string "sempre he volgut!$"

