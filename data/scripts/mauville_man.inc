MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hola, sóc el COMERCIANT.\n"
	.string "Vols intercanviar decoracions amb mi?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "M'has deixat amb la moral baixa…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Però ja hem intercanviat decoracions,\n"
	.string "tu i jo.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Si veus algun objecte decoratiu meu\n"
	.string "que vulguis, digues-ho.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "No vols res?\n"
	.string "Em sento rebutjat…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Aquell objecte decoratiu va pertànyer\n"
	.string "a {STR_VAR_1}.\p"
	.string "El vols?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Eh… Espera un moment. No tens ni\n"
	.string "una sola peça de decoració!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "D'acord, tria la decoració que\n"
	.string "m'intercanviaràs.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "No vols intercanviar amb mi?\n"
	.string "Em sento rebutjat…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Tens tots els {STR_VAR_2}S que es poden\n"
	.string "emmagatzemar. No tens lloc per això.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "D'acord, intercanviem el meu {STR_VAR_3}\n"
	.string "pel teu {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Aquesta peça de decoració està en ús.\n"
	.string "No la pots intercanviar.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Doncs intercanviem!\n"
	.string "Enviaré la meva decoració al teu PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ui! Ho sento! Aquesta és una peça\n"
	.string "de decoració molt rara.\l"
	.string "No puc intercanviar-la!\p"
	.string "Et puc oferir alguna altra cosa?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Sóc el CONTACONTES.\n"
	.string "Et contaré històries d'ENTRENADORS\l"
	.string "llegendaris.\p"
	.string "Vols escoltar la meva història?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "M'has deixat amb la moral baixa…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Conec aquestes llegendes.\n"
	.string "Quina història vols que t'expliqui?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Però no conec cap ENTRENADOR llegendari.\n"
	.string "Per tant, no conec cap història.\p"
	.string "On es pot trobar un ENTRENADOR digne\n"
	.string "d'una història llegendària?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Què dius?!\n"
	.string "Tu… Tu…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} vegades?!\p"
	.string "Això és realment magnífic!\n"
	.string "És el naixement d'una nova llegenda!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Em fa pensar, hi podria haver\n"
	.string "altres ENTRENADORS amb llegendes\l"
	.string "més impressionants per descobrir?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Ets un ENTRENADOR?\p"
	.string "Doncs digues-me, tens alguna història\n"
	.string "que sigui ni que sigui remotament\l"
	.string "llegendària?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Per cert… Voldries escoltar\n"
	.string "una altra història llegendària?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "No estic satisfet…\p"
	.string "M'agradaria que em portessis notícies\n"
	.string "dignes de ser anomenades una llegenda.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "M'agradaria que més gent estigués\n"
	.string "interessada a escoltar les meves\l"
	.string "històries èpiques d'ENTRENADORS\l"
	.string "llegendaris.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "L'ENTRENADOR que Desa$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Va desar la partida$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va desar la partida\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "No trobaràs cap ENTRENADOR més\n"
	.string "cautelós que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "L'ENTRENADOR de Modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Va crear modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va crear noves modes\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} està creant tendències per a\n"
	.string "tota la regió de HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "L'ENTRENADOR de BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Va plantar BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va plantar BAIES\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} és un llegendari amant\n"
	.string "de les BAIES!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "L'ENTRENADOR de BICIS$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Va canviar BICIS$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va canviar BICIS\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} deu estimar les BICIS\n"
	.string "profunda i apassionadament!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "L'ENTRENADOR Entrevistat$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Va ser entrevistat$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va ser entrevistat\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} deu ser un ENTRENADOR que\n"
	.string "atrau molta atenció!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "L'ENTRENADOR Combatent$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Va combatre$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va combatre\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} deu ser un ENTRENADOR que\n"
	.string "mai rebutja una oportunitat de combat!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "L'ENTRENADOR Capturador$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Va capturar POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va capturar\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} és un llegendari capturador\n"
	.string "de POKéMON salvatges!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "L'ENTRENADOR Pescador$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Va capturar POKéMON pescant$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va capturar\n"
	.string "{STR_VAR_1} POKéMON pescant!\p"
	.string "{STR_VAR_3} és un llegendari expert\n"
	.string "de la pesca!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "L'ENTRENADOR Esclovador$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Va fer eclosionar OUS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va fer eclosionar\n"
	.string "{STR_VAR_1} POKéMON d'OUS!\p"
	.string "{STR_VAR_3} és un llegendari escalfador\n"
	.string "d'OUS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "L'ENTRENADOR Evolucionador$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Va fer evolucionar POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va fer evolucionar\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} és el definitiu evolucionador\n"
	.string "de POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "L'ENTRENADOR del CENTRE$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Va usar CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va curar POKéMON\n"
	.string "{STR_VAR_1} vegades als CENTRES POKéMON!\p"
	.string "No hi ha major amant dels CENTRES\n"
	.string "POKéMON que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "L'ENTRENADOR Casolà$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Va descansar POKéMON a casa$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va curar POKéMON\n"
	.string "{STR_VAR_1} vegades a casa!\p"
	.string "No hi pot haver ningú més casolà\n"
	.string "que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "L'ENTRENADOR del SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Va entrar a la ZONA SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va entrar a la\n"
	.string "ZONA SAFARI {STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} és un ENTRENADOR el costat\n"
	.string "salvatge del qual surt a la ZONA SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "L'ENTRENADOR Tallador$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Va usar TALL$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va usar TALL\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} és un ENTRENADOR que deu\n"
	.string "estimar TALLAR!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "L'ENTRENADOR Trencapedres$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Va trencar roques$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va usar TRENCA ROCA\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} deu ser un ENTRENADOR que\n"
	.string "no pot deixar cap pedra sense trencar!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "L'ENTRENADOR Mudancer$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Va moure la BASE SECRETA$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va moure la BASE\n"
	.string "SECRETA {STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} és un ENTRENADOR que estima\n"
	.string "mudar-se sovint!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "L'ENTRENADOR Saltador$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Va usar ESQUITX$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va usar ESQUITX\n"
	.string "{STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} és un ENTRENADOR que deu\n"
	.string "estimar esquitxar!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "L'ENTRENADOR Tenaç$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Va recórrer a LLUITA$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Aquesta és la història d'un ENTRENADOR\n"
	.string "anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va haver de recórrer\n"
	.string "a LLUITA {STR_VAR_1} vegades!\p"
	.string "{STR_VAR_3} és un ENTRENADOR tenaç\n"
	.string "que mai cedeix a l'adversitat!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "El Campió de les SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Ha guanyat el premi gros a les SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va guanyar el\n"
	.string "premi gros a les SLOTS {STR_VAR_1} cops.\p"
	.string "{STR_VAR_3} és un ENTRENADOR que va\n"
	.string "tenir sort a les SLOTS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "El Campió de la RULETA$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Ha guanyat consecutivament a la RULETA$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va guanyar a la\n"
	.string "RULETA {STR_VAR_1} cops seguits.\p"
	.string "{STR_VAR_3} va tenir sort quan la bola\n"
	.string "va botar a la RULETA!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "El Desafiador de la TORRE BATALLA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Ha acceptat el repte de la TORRE BATALLA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va acceptar el\n"
	.string "repte de la TORRE BATALLA {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} és un ENTRENADOR que aspira\n"
	.string "a l'excel·lència a la TORRE BATALLA!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "L'Amant de les Mescles$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Ha fet {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va fer {POKEBLOCK}S\n"
	.string "{STR_VAR_1} cops!\p"
	.string "Ningú no és millor usant la MESCLADORA\n"
	.string "DE BAIES que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "L'Amant dels CONCURSOS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Ha participat en CONCURSOS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va participar en\n"
	.string "CONCURSOS {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu adorar ensenyar els\n"
	.string "seus POKéMON als altres!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "El Mestre dels CONCURSOS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Ha guanyat CONCURSOS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va guanyar\n"
	.string "CONCURSOS {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu ser un mestre dels\n"
	.string "CONCURSOS increïble!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "El Comprador Feliç$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Ha anat de compres$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va comprar coses\n"
	.string "a les botigues {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu ser d'aquelles persones\n"
	.string "que han nascut per comprar.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "El Trobador d'Objectes$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Ha usat un BUSCAOBJECTES$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va usar un\n"
	.string "BUSCAOBJECTES {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu gaudir escorcollant\n"
	.string "el terra per trobar objectes ocults!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "L'ENTRENADOR Xop$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Li ha caigut la pluja a sobre$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR es va mullar\n"
	.string "per la pluja {STR_VAR_1} cops!\p"
	.string "El carisma de {STR_VAR_3} fins i tot\n"
	.string "atrau la pluja!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "El Lector Àvid de POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Ha consultat la POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va consultar\n"
	.string "la POKéDEX {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu adorar inspeccionar\n"
	.string "POKéMON a la POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "El Col·leccionista de LLAÇOS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Ha rebut LLAÇOS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va rebre\n"
	.string "LLAÇOS {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu ser un ENTRENADOR que\n"
	.string "adora col·leccionar LLAÇOS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "El Saltador de Penya-segats$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Ha saltat penya-segats$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va saltar\n"
	.string "penya-segats {STR_VAR_1} cops!\p"
	.string "Si hi ha un penya-segat per saltar,\n"
	.string "{STR_VAR_3} no se'l pot saltar!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "L'Espectador Llegendari de TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Ha mirat la TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va mirar la TV\n"
	.string "{STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu adorar mirar la TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "L'ENTRENADOR Conscient del Temps$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Ha mirat l'hora$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va mirar l'hora\n"
	.string "{STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu ser un ENTRENADOR puntual\n"
	.string "que és conscient del temps.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "El Mag de la LOTERIA POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Ha guanyat LOTERIES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va guanyar\n"
	.string "LOTERIES POKéMON {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu tenir molts amics\n"
	.string "amb qui intercanviar POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "L'Usuari de la GUARDERIA$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Ha deixat POKéMON a la GUARDERIA$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va deixar POKéMON\n"
	.string "a la GUARDERIA {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu ser un emprenedor que\n"
	.string "cria POKéMON de manera agressiva!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "L'Amant del TELEFÈRIC$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Ha agafat el TELEFÈRIC$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR va agafar el\n"
	.string "TELEFÈRIC {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu ser un ENTRENADOR ocupat\n"
	.string "que sempre va amunt i avall!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "L'Amant de les Aigües Termals$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "S'ha banyat a les aigües termals$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Aquesta és la història d'un\n"
	.string "ENTRENADOR anomenat {STR_VAR_3}.\p"
	.string "Aquest ENTRENADOR es va banyar a\n"
	.string "les aigües termals {STR_VAR_1} cops!\p"
	.string "{STR_VAR_3} deu ser un ENTRENADOR\n"
	.string "amb la pell suau com un bebè!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Sóc en RIALLER!\n"
	.string "Tinc una història fascinant per a tu!\p"
	.string "Vols sentir la meva història?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "M'has deixat amb la moral baixa…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "A més, estava pensant…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "I crec que això és tot…\p"
	.string "Hauríem de xerrar un altre cop!\n"
	.string "Adéu-siau!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hola, sóc el BARD.\n"
	.string "Vols escoltar la meva cançó?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "M'has deixat amb la moral baixa…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, quina cançó tan emotiva…\n"
	.string "M'agradaria tocar-la per altres…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "I bé?\n"
	.string "T'agrada la meva cançó?\p"
	.string "Però no estic gaire content amb\n"
	.string "la lletra.\p"
	.string "Voldries escriure una lletra\n"
	.string "nova per a mi?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "M'has deixat amb la moral baixa…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Moltes gràcies!\n"
	.string "Deixa'm cantar-la per a tu.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Era així com volies que fos\n"
	.string "la teva cançó?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "D'acord! Doncs ja està.\n"
	.string "Cantaré aquesta cançó una temporada.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Ei, iu! Em diuen el MODERNÀS.\n"
	.string "T'ensenyaré el que es porta ara.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Però, ei, ja t'he ensenyat el que\n"
	.string "es porta ara.\p"
	.string "M'agradaria escampar la bona paraula\n"
	.string "a altres persones.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Però, ei, ja saps molt sobre el que\n"
	.string "es porta ara.\p"
	.string "No tinc res de nou per ensenyar-te!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Ei, has sentit a parlar de\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Què vol dir? Doncs…\n"
	.string "Pregunta-ho al teu pare o mare!$"
