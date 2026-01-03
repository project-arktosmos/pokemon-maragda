FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COSMOS: Oh…\n"
	.string "No hauria haver deixat que m'enganyessin\l"
	.string "per dir a l'EQUIP MAGMA on es troben\l"
	.string "els METEORITS…\p"
	.string "Aquell METEORIT de CASCADA METEÒRICA…\n"
	.string "Mai serà meu ara…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Eh?\p"
	.string "Aquest objecte…\p"
	.string "Podria ser?\p"
	.string "És el METEORIT que l'EQUIP MAGMA\n"
	.string "va agafar de CASCADA METEÒRICA?\p"
	.string "Si us plau, me'l pots donar?\p"
	.string "No el demano de franc.\n"
	.string "Què et sembla a canvi d'aquesta MT?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COSMOS: Aquesta MT representa\n"
	.string "el meu sentiment de gratitud.\l"
	.string "Si us plau, utilitza-la!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COSMOS: Oh, no m'ho puc creure.\n"
	.string "Això és genial, genial!\p"
	.string "Això ajudarà molt la meva recerca!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COSMOS: Oh, però…\n"
	.string "Estic destrossat per la decepció…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COSMOS: Si us plau, em pots donar\n"
	.string "aquest METEORIT?\p"
	.string "No el demano de franc.\n"
	.string "Què et sembla a canvi d'aquesta MT?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "El PROF. COSMOS ha anat a CASCADA\n"
	.string "METEÒRICA, a la RUTA 114, amb gent\l"
	.string "de l'EQUIP MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Pobre PROF. COSMOS…\n"
	.string "Està tan deprimit… Em sap greu per ell.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Mira el PROF. COSMOS…\n"
	.string "Està tan content! Trobo que és bonic.$"

