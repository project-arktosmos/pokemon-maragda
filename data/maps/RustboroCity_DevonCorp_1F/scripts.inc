RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Hola i benvingut a la CORPORACIÓ\n"
	.string "DEVON.\p"
	.string "Som productors orgullosos d'objectes i\n"
	.string "medicaments que milloren la teva vida.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Un dels nostres investigadors estúpidament\n"
	.string "ha deixat que li robessin un paquet important.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Ep, aquestes SABATILLES!\n"
	.string "Són un dels nostres productes!\p"
	.string "Em fa feliç quan veig algú\n"
	.string "usant alguna cosa que hem fet.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Aquell paquet robat…\p"
	.string "Bé, és clar que és important, però no és\n"
	.string "res que qualsevol pugui usar.\p"
	.string "Segons la meva estimació, aquell lladre\n"
	.string "no devia ser gaire llest.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Sembla que han recuperat\n"
	.string "les MERCADERIES DEVON robades.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Ho sento, només les persones autoritzades\n"
	.string "poden entrar aquí.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "És d'una estupidesa increïble.\n"
	.string "Com han pogut robar-nos?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hola!\n"
	.string "Sempre ets benvingut aquí!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Hi ha mostres de roques i metall\n"
	.string "exposades a la vitrina.\p"
	.string "Hi ha un panell amb un text\n"
	.string "escrit…\p"
	.string "“La CORPORACIÓ DEVON va començar com\n"
	.string "a productora de pedres de pedreres.\p"
	.string "“L'empresa també produïa ferro a partir\n"
	.string "de llimadures de la sorra.\p"
	.string "“Des d'aquell humil inici com a productora\n"
	.string "de matèries primeres, DEVON va créixer.\p"
	.string "“DEVON és ara fabricant d'una àmplia\n"
	.string "gamma de productes industrials.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototips i productes de prova omplen\n"
	.string "la vitrina.\p"
	.string "Hi ha un panell amb una descripció…\p"
	.string "“A més de productes industrials,\n"
	.string "DEVON ara comercialitza articles diversos i\l"
	.string "farmacèutics per a millors estils de vida.\p"
	.string "“Recentment, DEVON ha començat a comercialitzar\n"
	.string "eines per a ENTRENADORS POKéMON, incloent\l"
	.string "POKé BALLS i sistemes POKéNAV.”$"

