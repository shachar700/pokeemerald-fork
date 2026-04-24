BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
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
	.string "איהיהי!\n"
	.string "אני יכולה לדעת מה הפוקימונים חושבים!\p"
	.string "בבקשה!\n"
	.string "אפשר לראות את הפוקימון שלך?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "בוו!\n"
	.string "קמצ{SWAP_NUN}{ADD_YUD}{ADD_TAF}!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "הוא יילחם גם אם יש לו הרבה\l"
	.string "אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להתגנב!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יכה בחזרה!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא ידאג לעצמו!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "הוא יילחם גם אם יש לו הרבה\l" 
	.string "אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "המהמ…\p"
	.string "הוא אומר שהוא דואג לעצמו!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יכה בחזרה!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להתגנב!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא ידאג לעצמו!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "הוא יילחם גם אם יש לו הרבה\l"
	.string "אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להתגנב!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יכה בחזרה!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא ידאג לעצמו!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להתגנב!\n"
	.string "הוא אומר שהוא אוהב להתגנב גם\l"
	.string "אם יש לו הרבה אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יהפוך למתגנב!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "הוא יילחם גם אם יש לו הרבה\l"
	.string "אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להתגנב!\n"
	.string "הוא אומר שהוא אוהב להתגנב גם\l"
	.string "אם יש לו הרבה אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להתגנב!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא ידאג לעצמו!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "המהמ…\p"
	.string "הוא אומר שהוא דואג לעצמו!\n"
	.string "הוא אומר שהוא דואג לעצמו בין\l"
	.string "אם יש לו הרבה אאוצ'יז ובין אם לאו!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "המהמ…\p"
	.string "הוא אומר שהוא דואג לעצמו!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יהפוך למתגנב!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "המהמ…\p"
	.string "הוא אומר שהוא דואג לעצמו!\n"
	.string "הוא אומר שהוא דואג לעצמו גם\l"
	.string "אם יש לו הרבה אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להתגנב!\n"
	.string "הוא אומר שהוא אוהב להתגנב גם\l"
	.string "אם יש לו הרבה אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "המהמ…\p"
	.string "הוא אומר שהוא דואג לעצמו!\n"
	.string "הוא אומר שהוא דואג לעצמו גם\l"
	.string "אם יש לו הרבה אאוצ'יז!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "המהמ…\p"
	.string "הוא אומר שהוא דואג לעצמו!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יכה בחזרה!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "המהמ…\p"
	.string "הוא אומר שהוא אוהב להילחם!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יהפוך למתגנב!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "המהמ…\p"
	.string "הוא אומר שהוא דואג לעצמו!\n"
	.string "אבל אם הוא יקבל מספיק אאוצ'יז,\l"
	.string "הוא יהפוך למתגנב!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "זה מטופש! ביצה ישנה!\n"
	.string "אני לא יכולה לדבר איתה!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "איזה מקסים!\n"
	.string "הגברת הקטנה הזו טוענת שהיא יכולה\l"
	.string "להבין פוקימונים!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "יש לי הרגשה שהילדה הקטנה\n"
	.string "אומרת משהו עמוק.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "אני יודע משהו!\p"
	.string "הילדה הקטנה הזו משחקת הרבה\n"
	.string "בבית האדום!$"
