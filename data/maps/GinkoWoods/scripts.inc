GinkoWoods_MapScripts::
	.byte 0


GinkoWoods_EventScript_Toshio::
# 9 "data/maps/GinkoWoods/scripts.pory"
	trainerbattle_single TRAINER_TOSHIO_1, GinkoWoods_EventScript_Toshio_Text_0, GinkoWoods_EventScript_Toshio_Text_1
# 19 "data/maps/GinkoWoods/scripts.pory"
	speakername GinkoWoods_EventScript_Toshio_Text_2
# 20 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Toshio_Text_3
# 21 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_Eiji::
# 26 "data/maps/GinkoWoods/scripts.pory"
	trainerbattle_single TRAINER_EIJI, GinkoWoods_EventScript_Eiji_Text_0, GinkoWoods_EventScript_Eiji_Text_1
# 31 "data/maps/GinkoWoods/scripts.pory"
	speakername GinkoWoods_EventScript_Eiji_Text_2
# 32 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Eiji_Text_3
# 33 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_OldMan::
# 38 "data/maps/GinkoWoods/scripts.pory"
	lock
# 39 "data/maps/GinkoWoods/scripts.pory"
	faceplayer
# 40 "data/maps/GinkoWoods/scripts.pory"
	speakername GinkoWoods_EventScript_OldMan_Text_0
# 41 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_OldMan_Text_1
# 42 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_Bean::
# 47 "data/maps/GinkoWoods/scripts.pory"
	lock
# 48 "data/maps/GinkoWoods/scripts.pory"
	faceplayer
# 50 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_0
# 53 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 55 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 57 "data/maps/GinkoWoods/scripts.pory"
	turnobject 7, DIR_EAST
# 59 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_1
# 62 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 64 "data/maps/GinkoWoods/scripts.pory"
	turnobject 7, DIR_SOUTH
# 66 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 68 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_2
# 76 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 78 "data/maps/GinkoWoods/scripts.pory"
	fadescreen FADE_TO_BLACK
# 82 "data/maps/GinkoWoods/scripts.pory"
	delay 60
# 84 "data/maps/GinkoWoods/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 86 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 88 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_3
# 93 "data/maps/GinkoWoods/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, GinkoWoods_EventScript_Bean_Text_4, GinkoWoods_EventScript_Bean_Text_5, GinkoWoods_EventScript_Bean_Text_6
# 104 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 106 "data/maps/GinkoWoods/scripts.pory"
	switch VAR_RESULT
# 107 "data/maps/GinkoWoods/scripts.pory"
	case 0, GinkoWoods_EventScript_Bean_3
# 114 "data/maps/GinkoWoods/scripts.pory"
	case 1, GinkoWoods_EventScript_Bean_4
# 121 "data/maps/GinkoWoods/scripts.pory"
	case 2, GinkoWoods_EventScript_Bean_5
GinkoWoods_EventScript_Bean_1:
# 131 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 133 "data/maps/GinkoWoods/scripts.pory"
	applymovement 7, GinkoWoods_Movement_BeanWalksAway
# 134 "data/maps/GinkoWoods/scripts.pory"
	waitmovement 0
# 135 "data/maps/GinkoWoods/scripts.pory"
	removeobject 7
# 136 "data/maps/GinkoWoods/scripts.pory"
	setflag FLAG_HIDE_BEAN_GINKO_WOODS
# 138 "data/maps/GinkoWoods/scripts.pory"
	release
	return

GinkoWoods_EventScript_Bean_3:
# 108 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_7
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_4:
# 115 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_8
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_5:
# 122 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_9
	goto GinkoWoods_EventScript_Bean_1


# 141 "data/maps/GinkoWoods/scripts.pory"
GinkoWoods_Movement_BeanWalksAway:
# 142 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 142 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 142 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 142 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 142 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 142 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 142 "data/maps/GinkoWoods/scripts.pory"
	walk_up
	step_end

GinkoWoods_EventScript_Tracks::
# 146 "data/maps/GinkoWoods/scripts.pory"
	lock
# 148 "data/maps/GinkoWoods/scripts.pory"
	playse SE_PIN
# 149 "data/maps/GinkoWoods/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 150 "data/maps/GinkoWoods/scripts.pory"
	waitse
# 151 "data/maps/GinkoWoods/scripts.pory"
	waitmovement 0
# 152 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 153 "data/maps/GinkoWoods/scripts.pory"
	applymovement 7, Common_Movement_WalkInPlaceFasterRight
# 154 "data/maps/GinkoWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 156 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Tracks_Text_0
# 159 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 161 "data/maps/GinkoWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, GinkoWoods_Movement_PlayerWalkDown
# 162 "data/maps/GinkoWoods/scripts.pory"
	waitmovement 0
# 164 "data/maps/GinkoWoods/scripts.pory"
	release
	return


# 167 "data/maps/GinkoWoods/scripts.pory"
GinkoWoods_Movement_PlayerWalkDown:
# 168 "data/maps/GinkoWoods/scripts.pory"
	walk_down
	step_end

GinkoWoods_EventScript_TrainerTips1::
# 172 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_TrainerTips1_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_TrainerTips2::
# 180 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_Toshio_Text_0:
# 11 "data/maps/GinkoWoods/scripts.pory"
	.string "Our eyes met! Therefore we must\n"
	.string "battle!$"

GinkoWoods_EventScript_Toshio_Text_1:
# 12 "data/maps/GinkoWoods/scripts.pory"
	.string "Should have kept my mouth shut…$"

GinkoWoods_EventScript_Toshio_Text_2:
# 19 "data/maps/GinkoWoods/scripts.pory"
	.string "Toshio$"

GinkoWoods_EventScript_Toshio_Text_3:
# 20 "data/maps/GinkoWoods/scripts.pory"
	.string "Real wielders fight when they spot\n"
	.string "each other!\p"
	.string "At least that's what my dad told me…$"

GinkoWoods_EventScript_Eiji_Text_0:
# 28 "data/maps/GinkoWoods/scripts.pory"
	.string "With the help of my brand-new\n"
	.string "Pokémon, I'm catching all sort of\l"
	.string "bugs!$"

GinkoWoods_EventScript_Eiji_Text_1:
# 29 "data/maps/GinkoWoods/scripts.pory"
	.string "My bugs!$"

GinkoWoods_EventScript_Eiji_Text_2:
# 31 "data/maps/GinkoWoods/scripts.pory"
	.string "Eiji$"

GinkoWoods_EventScript_Eiji_Text_3:
# 32 "data/maps/GinkoWoods/scripts.pory"
	.string "I asked Elder Kaba for a bird Pokémon,\n"
	.string "because they're strong against bugs!$"

GinkoWoods_EventScript_OldMan_Text_0:
# 40 "data/maps/GinkoWoods/scripts.pory"
	.string "Old man$"

GinkoWoods_EventScript_OldMan_Text_1:
# 41 "data/maps/GinkoWoods/scripts.pory"
	.string "These woods are fascinating.\p"
	.string "There seem to be a lot of yellow\n"
	.string "Pokémon here.$"

GinkoWoods_EventScript_Bean_Text_0:
# 51 "data/maps/GinkoWoods/scripts.pory"
	.string "Hello!$"

GinkoWoods_EventScript_Bean_Text_1:
# 60 "data/maps/GinkoWoods/scripts.pory"
	.string "I just noticed there are some neat\n"
	.string "tracks in the dirt here.$"

GinkoWoods_EventScript_Bean_Text_2:
# 69 "data/maps/GinkoWoods/scripts.pory"
	.string "It looks like a small mammal's\n"
	.string "footprints, see?\p"
	.string "Studying Pokémon tracks is so\n"
	.string "fascinating. One can find out about a\l"
	.string "Pokémon's nesting place, their\l"
	.string "hunting habits, at what time they\l"
	.string "sleep, what they eat… Interesting,\l"
	.string "isn't it?\p"
	.string "These woods host a lot of yellow\n"
	.string "Pokémon, so I'd bet these are a\l"
	.string "Pikachu's, or a Kotora's. Do you know\l"
	.string "why there's a lot of yellow Pokémon\l"
	.string "here? Well, that's because smaller\l"
	.string "Pokémon can easily hide from\l"
	.string "predators in the foliage, and said\l"
	.string "predators can stalk their prey\l"
	.string "without being seen. Additionally, the\l"
	.string "high concentration of electric-type\l"
	.string "Pokémon, which seems to have\l"
	.string "happened fortuitously, explains the\l"
	.string "unnaturally high static electricity in\l"
	.string "the air here. Some of the non-electric\l"
	.string "Pokémon that live here have adapted\l"
	.string "by developing specific traits, like\l"
	.string "the Sewaddle you've probably seen on\l"
	.string "your way here that blah, blah blah\l"
	.string "blah blah, blah blah…$"

GinkoWoods_EventScript_Bean_Text_3:
# 89 "data/maps/GinkoWoods/scripts.pory"
	.string "…And that's all that is currently\n"
	.string "known about Joltik's habitat during\l"
	.string "the winter.\p"
	.string "Neat, isn't it?$"

GinkoWoods_EventScript_Bean_Text_4:
# 100 "data/maps/GinkoWoods/scripts.pory"
	.string "… …Yes?$"

GinkoWoods_EventScript_Bean_Text_5:
# 101 "data/maps/GinkoWoods/scripts.pory"
	.string "Do I know you?$"

GinkoWoods_EventScript_Bean_Text_6:
# 102 "data/maps/GinkoWoods/scripts.pory"
	.string "I was just passing through…$"

GinkoWoods_EventScript_Bean_Text_7:
# 109 "data/maps/GinkoWoods/scripts.pory"
	.string "Right! I am glad you share my interest\n"
	.string "in Pokémon habitat.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Bean_Text_8:
# 116 "data/maps/GinkoWoods/scripts.pory"
	.string "Right! I haven't introduced myself\n"
	.string "yet.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Bean_Text_9:
# 123 "data/maps/GinkoWoods/scripts.pory"
	.string "…Oh. I am blocking your path. I see.\p"
	.string "I guess I got carried away, have I\n"
	.string "not? That… tends to happen.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I am moving now, so that you\l"
	.string "can go through.\p"
	.string "I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Tracks_Text_0:
# 157 "data/maps/GinkoWoods/scripts.pory"
	.string "THE TRACKS!! YOU'RE STEPPING ON\n"
	.string "THEM!!!$"

GinkoWoods_EventScript_TrainerTips1_Text_0:
# 173 "data/maps/GinkoWoods/scripts.pory"
	.string "Did you know?\p"
	.string "Some items can be hidden under the\n"
	.string "forest's thick canopy. Look around!$"

GinkoWoods_EventScript_TrainerTips2_Text_0:
# 181 "data/maps/GinkoWoods/scripts.pory"
	.string "Did you know?\p"
	.string "You can sort the contents of your\n"
	.string "bag by pressing START.$"
