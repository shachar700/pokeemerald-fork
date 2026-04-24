BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "הפוקימון שלי הוא {STR_VAR_2}.\n"
	.string "את{EMIT_HEY} מכיר{ADD_HEY} אותו?\l"
	.string "הוא די חמוד ונחמד למדי.\p"
	.string "הקטנצ'יק הזה, אני יכול להחליף אותו\n"
	.string "בשמחה!\p"
	.string "רוצה להחליף את {STR_VAR_1}\n"
	.string "עבור ה{STR_VAR_2} שלי?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "או, הוא מקסים!\n"
	.string "תודה לך!\l"
	.string "אני מבטיחה שאהיה טובה אליו!\p"
	.string "או! אני מקווה שגם את{EMIT_HEY} תהי{EMIT_HEY}{ADD_YUD}\n"
	.string "טובה ל{STR_VAR_2} שלי!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "או, אני מצטערת!\n"
	.string "אני לא מתכוונת להחליף עבור שום דבר\l"
	.string "חוץ מ{STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "או, את{EMIT_HEY} לא רוצה?\n"
	.string "ובכן, זה גם בסדר.\l"
	.string "בבקשה בוא{ADD_YUD} לבקר אותנו שוב.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "צחקוק!\n"
	.string "{STR_VAR_1} הוא חמוד יותר ממה\l"
	.string "שדמיינתי. אני מאושרת!$"
