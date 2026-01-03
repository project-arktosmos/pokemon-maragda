SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Sí? Si busques en STERN,\n"
	.string "sóc jo.\p"
	.string "Ah! Aquestes han de ser les peces que\n"
	.string "vaig encarregar al SR. ROCA de DEVON.\p"
	.string "Gràcies! Fantàstic!\n"
	.string "Ara podem preparar l'expedició!$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hehehe, para!\n"
	.string "Ens quedarem aquestes peces!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPITÀ STERN: Q-què?\n"
	.string "Qui sou vosaltres?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Som l'EQUIP AQUA!\p"
	.string "El nostre CAP vol aquestes peces!\n"
	.string "Calla i dóna-les!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaaaah!\n"
	.string "Un nen m'ha guanyat!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, home, quin desastre…\n"
	.string "El CAP s'enfurismarà…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Bah, ploramiques!\n"
	.string "Deixa-m'ho a mi!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Què?!\n"
	.string "Jo també he perdut!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "I ara què? Si no aconseguim les peces,\n"
	.string "ens caurà una bona!\p"
	.string "Argh, no comptava que un nen\n"
	.string "entremaliador ens fes nosa!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "He vingut a veure per què tardeu tant\n"
	.string "a agafar unes peces, i vosaltres,\l"
	.string "ximples, us ha aturat un nen?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Som l'EQUIP AQUA,\n"
	.string "i estimem el mar!\p"
	.string "I jo sóc el líder de l'EQUIP AQUA,\n"
	.string "AQUILES!\p"
	.string "Per què interfereixes amb nosaltres?\p"
	.string "…No! No pot ser!\n"
	.string "No ets de l'EQUIP MAGMA?\p"
	.string "Espera, això no pot ser.\n"
	.string "No vas vestit així.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, persones… Tota vida depèn\n"
	.string "del mar.\p"
	.string "Per això, l'EQUIP AQUA es dedica a\n"
	.string "l'expansió del mar.\p"
	.string "No hi estàs d'acord? El que fem\n"
	.string "és una empresa magnífica.\p"
	.string "Ah, bé…\n"
	.string "Encara ets massa jove per entendre\l"
	.string "el nostre noble objectiu.\p"
	.string "Però, t'aviso, ni tan sols pensis\n"
	.string "en interferir amb els nostres plans.\p"
	.string "Les conseqüències et costaran\n"
	.string "molt cares!\p"
	.string "I no ho oblidis!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPITÀ STERN: Tu ets…\n"
	.string "Ah, d'acord, ets {PLAYER}{KUN}…\p"
	.string "En fi, ha estat una situació tensa!\n"
	.string "Gràcies per salvar-nos!\p"
	.string "Oh, sí, gairebé oblidava que fins i tot\n"
	.string "m'has portat les peces de DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPITÀ STERN: Ui!\n"
	.string "No hi ha temps a perdre!\p"
	.string "Hem de partir a la nostra expedició\n"
	.string "al fons del mar ben aviat.\p"
	.string "Gràcies de nou, però ara he de\n"
	.string "marxar!\p"
	.string "Pots passejar lliurement i veure\n"
	.string "les nostres instal·lacions.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "He vist una maqueta d'un vaixell aquí.\p"
	.string "M'ha recordat el VAIXELL ABANDONAT\n"
	.string "prop d'ALBUFERA…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "No t'atreveixis a córrer dins\n"
	.string "del MUSEU!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Uau, el submarí és increïble!\n"
	.string "Vull fer-hi un passeig!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“MOSTRA DE QUALITAT D'AIGUA 1,”\n"
	.string "diu l'etiqueta.\p"
	.string "El mar està tot connectat, però l'aigua\n"
	.string "sembla diferir segons la regió.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“MOSTRA DE QUALITAT D'AIGUA 2,”\n"
	.string "diu l'etiqueta.\p"
	.string "La salinitat de l'aigua de mar també\n"
	.string "difereix segons la regió?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Una pilota de goma s'expandeix\n"
	.string "i s'encongeix.\p"
	.string "“Al mar, el pes de l'aigua mateixa\n"
	.string "exerceix pressió.\p"
	.string "“En aigües poc profundes, la pressió\n"
	.string "no és gaire forta.\p"
	.string "“No obstant, en aigües molt profundes,\n"
	.string "la pressió pot arribar fins i tot a\l"
	.string "desenes de milers de tones en una àrea\l"
	.string "petita.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MODEL DE LA REGIÓ DE HOENN”\p"
	.string "És un diorama en miniatura de\n"
	.string "la regió de HOENN.\p"
	.string "On és LLAURAMAR aquí?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "És una exposició sobre el flux de\n"
	.string "l'aigua de mar.\p"
	.string "“Prop del fons del mar, l'aigua flueix\n"
	.string "a causa de diferències en factors com\l"
	.string "la temperatura i la salinitat.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "És una exposició sobre el flux de\n"
	.string "l'aigua de mar.\p"
	.string "“Cap a la superfície, l'aigua de mar\n"
	.string "flueix com corrents impulsats pel vent.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“EL FERRI S.S. TIDAL\p"
	.string "“Una rèplica a escala del vaixell\n"
	.string "en construcció a la DRASSANA STERN.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“SUBMARÍ EXPLORADOR 1\p"
	.string "“Una rèplica del submarí d'alt\n"
	.string "rendiment per explorar el fons marí.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“CÀPSULA SUBMERGIBLE\p"
	.string "“Una rèplica d'una càpsula compacta\n"
	.string "i no tripulada per explorar el fons marí.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“Una rèplica del transatlàntic de luxe\n"
	.string "que dona la volta al món.”$"

