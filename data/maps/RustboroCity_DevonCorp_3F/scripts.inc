RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "אני מר סטון, הנשיא של\n"
	.string "תאגיד דבון.\p"
	.string "הרגע שמעתי עליך!\p"
	.string "הצלת חבר צוות שלנו לא פעם אחת,\n"
	.string "אלא פעמיים!\p"
	.string "יש לי בקשה מאיש{ADD_HEY} מדהי{SWAP_MEM}{ADD_HEY} כמוך.\p"
	.string "אני מבין שאת{EMIT_HEY} בדרך למסור חבילה\n"
	.string "למספנה שבסלייטפורט.\p"
	.string "ובכן, בדרך, תוכל{ADD_YUD} לעצור בעיירת\n"
	.string "דופורד?\p"
	.string "קיוויתי שתוכל{ADD_YUD} למסור מכתב\n"
	.string "לסטיבן שבדופורד.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "מר סטון: עכשיו, עליך לדעת שאני\n"
	.string "נשיא נהדר.\p"
	.string "אז, לעולם לא אהיה כה קמצן שאבקש טובה\n"
	.string "מבלי לתת דבר בתמורה.\p"
	.string "לכן אני רוצה שתיקח{ADD_YUD} את זה!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} קיבל{ADD_HEY} את הפוקינווט.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "מר סטון: המכשיר הזה…\p"
	.string "זה הפוקימון נווט, או בקיצור\n"
	.string "פוקינווט.\p"
	.string "זה כלי שאין בלעדיו לכל מאמן\n"
	.string "שיוצא להרפתקה.\p"
	.string "יש בו מפה של מחוז הואן.\p"
	.string "תוכל{ADD_YUD} לבדוק בקלות את מיקומן של\n"
	.string "דופורד וסלייטפורט!\p"
	.string "דרך אגב, שמעתים ששני צוותי פשע ערמומיים\n"
	.string "מגמה ואקווה, אני מאמין--\l"
	.string "גורמים לצרות ברחבי האזור.\p"
	.string "לדעתי עדיף שתנוח{ADD_YUD} קצת לפני\n"
	.string "שתמשי{SWAP_CHAF}{ADD_YUD} בדרכך.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "מר סטון: ובכן, {PLAYER}{KUN},\n"
	.string "צא{ADD_YUD} בזהירות ובתשומת לב!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "מר סטון: אני סומך עליך!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "מר סטון: מסרת את המכתב שלי?\n"
	.string "תודה רבה לך!\p"
	.string "זו דרכי להודות לך.\n"
	.string "זה אמור לעזור לך כמאמ{SWAP_NUN}{ADD_TAF}.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "מר סטון: כשפוקימון מחזיק את\n"
	.string "עוד נ״נ, הוא יקבל חלק\l"
	.string "מנקודות הניסיון מהקרב.\p"
	.string "הוא יקבל ניסיון גם אם לא נלחם\n"
	.string "בעצמו.\p"
	.string "אפשר לומר שעוד נ״נ שימושי מאוד\n"
	.string "לגידול פוקימונים חלשים.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "מר סטון: מאז צעירותי הקדשתי את\n"
	.string "כולי לעבודה.\p"
	.string "כתוצאה מכך, אינני בקיא באופנות\n"
	.string "ובדברים מהסוג הזה.\p"
	.string "אבל האם כל הצעירים בימינו רוצים\n"
	.string "להיות מאמנים בליגת הפוקימון?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "זהו הקומה השלישית של תאגיד דבון.\p"
	.string "משרד הנשיא נמצא בקומה הזו.\p"
	.string "בכל מקרה, איני יכול לבטא כמה אני\n"
	.string "מודה על מה שעשית.\p"
	.string "המ… דרך אגב, אותה החבילה\n"
	.string "שהחזרת לנו…\p"
	.string "תוכל{ADD_YUD} למסור אותה למספנה\n"
	.string "שבסלייטפורט?\p"
	.string "זה יהיה נורא אם הפושעים האלה\n"
	.string "ינסו לגנוב אותה שוב.\p"
	.string "אה… היהיהי, אז, אה, אפשר לסמוך\n"
	.string "עליך שתעש{EMIT_HEY}{ADD_YUD} זאת?\p"
	.string "אה, נכון.\n"
	.string "תוכל{ADD_YUD} לחכות כאן רגע?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "הנשיא שלנו רוצה\n"
	.string "לדבר איתך.\p"
	.string "בבקשה, בוא{ADD_YUD} איתי.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "בבקשה, המש{ADD_YUD}{SWAP_CHAF}{ADD_YUD} פנימה.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "אם תבקר{ADD_YUD} במספנה שבסלייטפורט,\n"
	.string "כדאי לך לפגוש את הקפטן סטרן.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "המוצרים החדשים של דבון - הכדור חוזר\n"
	.string "והכדור עצר, הפכו לפופולרים\l"
	.string "מאוד בקרב מאמנים.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "זוהי תצוגה של אבנים ומינרלים נדירים\n"
	.string "שהורכבה על ידי הנשיא.$"

