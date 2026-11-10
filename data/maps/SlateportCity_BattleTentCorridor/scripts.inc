SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "רוצה עצה קטנה וטעימה\n"
	.string "לתחרויות?\p"
	.string "שימוש במהלך מסוים אחרי סוג\n"
	.string "מסוים אחר של מהלך מקנה לפעמים\l"
	.string "תשומת לב נוספת.\p"
	.string "אם את{EMIT_HEY} יודע{ADD_TAF} מה את{EMIT_HEY} עושה,\n"
	.string "אפשר לצבור המון נקודות בהופעה.\p"
	.string "כמובן, היריבים עלולים לנסות\n"
	.string "להפריע להופעה של הפוקימון שלך.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "אבא שלי שופט בתחרויות.\p"
	.string "אני תוהה מה אהיה כשאגדל,\n"
	.string "שופט או מנהיג מכון?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "אחי, אני כאילו ממש עצבני,\n"
	.string "יודע? כאילו, יודע, רק רציתי\l"
	.string "לדעת למה הפוקימון שלי\l"
	.string "אף פעם לא ניצח, כאילו, נו?\p"
	.string "אז, כאילו, אמרתי לשופט\n"
	.string "את דעתי, יודע, זה בחינם.\p"
	.string "והוא לא הקשיב לי, כאילו, הלו!\n"
	.string "אז, כאילו, באסה רצינית, אחי!\p"
	.string "היי, כאילו, את{EMIT_HEY}! שקט, יודע?\n"
	.string "פשוט, יודע, קח{ADD_YUD} את זה!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "זה, כאילו, מ”מ14, יודע?\n"
	.string "היי, זה עינוי, שומע אותי?\p"
	.string "כאילו, זה לא נותן ליריב להשתמש\n"
	.string "באותו מהלך פעמיים ברצף, קולט?\p"
	.string "היי, עכשיו תקשיב{ADD_YUD} טוב, כאילו,\n"
	.string "אני לא מענה אותך!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "מנחה: אוי, אוי, אוי!\n"
	.string "איזה פוקימון מהודר!\p"
	.string "בבקשה! גש{ADD_YUD} קדימה וקח{ADD_YUD}\n"
	.string "חלק בתחרויות המפוארות שלנו!\p"
	.string "תצליח{ADD_YUD}! אני בטוח בזה!\n"
	.string "העיניים שלי אף פעם לא טועות!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "שופט: שלום לך!\n"
	.string "אני רואה שאת{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}!\p"
	.string "אז אסור לך לפספס\n"
	.string "תחרות פוקימונים!\p"
	.string "השג{ADD_YUD} היתר תחרות בעיירת\n"
	.string "ורדנטרף ותוכל{ADD_YUD} להשתתף בכל עת!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "הגיע זמן ההופעה!\n"
	.string "במה כדאי לי לפתוח?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "הם לא שמו לב כמעט\n"
	.string "להופעה של הפוקימון שלי…\p"
	.string "הממף, השופט הזה לא מזהה\n"
	.string "דבר טוב גם כשהוא רואה אותו.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "אה, היי! את{EMIT_HEY} בטח מערי{SWAP_TZADIK}{ADD_HEY}\n"
	.string "רציני{ADD_TAF} אם הגעת כל כך קרוב.\p"
	.string "אגמול על ההתלהבות שלך\n"
	.string "בעצה חכמה.\p"
	.string "אם מהלך מצליח במיוחד,\n"
	.string "הקהל מתלהב.\p"
	.string "פוקימון שמופיע בדיוק\n"
	.string "כשכולם מתלהבים…\p"
	.string "טוב, הגיוני שמשהו טוב\n"
	.string "יקרה!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "אני לא מסוגל! אני לחוץ יותר\n"
	.string "מהפוקימון שלי.\p"
	.string "אני רועד והלב שלי דופק!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "קרב ותחרות הם לא אותו\n"
	.string "דבר, אבל הם גם דומים.\p"
	.string "צריך לעבוד קשה ולהאמין\n"
	.string "בפוקימון שגידלת.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "הפוקימון הזה נראה בשיא\n"
	.string "הכושר שלו, נכון?\p"
	.string "פוקימון שמצליח בשיפוט\n"
	.string "השני נראה רגוע יותר\l"
	.string "כשהוא מופיע.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "תסתכל{ADD_YUD} על המחזה העלוב הזה!\p"
	.string "הה, הפוקימון שלי הרבה יותר טוב\n"
	.string "מכל החבורה הזאת!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "לא בא לך לזוז יחד עם\n"
	.string "הפוקימונים כשהם מעלים\l"
	.string "הופעה אנרגטית?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "תחרויות פוקימונים\n"
	.string "במת דרגת היפר!$"

