LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "אוי, לי, לי! האם את{EMIT_HEY} מטייל{ADD_YUD} לבד?\n"
	.string "אבל את{EMIT_HEY} כל כך צעיר{ADD_HEY}! כל הכבוד לך!\p"
	.string "אני בטוח שהילדים שלי יכולים ללמוד\n"
	.string "ממך דבר או שניים!\p"
	.string "אני? אני מאסטר הפוקיגושים.\p"
	.string "אם אני נעשה רציני רק קצת, זה כי,\n"
	.string "אני יכול לרקוח פוקיגושים נהדרים.\p"
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} ללמוד ממני,\n"
	.string "מאסטר הפוקיגושים?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "או? את{EMIT_HEY} בטוח{ADD_HEY}?\p"
	.string "את{EMIT_HEY} לא צרי{SWAP_CHAF}{ADD_HEY} תמיד לנסות לעשות\n"
	.string "הכל לבד, יקיר{ADD_TAF}י!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "הו, טוב! את{EMIT_HEY} נפש חכמה!\n"
	.string "זה הולך להיות קצת ארוך, אז תקשיב{ADD_YUD} טוב!\p"
	.string "את{EMIT_HEY} מוכ{SWAP_NUN}{ADD_HEY}?\p"
	.string "אם את{EMIT_HEY} מסתכל{ADD_TAF} על פוקיגושים, אתה אמור לראות\n"
	.string "שהם מדורגים לפי איך שהם מרגישים.\p"
	.string "ככל שדירוג התחושה נמוך יותר,\n"
	.string "כך הוא טוב יותר. אל תשכח{ADD_YUD} זאת!\p"
	.string "לפוקיגוש טוב יש דירוג תחושה\n"
	.string "נמוך ורמה גבוהה.\p"
	.string "פוקימון יכול לאכול יותר פוקיגושים טובים\n"
	.string "מאשר כאלה רגילים, גם כן.\p"
	.string "וזה חשוב.\p"
	.string "אם את{EMIT_HEY} רוצה ליצור פוקיגושים חלקים,\n"
	.string "השתמש{ADD_YUD} בסוגים שונים של פירות יער.\p"
	.string "אל תהי{EMIT_HEY}{ADD_YUD} קמצ{SWAP_NUN}{ADD_YUD}{ADD_TAF}--סוגי פירות היער\n"
	.string "משפיעים על החלקות של הפוקיגושים.\p"
	.string "ועוד דבר.\p"
	.string "ככל שיותר אנשים מערבבים פירות יער,\n"
	.string "כך הפוקיגושים חלקים יותר.\p"
	.string "זו הסיבה שאת{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לדבר עם אנשים אחרים\n"
	.string "וליצור פוקיגושים יחד.\p"
	.string "זה בערך כל מה שאת{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לדעת כדי\n"
	.string "ליצור פוקיגושים טובים.\p"
	.string "אם לכולם היו פוקימונים שהם אוהבים,\n"
	.string "פוקיגושים חלקים, ומשפחה אוהבת,\l"
	.string "העולם היה מקום שמח יותר.\p"
	.string "אל תוותר{ADD_YUD}, יקיר{ADD_TAF}י!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "כשאשתי ילדה רביעייה, את{EMIT_HEY} יכול{ADD_HEY}\n"
	.string "להיות בטוח{ADD_HEY} שהייתי בהלם.\p"
	.string "אבל, עכשיו, לראות אותם משחקים יחד,\n"
	.string "זה משמח אותי.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "אנחנו עושים קרבות מרובי משתתפים, אבל אני\n"
	.string "יודע שאני הולך לנצח.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "אנחנו אוהבים לערבב דברים\n"
	.string "בפינת הרשומות.\p"
	.string "אבל מה מתערבב שם?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "אנחנו הולכים ליצור פוקיגושים\n"
	.string "בעזרת הבלנדר פירות יער!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "אני רוצה להתגאות בכמה שהפוקימון שלי\n"
	.string "קשוח, אז אנחנו הולכים להשתתף\l"
	.string "בתחרות יחד.$"

