CrobatHideout_1F_MapScripts::
# 25 "data/maps/CrobatHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 31 "data/maps/CrobatHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 26 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_TEMP_5
# 27 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_TEMP_1
# 28 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_TEMP_2
# 29 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_TEMP_4
	return

CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 32 "data/maps/CrobatHideout_1F/scripts.pory"
	map_script_2 VAR_CROBAT_HIDEOUT_STATE, 0, CrobatHideout_1F_SeenByGrunt
	.2byte 0


CrobatHideout_1F_SeenByGrunt::
# 37 "data/maps/CrobatHideout_1F/scripts.pory"
	lockall
# 39 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 24
# 41 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_SeenByGrunt_Movement_0
# 42 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 43 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 44 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_1
# 45 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 2
# 46 "data/maps/CrobatHideout_1F/scripts.pory"
	waitse
# 48 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 49 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_1
# 53 "data/maps/CrobatHideout_1F/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, CrobatHideout_1F_SeenByGrunt_Text_2, CrobatHideout_1F_SeenByGrunt_Text_3, CrobatHideout_1F_SeenByGrunt_Text_4
# 64 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 66 "data/maps/CrobatHideout_1F/scripts.pory"
	switch VAR_RESULT
# 67 "data/maps/CrobatHideout_1F/scripts.pory"
	case 0, CrobatHideout_1F_SeenByGrunt_3
# 73 "data/maps/CrobatHideout_1F/scripts.pory"
	case 1, CrobatHideout_1F_SeenByGrunt_4
# 80 "data/maps/CrobatHideout_1F/scripts.pory"
	case 2, CrobatHideout_1F_SeenByGrunt_5
CrobatHideout_1F_SeenByGrunt_1:
# 87 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 89 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_2
# 91 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 92 "data/maps/CrobatHideout_1F/scripts.pory"
	waitse
# 94 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 95 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_8
# 99 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_3
# 102 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 2
# 103 "data/maps/CrobatHideout_1F/scripts.pory"
	removeobject 2
# 105 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_CROBAT_HIDEOUT_SEEN_BY_GRUNT
# 106 "data/maps/CrobatHideout_1F/scripts.pory"
	setvar VAR_CROBAT_HIDEOUT_STATE, 1
# 107 "data/maps/CrobatHideout_1F/scripts.pory"
	releaseall
	return

CrobatHideout_1F_SeenByGrunt_3:
# 68 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 69 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_5
	goto CrobatHideout_1F_SeenByGrunt_1

CrobatHideout_1F_SeenByGrunt_4:
# 74 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 75 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_6
	goto CrobatHideout_1F_SeenByGrunt_1

CrobatHideout_1F_SeenByGrunt_5:
# 81 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 82 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SeenByGrunt_Text_7
	goto CrobatHideout_1F_SeenByGrunt_1


CrobatHideout_1F_EventScript_Grunt1::
# 111 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_1, CrobatHideout_1F_EventScript_Grunt1_Text_0, CrobatHideout_1F_EventScript_Grunt1_Text_1
# 116 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 117 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_Grunt1_Text_2
# 120 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntPaintingPokeballs::
# 125 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_2, CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_0, CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_1
# 130 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 131 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_2
# 134 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntLaundryRoom::
# 139 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_3, CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_0, CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_1
# 146 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 147 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_2
# 150 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntDoubleGirl::
# 155 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_4, CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_0, CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_1
# 162 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 163 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_2
# 166 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntDoubleGuy::
# 171 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_5, CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_0, CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_1
# 178 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 179 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_2
# 182 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_GruntNearReunionRoom::
# 187 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_6, CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_0, CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_1
# 194 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 195 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_2
# 198 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	end


CrobatHideout_1F_EventScript_Samurai::
# 203 "data/maps/CrobatHideout_1F/scripts.pory"
	lock
# 204 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 205 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_Samurai_Text_1
# 210 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 212 "data/maps/CrobatHideout_1F/scripts.pory"
	setflag FLAG_TEMP_3
# 213 "data/maps/CrobatHideout_1F/scripts.pory"
	release
	end


CrobatHideout_1F_EventScript_LaundrySchedule::
# 218 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EventScript_LaundrySchedule_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_Trigger_4V1_Left::
# 231 "data/maps/CrobatHideout_1F/scripts.pory"
	lockall
# 233 "data/maps/CrobatHideout_1F/scripts.pory"
	clearflag FLAG_TEMP_4
# 234 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 16
# 235 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 17
# 236 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 18
# 237 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 19
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 16, CrobatHideout_1F_Trigger_4V1_Left_Movement_0
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 17, CrobatHideout_1F_Trigger_4V1_Left_Movement_1
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 18, CrobatHideout_1F_Trigger_4V1_Left_Movement_2
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 19, CrobatHideout_1F_Trigger_4V1_Left_Movement_3
# 244 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 16
# 245 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 17
# 246 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 18
# 247 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 19
# 255 "data/maps/CrobatHideout_1F/scripts.pory"
	call CrobatHideout_1F_PlayerGets4V1d
# 258 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 14
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Left_Movement_4
# 260 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 19
# 261 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Left_Movement_5
# 262 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 19, CrobatHideout_1F_Trigger_4V1_Left_Movement_6
# 263 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Left_Movement_7
# 264 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 266 "data/maps/CrobatHideout_1F/scripts.pory"
	call CrobatHideout_1F_SamuraiOffersHelp
# 268 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Left_Movement_8
# 269 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Left_Movement_9
# 270 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 271 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 24
# 273 "data/maps/CrobatHideout_1F/scripts.pory"
	call CrobatHideout_1F_BattleSamuraiBackToBack
# 275 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Left_Movement_10
# 276 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Left_Movement_10
# 277 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 279 "data/maps/CrobatHideout_1F/scripts.pory"
	call CrobatHideout_1F_EnteredBossRoomWithSamurai
# 281 "data/maps/CrobatHideout_1F/scripts.pory"
	releaseall
	return


CrobatHideout_1F_PlayerGets4V1d::
# 285 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_PlayerGets4V1d_Movement_0
# 291 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 293 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 16, CrobatHideout_1F_PlayerGets4V1d_Movement_1
# 294 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 16
# 295 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 296 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_PlayerGets4V1d_Text_0
# 298 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 17, CrobatHideout_1F_PlayerGets4V1d_Movement_1
# 299 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 17
# 300 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 301 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_PlayerGets4V1d_Text_1
	return


CrobatHideout_1F_SamuraiOffersHelp::
# 305 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 306 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SamuraiOffersHelp_Text_0
# 310 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_SamuraiOffersHelp_Movement_0
# 313 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 14
# 314 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 315 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_SamuraiOffersHelp_Movement_1
# 316 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 14
# 317 "data/maps/CrobatHideout_1F/scripts.pory"
	waitse
# 319 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 320 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SamuraiOffersHelp_Text_1
# 324 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 326 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 327 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_SamuraiOffersHelp_Text_2
# 330 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
	return


CrobatHideout_1F_BattleSamuraiBackToBack::
# 335 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_two_trainers TRAINER_DUMMY, CrobatHideout_1F_BattleSamuraiBackToBack_Text_0, TRAINER_DUMMY, CrobatHideout_1F_BattleSamuraiBackToBack_Text_1
# 342 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 343 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_BattleSamuraiBackToBack_Text_2
# 346 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 348 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_0
# 349 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_1
# 351 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 352 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_BattleSamuraiBackToBack_Text_3
# 357 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 359 "data/maps/CrobatHideout_1F/scripts.pory"
	setvar VAR_CROBAT_HIDEOUT_STATE, 2
	return


CrobatHideout_1F_EnteredBossRoomWithSamurai::
# 363 "data/maps/CrobatHideout_1F/scripts.pory"
	special SpawnCameraObject
# 364 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CrobatHideout_1F_Trigger_4V1_Left_Movement_10
# 365 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 367 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 368 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_0
# 369 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 16
# 370 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 371 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_0
# 372 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 16
# 373 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 374 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_0
# 375 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 6
# 376 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 48
# 378 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1
# 379 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 7
# 380 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
# 381 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_0
# 384 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 386 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
# 387 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 388 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 9
# 389 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 390 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_2
# 397 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 399 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterUp
# 400 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 14
# 401 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 402 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_3
# 406 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 408 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 409 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 9
# 410 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 411 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_4
# 414 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 416 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 417 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 9, CrobatHideout_1F_SamuraiOffersHelp_Movement_1
# 418 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 419 "data/maps/CrobatHideout_1F/scripts.pory"
	waitse
# 420 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 9
# 421 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 422 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_5
# 425 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 427 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_3
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
# 430 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 432 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 433 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_6
# 438 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 440 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_LEDGE
# 441 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5
# 442 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 14
# 443 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 444 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_7
# 449 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 451 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 452 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_8
# 456 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 459 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 13
# 460 "data/maps/CrobatHideout_1F/scripts.pory"
	addobject 19
# 461 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_6
# 462 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 19, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_6
# 463 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 465 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
# 466 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
# 467 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 469 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 470 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_9
# 473 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 475 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_LEDGE
# 476 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5
# 477 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 19, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5
# 478 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 480 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_10
# 481 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_11
# 484 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 486 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_7
# 487 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_7
# 488 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 490 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 491 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 9
# 492 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 493 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_12
# 498 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 502 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
# 503 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_13
# 506 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 508 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_8
# 509 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_9
# 510 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 511 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_PIN
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_10
# 513 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 515 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_11
# 516 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_11
# 517 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_11
# 519 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_M_DIVE
# 521 "data/maps/CrobatHideout_1F/scripts.pory"
	fadescreen FADE_TO_WHITE
# 522 "data/maps/CrobatHideout_1F/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 523 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 48
# 524 "data/maps/CrobatHideout_1F/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 526 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 527 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_14
# 530 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 532 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1
# 533 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_12
# 534 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
# 535 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
# 537 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_15
# 538 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_16
# 541 "data/maps/CrobatHideout_1F/scripts.pory"
	setweather WEATHER_NONE
# 542 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 543 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 544 "data/maps/CrobatHideout_1F/scripts.pory"
	special RemoveCameraObject
# 546 "data/maps/CrobatHideout_1F/scripts.pory"
	call CrobatHideout_1F_LetsFight2v2
	return


CrobatHideout_1F_LetsFight2v2::
# 550 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 551 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_LetsFight2v2_Text_0
# 554 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 556 "data/maps/CrobatHideout_1F/scripts.pory"
	special SavePlayerParty
# 557 "data/maps/CrobatHideout_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 558 "data/maps/CrobatHideout_1F/scripts.pory"
	special ChooseHalfPartyForBattle
# 559 "data/maps/CrobatHideout_1F/scripts.pory"
	waitstate
# 561 "data/maps/CrobatHideout_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CrobatHideout_1F_LetsFight2v2_2
# 566 "data/maps/CrobatHideout_1F/scripts.pory"
	multi_2_vs_2 TRAINER_MAXIE_MOSSDEEP, CrobatHideout_1F_LetsFight2v2_Text_1, TRAINER_TABITHA_MOSSDEEP, CrobatHideout_1F_LetsFight2v2_Text_2, PARTNER_SAMURAI
# 573 "data/maps/CrobatHideout_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne CrobatHideout_1F_LetsFight2v2_5
# 615 "data/maps/CrobatHideout_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 616 "data/maps/CrobatHideout_1F/scripts.pory"
	special SetCB2WhiteOut
# 617 "data/maps/CrobatHideout_1F/scripts.pory"
	waitstate
CrobatHideout_1F_LetsFight2v2_1:
# 621 "data/maps/CrobatHideout_1F/scripts.pory"
	trainerbattle_two_trainers TRAINER_ADMIN_CROBAT_HIDEOUT_1, CrobatHideout_1F_LetsFight2v2_Text_7, TRAINER_ADMIN_CROBAT_HIDEOUT_2, CrobatHideout_1F_LetsFight2v2_Text_8
# 628 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1
# 629 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
	return

CrobatHideout_1F_LetsFight2v2_2:
# 562 "data/maps/CrobatHideout_1F/scripts.pory"
	special LoadPlayerParty
# 564 "data/maps/CrobatHideout_1F/scripts.pory"
	goto CrobatHideout_1F_LetsFight2v2
	goto CrobatHideout_1F_LetsFight2v2_1

CrobatHideout_1F_LetsFight2v2_5:
# 574 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 19, CrobatHideout_1F_LetsFight2v2_Movement_0
# 575 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 576 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_15
# 577 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_LetsFight2v2_Text_3
# 580 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 582 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_LetsFight2v2_Movement_1
# 583 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 584 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_15
# 585 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_LetsFight2v2_Text_4
# 588 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 590 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 19, CrobatHideout_1F_LetsFight2v2_Movement_2
# 591 "data/maps/CrobatHideout_1F/scripts.pory"
	applymovement 13, CrobatHideout_1F_LetsFight2v2_Movement_3
# 592 "data/maps/CrobatHideout_1F/scripts.pory"
	waitmovement 0
# 593 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_15
# 594 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_LetsFight2v2_Text_5
# 597 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 599 "data/maps/CrobatHideout_1F/scripts.pory"
	playse SE_M_DIVE
# 600 "data/maps/CrobatHideout_1F/scripts.pory"
	fadescreen FADE_TO_WHITE
# 601 "data/maps/CrobatHideout_1F/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 602 "data/maps/CrobatHideout_1F/scripts.pory"
	delay 48
# 603 "data/maps/CrobatHideout_1F/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 605 "data/maps/CrobatHideout_1F/scripts.pory"
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
# 606 "data/maps/CrobatHideout_1F/scripts.pory"
	msgbox CrobatHideout_1F_LetsFight2v2_Text_6
# 609 "data/maps/CrobatHideout_1F/scripts.pory"
	closemessage
# 611 "data/maps/CrobatHideout_1F/scripts.pory"
	setvar VAR_CROBAT_HIDEOUT_STATE, 3
# 613 "data/maps/CrobatHideout_1F/scripts.pory"
	warp MAP_YIFU_CITY, 33, 13
	goto CrobatHideout_1F_LetsFight2v2_1


# 41 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SeenByGrunt_Movement_0:
# 41 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_down
	step_end

# 44 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SeenByGrunt_Movement_1:
# 44 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
# 44 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
# 44 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 44 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 44 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 90 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SeenByGrunt_Movement_2:
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	lock_facing_direction
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_down
# 90 "data/maps/CrobatHideout_1F/scripts.pory"
	unlock_facing_direction
	step_end

# 101 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SeenByGrunt_Movement_3:
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_down
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 101 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 240 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_0:
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 240 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
	step_end

# 241 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_1:
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_right
# 241 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
	step_end

# 242 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_2:
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_up
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 242 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
	step_end

# 243 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_3:
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
# 243 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_faster_left
	step_end

# 259 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_4:
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
# 259 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
	step_end

# 261 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_5:
# 261 "data/maps/CrobatHideout_1F/scripts.pory"
	face_right
	step_end

# 262 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_6:
# 262 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
# 262 "data/maps/CrobatHideout_1F/scripts.pory"
	lock_facing_direction
# 262 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 262 "data/maps/CrobatHideout_1F/scripts.pory"
	unlock_facing_direction
	step_end

# 263 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_7:
# 263 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_left
	step_end

# 268 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_8:
# 268 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_faster_up
	step_end

# 269 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_9:
# 269 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 275 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_Trigger_4V1_Left_Movement_10:
# 275 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 275 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 275 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 275 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
	step_end

# 285 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_PlayerGets4V1d_Movement_0:
# 286 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
# 286 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 287 "data/maps/CrobatHideout_1F/scripts.pory"
	face_left
# 287 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 288 "data/maps/CrobatHideout_1F/scripts.pory"
	face_right
# 288 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 289 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
	step_end

# 293 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_PlayerGets4V1d_Movement_1:
# 293 "data/maps/CrobatHideout_1F/scripts.pory"
	lock_facing_direction
# 293 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_down
# 293 "data/maps/CrobatHideout_1F/scripts.pory"
	unlock_facing_direction
	step_end

# 312 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SamuraiOffersHelp_Movement_0:
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 312 "data/maps/CrobatHideout_1F/scripts.pory"
	face_left
	step_end

# 315 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_SamuraiOffersHelp_Movement_1:
# 315 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
# 315 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 315 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 315 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 348 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_BattleSamuraiBackToBack_Movement_0:
# 348 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_left
	step_end

# 349 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_BattleSamuraiBackToBack_Movement_1:
# 349 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_right
	step_end

# 368 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_0:
# 368 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
# 368 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
	step_end

# 378 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1:
# 378 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_up
	step_end

# 386 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2:
# 386 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
	step_end

# 428 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_3:
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	face_right
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 428 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
	step_end

# 429 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4:
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	face_left
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 429 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
	step_end

# 441 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5:
# 441 "data/maps/CrobatHideout_1F/scripts.pory"
	jump_in_place_up
	step_end

# 461 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_6:
# 461 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 461 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 461 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
	step_end

# 486 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_7:
# 486 "data/maps/CrobatHideout_1F/scripts.pory"
	face_up
	step_end

# 508 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_8:
# 508 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 508 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_right
# 508 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
	step_end

# 509 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_9:
# 509 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_right
# 509 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_up
# 509 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
	step_end

# 512 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_10:
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	emote_exclamation_mark
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_up
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_up
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_fast_up
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	face_down
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 512 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 515 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_11:
# 515 "data/maps/CrobatHideout_1F/scripts.pory"
	zubats_align
# 515 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 515 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 533 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_12:
# 533 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_down
# 533 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_down
# 533 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_down
# 533 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_down
	step_end

# 574 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_LetsFight2v2_Movement_0:
# 574 "data/maps/CrobatHideout_1F/scripts.pory"
	jump_in_place_left
	step_end

# 582 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_LetsFight2v2_Movement_1:
# 582 "data/maps/CrobatHideout_1F/scripts.pory"
	jump_in_place_right
	step_end

# 590 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_LetsFight2v2_Movement_2:
# 590 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_up
# 590 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 590 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 590 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_left
# 590 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

# 591 "data/maps/CrobatHideout_1F/scripts.pory"
CrobatHideout_1F_LetsFight2v2_Movement_3:
# 591 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_up
# 591 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 591 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
# 591 "data/maps/CrobatHideout_1F/scripts.pory"
	walk_in_place_fast_right
# 591 "data/maps/CrobatHideout_1F/scripts.pory"
	delay_16
	step_end

CrobatHideout_1F_SeenByGrunt_Text_0:
# 48 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Zubat Grunt$"

CrobatHideout_1F_SeenByGrunt_Text_1:
# 50 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Who the heck're you?!$"

CrobatHideout_1F_SeenByGrunt_Text_2:
# 60 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "{PLAYER}, nice to meet you!$"

CrobatHideout_1F_SeenByGrunt_Text_3:
# 61 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I'm the new recruit!$"

CrobatHideout_1F_SeenByGrunt_Text_4:
# 62 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Are you a criminal?$"

CrobatHideout_1F_SeenByGrunt_Text_5:
# 70 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I don' know no {PLAYER}!\n"
	.string "This ain't no tea party!\p"
	.string "You a spy? Ya don' work with the\n"
	.string "Samurai or somethin', do ya?$"

CrobatHideout_1F_SeenByGrunt_Text_6:
# 76 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Oh, right, 'course, the new recruit!\p"
	.string "(Why am I never in the loop?…)\p"
	.string "Wait… Where's yer uniform?$"

CrobatHideout_1F_SeenByGrunt_Text_7:
# 83 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Duh, what dum' question is that?\p"
	.string "…Wait…\n"
	.string "You're not a Crobat Shadow, are ya?$"

CrobatHideout_1F_SeenByGrunt_Text_8:
# 96 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Ah, crappers! Hideout's compromised!\p"
	.string "We've got an intruder!\n"
	.string "BOSS!! BOOOSSSS!!!$"

CrobatHideout_1F_EventScript_Grunt1_Text_0:
# 113 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I bet yer the intruder!\n"
	.string "Yeah, I'm smart like that!$"

CrobatHideout_1F_EventScript_Grunt1_Text_1:
# 114 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Boss, help us!$"

CrobatHideout_1F_EventScript_Grunt1_Text_2:
# 118 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Whaddyawant? Ya got nothin' on us!\n"
	.string "Err I mean, we done nothin' wrong!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_0:
# 127 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "What? I'm not paintin' Poké Balls to\n"
	.string "look like Ultra Balls!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_1:
# 128 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Alright alright, ya got me!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_2:
# 132 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I'm sure this is all super legal, but\n"
	.string "dontcha dare say a thing!$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_0:
# 142 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yer not here to help with the laundry,\n"
	.string "are ya?$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_1:
# 144 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Hung me out to dry…$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_2:
# 148 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I always end up on laundry duty, even\n"
	.string "when it's someone else's turn…$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_0:
# 158 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Where d'ya think yer goin', cutie pie?$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_1:
# 160 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Fine, go where ya want then, sheesh!$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_2:
# 164 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yer laughin' now, but our boss is\n"
	.string "gonna stomp on ya real good!$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_0:
# 174 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Trespassin's against the law, ya\n"
	.string "know?$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_1:
# 176 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Kids these days, I swear!$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_2:
# 180 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "We ain't gon' take this invasion of our\n"
	.string "privacy lyin' down!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_0:
# 190 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "This is our super secret hideout! Yer\n"
	.string "not wanted 'ere!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_1:
# 192 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yer ruinin' everythin'!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_2:
# 196 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Our boss takes good care of us!\n"
	.string "Everythin' was fine an' dandy 'til you\l"
	.string "showed up!$"

CrobatHideout_1F_EventScript_Samurai_Text_0:
# 204 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Samurai$"

CrobatHideout_1F_EventScript_Samurai_Text_1:
# 206 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Quiet! The leader of the Crobat\n"
	.string "Shadows is in the next room!\p"
	.string "You're a trainer, yes? You have a wild\n"
	.string "look in your eyes… Like you're itching\l"
	.string "for a fight!\p"
	.string "Shall we join forces for the\n"
	.string "inevitable confrontation?$"

CrobatHideout_1F_EventScript_LaundrySchedule_Text_0:
# 219 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "WEEKLY LAUNDRY SCHEDULE\n"
	.string "MON - Hiro\l"
	.string "TUE - Hiro\l"
	.string "WED - Mei\l"
	.string "THU - Kevin\l"
	.string "FRI - Hiro\l"
	.string "SAT - Saki\l"
	.string "SUN - Hiro$"

CrobatHideout_1F_PlayerGets4V1d_Text_0:
# 296 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Dontcha take another step!$"

CrobatHideout_1F_PlayerGets4V1d_Text_1:
# 301 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "We're 'ere to end ya!$"

CrobatHideout_1F_SamuraiOffersHelp_Text_0:
# 307 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "You sure are elusive! I finally caught\n"
	.string "up with your trail!\p"
	.string "Good work finding the Crobat Shadows'\n"
	.string "lair, we'd been on the lookout for a\l"
	.string "while!$"

CrobatHideout_1F_SamuraiOffersHelp_Text_1:
# 321 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Oh, you were in the midst of getting\n"
	.string "attacked by these four delinquents,\l"
	.string "were you not? Let me help! I can\l"
	.string "handle two at a time!$"

CrobatHideout_1F_SamuraiOffersHelp_Text_2:
# 328 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Hey, no fair! This was s'posed to be a\n"
	.string "four on one situation!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_0:
# 337 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "No more!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_1:
# 339 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Please let me live!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_2:
# 344 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Ayayaya! Jus' wait til the Boss hears\n"
	.string "of this!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_3:
# 353 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Nicely done!\n"
	.string "What is your name, child?\p"
	.string "… … …{PLAYER}!\n"
	.string "I see you have skill!\p"
	.string "We have to take their leader down!\n"
	.string "Follow me, {PLAYER}!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_0:
# 382 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Boss, uh, the intruder's 'ere!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1:
# 389 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Crobat Boss$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_2:
# 391 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yeah - I can see that, Kevin… As\n"
	.string "always, thank you for your input!\p"
	.string "Did one man and a puny lil' brat jus'\n"
	.string "wipe through our whole squad like it\l"
	.string "was nothin'? Is that what happened?\p"
	.string "Wait a second… I know this kid!\p"
	.string "Yer the annoyin' brat that ruined us a\n"
	.string "good muggin' back in Beachbound\l"
	.string "Route!\p"
	.string "What the hell, kid? Why're ya always\n"
	.string "all up in our business? D'ya think yer\l"
	.string "the law or somethin'?$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_3:
# 403 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I make the law here! You're under\n"
	.string "arrest, you thug!\n"
	.string "I'm taking you in for the PokéMart\l"
	.string "robbery!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_4:
# 412 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Bahaha! Don't make me laugh! Ya'll\n"
	.string "never get m-$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_5:
# 423 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Wait, a robbery? Which one of ya goons\n"
	.string "did this?$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_6:
# 434 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Well bravaw! You've jus' blown our\n"
	.string "cover, ya bumblin' idjets!\p"
	.string "A robbery right here in Yifu City? Jus'\n"
	.string "what were ya thinkin'?\p"
	.string "I told y'all to lay low!\n"
	.string "We can't deal with this much heat!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_7:
# 445 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Cut the chatter, you lowlife crook!\p"
	.string "Your reign of terror has been going on\n"
	.string "for too long!\p"
	.string "You are under arrest, I said!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_8:
# 453 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Nope, ya ain't arrestin' me!\p"
	.string "Golbat, to me!!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_9:
# 471 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "I trust ya to cover our backs, yeah?$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_10:
# 480 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Golbat Admins$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_11:
# 482 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Yes boss!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_12:
# 494 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "No fancy Samurai and no lil' privileged\n"
	.string "scrub ever gonna stop us!\p"
	.string "We're the Crobat Shadows, and we're\n"
	.string "always one step ahead of ya!\p"
	.string "Kid… Careful who ya team up with.$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_13:
# 504 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Zubat! Align!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_14:
# 528 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Cough… cough…\n"
	.string "They're gone!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_15:
# 537 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Golbat Admin$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_16:
# 539 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Prepare to be crushed!$"

CrobatHideout_1F_LetsFight2v2_Text_0:
# 552 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Let us join forces, {PLAYER}!$"

CrobatHideout_1F_LetsFight2v2_Text_1:
# 568 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "H-how'd that happen?!$"

CrobatHideout_1F_LetsFight2v2_Text_2:
# 570 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Ugh, that's humiliatin'…$"

CrobatHideout_1F_LetsFight2v2_Text_3:
# 578 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Ya dumball, ya made us lose!$"

CrobatHideout_1F_LetsFight2v2_Text_4:
# 586 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Naw I didn't! 'Twas yer fault!$"

CrobatHideout_1F_LetsFight2v2_Text_5:
# 595 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Nevermind that! Let's scram!$"

CrobatHideout_1F_LetsFight2v2_Text_6:
# 607 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Cough… Let's get out of here!$"

CrobatHideout_1F_LetsFight2v2_Text_7:
# 623 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Aw, man!$"

CrobatHideout_1F_LetsFight2v2_Text_8:
# 625 "data/maps/CrobatHideout_1F/scripts.pory"
	.string "Mama!$"
