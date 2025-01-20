GinkoWoods_MapScripts::
	.byte 0


GinkoWoods_EventScript_Scrub1::
# 9 "data/maps/GinkoWoods/scripts.pory"
	trainerbattle_single TRAINER_SCRUB_1, GinkoWoods_EventScript_Scrub1_Text_0, GinkoWoods_EventScript_Scrub1_Text_1
# 14 "data/maps/GinkoWoods/scripts.pory"
	speakername GinkoWoods_EventScript_Scrub1_Text_2
# 15 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Scrub1_Text_3
# 16 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_Toshio::
# 22 "data/maps/GinkoWoods/scripts.pory"
	trainerbattle_single TRAINER_TOSHIO_1, GinkoWoods_EventScript_Toshio_Text_0, GinkoWoods_EventScript_Toshio_Text_1
# 32 "data/maps/GinkoWoods/scripts.pory"
	speakername GinkoWoods_EventScript_Toshio_Text_2
# 33 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Toshio_Text_3
# 34 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_Eiji::
# 39 "data/maps/GinkoWoods/scripts.pory"
	trainerbattle_single TRAINER_EIJI, GinkoWoods_EventScript_Eiji_Text_0, GinkoWoods_EventScript_Eiji_Text_1
# 44 "data/maps/GinkoWoods/scripts.pory"
	speakername GinkoWoods_EventScript_Eiji_Text_2
# 45 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Eiji_Text_3
# 46 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_OldMan::
# 51 "data/maps/GinkoWoods/scripts.pory"
	lock
# 52 "data/maps/GinkoWoods/scripts.pory"
	faceplayer
# 53 "data/maps/GinkoWoods/scripts.pory"
	speakername GinkoWoods_EventScript_OldMan_Text_0
# 54 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_OldMan_Text_1
# 55 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_Bean::
# 60 "data/maps/GinkoWoods/scripts.pory"
	lock
# 61 "data/maps/GinkoWoods/scripts.pory"
	faceplayer
# 63 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_0
# 66 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 68 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 70 "data/maps/GinkoWoods/scripts.pory"
	turnobject 7, DIR_EAST
# 72 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_1
# 75 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 77 "data/maps/GinkoWoods/scripts.pory"
	turnobject 7, DIR_SOUTH
# 79 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 81 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_2
# 89 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 91 "data/maps/GinkoWoods/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/GinkoWoods/scripts.pory"
	addtime 0, 1, 30
# 94 "data/maps/GinkoWoods/scripts.pory"
	delay 60
# 96 "data/maps/GinkoWoods/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 98 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 100 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_3
# 105 "data/maps/GinkoWoods/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, GinkoWoods_EventScript_Bean_Text_4, GinkoWoods_EventScript_Bean_Text_5, GinkoWoods_EventScript_Bean_Text_6
# 116 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 118 "data/maps/GinkoWoods/scripts.pory"
	switch VAR_RESULT
# 119 "data/maps/GinkoWoods/scripts.pory"
	case 0, GinkoWoods_EventScript_Bean_3
# 126 "data/maps/GinkoWoods/scripts.pory"
	case 1, GinkoWoods_EventScript_Bean_4
# 133 "data/maps/GinkoWoods/scripts.pory"
	case 2, GinkoWoods_EventScript_Bean_5
GinkoWoods_EventScript_Bean_1:
# 143 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 145 "data/maps/GinkoWoods/scripts.pory"
	applymovement 7, GinkoWoods_Movement_BeanWalksAway
# 146 "data/maps/GinkoWoods/scripts.pory"
	waitmovement 0
# 147 "data/maps/GinkoWoods/scripts.pory"
	removeobject 7
# 148 "data/maps/GinkoWoods/scripts.pory"
	setflag FLAG_HIDE_BEAN_GINKO_WOODS
# 150 "data/maps/GinkoWoods/scripts.pory"
	release
	return

GinkoWoods_EventScript_Bean_3:
# 120 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_7
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_4:
# 127 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_8
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_5:
# 134 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Bean_Text_9
	goto GinkoWoods_EventScript_Bean_1


# 153 "data/maps/GinkoWoods/scripts.pory"
GinkoWoods_Movement_BeanWalksAway:
# 154 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 154 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 154 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 154 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 154 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 154 "data/maps/GinkoWoods/scripts.pory"
	walk_up
# 154 "data/maps/GinkoWoods/scripts.pory"
	walk_up
	step_end

GinkoWoods_EventScript_Tracks::
# 158 "data/maps/GinkoWoods/scripts.pory"
	lock
# 160 "data/maps/GinkoWoods/scripts.pory"
	playse SE_PIN
# 161 "data/maps/GinkoWoods/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 162 "data/maps/GinkoWoods/scripts.pory"
	waitse
# 163 "data/maps/GinkoWoods/scripts.pory"
	waitmovement 0
# 164 "data/maps/GinkoWoods/scripts.pory"
	delay 48
# 165 "data/maps/GinkoWoods/scripts.pory"
	applymovement 7, Common_Movement_WalkInPlaceFasterRight
# 166 "data/maps/GinkoWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 168 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Tracks_Text_0
# 171 "data/maps/GinkoWoods/scripts.pory"
	closemessage
# 173 "data/maps/GinkoWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, GinkoWoods_Movement_PlayerWalkDown
# 174 "data/maps/GinkoWoods/scripts.pory"
	waitmovement 0
# 176 "data/maps/GinkoWoods/scripts.pory"
	release
	return


# 179 "data/maps/GinkoWoods/scripts.pory"
GinkoWoods_Movement_PlayerWalkDown:
# 180 "data/maps/GinkoWoods/scripts.pory"
	walk_down
	step_end

GinkoWoods_EventScript_TrainerTips1::
# 184 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_TrainerTips1_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_TrainerTips2::
# 192 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_Scrub1_Text_0:
# 11 "data/maps/GinkoWoods/scripts.pory"
	.string "I am a scrub bug catcher whose sole\n"
	.string "purpose is to get stomped!$"

GinkoWoods_EventScript_Scrub1_Text_1:
# 12 "data/maps/GinkoWoods/scripts.pory"
	.string "I got stomped!$"

GinkoWoods_EventScript_Scrub1_Text_2:
# 14 "data/maps/GinkoWoods/scripts.pory"
	.string "Scrub$"

GinkoWoods_EventScript_Scrub1_Text_3:
# 15 "data/maps/GinkoWoods/scripts.pory"
	.string "If you lost to me you should\n"
	.string "uninstall!$"

GinkoWoods_EventScript_Toshio_Text_0:
# 24 "data/maps/GinkoWoods/scripts.pory"
	.string "Our eyes met! Therefore we must\n"
	.string "battle!$"

GinkoWoods_EventScript_Toshio_Text_1:
# 25 "data/maps/GinkoWoods/scripts.pory"
	.string "Should have kept my mouth shut…$"

GinkoWoods_EventScript_Toshio_Text_2:
# 32 "data/maps/GinkoWoods/scripts.pory"
	.string "Toshio$"

GinkoWoods_EventScript_Toshio_Text_3:
# 33 "data/maps/GinkoWoods/scripts.pory"
	.string "Real wielders fight when they spot\n"
	.string "each other!\p"
	.string "At least that's what my dad told me…$"

GinkoWoods_EventScript_Eiji_Text_0:
# 41 "data/maps/GinkoWoods/scripts.pory"
	.string "With the help of my brand-new\n"
	.string "Pokémon, I'm catching all sort of\l"
	.string "bugs!$"

GinkoWoods_EventScript_Eiji_Text_1:
# 42 "data/maps/GinkoWoods/scripts.pory"
	.string "My bugs!$"

GinkoWoods_EventScript_Eiji_Text_2:
# 44 "data/maps/GinkoWoods/scripts.pory"
	.string "Eiji$"

GinkoWoods_EventScript_Eiji_Text_3:
# 45 "data/maps/GinkoWoods/scripts.pory"
	.string "I asked Elder Kaba for a bird Pokémon,\n"
	.string "because they're strong against bugs!$"

GinkoWoods_EventScript_OldMan_Text_0:
# 53 "data/maps/GinkoWoods/scripts.pory"
	.string "Old man$"

GinkoWoods_EventScript_OldMan_Text_1:
# 54 "data/maps/GinkoWoods/scripts.pory"
	.string "These woods are fascinating.\p"
	.string "There seem to be a lot of yellow\n"
	.string "Pokémon here.$"

GinkoWoods_EventScript_Bean_Text_0:
# 64 "data/maps/GinkoWoods/scripts.pory"
	.string "Hello!$"

GinkoWoods_EventScript_Bean_Text_1:
# 73 "data/maps/GinkoWoods/scripts.pory"
	.string "I just noticed there are some neat\n"
	.string "tracks in the dirt here.$"

GinkoWoods_EventScript_Bean_Text_2:
# 82 "data/maps/GinkoWoods/scripts.pory"
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
# 101 "data/maps/GinkoWoods/scripts.pory"
	.string "…And that's all that is currently\n"
	.string "known about Joltik's habitat during\l"
	.string "the winter.\p"
	.string "Neat, isn't it?$"

GinkoWoods_EventScript_Bean_Text_4:
# 112 "data/maps/GinkoWoods/scripts.pory"
	.string "… …Yes?$"

GinkoWoods_EventScript_Bean_Text_5:
# 113 "data/maps/GinkoWoods/scripts.pory"
	.string "Do I know you?$"

GinkoWoods_EventScript_Bean_Text_6:
# 114 "data/maps/GinkoWoods/scripts.pory"
	.string "I was just passing through…$"

GinkoWoods_EventScript_Bean_Text_7:
# 121 "data/maps/GinkoWoods/scripts.pory"
	.string "Right! I am glad you share my interest\n"
	.string "in Pokémon habitat.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Bean_Text_8:
# 128 "data/maps/GinkoWoods/scripts.pory"
	.string "Right! I haven't introduced myself\n"
	.string "yet.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Bean_Text_9:
# 135 "data/maps/GinkoWoods/scripts.pory"
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
# 169 "data/maps/GinkoWoods/scripts.pory"
	.string "THE TRACKS!! YOU'RE STEPPING ON\n"
	.string "THEM!!!$"

GinkoWoods_EventScript_TrainerTips1_Text_0:
# 185 "data/maps/GinkoWoods/scripts.pory"
	.string "Did you know?\p"
	.string "Some items can be hidden under the\n"
	.string "forest's thick canopy. Look around!$"

GinkoWoods_EventScript_TrainerTips2_Text_0:
# 193 "data/maps/GinkoWoods/scripts.pory"
	.string "Did you know?\p"
	.string "You can sort the contents of your\n"
	.string "bag by pressing START.$"
