SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "אממ… אם זה הולך לפה, וזה\n"
	.string "הולך לשם…\p"
	.string "אז לאן הדבר הזה הולך?\n"
	.string "ומה לגבי הקטנצ'יק הזה?\p"
	.string "אאאחח! אני לא מצליח להבין שום\n"
	.string "דבר מזה!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "המ?\n"
	.string "הי, אני דוק.\p"
	.string "קפטן סטרן הזמין ממני\n"
	.string "לתכנן למעבורת.\p"
	.string "או! הדבר שם…\n"
	.string "האם אלה סחורת דבון?\p"
	.string "אבל, הממ…\n"
	.string "זה לא מספיק…\p"
	.string "קפטן סטרן יצא לאנשהו.\n"
	.string "הוא אמר שיש לו עבודה לעשות.\p"
	.string "תוכל{ADD_YUD} אולי למצוא את קפטן.\n"
	.string "סטרן ולמסור לו את זה?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "דוק: לאן קפטן סטרן נעלם?\p"
	.string "תוכל{ADD_YUD} למצוא את קפטן סטרן\n"
	.string "ולמסור לו את החבילה הזאת?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "דוק: בניית ספינות היא אומנות.\p"
	.string "הרבה דברים אי אפשר להבין\n"
	.string "רק בעזרת חישובים.\p"
	.string "הייתי שמח לעצה מותיק\n"
	.string "שמכיר את הים…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "דוק: הי! מר ברייני הצטרף אלינו\n"
	.string "כדי לעזור לנו.\p"
	.string "בזכות המלח הותיק, המעבורת\n"
	.string "מתקדמת יפה מאוד בבנייה.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "דוק: המעבורת סוף סוף מוכנה!\p"
	.string "הא/ק גאות החדשה היא באמת פלא\n"
	.string "של טכנולוגיה!\p"
	.string "אבל, יש לי תחושה שאנחנו יכולים\n"
	.string "לבנות משהו טוב עוד יותר.\p"
	.string "את{EMIT_HEY} יודע{ADD_TAF}, לטכנולוגיה אין סוף\n"
	.string "להתקדמות.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "מר ברייני: אה, {PLAYER}{KUN}!\n"
	.string "עבר כל כך הרבה זמן!\p"
	.string "איי, מאז שפגשתי אותך, הכלב ים הזקן\n"
	.string "הזה מרגיש שובב!\p"
	.string "אז החלטתי לעזור לדוק לבנות מעבורת.\p"
	.string "איי, אחרי הכל, מעבורת תוכל\n"
	.string "לסחוב מלא אנשים.\p"
	.string "אבל, את{EMIT_HEY} יודע{ADD_TAF}, הדוק הזה\n"
	.string "הוא משהו מיוחד.\p"
	.string "עם הכישרון בטכנולוגיה והניסיון\n"
	.string "שלי, אני בטוח שנוכל\l"
	.string "לבנות ספינה נהדרת, איי!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "העונות, המזג אוויר, איפה\n"
	.string "שהירח יושב בשמיים…\p"
	.string "זה ותנאים אחרים גורמים\n"
	.string "לים לשנות את פניו.\p"
	.string "בדיוק!\n"
	.string "הים הוא כמו יצור חי!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "אני סובל ממחלת ים בקלות.\n"
	.string "אז אני עוזר כאן במקום.$"

