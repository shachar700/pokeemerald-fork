RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "לפוקימון שלי יש אופי נאיבי, ולחבר\n"
	.string "שלי יש עם אופי עליז.\p"
	.string "זה מרתק איך שלפוקימון יש\n"
	.string "אישיויות!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "בדיוק כמו אנשים, יש פוקימון זכר\n"
	.string "ונקבה.\p"
	.string "אבל נראה שאף אחד לא יודע\n"
	.string "במה הם שונים.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "האיש ממול נתן לי מ״נ!\p"
	.string "השתמשתי בו כדי ללמד את הפוקימון שלי\n"
	.string "איך לחתוך עצים דקים.$"
