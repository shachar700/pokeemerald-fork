SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SlatePort_EventScript_ScottSceneMaybeThisTrainerMale
	call_if_eq VAR_RESULT, FEMALE, SlatePort_EventScript_ScottSceneMaybeThisTrainerFemale
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlatePort_EventScript_ScottSceneMaybeThisTrainerMale::
	msgbox SlateportCity_Text_MaybeThisTrainerMale, MSGBOX_DEFAULT
	return

SlatePort_EventScript_ScottSceneMaybeThisTrainerFemale::
	msgbox SlateportCity_Text_MaybeThisTrainerFemale, MSGBOX_DEFAULT
	return

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "אני גורו האנרגיה! אני אעשה זאת\n"
	.string "ואמכור לך מה שאת{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY}!$"

SlateportCity_Text_OhYourPokemon:
	.string "או?\n"
	.string "ה{STR_VAR_1} שלך…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "הוא עשה זאת נהדר!\p"
	.string "בתור פרס, בבקשה תביא{ADD_YUD} לו את\n"
	.string "סרט המאמץ.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} קיבל{ADD_HEY} את סרט המאמץ.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} ש{SWAP_MEM}{ADD_HEY} את סרט המאמץ\n"
	.string "ב{STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} להתאמץ קצת יותר.\p"
	.string "כשתעש{EMIT_HEY}{ADD_YUD} זאת, אתן לפוקימון שלך\n"
	.string "משהו נחמד.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "או! ה{STR_VAR_1} שלך, סרט\n"
	.string "המאמץ נראה טוב עליו!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "אור המגדלור מגיע\n"
	.string "רחוק לעשרות קילומטרים.\p"
	.string "אני תוהה אם זה לא מבהיל את\n"
	.string "הפוקימונים שבים.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "אוו, תרא{EMIT_HEY}{ADD_YUD} את זה!\p"
	.string "האצה כאן טרייה ומלאת חיים.\p"
	.string "זה נראה כאילו היא יכולה אפילו לקום\n"
	.string "ולהתנגד!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "כאשר המים נקיים, פירות הקציר השופע\n"
	.string "מתקבצים.\p"
	.string "וכאשר אנשים מתאספים, שוק\n"
	.string "צומח במהרה.\p"
	.string "כך נולדת וגדלה עיירה.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "קניות תוך כדאי שנושמים את\n"
	.string "ריח הים…\p"
	.string "סלייטפורט היא מקום נפלא!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "אם תשי{SWAP_MEM}{ADD_YUD} בובות או כריות על\n"
	.string "הרצפה, הן יתלכלכו.\p"
	.string "אני הולכת לקנות כמה לבנים כדי שהבובות\n"
	.string "והכריות שלי לא יתלכלו כשאשאיר אותן בחוץ.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "רואר! אני גם הולך להתחרות\n"
	.string "באוהל הקרבות!\p"
	.string "אבל קודם, אני צריך לתפוס\n"
	.string "כמה פוקימונים!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "פיו… אני פשוט מותש…\p"
	.string "הלכתי ברגל מהעיר מוויל.\n"
	.string "אבל, האמת, העיר הזאת ענקית.\p"
	.string "אם הייתי יודע, הייתי רוכב את\n"
	.string "אופניי לכאן.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "סטרן, הסחבק שבנה את המוזיאון,\n"
	.string "מסתבר שגם המנהיג של צוות חקירה תת ימי.\p"
	.string "אז, כולם קוראים לו קפטן סטרן.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "מה זה שם?\n"
	.string "התור הארוך הזה…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "כשהייתי ילד, ביקרתי, לעיתים קרובות\n"
	.string "במוזיאון.\p"
	.string "חלמתי על מסתורי הים לאחר שראיתי\n"
	.string "את התערוכות.$"

SlateportCity_Text_QuitPushing:
	.string "היי, שם! תפסיק{ADD_YUD} לדחוף!\n"
	.string "זה התור, את{EMIT_HEY} לא רואה?$"

SlateportCity_Text_AquaHasPolicy:
	.string "לצוות אקווה יש מדיניות\n"
	.string "של להתאסף ולהתפזר\l"
	.string "באתר הפעולה.$"

SlateportCity_Text_BossIsBrilliant:
	.string "הבוס שלנו גאוני.\p"
	.string "מה הוא רוצה לעשות\n"
	.string "עם מוזיאון עכשיו?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "מה התוכנית החדשה, אני תוהה?\p"
	.string "הבוס שלנו מפחיד כשהוא כועס, אז\n"
	.string "עדיף שלא אהרוס את העניינים…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "אם יש משהו שאנחנו צריכים\n"
	.string "במוזיאון, כדאי שניקח הכל!$"

SlateportCity_Text_DontButtIn:
	.string "היי, את{EMIT_HEY} שם!\n"
	.string "אל תצטופ{SWAP_PEY}{ADD_YUD}!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "תור ארוך, הא?\p"
	.string "זה מזכיר לי את הפעמים שעמדתי בתור\n"
	.string "לקנות משחקי להיטs…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "למה אנחנו בכלל עומדים בתור ומשלמים?\n"
	.string "אנחנו צריכים פשוט להיכנס!$"

SlateportCity_Text_WhatDoYouWant:
	.string "מה?\n"
	.string "מה את{EMIT_HEY} רוצה?$"

SlateportCity_Text_IllReadSignForYou:
	.string "את{EMIT_HEY} רוצה לקרוא את השלט הזה?\n"
	.string "אני אקרא בשבילך!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
    .string "בוא{ADD_YUD} נראה…\p"
    .string "אממ… נראה שזה אומר משהו כמו\n"
    .string "”החיים בים הם אינסופיים.“\p"
    .string "כן, אני די בטוח שזה מה\n"
    .string "שכתוב.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "רטינה…\p"
	.string "הייתי צריך להביא את הגיים בוי\n"
	.string "אדוונס שלי כדי שלא אשתעמם בתור…\p"
	.string "רטינה…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "כשהמבצע יגמר, אני אקח אותך לספא\n"
	.string "מעיינות חמים!\p"
	.string "זה מה שהמנהיג שלנו אמר.\n"
	.string "אני לא יכול לחכות!$"

SlateportCity_Text_SeaIsSoWet:
	.string "הים פשוט כל כך רחב…\p"
	.string "יכול להיות שהים נוצר\n"
	.string "מדמעות ששחררו פוקימון?$"

SlateportCity_Text_SinkOldBoats:
	.string "את{EMIT_HEY} יודע{ADD_TAF} מה הם עושים עם\n"
	.string "ספינות ישנות שכבר ישנות מדי להפלגה?\p"
	.string "הם שוקעים אותן בים כדי שיהפכו\n"
	.string "לבית לפוקימון.$"

SlateportCity_Text_BuyTooMuch:
	.string "בכל פעם שאני מבקרת כאן, אני נסחפת\n"
	.string "וקונה יותר מדי.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "אם את{EMIT_HEY} רוצה לשנות את הכינוי של\n"
	.string "פוקימון, תצטר{SWAP_CHAF}{ADD_YUD} לקבל עזרה\l"
	.string "מהמעריך שמות.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "כל פוקימון שקיבלת בהחלפה,\n"
	.string "לא ניתן לשנות את כינויו.\p"
	.string "האהבה של המאמן המקורית לפוקימון\n"
	.string "הזה נמצאת בכינוי.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "לאחרונה, אוהל קרב נבנה\n"
	.string "בסלייטפורט.\p"
	.string "מכונים הם כיפים, אבל האוהל קרב\n"
	.string "נהדר בדרכו שלו\p"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} למצוא פוקימון קשוח\n"
	.string "לאוהל הקרב!$"

SlateportCity_Text_CaptSternBeingInterviewed:
    .string "קיוויתי שזה כוכב מפורסם\n"
    .string "כדי שאוכל לקבל חתימה.\p"
    .string "אבל מי זה שמתראיין?\n"
	.string "זה לא קפטן סטרן?$"

SlateportCity_Text_InterviewerSoCool:
	.string "המראיינת היא כל כך מגניבה ויפה.\p"
	.string "כשאגדל, אני הולכת להיות\n"
	.string "עיתונאית בינלאומית!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "קפטן סטרן אומר שהם גילו משהו\n"
	.string "בתחתית הים.\p"
	.string "אני תוהה מה זה?\n"
	.string "מה זה יכול להיות?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "מה קורה כאן?\p"
	.string "האם הקפטן הטוב חזר עם דג\n"
	.string "ענקי מקרקעית הים?$"

SlateportCity_Text_AmIOnTV:
	.string "היי! את{EMIT_HEY} צופה?\n"
	.string "האם אני בטלוויזיה?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "ראיון בטלויזיה! כאן!\n"
	.string "הקפטן סלבריטאי!$"

SlateportCity_Text_BigSmileForCamera:
	.string "טאי: אוקיי, קפטן סטרן, חיוך גדול\n"
	.string "למצלמה!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "גאבי: מבינה, מבינה. חוית חוויה\n"
	.string "שאין לה תחליף…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "קפטן סטרן: כן, בהחלט. אנחנו מתכוונים\n"
	.string "להמשיך בחקירה שלנו.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "גאבי: זה נהדר, קפטן סטרן!\n"
	.string "תודה שלקחת מזמנך היקר לשוחח איתנו.\p"
	.string "אנו מקווים שנוכל לראיין אותך שוב\n"
	.string "עם חדשות על גילויים נוספים!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "קפטן סטרן: פיו…\p"
	.string "זו הייתה הפעם הראשונה שהצטלמתי\n"
	.string "לטלוויזיה. זה היה מלחיץ.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "או! {PLAYER}{KUN}!\n"
	.string "את{EMIT_HEY} נרא{EMIT_HEY}{ADD_YUD}{ADD_TAF} נהדר!\p"
	.string "עשינו גילוי ענקי בחקר שלנו על המצולות.\p"
	.string "מצאנו מערה תת ימית בדרך 821.\p"
	.string "אנחנו חושבים שזה בית גידול של פוקימון\n"
	.string "שנאמר שנכחד מזמן.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "פופופו…\n"
	.string "קפטן סטרן, אני מניח.\p"
	.string "אנחנו מצוות אקווה נשתלט\n"
	.string "על הצוללת שלך!\p"
	.string "ההתנגדות שלך חסרת משמעות!\n"
	.string "אנחנו מצפים לשיתוף פעולה מלא!\p"
	.string "פופופו…\n"
	.string "רק תסתכל{ADD_YUD} ותלמד{ADD_YUD} מה שצוות אקווה\l"
	.string "מתכנן!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "קפטן סטרן: על מה כל זה היה?\p"
	.string "נשמע שמישהו השתמש במגפון…\p"
	.string "מאיפה זה הגיע?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "זה מהנמל!\p"
	.string "הצוללת!\n"
	.string "הם מנסים לקחת אותה!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "בבקשה, בוא{ADD_YUD} איתי!$"

SlateportCity_Text_BattleTentSign:
	.string "אוהל הקרב אתר סלייטפורט\n"
	.string "“מצא את זה! הפוקימון המיטבי!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "המספנה של סטרן\p"
	.string "”דרוש: מלח שיודע להפליג\n"
	.string "בכל הזרמים.“$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "המספנה של סטרן\p"
	.string "”המעבורת ס.ס גאות כמעט\n"
	.string "הושלמה לשרת את הנמלים של\l"
	.string "סלייטפורט וליליקוב.“$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "המספנה של סטרן\p"
	.string "”עלייה למעבורת א/ק גאות של\n"
	.string "סלייטפורט-ליליקוב מתבצעת בנמל.“$"

SlateportCity_Text_PokemonFanClubSign:
	.string "מועדון מעריצי פוקימון\n"
	.string "”קריאה לכל אוהדי פוקימון!“$"

SlateportCity_Text_OceanicMuseumSign:
	.string "”הים האינסופי מזין\n"
	.string "את כל החיים.“\p"
	.string "מוזיאון ימי$"

SlateportCity_Text_CitySign:
	.string "עיר סלייטפורט\p"
	.string "”הנמל בו אנשים ופוקימון\n"
	.string "חוצים יחדיו.“$"

SlateportCity_Text_MarketSign:
	.string "שוק סלייטפורט\n"
	.string "“פריטים יחודים שלא נמצאים במקום אחר!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "נמל סלייטפורט\p"
	.string "”המעבורת א/ק גאות נמצאת בבנייה\n"
	.string "במספנה.\p"
	.string "”שירות צפוי להתחיל בקרוב.“$"

SlateportCity_Text_HarborSign:
	.string "נמל סלייטפורט\p"
	.string "”תהנו משיט מהנה על\n"
	.string "המעבורת א/ק גאות.“$"

SlateportCity_Text_NameRatersHouseSign:
	.string "בית המעריך שמות\n"
	.string "”כינויי פוקימון להערכה.“$"

SlateportCity_Text_ExplainBerries:
	.string "אם פוקימון פראי נפגע, הוא מרפא את\n"
	.string "עצמו באכילת פירות יער.\p"
	.string "ידעת את זה?\p"
	.string "מישהו ראה את זה וקיבל את הרעיון\n"
	.string "של להכין תרופות מפירות יער.\p"
	.string "ידעת את זה?\p"
	.string "להפוך פירות יער לתרופה,\n"
	.string "צריך למעוך אותם לכדי אבקה.\p"
	.string "ידעת את זה?\p"
	.string "נראה שיש לך עניין בפירות יער!\p"
	.string "יש לי משהו טוב עבור מישהו כמוך.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "לאחרונה התקנתי מכונות במרכזי\n"
	.string "פוקימון למעיכת פירות יער.\p"
	.string "המכונות מעיכת פירות יער נמצאות\n"
	.string "בפינה הישירה בקומה העליונה.\p"
	.string "ידעת?\p"
	.string "תוכל{ADD_YUD} להכין עבורי אבקת פירות יער\n"
	.string "בעזרת המכונות האלו?\p"
	.string "אני יכול להכין לך כל מיני תרופות\n"
	.string "אם תביא{ADD_YUD} לי הרבה אבקת פירות יער.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "הבאת לי קצת אבקת פירות יער?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "במה תרצה להחליף את זה?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "אוקיי, רוצה להחליף את האבקת\n"
	.string "פירות יער עבור {STR_VAR_1} אחד?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "או, יקיר{ADD_TAF}י. אין לך מספיק\n"
	.string "אבקת פירות יער.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "זה אבקת פירות יער איכותית.\n"
	.string "זה ייצור תרופות מצויינות.\p"
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} להחליף עוד מהאבקת\n"
	.string "יער שלך עבור משהו אחר?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "בסדר! כשתשיג{ADD_YUD} עוד אבקת פירות יער,\n"
	.string "תביא{ADD_YUD} לי בבקשה!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "תחז{EMIT_VAV}ר{ADD_YUD} אם תרצי להחליף אבקת\n"
	.string "פירות יער עבור תרופה.\p"
	.string "אני תמיד מנהלת כאן שוק.\p"
	.string "ידעת?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "סקוט: הא?\n"
	.string "אני בטוח שפגשתי אותך איפשהו לפניכן.\p"
	.string "האם הצגתי את עצמי לך?\n"
	.string "אם לא, שמי סקוט.\p"
	.string "בדיוק ראיתי את צוות אקווה בורח\n"
	.string "מכאן כאילו נעקצו.\p"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לנחש--את{EMIT_HEY} הברחת אותם?$"

SlateportCity_Text_MaybeThisTrainerMale:
	.string "סקוט: הממ…\n"
	.string "אולי, רק אולי, המאמן הזה…$"

SlateportCity_Text_MaybeThisTrainerFemale:
	.string "סקוט: הממ…\n"
	.string "אולי, רק אולי, המאמנת הזאת…$"	

SlateportCity_Text_LetsRegisterEachOther:
	.string "סקוט: בסדר! אני חושב שתהי{EMIT_HEY}{ADD_YUD}\n"
	.string "חבר{ADD_HEY} טוב{ADD_HEY}.\p"
	.string "אז, בוא{ADD_YUD} נרשום אחד את השני{ADD_HEY}\n"
	.string "בפוקינווט.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "האדם הזה סקוט נרשם\n"
	.string "בפוקינווט.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "סקוט: מה שאני רוצה זה להצטרף אלייך,\n"
	.string "אני גם רוצה לשים עין\l"
	.string "על כישרונות של אחרים.\p"
	.string "אז, אני אסתובב בערים אחרות קצת.\p"
	.string "נתראה, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "סקוט: או, היי!\n"
	.string "אם זה לא {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, ת{SWAP_NUN}{ADD_YUD} לי לנחש--את{EMIT_HEY} הול{SWAP_CHAF}{ADD_TAF}\n"
	.string "לאתגר את אוהל הקרב?\p"
	.string "כן! זה רעיון טוב!\n"
	.string "זה באמת רעיון נהדר!\p"
	.string "אחרי הכל, מאמ{SWAP_NUN}{ADD_TAF} חזק{ADD_HEY} ה{EMIT_VAV}{ADD_YUD}א\n"
	.string "התאמה מושלמת לאוהל הקרב!\p"
	.string "ת{SWAP_NUN}{ADD_YUD} את המאמץ הכי טוב שלך!$"
