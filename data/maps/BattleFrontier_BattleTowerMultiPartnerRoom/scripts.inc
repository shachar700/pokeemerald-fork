BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "אנא מצא{ADD_YUD} שותף מתוך\n"
	.string "המאמנים שנמצאים כאן.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, לא מצאת שותף\n"
	.string "לצוות תג שלך.\p"
	.string "האם ברצונך להפסיק לחפש ולחזור\n"
	.string "לדלפק הקבלה?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "אז אנא מצא{ADD_YUD} שותף מתוך\n"
	.string "המאמנים שנמצאים כאן.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "תודה שבחרת שותף.\p"
	.string "אני אראה לך עכשיו את\n"
	.string "חדר הקרב הרב משתתפים.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}.\n"
	.string "את{EMIT_HEY} יכול{ADD_HEY} לקרוא לי {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "בהמלצת {STR_VAR_1} הבאתי\n"
	.string "אחד {STR_VAR_3} עם {STR_VAR_2} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "בבקשה, הרש{EMIT_HEY}{ADD_YUD} לי להצטרף אליך כצוות תג.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "תודה!\n"
	.string "אני אלך להירשם עכשיו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "באמת רציתי ליצור צוות תג\n"
	.string "איתך, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}.\n"
	.string "שמי {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "קיבלתי עצה מ{STR_VAR_1} ובחרתי\n"
	.string "אחד {STR_VAR_3} עם {STR_VAR_2} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "בבקשה, בוא{ADD_YUD} ניצור צוות תג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "תודה רבה!\n"
	.string "אני אסיים את ההרשמה במהרה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, אני קיוויתי שאוכל\n"
	.string "להשתתף איתך…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "אממ, קוראים לי {STR_VAR_3}, ואני\n"
	.string "חניך מספר {STR_VAR_2} של {STR_VAR_1}.\p"
	.string "הו-וו…\p"
	.string "סליחה!\n"
	.string "המתח הזה גורם לי לבכות…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} יעץ לי, אז יש לי\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "הו-וו…\n"
	.string "בבקשה, בבקשה הצטרף אלי!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "אה, באמת? את{EMIT_HEY} מסכי{SWAP_MEM}{ADD_HEY}?\n"
	.string "נהדר! מדהים! אההה!\p"
	.string "אה… סליחה…\n"
	.string "אני כל כך שמח, אני בוכה…\p"
	.string "אני אלך להירשם עכשיו.\n"
	.string "בבקשה אל תל{SWAP_CHAF}{ADD_YUD}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "אה, אאבל…\n"
	.string "בההה… וואאהה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "שלום! אני {STR_VAR_3}!\n"
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} המליץ על הצוות שלי.\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1},\n"
	.string "זה מה שיש לי! מגניב, נכון?\p"
	.string "אז קדימה!\n"
	.string "בוא{ADD_YUD} ניצור צוות תג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "יאיי! מצוין!\n"
	.string "אוקיי, אני אלך להירשם, בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "אוו, למה?\n"
	.string "רציתי להשתתף, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "אני {STR_VAR_3}, החניך מספר {STR_VAR_2}\n"
	.string "של המפורסם {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "פניתי אל {STR_VAR_3} לקבלת עצה.\n"
	.string "אחד {STR_VAR_1}-משתמש{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "ואחד {STR_VAR_2} עם {STR_VAR_1},\n"
	.string "זו הצוות תגיות שלי.\p"
	.string "בבקשה, האם תצטר{SWAP_PEY}{ADD_YUD} אלי\n"
	.string "כצוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "תודה!\n"
	.string "אני אלך להירשם מיד!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, קיוויתי שאוכל להצטרף\n"
	.string "אליך כצוות תג…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "אממ… אני באמת שמח שאת{EMIT_HEY}\n"
	.string "לקחת את הזמן לדבר איתי.\p"
	.string "שלום, אני {STR_VAR_3}.\n"
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} נתן לי עצה.\n"
	.string "אני אסיר תודה לה מאוד.\p"
	.string "יש לי צוות של אחד {STR_VAR_2}\n"
	.string "עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\n"
	.string "אני יודע שאני מבקש הרבה…\p"
	.string "אני לא חושב שתהי{EMIT_HEY}{ADD_YUD} מוכ{SWAP_NUN}{ADD_YUD},\n"
	.string "אבל האם אוכל להצטרף אליך כשותף?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "באמת? אני לא מאמין!\n"
	.string "אני לא מאמין שתאפשר{ADD_YUD} לי להצטרף!\l"
	.string "אני… לא אאכזב אותך!\p"
	.string "אממ… אם באמת בסדר, אני אלך להירשם\n"
	.string "עכשיו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "אה…\n"
	.string "אני לא חשבתי שאני מספיק טוב…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "שלום, אני {STR_VAR_3}.\n"
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} אמר שזו תהיה\n"
	.string "רעיון טוב ליצור צוות כזה:\l"
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "ואחד {STR_VAR_2} שיודע להשתמש\n"
	.string "ב{STR_VAR_1}.\p"
	.string "לא רע, נכון?\n"
	.string "רוצה שאתאחד איתך?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "אוקיי, אני שמח להצטרף!\n"
	.string "אני מקווה שלא תבזבז את זה בשבילי!\l"
	.string "אני אלך עכשיו להירשם.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "מה? למה דחית אותי?\n"
	.string "את{EMIT_HEY} לא מבי{SWAP_NUN}{ADD_HEY} את האופי!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "אני {STR_VAR_3} ואני טריאתלט.\n"
	.string "אני עסוק כל יום עם ריצה,\l"
	.string "אימון, וגם רשימות.\p"
	.string "אני גם חניך מספר {STR_VAR_2} של {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "זה מה ש{STR_VAR_3} המליץ.\n"
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "ואחד {STR_VAR_1}-משתמש\n"
	.string "{STR_VAR_2}.\p"
	.string "השקעתי מאמצים רבים בגידולם\n"
	.string "גם כשאני עסוק.\p"
	.string "בוא{ADD_YUD} ניצור צוות תג\n"
	.string "וננסה את זה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "תודה, זה הרוח הנכונה!\n"
	.string "המת{ADD_YUD}{SWAP_NUN}{ADD_YUD} רגע בזמן שאני הולך להירשם, בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "הקדשתי זמן מהלו”ז עמוס שלי\n"
	.string "להיות כאן! תן לי להירגע!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "שלום!\n"
	.string "מה שלומך?\p"
	.string "אני {STR_VAR_3}, חניך מספר {STR_VAR_2} של {STR_VAR_1}.\n"
	.string "נעים להכיר!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "הקשב, הקשב! חייבת לשמוע על\n"
	.string "הפוקימונים ש{STR_VAR_3} המליץ עליהם.\l"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "ואחד {STR_VAR_2} עם {STR_VAR_1}.\n"
	.string "כמובן שאילפתי אותם מצוין!\p"
	.string "אז, רוצה להצטרף?\n"
	.string "אני בטוח שזה יהיה שילוב נהדר!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "יאי, זה יהיה כיף!\n"
	.string "אני אלך להירשם!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "אה, שאת{EMIT_HEY} מרושע{ADD_TAF}!\n"
	.string "ממליצים עלי, שאת{EMIT_HEY} יודע{ADD_TAF}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "רשום לי להציג את עצמי.\n"
	.string "אני {STR_VAR_3}.\p"
	.string "אני משרת כחניך מספר {STR_VAR_2}\n"
	.string "של {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "חיפשתי עצה חכמה מ{STR_VAR_3} וגידלתי את הצוות\l"
	.string "שלי של אחד {STR_VAR_2} עם {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "ואחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "אנא הסכים להיות שותפי כצוות תג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "אה… אני מתרגש!\n"
	.string "אני מבטיח לתת את הטוב ביותר!\p"
	.string "כמובן שאלך להירשם!\n"
	.string "בבקשה המתן!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "קיוויתי שאוכל להצטרף אליך,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "איי! דיברת אלי!\n"
	.string "אני… מתמלא שמחה!\p"
	.string "אני {STR_VAR_3}! אני חניך מספר {STR_VAR_2}\n"
	.string "של {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "בהמלצת {STR_VAR_3} אימנתי\n"
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "ואחד {STR_VAR_1}-משתמש\n"
	.string "{STR_VAR_2}.\p"
	.string "בבקשה, האם תוכל לקיים את משאלתי?\n"
	.string "אני רוצה להיות שותף צוות התג שלך!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "איי! אני… מתחרפן!\n"
	.string "תודה רבה!\l"
	.string "אני אלך להירשם מיד!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "וואאה! אין לך מעט רחמים?\n"
	.string "אבל זה עושה אותך מגניב יותר…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "יא-הו! אני חניך מספר {STR_VAR_2}\n"
	.string "של {STR_VAR_1}!\p"
	.string "שמי {STR_VAR_3}, שלום, שלום!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "המנטור שלי {STR_VAR_3} המליץ\n"
	.string "על אחד {STR_VAR_1}-מאסטר {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "ואחד {STR_VAR_1}-מאסטר\n"
	.string "{STR_VAR_2}.\p"
	.string "דברים טובים, נכון?\n"
	.string "תצטרף אלי, נכון?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "בסדר, מצוין!\n"
	.string "אני אסיים את ההרשמה מהר!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "אווו!\n"
	.string "את{EMIT_HEY} אדם מתוחכם, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "היי! יש צרה! זהו\n"
	.string "היום האחרון של מגדל הקרב!\p"
	.string "… … … … … …\n"
	.string "רק צוחק!\p"
	.string "קוראים לי {STR_VAR_3} ואני גם כך קורא לעצמי!\n"
	.string "אני חניך מספר 1,000 של {STR_VAR_1}!\l"
	.string "למעשה, אני חניך מספר {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} נתן לי עצה.\n"
	.string "{STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} עם {STR_VAR_1}.\n"
	.string "יש לי עשרה מכל סוג!\l"
	.string "למעשה, רק אחד מכל סוג!\p"
	.string "מה דעתך?\n"
	.string "רוצה לנסות קרבות תג איתי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "יאפי!\n"
	.string "אתן לך פוקימון כתודה!\p"
	.string "רק צוחק! אבל באמת אלך לעשות\n"
	.string "את ההרשמה, בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "אה, זה כל כך קר! אצטרך להרוס\n"
	.string "את מגדל הקרב בגלל זה!\p"
	.string "כמובן שלא באמת!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "היי, אני רוקנרול!\n"
	.string "פוקימונים, אני שולט!\p"
	.string "אני {STR_VAR_3} הימאי המראפר.\n"
	.string "אל תטעה אותי באף אחד אחר!\p"
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}.\n"
	.string "אל תמהר לפסול אותי!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "בהנחיית {STR_VAR_3} הרכבתי את צוותי בגאווה!\l"
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "ואחד {STR_VAR_1}-משתמש\n"
	.string "{STR_VAR_2}!\p"
	.string "את המפגש הזה עלינו לחגוג,\n"
	.string "עם ניצחון צוות תג לחגיגה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "היי, היי, אני אוהב את הסגנון שלך!\n"
	.string "אני אלך להגיש את ההרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "אה, היי, {PLAYER}, זה קר!\n"
	.string "אם אפשר להיות כנה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "יאפיי-יאו!\n"
	.string "אה, אל תברח! רק נהניתי!\p"
	.string "שלום! אני {STR_VAR_3}!\n"
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} אמר לי מה לעשות.\n"
	.string "אז אחד {STR_VAR_1}-משתמש {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "ואחד {STR_VAR_1}-משתמש\n"
	.string "{STR_VAR_2}, בחרתי.\p"
	.string "אז, מה תגיד?\n"
	.string "קדימה, עשה לי את היום!\p"
	.string "בבקשה, אני מתחנן!\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לי להצטרף אליך, אל תשאיר אותי עצוב!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "יאאה! המזל איתי!\n"
	.string "זה בהחלט משמח אותי!\p"
	.string "לפני שנלך לקרב,\n"
	.string "אני אלך להירשם מיד!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "את{EMIT_HEY} מסרב לי?\n"
	.string "{PLAYER}, את{EMIT_HEY} גורם לי להזעיף פנים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "שיעול!\p"
	.string "אה, סליחה, יש לי צינון.\n"
	.string "אבל הפוקימונים שלי בסדר.\p"
	.string "שמי {STR_VAR_3}, חניך מספר {STR_VAR_2} של {STR_VAR_1}.\n"
	.string "שיעול!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "לקחתי ברצינות את עצת {STR_VAR_3}\n"
	.string "והרכבתי את הצוות שלי של\l"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "אימנתי אותם כל יום,\n"
	.string "אפילו ברוח ובגשם.\p"
	.string "אולי בגלל זה יש לי צינון,\n"
	.string "כך נראה לי.\p"
	.string "זה מי שאני.\n"
	.string "רוצה להיות שותפי לצוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "תודה, אני מעריך זאת!\n"
	.string "שיעול, שיעול!\l"
	.string "המתן בזמן שאני הולך להירשם.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "אה, לא תסכים?\n"
	.string "{PLAYER}, אני חושב שנעשה צוות תג טוב.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "אה, שלום!\n"
	.string "זה מלחיץ.\p"
	.string "אני {STR_VAR_3}.\n"
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} אמר שהצוות הזה יהיה טוב--\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "אני קצת לא בטוח בעצמי לגבי זה,\n"
	.string "אבל האם תתן לי להצטרף אליך?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "או, אוי, תודה!\n"
	.string "אני מתבייש, אבל אתן את הכי טוב!\p"
	.string "אני אלך לסיים את ההרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "אה, בבקשה אל תגיד לא!\n"
	.string "אני כבר די חסר ביטחון…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "אני {STR_VAR_3}, וזה לא שקר.\n"
	.string "אני חניך מספר {STR_VAR_2} של {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} המליץ על הצוות שלי.\p"
	.string "מאחר שהעצה נשמעה כנה,\n"
	.string "החלטתי להביא איתי\l"
	.string "את {STR_VAR_1}-משתמש {STR_VAR_2} שלי ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "את {STR_VAR_1}-משתמש {STR_VAR_2}.\p"
	.string "אם אפשר, אשמח אם תקבל אותי\n"
	.string "כשותף לצוות תג שלך.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "את{EMIT_HEY} באמת תקבל אותי?\n"
	.string "אחרת זה יהיה נורא.\p"
	.string "אבל מאחר שאת{EMIT_HEY} הסכמת, זה בסדר.\n"
	.string "אני אלך להירשם עבור שנינו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "הממ? למה תסרב?\n"
	.string "זה הסיפור שלך לבדיחה?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "אני {STR_VAR_1}, ואני ילדה צעירה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "מה שיש לי הוא אחד {STR_VAR_2}\n"
	.string "שמשתמש ב{STR_VAR_1} ואחד$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} שמשתמש ב{STR_VAR_1}.\n"
	.string "אלה מה שיש עימי.\p"
	.string "האם תהיה שותפי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "תודה!\n"
	.string "אני אלך לבצע את ההרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "את{EMIT_HEY} לא רוצה להיות שותפי?\n"
	.string "את{EMIT_HEY} תתחרט{ADD_YUD} על זה אחר כך!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "שלום!\p"
	.string "אני הילד {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "רוצה לדעת מה יש לי?\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "תהיה שותפי לצוות תג, נכון?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "יאיי!\n"
	.string "אני אלך להירשם, בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "אוף! אילו היית יוצר צוות תג עם\n"
	.string "הפוקימונים שלי, היינו בלתי מנוצחים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "יאהו!\n"
	.string "אני מטייל {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "יודע מה יש לי?\n"
	.string "ה{STR_VAR_1}-משתמש {STR_VAR_2} שלי ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "ה{STR_VAR_1}-משתמש {STR_VAR_2} שלי!\p"
	.string "נשמע טוב, נכון?\n"
	.string "רוצה ליצור צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "יאהו!\n"
	.string "אני אלך להירשם עכשיו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "הייתי שמח להילחם לצדך.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "שלום!\n"
	.string "אני {STR_VAR_1}, ואני יופי!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "האם ידעת מה אילפתי?\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "מה דעתך?\n"
	.string "רוצה ליצור צוות תג יחד?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "נפלא!\n"
	.string "אני אלך לסיים את ההרשמה עכשיו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "איזו אכזבה!\p"
	.string "אנחנו יחד היינו הטובים ביותר!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "יו!\p"
	.string "את{EMIT_HEY} יודע מי אני?\n"
	.string "אני {STR_VAR_1} הדייג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "יש לי צוות של אחד\n"
	.string "{STR_VAR_1}-משתמש {STR_VAR_2} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "ואחד {STR_VAR_1}-משתמש {STR_VAR_2}.\p"
	.string "אז, מה דעתך?\n"
	.string "תלחם לצדי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "טוב, טוב!\n"
	.string "השאר זאת לי!\p"
	.string "אני אלך להירשם עבור שנינו עכשיו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "היינו מתאימים בדיוק גם…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "נעים להכיר.\n"
	.string "אני {STR_VAR_1}, גברת.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "מלווה אותי צוות של\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "מקווה שזה יקבל את אישורך.\n"
	.string "רוצה שתהיה שותפי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "מודה לך בכנות.\n"
	.string "אדאג להרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "בטוחה שתצטער על כך שלא לקחת\n"
	.string "אותי כשותפה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "אני טריאתלטית {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "מה שיש לי…\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\n"
	.string "זו הצוות תגיות שלי!\p"
	.string "בבקשה?\n"
	.string "תיצור איתי צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "אוי, תודה!\n"
	.string "אני אלך להירשם בדלפק.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "אנחנו יחד היינו חזקים בטוח!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "היי!\n"
	.string "אני לוכד חרקים {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "תבדוק מה יש לי!\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "אז תקשיב!\n"
	.string "רוצה ליצור צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "תפסתי אותך!\p"
	.string "אני אלך לבצע את ההרשמה\n"
	.string "בדלפק.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "אוף, הפוקימונים שלי מדהימים.\n"
	.string "מקווה שלא תתחרט!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "יום טוב!\n"
	.string "אני תלמיד {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "מה שאילפתי הם אחד\n"
	.string "{STR_VAR_2} שמשתמש ב{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "ואחד {STR_VAR_2} שמשתמש\n"
	.string "ב{STR_VAR_1}.\p"
	.string "לא רע, מה דעתך?\n"
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} ליצור צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "תודה רבה!\n"
	.string "אדאג להשלים את ההרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "חבל מאוד…\p"
	.string "קיוויתי שאוכל ללמוד ממך\n"
	.string "כשותף…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "יו! תן לי לומר מי אני!\n"
	.string "אני הילד העשיר {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "נחש מה יש לי!\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "אני מציע לך אפשרות\n"
	.string "להיות בצוות תג איתי.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "מהלך חכם!\p"
	.string "אני אסיים את תהליך ההרשמה\n"
	.string "מהר!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "את{EMIT_HEY} תדחה אותי מכל האנשים?\n"
	.string "תתחרט על ההחלטה הזאת בטוח!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "הייה!\n"
	.string "אני אלוף שחור {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "כחבריי, יש לי\n"
	.string "אחד {STR_VAR_2} המשתמש ב{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "ואחד {STR_VAR_2} המשתמש\n"
	.string "ב{STR_VAR_1}.\p"
	.string "בבקשה, קבל את בקשתי!\n"
	.string "הרשה לי להיות שותף תג שלך!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "הייה!\n"
	.string "אני אלך להירשם מיד!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "אני מבין… מקווה להזדמנות\n"
	.string "בפעם הבאה שנפגש…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "שלום!\n"
	.string "אני {STR_VAR_1}, ואני שייטת!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "אספר לך מה יש לי.\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\n"
	.string "האם אוכל להצטרף לצוות התג שלך?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "תודה!\n"
	.string "אני אלך להירשם עבורנו עכשיו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "אם היינו שותפים, היינו חזקים כל כך!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "ברכות…\n"
	.string "אני משוגע הקסמים {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "אני נושא עימי אחד {STR_VAR_1} בשימוש\n"
	.string "{STR_VAR_2} ביחד עם אחד$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}-משתמש {STR_VAR_2}…\p"
	.string "אני מתחנן…\n"
	.string "הצטרף אלי כצוות תג…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "מודה לך…\n"
	.string "אני אלך להירשם עבורנו…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "כל כך רציתי להצטרף אליך…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "מה שלומך? אני {STR_VAR_1},\n"
	.string "ואני מאלף פוקימונים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "אני מגדל כמה טובים!\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "ואחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "מה דעתך?\n"
	.string "רוצה ליצור צוות תג איתי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "תודה רבה!\p"
	.string "אני אלך לטפל בהרשמה, חכה כאן!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "קיוויתי להיות שותפך…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "נו, שלום!\n"
	.string "אני טריאתלטית {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "רוצה לדעת עם מה אני רצה?\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "נו?\n"
	.string "רוצה להיות שותף לצוות תג איתי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "מעולה!\p"
	.string "אחזור מהר ואשלים את ההרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "את{EMIT_HEY} ואני היינו עליונים.\n"
	.string "חבל…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "היי שם! קוראים לי {STR_VAR_1}!\n"
	.string "אני טריאתלט!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "אני רץ עם הצוות החזק שלי--\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "לא רע, נכון?\n"
	.string "אנחנו צריכים להיות צוות תג ביחד!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "סבבה!\n"
	.string "אני אלך להירשם במהירות!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "באמת רציתי להילחם כשותף צוות תג שלך…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "אני ילדת קרב {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "אימנתי והקשחתי אחד\n"
	.string "{STR_VAR_1}-משתמש {STR_VAR_2} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}!\p"
	.string "את{EMIT_HEY} אוהב את השילוב הזה?\n"
	.string "מה דעתך שתתחבר איתי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "אוי, תודה!\p"
	.string "אני אלך להשלים את ההרשמה\n"
	.string "עכשיו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "איתך, חשבתי שנוכל להקים\n"
	.string "את צוות התג האולטימטיבי…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "אני טריאתלט {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "רץתי עם אחד {STR_VAR_2}\n"
	.string " שיודע להשתמש ב{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "ואחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "אנחנו יכולים להיות צוות תג.\n"
	.string "האם זה לא יהיה נפלא?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "תודה!\p"
	.string "אני אלך להירשם עבורנו, ועכשיו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "אוף, זה חבל. היינו צוות תג הכי חזק!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "אני?\n"
	.string "אני שייט {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "מה יש לי עימי?\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "נו?\n"
	.string "תשתף איתי פעולה, כן?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "בסדר!\p"
	.string "אני אלך להירשם!\n"
	.string "נייחד יחד היותנו מצוינים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "הפוקימונים שלי חזקים בטוח…\n"
	.string "חבל שאינך רוצה להצטרף.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "יאה-היי!\n"
	.string "קוראים לי גיטריסט {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "תסתכל על המלווה שלי!\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "יאה-היי! די פרוע, נכון?\n"
	.string "נעשה דואט בצוות תג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "יאה-היי! נכון!\n"
	.string "אני אלך לבצע את ההרשמה עכשיו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "הפוקימונים שלי קשים כמו סלע!\n"
	.string "תתחרט, אני אומר לך!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "נעים להכיר.\n"
	.string "אני {STR_VAR_1}, ג'נטלמן.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "מלווים אותי הנאמנים שלי\n"
	.string "{STR_VAR_1}-משתמש {STR_VAR_2} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}.\p"
	.string "האם אוכל לבקש ממך להצטרף אלי\n"
	.string "כשותף צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "אה, מודה על אמונתך.\n"
	.string "אני אסיים את ההרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "זה חבל מאוד…\p"
	.string "אחכה להזדמנות הבאה…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "שלום, אני {STR_VAR_1},\n"
	.string "ואני אוהב פוקימונים.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "יש לי עכשיו אחד {STR_VAR_2}\n"
	.string " שיודע את המהלך {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "האם אהבת את מה שראית?\n"
	.string "למה שלא תהיה שותפי לצוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "תודה!\n"
	.string "אדאג להרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "הפוקימונים שלי מהדרגה הגבוהה…\n"
	.string "חבל שלא מעריכים זאת.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "הממ!\n"
	.string "אני {STR_VAR_1}, ואני מומחה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "הפוקימונים שאימנתי הם\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "מה דעתך על צוות תג איתי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "הממ!\n"
	.string "אני אלך להירשם מיד!\l"
	.string "בואו נעשה את המיטב!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "אני אקווה שהבחירה שלך תהיה\n"
	.string "נכונה…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "שלום, שלום.\n"
	.string "אני {STR_VAR_1}, ואני מומחית.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "אילפתי את הפוקימונים שלי בקפידה.\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}--\n"
	.string "אלה מה שיש לי.\p"
	.string "האם לא תרצ{EMIT_HEY}{ADD_YUD} להצטרף אלי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "טוב, טוב.\n"
	.string "אדאג להרשמה מיד.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "אולי נוכל ליצור צוות בפעם\n"
	.string "הבאה שנפגש.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "אני מאמן דרקונים {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "הצוות שאימנתי הוא\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "מה דעתך?\n"
	.string "רוצה להיות שותפי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "בסדר, אתן את מיטב שלי!\n"
	.string "אני אלך להירשם עכשיו, בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "לא תמצא הרבה שותפים חזקים יותר ממני!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "אני שומר על ציפורים {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "איזה פוקימון יש לי?\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "האם לא נראה שנעשה צוות תג מוצלח?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "מעולה, תודה!\n"
	.string "אדאג להרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "הפוקימונים שלי ואני חזקים.\n"
	.string "איזו אכזבה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "אני נער נינג'ה {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "צוות הפוקימונים שלי כולל אחד\n"
	.string "{STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "בוא נהיה בצוות תג יחד!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "יאיי!\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לי ללכת להירשם!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "תתחרט שלא לקחת את הפוקימונים\n"
	.string "החזקים שלי לצדך!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "שלום!\n"
	.string "אני גברת מטרייה {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "מלווה אותי כעת {STR_VAR_2}\n"
	.string "שמשתמש ב{STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "אחד {STR_VAR_2} שמשתמש\n"
	.string "ב{STR_VAR_1}.\p"
	.string "האם אינם חביבים?\n"
	.string "רוצה להצטרף אלינו כצוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "תודה רבה!\p"
	.string "אני אלך להירשם בדלפק.\n"
	.string "בואו לא מאכזבים זה את זה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "הפוקימונים שלי חזקים מאוד.\n"
	.string "איזו אכזבה…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "שלום.\n"
	.string "אני {STR_VAR_1}, משוגע חרקים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "מצאתי את הפוקימונים שלי, כן.\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}--\n"
	.string "אלה מה שמצאתי.\p"
	.string "האם אוכל לעניין אותך ליצור\n"
	.string "צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "בסדר!\n"
	.string "מובן!\p"
	.string "לא ארחיק זמן בהרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "עם הפוקימונים שמצאתי, לא היינו\n"
	.string "הפסדנו…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "אהוי, שם!\n"
	.string "אני ימאי {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "ת{SWAP_NUN}{ADD_YUD} לי להראות לך את הלהט שלי!\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "כמובן שלא תדחה אותי. נתחבר, נכון?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "לא ציפיתי לפחות מזה!\n"
	.string "אני אלך להירשם עכשיו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "היינו עוברים דרך האויב! חבל!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "היי, אני {STR_VAR_1}.\n"
	.string "אני אספן.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "התכשיטים באוסף שלי הם\n"
	.string "ה{STR_VAR_2} שלי עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "נהדר, נכון?\n"
	.string "אנחנו צריכים להיות צוות יחד.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "אה, כן!\p"
	.string "טוב, אל נבזבז זמן.\n"
	.string "אני אלך להירשם עבורנו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "ובכן, זה מעציב.\n"
	.string "את{EMIT_HEY} לא מעריך את הפוקימונים שלי.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "מה נשמע, אני {STR_VAR_1}.\n"
	.string "אני ריינג'ר פוקימונים.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "חברתיי הם אחד\n"
	.string "{STR_VAR_1}-משתמש {STR_VAR_2} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "האם לא נראה שנהיה צוות תג מרשים?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "נפלא!\n"
	.string "אדאג להרשמה עכשיו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "בפעם הבאה, בחר את הפוקימונים שלי,\n"
	.string "בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "שמי {STR_VAR_1}.\n"
	.string "אני ריינג'רית פוקימונים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "אזכיר לך על הצוות שלי. יש לי\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "איך תרצ{EMIT_HEY}{ADD_YUD} ליצור צוות תג\n"
	.string "עם הקבוצה הקטנה שלי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "נהיה במיטבנו!\n"
	.string "אני אסיים את ההרשמה במהירות!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "מקווה שתבחר את הפוקימונים שלי\n"
	.string "בפעם הבאה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "נעים להכיר. אני {STR_VAR_1}.\n"
	.string "אני גברת ארומה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "אני משוטטת עם אחד {STR_VAR_2}\n"
	.string "שמשתמש ב{STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "אחד {STR_VAR_2} שמשתמש\n"
	.string "ב{STR_VAR_1}.\p"
	.string "מקווה שהם ימצאו חן בעיניך.\n"
	.string "היית רוצה להיות שותפתי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "מכובד על קבלתך.\n"
	.string "אני אלך להירשם מיד.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "יהיה נפלא אם נוכל ליצור\n"
	.string "צוות תג בפעם הבאה שנפגש.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "רוצה לדעת מי אני?\n"
	.string "אני {STR_VAR_1}, משוגע חורבות!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "הפוקימונים שברשותי הם\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "מעניין, נכון?\n"
	.string "מה אם נתחבר כשותפים?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "זו החלטה נכונה!\n"
	.string "אני אלך למלא את טופס ההרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "הממ…\n"
	.string "אני חושב שהפוקימונים שלי חזקים…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "אני מאמן מגניב {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "הפוקימונים שיש לי עכשיו הם\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\n"
	.string "מגניב, נכון?\p"
	.string "האם לא יהיה מגניב אם\n"
	.string "ניצור צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "מגניב!\n"
	.string "אני אלך להירשם במהירות!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "חשבתי שניצור\n"
	.string "את הצוות הגדול אי פעם.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "אני מאמנת מגניבה {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "הצוות שאילפתי כולל אחד\n"
	.string "{STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "זה נשמע בסדר?\n"
	.string "מה אם נהפוך לשותפות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "נשמע מצוין!\n"
	.string "אעדיף להשלים את ההרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "חשבתי כמה נהיה\n"
	.string "צוות חזק…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "היי-יו!\n"
	.string "אני {STR_VAR_1}, משוגע פוקימונים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "מה יש לאיש כמוני?\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1},\n"
	.string "זהו!\p"
	.string "יאללה!\n"
	.string "נרעד כמין צוות תג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "בחירה מצוינת!\n"
	.string "אירשם עבור שנינו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "הפוקימונים שלי אכזריים!\n"
	.string "לא אשמתי אם תתחרט!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "מה נשמע!\n"
	.string "אני מדליק {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "את{EMIT_HEY} יודע מה שאימנתי הביא?\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "נו, מה תגיד?\n"
	.string "רוצה ליצור צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "בסדר!\n"
	.string "אני אלך לבצע את ההרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "הבטחה שתשתף איתי פעולה\n"
	.string "בפעם הבאה שנפגש?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "אני {STR_VAR_1}, ואני קמפינג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "אילפתי אחד {STR_VAR_1}-\n"
	.string "שמשתמש ב{STR_VAR_2} ועוד אחד$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}-משתמש {STR_VAR_2}.\p"
	.string "האם את{EMIT_HEY} חושב שיהיה כיף להצטרף?\n"
	.string "אני בטוח שכן!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "כן!\n"
	.string "אני אלך להירשם!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "בפעם הבאה, בסדר?\n"
	.string "אני רוצה להיות בצוות שלך.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "שלום!\n"
	.string "אני {STR_VAR_1}, ואני פיקניקאי!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "הפוקימונים שאני לוקח הם\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} להצטרף אלי\n"
	.string "כשותף צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "או, תודה רבה!\n"
	.string "אני אלך להירשם עכשיו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "יהיה נחמד אם אוכל להצטרף אליך\n"
	.string "מועד אחר.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "אני פסיכי {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "הצוות תג שאילפתי הם\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} ליצור צוות תג\n"
	.string "איתי?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "בשמחה!\n"
	.string "אדאג להרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "אם ניפגש שוב, זה הזמן\n"
	.string "שתתחבר איתי.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "אני {STR_VAR_1}.\n"
	.string "אני פסיכית.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}--\n"
	.string "הם תלמידי.\p"
	.string "האם רעיון של יצירת שותפות\n"
	.string "כצוות תג מעניין אותך?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "תודה.\n"
	.string "אני אלך לטפל בהרשמה.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "מקווה שתהיה הזדמנות נוספת\n"
	.string "ליצור ברית.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "אני תלמידה {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "ועוד אחד {STR_VAR_1}-משתמש\n"
	.string "{STR_VAR_2} הם צוות תג הפוקימונים שלי.\p"
	.string "האם אפשר בבקשה להיות שותפתך\n"
	.string "בצוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "אוי, תודה!\n"
	.string "אני אלך להירשם בדלפק מיד!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "בבקשה?\n"
	.string "האם אוכל להצטרף אליך בפעם הבאה?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "היי! קוראים לי {STR_VAR_1}!\n"
	.string "אני מטפל פוקימונים!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "הפוקימונים שגידלתי הם אחד\n"
	.string "{STR_VAR_1}-משתמש {STR_VAR_2} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}.\p"
	.string "נשמע מעניין?\n"
	.string "מה אם ניצור צוות תג?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "בסדר גמור!\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לטפל בהרשמה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "את{EMIT_HEY} חייב{ADD_TAF} להתחבר איתי בפעם הבאה,\n"
	.string "בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "אני {STR_VAR_1}, וגאה לומר\n"
	.string "שאני אוהבת פוקימונים.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "הפוקימונים החמודים שאילפתי הם\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}.\p"
	.string "הם לא הכי חמודים?\n"
	.string "עלינו ליצור צוות!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "תודה לך יקירי!\n"
	.string "אני אלך להירשם עכשיו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "הפוקימונים החמודים שלי הם הכי טובים,\n"
	.string "רק שתדע. כמה מעצבן!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "היי, אני שוחה {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "אחד {STR_VAR_1}-משתמש {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "ועוד אחד {STR_VAR_1}-משתמש\n"
	.string "{STR_VAR_2} הם מה שאילפתי.\p"
	.string "את{EMIT_HEY} ואני, בואו נעשה צוות תג.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "מעולה!\n"
	.string "אני אלך להירשם עבור שנינו.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "אם נפגש שוב, את{EMIT_HEY} חייב{ADD_TAF} לי\n"
	.string "צוות תג!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "מה קורה?\n"
	.string "אני {STR_VAR_1}, ואני טריאתלט!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "יש לי כמה פוקימונים נחמדים.\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "יהיה נחמד אם ניצור צוות תג\n"
	.string "ביחד, אז מה דעתך?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "יוצא מן הכוח!\n"
	.string "חכ{EMIT_HEY}{ADD_YUD} שאסיים להירשם, בסדר?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "אני מצפה שתאפשר לי להצטרף\n"
	.string "בפעם הבאה, מה דעתך?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "אני הטריאתלטית {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "עוד אחד {STR_VAR_2} שיודע להשתמש\n"
	.string "ב{STR_VAR_1}. זו הצוות תגיות שלי.\p"
	.string "מה דעתך?\n"
	.string "אנחנו ניצור צוות טוב, לדעתי.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "אהבתי את התשובה!\n"
	.string "אני אסיים את ההרשמה במהירות!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "תתני לי הזדמנות נוספת ליצור\n"
	.string "שותפות, נכון?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "היי שם! הלו!\n"
	.string "אני {STR_VAR_1}, ואני שוחה!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "תבדוק מה אילפתי!\n"
	.string "אחד {STR_VAR_2} עם {STR_VAR_1} ו$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "אחד {STR_VAR_2} עם {STR_VAR_1}!\p"
	.string "מגניב, נכון?\n"
	.string "יהיה מגניב גם ליצור צוות!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "תודה רבה!\n"
	.string "אני אסיים את ההרשמה הזו!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "אם נפגש שוב, את{EMIT_HEY} חייב{ADD_TAF} להתחבר\n"
	.string "אליי. תעש{EMIT_HEY}{ADD_YUD} זאת, נכון?$"

