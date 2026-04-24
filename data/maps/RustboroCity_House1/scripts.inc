RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "הא? הפוקימון שלי חמוד?\n"
	.string "בטח, ידעתי את זה.\p"
	.string "אבל אם את{EMIT_HEY} ממש רוצה, אני מוכן\n"
	.string "להחליף אותו איתך.\p"
	.string "אני אתן לך את {STR_VAR_2} שלי תמורת\n"
	.string "{STR_VAR_1} אם את{EMIT_HEY} רוצה.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "היהיהי…\n"
	.string "בבקשה תטפל{ADD_YUD} יפה בפוקימון שלי.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "הא? זה בכלל לא נראה לי\n"
	.string "כמו {STR_VAR_1}.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "אה, אם את{EMIT_HEY} לא רוצה, זה בסדר.\n"
	.string "אבל הפוקימון שלי חמוד, את{EMIT_HEY} יודע{ADD_TAF}…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "כל פוקימון יכול להיות חמוד אם\n"
	.string "מטפלים בו בתשומת לב ובחיבה.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "בכל מיני מקומות יש כל מיני\n"
	.string "פוקימונים ואנשים.\p"
	.string "זה מרתק אותי, לכן אני הולך לכל\n"
	.string "מיני מקומות.$"

