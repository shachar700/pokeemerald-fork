FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applywaitmovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	bufferspeciesname STR_VAR_1, SPECIES_WINGULL
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	bufferspeciesname STR_VAR_1, SPECIES_WINGULL
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	bufferspeciesname STR_VAR_1, SPECIES_WINGULL
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_WINGULL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "כשאנשים נמצאים יחד עם פוקימון,\n"
	.string "הם יוצרים יותר ויותר חברויות.\p"
	.string "וזה מקרב את העולם כולו\n"
	.string "יחד. אני חושבת שזה נהדר!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "הנה!\n"
	.string "קדימה, פוקימון ציפור!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "היהי, ביקשתי מ{STR_VAR_1} לעשות סידור\n"
	.string "בשבילי.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "יופי!\n"
	.string "ברוך השב, {STR_VAR_1}!\p"
	.string "הא? מה זה?\n"
	.string "מה הוא מחזיק?\p"
	.string "עשב נפשי?\n"
	.string "הוא בטח מצא אותו איפשהו.\p"
	.string "אבל אני לא מאמן, אז את{EMIT_HEY}\n"
	.string "יכול{ADD_HEY} לקחת אותו.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "בזכות ה{STR_VAR_1} שלי, יש לי חברים\n"
	.string "שגרים רחוק מכאן.$"

FortreeCity_House4_Text_Wingull:
	.string "{STR_VAR_1}: פיהיוה!$"

