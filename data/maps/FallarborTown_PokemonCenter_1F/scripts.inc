FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applywaitmovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applywaitmovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "או, שלום.\n"
	.string "ואת{EMIT_HEY}?\p"
	.string "אוקיי, שמך הוא {PLAYER}{KUN}.\n"
	.string "אני רואה שאת{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}.\p"
	.string "אז זה אומר שאת{EMIT_HEY} משתמש{ADD_TAF} במערכת אחסון\n"
	.string "הפוקימון שאני פיתחתי.\p"
	.string "הדרך שבה הגעתי למסקנה הזו היא\n"
	.string "תהליך הסקה פשוט.\p"
	.string "דיברת איתי כי רצית לגשת\n"
	.string "למשהו במחשב הזה.\p"
	.string "או, אני מצטערת. אני לאנט.\p"
	.string "בכנות, אני שמחה לפגוש אותך--זה\n"
	.string "נהדר שאת{EMIT_HEY} משתמש{ADD_TAF} במערכת האחסון.\p"
	.string "אם תוכל{ADD_YUD}, בבקשה תבקר{ADD_YUD} אותי בבית.\n"
	.string "הבית שלי בדרך 411.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "אני תוהה איך פוקימון נראו לפני\n"
	.string "המון המון זמן?\p"
	.string "אולי מטורף המאובנים בקצה\n"
	.string "העיר יודע.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "בשדות של פולרבר, שתלנו שתילים\n"
	.string "של עצים עמידים שמשגשגים\l"
	.string "אפילו באפר געשי.$"

