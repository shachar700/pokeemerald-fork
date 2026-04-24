BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "במשך 07 שנה גידלתי פוקימונים!\n"
	.string "אני האיש שאותו הם מעריצים\l"
	.string "כמגדל הפוקימונים האגדי הבכיר!\p"
	.string "אם אי פעם תהפוך למנוסה כמוני,\n"
	.string "תראה את היכולות של פוקימונים\l"
	.string "במבט חטוף.\p"
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}. האם לא מעניין אותך לדעת\n"
	.string "מהן היכולות של הפוקימונים שלך?\l"
	.string "היכולות?\p"
	.string "הנה!\n"
	.string "בוא{ADD_YUD} נסתכל על הפוקימונים שלך!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…הממ…\p"
	.string "את זה, בסך הכל, הייתי מתאר\n"
	.string "כבעל יכולת ממוצעת.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…הממ…\p"
	.string "את זה, בסך הכל, הייתי מתאר\n"
	.string "כבעל יכולת טובה יותר מהממוצע.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…הממ…\p"
	.string "את זה, בסך הכל, הייתי אומר שהוא\n"
	.string "די מרשים ביכולת!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…הממ…\p"
	.string "את זה, בסך הכל, הייתי אומר שהוא\n"
	.string "מצטיין להפליא ביכולת!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "אגב, ההיבט הטוב ביותר שלו,\n"
	.string "הייתי אומר, הוא הנח שלו…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "אגב, ההיבט הטוב ביותר שלו,\n"
	.string "הייתי אומר, הוא ההתקפה שלו…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "אגב, ההיבט הטוב ביותר שלו,\n"
	.string "הייתי אומר, הוא ההגנה שלו…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "אגב, ההיבט הטוב ביותר שלו,\n"
	.string "הייתי אומר, הוא ההתקפה המיוחדת שלו…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "אגב, ההיבט הטוב ביותר שלו,\n"
	.string "הייתי אומר, הוא ההגנה המיוחדת שלו…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "אגב, ההיבט הטוב ביותר שלו,\n"
	.string "הייתי אומר, הוא המהירות שלו…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "הנתון הזה טוב יחסית.\n"
	.string "…המ… כך אני קורא לזה.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "הנתון הזה די מרשים.\n"
	.string "…המ… כך אני קורא לזה.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "הנתון הזה מצטיין!\n"
	.string "…המ… כך אני קורא לזה.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "זה מושלם! דבר של שלמות!\n"
	.string "…המ… כך אני קורא לזה.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "מה?\n"
	.string "אין לך זמן לעצה שלי?\p"
	.string "את{EMIT_HEY} תמיד צרי{SWAP_CHAF}{ADD_HEY} להיות להוט{ADD_HEY} ללמוד\n"
	.string "מהחוויות של המבוגרים ממך!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "כן, מה עכשיו?\p"
	.string "יש לי עניינים שצריך לטפל בהם!\n"
	.string "שמ{EMIT_VAV}ר{ADD_YUD} את זה לפעם הבאה!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "אה, צעיר{ADD_HEY}! האם היכולות של הפוקימונים\n"
	.string "שלך מסקרנות אותך?\p"
	.string "הנה, הנה!\n"
	.string "בוא{ADD_YUD} נסתכל על הפוקימונים שלך!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "אני מומחה, אבל אפילו אני לא יכול לדעת\n"
	.string "שום דבר על פוקימון שלא בקע!\p"
	.string "הרא{EMIT_HEY}{ADD_YUD} לי פוקימון!\n"
	.string "פוקימון זה מה שאני צריך לראות!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "הוא אמר שהפוקימון שלי מצטיין!\n"
	.string "אני שמח שגידלתי אותו בזהירות!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "הוא אמר שהפוקימון שלי מצטיין!\n"
	.string "אבל לא עשיתי שום דבר מיוחד\l"
	.string "כשגידלתי אותו…$"

