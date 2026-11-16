EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_EVER_GRANDE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_EVER_GRANDE_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
	applywaitmovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
	applywaitmovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
	.string "ליגת הפוקימון נמצאת במרחק קצר\n"
	.string "אחרי דרך הניצחון.\p"
	.string "אם הגעת עד לכאן, איזו ברירה\n"
	.string "נשארה לך חוץ מלהמשיך?$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
	.string "דרך הניצחון הארוכה והמאתגרת…\p"
	.string "זה כמו לחוות מחדש את המסע בחיים…\p"
	.string "תאמי{SWAP_NUN}{ADD_YUD} בפוקימונים שלך ות{SWAP_NUN}{ADD_YUD} להם\n"
	.string "את המיטב שבך!$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
	.string "סקוט: {PLAYER}{KUN}, הגעת עד לכאן כדי\n"
	.string "להתמודד מול ליגת הפוקימון!\p"
	.string "אני שמח בשבילך!\n"
	.string "הפכת את העידוד שלי למשתלם!\p"
	.string "{PLAYER}{KUN}, אם תהפ{EMIT_VAV}{SWAP_PEY}{ADD_YUD} להיות\n"
	.string "אלו{SWAP_PEY}{ADD_TAF} ליגת הפוקימון…\p"
	.string "אז אצור איתך קשר.\p"
	.string "אוקיי, {PLAYER}{KUN}.\n"
	.string "שא{EMIT_VAV}{SWAP_PEY}{ADD_YUD} לגדולה!$"

