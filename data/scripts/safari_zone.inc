SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לצאת מאזור\n"
	.string "הספארי עכשיו?$"

SafariZone_Text_TimesUp:
	.string "דינג-דונג! נגמר הזמן!\n"
	.string "משחק הספארי שלך הסתיים.$"

SafariZone_Text_OutOfBalls:
	.string "אזלו לך כדורי הספארי.\n"
	.string "משחק הספארי שלך הסתיים.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} להניח פוקיגוש\n"
	.string "על מתקן ההאכלה לפוקיגושים?$"

SafariZone_Text_PokeblockStillHere:
	.string "ה{STR_VAR_1} שהשארת\n"
	.string "לפניכן עדיין כאן$"

SafariZone_Text_PokeblockWasPlaced:
	.string "ה{STR_VAR_1} הונח\n"
	.string "על מתקן ההאכלה לפוקיגושים.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לאזור הספארי!\p"
	.string "כאן, תוכל{ADD_YUD} לחזות בסוגים רבים של\n"
	.string "פוקימונים שנדיר לראות בהואן.\p"
	.string "בנוסף, תרא{EMIT_HEY}{ADD_YUD} אותם במצבם הפראי,\n"
	.string "והלא מאולף בסביבתם הטבעית.\p"
	.string "בנוסף, פתחנו את השערים\n"
	.string "למאמני פוקימונים.\p"
	.string "את{EMIT_HEY} מוזמ{SWAP_NUN}{ADD_TAF} לתפוס פוקימונים\n"
	.string "ולשמור אותם!\p"
	.string "היכנס{ADD_YUD} ותיהנ{EMIT_HEY}{ADD_YUD} מאזור הספארי!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לאזור הספארי!\p"
	.string "זו הפעם הראשונה שלך כאן?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "היכנס{ADD_YUD} ותיהנ{EMIT_HEY}{ADD_YUD} מאזור הספארי!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "כשאת{EMIT_HEY} נכנס{ADD_TAF} לאזור הספארי, את{EMIT_HEY}\n"
	.string "מתחיל{ADD_HEY} עם 03 כדורי ספארי\l"
	.string "לתפיסת פוקימונים.\p"
	.string "משחק הספארי מסתיים כשנגמרים לך\n"
	.string "כדורי הספאיר, או לאחר\l"
	.string "שהלכת 005 צעדים.\p"
	.string "היכנס{ADD_YUD} ותיהנ{EMIT_HEY}{ADD_YUD} מאזור הספארי!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "ברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לאזור הספארי!\p"
	.string "כל מה שתוכל{ADD_YUD} לתפוס רק ב-005¥ בלבד!\n"
	.string "האם תרצ{EMIT_HEY}{ADD_YUD} לשחק במשחק הספארי?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "אוקיי.\n"
	.string "נשמח שתשחק{ADD_YUD} בפעם אחרת!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "אין לך מספיק כסף.\n"
	.string "מצטער.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "זה יעלה 005¥, בבקשה.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "הנה כדורי הספארי שלך.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} קיבל{ADD_HEY} 03 כדורי ספארי.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "אנו נודיע לך כשהמשחק שלך\n"
	.string "יסתיים.\p"
	.string "לכן, עד אז, בבקשה תהנ{EMIT_HEY}{ADD_YUD}!\n"
	.string "צא{ADD_YUD} לדרך למסע הפראי שלך!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "סלח{ADD_YUD} לי!\n"
	.string "קופסת המחשב שלך מלאה.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "סלח{ADD_YUD} לי!\n"
	.string "נראה שאין ברשותך קופסת פוקיגוש.\p"
	.string "משחק הספארי שלך יהיה הרבה יותר\n"
	.string "מוצלח אם תשתמש{ADD_YUD} בפוקיגושים.\p"
	.string "אנא חז{EMIT_VAV}ר{ADD_YUD} עם קופסת פוקיגוש.\p"
	.string "תוכל{ADD_YUD} להשיג קופסת פוקיגוש\n"
	.string "מאולם התחרות של ליליקוב.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "עדיין נותן לך זמן. האם תרצ{EMIT_HEY}{ADD_YUD}\n"
	.string "לצאת מאזור הספארי עכשיו?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "אנא תהנ{EMIT_HEY}{ADD_YUD} מהמשך ההרפתקה\n"
	.string "הפראית שלך!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "אוקיי.\p"
	.string "אני אקח בחזרה את כדורי הספארי\n"
	.string "שנותרו לך.\p"
	.string "תודה ששיחקת.\n"
	.string "אנו מקווים לראותך שוב.$"

SafariZone_South_Text_GoodLuck:
	.string "בהצלחה!\p"
	.string "אם את{EMIT_HEY} צרי{SWAP_TZADIK}{ADD_HEY} משהו, אל תהסס{ADD_YUD}\n"
	.string "בבקשה לומר לי!$"

SafariZone_South_Text_Boy:
	.string "הידעת?\p"
	.string "אם שמים פוקיגוש בקופסה המרובעת\n"
	.string "ההיא, פוקימונים מתאספים סביבה.$"

SafariZone_South_Text_Man:
	.string "אני הולך להמשיך ללכת פנימה, אבל\n"
	.string "שכחתי להביא אופניים.\p"
	.string "משהו אומר לי שפוקימונים נדירים\n"
	.string "חיים באזורים המרוחקים.$"

SafariZone_Southwest_Text_Woman:
	.string "לפעמים, כשאני זורקת פוקיגוש לעבר\n"
	.string "פוקימון, הוא מתעלם ממנו.\p"
	.string "האם לפוקימון יש העדפות\n"
	.string "לגבי מה שהם אוכלים?$"

SafariZone_Northwest_Text_Man:
	.string "הא… אה…\n"
	.string "ה…הצלחתי להגיע לכאן…אבל…\p"
	.string "אני מותש… אין לי אנרגיה\n"
	.string "לתפוס פוקימונים…$"

SafariZone_North_Text_Fisherman:
	.string "אני במשימה לתפוס פוקימוני מים\n"
	.string "שלא רואים בהואן.\p"
	.string "יש לך מושג איפה האגם?$"

SafariZone_North_Text_Man:
	.string "אני הולך לתפוס הרבה פוקימונים נדירים\n"
	.string "כאן ולהחליף אותם עם החברים שלי!$"

SafariZone_South_Text_Youngster:
	.string "שמתי פוקיגוש על מתקן ההאכלה לפוקיגושים.\n"
	.string "אבל נראה שהוא נעלם.\p"
	.string "אני מניח שפוקימונים בטח אכלו אותו\n"
	.string "בלי ששמתי לב.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "עצה למאמנים באזור הספארי!\p"
	.string "זרקו פוקיגושים לעבר פוקימונים פראים כדי\n"
	.string "להפחית את הסיכוי שיברחו.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "”תנו מנוחה לרגליכם העייפות.“\n"
	.string "בית מנוחה$"

SafariZone_RestHouse_Text_Youngster:
	.string "אין לי שום פוקיגושים, אבל תפסתי\n"
	.string "מספר רב של פוקימונים.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY} לשפר את סיכויי התפיסה שלך\n"
	.string "על ידי התקרבות אליהם\l"
	.string "לפני הזריקת כדור ספארי.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "אם תשתמש{ADD_YUD} בפוקיגושים, פוקימונים פראיים\n"
	.string "לא ימהרו לברוח.\p"
	.string "אין טעם לתת פוקיגושים\n"
	.string "לפוקימונים שלא בורחים בקלות.$"

SafariZone_RestHouse_Text_FatMan:
	.string "אם תשי{SWAP_MEM}{ADD_YUD} פוקיגוש על מתקן ההאכלה,\n"
	.string "פוקימונים ימשכו אליו.\p"
	.string "אני חושב שפוקימונים עם אופי דומה\n"
	.string "לפוקיגוש מסוים נמשכים אליו.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "אזור זה עדיין בבנייה.\n"
	.string "הכניסה אסורה, מצטער!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "פרויקט ההרחבה של אזור הספארי\n"
	.string "הסתיים כעת.\p"
	.string "אנו מקווים שתהנו מהאזור החדש.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "אזור זה עדיין בבנייה.\n"
	.string "הכניסה אסורה, מצטער!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "וואו! ויי! לא ראיתי אף אחד\n"
	.string "מהפוקימונים האלה לפניכן!$"

SafariZone_Southeast_Text_FatMan:
	.string "הפוקימונים באזור הזה כולם\n"
	.string "חדשים לי.\p"
	.string "ומרשים לי לתפוס את הפוקימונים\n"
	.string "הנדירים האלה! איזה מגניב!$"

SafariZone_Southeast_Text_RichBoy:
	.string "נראה שהפוקימונים בסביבה הזו\n"
	.string "הם ממקום אחר חוץ מהואן.$"

SafariZone_Northeast_Text_Boy:
	.string "נשארו לי רק כמה כדורי ספארי בודדים.\p"
	.string "קשה לי לנסות להחליט\n"
	.string "מה כדאי לי לתפוס.$"

SafariZone_Northeast_Text_Woman:
	.string "שמעתי שאפשר לראות כאן {STR_VAR_1}.\n"
	.string "איפה הוא עשוי להיות?$"

SafariZone_Northeast_Text_Girl:
	.string "או, בוו!\n"
	.string "אני לא מצליחה לתפוס כלום!\p"
	.string "אני אגמור בבזבוז דמי הכניסה\n"
	.string "אם לא אתפוס משהו!$"
