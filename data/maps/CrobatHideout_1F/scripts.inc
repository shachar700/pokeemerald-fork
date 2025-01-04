CrobatHideout_1F_MapScripts::
# 10 "data/maps/CrobatHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/CrobatHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 11 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_TEMP_1
	return

CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/CrobatHideout_1F/scripts.pory"
	map_script_2 FLAG_CROBAT_HIDEOUT_SEEN_BY_GRUNT, 0, CrobatHideout_1F_SeenByGrunt
	.2byte 0


CrobatHideout_1F_SeenByGrunt::
# 19 "data/maps/CrobatHideout_1F/scripts.pory"
	lockall
# 21 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 24
# 23 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_SeenByGrunt_Movement_0
# 24 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 25 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_1
# 26 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 2
# 27 "data/maps/CrobatHideout_1F/scripts.pory"
	waitse
# 29 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 30 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_1
# 36 "data/maps/CrobatHideout_1F/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, CrobatHideout_1F_SeenByGrunt_Text_2, CrobatHideout_1F_SeenByGrunt_Text_3, CrobatHideout_1F_SeenByGrunt_Text_4
# 47 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 49 "data/maps/CrobatHideout_1F/scripts.pory"
	switch VAR_RESULT
# 50 "data/maps/CrobatHideout_1F/scripts.pory"
	case 0, CrobatHideout_1F_SeenByGrunt_3
# 56 "data/maps/CrobatHideout_1F/scripts.pory"
	case 1, CrobatHideout_1F_SeenByGrunt_4
CrobatHideout_1F_SeenByGrunt_1:
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_2
# 67 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 2
# 68 "data/maps/CrobatHideout_1F/scripts.pory"
	removeobject 2
# 70 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_CROBAT_HIDEOUT_SEEN_BY_GRUNT
# 71 "data/maps/CrobatHideout_1F/scripts.pory"
	releaseall
	return

CrobatHideout_1F_SeenByGrunt_3:
# 51 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 52 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_5
	goto CrobatHideout_1F_SeenByGrunt_1

CrobatHideout_1F_SeenByGrunt_4:
# 57 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 58 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_6
	goto CrobatHideout_1F_SeenByGrunt_1


CrobatHideout_1F_EventScript_Grunt1::
# 76 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_DUMMY, CrobatHideout_1F_EventScript_Grunt1_Text_0, CrobatHideout_1F_EventScript_Grunt1_Text_1
# 81 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 82 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_Grunt1_Text_2
# 85 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntPaintingPokeballs::
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_DUMMY, CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_0, CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_1
# 95 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 96 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_2
# 99 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntLaundryRoom::
# 104 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_DUMMY, CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_0, CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_1
# 111 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 112 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_2
# 115 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntDoubleGirl::
# 120 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_DUMMY, CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_0, CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_1
# 127 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 128 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_2
# 131 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntDoubleGuy::
# 136 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_DUMMY, CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_0, CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_1
# 143 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 144 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_2
# 147 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntNearReunionRoom::
# 152 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_DUMMY, CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_0, CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_1
# 159 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 160 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_2
# 163 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_Trigger_BossRoom::
# 168 "data/maps/CrobatHideout_1F/scripts.pory"
	lockall
# 170 "data/maps/CrobatHideout_1F/scripts.pory"
	special SpawnCameraObject
# 171 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CrobatHideout_1F_Trigger_BossRoom_Movement_0
# 172 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 174 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 175 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 8, CrobatHideout_1F_Trigger_BossRoom_Movement_1
# 176 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 16
# 177 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 178 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 7, CrobatHideout_1F_Trigger_BossRoom_Movement_1
# 179 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 16
# 180 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 181 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 6, CrobatHideout_1F_Trigger_BossRoom_Movement_1
# 182 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 6
# 183 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 48
# 185 "data/maps/CrobatHideout_1F/scripts.pory"
	clearflag FLAG_TEMP_1
# 186 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 13
# 187 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_Trigger_BossRoom_Movement_2
# 188 "data/maps/CrobatHideout_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 189 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 13
# 190 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_Trigger_BossRoom_Movement_3
# 191 "data/maps/CrobatHideout_1F/scripts.pory"
	compare VAR_TEMP_0, 34
	goto_if_eq CrobatHideout_1F_Trigger_BossRoom_2
CrobatHideout_1F_Trigger_BossRoom_1:
# 194 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 196 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 197 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_Trigger_BossRoom_Text_0
# 200 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 202 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 203 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 9
# 204 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_Trigger_BossRoom_Text_1
# 205 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_Trigger_BossRoom_Text_2
# 210 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 32
# 211 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_Trigger_BossRoom_Movement_5
# 212 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 213 "data/maps/CrobatHideout_1F/scripts.pory"
	removeobject 13
# 215 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 217 "data/maps/CrobatHideout_1F/scripts.pory"
	special RemoveCameraObject
# 219 "data/maps/CrobatHideout_1F/scripts.pory"
	releaseall
	return

CrobatHideout_1F_Trigger_BossRoom_2:
# 192 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_BossRoom_Movement_4
	goto CrobatHideout_1F_Trigger_BossRoom_1


CrobatHideout_1F_EventScript_LaundrySchedule::
# 223 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_LaundrySchedule_Text_0, MSGBOX_SIGN
	return


# 23 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SeenByGrunt_Movement_0:
# 23 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
	step_end

# 25 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SeenByGrunt_Movement_1:
# 25 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
# 25 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
# 25 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 25 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 25 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 66 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SeenByGrunt_Movement_2:
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 171 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_BossRoom_Movement_0:
# 171 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 171 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 171 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 171 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
	step_end

# 175 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_BossRoom_Movement_1:
# 175 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
# 175 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
	step_end

# 187 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_BossRoom_Movement_2:
# 187 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_up
# 187 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_up
	step_end

# 190 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_BossRoom_Movement_3:
# 190 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_up
	step_end

# 192 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_BossRoom_Movement_4:
# 192 "data/maps/CrobatHideout_1F/scripts.pory"
	face_left
# 192 "data/maps/CrobatHideout_1F/scripts.pory"
	lock_facing_direction
# 192 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_right
# 192 "data/maps/CrobatHideout_1F/scripts.pory"
	unlock_facing_direction
# 192 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
	step_end

# 211 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_BossRoom_Movement_5:
# 211 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 211 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
	step_end

CrobatHideout_1F_SeenByGrunt_Text_0:
# 29 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Zubat Grunt$"

CrobatHideout_1F_SeenByGrunt_Text_1:
# 31 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Who're you?!$"

CrobatHideout_1F_SeenByGrunt_Text_2:
# 43 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "{PLAYER}, nice to meet you!$"

CrobatHideout_1F_SeenByGrunt_Text_3:
# 44 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I'm the new recruit!$"

CrobatHideout_1F_SeenByGrunt_Text_4:
# 45 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Are you a criminal?$"

CrobatHideout_1F_SeenByGrunt_Text_5:
# 53 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I don' know no {PLAYER}! This ain't\n"
	.string "no tea party!\p"
	.string "You a spy? Ya don' work with the\n"
	.string "Samurai, do ya?$"

CrobatHideout_1F_SeenByGrunt_Text_6:
# 59 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Oh, right, 'course, the new recruit!\p"
	.string "(Why am I never in the loop?…)\p"
	.string "Wait, where's yer uniform?$"

CrobatHideout_1F_EventScript_Grunt1_Text_0:
# 78 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Are ya the intruder?$"

CrobatHideout_1F_EventScript_Grunt1_Text_1:
# 79 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Boss, help us!$"

CrobatHideout_1F_EventScript_Grunt1_Text_2:
# 83 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Whaddyawant? You got nothin' on us!\n"
	.string "Err I mean, we done nothin' wrong!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_0:
# 92 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "What? I'm not paintin' Poké Balls to\n"
	.string "look like Ultra Balls!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_1:
# 93 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Alright alright, ya got me!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_2:
# 97 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I'm sure this is all super legal, but\n"
	.string "don't ya dare say a thing!$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_0:
# 107 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yer not here to help with the laundry,\n"
	.string "are ya?$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_1:
# 109 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Oof…$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_2:
# 113 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I always end up on laundry duty, even\n"
	.string "when it's someone else's turn…$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_0:
# 123 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Where d'ya think yer goin', cutie pie?$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_1:
# 125 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Fine, go where ya want then!$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_2:
# 129 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yer laughin' now, but the boss is\n"
	.string "gonna take care of ya real good!$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_0:
# 139 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Trespassin's against the law, ya\n"
	.string "know?$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_1:
# 141 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Kids these days, I swear!$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_2:
# 145 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "We ain't gonna take this invasion of\n"
	.string "our privacy lyin' down!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_0:
# 155 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "This is our super secret hideout! Yer\n"
	.string "not wanted 'ere!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_1:
# 157 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Ya make me sad!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_2:
# 161 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Everythin' was fine an' dandy 'til you\n"
	.string "showed up!$"

CrobatHideout_1F_Trigger_BossRoom_Text_0:
# 198 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Boss! The intruder's 'ere!$"

CrobatHideout_1F_Trigger_BossRoom_Text_1:
# 204 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Crobat Boss$"

CrobatHideout_1F_Trigger_BossRoom_Text_2:
# 206 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yeah - I can see that!\n"
	.string "Did this puny lil' kid jus' wipe through\l"
	.string "our whole squad like it was nothin'?\l"
	.string "Is that what happened?\p"
	.string "What the hell, kid? D'ya think yer the\n"
	.string "law or somethin'?$"

CrobatHideout_1F_EventScript_LaundrySchedule_Text_0:
# 224 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "WEEKLY LAUNDRY SCHEDULE\n"
	.string "MON - Hiro\l"
	.string "TUE - Hiro\l"
	.string "WED - Mei\l"
	.string "THU - Kevin\l"
	.string "FRI - Hiro\l"
	.string "SAT - Saki\l"
	.string "SUN - Hiro$"
