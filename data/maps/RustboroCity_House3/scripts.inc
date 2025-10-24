RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "לפוקימון שלי, אני נותן,\n"
	.string "כינויים מתאימים להפליא!\p"
	.string "זה הביטוי שלי ל…\n"
	.string "יצירתיות, כן, זהו זה!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "אבל לתת את השם פקצ׳ו\n"
	.string "ל{STR_VAR_1}? זה חסר טעם.\p"
	.string "אני מניחה שטוב להשתמש בשם\n"
	.string "שקל להבין, אבל עדיין…$"

RustboroCity_House3_Text_Pekachu:
	.string "{STR_VAR_1}: פיקא!$"

