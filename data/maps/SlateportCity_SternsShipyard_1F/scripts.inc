SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Hmm… Si això va aquí, i allò\n"
	.string "va allà…\p"
	.string "Llavors on va aquesta cosa?\n"
	.string "I què passa amb aquell trasto?\p"
	.string "Aaargh! No hi entenc res\n"
	.string "de res!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm?\n"
	.string "Hola, sóc en MOLL.\p"
	.string "El CAPITÀ STERN m'ha encarregat\n"
	.string "dissenyar un ferri.\p"
	.string "Oh! Això d'aquí…\n"
	.string "Són PAQUETS DEVON?\p"
	.string "Però, hmm…\n"
	.string "Això no pot ser…\p"
	.string "El CAPITÀ STERN ha marxat a algun lloc.\n"
	.string "Ha dit que tenia feina a fer.\p"
	.string "Podries anar a trobar el CAPITÀ\n"
	.string "STERN i entregar-li això?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "MOLL: On deu haver anat el\n"
	.string "CAPITÀ STERN?\p"
	.string "Podries anar a trobar el CAPITÀ STERN\n"
	.string "i entregar-li el paquet?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "MOLL: Construir vaixells és un art.\p"
	.string "Moltes coses no es poden esbrinar\n"
	.string "només calculant.\p"
	.string "Realment m'aniria bé el consell d'un\n"
	.string "veterà que conegui els mars…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "MOLL: Hola! El SR. AIMAR s'ha unit a\n"
	.string "nosaltres per ajudar-nos.\p"
	.string "Gràcies al mariner veterà, el\n"
	.string "ferri va agafant forma.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "MOLL: El ferri finalment està llest!\p"
	.string "El nou S.S. TIDAL és veritablement\n"
	.string "una meravella de la tecnologia!\p"
	.string "Però, tinc la sensació que podem\n"
	.string "fer alguna cosa encara millor.\p"
	.string "Ja saps, la tecnologia mai\n"
	.string "deixa d'avançar.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "SR. AIMAR: Ah, {PLAYER}{KUN}!\n"
	.string "Quant de temps!\p"
	.string "Sí, des que et vaig conèixer, aquest\n"
	.string "vell llop de mar s'ha sentit animat!\p"
	.string "Així que he decidit ajudar en MOLL\n"
	.string "a fer un ferri.\p"
	.string "Sí, al cap i a la fi, un ferri pot\n"
	.string "transportar molta gent.\p"
	.string "Però, saps, en MOLL és realment\n"
	.string "algú especial.\p"
	.string "Amb la seva destresa tecnològica i\n"
	.string "la meva experiència, estic segur que\l"
	.string "podem construir un gran vaixell!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Les estacions, el temps, on es troba\n"
	.string "la lluna al cel…\p"
	.string "Aquestes i altres condicions fan\n"
	.string "que el mar canviï d'expressió.\p"
	.string "Així és!\n"
	.string "El mar és com un ésser viu!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Em marejo molt fàcilment.\n"
	.string "Així que ajudo aquí en comptes.$"

