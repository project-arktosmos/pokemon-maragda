LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "AURA: {PLAYER}{KUN}! Quant de temps!\p"
	.string "Oh? Mentre jo visitava les aigües termals,\n"
	.string "tu has aconseguit la MEDALLA DE TERMA.\p"
	.string "Deus haver recollit\n"
	.string "bons POKéMON…\l"
	.string "No, crec que n'has criat alguns.\p"
	.string "Suposo que estaria bé que tinguessis\n"
	.string "això.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "AURA: Amb aquestes ULLERES DEL DESERT,\n"
	.string "no tindràs problemes per travessar\l"
	.string "el desert a prop de la RUTA 111.\p"
	.string "Però, uau, {PLAYER}{KUN}…\n"
	.string "Desafiant GIMNASOS…\p"
	.string "T'esforces molt perquè no em vols\n"
	.string "perdre, aposto!\p"
	.string "{PLAYER}{KUN}, crec que hauria de desafiar\n"
	.string "el teu pare al GIMNÀS DE PETÀLIA.\p"
	.string "Ens veiem!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BLAI: {PLAYER}, ei, fa temps.\n"
	.string "Com va?\p"
	.string "Hmm…\n"
	.string "És una bona col·lecció de MEDALLES.\p"
	.string "D'acord, doncs.\n"
	.string "Et pots quedar això.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BLAI: Porta això amb tu si tens previst\n"
	.string "anar al desert a prop de la\l"
	.string "RUTA 111.\p"
	.string "Hi hauria d'haver POKéMON que viuen\n"
	.string "exclusivament al desert.\l"
	.string "Podries buscar-ne alguns.\p"
	.string "Pel que fa a mi…\n"
	.string "Estic pensant en desafiar en NORBERT,\l"
	.string "el LÍDER DE GIMNÀS DE PETÀLIA.\p"
	.string "A diferència de tu, {PLAYER}, el teu pare\n"
	.string "sembla que és realment dur.\p"
	.string "Ens veiem!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Tinc aquí un OU.\p"
	.string "Esperava fer-lo eclosionar cobrint-lo\n"
	.string "amb sorra calenta a les termes.\l"
	.string "Però no sembla ser suficient…\p"
	.string "He sentit que seria millor si es\n"
	.string "manté junt amb POKéMON i es\l"
	.string "porta per tot arreu.\p"
	.string "Ets un ENTRENADOR, oi?\n"
	.string "I els teus POKéMON irradien vitalitat.\p"
	.string "Doncs, què me'n dius?\n"
	.string "Voldràs agafar aquest OU per fer-lo eclosionar?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Bé! Espero que caminis molt amb\n"
	.string "aquest OU!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} ha rebut l'OU.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? Tens massa POKéMON.\n"
	.string "No hi ha lloc per a aquest OU…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Com vulguis, doncs…\p"
	.string "Si canvies d'opinió sobre fer eclosionar\n"
	.string "aquest OU, seré aquí.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "De tant en tant, es troben OUTS a la\n"
	.string "GUARDERIA POKéMON.\p"
	.string "O almenys així diuen els rumors.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Traiem tanta aigua calenta com necessitem,\n"
	.string "i les termes mai s'assequen.\p"
	.string "No és màgic?\p"
	.string "Aquestes termes apareixen a prop de\n"
	.string "volcans actius. Les venes d'aigua sota\l"
	.string "terra són escalfades pel magma i brollen\l"
	.string "com a aigües termals.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Estar enterrat en aquesta sorra calenta és…\n"
	.string "Sospir…\p"
	.string "Tan calent i celestial…\p"
	.string "Eh? Gyaah! Au!\p"
	.string "Un POKéMON m'ha mossegat el cul!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, t'agraden les aigües termals?\p"
	.string "És sorprenent per algú tan jove\n"
	.string "com tu.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Em banyo a les termes cada dia.\p"
	.string "Vull convertir-me en una LÍDER DE GIMNÀS\n"
	.string "forta i bonica com la CANDELA.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Si la gent posés POKéMON a les termes,\n"
	.string "podria ser molt estrany.\p"
	.string "Podria ser un bany elèctric, o\n"
	.string "un bany de bombolles, o fins i tot de lava…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Diuen que aquestes aigües termals\n"
	.string "són bones per calmar la tensió nerviosa,\l"
	.string "alleujar els músculs adolorits, resoldre\l"
	.string "problemes romàntics, i atraure\l"
	.string "diners…$"

LavaridgeTown_Text_TownSign:
	.string "POBLE TERMA\p"
	.string "“AIGÜES TERMALS DEL CENTRE POKéMON\n"
	.string "Un lloc excel·lent per relaxar-se!”$"

LavaridgeTown_Text_GymSign:
	.string "GIMNÀS POKéMON DE POBLE TERMA\n"
	.string "LÍDER: CANDELA\l"
	.string "“La que crema amb passió de foc!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "BOTIGA D'HERBES POKéMON\n"
	.string "“Gust amarg, millor cura!”$"

