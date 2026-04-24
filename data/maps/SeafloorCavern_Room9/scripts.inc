SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	bufferspeciesname STR_VAR_1, SPECIES_KYOGRE
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	bufferspeciesname STR_VAR_2, SPECIES_GROUDON
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "ארצ'י: עצ{EMIT_VAV}ר{ADD_YUD} בדיוק שם.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "ארצ'י: פופופו…\n"
	.string "אז זה היית את{EMIT_HEY}, אחרי הכל.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "ארצ'י: תסתכל{ADD_YUD}!\p"
	.string "תרא{EMIT_HEY}{ADD_YUD} כמה יפה היא, הצורה הישנה\n"
	.string "של הפוקימון הקדום {STR_VAR_1}!\p"
	.string "חיכיתי כל כך הרבה זמן שהיום הזה\n"
	.string "יגיע…$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "ארצ'י: זה מפתיע אותי, איך הצלחת\n"
	.string "לרדוף אחריי עד לכאן.\p"
	.string "אבל זה נגמר עכשיו.\p"
	.string "למען הגשמת החלום שלי,\n"
	.string "את{EMIT_HEY} חייב{ADD_TAF} להיעלם עכשיו!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "מה?!\p"
	.string "הפסדתי לילד{ADD_HEY} פשוט{ADD_HEY} כמוך?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "ארצ'י: פופופו…\p"
	.string "אני משבח אותך. אני חייב להכיר בכך\n"
	.string "שאת{EMIT_HEY} באמת מחונ{SWAP_NUN}{ADD_TAF}.\p"
	.string "אבל!\n"
	.string "זה ברשותי!\p"
	.string "עם הכדור האדום הזה, אני יכול לגרום ל{STR_VAR_1}…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "הכדור האדום החל לפתע לזרוח\n"
	.string "מעצמו!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "ארצ'י: מה?!\p"
	.string "לא עשיתי כלום.\n"
	.string "למה הכדור האדום…\p"
	.string "לאן {STR_VAR_1} נעלם?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "ארצ'י: המ? זו הודעה מהחברים\n"
	.string "שלנו בחוץ…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "ארצ'י: כן, מה זה?\p"
	.string "המ…\n"
	.string "יורד גשם כבד?\p"
	.string "טוב… זה מה שהיה צריך לקרות.\n"
	.string "לשם כך הערנו את {STR_VAR_1},\l"
	.string "כדי להגשים את חזון צוות אקווה של\l"
	.string "הרחבת הים.\p"
	.string "מה?!\p"
	.string "יורד גשם חזק הרבה יותר ממה\n"
	.string "שדמיינו? אתם בסכנה?\p"
	.string "זה לא יכול להיות…\n"
	.string "זה פשוט לא אפשרי…\p"
	.string "שמרו על המיקום שלכם ועקבו אחר\n"
	.string "המצב!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "ארצ'י: משהו לא בסדר…\p"
	.string "הכדור האדום אמור להעיר\n"
	.string "ולשלוט ב{STR_VAR_1}…\p"
	.string "אבל… למה?\n"
	.string "למה {STR_VAR_1} נעלם?\p"
	.string "למה?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "מקסי: מה עוללת?\p"
	.string "ארצ'י… הערת סוף סוף את {STR_VAR_1},\n"
	.string "נכון?\p"
	.string "מה יקרה לעולם אם המבול הזה\n"
	.string "יימשך לנצח?\p"
	.string "מסת היבשה של העולם תטבע\n"
	.string "בים המעמיק…$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "ארצ'י: מ-מה?!\n"
	.string "אל תתנשא עליי!\p"
	.string "לא הייתם אתם, צוות מגמה,\n"
	.string "שהרגיזו את {STR_VAR_2}?\p"
	.string "כל עוד הכדור האדום הזה אצלי,\n"
	.string "אני אמור להיות מסוגל לשלוט ב{STR_VAR_1}…\p"
	.string "אני אמור להיות מסוגל לשלוט בו…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "מקסי: אין לנו זמן\n"
	.string "להתווכח על זה כאן!\p"
	.string "צא החוצה ותראה בעצמך!\p"
	.string "תראה אם מה שעוללת זה העולם\n"
	.string "שאותו רצינו!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "מקסי: {PLAYER}, קדימה, את{EMIT_HEY} גם חייב{ADD_TAF}\n"
	.string "לצאת מכאן!$"
