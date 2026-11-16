LittlerootTown_MaysHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_MaysHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 2, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 6, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 1, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
LittlerootTown_MaysHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1, LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 1, 1
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, FEMALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, FEMALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	end

LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RivalsHouse_1F_EventScript_RivalMom::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, RivalsHouse_1F_EventScript_RivalTooBusy
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalTooBusy::
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalIsOnRoute103::
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_GoHomeEverySoOften::
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalSibling::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, FEMALE
	applywaitmovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	call_if_ne VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
	return

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

RivalsHouse_1F_Text_OhYoureTheNewNeighbor:
	.string "או, שלום. ומי את{EMIT_HEY}?\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "אה, את{EMIT_HEY} {PLAYER}{KUN}, השכ{SWAP_NUN}{ADD_HEY} החדש שלנו\n"
	.string "בבית הסמוך! היי!\p"
	.string "יש לנו {STR_VAR_1} בערך באותו\n"
	.string "גיל כמוך.\p"
	.string "ה{STR_VAR_1} שלנו נרגש{EMIT_TAF} להכיר חברים חדשים.\p"
	.string "ה{STR_VAR_1} שלנו נמצא{EMIT_TAF} למעלה, אני חושבת.$"

RivalsHouse_1F_Text_LikeChildLikeFather:
	.string "הילד{EMIT_HEY}, כמו האבא.\p"
	.string "בעלי משוגע על פוקימון כמו\n"
	.string "הילד{EMIT_HEY} שלנו.\p"
	.string "אם הוא לא במעבדה שלו, הוא כנראה\n"
	.string "מפשפש בין שדות הדשא.$"

RivalsHouse_1F_Text_TooBusyToNoticeVisit:
	.string "זה {RIVAL}!\p"
	.string "אני מניחה שהילד{EMIT_HEY} שלנו עסוקה מדי\n"
	.string "בפוקימון מאשר להבחין שהגעתP\l"
	.string "לבקר, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_WentOutToRoute103:
	.string "או, {RIVAL} יצא{EMIT_HEY} לדרך 301\n"
	.string "רק לפני זמן קצר.\p"
	.string "הילד{EMIT_HEY}, כמו האבא.\p"
	.string "{RIVAL} לא מסוגל{EMIT_TAF} להיות בבית.$"

RivalsHouse_1F_Text_ShouldGoHomeEverySoOften:
	.string "אני חושבת שזה נפלא לאנשים\n"
	.string "לטייל עם פוקימון.\p"
	.string "אבל צריך לחזור הביתה מדי פעם\n"
	.string "ליידע את אמא שלך שהכל בסדר.\p"
	.string "היא אולי לא תגיד את זה, אבל אני בטוח שהיא\n"
	.string "דואגת לך, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_MayWhoAreYou:
	.string "הא?\n"
	.string "מי… מי אתה?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "אה, אתה {PLAYER}{KUN}.\n"
	.string "אז המעבר שלך היה היום.\p"
	.string "אמ… אני מאי.\n"
	.string "שמחה לפגוש אותך!\p"
	.string "אני…\n"
	.string "יש לי מן חלום כזה להיות חברה\l"
	.string "של פוקימונים מכל העולם.\p"
	.string "אני… אני שמעתי עלייך, {PLAYER}{KUN},\n"
	.string "מאבא שלי, פרופ. בירץ'.\p"
	.string "קיוויתי שתהיה נחמד, {PLAYER}{KUN}, \n"
	.string "ונוכל להיות חברים.\p"
	.string "או, זה מגוחך, לא?\n"
	.string "אני… רק עכשיו פגשתי אותך, {PLAYER}{KUN}.\p"
	.string "חיחי…\p"
	.string "או, לא! שכחתי!\p"
	.string "אני אמורה לעזור לאבא שלי לתפוס\n"
	.string "פוקימון פרוע!\p"
	.string "{PLAYER}{KUN}, אני אדבר איתך אחר כך!$"

RivalsHouse_1F_Text_BrendanWhoAreYou:
	.string "היי!\n"
	.string "את…\p"
	.string "מי את?\p"
	.string "אה, את {PLAYER}, לא?\n"
	.string "עברת לבית ליד, נכון?\p"
	.string "אני לא ידעתי שאת בת.\p"
	.string "אבא, פרופ. בירץ', אמר שהשכן\n"
	.string "לידינו הוא הילד של מנהיג המכון,\l"
	.string "אז הנחתי שהוא התכוון לבן.\p"
	.string "שמי ברנדן.\n"
	.string "אז, היי, שכנה!\p"
	.string "הא? היי, {PLAYER}, אין לך\n"
	.string "פוקימון?\p"
	.string "את רוצה שאני אתפוס לך אחד?\p"
	.string "או, אוף, שכחתי…\p"
	.string "אני אמור לעזור לאבא שלי לתפוס\n"
	.string "פוקימון פרוע.\p"
	.string "בפעם אחרת, בסדר?$"

RivalsHouse_1F_Text_DoYouHavePokemon:
	.string "היי, שכ{SWAP_NUN}{ADD_HEY}!\p"
	.string "כבר יש לך פוקימון משלך?$"
