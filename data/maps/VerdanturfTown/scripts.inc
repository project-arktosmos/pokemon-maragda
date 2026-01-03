VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "El meu papa m'ho va dir.\p"
	.string "Diu que aquest túnel està ple de\n"
	.string "POKéMON tímids.\p"
	.string "S'espanten amb el soroll fort i\n"
	.string "fan un gran enrenou.\p"
	.string "Per això van haver d'aturar el gran\n"
	.string "projecte del túnel.\p"
	.string "Però hi ha un home. Està intentant\n"
	.string "excavar el túnel ell tot sol!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Hi havia un home que va excavar un\n"
	.string "túnel per una dona que estimava.\p"
	.string "No ho entenc del tot, però bé!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Per la direcció dels vents, la cendra\n"
	.string "volcànica mai arriba aquí.\p"
	.string "L'aire és net i deliciós aquí.\n"
	.string "Viure aquí fa miracles fins i tot per\l"
	.string "a persones fràgils i malaltisses.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Els meus POKéMON i jo, hem tingut\n"
	.string "una gran ratxa de victòries.\p"
	.string "Així que he decidit debutar a la TENDA\n"
	.string "COMBAT d'aquest poble.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Has vist la cova al costat de la\n"
	.string "BOTIGA POKéMON?\p"
	.string "Hi ha un home que intenta trencar\n"
	.string "les roques per passar a l'altre\l"
	.string "costat.\p"
	.string "Seria genial si poguéssim passar…\n"
	.string "Seria fàcil anar a FERRERICA.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Aquella cova al costat de la BOTIGA\n"
	.string "POKéMON ara és un túnel a l'altre costat.\p"
	.string "És genial--ara és fàcil anar a comprar\n"
	.string "productes nous de DEVON a FERRERICA.$"

VerdanturfTown_Text_TownSign:
	.string "POBLE VERDANTURF\p"
	.string "“Les terres altes ventoses amb la\n"
	.string "dolça fragància de l'herba.”$"

VerdanturfTown_Text_WandasHouse:
	.string "CASA DE LA WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "TENDA COMBAT SEU VERDANTURF\n"
	.string "“Deleiteu-vos amb els combats!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TÚNEL FERRIFRESC\n"
	.string "“Connectant FERRERICA i VERDANTURF\p"
	.string "“El projecte del túnel ha estat\n"
	.string "cancel·lat.”$"

