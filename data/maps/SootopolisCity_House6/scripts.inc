SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "שלום! את{EMIT_HEY} האורח{ADD_TAF} הראשו{SWAP_NUN}{ADD_HEY} שלנו\n"
	.string "מזה זמן רב.\p"
	.string "הבאת אור ליום שלי, אז אני\n"
	.string "אתן לך בובת וויילמר ענקית!$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "תשמ{EMIT_VAV}ר{ADD_YUD} עליה היטב!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "או, את{EMIT_HEY} רוצה את זה אבל לא עכשיו?\n"
	.string "אוקיי, אז אני אשמור אותה בשבילך.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "את{EMIT_HEY} בטוח{ADD_HEY}?\n"
	.string "את{EMIT_HEY} לא רוצה את הבובה הזו?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "אני אוהבת בובות רכות!$"

