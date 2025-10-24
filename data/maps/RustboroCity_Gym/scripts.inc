RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "יו, איך הולך?\p"
	.string "תשמע{ADD_YUD}, חבר{ADD_HEY}!\n"
	.string "רוצה להיות האלו{SWAP_PEY}{ADD_HEY}?\p"
	.string "אני לא מאמן בעצמי, אבל אני יכול\n"
	.string "לתת לך עצות מנצחות.\p"
	.string "אז זה סגור! נכוון יחד\n"
	.string "לאליפות הפוקימון!\p"
	.string "התפקיד שלך כמאמ{SWAP_NUN}{ADD_TAF} זה לאסוף\n"
	.string "תגי מכון, נכון?\p"
	.string "אבל מנהיגי מכון הם לא קלים!\p"
	.string "וזה איפה שאני בא לעזור!\n"
	.string "אני כאן כדי לתת עצה של מומחה!\p"
	.string "רוקסן, מנהיגת המכון, משתמשת\n"
	.string "בפוקימון מסוג אבן.\p"
	.string "סוג אבן הוא מאוד עמיד, אבל\n"
	.string "לא יכול לעמוד בפני מהלכי מים\l"
	.string "ומהלכי עשב.\p"
	.string "בוא{ADD_YUD} לראות אותי לאחר מכן, אם הבסת\n"
	.string "את מנהיגת המכון.\p"
	.string "ובכן, ל{SWAP_CHAF}{ADD_YUD} על זה!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "וואו! איזה ניצחון עוצר נשימה!\n"
	.string "העידוד שלי כנראה עבד!\p"
	.string "נהדר!\n"
	.string "תבד{EMIT_VAV}ק{ADD_YUD} את כרטיס המאמן שלך.\p"
	.string "תג האבן שהשגת אמור להיות\n"
	.string "מתועד בו.\p"
	.string "במילים אחרות…\p"
	.string "עשית את הצעד הראשון\n"
	.string "במדרגות לאליפות!\p"
	.string "זה בטח מרגיש מדהים!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "אל תקח{ADD_YUD} אותנו מאמני המכון בקלות!\n"
	.string "אני אראה לך למה אנחנו טובים יותר!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "היית טוב{ADD_HEY} מדי בשבילי…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "עוד לא ראית כלום מהכוח המפחיד\n"
	.string "של פוקימון מסוג סלע!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "אם את{EMIT_HEY} לא מצליח{ADD_HEY} להביס אותי, אין לך\n"
	.string "סיכוי נגד רוקסן!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "וואו! יש לך באמת פוטנציאל!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "רוקסן חזה ממני פי כמה וכמה.\p"
	.string "כדאי שתהי{EMIT_HEY}{ADD_YUD} דרו{SWAP_CHAF}{ADD_HEY}!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "אז אנחנו באמצע העיר,\n"
	.string "אבל אז מה?\p"
	.string "הפוקימון אבן שלי צריך מקום\n"
	.string "להשתולל!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "או, אוי לי!\n"
	.string "המאתגר{ADD_TAF} שלנו ה{EMIT_VAV}{ADD_YUD}א לקוח{ADD_HEY} נחוש{ADD_HEY}!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "אני חייב להוריד את הכובע בפני\n"
	.string "המנהיגה שלנו.\p"
	.string "זה הצריך שכל ותבונה מצידה\n"
	.string "לבחור בסוג אבן מגיל כזה צעיר.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "שלום, אני רוקסן, מנהיגת המכון\n"
	.string "פוקימון ברסטבורו.\p"
	.string "נהייתי מנהיגת מכון כדי שאוכל\n"
	.string "ליישם בקרב את מה שלמדתי בבית הספר\l"
	.string "למאמני פוקימון.\p"
	.string "תוכל{ADD_YUD} להראות לי איך את{EMIT_HEY} נלח{SWAP_MEM}{ADD_TAF},\n"
	.string "ואילו פוקימונים את{EMIT_HEY} בוחר{ADD_TAF}?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "אז…\n"
	.string "הפסדתי…\p"
	.string "זה נראה שיש לי עדיין הרבה\n"
	.string "ללמוד…\p"
	.string "אני מבינה.\p"
	.string "חוקי ליגת הפוקימון אומרים\n"
	.string "שיש לתת למאמנים את זה\l"
	.string "אם הם מביסים את מנהיג המכון.\p"
	.string "בבקשה, קבל{ADD_YUD} את תג האבן\n"
	.string "הרשמי של ליגת הפוקימון.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} קיבל{ADD_HEY} את התג אבן\n"
	.string "מרוקסן.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "תג האבן מחזק את כוח ההתקפה\n"
	.string "של הפוקימונים שלך.\p"
	.string "זה גם מאפשר להם להשתמש במהלך מ.נ\n"
	.string "חיתוך מחוץ לקרב.\p"
	.string "קח{ADD_YUD} את זה גם איתך.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "המכשיר מהלך הזה, מ”מ93,\n"
	.string "מכיל קבורת סלע.\p"
	.string "הוא לא רק גורם לנזק על ידי זריקת\n"
	.string "אבנים, אלא גם מוריד מהירות.\p"
	.string "אם את{EMIT_HEY} משתמש{ADD_TAF} במ”מ, זה מלמד\n"
	.string "מיד את המהלך לפוקימון .\p"
	.string "זכ{EMIT_VAV}ר{ADD_YUD}, ניתן להשתמש במ”מ רק פעם אחת,\n"
	.string "אז חש{EMIT_VAV}ב{ADD_YUD} היטב לפני שאת{EMIT_HEY} משתמש{ADD_TAF} בו.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "מכיוון שאת{EMIT_HEY} כל כך חזקה, עליך\n"
	.string "לאתגר את מנהיגי המכון האחרים.\p"
	.string "על ידי קרבות עם מאמנים רבים,\n"
	.string "תוכל{ADD_YUD} ללמוד המון.$"

RustboroCity_Gym_Text_GymStatue:
	.string "מכון הפוקימון של העיר רסטבורו$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "מכון הפוקימון של העיר רסטבורו\p"
	.string "מאמנים מוסמכים בידי רוקסן:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … ביפ!\p"
	.string "רוקסן: או, שלום, {PLAYER}?\n"
	.string "זאת רוקסן מהעיר רסטבורו.\p"
	.string "שמעתי מבראולי שהתקדמת\n"
	.string "מעלה בדרגות המאמנים\l"
	.string "בקצב מסחרר.\p"
	.string "ובכן, אני מעדיפה לא לחשוב\n"
	.string "שלא אוכל להביס אותך.\p"
	.string "אני מבטיחה, לשפר את המכון שלי\n"
	.string "כדי שתוכל{ADD_YUD} לאתגר אותנו שוב.\p"
	.string "אני מקווה שתצפ{EMIT_HEY}{ADD_YUD} לזה\n"
	.string "כמוני!\p"
	.string "… … … … … …\n"
	.string "… … … … … קליק!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "מנהיגת המכון רוקסן נרשמה\n"
	.string "בפוקינווט.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "רוקסן: אני כל כך שמחה לראות אותך שוב.\n"
	.string "אני רוקסן, מנהיגת המכון כאן.\p"
	.string "אני בטוחה ששנינו חווינו קרבות רבים\n"
	.string "מאז הפעם האחרונה שנפגשנו.\p"
	.string "אשמח לראות כמה השתפרנו.\n"
	.string "בוא נילחם!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "גררר…\n"
	.string "שוב, הפסדתי…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "רוקסן: עדיין יש לי הרבה מה ללמוד\n"
	.string "בקרבות פוקימון.\p"
	.string "ההבנה הזו רק גורמת לי לאהוב\n"
	.string "קרבות אפילו יותר!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "רוקסן: אני כל כך שמחה לראות אותך שוב.\n"
	.string "אני רוקסן, מנהיגת המכון כאן.\p"
	.string "אני בטוחה ששנינו חווינו קרבות רבים\n"
	.string "מאז הפעם האחרונה שנפגשנו.\p"
	.string "אשמח לראות כמה השתפרנו…\p"
	.string "או לא…\n"
	.string "יש לך רק פוקימון אחד איתך?\p"
	.string "אנא חז{EMIT_VAV}ר{ADD_YUD} כשיהיה איתך לפחות\n"
	.string "עוד פוקימון אחד.$"
