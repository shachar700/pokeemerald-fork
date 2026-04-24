BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "האם זו הפעם הראשונה שלך כאן?\n"
	.string "אנא צעד{ADD_YUD} מכאן!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "קווי החזית של קרבות פוקימונים!\n"
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לחזית הקרב!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "למבקר בפעם הראשונה, אנו מנפיקים\n"
	.string "את היתר הקרב.\p"
	.string "הוא מיועד לשימוש בכל המתקנים\n"
	.string "שבחזית הקרב.\p"
	.string "הנה בשבילך!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} קיבל{ADD_HEY} את\n"
	.string "היתר חזית הקרב.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} הניח{ADD_HEY} את כרטיס המאמן\n"
	.string "בהיתר חזית הקרב.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "אנו מקווים שתהנ{EMIT_HEY}{ADD_YUD} מכל מה שיש\n"
	.string "לחזית הקרב להציע!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: טוב, אם זה לא {PLAYER}{KUN}!\n"
	.string "הגעת לכאן!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "מדריך: או! מר סקוט, אדוני!\n"
	.string "יום טוב לך, אדוני!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "סקוט: נהדר לראות אותך כאן,\n"
	.string "באמת שכן!\p"
	.string "אני מקווה שתקדיש{ADD_YUD} את זמנך\n"
	.string "ותחק{EMIT_VAV}ר{ADD_YUD} את כל המקום.\p"
	.string "באופן טבעי, אני מקווה שגם תחוו{EMIT_HEY}{ADD_YUD}\n"
	.string "את המהות הטהורה של קרב.\p"
	.string "גם המגורים שלי כאן, אז תרגיש{ADD_YUD}\n"
	.string "חופשי לבקר אם יש לך זמן.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "אני המדריך שלך למתקנים השונים\n"
	.string "כאן בחזית הקרב.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "על מה תרצ{EMIT_HEY}{ADD_YUD} ללמוד?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "זהו המגדל הענק הנחשב\n"
	.string "לסמל של חזית הקרב.\p"
	.string "יש ארבעה סוגים של חדרי קרב\n"
	.string "במגדל לקרבות יחידים, זוגות, מרובים,\l"
	.string "וקרבות מרובים מקושרים.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "כיפת הקרב היא הבניין הגדול\n"
	.string "שמעוצב כמו ביצה ענקית.\p"
	.string "אירועים הנקראים טורנירי קרב נערכים\n"
	.string "במתקן הזה.\p"
	.string "טורנירי הקרב מוצעים\n"
	.string "בשני מסלולים--לקרבות יחידים וזוגות.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "ארמון הקרב הוא הבניין האדום\n"
	.string "שמימין לחזית הקרב.\p"
	.string "יש שני סוגים של אולמות קרב\n"
	.string "לקרבות יחידים וזוגות.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "זירת הקרב היא הבניין דמוי הדוג'ו\n"
	.string "במרכז-ימין של חזית הקרב.\p"
	.string "אירוע שנקרא טורניר נוקאאוט קבוע\n"
	.string "מתקיים בזירת הקרב.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "מפעל הקרב הוא הבניין הגדול\n"
	.string "שהכי קרוב אלינו.\p"
	.string "אירוע שנקרא החלפת קרב\n"
	.string "נערך שם.\p"
	.string "אירוע החלפת הקרב מוצע\n"
	.string "בשני מסלולים לקרבות יחידים וזוגות.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "נהר הקרב הוא הבניין שמעוצב\n"
	.string "כמו פוקימון במרכז-שמאל של\l"
	.string "חזית הקרב.\p"
	.string "אירוע שנקרא בחירת קרב\n"
	.string "נערך שם.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "פירמידת הקרב היא הפירמידה\n"
	.string "העצומה.\p"
	.string "אירוע שנקרא מסע הקרב\n"
	.string "נערך שם.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "אולם הדירוג ממוקם ליד\n"
	.string "מגדל הקרב.\p"
	.string "שם, את{EMIT_HEY} יכול{ADD_HEY} לראות את השיאים הפנטסטיים\n"
	.string "ביותר שהושארו על ידי מאמנים\l"
	.string "שלקחו על עצמם את האתגרים הרבים של\l"
	.string "חזית הקרב.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "פינת שירות ההחלפה נמצאת ליד\n"
	.string "מגדל הקרב.\p"
	.string "את נקודות הקרב שהרווחת\n"
	.string "בחזית הקרב ניתן להמיר\l"
	.string "שם בפרסים מדהימים.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "אני המדריך שלך לחוקים הבסיסיים\n"
	.string "שמשותפים לכל האתגרים המוצעים\l"
	.string "על ידי המתקנים שבחזית הקרב.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "על מה תרצ{EMIT_HEY}{ADD_YUD} ללמוד?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "כל האתגרים במתקנים של\n"
	.string "חזית הקרב מגיעים בשני\l"
	.string "מסלולים--רמה 05 ורמה פתוחה.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "מסלול רמה 05 פתוח לפוקימונים\n"
	.string "עד וכולל רמה 05.\p"
	.string "עם זאת, זכ{EMIT_VAV}ר{ADD_YUD} שאף מאמן\n"
	.string "שתתמודד מולו לא יהיה לו פוקימון\l"
	.string "מתחת לרמה 05.\p"
	.string "המסלול הזה הוא רמת הכניסה\n"
	.string "לקרבות בחזית הקרב.\p"
	.string "כדי להתחיל, אנו מקווים שתאתגר{ADD_YUD}\n"
	.string "את המסלול הזה.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "מסלול רמה פתוחה לא מציב מגבלה\n"
	.string "על רמות הפוקימונים שנכנסים\l"
	.string "לאתגרים.\p"
	.string "רמות היריבים שלך יותאמו\n"
	.string "כדי להתאים לרמות של\l"
	.string "הפוקימונים שלך.\p"
	.string "עם זאת, אף מאמן שתתמודד{ADD_YUD} מולו לא\n"
	.string "יהיה לו פוקימון מתחת לרמה 06.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "כמעט כל סוג של פוקימון יכול לקבל\n"
	.string "את האתגרים בכל המתקנים.\p"
	.string "עם זאת, ביצים וסוגי פוקימונים מסוימים\n"
	.string "אינם מורשים.\p"
	.string "מספר הפוקימונים הנדרש עבור\n"
	.string "אתגרים יהיה תלוי במתקן.\p"
	.string "עם זאת, בכל המתקנים, שניים או יותר\n"
	.string "מאותו סוג של פוקימונים אינם\l"
	.string "מותרים.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "כאשר נכנסים לאתגר במתקן של חזית\n"
	.string "הקרב, פוקימונים לא יכולים להחזיק\l"
	.string "אותו סוג של פריט.\p"
	.string "אנא ודא{ADD_YUD} שכל הפוקימונים\n"
	.string "שנכנסים לאתגר מחזיקים\l"
	.string "פריטים שונים.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "אני המדריך שלך להיתר חזית הקרב.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "על מה תרצ{EMIT_HEY}{ADD_YUD} ללמוד?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "ישנם שבעה מתקנים\n"
	.string "בחזית הקרב.\p"
	.string "מאמנים שמקבלים הכרה על יכולותיהם\n"
	.string "עשויים לקבל סמלים כפרס\l"
	.string "מכל אחד מהמתקנים.\p"
	.string "כדי לזכות בסמל, מאמנים עשויים להצטרך\n"
	.string "להביס מאמנים אחרים ברצף,\l"
	.string "ועשויים להצטרך לנצח באירועים שוב ושוב.\p"
	.string "זה בהחלט לא קל לזכות בסמלים.\n"
	.string "אני מאחל לך את כל המזל שבעולם!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "אפשר להקליט קרב אחד\n"
	.string "בכרטיס חזית הקרב שלך.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY} להקליט קרב שהיה לך עם\n"
	.string "חבר או חברים.\p"
	.string "או שאת{EMIT_HEY} יכול{ADD_HEY} להקליט קרב שנערך\n"
	.string "בחזית הקרב, לא כולל קרבות\l"
	.string "בנהר הקרב או בפירמידת הקרב.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY} לבחור להקליט את הקרב שלך\n"
	.string "בסוף הקרב.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "נקודות קרב הן פרסים שניתנים\n"
	.string "למאמנים שנלחמו בצורה יוצאת דופן\l"
	.string "בחזית הקרב.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY} להמיר את נקודות הקרב שלך\n"
	.string "בפרסים בפינת שירות ההחלפה.$"

