BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "המקום שבו רוח הקרב של מאמנים\n"
	.string "מועמדת למבחן!\p"
	.string "אני מברך את פניך לזירת הקרב!\p"
	.string "אני המדריכה שלך לטורניר נוקאאוט קבוע!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "עכשיו, האם תרצ{EMIT_HEY} לקחת חלק\n"
	.string "באתגר זירת הקרב?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "אנו מצפים לאתגר שלך\n"
	.string "בהזדמנות אחרת!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "בזירת הקרב, אנו עורכים\n"
	.string "את טורניר נוקאאוט קבוע.\p"
	.string "כל המשתתפים נכנסים עם צוות של\n"
	.string "שלושה פוקימונים.\p"
	.string "שלושת הפוקימונים חייבים להיות מסודרים\n"
	.string "בסדר שבו הם הופיעו.\p"
	.string "במהלך הקרב, הפוקימונים יופיעו\n"
	.string "אחד בכל פעם בסדר שנקבע מראש.\p"
	.string "ברגע שפוקימון נכנס לקרב, הוא חייב\n"
	.string "להישאר בחוץ עד להכרעת הקרב.\p"
	.string "אם הקרב נשאר ללא הכרעה לאחר\n"
	.string "שלושה תורות, הוא עובר לשיפוט.\p"
	.string "אם את{EMIT_HEY} מעוניי{SWAP_NUN}{ADD_TAF} להפסיק את האתגר שלך,\n"
	.string "אנא שמ{EMIT_VAV}ר{ADD_YUD} את המשחק.\p"
	.string "אם לא תשמ{EMIT_VAV}ר{ADD_YUD}, לא תוכל{ADD_YUD}\n"
	.string "להמשיך עם האתגר שלך.\p"
	.string "אם תבצע את ההישג של ניצחון על\n"
	.string "שבעה מאמנים ברצף,\l"
	.string "אנו נעניק לך נקודות קרב.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "לפני שאני מראה לך את הדרך לזירת\n"
	.string "הקרב, את{EMIT_HEY} חייב{ADD_TAF} לשמור. האם זה בסדר?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "זירת הקרב מציעה שתי רמות\n"
	.string "של אתגר, רמה 05 ורמה פתוחה.\l"
	.string "באיזה תבחר{ADD_YUD}?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "בסדר גמור, עכשיו בחר{ADD_YUD} את שלושת\n"
	.string "הפוקימונים שלך, בבקשה.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "מאתגר{ADD_TAF} יקר{ADD_HEY} שלי!\p"
	.string "אין לך את שלושת הפוקימונים\n"
	.string "הנדרשים לכניסה.\p"
	.string "כדי לעמוד בתנאי, את{EMIT_HEY} חייב{ADD_TAF} להביא שלושה\n"
	.string "סוגים שונים של פוקימונים.\p"
	.string "הם גם חייבים לא להחזיק את אותם\n"
	.string "סוגי פריטים.\p"
	.string "ביצים{STR_VAR_1} אינן מתאימות.\p"
	.string "כאשר תסיי{SWAP_MEM}{ADD_YUD} עם ההכנות שלך,\n"
	.string "בבקשה תחז{EMIT_VAV}ר{ADD_YUD}.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "מאתגר{ADD_TAF} יקר{ADD_HEY} שלי!\p"
	.string "אין לך את שלושת הפוקימונים\n"
	.string "הנדרשים לכניסה.\p"
	.string "כדי לעמוד בתנאי, את{EMIT_HEY} חייב{ADD_TAF} להביא שלושה\n"
	.string "סוגים שונים של פוקימונים.\p"
	.string "שלושת הפוקימונים השונים\n"
	.string "חייבים להיות כולם ברמה 05 או פחות.\p"
	.string "הם גם חייבים לא להחזיק את אותם\n"
	.string "סוגי פריטים.\p"
	.string "ביצים{STR_VAR_1} אינן מתאימות.\p"
	.string "כאשר תסיי{SWAP_MEM}{ADD_YUD} עם ההכנות שלך,\n"
	.string "בבקשה תחז{EMIT_VAV}ר{ADD_YUD}.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "אני עכשיו אדריך אותך\n"
	.string "לזירת הקרב.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "מאתגר{ADD_TAF} יקר{ADD_HEY} שלי!\p"
	.string "לא שמרת את המשחק לפני\n"
	.string "שכיבית, נכון?\p"
	.string "זה מצער, אבל זה גרם\n"
	.string "לפסילה שלך מהאתגר.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY}, כמובן, להתחיל את האתגר\n"
	.string "מחדש.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "אנו מברכים אותך על רצף הניצחונות\n"
	.string "המפואר שלך על שבעה מאמנים!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "ההישג שלך יירשם.\n"
	.string "נא להמתין בזמן שאני שומר את המשחק.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "כדי לחגוג את רצף 7 הניצחונות שלך,\n"
	.string "אנו מעניקים לך את הפרס הזה.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} קיבל{ADD_HEY} את הפרס\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "או?\n"
	.string "נראה שהתיק שלך מלא.\p"
	.string "אני מפציר בך לפנות מקום\n"
	.string "ולחזור בשביל הפרס שלך.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "תודה רבה על השתתפותך!\p"
	.string "נא להמתין בזמן שאני שומר את המשחק.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "אנו מצפים לאתגר שלך\n"
	.string "בהזדמנות אחרת!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "חיכינו לבואך.\p"
	.string "לפני שאני מראה לך את הדרך לזירת\n"
	.string "הקרב, עליי לשמור את המשחק.\l"
	.string "נא להמתין.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "האם עליי להקליט את קרב זירת הקרב\n"
	.string "האחרון שלך בהיתר חזית הקרב שלך?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "הפסדתי בהחלטת השופט…\p"
	.string "אני לא חושב שזה היה רעיון טוב רק\n"
	.string "להשתמש במהלכי הגנה ולא לתקוף…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "ניצחתי בשיפוט!\p"
	.string "פגיעה עקבית בפוקימון של היריב\n"
	.string "עבדה!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "הקרב שלנו הוכרז כתיקו.\p"
	.string "כשנגמר הזמן, גם לפוקימון שלי וגם\n"
	.string "לפוקימון של היריב הייתה בערך אותה\l"
	.string "כמות חיים שנותרה.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "בזירת הקרב, סדר הפוקימונים\n"
	.string "חשוב לחלוטין.\p"
	.string "לדוגמה, אם לפוקימון הראשון שלך\n"
	.string "יש חסרונות סוג מסוימים,\l"
	.string "נס{EMIT_HEY}{ADD_YUD} להפוך את הפוקימון השני שלך לאחד\l"
	.string "עם מהלכים שהם סופר יעילים\l"
	.string "נגד הראשון.\p"
	.string "אני חושב שזו תהיה דרך טובה\n"
	.string "ליצור צוות יעיל.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "חוקי טורניר נוקאאוט קבוע רשומים.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "איזה כותרת את{EMIT_HEY} רוצה לקרוא?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "לטורניר נוקאאוט קבוע יש חוקים מיוחדים,\n"
	.string "בניגוד לקרבות רגילים.\p"
	.string "ראשית, קרב אחד נמשך רק\n"
	.string "שלושה תורות.\p"
	.string "אם התוצאה לא מוכרעת לאחר\n"
	.string "שלושה תורות, זה עובר לשיפוט.\p"
	.string "השופט יבחר את המנצח\n"
	.string "על בסיס איך הפוקימונים נלחמו.\p"
	.string "כמו כן, פוקימון לא ניתן להחליף\n"
	.string "עד שתוצאת הקרב שלו מוכרעת.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "גורם השיפוט הראשון הוא ”תודעה.“.\n"
	.string "הגורם הזה מעריך עד כמה תוקפניים\l"
	.string "היו הלוחמים.\p"
	.string "השיפוט מבוסס על כמה פעמים\n"
	.string "המאמנים הורו על שימוש\l"
	.string "במהלכים התקפיים.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "גורם השיפוט השני הוא ”מיומנות“.\n"
	.string "הגורם הזה מעריך עד כמה יעיל\l"
	.string "היה השימוש במהלכי פוקימונים.\p"
	.string "אם המהלך הצליח,\n"
	.string "דירוג המיומנות עולה.\p"
	.string "אם המהלך נכשל, דירוג המיומנות\n"
	.string "יורד.\p"
	.string "אם זה היה מהלך התקפי, דירוג המיומנות\n"
	.string "עולה אם המהלך היה ”סופר יעיל\l"
	.string "ויורד אם הוא היה לא יעיל במיוחד.“\l"
	.string "במיוחד.\p"
	.string "דירוג המיומנות לא יעלה עבור\n"
	.string "מהלכים כמו הגנה וזיהוי.\p"
	.string "אם היריב השתמש בהגנה או\n"
	.string "בזיהוי, והפוקימון שלך לא פגע\l"
	.string "במהלך, דירוג המיומנות שלו לא יירד.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "גורם השיפוט השלישי הוא ”גוף“.\n"
	.string "הגורם הזה מבוסס על כמה נקודות חיים\l"
	.string "נשארו בסוף הקרב.\p"
	.string "הדירוג לוקח בחשבון כמה נקודות חיים\n"
	.string "היו לפוקימון בתחילת הקרב,\l"
	.string "ומה נשאר בסופו.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "ניצחון שנחטף משליטת הזירה,\n"
	.string "וניצחון גורף על שבעה מאמנים!\p"
	.string "אנו מברכים אותך על האתגר\n"
	.string "המפואר ביותר שלך!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "האתגר היקר שלי, כהכרה ברוחך\n"
	.string "הבלתי נלאית, אנא קבל{ADD_YUD}\l"
	.string "את נקודות הקרב האלה.$"
