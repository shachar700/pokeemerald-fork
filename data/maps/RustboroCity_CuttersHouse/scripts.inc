RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "ההבעה הנחושה הזו…\n"
	.string "האופן הגמיש שבו את{EMIT_HEY} נע{ADD_HEY}…\l"
	.string "והפוקימונים המאומנים שלך…\p"
	.string "ברור שאת{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF} מיומ{SWAP_NUN}{ADD_TAF}!\p"
	.string "לא, חכ{EMIT_HEY}{ADD_YUD}, אל תגיד{ADD_YUD} מילה.\n"
	.string "אני יכול להבין רק מלראות אותך.\p"
	.string "אני בטוח שתוכל{ADD_YUD} להשתמש\n"
	.string "במכשיר הנסתר הזה היטב.\p"
	.string "אין צריך להיות צנוע{ADD_HEY} או בייש{SWAP_NUN}{ADD_YUD}{ADD_TAF}.\n"
	.string "קדימה, קח{ADD_YUD} אותו!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "המכשיר הנסתר הזה, או מ״נ\n"
	.string "לקיצור, הוא חיתוך.\p"
	.string "מהלך מ״נ הוא כזה שניתן להשתמש בו\n"
	.string "על ידי פוקימון גם מחוץ לקרב.\p"
	.string "כל פוקימון שלמד חיתוך יכול\n"
	.string "לחתוך עצים דקים אם המאמן\l"
	.string "זכה בתג האבן.\p"
	.string "ובניגוד למ״מ, ניתן להשתמש במ״נ \n"
	.string "יותר מפעם אחת.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "כאשר הרחיבו את העיר רסטבורו,\n"
	.string "אבא שלי עזר.\p"
	.string "הוא גרם לפוקימונים שלו להשתמש בחיתוך\n"
	.string "כדי לנקות את הקרקע מעצים.$"

