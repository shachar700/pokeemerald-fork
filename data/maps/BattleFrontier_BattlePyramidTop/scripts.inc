BattleFrontier_BattlePyramidTop_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp
	.byte 0

BattleFrontier_BattlePyramidTop_OnTransition:
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto_if_ne VAR_TEMP_C, 0, BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects
	setobjectxyperm LOCALID_BRANDON, 0, 0
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects::
	end

BattleFrontier_BattlePyramidTop_OnResume:
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus
	call BattleFrontier_EventScript_SetBrainObjectGfx
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus::
	copyvar VAR_TEMP_C, VAR_RESULT
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePyramidTop_OnFrame:
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID_TOP, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_Attendant::
	lock
	faceplayer
	goto_if_ne VAR_TEMP_D, 0, BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady
	goto_if_ne VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop
	waitmovement 0
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath
	waitmovement 0
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	closemessage
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady::
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside::
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere, MSGBOX_DEFAULT
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	setvar VAR_TEMP_D, 1
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon::
	lockall
	switch VAR_TEMP_C
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver::
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold::
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle::
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_PYRAMID
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	return

BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside:
	walk_right
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath:
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer:
	walk_fast_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	delay_16
	step_end

BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo:
	.string "זה תענוג לראות אותך כאן!\n"
	.string "הגעת לפסגת פירמידת\l"
	.string "הקרב!\p"
	.string "מעל נמצאת נקודת\n"
	.string "התצפית של הפירמידה.\p"
	.string "זה מקום פתוח רק לאלה\n"
	.string "שכבשו את הפירמידה.\p"
	.string "עכשיו, בבקשה!\n"
	.string "על{EMIT_HEY}{ADD_YUD} למעלה!$"

BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid:
	.string "הכובש{ADD_TAF} החדש של הפירמידה!\n"
	.string "שיהיה ידוע השם {PLAYER}!$"

BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere:
	.string "זה תענוג לראות אותך כאן!\p"
	.string "לרוע המזל, היית שני{ADD_HEY} בפער\n"
	.string "של חלקיק זמן בלבד!\p"
	.string "המפקד שלנו כבר כבש את\n"
	.string "הפירמידה לפניך.\p"
	.string "למרות זאת, החוקר{ADD_TAF} הצעיר{ADD_HEY} שלי…\n"
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}!\p"
	.string "הוכ{ADD_YUD}ח{ADD_YUD} את כוחך וקח{ADD_YUD} את תהילת\n"
	.string "הפסגה מהמפקד שלנו!\p"
	.string "עכשיו, בבקשה! כשתהי{EMIT_HEY}{ADD_YUD} מוכ{SWAP_NUN}{ADD_HEY},\n"
	.string "קח{ADD_YUD} צעד אחד נוסף של אומץ!$"

BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure:
	.string "הרפתק{SWAP_NUN}{ADD_YUD}{ADD_TAF} צעיר{ADD_HEY}…\p"
	.string "האם לא תסכים שלחקור\n"
	.string "הוא ההרפתקה הגדולה ביותר?\p"
	.string "השכל שלך!\p"
	.string "הכוח שלך!\p"
	.string "הפוקימונים שלך!\p"
	.string "ומעל לכל, רק האומץ שלך\n"
	.string "להוביל אותך דרך עולמות לא ידועים…$"

BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon:
	.string "אהה, כן, החיים האלה באמת מופלאים!\n"
	.string "מופלאים, הם מופלאים! הא?\p"
	.string "אני ברנדון!\p"
	.string "אני מלך הפירמידה, מה שאומר\n"
	.string "שאני הממונה כאן.\p"
	.string "רוב האנשים קוראים לי המפקד!\p"
	.string "בואך לכאן אומר שיש לך\n"
	.string "ביטחון עצמי רב כל כך, אני צודק?\l"
	.string "אני צודק?\p"
	.string "האהאהאהא!\n"
	.string "זה הולך להיות מרגש!$"

BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle:
	.string "עכשיו, אם כך!\n"
	.string "הב{ADD_YUD}א{ADD_YUD} את אומץ ליבך לקרב שלנו!$"

BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease:
	.string "ברנדון: האהאהא! מופלא זה היה!\n"
	.string "מופלא, כן, באמת!\p"
	.string "כל הכבוד! הרווחת הכרה!\n"
	.string "היתר חזית הקרב שלך, בבקשה!$"

BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol:
	.string "סמל האומץ הוטבע על\n"
	.string "היתר חזית הקרב!$"

BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting:
	.string "חוקר{ADD_TAF} צעיר{ADD_HEY}!\n"
	.string "אני מצפה לפגישה הבאה שלנו!$"

BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned:
	.string "ברנדון: …סוף סוף חזרת,\n"
	.string "חוקר{ADD_TAF} צעיר{ADD_HEY}…\p"
	.string "אהבתך להרפתקאות נראית כאילו מגיעה\n"
	.string "עמוק מתוך ליבך…\p"
	.string "כן… את{EMIT_HEY} בדיוק כמוני\n"
	.string "בצעירותי…\p"
	.string "… … …אה…\p"
	.string "הנלהבים!\p"
	.string "המסוכנים!\p"
	.string "הנואשים!\p"
	.string "ימי ההרפתקאות מתריסות המוות,\n"
	.string "מאשרות החיים, חזרו…$"

BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter:
	.string "עכשיו, אם כך!\p"
	.string "אני חש שהאומץ שלי הוא מחוץ\n"
	.string "לסקאלה!$"

BattleFrontier_BattlePyramidTop_Text_EverythingYouHave:
	.string "כל מה שיש לך!\n"
	.string "אני מוכן לכל זה!$"

BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis:
	.string "ברנדון: האהאהאהא!\n"
	.string "מדהים!\l"
	.string "כן, זה מופלא, באמת!\p"
	.string "חוקר{ADD_TAF} צעיר{ADD_HEY}!\p"
	.string "הבסת אותי לחלוטין!\n"
	.string "הנה! אני רוצה שתקבל{ADD_YUD} את זה!$"

BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine:
	.string "סמל האומץ קיבל\n"
	.string "ברק זהוב!$"

BattleFrontier_BattlePyramidTop_Text_FarewellForNow:
	.string "אה, כן! זה רק מראה\n"
	.string "שיש לי עוד הרבה מה ללמוד!\p"
	.string "מי ייתן ודרכינו יצטלבו שוב!\n"
	.string "להתראות לעת עתה, חוקר{ADD_TAF} צעיר{ADD_HEY}!$"

BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady:
	.string "עכשיו, כשתהי{EMIT_HEY}{ADD_YUD} מוכ{SWAP_NUN}{ADD_HEY}, קח{ADD_YUD} אומץ\n"
	.string "וצעד{ADD_YUD} קדימה.$"

