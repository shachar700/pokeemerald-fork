BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applywaitmovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applywaitmovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applywaitmovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applywaitmovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_SEVIPER
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "זוהי כיפת הקרב!\n"
	.string "הדרך שלך לכוכב העל הבלתי מנוצח!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "זהו מפעל הקרב!\n"
	.string "חפשו את הפוקימונים הקשוחים ביותר!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "זהו נהר הקרב!\n"
	.string "בחרו אחד משלושה נתיבים!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "זהו מגדל הקרב.\p"
	.string "מאמנים מביאים את הפוקימונים\n"
	.string "המגודלים הטובים ביותר שלהם לקרבות\l"
	.string "בסגנון הדחה.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "שלום, את{EMIT_HEY} כאן בשביל המעבורת?\n"
	.string "אפשר לראות את הכרטיס שלך?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "ל{PLAYER} אין כרטיס…\p"
	.string "אני מצטערת מאוד.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} שיהיה לך כרטיס כדי לעלות\n"
	.string "למעבורת.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} הציג{ADD_HEY} את הכרטיס.\p"
	.string "מושלם! זה כל מה שאת{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY}!\p"
	.string "ולאן תרצ{EMIT_HEY}{ADD_YUD} להגיע?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "עיר סלייטפורט, אם כך!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "עיר ליליקוב, אם כך!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "אנא הפל{ADD_YUD}ג{ADD_YUD} איתנו בפעם אחרת!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "אנא על{EMIT_HEY}{ADD_YUD} למעבורת והמת{ADD_YUD}{SWAP_NUN}{ADD_YUD}\n"
	.string "להפלגה.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "אם כן, לאן תרצ{EMIT_HEY}{ADD_YUD} להגיע?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "אני הטוב מכל החברים שלי.\n"
	.string "אבל כאן…\l"
	.string "הייתי חסר תועלת!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "אני רוצה ללכת למגדל הקרב,\n"
	.string "אבל אני לא מוצא אותו למרות שיש לי\l"
	.string "מפה של חזית הקרב.\p"
	.string "המקום הזה פשוט גדול מדי!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "רציתי לקחת אתגר ברגע\n"
	.string "שהגעתי לכאן.\p"
	.string "אבל בדרך, קיבלתי מחלת ים…\n"
	.string "אוררררפ…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "זה לא שכל אחד יכול לבוא\n"
	.string "לכאן, את{EMIT_HEY} יודע{ADD_TAF}?\p"
	.string "רק אותם מאמנים שהוכרו\n"
	.string "כקשוחים מובאים לכאן.\p"
	.string "זו הסיבה שמאמנים רבים אפילו לא\n"
	.string "יודעים על חזית הקרב.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "היי, אח…\p"
	.string "אתה בטוח שאנחנו יכולים לקחת אתגרים\n"
	.string "גם אם אין לנו פוקימונים?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "אה…\n"
	.string "אני בטוח שזה יהיה בסדר.\p"
	.string "אני חושב…\p"
	.string "אבל אתה זוכר את הבחור המפחיד הגדול ההוא?\n"
	.string "הוא אמר, ”אני אשאיל לכם פוקימונים!“$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "זה מפעל הקרב.\n"
	.string "את{EMIT_HEY} יכול{ADD_HEY} לשכור שם פוקימונים חזקים.\p"
	.string "אבל זה גורם לי לתהות.\n"
	.string "מי מגדל את הפוקימונים השכורים האלה?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "אני מפחד להיכנס לנהר הקרב\n"
	.string "בגלל {STR_VAR_1}…\p"
	.string "א-אבל הגעתי עד לכאן, אז אני\n"
	.string "אנסה לכבוש הכל!\l"
	.string "…רעד…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "בוא{ADD_YUD} נשחק אבן, נייר, ומספריים!\n"
	.string "אחת, שתיים, ושלוש!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "יש! ניצחתי!\n"
	.string "אני אקבל את אתגר נהר הקרב!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "או, לא…\n"
	.string "הפסדתי.\p"
	.string "אני מניח שאני לא בר מזל היום.\n"
	.string "אני אדחה את אתגר נהר הקרב שלי\l"
	.string "למחר.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "אני מאמין שאני האדם היחידי כאן,\n"
	.string "שמסיבה לא ידועה כלשהי, היה בוחר\l"
	.string "בדייג על פני קרב.\p"
	.string "הא? אי אפשר לתפוס שום דבר כאן?\n"
	.string "זה מאכזב…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "היום, אני הולך להמשיך להילחם,\n"
	.string "לא משנה מה, עד שאשיג סמל.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "או? את{EMIT_HEY} בדרך לאתגר\n"
	.string "כיפת הקרב?\p"
	.string "אני מאחל לך את כל המזל שבעולם.\n"
	.string "ששנינו ננצח בדרכינו וניפגש\l"
	.string "באתגרים.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "סבא, הנה!\n"
	.string "כיפת הקרב כאן!\l"
	.string "לך תשיג אותם, סבא!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "אה, אז זוהי זירת הקרב?\n"
	.string "אני לא אתן לג'נטלמנים לנצח אותי!\p"
	.string "אבל איפה הכניסה?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "לא היה כאן כלום לפני זמן\n"
	.string "לא רב כל כך.\p"
	.string "אבל, עכשיו תרא{EMIT_HEY}{ADD_YUD} את המקום הזה! מדהים!\n"
	.string "אני אביא את אמא שלי לראות את זה.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "סוף סוף הגעתי לחזית הקרב!\p"
	.string "אני בטוח שאמשוך תשומת לב עם\n"
	.string "המראה והיכולת שלי!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "לעיסה, לעיסה…\p"
	.string "נראה שהכיכר הזו מלאה באנשים\n"
	.string "קשוחים.\p"
	.string "לעיסה, לעיסה…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "קראנץ', לעיסה…\p"
	.string "לפני זמן מה, פגשתי בחורה מבוגרת\n"
	.string "בנהר הקרב.\p"
	.string "היו לה עיניים מפחידות\n"
	.string "בצורה עוינת ממש.\p"
	.string "קראנץ', לעיסה…\p"
	.string "היא התמלאה זעם: ”תפסיק כבר\n"
	.string "לאכול!“ ואז היא הרביצה לי.\p"
	.string "זו הייתה חוויה מפחידה\n"
	.string "ומחרידה, בוודאות.\p"
	.string "קראנץ', לעיסה…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "הא? תקשיב לעצמך!\n"
	.string "זה שטויות!\p"
	.string "וואו, בפעם האחרונה שעודדתי אותו,\n"
	.string "העיניים שלנו נפגשו ועפו ניצוצות!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "מהההההה?!\n"
	.string "פחחח!\p"
	.string "זה קרה רק בגלל\n"
	.string "שבמקרה ישבתי לידך!\p"
	.string "אלוף הכיפה רק הסתכל לכיוון שלנו\n"
	.string "כי העידוד שלי היה כל כך חזק!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "או, תשתקו!\n"
	.string "תנמיכו את הרעש הזה!\p"
	.string "מעריצים מזדמנים צריכים להישאר\n"
	.string "לעודד איזה מנהיג מכון!\p"
	.string "אלוף הכיפה הוא שלי!\n"
	.string "האליל היחידי בשבילי!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "האנשים האלה שמתווכחים שם…\p"
	.string "קשה להאמין, אבל הם היו פעם\n"
	.string "מאמנים, וטובים.\p"
	.string "הם היו קשוחים בצורה בלתי רגילה,\n"
	.string "והם היו מפורסמים, גם כן.\p"
	.string "אבל הם הובסו לחלוטין על ידי\n"
	.string "מאמן מסוים בטורניר.\p"
	.string "הם הובסו כל כך ביסודיות,\n"
	.string "שהם התאהבו במאמן.\p"
	.string "עכשיו הם רק מעריצים של המאמן.\n"
	.string "הם הולכים לעודד את האליל שלהם\l"
	.string "בכיפת הקרב כל יום עכשיו.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "שמעתי שמועה שמישהו ראה\n"
	.string "פוקימון עם זנב ארוך במיוחד\l"
	.string "איפשהו בחזית הקרב.\p"
	.string "הוא בטח מקסים. אני בטוח בזה…\p"
	.string "או, אתגרים יכולים לחכות. אני מרגיש מונע\n"
	.string "למצוא את היצור המקסים!$"

