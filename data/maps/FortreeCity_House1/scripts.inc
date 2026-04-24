FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	bufferspeciesname STR_VAR_1, SPECIES_VOLBEAT
	bufferspeciesname STR_VAR_2, SPECIES_PLUSLE
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "וואאאארואר! אני חייב אותו!\n"
	.string "אני חייב להשיג {STR_VAR_1} אחד!\l"
	.string "אני אעשה הכל בשבילו!\p"
	.string "…אה… שמעת את זה?\n"
	.string "את הצעקה שלי מעומק ליבי?\p"
	.string "לאחר ששמעת זאת, תחלי{SWAP_PEY}{ADD_YUD}\n"
	.string "את {STR_VAR_1} שלך עבור ה{STR_VAR_2} שלי,\l"
	.string "נכון?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "או, כן, בדיוק!\p"
	.string "{STR_VAR_1}, ברוך הבא!\n"
	.string "{STR_VAR_2}, שמור על עצמך!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "או, לא, אני לא חושב כך.\n"
	.string "זה לא {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "לא? את{EMIT_HEY} לא תסח{EMIT_VAV}ר{ADD_YUD} איתי?\n"
	.string "אפילו אחרי שחשפתי את ליבי בפניך?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "אני אהפוך את {STR_VAR_1} לחזק\n"
	.string "במיוחד מרגע זה!\p"
	.string "אני מקווה שתעש{EMIT_HEY}{ADD_YUD} את אותו דבר עם {STR_VAR_2}!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "להחליף פוקימון עם אחרים…\p"
	.string "זה כמו להחליף את הזיכרונות\n"
	.string "שלך עם אנשים אחרים.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "{STR_VAR_1}: גומומוה?$"

