Route110_SeasideCyclingRoadNorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadNorthEntrance_OnTransition
	.byte 0

Route110_SeasideCyclingRoadNorthEntrance_OnTransition:
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 3, Route110_SeasideCyclingRoadNorthEntrance_EventScript_RestartChallenge
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 2, Route110_SeasideCyclingRoadNorthEntrance_EventScript_RestartChallenge
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_RestartChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	call_if_eq VAR_RESULT, 2, Route110_SeasideCyclingRoadNorthEntrance_EventScript_OnMachBike
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_OnMachBike::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter:
	walk_left
	step_end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_ClearCyclingRoad::
	lockall
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad:
    .string "בשביל האופניים אפשר לרכב בכל הכוח\n"
    .string "ולהתחרות במהירות כרצונך.\p"
    .string "מרגיש מצוין לרכב כל כך מהר, אבל נס{EMIT_HEY}{ADD_YUD}\n"
    .string "לא להתנגש באף אחד!$"

Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk:
    .string "סליחה, אי אפשר ללכת בשביל האופניים.\n"
    .string "זה מסוכן מדי.\p"
    .string "בבקשה תחז{EMIT_VAV}ר{ADD_YUD} עם אופניים.$"

