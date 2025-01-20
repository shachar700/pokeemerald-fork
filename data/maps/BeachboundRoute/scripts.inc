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


BeachboundRoute_EventScript_Scrub2::
# 142 "data/maps/BeachboundRoute/scripts.pory"
	trainerbattle_single TRAINER_SCRUB_2, BeachboundRoute_EventScript_Scrub2_Text_0, BeachboundRoute_EventScript_Scrub2_Text_1
# 147 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Scrub2_Text_2
# 148 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Scrub2_Text_3
# 149 "data/maps/BeachboundRoute/scripts.pory"
	release
	end


BeachboundRoute_EventScript_SomeoneCallingForHelp::
# 154 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 156 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0
# 157 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_1
# 161 "data/maps/BeachboundRoute/scripts.pory"
	playse SE_PIN
# 162 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 163 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 164 "data/maps/BeachboundRoute/scripts.pory"
	waitse
# 165 "data/maps/BeachboundRoute/scripts.pory"
	delay 48
# 167 "data/maps/BeachboundRoute/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 168 "data/maps/BeachboundRoute/scripts.pory"
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 2
# 170 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_WhereAreYouGoing::
# 174 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 176 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0
# 177 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_WhereAreYouGoing_Text_0
# 183 "data/maps/BeachboundRoute/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 184 "data/maps/BeachboundRoute/scripts.pory"
	switch VAR_RESULT
# 185 "data/maps/BeachboundRoute/scripts.pory"
	case DIR_EAST, BeachboundRoute_EventScript_WhereAreYouGoing_3
# 187 "data/maps/BeachboundRoute/scripts.pory"
	case DIR_WEST, BeachboundRoute_EventScript_WhereAreYouGoing_4
# 189 "data/maps/BeachboundRoute/scripts.pory"
	case DIR_SOUTH, BeachboundRoute_EventScript_WhereAreYouGoing_5
BeachboundRoute_EventScript_WhereAreYouGoing_1:
# 192 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 194 "data/maps/BeachboundRoute/scripts.pory"
	release
	return

BeachboundRoute_EventScript_WhereAreYouGoing_3:
# 186 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1

BeachboundRoute_EventScript_WhereAreYouGoing_4:
# 188 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1

BeachboundRoute_EventScript_WhereAreYouGoing_5:
# 190 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_2
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1


BeachboundRoute_EventScript_Mugging_Left::
# 198 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 199 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1
# 200 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 201 "data/maps/BeachboundRoute/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 202 "data/maps/BeachboundRoute/scripts.pory"
	call BeachboundRoute_EventScript_Mugging
# 203 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_Mugging_Right::
# 207 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 208 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0
# 209 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 210 "data/maps/BeachboundRoute/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 211 "data/maps/BeachboundRoute/scripts.pory"
	call BeachboundRoute_EventScript_Mugging
# 212 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_Mugging_Center::
# 216 "data/maps/BeachboundRoute/scripts.pory"
	lock
# 217 "data/maps/BeachboundRoute/scripts.pory"
	call BeachboundRoute_EventScript_Mugging
# 218 "data/maps/BeachboundRoute/scripts.pory"
	release
	return


BeachboundRoute_EventScript_Mugging::
# 223 "data/maps/BeachboundRoute/scripts.pory"
	compare VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 3
	goto_if_lt BeachboundRoute_EventScript_Mugging_2
# 340 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_SOUTH
# 341 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 342 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_16
BeachboundRoute_EventScript_Mugging_1:
# 349 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_0
# 350 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_1
# 351 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_1
# 352 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 24
# 353 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 354 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 356 "data/maps/BeachboundRoute/scripts.pory"
	trainerbattle_two_trainers TRAINER_GRUNT_BEACHBOUND_ROUTE_1, BeachboundRoute_EventScript_Mugging_Text_17, TRAINER_GRUNT_BEACHBOUND_ROUTE_2, BeachboundRoute_EventScript_Mugging_Text_18
# 363 "data/maps/BeachboundRoute/scripts.pory"
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 4
# 365 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, Common_Movement_WalkInPlaceFasterRight
# 366 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 367 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_19
# 368 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_20
# 371 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 373 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, Common_Movement_WalkInPlaceFasterRight
# 374 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 375 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_19
# 376 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_21
# 379 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 381 "data/maps/BeachboundRoute/scripts.pory"
	delay 24
# 383 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 384 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_22
# 389 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 391 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, Common_Movement_WalkInPlaceFasterDown
# 392 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 393 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_10
# 394 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_23
# 397 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 399 "data/maps/BeachboundRoute/scripts.pory"
	delay 24
# 401 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_2
# 402 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 404 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 405 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_24
# 408 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 410 "data/maps/BeachboundRoute/scripts.pory"
	delay 48
# 412 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_3
# 413 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 415 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 416 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_25
# 421 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 423 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_NORTH
# 425 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 426 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_26
# 429 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 431 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_4
# 432 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_4
# 433 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 434 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 435 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_5
# 436 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_5
# 437 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, BeachboundRoute_EventScript_Mugging_Movement_5
# 438 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 439 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 440 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 25
# 442 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_6
# 443 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_7
# 444 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_8
# 445 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, BeachboundRoute_EventScript_Mugging_Movement_9
# 446 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 24
# 447 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 448 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 449 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 25
# 451 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 24
# 452 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 23
# 453 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 26
# 454 "data/maps/BeachboundRoute/scripts.pory"
	removeobject 25
# 455 "data/maps/BeachboundRoute/scripts.pory"
	setflag FLAG_HIDE_CROBAT_SHADOWS_BEACHBOUND_RT
# 457 "data/maps/BeachboundRoute/scripts.pory"
	delay 60
# 459 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 22, BeachboundRoute_EventScript_Mugging_Movement_10
# 460 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 22
# 462 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_27
# 463 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_28
# 468 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 471 "data/maps/BeachboundRoute/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 473 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_27
# 474 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_29
# 479 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 481 "data/maps/BeachboundRoute/scripts.pory"
	addvar VAR_PLAYER_REPUTATION, 1
# 483 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 22, BeachboundRoute_EventScript_Mugging_Movement_11
# 484 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 22
# 485 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
	return

BeachboundRoute_EventScript_Mugging_2:
# 224 "data/maps/BeachboundRoute/scripts.pory"
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 3
# 225 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, Common_Movement_WalkInPlaceFasterUp
# 226 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 228 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 229 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_1
# 232 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 234 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, Common_Movement_WalkInPlaceFasterUp
# 235 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 237 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 238 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_2
# 241 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 243 "data/maps/BeachboundRoute/scripts.pory"
	delay 40
# 245 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_SOUTH
# 246 "data/maps/BeachboundRoute/scripts.pory"
	playse SE_PIN
# 247 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 24, Common_Movement_ExclamationMark
# 248 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 249 "data/maps/BeachboundRoute/scripts.pory"
	waitse
# 250 "data/maps/BeachboundRoute/scripts.pory"
	delay 48
# 252 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 253 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_3
# 258 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 23, Common_Movement_FaceDown
# 259 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 26, Common_Movement_FaceDown
# 260 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, Common_Movement_FaceDown
# 261 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 23
# 262 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 26
# 263 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 25
# 265 "data/maps/BeachboundRoute/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, BeachboundRoute_EventScript_Mugging_Text_4, BeachboundRoute_EventScript_Mugging_Text_5, BeachboundRoute_EventScript_Mugging_Text_6
# 276 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 278 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_0
# 279 "data/maps/BeachboundRoute/scripts.pory"
	switch VAR_RESULT
# 280 "data/maps/BeachboundRoute/scripts.pory"
	case 0, BeachboundRoute_EventScript_Mugging_7
# 290 "data/maps/BeachboundRoute/scripts.pory"
	case 1, BeachboundRoute_EventScript_Mugging_8
# 300 "data/maps/BeachboundRoute/scripts.pory"
	case 2, BeachboundRoute_EventScript_Mugging_9
BeachboundRoute_EventScript_Mugging_5:
# 311 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 313 "data/maps/BeachboundRoute/scripts.pory"
	applymovement 25, Common_Movement_WalkInPlaceFasterDown
# 314 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 315 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_10
# 316 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_11
# 319 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 321 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_NORTH
# 322 "data/maps/BeachboundRoute/scripts.pory"
	delay 40
# 324 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_12
# 325 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_13
# 328 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
# 330 "data/maps/BeachboundRoute/scripts.pory"
	turnobject 24, DIR_SOUTH
# 332 "data/maps/BeachboundRoute/scripts.pory"
	delay 24
# 334 "data/maps/BeachboundRoute/scripts.pory"
	speakername BeachboundRoute_EventScript_Mugging_Text_14
# 335 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_15
# 338 "data/maps/BeachboundRoute/scripts.pory"
	closemessage
	goto BeachboundRoute_EventScript_Mugging_1

BeachboundRoute_EventScript_Mugging_7:
# 281 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_7
	goto BeachboundRoute_EventScript_Mugging_5

BeachboundRoute_EventScript_Mugging_8:
# 291 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_8
	goto BeachboundRoute_EventScript_Mugging_5

BeachboundRoute_EventScript_Mugging_9:
# 301 "data/maps/BeachboundRoute/scripts.pory"
	msgbox BeachboundRoute_EventScript_Mugging_Text_9
	goto BeachboundRoute_EventScript_Mugging_5


BeachboundRoute_EventScript_SeeDecay::
# 489 "data/maps/BeachboundRoute/scripts.pory"
	lockall
# 491 "data/maps/BeachboundRoute/scripts.pory"
	playse SE_PIN
# 492 "data/maps/BeachboundRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 493 "data/maps/BeachboundRoute/scripts.pory"
	waitse
# 494 "data/maps/BeachboundRoute/scripts.pory"
	waitmovement 0
# 496 "data/maps/BeachboundRoute/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 497 "data/maps/BeachboundRoute/scripts.pory"
	warpsilent MAP_BEACHBOUND_ROUTE_DECAY, 43, 17
# 499 "data/maps/BeachboundRoute/scripts.pory"
	releaseall
	return


# 186 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0:
# 186 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 188 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1:
# 188 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
	step_end

# 190 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_WhereAreYouGoing_Movement_2:
# 190 "data/maps/BeachboundRoute/scripts.pory"
	walk_up
	step_end

# 349 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_0:
# 349 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 349 "data/maps/BeachboundRoute/scripts.pory"
	face_left
	step_end

# 350 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_1:
# 350 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
	step_end

# 401 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_2:
# 401 "data/maps/BeachboundRoute/scripts.pory"
	face_up
	step_end

# 412 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_3:
# 412 "data/maps/BeachboundRoute/scripts.pory"
	face_right
	step_end

# 431 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_4:
# 431 "data/maps/BeachboundRoute/scripts.pory"
	walk_up
# 431 "data/maps/BeachboundRoute/scripts.pory"
	face_down
	step_end

# 435 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_5:
# 435 "data/maps/BeachboundRoute/scripts.pory"
	face_down
# 435 "data/maps/BeachboundRoute/scripts.pory"
	zubats_align
# 435 "data/maps/BeachboundRoute/scripts.pory"
	delay_16
# 435 "data/maps/BeachboundRoute/scripts.pory"
	delay_16
	step_end

# 442 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_6:
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 442 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 443 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_7:
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 443 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 444 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_8:
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_right
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 444 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 445 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_9:
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 445 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
	step_end

# 459 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_10:
# 459 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 459 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
	step_end

# 483 "data/maps/BeachboundRoute/scripts.pory"
BeachboundRoute_EventScript_Mugging_Movement_11:
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_down
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
	walk_left
# 483 "data/maps/BeachboundRoute/scripts.pory"
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

BeachboundRoute_EventScript_Scrub2_Text_0:
# 144 "data/maps/BeachboundRoute/scripts.pory"
	.string "I am a scrub youngster whose sole\n"
	.string "purpose is to get stomped!$"

BeachboundRoute_EventScript_Scrub2_Text_1:
# 145 "data/maps/BeachboundRoute/scripts.pory"
	.string "I got stomped!$"

BeachboundRoute_EventScript_Scrub2_Text_2:
# 147 "data/maps/BeachboundRoute/scripts.pory"
	.string "Scrub2$"

BeachboundRoute_EventScript_Scrub2_Text_3:
# 148 "data/maps/BeachboundRoute/scripts.pory"
	.string "If you lost to me you should\n"
	.string "uninstall!$"

BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0:
# 156 "data/maps/BeachboundRoute/scripts.pory"
	.string "???$"

BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_1:
# 158 "data/maps/BeachboundRoute/scripts.pory"
	.string "Help! Someone help me!$"

BeachboundRoute_EventScript_WhereAreYouGoing_Text_0:
# 178 "data/maps/BeachboundRoute/scripts.pory"
	.string "Hey, you! In the red and blue clothes!\p"
	.string "Are you… Are you leaving?!\p"
	.string "Can't you be a decent human being and\n"
	.string "help me out?$"

BeachboundRoute_EventScript_Mugging_Text_0:
# 228 "data/maps/BeachboundRoute/scripts.pory"
	.string "Shady Man$"

BeachboundRoute_EventScript_Mugging_Text_1:
# 230 "data/maps/BeachboundRoute/scripts.pory"
	.string "Stop yappin', lady! Just give us yer\n"
	.string "Pokémon already!$"

BeachboundRoute_EventScript_Mugging_Text_2:
# 239 "data/maps/BeachboundRoute/scripts.pory"
	.string "C'mon, don't make this difficult! Just\n"
	.string "hand it over!$"

BeachboundRoute_EventScript_Mugging_Text_3:
# 254 "data/maps/BeachboundRoute/scripts.pory"
	.string "Just what d'you think yer doin'?\p"
	.string "Can't ya see we're in the middle of\n"
	.string "something 'ere?$"

BeachboundRoute_EventScript_Mugging_Text_4:
# 272 "data/maps/BeachboundRoute/scripts.pory"
	.string "Leave her alone!$"

BeachboundRoute_EventScript_Mugging_Text_5:
# 273 "data/maps/BeachboundRoute/scripts.pory"
	.string "Actually, I was just leaving!$"

BeachboundRoute_EventScript_Mugging_Text_6:
# 274 "data/maps/BeachboundRoute/scripts.pory"
	.string "Uh…$"

BeachboundRoute_EventScript_Mugging_Text_7:
# 282 "data/maps/BeachboundRoute/scripts.pory"
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
# 292 "data/maps/BeachboundRoute/scripts.pory"
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
# 302 "data/maps/BeachboundRoute/scripts.pory"
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
# 315 "data/maps/BeachboundRoute/scripts.pory"
	.string "Crobat Shadow$"

BeachboundRoute_EventScript_Mugging_Text_11:
# 317 "data/maps/BeachboundRoute/scripts.pory"
	.string "Uh… What's an allergory, boss?$"

BeachboundRoute_EventScript_Mugging_Text_12:
# 324 "data/maps/BeachboundRoute/scripts.pory"
	.string "Crobat boss$"

BeachboundRoute_EventScript_Mugging_Text_13:
# 326 "data/maps/BeachboundRoute/scripts.pory"
	.string "…Gonna pretend ya didn't say that.$"

BeachboundRoute_EventScript_Mugging_Text_14:
# 334 "data/maps/BeachboundRoute/scripts.pory"
	.string "Crobat Boss$"

BeachboundRoute_EventScript_Mugging_Text_15:
# 336 "data/maps/BeachboundRoute/scripts.pory"
	.string "'Nuff yappin' already! Take care of\n"
	.string "this clown, boys!$"

BeachboundRoute_EventScript_Mugging_Text_16:
# 343 "data/maps/BeachboundRoute/scripts.pory"
	.string "Can't believe it! Look who's back!\p"
	.string "Back fer another whoopin', are we?\p"
	.string "Take care of this clown, boys!$"

BeachboundRoute_EventScript_Mugging_Text_17:
# 358 "data/maps/BeachboundRoute/scripts.pory"
	.string "Aw, man!$"

BeachboundRoute_EventScript_Mugging_Text_18:
# 360 "data/maps/BeachboundRoute/scripts.pory"
	.string "Mama!$"

BeachboundRoute_EventScript_Mugging_Text_19:
# 367 "data/maps/BeachboundRoute/scripts.pory"
	.string "Zubat Grunt$"

BeachboundRoute_EventScript_Mugging_Text_20:
# 369 "data/maps/BeachboundRoute/scripts.pory"
	.string "Sorry, boss!$"

BeachboundRoute_EventScript_Mugging_Text_21:
# 377 "data/maps/BeachboundRoute/scripts.pory"
	.string "We got stomped proper, boss!$"

BeachboundRoute_EventScript_Mugging_Text_22:
# 385 "data/maps/BeachboundRoute/scripts.pory"
	.string "Ya gotta be kiddin' me…\p"
	.string "Can't even do no regular muggin' in\n"
	.string "peace anymore!\p"
	.string "Well, I ain't gonna stoop to fighting\n"
	.string "ya myself!$"

BeachboundRoute_EventScript_Mugging_Text_23:
# 395 "data/maps/BeachboundRoute/scripts.pory"
	.string "Boss, what's a stoop?$"

BeachboundRoute_EventScript_Mugging_Text_24:
# 406 "data/maps/BeachboundRoute/scripts.pory"
	.string "For the love of god, Kevin…$"

BeachboundRoute_EventScript_Mugging_Text_25:
# 417 "data/maps/BeachboundRoute/scripts.pory"
	.string "Movin' on! You've not seen the last of\n"
	.string "us, ya annoying brat!\p"
	.string "Ya better steer clear of the Crobat\n"
	.string "Shadows from now on!\p"
	.string "Let's move it, boys!$"

BeachboundRoute_EventScript_Mugging_Text_26:
# 427 "data/maps/BeachboundRoute/scripts.pory"
	.string "ZUBATS, ALIGN!!$"

BeachboundRoute_EventScript_Mugging_Text_27:
# 462 "data/maps/BeachboundRoute/scripts.pory"
	.string "Woman$"

BeachboundRoute_EventScript_Mugging_Text_28:
# 464 "data/maps/BeachboundRoute/scripts.pory"
	.string "Thank you so much for helping me!\p"
	.string "Those ruffians were about to steal my\n"
	.string "Pokémon!\p"
	.string "I don't have much to offer you as a\n"
	.string "thanks, but please take this!$"

BeachboundRoute_EventScript_Mugging_Text_29:
# 475 "data/maps/BeachboundRoute/scripts.pory"
	.string "What's your name?\n"
	.string "{PLAYER}?\p"
	.string "I'll be sure to tell everyone what a\n"
	.string "hero you are!$"
