ChiiTown_School_MapScripts::
# 2 "data/maps/ChiiTown_School/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_School_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ChiiTown_School_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/ChiiTown_School/scripts.pory"
	call ChiiTownSchool_NPCSchedules
	return


ChiiTown_School_EventScript_Teacher::
# 8 "data/maps/ChiiTown_School/scripts.pory"
	gettimeofday
# 9 "data/maps/ChiiTown_School/scripts.pory"
	switch VAR_0x8000
# 10 "data/maps/ChiiTown_School/scripts.pory"
	case TIME_EARLY_MORNING, ChiiTown_School_EventScript_Teacher_2
# 12 "data/maps/ChiiTown_School/scripts.pory"
	case TIME_MORNING, ChiiTown_School_EventScript_Teacher_3
# 14 "data/maps/ChiiTown_School/scripts.pory"
	case TIME_EVENING, ChiiTown_School_EventScript_Teacher_4
	return

ChiiTown_School_EventScript_Teacher_2:
# 11 "data/maps/ChiiTown_School/scripts.pory"
	goto ChiiTown_School_EventScript_PreparingDay
	return

ChiiTown_School_EventScript_Teacher_3:
# 13 "data/maps/ChiiTown_School/scripts.pory"
	goto ChiiTown_School_EventScript_Teaching
	return

ChiiTown_School_EventScript_Teacher_4:
# 15 "data/maps/ChiiTown_School/scripts.pory"
	goto ChiiTown_School_EventScript_EndingDay
	return


ChiiTown_School_EventScript_PreparingDay::
# 20 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 21 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 23 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_PreparingDay_Text_0
# 24 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_PreparingDay_Text_1
# 27 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 29 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 30 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 31 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_Teaching::
# 36 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 37 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 39 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_PreparingDay_Text_0
# 40 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_Teaching_Text_0
# 45 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 47 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 48 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 49 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_EndingDay::
# 53 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 54 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 56 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_PreparingDay_Text_0
# 57 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_EndingDay_Text_0
# 60 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 62 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 63 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 64 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_BoardLegend::
# 68 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 69 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_BoardLegend_Text_0
# 75 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 76 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_Board::
# 80 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 81 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_Board_Text_0
# 84 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 85 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildImBored::
# 89 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 90 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 92 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 93 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildImBored_Text_1
# 96 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 98 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 99 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 100 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildAlreadyKnowLegend::
# 104 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 105 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 107 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 108 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildAlreadyKnowLegend_Text_0
# 111 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 113 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 114 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 115 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildPokemonInsideVolcano::
# 119 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 120 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 122 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 123 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildPokemonInsideVolcano_Text_0
# 126 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 128 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 129 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 130 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildTellsStory::
# 134 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 135 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 137 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 138 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildTellsStory_Text_0
# 142 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 144 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 145 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 146 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_IsThePokemonWakingUp::
# 150 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 151 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 153 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 154 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_IsThePokemonWakingUp_Text_0
# 159 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 161 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 162 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 163 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildWiseGlasses::
# 167 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 168 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 170 "data/maps/ChiiTown_School/scripts.pory"
	goto_if_unset FLAG_SMART_GLASSES, ChiiTown_School_EventScript_ChildWiseGlasses_2
ChiiTown_School_EventScript_ChildWiseGlasses_1:
# 182 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 183 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildWiseGlasses_Text_1
# 186 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 188 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 189 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 190 "data/maps/ChiiTown_School/scripts.pory"
	release
	return

ChiiTown_School_EventScript_ChildWiseGlasses_2:
# 171 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 172 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildWiseGlasses_Text_0
# 176 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 178 "data/maps/ChiiTown_School/scripts.pory"
	giveitem ITEM_WISE_GLASSES
# 179 "data/maps/ChiiTown_School/scripts.pory"
	setflag FLAG_SMART_GLASSES
	goto ChiiTown_School_EventScript_ChildWiseGlasses_1


ChiiTown_School_EventScript_ChildLikeSensei::
# 194 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 195 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 197 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 198 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildLikeSensei_Text_0
# 201 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 203 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 204 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 205 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_PreparingDay_Text_0:
# 23 "data/maps/ChiiTown_School/scripts.pory"
	.string "Sensei$"

ChiiTown_School_EventScript_PreparingDay_Text_1:
# 25 "data/maps/ChiiTown_School/scripts.pory"
	.string "Um… The school isn't open yet, I'm\n"
	.string "afraid. However, you may come back\l"
	.string "later with your little brother or\l"
	.string "sister if you'd like!$"

ChiiTown_School_EventScript_Teaching_Text_0:
# 41 "data/maps/ChiiTown_School/scripts.pory"
	.string "Um… Aren't you a little old for\n"
	.string "this class?\p"
	.string "It's alright, you can stay!\p"
	.string "Today we're doing some creative\n"
	.string "writing about the Toku legends.$"

ChiiTown_School_EventScript_EndingDay_Text_0:
# 58 "data/maps/ChiiTown_School/scripts.pory"
	.string "Oh! I'm afraid classes are done for\n"
	.string "the day. You'll have to come back\l"
	.string "tomorrow.$"

ChiiTown_School_EventScript_BoardLegend_Text_0:
# 70 "data/maps/ChiiTown_School/scripts.pory"
	.string "A detailed print depicts\n"
	.string "an old legend.\p"
	.string "“A very long time ago, the Volcano\n"
	.string "erupted terribly.\p"
	.string "Four awakened Treasures fought\n"
	.string "the fiery Pokémon that lived\l"
	.string "inside it.\p"
	.string "At last, the four Treasures and\n"
	.string "the fiery Pokémon slumbered again.”$"

ChiiTown_School_EventScript_Board_Text_0:
# 82 "data/maps/ChiiTown_School/scripts.pory"
	.string "A wide sheet of paper with lots of\n"
	.string "tiny squiggles on it.$"

ChiiTown_School_EventScript_ChildImBored_Text_0:
# 92 "data/maps/ChiiTown_School/scripts.pory"
	.string "Child$"

ChiiTown_School_EventScript_ChildImBored_Text_1:
# 94 "data/maps/ChiiTown_School/scripts.pory"
	.string "I'm bored! Why won't recess start\n"
	.string "already!$"

ChiiTown_School_EventScript_ChildAlreadyKnowLegend_Text_0:
# 109 "data/maps/ChiiTown_School/scripts.pory"
	.string "I already knew all of this! My gramma\n"
	.string "told me about the legend a bajillion\l"
	.string "times!$"

ChiiTown_School_EventScript_ChildPokemonInsideVolcano_Text_0:
# 124 "data/maps/ChiiTown_School/scripts.pory"
	.string "There's a Pokémon inside the\n"
	.string "volcano?! That's AWESOME!$"

ChiiTown_School_EventScript_ChildTellsStory_Text_0:
# 139 "data/maps/ChiiTown_School/scripts.pory"
	.string "I know the story, I know the story!\p"
	.string "Once upon a time, the Volcano Pokémon\n"
	.string "woke up, and then there was fire\l"
	.string "everywhere, and then four Pokémon\l"
	.string "were fighting the Volcano one, and\l"
	.string "then the Volcano stopped spitting\l"
	.string "fire because the Pokémon went back\l"
	.string "to sleep!$"

ChiiTown_School_EventScript_IsThePokemonWakingUp_Text_0:
# 155 "data/maps/ChiiTown_School/scripts.pory"
	.string "When the Volcano Pokémon went to\n"
	.string "bed, the Volcano stopped erupting!\p"
	.string "But the Volcano has been rumbling for\n"
	.string "days now…\p"
	.string "Does that mean the Pokémon's waking\n"
	.string "up again?$"

ChiiTown_School_EventScript_ChildWiseGlasses_Text_0:
# 173 "data/maps/ChiiTown_School/scripts.pory"
	.string "Ugh, I missed a class so I have to\n"
	.string "catch up on Pokémon's attack and\l"
	.string "special attack…\p"
	.string "I'm almost done though! I don't even\n"
	.string "need these anymore!$"

ChiiTown_School_EventScript_ChildWiseGlasses_Text_1:
# 184 "data/maps/ChiiTown_School/scripts.pory"
	.string "These are my smart glasses. You\n"
	.string "looked like you needed them!$"

ChiiTown_School_EventScript_ChildLikeSensei_Text_0:
# 199 "data/maps/ChiiTown_School/scripts.pory"
	.string "I like our Sensei. She's pretty and\n"
	.string "she smells nice.$"
