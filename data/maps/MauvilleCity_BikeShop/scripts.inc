MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "טוב, טוב, מה יש לנו כאן?\n"
	.string "לקו{ADD_HEY} מלא{ADD_TAF} אנרגיה!\p"
	.string "אני? את{EMIT_HEY} יכול{ADD_HEY} לקרוא לי ריידל.\n"
	.string "אני הבעלים של חנות האופניים הזו.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "ריידל: נעלי הריצה שלך…\n"
	.string "הן כל כך מלוכלכות.\p"
	.string "האם באת מרחוק?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "ריידל: האם זה נכון?\p"
	.string "אם כן, אני מניח שאין לך צורך\n"
	.string "באף אחד מהאופניים שלי.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "ריידל: המ, המ… … … … …\p"
	.string "את{EMIT_HEY} אומר{ADD_TAF} שהגעת כל הדרך\n"
	.string "מליטלרוט?\p"
	.string "אלוהים אדירים!\n"
	.string "זה רחוק בצורה מגוחכת!\p"
	.string "אם היו לך האופניים שלי, היית יכול{ADD_HEY}\n"
	.string "לרכב לכל מקום בקלות תוך כדי שאת{EMIT_HEY} מרגיש את\l"
	.string "הליטוף העדין של הרוח!\p"
	.string "אני אגלה לך משהו!\n"
	.string "אני אתן לך אופניים!\p"
	.string "או, חכ{EMIT_HEY}{ADD_YUD} רגע!\p"
	.string "שכחתי לומר לך שיש\n"
	.string "שני סוגי אופניים!\p"
	.string "הם אופני מאך ואופני אקרו!\p"
	.string "אופני המאך מיועדים לרוכבים שרוצים\n"
	.string "להרגיש את הרוח עם גופם!\p"
	.string "ואופני אקרו מיועדים לאלה\n"
	.string "שמעדיפים רכיבה טכנית!\p"
	.string "אני אדם ממש מתוק, אז את{EMIT_HEY} יכול{ADD_HEY}\n"
	.string "לקבל את מה שאת{EMIT_HEY} אוהב{ADD_TAF}!\p"
	.string "באיזה מהם תבחר{ADD_YUD}?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} בחר{ADD_HEY} באופני מאך.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} בחר{ADD_HEY} באופני אקרו.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "ריידל: אם יתחשק לך להחליף\n"
	.string "אופניים, פשוט תבוא{ADD_YUD} לבקר אותי!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "ריידל: או? חשבת על להחליף\n"
	.string "אופניים?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "ריידל: בסדר, אין בעיה!\n"
	.string "אני אחליף לך את האופניים!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} החלי{SWAP_PEY}{ADD_HEY} את אופני המאך\n"
	.string "באופני אקרו.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} החלי{SWAP_PEY}{ADD_HEY} את אופני האקרו\n"
	.string "באופני מאך.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "ריידל: טוב, טוב!\n"
	.string "אני שמח שאת{EMIT_HEY} אוהב{ADD_TAF} את זה!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "או? מה קרה לאופניים האלה\n"
	.string "שנתתי לך?\p"
	.string "או, הבנתי, את{EMIT_HEY} אחסנת אותם בעזרת המחשב שלך.\p"
	.string "טוב, הוצ{ADD_YUD}א{ADD_YUD} אותם מאחסון המחשב,\n"
	.string "ואשמח להחליף אותם!\p"
	.string "מי ייתן והרוח תמיד תהיה בגבך\n"
	.string "בהרפתקה שלך!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "אני לומד על אופניים בזמן\n"
	.string "שאני עובד כאן.\p"
	.string "אם את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} עצה איך לרכב על\n"
	.string "האופניים שלך, יש כמה חוברות הדרכה\l"
	.string "מאחור.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "זו חוברת הדרכה על אופני המאך.\p"
	.string "איזה עמוד את{EMIT_HEY} רוצה לקרוא?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "האופניים נעים בכיוון שאליו\n"
	.string "לוח הבקרה נלחץ.\p"
	.string "הם יאיצו ברגע שהם יתחילו לנוע.\p"
	.string "כדי לעצור, שחררו את לוח הבקרה.\n"
	.string "האופניים יאטו עד לעצירה.\p"
	.string "רוצה לקרוא עמוד אחר?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "אופני מאך מהירים, אבל הם לא יכולים\n"
	.string "לעצור במהירות רבה.\p"
	.string "זה נהיה קצת מסובך לעבור\n"
	.string "פינות.\p"
	.string "שחררו את לוח הבקרה קצת\n"
	.string "לפני הפינה והאטו.\p"
	.string "רוצה לקרוא עמוד אחר?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "יש מדרונות חוליים קטנים\n"
	.string "ברחבי מחוז הון.\p"
	.string "החול הרופף והמתפורר גורם\n"
	.string "לטיפוס רגיל להיות בלתי אפשרי.\p"
	.string "אבל אם יש לכם אופני מאך, תוכלו\n"
	.string "לטוס במעלה מדרון חולי.\p"
	.string "רוצה לקרוא עמוד אחר?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "זו חוברת הדרכה על אופני האקרו.\p"
	.string "איזה עמוד את{EMIT_HEY} רוצה לקרוא?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "לחצו על כפתור B בזמן שאתם רוכבים,\n"
	.string "והגלגל הקדמי מתרומם.\p"
	.string "אתם יכולים לטוס מסביב כשהגלגל\n"
	.string "הקדמי למעלה באמצעות לוח הבקרה.\p"
	.string "הטכניקה הזו נקראת עמידת גלגל.\p"
	.string "רוצה לקרוא עמוד אחר?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "אם תמשיכו ללחוץ על כפתור B,\n"
	.string "האופניים שלכם יכולים לקפוץ במקום.\p"
	.string "הטכניקה הזו נקראת קפיצת ארנב.\p"
	.string "אתם יכולים גם לרכוב תוך כדי קפיצה.\p"
	.string "רוצה לקרוא עמוד אחר?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "לחצו על כפתור B ועל לוח הבקרה\n"
	.string "במקביל כדי לקפוץ.\p"
	.string "לחצו על לוח הבקרה לצד\n"
	.string "כדי לקפוץ הצידה.\p"
	.string "לחצו לאחור כדי לגרום לאופניים\n"
	.string "להחליף כיוון תוך כדי קפיצה.\p"
	.string "רוצה לקרוא עמוד אחר?$"

