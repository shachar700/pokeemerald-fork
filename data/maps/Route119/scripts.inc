Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
	delay 65
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	addobject LOCALID_ROUTE119_RIVAL
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
	releaseall
	end

Route119_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route119_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_BattleMay::
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleMayTreecko
	case 1, Route119_EventScript_BattleMayTorchic
	case 2, Route119_EventScript_BattleMayMudkip
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_BattleBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTorchic
	case 2, Route119_EventScript_BattleBrendanMudkip
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_ROUTE119_SCOTT
	applywaitmovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottEnter
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_ROUTE119_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applywaitmovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit1
	return

Route119_EventScript_ScottExit2::
	applywaitmovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit2
	return

Route119_EventScript_RivalEnter1::
	applywaitmovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	return

Route119_EventScript_RivalEnter2::
	applywaitmovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	return

Route119_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 25, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 26, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "מאי: {PLAYER}{KUN}!\n"
	.string "איפה היית? חיפשתי אותך!\p"
	.string "כמה חזק יותר נהיית?\n"
	.string "תן לי לבדוק אותך!\p"
	.string "מוכן עם הפוקימונים שלך?\n"
	.string "כמובן שאתה מוכן! קדימה!$"

Route119_Text_MayDefeat:
	.string "אצ'ה!\n"
	.string "{PLAYER}{KUN}, אתה חזק!\p"
	.string "דאגתי שאולי אתה\n"
	.string "מתקשה באימונים שלך.$"

Route119_Text_MayPresentForYou:
	.string "מאי: אבל לא היה לי שום דבר\n"
	.string "לדאוג לגביו! תמשיך ככה!\p"
	.string "והנה! יש לי מתנה בשבילך.$"

Route119_Text_MayExplainFly:
	.string "מאי: תשתמש בתעופה, והפוקימון שלך\n"
	.string "ישא אותך באופן מיידי לכל עיר שבה\l"
	.string "כבר ביקרת.\p"
	.string "אבל, כדי להשתמש בתעופה, אתה צריך לקבל\n"
	.string "את תג המכון של פורטרי.\l"
	.string "זה חשוב, אז אל תשכח.\p"
	.string "כדאי לך לטוס הביתה ולבקר\n"
	.string "בליטלרוט לשם שינוי.\p"
	.string "אני בטוחה שאמא שלך דואגת לך,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "טוב, ניפגש שוב איפשהו!$"

Route119_Text_BrendanIntro:
	.string "ברנדן: {PLAYER}! אז כאן\n"
	.string "חיפשת פוקימונים?\p"
	.string "תני לי לראות כמה טובה נהיית.\n"
	.string "אני אבחן אותך!\p"
	.string "עכשיו!\n"
	.string "זה קרב, אז הילחמי!$"

Route119_Text_BrendanDefeat:
	.string "הממ…\n"
	.string "נהיית די טובה.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "ברנדן: הייתי אומר שאת מספיק טובה\n"
	.string "כדי לחפש פוקימונים בכל מקום.\p"
	.string "הנה, אני אתן לך את זה.\n"
	.string "נסי את זה!$"

Route119_Text_BrendanExplainFly:
	.string "ברנדן: השתמש בתעופה, והפוקימון\n"
	.string "שלך יישא אותך באופן מיידי לכל עיר\l"
	.string "שכבר ביקרת.\p"
	.string "אבל את{EMIT_HEY} צריכה את תג המכון של פורטרי\n"
	.string "כדי לעשות את זה.\p"
	.string "בכל מקרה, אני צריך להמשיך הלאה.$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "סקוט: האהאהא!\n"
	.string "כל הכבוד, {PLAYER}{KUN}!\p"
	.string "בדיוק חלפתי על פני מאמן שרכב\n"
	.string "על אופניים.\p"
	.string "בדיוק ניצחת את המאמן ההוא, נכון?\n"
	.string "זה היה די ברור שעשית את זה.\p"
	.string "הילד{EMIT_HEY} נראה ממש נסער{EMIT_TAF} עם\n"
	.string "פנים אדומות מכעס.\p"
	.string "אני באמת נתקל בך לעתים קרובות.\n"
	.string "את{EMIT_HEY} בדרך למכון פורטרי עכשיו?\p"
	.string "אני מצפה שתצליח{ADD_YUD} במכון.\n"
	.string "טוב, נתראה!$"


Route119_Text_ScottYouWonAtFortreeGym:
	.string "… … … … … …\n"
	.string "… … … … … ביפ!\p"
	.string "סקוט: היי, {PLAYER}{KUN}, זה אני!\p"
	.string "בדיוק כפי שחשבתי, ניצחת\n"
	.string "במכון פורטרי.\p"
	.string "הכוח שלך…\n"
	.string "אולי את{EMIT_HEY} באמת המאמ{SWAP_NUN}{ADD_TAF}\l"
	.string "שחיפשתי.\p"
	.string "זכ{EMIT_VAV}ר{ADD_YUD}, יש לך מעריץ.\n"
	.string "אני אעודד מהצד.\l"
	.string "תמשי{SWAP_CHAF}{ADD_YUD} בעבודה הנהדרת!\p"
	.string "… … … … … …\n"
	.string "… … … … … קליק!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "אנחנו עומדים כאן על המשמר.\p"
	.string "היי, את{EMIT_HEY}! תתרחק{ADD_YUD} ממכון מזג\n"
	.string "האוויר. זה לא בטוח.$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "תפקיד שמירה משעמם באופן מפתיע.\p"
	.string "היי, את{EMIT_HEY}! בבקשה אל תתקרב{ADD_YUD}\n"
	.string "למכון מזג האוויר.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "חשבתי שאת{EMIT_HEY} ע{SWAP_PEY}{ADD_HEY} על ידי תפיסת\n"
	.string "להקה שלמה של פוקימוני ציפור, ואז\l"
	.string "נאחז{ADD_TAF} בהם איכשהו.\p"
	.string "אבל מתברר שיש מהלך מ”נ\n"
	.string "שנקרא תעופה!\p"
	.string "הלוואי שהייתי יודע על זה מזמן…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "אחח…\n"
	.string "זה לא עובר…\p"
	.string "הדשא הגבוה לוכד צמיגי אופניים.\n"
	.string "אין מצב שאת{EMIT_HEY} יכול{ADD_HEY} לרכוב כאן.$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "האם הפוקימון שלך יכול להשתמש בכוח\n"
	.string "הסודי שלו על ערימת דשא גדולה וליצור\l"
	.string "בסיס סודי?$"

Route119_Text_RouteSignFortree:
	.string "דרך 911\n"
	.string "{RIGHT_ARROW} עיר פורטרי$"

Route119_Text_WeatherInstitute:
	.string "מכון מזג האוויר$"

Route119_Text_TrainerTipsDecoration:
	.string "טיפים למאמנים\p"
	.string "ניתן למקם עד שישה עשר פריטי\n"
	.string "קישוט ורהיטים בבסיס סודי.\p"
	.string "בחרו את הפריטים האהובים עלכם ותצרו\n"
	.string "בסיס סודי משלכם בדיוק כמו\l"
	.string "שאתם רוצים.$"
