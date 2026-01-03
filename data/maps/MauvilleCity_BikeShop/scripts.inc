MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Vaja, vaja, què tenim aquí?\n"
	.string "Un client molt energètic!\p"
	.string "Jo? Pots dir-me RADEL.\n"
	.string "Sóc el propietari d'aquesta botiga de bicis.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RADEL: Les teves SABATILLES…\n"
	.string "Estan bastant brutes.\p"
	.string "Has vingut de molt lluny?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RADEL: Ah, sí?\p"
	.string "Llavors, suposo que no necessites\n"
	.string "cap de les meves BICIS.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RADEL: Hm, hm… … … … …\p"
	.string "Dius que has vingut de\n"
	.string "LLAVOR PETITA?\p"
	.string "Déu meu!\n"
	.string "Això és ridículament lluny!\p"
	.string "Si tinguessis una de les meves BICIS,\n"
	.string "podries anar a qualsevol lloc fàcilment\l"
	.string "mentre sents la caricia del vent!\p"
	.string "T'explicaré què!\n"
	.string "Et donaré una BICI!\p"
	.string "Oh, espera un segon!\p"
	.string "He oblidat dir-te que hi ha\n"
	.string "dos tipus de BICIS!\p"
	.string "Són la BICI TURBO i\n"
	.string "la BICI ACROBÀTICA!\p"
	.string "La BICI TURBO és per a ciclistes que\n"
	.string "volen sentir el vent amb el cos!\p"
	.string "I la BICI ACROBÀTICA és per als que\n"
	.string "prefereixen passejos tècnics!\p"
	.string "Sóc molt generós, així que pots\n"
	.string "triar la que vulguis!\p"
	.string "Quina triaràs?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} ha triat la BICI TURBO.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} ha triat la BICI ACROBÀTICA.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RADEL: Si tens ganes de canviar\n"
	.string "de BICI, vine a veure'm!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RADEL: Oh? Estaves pensant en\n"
	.string "canviar de BICI?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RADEL: D'acord, cap problema!\n"
	.string "Et canviaré la BICI!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} ha canviat la BICI TURBO\n"
	.string "per una BICI ACROBÀTICA.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} ha canviat la BICI ACROBÀTICA\n"
	.string "per una BICI TURBO.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RADEL: Bé, bé!\n"
	.string "M'alegro que t'agradi!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Què ha passat amb aquella BICI\n"
	.string "que et vaig donar?\p"
	.string "Oh, ja ho entenc, l'has guardat al PC.\p"
	.string "Bé, treu-la del PC,\n"
	.string "i estaré encantat de canviar-la!\p"
	.string "Que el vent sempre bufi a favor\n"
	.string "en la teva aventura!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Estic aprenent sobre BICIS mentre\n"
	.string "treballo aquí.\p"
	.string "Si necessites consells sobre com muntar\n"
	.string "la teva BICI, hi ha un parell de manuals\l"
	.string "al fons.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "És un manual de la BICI TURBO.\p"
	.string "Quina pàgina vols llegir?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Una BICI es mou en la direcció que\n"
	.string "prems al Pad de Control +.\p"
	.string "Agafarà velocitat quan comenci a rodar.\p"
	.string "Per parar, deixa anar el Pad de Control +.\n"
	.string "La BICI s'aturarà.\p"
	.string "Vols llegir una altra pàgina?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Una BICI TURBO és ràpida, però no pot\n"
	.string "parar gaire ràpid.\p"
	.string "Es torna una mica complicat girar\n"
	.string "en una cantonada.\p"
	.string "Deixa anar el Pad de Control + una mica\n"
	.string "abans de la cantonada i frena.\p"
	.string "Vols llegir una altra pàgina?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Hi ha petites pujades de sorra\n"
	.string "per tota la regió de HOENN.\p"
	.string "La sorra fluixa i esmicable fa que sigui\n"
	.string "impossible pujar normalment.\p"
	.string "Però si tens una BICI TURBO, pots\n"
	.string "pujar ràpidament una pujada de sorra.\p"
	.string "Vols llegir una altra pàgina?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "És un manual de la BICI ACROBÀTICA.\p"
	.string "Quina pàgina vols llegir?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Prem el Botó B mentre condueixes,\n"
	.string "i la roda davantera s'aixecarà.\p"
	.string "Pots circular amb la roda davantera\n"
	.string "aixecada usant el Pad de Control +.\p"
	.string "Aquesta tècnica es diu wheelie.\p"
	.string "Vols llegir una altra pàgina?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Mantenint el Botó B premut,\n"
	.string "la teva BICI pot saltar al lloc.\p"
	.string "Aquesta tècnica es diu bunny hop.\p"
	.string "També pots conduir saltant.\p"
	.string "Vols llegir una altra pàgina?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Prem el Botó B i el Pad de Control +\n"
	.string "alhora per saltar.\p"
	.string "Prem el Pad de Control + cap al costat\n"
	.string "per saltar de costat.\p"
	.string "Prem-lo cap enrere per fer que la BICI\n"
	.string "canviï de direcció mentre salta.\p"
	.string "Vols llegir una altra pàgina?$"

