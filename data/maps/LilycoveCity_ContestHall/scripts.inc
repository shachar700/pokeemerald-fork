@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_ZUBAT
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_AZURILL
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applywaitmovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "הפוקימון הזה זכה בתחרות היופי\n"
	.string "כאן לפני כן.\p"
	.string "טוב, נחש{ADD_YUD} מה? היום, גרמתי לו\n"
	.string "לזכות בתחרות חוכמה!\p"
	.string "היכולות שלי מפחידות אפילו אותי…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "נכנסתי לכמה תחרויות,\n"
	.string "אז אני רואה איך הדברים עובדים.\p"
	.string "אם את{EMIT_HEY} נמצא{ADD_TAF} בתחרות מגניבות,\n"
	.string "מהלכים מגניבים נחשבים כמושכים.\p"
	.string "אבל מהלכים חכמים ומהלכים חמודים\n"
	.string "לא נחשבים כל כך, למשל.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "לאותו צעיר שניצח קודם לכן היה\n"
	.string "הרבה פוקיגושים שונים.\p"
	.string "האם אפשר לנצח אם יש לך כל כך הרבה\n"
	.string "מהדברים האלה?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "וואה, זה לא מקום עצום!\p"
	.string "המתח באוויר… זה לא\n"
	.string "כמו אולם תחרות נידח.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "מנחה: אוקיי, פוקימונים חכמים\n"
	.string "והמאמנים שלהם, האם אתם מוכנים?!\p"
	.string "תנו את ההופעה הטובה ביותר שלכם!\n"
	.string "בואו נמשוך!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "שופט: האם את{EMIT_HEY} נהנ{EMIT_HEY}{ADD_YUD}{ADD_TAF} מהתחרות הזו?\p"
	.string "תחז{EMIT_VAV}ר{ADD_YUD} עם שלושה חברים,\n"
	.string "וכולכם תוכלו להיכנס לתחרות!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "אייאייאייאיי…\n"
	.string "נכנסתי לתחרות הלא נכונה.\p"
	.string "הכנסתי את הפוקימון הקשוח הזה\n"
	.string "לתחרות חוכמה…\p"
	.string "קדימה, הרשם אותם עם ריסוק סלע\n"
	.string "שנראה חכם.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "ביליתי שנים רבות, ואת כל\n"
	.string "החוכמה שלי, בגידול הפוקימון הזה\l"
	.string "כדי שיהיה חכם.\p"
	.string "הוא לא יובס בקלות על ידי פוקימון\n"
	.string "של גור צעיר כלשהו.\p"
	.string "אשתי היקרה, האם את רואה את זה?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "הנה זה!\p"
	.string "אם הפוקימון שלי ישלוף מהלך חכם עכשיו,\n"
	.string "ההתרגשות של הקהל תגיע לשיא!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "או, יקירי, לא!\p"
	.string "המהלך התעלקות של {STR_VAR_1} המתוק שלי כל כך\n"
	.string "חמוד שהמשכתי להשתמש בו שוב ושוב!\p"
	.string "אבל האנשים הרשעים האלה לא מעריכים\n"
	.string "את זה בכלל!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "קייאההה! אתה יפה, סבא!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "גם כאשר מאמנים מכניסים את אותו\n"
	.string "סוג של פוקימון, נראה שכולם משתמשים\l"
	.string "במהלכים שונים עבור המשיכות.\p"
	.string "זה בדיוק כמו שיש לאנשים\n"
	.string "סגנונות שונים לקרב.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "אני חושב שהפוקימונים נראים חכמים\n"
	.string "יותר מהמאמנים שלהם. בהרבה.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "כשכל הדברים נאמרים ונעשים, אני עדיין אוהב\n"
	.string "תחרויות חוכמה.\p"
	.string "הצבע הירוק האינטלקטואלי הזה…\n"
	.string "הוא כל כך… כל כך… מגניב.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "מנחה: האם גם את{EMIT_HEY} נכנס{ADD_TAF} לתחרות היופי?\n"
	.string "בהצלחה!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "שופט: אה, כל פוקימון כאן הוא\n"
	.string "דוגמה ליופי טהור!\p"
	.string "וואי, כמעט שכחתי לנקד אותם!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "פוקימון יפה כזה…\n"
	.string "אין עוד אחד כמוהו.\p"
	.string "העיניים של כולם יהיו נעוצות\n"
	.string "ביופי שלי.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "וואאאאאה!\p"
	.string "הברשתי וטיפחתי את הפוקימון שלי\n"
	.string "בזהירות עבור התחרות הזו…\p"
	.string "אבל הגזמתי…\n"
	.string "הפרווה של הפוקימון שלי הפכה למדובללת…\p"
	.string "מה עליי לעשות?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "הקרן זוהרת הזאת כל כך מסנוורת,\n"
	.string "שהשופט לא יוכל לראות אותה.\p"
	.string "אה, רגע שנייה…\n"
	.string "אם כך, זה יהיה חסר משמעות!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "הפוקימון היפה הזה נראה בדיוק כמוני\n"
	.string "כשהייתי צעירה יותר.\p"
	.string "ברגע שאמרתי את זה, בעלי\n"
	.string "ירק את הקפה שהוא שתה.\p"
	.string "האם אמרתי משהו מצחיק?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "את{EMIT_HEY} יודע{ADD_TAF}, אם אני מנצחת\n"
	.string "בתחרות יופי, זה בהחלט עושה אותי\l"
	.string "שמחה. יותר מהרגיל, בכל אופן.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "וואהאהאהאה!\p"
	.string "האם תעי{SWAP_PEY}{ADD_YUD} מבט בכל הפוקימונים\n"
	.string "היפים האלה!\l"
	.string "אני פשוט אוהב את כל הנוצץ הזה!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} תמיד לנצח רק על בסיס יופי\n"
	.string "בלבד.\p"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לטפח את הפוקימון שלך כך\n"
	.string "שהוא יהיה יפה ומבריק כמו שלי.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "מנחה: או-או! שלום!\n"
	.string "אנחנו באמצע תחרות!\p"
	.string "נא להרשם בדלפק הרישום שלנו\n"
	.string "ותבוא{ADD_YUD}, אוקיי?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "שופט: או, משיכות כאלה מקסימות וחמודות!\p"
	.string "או, אלוהים! איזה משיכת כיסוי מים\n"
	.string "חמודה לחלוטין!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "או, לא… {STR_VAR_1} המתוק שלי הוסח דעת\n"
	.string "על ידי פוקימון אחר.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "הפוקימון שלי מעולם לא ניצח בקרב,\n"
	.string "אבל הכנסתי אותו לתחרות ותיזהר{ADD_YUD}!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "הריקוד עלי כותרת של הפוקימון שלי הוא פלא\n"
	.string "של אלגנטיות.\p"
	.string "אני לא אתן לאף אחד להפריע\n"
	.string "להופעה שלו.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "הפוקימונים של כולם חמודים מאוד.\p"
	.string "עם זאת, אם הפוקימון שלי היה עושה\n"
	.string "משיכה חמודה…\p"
	.string "אני בטוח שזה יהיה הרבה יותר \n"
	.string "חמוד מהאחרים.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "הילד שלי נמצא בתחרות הזו.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "קדימה, יקירי. לך על זה!\n"
	.string "הפוקימון שלך הוא הטוב ביותר!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "אני חושב שהילדה שם\n"
	.string "היא החמודה ביותר בחבורה.\p"
	.string "מה זה? הם שופטים\n"
	.string "פוקימונים לפי המראה שלהם?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "אוו, לראות את כל הפוקימונים החמודים האלה,\n"
	.string "הם גורמים לי לרצות להשיג משלי!\p"
	.string "אני הולך לתפוס כמה!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "במת תחרות יופי\n"
	.string "להתפתות בידי פוקימונים יפים!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "במת תחרות חמידות\n"
	.string "להיות מוקסם בידי פוקימונים חמודים!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "במת תחרות חוכמה\n"
	.string "להתרשם בידי פוקימונים חכמים!$"

