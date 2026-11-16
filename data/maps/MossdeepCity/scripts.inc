MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	bufferspeciesname STR_VAR_1, SPECIES_WAILMER
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applywaitmovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "קיבלתי את זה מסטיבן, אבל אני לא\n"
	.string "יודע למה זה טוב.\p"
	.string "אני חושב שקוראים לזה אבן המלך.\n"
	.string "את{EMIT_HEY} רוצה את זה?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "למה שתרצה את זה?\n"
	.string "את{EMIT_HEY} מוזר{ADD_HEY}.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY} לשמור את זה, אבל שמ{EMIT_VAV}ר{ADD_YUD} את זה בסוד\n"
	.string "מסטיבן.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "הבית של סטיבן נמצא ממש שם!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "כן, גם את{EMIT_HEY} חושב{ADD_TAF} ככה! מה את{EMIT_HEY} אמור{ADD_HEY}\n"
	.string "לעשות עם איזו אבן מוזרה?$"

MossdeepCity_Text_WailmerWatching:
	.string "סביב מוסדיפ, אפשר לראות {STR_VAR_1}\n"
	.string "פראיים.\p"
	.string "קוראים לזה, אה…\n"
	.string "מה זה היה?\p"
	.string "וואי, וואי, וואי…\p"
	.string "צפיית {STR_VAR_1}!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "מרכז החלל של האי\n"
	.string "משגר טילים ענקיים.\p"
	.string "הייתה איזו מהומה\n"
	.string "בגלל מכתב שקיבלו לאחרונה.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "מרכז החלל של האי\n"
	.string "משגר טילים ענקיים.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "שמעתי מחבר מלח שצוות אקווה\n"
	.string "התמקם בליליקוב.\p"
	.string "שמעתי גם שמישהו הגיע\n"
	.string "והביס אותם לגמרי!\p"
	.string "אבל מוסדיפ כאן סומנה כמטרה\n"
	.string "על ידי צוות מגמה.\p"
	.string "אם את{EMIT_HEY} רוצה לדעת מה הם זוממים,\n"
	.string "ל{SWAP_CHAF}{ADD_YUD} לבקר במרכז החלל.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "אני מלח, אז הים הוא כמובן\n"
	.string "חשוב יותר בשבילי.\p"
	.string "אבל את{EMIT_HEY} יודע{ADD_TAF}? כשאני חוזר ליבשה\n"
	.string "אחרי מסע ארוך, אני כן מרגיש הקלה!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "האם זה לא יהיה נחמד?\p"
	.string "אם כל העולם היה מכוסה\n"
	.string "בצמחים ופרחים כמו האי הזה?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "כל החיים זקוקים לים כדי להתקיים, למרות\n"
	.string "שהם בונים את ביתם על היבשה.\p"
	.string "החיים, לאחר שסיימו את דרכם, הופכים\n"
	.string "לאדמה וחוזרים ליבשה.\p"
	.string "והים תמיד מחובר\n"
	.string "ליבשה.\p"
	.string "כן, כמו קו החוף כאן.$"

MossdeepCity_Text_SurfExhilarating:
	.string "מסע בספינה זה בסדר.\p"
	.string "אבל לחצות את הים עם פוקימונים\n"
	.string "באמצעות גלישה…\p"
	.string "זהו מסע מעורר חושים!\n"
	.string "את{EMIT_HEY} לא מסכי{SWAP_MEM}{ADD_HEY}, צעיר{ADD_HEY}?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "לאבן הזו יש משמעות מיוחדת עבור\n"
	.string "האנשים במרכז החלל.\p"
	.string "הם שמו אותה כאן כמשאלת לב עבור\n"
	.string "הטילים שלהם שיטוסו בבטחה.\p"
	.string "כשאת{EMIT_HEY} מבקש משאלה, במה את{EMIT_HEY} משתמש{ADD_TAF}?\n"
	.string "האם את{EMIT_HEY} מבקש{ADD_TAF} משאלה מכוכב?\p"
	.string "אני משתמשת בתג משאלה כדי שזה יקרה.\n"
	.string "זה מה שאני עושה.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "זו אבן לבנה.$"

MossdeepCity_Text_GymSign:
	.string "מכון הפוקימונים של העיר מוסדיפ\n"
	.string "מנהיגים: ליזה וטייט\p"
	.string "”השילוב המיסטי!“$"

MossdeepCity_Text_CitySign:
	.string "העיר מוסדיפ\n"
	.string "”הסלוגן שלנו: הוקרת פוקימונים!“$"

MossdeepCity_Text_SpaceCenterSign:
	.string "מרכז החלל של מוסדיפ\n"
	.string "”המקום הקרוב ביותר לחלל.“$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "סקוט: {PLAYER}{KUN}, מרגיש{ADD_HEY} טוב?\n"
	.string "אני מרגיש נהדר!\p"
	.string "שמעתי שמנהיג מכון מוסדיפ\n"
	.string "די חזק, אז החלטתי לבוא\l"
	.string "לבדוק בעצמי.\p"
	.string "אבל יש משהו מוזר\n"
	.string "בעיר הזו.\p"
	.string "אנשים מדברים על מכתב אזהרה\n"
	.string "ועל מרכז החלל…\p"
	.string "עם זאת, אני לא חושב שזה נוגע\n"
	.string "אליי בשום צורה.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "אהה… זה מרגיש נהדר לתת לגלים\n"
	.string "לשטוף את כפות רגליי…\p"
	.string "אם כבר מדברים על גלים, את{EMIT_HEY} מכיר{ADD_HEY} את\n"
	.string "עיר האי סוטופוליס?\p"
	.string "אני חושב שהמכון שם קיבל מנהיג\n"
	.string "חדש.\p"
	.string "אנשים אומרים לי שהמנהיג החדש פעם\n"
	.string "היה המנטור של וולאס.$"

