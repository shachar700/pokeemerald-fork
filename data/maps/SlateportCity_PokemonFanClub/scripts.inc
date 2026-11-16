SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applywaitmovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	applywaitmovement VAR_LAST_TALKED, Common_Movement_Delay48
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_AZUMARILL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "אר-אם! אני היושב ראש של מועדון\n"
	.string "המעריצים של פוקימון!\p"
	.string "בתור היושב ראש, אני מטבעי\n"
	.string "הכי חשוב!\p"
	.string "אף אחד לא יכול להתעלות עליי כשזה\n"
	.string "נוגע לגידול פוקימון. אף אחד!\p"
	.string "ובכן, הרש{EMIT_HEY}{ADD_YUD}לי לספר לך על\n"
	.string "תחרויות פוקימון.\p"
    .string "אלו אירועים שבהם אפשר להציג\n"
    .string "פוקימונים לעיני כל העולם!\p"
    .string "עם זאת, הן מתקיימות בערים רחוקות,\n"
	.string "אז אני לא יכול להשתתף לעיתים קרובות.\p"
    .string "לכן אנחנו מתכנסים כאן כדי להציג\n"
    .string "את הפוקימונים שלנו, ולאפשר לאחרים\l"
    .string "להראות לנו את שלהם.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
    .string "הפוקימון של מאמן שהשתתף\n"
    .string "בתחרות פוקימונים…\l"
    .string "אותו הייתי רוצה לראות.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "אר-אם! אני רואה שהשתתפת\n"
	.string "בתחרות פוקימון!\p"
    .string "בבקשה! הרש{EMIT_HEY}{ADD_YUD} לי לבדוק איך גידלת\n"
    .string "את הפוקימון שלך.\p"
    .string "זה משמח אותי לראות פוקימונים\n"
    .string "שגודלו על ידי מאמנים אחרים.\p"
    .string "ההבעות השמחות של פוקימונים\n"
    .string "שגודלו עם טיפוח נכון…\p"
    .string "עיניו הטובות של המאמן שטיפח\n"
    .string "וגידל את הפוקימון…\p"
    .string "המחשבה הזו לבדה ממלאת את לבי\n"
    .string "בשמחה עצומה.\p"
    .string "או! אני ממש מצטער!\n"
    .string "סלח{ADD_YUD} לי על הפטפוט!\p"
    .string "בבקשה! הרש{EMIT_HEY}{ADD_YUD} לי לבדוק כמה\n"
    .string "הפוקימון שלך גדל!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "איך הפוקימון שלך גדל?\n"
	.string "הרש{EMIT_HEY}{ADD_YUD} לי לבדוק.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "המ, המ…\n"
	.string "אני מבין…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "הממ… זה לא רע, אבל זה גם לא\n"
    .string "טוב…\p"
	.string "את{EMIT_HEY}, המאמ{SWAP_NUN}{ADD_TAF}, צרי{SWAP_CHAF}{ADD_HEY} להשקיע יותר"
	.string "מאמץ בגידול הפוקימון הזה!\p"
	.string "למשל, אוכל להציע שתת{SWAP_NUN}{ADD_YUD}\n"
	.string "לו יותר פוקיגושים?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "אוי, לי…\p"
    .string "הפוקימון שלך גדל היטב,\n"
    .string "ולכן מגיע לך פרס.\p"
    .string "למרבה הצער, אין לך מקום לזה\n"
    .string "בתיק שלך.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "ה{STR_VAR_1} שלך גדל בצורה\n"
	.string "מרשימה ביותר!\l"
	.string "הוא דוגמה מצויינת!\p"
	.string "אבל! אם היית נות{SWAP_NUN}{ADD_TAF} לו את זה,\n"
	.string "הוא יגדל אפילו יותר טוב! בהחלט!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
    .string "ת{SWAP_NUN}{ADD_YUD} לפוקימון להחזיק את הצעיף האדום הזה.\p"
    .string "כולם יבחינו בקוליות של\n"
    .string "אותו פוקימון!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
    .string "ת{SWAP_NUN}{ADD_YUD} לפוקימון להחזיק את הצעיף הכחול הזה.\p"
    .string "היופי שלו יודגש אפילו יותר\n"
    .string "מאשר עכשיו!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
    .string "ת{SWAP_NUN}{ADD_YUD} לפוקימון להחזיק את הצעיף הורוד הזה.\p"
    .string "זה ידגיש עוד יותר את\n"
    .string "החמידות של הפוקימון!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
    .string "ת{SWAP_NUN}{ADD_YUD} לפוקימון להחזיק את הצעיף הירוק הזה.\p"
    .string "זה ישפר את החוכמה\n"
    .string "של הפוקימון!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
    .string "ת{SWAP_NUN}{ADD_YUD} לפוקימון להחזיק את הצעיף הצהוב הזה.\p"
    .string "זה יחזק את קשיחותו\n"
    .string "של הפוקימון!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
    .string "אני מתנצל, אבל אין לי יותר\n"
    .string "דברים לתת לך! בכלל לא!\p"
    .string "אחרי הכל, התברכת ביכולת\n"
    .string "לגדל פוקימונים בלי להזדקק\l"
    .string "לשום פריט!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
    .string "אני אוהב לראות פוקימונים שאוהבים\n"
    .string "את המאמנים שלהם.\p"
    .string "פוקימונים רגישים מאוד\n"
    .string "לרגשות של המאמנים שלהם.\p"
    .string "אם תטפל{ADD_YUD} בפוקימון שלך באהבה\n"
    .string "ובדאגה, הוא יאהב אותך בחזרה.\p"
    .string "כשהפוקימון שלך יאהב אותך,\n"
    .string "בוא{ADD_YUD} להראות לי.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
    .string "הפוקימון שלך ממש מעריץ אותך.\p"
    .string "עבורך, מאמ{SWAP_NUN}{ADD_TAF} רחו{SWAP_MEM}{ADD_HEY} במיוחד,\n"
    .string "מתנה ממועדון המעריצים!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
    .string "פוקימונים רגישים מאוד\n"
    .string "לרגשות של המאמנים שלהם.\p"
    .string "אם תטפל{ADD_YUD} בפוקימונים באהבה\n"
    .string "ובדאגה, הם יאהבו אותך בחזרה.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
    .string "אם תמשי{SWAP_CHAF}{ADD_YUD} לתת לפוקימון להתעלף\n"
    .string "בקרב, הוא יתחיל לשנוא את זה.\p"
    .string "בקרוב, הוא יפסיק לסמוך\n"
    .string "על המאמן.\p"
    .string "במילים אחרות, הוא בהחלט לא\n"
    .string "יאהב אותך במיוחד.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "האם פוקימונים נהנים כשמשתמשים\n"
	.string "עליהם פריטים?\p"
    .string "שלי נראה ממש שמח כשנתתי לו\n"
    .string "קצת חלבון.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "{STR_VAR_1}: פפפניאאאאה…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "{STR_VAR_1}: קיווו…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "{STR_VAR_1}: מארימארי?$"

