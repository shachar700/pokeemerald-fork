BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "המקום שבו המזל של מאמנים\n"
	.string "מועמד למבחן…\p"
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לנהר הקרב…\p"
	.string "אני המדריכה שלך לנהר הקרב…$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לקבל את אתגר\n"
	.string "בחירת הקרב?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "כאן אנחנו עורכים אירוע שאנו קוראים\n"
	.string "לו בחירת הקרב.\p"
	.string "החוקים של בחירת הקרב הם מאוד\n"
	.string "פשוטים…\p"
	.string "בחר{ADD_YUD} אחד משלושה נתיבים ול{SWAP_CHAF}{ADD_YUD}\n"
	.string "לחדר המטרה בסוף נהר הקרב.\l"
	.string "זה כזה פשוט.\p"
	.string "עם זאת, מה שקורה בנתיב שנבחר\n"
	.string "תלוי לחלוטין במזל של המתמודד…\p"
	.string "אם תגיע{ADD_YUD} למטרה, תקבל{ADD_YUD}\n"
	.string "נקודות קרב כפרס.\p"
	.string "אם את{EMIT_HEY} רוצה להפסיק את האתגר\n"
	.string "שלך, אנא דבר{ADD_YUD} עם הצוות שלנו\l"
	.string "בחדרים הגדולים בדרך.\p"
	.string "אם לא תשמ{EMIT_VAV}ר{ADD_YUD} לפני שתפסיק{ADD_YUD},\n"
	.string "את{EMIT_HEY} תיפסל{ADD_YUD}.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "אנחנו מצפים לראות אותך\n"
	.string "בהזדמנות אחרת…$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "יש לך בחירה בין שני מסלולים,\n"
	.string "רמה 05 ורמה פתוחה.\l"
	.string "באיזה תתמודד{ADD_YUD}?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "אני מבקשת את סליחתך, אבל…\p"
	.string "אין לך שלושה פוקימונים מתאימים\n"
	.string "לאירוע בחירת הקרב.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} שיהיו לך שלושה פוקימונים שונים\n"
	.string "ברמה 05 או פחות כדי להיכנס.\p"
	.string "הם גם חייבים להחזיק סוגים שונים\n"
	.string "של פריטים.\p"
	.string "ביצים{STR_VAR_1} אינן מתאימות.\p"
	.string "אנא בוא{ADD_YUD} לבקר אותי\n"
	.string "כשאת{EMIT_HEY} מוכ{SWAP_NUN}{ADD_HEY}…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "אני מבקשת את סליחתך, אבל…\p"
	.string "אין לך שלושה פוקימונים מתאימים\n"
	.string "לאירוע בחירת הקרב.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} שיהיו לך שלושה פוקימונים\n"
	.string "שונים כדי להיכנס.\p"
	.string "הם גם חייבים להחזיק סוגים שונים\n"
	.string "של פריטים.\p"
	.string "ביצים{STR_VAR_1} אינן מתאימות.\p"
	.string "אנא בוא{ADD_YUD} לבקר אותי\n"
	.string "כשאת{EMIT_HEY} מוכ{SWAP_NUN}{ADD_HEY}…$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "אנא בחר{ADD_YUD} את שלושת הפוקימונים\n"
	.string "שבהם תרצ{EMIT_HEY}{ADD_YUD} להשתמש באתגר…$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "לפני שתתחיל{ADD_YUD} את אתגר בחירת הקרב\n"
	.string "שלך, עליי לשמור את המשחק.\l"
	.string "האם זה מקובל?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "תיכנס{ADD_YUD} מכאן…$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "האתגר שלך הסתיים…\p"
	.string "אני ארשום את התוצאות שלך.\n"
	.string "נא להמתין…$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "את{EMIT_HEY} השלמת את האתגר…\p"
	.string "אני חייב לומר… נראה שיש לך מזל\n"
	.string "בשפע…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "אני ארשום את התוצאות שלך.\n"
	.string "נא להמתין…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "כדי לחגוג את השלמת אתגר\n"
	.string "בחירת הקרב, אנו מעניקים לך את נקודות\l"
	.string "הקרב האלו…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "זה נראה שהגעת למגבלה\n"
	.string "של נקודות קרב…\p"
	.string "אנא המ{ADD_YUD}ר{ADD_YUD} כמה נקודות קרב\n"
	.string "עבור פרסים, ואז חז{EMIT_VAV}ר{ADD_YUD}…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "אני מבקשת את סליחתך, אבל…\p"
	.string "לא שמרת לפני שהפסקת את\n"
	.string "האתגר שלך בפעם האחרונה.\p"
	.string "בגלל זה, האתגר שלך עד כה\n"
	.string "נפסל. אני מצטער…$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "ברכות…\p"
	.string "חטפת את הניצחון ממלכת הנהר\n"
	.string "והשלמת את האירוע…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "כהכרה במזלך המדהים,\n"
	.string "אנו מעניקים לך את נקודות הקרב האלו…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "אררג! פספסתי את ההזדמנות!\n"
	.string "הייתי חדר אחד רחוק מהמטרה!\p"
	.string "במקום הזה, מוטב שתשי{SWAP_MEM}{ADD_YUD} לב\n"
	.string "לרעל, הקפאה וכן הלאה.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "השלמתי את האתגר 01 פעמים\n"
	.string "עכשיו, אבל אף פעם לא הייתי צריך להילחם\l"
	.string "במאמן אפילו פעם אחת.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "תקשיב{ADD_YUD}! תקשיב{ADD_YUD}!\p"
	.string "את{EMIT_HEY} לא חושב{ADD_TAF} שהיכולות\n"
	.string "המיוחדות של פוקימונים יהיו שימושיות\l"
	.string "כאן?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "מה זה המקום המוזר הזה?\n"
	.string "אני לא מצליח להבין את זה בכלל!\p"
	.string "ניסיתי את האתגר מספר פעמים,\n"
	.string "אבל כל מה שאני עושה זה להיתקל\l"
	.string "במאמנים בכל נתיב שאני בוחר.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "חוקי בחירת הקרב רשומים.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "איזו כותרת את{EMIT_HEY} רוצה לקרוא?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "אין להשתמש בתיק ובפוקינווט\n"
	.string "במהלך אתגר בחירת הקרב.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "במהלך אתגר בחירת הקרב,\n"
	.string "כל פרי יער או עשב המוחזק על ידי פוקימונים\l"
	.string "יהיה יעיל רק פעם אחת.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "במהלך אתגר בחירת הקרב,\n"
	.string "הרצף של פוקימונים לא יכול\l"
	.string "להשתנות.\p"
	.string "יש לקבוע את הרצף לפני\n"
	.string "תחילת האתגר שלך.$"

