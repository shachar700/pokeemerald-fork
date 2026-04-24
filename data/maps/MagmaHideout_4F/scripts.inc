MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	bufferspeciesname STR_VAR_1, SPECIES_GROUDON
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "גם אני רוצה לראות את {STR_VAR_1}, אבל הם\n"
	.string "לא נותנים לי לראות אפילו את הזנב שלו…\p"
	.string "זה גורם לי להרגיש ממש מתוסכל.\p"
	.string "או, לא!\n"
	.string "פטפטתי על {STR_VAR_1}!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "אני מניח שזה בלתי אפשרי לנצח אם\n"
	.string "אין לאדם נפש רגועה…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "מעניין אם ל{STR_VAR_1} יש בכלל זנב?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "פוהאהאהא!\n"
	.string "בקרוב! ממש בקרוב!\l"
	.string "המטרה הגדולה שלנו תושג!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "גררר…\n"
	.string "הגעתי כל כך רחוק, ועכשיו זה?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "מקסי, אדוני!\n"
	.string "פולש{ADD_TAF} בדרכ{EMIT_VAV}{ADD_HEY} אליך!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "את{EMIT_HEY} עוד לא גמור{ADD_HEY}!\n"
	.string "את{EMIT_HEY} לא עובר{ADD_TAF} אותי בקלות!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "האם היה כל כך קל להפיל אותי?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "ק-קדימה, עוד קרב אחד…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "היהיהי!\n"
	.string "הגעת כל כך רחוק, אז אני אגלה לך!\p"
	.string "זה נכון!\n"
	.string "מלפנים, {STR_VAR_1} ישן!\p"
	.string "מקסי הלך ל{STR_VAR_1} ממש לפני\n"
	.string "שניות!\p"
	.string "הוא יתעורר ממש בקרוב!\n"
	.string "היהי! היהיהי!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "הופלתי שוב…\n"
	.string "היהי…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…ובזמן שבזבזת זמן איתי,\n"
	.string "מקסי אמור היה להעיר את {STR_VAR_1}…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "מקסי: {STR_VAR_1}…\p"
	.string "שום דבר לא יכול היה להעיר אותך מהשינה\n"
	.string "שלך שטופת המגמה…\p"
	.string "הכדור הכחול הזה הוא מה שחיפשת.\n"
	.string "לא?\p"
	.string "הבאתי לך את הכדור הכחול.\n"
	.string "תן לזוהר שלו להעיר אותך!\p"
	.string "והראה לי…\n"
	.string "הראה לי את מלוא כוחך!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "מקסי: {STR_VAR_1}!\n"
	.string "מה לא בסדר?\p"
	.string "האם הכדור הכחול לא היה המפתח?\p"
	.string "{STR_VAR_1}!\n"
	.string "לאן נעלמת…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "מקסי: או, אז זה היית את{EMIT_HEY}?\p"
	.string "ראיתי אותך מסתובב{ADD_TAF} ללא הזמנה\n"
	.string "כאן ושם…\p"
	.string "אני מבין עכשיו!\n"
	.string "את{EMIT_HEY} בטח עשית איזה תעלול זול!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "מה גורם לך להיות כה מיומ{SWAP_NUN}{ADD_TAF} בטיפול\n"
	.string "פוקימונים?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "מקסי: חייבת להיות איזו סיבה\n"
	.string "למה {STR_VAR_1} ברח…\p"
	.string "זה מה שאת{EMIT_HEY} מנסה לומר,\n"
	.string "נכון?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "המפ…\n"
	.string "את{EMIT_HEY} חושב{ADD_TAF} שלא ידעתי את זה?\p"
	.string "עם {STR_VAR_1} שנעלם, אין עוד צורך\n"
	.string "בהר געש הארור הזה.\p"
	.string "אני הולך לרדוף אחרי {STR_VAR_1}, אז כאן\n"
	.string "דרכינו נפרדות!$"
