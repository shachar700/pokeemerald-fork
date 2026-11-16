VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "אבא שלי סיפר לי.\p"
	.string "הוא אמר שהמנהרה הזאת מלאה\n"
	.string "בפוקימונים ביישנים.\p"
	.string "הם נורא נבהלים מרעשים חזקים\n"
	.string "ועושים מהומה גדולה.\p"
	.string "אז נאלצו לעצור את פרויקט\n"
	.string "המנהרה הגדול.\p"
	.string "אבל יש איש אחד. הוא מנסה לחפור\n"
	.string "את המנהרה לבדו!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "היה פה איש שחפר מנהרה בשביל\n"
	.string "אישה שהוא אהב.\p"
	.string "אני לא ממש מבינה את זה, אבל היי!$"

VerdanturfTown_Text_AirCleanHere:
	.string "בגלל כיוון הרוחות, אפר וולקני\n"
	.string "אף פעם לא עף לכיוון הזה.\p"
	.string "האוויר פה נקי וטעים.\n"
	.string "לחיות פה יכול לעשות פלאים אפילו\l"
	.string "לאנשים חלשים וחולניים.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "הפוקימון שלי ואני, אנחנו ברצף\n"
	.string "ניצחונות מרשים.\p"
	.string "אז החלטתי לעשות את הופעת הבכורה\n"
	.string "שלי באוהל הקרב בעיירה הזאת.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "ראית את המערה ליד החנות פוקימון?\p"
	.string "יש שם בחור שמנסה לנפץ סלעים\n"
	.string "כדי שיוכל לפרוץ דבר לצד השני.\p"
	.string "זה יהיה נהדר אם נוכל לעבור דרך שם…\n"
	.string "זה יקל על הביקור ברסטבורו.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "המערה שליד החנות פוקימון\n"
	.string "היא עכשיו מנהרה לצד השני.\p"
	.string "זה נהדר--קל ללכת לקנות\n"
	.string "מוצרי דבון חדשים ברסטבורו עכשיו.$"

VerdanturfTown_Text_TownSign:
	.string "עיירת ורדנטרף\p"
	.string "”הרמות שטופות הרוח עם\n"
	.string "הניחוח המתוק של הדשא.“$"

VerdanturfTown_Text_WandasHouse:
	.string "הבית של וונדה$"

VerdanturfTown_Text_BattleTentSign:
	.string "אוהל הקרב אתר ורדנטרף\n"
	.string "”בואו לחזות בעינכם בקרבות!“$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "מנהרת רסטרף\n"
	.string "”מקשרת בין רסטבורו וורדנטרף\p"
	.string "”פרויקט המנהרה בוטל.“$"

