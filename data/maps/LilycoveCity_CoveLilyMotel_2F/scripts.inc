LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "אני מעצב המשחק.\p"
	.string "או, האם זה נכון?\n"
	.string "את{EMIT_HEY} עובד{ADD_TAF} על הפוקידע?\p"
	.string "זה קשה לנסות להשלים אותו,\n"
	.string "אבל אל תוותר{ADD_YUD}.\p"
	.string "אם תשלי{SWAP_MEM}{ADD_YUD} אותו, בבקשה בוא{ADD_YUD}\n"
	.string "להראות לי.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "ואו! זה מדהים!\n"
	.string "כן, זה מדהים לגמרי!\p"
	.string "הפוקידע הזה מלא לחלוטין!\n"
	.string "את{EMIT_HEY} בטח באמת אוהב{ADD_TAF} פוקימונים!\p"
	.string "אני כל כך מתרשם!\p"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לתת לך משהו כהכרה\n"
	.string "בהישגך!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "אני? את{EMIT_HEY} מדבר{ADD_TAF} אליי?\n"
	.string "אני המתכנת.\p"
	.string "אני תוהה איך נראים מכונות המזל\n"
	.string "כאן.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "אני הגרפיקאי! נכון שהפוקימונים\n"
	.string "של הואן מעניינים?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "הבעלות אבוב, הן חמודות, היי?\n"
	.string "להילחם נגד בעלת אבוב חמודה…\p"
	.string "וופ, זה כל כך מגניב!\p"
	.string "והתאומות! הן לא חמודות?\n"
	.string "קרב 2 נגד 2 עם תאומות…\p"
	.string "וופ, זה כיף בלתי נסבל!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "רוח הים מדגדגת את ליבי.\n"
	.string "זה מרגיש נפלא כאן!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "את{EMIT_HEY} אף פעם לא יודע{ADD_TAF} מתי והיכן\n"
	.string "אנשים יאתגרו אותך.\p"
	.string "זו הסיבה שאני אף פעם לא עוזב את הבית\n"
	.string "בלי מכשיר הגיים בוי אדוונס שלי.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "סקוט: … … … … …\n"
	.string "… … … … … זזז…\p"
	.string "… … … … … הא?!\n"
	.string "או, סליחה, סליחה! נמנמתי!\p"
	.string "באתי לבדוק את עניין\n"
	.string "תחרויות הפוקימונים.\p"
	.string "אני חייב להודות, זה נראה די\n"
	.string "מבדר, אבל…\p"
	.string "תחש{EMIT_VAV}ב{ADD_YUD} עליי כטהור--אני מעדיף\n"
	.string "קרבות ומאמנים קשוחים.\p"
	.string "אבל זה רק אני.\p"
	.string "{PLAYER}{KUN}, אני מקווה שתהנ{EMIT_HEY}{ADD_YUD} מכל דבר\n"
	.string "כמו מכוני המכון, התחרויות, אוהל הקרב,\l"
	.string "הכל!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "סקוט: אני חושב שכן נדרשת אסטרטגיה\n"
	.string "כדי לנצח בתחרות.\p"
	.string "גיבוש אסטרטגיות תחרות הוא דרך אחת\n"
	.string "להפוך למאמן טוב יותר, הייתי אומר.$"

