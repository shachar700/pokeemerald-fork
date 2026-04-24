BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "בוהאהאהא!\p"
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} לדעת מלהסתכל עכשיו,\n"
	.string "אבל פעם הייתי מאמנת קשוחה.\p"
	.string "היה לי מוניטין בתור היופי הכי\n"
	.string "קשוח בסביבה, אני אומרת לך!\p"
	.string "… … … … … …\p"
	.string "מה זה עכשיו?\n"
	.string "את{EMIT_HEY} לא מאמי{SWAP_NUN}{ADD_HEY} לי.\p"
	.string "אני לא כמו האישה המתנשאת שם\n"
	.string "מעבר. אני באמת מוכשרת!\p"
	.string "ת{SWAP_NUN}{ADD_YUD} לי להוכיח לך את זה.\n"
	.string "אני יכולה ללמד את הפוקימונים שלך מהלכים\l"
	.string "מיוחדים ועם זאת חמודים.\p"
	.string "אבל השיעורים שלי לא ניתנים בחינם.\n"
	.string "מה דעתך לשלם עבור המהלכים שאני מלמדת\l"
	.string "עם קצת נקודות קרב?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "בווהאהאהא!\p"
	.string "האם חזרת ללמוד מהלכי פוקימון\n"
	.string "מיוחדים ועם זאת חמודים?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "בסדר, בסדר, תסתכל{ADD_YUD} לכאן!\n"
	.string "איזה מהלך עליי ללמד?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "המהלך {STR_VAR_1}, נכון?\n"
	.string "זה יעלה {STR_VAR_2} נקודות קרב, אוקיי?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "בסדר, בסדר, עכשיו בחר{ADD_YUD} את הפוקימון\n"
	.string "שעליי ללמד אותו את המהלך.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "מה לע…\n"
	.string "אין לך מספיק נקודות קרב!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "את{EMIT_HEY} רואה כמה אני מוכשרת עכשיו?\n"
	.string "אני אקח את נקודות הקרב שלך, תודה!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "מה זה?\n"
	.string "את{EMIT_HEY} לא רוצה…\p"
	.string "אם את{EMIT_HEY} רוצה לראות כמה אני מוכשרת,\n"
	.string "את{EMIT_HEY} מוזמ{SWAP_NUN}{ADD_TAF} לבוא לראות אותי בכל עת!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "איחיחי!\p"
	.string "אני יודע שקשה לראות עכשיו, אבל פעם\n"
	.string "הייתי מאמן פנטסטי.\p"
	.string "היה לי מוניטין בתור השחיין\n"
	.string "הבלתי מנוצח בסביבה, אני אומר לך!\p"
	.string "… … … … … …\p"
	.string "מה לא בסדר?\n"
	.string "את{EMIT_HEY} לא מאמי{SWAP_NUN}{ADD_HEY} לי.\p"
	.string "אני לא כמו האישה המגושמת שם\n"
	.string "מעבר. אני באמת מנוסה!\p"
	.string "אני יכול להוכיח לך את זה.\n"
	.string "אני יכול ללמד את הפוקימונים שלך מהלכים\l"
	.string "קשוחים ועם זאת יפים.\p"
	.string "אבל השיעורים שלי לא ניתנים בחינם.\n"
	.string "מה דעתך לשלם עבור המהלכים שאני מלמד\l"
	.string "עם קצת נקודות קרב?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "איחיחי!\p"
	.string "האם חזרת ללמוד מהלכי פוקימון\n"
	.string "קשוחים ועם זאת יפים?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "הנשים האלה, הדרך שבה הן משמיצות\n"
	.string "אחת את השנייה, את{EMIT_HEY} בטח חושב{ADD_TAF}\l"
	.string "שהן לא מסתדרות.\p"
	.string "אבל אם זה היה נכון, הן לא היו\n"
	.string "נשארות כאן יחד, נכון?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "כשהייתי רק צעיר קטן,\n"
	.string "הנשים האלה היו חזקות ויפות.\p"
	.string "הן היו אלילות בקרבנו המאמנים.\p"
	.string "גם עכשיו, הגיל לא הקהה את\n"
	.string "היכולות שלהן.\p"
	.string "למעשה, מהלכי הפוקימון שלהן הפכו\n"
	.string "מלוטשים יותר.\p"
	.string "אבל… משום מה, אני לא יכול שלא\n"
	.string "להרגיש את זה…\p"
	.string "הזמן כל כך אכזרי…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "משקם עד\n"
	.string "מחצית מהנח\n"
	.string "המקסימליים של המשתמש.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "מטיל נזק\n"
	.string "זהה לרמה\n"
	.string "של המשתמש.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "משקם מחצית\n"
	.string "מהנזק שהוטל\n"
	.string "על יריב ישן.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "אגרוף חזק\n"
	.string "שנזרק עם\n"
	.string "כוח מדהים.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "בעיטה עוצמתית\n"
	.string "בצורה יוצאת\n"
	.string "דופן עם כוח עצום.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "הטלת גוף מלאה\n"
	.string "שעלולה לגרום\n"
	.string "לשיתוק.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "סלעים גדולים\n"
	.string "מוטלים. עלול\n"
	.string "לגרום לרתיעה.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "מגיב על כל\n"
	.string "מכה פיזית\n"
	.string "בכוח כפול.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "זעזוע חלש של\n"
	.string "חשמל שמשתק\n"
	.string "את היריב.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "ריקוד לחימה\n"
	.string "שמעלה בחדות\n"
	.string "את ההתקפה.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "מתכרבל כדי\n"
	.string "להסתיר נקודות\n"
	.string "תורפה ולהעלות הגנה.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "התקפה קולנית\n"
	.string "שניתן להשתמש\n"
	.string "בה רק בשינה.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "מטיל בוץ על\n"
	.string "פני היריב כדי\n"
	.string "להפחית את הדיוק.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "מתיז קרניים\n"
	.string "דמויות כוכב\n"
	.string "שלעולם לא מחטיאות.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "התקפה מצמררת\n"
	.string "שמורידה את\n"
	.string "המהירות של היריב.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "עומד בכל\n"
	.string "התקפה למשך\n"
	.string "סיבוב אחד, ומשאיר 1 נח.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "מעתיק את\n"
	.string "ההשפעות של היריב\n"
	.string "ונותן למשתמש.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "אגרוף קפוא\n"
	.string "שעלול להקפיא\n"
	.string "את היריב.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "אגרוף\n"
	.string "מחושמל שעלול\n"
	.string "לשתק את היריב.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "אגרוף לוהט\n"
	.string "שעלול לשרוף\n"
	.string "את היריב.$"
