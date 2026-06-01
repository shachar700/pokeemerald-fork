BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "איפה שאומץ של מאמנים\n"
	.string "עומד למבחן!\p"
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לפירמידת הקרב!\p"
	.string "אני המדריכה שלך\n"
	.string "למסע הקרבות.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
    .string "האם יש לך את האומץ לצאת\n"
    .string "לאתגר מסע הקרבות?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
    .string "אנחנו נמתין לאתגר שלך בעתיד!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
    .string "מסע הקרבות הוא אירוע לחימה\n"
    .string "בו עליך לחקור את הפירמידה\l"
    .string "ולנסות להגיע לראש.\p"
    .string "בפירמידה יש שבע קומות של\n"
    .string "מבוכים, ובהן לא רק מאמנים מיומנים\l"
    .string "אלא גם פוקימונים בטבע.\p"
    .string "עליך להיכנס עם שלושה פוקימונים,\n"
    .string "שאף אחד מהם אינו מחזיק חפץ.\p"
    .string "במהלך העלייה יסופק לך\n"
    .string "תיק קרב לחפצים.\p"
    .string "אם תיכשל{ADD_YUD} באתגר, כל חפץ\n"
    .string "שהונח בתיק הקרב ייעלם.\p"
    .string "אם תרצה להפסיק את האתגר,\n"
	.string "עליך לבחור ”מנוחה“\l"
	.string "ולשמור את המשחק.\p"
    .string "אם לא תשמ{EMIT_VAV}ר{ADD_YUD} לפני שתפסיק{ADD_YUD},\n"
    .string "את{EMIT_HEY} תיפסל{ADD_YUD}.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
    .string "הפירמידה מציעה שני מסלולים,\n"
    .string "רמה 05 ורמה פתוחה.\l"
    .string "לאיזה מהם תיכנס{ADD_YUD}?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "טוב מאוד. עכשיו, נא לבחור את שלושת"
	.string "הפוקימונים שילוו אותך.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
    .string "יש בעיה קטנה, הרפתק{SWAP_NUN}{ADD_YUD}{ADD_TAF}!\p"
    .string "נראה שאין לך שלושה פוקימונים\n"
    .string "המוכשרים לאתגר.\p"
    .string "אנא זכ{EMIT_VAV}ר{ADD_YUD} גם להסיר את כל הפריטים\n"
    .string "מהפוקימונים שלך.\p"
    .string "ביצים{STR_VAR_1} אינן מתאימות.\p"
    .string "כשאת{EMIT_HEY} מוכ{SWAP_NUN}{ADD_YUD}, דבר{ADD_YUD} איתי שוב.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
    .string "יש בעיה קטנה, הרפתק{SWAP_NUN}{ADD_YUD}{ADD_TAF}!\p"
    .string "נראה שאין לך שלושה פוקימונים\n"
    .string "המוכשרים לאתגר.\p"
    .string "על שלושת הפוקימונים להיות שונים,\n"
    .string "וכל אחד מהם לא גבוה מרמה 05.\p"
    .string "אנא זכ{EMIT_VAV}ר{ADD_YUD} גם להסיר את כל הפריטים\n"
    .string "מהפוקימונים שלך.\p"
    .string "ביצים{STR_VAR_1} אינן מתאימות.\p"
    .string "כשאת{EMIT_HEY} מוכ{SWAP_NUN}{ADD_YUD}, דבר{ADD_YUD} איתי שוב.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
    .string "לפני שתיכנס{ADD_YUD} אל פירמידת הקרבות,\n"
    .string "יש לשמור את המשחק. האם זה בסדר?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "טוב מאוד. אני עכשיו אניס אותך\n"
	.string "לפירמידת הקרב.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "אנחנו נשמור על התיק שלך בהשגחה,\n"
	.string "{PLAYER}, בזמן שאת{EMIT_HEY} חוקר{ADD_TAF}.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "בתמורה, בבקשה קבל{ADD_YUD} את תיק הקרב הזה,\n"
	.string "האחד שהשתמשת בו קודם.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "בתמורה, בבקשה קבל{ADD_YUD} את תיק הקרב הזה.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} החלי{SWAP_PEY}{ADD_HEY} את התיק\n"
	.string "בתיק הקרב.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
    .string "כשאת{EMIT_HEY} דור{SWAP_CHAF}{ADD_TAF} על הלוח הזה,\n"
    .string "תועבר{ADD_YUD} לקומה גבוהה יותר\l"
    .string "בפירמידה.\p"
    .string "הלוואי שהמסע שלך יעבור\n"
    .string "בשלום!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
    .string "בעיה חמורה, חוקר{ADD_TAF}!\p"
    .string "לא שמרת לפני שנטשת\n"
    .string "את האתגר בפעם הקודמת.\p"
    .string "כתוצאה מכך, האתגר שלך נפסל.\n"
    .string "מצטערים על כך.\p"
    .string "הנה התיק ששמרנו\n"
    .string "עבורך.\p"
    .string "{PLAYER} קיבל{ADD_HEY} בחזרה את התיק.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
    .string "נפלא לראות אותך שוב!\p"
    .string "כבשת את הפירמידה!\n"
    .string "כמה מדהים!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "אה, בעיה קטנה.\p"
	.string "לפחות פוקימון אחד מחזיק\n"
	.string "בפריט.\p"
	.string "אני מצטערת לומר, פריטים שהושגו\n"
	.string "בפירמידה לא ניתן להוציא.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "כל הפריטים המוחזקים על ידי הפוקימונים\n"
    .string "שלך יועברו לתיק הקרב שלך, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "תיק הקרב אינו יכול להכיל את כל\n"
	.string "הפריטים שלך, אני מצטער לומר.\p"
	.string "אנא בחר את הפריטים שתשמור ב-\n"
	.string "תיק הקרב, ועם הפוקימונים שלך.$"
	
BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "לפחות פוקימון אחד עדיין\n"
	.string "מחזיק פריט.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "בבקשה לבחור את הפריטים לשמירה\n"
	.string "בתיק הקרב, ועם הפוקימונים שלך.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} החזיר{ADD_HEY} את כל מה\n"
	.string "שהפוקימונים החזיקו.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "תיק הקרב שבו השתמשת יישמר\n"
	.string "במוכנות לאתגר הבא שלך.\p"
	.string "{PLAYER} מסר{ADD_HEY} את תיק הקרב\n"
	.string "עבור החזרת התיק.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "אני חייב לרשום את התוצאות שלך.\n"
	.string "נא להמתין.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "כמזכרת על כיבוש\n"
	.string "פירמידת הקרב, אנא קח{ADD_YUD} את זה.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} קיבל{ADD_YUD} את הפרס\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…אה…\n"
	.string "התיק שלך נראה מלא.\p"
	.string "אנא חז{EMIT_VAV}ר{ADD_YUD} לאחר שארגנת את\n"
	.string "תוכן התיק שלך.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "כמה מאכזב עבורך…\p"
	.string "הנה התיק שהחזקנו\n"
	.string "עבורך.\p"
	.string "{PLAYER} קיבל{ADD_HEY} את התיק בחזרה.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "אנחנו מצפים לאתגר\n"
	.string "הבא שלך!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "אנחנו חיכינו לבואך\n"
	.string "בקוצר רוח!\p"
	.string "הנה הפרס שלך על כיבוש\n"
	.string "הפירמידה.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY}…\p"
	.string "אני אשמח לספר לך אילו\n"
	.string "צרות אורבות בפירמידה…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "אהה!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "אני רואה מטר של ניצוצות…\p"
	.string "…ובו, אני רואה את הפוקימונים שלך\n"
	.string "מתקשים עם שיתוק…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "אני רואה רעל…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "מהשפעות הרעל…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "אני רואה להבות אדומות בוהקות…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "מכויות…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "אני חש בלחץ אדיר של\n"
	.string "כעס בלתי ממומש…\p"
	.string "זו קללה…\p"
	.string "…ואני רואה את הפוקימונים שלך מרוקנים\n"
	.string "מנקודות כוח ואין להם ברירה\l"
	.string "אלא להשתמש במאבק…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "אני רואה פוקימונים מרחפים ברום…\p"
	.string "…ואני רואה את הפוקימונים שלך מתוסכלים\n"
	.string "ממהלכים סוג אדמה חסרות אונים…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "אני חש אנרגיה אדירה עולה\n"
	.string "מהקרקע שמתחת…\p"
	.string "…ואני רואה את הפוקימונים שלך שאינם יכולים\n"
	.string "לברוח מאחיזות הכוח…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "אני רואה פוקימונים מסוג קרח…\p"
	.string "…ואני רואה את הפוקימונים שלך נלחמים\n"
	.string "בהשפעות הקפואות של הקרח…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "אני רואה שטף של מהלכים שמסכנים\n"
	.string "את המשתמש…\p"
	.string "…ואני רואה את הפוקימונים שלך נופלים\n"
	.string "להם…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "אני רואה פוקימונים מסוג על חושי…\p"
	.string "…ואני רואה את הפוקימונים שלך בייסורים\n"
	.string "ממהלכים על חושיים…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "אני רואה פוקימונים מסוג אבן…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "ממהלכי אבן…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "אני רואה פוקימונים מסוג לחימה…\p"
	.string "…ואני רואה את הפוקימונים שלך מוכים\n"
	.string "ממהלכי לחימה…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "ריקוד גשם… יום שמשי…\n"
	.string "סופת חול… ברד…\p"
	.string "אני רואה פוקימונים שמתחזקים\n"
	.string "עם מזג האוויר…\p"
	.string "…ואני רואה את הפוקימונים שלך מבולבלים\n"
	.string "מסוגים שונים של מהלכים…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "אני רואה פוקימונים מסוג חרק…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "מסוגי התקפות שונים…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "אני רואה פוקימונים מסוג אפלה…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "ממהלכי אפלה…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "אני רואה פוקימונים מסוג מים…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "ממהלכי מים…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "אני רואה פוקימונים מסוג רוח…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "ממהלכי רוח…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "אני רואה פוקימונים מסוג פלדה…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "ממהלכים עוצמתיים במידה בלתי רגילה…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "אני רואה פוקימונים מעופפים…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "ממהלכים עוצמתיים במידה בלתי רגילה…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "אני רואה את אלה שהתפתחו\n"
	.string "מכוחן של אבנים…\p"
	.string "אני גם חש באש, מים,\n"
	.string "וחשמל…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "משלושת הכוחות האלה…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "אני רואה פוקימונים מסוג רגיל…\p"
	.string "…ואני רואה את הפוקימונים שלך סובלים\n"
	.string "ממהלכים עוצמתיים במידה בלתי רגילה…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "בין אם תאמי{SWAP_NUN}{ADD_YUD} בחזיונות שלי\n"
	.string "או לא, הבחירה היא שלך…\p"
	.string "את העתיד אפשר לשנות בכל עת…\n"
	.string "אני מאחל לך מעבר בטוח…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "הידעת?\p"
	.string "אם את{EMIT_HEY} ר{SWAP_TZADIK}{ADD_HEY} מהר, מאמנים עשויים לשים\n"
	.string "לב ולבוא אחריך לקרב.\p"
	.string "אז, אם את{EMIT_HEY} רוצה להימנע ממאמנים,\n"
	.string "אל תתפ{EMIT_VAV}ס{ADD_YUD} את עיניהם, אלא חל{EMIT_VAV}{SWAP_PEY}{ADD_YUD}\l"
	.string "על פניהם בזהירות ובשקט.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "אווווואאאאאאררררג!\p"
	.string "היו לי המון פריטים, אבל איבדתי\n"
	.string "את כולם כשהפסדתי!\p"
	.string "אווווואאאאאאררררג!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "ברוך שובך!\n"
	.string "עשית את הבלתי יאומן!\p"
	.string "ניצחת את מלך הפירמידה\n"
	.string "וכבשת את פירמידת הקרב!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "חוקר{ADD_TAF} צעיר{ADD_HEY}!\n"
	.string "כהוקרה על אומץ לבך,\l"
	.string "אנחנו מעניקים לך נקודות קרב אלה!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "חוקי מסע הקרב מפורטים.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "איזו כותרת תרצ{EMIT_HEY}{ADD_YUD} לקרוא?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "כאשר הפירמידה נכבשת,\n"
	.string "הפוקימונים הפראיים שמופיעים בה\l"
	.string "מוחלפים בסוגים אחרים.\p"
	.string "חקרו, צפו, ולמדו אילו סוגי\n"
	.string "פוקימונים פראיים אתם עשויים לפגוש.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "מאמנים אורבים לכם\n"
	.string "בתוך הפירמידה.\p"
	.string "בכל קומה, יש עד\n"
	.string "שמונה מאמנים.\p"
	.string "כאשר תנצחו מאמן, תקבלו\n"
	.string "רמז מועיל להרפתקה שלכם.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "המבוכים בפירמידה מסדרים\n"
	.string "את עצמם מחדש בכל פעם שאתם נכנסים.\p"
	.string "המבוכים מוארים באור קלוש.\n"
	.string "עליכם להתקדם בזהירות.\p"
	.string "האור מתחזק בכל פעם שאתם\n"
	.string "מנצחים פוקימון פראי או מאמן.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "תיק הקרב משמש כתיק שלכם\n"
	.string "בזמן שאתם בפירמידה.\p"
	.string "ישנם שני תיקי קרב נפרדים--\n"
	.string "אחד לכל אחת מהרפתקאות, רמה 05\l"
	.string "ורמה פתוחה.\p"
	.string "כל אחד מהם יכול להכיל עד 99 יחידות\n"
	.string "מעשרה סוגי פריטים.\p"
	.string "תכולת תיק הקרב אובדת\n"
	.string "אם אתם נכשלים במסע שלכם.$"

