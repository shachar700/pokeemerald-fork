AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applywaitmovement VAR_0x8008, Common_Movement_ExclamationMark
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applywaitmovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	delay 20
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "היהיהי…\p"
	.string "הגעת לכאן כבר, הא?\n"
	.string "הערכנו אותך פחות למדי!\p"
	.string "אבל זהו זה!\p"
	.string "אני מעל לעובדים הפשוטים שראית\n"
	.string "עד עכשיו.\p"
	.string "אני לא מבזבז זמן.\n"
	.string "אני הולך לרסק אותך!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "היהיהי…\n"
	.string "אז, גם אני הפסדתי…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "היהיהי!\p"
	.string "בזמן ששיחקתי איתך, הבוס שלנו\n"
	.string "סיים את ההכנות שלו!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "היהיהי!\p"
	.string "הבוס שלנו כבר יצא לדרכו אל\n"
	.string "איזו מערה מתחת לים!\p"
	.string "אם את{EMIT_HEY} מתכוו{SWAP_NUN}{ADD_TAF} לרדוף, מוטב שתחפש{ADD_YUD}\n"
	.string "בים הגדול והרחב מעבר לליליקוב.\l"
	.string "אבל האם תמצא אותה אז?\n"
	.string "היהיהי!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "וואהאהאה, נמאס לי לחכות!\n"
	.string "גם לי את{EMIT_HEY} חייב{ADD_TAF} קרב!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "עייף מלחכות…\n"
	.string "אבוד ומבולבל…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "בוס…\n"
	.string "האם זה מספיק טוב?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "לוחות שיגור, מקור הגאווה והשמחה\n"
	.string "של המחבוא!\p"
	.string "אין לך מושג היכן את{EMIT_HEY} נמצא{ADD_TAF},\n"
	.string "נכון?\p"
	.string "להבהיל ולעייף את האויב, ואז\n"
	.string "להנחית את המכה! זו התוכנית שלנו!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "מה קורה איתך?\n"
	.string "את{EMIT_HEY} לא עיי{SWAP_PEY}{ADD_HEY} בכלל!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "זה מזכיר לי… אני לא זוכר\n"
	.string "איפה שמתי את הכדור על.\p"
	.string "אם אני לא אשמור עליו, הבוס שלנו\n"
	.string "ינזוף בי…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "כשהצטרפתי לצוות אקווה, הדבר הראשון\n"
	.string "שהייתי צריך ללמוד היה כיצד לוחות\l"
	.string "השיגור האלה מחוברים.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "הייתי עסוק מדי במחשבות על\n"
	.string "לוחות השיגור…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "אני אצטרך ללמוד כיצד אני יכול\n"
	.string "להילחם בצורה יעילה יותר…$"
