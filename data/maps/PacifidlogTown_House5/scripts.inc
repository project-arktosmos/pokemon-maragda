PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "No puc veure l'ILLA MIRATGE avui…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Oh, déu meu!\n"
	.string "Puc veure l'ILLA MIRATGE avui!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "L'ILLA MIRATGE…\p"
	.string "Deu fer-se visible i invisible\n"
	.string "depenent de les condicions climàtiques\l"
	.string "que fan aparèixer els miratges.\p"
	.string "O realment està apareixent i\n"
	.string "desapareixent?$"

