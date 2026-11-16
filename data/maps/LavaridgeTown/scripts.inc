LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	closedoor 12, 15
	waitdooranim
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "מאי: {PLAYER}{KUN}! הרבה זמן לא ראיתי אותך!\p"
	.string "או? בזמן שביקרתי במעיינות החמים,\n"
	.string "קיבלת את תג המכון של לברידג'.\p"
	.string "אתה בטח אספת פוקימונים טובים…\n"
	.string "לא, אני מאמינה שגידלת כמה.\p"
	.string "אני מניחה שזה בסדר שתקבל\n"
	.string "את זה.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "מאי: עם המשקפי מגן האלה,\n"
	.string "לא תהיה לך בעיה לעבור את המדבר\l"
	.string "ליד דרך 111.\p"
	.string "אבל, ואו, {PLAYER}{KUN}…\n"
	.string "אתגר מכונים…\p"
	.string "אתה משתדל חזק כי אתה לא\n"
	.string "רוצה להפסיד לי, אני בטוחה!\p"
	.string "{PLAYER}{KUN}, אני חושבת שאני צריכה לאתגר\n"
	.string "את אבא שלך במכון פטלבורג.\p"
	.string "נתראה שוב!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "ברנדן: {PLAYER}, היי, עבר זמן מה.\n"
	.string "מה שלומך?\p"
	.string "הממ…\n"
	.string "זהו אוסף תגים לא רע.\p"
	.string "בסדר גמור, אם כך.\n"
	.string "את יכולה לקבל את זה.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "ברנדן: שמרי את אלה אצלך אם את\n"
	.string "מתכננת להיכנס למדבר ההוא ליד\l"
	.string "דרך 111.\p"
	.string "אמור להיות שם פוקימונים\n"
	.string "שהם תושבי המדבר בלבד.\l"
	.string "אולי תחפשי כמה כאלה.\p"
	.string "באשר אליי…\n"
	.string "אני שוקל לאתגר את נורמן,\l"
	.string "מנהיג מכון פטלבורג.\p"
	.string "בניגוד אליך, {PLAYER}, אבא שלך נראה\n"
	.string "באמת קשוח.\p"
	.string "נתראה בהמשך!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "יש לי כאן ביצה.\p"
	.string "קיוויתי לבקוע אותה על ידי כיסויה\n"
	.string "בחול חם ליד המעיינות החמים.\l"
	.string "אבל זה לא נראה מספיק…\p"
	.string "שמעתי שיהיה הכי טוב אם היא\n"
	.string "תשמר יחד עם פוקימונים\l"
	.string "ותישא איתך.\p"
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}, נכון?\n"
	.string "והפוקימונים שלך מקרינים חיוניות.\p"
	.string "אז, מה את{EMIT_HEY} אומר{ADD_TAF}?\n"
	.string "האם תיקח{ADD_YUD} את הביצה הזו לבקיעה?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "טוב! אני מקווה שתל{SWAP_CHAF}{ADD_YUD} הרבה עם\n"
	.string "הביצה הזו!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} קיבל{ADD_HEY} את הביצה.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "או? יש לך יותר מדי פוקימונים.\n"
	.string "אין מקום לביצה הזו…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "כפי שתרצ{EMIT_HEY}{ADD_YUD}, אם כן…\p"
	.string "אם תשנ{EMIT_HEY}{ADD_YUD} את דעתך לגבי\n"
	.string "בקיעת הביצה הזו, אני אהיה כאן.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "מדי פעם, תימצא ביצה\n"
	.string "במעון הפוקימונים.\p"
	.string "או לפחות כך הולכת השמועה.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "אנחנו שואבים כמה מים חמים שאנחנו צריכים,\n"
	.string "ובכל זאת המעיינות החמים אף פעם לא מתייבשים.\p"
	.string "זה לא קסום?\p"
	.string "המעיינות החמים האלה מופיעים ליד\n"
	.string "הרי געש פעילים. עורקי מים מתחת לאדמה\l"
	.string "מחוממים על ידי מגמה כדי לפרוץ\l"
	.string "בתור מעיינות חמים.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "להיות קבור בחול החם הזה זה…\n"
	.string "אנחה…\p"
	.string "כל כך חם ושמימי…\p"
	.string "אה? גיאאא! אאוץ'!\p"
	.string "פוקימון נשך לי את הישבן!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "או, את{EMIT_HEY} אוהב{ADD_TAF} מעיינות חמים, הא?\p"
	.string "זה מפתיע עבור מישהו כה צעיר\n"
	.string "כמוך.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "אני מתרחץ במעיינות החמים כל יום.\p"
	.string "אני רוצה להפוך למנהיגת מכון יפה\n"
	.string "וחזקה כמו פלאנרי.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "אם אנשים היו מכניסים פוקימונים למעיינות\n"
	.string "חמים, זה יכול להיות מוזר ברצינות.\p"
	.string "וואי, זו יכולה להיות אמבטיה חשמלית, או\n"
	.string "אמבטיית בועות, או אפילו אמבטיית לבה…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "הם טוענים שהמעיינות החמים האלה\n"
	.string "טובים להרגעת מתח עצבי,\l"
	.string "להקלה על שרירים כואבים, לפתרון\l"
	.string "בעיות רומנטיות, ולמשיכת\l"
	.string "כסף…$"

LavaridgeTown_Text_TownSign:
	.string "העיר לברידג'\p"
	.string "”מרכז פוקימונים מעיינות חמים\n"
	.string "מקום מצוין להירגע!“$"

LavaridgeTown_Text_GymSign:
	.string "מכון הפוקימונים של עיר לברידג'\n"
	.string "מנהיגה: פלאנרי\l"
	.string "”אחת עם תשוקה לוהטת שבוערת!“$"

LavaridgeTown_Text_HerbShopSign:
	.string "חנות עשבי פוקימונים\n"
	.string "”טעם מר--תרופה טובה יותר!“$"

