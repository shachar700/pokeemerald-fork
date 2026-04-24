MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "הי, אני הסוחר.\n"
	.string "רוצה להחליף קישוטים איתי?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "או…\n"
	.string "השארת אותי מדוכדך…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "אבל החלפנו קישוטים כבר,\n"
	.string "אני ואת{EMIT_HEY}.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "אם תרא{EMIT_HEY}{ADD_YUD} פריט קישוט שלי\n"
	.string "שתרצ{EMIT_HEY}{ADD_YUD}, תגיד{ADD_YUD}.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "את{EMIT_HEY} לא רוצה כלום?\n"
	.string "אני מרגיש לא רצוי…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "הפריט קישוט הזה היה שייך פעם\n"
	.string "ל{STR_VAR_1}.\p"
	.string "את{EMIT_HEY} רוצה אותו?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "אה… חכ{EMIT_HEY}{ADD_YUD} שנייה. אין לך\n"
	.string "אף פריט קישוט!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "אוקיי, בחר{ADD_YUD} את הקישוט\n"
	.string "שתחלי{SWAP_PEY}{ADD_YUD} איתי.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "את{EMIT_HEY} לא תחלי{SWAP_PEY}{ADD_YUD} איתי?\n"
	.string "אני מרגיש לא רצוי…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "יש לך את כל ה{STR_VAR_2}ים שניתן\n"
	.string "לאחסן. אין לך מקום לזה.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "אוקיי, אז נחליף את ה{STR_VAR_3}\n"
	.string "שלי עבור ה{STR_VAR_2} שלך?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "הפריט קישוט הזה בשימוש.\n"
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} להחליף אותו.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "אז נחליף!\n"
	.string "אני אשלח את הקישוט שלי למחשב שלך.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "אופס! סליחה! זה ממש פריט\n"
	.string "קישוט נדיר.\l"
	.string "אני לא יכול להחליף אותו!\p"
	.string "את{EMIT_HEY} מעוניי{SWAP_NUN}{ADD_TAF} במשהו אחר?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "אני המספר.\n"
	.string "אני אספר לך על מאמנים\l"
	.string "אגדיים.\p"
	.string "האם תשמע{ADD_YUD} את סיפורי?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "או…\n"
	.string "השארת אותי מדוכדך…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "אני מכיר את האגדות האלו.\n"
	.string "איזה סיפור תרצ{EMIT_HEY}{ADD_YUD} שאספר?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "אבל איני מכיר מאמנים אגדיים.\n"
	.string "לפיכך אין לי סיפורים לספר.\p"
	.string "איפה אפשר למצוא מאמן הראוי\n"
	.string "לסיפור אגדי?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "מה זה?!\n"
	.string "את{EMIT_HEY}… את{EMIT_HEY}…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} פעם)ים(?!\p"
	.string "זה באמת נפלא!\n"
	.string "זאת לידתה של אגדה חדשה!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "זה גורם לי לחשוב, האם ישנם\n"
	.string "מאמנים אחרים עם אגדות מרשימות\l"
	.string "שמחכות להתגלות?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "האם את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}?\p"
	.string "אם כך אמ{EMIT_VAV}ר{ADD_YUD} לי - האם יש לך סיפורים\n"
	.string "שהם ולו במקצת אגדיים?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "אגב… האם תרצ{EMIT_HEY}{ADD_YUD} לשמוע\n"
	.string "עוד סיפור אגדי?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "הממ…\n"
	.string "אני לא מרוצה…\p"
	.string "הלוואי שתביא{ADD_YUD} לי חדשות שראויות\n"  
	.string "להיקרא אגדה.$"  

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "הלוואי שיותר אנשים היו מתעניינים\n"  
	.string "לשמוע את סיפוריי האפיים על\n"  
	.string "מאמני פוקימון אגדים.$"  

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "המאמן ששומר בלי סוף$"  

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "שמר את המשחק$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::  
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה שמר את המשחק\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "מאמן זהיר יותר מ{STR_VAR_3}\n"  
	.string "אי אפשר למצוא!$"  

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::  
	.string "המאמן קובע הטרנדים$"  

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::  
	.string "התחיל טרנדים$"  

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::  
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה התחיל טרנדים חדשים\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} קובע טרנדים לכל\n"  
	.string "אזור הואן!$"  

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "המאמן ששותל פירות$"  

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "שתל פירות$"  

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה שתל פירות\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} הוא אוהב אגדי של\n"  
	.string "פירות!$"  

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "המאמן שחובב אופניים$"  

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "החליף אופניים$"  

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה החליף אופניים\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} בטח אוהב אופניים\n"  
	.string "בכל ליבו ונפשו!$"  

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "המאמן המתראיין$"  

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "השתתף בראיון$"  

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה השתתף בראיונות\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} הוא מאמן שמושך\n"  
	.string "תשומת לב רבה!$"  

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "המאמן שחובב קרבות$" 

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "בקרב$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה היה בקרב {STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} הוא מאמן שאף פעם\n"  
	.string "לא מפספס הזדמנות לקרב!$"  

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "המאמן שתופס פוקימונים$"  

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "תפס פוקימונים$"  

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה תפס\n"  
	.string "{STR_VAR_1} פוקימונים!\p"  
	.string "{STR_VAR_3} הוא תופס אגדי של\n"  
	.string "פוקימונים פראיים!$"  

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "המאמן הדייג$"  

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "תפס פוקימונים עם חכה$"  

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה תפס\n"  
	.string "{STR_VAR_1} פוקימונים בזמן דיג!\p"  
	.string "{STR_VAR_3} הוא מומחה דיג אגדי!$"  

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "המאמן שמחמם ביצים$"  

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "בקע ביצים$" 

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה בקע {STR_VAR_1} פוקימונים\n"  
	.string "מתוך ביצים!\p"  
	.string "{STR_VAR_3} הוא מחמם אגדי\n"  
	.string "של ביצים!$"  

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "המאמן שמפתח פוקימונים$"  

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "פיתח פוקימונים$"  

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה גרם ל-{STR_VAR_1} פוקימונים\n"  
	.string "להתפתח!\p"  
	.string "{STR_VAR_3} הוא מפתח הפוקימונים\n"  
	.string "העליון!$"  

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "המאמן שאוהב מרכזי פוקימונים$" 

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "השתמש במרכזי פוקימונים$" 

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה ריפא פוקימונים\n"  
	.string "{STR_VAR_1} פעמים במרכזי פוקימונים!\p"  
	.string "אין אוהב גדול יותר של מרכזי\n"  
	.string "פוקימונים מאשר {STR_VAR_3}!$"  

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "המאמן הביתי$"  

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "הניח לפוקימונים לנוח בבית$"  

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה ריפא את הפוקימונים שלו\n"  
	.string "{STR_VAR_1} פעמים בבית!\p"  
	.string "אין מאמן ביתי יותר\n"  
	.string "מ{STR_VAR_3}!$"  

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "המאמן שחובב ספארי$"  

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "נכנס לאזור הספארי$"  

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה ביקר באזור הספארי\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} הוא מאמן שהצד הפראי שלו\n"  
	.string "מתעורר בספארי!$"  

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "המאמן שחותך בטירוף$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "השתמש בחיתוך$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "זהו סיפור על מאמן\n"
	.string "בשם {STR_VAR_3}.\p"
	.string "המאמן הזה השתמש בחיתוך\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} חייב מאמן שפשוט\n"
	.string "אוהב לחתוך!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "המאמן מרסק האבנים$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "ריסק אבנים$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "זהו סיפור על מאמן\n"
	.string "בשם {STR_VAR_3}.\p"
	.string "המאמן הזה השתמש בריסוק אבנים\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} חייב להיות מאמן\n"
	.string "שלא משאיר אבן לא מרוסקת!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "המאמן שאוהב לעבור$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "העביר את הבסיס הסודי$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה העביר את הבסיס הסודי\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} אוהב להעביר\n"
	.string "בתים לעיתים תכופות!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "המאמן שאוהב להשתכשך$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "השתמש בשכשוך$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה השתמש בשכשוך\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} הוא מאמן שחייב לאהוב\n"
	.string "להשתכשך ולשחק במים!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "המאמן העיקש$"  

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "נאלץ להשתמש במאבק$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p" 
	.string "המאמן הזה נאלץ להסתמך על מאבק\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} הוא מאמן עקשן\n"
	.string "שאף פעם לא מוותר במצוקה!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "אלוף המכונת מזל$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "זכה בפרס הגדול במכונות$"  

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה זכה בפרס הגדול במכונות\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} הוא מאמן בר מזל\n"
	.string "במכונות!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "אלוף הרולטה$"  

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "זכה ברולטה ברצף$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה ניצח ברולטה\n"  
	.string "{STR_VAR_1} פעמים ברצף!\p"  
	.string "{STR_VAR_3} היה בר מזל כשהכדור\n"  
	.string "ניתר ברולטה!$"  

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "המאמן שמאתגר את מגדל הקרב$"  

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "לקח חלק באתגר מגדל הקרב$"  

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה לקח חלק באתגר מגדל\n"
	.string "הקרב {STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} הוא מאמן ששואף\n"
	.string "למצוינות במגדל הקרב!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "המאמן שאוהב לערבב$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "הכין פוקיגושים$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה הכין פוקיגושים\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "אין כמו {STR_VAR_3} בשימוש בבלנדר\n"
	.string "פירות יער!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "המאמן שאוהב תחרויות$"  

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "השתתף בתחרויות$"  

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה נכנס לתחרויות\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} בטח אוהב להראות\n"  
	.string "את הפוקימונים שלו לאחרים!$"  

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "מאסטר התחרויות$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "ניצח בתחרויות$"  

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה ניצח בתחרויות\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} הוא מאסטר תחרויות\n"  
	.string "מדהים!$"  

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "הקונה השמח$"  

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "קנה$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה קנה פריטים בחנויות\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} בטח אחד מהאלה\n"
	.string "שנולדו לקנות.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "המאמן שמוצא פריטים$"  

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "השתמש במאתר פריט$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה השתמש במאתר פריט\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} נהנה לסרוק את האדמה\n"  
	.string "ולמצוא פריטים חבויים!$"  

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "המאמן הספוג מהגשם$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "נרטב$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה נספג בגשם\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "הכריזמה של {STR_VAR_3} בטח\n"
	.string "מושכת גשם!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "חובב קריאת הפוקידע$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "בדק את הפוקידע$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה בדק את הפוקידע\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} בטח אוהב לבדוק\n"
	.string "פוקימונים בפוקידע!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "אוסף הסרטים$"  

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "קיבל סרטים$"  

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה קיבל סרטים\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} בטח אוהב לאסוף\n"  
	.string "סרטים!$"  

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "המאמן שקפץ מהקצה$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "קפץ למטה מהקצה$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה קפץ למטה מהקצה\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "אם יש קצה לקפוץ ממנו,\n"
	.string "{STR_VAR_3} לא יכול להתעלם!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "צופה הטלוויזיה האגדי$"  

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "צפה בטלוויזיה$" 

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה צפה בטלוויזיה\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} בטח אוהב לצפות בטלוויזיה!$"  

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "המאמן שקשוב לזמן$"  

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "בדק את השעה$" 

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה בדק את השעה\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} הוא מאמן דייקן\n"  
	.string "שהוא מודע לזמן.$"  

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "קוסם לוטו הפוקימון$"  

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "זכה בלוטו הפוקימון$"  

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה זכה בלוטו הפוקימון\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} בטח עם הרבה חברים\n"
	.string "להחליף איתם פוקימונים!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "המאמן שמשתמש במעון$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "השאיר פוקימונים במעון$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה השאיר פוקימונים במעון\n"  
	.string "{STR_VAR_1} פעמים!\p"  
	.string "{STR_VAR_3} בטח דוחף קדימה\n"
	.string "לגידול פוקימונים באגרסיביות!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "המאמן שאוהב רכבלים$"  

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "רכב ברכבל$"  

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p" 
	.string "המאמן הזה רכב ברכבל\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} בטח מאמן עסוק\n"
	.string "שעולה ויורד כל הזמן!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "המאמן שאוהב מעיינות חמים$" 

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "התרחץ במעיינות חמים$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "זהו סיפור על מאמן\n"  
	.string "בשם {STR_VAR_3}.\p"  
	.string "המאמן הזה התרחץ במעיינות חמים\n"
	.string "{STR_VAR_1} פעמים!\p"
	.string "{STR_VAR_3} בטח מאמן עם עור\n"
	.string "חלק כמו תינוק!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "אני גידי!\n"
	.string "יש לי סיפור נוצץ בשבילך!\p"
	.string "רוצה לשמוע את הסיפור שלי?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "או…\n"
	.string "השארת אותי מדוכדך…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "בנוסף, אני חשבתי…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "זה הכל, אני חושב…\p"
	.string "אנחנו צריכים לשוחח שוב!\n"
	.string "ביי-ביי!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "הי, אני המשורר.\n"
	.string "רוצה לשמוע את השיר שלי?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "או…\n"
	.string "השארת אותי מדוכדך…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "או, איזו מנגינה מרגשת…\n"
	.string "הלוואי שיכולתי לנגן אותה לאחרים…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "אז?\n"
	.string "מה דעתך על השיר שלי?\p"
	.string "אבל אני לא ממש מרוצה\n"
	.string "מהמילים שלו.\p"
	.string "רוצה לכתוב כמה מילים חדשות\n"
	.string "בשבילי?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "או…\n"
	.string "השארת אותי מדוכדך…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "תודה רבה לך!\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לשיר אותו בשבילך.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "האם ככה רצית שהשיר שלך\n"
	.string "ישמע?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "אוקיי! זהו זה, אז.\n"
	.string "אני אשיר את השיר הזה לזמן מה.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "היי, ין! קוראים לי ההיפסטר.\n"
	.string "אלמד אותך מה חם ומגניב עכשיו.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "אבל, החח, כבר לימדתי אותך מה חם\n"
	.string "ומגניב עכשיו.\p"
	.string "אני רוצה להפיץ את הבשורה גם\n"  
	.string "לאנשים אחרים.$"  

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "אבל, היי, את{EMIT_HEY} כבר יודע{ADD_TAF} הרבה על\n"  
	.string "מה שחם ומגניב.\p"  
	.string "אין לי שום דבר חדש ללמד אותך!$"  

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "היי, שמעת על\n"
	.string "”{STR_VAR_1}“?\p"
	.string "מה המשמעות? ובכן…\n"
	.string "תשאל{ADD_YUD} את אבא או אמא שלך, אוקיי?$"
