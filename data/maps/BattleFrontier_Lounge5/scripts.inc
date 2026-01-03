BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Ehehe!\n"
	.string "Puc dir què pensen els POKéMON!\p"
	.string "Siusplau!\n"
	.string "Puc veure els teus POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Buu!\n"
	.string "Garrepa!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Combatria encara que tingui\l"
	.string "molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada ser astut!\n"
	.string "Però si rep prou ais,\l"
	.string "tornarà el cop!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Però si rep prou ais,\l"
	.string "es preocuparà per ell mateix!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Combatria encara que tingui\l"
	.string "molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Aquest diu que es cuida a si mateix!\n"
	.string "Però si rep prou ais,\l"
	.string "tornarà el cop!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada ser astut!\n"
	.string "Però si rep prou ais,\l"
	.string "es preocuparà per ell mateix!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Combatria encara que tingui\l"
	.string "molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada ser astut!\n"
	.string "Però si rep prou ais,\l"
	.string "tornarà el cop!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Però si rep prou ais,\l"
	.string "es preocuparà per ell mateix!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada ser astut!\n"
	.string "Diu que li agrada ser astut encara\l"
	.string "que tingui molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Però si rep prou ais,\l"
	.string "es tornarà astut!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Combatria encara que tingui\l"
	.string "molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada ser astut!\n"
	.string "Diu que li agrada ser astut encara\l"
	.string "que tingui molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada ser astut!\n"
	.string "Però si rep prou ais,\l"
	.string "es preocuparà per ell mateix!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm…\p"
	.string "Aquest diu que es cuida a si mateix!\n"
	.string "Diu que es preocupa per ell mateix\l"
	.string "tant si té molts ais com si no!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm…\p"
	.string "Aquest diu que es cuida a si mateix!\n"
	.string "Però si rep prou ais,\l"
	.string "es tornarà astut!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm…\p"
	.string "Aquest diu que es cuida a si mateix!\n"
	.string "Diu que es preocupa per ell mateix\l"
	.string "encara que tingui molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada ser astut!\n"
	.string "Diu que li agrada ser astut encara\l"
	.string "que tingui molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm…\p"
	.string "Aquest diu que es cuida a si mateix!\n"
	.string "Diu que es preocupa per ell mateix\l"
	.string "encara que tingui molts ais!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Aquest diu que es cuida a si mateix!\n"
	.string "Però si rep prou ais,\l"
	.string "tornarà el cop!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Aquest diu que li agrada combatre!\n"
	.string "Però si rep prou ais,\l"
	.string "es tornarà astut!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm…\p"
	.string "Aquest diu que es cuida a si mateix!\n"
	.string "Però si rep prou ais,\l"
	.string "es tornarà astut!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Quin ximple! Un OU dorm!\n"
	.string "No puc parlar amb ell!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Que encantador!\n"
	.string "Aquesta petita diu que pot\l"
	.string "entendre els POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Tinc la sensació que la nena\n"
	.string "diu alguna cosa profunda.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Sé una cosa!\p"
	.string "Aquella nena juga molt a la casa\n"
	.string "vermella!$"

