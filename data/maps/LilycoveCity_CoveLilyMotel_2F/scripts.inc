LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Sóc el DISSENYADOR DE JOCS.\p"
	.string "Oh, és així?\n"
	.string "Estàs treballant en una POKéDEX?\p"
	.string "És difícil intentar completar-la,\n"
	.string "però no et rendeixis.\p"
	.string "Si la completes, si us plau vine\n"
	.string "a ensenyar-me-la.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Uau! Això és impressionant!\n"
	.string "Sí, és totalment impressionant!\p"
	.string "Aquesta POKéDEX està completament plena!\n"
	.string "Realment deus estimar els POKéMON!\p"
	.string "Estic tan impressionat!\p"
	.string "Deixa'm donar-te alguna cosa en\n"
	.string "reconeixement de la teva fita!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Jo? M'estàs parlant a mi?\n"
	.string "Sóc el PROGRAMADOR.\p"
	.string "Em pregunto com són les MÀQUINES\n"
	.string "ESCURABUTXAQUES d'aquí.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Sóc el DISSENYADOR GRÀFIC! No són\n"
	.string "interessants els POKéMON de HOENN?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Les noies TUBERES, són bufones, eh?\n"
	.string "Combatre contra una TUBERA bufona…\p"
	.string "Uf, és genial!\p"
	.string "I les BESSONES! No són bufones?\n"
	.string "Un combat 2 contra 2 amb BESSONES…\p"
	.string "Uf, és increïblement divertit!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brisa marina m'acaricia el cor.\n"
	.string "Aquí s'hi està meravellosament!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Mai se sap quan i on\n"
	.string "et desafiaran.\p"
	.string "Per això mai surto de casa sense\n"
	.string "la meva GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Eh?!\n"
	.string "Oh, perdona, perdona! Estava dormint!\p"
	.string "He vingut a veure això del\n"
	.string "CONCURS POKéMON.\p"
	.string "He d'admetre que sembla força\n"
	.string "entretingut, però…\p"
	.string "Considera'm un purista: prefereixo\n"
	.string "els combats i els ENTRENADORS durs.\p"
	.string "Però això és cosa meva.\p"
	.string "{PLAYER}{KUN}, espero que gaudeixis de tot,\n"
	.string "com els GIMNASOS, CONCURSOS, CARPA,\l"
	.string "tot el conjunt!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Crec que sí que cal estratègia\n"
	.string "per guanyar un CONCURS.\p"
	.string "Idear estratègies de CONCURS és una\n"
	.string "manera de ser millor ENTRENADOR, diria.$"

