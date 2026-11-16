Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applywaitmovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_Delay48
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_1
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_2
	removeobject LOCALID_WEATHER_INSTITUTE_2F_SHELLY
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_4
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applywaitmovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	fadescreen FADE_FROM_BLACK
	applywaitmovement LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	copyobjectxytoperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	@ bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "המכון יצר סוג של\n"
	.string "פוקימון שיש לו קשר כלשהו\l"
	.string "למזג האוויר. אנחנו כאן כדי לקחת אותם!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "התוכנית שלנו מתקלקלת על ידי ילד{ADD_HEY}?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "אם הפוקימון שהם יצרו כאן יכול\n"
	.string "לשלוט במזג האוויר בחופשיות, אז אנחנו\l"
	.string "בצוות אקווה בהחלט צריכים אותו!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "אנחנו צוות אקווה!\n"
	.string "אנחנו מופיעים בכל מקום שבו מוצאים\l"
	.string "משהו נדיר!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "תפסת אותי!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "אין לך מושג למה אנחנו\n"
	.string "בצוות אקווה שואפים!\l"
	.string "אל תפריע{ADD_YUD} לנו!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "אל תגיד לי שגם את{EMIT_HEY} מחפש{ADD_TAF} את\n"
	.string "פוקימון מזג האוויר ההוא?\p"
	.string "זה לא-לא!\n"
	.string "אנחנו היינו כאן כדי להשיג אותו ראשונים!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "או, תרא{EMIT_HEY}{ADD_YUD} את הפוקימונים שלי?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "המפ, אז מה?\n"
	.string "מה שאנחנו רוצים…\p"
	.string "מה שאנחנו באמת רוצים לא כאן…\n"
	.string "איחיחיחיחי…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "אהאהאהאהא!\p"
	.string "את{EMIT_HEY} מתכוו{SWAP_NUN}{ADD_TAF} להתערב בענייני\n"
	.string "צוות אקווה?\p"
	.string "את{EMIT_HEY} או חסר{ADD_TAF} פחד לחלוטין,\n"
	.string "פשוט בור{ADD_HEY}, או שניהם!\p"
	.string "את{EMIT_HEY} כל כך חמוד{ADD_HEY}, שזה מגעיל!\n"
	.string "אני אוריד אותך, ילדון!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "אהאהאהאהא!\n"
	.string "את{EMIT_HEY} חזק{ADD_HEY} בצורה מגעילה!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "זה מספיק גרוע שצוות מגמה\n"
	.string "מתערב, ועכשיו יש אותך!\p"
	.string "מה גורם לך לרצות לרחרח\n"
	.string "בעניינים שלנו, בכל מקרה?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "יש לנו מצב כאן!\p"
	.string "אספסוף של צוות מגמה עבר זה עתה\n"
	.string "במכון מזג האוויר.\p"
	.string "נראה שהם בדרכם אל\n"
	.string "הר המוקד!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "מה?!\p"
	.string "אנחנו לא יכולים לבזבז עוד זמן כאן!\n"
	.string "גם אנחנו חייבים למהר להר המוקד!\p"
	.string "אהאהאהאהא!\n"
	.string "צוות מגמה, חכו ותראו!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "תודה!\n"
	.string "בזכותך, אנחנו בטוחים!\p"
	.string "זו אולי דרך מוזרה להודות לך,\n"
	.string "אבל קח{ADD_YUD} את הפוקימון הזה.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "המ? נראה שאין לך מקום\n"
	.string "לפוקימון הזה.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} קיבל{ADD_HEY} {STR_VAR_1}!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "הפוקימון הזה משנה צורה לפי\n"
	.string "תנאי מזג האוויר.\p"
	.string "יש לנו שפע מהם במכון--\n"
	.string "קח{ADD_YUD} אותו.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "חקרתי גשם במשך שנים רבות, אבל זה מגוחך\n"
	.string "לחשוב שבני אדם יכולים לשנות את\l"
	.string "מזג האוויר בחופשיות.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "אני עוקב אחר דפוסי מזג האוויר\n"
	.string "במחוז הואן.\p"
	.string "נכון לעכשיו, נרשמה בצורת\n"
	.string "ב{STR_VAR_1}.\p"
	.string "האם זה יכול להיות, איפשהו ליד\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "אני עוקב אחר דפוסי מזג האוויר\n"
	.string "במחוז הואן.\p"
	.string "נכון לעכשיו, נרשמו גשמים כבדים\n"
	.string "מעל {STR_VAR_1}.\p"
	.string "האם זה יכול להיות, איפשהו ליד\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "תנאי מזג אוויר חריגים כבר\n"
	.string "לא מדווחים.\p"
	.string "הגשם המזדמן הוא ברכה,\n"
	.string "באמת.$"

