SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Benvingut al MUSEU OCEÀNIC.\p"
	.string "L'entrada costa ¥50.\n"
	.string "Vols entrar?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Que ho gaudeixis.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? Ho sento, però sembla que no\n"
	.string "tens prou diners.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? Ets del grup que ha entrat\n"
	.string "abans?\p"
	.string "Ets l'únic que arriba tard.\n"
	.string "Millor que els atrapin!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Nosaltres, l'EQUIP AQUA, existim pel\n"
	.string "bé de tots!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Ens van dir que ens reuníssim aquí,\n"
	.string "així que ho vam fer, però…\p"
	.string "El nostre CAP, la peça clau, no hi és.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Si robés les coses d'aquí,\n"
	.string "em faria ric?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "El que aprengui aquí, ho puc fer servir\n"
	.string "per a malifetes…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Si els nostres no ho haguessin pifiat\n"
	.string "a FERRERICA, no seríem aquí!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "No tenia ¥50, així que va costar\n"
	.string "molt passar pel recepcionista.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Vull aprendre sobre el mar i\n"
	.string "usar aquest coneixement per combatre.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Em poso tot emocionat i content\n"
	.string "quan veig el mar!\p"
	.string "Per a mi, el CAP. STERN és el\n"
	.string "model a seguir número u!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "El mar és vast sense fi, i\n"
	.string "infinitament profund…\p"
	.string "Hi ha d'haver molts POKéMON que\n"
	.string "no coneixem.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Vull un POKéMON marí.\p"
	.string "Crec que seria fresquet i agradable\n"
	.string "d'abraçar.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiyeeeh!\n"
	.string "Què fas aquí?\p"
	.string "Jo? Sóc el membre de l'EQUIP AQUA\n"
	.string "que vas apallissar abans, recordes?\l"
	.string "Al TÚNEL RUGITURF?\p"
	.string "Aquí tens, pren això!\n"
	.string "M'has de perdonar!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Aquesta MT t'escau més a tu\n"
	.string "que a mi.\p"
	.string "Espero no tornar-te a veure mai!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Va, siiii!\n"
	.string "Has de prendre això i deixar-me marxar!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Un fluid blau està girant en espiral\n"
	.string "dins d'un recipient de vidre.\p"
	.string "“Això és un experiment per crear un\n"
	.string "REMOLÍ artificialment usant vent.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Una bola vermella puja i baixa\n"
	.string "dins d'un recipient de vidre.\p"
	.string "“Això és un experiment que simula una\n"
	.string "CASCADA usant la flotabilitat de la bola.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "És una mostra de sòl del fons\n"
	.string "de l'oceà.\p"
	.string "“Durant molts anys, les restes de\n"
	.string "formes de vida s'acumulen al fons del\l"
	.string "mar, formant capes sedimentàries.\p"
	.string "“Analitzant aquestes capes, es revela\n"
	.string "el passat antic.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "És una mostra de sorra de platja.\p"
	.string "“Les pedres de les muntanyes són\n"
	.string "arrossegades pels rius on són\l"
	.string "esmicolades i polides.\p"
	.string "“Es redueixen a grans i acaben\n"
	.string "com a sorra a les platges.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“CURIOSITAT OCEÀNICA 1\n"
	.string "Per què l'aigua de mar és blava?\p"
	.string "“La llum es compon de molts colors.\p"
	.string "“Quan la llum passa per l'aigua,\n"
	.string "la majoria de tipus de llum perden color.\p"
	.string "“No obstant, la llum blava conserva\n"
	.string "el seu color, fent que el mar sembli blau.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“CURIOSITAT OCEÀNICA 2\n"
	.string "Per què el mar és salat?\p"
	.string "“L'aigua de mar conté sal dissolta en\n"
	.string "forma d'ions de sodi i clor.\p"
	.string "“Aquests ions es filtren de les roques\n"
	.string "i són portats al mar per la pluja.\p"
	.string "“La concentració de sal dissolta\n"
	.string "fa que el mar sigui salat.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“CURIOSITAT OCEÀNICA 3\n"
	.string "Què és més gran? El mar o la terra?\p"
	.string "“El mar cobreix aproximadament el 70%\n"
	.string "del planeta, i la resta és terra.\p"
	.string "“Per tant, el mar és més del doble\n"
	.string "de gran que la terra.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "És un fòssil amb crestes ondulades.\p"
	.string "“El sòl del fons oceànic és erosionat\n"
	.string "per la marea.\p"
	.string "“L'aigua de mar en moviment marca el sòl\n"
	.string "amb petites crestes i valls.\p"
	.string "“Si aquest sòl es fossilitza, s'anomena\n"
	.string "marca d'onada.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Una màquina estranya està girant\n"
	.string "sota una cúpula de vidre.\p"
	.string "Potser serveix per mesurar la\n"
	.string "profunditat d'alguna cosa…$"

