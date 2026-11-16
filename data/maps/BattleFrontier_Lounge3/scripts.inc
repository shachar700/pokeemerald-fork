BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…מה את{EMIT_HEY} רוצה?\p"
	.string "את{EMIT_HEY} לא רואה שאנחנו קצת עסוקים כאן?\n"
	.string "העניין של{SWAP_CHAF}{ADD_YUD} לא יכול לחכות לאחר כך?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…הא?\n"
	.string "את{EMIT_HEY} נראה לי כמו מאמ{SWAP_NUN}{ADD_TAF} קשוח{ADD_HEY}.\p"
	.string "היהיה…\n"
	.string "תקשיב{ADD_YUD}, יש לי הצעה כזו.\p"
	.string "יש לנו קבוצה קטנה כאן,\n"
	.string "ואנחנו משחקים משחק קטן עם מה\l"
	.string "שקורה בחזית הקרב.\p"
	.string "הכללים ממש פשוטים.\p"
	.string "קודם, אנחנו בוחרים מתקן אחד\n"
	.string "בחזית הקרב.\p"
	.string "אז, כל אחד מאיתנו בוחר מאמן אחר\n"
	.string "שמשתתף באתגר של אותו מתקן,\l"
	.string "ומהמרים עם נקודות הקרב שלנו.\p"
	.string "הבחור שהימר על המאמן עם\n"
	.string "השיא הטוב ביותר לוקח את כל נקודות\l"
	.string "הקרב בקופה.\p"
	.string "נשמע פשוט, הא?\n"
	.string "אז, בכל מקרה…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} לאתגר את חדרי קרב היחידים\l"
	.string "במגדל הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} לאתגר את חדרי קרב הזוגות\l"
	.string "במגדל הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} לאתגר את חדרי קרב המרובי משתתפים\l"
	.string "במגדל הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} להיכנס לטורניר קרב היחידים\l"
	.string "בכיפת הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} להיכנס לטורניר קרב הזוגות\l"
	.string "בכיפת הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} להיכנס לטורניר החלפת קרב יחידים\l"
	.string "במפעל הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} להיכנס לטורניר החלפת קרב זוגות\l"
	.string "במפעל הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} לאתגר את אולמות קרב היחידים\l"
	.string "בארמון הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} לאתגר את אולמות קרב הזוגות\l"
	.string "בארמון הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} להיכנס לטורניר נוקאאוט קבוע\l"
	.string "בזירת הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} להיכנס לבחירת הקרב\l"
	.string "של נהר הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "מה שאני מחפש זה מאמן\n"
	.string "שהול{SWAP_CHAF}{ADD_YUD} להיכנס למסע הקרב\l"
	.string "של פירמידת הקרב.\p"
	.string "אבל עד כה, לא ראיתי מאמן\n"
	.string "שיש לו את האיכות המנצחת הזאת.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "אני אדאג לכך שגם את{EMIT_HEY} תרוויח{ADD_YUD}.\n"
	.string "אז מה דעתך?\l"
	.string "מה דעתך להיכנס לאירוע הזה בשבילי?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "בסדר גמור, זה מושלם.\n"
	.string "אז, אה… מה דעתך ללוות לי כמה\l"
	.string "מנקודות הקרב שלך?\p"
	.string "תאמי{SWAP_NUN}{ADD_YUD} לי, אני אראה לך את הכרת התודה שלי\n"
	.string "לאחר מכן.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "נהדר, נהדר!\n"
	.string "אז, כמה את{EMIT_HEY} יכול{ADD_HEY} להלוות לי?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "או, לא, לא, לא!\n"
	.string "אין לך מספיק נקודות קרב!\p"
	.string "הלוואי שלא היית מתעסק{ADD_TAF} בשטויות ומבזבז{ADD_TAF}\n"
	.string "את זמנם של כולם!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "היהיה! תודה רבה!\n"
	.string "אז, קדימה, ל{SWAP_CHAF}{ADD_YUD}!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "ל{SWAP_CHAF}{ADD_YUD} לחדרי קרב היחידים\n"
	.string "במגדל הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD} את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "ל{SWAP_CHAF}{ADD_YUD} לחדרי קרב הזוגות\n"
	.string "במגדל הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD} את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "ל{SWAP_CHAF}{ADD_YUD} לחדרי קרב המרובים\n"
	.string "במגדל הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "ל{SWAP_CHAF}{ADD_YUD} לטורניר קרב היחידים\n"
	.string "בכיפת הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "ל{SWAP_CHAF}{ADD_YUD} לטורניר קרב הזוגות\n"
	.string "בכיפת הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "ל{SWAP_CHAF}{ADD_YUD} לטורניר החלפת קרב יחידים\n"
	.string "במפעל הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "ל{SWAP_CHAF}{ADD_YUD} לטורניר החלפת קרב זוגות\n"
	.string "במפעל לקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "ל{SWAP_CHAF}{ADD_YUD} לאולמות קרב היחידים\n"
	.string "בארמון הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "ל{SWAP_CHAF}{ADD_YUD} לאולמות קרב הזוגות\n"
	.string "בארמון הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "ל{SWAP_CHAF}{ADD_YUD} לטורניר KO קבוע\n"
	.string "בזירת הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "ל{SWAP_CHAF}{ADD_YUD} לבחירת הקרב\n"
	.string "של נהר הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "ל{SWAP_CHAF}{ADD_YUD} למסע הקרב\n"
	.string "של פירמידת הקרב מהר!\p"
	.string "זה מצב של חובה לנצח!\n"
	.string "אל תבזבז{ADD_YUD}את ההזדמנות שלך!\l"
	.string "העתיד של שנינו תלוי בך!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "הו, זה את{EMIT_HEY}…\n"
	.string "ניסיון יפה…\p"
	.string "אני שונא לבשר לך, אבל אני לא יכול\n"
	.string "להחזיר לך את נקודות הקרב…\p"
	.string "אני מניח שנצטרך לתת לזה לדרבן\n"
	.string "אותנו לנסות חזק יותר בפעם הבאה!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "או, כן!\n"
	.string "שלום לך, אלו{SWAP_PEY}{ADD_HEY}!\p"
	.string "אני ידעתי שאת{EMIT_HEY} יכול{ADD_HEY}!\n"
	.string "אני ידעתי שתעש{EMIT_HEY}{ADD_YUD} את זה!\l"
	.string "שנינו מנצחים גדולים!\p"
	.string "אני אחזיר לך את נקודות הקרב,\n"
	.string "וכמובן, קצת תוספת ממני!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} קיבל{ADD_HEY}\n"
	.string "{STR_VAR_1} נקודות קרב.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "אם את{EMIT_HEY} מוכ{SWAP_NUN}{ADD_HEY} לאתגר נוסף,\n"
	.string "בבקשה תחש{EMIT_VAV}ב{ADD_YUD} עליי!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "לא מעוניי{SWAP_NUN}{ADD_TAF}?! את{EMIT_HEY} לא צרי{SWAP_CHAF}{ADD_HEY} להיות\n"
	.string "כל כך לפחד לקחת סיכון!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "או…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "אני הימרתי על המאמן הלא נכון שוב!\p"
	.string "אולי אני צריך להילחם באופן רגיל\n"
	.string "כמו כולם…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "המאמן ההוא…\p"
	.string "הוא טוב, אבל הוא נבהל יותר מדי\n"
	.string "בקלות כדי לשרוד את כיפת הקרב…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "צחקוק!\n"
	.string "אני יודע לזהות מנצח כשאני רואה אותו!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "המאמנים האלה…\n"
	.string "מה הם עושים?\l"
	.string "הם צריכים לקחת אתגרים.$"
