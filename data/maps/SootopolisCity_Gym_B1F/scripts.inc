SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "אראה לך את הטכניקות הנשגבות\n"
	.string "שלמדתי ממנהיג המכון שלנו, חואן!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "סלח לי, חואן…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "כדאי לראות מה קורה כשכל\n"
	.string "אריחי הרצפה נסדקים.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "הגעת עד לכאן, אבל לחואן\n"
	.string "לא תגיע{ADD_YUD}.\p"
	.string "לא אם תפסיד{ADD_YUD} לי!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "את{EMIT_HEY} חזק{ADD_HEY}!\n"
	.string "המראה החמוד שלך הטעה אותי!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "אולי את{EMIT_HEY} מספיק טוב{ADD_HEY} כדי לא\n"
	.string "להימחק במכה אחת של חואן.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "המראה של חואן מנהל\n"
	.string "קרב…\p"
	.string "היופי שבו גרם לי\n"
	.string "להפוך למאמנת.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "נלחמת ביותר יופי ממה\n"
	.string "שאני הצלחתי…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "החן שאת{EMIT_HEY} מביא{ADD_HEY} לקרב הוא\n"
	.string "נפלא.\p"
	.string "אוי… כמה מזל יש לי שמצאתי\n"
	.string "פוקימונים.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "אני צריכה ללמד אותך כמה קרבות\n"
	.string "יכולים להיות קשים.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "אה.\n"
	.string "את{EMIT_HEY} חזק{ADD_HEY}.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "אגיד לך משהו טוב.\p"
	.string "אם את{EMIT_HEY} רוצה להגיע לחואן,\n"
	.string "צריך לדרוך על כל אריח פעם אחת.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "מכון הפוקימונים ברמה הגבוהה ביותר\n"
	.string "באזור הואן…\p"
	.string "זה מכון סוטופוליס.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "איזו רמה גבוהה יש לך!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "במקום להסתפק בלהיות\n"
	.string "במכון חזק, נראה לי שאימון\l"
	.string "במקומות אחרים יחזק אותך יותר.\l"
	.string "ומעל הכול, זה נראה כיף יותר.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "אני מאמנת את הפוקימונים שלי יחד עם\n"
	.string "חואן.\p"
	.string "אל תחשוב{ADD_YUD} שאני טרף קל.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "הובסתי…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "אני חושבת שיש לך פוטנציאל.\n"
	.string "למה שלא תישאר{ADD_YUD} להתאמן איתנו?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "גלישה חיננית על הקרח בלי\n"
	.string "לחצות אף קו…\p"
	.string "מאמן שיציג ביצוע כזה\n"
	.string "יהיה יפה ואלגנטי!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "סליחה, מה?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "זה ממש ברור, אבל כמה את{EMIT_HEY} חזק{ADD_HEY}\n"
	.string "כמאמ{SWAP_NUN}{ADD_TAF} לא קשור בכלל\l"
	.string "לכמה את{EMIT_HEY} צעיר{ADD_HEY} או מבוגר{ADD_TAF}.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "כשאני עם הפוקימונים שלי, הזמן\n"
	.string "טס לפני שמספיקים להגיד ”אופס!“$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "אופס!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "הלוואי שיכולתי לשכוח ממקרים אבודים\n"
	.string "לפני שאני מספיקה להגיד ”אופס!“$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "אני יכולה להילחם עם פוקימונים נדירים\n"
	.string "ממש, אם תרצ{EMIT_HEY}{ADD_YUD}.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "אוי, הנה! הספקת להסתכל טוב\n"
	.string "על הפוקימונים שלי?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "באתי למכון הזה כי חואן\n"
	.string "שיבח אותי על הפוקימונים היקרים שלי.\p"
	.string "אוי, לו רק פגשתי את חואן לפני שנים\n"
	.string "כשהייתי צעירה יותר…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "צחקוק…\n"
	.string "המבט הקודר שלך כל כך מקסים.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "אוי ואבוי.\n"
	.string "הייתי הרבה יותר מדי רכה איתך.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "לא היית מצליח{ADD_HEY} לגעת בחואן,\n"
	.string "אני בטוחה. צחקוק…$"

