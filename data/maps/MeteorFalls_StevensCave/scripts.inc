MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "סטיבן: או, וואו, {PLAYER}{KUN}.\n"
	.string "אני מופתע שידעת איפה למצוא אותי.\p"
	.string "האם את{EMIT_HEY}, המ…אולי חושב{ADD_TAF} עליי רק\n"
	.string "בתור משוגע על סלעים?\p"
	.string "לא, זה לא יכול להיות נכון.\p"
	.string "נלחמנו זה לצד זה במרכז החלל\n"
	.string "של סוטופוליס.\p"
	.string "את{EMIT_HEY} כבר צרי{SWAP_CHAF}{ADD_HEY} לדעת טוב מאוד\n"
	.string "כמה אני חזק.\p"
	.string "אוקיי, {PLAYER}{KUN}, אם את{EMIT_HEY} מתכוו{SWAP_NUN}{ADD_TAF} לאתגר\n"
	.string "אותי ברצינות, צפ{EMIT_HEY}{ADD_YUD} לגרוע מכל!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "את{EMIT_HEY}…\n"
	.string "לא ידעתי שנהיית כל כך חזק{ADD_HEY}…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "סטיבן: כשאני חושב על זה, מאז שנפגשנו\n"
	.string "לראשונה במערכת הגרניט בדופורוד,\l"
	.string "הייתה לי מן תחושה כזו.\p"
	.string "חשבתי שיום אחד תהפ{EMIT_VAV}{SWAP_CHAF}{ADD_YUD} להיות\n"
	.string "האלו{SWAP_PEY}{ADD_HEY}.\p"
	.string "הניחושים שלי בדרך כלל מתגשמים.\p"
	.string "ולאן תל{SWAP_CHAF}{ADD_YUD} מכאן?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "פופופו, אפילו אני לא יכול להגיד לך.$"

