BeachboundRoute_MapScripts::
# 12 "data/maps/BeachboundRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BeachboundRoute_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

BeachboundRoute_MapScripts_MAP_SCRIPT_ON_LOAD:
# 13 "data/maps/BeachboundRoute/scripts.pory"
	call BeachboundRoute_EventScript_TimeBasedEvents
	return


BeachboundRoute_EventScript_TimeBasedEvents::
# 18 "data/maps/BeachboundRoute/scripts.pory"
	setflag FLAG_TEMP_6
# 19 "data/maps/BeachboundRoute/scripts.pory"
	setflag FLAG_TEMP_7
# 21 "data/maps/BeachboundRoute/scripts.pory"
	gettimeofday
# 22 "data/maps/BeachboundRoute/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_ne BeachboundRoute_EventScript_TimeBasedEvents_2
BeachboundRoute_EventScript_TimeBasedEvents_1:
# 26 "data/maps/BeachboundRoute/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_ne BeachboundRoute_EventScript_TimeBasedEvents_5
	return

BeachboundRoute_EventScript_TimeBasedEvents_2:
# 23 "data/maps/BeachboundRoute/scripts.pory"
	clearflag FLAG_TEMP_6
	goto BeachboundRoute_EventScript_TimeBasedEvents_1

BeachboundRoute_EventScript_TimeBasedEvents_4:
# 27 "data/maps/BeachboundRoute/scripts.pory"
	clearflag FLAG_TEMP_7
	return

BeachboundRoute_EventScript_TimeBasedEvents_5:
# 26 "data/maps/BeachboundRoute/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_ne BeachboundRoute_EventScript_TimeBasedEvents_4
	return


BeachboundRoute_EventScript_RunningBoy::
# 32 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_RunningBoy_Text_0
# 33 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_RunningBoy_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_RunningGirl::
# 40 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_RunningGirl_Text_0
# 41 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_RunningGirl_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_AnnoyedGirl::
# 47 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_AnnoyedGirl_Text_0
# 48 "data/maps/BeachboundRoute/scripts.pory"
	goto_if_set FLAG_TEMP_7, BeachboundRoute_EventScript_AnnoyedGirl_1
# 53 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_AnnoyedGirl_Text_2, MSGBOX_NPC
	return

BeachboundRoute_EventScript_AnnoyedGirl_1:
# 49 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_AnnoyedGirl_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_AnnoyedBoy::
# 60 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_AnnoyedBoy_Text_0
# 61 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_AnnoyedBoy_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_Hoppip::
# 68 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 69 "data/maps/BeachboundRoute/scripts.pory"
	faceplayer
# 70 "data/maps/BeachboundRoute/scripts.pory"
	ismonseen SPECIES_HOPPIP
# 71 "data/maps/BeachboundRoute/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne BeachboundRoute_EventScript_Hoppip_2
# 74 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Hoppip_Text_1
BeachboundRoute_EventScript_Hoppip_1:
# 76 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Hoppip_Text_2
# 79 "data/maps/BeachboundRoute/scripts.pory"
	playmoncry SPECIES_HOPPIP, CRY_MODE_NORMAL
# 80 "data/maps/BeachboundRoute/scripts.pory"
	waitmoncry
# 81 "data/maps/BeachboundRoute/scripts.pory"
	release
	end

BeachboundRoute_EventScript_Hoppip_2:
# 72 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Hoppip_Text_0
	goto BeachboundRoute_EventScript_Hoppip_1


BeachboundRoute_EventScript_Wooloo::
# 87 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 88 "data/maps/BeachboundRoute/scripts.pory"
	faceplayer
# 89 "data/maps/BeachboundRoute/scripts.pory"
	ismonseen SPECIES_WOOLOO
# 90 "data/maps/BeachboundRoute/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne BeachboundRoute_EventScript_Wooloo_2
# 93 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Wooloo_Text_1
BeachboundRoute_EventScript_Wooloo_1:
# 95 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Wooloo_Text_2
# 98 "data/maps/BeachboundRoute/scripts.pory"
	playmoncry SPECIES_WOOLOO, CRY_MODE_NORMAL
# 99 "data/maps/BeachboundRoute/scripts.pory"
	waitmoncry
# 100 "data/maps/BeachboundRoute/scripts.pory"
	release
	end

BeachboundRoute_EventScript_Wooloo_2:
# 91 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Wooloo_Text_0
	goto BeachboundRoute_EventScript_Wooloo_1


BeachboundRoute_EventScript_Shepherd::
# 105 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Shepherd_Text_0
# 106 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Shepherd_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_Karu::
# 112 "data/maps/BeachboundRoute/scripts.pory"
	trainerbattle_single TRAINER_KARU, BeachboundRoute_EventScript_Karu_Text_0, BeachboundRoute_EventScript_Karu_Text_1, BeachboundRoute_EventScript_Karu_PostBattle
# 118 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Karu_Text_2
# 119 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Karu_Text_3, MSGBOX_AUTOCLOSE
	end


BeachboundRoute_EventScript_Karu_PostBattle::
# 124 "data/maps/BeachboundRoute/scripts.pory"
	setflag FLAG_TEMP_5
# 125 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 10
	return


BeachboundRoute_EventScript_Kin::
# 130 "data/maps/BeachboundRoute/scripts.pory"
	trainerbattle_single TRAINER_KIN_1, BeachboundRoute_EventScript_Kin_Text_0, BeachboundRoute_EventScript_Kin_Text_1
# 135 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Kin_Text_2
# 136 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Kin_Text_3, MSGBOX_AUTOCLOSE
	end


BeachboundRoute_EventScript_SomeoneCallingForHelp::
# 141 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 143 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0
# 144 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_1
# 148 "data/maps/BeachboundRoute/scripts.pory"
	playse SE_PIN
# 149 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 150 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 151 "data/maps/BeachboundRoute/scripts.pory"
	waitse
# 152 "data/maps/BeachboundRoute/scripts.pory"
	delay 48
# 154 "data/maps/BeachboundRoute/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 155 "data/maps/BeachboundRoute/scripts.pory"
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 2
# 157 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_WhereAreYouGoing::
# 161 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 163 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0
# 164 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_WhereAreYouGoing_Text_0
# 170 "data/maps/BeachboundRoute/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 171 "data/maps/BeachboundRoute/scripts.pory"
	switch VAR_RESULT
# 172 "data/maps/BeachboundRoute/scripts.pory"
	case DIR_EAST, BeachboundRoute_EventScript_WhereAreYouGoing_3
# 174 "data/maps/BeachboundRoute/scripts.pory"
	case DIR_WEST, BeachboundRoute_EventScript_WhereAreYouGoing_4
# 176 "data/maps/BeachboundRoute/scripts.pory"
	case DIR_SOUTH, BeachboundRoute_EventScript_WhereAreYouGoing_5
BeachboundRoute_EventScript_WhereAreYouGoing_1:
# 179 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 181 "data/maps/BeachboundRoute/scripts.pory"
	release
	return

BeachboundRoute_EventScript_WhereAreYouGoing_3:
# 173 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1

BeachboundRoute_EventScript_WhereAreYouGoing_4:
# 175 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1

BeachboundRoute_EventScript_WhereAreYouGoing_5:
# 177 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_2
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1


BeachboundRoute_EventScript_Mugging_Left::
# 185 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 186 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1
# 187 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 188 "data/maps/BeachboundRoute/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 189 "data/maps/BeachboundRoute/scripts.pory"
	call BeachboundRoute_EventScript_Mugging
# 190 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_Mugging_Right::
# 194 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 195 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0
# 196 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 197 "data/maps/BeachboundRoute/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 198 "data/maps/BeachboundRoute/scripts.pory"
	call BeachboundRoute_EventScript_Mugging
# 199 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_Mugging_Center::
# 203 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 204 "data/maps/BeachboundRoute/scripts.pory"
	call BeachboundRoute_EventScript_Mugging
# 205 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_Mugging::
# 210 "data/maps/BeachboundRoute/scripts.pory"
	compare VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 3
	goto_if_lt BeachboundRoute_EventScript_Mugging_2
# 327 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_SOUTH
# 328 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 329 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_16
BeachboundRoute_EventScript_Mugging_1:
# 336 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_0
# 337 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_1
# 338 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_1
# 339 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 24
# 340 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 341 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 343 "data/maps/BeachboundRoute/scripts.pory"
	trainerbattle_two_trainers TRAINER_GRUNT_BEACHBOUND_ROUTE_1, BeachboundRoute_EventScript_Mugging_Text_17, TRAINER_GRUNT_BEACHBOUND_ROUTE_2, BeachboundRoute_EventScript_Mugging_Text_18
# 350 "data/maps/BeachboundRoute/scripts.pory"
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 4
# 352 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, Common_Movement_WalkInPlaceFasterRight
# 353 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 354 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_19
# 355 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_20
# 358 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 360 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, Common_Movement_WalkInPlaceFasterRight
# 361 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 362 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_19
# 363 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_21
# 366 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 368 "data/maps/BeachboundRoute/scripts.pory"
	delay 24
# 370 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 371 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_22
# 376 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 378 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, Common_Movement_WalkInPlaceFasterDown
# 379 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 380 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_10
# 381 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_23
# 384 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 386 "data/maps/BeachboundRoute/scripts.pory"
	delay 24
# 388 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_2
# 389 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 391 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 392 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_24
# 395 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 397 "data/maps/BeachboundRoute/scripts.pory"
	delay 48
# 399 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_3
# 400 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 402 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 403 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_25
# 408 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 410 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_NORTH
# 412 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 413 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_26
# 416 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 418 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_4
# 419 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_4
# 420 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 421 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 422 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_5
# 423 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_5
# 424 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, BeachboundRoute_EventScript_Mugging_Movement_5
# 425 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 426 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 427 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 25
# 429 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_6
# 430 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_7
# 431 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_8
# 432 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, BeachboundRoute_EventScript_Mugging_Movement_9
# 433 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 24
# 434 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 435 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 436 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 25
# 438 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 24
# 439 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 23
# 440 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 26
# 441 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 25
# 442 "data/maps/BeachboundRoute/scripts.pory"
	setflag FLAG_HIDE_CROBAT_SHADOWS_BEACHBOUND_RT
# 444 "data/maps/BeachboundRoute/scripts.pory"
	delay 60
# 446 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 22, BeachboundRoute_EventScript_Mugging_Movement_10
# 447 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 22
# 449 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_27
# 450 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_28
# 455 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 458 "data/maps/BeachboundRoute/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 460 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_27
# 461 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_29
# 466 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 468 "data/maps/BeachboundRoute/scripts.pory"
	addvar VAR_PLAYER_REPUTATION, 1
# 470 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 22, BeachboundRoute_EventScript_Mugging_Movement_11
# 471 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 22
# 472 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
	return

BeachboundRoute_EventScript_Mugging_2:
# 211 "data/maps/BeachboundRoute/scripts.pory"
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 3
# 212 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, Common_Movement_WalkInPlaceFasterUp
# 213 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 215 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 216 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_1
# 219 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 221 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, Common_Movement_WalkInPlaceFasterUp
# 222 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 224 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 225 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_2
# 228 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 230 "data/maps/BeachboundRoute/scripts.pory"
	delay 40
# 232 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_SOUTH
# 233 "data/maps/BeachboundRoute/scripts.pory"
	playse SE_PIN
# 234 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, Common_Movement_ExclamationMark
# 235 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 236 "data/maps/BeachboundRoute/scripts.pory"
	waitse
# 237 "data/maps/BeachboundRoute/scripts.pory"
	delay 48
# 239 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 240 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_3
# 245 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, Common_Movement_FaceDown
# 246 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, Common_Movement_FaceDown
# 247 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, Common_Movement_FaceDown
# 248 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 249 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 250 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 25
# 252 "data/maps/BeachboundRoute/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, BeachboundRoute_EventScript_Mugging_Text_4, BeachboundRoute_EventScript_Mugging_Text_5, BeachboundRoute_EventScript_Mugging_Text_6
# 263 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 265 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 266 "data/maps/BeachboundRoute/scripts.pory"
	switch VAR_RESULT
# 267 "data/maps/BeachboundRoute/scripts.pory"
	case 0, BeachboundRoute_EventScript_Mugging_7
# 277 "data/maps/BeachboundRoute/scripts.pory"
	case 1, BeachboundRoute_EventScript_Mugging_8
# 287 "data/maps/BeachboundRoute/scripts.pory"
	case 2, BeachboundRoute_EventScript_Mugging_9
BeachboundRoute_EventScript_Mugging_5:
# 298 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 300 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, Common_Movement_WalkInPlaceFasterDown
# 301 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 302 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_10
# 303 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_11
# 306 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 308 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_NORTH
# 309 "data/maps/BeachboundRoute/scripts.pory"
	delay 40
# 311 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_12
# 312 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_13
# 315 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 317 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_SOUTH
# 319 "data/maps/BeachboundRoute/scripts.pory"
	delay 24
# 321 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 322 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_15
# 325 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
	goto BeachboundRoute_EventScript_Mugging_1

BeachboundRoute_EventScript_Mugging_7:
# 268 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_7
	goto BeachboundRoute_EventScript_Mugging_5

BeachboundRoute_EventScript_Mugging_8:
# 278 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_8
	goto BeachboundRoute_EventScript_Mugging_5

BeachboundRoute_EventScript_Mugging_9:
# 288 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_9
	goto BeachboundRoute_EventScript_Mugging_5


BeachboundRoute_EventScript_SeeDecay::
# 476 "data/maps/BeachboundRoute/scripts.pory"
	lockall
# 478 "data/maps/BeachboundRoute/scripts.pory"
	playse SE_PIN
# 479 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 480 "data/maps/BeachboundRoute/scripts.pory"
	waitse
# 481 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 483 "data/maps/BeachboundRoute/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 484 "data/maps/BeachboundRoute/scripts.pory"
	warpsilent MAP_BEACHBOUND_ROUTE_DECAY, 43, 17
# 486 "data/maps/BeachboundRoute/scripts.pory"
	releaseall
	return


# 173 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0:
# 173 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 175 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1:
# 175 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
	step_end

# 177 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_WhereAreYouGoing_Movement_2:
# 177 "data/maps/BeachboundRoute/scripts.pory"
	walk_up
	step_end

# 336 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_0:
# 336 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 336 "data/maps/BeachboundRoute/scripts.pory"
	face_left
	step_end

# 337 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_1:
# 337 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
	step_end

# 388 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_2:
# 388 "data/maps/BeachboundRoute/scripts.pory"
	face_up
	step_end

# 399 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_3:
# 399 "data/maps/BeachboundRoute/scripts.pory"
	face_right
	step_end

# 418 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_4:
# 418 "data/maps/BeachboundRoute/scripts.pory"
	walk_up
# 418 "data/maps/BeachboundRoute/scripts.pory"
	face_down
	step_end

# 422 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_5:
# 422 "data/maps/BeachboundRoute/scripts.pory"
	face_down
# 422 "data/maps/BeachboundRoute/scripts.pory"
	zubats_align
# 422 "data/maps/BeachboundRoute/scripts.pory"
	delay_16
# 422 "data/maps/BeachboundRoute/scripts.pory"
	delay_16
	step_end

# 429 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_6:
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 429 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 430 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_7:
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 430 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 431 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_8:
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 432 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_9:
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 432 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 446 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_10:
# 446 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 446 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
	step_end

# 470 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_11:
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 470 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

BeachboundRoute_EventScript_RunningBoy_Text_0:
# 32 "data/maps/BeachboundRoute/scripts.pory"
	.string "Little boy$"

BeachboundRoute_EventScript_RunningBoy_Text_1:
# 34 "data/maps/BeachboundRoute/scripts.pory"
	.string "Running running running!!\p"
	.string "Yaaaaaaaay!!!$"

BeachboundRoute_EventScript_RunningGirl_Text_0:
# 40 "data/maps/BeachboundRoute/scripts.pory"
	.string "Little girl$"

BeachboundRoute_EventScript_RunningGirl_Text_1:
# 42 "data/maps/BeachboundRoute/scripts.pory"
	.string "Wait for me!! It's not fair!!!$"

BeachboundRoute_EventScript_AnnoyedGirl_Text_0:
# 47 "data/maps/BeachboundRoute/scripts.pory"
	.string "Annoyed girl$"

BeachboundRoute_EventScript_AnnoyedGirl_Text_1:
# 50 "data/maps/BeachboundRoute/scripts.pory"
	.string "Hum… Could you maybe, like, leave?$"

BeachboundRoute_EventScript_AnnoyedGirl_Text_2:
# 54 "data/maps/BeachboundRoute/scripts.pory"
	.string "I wish those kids would leave…$"

BeachboundRoute_EventScript_AnnoyedBoy_Text_0:
# 60 "data/maps/BeachboundRoute/scripts.pory"
	.string "Annoyed boy$"

BeachboundRoute_EventScript_AnnoyedBoy_Text_1:
# 62 "data/maps/BeachboundRoute/scripts.pory"
	.string "I brought my date to the Lover's\n"
	.string "Meadow, but I kind of thought we'd be\l"
	.string "alone…$"

BeachboundRoute_EventScript_Hoppip_Text_0:
# 72 "data/maps/BeachboundRoute/scripts.pory"
	.string "Hoppip$"

BeachboundRoute_EventScript_Hoppip_Text_1:
# 74 "data/maps/BeachboundRoute/scripts.pory"
	.string "Leafy cat$"

BeachboundRoute_EventScript_Hoppip_Text_2:
# 77 "data/maps/BeachboundRoute/scripts.pory"
	.string "Pip!$"

BeachboundRoute_EventScript_Wooloo_Text_0:
# 91 "data/maps/BeachboundRoute/scripts.pory"
	.string "Wooloo$"

BeachboundRoute_EventScript_Wooloo_Text_1:
# 93 "data/maps/BeachboundRoute/scripts.pory"
	.string "Wool ball$"

BeachboundRoute_EventScript_Wooloo_Text_2:
# 96 "data/maps/BeachboundRoute/scripts.pory"
	.string "Bah…$"

BeachboundRoute_EventScript_Shepherd_Text_0:
# 105 "data/maps/BeachboundRoute/scripts.pory"
	.string "Shepherd$"

BeachboundRoute_EventScript_Shepherd_Text_1:
# 107 "data/maps/BeachboundRoute/scripts.pory"
	.string "I bring my Wooloo here to graze\n"
	.string "everyday.$"

BeachboundRoute_EventScript_Karu_Text_0:
# 114 "data/maps/BeachboundRoute/scripts.pory"
	.string "Please allow me to introduce you to\n"
	.string "your own defeat!$"

BeachboundRoute_EventScript_Karu_Text_1:
# 115 "data/maps/BeachboundRoute/scripts.pory"
	.string "N-nice to meet you…$"

BeachboundRoute_EventScript_Karu_Text_2:
# 118 "data/maps/BeachboundRoute/scripts.pory"
	.string "Karu$"

BeachboundRoute_EventScript_Karu_Text_3:
# 119 "data/maps/BeachboundRoute/scripts.pory"
	.string "You wiped me away there. How long\n"
	.string "have you been a wielder?$"

BeachboundRoute_EventScript_Kin_Text_0:
# 132 "data/maps/BeachboundRoute/scripts.pory"
	.string "I run several hours everyday! You\n"
	.string "literally cannot defeat me!$"

BeachboundRoute_EventScript_Kin_Text_1:
# 133 "data/maps/BeachboundRoute/scripts.pory"
	.string "Ow! I pulled a muscle!$"

BeachboundRoute_EventScript_Kin_Text_2:
# 135 "data/maps/BeachboundRoute/scripts.pory"
	.string "Kin$"

BeachboundRoute_EventScript_Kin_Text_3:
# 136 "data/maps/BeachboundRoute/scripts.pory"
	.string "You really don't look strong at all,\n"
	.string "and yet…$"

BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0:
# 143 "data/maps/BeachboundRoute/scripts.pory"
	.string "???$"

BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_1:
# 145 "data/maps/BeachboundRoute/scripts.pory"
	.string "Help! Someone help me!$"

BeachboundRoute_EventScript_WhereAreYouGoing_Text_0:
# 165 "data/maps/BeachboundRoute/scripts.pory"
	.string "Hey, you! In the red and blue clothes!\p"
	.string "Are you… Are you leaving?!\p"
	.string "Can't you be a decent human being and\n"
	.string "help me out?$"

BeachboundRoute_EventScript_Mugging_Text_0:
# 215 "data/maps/BeachboundRoute/scripts.pory"
	.string "Shady Man$"

BeachboundRoute_EventScript_Mugging_Text_1:
# 217 "data/maps/BeachboundRoute/scripts.pory"
	.string "Stop yappin', lady! Just give us yer\n"
	.string "Pokémon already!$"

BeachboundRoute_EventScript_Mugging_Text_2:
# 226 "data/maps/BeachboundRoute/scripts.pory"
	.string "C'mon, don't make this difficult! Just\n"
	.string "hand it over!$"

BeachboundRoute_EventScript_Mugging_Text_3:
# 241 "data/maps/BeachboundRoute/scripts.pory"
	.string "Just what d'you think yer doin'?\p"
	.string "Can't ya see we're in the middle of\n"
	.string "something 'ere?$"

BeachboundRoute_EventScript_Mugging_Text_4:
# 259 "data/maps/BeachboundRoute/scripts.pory"
	.string "Leave her alone!$"

BeachboundRoute_EventScript_Mugging_Text_5:
# 260 "data/maps/BeachboundRoute/scripts.pory"
	.string "Actually, I was just leaving!$"

BeachboundRoute_EventScript_Mugging_Text_6:
# 261 "data/maps/BeachboundRoute/scripts.pory"
	.string "Uh…$"

BeachboundRoute_EventScript_Mugging_Text_7:
# 269 "data/maps/BeachboundRoute/scripts.pory"
	.string "Ooh, feelin' heroic today, are we?\p"
	.string "D'ya know what we do to nosy brats\n"
	.string "who're not clever enough to mind their\l"
	.string "own business?\p"
	.string "Ya have no self-preservation\n"
	.string "instinct whatsoever, do ya?\p"
	.string "D'ya even know who we are?\p"
	.string "We're the world-famous Crobat\n"
	.string "Shadows!\p"
	.string "Thievin', muggin', wreakin' havoc… Ya\n"
	.string "name it!\p"
	.string "We're basically the allegory of crime!$"

BeachboundRoute_EventScript_Mugging_Text_8:
# 279 "data/maps/BeachboundRoute/scripts.pory"
	.string "'S a little too late fer that, don't ya\n"
	.string "think? D'ya know what we do to nosy\l"
	.string "brats who're not clever enough to\l"
	.string "mind their own business?\p"
	.string "Ya have no self-preservation\n"
	.string "instinct whatsoever, do ya?\p"
	.string "D'ya even know who we are?\p"
	.string "We're the world-famous Crobat\n"
	.string "Shadows!\p"
	.string "Thievin', muggin', wreakin' havoc… Ya\n"
	.string "name it!\p"
	.string "We're basically the allegory of crime!$"

BeachboundRoute_EventScript_Mugging_Text_9:
# 289 "data/maps/BeachboundRoute/scripts.pory"
	.string "Got nothin' to say, huh?\p"
	.string "D'ya know what we do to nosy brats\n"
	.string "who're not clever enough to mind their\l"
	.string "own business?\p"
	.string "Ya have no self-preservation\n"
	.string "instinct whatsoever, do ya?\p"
	.string "D'ya even know who we are?\p"
	.string "We're the world-famous Crobat\n"
	.string "Shadows!\p"
	.string "Thievin', muggin', wreakin' havoc… Ya\n"
	.string "name it!\p"
	.string "We're basically the allegory of crime!$"

BeachboundRoute_EventScript_Mugging_Text_10:
# 302 "data/maps/BeachboundRoute/scripts.pory"
	.string "Crobat Shadow$"

BeachboundRoute_EventScript_Mugging_Text_11:
# 304 "data/maps/BeachboundRoute/scripts.pory"
	.string "Uh… What's an allergory, boss?$"

BeachboundRoute_EventScript_Mugging_Text_12:
# 311 "data/maps/BeachboundRoute/scripts.pory"
	.string "Crobat boss$"

BeachboundRoute_EventScript_Mugging_Text_13:
# 313 "data/maps/BeachboundRoute/scripts.pory"
	.string "…Gonna pretend ya didn't say that.$"

BeachboundRoute_EventScript_Mugging_Text_14:
# 321 "data/maps/BeachboundRoute/scripts.pory"
	.string "Crobat Boss$"

BeachboundRoute_EventScript_Mugging_Text_15:
# 323 "data/maps/BeachboundRoute/scripts.pory"
	.string "'Nuff yappin' already! Take care of\n"
	.string "this clown, boys!$"

BeachboundRoute_EventScript_Mugging_Text_16:
# 330 "data/maps/BeachboundRoute/scripts.pory"
	.string "Can't believe it! Look who's back!\p"
	.string "Back fer another whoopin', are we?\p"
	.string "Take care of this clown, boys!$"

BeachboundRoute_EventScript_Mugging_Text_17:
# 345 "data/maps/BeachboundRoute/scripts.pory"
	.string "Aw, man!$"

BeachboundRoute_EventScript_Mugging_Text_18:
# 347 "data/maps/BeachboundRoute/scripts.pory"
	.string "Mama!$"

BeachboundRoute_EventScript_Mugging_Text_19:
# 354 "data/maps/BeachboundRoute/scripts.pory"
	.string "Zubat Grunt$"

BeachboundRoute_EventScript_Mugging_Text_20:
# 356 "data/maps/BeachboundRoute/scripts.pory"
	.string "Sorry, boss!$"

BeachboundRoute_EventScript_Mugging_Text_21:
# 364 "data/maps/BeachboundRoute/scripts.pory"
	.string "We got stomped proper, boss!$"

BeachboundRoute_EventScript_Mugging_Text_22:
# 372 "data/maps/BeachboundRoute/scripts.pory"
	.string "Ya gotta be kiddin' me…\p"
	.string "Can't even do no regular muggin' in\n"
	.string "peace anymore!\p"
	.string "Well, I ain't gonna stoop to fighting\n"
	.string "ya myself!$"

BeachboundRoute_EventScript_Mugging_Text_23:
# 382 "data/maps/BeachboundRoute/scripts.pory"
	.string "Boss, what's a stoop?$"

BeachboundRoute_EventScript_Mugging_Text_24:
# 393 "data/maps/BeachboundRoute/scripts.pory"
	.string "For the love of god, Kevin…$"

BeachboundRoute_EventScript_Mugging_Text_25:
# 404 "data/maps/BeachboundRoute/scripts.pory"
	.string "Movin' on! You've not seen the last of\n"
	.string "us, ya annoying brat!\p"
	.string "Ya better steer clear of the Crobat\n"
	.string "Shadows from now on!\p"
	.string "Let's move it, boys!$"

BeachboundRoute_EventScript_Mugging_Text_26:
# 414 "data/maps/BeachboundRoute/scripts.pory"
	.string "ZUBATS, ALIGN!!$"

BeachboundRoute_EventScript_Mugging_Text_27:
# 449 "data/maps/BeachboundRoute/scripts.pory"
	.string "Woman$"

BeachboundRoute_EventScript_Mugging_Text_28:
# 451 "data/maps/BeachboundRoute/scripts.pory"
	.string "Thank you so much for helping me!\p"
	.string "Those ruffians were about to steal my\n"
	.string "Pokémon!\p"
	.string "I don't have much to offer you as a\n"
	.string "thanks, but please take this!$"

BeachboundRoute_EventScript_Mugging_Text_29:
# 462 "data/maps/BeachboundRoute/scripts.pory"
	.string "What's your name?\n"
	.string "{PLAYER}?\p"
	.string "I'll be sure to tell everyone what a\n"
	.string "hero you are!$"
