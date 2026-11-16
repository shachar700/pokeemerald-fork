MossdeepCity_House2_MapScripts::
	.byte 0

MossdeepCity_House2_EventScript_Man::
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Twin::
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_WINGULL
	msgbox MossdeepCity_House2_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_WINGULL_DELIVERED_MAIL
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_House2_EventScript_WingullExitNorth
	call_if_eq VAR_FACING, DIR_WEST, MossdeepCity_House2_EventScript_WingullExitWest
	removeobject LOCALID_MOSSDEEP_HOUSE_WINGULL
	release
	end

MossdeepCity_House2_EventScript_WingullExitNorth::
	applywaitmovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitNorth
	return

MossdeepCity_House2_EventScript_WingullExitWest::
	applywaitmovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitEast
	return

MossdeepCity_House2_Movement_WingullExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_WingullExitEast:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree:
    .string "האחות הקטנה שלי מחליפה מכתבים\n"
    .string "עם החבר שלה בפורטרי.\p"
    .string "אני בכלל לא מקנא בה.$"

MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth:
    .string "למרות שאני לא רואה את החבר שלי\n"
    .string "בפורטרי, הפוקימון שלי מביא מכתבים\l"
    .string "הלוך ושוב בשבילנו.\p"
    .string "אני לא מרגישה בודדה, למרות שאנחנו\n"
    .string "בנפרד.$"

MossdeepCity_House2_Text_Wingull:
	.string "{STR_VAR_1}: פיהיוה!$"

