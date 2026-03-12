SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "סליחה?\n"
	.string "את{EMIT_HEY} מחפש{ADD_TAF} ספינה?\p"
	.string "אני מצטערת, שירות המעבורת אינו\n"
	.string "זמין כעת…$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "שלום, את{EMIT_HEY} כאן בשביל המעבורת?\n"
	.string "אפשר לראות את הכרטיס שלך?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "ל{PLAYER} אין כרטיס…\p"
	.string "אני מצטערת מאוד.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} כרטיס כדי לעלות\n"
	.string "על המעבורת.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} הציג{ADD_HEY} את הכרטיס.\p"
	.string "מושלם! זה כל מה שאת{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY}!\p"
	.string "ולאן תרצ{EMIT_HEY}{ADD_YUD} להגיע?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "בבקשה תפליג{ADD_YUD} איתנו בפעם אחרת!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "אז לעיר ליליקוב, אם כך!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "אז לחזית הקרב, אם כך!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "נא לעלות על המעבורת ולהמתין\n"
	.string "לציאה.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "אז, לאן תרצ{EMIT_HEY}{ADD_YUD} להגיע?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "מסע לקרקעית הים…\n"
	.string "אני תוהה איך זה היה מרגיש?\p"
	.string "הייתי שמח לצלול עמוק מתחת למים\n"
	.string "ככה יום אחד.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "כדי שספינה תפליג בבטחה, אנחנו צריכים\n"
	.string "לדעת את מצב מזג האוויר!\p"
	.string "אגב מזג אוויר, שמעתי משהו מבחור\n"
	.string "ממכון למזג האוויר.\p"
	.string "הוא סיפר שמזג אוויר חריג דווח\n"
	.string "בכל רחבי האזור!\p"
	.string "כדאי לך לבקר במכון מזג האוויר\n"
	.string "ולשאול מסביב!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "רציתי להצטרף לקפטן סטרן בחקר\n"
	.string "קרקעית האוקיינוס.\p"
	.string "אבל הצוללת קטנה מדי בשבילי.\p"
	.string "אם הייתי נדחס פנימה, לא היה נשאר\n"
	.string "מקום בכלל לקפטן…$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "קפטן סטרן: הבריונים האלה…\p"
	.string "אלו אותם טיפוסים שניסו לגנוב\n"
	.string "את סחורת דבון במוזיאון.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "ארצ'י: או?\n"
	.string "לא את{EMIT_HEY} שוב…\p"
	.string "את{EMIT_HEY} עקש{SWAP_NUN}{ADD_YUD}{ADD_TAF} לעקוב אחרינו עד כאן,\n"
	.string "זה אני מוכן להעריך לך.\p"
	.string "אבל עכשיו…\n"
	.string "אף אחד לא יוכל לעצור אותנו! אף אחד!\p"
	.string "או שתעק{EMIT_VAV}ב{ADD_YUD} אחרינו חזרה למחבוא\n"
	.string "שלנו בעיר ליליקוב?\p"
	.string "פואהאהאהאהא…$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "קפטן סטרן: למה…\p"
	.string "למה שצוות אקווה יגנוב את הצוללת\n"
	.string "חוקרת 1 שלי?\p"
	.string "הם בטח לא אחרי הפוקימונים\n"
	.string "הרדומים בתחתית הים…\p"
	.string "אבל גם אם הייתי מנסה לרדוף אחריהם,\n"
	.string "אין לי סיכוי מולם…$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "קפטן סטרן: או, {PLAYER}{KUN}…\p"
	.string "אוקיי… אז צוות אקווה עזב לפני\n"
	.string "שהצלחת לעצור אותם…\p"
	.string "או, לא, אל תאשי{SWAP_MEM}{ADD_YUD} את עצמך.\n"
	.string "את{EMIT_HEY} לא אחראי{ADD_TAF} לזה.\p"
	.string "לנסות לתפוס צוללת…\n"
	.string "זה בלתי אפשרי לרוב האנשים.\p"
	.string "צריך פוקימון שיודע איך לצלול…\p"
	.string "אולי אם תל{SWAP_CHAF}{ADD_YUD} לעיר מוסדיפ…\p"
	.string "הרבה צוללנים גרים שם, אז מישהו\n"
	.string "עלול ללמד אותך…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "קפטן סטרן: לנסות לתפוס\n"
	.string "צוללת… זה בלתי אפשרי.\p"
	.string "את{EMIT_HEY} תצטר{SWAP_CHAF}{ADD_YUD} פוקימון שיודע\n"
	.string "לצלול…\p"
	.string "אולי אם תל{SWAP_CHAF}{ADD_YUD} לעיר מוסדיפ…\p"
	.string "הרבה צוללנים חיים שם, אז\n"
	.string "מישהו אולי ילמד אותך…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "קפטן סטרן: או, כן.\n"
	.string "מר ברייני הגיע למספנה שלנו.\p"
	.string "זה לא ייקח עוד הרבה זמן עד שנסיים\n"
	.string "לבנות את המעבורת!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "קפטן סטרן: {PLAYER}{KUN}!\p"
	.string "סוף סוף סיימנו לבנות את המעבורת\n"
	.string "ס.ס גאות!\p"
	.string "לא היינו מצליחים בלי העזרה של\n"
	.string "החבר שלך, מר ברייני.\p"
	.string "בבקשה תצא{ADD_YUD} להפלגה קצרה עליה!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "קפטן סטרן: או?\n"
	.string "{PLAYER}{KUN}, הפריט הזה שיש לך…\p"
	.string "זה הסורק! זה בטוח יעזור\n"
	.string "לנו בחקירות שלנו.\p"
	.string "{PLAYER}{KUN}, האם תרצ{EMIT_HEY}{ADD_YUD} להחליף את\n"
	.string "הסורק שלך עבור משהו?\p"
	.string "כמו, למשל, שן מצולות\n"
	.string "או קשקש מצולות שיש לי?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "קפטן סטרן: את{EMIT_HEY} בטוח{ADD_HEY}?\n"
	.string "זה חסר תועלת בשבילך, {PLAYER}{KUN}…\p"
	.string "ובכן, בסדר, אז. אם תרצ{EMIT_HEY}{ADD_YUD} להחליף את\n"
	.string "הסורק שלך, תודיע{ADD_YUD} לי.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "קפטן סטרן: אז את{EMIT_HEY} תחלי{SWAP_PEY}{ADD_YUD} אותו עבור\n"
	.string "השן מצולות שלי?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "קפטן סטרן: אז את{EMIT_HEY} תחלי{SWAP_PEY}{ADD_YUD} אותו עבור\n"
	.string "הקשקש מצולות שלי?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "קפטן סטרן: איזה אחד אתה רוצה?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER} מסר{ADD_HEY} את הסורק\n"
	.string "לקפטן סטרן.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "קפטן סטרן: תודה, {PLAYER}{KUN}!\n"
	.string "זה יעזור המון למחקר שלנו!$"
