BattleFrontier_BattlePikeThreePathRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_OnWarp:
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_4, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby::
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume
	waitmessage
	pike_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge, MSGBOX_DEFAULT
	closemessage
	releaseall
	frontier_settrainers
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant::
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Room number
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge::
	frontier_saveparty
	message BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData
	waitmessage
	special LoadPlayerParty
	pike_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePike_EventScript_Retire
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom::
	pike_sethintroom
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint::
	setvar VAR_TEMP_5, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint::
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos
	waitmovement 0
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver::
	pike_gethint
	goto_if_eq VAR_RESULT, PIKE_HINT_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint::
	pike_gethintroomid
	switch VAR_RESULT
	case PIKE_ROOM_LEFT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint
	case PIKE_ROOM_CENTER, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint
	case PIKE_ROOM_RIGHT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint::
	pike_gethint
	switch VAR_RESULT
	case PIKE_HINT_NOSTALGIA, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia
	case PIKE_HINT_WHISPERING, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering
	case PIKE_HINT_POKEMON, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon
	case PIKE_HINT_PEOPLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1:
	.string "את{EMIT_HEY} נמצא{ADD_TAF} כרגע\n"
	.string "בחדר הראשון…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3:
	.string "את{EMIT_HEY} נמצא{ADD_TAF} כרגע\n"
	.string "בחדר השלישי…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5:
	.string "את{EMIT_HEY} נמצא{ADD_TAF} כרגע\n"
	.string "בחדר החמישי…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7:
	.string "את{EMIT_HEY} נמצא{ADD_TAF} כרגע\n"
	.string "בחדר השביעי…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9:
	.string "את{EMIT_HEY} נמצא{ADD_TAF} כרגע\n"
	.string "בחדר התשיעי…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11:
	.string "את{EMIT_HEY} נמצא{ADD_TAF} כרגע\n"
	.string "בחדר האחד עשר…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13:
	.string "את{EMIT_HEY} נמצא{ADD_TAF} כרגע\n"
	.string "בחדר השלושה עשר…$"

BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge:
	.string "האם תמשי{SWAP_CHAF}{ADD_YUD} עם\n"
	.string "האתגר שלך?$"

BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לשמור את האתגר שלך\n"
	.string "ולפרוש מהמשחק לעת עתה?$"

BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge:
	.string "האם ברצונך לפרוש מאתגר\n"
	.string "בחירת הקרב שלך?$"

BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume:
	.string "חיכינו לשובך…\p"
	.string "לפני שתמשי{SWAP_CHAF}{ADD_YUD} באתגר בחירת הקרב שלך,\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לשמור את המשחק…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge:
	.string "אנא תהנ{EMIT_HEY}{ADD_YUD} מאתגר בחירת הקרב\n"
	.string "שלך…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData:
	.string "אני שומר את הנתונים שלך…\n"
	.string "קצת זמן, בבקשה…$"

BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack:
	.string "הנתיב חסום!\n"
	.string "ואין דרך חזרה…$"

BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose:
	.string "אני מבקשת את סליחתך, אבל…\p"
	.string "האם את{EMIT_HEY} אולי מוצא{ADD_TAF} את זה קשה\n"
	.string "לבחור את הנתיב שלך?$"

BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence:
	.string "אני מבינה…\n"
	.string "אני מתנצלת על חוצפתי…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath:
	.string "אה, ת{SWAP_NUN}{ADD_YUD} לי לראות… יש משהו\n"
	.string "בנוגע לנתיב מימין…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath:
	.string "אה, ת{SWAP_NUN}{ADD_YUD} לי לראות… יש משהו\n"
	.string "בנוגע לנתיב המרכזי…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath:
	.string "אה, ת{SWAP_NUN}{ADD_YUD} לי לראות… יש משהו\n"
	.string "בנוגע לנתיב משמאל…$"

BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon:
	.string "נראה שיש בו ארומה מובהקת\n"
	.string "של פוקימונים שנושבת סביבו…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople:
	.string "האם זה… מאמן?\n"
	.string "אני חש בנוכחות של אנשים…$"

BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering:
	.string "נראה ששמעתי משהו…\n"
	.string "אולי זו הייתה לחישה…$"

BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga:
	.string "מסיבה מוזרה כלשהי, הרגשתי גל\n"
	.string "של נוסטלגיה מגיע ממנו…$"

BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent:
	.string "אני מצטער לומר…\p"
	.string "אירוע מחריד, כן, אירוע נורא,\n"
	.string "עומד לפקוד אותך…\p"
	.string "אני מפציר בך להיזהר מאוד\n"
	.string "ולהתכונן לגרוע מכל…$"

BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence:
	.string "מכל נתיב אני חש בנוכחות\n"
	.string "מפחידה…$"
