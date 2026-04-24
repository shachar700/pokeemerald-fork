SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	bufferspeciesname STR_VAR_2, SPECIES_LOTAD
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	bufferspeciesname STR_VAR_1, SPECIES_SEEDOT
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	bufferspeciesname STR_VAR_2, SPECIES_SEEDOT
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	bufferspeciesname STR_VAR_1, SPECIES_LOTAD
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "האם את{EMIT_HEY} מכיר{ADD_HEY} את הפוקימון {STR_VAR_1}?\n"
	.string "בקושי רואים אותו בסוטופוליס.\p"
	.string "בכל מקרה, אני אוהב {STR_VAR_1} גדול.\n"
	.string "ככל שהוא גדול יותר, כך טוב יותר.\p"
	.string "אבל אחי הקטן, הוא אומר\n"
	.string "ש{STR_VAR_2} גדול יותר.\p"
	.string "זה מטופש.\n"
	.string "{STR_VAR_1} חייב להיות גדול מזה!\p"
	.string "הא? יש לך {STR_VAR_1} איתך?\n"
	.string "ב-ב-בבקשה, תרא{EMIT_HEY}{ADD_YUD} לי!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} מטרים!\n"
	.string "או, אלוהים, זה אחד גדול!\p"
	.string "הוא אולי אפילו מנצח את {STR_VAR_1} הגדול\n"
	.string "שאחי הקטן ראה!\p"
	.string "תודה שהראית לי.\n"
	.string "זו התודה שלי!$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "הא?\n"
	.string "התיק שלך מלא לגמריי.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} מטרים, זה מה שיש?\p"
	.string "הממ… ראיתי {STR_VAR_1} גדול יותר\n"
	.string "מזה.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "או, זה די משהו…\n"
	.string "אבל זה לא {STR_VAR_1}!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "אין לך {STR_VAR_1} גדול?\n"
	.string "חבל…\p"
	.string "אם את{EMIT_HEY} משיג{ADD_HEY} {STR_VAR_1} גדול, בבקשה\n"
	.string "בוא{ADD_YUD} להראות לי.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "ה{STR_VAR_1} הגדול ביותר בהיסטוריה!\n"
	.string "הענק של {STR_VAR_2} בגודל {STR_VAR_3} מטרים!\p"
	.string "{STR_VAR_1} גדול יותר מ{STR_VAR_1} השני\n"
	.string "תמיד מבוקש!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "האם אתה מכיר את הפוקימון {STR_VAR_1}?\n"
	.string "לעיתים רחוקות רואים אותו בסוטופוליס.\p"
	.string "אני אוהב, כלומר אוהב, {STR_VAR_1} גדול!\p"
	.string "אחי הגדול אומר ש{STR_VAR_2} גדול יותר.\p"
	.string "אבל זה לא נכון! כולם יודעים ש\n"
	.string "{STR_VAR_1} גדול בהרבה.\p"
	.string "הא? יש לך {STR_VAR_1}?\n"
	.string "ב-ב-בבקשה תרא{EMIT_HEY}{ADD_YUD} לי!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} מטרים!\n"
	.string "וואו, זה גדול!\p"
	.string "זה אולי אפילו גדול יותר מה{STR_VAR_1} העצום\n"
	.string "שאחי הגדול ראה.\p"
	.string "תודה שהראית לי!\n"
	.string "זו התודה שלי!$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "הא?\n"
	.string "התיק שלך מלא לגמרי.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} מטרים?\p"
	.string "הממ… ראיתי {STR_VAR_1} גדול יותר\n"
	.string "מזה כאן.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "טוב, זה משהו!\n"
	.string "אבל זה לא {STR_VAR_1}!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "אין לך {STR_VAR_1} גדול?\n"
	.string "כמה מאכזב…\p"
	.string "אם את{EMIT_HEY} משיג{ADD_HEY} {STR_VAR_1} גדול, בבקשה\n"
	.string "בוא{ADD_YUD} להראות לי.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "ה{STR_VAR_1} הגדול ביותר בהיסטוריה!\n"
	.string "הענק של {STR_VAR_2} בגודל {STR_VAR_3} מטרים!\p"
	.string "{STR_VAR_1} גדול יותר מ{STR_VAR_1} השני\n"
	.string "תמיד מבוקש!$"
