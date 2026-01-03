SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PIRA…\p"
	.string "Al seu cim hi ha dos orbes col·locats\n"
	.string "un al costat de l'altre. Ho sabies?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Sí, dos orbes un al costat de l'altre…\p"
	.string "La visió d'ells junts…\n"
	.string "És d'alguna manera reconfortant…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Ah, sí?\n"
	.string "Potser hauries de visitar-ho i veure-ho…$"

