BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applywaitmovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "באנו לכאן כדי להשגיח על\n"
	.string "הנכד שלנו.\p"
	.string "אבל מכיוון שאנחנו כאן, חשבנו\n"
	.string "שכדאי לקנות כמה מזכרות.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "יקיר{ADD_TAF}י, מה דעתך על זה?\n"
	.string "זה לא יכולה להיות מתנה נחמדה?\p"
	.string "זה…ח…ל…בון?\n"
	.string "זה נשמע טעים, לא?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "הרבה מהמתקנים של חזית הקרב\n"
	.string "לא מאפשרים שימוש בפריטים\l"
	.string "במהלך הקרבות.\p"
	.string "החוק הזה הופך את הדברים לקשים\n"
	.string "עוד יותר ממה שהם כבר!$"

