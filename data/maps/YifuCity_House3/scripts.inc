YifuCity_House3_MapScripts::
	.byte 0


YifuCity_House3_EggGirlsMom::
# 6 "data/maps/YifuCity_House3/scripts.pory"
	lock
# 7 "data/maps/YifuCity_House3/scripts.pory"
	faceplayer
# 8 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EggGirlsMom_Text_0
# 10 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_EggGirlsMom_Text_1
# 13 "data/maps/YifuCity_House3/scripts.pory"
	release
	return


YifuCity_House3_EventScript_Togepi::
# 17 "data/maps/YifuCity_House3/scripts.pory"
	lock
# 18 "data/maps/YifuCity_House3/scripts.pory"
	faceplayer
# 19 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_Togepi_Text_0
# 20 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_EventScript_Togepi_Text_1
# 23 "data/maps/YifuCity_House3/scripts.pory"
	playmoncry SPECIES_TOGEPI, CRY_MODE_NORMAL
# 24 "data/maps/YifuCity_House3/scripts.pory"
	waitmoncry
# 25 "data/maps/YifuCity_House3/scripts.pory"
	release
	end


YifuCity_House3_EventScript_EggGirl::
# 30 "data/maps/YifuCity_House3/scripts.pory"
	lock
# 31 "data/maps/YifuCity_House3/scripts.pory"
	faceplayer
# 33 "data/maps/YifuCity_House3/scripts.pory"
	compare VAR_EGG_SPECIES_GIVEN_TO_EGG_GIRL, SPECIES_NONE
	goto_if_ne YifuCity_House3_EventScript_EggGirl_2
# 37 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 38 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_EventScript_EggGirl_Text_1
YifuCity_House3_EventScript_EggGirl_1:
# 42 "data/maps/YifuCity_House3/scripts.pory"
	release
	return

YifuCity_House3_EventScript_EggGirl_2:
# 34 "data/maps/YifuCity_House3/scripts.pory"
	call YifuCity_House3_NotTradedYet
	goto YifuCity_House3_EventScript_EggGirl_1


YifuCity_House3_NotTradedYet::
# 46 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 47 "data/maps/YifuCity_House3/scripts.pory"
	special GetPlayerSirMissString
# 48 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_NotTradedYet_Text_0
# 52 "data/maps/YifuCity_House3/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_House3_NotTradedYet_Text_1, YifuCity_House3_NotTradedYet_Text_2, YifuCity_House3_NotTradedYet_Text_3, YifuCity_House3_NotTradedYet_Text_4
# 64 "data/maps/YifuCity_House3/scripts.pory"
	closemessage
# 66 "data/maps/YifuCity_House3/scripts.pory"
	switch VAR_RESULT
# 67 "data/maps/YifuCity_House3/scripts.pory"
	case 0, YifuCity_House3_NotTradedYet_3
# 75 "data/maps/YifuCity_House3/scripts.pory"
	case 1, YifuCity_House3_NotTradedYet_4
# 83 "data/maps/YifuCity_House3/scripts.pory"
	case 2, YifuCity_House3_NotTradedYet_5
# 90 "data/maps/YifuCity_House3/scripts.pory"
	case 3, YifuCity_House3_NotTradedYet_6
YifuCity_House3_NotTradedYet_1:
# 100 "data/maps/YifuCity_House3/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_House3_NotTradedYet_Text_9, YifuCity_House3_NotTradedYet_Text_10
# 110 "data/maps/YifuCity_House3/scripts.pory"
	closemessage
# 112 "data/maps/YifuCity_House3/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/YifuCity_House3/scripts.pory"
	case 0, YifuCity_House3_NotTradedYet_9
# 115 "data/maps/YifuCity_House3/scripts.pory"
	case 1, YifuCity_House3_NotTradedYet_10
YifuCity_House3_NotTradedYet_7:
# 122 "data/maps/YifuCity_House3/scripts.pory"
	release
	return

YifuCity_House3_NotTradedYet_3:
# 68 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 69 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_NotTradedYet_Text_5
	goto YifuCity_House3_NotTradedYet_1

YifuCity_House3_NotTradedYet_4:
# 76 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 77 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_NotTradedYet_Text_6
	goto YifuCity_House3_NotTradedYet_1

YifuCity_House3_NotTradedYet_5:
# 84 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 85 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_NotTradedYet_Text_7
# 88 "data/maps/YifuCity_House3/scripts.pory"
	release
	end

YifuCity_House3_NotTradedYet_6:
# 91 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 92 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_NotTradedYet_Text_8
	goto YifuCity_House3_NotTradedYet_1

YifuCity_House3_NotTradedYet_9:
# 114 "data/maps/YifuCity_House3/scripts.pory"
	call YifuCity_House3_TradeEgg
	goto YifuCity_House3_NotTradedYet_7

YifuCity_House3_NotTradedYet_10:
# 116 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 117 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_NotTradedYet_Text_7
	goto YifuCity_House3_NotTradedYet_7


YifuCity_House3_TradeEgg::
# 126 "data/maps/YifuCity_House3/scripts.pory"
	special ChoosePartyMon
# 127 "data/maps/YifuCity_House3/scripts.pory"
	waitstate
# 128 "data/maps/YifuCity_House3/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq YifuCity_House3_TradeEgg_1
# 133 "data/maps/YifuCity_House3/scripts.pory"
	special IsSelectedMonEgg
# 134 "data/maps/YifuCity_House3/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_House3_TradeEgg_4
# 153 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 154 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_TradeEgg_Text_3
# 155 "data/maps/YifuCity_House3/scripts.pory"
	closemessage
	return

YifuCity_House3_TradeEgg_1:
# 129 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 130 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_TradeEgg_Text_0
# 131 "data/maps/YifuCity_House3/scripts.pory"
	closemessage
	return

YifuCity_House3_TradeEgg_4:
# 135 "data/maps/YifuCity_House3/scripts.pory"
	specialvar VAR_EGG_SPECIES_GIVEN_TO_EGG_GIRL, ScriptGetPartyMonSpeciesEvenIfEgg
# 136 "data/maps/YifuCity_House3/scripts.pory"
	special DestroySelectedPartyMon
# 140 "data/maps/YifuCity_House3/scripts.pory"
	giveegg SPECIES_WYNAUT
# 141 "data/maps/YifuCity_House3/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 142 "data/maps/YifuCity_House3/scripts.pory"
	message YifuCity_House3_TradeEgg_Text_1
# 143 "data/maps/YifuCity_House3/scripts.pory"
	waitmessage
# 144 "data/maps/YifuCity_House3/scripts.pory"
	waitfanfare
# 146 "data/maps/YifuCity_House3/scripts.pory"
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
# 147 "data/maps/YifuCity_House3/scripts.pory"
	msgbox YifuCity_House3_TradeEgg_Text_2
# 151 "data/maps/YifuCity_House3/scripts.pory"
	closemessage
	return


YifuCity_House3_EggGirlsMom_Text_0:
# 8 "data/maps/YifuCity_House3/scripts.pory"
	.string "Woman$"

YifuCity_House3_EggGirlsMom_Text_1:
# 11 "data/maps/YifuCity_House3/scripts.pory"
	.string "I help out at the Pokémon daycare\n"
	.string "west of Windycape on tuesdays.\l"
	.string "Sometimes they'll let me bring back an\l"
	.string "egg for my daughter!$"

YifuCity_House3_EventScript_Togepi_Text_0:
# 19 "data/maps/YifuCity_House3/scripts.pory"
	.string "Togepi$"

YifuCity_House3_EventScript_Togepi_Text_1:
# 21 "data/maps/YifuCity_House3/scripts.pory"
	.string "Preee!$"

YifuCity_House3_EventScript_EggGirl_Text_0:
# 37 "data/maps/YifuCity_House3/scripts.pory"
	.string "Little girl$"

YifuCity_House3_EventScript_EggGirl_Text_1:
# 39 "data/maps/YifuCity_House3/scripts.pory"
	.string "Can't wait for my egg to hatch!$"

YifuCity_House3_NotTradedYet_Text_0:
# 49 "data/maps/YifuCity_House3/scripts.pory"
	.string "Hello {STR_VAR_1}! Do you like\n"
	.string "eggs?$"

YifuCity_House3_NotTradedYet_Text_1:
# 59 "data/maps/YifuCity_House3/scripts.pory"
	.string "Yes!$"

YifuCity_House3_NotTradedYet_Text_2:
# 60 "data/maps/YifuCity_House3/scripts.pory"
	.string "Yes, they're delicious!$"

YifuCity_House3_NotTradedYet_Text_3:
# 61 "data/maps/YifuCity_House3/scripts.pory"
	.string "Not really.$"

YifuCity_House3_NotTradedYet_Text_4:
# 62 "data/maps/YifuCity_House3/scripts.pory"
	.string "Eggs?$"

YifuCity_House3_NotTradedYet_Text_5:
# 70 "data/maps/YifuCity_House3/scripts.pory"
	.string "Really?! Me too!! Pokémon eggs are so\n"
	.string "cool!\l"
	.string "I love not knowing what will jump out\l"
	.string "of the egg!\p"
	.string "Wanna trade me a mystery egg for a\n"
	.string "mystery egg?\l"
	.string "That way we'll both have a surprise!$"

YifuCity_House3_NotTradedYet_Text_6:
# 78 "data/maps/YifuCity_House3/scripts.pory"
	.string "WHAT? Ewww, gross! I don't mean\n"
	.string "EATING them!\p"
	.string "I just love waiting for a Pokémon to\n"
	.string "jump of of its egg, especially when I\l"
	.string "have no idea what it's gonna be!\p"
	.string "Wanna trade me a mystery egg for a\n"
	.string "mystery egg?\l"
	.string "That way we'll both have a surprise!$"

YifuCity_House3_NotTradedYet_Text_7:
# 86 "data/maps/YifuCity_House3/scripts.pory"
	.string "Oh… Alright…$"

YifuCity_House3_NotTradedYet_Text_8:
# 93 "data/maps/YifuCity_House3/scripts.pory"
	.string "Eggs! Pokémon eggs! I just love\n"
	.string "waiting for a Pokémon to jump of of\l"
	.string "its egg, especially when I have no\l"
	.string "idea what it's gonna be!\p"
	.string "Wanna trade me a mystery egg for a\n"
	.string "mystery egg?\l"
	.string "That way we'll both have a surprise!$"

YifuCity_House3_NotTradedYet_Text_9:
# 107 "data/maps/YifuCity_House3/scripts.pory"
	.string "Sure!$"

YifuCity_House3_NotTradedYet_Text_10:
# 108 "data/maps/YifuCity_House3/scripts.pory"
	.string "No.$"

YifuCity_House3_TradeEgg_Text_0:
# 130 "data/maps/YifuCity_House3/scripts.pory"
	.string "Have you changed your mind?$"

YifuCity_House3_TradeEgg_Text_1:
# 142 "data/maps/YifuCity_House3/scripts.pory"
	.string "{PLAYER} received the mysterious\n"
	.string "egg!$"

YifuCity_House3_TradeEgg_Text_2:
# 148 "data/maps/YifuCity_House3/scripts.pory"
	.string "Yay!!! I can't wait for my egg to\n"
	.string "hatch!\p"
	.string "Aren't you wondering what you're\n"
	.string "gonna get?$"

YifuCity_House3_TradeEgg_Text_3:
# 154 "data/maps/YifuCity_House3/scripts.pory"
	.string "That's not an egg, you silly!$"
