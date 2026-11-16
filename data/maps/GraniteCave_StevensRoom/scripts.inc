GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applywaitmovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "שמי סטיבן.\p"
	.string "אני מתעניין באבנים נדירות,\n"
	.string "ולכן אני מטייל ממקום למקום.\p"
	.string "אה?\n"
	.string "מכתב בשבילי?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "סטיבן: אוקיי, תודה לך.\p"
	.string "עברת את כל הדרך הזו רק כדי למסור\n"
	.string "לי את המכתב. אני חייב להודות לך.\p"
	.string "בוא{ADD_YUD} נראה…\n"
	.string "אני אתן לך את המ”מ הזה.\p"
	.string "הוא מכיל את המהלך האהוב עליי,\n"
	.string "כנפי פלדה.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "סטיבן: הפוקימונים שלך נראים\n"
	.string "חזקים למדי.\p"
	.string "אם תמשי{SWAP_CHAF}{ADD_YUD} להתאמן, אולי יום אחד\n"
	.string "תוכל{ADD_YUD} להפוך לאלו{SWAP_PEY}{ADD_TAF} ליגת הפוקימונים.\l"
	.string "זה מה שאני חושב.\p"
	.string "אני יודע, מאחר ואנחנו כבר מכירים\n"
	.string "זה את זה, בוא נרשום אחד את השני\l"
	.string "בפוקינווט שלנו.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "סטיבן נרשם\n"
	.string "בפוקינווט.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "עכשיו,אני חייב למהר הלאה.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "או, התיק שלך מלא…\n"
	.string "חבל למדי.$"

