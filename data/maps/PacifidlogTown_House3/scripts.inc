PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	bufferspeciesname STR_VAR_3, SPECIES_BAGON
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "תרא{EMIT_HEY}{ADD_YUD} את {STR_VAR_2}!\p"
	.string "זה ה{STR_VAR_2} שתפסתי\n"
	.string "אתמול כדי לחגוג את היום הולדת שלך!\p"
	.string "או, אני יכול לראות שאת{EMIT_HEY} רוצה אותו!\n"
	.string "אחרי הכל, אין לו מחיר!\p"
	.string "אני אגיד לך מה. אני אהיה מוכן\n"
	.string "להחליף אותו עבור {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "או, אז זה {STR_VAR_1}?\p"
	.string "זה קצת דומה ל{STR_VAR_2},\n"
	.string "אך שונה מקצת.\p"
	.string "תודה לך!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "לא, לא, לא! אני לא אסכים\n"
	.string "לכלום פחות מ{STR_VAR_1}!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "או, אז את{EMIT_HEY} לא הול{SWAP_CHAF}{ADD_TAF}\n"
	.string "עם זה?\p"
	.string "זה בסדר. אני לא נואש\n"
	.string "להחלפה או משהו$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "אני יודע שאני יכול לחפש אחד\n"
	.string "בעצמי, אבל…\p"
	.string "אבל ממש רציתי לקבל {STR_VAR_3}\n"
	.string "ממאמן אחר שתפס…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "האם זה פוקידע?\p"
	.string "האם יצא לך לפגוש הרבה \n"
	.string "פוקימונים שונים\p"
	.string "הלוואי והייתי כמוך.$"

