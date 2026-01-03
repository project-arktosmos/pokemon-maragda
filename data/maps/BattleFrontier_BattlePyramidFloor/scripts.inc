BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, LOCALID_NONE, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Aquest és un missatge de prova.$"

gText_BattlePyramidConfirmRest::
	.string "La teva missió de PIRÀMIDE COMBAT es\n"
	.string "desarà perquè puguis sortir ara.\l"
	.string "D'acord?$"

gText_BattlePyramidConfirmRetire::
	.string "Segur que vols abandonar la teva\n"
	.string "missió de PIRÀMIDE?$"

BattlePyramid_Text_ExitHintUp1::
	.string "La sortida d'aquest pis és en\n"
	.string "aquesta direcció: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "La sortida d'aquest pis és en\n"
	.string "aquesta direcció: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "La sortida d'aquest pis és en\n"
	.string "aquesta direcció: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "La sortida d'aquest pis és en\n"
	.string "aquesta direcció: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "La sortida d'aquest pis és en\n"
	.string "direcció {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "La sortida d'aquest pis és en\n"
	.string "direcció {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "La sortida d'aquest pis és en\n"
	.string "direcció {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "La sortida d'aquest pis és en\n"
	.string "direcció {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "La sortida és\n"
	.string "cap a {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "La sortida és\n"
	.string "cap a {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "La sortida és\n"
	.string "cap a {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "La sortida és\n"
	.string "cap a {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "En aquest pis, la sortida és en algun\n"
	.string "lloc en direcció {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "En aquest pis, la sortida és en algun\n"
	.string "lloc en direcció {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "En aquest pis, la sortida és en algun\n"
	.string "lloc en direcció {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "En aquest pis, la sortida és en algun\n"
	.string "lloc en direcció {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "La sortida?\n"
	.string "És cap a {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "La sortida?\n"
	.string "És cap a {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "La sortida?\n"
	.string "És cap a {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "La sortida?\n"
	.string "És cap a {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "La sortida resulta ser en\n"
	.string "direcció {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "La sortida resulta ser en\n"
	.string "direcció {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "La sortida resulta ser en\n"
	.string "direcció {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "La sortida resulta ser en\n"
	.string "direcció {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden vuit objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden set objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden sis objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden cinc objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden quatre objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden tres objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden dos objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Busques objectes?\p"
	.string "Queda un objecte per\n"
	.string "trobar.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Busques objectes?\p"
	.string "No queda res per\n"
	.string "trobar!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Hi ha vuit objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden set objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden sis objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden cinc objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden quatre objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden tres objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden dos objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Només queda un objecte\n"
	.string "escampat per aquí.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "No queda res\n"
	.string "escampat per aquí.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que queden vuit objectes\n"
	.string "esperant ser trobats en aquest pis.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que queden set objectes\n"
	.string "esperant ser trobats en aquest pis.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que queden sis objectes\n"
	.string "esperant ser trobats en aquest pis.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que queden cinc objectes\n"
	.string "esperant ser trobats en aquest pis.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que queden quatre objectes\n"
	.string "esperant ser trobats en aquest pis.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que queden tres objectes\n"
	.string "esperant ser trobats en aquest pis.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que queden dos objectes\n"
	.string "esperant ser trobats en aquest pis.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que només queda un objecte\n"
	.string "esperant ser trobat en aquest pis.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Com va la teva reserva d'objectes?\p"
	.string "Crec que no queden més objectes\n"
	.string "esperant ser trobats en aquest pis.\l"
	.string "Cuida't!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha vuit objectes\n"
	.string "més al terra.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha set objectes\n"
	.string "més al terra.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha sis objectes\n"
	.string "més al terra.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha cinc objectes\n"
	.string "més al terra.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha quatre objectes\n"
	.string "més al terra.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha tres objectes\n"
	.string "més al terra.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha dos objectes\n"
	.string "més al terra.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que només queda un objecte\n"
	.string "més al terra.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que no queden més objectes\n"
	.string "al terra.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha vuit objectes…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha set objectes…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha sis objectes…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha cinc objectes…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha quatre objectes…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha tres objectes…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha dos objectes…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que hi ha un objecte…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "En aquest pis de la PIRÀMIDE,\n"
	.string "he sentit que no hi ha objectes…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha vuit objectes més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha set objectes més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha sis objectes més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha cinc objectes més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha quatre objectes més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha tres objectes més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha dos objectes més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que hi ha un objecte més\n"
	.string "en aquest pis.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que no queden més objectes\n"
	.string "en aquest pis.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "Però encara queden set\n"
	.string "ENTRENADORS durs a part de mi!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "Però encara queden sis\n"
	.string "ENTRENADORS durs a part de mi!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "Però encara queden cinc\n"
	.string "ENTRENADORS durs a part de mi!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "Però encara queden quatre\n"
	.string "ENTRENADORS durs a part de mi!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "Però encara queden tres\n"
	.string "ENTRENADORS durs a part de mi!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "Però encara queden dos\n"
	.string "ENTRENADORS durs a part de mi!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "Però encara queda un\n"
	.string "ENTRENADOR dur a part de mi!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Has estat increïble!\p"
	.string "No queda ningú que et\n"
	.string "pugui derrotar!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però queden set ENTRENADORS!\n"
	.string "Algú et posarà al teu lloc!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però queden sis ENTRENADORS!\n"
	.string "Algú et posarà al teu lloc!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però queden cinc ENTRENADORS!\n"
	.string "Algú et posarà al teu lloc!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però queden quatre ENTRENADORS!\n"
	.string "Algú et posarà al teu lloc!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però queden tres ENTRENADORS!\n"
	.string "Algú et posarà al teu lloc!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però queden dos ENTRENADORS!\n"
	.string "Algú et posarà al teu lloc!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però queda un ENTRENADOR!\n"
	.string "Segur que et posarà al teu lloc!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Això és tan frustrant!\p"
	.string "Però no queden més ENTRENADORS\n"
	.string "que puguin enfrontar-se a tu!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Però hi ha set ENTRENADORS més\n"
	.string "en aquest pis. Els pots derrotar tots?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Però hi ha sis ENTRENADORS més\n"
	.string "en aquest pis. Els pots derrotar tots?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Però hi ha cinc ENTRENADORS més\n"
	.string "en aquest pis. Els pots derrotar tots?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Però hi ha quatre ENTRENADORS més\n"
	.string "en aquest pis. Els pots derrotar tots?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Però hi ha tres ENTRENADORS més\n"
	.string "en aquest pis. Els pots derrotar tots?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Però hi ha dos ENTRENADORS més\n"
	.string "en aquest pis. Els pots derrotar?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Però encara queda un ENTRENADOR\n"
	.string "en aquest pis. Pots guanyar?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Molt impressionant!\p"
	.string "Has derrotat tots els ENTRENADORS\n"
	.string "d'aquest pis.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Potser podries escombar els\n"
	.string "set ENTRENADORS que queden aquí.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Potser podries escombar els\n"
	.string "sis ENTRENADORS que queden aquí.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Potser podries escombar els\n"
	.string "cinc ENTRENADORS que queden aquí.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Potser podries escombar els\n"
	.string "quatre ENTRENADORS que queden aquí.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Potser podries escombar els\n"
	.string "tres ENTRENADORS que queden aquí.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Potser podries escombar els\n"
	.string "dos ENTRENADORS que queden aquí.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Potser podries completar l'escombrada\n"
	.string "amb l'ENTRENADOR que queda aquí.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "No queda ningú que et\n"
	.string "pugui derrotar ara…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Potser tens el que cal per derrotar\n"
	.string "els set ENTRENADORS experts que queden.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Potser tens el que cal per derrotar\n"
	.string "els sis ENTRENADORS experts que queden.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Potser tens el que cal per derrotar\n"
	.string "els cinc ENTRENADORS experts que queden.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Potser tens el que cal per derrotar\n"
	.string "els quatre ENTRENADORS experts que queden.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Potser tens el que cal per derrotar\n"
	.string "els tres ENTRENADORS experts que queden.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Potser tens el que cal per derrotar\n"
	.string "els dos ENTRENADORS experts que queden.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Potser tens el que cal per derrotar\n"
	.string "l'ENTRENADOR expert que queda.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Les teves habilitats són impecables.\p"
	.string "No queden més ENTRENADORS aquí\n"
	.string "amb cap oportunitat de guanyar-te.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Pots continuar guanyant contra\n"
	.string "els set ENTRENADORS restants?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Pots continuar guanyant contra\n"
	.string "els sis ENTRENADORS restants?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Pots continuar guanyant contra\n"
	.string "els cinc ENTRENADORS restants?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Pots continuar guanyant contra\n"
	.string "els quatre ENTRENADORS restants?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Pots continuar guanyant contra\n"
	.string "els tres ENTRENADORS restants?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Pots continuar guanyant contra\n"
	.string "els dos ENTRENADORS restants?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Pots continuar guanyant contra\n"
	.string "l'últim ENTRENADOR restant?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "No queda cap ENTRENADOR que\n"
	.string "pugui enfrontar-se a tu ara…$"
