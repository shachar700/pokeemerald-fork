VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "לאיזו תחרות את{EMIT_HEY} הול{SWAP_CHAF}{ADD_TAF}?\n"
	.string "רוצה עצה?\p"
	.string "בכל תחרות, למשל תחרות\n"
	.string "חמידות, אני לא חושב ששופטים\l"
	.string "רק לפי חמידות בסיבוב הראשון.\p"
	.string "צריך למצוא דרכים לגדל\n"
	.string "פוקימונים טוב יותר.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "גידלתי את הפוקימון שלי להיות חמוד.\p"
	.string "גיליתי שאפשר לרשום פוקימונים\n"
	.string "לתחרות חמידות!\p"
	.string "אני כל כך שמחה שגידלתי את\n"
	.string "הפוקימון שלי באהבה ובמסירות…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "הפוקימון שלי שולט!\p"
	.string "הוא מגניב, קשוח אבל יפה, חמוד\n"
	.string "וחכם. הוא מושלם!\p"
	.string "אני יכול לנסות לנצח בכל\n"
	.string "תחרות ותחרות.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "תחרויות פוקימונים\n"
	.string "במת דרגה רגילה!$"

