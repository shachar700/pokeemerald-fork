WindsweptRoute_MapScripts::
	.byte 0


WindsweptRoute_EventScript_OvergrownTrees::
# 7 "data/maps/WindsweptRoute/scripts.pory"
	lock
# 8 "data/maps/WindsweptRoute/scripts.pory"
	faceplayer
# 9 "data/maps/WindsweptRoute/scripts.pory"
	goto_if_set FLAG_CUT_TREE_SILVER_TUNNEL, WindsweptRoute_EventScript_OvergrownTrees_2
# 14 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_OvergrownTrees_Text_1
WindsweptRoute_EventScript_OvergrownTrees_1:
# 19 "data/maps/WindsweptRoute/scripts.pory"
	release
	return

WindsweptRoute_EventScript_OvergrownTrees_2:
# 10 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_OvergrownTrees_Text_0
	goto WindsweptRoute_EventScript_OvergrownTrees_1


WindsweptRoute_EventScript_Trainer1::
# 23 "data/maps/WindsweptRoute/scripts.pory"
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
# 28 "data/maps/WindsweptRoute/scripts.pory"
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
# 29 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer2::
# 34 "data/maps/WindsweptRoute/scripts.pory"
	trainerbattle_single TRAINER_ITAMAE, WindsweptRoute_EventScript_Trainer2_Text_0, WindsweptRoute_EventScript_Trainer2_Text_1
# 39 "data/maps/WindsweptRoute/scripts.pory"
	speakername WindsweptRoute_EventScript_Trainer2_Text_2
# 40 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_Trainer2_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer3::
# 45 "data/maps/WindsweptRoute/scripts.pory"
	trainerbattle_single TRAINER_MAKOTO_1, WindsweptRoute_EventScript_Trainer3_Text_0, WindsweptRoute_EventScript_Trainer3_Text_1
# 50 "data/maps/WindsweptRoute/scripts.pory"
	speakername WindsweptRoute_EventScript_Trainer3_Text_2
# 51 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_Trainer3_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Fisherman_ShortRod::
# 56 "data/maps/WindsweptRoute/scripts.pory"
	lock
# 57 "data/maps/WindsweptRoute/scripts.pory"
	faceplayer
# 58 "data/maps/WindsweptRoute/scripts.pory"
	speakername WindsweptRoute_EventScript_Fisherman_ShortRod_Text_0
# 59 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_Fisherman_ShortRod_Text_1
# 63 "data/maps/WindsweptRoute/scripts.pory"
	closemessage
# 64 "data/maps/WindsweptRoute/scripts.pory"
	release
	return


WindsweptRoute_EventScript_Trainer4::
# 68 "data/maps/WindsweptRoute/scripts.pory"
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
# 73 "data/maps/WindsweptRoute/scripts.pory"
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
# 74 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer5::
# 79 "data/maps/WindsweptRoute/scripts.pory"
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
# 84 "data/maps/WindsweptRoute/scripts.pory"
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
# 85 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer6::
# 90 "data/maps/WindsweptRoute/scripts.pory"
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
# 95 "data/maps/WindsweptRoute/scripts.pory"
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
# 96 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_OvergrownTrees_Text_0:
# 11 "data/maps/WindsweptRoute/scripts.pory"
	.string "Thank you for cutting down that\n"
	.string "annoying tree! We can go to Silveridge\l"
	.string "again now!$"

WindsweptRoute_EventScript_OvergrownTrees_Text_1:
# 15 "data/maps/WindsweptRoute/scripts.pory"
	.string "The weeds got out of control here,\n"
	.string "and some trees now block the way to\l"
	.string "Silver Tunnel…\p"
	.string "Someone'll eventually have to ask for\n"
	.string "help from the old Cut master on\l"
	.string "Tranquil route…$"

WindsweptRoute_EventScript_Trainer1_Text_0:
# 25 "data/maps/WindsweptRoute/scripts.pory"
	.string "These winds blow as strong as my will\n"
	.string "to win!$"

WindsweptRoute_EventScript_Trainer1_Text_1:
# 26 "data/maps/WindsweptRoute/scripts.pory"
	.string "You blew us away!$"

WindsweptRoute_EventScript_Trainer1_Text_2:
# 28 "data/maps/WindsweptRoute/scripts.pory"
	.string "Musashi$"

WindsweptRoute_EventScript_Trainer1_Text_3:
# 29 "data/maps/WindsweptRoute/scripts.pory"
	.string "I come here to train my Pokémon. The\n"
	.string "harsh weather helps us give the best\l"
	.string "of ourselves.$"

WindsweptRoute_EventScript_Trainer2_Text_0:
# 36 "data/maps/WindsweptRoute/scripts.pory"
	.string "I'm scouring this salty grass for the\n"
	.string "tastiest ingredients!$"

WindsweptRoute_EventScript_Trainer2_Text_1:
# 37 "data/maps/WindsweptRoute/scripts.pory"
	.string "Bitter is the taste of defeat…$"

WindsweptRoute_EventScript_Trainer2_Text_2:
# 39 "data/maps/WindsweptRoute/scripts.pory"
	.string "Itamae$"

WindsweptRoute_EventScript_Trainer2_Text_3:
# 40 "data/maps/WindsweptRoute/scripts.pory"
	.string "This place is an inspiration for my\n"
	.string "innovative cuisine.\p"
	.string "The rocks are salty, the plants are\n"
	.string "salty… To an extent, even the air is\l"
	.string "salty.$"

WindsweptRoute_EventScript_Trainer3_Text_0:
# 47 "data/maps/WindsweptRoute/scripts.pory"
	.string "These cliffs are so damn tall! Good\n"
	.string "thing I have a damn long fishing rod.$"

WindsweptRoute_EventScript_Trainer3_Text_1:
# 48 "data/maps/WindsweptRoute/scripts.pory"
	.string "My rod didn't keep me from losing…$"

WindsweptRoute_EventScript_Trainer3_Text_2:
# 50 "data/maps/WindsweptRoute/scripts.pory"
	.string "Makoto$"

WindsweptRoute_EventScript_Trainer3_Text_3:
# 51 "data/maps/WindsweptRoute/scripts.pory"
	.string "Look at that poor sod over there! His\n"
	.string "fishing rod's so short, I can't help\l"
	.string "but laugh!$"

WindsweptRoute_EventScript_Fisherman_ShortRod_Text_0:
# 58 "data/maps/WindsweptRoute/scripts.pory"
	.string "Fisherman$"

WindsweptRoute_EventScript_Fisherman_ShortRod_Text_1:
# 60 "data/maps/WindsweptRoute/scripts.pory"
	.string "That guy over there keeps bragging\n"
	.string "about having a long fishing rod.\p"
	.string "Little does he realize that I, with my\n"
	.string "much shorter rod, catch only the\l"
	.string "highest-jumping fish!$"
