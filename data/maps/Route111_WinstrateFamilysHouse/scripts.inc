Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applywaitmovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "את{EMIT_HEY} המאמ{SWAP_NUN}{ADD_TAF} הראשו{SWAP_NUN}{ADD_HEY} שראיתי\n"
    .string "שמוציא{ADD_HEY} פוקימון במיומנות כזו.\p"
    .string "אבל, עלי לומר לך--הבן שלי\n"
    .string "חזק ממך.\p"
    .string "הוא אפילו לקח על עצמו את\n"
    .string "אתגר ליגת הפוקימון, שתדע{ADD_YUD}.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "אנחנו משתמשים בצמיד החוזק הזה כדי\n"
	.string "לחזק את הפוקימונים שלנו\l"
	.string "שלנו באימונים בצורה יעילה.\p"
	.string "מכיוון שהבסת את כולנו כאן,\n"
    .string "אני לא יודע{ADD_TAF} אם את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} את זה, אבל\l"
    .string "אנחנו נשמח אם תקח{ADD_YUD} את צמיד החוזק שלנו.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "כשזה נוגע לקרבות פוקימון,\n"
    .string "אנחנו נוטים להיות נלהבים למדי.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "אמא חזקה יותר מאבא.\p"
    .string "אני חזק יותר מאמא.\p"
    .string "וסבתא חזקה יותר ממני!\p"
    .string "אבל אחי הגדול חזק אפילו יותר\n"
    .string "מסבתא.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "אין ספק שאת{EMIT_HEY} חזק{ADD_HEY}.\p"
    .string "אבל אם היית נלח{SWAP_MEM}{ADD_TAF} בנכד שלי,\n"
    .string "היית גומר{ADD_TAF} בבכי מתסכול.\p"
    .string "הוא הרבה יותר חזק מכל מאמן\n"
    .string "שהמשפחה שלנו מכירה.\p"
    .string "הוא בטח כבר מאתגר את אלוף\n"
    .string "ליגת הפוקימון.\p"
    .string "אם אני מכירה את הנכד שלי, הוא\n"
    .string "אולי כבר האלוף!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "הנכד שלי בטח כבר מאתגר את\n"
    .string "אלוף ליגת הפוקימון.\p"
    .string "אם אני מכירה את הנכד שלי, הוא\n"
    .string "אולי כבר האלוף!$"

