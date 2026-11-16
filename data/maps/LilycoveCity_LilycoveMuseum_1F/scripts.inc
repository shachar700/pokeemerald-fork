LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applywaitmovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applywaitmovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applywaitmovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applywaitmovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} למוזיאון ליליקוב.\p"
	.string "אנא הקד{ADD_YUD}ש{ADD_YUD} זמן להנות מהאוסף\n"
	.string "שלנו של יצירות אומנות פנטסטיות\l"
	.string "המציגות פוקימונים.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "אני האוצר של מוזיאון\n"
	.string "האומנויות היפות הזה.\p"
	.string "זה מחמם את הלב לראות מישהו כזה\n"
	.string "צעיר כמוך במוזיאון שלנו.\p"
	.string "האם כבר צפית באוסף\n"
	.string "הציורים שלנו?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "אה, אם כן, אז לא אפריע לך.\n"
	.string "בבקשה, קח{ADD_YUD} את הזמן שלך.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "או? אני מאמין שנראה שאת{EMIT_HEY}\n"
	.string "מאמ{SWAP_NUN}{ADD_TAF} פוקימונים.\p"
	.string "האם יש לך עניין גם בציורים?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "אני מבין…\p"
	.string "אני מרגיש כבוד שבאת לבקר\n"
	.string "אותנו למרות זאת.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "אה, מצוין!\n"
	.string "את{EMIT_HEY} כן אוהב{ADD_TAF} ציורים!\p"
	.string "אם כך, האם אוכל לבקש ממך לבוא איתי?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "זהו ציור ישן מאוד.\n"
	.string "הצבע מתקלף פה ושם.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "זהו נוף מוזר עם תפאורה\n"
	.string "ביזארית ופנטסטית.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "זהו ציור של אישה יפה, מחייכת\n"
	.string "עם פוקימון על ברכיה.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "זהו ציור של פוקימון אגדי\n"
	.string "מלפני הרבה זמן.\p"
	.string "האומן צייר את זה מתוך\n"
	.string "דמיון.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "זהו ציור של פוקימוני עשב\n"
	.string "מתנדנדים ברוח.\p"
	.string "נראה שהם נהנים מהליטוף\n"
	.string "העדין של הרוח.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "זהו ציור של פירות יער\n"
	.string "שנראים טעימים.\p"
	.string "הציור הזה יכול לגרום לך להיות רעב!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "זה העתק של פסל מפורסם.\p"
	.string "הוא מתאר פוקימון ציפור עתיק.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "זה פוכדור גדול מגולף מתוך\n"
	.string "אבן שחורה.\p"
	.string "ככל הנראה הוא שימש בפסטיבלים\n"
	.string "בימים עברו.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "זהו לוח אבן ענק החרוט\n"
	.string "בפוקימונים ובטקסט צפוף באותיות\l"
	.string "קטנות של שפה עתיקה,\l"
	.string "בלתי קריאה.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "המממ…\n"
	.string "איזה יצירות בעלות פאר…$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "להילחם עם פוקימונים זה כיף,\n"
	.string "אני מודה לך על כך.\p"
	.string "אבל אסור לשכוח את האהבה שלנו\n"
	.string "לאומנויות היפות.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "מוזיאון האומנות הזה… ובכן, את{EMIT_HEY} יכול{ADD_HEY}\n"
	.string "לראות בו ציורים פנטסטיים רבים.\p"
	.string "והאוצר הוא אדם נפלא.\p"
	.string "בקרב אומנים כמוני, המוזיאון הזה\n"
	.string "הוא השראה.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "הגברת הזו יפה!\n"
	.string "היא כמו אמא!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "הפוקימון הזה מקסים!\n"
	.string "בדיוק כמו הבן הקטן שלנו!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "שמעתי שמוזיאון האומנות הזה קיבל\n"
	.string "כמה ציורים חדשים.\p"
	.string "אז, באופן טבעי מיהרתי לכאן.\p"
	.string "האם הציורים החדשים מוצגים\n"
	.string "בקומה השנייה?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "לאחרונה, האוצר היה\n"
	.string "עליז במיוחד.\p"
	.string "אני בטוח שמשהו טוב קרה לו.\n"
	.string "בהחלט.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "אני שואף לראות הרבה ציורים נהדרים\n"
	.string "כאן וללמוד מהם.\p"
	.string "יש לי חלום שיום אחד היצירה\n"
	.string "שלי תוצג כאן.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "מוזיאון האומנות הפך ליעד\n"
	.string "תיירותי אהוב.\p"
	.string "זה נהדר עבור ליליקוב…\n"
	.string "לא, נהדר עבור מחוז הואן!\p"
	.string "זה מה ששמעתי--מאמן יחיד\n"
	.string "השיג את כל הציורים למעלה.$"

