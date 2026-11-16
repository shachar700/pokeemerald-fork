MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_RALTS
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "דוד: זה בגלל פוקימונים שלילד\n"
	.string "הזה יש יותר חיוניות, אני מניח…\l"
	.string "אבל הוא נהיה קצת יותר מדי נמרץ…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "וולי: אוו, דוד, בבקשה?\p"
	.string "אני רוצה לאתגר את המכון הזה ולראות\n"
	.string "כמה השתפרתי.\p"
	.string "בבקשה? מותר לי, בבקשה?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "דוד: עכשיו חכה, וולי.\p"
	.string "מאז שהתחלת לחיות עם פוקימונים,\n"
	.string "אתה באמת נהיית חזק יותר.\p"
	.string "אבל אתה לא חושב שאתה מגזים\n"
	.string "לאתגר מכון פתאום?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "וולי: אני לא מגזים.\p"
	.string "אם אחבר כוחות עם {STR_VAR_1},\n"
	.string "אנחנו יכולים לנצח כל אחד!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "וולי: או! היי, {PLAYER}!\p"
	.string "נהייתי הרבה יותר חזק מאז\n"
	.string "שנפגשנו.\p"
	.string "{PLAYER}, אני רוצה שאת{EMIT_HEY} וגם הדוד שלי\n"
	.string "תבינו את זה.\p"
	.string "{PLAYER}, בבקשה, האם תילח{SWAP_MEM}{ADD_YUD}\n"
	.string "איתי?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "וולי: או… אם את{EMIT_HEY} לא נלח{SWAP_MEM}{ADD_TAF} מולי,\n"
	.string "{PLAYER}, הדוד שלי לא יידע שנהייתי\l"
	.string "ממש חזק.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "דוד: {PLAYER}{KUN}, נכון?\n"
	.string "מטעם וולי, אני יכול לבקש ממך\l"
	.string "להילחם איתו רק הפעם?\p"
	.string "אני לא חושב שהוא יקשיב לשום\n"
	.string "היגיון במצב שבו הוא נמצא עכשיו.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "וולי: {PLAYER}, בבקשה!\n"
	.string "הילח{SWAP_MEM}{ADD_YUD} מולי, בבקשה.$"

MauvilleCity_Text_WallyHereICome:
	.string "וולי: {PLAYER}, תודה לך.\p"
	.string "אוקיי… הנה אני בא!$"

MauvilleCity_Text_WallyDefeat:
	.string "וולי: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "הפסדתי…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "וולי: דוד…\n"
	.string "אני אחזור לורדנטרף…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, תודה לך.\n"
	.string "להיות מאמן זה קשה, לא?\p"
	.string "זה לא מספיק רק שיהיו לך פוקימונים\n"
	.string "ושתגרום להם להילחם. זה לא מהות\l"
	.string "העניין בלהיות מאמן אמיתי.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "דוד: וולי, אין צורך שתהיה כל כך\n"
	.string "מדוכא.\p"
	.string "מה מונע ממך מלהיות\n"
	.string "חזק יותר ויותר?\p"
	.string "קדימה, בוא נלך הביתה.\n"
	.string "כולם מחכים לך.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "דוד: {PLAYER}{KUN}, זה פשוט הכה בי\n"
	.string "שאת{EMIT_HEY} בטח המאמ{SWAP_NUN}{ADD_TAF} ששמר{ADD_HEY}\l"
	.string "על וולי כשהוא תפס את הפוקימון\l"
	.string "שלו.\p"
	.string "למה שלא תבקר{ADD_YUD} אותנו בורדנטרף\n"
	.string "מתישהו?\l"
	.string "אני בטוח שוולי ייהנה מזה.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … ביפ!\p"
	.string "וולי: או, שלום, {PLAYER}!\p"
	.string "רק רציתי לומר לך\n"
	.string "שהדוד שלי קנה לי פוקינווט!\p"
	.string "עכשיו אני יכול ליצור איתך קשר\n"
	.string "בכל עת, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … קליק!$"

MauvilleCity_Text_RegisteredWally:
	.string "וולי נרשם\n"
	.string "בפוקינווט.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "סקוט: היהי…\n"
	.string "צפיתי במשחק הזה!\p"
	.string "את{EMIT_HEY} חבר{ADD_HEY} של הילד ההוא וולי,\n"
	.string "נכון?\p"
	.string "אבל לא התאפקת\n"
	.string "וניצחת אותו בצורה מרשימה.\p"
	.string "כן! זה מה שקרב פוקימונים אמיתי\n"
	.string "הוא!\p"
	.string "אני מעריץ מאמנים כאלה!\p"
	.string "… … … … … …\n"
	.string "אני אעודד אותך!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "ווטסון: או, {PLAYER}{KUN}!\n"
	.string "את{EMIT_HEY} נרא{EMIT_HEY}{ADD_YUD}{ADD_TAF} מלא{ADD_TAF} חיוניות!\l"
	.string "זה דבר טוב, וואהאהאהאהא!\p"
	.string "בסדר! החלטתי!\n"
	.string "אני צריך טובה, {PLAYER}{KUN}!\p"
	.string "בעיר מוויל יש אזור תת קרקעי\n"
	.string "שנקרא מוויל החדשה.\p"
	.string "{PLAYER}{KUN}, הייתי רוצה שתל{SWAP_CHAF}{ADD_YUD} לשם ותכב{EMIT_HEY}{ADD_YUD}\n"
	.string "את הגנרטור.\p"
	.string "הגנרטור פועל קצת\n"
	.string "בצורה משובשת. זה נהיה לא בטוח.\p"
	.string "הנה, זה המפתח כדי להיכנס\n"
	.string "למוויל החדשה.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "ווטסון: אל תדאג{ADD_YUD} לגבי זה.\n"
	.string "זה לא יהיה אתגר בשבילך.\p"
	.string "הכניסה למוויל החדשה היא רק\n"
	.string "שיט קצר מדרך 011.\p"
	.string "זהו זה, אם כן, יש לך את האמון שלי!\n"
	.string "וואהאהאהאהא!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "ווטסון: וואהאהאהאהא!\p"
	.string "ידעתי את זה, {PLAYER}{KUN}! ידעתי שבחרתי\n"
	.string "נכון כששאלתי אותך!\p"
	.string "זו התודה שלי--מ”מ שמכיל\n"
	.string "מכת ברק!\p"
	.string "קדימה, הרווחת את זה!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "ווטסון: וואהאהאהאהא!\p"
	.string "זה משמח אותי עד אין קץ לראות\n"
	.string "את הצעירים קמים ולוקחים אחריות!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "את{EMIT_HEY} יודע{ADD_TAF}, זה מגניב לערוך קרבות\n"
	.string "פוקימונים וכדומה…\p"
	.string "אבל אם הפוקימון שלך נפצע,\n"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לטפל בו כדי שיחלים.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "הדרכים של העיר הזו נמתחות צפונה\n"
	.string "ודרומה, ומזרחה ומערבה.\p"
	.string "בגלל זה, מגיעים אלינו כל מיני\n"
	.string "אנשים שעוברים דרך.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "האם היית כבר בחנות האופניים של ריידל?\p"
	.string "ריידל, הבעלים, הוא איש נדיב\n"
	.string "מאוד.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "גם אם את{EMIT_HEY} רוכב{ADD_TAF} על אופניים,\n"
	.string "פוקימונים פראיים יכולים לקפוץ עליך.$"

MauvilleCity_Text_CitySign:
	.string "העיר מוויל\n"
	.string "”העיר הבהירה והמבריקה של הכיף!“$"

MauvilleCity_Text_GymSign:
	.string "מכון הפוקימונים של העיר מוויל\n"
	.string "מנהיג: ווטסון\l"
	.string "”האיש המשמח ומחשמל!“$"

MauvilleCity_Text_BikeShopSign:
	.string "”רכבו בחצץ וטלטלו את\n"
	.string "נשמתכם!“\l"
	.string "האופניים של ריידל$"

MauvilleCity_Text_GameCornerSign:
	.string "”מקום המשחק לכולם!“\n"
	.string "פינת המשחקים של מוויל$"

MauvilleCity_Text_ExplainTV:
	.string "היי, את{EMIT_HEY} צופה בטלוויזיה בכלל?\p"
	.string "הם הוסיפו לאחרונה חבורה של תוכניות\n"
	.string "חדשות ומגניבות.\p"
	.string "טלוויזיה זה כל כך מגניב. ראיתי את החברים\n"
	.string "שלי בטלוויזיה פשוט פתאום.\p"
	.string "ולפעמים, הם אפילו שמים אותך בטלוויזיה\n"
	.string "בלי לומר לך.\p"
	.string "הלוואי שאהיה בטלוויזיה מתישהו.\p"
	.string "זו הסיבה שבגללה אני חושב שאת{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לבדוק\n"
	.string "טלוויזיות בכל הזדמנות.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "היי, האם צפית בטלוויזיות?$"
