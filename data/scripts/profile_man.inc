ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "שלום לך, מאמ{SWAP_NUN}{ADD_TAF}!\n"
	.string "יש לך חיוך נפלא.\p"
	.string "יש לי תחביב--לאסוף פרופילים\n"
	.string "של מאמני פוקימון.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "אז, מה דעתך?\n"
	.string "אפשר לראות את הפרופיל שלך?$"

ProfileMan_Text_EasyChatExplanation:
	.string "את{EMIT_HEY} יוצר{ADD_TAF} פרופיל משלך על ידי חיבור\n"
	.string "של ארבע מילים או ביטויים.\p"
	.string "הנה, אני אראה לך דוגמה לפרופיל\n"
	.string "שמשתמש בארבעה קטעי טקסט.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY} להחליף את ארבעת הקטעים\n"
	.string "בקטעי טקסט אחרים איך שרק תרצ{EMIT_HEY}{ADD_YUD}\l"
	.string "כדי ליצור פרופיל משלך.\p"
	.string "ישנם קטעי טקסט רבים שבהם תוכל{ADD_YUD}\n"
	.string "להשתמש.\p"
	.string "הם מסודרים בקבוצות כמו\n"
	.string "פוקימון, סגנונות חיים, ותחביבים\l"
	.string "אז זה מקל יותר בלחפש אותם.\p"
	.string "אז, תחילה, בחר{ADD_YUD} קבוצת קטעי טקסט\n"
	.string "להצגת רשימת האפשרויות.\p"
	.string "ואז, בחר{ADD_YUD} את האפשרות שאת{EMIT_HEY} רוצה.\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} על הפעולה עבור שאר בחירות,\n"
	.string "הטקסט, ויהיה לך פרופיל משלך.$"

ProfileMan_Text_LetsSeeItThen:
	.string "כן! תודה לך!\n"
	.string "בוא{ADD_YUD} נראה אותו, אז.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "אוי, לא, באמת?\p"
	.string "דמיינתי שלמישהו כמוך יהיה\n"
	.string "פרופיל נפלא…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "או? את{EMIT_HEY} לא בעניין כרגע?\p"
	.string "טוב, מבחינתי כל זמן זה בסדר!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "שלום לך, מאמ{SWAP_NUN}{ADD_TAF}!\n"
	.string "יש לך חיוך נפלא.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "אפשר לראות את הפרופיל החדש שלך?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "כן! תודה לך!\p"
	.string "אני מקווה שהוא אפילו טוב יותר\n"
	.string "מהפרופיל שהראית לי קודם.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "או, את{EMIT_HEY} אוהב{ADD_TAF} את הפרופיל שלך כמו שהוא.\p"
	.string "אני לא מאשים אותך--זה פרופיל\n"
	.string "נפלא כמו שהוא עכשיו.$"

ProfileMan_Text_FantasticProfile:
	.string "פ-פנטסטי!\p"
	.string "הפרופיל שלך, הוא נפלא!\n"
	.string "הוא באמת אומר מי את{EMIT_HEY}.\p"
	.string "למה, כל מי שישמע את הפרופיל הזה\n"
	.string "יהיה שבוי בקסמך!\p"
	.string "תודה לך!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "מה?\n"
	.string "את{EMIT_HEY} מכיר{ADD_HEY} את המשפט הסודי!\p"
	.string "זה אומר שעכשיו את{EMIT_HEY} חבר{ADD_HEY}\n"
	.string "במועדון האירוע המסתורי!$"
