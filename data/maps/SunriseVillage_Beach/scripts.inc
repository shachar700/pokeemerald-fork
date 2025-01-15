SunriseVillage_Beach_MapScripts::
	.byte 0


SunriseVillage_Beach_EventScript_RivalSpeech::
# 7 "data/maps/SunriseVillage_Beach/scripts.pory"
	lock
# 8 "data/maps/SunriseVillage_Beach/scripts.pory"
	playse SE_PIN
# 9 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 10 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 11 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 48
# 12 "data/maps/SunriseVillage_Beach/scripts.pory"
	faceplayer
# 13 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 14 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_1
# 17 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 20 "data/maps/SunriseVillage_Beach/scripts.pory"
	switch VAR_FACING
# 21 "data/maps/SunriseVillage_Beach/scripts.pory"
	case DIR_SOUTH, SunriseVillage_Beach_EventScript_RivalSpeech_3
# 23 "data/maps/SunriseVillage_Beach/scripts.pory"
	case DIR_NORTH, SunriseVillage_Beach_EventScript_RivalSpeech_4
# 25 "data/maps/SunriseVillage_Beach/scripts.pory"
	case DIR_WEST, SunriseVillage_Beach_EventScript_RivalSpeech_5
# 27 "data/maps/SunriseVillage_Beach/scripts.pory"
	case DIR_EAST, SunriseVillage_Beach_EventScript_RivalSpeech_6
SunriseVillage_Beach_EventScript_RivalSpeech_1:
# 30 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 31 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, SunriseVillage_Beach_Movement_RivalSitsOnBench
# 32 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 34 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 35 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_2
# 43 "data/maps/SunriseVillage_Beach/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_Beach_EventScript_RivalSpeech_Text_3, SunriseVillage_Beach_EventScript_RivalSpeech_Text_4
# 53 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 56 "data/maps/SunriseVillage_Beach/scripts.pory"
	switch VAR_RESULT
# 57 "data/maps/SunriseVillage_Beach/scripts.pory"
	case 0, SunriseVillage_Beach_EventScript_RivalSpeech_9
# 86 "data/maps/SunriseVillage_Beach/scripts.pory"
	case 1, SunriseVillage_Beach_EventScript_RivalSpeech_10
SunriseVillage_Beach_EventScript_RivalSpeech_7:
# 116 "data/maps/SunriseVillage_Beach/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_Beach_EventScript_RivalSpeech_Text_10, SunriseVillage_Beach_EventScript_RivalSpeech_Text_11, SunriseVillage_Beach_EventScript_RivalSpeech_Text_12
# 127 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 129 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 130 "data/maps/SunriseVillage_Beach/scripts.pory"
	switch VAR_RESULT
# 131 "data/maps/SunriseVillage_Beach/scripts.pory"
	case 0, SunriseVillage_Beach_EventScript_RivalSpeech_13
# 138 "data/maps/SunriseVillage_Beach/scripts.pory"
	case 1, SunriseVillage_Beach_EventScript_RivalSpeech_14
# 144 "data/maps/SunriseVillage_Beach/scripts.pory"
	case 2, SunriseVillage_Beach_EventScript_RivalSpeech_15
SunriseVillage_Beach_EventScript_RivalSpeech_11:
# 152 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 154 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 48
# 157 "data/maps/SunriseVillage_Beach/scripts.pory"
	setvar VAR_0x8004, 1
# 158 "data/maps/SunriseVillage_Beach/scripts.pory"
	setvar VAR_0x8005, 1
# 159 "data/maps/SunriseVillage_Beach/scripts.pory"
	setvar VAR_0x8006, 20
# 160 "data/maps/SunriseVillage_Beach/scripts.pory"
	setvar VAR_0x8007, 5
# 161 "data/maps/SunriseVillage_Beach/scripts.pory"
	special ShakeCamera
# 162 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 16
# 163 "data/maps/SunriseVillage_Beach/scripts.pory"
	playse SE_PIN
# 164 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, SunriseVillage_Beach_Movement_RivalSurprisedByQuake
# 165 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 16
# 166 "data/maps/SunriseVillage_Beach/scripts.pory"
	playse SE_PIN
# 167 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_PlayerSurprisedByQuake
# 168 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitstate
# 169 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 170 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 1
# 171 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 48
# 174 "data/maps/SunriseVillage_Beach/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 175 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
# 176 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 178 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 179 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_16
# 185 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 187 "data/maps/SunriseVillage_Beach/scripts.pory"
	playse SE_PIN
# 188 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 189 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 190 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 48
# 192 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, SunriseVillage_Beach_Movement_RivalSeesDistribution
# 193 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 195 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 196 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_17
# 200 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 202 "data/maps/SunriseVillage_Beach/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 204 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, SunriseVillage_Beach_Movement_RivalRaces
# 205 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 207 "data/maps/SunriseVillage_Beach/scripts.pory"
	setflag FLAG_HIDE_SUNRISE_BEACH_RIVAL
# 208 "data/maps/SunriseVillage_Beach/scripts.pory"
	clearflag FLAG_HIDE_SUNRISE_VILLAGE_STANDARD_NPC_POSITIONS
# 209 "data/maps/SunriseVillage_Beach/scripts.pory"
	clearflag FLAG_HIDE_BIGSIS_HOME
# 210 "data/maps/SunriseVillage_Beach/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
# 212 "data/maps/SunriseVillage_Beach/scripts.pory"
	removeobject 1
# 213 "data/maps/SunriseVillage_Beach/scripts.pory"
	release
	end

SunriseVillage_Beach_EventScript_RivalSpeech_3:
# 22 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromTop
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_4:
# 24 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromBottom
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_5:
# 26 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromRight
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_6:
# 28 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromLeft
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_9:
# 58 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 59 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_5
# 63 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 65 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 66 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 68 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 69 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_6
# 74 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 76 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 48
# 78 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
# 79 "data/maps/SunriseVillage_Beach/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 81 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 82 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_7
	goto SunriseVillage_Beach_EventScript_RivalSpeech_7

SunriseVillage_Beach_EventScript_RivalSpeech_10:
# 87 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 88 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_8
# 92 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 94 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 95 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 97 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 98 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_6
# 103 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 105 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay 48
# 107 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
# 108 "data/maps/SunriseVillage_Beach/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 110 "data/maps/SunriseVillage_Beach/scripts.pory"
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 111 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_9
	goto SunriseVillage_Beach_EventScript_RivalSpeech_7

SunriseVillage_Beach_EventScript_RivalSpeech_13:
# 132 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_13
	goto SunriseVillage_Beach_EventScript_RivalSpeech_11

SunriseVillage_Beach_EventScript_RivalSpeech_14:
# 139 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_14
	goto SunriseVillage_Beach_EventScript_RivalSpeech_11

SunriseVillage_Beach_EventScript_RivalSpeech_15:
# 145 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_15
	goto SunriseVillage_Beach_EventScript_RivalSpeech_11


# 217 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_PlayerSurprisedByQuake:
# 218 "data/maps/SunriseVillage_Beach/scripts.pory"
	emote_exclamation_mark
# 219 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 220 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_right
# 221 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 222 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_up
# 223 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 224 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_right
# 225 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 226 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_down
# 227 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 228 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_left
# 229 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 230 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_up
	step_end

# 233 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_RivalSurprisedByQuake:
# 234 "data/maps/SunriseVillage_Beach/scripts.pory"
	emote_exclamation_mark
# 235 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 236 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_down
# 237 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 238 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_up
# 239 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 240 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_left
# 241 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 242 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_right
# 243 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 244 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_up
# 245 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 246 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_down
	step_end

SunriseVillage_Beach_EventScript_Corsola::
# 251 "data/maps/SunriseVillage_Beach/scripts.pory"
	lock
# 252 "data/maps/SunriseVillage_Beach/scripts.pory"
	faceplayer
# 253 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitse
# 254 "data/maps/SunriseVillage_Beach/scripts.pory"
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
# 255 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_Corsola_Text_0
# 258 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmoncry
# 259 "data/maps/SunriseVillage_Beach/scripts.pory"
	release
	end


SunriseVillage_Beach_EventScript_Corsola2::
# 264 "data/maps/SunriseVillage_Beach/scripts.pory"
	lock
# 265 "data/maps/SunriseVillage_Beach/scripts.pory"
	faceplayer
# 266 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitse
# 267 "data/maps/SunriseVillage_Beach/scripts.pory"
	playmoncry SPECIES_CORSOLA, CRY_MODE_WEAK
# 268 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_Corsola2_Text_0
# 271 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmoncry
# 272 "data/maps/SunriseVillage_Beach/scripts.pory"
	release
	end


# 276 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_RivalSitsOnBench:
# 277 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_in_place_faster_left
# 278 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 278 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 278 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 278 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 278 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 279 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

# 282 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_GoNextToRivalFromLeft:
# 283 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_up
# 284 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_right
# 285 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_in_place_faster_left
# 286 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

# 289 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_GoNextToRivalFromTop:
# 290 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_in_place_faster_left
# 291 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

# 294 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_GoNextToRivalFromRight:
# 295 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_up
# 296 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_left
# 297 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

# 300 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_GoNextToRivalFromBottom:
# 301 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_right
# 302 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_up
# 302 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_up
# 303 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_left
# 304 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

# 307 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_RivalSeesDistribution:
# 308 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_right
# 309 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 310 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 311 "data/maps/SunriseVillage_Beach/scripts.pory"
	delay_16
# 312 "data/maps/SunriseVillage_Beach/scripts.pory"
	face_player
# 313 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

# 316 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_RivalRaces:
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 317 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 318 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

SunriseVillage_Beach_EventScript_RivalSpeech_Text_0:
# 13 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Natsuki$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_1:
# 15 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Hey, {PLAYER}! Come on, sit down\n"
	.string "next to me.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_2:
# 36 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "It's been crazy lately, huh?\p"
	.string "With the Pokémon in Ginko Woods,\n"
	.string "and the volcano…\p"
	.string "It feels like everything's\n"
	.string "about to change.\p"
	.string "Everyone is so anxious.\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_3:
# 50 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Are you worried?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_4:
# 51 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "What are you thinking about?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_5:
# 60 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Nah, you know me.\n"
	.string "We'll figure it out when we get there.\p"
	.string "That's what I've always done,\n"
	.string "everything turns out fine eventually.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_6:
# 70 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Hey, look.\p"
	.string "You can see Yifu City very clearly\n"
	.string "today, it's gorgeous!\p"
	.string "…$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_7:
# 83 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "You okay there, {PLAYER}?\n"
	.string "You look troubled.\p"
	.string "Aren't you excited to become\n"
	.string "a Pokémon wielder?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_8:
# 89 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Huh?…\p"
	.string "…Oh, sorry, I was just wondering\n"
	.string "which Pokémon I'm gonna be getting.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_9:
# 112 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "What about you, {PLAYER}?\n"
	.string "You excited about getting\l"
	.string "your own Pokémon?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_10:
# 123 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "I'm thrilled!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_11:
# 124 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "I'm terrified!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_12:
# 125 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "It's whatever.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_13:
# 133 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Hell yeah!\p"
	.string "We're going to make awesome wielders,\n"
	.string "I can already tell.\p"
	.string "Maybe you'll even be second best\n"
	.string "one day…\p"
	.string "Behind me, of course!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_14:
# 140 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Uh, you're kidding, right?\p"
	.string "It's going to be awesome.\n"
	.string "Just chill.\p"
	.string "Once we get our Pokémon, we'll do\n"
	.string "whatever we want!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_15:
# 146 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Oh c'mon, you're just pretending\n"
	.string "not to be excited.\p"
	.string "Look at you, acting all tough\n"
	.string "and silent…\l"
	.string "But I see right through you!\p"
	.string "I bet you'll be a great wielder.\n"
	.string "Maybe even as good as me…\p"
	.string "Probably not though!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_16:
# 180 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Woah, there it goes again!\n"
	.string "You good, {PLAYER}?\p"
	.string "Whew! Those quakes are no joke, huh?\p"
	.string "Maybe the volcano's telling us\n"
	.string "to get to Elder Kaba's house already.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_17:
# 197 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Aw Shuckles, the distribution's\n"
	.string "already started!\p"
	.string "Let's go, {PLAYER}!!$"

SunriseVillage_Beach_EventScript_Corsola_Text_0:
# 256 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Krr!$"

SunriseVillage_Beach_EventScript_Corsola2_Text_0:
# 269 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Laaa!$"
