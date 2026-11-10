SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "כן? אם את{EMIT_HEY} מחפש{ADD_TAF} את סטרן,\n"
	.string "זה אני.\p"
	.string "אה! אלה בטח החלקים שהזמנתי\n"
	.string "ממר סטון מדבון.\p"
	.string "תודה רבה! זה נהדר!\n"
	.string "עכשיו נוכל להתכונן למשלחת שלנו.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "חה חה חה, רגע אחד!\n"
	.string "את החלקים האלה אנחנו לוקחים!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "קפטן סטרן: מ-מה?\n"
	.string "מי אתם בכלל?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "אנחנו צוות אקווה!\p"
	.string "הבוס שלנו רוצה את החלקים האלה!\n"
	.string "סתום את הפה ותעביר אותם הנה!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "אוווווה!\n"
	.string "ילד{ADD_HEY} ניצח{ADD_HEY} אותי!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "אוי, איזה אסון…\n"
	.string "הבוס הולך להשתולל מכעס…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "הממף, נמושה בכיין!\n"
	.string "תן לי לטפל בזה!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "מה?!\n"
	.string "גם אני הפסדתי!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "ומה עכשיו? אם לא נשיג את החלקים,\n"
	.string "אכלנו אותה!\p"
	.string "ארגגג, לא חשבתי שאיזה זאטוט\n"
	.string "יתקע לנו מקלות בגלגלים!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "באתי לראות למה לוקח לכם כל כך\n"
	.string "הרבה זמן לחטוף כמה חלקים, ואתם,\l"
	.string "הפתאים, נתקעתם בגלל ילד{ADD_HEY}?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "אנחנו צוות אקווה,\n"
	.string "ואנחנו אוהבים את הים!\p"
	.string "ואני המנהיג של צוות אקווה,\n"
	.string "ארצ'י!\p"
	.string "למה את{EMIT_HEY} מתערב{ADD_TAF} בענייננו?\p"
	.string "…לא! זה לא ייתכן!\n"
	.string "את{EMIT_HEY} לא מצוות מגמה?\p"
	.string "רגע, זה לא יכול להיות.\n"
	.string "את{EMIT_HEY} לא לבוש{ADD_HEY} כמו אחד מהם.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "פוקימונים, אנשים… כל החיים\n"
	.string "תלויים בים.\p"
	.string "לכן צוות אקווה מקדיש את עצמו\n"
	.string "להרחבת הים.\p"
	.string "את{EMIT_HEY} לא מסכים{ADD_HEY}? מה שאנחנו\n"
	.string "עושים הוא מפעל כביר.\p"
	.string "אה, טוב…\n"
	.string "את{EMIT_HEY} עדיין צעיר{ADD_HEY} מדי בשביל להבין\l"
	.string "את מטרתנו הנעלה.\p"
	.string "אבל אני מזהיר אותך, אל תעז{ADD_YUD}\n"
	.string "להתערב שוב בתוכניות שלנו.\p"
	.string "המחיר שתשל{SWAP_MEM}{ADD_YUD} יהיה\n"
	.string "כבד מאוד!\p"
	.string "ואל תשכח{ADD_YUD} את זה!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "קפטן סטרן: את{EMIT_HEY}…\n"
	.string "אה, נכון, את{EMIT_HEY} {PLAYER}{KUN}…\p"
	.string "בכל אופן, זה היה מצב מתוח!\n"
	.string "תודה שהצלת אותנו!\p"
	.string "אה, כן, כמעט שכחתי שאפילו\n"
	.string "הבאת לי את החלקים מדבון!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "קפטן סטרן: אופס!\n"
	.string "אין זמן לבזבז!\p"
	.string "אנחנו צריכים לצאת למשלחת לקרקעית\n"
	.string "הים ממש בקרוב.\p"
	.string "תודה שוב, אבל עכשיו אני\n"
	.string "חייב ללכת!\p"
	.string "את{EMIT_HEY} מוזמ{SWAP_NUN}{ADD_TAF} להסתובב פה\n"
	.string "ולבדוק את המתקנים שלנו.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "ראיתי פה דגם של ספינה.\p"
	.string "הוא הזכיר לי את הספינה הנטושה\n"
	.string "ליד עיירת דופורד…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "שלא תעז{ADD_YUD} להתרוצץ בתוך\n"
	.string "המוזיאון!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "וואו, הצוללת מדהימה!\n"
	.string "אני רוצה לשוט בה!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "”דגימת איכות מים 1“, כתוב\n"
	.string "על התווית.\p"
	.string "כל הים מחובר, אבל נראה\n"
	.string "שהמים שונים מאזור לאזור.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "”דגימת איכות מים 2“, כתוב\n"
	.string "על התווית.\p"
	.string "האם גם המליחות של מי הים\n"
	.string "שונה מאזור לאזור?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "כדור גומי מתרחב\n"
	.string "ומתכווץ.\p"
	.string "”בים, משקל המים עצמם\n"
	.string "יוצר לחץ.\p"
	.string "”במים רדודים, הלחץ אינו\n"
	.string "כבד במיוחד.\p"
	.string "”אבל במים עמוקים מאוד, הלחץ\n"
	.string "יכול להגיע לעשרות אלפי טונות\l"
	.string "על שטח קטן.“$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "”דגם של אזור הואן“\p"
	.string "זוהי דיורמה מוקטנת של\n"
	.string "אזור הואן.\p"
	.string "איפה עיירת ליטלרוט כאן?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "זוהי תצוגה על זרימת מי הים.\p"
	.string "”ליד קרקעית הים, המים זורמים\n"
	.string "בגלל הבדלים בגורמים\l"
	.string "כמו טמפרטורה ומליחות.“$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "זוהי תצוגה על זרימת מי הים.\p"
	.string "”קרוב לפני השטח, מי הים זורמים\n"
	.string "בזרמים שהרוחות מניעות.“$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "”המעבורת ס.ס גאות\p"
	.string "”דגם מוקטן של הספינה שנבנית\n"
	.string "במספנה של סטרן.“$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "”צוללת החוקר 1\p"
	.string "”העתק של צוללת מתקדמת\n"
	.string "לחקר קרקעית הים.“$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "”תא צלילה\p"
	.string "”העתק של תא קטן ללא צוות\n"
	.string "לחקר קרקעית הים.“$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "”ס.ס אנה\p"
	.string "”העתק של ספינת הפאר\n"
	.string "שמקיפה את העולם.“$"

