TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "זוהי גבעת המאמנים שבה\n"
	.string "תוכל{ADD_YUD} להנות מקרבות תג עם מאמנים\l"
	.string "רבים.\p"
	.string "לרוע המזל, אנחנו עדיין\n"
	.string "מתכוננים. אנא חז{EMIT_VAV}ר{ADD_YUD} מאוחר יותר!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "שלום!\p"
	.string "זוהי גבעת המאמנים שבה\n"
	.string "תוכל{ADD_YUD} להנות מקרבות תג עם מאמנים\l"
	.string "רבים!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "האם זה הביקור הראשון שלך כאן?\p"
	.string "לפני שאת{EMIT_HEY} נכנס{ADD_TAF}, אנא שמ{EMIT_VAV}ר{ADD_YUD}\n"
	.string "את המשחק שלך.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "בוא{ADD_YUD} נראה…\n"
	.string "המאמנים שנמצאים כאן עכשיו הם…\p"
	.string "עד קומה מס' {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "בוא{ADD_YUD} נראה…\n"
	.string "המאמנים שנמצאים כאן עכשיו הם…\p"
	.string "נראה שיש מאמנים שנאספו\n"
	.string "בכל חדר.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לאתגר את\n"
	.string "המאמנים הממתינים?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "אני אתזמן את ההתקדמות שלך.\n"
	.string "בהצלחה!\p"
	.string "היכון…\p"
	.string "הכן…\p"
	.string "צא!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "אנא בקר{ADD_YUD} אותנו שוב!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "זה חבל.\p"
	.string "אני חושב שהשקעת מאמץ\n"
	.string "עצום בקרבות שלך.\p"
	.string "אנא חז{EMIT_VAV}ר{ADD_YUD} ונס{EMIT_HEY}{ADD_YUD} שוב!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "אני מקווה שתית{SWAP_NUN}{ADD_YUD} את המיטב שלך.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "כאשר המאמנים מחליפים מקומות,\n"
	.string "התנועה יכולה להיות קדחתנית.\p"
	.string "כדי להימנע מההמולה, העברנו\n"
	.string "את דלפק הקבלה לכאן.\p"
	.string "אני מצטער על אי הנוחות.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "תודה שהשתתפת!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "כאן בגבעת המאמנים, אנחנו עורכים\n"
	.string "אירוע שנקרא מתקפת זמן.\p"
	.string "זהו מירוץ המודד כמה זמן\n"
	.string "לוקח לך להגיע לבעלים שלנו על\l"
	.string "הגג מהדלפק הזה.\p"
	.string "הזמנים המהירים ביותר מוצגים על\n"
	.string "לוח הזמנים--נס{EMIT_HEY}{ADD_YUD} להתחרות עם\l"
	.string "החברים שלך.\p"
	.string "בקרבות מאמנים לאורך הדרך,\n"
	.string "לא יוענקו נקודות ניסיון או כסף.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "או, אני מצטער, אבל נראה שיש לך\n"
	.string "רק פוקימון אחד איתך.\p"
	.string "תזדקק{ADD_YUD} לפחות לשני פוקימונים\n"
	.string "כדי להיכנס לאירוע הזה.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "המ! המ!\p"
	.string "סוף סוף הגעת!\n"
	.string "כן, הגעת!\p"
	.string "חכ{EMIT_HEY}{ADD_YUD}! אל תגיד{ADD_YUD} את זה!\n"
	.string "אני יודע למה הגעת עד הלום\l"
	.string "לבדך!\p"
	.string "רצית לראות אותי, את הבעלים\n"
	.string "של גבעת המאמנים, כי…\p"
	.string "את{EMIT_HEY} רוצה ליצור איתי צוות תג!\n"
	.string "ווא-הווו!\p"
	.string "…אה?\n"
	.string "זה לא זה?\p"
	.string "בכל מקרה, צפיתי בך בדרכך למעלה.\n"
	.string "קרב מדהים! באמת בראבו!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "למישהו מופלא כמוך,\n"
	.string "יש לי את המתנה הכי מופלאה!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "או, לא, מלא בדברים!\n"
	.string "תחז{EMIT_VAV}ר{ADD_YUD} מאוחר יותר בשביל זה!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "או, חכ{EMIT_HEY}{ADD_YUD} רגע! האם ייתכן שהגעת\n"
	.string "לכאן במהירות מופלאה?\p"
	.string "כמה נפלא! לא היית צרי{SWAP_CHAF}{ADD_HEY}\n"
	.string "למהר כל כך כדי לראות אותי!\p"
	.string "זה כל כך משמח. אני אעדכן את לוח\n"
	.string "הזמנים בקבלה!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "אבל, או…\n"
	.string "לא היית מהיר{ADD_HEY} במיוחד בדרכך לכאן.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "אולי זה ישמח אותי יותר אם תגיע{ADD_YUD}\n"
	.string "מהר יותר בפעם הבאה.\p"
	.string "אז, אני אשמח להקים\n"
	.string "איתך צוות תג!\p"
	.string "עד שניפגש שוב, אמיגו!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "בניתי את גבעת המאמנים רק\n"
	.string "מסיבה אחת ויחידה!\p"
	.string "כדי למצוא את השותף המתאים ביותר\n"
	.string "איתו אוכל להקים צוות תג!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} דקות. {STR_VAR_2}.{STR_VAR_3} שניות.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "מי יודע איזה סוג של מאמנים\n"
	.string "ושילובי פוקימונים יש לפנינו?\p"
	.string "כל מה שאני יודע זה שאני אפיל\n"
	.string "כל מי שיעמוד בדרכי!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "שמעתי שמאמנים קשוחים מגיעים לגבעת\n"
	.string "המאמנים מכל רחבי העולם.\p"
	.string "אני לא יכול לחכות לבדוק את המים!\p"
	.string "אני אפיל כל מי שיעמוד בדרכי!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "את{EMIT_HEY} רואה את לוח הזמנים שם?\p"
	.string "החברים שלי ואני מנסים לראות מי\n"
	.string "מצליח להגיע לפסגה בזמן הקצר ביותר.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "את{EMIT_HEY} יודע{ADD_TAF} מתי הם פותחים\n"
	.string "את המקום הזה?\p"
	.string "אני מחכה כאן כדי להיות המתמודד\n"
	.string "הראשון אי פעם!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לחזור\n"
	.string "לדלפק הקבלה?$"
