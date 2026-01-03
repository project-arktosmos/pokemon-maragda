SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Ets ENTRENADOR POKéMON, oi?\p"
	.string "JAUME d'ALGÈPOLIS té molts fans.\n"
	.string "Fins i tot més que el seu estudiant BLASCO!\p"
	.string "Tu en tens?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, llavors deus ser força fort.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, vaja…\n"
	.string "Això és una mica solitari.\p"
	.string "Intenta esforçar-te una mica més per\n"
	.string "aconseguir seguidors.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Els fans més fidels venen fins i tot\n"
	.string "de fora de HOENN.\p"
	.string "Era molt boig quan vaig anar al\n"
	.string "CLUB DE FANS D'ENTRENADORS a CALAGUA.$"

