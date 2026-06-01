BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "המקום שבו האינטליגנציה של מאמנים\n"
	.string "מועמדת למבחן!\p"
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} למפעל הקרב!\p"
	.string "אני המדריכה שלך לטורניר החלפת\n"
	.string "קרב יחידים.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לקחת חלק באתגר\n"
	.string "החלפת קרב יחידים?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "טורניר החלפת קרב יחידים\n"
	.string "הוא תחרות קרב יחיד המשתמשת\l"
	.string "רק בפוקימונים שכורים.\p"
	.string "קודם, יושאל לך שלושה\n"
	.string "פוקימונים במיוחד לאירוע הזה.\p"
	.string "באמצעות הפוקימונים השכורים שסופקו,\n"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לערוך קרב יחיד.\p"
	.string "אם תנצח{ADD_YUD}, מותר לך להחליף\n"
	.string "אחד מהפוקימונים השכורים שלך.\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} על המחזור הזה של קרב\n"
	.string "והחלפה--אם תנצח{ADD_YUD} שבע פעמים\l"
	.string "ברצף, תרוויח{ADD_YUD} נקודות קרב.\p"
	.string "אם את{EMIT_HEY} רוצה להפסיק את האתגר\n"
	.string "שלך, אנא שמ{EMIT_VAV}ר{ADD_YUD} את המשחק.\p"
	.string "אם לא תשמ{EMIT_VAV}ר{ADD_YUD}, את{EMIT_HEY} תיפסל{ADD_YUD}\n"
	.string "מהאתגר שלך.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "אנו מצפים לביקור הבא שלך.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "באיזו רמה תרצ{EMIT_HEY}{ADD_YUD} להתחרות?\n"
	.string "רמה 05 או רמה פתוחה?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "לפני שאת{EMIT_HEY} מתחיל{ADD_HEY} את האתגר שלך,\n"
	.string "אני צריך לשמור את המשחק. האם זה בסדר?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "אוקיי, אני אחזיק את הפוקימונים שלך\n"
	.string "לשמירה בזמן שאת{EMIT_HEY} מתחרה.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "בבקשה מכאן.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "תודה שהשתתפת!\p"
	.string "אני אחזיר את הפוקימונים האישיים שלך\n"
	.string "בתמורה לפוקימונים השכורים שלנו.\p"
	.string "עליי גם לשמור את תוצאות האירוע.\n"
	.string "נא להמתין.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "אני אחזיר את הפוקימונים האישיים שלך\n"
	.string "בתמורה לפוקימונים השכורים שלנו.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "ברכות! ניצחת שבע\n"
	.string "קרבות החלפת קרב רצופים!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "כהכרה ברצף 7 הניצחונות שלך,\n"
	.string "אנו מעניקים לך את נקודות הקרב האלה.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "או, או, או!\p"
	.string "נקודות הקרב שלך הגיעו למקסימום.\p"
	.string "אנא חז{EMIT_VAV}ר{ADD_YUD} לאחר שימוש\n"
	.string "בכמה נקודות קרב.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "חיכינו לך!\p"
	.string "לפני שנמשיך את האתגר שלך,\n"
	.string "עליי לשמור את המשחק.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "אני מצטער לומר את זה, אבל לא\n"
	.string "שמרת לפני שהפסקת לשחק בפעם האחרונה.\p"
	.string "כתוצאה מכך, את{EMIT_HEY} נפסלת\n"
	.string "מהאתגר שלך.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "אנחנו נחזיר לך את הפוקימונים האישיים שלך.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} קיבל{ADD_HEY} את הפרס\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "המקום שבו האינטליגנציה של מאמנים\n"
	.string "מועמדת למבחן!\p"
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} למפעל הקרב!\p"
	.string "אני המדריכה שלך לטורניר החלפת\n"
	.string "קרב זוגות.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לקחת חלק באתגר\n"
	.string "החלפת קרב זוגות?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "טורניר החלפת קרב זוגות\n"
	.string "הוא תחרות קרב זוגות המשתמשת\l"
	.string "רק בפוקימונים שכורים.\p"
	.string "קודם, יושאל לך שלושה\n"
	.string "פוקימונים במיוחד לאירוע הזה.\p"
	.string "באמצעות הפוקימונים השכורים שסופקו,\n"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לערוך קרב זוגות.\p"
	.string "אם תנצח{ADD_YUD}, מותר לך להחליף\n"
	.string "אחד מהפוקימונים השכורים שלך.\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} על המחזור הזה של קרב ו\n"
	.string "החלפה--אם תנצח{ADD_YUD} שבע פעמים ב\l"
	.string "ברצף, תרוויח{ADD_YUD} נקודות קרב.\p"
	.string "אם את{EMIT_HEY} רוצה להפסיק את האתגר\n"
	.string "שלך, אנא שמ{EMIT_VAV}ר{ADD_YUD} את המשחק.\p"
	.string "אם לא תשמ{EMIT_VAV}ר{ADD_YUD} לפני שאת{EMIT_HEY} מפסיק{ADD_HEY},\n"
	.string "את{EMIT_HEY} תיפסל{ADD_YUD}.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "ברכות על שהבסת את\n"
	.string "ראש המפעל וניצחת\l"
	.string "שבעה קרבות ברצף!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "כהכרה בעושר הידע שלך\n"
	.string "ובאינטליגנציה החדה, אנו מעניקים\l"
	.string "לך את נקודות הקרב האלה.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "הרש{EMIT_HEY}{ADD_YUD} לי להחליף את הפוקימונים שלך\n"
	.string "בתמורה לפוקימונים השכורים שלנו.\p"
	.string "אני צריך לשמור את נתוני הקרב,\n"
	.string "אז נא להמתין.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} להקליט את משחק המפעל\n"
	.string "הקרב האחרון שלך על היתר חזית הקרב שלך?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "היי!\n"
	.string "את{EMIT_HEY}, שם!\p"
	.string "האם את{EMIT_HEY} חושב{ADD_TAF} שהאירועים כאן\n"
	.string "קלים מכיוון שאינך צרי{SWAP_CHAF}{ADD_HEY} שיהיה\l"
	.string "לך צוות פוקימונים שגידלת?\p"
	.string "אני לא הייתי כזה בטוח לגבי ניצחון\n"
	.string "כזה קל.\p"
	.string "אם אין לך ידע מעמיק\n"
	.string "על פוקימונים ומהלכיהם,\l"
	.string "זה יהיה קשוח להמשיך ולנצח.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "החלפתי לפוקימון חלש…\n"
	.string "חשבתי שזה סוג טוב שיהיה לי…\p"
	.string "הם ניצחו אותנו בקלות…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "הדברים לא הלכו בדרכי\n"
	.string "בכלל.\p"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לבדוק את הפוקימונים של היריב\n"
	.string "שלך במהלך הקרב כדי לראות אם\l"
	.string "הם טובים.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "את{EMIT_HEY} יודע{ADD_TAF} איך הצוות כאן נותן לך\n"
	.string "כמה רמזים על היריב הבא שלך?\p"
	.string "טוב, אני גבר בוגר, אבל אני מתקשה\n"
	.string "להבין את הרמזים שלהם.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "כאילו, אני ממש קשוח, אבל אני משתעמם\n"
	.string "ממש בקלות, אז פשוט המשכתי להחליף\l"
	.string "ולהילחם שוב ושוב.\p"
	.string "בכל מקרה, כשהמשכתי להיכנס\n"
	.string "לאירועי החלפת קרב, שמתי לב שהם\l"
	.string "מגוונים את הפוקימונים השכורים.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "חוקי החלפת הקרב רשומים.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "איזו כותרת את{EMIT_HEY} רוצה לקרוא?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "באירוע החלפת קרב, אתם יכולים להשתמש\n"
	.string "רק בשלושה פוקימונים.\p"
	.string "בין אם אתם שוכרים או מחליפים,\n"
	.string "בצוות שלכם לא יכולים להיות שניים או יותר\l"
	.string "מאותו פוקימון.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "אתם יכולים להחליף פוקימונים רק עם\n"
	.string "המאמן שרק הרגע הבסתם.\p"
	.string "אתם יכולים להחליף רק עבור אותם פוקימונים\n"
	.string "שבהם השתמש המאמן המובס.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "אחרי כל קרב שאתם מנצחים, אתם יכולים\n"
	.string "להחליף עבור אחד מהפוקימונים של היריב\l"
	.string "המובס שלכם.\p"
	.string "אתם לא תוכלו להחליף פוקימונים\n"
	.string "עם המאמן השביעי באירוע.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "יש שתי נקודות מפתח שצריך לשים לב\n"
	.string "אליהן בעת החלפת פוקימונים.\p"
	.string "ראשית, בעת החלפה, אתם לא יכולים לבדוק\n"
	.string "את הנתונים של הפוקימון שאתם עומדים\l"
	.string "לקבל.\p"
	.string "שנית, הפוקימונים בצוות שכםך\n"
	.string "ממוקמים ברצף, בהתאם לסדר\l"
	.string "שבו שכרתם אותם.\p"
	.string "הרצף הזה נשאר ללא שינוי\n"
	.string "גם כאשר מתבצעות החלפות.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "ברמה הפתוחה, הפוקימונים השכורים\n"
	.string "והפוקימונים של המאמנים היריבים\l"
	.string "הם כולם רמה 001.$"
