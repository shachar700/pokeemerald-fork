VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applywaitmovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applywaitmovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "וולי: היי! {PLAYER}!\p"
	.string "אני בטוח שאת{EMIT_HEY} מופתע{ADD_TAF} לראות אותי כאן!\p"
	.string "הגעתי עד לכאן, והכל בזכותך!\p"
	.string "{PLAYER}, ההפסד לך בפעם הזאת\n"
	.string "חיזק אותי!\p"
	.string "אבל אני לא הולך להפסיד יותר!\p"
	.string "אני הולך לנצח! למען הפוקימונים\n"
	.string "שנתנו לי אומץ וכוח!\p"
	.string "אוקיי… הנה אני בא!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "ואו!\n"
	.string "{PLAYER}, את{EMIT_HEY} חזק{ADD_HEY}, אחרי הכל!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "וולי: לא יכולתי לנצח אותך היום,\n"
	.string "{PLAYER}, אבל יום אחד, אני אדביק\l"
	.string "אותך!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "וולי: היי! {PLAYER}!\p"
	.string "התחזקתי מאז הפעם\n"
	.string "האחרונה! רציתי להראות לך, {PLAYER}!\p"
	.string "אוקיי… הנה אני בא!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "ואו!\n"
	.string "{PLAYER}, את{EMIT_HEY} חזק{ADD_HEY}, אחרי הכל!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "וולי: לא יכולתי לנצח אותך גם הפעם,\n"
	.string "אבל יום אחד, {PLAYER},\l"
	.string "אני אדביק אותך…\p"
	.string "ואאתגר את ליגת הפוקימון!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "הגעתי עד לכאן כמה פעמים,\n"
	.string "אבל הקטע האחרון כל כך ארוך…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "החלום שלי נגמר כאן שוב…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "הגעת עד לכאן. שמ{EMIT_VAV}ר{ADD_YUD} על המומנטום\n"
	.string "והפ{EMIT_VAV}{SWAP_CHAF}{ADD_YUD} לאלו{SWAP_PEY}{ADD_HEY}! אם מישהו יכול, זה את{EMIT_HEY}!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "לא עברתי את כל הדרך הזו כדי להפסיד עכשיו.\n"
	.string "אפשרות כזו לא קיימת!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "בלתי אפשרי…\n"
	.string "הפסדתי?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "הפסדתי כאן…\p"
	.string "זה אומר שחסרות לי הכישורים\n"
	.string "להפוך לאלוף…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "הדרך האינסופית והקשה לכאורה הזו\n"
	.string "עומדת בשמה הניצחון.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "סגנון הקרב שלך פנטסטי…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "נראה שיש לך את הפוטנציאל\n"
	.string "להפוך לאלו{SWAP_PEY}{ADD_HEY}.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "מהי דרך הניצחון?\n"
	.string "אני אגיד לך אם תנצח{ADD_YUD}!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "אוקיי!\n"
	.string "כל הכבוד!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "לעבור כאן בשלום--זהו המבחן האחרון\n"
	.string "לכל מאמן שמכוון להיות אלוף הפוקימון.\l"
	.string "זו הסיבה שקוראים לזה דרך הניצחון.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "אין לי מה לומר למישהו\n"
	.string "שהגיע{ADD_HEY} כל כך רחוק. קדימה!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "זו חרפה…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "המף, ל{SWAP_CHAF}{ADD_YUD} ישר קדימה.\n"
	.string "תרא{EMIT_HEY}{ADD_YUD} אם אכפת לי.$"
