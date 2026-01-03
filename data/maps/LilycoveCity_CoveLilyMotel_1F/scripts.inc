LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, han doblat els clients utilitzant\n"
	.string "POKéMON com a atraccions?\p"
	.string "Hm, bé, potser hauria de fer d'un\n"
	.string "POKéMON bufó la mascota de la fonda.\p"
	.string "Em pregunto si això atraurà més\n"
	.string "clients a quedar-se amb nosaltres?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, perdona, perdona!\n"
	.string "Estava massa absort mirant la tele!\p"
	.string "Des que l'EQUIP AQUA va arribar,\n"
	.string "els turistes s'han mantingut lluny.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Ei, aparta't!\n"
	.string "No puc veure la tele!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Increïble! Em dius que un POKéMON\n"
	.string "ha trobat un objecte perdut d'algú?\p"
	.string "Això és alguna cosa. Si tinguéssim\n"
	.string "POKéMON llestos com aquest…\p"
	.string "Podríem recuperar qualsevol cosa que\n"
	.string "els nostres clients haguessin perdut…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, perdona, perdona!\n"
	.string "Estava massa absort mirant la tele!\p"
	.string "He sentit que algú ha enfonsat\n"
	.string "l'AMAGATALL DE L'EQUIP AQUA.\p"
	.string "Gràcies a això, acabem de reservar\n"
	.string "un grup gran.\p"
	.string "Era una empresa anomenada… Eh…\n"
	.string "GAME alguna cosa…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Increïble! Un POKéMON guardià de casa\n"
	.string "ha atrapat un lladre?\p"
	.string "Això és alguna cosa. Si tinguéssim un\n"
	.string "POKéMON dur com a guàrdia de seguretat…\p"
	.string "Podríem oferir als nostres clients\n"
	.string "més seguretat.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, perdona, perdona!\n"
	.string "Estava massa absort mirant la tele.\p"
	.string "Oh, sí. Un grup gran de clients va\n"
	.string "arribar fa una estona.\p"
	.string "Han reservat com a GAME FREAK,\n"
	.string "així que deuen fer videojocs.\p"
	.string "Ui, millor que em posi a preparar\n"
	.string "el seu sopar!$"

