LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_WAILMER
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	bufferspeciesname STR_VAR_1, SPECIES_WAILMER
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
    .string "מאי: או, היי?\n"
    .string "{PLAYER}{KUN}, גם אתה עושה קניות?\p"
    .string "קניתי המון בובות ופוסטרים.\p"
    .string "כמובן, גם תפסתי הרבה פוקימונים,\n"
    .string "ואני גם מגדלת אותם כמו שצריך.\p"
    .string "למעשה, אני יותר מודאגת אם אתה\n"
    .string "מגדל פוקימונים כמו שצריך, {PLAYER}{KUN}.\p"
    .string "אני אערוך איתך קרב, כדי שתוכל להראות\n"
    .string "לי את הפוקימונים שלך, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
    .string "מאי: או, למה? {PLAYER}{KUN}, לא גידלת\n"
    .string "את הפוקימונים שלך?\p"
    .string "זה לא מראה טוב כל כך בתור מאמן…$"

LilycoveCity_Text_MayBattleMe:
    .string "מאי: נו, בוא נלחם, כדי שאוכל\n"
    .string "לבדוק את הפוקימונים שלך!$"

LilycoveCity_Text_MayWontBeBeaten:
    .string "מאי: הפוקימונים שגידלתי לא יובסו\n"
    .string "על ידי הפוקימונים שלך, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
    .string "… … … … … … … …\p"
    .string "אני זוכרת את הקרב שהיה לי איתך,\n"
    .string "{PLAYER}{KUN}, בדרך 301.\p"
    .string "הקרב הזה עזר לך להתחזק ככה, {PLAYER}{KUN},\n"
    .string "נכון?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
    .string "מאי: אני חושבת לחזור בקרוב לליטלרוט.\p"
    .string "תפסתי קבוצה נחמדה של פוקימונים,\n"
    .string "והפוקידע שלי מתקדם, אז\l"
    .string "אני הולכת הביתה להראות לאבא שלי.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
    .string "{PLAYER}{KUN}, מה אתה הולך לעשות?\p"
    .string "לאסוף את כל תגי המכון ולגשת לאתגר\n"
    .string "ליגת הפוקימונים?\p"
    .string "טוב, בזמן שאתה אוסף תגים, {PLAYER}{KUN},\n"
    .string "אני הולכת לעבוד על הפוקידע שלי.\l"
    .string "אני אשלים אותו לפניך!\p"
    .string "להתראות!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
    .string "{PLAYER}{KUN}, מה אתה הולך לעשות?\p"
    .string "אתה ניגש לאתגר ליגת הפוקימונים?\p"
    .string "או שאתה הולך להשלים את הפוקידע שלך?\p"
    .string "אולי הפסדתי לך בקרב, אבל אני אסיים\n"
    .string "את הפוקידע שלי לפניך!\p"
    .string "להתראות!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
    .string "{PLAYER}{KUN}, מה אתה הולך לעשות?\p"
    .string "אתה ניגש לאתגר חזית הקרב?\p"
    .string "או שאתה הולך להשלים את הפוקידע שלך?\p"
    .string "אולי הפסדתי לך בקרב, אבל אני אסיים\n"
    .string "את הפוקידע שלי לפניך!\p"
    .string "להתראות!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
    .string "ברנדן: אה, היי, זה {PLAYER}.\p"
    .string "אני עושה שליחות בשביל אבא שלי.\n"
    .string "לא, אני לא קונה בובות.\p"
    .string "בכל אופן, עבר זמה מה.\p"
    .string "רוצה קרב כדי לראות מי אימן\n"
    .string "את הפוקימונים שלו טוב יותר?$"

LilycoveCity_Text_BrendanNoConfidence:
    .string "ברנדן: אה, מה קרה?\n"
    .string "אין לך ביטחון?$"

LilycoveCity_Text_BrendanBattleMe:
    .string "ברנדן: רוצה קרב כדי לראות מי אימן\n"
    .string "את הפוקימונים שלו טוב יותר?$"

LilycoveCity_Text_BrendanWontBeBeaten:
    .string "ברנדן: אוו, אבל את יודעת שאני לא\n"
    .string "אפסיד לאף {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
    .string "המפ…\n"
    .string "עשית הרבה אימונים.\p"
    .string "זה קצת צורב--הייתה לי התחלה מוקדמת\n"
    .string "עליך בתור מאמן…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
    .string "ברנדן: אני…\n"
    .string "אני מתכנן לחזור הביתה לליטלרוט.\p"
    .string "את יודעת שאני עוזר לאבא שלי עם\n"
    .string "הפוקידע שלו. זה מתקדם יפה,\l"
    .string "אז אני צריך ללכת להראות לו.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
    .string "{PLAYER}, מה את הולכת לעשות?\p"
    .string "לאסוף את כל תגי המכון ולגשת לאתגר\n"
    .string "ליגת הפוקימונים?\p"
    .string "אולי אני אעשה את זה גם…\p"
    .string "טוב, בכל אופן, תהיי חזקה!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
    .string "{PLAYER}, מה את הולכת לעשות?\p"
    .string "מכיוון שאת כל כך חזקה, האם את ניגשת\n"
    .string "לאתגר ליגת הפוקימונים?\p"
    .string "הא, גם אני--אם אני אאמן את הפוקימונים\n"
    .string "שלי קצת יותר, אני צריך להיות חזק יותר\l"
    .string "ממך, {PLAYER}.\p"
    .string "טוב, בכל אופן, תהיי חזקה!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
    .string "{PLAYER}, מה את הולכת לעשות?\p"
    .string "את ניגשת לאתגר חזית הקרב?\p"
    .string "או שאת הולכת להשלים את הפוקידע שלך?\p"
    .string "מכיוון שאת כל כך חזקה, כדאי לך\n"
    .string "לשקול את חזית הקרב.\p"
    .string "הא, אם אני אאמן את הפוקימונים שלי קצת\n"
    .string "יותר, אני אתחזק יותר ממך, {PLAYER}.\p"
    .string "אולי אני צריך ללכת לחזית הקרב.\p"
    .string "טוב, בכל אופן, תהיי חזקה!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
    .string "פופופו…\p"
    .string "היום העברנו עוד שלל למחבוא הסודי\n"
    .string "שלנו…\p"
    .string "מ-מי את{EMIT_HEY}?!\n"
    .string "אני רק דיברתי לעצמי!$"

LilycoveCity_Text_ChanceToDoBigThings:
    .string "אני רק עובד, אז אני לא יודע מה\n"
    .string "הבוס חושב…\p"
    .string "אבל להיות בצוות אקווה, אני יודע שאקבל\n"
    .string "את ההזדמנות לעשות דברים גדולים!\p"
    .string "מ-מי את{EMIT_HEY}?!\n"
    .string "אני רק דיברתי לעצמי!$"

LilycoveCity_Text_DontGoNearCaveInCove:
    .string "היי, את{EMIT_HEY}!\p"
    .string "אל תתקרב{ADD_YUD} למערה במפרץ!\p"
    .string "למה? את{EMIT_HEY} לא צרי{SWAP_CHAF}{ADD_HEY} סיבה למה!\n"
    .string "אני מבוגר, אז פשוט תקשיב{ADD_YUD} לי!$"

LilycoveCity_Text_IfWorldBecomesOurs:
    .string "אם כל העולם הרחב הזה יהפוך להיות שלנו,\n"
    .string "של צוות אקווה, זה יהיה מקום מאושר יותר\l"
    .string "גם לפוקימונים.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
    .string "שם! {STR_VAR_1}!\n"
    .string "קפוץ מהמים עכשיו!$"

LilycoveCity_Text_GetLostMessingUpTraining:
    .string "הא? מה את{EMIT_HEY} רוצה?\p"
    .string "את{EMIT_HEY} מפריע{ADD_HEY} לאימונים שלנו,\n"
    .string "אז את{EMIT_HEY} יכול{ADD_HEY}, כאילו, ללכת לאיבוד?$"

LilycoveCity_Text_ContestHallInTown:
    .string "יש אולם תחרויות פוקימונים\n"
    .string "בדיוק בעיר הזו. \p"
    .string "זה אומר שפוקימונים מאומנים היטב\n"
    .string "יגיעו מכל רחבי המדינה.\p"
    .string "ליבי מתמלא בהתרגשות!$"

LilycoveCity_Text_StrangeCaveInCove:
    .string "את{EMIT_HEY} ראית את המערה המוזרה הזו\n"
    .string "במפרץ שבקצה העיר?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
    .string "אני הולך ללמד את הפוקימון שלי כמה\n"
    .string "מהלכים חדשים כדי להיכנס לתחרות.\p"
    .string "אז, אני הולך לראות את מוחק המהלכים\n"
    .string "ולגרום לו לשכוח מהלכי מ”נ.$"

LilycoveCity_Text_ImFromKanto:
    .string "באתי מקאנטו.\p"
    .string "אזור הואן יפהפה עם כל\n"
    .string "המים והטבע הירוק שלו.\p"
    .string "האא? רגע אחד…\p"
    .string "האם יתכנו פוקימונים נדירים שחיים\n"
    .string "רק באזור הזה?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
    .string "צוות אקווה מאמן את ה{STR_VAR_1} שלו\n"
    .string "במפרץ.\p"
    .string "אנחנו המלחים לא יכולים להוציא את\n"
    .string "הסירות שלנו לים כשהם בדרך!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
    .string "אהוי, ידעת?\p"
    .string "מישהו הדף את צוות אקווה החוצה\n"
    .string "מהדרך בשבילנו!\p"
    .string "זה הוציא את ה{STR_VAR_1} מהמפרץ,\n"
    .string "אז אנחנו יכולים להוציא את הסירות שלנו שוב.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
    .string "תפסתי תנומה רגועה בפונדק שליד הים\n"
    .string "לצלילי הגלים…\p"
    .string "כשמישהו גנב לי את הפוקימון!\p"
    .string "מי החוטף?\n"
    .string "צוות אקווה? זה צוות אקווה?$"

LilycoveCity_Text_MissingPokemonCameBack:
    .string "הפוקימון החסר שלי…\n"
    .string "הוא חזר מבלי ששמתי לב!$"

LilycoveCity_Text_ImArtDealer:
    .string "אני סוחר אומנות.\p"
    .string "אני קונה ומוכר אומנות יפה,\n"
    .string "במיוחד ציורים.\p"
    .string "שמעתי שבמוזיאון כאן יש\n"
    .string "יצירות מפוארות בתערוכה…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
    .string "גם כשאנחנו מזדקנים ומקבלים קמטים,\n"
    .string "הים נשאר צעיר לנצח עם\l"
    .string "הזוהר העז של החיים…\p"
    .string "פוהוהו פוהוהוהוהו…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
    .string "זה היה לפני שישים שנה שבעלי\n"
    .string "הציע לי נישואין כאן.\l"
    .string "הים נשאר יפה כתמיד.\p"
    .string "מופופופו מופופופופופו…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
    .string "המ, את{EMIT_HEY} יודע{ADD_TAF} על המערה המוזרה\n"
    .string "במפרץ הזה?\p"
    .string "זו היתה תצורה טבעית,\n"
    .string "אבל אז החבר'ה האלה מצוות אקווה באו\l"
    .string "ועשו את השיפוצים שלהם.\p"
    .string "הם קוראים לעצמם\n"
    .string "”צוות אקווה אוהב הטבע“!\p"
    .string "אבל מה שהם עושים ומה שהם אומרים\n"
    .string "לא תואם בכלל!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
    .string "המערה הזו במפרץ…\p"
    .string "לא שמתי לב מיד,\n"
    .string "אבל היא ריקה לחלוטין עכשיו.\p"
    .string "החבר'ה האלה של צוות אקווה, הם בטח\n"
    .string "הלכו משם לתמיד.$"

LilycoveCity_Text_CitySign:
    .string "העיר ליליקוב\p"
    .string "”המקום בו היבשה נגמרת\n"
    .string "והים מתחיל.“$"

LilycoveCity_Text_ContestHallSign:
    .string "אולם תחרויות פוקימונים\n"
    .string "”מקום ההתכנסות של מאמנים!“$"

LilycoveCity_Text_MotelSign:
    .string "מלונית שושנת המפרץ\p"
    .string "”זכרו אותנו כשושנת המפרץ של\n"
    .string "ליליקוב.“$"

LilycoveCity_Text_MuseumSign:
    .string "מוזיאון ליליקוב\p"
    .string "”אוסף מופת של פוקימונים\n"
    .string "בתערוכה!“$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
    .string "מוזיאון ליליקוב\p"
    .string "”אוסף הפוקימונים של {PLAYER}\n"
    .string "בתערוכה!“$"

LilycoveCity_Text_HarborSignUnderConstruction:
    .string "נמל העיר ליליקוב\p"
    .string "”מעבורת א/ק גאות נמצאת בבנייה\n"
    .string "בעיר סלייטפורט.\p"
    .string "”השירות מתוכנן להתחיל בקרוב.“$"

LilycoveCity_Text_HarborSign:
    .string "נמל העיר ליליקוב\p"
    .string "“תהנו משייט נעים על\n"
    .string "מעבורת א/ק גאות.“$"

LilycoveCity_Text_TrainerFanClubSign:
    .string "מועדון המעריצים של מאמני הפוקימונים\p"
    .string "השמות של המאמנים משורבטים\n"
    .string "על כל השלט…$"

LilycoveCity_Text_DepartmentStoreSign:
    .string "חנות הכלבו של ליליקוב\p"
    .string "”מלא בסחורה נהדרת\n"
    .string "ובהתרגשות!\p"
    .string "”מקום נהדר למצוא את הדבר\n"
    .string "שאתם צריכים!“$"

LilycoveCity_Text_MoveDeletersHouseSign:
    .string "הבית של מוחק המהלכים\p"
    .string "“מהלכי פוקימונים לא רצויים נמחקים.“$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
    .string "את{EMIT_HEY} יודע{ADD_TAF} על המכונה\n"
    .string "בלנדר פירות יער?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
    .string "אנשים צריכים לעבוד יחד כדי לגרום לזה\n"
    .string "להסתובב מהר יותר.\p"
    .string "ככל שאת{EMIT_HEY} יכול{ADD_HEY} לגרום לזה להסתובב מהר יותר,\n"
    .string "כך תקבל{ADD_YUD} פוקיגושים טובים יותר, שמעתי.$"

LilycoveCity_Text_ExplainBerryBlender:
    .string "זה משמש להכנת סוג של ממתק\n"
    .string "שנקרא פוקיגוש.\p"
    .string "אם אתה נותן פוקיגוש טוב לפוקימון,\n"
    .string "הכושר שלו ישתפר מאוד.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
    .string "שמעתי שיש איזה מגדל איפשהו בחוץ\n"
    .string "בנתיבי הים.\p"
    .string "קוראים לזה עמוד השמיים, כך שמעתי.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
    .string "ראיתי את המגדל הגבוה הזה איפשהו\n"
    .string "סביב דרך 131.\p"
    .string "האם זה יכול להיות…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
    .string "הרגע הגענו לכאן לחופשת\n"
    .string "ירח הדבש שלנו.\p"
    .string "במקרה ראינו פוקימון מסוג דרקון\n"
    .string "עף גבוה בשמיים.\p"
    .string "האם פוקימונים מגניבים כאלה חיים\n"
    .string "באזור הואן?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
    .string "בירח הדבש שלנו, נשבענו לראות כמה\n"
    .string "שיותר פוקימונים נדירים שאפשר.\p"
    .string "אז שמחנו לראות פוקימון נדיר\n"
    .string "ברגע שהגענו.\p"
    .string "כלומר, אנחנו לגמרי מאושרים!$"

