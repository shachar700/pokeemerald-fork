@ NOTE: Route 109's sail to Dewford script references local IDs from Dewford's map.
@  These are labeled in DewfordTown/scripts.inc

Route109_MapScripts::
	.byte 0

Route109_EventScript_StartDepartForDewford::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_ROUTE109, 0
	setobjectsubpriority LOCALID_PLAYER, MAP_ROUTE109, 0
	applywaitmovement LOCALID_ROUTE109_BRINEY, Route109_Movement_BrineyEnterBoat
	removeobject LOCALID_ROUTE109_BRINEY
	switch VAR_FACING
	case DIR_SOUTH, Route109_EventScript_EnterBoatSouth
	case DIR_WEST, Route109_EventScript_EnterBoatWest
	case DIR_EAST, Route109_EventScript_EnterBoatEast
	end

Route109_EventScript_EnterBoatSouth::
	applywaitmovement LOCALID_PLAYER, Route109_Movement_PlayerEnterBoatSouth
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_EnterBoatEast::
	applywaitmovement LOCALID_PLAYER, Route109_Movement_PlayerEnterBoatEast
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_EnterBoatWest::
	applywaitmovement LOCALID_PLAYER, Route109_Movement_PlayerEnterBoatWest
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_DoSailToDewford::
	hideobjectat LOCALID_PLAYER, MAP_ROUTE109
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_ROUTE109_BOAT, Route109_Movement_SailToDewford
	applymovement LOCALID_PLAYER, Route109_Movement_SailToDewford
	waitmovement 0
	delay 50
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
	applywaitmovement LOCALID_PLAYER, Route109_Movement_PlayerExitBoat
	addobject LOCALID_DEWFORD_BOAT
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setobjectxyperm LOCALID_DEWFORD_BRINEY, 12, 8
	addobject LOCALID_DEWFORD_BRINEY
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
	applywaitmovement LOCALID_DEWFORD_BRINEY, Route109_Movement_BrineyExitBoat
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	hideobjectat LOCALID_ROUTE109_BOAT, MAP_ROUTE109
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority LOCALID_PLAYER, MAP_ROUTE109
	resetobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN
	copyobjectxytoperm LOCALID_DEWFORD_BRINEY
	release
	end

Route109_Movement_SailToDewford:
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

Route109_Movement_PlayerEnterBoatSouth:
	walk_down
	walk_down
	step_end

Route109_Movement_PlayerExitBoat:
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_right
	step_end

Route109_Movement_PlayerEnterBoatEast:
	walk_right
	walk_down
	step_end

Route109_Movement_PlayerEnterBoatWest:
	walk_left
	walk_down
	step_end

Route109_Movement_BrineyEnterBoat:
	walk_down
	step_end

Route109_Movement_BrineyExitBoat:
	walk_down
	walk_in_place_faster_left
	step_end

Route109_EventScript_MrBriney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route109_EventScript_HaveNotDeliveredDevonGood
	goto Route109_EventScript_DeliveredDevonGoods
	end

Route109_EventScript_HaveNotDeliveredDevonGood::
	message Route109_Text_BrineySailToDewfordQuestion
	msgbox Route109_Text_BrineySailToDewfordQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route109_EventScript_StayHere
	goto Route109_EventScript_SailToDewford
	end

Route109_EventScript_DeliveredDevonGoods::
	message Route109_Text_BrineyWhereAreWeBound
	waitmessage
	multichoicedefault 21, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route109_EventScript_SailToDewford
	case 1, Route109_EventScript_ChoseNotToSail
	case MULTI_B_PRESSED, Route109_EventScript_ChoseNotToSail
	end

Route109_EventScript_SailToDewford::
	msgbox Route109_Text_BrineyDewfordItIs, MSGBOX_DEFAULT
	closemessage
	goto Route109_EventScript_StartDepartForDewford
	end

Route109_EventScript_StayHere::
	msgbox Route109_Text_BrineyDeliverDevonGoods, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_ChoseNotToSail::
	msgbox Route109_Text_BrineyTellMeWhenYouNeedToSail, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_SeashoreHouseGirl::
	msgbox Route109_Text_ChillAtMyPapasSpot, MSGBOX_NPC
	end

Route109_EventScript_SandCastleBoy::
	lock
	faceplayer
	msgbox Route109_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route109_EventScript_SoftSandGirl::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_AlreadyReceivedSoftSand
	msgbox Route109_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_SOFT_SAND
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	setflag FLAG_RECEIVED_SOFT_SAND
	release
	end

Route109_EventScript_AlreadyReceivedSoftSand::
	msgbox Route109_Text_WereGoingToMakeBigCastle, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route109_EventScript_Woman::
	msgbox Route109_Text_LittleKidsDartAround, MSGBOX_NPC
	end

Route109_EventScript_OldMan::
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
	end

Route109_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox Route109_Text_ZigzagoonCry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route109_EventScript_SeashoreHouseSign::
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
	end

Route109_EventScript_TrainerTipsSign::
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
	end

Route109_EventScript_David::
	trainerbattle_single TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated
	msgbox Route109_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Alice::
	trainerbattle_single TRAINER_ALICE, Route109_Text_AliceIntro, Route109_Text_AliceDefeated
	msgbox Route109_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated
	msgbox Route109_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Edmond::
	trainerbattle_single TRAINER_EDMOND, Route109_Text_EdmondIntro, Route109_Text_EdmondDefeated
	msgbox Route109_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Route109_EventScript_RickyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_RickyRematch
	msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_RickyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route109_Text_RickyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICKY_1
	release
	end

Route109_EventScript_RickyRematch::
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_RickyRematchIntro, Route109_Text_RickyRematchDefeated
	msgbox Route109_Text_RickyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Route109_EventScript_LolaRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_LolaRematch
	msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_LolaRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route109_Text_LolaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA_1
	release
	end

Route109_EventScript_LolaRematch::
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_LolaRematchIntro, Route109_Text_LolaRematchDefeated
	msgbox Route109_Text_LolaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Austina::
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated
	msgbox Route109_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Gwen::
	trainerbattle_single TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated
	msgbox Route109_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER, Route109_Text_CarterIntro, Route109_Text_CarterDefeated
	msgbox Route109_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Paul::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_PaulIntro, Route109_Text_PaulDefeated, Route109_Text_PaulNotEnoughPokemon
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Mel::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_MelIntro, Route109_Text_MelDefeated, Route109_Text_MelNotEnoughPokemon
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Chandler::
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated
	msgbox Route109_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Hailey::
	trainerbattle_single TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Elijah::
	trainerbattle_single TRAINER_ELIJAH, Route109_Text_ElijahIntro, Route109_Text_ElijahDefeated
	msgbox Route109_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Text_BrineyLandedInSlateportDeliverGoods:
	.string "מר ברייני: אהוי!\n"
	.string "עגנו בסלייטפורט!\p"
	.string "אני מניח שאת{EMIT_HEY} הול{SWAP_CHAF}{ADD_TAF} לבקר את קפטן.\n"
	.string "סטרן ולמסור לו את הסחורת דבון?$"

Route109_Text_BrineySailToDewfordQuestion:
	.string "מר ברייני: חשבתי שאת{EMIT_HEY} אמור{ADD_HEY}\n"
	.string "למסור את הסחורת דבון.\p"
	.string "אז, האם תרצ{EMIT_HEY}{ADD_YUD} להפליג חזרה\n"
	.string "לדופורד?$"

Route109_Text_BrineyDewfordItIs:
	.string "מר ברייני: לדופורד, אז!\p"
	.string "עוגנים למעלה!\n"
	.string "פיקו, אנחנו מפליגים, יקירתי!$"

Route109_Text_BrineyDeliverDevonGoods:
	.string "מר ברייני: אז ל{SWAP_CHAF}{ADD_YUD} ותמס{EMIT_VAV}ר{ADD_YUD} את\n"
	.string "הסחורת דבון. אני אחכה.$"

DewfordTown_Text_BrineyLandedInSlateport:
	.string "מר ברייני: אהוי! עגנו בסלייטפורט!\p"
	.string "רק לי תגיד{ADD_YUD} מתי תרצ{EMIT_HEY}{ADD_YUD} לצאת\n"
	.string "שוב להפלגה!$"

Route109_Text_BrineyWhereAreWeBound:
	.string "מר ברייני: אהוי!\n"
	.string "בשבילך, אני אצא לים בכל עת!\p"
	.string "עכשיו, חבר{ADD_TAF}י, לאן פנינו?$"

Route109_Text_BrineyTellMeWhenYouNeedToSail:
	.string "מר ברייני: פשוט תגיד{ADD_YUD} לי מתי\n"
	.string "שתצטר{SWAP_CHAF}{ADD_YUD} להפליג שוב!$"

Route109_Text_ChillAtMyPapasSpot:
	.string "יו, מאמנים!\n"
	.string "בין אם אתם חמים אש מגיל שש,\l"
	.string "או קרים כטבע מגיל שבע,\l"
	.string "הירגעו בפינה של פאפה!$"

Route109_Text_LittleKidsDartAround:
	.string "ילדים קטנים יכולים לרוץ כל כך מהר…\p"
	.string "אי אפשר להוריד מהם את העיניים\n"
	.string "לרגע. זה מאוד מתיש.\p"
	.string "שלי עם הפוקימון שלי, אז הם\n"
	.string "אמורים להיות בסדר, אבל…$"

Route109_Text_SandCastleTakingLongTime:
	.string "ארמון החול שלנו לוקח מלא זמן\n"
	.string "להיבנות.$"

Route109_Text_YouCanHaveThis:
	.string "את{EMIT_HEY} יכול{ADD_HEY} לקבל את זה!$"

Route109_Text_WereGoingToMakeBigCastle:
	.string "אנחנו נקח את כל החול מהחוף\n"
	.string "ונבנה ארמון ענקי!\p"
	.string "ואז אנחנו נהיה מלך\n"
	.string "ומלכה.\p"
	.string "נרשה לך להיות המשרת{ADD_TAF}.$"

Route109_Text_ZigzagoonPicksUpLitter:
	.string "המים באזורים האלה נקיים.\p"
	.string "אבל, אני מאפשר ל{STR_VAR_1} שלי לאסוף זבל\n"
	.string "מהחוף לפעמים.\p"
	.string "מים מלוכלכים הופכים לגשם ומצטרפים\n"
	.string "לנהרות שלנו, שמהם אנחנו שותים…\p"
	.string "אם נזהם את הים, כל זה יחזור\n"
	.string "אלינו בסופו של דבר.$"

Route109_Text_ZigzagoonCry:
	.string "{STR_VAR_1}: גוגוו?$"

Route109_Text_SeashoreHouseSign:
	.string "בית חוף הים\p"
	.string "“שקרבות לוהטים ישתוללו בחולות לוהטים!\n"
	.string "המקום למאמנים לוהטים!”$"

Route109_Text_TrainerTipsSign:
	.string "טיפים למאמנים\p"
	.string "פוקימונים באותה רמה לא תמיד יהיו\n"
	.string "עם נתונים זהים.\p"
	.string "נאמר שפוקימון שגודל על ידי מאמנים\n"
	.string "מתחזק יותר מאשר פוקימון פראי.$"
