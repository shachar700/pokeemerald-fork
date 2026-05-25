RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	bufferspeciesname STR_VAR_1, SPECIES_SEEDOT
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "הלוח מציג שינויים במצבים\n"
	.string "שיכולים להשפיע על פוקימון בקרב.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "איזה נושא את{EMIT_HEY} רוצה לקרוא?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "אם פוקימון מורעל, הוא יאבד\n"
	.string "בהדרגה נקודות חיים, נ”ח בקיצור.\p"
	.string "השפעות הרעל נשארות גם לאחר\n"
	.string "הקרב.\p"
	.string "הנח של פוקימון מורעל יירדו\n"
	.string "גם בשטח.\p"
	.string "לרפא רעל בעזרת נוגדן.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "אם פוקימון משותק, המהירות שלו\n"
	.string "תרד.\p"
	.string "יתכן שהוא לא יוכל לזוז בזמן\n"
	.string "הקרב.\p"
	.string "השותקות נשארת גם לאחר קרב.\n"
	.string "לרפא שיתוק בעזרת ריפוי שיתוק.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "אם פוקימון נרדם, הוא לא יוכל\n"
	.string "להתקיף.\p"
	.string "פוקימון יכול להתעורר בעצמו,\n"
	.string "אך אם הקרב יסתיים בזמן שהוא\n"
	.string "נרדם, הוא יישאר ישן.\p"
	.string "לעורר אותו בעזרת שיקוי מעורר.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "כוויה מפחיתה את עוצמת ההתקפה, ובהדרגה\n"
	.string "מפחיתה נ”ח של הקורבן.\p"
	.string "כוויה נמשכת גם לאחר הקרב.\n"
	.string "לרפא כויה בעזרת ריפוי כויה.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "אם פוקימון קפוא, הוא נהיה\n"
	.string "חסר אונים לחלוטין.\p"
	.string "הוא יישאר קפוא גם לאחר הקרב.\n"
	.string "להפשיר אותו בעזרת ריפוי קרח.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "תלמידים שלא לומדים מקבלים טעם קטן\n"
	.string "מהטופר מהיר שלי.\p"
	.string "בין אם את{EMIT_HEY} תלמיד{ADD_HEY} טוב{ADD_HEY} או לא,\n"
	.string "זה יתברר בדרך שבה תשתמש{ADD_YUD}\l"
	.string "בפריט הזה.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "פוקימון שמחזיק בטופר מהיר\n"
	.string "לפעמים יקדים את יריבו ויפעל\l"
	.string "לפניו.\p"
	.string "ישנם פריטים רבים אחרים שמיועדים\n"
	.string "להחזקה על ידי פוקימון.\p"
	.string "פריטים אלו בלבד נותנים הרבה\n"
	.string "נושאים ללמוד!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "אני מחליף פוקימון עם חבר שלי\n"
	.string "כרגע.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "תמיד רציתי {STR_VAR_1},\n"
	.string "וסוף סוף אני מקבל אחד!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "פוקימונים יכולים להחזיק פריטים,\n"
	.string "אבל הם לא יודעים מה לעשות עם\l"
	.string "פריטים ידי אדם כמו שיתוק ונוגדן.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "את{EMIT_HEY} יודע{ADD_TAF} שלפעמים מהלכי פוקימון\n"
	.string "יכולים לבלבל פוקימון?\p"
	.string "פוקימון מבולבל לפעמים יתקוף\n"
	.string "את עצמו בלי כוונה.\p"
	.string "אבל לאחר הקרב, הוא יחזור למצב\n"
	.string "רגיל.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "פוקימון שמחזיק בפרי יער ירפא את\n"
	.string "עצמו…\p"
	.string "ישנם סוגים רבים של פריטים\n"
	.string "שפוקימונים יכולים להחזיק…\p"
	.string "אוי, זה ממש קשה לרשום את\n"
	.string "הכל…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "זה המחברת של תלמיד זה…\p"
	.string "פוקימון נתפסים באמצעות\n"
	.string "פוכדורים.\p"
	.string "עד שישה פוקימונים יכולים\n"
	.string "ללוות מאמן.\p"
	.string "מאמן הוא מי שתופס\n"
	.string "פוקימון, מגדל אותם, ונלחם\l"
	.string "איתם.\p"
	.string "משימת המאמן היא להביס מאמנים\n"
	.string "חזקים שמחכים באתגר\l"
	.string "מכוני הפוקימון.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "שלום? לא כבר נפגשנו בעבר?\n"
	.string "נראה לי שבעיר פטלבורג.\p"
	.string "הרש{EMIT_HEY}{ADD_YUD} לי להציג את עצמי.\n"
	.string "שמי סקוט.\p"
	.string "טיילתי בכל מקום בחיפוש\n"
	.string "אחר מאמנים יוצאי דופן.\p"
	.string "באופן ספציפי יותר, אני מחפש\n"
	.string "מומחים לקרבות פוקימון.\p"
	.string "אז, מה מביא אותך לבית ספר הזה?\n"
	.string "את{EMIT_HEY} גם מאמ{SWAP_NUN}{ADD_TAF}?\p"
	.string "הדבר הראשון שכדאי לך לעשות הוא\n"
	.string "שפוקימון ילמד את המהלך חיתוך.\p"
	.string "למיטב זכרוני, למישהו בעיר הזה\n"
	.string "יש חיתוק.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "סקוט: הממ…\p"
	.string "רמת הכישרון של התלמידים כאן\n"
	.string "לא ידועה. הפוטנציאל קיים.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "סקוט: או, מה זה?\p"
	.string "זה התג אבן, הלא כן?\n"
	.string "זה די מרשים, הייתי אומר.\p"
	.string "אבל, את{EMIT_HEY} יודע{ADD_TAF}, הייתי שמח לראות\n"
	.string "אותך בקרב.\p"
	.string "זה קשה להבין איך את{EMIT_HEY} בתור\n"
	.string "מאמן מתג ליגה.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "שלום? לא כבר נפגשנו בעבר?\n"
	.string "נראה לי שבעיר פטלבורג.\p"
	.string "הרש{EMIT_HEY}{ADD_YUD} לי להציג את עצמי.\n"
	.string "שמי סקוט.\p"
	.string "טיילתי בכל מקום בחיפוש\n"
	.string "אחר מאמנים יוצאי דופן.\p"
	.string "באופן ספציפי יותר, אני מחפש\n"
	.string "מומחים לקרבות פוקימון.\p"
	.string "או, מה זה?\n"
	.string "זה התג אבן, הלא כן?\n"
	.string "זה די מרשים, הייתי מרשים, עבור\n"
	.string "מאמ{SWAP_NUN}{ADD_TAF} מתחיל{ADD_HEY} כמוך.\p"
	.string "אבל, את{EMIT_HEY} יודע{ADD_TAF}, הייתי שמח לראות\n"
	.string "אותך בקרב.\p"
	.string "זה קשה להבין איך את{EMIT_HEY} בתור\n"
	.string "מאמן מתג ליגה.$"

