Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Què és això?\n"
	.string "Què estic fent?\p"
	.string "Estic pensant en fer-me la meva pròpia\n"
	.string "habitació aquí amb un moviment POKéMON.\p"
	.string "Ja ho sé! Et donaré aquesta MT.\n"
	.string "La faràs servir per fer la teva habitació?$"

Route111_Text_ExplainSecretPower:
	.string "Busca un arbre gran que sembli que\n"
	.string "podrien caure lianes.\p"
	.string "Fes servir PODER SECRET davant l'arbre.\n"
	.string "Algunes lianes haurien d'alliberar-se\l"
	.string "i caure, perquè puguis escalar l'arbre.\p"
	.string "Trobaràs molt d'espai per posar-hi\n"
	.string "les teves coses preferides.\p"
	.string "Serà la teva pròpia habitació secreta…\n"
	.string "Una BASE SECRETA!\p"
	.string "Tu també n'hauries de fer una.\p"
	.string "Una altra cosa, no sempre has de\n"
	.string "fer la teva BASE SECRETA en un arbre.\p"
	.string "Prova d'usar PODER SECRET en parets\n"
	.string "de roca que tinguin petites osques.\p"
	.string "Jo buscaré altres llocs també.\n"
	.string "D'acord, adeu!$"

Route111_Text_DontWantThis:
	.string "Oh, no ho vols?\n"
	.string "Si canvies d'opinió, digues-m'ho, d'acord?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, no tens espai per a això.\p"
	.string "Me'l guardaré, així que torna a\n"
	.string "buscar-lo un altre dia, d'acord?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
