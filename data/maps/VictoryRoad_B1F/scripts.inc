VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Pensar que m'estic acostant\n"
	.string "a la LLIGA POKéMON…\p"
	.string "Em fa una mica de por…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "No he pogut fer res…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "La LLIGA POKéMON s'ha allunyat\n"
	.string "un altre cop… Quina decepció…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Per guanyar a la LLIGA POKéMON,\n"
	.string "necessites la confiança dels teus\l"
	.string "POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "La teva relació es basa en una\n"
	.string "confiança sòlida.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Estant junts tot el temps, la confiança\n"
	.string "creix entre POKéMON i ENTRENADORS.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Això no és la meta. És només un lloc\n"
	.string "de camí a la LLIGA POKéMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Així es fa!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Ho faràs bé, de segur!\n"
	.string "Els teus POKéMON estan impacients!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Els meus POKéMON són còsmicament\n"
	.string "impressionants!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Mai havia conegut ningú com tu.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Fins i tot fora de combat, sento\n"
	.string "un poder increïble que emana de tu\l"
	.string "i dels teus POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "D'acord, no cal estar tan tens!\n"
	.string "Relaxa't, anem amb calma!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Vaja!\n"
	.string "Meravellós!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Sí, això és el CAMÍ DE LA VICTÒRIA.\p"
	.string "Però no és tan diferent del camí\n"
	.string "que has recorregut fins ara.\p"
	.string "Intenta gaudir de la resta\n"
	.string "del trajecte!$"

