PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	bufferspeciesname STR_VAR_1, VAR_STARTER_MON
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "המערכת אחסון פוקימון מבוססת\n"
	.string "מחשב הזאת…\p"
	.string "מי שיצר אותו חייב להיות סוג\n"
	.string "של קוסם מדעי!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "כשהפוקימון שלי אכל פרי אוכמניה,\n"
	.string "זה החזיר לו נ”ח!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "ישנם סוגים רבים של פוקימון.\p"
	.string "לכל הסוגים יש את החוזקות והחולשות\n"
	.string "שלהם נגד סוגים אחרים.\p"
	.string "בהתאם לסוגים של הפוקימון,\n"
	.string "קרב יכול להיות קל או קשה.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "למשל, ה{STR_VAR_1} שלך\n"
	.string "הוא מסוג עשב.\p"
	.string "הוא חזק נגד סוגי מים ואדמה.\p"
	.string "אבל, חלש נגד פוקימון מסוג אש.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "למשל, ה{STR_VAR_1} שלך\n"
	.string "הוא מסוג אש.\p"
	.string "הוא חזק נגד סוגי עשב וחרק.\p"
	.string "אבל, חלש נגד פוקימון מסוג מים.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "למשל, ה{STR_VAR_1} שלך\n"
	.string "הוא מסוג מים.\p"
	.string "הוא חזק נגד סוג אש.\p"
	.string "אבל, חלש נגד פוקימון מסוג עשב\n"
	.string "וחשמל.$"
