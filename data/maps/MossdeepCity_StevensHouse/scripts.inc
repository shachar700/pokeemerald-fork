MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_StevensHouse_OnTransition:
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos::
	setobjectxyperm LOCALID_STEVENS_HOUSE_STEVEN, 6, 5
	setobjectmovementtype LOCALID_STEVENS_HOUSE_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame:
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
	lockall
	applywaitmovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_Delay48
	applywaitmovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 20
	applywaitmovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
	lockall
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_STEVENS_HOUSE_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven::
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter::
	lockall
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
	finditem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
	.string "סטיבן: {PLAYER}{KUN}…\p"
	.string "כפי שאת{EMIT_HEY} רואה, אין כאן הרבה,\n"
	.string "אבל זה הבית שלי.\p"
	.string "תודה על כל מה שעשית.\p"
	.string "זה אות ההערכה שלי.\n"
	.string "זוהי המכונה הנסתרת צלילה.\p"
	.string "אין צורך להתבייש--הרווחת\n"
	.string "את המ”נ הזה.$"

MossdeepCity_StevensHouse_Text_ExplainDive:
	.string "סטיבן: בזמן שאת{EMIT_HEY} משתמש{ADD_TAF} בגלישה, את{EMIT_HEY}\n"
	.string "צרי{SWAP_CHAF}{ADD_HEY} לשים לב לכתמי מים כהים.\p"
	.string "השתמש{ADD_YUD} בצלילה אם את{EMIT_HEY} מגיע{ADD_HEY} למים עמוקים\n"
	.string "כאלה. את{EMIT_HEY} תשקע{ADD_YUD} לקרקעית הים.\p"
	.string "כשאת{EMIT_HEY} רוצה לחזור למעלה, השתמש{ADD_YUD}\n"
	.string "שוב בצלילה.\p"
	.string "עם זאת, בחלק מהמקומות לא תהיה לך\n"
	.string "האפשרות לעלות אל פני המים.$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
	.string "סטיבן: ככל הנראה, ישנה\n"
	.string "מערה תת-ימית בין\l"
	.string "מוסדיפ לסוטופוליס.\p"
	.string "את{EMIT_HEY} יודע{ADD_TAF}, זו שקפטן סטרן\n"
	.string "מצא בצוללת שלו.$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
	.string "{PLAYER} בדק{ADD_HEY} את הפוכדור.\p"
	.string "הוא הכיל את הפוקימון\n"
	.string "{STR_VAR_1}.\p"
	.string "לקחת את הפוכדור?$"

MossdeepCity_StevensHouse_Text_ObtainedBeldum:
	.string "{PLAYER} קיבל{ADD_HEY} {STR_VAR_2}.$"

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
	.string "אין מקום לפוקימון נוסף.$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} השאיר{ADD_HEY} את הפוכדור\n"
	.string "במקום בו היה.$"

MossdeepCity_StevensHouse_Text_LetterFromSteven:
	.string "זה מכתב.\p"
	.string "… … … … … …\p"
	.string "ל{PLAYER}{KUN}…\p"
	.string "החלטתי לעשות חיפוש נשמה קטן\n"
	.string "ולהתאמן בדרך.\p"
	.string "אני לא מתכנן לחזור הביתה למשך\n"
	.string "זמן מה.\p"
	.string "יש לי טובה לבקש ממך.\p"
	.string "אני רוצה שתיקח{ADD_YUD} את הפוכדור\n"
	.string "שעל השולחן.\p"
	.string "בתוכו יש {STR_VAR_1}, הפוקימון\n"
	.string "האהוב עליי.\p"
	.string "אני סומך עליך.\p"
	.string "שדרכינו יצטלבו יום אחד.\p"
	.string "סטיבן סטון$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
	.string "זהו אוסף של סלעים ואבנים נדירות\n"
	.string "שאסף סטיבן.$"

