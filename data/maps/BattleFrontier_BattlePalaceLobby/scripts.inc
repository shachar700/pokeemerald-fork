BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "איפה שלבבות המאמנים\n"
	.string "עומדות למבחן.\p"
	.string "אני מברך אותך לארמן הקרב.\p"
	.string "אני מקבל אתגרים לאולמות\n"
	.string "הקרב היחיד.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "האם את{EMIT_HEY} רוצה לקחת חלק באתגר\n"
	.string "אולם הקרב היחיד?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "בארמון הקרב, ישנם מספר אודיטוריומים\n"
	.string "לקרבות יחידים הנקראים אולמות קרב יחידים.\p"
	.string "הקרבות היחידים מתנהלים בדרך הרגילה,\n"
	.string "למעט כלל מכריע אחד שחייבים לציית לו.\p"
	.string "מאמנים מורשים רק להחליף את\n"
	.string "הפוקימונים שלהם פנימה והחוצה.\p"
	.string "מאמנים אסורים אחרת לפקד על\n"
	.string "הפוקימונים שלהם.\p"
	.string "הפוקימונים צריכים להתנהג לפי\n"
	.string "האופי שלהם ולהילחם בעצמם.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לתת את האמון שלך בפוקימונים\n"
	.string "שלך ולהשגיח עליהם.\p"
	.string "אם תזכ{EMIT_HEY}{ADD_YUD} בכבוד להביס שבעה מאמנים\n"
	.string "ברצף, נעניק לך נקודות קרב.\p"
	.string "אם את{EMIT_HEY} רוצה להפסיק את האתגר שלך,\n"
	.string "עליך לשמור את המשחק.\p"
	.string "אם לא תשמ{EMIT_VAV}ר{ADD_YUD} לפני ההפסקה,\n"
	.string "את{EMIT_HEY} תיפסל{ADD_YUD}.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "כאשר תחזק{ADD_YUD} את ליבך ואת הפוקימונים\n"
	.string "שלך, עליך לחזור.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "ישנם שני אולמות קרב,\n"
	.string "רמה 05 ורמה פתוחה.\l"
	.string "מהו הבחירה שלך לאתגר?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "אנחה…\p"
	.string "אין לך את שלושת הפוקימונים\n"
	.string "הנדרשים לאתגר.\p"
	.string "כדי להיכנס, עליך לספק שלושה\n"
	.string "סוגים שונים של פוקימונים.\p"
	.string "פוקימונים אלה חייבים להיות כולם\n"
	.string "ברמה 05 או ברמה נמוכה יותר.\p"
	.string "הם גם לא יכולים להחזיק\n"
	.string "את אותם סוגי הפריטים.\p"
	.string "ביצים{STR_VAR_1} לא כשירות.\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} כאשר תעש{EMIT_HEY}{ADD_YUD} את ההכנות שלך.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "אנחה…\p"
	.string "אין לך את שלושת הפוקימונים\n"
	.string "הנדרשים לאתגר.\p"
	.string "כדי להיכנס, עליך לספק שלושה\n"
	.string "סוגים שונים של פוקימונים.\p"
	.string "הם גם לא יכולים להחזיק\n"
	.string "את אותם סוגי הפריטים.\p"
	.string "ביצים{STR_VAR_1} לא כשירות.\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} כאשר תעש{EMIT_HEY}{ADD_YUD} את ההכנות שלך.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "טוב. עכשיו, עליך לבחור את\n"
	.string "שלושת הפוקימונים שלך.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "אני חייבת לשמור לפני שאראה לך\n"
	.string "את אולם הקרב. האם זה בסדר?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "טוב.\n"
	.string "עכשיו, עק{EMIT_VAV}ב{ADD_YUD} אחריי.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "אני מרגישה בעלת זכות שראיתי\n"
	.string "את מעשי הפוקימונים שלך.\p"
	.string "התוצאות יירשמו.\n"
	.string "אני חייבת לבקש ממך להמתין זמן קצר.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "להשיג רצף של 7 ניצחונות…\p"
	.string "הקשרים שקושרים את ליבך עם\n"
	.string "הפוקימונים שלך נראים איתנים ואמיתיים.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "המעשה שלך יירשם.\n"
	.string "אני חייבת לבקש ממך להמתין זמן קצר.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "For the feat of your 7-win streak,\n"
	.string "we present you with Battle Point(s).$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "נראה שאין לך מקום לפרס שלנו.\p"
	.string "כדאי שתחז{EMIT_VAV}ר{ADD_YUD} לאחר שארגנת\n"
	.string "את התיק שלך.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "חיכינו לך…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "אני חייבת לשמור לפני שאראה לך\n"
	.string "את אולם הקרב. האם זה בסדר?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "אנחה…\p"
	.string "נכשלת בלשמור לפני שסיימת את\n"
	.string "האתגר שלך בפעם האחרונה.\p"
	.string "כתוצאה מכך, האתגר שלך נפסל.\n"
	.string "זה מאוד מצער.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "עבור בחור חסון כמוני,\n"
	.string "פוקימונים חסונים הם הטובים ביותר.\p"
	.string "התקפה היא ההגנה הטובה ביותר!\n"
	.string "התקפה בלתי פוסקת היא האולטימטיבית!\p"
	.string "אבל זה לא על מה רציתי\n"
	.string "לשוחח.\p"
	.string "מדי פעם גברת חמודה מאוד\n"
	.string "מגיעה לכאן.\p"
	.string "היא אומרת שהיא יכולה לדעת\n"
	.string "מה פוקימונים חושבים.\p"
	.string "אני לא יודע על החלק הזה,\n"
	.string "אבל היא ממש חמודה.\p"
	.string "הא?\n"
	.string "למה את{EMIT_HEY} מסתכל{ADD_TAF} עליי ככה?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "הממ…\p"
	.string "נראה שהאופי של פוקימונים והמהלכים\n"
	.string "שהם למדו הם המפתחות לקרב כאן.\p"
	.string "ליתר דיוק, זה כמה טוב המהלכים\n"
	.string "מתאימים לאופי של הפוקימון.\p"
	.string "אם הפוקימון שלך בצרות ולא\n"
	.string "מצליח לממש את הפוטנציאל שלו,\l"
	.string "ייתכן שתצטר{SWAP_CHAF}{ADD_YUD} לבדוק כמה טוב\l"
	.string "המהלכים שלו מתאימים לאופי שלו.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "הפוקימון שלי בדרך כלל מאוד צייתן.\p"
	.string "אבל כשהוא באולם קרב, הוא\n"
	.string "לפעמים נראה כאילו הוא הופך\l"
	.string "למשהו מרושע!\p"
	.string "הוא הופך להיות לגמרי מאיים.\n"
	.string "זה אפילו מזעזע.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "אני תוהה איזה סוג של אופי היה\n"
	.string "לפוקימון שמעדיף להחליש את\l"
	.string "יריביו ולשחוק אותם לאט.\p"
	.string "הייתי מופתע אם זה היה אופי רגוע.\p"
	.string "אבל, לא, זה לא יכול להיות נכון.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "איפה שלבבות המאמנים\n"
	.string "עומדות למבחן.\p"
	.string "אני מברך אותך לארמן הקרב.\p"
	.string "אני מקבל אתגרים לאולמות\n"
	.string "הקרב הכפול.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "האם את{EMIT_HEY} רוצה לקחת חלק באתגר\n"
	.string "אולם הקרב הכפול?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "בארמון הקרב, ישנם מספר אודיטוריומים\n"
	.string "לקרבות כפולים הנקראים אולמות קרב כפולים.\p"
	.string "הקרבות הכפולים מתנהלים בדרך הרגילה,\n"
	.string "למעט כלל מכריע אחד שחייבים לציית לו.\p"
	.string "מאמנים מורשים רק להחליף את\n"
	.string "הפוקימונים שלהם פנימה והחוצה.\p"
	.string "מאמנים אסורים אחרת לפקד על\n"
	.string "הפוקימונים שלהם.\p"
	.string "הפוקימונים צריכים להתנהג לפי\n"
	.string "האופי שלהם ולהילחם בעצמם.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לתת את האמון שלך בפוקימונים\n"
	.string "שלך ולהשגיח עליהם.\p"
	.string "אם תזכ{EMIT_HEY}{ADD_YUD} בכבוד להביס שבעה מאמנים\n"
	.string "ברצף, נעניק לך נקודות קרב.\p"
	.string "אם את{EMIT_HEY} רוצה להפסיק את האתגר שלך,\n"
	.string "עליך לשמור את המשחק.\p"
	.string "אם לא תשמ{EMIT_VAV}ר{ADD_YUD} לפני ההפסקה,\n"
	.string "את{EMIT_HEY} תיפסל{ADD_YUD}.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "להביס את מומחה הארמון\n"
	.string "ושבעה מאמנים ברצף…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "לכבוד הקשר שאת{EMIT_HEY} חולק{ADD_TAF} עם\n"
	.string "הפוקימונים שלך, אנחנו מעניקים לך\l"
	.string "את נקודות הקרב האלה.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לתעד את משחק ארמון\n"
	.string "הקרב האחרון שלך על\l"
	.string "היתר החזית שלך?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "כללי אולם הקרב רשומים.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "איזו כותרת את{EMIT_HEY} רוצה לקרוא?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "כאן, פוקימונים נדרשים לחשוב\n"
	.string "ולהילחם בעצמם.\p"
	.string "בניגוד לטבע, פוקימונים שחיים\n"
	.string "עם אנשים מתנהגים אחרת\l"
	.string "בהתאם לאופי שלהם.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "בהתאם לאופי שלו, פוקימון עשוי\n"
	.string "להעדיף לתקוף לא משנה מה.\p"
	.string "פוקימון אחר עשוי להעדיף להגן\n"
	.string "על עצמו מכל נזק.\p"
	.string "אחר עשוי להנות להרגיז או\n"
	.string "לבלבל את אויביו.\p"
	.string "בגלל האופי שלו, לפוקימון יהיו\n"
	.string "מהלכים מועדפים שהוא טוב\l"
	.string "בשימוש בהם.\p"
	.string "הוא עשוי גם לא לאהוב מהלכים\n"
	.string "מסוימים שקשה לו להשתמש בהם.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "יש מהלכי התקפה שגורמים נזק\n"
	.string "ישיר לאויב.\p"
	.string "יש מהלכי הגנה שמשמשים\n"
	.string "להכנה להתקפות אויב או\l"
	.string "משמשים לריפוי נח וכך הלאה.\p"
	.string "יש גם מהלכים מוזרים אחרים\n"
	.string "שעשויים להחליש את האויבים עם\l"
	.string "בעיות נתונים כולל רעל\l"
	.string "ושיתוק.\p"
	.string "פוקימונים ישקלו להשתמש במהלכים\n"
	.string "בשלוש הקטגוריות האלה.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "כאשר אינו תחת פיקוד המאמן שלו,\n"
	.string "פוקימון עשוי להיות לא מסוגל להשתמש\l"
	.string "ביעילות במהלכים מסוימים.\p"
	.string "פוקימון לא טוב בשימוש בכל מהלך\n"
	.string "שהוא לא אוהב.\p"
	.string "אם פוקימון יודע רק מהלכים שלא\n"
	.string "מתאימים לאופי שלו, הוא לעתים קרובות\l"
	.string "לא יוכל לממש את הפוטנציאל שלו.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "בהתאם לאופי שלו, פוקימון עשוי\n"
	.string "להתחיל להשתמש במהלכים שלא מתאימים\l"
	.string "לאופי שלו כשהוא בצרות.\p"
	.string "אם פוקימון מתחיל להתנהג בצורה מוזרה\n"
	.string "במצב קשה, צפו בו בזהירות.$"

