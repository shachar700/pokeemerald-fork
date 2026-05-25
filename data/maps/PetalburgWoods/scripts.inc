PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	bufferspeciesname STR_VAR_1, SPECIES_SHROOMISH
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	bufferspeciesname STR_VAR_1, SPECIES_SHROOMISH
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "המממ…\n"
	.string "לא מוצא אף אחד…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "שלום, ראית פוקימון כלשהו\n"
	.string "בשם {STR_VAR_1} מסתובב פה?\p"
	.string "אני ממש אוהב את הפוקימון הזה.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "התכוונתי לארוב לך, אבל\n"
	.string "היית חייב להתעקב ביערות פטלבורג\l"
	.string "לנצח, נכון?\p"
	.string "נמאס לי לחכות, אז הנה אני!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "אתה! חוקר של דבון!\p"
	.string "תביא לי את הניירות האלו!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "איייי!\p"
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF} פוקימון, נכון?\n"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לעזור לי, בבקשה!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "הא? מה את{EMIT_HEY} חושב{ADD_TAF} שאת{EMIT_HEY} עושה?\n"
	.string "מה, את{EMIT_HEY} מתכוו{SWAP_NUN}{ADD_TAF} להגן עליו?\p"
	.string "אף אחד שמתעסק עם צוות אקווה\n"
	.string "לא מקבל שום רחמים, אפילו לא ילד{ADD_YUD}!\p"
	.string "בוא{ADD_YUD} נילחם!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "את{EMIT_HEY} צוחק{ADD_TAF} עליי! את{EMIT_HEY} חזק{ADD_HEY}!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "גררר… יש לך מעין חוצפה\n"
	.string "להתערב בעניינים של צוות אקווה!\l"
	.string "בוא{ADD_YUD} נילחם שוב!\p"
	.string "הלוואי שיכולתי להגיד את זה, אבל נגמרו\n"
	.string "לי הפוקימונים…\p"
	.string "ו, היי, אנחנו מצוות אקווה \n"
	.string "מחפשים משהו ברסטבורו.\p"
	.string "אני אתן לך ללכת הפעם!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "ווו…\n"
	.string "זה היה קרוב מדי!\p"
	.string "בזכותך הוא לא הצליח לגנוב ממני\n"
	.string "את המסמכים החשובים האלה.\p"
	.string "אני יודע, אני אתן לך כדור רב\n"
	.string "בתור תודה!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "הוא לא אמר, אותו בריון מצוות אקווה\n"
	.string "שהם גם מחפשים משהו ברסטבורו?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "אוי לא! זה משבר!\n"
	.string "אני לא יכול לבזב זמן!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "התיק שלא מלא בפריטים.\n"
	.string "אני לא יכול לתת לך את הכדור הרב הזה.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "תפסתי המון פוקימונים!\p"
	.string "קדימה, קדימה, קדימה!\n"
	.string "צוות פוקימוני חרק שלי!$"

PetalburgWoods_Text_ICouldntWin:
	.string "יש לי את כל הפוקימונים האלה,\n"
	.string "אבל לא הצלחתי לנצח…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "תפסתי מספר פוקימונים.\n"
	.string "עכשיו נגמרו לי הפוכדורים.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "אם את{EMIT_HEY} מביא{ADD_HEY} פוקימון חרק לבית ספר,\n"
	.string "את{EMIT_HEY} ישר נהי{EMIT_HEY}{ADD_YUD}{ADD_TAF} פופולרי{ADD_TAF}!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "אני לא יכול להיות פופולרי אם אני מפסיד.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "אם יש לך פוקימון חרק גדול,\n"
	.string "אנשים מכבדים אותך על זה.$"

PetalburgWoods_Text_IWantRematch1:
	.string "אני רוצה קרב חוזר כשפוקימוני החרק\n"
	.string "שלי יגדלו!\p"
	.string "אני רושם אותך בפוקינווט שלי!$"

PetalburgWoods_Text_IWantRematch2:
	.string "אני רוצה קרב חוזר כשפוקימוני החרק\n"
	.string "שלי יגדלו!\p"
	.string "אני רושם אותך בפוקינווט שלי!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "פוקימוני החרק שלי גדלו.\n"
	.string "אני חוזר להיות פופולרי.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "אני לא יכול להיות פופולרי אם אני מפסיד.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "את{EMIT_HEY} נהי{EMIT_HEY}{ADD_YUD}{ADD_TAF} פופולרי{ADD_TAF} אם יש לך\n"
	.string "פוקימון חזק, נכון?\l"
	.string "אז, התאמנתי חזק.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "היי, את{EMIT_HEY} שם!\n"
	.string "הפוקימונים שלך בסדר?\p"
	.string "אם הפוקימון שלך חלש ואת רוצה להימנע\n"
	.string "מקרבות, תתרחק{ADD_YUD} מדשא גבוהה.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "לפעמים יש דברים על הקרקע גם אם לא רואים\n"
	.string "אותם.\p"
	.string "לכן אני תמיד בודק איפה אני דורך.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "או, נהדר!\n"
	.string "זה התג ממכון רסטבורו!\p"
	.string "את{EMIT_HEY} בטח מאמ{SWAP_NUN}{ADD_TAF}.\n"
	.string "כדאי שתנס{EMIT_HEY}{ADD_YUD} את הפריט הזה.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "זה זרע פלא.\n"
	.string "אם פוקימון מחזיר בפריט הזה,\l"
	.string "מהלכים מסוג עשב מתחזקים.\p"
	.string "חוץ מזרע פלא, נראה לי שיש עוד פריטים\n"
	.string "נוחים שפוקימונים יכולים להחזיק.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "טיפים למאמנים\p"
	.string "כל פוקימון שמופיע אפילו פעם אחת בקרב\n"
	.string "מקבל נקודות ניסיון.\p"
	.string "כדי לגדל פוקימון חלש, שי{SWAP_MEM}{ADD_YUD} אותו בצד שמאל\n"
	.string "ברשימת הצוות.\p"
	.string "ברגע שהקרב מתחיל, תחלי{SWAP_PEY}{ADD_YUD} אותו\n"
	.string "החוצה. הוא יקבל ניסיון מבלי להיפגע.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "טיפים למאמנים\p"
	.string "בנוסף לנקודות חיים (נ”ח), לפוקימון\n"
	.string "יש גם נקודות כוח (נכ) שמשמשות\l"
	.string "למהלכים בקרב.\p"
	.string "אם לפוקימון נגמר הנכ, צריך לקחת,\n"
	.string "אותו למרכז הפוקימונים.$"

