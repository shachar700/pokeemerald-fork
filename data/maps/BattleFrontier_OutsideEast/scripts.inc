BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "זהו מגדל הקרב!\n"
	.string "לשמור על רצף הניצחונות בתור המאמן\l"
	.string "הקשוח ביותר!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "זהו ארמון הקרב!\n"
	.string "לשמור את העיניים שלך על קרבות פוקימונים!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "זוהי זירת הקרב!\n"
	.string "שהקבוצות הקשוחות ביותר יתאספו!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "זוהי פירמידת הקרב!\n"
	.string "להתקדם דרך מסע הקרב!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "אולם הדירוג של חזית הקרב\n"
	.string "לכוון לשיאים חדשים!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "פינת החלפת נקודות קרב\n"
	.string "להמיר את נקודות הקרב שלך!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "ואו!\n"
	.string "זה ענק!\p"
	.string "מגדל הקרב מרגיש מיוחד.\n"
	.string "הוא שונה מהאחרים.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "השאיפה הגדולה שלי היא לכבוש את חזית\n"
	.string "הקרב ואת ליגת הפוקימונים.\l"
	.string "ליגת הפוקימונים.\p"
	.string "ואם החלום שלי יתגשם…\p"
	.string "אני… אני אשאל את מימי מהבית ליד\n"
	.string "אם היא תרצה להיות חברה שלי!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "פירמידת הקרב קשה מדי!\n"
	.string "אני פשוט לא מצליח להגיע לפסגה!\p"
	.string "מאחר שאזלו לי האפשרויות, אולי אני יכול\n"
	.string "לטפס מבחוץ…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "אני משגשג בחושך…\n"
	.string "כן… מה ראוי לי?\l"
	.string "שום דבר מלבד פירמידת הקרב…\p"
	.string "מה דעתך לשוטט בחושך\n"
	.string "ובייאוש מוחלט לגמריי?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "לא ישנתי שבוע, אבל אז\n"
	.string "הרכבתי את הצוות האולטימטיבי!\p"
	.string "אני לא רואה את עצמי מפסיד, בלי צחוק.\n"
	.string "אנחנו מסתערים על זירת הקרב!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "האם סקוט גם הביא אותך לכאן?\n"
	.string "מה קורה עם הבחור הזה?\p"
	.string "זה נשמע שהוא באמת יודע\n"
	.string "לזהות מאמנים מוכשרים, אבל…\p"
	.string "מעולם לא ראיתי אותו נלחם בעצמו\n"
	.string "אפילו פעם אחת.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "זיג!\n"
	.string "אני מאמין בך, חבר קטן!\p"
	.string "אני אכין לזיג הקטן שלי כל פינוק\n"
	.string "טעים שיאהב אם תנצח!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "{STR_VAR_1} נראה ריקני…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "אנשים קוראים לי חטטן,\n"
	.string "אבל אני לא יכול לשלוט בזה.\p"
	.string "הכובע שלך עקום!\n"
	.string "או, לא, אשפה על הקרקע!\l"
	.string "אופס, עוד מעט ארוחת ערב!\p"
	.string "אני לא יודע אם אני יכול לעמוד במצב שבו אני רק\n"
	.string "צופה בארמון הקרב…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "אני אולי לא נראה כל כך מרשים עכשיו,\n"
	.string "אבל פעם ניצחתי מנהיג מכון.\p"
	.string "מי יודע, אולי אני צריך לנסות\n"
	.string "שוב לקבל תהילה.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "אני מהיר על האופניים שלי, וזה נכון גם\n"
	.string "לגבי הדרך שבה אני נלחם.\p"
	.string "אני מנצח משחקים בהרף\n"
	.string "עין!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "אני טוב יותר מאבא שלי\n"
	.string "בפוקימונים.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "קדימה, מתוקי שלי!\n"
	.string "לך לצבור כמה ניצחונות בשביל אבא!\p"
	.string "אתה בדיוק כמו אמא שלך,\n"
	.string "אז אתה תשתלט על כולם!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "זה לא היה קל להגיע לכאן,\n"
	.string "אבל שמעתי על ילדה יפהפייה\l"
	.string "בזירת הקרב.\p"
	.string "במקומה, את{EMIT_HEY} יודע{ADD_TAF} מה\n"
	.string "מצאתי?\p"
	.string "אספסוף שלם של אומני לחימה מזיעים,\n"
	.string "מסריחים ופרימיטיביים!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "אני רואה לפעמים איש זקן שנראה\n"
	.string "חשוב באמת נכנס לשם.\p"
	.string "יש לו פוקימונים ממש מדהימים.\n"
	.string "הוא נראה ממש נחמד, עם זאת.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "את{EMIT_HEY} מכיר{ADD_HEY} את זה?\n"
	.string "האגדה של פירמידת הקרב?\p"
	.string "כאשר יגיע מאמן בטוח בעצמו\n"
	.string "שיחפש את פסגת הזהב,\l"
	.string "יופיע אדם יוצא דופן.\p"
	.string "את{EMIT_HEY} לא מכיר{ADD_HEY} את האגדה הזו?\n"
	.string "טוב, כמובן שלא!\l"
	.string "הרגע המצאתי אותה!\p"
	.string "מה זה אמור להביע?\n"
	.string "את זה, ידיד{ADD_TAF}י, אני לא יכול לומר!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "בנאדם! או בנאדם!\n"
	.string "מעולם לא הפסדתי אפילו פעם אחת לפניכן!\p"
	.string "אבל הושמדתי ללא\n"
	.string "רחמים!\p"
	.string "ואז אומרים לי שאין לי\n"
	.string "כישרון?! בנאדם!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "הבחור הזה נתקל במאמן\n"
	.string "נורא קשוח בזמן שהוא היה באתגר\l"
	.string "מגדל הקרב.\p"
	.string "עכשיו תרא{EMIT_HEY}{ADD_YUD} אותו…\p"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} להיות זהיר{ADD_HEY} אם את{EMIT_HEY} אי פעם\n"
	.string "תחליט{ADD_YUD} ללכת למגדל הקרב.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "כן!\n"
	.string "סוף סוף יש לי מספיק נקודות קרב!\p"
	.string "אני מניח שאני אחליף את זה בעוד בובה\n"
	.string "קטיפתית ענקית!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "או, כן, אוקיי!\n"
	.string "אז זה אולם הדירוג!\p"
	.string "הייתי רוצה להיכנס להיסטוריה בתור\n"
	.string "אלוף על ולרשום את השם שלי\l"
	.string "כאן לדורות הבאים.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "איתך לצידי, אני יכול לעשות כל דבר.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "אוו, מותק, אתה כל כך נפלא!\p"
	.string "אוו, אני פשוט לא יכולה לחכות יותר!\p"
	.string "בוא נלך לחדר קרב מרובה משתתפים\n"
	.string "ממש עכשיו!\p"
	.string "אם נהיה יחד בסלון הקרב,\n"
	.string "כוח האהבה שלנו יתגבר על\l"
	.string "כל מי שניפגוש.\p"
	.string "וואי, לפנינו, מותק, הכל\n"
	.string "ייפול כמו אבני דומינו!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "חזית הקרב אינו מיועד באופן בלעדי\n"
	.string "למאמנים קשוחים.\p"
	.string "אנשים רבים עם יכולות מיוחדות\n"
	.string "הוזמנו, כך נראה.\p"
	.string "האיש הזה סקוט…\p"
	.string "אולי הוא בנה את המקום הזה כדי לשרת\n"
	.string "מטרה גדולה יותר…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "סלח{ADD_YUD} לי, צעיר{ADD_HEY}.\n"
	.string "האם יש לך ראייה טובה?\p"
	.string "יש עץ מוזר שעבר כאן, ולעיני\n"
	.string "העייפות שלי הוא נראה מתנועע.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "סלח{ADD_YUD} לי, צעיר{ADD_HEY}.\n"
	.string "האם יש לך זיכרון טוב?\p"
	.string "יש לי הרגשה שפעם היה כאן\n"
	.string "עץ מוזר שעבר.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "אני…\n"
	.string "ראיתי את זה!\p"
	.string "היה פוקימון דביק כזה עם\n"
	.string "זנב ארוך שם מקדימה!\p"
	.string "הוא התחבא מתחת לסלע, והוא\n"
	.string "המשיך לבהות בי!$"
