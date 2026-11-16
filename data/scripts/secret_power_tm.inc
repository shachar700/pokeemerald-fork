Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "מה זה?\n"
	.string "מה אני עושה?\p"
	.string "אני חושב להכין חדר משלי\n"
	.string "כאן בעזרת מהלך של פוקימון.\p"
	.string "אני יודע! אני אתן לך את המ”מ הזה.\n"
	.string "האם תשתמש{ADD_YUD} בו כדי ליצור חדר משלך?$"

Route111_Text_ExplainSecretPower:
	.string "מצא{ADD_YUD} עץ גדול שנראה כאילו הוא עומד\n"
	.string "להוריד כמה גפנים.\p"
	.string "השתמש{ADD_YUD} בכוח סודי מול העץ.\n"
	.string "כמה גפנים אמורים להשתחרר וליפול\l"
	.string "למטה, כדי שתוכל{ADD_YUD} לטפס על העץ.\p"
	.string "את{EMIT_HEY} תמצא{ADD_YUD} הרבה מקום לשים\n"
	.string "את הדברים האהובים עליך.\p"
	.string "זה יהיה החדר הסודי שלך…\n"
	.string "בסיס סודי!\p"
	.string "כדאי לך ליצור אחד גם.\p"
	.string "עוד משהו, את{EMIT_HEY} לא תמיד צרי{SWAP_CHAF}{ADD_HEY}\n"
	.string "לבנות את הבסיס סודי שלך בעץ.\p"
	.string "תנס{EMIT_HEY}{ADD_YUD} להשתמש בכוח סודי על קירות סלע\n"
	.string "שיש בהם שקעים קטנים.\p"
	.string "אני הולך גם לחפש מקומות אחרים.\n"
	.string "אוקיי, ביי!$"

Route111_Text_DontWantThis:
	.string "או, את{EMIT_HEY} לא רוצה את זה?\n"
	.string "אם תשנ{EMIT_HEY}{ADD_YUD} את דעתך, תגיד{ADD_YUD} לי, אוקיי?$"

Route111_Text_DontHaveAnyRoom:
	.string "או, אין לך מקום לזה.\p"
	.string "אני אחזיק בזה, אז תחז{EMIT_VAV}ר{ADD_YUD} לזה\n"
	.string "בפעם אחרת, אוקיי?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applywaitmovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	return

Route111_EventScript_SecretPowerManExitNorth::
	applywaitmovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
