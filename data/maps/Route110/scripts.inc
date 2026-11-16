Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applywaitmovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applywaitmovement LOCALID_ROUTE110_RIVAL, Common_Movement_WalkInPlaceFasterDown
	applywaitmovement LOCALID_ROUTE110_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_ROUTE110_RIVAL, Common_Movement_Delay48
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_ITEMFINDER
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_ROUTE110_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_ROUTE110_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_ROUTE110_RIVAL
	addobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applywaitmovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer1
	return

Route110_EventScript_RivalApproachPlayer2::
	applywaitmovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer2
	return

Route110_EventScript_RivalApproachPlayer3::
	applywaitmovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer3
	return

Route110_EventScript_RivalExit1::
	applywaitmovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	return

Route110_EventScript_RivalExit2::
	applywaitmovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	return

Route110_EventScript_RivalExit3::
	applywaitmovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_ROUTE110_BIRCH
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchEntrance
	playse SE_PIN
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_Delay48
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	delay 10
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterRight
	delay 20
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterDown
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_ROUTE110_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer1
	return

Route110_EventScript_BirchApproachPlayer2::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer2
	return

Route110_EventScript_BirchApproachPlayer3::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer3
	return

Route110_EventScript_BirchApproachPlayer4::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer4
	return

Route110_EventScript_BirchExit1::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit1
	return

Route110_EventScript_BirchExit2::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit2
	return

Route110_EventScript_BirchExit3::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit3
	return

Route110_EventScript_BirchExit4::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit4
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "פעילויות צוות אקווה…\n"
	.string "אנחנו לא יכולים לדבר עליהן עדיין.$"

Route110_Text_KickUpARuckus:
	.string "אני רוצה ללכת לסלייטפורט\n"
	.string "ולגרום למהומה!$"

Route110_Text_MyFirstJobInAqua:
	.string "זו העבודה הראשונה שלי אחרי שהצטרפתי\n"
	.string "לצוות אקווה. זה קצת מפחיד.$"

Route110_Text_AquaActionsBringSmiles:
	.string "הפעולות של צוות אקווה אמורות להביא\n"
	.string "חיוכים לפניהם של אנשים!$"

Route110_Text_MayLetsBattle:
	.string "מאי: היי, {PLAYER}{KUN}, הרבה זמן לא ראיתי אותך!\p"
	.string "בזמן שחיפשתי פוקימונים\n"
	.string "אחרים, הפוקימון שלי התחזק יותר.\p"
	.string "אז…\n"
	.string "מה דעתך על קרב קטן?$"

Route110_Text_MayDefeated:
	.string "יאייקס!\n"
	.string "אתה טוב יותר ממה שציפיתי!$"

Route110_Text_MayTakeThis:
	.string "מאי: {PLAYER}{KUN}, היית גם עסוק\n"
	.string "באימונים, נכון?\p"
	.string "אני חושבת שמגיע לך פרס!\n"
	.string "זה ממני!$"

Route110_Text_MayExplainItemfinder:
	.string "מאי: זה מאתר פריט.\p"
	.string "נסה את זה. אם יש פריט שאינו\n"
	.string "גלוי, הוא משמיע צליל.\p"
	.string "אוקיי, {PLAYER}{KUN}, בוא ניפגש שוב!\p"
	.string "אני יודעת שזה קצת מטופש מצדי,\n"
	.string "אבל אני חושבת שאתה צריך להתאמן חזק\l"
	.string "יותר לפעם הבאה.$"

Route110_Text_BrendanLetsBattle:
	.string "ברנדן: היי, {PLAYER}.\n"
	.string "אז זה המקום שבו היית.\l"
	.string "מה קורה?\p"
	.string "האם גידלת את הפוקימונים שלך?\n"
	.string "אני אבדוק אותך.$"

Route110_Text_BrendanDefeated:
	.string "הממ…\n"
	.string "את די טובה.$"

Route110_Text_BrendanTakeThis:
	.string "ברנדן: {PLAYER}, התאמנת\n"
	.string "בלי ששמתי לב…\p"
	.string "מספיק טוב!\n"
	.string "קחי את זה.$"

Route110_Text_BrendanExplainItemfinder:
	.string "ברנדן: זה מאתר פריט.\p"
	.string "תשתמשי בו כדי לחפש פריטים\n"
	.string "שאינם גלויים.\p"
	.string "אם הוא חש משהו, הוא משמיע\n"
	.string "צליל.\p"
	.string "בכל מקרה, אני יוצא לחפש פוקימונים\n"
	.string "חדשים.$"

Route110_Text_RideBikeAtFullSpeed:
	.string "האם זה לא יהיה נהדר לרכוב על אופניים\n"
	.string "במלוא המהירות בשביל האופניים?$"

Route110_Text_HairStreamsBehindMe:
	.string "איך את{EMIT_HEY} אוהב{ADD_TAF} את הדרך שבה השיער\n"
	.string "שלי בצבע עורב מתנופף מאחוריי?\p"
	.string "הארכתי את השיער שלי רק בשביל זה.$"

Route110_Text_YouGotBikeFromRydel:
	.string "או, היי, קיבלת את האופניים האלה מריידל!\p"
	.string "או, זה ברור לחלוטין.\n"
	.string "זה כתוב ממש על האופניים שלך…\p"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\n"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\p"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\n"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\p"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\n"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\p"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\n"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל,\p"
	.string "ריידל, ריידל, ריידל, ריידל, ריידל…\n"
	.string "השם הזה נמצא בכל מקום.\p"
	.string "כדאי לך לרכוב עליהם בכל\n"
	.string "מקום--זו פרסומת טובה!$"

Route110_Text_TwoRoads:
	.string "שתי הדרכים, אחת למעלה, אחת למטה…\p"
	.string "דרך לכל אחד מבני אדם ופוקימונים.\n"
	.string "אולי זה הוגן ונכון.$"

Route110_Text_WalkOnTheLowRoad:
	.string "אין לי אופניים, אז אני אעשה\n"
	.string "הליכה נינוחה בדרך התחתונה.$"

Route110_Text_BikeTechniques:
	.string "לימוד טכניקות יהפוך את רכיבת האופניים\n"
	.string "לכיפית עוד יותר.\p"
	.string "יש כמה מקומות שאת{EMIT_HEY} יכול{ADD_HEY}\n"
	.string "להגיע אליהם רק באמצעות טכניקת אופניים.$"

Route110_Text_WhichShouldIChoose:
	.string "במה עליי לבחור?\p"
	.string "ללכת בקו ישר למוויל\n"
	.string "בשביל האופניים, או לקחת את הדרך התחתונה\l"
	.string "ולחפש פוקימונים?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "מספר ההתנגשויות:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "זמן כולל:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "בראבו! הופעה נהדרת!\p"
	.string "האהבה שלך לרכיבה על אופניים מגיעה\n"
	.string "עמוק מתוך ליבך.\l"
	.string "זעזעת אותי עד עמקי נשמתי!$"

Route110_Text_ChallengeReactionGood:
	.string "הטכניקה שלך יוצאת דופן.\p"
	.string "אני מציע שתאי{SWAP_TZADIK}{ADD_YUD} קצת\n"
	.string "ועדיין תמנע{ADD_YUD} מהתנגשויות.$"

Route110_Text_ChallengeReactionOk:
	.string "הייתי מחשיב אותך כעבודה\n"
	.string "בתהליך.\p"
	.string "עם זאת, אני מקווה שלא תשכח{ADD_YUD} את\n"
	.string "ההנאה הטהורה של רכיבה על אופניים.$"

Route110_Text_ChallengeReactionBad:
	.string "אלוהים… כישורי הרכיבה שלך גובלים\n"
	.string "במפחיד.\p"
	.string "את{EMIT_HEY} בהחלט צרי{SWAP_CHAF}{ADD_HEY} הרבה יותר\n"
	.string "אימון ברכיבה.$"

Route110_Text_ChallengeReactionWorst:
	.string "…אני מזועזע…\p"
	.string "את{EMIT_HEY} אולי לא מתאי{SWAP_MEM}{ADD_HEY} לענייני\n"
	.string "הרכיבה המצערים האלה.\p"
	.string "כדאי לך לשקול ברצינות\n"
	.string "להחזיר את האופניים האלה לריידל.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "זהו שביל האופניים.\p"
	.string "אם תרכב{ADD_YUD} ממוויל\n"
	.string "לסלייטפורט על אופני מאך, את{EMIT_HEY} תקבל{ADD_YUD}\l"
	.string "דירוג על מספר ההתנגשויות\l"
	.string "והזמן הכולל שלך.$"

Route110_Text_AlwaysAimHigher:
	.string "בלי קשר לתוצאות, אני סומך על\n"
	.string "שאראה ממך עוד אתגרים.\l"
	.string "תמיד כוו{SWAP_NUN}{ADD_YUD} גבוה יותר!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "בשביל האופניים הזה, אלה שרוכבים על\n"
	.string "אופני מאך מדורגים על מספר\l"
	.string "ההתנגשויות שלהם והזמן הכולל.\p"
	.string "אופני אקרו לא מתאימים לדירוג.\n"
	.string "קל מדי לפנות איתם, אז זה לא הוגן.$"

Route110_Text_SlateportCitySign:
	.string "דרך 011\n"
	.string "{DOWN_ARROW} עיר סלייטפורט$"

Route110_Text_CyclingRoadSign:
	.string "שביל האופניים לצד חוף הים$"

Route110_Text_AquaWasHere:
	.string "”צוות אקווה היה כאן!“\p"
	.string "מישהו צבע את זה על השלט הזה,\n"
	.string "אבל מישהו אחר צבע מעל.\p"
	.string "”צוות מגמה שולט!“ זה מה\n"
	.string "שכתוב עכשיו.$"

Route110_Text_Route103Sign:
	.string "דרך 011\n"
	.string "{LEFT_ARROW} דרך 301$"

Route110_Text_SeasideParkingSign:
	.string "חניית חוף הים$"

Route110_Text_MauvilleCitySign:
	.string "דרך 011\n"
	.string "{UP_ARROW} העיר מוויל$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "טיפים למאמנים\p"
	.string "ניתן לגרום ליריב להיות חסר אונים על ידי\n"
	.string "שיתוק שלו או על ידי לגרום לו לישון.\p"
	.string "זו טכניקה חשובה עבור\n"
	.string "קרבות פוקימונים.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "טיפים למאמנים\p"
	.string "ניתן לארגן מחדש את הפריטים בתיק\n"
	.string "על ידי לחיצה על TCELES.$"

Route110_Text_TrickHouseSign:
	.string "”שלושה צעדים {RIGHT_ARROW} ושני צעדים {UP_ARROW}\n"
	.string "כדי להגיע לבית הטריקים המופלא.“$"

Route110_Text_BestRecord:
	.string "השיא הטוב ביותר עד היום…\p"
	.string "מס' התנגשויות: {STR_VAR_1}\p"
	.string "זמן שעבר: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "השיא הטוב ביותר עד היום…\p"
	.string "נראה שאף אחד לא לקח את האתגר.\n"
	.string "אין שיא…$"

Route110_Text_ImagineSeeingYouHere:
	.string "פרופ. בירץ': או, {PLAYER}{KUN}!\n"
	.string "תאר{ADD_YUD} לעצמך לראות אותך כאן!\p"
	.string "ואיפה היריב שלי?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "או, אני מבין!\n"
	.string "שניכם רצים בנפרד.\l"
	.string "טוב, זה בסדר.\p"
	.string "אה, כן, שמעתי שבפוקינווט שלך\n"
	.string "הותקנה מערכת שיחת הקרב.\p"
	.string "טוב, אם כן, אני צריך לרשום אותך\n"
	.string "בפוקינווט שלי גם כן.\p"
	.string "כך, גם כשאנחנו בנפרד,\n"
	.string "אני יכול לדרג את הפוקידע שלך בכל עת.\p"
	.string "… … … … … …$"

Route110_Text_RegisteredBirchInPokenav:
	.string "פרופ' בירץ' נרשם\n"
	.string "בפוקינווט.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "פרופ. בירץ': {PLAYER}{KUN}…\p"
	.string "אנא השג{ADD_YUD}ח{ADD_YUD} על היריב שלי.\n"
	.string "… … … … … …\p"
	.string "טוב, מוטב שאמשיך בדרכי.\n"
	.string "נתראה שוב, {PLAYER}{KUN}!$"

