MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	bufferspeciesname STR_VAR_1, SPECIES_GROUDON
	bufferspeciesname STR_VAR_2, SPECIES_KYOGRE
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "לא! הבריונים האלה מצוות מגמה הגיעו\n"
	.string "לכאן לפנינו!\p"
	.string "אנחנו לא יכולים לפגר מאחור!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "חשבתי שאת{EMIT_HEY} מהמגמאים\n"
	.string "שבמקרה חזר{ADD_HEY}…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "כן, אז את{EMIT_HEY} חזק{ADD_HEY}…\n"
	.string "אבל יש הרבה מאיתנו!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "הא!\n"
	.string "חבל לך!\p"
	.string "אם היית בא{ADD_HEY} קודם, היית צרי{SWAP_CHAF}{ADD_HEY}\n"
	.string "להילחם רק בצוות מגמה החלשלוש.\p"
	.string "אבל מכיוון שהגעת עכשיו, את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY}\n"
	.string "להתמודד מולנו, הקשוחים!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "אוחח… הייתי צריך לתת לך להתמודד\n"
	.string "מול צוות מגמה קודם…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "את{EMIT_HEY} לא יודע{ADD_TAF} כלום!\n"
	.string "אז למה את{EMIT_HEY} מתעסק{ADD_TAF} איתנו?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "את{EMIT_HEY}…\n"
	.string "ראינו אותך בהר הארובה.\p"
	.string "את{EMIT_HEY} לא שיי{SWAP_CHAF}{ADD_TAF} לאף אחד מהצוותים,\n"
	.string "אז למה שתהי{EMIT_HEY}{ADD_YUD} כאן?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "אם את{EMIT_HEY} הול{SWAP_CHAF}{ADD_TAF} להתעסק עם מישהו,\n"
	.string "שזה יהיה צוות מגמה…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "איח, זה לא משנה!\n"
	.string "קנינו לנו קצת זמן!\p"
	.string "הבוס בטח חטף את מה\n"
	.string "שהוא רדף אחריו!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "או, אני יודעת!\n"
	.string "ניסית להצטרף לצוות מגמה,\l"
	.string "אבל הם לא קיבלו אותך!\p"
	.string "טוב, אל תחש{EMIT_VAV}ב{ADD_YUD} שאנחנו ניתן לך\n"
	.string "להצטרף לצוות אקווה שלנו!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "אם את{EMIT_HEY} כל כך רוצה להצטרף לצוות אקווה,\n"
	.string "אנחנו יכולים לשקול את זה…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "יש לנו שילוב נהדר של חברי\n"
	.string "צוות שלנו והמנהיג שלנו.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ארצ'י: מקסי מצוות מגמה הקדים\n"
	.string "אותנו, אבל גם אנחנו קיבלנו את מה שרצינו.\p"
	.string "הכדור האדום שנשמר בהר המוקד…\n"
	.string "אני, ארצ'י, מחזיק בו עכשיו!\p"
	.string "פופופו… עכשיו אנחנו יכולים להגשים\n"
	.string "את מטרתנו הסופית!\p"
	.string "אוקיי, צוות!\n"
	.string "אנחנו מסתלקים!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "או, לא…\n"
	.string "זה לא יכול לקרות…\p"
	.string "לא רק הכדור הכחול, אלא אפילו\n"
	.string "הכדור האדום נלקח…\p"
	.string "אסור שהכדור הכחול והכדור האדום\n"
	.string "ייפרדו. הם שייכים יחד.\p"
	.string "מה הגברים האלה מנסים לעשות עם\n"
	.string "שני הכדורים?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "או, כן. האם צוות מגמה היה זה שבא\n"
	.string "ולקח את הכדור הכחול ראשון?\p"
	.string "טוב, בחיפזונם, הם השאירו את זה\n"
	.string "מאחור.\p"
	.string "אני לא יכול לדמיין מה בדיוק זה\n"
	.string "יכול להיות.\p"
	.string "הייתי רוצה שתקבל{ADD_YUD} את זה.\n"
	.string "אולי זה יהיה שימושי בדרך כלשהי.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "הכדור הכחול והכדור האדום נלקחו על ידי\n"
	.string "הגברים המרושעים האלה…\p"
	.string "אסור שהם ייפרדו לעולם…\n"
	.string "אני חושש שמשהו נוראי יקרה…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "או, אלוהים אדירים…\p"
	.string "את{EMIT_HEY} אומר{ADD_TAF} שגם {STR_VAR_1} וגם {STR_VAR_2}\n"
	.string "הועררו?\p"
	.string "נאמר כי הכדור הכחול והכדור האדום\n"
	.string "השקיטו את זעמם של שני\l"
	.string "הפוקימונים…\p"
	.string "נאמר גם שהבעלים האמיתי\n"
	.string "של הכדורים עדיין קיים.\p"
	.string "עם זאת, אף אחד לא יודע מי, או למה\n"
	.string "בדיוק, שייך הכדורים.\p"
	.string "זה יכול להיות אדם, או אולי\n"
	.string "פוקימון, אבל אף אחד לא יודע.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "שני הגברים שלקחו את הכדורים שבו\n"
	.string "להחזיר אותם בכוחות עצמם.\p"
	.string "הגברים האלה…\n"
	.string "אולי הם לא כל כך רעים אחרי הכל…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "התגלמות היבשה, הים,\n"
	.string "והשמיים…\p"
	.string "זה נאמר שהם זהותם של\n"
	.string "הפוקימונים העל-קדומים…\p"
	.string "באותו אופן של בני אדם ופוקימונים\n"
	.string "יש חיים, גם העולם שלנו,\l"
	.string "חי…\p"
	.string "הפוקימונים העל-קדומים לימדו\n"
	.string "אותנו את זה…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "הר המוקד הוא המקום בו אנו מרגיעים את הרוחות\n"
	.string "של פוקימונים שנפטרו…\p"
	.string "זהו מקום גבוה שבו אפשר\n"
	.string "לראות את כל הואן…\p"
	.string "רוחות הפוקימונים חסרות הגוף\n"
	.string "בטח מוצאות נחמה כאן…\p"
	.string "האם זה צירוף מקרים שאת{EMIT_HEY} כאן…\p"
	.string "האם תקשיב{ADD_YUD} לסיפור שלי? סיפור המסופר\n"
	.string "מזה זמן רב במחוז הואן?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "זה קרה לפני הרבה, הרבה זמן…\p"
	.string "העולם היה שרוי במאבק עז\n"
	.string "בין פוקימוני היבשה\l"
	.string "לבין פוקימוני הים…\p"
	.string "פוקימוני היבשה הרימו\n"
	.string "הרים ויצרו יבשות…\p"
	.string "פוקימוני הים הרימו גלים עצומים\n"
	.string "וחצבו אוקיינוסים…\p"
	.string "הדו-קרב העז שלהם השתולל ללא סוף.\p"
	.string "העולם נבלע בשריפות\n"
	.string "עצומות ובסערות אכזריות.\p"
	.string "הכדור הכחול והכדור האדום הביאו\n"
	.string "קץ לאסון.\p"
	.string "אור נשפך משני הכדורים\n"
	.string "והרגיע את היריבים הזועמים.\p"
	.string "הזוג, שהפך לצייתן, צלל עמוק לתוך\n"
	.string "הים שבו הם נעלמו\l"
	.string "בסופו של דבר…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "אני מבין…\n"
	.string "טוב, גם זה בסדר…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "מקסי: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "זה התפקיד שלי להעביר את האגדות\n"
	.string "של הואן לדורות הבאים.\p"
	.string "והמשבר שהסתיים זה עתה\n"
	.string "בסוטופוליס כתב מחדש אגדה…\p"
	.string "האם יש לך זמן לשמוע את האגדה\n"
	.string "החדשה של הואן?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "זה קרה לפני הרבה, הרבה זמן…\p"
	.string "העולם היה שרוי במאבק עז\n"
	.string "בין פוקימוני היבשה\l"
	.string "לבין פוקימוני הים…\p"
	.string "פוקימוני היבשה הרימו\n"
	.string "הרים ויצרו יבשות…\p"
	.string "פוקימוני הים הרימו גלים עצומים\n"
	.string "וחצבו אוקיינוסים…\p"
	.string "הדו-קרב העז שלהם השתולל ללא סוף.\p"
	.string "העולם נבלע בשריפות\n"
	.string "עצומות ובסערות אכזריות.\p"
	.string "זה היה הרגע שבו הפוקימון של\n"
	.string "השמיים ירד מסערה.\p"
	.string "הפוקימון, זוהר ירוק עז,\n"
	.string "הרגיע את שני הפוקימונים הזועמים.\p"
	.string "אז, לאחר שמילא את חובתו, הפוקימון\n"
	.string "הירוק עף לשחקים הרחוקים…$"

