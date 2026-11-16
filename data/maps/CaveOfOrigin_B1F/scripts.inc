CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_GROUDON
	bufferspeciesname STR_VAR_2, SPECIES_KYOGRE
	bufferspeciesname STR_VAR_3, SPECIES_RAYQUAZA
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	delay 60
	playse SE_PIN
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	delay 30
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "אה, אז את{EMIT_HEY} {PLAYER}{KUN}?\n"
	.string "שמעתי סיפורים על מעשיך.\p"
	.string "שמי וולאס.\p"
	.string "הייתי פעם מנהיג מכון\n"
	.string "בסוטופוליס, אבל משהו עלה.\p"
	.string "אז עכשיו, הפקדתי את המנטור שלי חואן\n"
	.string "על תפעול המכון.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "{STR_VAR_1} ו{STR_VAR_2}, שני הפוקימונים\n"
	.string "שזורעים כאן הרס, נחשבים\l"
	.string "לפוקימונים על-קדומים.\p"
	.string "אבל אין רק שני פוקימונים על-\n"
	.string "קדומים.\p"
	.string "יש עוד אחד איפשהו.\p"
	.string "איפשהו, יש פוקימון על-\n"
	.string "קדום בשם {STR_VAR_3}.\p"
	.string "נאמר ש{STR_VAR_3} הוא זה\n"
	.string "שהרגיע את שני הנלחמים\l"
	.string "בעבר הרחוק.\p"
	.string "אבל אפילו לי אין מושג לגבי\n"
	.string "מקום הימצאו של {STR_VAR_3}…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "וולאס: {PLAYER}{KUN}, האם את{EMIT_HEY} אולי\n"
	.string "יודע{ADD_TAF} היכן {STR_VAR_3} נמצא עכשיו?\p"
	.string "אם כן, בבקשה תגיד{ADD_YUD} לי.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "וולאס: מערת המקור?\p"
	.string "אבל זה ממש כאן!\n"
	.string "אני צריך שתעש{EMIT_HEY}{ADD_YUD} עבודה טובה יותר מזה!\p"
	.string "בבקשה, אני צריך שתחש{EMIT_VAV}ב{ADD_YUD} איפה\n"
	.string "{STR_VAR_3} יכול להיות כרגע.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "וולאס: הר המוקד?\p"
	.string "אבל כשפגשתי שם את האישה המבוגרת\n"
	.string "מוקדם יותר, היא לא הזכירה אותו.\p"
	.string "אני מאוד מפקפק בכך שהאישה המבוגרת\n"
	.string "תנסה להסתיר ממני משהו…\p"
	.string "{PLAYER}{KUN}, האם תוכל{ADD_YUD} לחשוב על זה\n"
	.string "יותר בזהירות למעני?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "וולאס: האא? את{EMIT_HEY} לא זוכר{ADD_TAF}?\n"
	.string "הממ… זו בעיה…\p"
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} להיזכר איכשהו?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "וולאס: עמוד השמיים?\p"
	.string "זה זה!\n"
	.string "זה בטח עמוד השמיים!\p"
	.string "{PLAYER}{KUN}, אין רגע לבזבז!\n"
	.string "נלך לעמוד השמיים מיד!$"

