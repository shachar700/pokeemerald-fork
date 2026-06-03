MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "הכוח שטמון במטאוריט…\p"
	.string "על ידי הגברת הכוח שלו באמצעות\n"
	.string "המכונה הזו, הפעילות הגעשית של הר\l"
	.string "הארובה תתעצם באופן מיידי…\p"
	.string "האנרגיה שלו תגדל עמוק בתוך\n"
	.string "הלוע ו…\l"
	.string "פופופו…$"

MtChimney_Text_MaxieIntro:
	.string "מקסי: המ?\n"
	.string "מי את{EMIT_HEY}?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "שמעתי את ארצ'י מתלונן על ילד{ADD_HEY}\n"
	.string "שמתערב{ADD_TAF} בענייני צוות אקווה.\l"
	.string "בטח הוא התכוון אליך.\p"
	.string "המפ! אז את{EMIT_HEY} חושב{ADD_TAF} להתערב\n"
	.string "גם אצלנו, צוות מגמה?\p"
	.string "עכשיו את{EMIT_HEY} תקשיב{ADD_YUD}.\n"
	.string "לפני זמן רב, יצורים חיים השתמשו\l"
	.string "ביבשה כדי לחיות ולצמוח.\p"
	.string "זו הסיבה שהיבשה היא החשובה מכל!\n"
	.string "זהו הבסיס להכל!\p"
	.string "זו הסיבה שצוות מגמה מוקדש\n"
	.string "להרחבת מסת היבשה.\p"
	.string "זה למען קידום נוסף של\n"
	.string "האנושות והפוקימונים!\p"
	.string "ולשם כך, אנחנו צריכים את הכוח של\n"
	.string "מה שישן בתוך ההר הזה…\p"
	.string "או! לא היה צורך שתלמד{ADD_YUD}\n"
	.string "כל כך הרבה.\p"
	.string "אבל, לא משנה!\n"
	.string "אני אלמד אותך את ההשלכות של\l"
	.string "התערבות בתוכנית הגדולה שלנו!$"

MtChimney_Text_MaxieDefeat:
	.string "מה?!\p"
	.string "אני, מקסי, נתפסתי לא מוכן?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "מקסי: אבל, מספיק.\n"
	.string "אני אוותר הפעם.\p"
	.string "אבל אל תחש{EMIT_VAV}ב{ADD_YUD} שזו הפעם האחרונה\n"
	.string "שראית את צוות מגמה.\p"
	.string "פופופו…\p"
	.string "גם בלי המטאוריט, אם נשיג את\n"
	.string "הכדור ההוא… פופופו…$"

MtChimney_Text_TabithaIntro:
	.string "היהיהי!\p"
	.string "אז הגעת עד לכאן!\p"
	.string "אבל את{EMIT_HEY} איחרת מדי!\n"
	.string "אני כבר מסרתי את המטאוריט\l"
	.string "ממפלי המטאור לבוס!$"

MtChimney_Text_TabithaDefeat:
	.string "היהיהי…\p"
	.string "למרות שהפסדתי, אם המנהיג שלנו\n"
	.string "יעיר את הדבר ההוא…$"

MtChimney_Text_TabithaPostBattle:
	.string "בוס, מהר!\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לזה את האנרגיה של המטאוריט!\p"
	.string "היהיהי…$"

MtChimney_Text_Grunt2Intro:
	.string "אנחנו בצוות מגמה עובדים קשה למען\n"
	.string "כולם.\p"
	.string "כמו, אם הכוח של הדבר ההוא יגדיל את\n"
	.string "היבשה, יהיו יותר מקומות לגור.\p"
	.string "כולם יהיו מאושרים!$"

MtChimney_Text_Grunt2Defeat:
	.string "האא?\n"
	.string "למה את{EMIT_HEY} מתכוו{SWAP_NUN}{ADD_TAF} שהפסדתי?$"

MtChimney_Text_Grunt2PostBattle:
	.string "הבוס שלנו אומר, ”זה יעשה את כולם\n"
	.string "מאושרים.“\p"
	.string "אבל למה כולם ממשיכים\n"
	.string "להפריע לנו?$"

MtChimney_Text_Grunt1Intro:
	.string "אם הייתה יותר יבשה, הייתי יכול\n"
	.string "לקבל בית גדול משלי!\p"
	.string "אני הולך לבנות אותו על לבה מוקשחת!$"

MtChimney_Text_Grunt1Defeat:
	.string "החלום שלי על בית גדול…$"

MtChimney_Text_Grunt1PostBattle:
	.string "ילד{ADD_HEY} כמוך, צרי{SWAP_CHAF}{ADD_HEY} להיות\n"
	.string "משפרי{SWAP_TZADIK}{ADD_HEY} מים בגלים!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "צוות אקווה המעצבן הזה…\n"
	.string "הם תמיד מפריעים לתוכניות שלנו!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "מטאוריטים מכילים כוח מדהים!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "מוטב שלא תתעסק איתנו!\p"
	.string "אנחנו מנסים להעיר את הדבר ההוא\n"
	.string "לטובת כולם!$"

MtChimney_Text_AquasNameSimilar:
	.string "אנחנו צוות מגמה!\p"
	.string "הם צוות אקווה!\p"
	.string "זה מרגיז אותי לגמרי שהם משתמשים\n"
	.string "בשם דומה לשלנו!$"

MtChimney_Text_DouseThemInFire:
	.string "כן!\n"
	.string "הטביעו אותם באש!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "אנחנו הולכים להמשיך ליצור עוד יבשה!$"

MtChimney_Text_Bufoh:
	.string "בופו!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ארצ'י: גרר, {PLAYER}!\n"
	.string "הייתי צריך לנחש שתופיע!\p"
	.string "רא{EMIT_HEY}{ADD_YUD} בעצמך מה הפנאטים\n"
	.string "מצוות מגמה זוממים!\p"
	.string "הם מנסים להחדיר את הכוח של\n"
	.string "המטאוריט הגנוב אל הר הגעש!\p"
	.string "לעשות דבר כזה יגרום להתפרצות\n"
	.string "הר הגעש!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ארצ'י: גרר…\p"
	.string "אני רוצה לעצור את מקסי,\n"
	.string "אבל אני לא יכול!\p"
	.string "בטח לא כשאני עסוק בקרב\n"
	.string "נגד שלושה יריבים בבת אחת!$"

MtChimney_Text_ArchieThankYou:
	.string "ארצ'י: {PLAYER}!\n"
	.string "תודה לך!\p"
	.string "בעזרתך, סיכלנו את התוכנית ההרסנית\n"
	.string "של צוות מגמה!\p"
	.string "אבל… את{EMIT_HEY}…\n"
	.string "בצד של מי את{EMIT_HEY}?\p"
	.string "אה, זה לא משנה.\p"
	.string "אנחנו נשאר ערניים ונמשיך\n"
	.string "ברדיפה אחרי צוות מגמה.\p"
	.string "{PLAYER}, אנחנו ניפגש שוב!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "ארור… צוות מגמה עולה עלינו במספר!\n"
	.string "אנחנו לא יכולים לעמוד בקצב שלהם!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "אם הם ירחיבו את היבשה, יהיו\n"
	.string "פחות בתי גידול לפוקימוני מים!$"

MtChimney_Text_MagmasNameSimilar:
	.string "אנחנו צוות אקווה!\p"
	.string "הם צוות מגמה!\p"
	.string "זה שורף לי שפשוט הם משתמשים בשם\n"
	.string "כל כך מבלבל!$"

MtChimney_Text_Bushaa:
	.string "בושאא!$"

MtChimney_Text_LavaCookiesJust200:
	.string "עוגיות לבה הן המומחיות המקומית\n"
	.string "של הר צ'הארובה.\p"
	.string "תנס{EMIT_HEY}{ADD_YUD} אחד. זה רק ¥002.$"

MtChimney_Text_ThankYouDear:
	.string "תודה לך, יקיר{ADD_TAF}י!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "או, יקיר{ADD_TAF}י. אי אפשר לקנות דבר אם\n"
	.string "אין לך כסף.$"

MtChimney_Text_OhFineThen:
	.string "או, טוב אם כך.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "מטאוריט מותקן על מכונה\n"
	.string "מסתורית…\p"
	.string "נראה שהמכונה אוגרת\n"
	.string "אנרגיה במטאוריט.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "מטאוריט מותקן על מכונה\n"
	.string "מסתורית…\p"
	.string "האם את{EMIT_HEY} רוצה להסיר את המטאוריט?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} הסיר{ADD_HEY} את המטאוריט\n"
	.string "מהמכונה המסתורית.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} השאיר{ADD_HEY} את המטאוריט במקום\n"
	.string "שבו הוא היה.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "המכונה המסתורית הזו…\n"
	.string "היא לא מגיבה בכלל.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} מעבר משונן\n"
	.string "העיר לברידג' קדימה$"

MtChimney_Text_ShelbyIntro:
	.string "הייתי במעיינות החמים\n"
	.string "ורעננתי את העצמות העייפות שלי.\l"
	.string "כרגע אני מרגישה חזקה!$"

MtChimney_Text_ShelbyDefeat:
	.string "או, אלוהים.\n"
	.string "את{EMIT_HEY} באמת משהו!$"

MtChimney_Text_ShelbyPostBattle:
	.string "טוב, טוב, הפסדתי. אני לא יכולה לקרוא\n"
	.string "לעצמי מומחית עכשיו, נכון?$"

MtChimney_Text_ShelbyRegister:
	.string "תודה לך, ילד{ADD_HEY}. זה היה כיף, כאילו\n"
	.string "נלחמתי בנכד שלי.\p"
	.string "בבקשה, בוא{ADD_YUD} לבקר אותי שוב\n"
	.string "לקרב חוזר.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "אם את{EMIT_HEY} יכול{ADD_HEY} לחבר את לבך עם ליבם\n"
	.string "של הפוקימונים שלך, ובכן, את{EMIT_HEY} אמור{ADD_HEY}\l"
	.string "להיות מסוגל{ADD_TAF} להשיג דברים גדולים.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "או, אלוהים.\n"
	.string "את{EMIT_HEY} באמת משהו!$"

MtChimney_Text_ShelbyPostRematch:
	.string "אולי לבך הפך לאחד\n"
	.string "עם ליבם של הפוקימונים שלך.$"

MtChimney_Text_MelissaIntro:
	.string "יש בי את האש, מותק.\n"
	.string "אני לא יכולה לסבול את זה! אני חייבת להילחם!$"

MtChimney_Text_MelissaDefeat:
	.string "אוו, זה היה קרב לוהט ושורף!$"

MtChimney_Text_MelissaPostBattle:
	.string "החום של הר הארובה מחמם\n"
	.string "אותי, מותק!$"

MtChimney_Text_SheilaIntro:
	.string "סוף סוף הגעתי להר הארובה.\n"
	.string "אני רוצה לגרום לפוקימון שלי להילחם!$"

MtChimney_Text_SheilaDefeat:
	.string "הדרך שבה את{EMIT_HEY} נלח{SWAP_MEM}{ADD_TAF}…\n"
	.string "זה כמו התפרצות של הר הארובה!$"

MtChimney_Text_SheilaPostBattle:
	.string "כפי שאמרתי, סוף סוף הגעתי להר\n"
	.string "הארובה. יהיה חבל אם\l"
	.string "אני רק אעשה קצת תצפיות…\p"
	.string "אני רוצה לערוך כמה קרבות ולקנות\n"
	.string "עוגיות כמזכרות.$"

MtChimney_Text_ShirleyIntro:
	.string "מאז שהתרחצתי במעיינות החמים,\n"
	.string "אני מרגישה נהדר!\l"
	.string "אני בטוחה שאני הולכת לנצח!$"

MtChimney_Text_ShirleyDefeat:
	.string "יאוץ'!\n"
	.string "אני מקבלת צמרמורת מחוץ למים.$"

MtChimney_Text_ShirleyPostBattle:
	.string "אני אצטרך לטבול שוב\n"
	.string "במעיינות החמים. רוצה להצטרף אליי?\p"
	.string "סתם צוחקת!$"

MtChimney_Text_SawyerIntro:
	.string "זהו הר נהדר! יש כאן שפע של\n"
	.string "אנשים חמים לחברה!$"

MtChimney_Text_SawyerDefeat:
	.string "הו, גם את{EMIT_HEY} גחל{ADD_TAF} אמיתי{ADD_TAF}!$"

MtChimney_Text_SawyerPostBattle:
	.string "אני חושב שאני צריך טבילה במעיין\n"
	.string "החם של לברידג' עם המקומיים!$"

MtChimney_Text_SawyerRegister:
	.string "אני אוהב כדורי אש קטנים כמוך.\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לרשום אותך בפוקינווט שלי.$"

MtChimney_Text_SawyerRematchIntro:
	.string "אני מוקף בשמחה באנשים חמים\n"
	.string "בסביבה הזו. אני לא אפסיד!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "אלוהים, את{EMIT_HEY} עדיין אותה\n"
	.string "גחל{ADD_TAF} כמו קודם!$"

MtChimney_Text_SawyerPostRematch:
	.string "למעשה, ממש חם כאן.\n"
	.string "אני לבוש יותר מדי לאזור הזה.$"

