MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "יו, מה שלומך, {PLAYER}\n"
	.string "אלו{SWAP_PEY}{ADD_HEY} שבדרך?\p"
	.string "מנהיגי המכון כאן משתמשים\n"
	.string "בפוקימונים מסוג על חושי.\p"
	.string "אם את{EMIT_HEY} הולך נגדם עם\n"
	.string "פוקימונים מסוג לחימה או רעל,\l"
	.string "הם יגרמו לנזק נוראי!\p"
	.string "בנוסף, הם יתקפו אותך עם\n"
	.string "התקפות משולבות מדהימות.\p"
	.string "אם את{EMIT_HEY} רוצה לנצח, תצטר{SWAP_CHAF}{ADD_YUD} להראות\n"
	.string "להם כמה את{EMIT_HEY} מחובר{ADD_TAF} לפוקימון\l"
	.string "שלך. ל{SWAP_CHAF}{ADD_YUD} על זה!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "ואו, את{EMIT_HEY} מדהי{SWAP_MEM}{ADD_HEY}!\n"
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF} נהדר{ADD_TAF}!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "קרבות תלויים בכוח של הרוח\n"
	.string "שלך! חלשי הרוח לעולם לא ינצחו!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "הפסדתי!\n"
	.string "אני חייב לחשל את רוחי שוב!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "ההססנים מפסידים.\n"
	.string "זו האזהרה שלי לך.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "ת{SWAP_NUN}{ADD_YUD} לי לראות את הכישרון שלך!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "יש לך כישרון מרהיב!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "אם יש בעולם ילדי פלא,\n"
	.string "אז מנהיגי המכון שלנו הם כאלה!\p"
	.string "עם זאת, את{EMIT_HEY} עשוי{ADD_HEY} להיות מוכשר{ADD_TAF}\n"
	.string "יותר מהם אפילו…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "פופופופו… תראה אותי מרחף\n"
	.string "פוכדור בכוח טלקינטי!\p"
	.string "וורוואאאאאאאר!\n"
	.string "… … … … … … …\p"
	.string "לפעמים, אני לא מסונכרן…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "כישורי קרב הפוקימון שלי גם\n"
	.string "לא מסונכרנים!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "פוכדור היה כבד מדי להרמה\n"
	.string "באמצעות כוח על חושי. אבל כדור המוך הזה…\p"
	.string "ווווווווווווווווו!\n"
	.string "… … … … … …\p"
	.string "לא, אני לא מרמה!\n"
	.string "לא נשפתי עליו! באמת!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "כאשר את{EMIT_HEY} מפסיד{ADD_HEY} לי, אל תהי{EMIT_HEY}{ADD_YUD}\n"
	.string "קשה מדי עם עצמך.\p"
	.string "זה לא שאת{EMIT_HEY} חלש{ADD_HEY}--אני פשוט\n"
	.string "חזקה מדי!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "את{EMIT_HEY} פשוט חזק{ADD_HEY} מדי!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "אני לא אהיה מדוכאת בגלל\n"
	.string "ההפסד. אני רק צריכה להתאמן חזק יותר.\p"
	.string "חשיבה חיובית--זו הנקודה החזקה\n"
	.string "שלי!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "אני רואה את זה…\n"
	.string "אני רואה את העתיד שלך…\p"
	.string "אם את{EMIT_HEY} יכול{ADD_HEY} לנצח אותי, אני אגיד לך\n"
	.string "את העתיד שלך!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "אני נכנעת!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "את{EMIT_HEY} תנהל{ADD_YUD} קרב עוצמתי בצורה מחרידה\n"
	.string "עם מנהיגי המכון שלנו…\p"
	.string "התוצאה…\n"
	.string "את{EMIT_HEY} לא תשמע{ADD_YUD} אותה ממני!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "הדרכים שבהן טיילת…\n"
	.string "מה שחווית…\p"
	.string "בוא{ADD_YUD} אליי עם כל מה\n"
	.string "שלמדת!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "טיילת בשביל של גדולה!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "עתיד מזהיר מחכה לאלה שעבדו\n"
	.string "במרץ.\p"
	.string "לאלה שהתעצלו, יש רק\n"
	.string "ייאוש בסוף.\p"
	.string "מה שזורעים קוצרים…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "אפילו בסיכון החיים, אני אנצח\n"
	.string "בקרב הזה!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "מה שאת{EMIT_HEY} עושה…\n"
	.string "זה מחריד אותי…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "איך את{EMIT_HEY} מעז{ADD_HEY} לנצח אותי…\p"
	.string "זו לא תהיה אשמתי אם משהו\n"
	.string "נוראי יקרה לך…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "הוהוהו.\p"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} שאראה לך כמה עקשן\n"
	.string "יכול להיות הסוג העל חושי.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "אוי לי, אוי לי!\n"
	.string "סגנון הקרב שלך פנטסטי!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "אני… אני לא נותן להפסד לבלבל אותי,\n"
	.string "לא משנה כמה גרוע.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "ת{SWAP_NUN}{ADD_YUD} לי להראות לך זמן נוראי לחלוטין,\n"
	.string "מחריד!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "ל-לאאאא!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "החיוניות שלך מדבקת!\n"
	.string "תתרחק{ADD_YUD} ממני מהר!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "אני אולי עברתי את שיאי, אבל אני מציע\n"
	.string "שלא תתנשא{ADD_YUD} עליי.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "אה, את{EMIT_HEY} גדוש{ADD_HEY} בכוח\n"
	.string "של הנעורים!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "זה נראה שלא יכולתי להתגבר\n"
	.string "על האנרגיה הצעירה שלך.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "את{EMIT_HEY} לא מגיע{ADD_HEY} עד הסוף!\n"
	.string "לא אם אני יכול לעזור לזה!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "איך את{EMIT_HEY} יכול{ADD_HEY} להיות כל כך חזק{ADD_HEY}\n"
	.string "בצורה מגוחכת?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "המפ! את{EMIT_HEY} אולי חזק{ADD_HEY}, אבל את{EMIT_HEY} לא\n"
	.string "מתאי{SWAP_MEM}{ADD_HEY} לסוג העל חושי!\p"
	.string "הדרך שבה את{EMIT_HEY} נלח{SWAP_MEM}{ADD_TAF} היא איכשהו אכזרית!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "וורוואאר! תטע{SWAP_MEM}{ADD_YUD} את הכוח הקשוח של הפוקימון\n"
	.string "העל שלי בקרבות!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "או!\n"
	.string "גמור!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "בסדר! אני חושב שאפתח כוח פוקימון\n"
	.string "בלתי מנוצח ומיוחד בפעם הבאה.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "טייט: היהיהי… הופתעת?\p"
	.string "ליזה: פופופו… הופתעת?\p"
	.string "טייט: שיש שני מנהיגי מכון?\n"
	.string "ליזה: שיש שני מנהיגי מכון?\p"
	.string "טייט: אנחנו תאומים!\n"
	.string "ליזה: אנחנו תאומים!\p"
	.string "טייט: אנחנו לא צריכים לדבר כי…\n"
	.string "ליזה: כל אחד מאיתנו יכול לדעת מה…\p"
	.string "טייט: השני חושב…\n"
	.string "ליזה: הכל במוחנו!\p"
	.string "טייט: השילוב הזה שלנו…\n"
	.string "ליזה: את{EMIT_HEY} יכול לנצח אותו?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "טייט: מה?! השילוב שלנו…\n"
	.string "ליזה: נופץ לרסיסים!\p"
	.string "טייט: זה לא יכול להימנע. ניצחת…\n"
	.string "ליזה: אז, כהכרה, קח{ADD_YUD} את זה.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} קיבל{ADD_HEY} את תג התודעה\n"
	.string "מטייט וליזה.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "טייט: תג התודעה משפר את ההתקפה מ.\n"
	.string "ואת ההגנה מ. של פוקימונים.\p"
	.string "ליזה: זה גם מאפשר לך להשתמש במהלך המ”נ\n"
	.string "צלילה מחוץ לקרב.\p"
	.string "טייט: את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לקחת גם את זה.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "טייט: המ”מ40 הזה מכיל…\n"
	.string "ליזה: ראש שקט!\p"
	.string "טייט: זה מעלה התקפה מ. ו…\n"
	.string "ליזה: זה מעלה הגנה מ.!\p"
	.string "טייט: זה מהלך שמושלם…\n"
	.string "ליזה: לפוקימונים על חושיים!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "מנהיגי המכון טייט וליזה נרשמו\n"
	.string "בפוקינווט.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "טייט: נראה שהקשר בינך\n"
	.string "לפוקימונים שלך חזק בהרבה\l"
	.string "מהקשר שלנו כתאומים.\p"
	.string "ליזה: את{EMIT_HEY} תהפ{EMIT_VAV}{SWAP_CHAF}{ADD_YUD} לחזק{ADD_HEY} אפילו יותר!\n"
	.string "נלחמנו בך, אז אנחנו יודעים.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "טייט: היהיהי… הופתעת?\p"
	.string "ליזה: שיש שני מנהיגי מכון?\p"
	.string "טייט: אופס, יש לך רק פוקימון…\n"
	.string "ליזה: אחד שיכול להילחם.\p"
	.string "טייט: אנחנו לא יכולים להילחם בצורה כזו!\p"
	.string "ליזה: אם את{EMIT_HEY} רוצה לאתגר אותנו,\n"
	.string "תביא{ADD_YUD} עוד פוקימונים.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "מכון הפוקימונים של העיר מוסדיפ$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "מכון הפוקימונים של העיר מוסדיפ\p"
	.string "מאמנים מוסמכים בידי ליזה וטייט:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "טייט: פוקימונים…\n"
	.string "ליזה: פוקימונים…\p"
	.string "טייט: על ידי שינוי הרכב הקבוצה…\n"
	.string "ליזה: סגנון הקרב משתנה.\p"
	.string "טייט: אבל אני…\n"
	.string "ליזה: אבל אני…\p"
	.string "טייט: אני תמיד אהיה עם ליזה!\n"
	.string "ליזה: אני תמיד אהיה עם טייט!\p"
	.string "טייט: השילוב שלנו…\n"
	.string "ליזה: אנחנו נראה לך שוב ושוב!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "טייט: את{EMIT_HEY} והפוקימונים שלך…\n"
	.string "ליזה: זה כאילו הייתם אחים!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "טייט: את{EMIT_HEY} יכול{ADD_HEY} להפיל אותנו,\n"
	.string "אבל אנחנו אף פעם לא נישאר למטה!\p"
	.string "ליזה: כי שנינו,\n"
	.string "אנחנו תמיד תומכים אחת בשני!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "טייט: חזרת שוב…\n"
	.string "ליזה: חזרת שוב…\p"
	.string "טייט: כדי לתת לנו קרב חוזר.\n"
	.string "ליזה: כדי לתת לנו קרב חוזר.\p"
	.string "טייט: אבל…\n"
	.string "ליזה: לקרב שלנו…\p"
	.string "טייט: הבאת רק פוקימון אחד!\n"
	.string "ליזה: הבאת רק פוקימון אחד!\p"
	.string "טייט: אנחנו צריכים שתביא{ADD_YUD} לפחות…\n"
	.string "ליזה: שני פוקימונים כשתחז{EMIT_VAV}ר{ADD_YUD}.$"
