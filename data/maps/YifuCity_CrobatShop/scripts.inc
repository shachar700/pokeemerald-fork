YifuCity_CrobatShop_MapScripts::
# 6 "data/maps/YifuCity_CrobatShop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_CrobatShop_SetupNpcs
	.byte 0


YifuCity_CrobatShop_SetupNpcs::
# 10 "data/maps/YifuCity_CrobatShop/scripts.pory"
	goto_if_set FLAG_CROBAT_PASSWORD_CORRECT, YifuCity_CrobatShop_SetupNpcs_1
	return

YifuCity_CrobatShop_SetupNpcs_1:
# 11 "data/maps/YifuCity_CrobatShop/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
# 12 "data/maps/YifuCity_CrobatShop/scripts.pory"
	setobjectxyperm 4, 7, 4
	return


YifuCity_CrobatShop_Cashier::
# 17 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock
# 18 "data/maps/YifuCity_CrobatShop/scripts.pory"
	faceplayer
# 19 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Cashier_Text_0
# 20 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Cashier_Text_1
# 24 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 25 "data/maps/YifuCity_CrobatShop/scripts.pory"
	release
	return


YifuCity_CrobatShop_Guard::
# 29 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock
# 30 "data/maps/YifuCity_CrobatShop/scripts.pory"
	faceplayer
# 31 "data/maps/YifuCity_CrobatShop/scripts.pory"
	goto_if_set FLAG_CROBAT_PASSWORD_CORRECT, YifuCity_CrobatShop_Guard_2
# 40 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_0
# 41 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Guard_Text_0
# 42 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Guard_Text_2
# 46 "data/maps/YifuCity_CrobatShop/scripts.pory"
	goto_if_unset FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF, YifuCity_CrobatShop_Guard_5
# 46 "data/maps/YifuCity_CrobatShop/scripts.pory"
	goto_if_unset FLAG_GOT_CROBAT_PASSWORD_SECOND_HALF, YifuCity_CrobatShop_Guard_5
# 83 "data/maps/YifuCity_CrobatShop/scripts.pory"
	goto_if_set FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF, YifuCity_CrobatShop_Guard_14
YifuCity_CrobatShop_Guard_4:
# 147 "data/maps/YifuCity_CrobatShop/scripts.pory"
	release
	return

YifuCity_CrobatShop_Guard_2:
# 32 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Guard_Text_0
# 33 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Guard_Text_1
# 36 "data/maps/YifuCity_CrobatShop/scripts.pory"
	release
	end

YifuCity_CrobatShop_Guard_5:
# 47 "data/maps/YifuCity_CrobatShop/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_3, YifuCity_CrobatShop_Guard_Text_4, YifuCity_CrobatShop_Guard_Text_5
# 58 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 60 "data/maps/YifuCity_CrobatShop/scripts.pory"
	delay 24
# 62 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_1
# 64 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Guard_Text_0
# 65 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Guard_Text_6
# 68 "data/maps/YifuCity_CrobatShop/scripts.pory"
	waitmovement 0
# 69 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 71 "data/maps/YifuCity_CrobatShop/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_11
# 75 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_2
# 76 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_3
YifuCity_CrobatShop_Guard_10:
# 79 "data/maps/YifuCity_CrobatShop/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 80 "data/maps/YifuCity_CrobatShop/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 81 "data/maps/YifuCity_CrobatShop/scripts.pory"
	release
	goto YifuCity_CrobatShop_Guard_4

YifuCity_CrobatShop_Guard_11:
# 72 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_2
# 73 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_3
	goto YifuCity_CrobatShop_Guard_10

YifuCity_CrobatShop_Guard_14:
# 84 "data/maps/YifuCity_CrobatShop/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_7, YifuCity_CrobatShop_Guard_Text_8, YifuCity_CrobatShop_Guard_Text_9
# 95 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 97 "data/maps/YifuCity_CrobatShop/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq YifuCity_CrobatShop_Guard_17
YifuCity_CrobatShop_Guard_16:
# 101 "data/maps/YifuCity_CrobatShop/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_10, YifuCity_CrobatShop_Guard_Text_11, YifuCity_CrobatShop_Guard_Text_12
# 113 "data/maps/YifuCity_CrobatShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_CrobatShop_Guard_20
YifuCity_CrobatShop_Guard_19:
# 117 "data/maps/YifuCity_CrobatShop/scripts.pory"
	delay 24
# 119 "data/maps/YifuCity_CrobatShop/scripts.pory"
	goto_if_set FLAG_TEMP_2, YifuCity_CrobatShop_Guard_24
YifuCity_CrobatShop_Guard_23:
# 138 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Guard_Text_0
# 139 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Guard_Text_6
# 142 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
	goto YifuCity_CrobatShop_Guard_4

YifuCity_CrobatShop_Guard_17:
# 98 "data/maps/YifuCity_CrobatShop/scripts.pory"
	setflag FLAG_TEMP_1
	goto YifuCity_CrobatShop_Guard_16

YifuCity_CrobatShop_Guard_20:
# 114 "data/maps/YifuCity_CrobatShop/scripts.pory"
	setflag FLAG_TEMP_2
	goto YifuCity_CrobatShop_Guard_19

YifuCity_CrobatShop_Guard_22:
# 120 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Guard_Text_0
# 121 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Guard_Text_13
# 126 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 128 "data/maps/YifuCity_CrobatShop/scripts.pory"
	setflag FLAG_CROBAT_PASSWORD_CORRECT
# 130 "data/maps/YifuCity_CrobatShop/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_28
YifuCity_CrobatShop_Guard_27:
# 134 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_5
# 135 "data/maps/YifuCity_CrobatShop/scripts.pory"
	waitmovement 0
	goto YifuCity_CrobatShop_Guard_4

YifuCity_CrobatShop_Guard_24:
# 119 "data/maps/YifuCity_CrobatShop/scripts.pory"
	goto_if_set FLAG_TEMP_2, YifuCity_CrobatShop_Guard_22
	goto YifuCity_CrobatShop_Guard_23

YifuCity_CrobatShop_Guard_28:
# 131 "data/maps/YifuCity_CrobatShop/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_4
	goto YifuCity_CrobatShop_Guard_27


YifuCity_CrobatShop_Customer1::
# 151 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock
# 152 "data/maps/YifuCity_CrobatShop/scripts.pory"
	faceplayer
# 153 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Customer1_Text_0
# 154 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Customer1_Text_1
# 157 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 158 "data/maps/YifuCity_CrobatShop/scripts.pory"
	release
	return


YifuCity_CrobatShop_Customer2::
# 162 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock
# 163 "data/maps/YifuCity_CrobatShop/scripts.pory"
	faceplayer
# 164 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_Customer1_Text_0
# 165 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_Customer2_Text_0
# 168 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 169 "data/maps/YifuCity_CrobatShop/scripts.pory"
	release
	return


YifuCity_CrobatShop_EventScript_Samurai::
# 173 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock
# 174 "data/maps/YifuCity_CrobatShop/scripts.pory"
	faceplayer
# 175 "data/maps/YifuCity_CrobatShop/scripts.pory"
	speakername YifuCity_CrobatShop_EventScript_Samurai_Text_0
# 176 "data/maps/YifuCity_CrobatShop/scripts.pory"
	msgbox YifuCity_CrobatShop_EventScript_Samurai_Text_1
# 180 "data/maps/YifuCity_CrobatShop/scripts.pory"
	closemessage
# 181 "data/maps/YifuCity_CrobatShop/scripts.pory"
	release
	return


# 40 "data/maps/YifuCity_CrobatShop/scripts.pory"
YifuCity_CrobatShop_Guard_Movement_0:
# 40 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock_facing_direction
# 40 "data/maps/YifuCity_CrobatShop/scripts.pory"
	walk_in_place_faster_left
# 40 "data/maps/YifuCity_CrobatShop/scripts.pory"
	unlock_facing_direction
	step_end

# 62 "data/maps/YifuCity_CrobatShop/scripts.pory"
YifuCity_CrobatShop_Guard_Movement_1:
# 62 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock_facing_direction
# 62 "data/maps/YifuCity_CrobatShop/scripts.pory"
	walk_in_place_faster_left
	step_end

# 72 "data/maps/YifuCity_CrobatShop/scripts.pory"
YifuCity_CrobatShop_Guard_Movement_2:
# 72 "data/maps/YifuCity_CrobatShop/scripts.pory"
	walk_left
# 72 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock_facing_direction
# 72 "data/maps/YifuCity_CrobatShop/scripts.pory"
	walk_right
# 72 "data/maps/YifuCity_CrobatShop/scripts.pory"
	unlock_facing_direction
	step_end

# 73 "data/maps/YifuCity_CrobatShop/scripts.pory"
YifuCity_CrobatShop_Guard_Movement_3:
# 73 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock_facing_direction
# 73 "data/maps/YifuCity_CrobatShop/scripts.pory"
	lock_anim
# 73 "data/maps/YifuCity_CrobatShop/scripts.pory"
	jump_2_left
# 73 "data/maps/YifuCity_CrobatShop/scripts.pory"
	unlock_facing_direction
# 73 "data/maps/YifuCity_CrobatShop/scripts.pory"
	unlock_anim
	step_end

# 131 "data/maps/YifuCity_CrobatShop/scripts.pory"
YifuCity_CrobatShop_Guard_Movement_4:
# 131 "data/maps/YifuCity_CrobatShop/scripts.pory"
	walk_left
# 131 "data/maps/YifuCity_CrobatShop/scripts.pory"
	face_right
	step_end

# 134 "data/maps/YifuCity_CrobatShop/scripts.pory"
YifuCity_CrobatShop_Guard_Movement_5:
# 134 "data/maps/YifuCity_CrobatShop/scripts.pory"
	walk_down
# 134 "data/maps/YifuCity_CrobatShop/scripts.pory"
	face_left
	step_end

YifuCity_CrobatShop_Cashier_Text_0:
# 19 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Cashier$"

YifuCity_CrobatShop_Cashier_Text_1:
# 21 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "G'day uh, welcome to the ye olde\n"
	.string "Crobat Shoppe!\p"
	.string "TODO EVA$"

YifuCity_CrobatShop_Guard_Text_0:
# 32 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Shady man$"

YifuCity_CrobatShop_Guard_Text_1:
# 34 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Standin' guard is boring… Yawn…$"

YifuCity_CrobatShop_Guard_Text_2:
# 43 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Password?$"

YifuCity_CrobatShop_Guard_Text_3:
# 54 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Uh…$"

YifuCity_CrobatShop_Guard_Text_4:
# 55 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Ehm…$"

YifuCity_CrobatShop_Guard_Text_5:
# 56 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Well…$"

YifuCity_CrobatShop_Guard_Text_6:
# 66 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "That ain't the password! Scram!$"

YifuCity_CrobatShop_Guard_Text_7:
# 91 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Noivern…$"

YifuCity_CrobatShop_Guard_Text_8:
# 92 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Crobat…$"

YifuCity_CrobatShop_Guard_Text_9:
# 93 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Swoobat…$"

YifuCity_CrobatShop_Guard_Text_10:
# 108 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "…is awesome!$"

YifuCity_CrobatShop_Guard_Text_11:
# 109 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "…is amazing!$"

YifuCity_CrobatShop_Guard_Text_12:
# 110 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "…is legendary!$"

YifuCity_CrobatShop_Guard_Text_13:
# 122 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Hmmm… Ya don't look like the typical\n"
	.string "Zubat…\p"
	.string "… … … …\n"
	.string "… …Alright, ya can go through.\l"
	.string "Next time wear the damn uniform\l"
	.string "though, will ya?$"

YifuCity_CrobatShop_Customer1_Text_0:
# 153 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Customer$"

YifuCity_CrobatShop_Customer1_Text_1:
# 155 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "This place is amazing!\n"
	.string "How is everything so cheap?!$"

YifuCity_CrobatShop_Customer2_Text_0:
# 166 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "These Ultra Balls looks… different,\n"
	.string "somehow…$"

YifuCity_CrobatShop_EventScript_Samurai_Text_0:
# 175 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Samurai$"

YifuCity_CrobatShop_EventScript_Samurai_Text_1:
# 177 "data/maps/YifuCity_CrobatShop/scripts.pory"
	.string "Shhh, don't look at me!\n"
	.string "Someone tipped me off that the\l"
	.string "Crobat Shadows' band of misfits has a\l"
	.string "secret hideout right under the city!\p"
	.string "I'm trying to know more by standing\n"
	.string "around and listening!$"
