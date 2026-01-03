LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Oh, vaja! Viatges sol?\n"
	.string "Però ets tan jove! Ben fet!\p"
	.string "Estic segura que els meus fills\n"
	.string "podrien aprendre alguna cosa de tu!\p"
	.string "Jo? Sóc una mestra dels {POKEBLOCK}S.\p"
	.string "Si m'hi poso una miqueta, doncs,\n"
	.string "puc preparar grans {POKEBLOCK}S.\p"
	.string "T'agradaria aprendre de mi,\n"
	.string "una mestra dels {POKEBLOCK}S?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh? N'estàs segur?\p"
	.string "No hauries d'intentar fer-ho sempre\n"
	.string "tot tu sol, estimat!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh, bé! Ets molt llest!\n"
	.string "Això és una mica llarg, escolta bé!\p"
	.string "Estàs preparat?\p"
	.string "Si mires els {POKEBLOCK}S, veuràs\n"
	.string "que es puntuen segons la seva textura.\p"
	.string "Com més baixa la textura,\n"
	.string "millor és. No ho oblidis!\p"
	.string "Un bon {POKEBLOCK} té una textura\n"
	.string "baixa i un nivell alt.\p"
	.string "Un POKéMON pot menjar més {POKEBLOCK}S\n"
	.string "bons que els normals, a més.\p"
	.string "I això és important.\p"
	.string "Si vols fer {POKEBLOCK}S suaus,\n"
	.string "usa diferents tipus de BAIES.\p"
	.string "No siguis garrepa; els tipus de BAIES\n"
	.string "afecten la suavitat dels {POKEBLOCK}S.\p"
	.string "I una altra cosa.\p"
	.string "Com més gent barrejant BAIES,\n"
	.string "més suaus els {POKEBLOCK}S.\p"
	.string "Per això hauries de parlar amb altra\n"
	.string "gent i fer {POKEBLOCK}S junts.\p"
	.string "Això és tot el que necessites saber per\n"
	.string "fer bons {POKEBLOCK}S.\p"
	.string "Si tothom tingués POKéMON que estimen,\n"
	.string "{POKEBLOCK}S suaus i una família amorosa,\l"
	.string "el món seria un lloc més feliç.\p"
	.string "No et rendeixis, estimat!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Quan la meva dona va tenir quadrigèmins,\n"
	.string "pots apostar que em vaig sorprendre.\p"
	.string "Però, ara, veient-los jugar junts,\n"
	.string "em fa feliç.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Estem fent COMBATS MULTIPLES, però sé\n"
	.string "que jo guanyaré.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Ens agrada barrejar coses\n"
	.string "al RACÓ DELS RÈCORDS.\p"
	.string "Però què es barreja?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Farem super {POKEBLOCK}S\n"
	.string "amb una BATEDORA DE BAIES!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Vull presumir de com n'és de dur el meu\n"
	.string "POKéMON, així que entrarem junts\l"
	.string "a un CONCURS.$"

