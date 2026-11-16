MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applywaitmovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	applywaitmovement VAR_LAST_TALKED, Common_Movement_Delay48
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "אם היה לי אופניים, היה קל לדווש\n"
	.string "לסלייטפורט בשביל קצת קניות.\p"
	.string "הייתי יכול לקנות מכתב נמל\n"
	.string "בפוקימון מרט שבסלייטפורט…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "אה! יש לך מכתב נמל?\n"
	.string "תרצ{EMIT_HEY}{ADD_YUD} להחליף אותו בתיבת מטבעות?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "אוי, אני כל כך שמח!\n"
	.string "בסדר, אני אתן לך תיבת מטבעות!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "אפשר להשתמש בתיבת המטבעות\n"
	.string "בפינת המשחקים.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "אוי, זה מאכזב.\p"
	.string "צריך תיבת מטבעות בשביל\n"
	.string "פינת המשחקים.$"

