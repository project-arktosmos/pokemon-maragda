RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, és tan difícil cada dia…\p"
	.string "Què és difícil?\n"
	.string "Has de preguntar?\p"
	.string "És intentar decidir què\n"
	.string "fer per menjar cada dia.\p"
	.string "Realment no és fàcil pensar\n"
	.string "els àpats cada dia.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, hola!\n"
	.string "Benvingut a casa dels PEBRE.\p"
	.string "Tinc una pregunta per a tu.\n"
	.string "Has cuidat mai nens?\p"
	.string "Mira, sóc pare novell, així que criar\n"
	.string "un fill és tot nou per a mi.\p"
	.string "I tinc un problema. La meva filla\n"
	.string "WALDA no riu prou.\p"
	.string "Crec que riuria si li digués\n"
	.string "alguna cosa divertida.\p"
	.string "Coneixes alguna paraula o frase\n"
	.string "divertida que em puguis dir?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "He estat dient “{STR_VAR_1}”\n"
	.string "per divertir-la últimament.\p"
	.string "Coneixes alguna paraula o frase\n"
	.string "millor que pugui funcionar?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, és meravellós.\n"
	.string "Doncs, digues-m'ho, la teva proposta.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, de veritat?\p"
	.string "Bé, si se t'acut una bona proposta,\n"
	.string "sóc tot orelles.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, ja veig.\n"
	.string "Bé, provem-ho, d'acord?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, sí! Està rient!\n"
	.string "Oh, estic tan content com ella!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, ja veig.\n"
	.string "Bé, provem-ho, d'acord?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… No somriu gens.\n"
	.string "Potser la WALDA és una nena seriosa…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, així que no coneixes cap paraula bona.\n"
	.string "Hauré de pensar pel meu compte, doncs.\p"
	.string "Hmm…\n"
	.string "Què tal “{STR_VAR_1}”?\l"
	.string "A veure si funciona.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… No somriu gens.\n"
	.string "Potser la WALDA és una nena seriosa…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, així que no coneixes cap paraula bona.\n"
	.string "Suposo que intentaré divertir-la amb\l"
	.string "la frase que feia servir abans.\p"
	.string "De totes maneres, si tens una bona proposta,\n"
	.string "no dubtis a dir-m'ho, d'acord?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Gràcies!\p"
	.string "Gràcies a tu, la meva estimada WALDA\n"
	.string "ha rigut per a mi!\p"
	.string "En realitat, potser no semblo gaire\n"
	.string "especial, però sóc un dels millors\l"
	.string "investigadors de la CORPORACIÓ DEVON.\p"
	.string "I si et fes alguna cosa a canvi?\p"
	.string "Ja ho sé, afegiré nous patrons de fons\n"
	.string "de pantalla per a les CAIXES al Sistema\l"
	.string "d'Emmagatzematge POKéMON del PC.\p"
	.string "Al menú de patrons de fons de pantalla,\n"
	.string "selecciona “AMICS.”\p"
	.string "Això et donarà accés als nous\n"
	.string "patrons de fons de pantalla.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "És una NINA de peluix POKéMON!$"

