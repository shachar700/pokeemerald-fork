MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "זיכרונות על {STR_VAR_1} היקר שלי…\n"
	.string "עיניי עולות על גדותיהן מלחשוב על זה.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "אוץ', אאוץ'… יש כאן ושם חורים\n"
	.string "בקרקע.\p"
	.string "לא שמתי לב ונפלתי מהקומה שמעל.$"

MtPyre_2F_Text_MarkIntro:
	.string "היי! את{EMIT_HEY} מחפש{ADD_TAF} פוקימונים?\n"
	.string "הגעת אחריי! זה לא מנומס!$"

MtPyre_2F_Text_MarkDefeat:
	.string "איייי!\n"
	.string "אני מצטער, סלח{ADD_YUD} לי בבקשה!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "אנשים לא באים לכאן לעתים קרובות, אז\n"
	.string "חשבתי שיהיו כאן פוקימונים נדירים.$"

MtPyre_2F_Text_LukeIntro:
	.string "לוק: אנחנו כאן במסגרת אתגר.\p"
	.string "היהיה, אם אראה לה כמה אני מגניב,\n"
	.string "היא תתאהב בי. אני יודע את זה!\p"
	.string "אני יודע! אני ארסק אותך ואראה לה\n"
	.string "כמה אני מגניב!$"

MtPyre_2F_Text_LukeDefeat:
	.string "לוק: וופסי!$"

MtPyre_2F_Text_LukePostBattle:
	.string "לוק: טוב, הפסדנו אבל זה בסדר!\n"
	.string "אני ממש כאן לידך.\l"
	.string "אנחנו נעבור את התיגר הזה!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "לוק: אם את{EMIT_HEY} רוצה להתמודד מולי,\n"
	.string "תביא{ADD_YUD} עוד פוקימונים.\p"
	.string "אם לא, אני לא אוכל להשוויץ בפני\n"
	.string "החברה שלי כמה אני מגניב!$"

MtPyre_2F_Text_DezIntro:
	.string "דז: באתי לכאן במסגרת תיגר עם\n"
	.string "החבר שלי.\p"
	.string "זה ממש מפחיד, אבל אני עם החבר\n"
	.string "שלי. זה בסדר.\p"
	.string "אני יודעת! אני אגרום לחבר שלי להיראות\n"
	.string "מגניב על ידי כך שאביס אותך!$"

MtPyre_2F_Text_DezDefeat:
	.string "דז: ואאאאה! אני מפחדת!$"

MtPyre_2F_Text_DezPostBattle:
	.string "דז: אנחנו מאוהבים, אז לא אכפת לנו\n"
	.string "אם נפסיד!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "דז: אם את{EMIT_HEY} רוצה לאתגר אותנו, את{EMIT_HEY}\n"
	.string "צרי{SWAP_CHAF}{ADD_HEY} להביא לפחות שני פוקימונים.\p"
	.string "החבר שלי חזק.\n"
	.string "רק פוקימון אחד לא יספיק בכלל.$"

MtPyre_2F_Text_LeahIntro:
	.string "את{EMIT_HEY} מראה לא מוכר…\n"
	.string "עז{EMIT_VAV}ב{ADD_YUD} לפני שיקרה לך משהו!$"

MtPyre_2F_Text_LeahDefeat:
	.string "הממ…\n"
	.string "את{EMIT_HEY} עמיד{ADD_HEY}.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "המשפחה שלנו הם מאמנים כאן\n"
	.string "מאז ימי סבתא-רבתא שלי…\p"
	.string "זו חובתי להגן על\n"
	.string "ההר הזה…$"

MtPyre_2F_Text_ZanderIntro:
	.string "קייאאאהה!\n"
	.string "אני מבוהל!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "לאאאאא!\n"
	.string "איבדתי את העשתונות!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "אני נבהל בכל פעם שאני רואה\n"
	.string "משהו זז…\p"
	.string "לא הייתי צריך לבוא לכאן להתאמן…$"

