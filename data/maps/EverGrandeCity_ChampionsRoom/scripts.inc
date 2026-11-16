EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkUp4
	delay 40
	applywaitmovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applywaitmovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applywaitmovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	delay 20
	applywaitmovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "וולאס: שלום, {PLAYER}{KUN}.\p"
	.string "האירוע הזה בעיר סוטופוליס…\n"
	.string "זו הייתה עבודה מעולה, כששמת קץ\l"
	.string "למשבר הזה לבדך.\p"
	.string "אופס!\p"
	.string "זה לא יהיה הוגן לומר שאת{EMIT_HEY}\n"
	.string "לבדך סיימת את המשבר.\p"
	.string "התגברת על המצב הקשה הזה\n"
	.string "על ידי עבודה כאחד עם הפוקימונים שלך.\p"
	.string "אנחנו המאמנים מגדלים פוקימונים על ידי מתן\n"
	.string "פריטים ועל ידי לימודם טכניקות\l"
	.string "חדשות לקרב.\p"
	.string "אבל אנחנו בעצמנו גם לומדים הרבה\n"
	.string "דברים מפוקימונים.\p"
	.string "וכאן ההישגים שלך מועמדים למבחן\n"
	.string "מול מה שאחרים כמוך השיגו.\p"
	.string "עכשיו!\p"
	.string "מי יכול לרקוד בצורה האלגנטית ביותר עם\n"
	.string "הפוקימונים שלו בהואן?\p"
	.string "הרא{EMIT_HEY}{ADD_YUD} לי כאן ועכשיו!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "אני, האלוף, נופל בתבוסה…\p"
	.string "זו הייתה עבודה נפלאה.\n"
	.string "היית אלגנטי{ADD_TAF}, בצורה מרגיזה.\l"
	.string "ובכל זאת זה היה מפואר לחלוטין!\p"
	.string "כל הכבוד לך, {PLAYER}{KUN}!\p"
	.string "את{EMIT_HEY}באמת מאמ{SWAP_NUN}{ADD_TAF} פוקימונים\n"
	.string "אציל{ADD_HEY}!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "וולאס: הפוקימונים ששלחת\n"
	.string "לקרב…\p"
	.string "לפעמים הם רקדו כמו רוח\n"
	.string "אביבית, ולפעמים הם הכו\l"
	.string "כמו ברק.\p"
	.string "באלגנטיות קלילה, אך בטוחה,\n"
	.string "הובלת את הפוקימונים שלך.\p"
	.string "אפילו אני הרגשתי מסונוור מההופעה\n"
	.string "המופתית שלך!\p"
	.string "את{EMIT_HEY} עומד{ADD_TAF} עכשיו בפסגה המפוארת\n"
	.string "של ליגת הפוקימונים.\p"
	.string "אני מכריז עליך בתור האלו{SWAP_PEY}{ADD_HEY}\n"
	.string "החדש{ADD_HEY} של מחוז הואן…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "מאי: {PLAYER}{KUN}!\p"
	.string "הנה עצה לפני שאתה מאתגר\n"
	.string "את האלוף…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "מאי: הא?\n"
	.string "מה, מה, מה?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "זה יכול להיות ש…\l"
	.string "זה כבר נגמר?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "ברנדן: {PLAYER}!\p"
	.string "מה דעתך על קצת עצה לפני\n"
	.string "שאת מאתגרת את האלוף?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "ברנדן: {PLAYER}…\p"
	.string "את מנסה לומר לי…\n"
	.string "שניצחת את האלוף?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "פרופ. בירץ': רואה?\n"
	.string "מה אמרתי לך, {RIVAL}?\p"
	.string " לא אמרתי לך שאת{ADD_HEY} לא חייב{EMIT_TAF}\n"
	.string "לדאוג לגבי {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, סוף סוף עשית את זה.\p"
	.string "כששמעתי שהבסת את אבא שלך\n"
	.string "במכון פטלבורג, חשבתי שאולי\l"
	.string "יש לך סיכוי…\p"
	.string "אבל לחשוב שבאמת הפכת\n"
	.string "לאלו{SWAP_PEY}{ADD_HEY}!\p"
	.string "אה, כן!\p"
	.string "מה עלה בגורל הפוקידע שלך?\n"
	.string "הנה, ת{SWAP_NUN}{ADD_YUD} לי לראות.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "פרופ. בירץ': בכל מקרה,\n"
	.string "ברכות!\p"
	.string "עכשיו, ל{SWAP_CHAF}{ADD_YUD} בגאווה לחדר האחרון!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "וולאס: {PLAYER}{KUN}…\p"
	.string "לא, ת{SWAP_NUN}{ADD_YUD} לי לנסח את זה מחדש כראוי.\p"
	.string "האלו{SWAP_PEY}{ADD_HEY} החדש{ADD_HEY}!\p"
	.string "בוא{ADD_HEY} איתי.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "וולאס: אני מצטער, אבל…\p"
	.string "מכאן ואלך, רק אותם המאמנים\n"
	.string "שהפכו לאלופים רשאים להיכנס.\p"
	.string "את{EMIT_HEY}חייב{EMIT_TAF} לחכות בחוץ עם\n"
	.string "פרופ' בירץ'.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "מאי: גניחה…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "אני רק צוחקת! זה בסדר!\n"
	.string "זה החוק!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "בכנות, ברכות!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "ברנדן: מההההה?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "זה לא יכול להימנע אם זה החוק.\p"
	.string "{PLAYER}, יפה מאוד!\n"
	.string "ברכות!$"

