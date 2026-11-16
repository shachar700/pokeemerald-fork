LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applywaitmovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "המ, אז הם הכפילו את מספר האורחים\n"
	.string "באמצעות שימוש בפוקימונים כאטרקציות?\p"
	.string "המ, טוב, אולי כדאי שאני אהפוך פוקימון\n"
	.string "חמוד לקמע של הפונדק שלנו.\p"
	.string "אני תוהה אם זה ימשוך יותר אורחים\n"
	.string "להתארח אצלנו?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "או, סליחה, סליחה!\n"
	.string "הייתי שקוע מדי בצפייה בטלוויזיה!\p"
	.string "מאז שצוות אקווה הגיע לעיר,\n"
	.string "התיירים נמנעים מלהגיע.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "היי, זוז{ADD_YUD} מקדימה!\n"
	.string "אני לא רואה את הטלוויזיה!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "מדהים! את{EMIT_HEY} אומר{ADD_TAF} לי שפוקימון\n"
	.string "מצא פריט אבוד של מישהו?\p"
	.string "זה משהו. אם היו לנו כמה פוקימונים\n"
	.string "חכמים כאלה…\p"
	.string "היינו יכולים לאתר כל דבר שהאורחים\n"
	.string "שלנו איבדו…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "או, סליחה, סליחה!\n"
	.string "הייתי שקוע מדי בצפייה בטלוויזיה!\p"
	.string "שמעתי שמישהו פירק\n"
	.string "את המחבוא של צוות אקווה.\p"
	.string "בזכות זה, בדיוק סגרנו הזמנה\n"
	.string "מקבוצה גדולה.\p"
	.string "זו הייתה חברה שנקראת… אה…\n"
	.string "גיים משהו…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "מדהים! פוקימון ששמר על הבית\n"
	.string "תפס פורץ?\p"
	.string "זה משהו. אם היה לנו פוקימון קשוח\n"
	.string "כשומר ביטחון…\p"
	.string "היינו יכולים לספק לאורחים שלנו\n"
	.string "בטיחות גדולה יותר.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "או, סליחה, סליחה!\n"
	.string "הייתי שקוע מדי בצפייה בטלוויזיה.\p"
	.string "אה, כן. קבוצה גדולה של אורחים הגיעה\n"
	.string "לפני זמן קצר.\p"
	.string "הם נרשמו כגיים פריק,\n"
	.string "אז אני מניח שהם בטח מכינים משחקים.\p"
	.string "אוי ואבוי, מוטב שאתחיל לעבוד על\n"
	.string "ארוחת הערב שלהם!$"

