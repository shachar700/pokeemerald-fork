SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "ברוכים הבאים למוזיאון האוקיינוס.\p"
	.string "דמי הכניסה הם 05¥.\n"
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} להיכנס?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "בבקשה תהנ{EMIT_HEY}{ADD_YUD}.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "או? אני מצטערת, אבל אין לך\n"
	.string "מספיק כסף.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "או? את{EMIT_HEY} עם הקבוצה שנכנסה\n"
	.string "קודם?\p"
	.string "את{EMIT_HEY} היחיד{ADD_HEY} שמאחר{ADD_TAF}.\n"
	.string "כדאי שתמהר{ADD_YUD}!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "אנחנו, צוות אקווה, קיימים לטובת\n"
	.string "כולם!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "אמרו לנו להתאסף כאן,\n"
	.string "אז עשינו זאת, אבל…\p"
	.string "הבוס שלנו, החוליה המקשרת, לא כאן.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "אם הייתי גונב את הדברים כאן,\n"
	.string "זה היה עושה אותי עשיר?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "מה שאני לומד כאן, אני יכול ליישם\n"
	.string "במעשים מרושעים…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "אם החבר'ה שלנו לא היו מפשלים\n"
	.string "ברסטבורו, לא היינו כאן!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "לא היה לי 05¥, אז לקח הרבה זמן\n"
	.string "לעבור את פקידת הקבלה.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "אני רוצה ללמוד על הים\n"
	.string "ולהשתמש בידע הזה בקרבות.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "אני מתרגש לגמרי כשאני\n"
	.string "רואה את הים!\p"
	.string "בשבילי, קפטן סטרן הוא\n"
	.string "המודל לחיקוי מספר אחד!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "הים עצום ללא סוף,\n"
	.string "ועמוק לאינסוף…\p"
	.string "בטוח יש מלא פוקימונים\n"
	.string "שאנחנו לא יודעים עליהם.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "אני רוצה פוקימון ים.\p"
	.string "נראה לי שירגיש קריר ונעים\n"
	.string "לחבק אותו.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "איייי!\n"
	.string "מה את{EMIT_HEY} עושה כאן?\p"
	.string "אני? אני חבר צוות אקווה\n"
	.string "שהבסת קודם, זוכר{ADD_TAF}?\l"
	.string "אז במנהרת רסטרף?\p"
	.string "הנה, קח{ADD_YUD} את זה!\n"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לסלוח לי!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "המ”מ הזה, הוא מתאים לך יותר\n"
	.string "מאשר לי.\p"
	.string "מקווה שלא אראה אותך שוב!\n"
	.string "וואהאהאהא!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "אוו, נו באמת!\n"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לקחת את זה ולתת לי ללכת!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "נוזל כחול מסתחרר בתוך\n"
	.string "כלי זכוכית.\p"
	.string "”זהו ניסוי ליצור מערבולת\n"
	.string "באופן מלאכותי בעזרת רוח.“$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "כדור אדום קופץ למעלה ולמטה\n"
	.string "בתוך כלי זכוכית.\p"
	.string "”זהו ניסוי שמדמה מפל\n"
	.string "בעזרת הציפה של הכדור.“$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "זו דגימה של אדמה מקרקעית\n"
	.string "האוקיינוס.\p"
	.string "”במשך שנים רבות, שרידי\n"
	.string "יצורים חיים שוקעים לקרקעית\l"
	.string "הים, ויוצרם שכבות משקע.\p"
	.string "”על ידי ניתוח שכבות אלו,\n"
	.string "העבר הקדום נחשף.“$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "זו דגימה של חול החוף.\p"
	.string "”אבנים מההרים נשטפות\n"
	.string "מטה בנהרות, שם הן\l"
	.string "נשחקות ומתפוררות.\p"
	.string "”הן הופכות לגרגרים ומסיימות\n"
	.string "כחול בחופים.“$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "עובדתונת אוקיינוס 1\n"
	.string "למה מי הים כחולים?\p"
	.string "”האור מורכב מהרבה צבעים.\p"
	.string "”כאשר האור עובר במים,\n"
	.string "רוב סוגי האור מאבדים צבע.\p"
	.string "”עף על פי כן, הצבע הכחול שומר על\n"
	.string "צבעו, וגורם לים להיראות כחול.“$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "”עובדותונת אוקיינוס 2\n"
	.string "למה הים מלוח?\p"
	.string "”מי הים מכילים מלח מומס\n"
	.string "בצורת יוני נתרן וכלור.\p"
	.string "”היונים האלה יוצאים מסלעים\n"
	.string "ונסחפים לים מהגשם.\p"
	.string "”ריכוז המלח המומס הוא מה\n"
	.string "שהופך את הים למלוח.“$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "”עובדתונת אוקיינוס 3\n"
	.string "מה גדול יותר? הים או היבשה?\p"
	.string "”הים מכסה בערך 07%\n"
	.string "מהכוכב לכת , והשאר יבשה.\p"
	.string "”לכן הים גדול יותר\n"
	.string "פי שניים מהיבשה.“$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "זהו מאובן עם רכסים גליים.\p"
	.string "”האדמה בקרקעית הים נשחקת\n"
	.string "על ידי הגאות והשפל.\p"
	.string "”מי הים הזורמים יוצרים\n"
	.string "רכסים ועמקים קטנים באדמה.\p"
	.string "”אם אדמה זו מתאבנת,\n"
	.string "זה נקרא סימן אדוות.“$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "מכונה מוזרה מסתובבת\n"
	.string "מתחת לכיפת זכוכית.\p"
	.string "אולי זה בשביל למדוד\n"
	.string "עומק של משהו…$"

