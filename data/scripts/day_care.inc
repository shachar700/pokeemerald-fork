Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "אני איש המעון.\p"
	.string "אני עוזר לטפל בפוקימונים\n"
	.string "היקרים של מאמנים.\p"
	.string "אם תרצ{EMIT_HEY}{ADD_YUD} שאגדל את הפוקימון שלך,\n"
	.string "דבר{ADD_YUD} עם אשתי.$"

Route117_Text_DoYouWantEgg:
	.string "אה, זה את{EMIT_HEY}!\p"
	.string "גידלנו את הפוקימונים שלך,\n"
	.string "ולטובתנו, הופתענו!\p"
	.string "לפוקימונים שלך יש ביצה!\p"
	.string "אנחנו לא יודעים איך היא הגיעה לשם,\n"
	.string "אבל לפוקימונים שלך יש אותה.\p"
	.string "את{EMIT_HEY} רוצה אותה, נכון?$"

Route117_Text_YourMonIsDoingFine:
	.string "אה, זה את{EMIT_HEY}! טוב לראות אותך.\n"
	.string "ה{STR_VAR_1} שלך מסתדר מצוין.$"

Route117_Text_IllKeepIt:
	.string "אם כך, אשמור אותה.\n"
	.string "תודה!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "אין לך מקום בשבילה…\n"
	.string "תחז{EMIT_VAV}ר{ADD_YUD} כשתפנ{EMIT_HEY}{ADD_YUD} מקום.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER} קיבל{ADD_HEY} את הביצה\n"
	.string "מאיש המעון.$"

Route117_Text_TakeGoodCareOfIt:
	.string "טפל{ADD_YUD} בה היטב.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "דרך אגב, ה{STR_VAR_1} שלך,\n"
	.string "נראה ידידותי ל{STR_VAR_3} של {STR_VAR_2}.\p"
	.string "יכול להיות שאפילו ראיתי אותו מקבל\n"
	.string "דואר.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"

Route117_Text_YourMonsAreDoingFine:
	.string "אה, זה את{EMIT_HEY}! ה{STR_VAR_1} שלך\n"
	.string "ו{STR_VAR_2} מסתדרים מצויין.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "אני באמת אשמור אותה.\n"
	.string "את{EMIT_HEY} באמת רוצה את זה, כן?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "אני גברת המעון.\p"
	.string "אנחנו יכולים לגדל עבורך פוקימונים.\p"
	.string "תרצ{EMIT_HEY}{ADD_YUD} שנגדל אחד?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "איזה פוקימון תרצ{EMIT_HEY}{ADD_YUD} שנגדל\n"
	.string "עבורך?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "בסדר, אנחנו נגדל את ה{STR_VAR_1} שלך\n"
	.string "לזמן מה.\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} אליו מאוחר יותר.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "אנחנו יכולים לגדל שניים מהפוקימונים שלך.\n"
	.string "תרצ{EMIT_HEY}{ADD_YUD} שנגדל עוד אחד?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "בעלי חיפש אותך.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "או, בסדר, אם כך.\n"
	.string "בוא{ADD_YUD} שוב.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "אין לך מספיק כסף…$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "האם תקח{ADD_YUD} בחזרה גם את השני?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "בסדר.\n"
	.string "בוא{ADD_YUD} שוב.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "אה, זה את{EMIT_HEY}! טוב לראות אותך.\n"
	.string "הפוקימונים שלך רק מסתדרים מצויין!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "מבחינת רמה, ה{STR_VAR_1} שלך\n"
	.string "גדל ב-{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "צוות הפוקימונים שלך מלא.\n"
	.string "פנ{EMIT_HEY}{ADD_YUD} מקום, ואז בוא{ADD_YUD} לראות אותי.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "Which POKéMON will you take back?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "אם את{EMIT_HEY} רוצה את {STR_VAR_1} שלך בחזרה,\n"
	.string "זה יעלה {STR_VAR_2}¥.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "מצויין!\n"
	.string "הנה הפוקימון שלך.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} לקח{ADD_HEY} בחזרה את {STR_VAR_1}\n"
	.string "מגברת המעון.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "או? אבל יש לך רק פוקימון\n"
	.string "אחד.\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} בפעם אחרת.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "האם תקח{ADD_YUD} את הפוקימון שלך בחזרה?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "אם תשאיר לי את הפוקימון הזה,\n"
	.string "עם מה תילח{SWAP_MEM}{ADD_YUD}?\p"
	.string "חז{EMIT_VAV}ר{ADD_YUD} בפעם אחרת.$"

Text_EggHatchHuh:
	.string "הא?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "הא?\n"
	.string "רגע, רגע.\p"
	.string "אם תשאיר{ADD_YUD} את הפוקימון הזה איתי,\n"
	.string "את{EMIT_HEY} תישאר{ADD_YUD} עם רק אחד.\p"
	.string "יהיה לך עדיף אם תתפ{EMIT_VAV}ס{ADD_YUD}\n"
	.string "עוד כמה, אני חייבת לומר.$"
