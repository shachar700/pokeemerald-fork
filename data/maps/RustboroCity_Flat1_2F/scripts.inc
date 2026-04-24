RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "או, זה כל כך קשה כל יום…\p"
	.string "מה קשה?\n"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לשאול?\p"
	.string "זה לנסות להחליט מה\n"
	.string "להכין לארוחות כל יום.\p"
	.string "באמת לא קל להמציא\n"
	.string "ארוחות כל יום.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "או, שלום!\n"
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לבית משפחת פפר.\p"
	.string "יש לי שאלה בשבילך.\n"
	.string "האם אי פעם שמרת על תינוק?\p"
	.string "את{EMIT_HEY} מבי{SWAP_NUN}{ADD_HEY}, אני אב חדש, אז גידול\n"
	.string "ילד זה חדש לי לגמרי.\p"
	.string "ויש לי בעיה. הבת שלי\n"
	.string "וולדה לא צוחקת מספיק.\p"
	.string "אני חושב שהיא תצחק אם אגיד לה\n"
	.string "משהו מצחיק.\p"
	.string "את{EMIT_HEY} מכיר{ADD_HEY} מילה מצחיקה או\n"
	.string "ביטוי שתוכל{ADD_YUD} להגיד לי?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "אמרתי לאחרונה ”{STR_VAR_1}“\n"
	.string "כדי לשעשעש אותה.\p"
	.string "את{EMIT_HEY} מכיר{ADD_HEY} מילה או\n"
	.string "ביטוי שעלול לעבוד?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "או, זה נהדר.\n"
	.string "אז, בוא{ADD_YUD} נשמע, את ההצעה שלך.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "או, זה נכון?\p"
	.string "ובכן, אם תמצא{ADD_YUD} הצעה טובה,\n"
	.string "כולי אוזן.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "אה, הבנתי.\n"
	.string "ובכן, בוא{ADD_YUD} ננסה, כן?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "או, כן! היא צוחקת!\n"
	.string "או, אני שמח בדיוק כמוה!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "אה, הבנתי.\n"
	.string "ובכן, בוא{ADD_YUD} ננסה, כן?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "המממ… היא לא מחייכת בכלל.\n"
	.string "אולי וולדה היא ילדה רצינית…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "או, אז את{EMIT_HEY} לא מכיר{ADD_HEY} מילים טובות.\n"
	.string "כדאי שאחשוב בעצמי, אז.\p"
	.string "הממ…\n"
	.string "מה לגבי “{STR_VAR_1}”?\l"
	.string "בוא{ADD_YUD} נראה אם זה יעבוד.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "המממ… היא לא מחייכת בכלל.\n"
	.string "אולי וולדה היא ילדה רצינית…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "או, אז את{EMIT_HEY} לא מכיר{ADD_HEY} מילים טובות.\n"
	.string "אני מניח שאנסה לשעשע אותה עם\l"
	.string "האמרה שאמרתי לפניכן.\p"
	.string "בכל מקרה, אם יש לך הצעה טובה,\n"
	.string "אל תהסס{ADD_YUD} לומר לי, כן?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "תודה לך!\p"
	.string "בזכותך, וולדה היקרה שלי\n"
	.string "צחקה בשבילי!\p"
	.string "האמתי, אני אולי לא נראה כל כך\n"
	.string "מיוחד, אבל אני חוקר מתאגיד דבון,\l"
	.string "אחד מהחוקרים המובילים.\p"
	.string "אז, מה דעתך שאעשה משהו בתמורה\n"
	.string "בשבילך?\p"
	.string "אני יודע, אני אוסיף כמה דפוסי טפט חדשים\n"
	.string "לקופסאות במחשב\l"
	.string "מערכת אחסון פוקימון.\p"
	.string "בתפריט הדפסי טפט,\n"
	.string "בחר{ADD_YUD} ”חברים.“\p"
	.string "זה ייתן לך גישה לדפוסי\n"
	.string "טפט חדשים.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "זוהי בובת קטיפה של פוקימון!$"

