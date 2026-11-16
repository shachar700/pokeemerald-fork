FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applywaitmovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "אף אחד לא מאמין לי, אבל ראיתי פוקימון\n"
	.string "ענקי בשמיים.\p"
	.string "הוא נראה מתפתל בזמן שהוא עף לכיוון\n"
	.string "דרך 131.\p"
	.string "דרך אגב… רחרוח…\n"
	.string "אמ… את{EMIT_HEY}, אה… מריח{ADD_HEY} שרו{SWAP_PEY}{ADD_HEY}.\p"
	.string "היית בהר געש או משהו?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "אני רוצה ללכת למכון הפוקימונים,\n"
	.string "אבל משהו חוסם את הדרך.\p"
	.string "אחרי כל הטרחה שעברתי\n"
	.string "באימונים בדרך 021…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "הבאתי איתי את הפוקימונים שהם מקור\n"
	.string "גאוותי ושמחתי. הפעם, אני אנצח את וינונה.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "האדמה סופגת מי גשמים,\n"
	.string "והעצים גדלים על ידי שתיית המים האלה…\p"
	.string "העיר פורטרי שלנו קיימת כי יש\n"
	.string "גם מים וגם אדמה.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "העיר מורכבת מבתים שנבנו על\n"
	.string "עצים.\p"
	.string "אולי בגלל אורח החיים הזה,\n"
	.string "כולם בריאים ותוססים.\p"
	.string "וכן, אפילו אני--אני מרגיש כאילו\n"
	.string "התבגרתי שלושים שנה צעיר יותר.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "לחיות על צמרות העצים זה בסדר.\p"
	.string "אבל לפעמים פוקימוני חרק נכנסים\n"
	.string "דרך החלונות.\l"
	.string "זה יכול להיות ממש מבהיל.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "יש פוקימונים שמתפתחים כשאת{EMIT_HEY}\n"
	.string "מחלי{SWAP_PEY}{ADD_HEY} אותם! זה מה ששמעתי.$"

FortreeCity_Text_SomethingUnseeable:
	.string "משהו בלתי נראה חוסם את הדרך.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "משהו בלתי נראה חוסם את הדרך.\p"
	.string "רוצה להשתמש בעדשת דבון?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} השתמש{ADD_HEY} בעדשת דבון.\p"
	.string "פוקימון בלתי נראה הפך לגלוי\n"
	.string "לחלוטין!\p"
	.string "הפוקימון המבוהל נמלט!$"

FortreeCity_Text_CitySign:
	.string "העיר פורטרי\n"
	.string "”עיר צמרות העצים שמשתעשעת עם\l"
	.string "הטבע.“$"

FortreeCity_Text_GymSign:
	.string "מכון הפוקימונים של העיר פורטרי\n"
	.string "מנהיגה: וינונה\p"
	.string "”משתמשת הציפורים הממריאה אל\n"
	.string "העולם.“$"

