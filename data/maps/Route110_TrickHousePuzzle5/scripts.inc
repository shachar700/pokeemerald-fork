Route110_TrickHousePuzzle5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_OnTransition
	.byte 0

Route110_TrickHousePuzzle5_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_8, 0
	end

Route110_TrickHousePuzzle5_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle5_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle5_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1::
	lockall
	applywaitmovement LOCALID_MECHADOLL_1, Common_Movement_FacePlayer
	goto_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2::
	lockall
	applywaitmovement LOCALID_MECHADOLL_2, Common_Movement_FacePlayer
	goto_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3::
	lockall
	applywaitmovement LOCALID_MECHADOLL_3, Common_Movement_FacePlayer
	goto_if_eq VAR_TEMP_3, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4::
	lockall
	applywaitmovement LOCALID_MECHADOLL_4, Common_Movement_FacePlayer
	goto_if_eq VAR_TEMP_4, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5::
	lockall
	applywaitmovement LOCALID_MECHADOLL_5, Common_Movement_FacePlayer
	goto_if_eq VAR_TEMP_5, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger5::
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

@ Unused
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger5::
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_1
	playse SE_PIN
	applywaitmovement LOCALID_MECHADOLL_1, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MECHADOLL_1, Common_Movement_Delay48
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate::
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_2
	playse SE_PIN
	applywaitmovement LOCALID_MECHADOLL_2, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MECHADOLL_2, Common_Movement_Delay48
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4
	call_if_eq VAR_TEMP_9, 5, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate::
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_3
	playse SE_PIN
	applywaitmovement LOCALID_MECHADOLL_3, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MECHADOLL_3, Common_Movement_Delay48
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate::
	setvar VAR_TEMP_4, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_4
	playse SE_PIN
	applywaitmovement LOCALID_MECHADOLL_4, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MECHADOLL_4, Common_Movement_Delay48
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate::
	setvar VAR_TEMP_5, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_5
	playse SE_PIN
	applywaitmovement LOCALID_MECHADOLL_5, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MECHADOLL_5, Common_Movement_Delay48
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_ODDISH
	bufferspeciesname STR_VAR_2, SPECIES_POOCHYENA
	bufferspeciesname STR_VAR_3, SPECIES_TAILLOW
	multichoice 0, 0, MULTI_MECHADOLL1_Q1, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_AZURILL
	bufferspeciesname STR_VAR_2, SPECIES_LOTAD
	bufferspeciesname STR_VAR_3, SPECIES_WINGULL
	multichoice 0, 0, MULTI_MECHADOLL1_Q2, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_DUSTOX
	bufferspeciesname STR_VAR_2, SPECIES_ZUBAT
	bufferspeciesname STR_VAR_3, SPECIES_NINCADA
	multichoice 0, 0, MULTI_MECHADOLL1_Q3, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_RALTS
	bufferspeciesname STR_VAR_2, SPECIES_ZIGZAGOON
	bufferspeciesname STR_VAR_3, SPECIES_SLAKOTH
	multichoice 0, 0, MULTI_MECHADOLL2_Q1, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_POOCHYENA
	bufferspeciesname STR_VAR_2, SPECIES_SHROOMISH
	bufferspeciesname STR_VAR_3, SPECIES_ZIGZAGOON
	multichoice 0, 0, MULTI_MECHADOLL2_Q2, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_POOCHYENA
	bufferspeciesname STR_VAR_2, SPECIES_ZUBAT
	bufferspeciesname STR_VAR_3, SPECIES_CARVANHA
	multichoice 0, 0, MULTI_MECHADOLL2_Q3, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q1, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q2, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q3, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q1, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q2, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q3, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q1, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q2, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q3, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer::
	waitse
	playse SE_FAILURE
	msgbox Route110_TrickHousePuzzle5_Text_DisappointmentError, MSGBOX_DEFAULT
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_MechadollShake
	msgbox Route110_TrickHousePuzzle5_Text_Wahahahaha, MSGBOX_DEFAULT
	waitmovement 0
	msgbox Route110_TrickHousePuzzle5_Text_WaitForNextChallenge, MSGBOX_DEFAULT
	closemessage
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_CorrectAnswer::
	waitse
	playse SE_SUCCESS
	goto Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	end

Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough::
	msgbox Route110_TrickHousePuzzle5_Text_CorrectGoThrough, MSGBOX_DEFAULT
	releaseall
	end

@ Absurd redundancy in movement scripts that could be resolved by using VAR_TEMP_8 for applymovement instead
@ Many of the below movement scripts arent even used, see below
@   Mechadoll 2 is the only mechadoll to walk right, all the other WalkRight scripts are unused
@   Mechadoll 5 never walks, all the Mechadoll5Walk scripts are unused
@   No mechadoll walks left 5 paces, all the WalkLeft5 scripts are unused
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft5::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5::
	applywaitmovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5::
	applywaitmovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5::
	applywaitmovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5::
	applywaitmovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5::
	applywaitmovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight5
	return

Route110_TrickHousePuzzle5_Movement_WalkLeft1:
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft2:
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft3:
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft4:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight1:
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight2:
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight3:
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight4:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_MechadollShake:
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_down
	step_end

Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} כתב{ADD_HEY} את הקוד הסודי\n"
	.string "על הדלת.\p"
	.string "”מאסטר הטריקים הוא גאון.“\n"
	.string "… … … … … … … …\p"
	.string "המנעול נפתח בלחיצה!$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Intro:
	.string "קליקטי-קלאק…\n"
	.string "מכאדול 1 אני!\p"
	.string "אם תענה נכון על החידונים,\n"
	.string "אז תלך למכאדול 5.\l"
	.string "אז תוכל לקבל את הקוד הסודי.$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1:
	.string "חידון מכאדול 1.\p"
	.string "אחד מהפוקימונים האלה לא נמצא\n"
	.string "בדרך 011. איזה מהם?$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2:
	.string "חידון מכאדול 1.\p"
	.string "אחד מהפוקימונים האלה הוא לא\n"
	.string "מסוג מים. איזה מהם?$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3:
	.string "חידון מכאדול 1.\p"
	.string "אחד מהפוקימונים האלה לא משתמש\n"
	.string "בהתעלקות. איזה מהם?$"

Route110_TrickHousePuzzle5_Text_CorrectGoThrough:
	.string "ברכות. צדקת.\n"
	.string "התקדם. בבקשה.$"

Route110_TrickHousePuzzle5_Text_DisappointmentError:
	.string "בזזזט. אכזבה.\n"
	.string "שגיאה.$"

Route110_TrickHousePuzzle5_Text_Wahahahaha:
	.string "וואהאהאהאהא! וואהאהאהאהא!\n"
	.string "קליקטי-קלאק!$"

Route110_TrickHousePuzzle5_Text_WaitForNextChallenge:
	.string "לאתגר הבא שלך אנחנו מחכים.$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Intro:
	.string "קליקטי-קלאק…\n"
	.string "מכאדול 2 אני!\p"
	.string "רמת הקושי של מכאדול 1\n"
	.string "מוגדרת נמוך מדי.$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1:
	.string "חידון מכאדול 2.\p"
	.string "איזה מהפוקימונים האלה וולי\n"
	.string "השאיל מאבא שלך?$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2:
	.string "חידון מכאדול 2.\p"
	.string "איזה מהפוקימונים האלה רדף אחרי\n"
	.string "פרופ. בירץ'?$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3:
	.string "חידון מכאדול 2.\p"
	.string "איזה מהפוקימונים האלה צוות אקווה\n"
	.string "השתמש ביער פטלבורג?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Intro:
	.string "קליקטי-קלאק…\n"
	.string "מכאדול 3 אני!\p"
	.string "ענייני כסף הם המיקוד היחיד שלי.$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1:
	.string "חידון מכאדול 3.\p"
	.string "מה עולה יותר?\n"
	.string "שלושה מכתבי נמל או ריפוי כויה אחד?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2:
	.string "חידון מכאדול 3.\p"
	.string "למכור כדור רב אחד ולקנות\n"
	.string "שיקוי אחד. כמה כסף נשאר?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3:
	.string "חידון מכאדול 3.\p"
	.string "האם דוחה אחד וסודה פופ עולים\n"
	.string "יותר משיקוי רב אחד?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Intro:
	.string "קליקטי-קלאק…\n"
	.string "מכאדול 4 אני!\p"
	.string "החידון שלי הוא מושא יופי.$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1:
	.string "חידון מכאדול 4.\p"
	.string "בבית חוף הים, היו יותר גברים\n"
	.string "או נשים?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2:
	.string "חידון מכאדול 4.\p"
	.string "בעיירת לברידג', היו יותר זקנים\n"
	.string "או זקנות?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3:
	.string "חידון מכאדול 4.\p"
	.string "בבית הספר למאמנים, כמה סטודנטיות\n"
	.string "היו שם?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Intro:
	.string "קליקטי-קלאק…\n"
	.string "מכאדול 5 אני!\p"
	.string "הישג הטוב והגאה ביותר של\n"
	.string "המאסטר אני.$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1:
	.string "חידון מכאדול 5.\p"
	.string "במועדון מעריצי פוקימון בסלייטפורט,\n"
	.string "כמה פוקימונים היו שם?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2:
	.string "חידון מכאדול 5.\p"
	.string "בעיר פורטרי, כמה\n"
	.string "בתי עץ היו שם?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3:
	.string "חידון מכאדול 5.\p"
	.string "על שביל האופניים, כמה\n"
	.string "טריאתלטים היו שם?$"
