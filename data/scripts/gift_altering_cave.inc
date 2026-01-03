MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Gràcies per usar el Sistema de\n"
	.string "REGAL MISTERI.\p"
	.string "Sembla que hi ha un rumor sobre\n"
	.string "avistaments de POKéMON rars.\p"
	.string "Segons diuen, els avistaments van ser\n"
	.string "a la COVA CANVIANT de la RUTA 103.\p"
	.string "Potser valdria la pena que\n"
	.string "investiguessis aquest rumor.$"
