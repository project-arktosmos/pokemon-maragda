MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Tota mena de criatures vaguen pels\n"
	.string "vessants del MT. PÍRA…\p"
	.string "No se sap què pot passar.\n"
	.string "Pren això. És pel teu bé.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Fes que un POKéMON porti aquesta\n"
	.string "PLACA NETA.\p"
	.string "Ajudarà a allunyar els POKéMON salvatges.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Has vingut a retre homenatge\n"
	.string "als esperits dels POKéMON difunts?\p"
	.string "Deus estimar molt els teus POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Aquest és el lloc de descans final\n"
	.string "del meu ZIGZAGOON. L'estimava molt…$"

