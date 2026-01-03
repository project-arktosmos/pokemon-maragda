MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Quan era jove, vaig viatjar pel món\n"
	.string "com a ENTRENADOR POKéMON.\p"
	.string "Ara que m'he tornat un vell carraca,\n"
	.string "la meva única diversió és veure\l"
	.string "combatre els ENTRENADORS joves.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "La porta sembla estar tancada.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un ENTRENADOR anomenat {STR_VAR_1}\n"
	.string "està visitant casa meva.\p"
	.string "T'agradaria desafiar\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "No combatràs? Estic decebut\n"
	.string "de no poder veure't combatre…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, molt bé, molt bé!\p"
	.string "Però la meva casa no és gaire sòlida.\p"
	.string "Puc demanar-vos que ho limiteu\n"
	.string "a un combat 3 contra 3?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Abans que combateu tots dos, hauríeu\n"
	.string "de guardar el vostre progrés.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Espero veure un bon combat!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Així que ha quedat en empat.\p"
	.string "Ha estat un combat brillant en el qual\n"
	.string "cap bàndol ha cedit ni un pas!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Això ha estat superlatiu!\p"
	.string "Ha estat com veure'm a mi mateix\n"
	.string "en la meva joventut!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, quina llàstima!\p"
	.string "Però ha estat un bon combat.\n"
	.string "Espero que guanyis la pròxima vegada.$"
