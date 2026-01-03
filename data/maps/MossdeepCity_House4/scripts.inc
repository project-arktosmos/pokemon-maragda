MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "El meu germanet diu que li agrada anar\n"
	.string "a buscar les BASES SECRETES de la gent.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "El meu germanet diu que li agrada\n"
	.string "visitar les BASES SECRETES de la gent\l"
	.string "i tenir combats POKéMON.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Has estat tu qui ha fet una BASE SECRETA\n"
	.string "a prop de {STR_VAR_1}?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "Hauries de fer una BASE SECRETA\n"
	.string "en algun lloc. La trobaré!$"

MossdeepCity_House4_Text_Skitty:
	.string "SKITTY: Miiiau?$"

