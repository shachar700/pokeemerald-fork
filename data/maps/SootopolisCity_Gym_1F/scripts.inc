SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "יו! מה נשמע, {PLAYER}\n"
	.string "אלו{SWAP_PEY}{ADD_HEY} שבדרך?\p"
	.string "מנהיג מכון סוטופוליס, חואן, הוא\n"
	.string "מומחה לפוקימונים מסוג מים.\p"
	.string "וכדי להגיע לחואן, רצפה קפואה\n"
	.string "תעכב את ההתקדמות שלך…\p"
	.string "תקשיב{ADD_YUD}, אני מצטער, אבל זו כל\n"
	.string "העצה שיש לי בשבילך.\p"
	.string "את שאר הדרך, את{EMIT_HEY} צריך{ADD_HEY}\n"
	.string "לעשות בעצמך!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "וואו! ניצחת אפילו את חואן, שנחשב\n"
	.string "לטוב ביותר בכל הואן!\p"
	.string "אוקיי! תסתכל{ADD_YUD} על כרטיס המאמן שלך.\p"
	.string "אם השגת את כל התגים, יש לך את\n"
	.string "מה שצריך לאתגר את ליגת הפוקימונים!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "הרש{EMIT_HEY}{ADD_YUD} לי לשאול.\n"
	.string "הידעת?\l"
	.string "אה, אל לי להיות כה מסתורי.\p"
	.string "אני הוא שלימד את וולאס כל מה\n"
	.string "שיש לדעת על פוקימונים.\p"
	.string "פעם, ויתרתי על תפקידי\n"
	.string "כמנהיג המכון.\p"
	.string "במקומי, הפקדתי את המכון\n"
	.string "בידי וולאס.\p"
	.string "אולם, צצה סיבה משכנעת\n"
	.string "לשובי.\p"
	.string "אה, אבל די בפטפוטים.\n"
	.string "הבה נתחיל את הקרב שלנו, כן?\p"
	.string "אנא, צפ{EMIT_HEY}{ADD_YUD} באמנות\n"
	.string "שלנו.\p"
	.string "אשליה מפוארת של מים, מפוסלת\n"
	.string "בידי הפוקימונים ובידיי!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "אהאהאהא, מצוין!\n"
	.string "טוב מאוד, את{EMIT_HEY} המנצח{ADD_TAF}.\p"
	.string "אני חש בך את הברק המזהיר\n"
	.string "של כישרון שיתגבר על הכול.\p"
	.string "אולם, לעומתי או אפילו לעומת וולאס,\n"
	.string "חסרה לך אלגנטיות.\p"
	.string "אולי עליי להשאיל לך\n"
	.string "את הלבוש שלי?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "האהאה, אני רק מתלוצץ!\p"
	.string "במקום בגדיי, אגמול לך\n"
	.string "בזה, תג הגשם!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} קיבל{ADD_HEY} את תג הגשם\n"
	.string "מחואן.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "תג הגשם יבטיח לך\n"
	.string "את צייתנותם המלאה של כל\l"
	.string "הפוקימונים שלך לכל פקודה.\p"
	.string "תג הגשם מאפשר גם שימוש\n"
	.string "במהלך המ”נ מפל מים כדי לטפס\l"
	.string "על קירות של מים גועשים.\p"
	.string "וכדי שלעולם לא תשכח{ADD_YUD} את\n"
	.string "הקרב שחלקנו, קח{ADD_YUD} את זה…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "המכונה הטכנית שנתתי לך\n"
	.string "מכילה דופק מים.\p"
	.string "בשימוש, היא תבלבל לעיתים\n"
	.string "את המטרה בגלים על-קוליים.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "מנהיג המכון חואן נרשם\n"
	.string "בפוקינווט.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "המאמנים שאספו את כל\n"
	.string "תגי המכונים של הואן צריכים לפלס\l"
	.string "את דרכם אל היעד האולטימטיבי.\p"
	.string "ליגת הפוקימונים.\p"
	.string "יש לנסוע אל הקצה המזרחי ביותר\n"
	.string "של הואן, אל האי אבר גרנדה.\p"
	.string "שם, תמצא{ADD_YUD} את ליגת\n"
	.string "הפוקימונים.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "נותר רק תג אחד\n"
	.string "להשיג בהואן.\p"
	.string "אם את{EMIT_HEY} רוצה לאתגר את ליגת\n"
	.string "הפוקימונים, את{EMIT_HEY} חייב{ADD_TAF} להשיג\l"
	.string "את התג האחרון מהמכון בפורטרי.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "מכון הפוקימונים של עיר סוטופוליס$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "מכון הפוקימונים של עיר סוטופוליס\p"
	.string "המאמנים המוסמכים בידי חואן:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "חואן: אה, המכון הזה שב למצב\n"
	.string "השלווה הרגיל שלו…\p"
	.string "אבל הטייפון הצעיר שלנו חזר\n"
	.string "להעמיד אותנו שוב במבחן!\p"
	.string "ובכן, ידידי, בהחלט!\p"
	.string "אשמח לרקוד איתך\n"
	.string "בכל פעם שתרצ{EMIT_HEY}{ADD_YUD}!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "אהאהאהא, את{EMIT_HEY} המנצח{ADD_TAF}!\n"
	.string "ניצחת אותי שוב!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "חואן: אילו ביקשתי ממך להיות\n"
	.string "השוליה שלי, היית מסרב{ADD_TAF}, בטוח.\p"
	.string "הייתי רוצה להעניק לך את\n"
	.string "המעיל שלי במתנה.\p"
	.string "אבל שוב, היית מסרב{ADD_TAF}.\n"
	.string "כך אני מדמיין.\p"
	.string "וזה, ידידי, סימן בטוח\n"
	.string "לאצילות!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "חואן: אה, המכון הזה שב למצב\n"
	.string "השלווה הרגיל שלו…\p"
	.string "אבל הטייפון הצעיר שלנו חזר\n"
	.string "להעמיד אותנו שוב במבחן!\p"
	.string "ובכן, ידידי, בהחלט!\n"
	.string "אשמח לרקוד איתך…\p"
	.string "אה, לא, לא, לא.\n"
	.string "יש איתך רק פוקימון אחד.\p"
	.string "הייתי רוצה שתחזור{ADD_YUD} עם\n"
	.string "שני פוקימונים, אולי יותר, בבקשה.$"

