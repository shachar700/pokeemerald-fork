SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "הי, הי! אני המעריך שמות!\n"
	.string "אני המגיד עתידות של השמות!\p"
	.string "אשמח לדרג את הכינוי של\n"
	.string "הפוקימון שלך.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "איזה כינוי פוקימון עליי\n"
	.string "לבקר?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "המממ… {STR_VAR_1}, נכון? זהו\n"
	.string "שם יפה מאוד שבחרת.\p"
	.string "אבל! מה דעתך אם אציע שם\n"
	.string "קצת יותר טוב?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "אה, טוב. אז, מה יהיה\n"
	.string "הכינוי החדש?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "זהו! מעכשיו, הפוקימון הזה\n"
	.string "יקרא {STR_VAR_1}!\p"
	.string "זהו שם טוב יותר מקודמו!\n"
	.string "איזה מזל יש לך!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "הבנתי.\n"
	.string "אנא בוא{ADD_YUD} לבקר שוב.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "זהו! מעכשיו, הפוקימון הזה\n"
	.string "יקרא {STR_VAR_1}!\p"
	.string "נראה שאין שינוי מקודמו,\n"
	.string "ובכל זאת, זהו שם נשגב בהרבה!\p"
	.string "איזה מזל יש לך!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "המממ… {STR_VAR_1} אם כן!\p"
	.string "זהו כינוי מרהיב!\n"
	.string "זה מעבר לכל דופי!\p"
	.string "כדאי לך לטפח את {STR_VAR_1}\n"
	.string "מעתה והלאה.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "נו, באמת.\n"
	.string "זה רק ביצה!$"

