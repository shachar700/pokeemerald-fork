ChiiTown_MapScripts::
# 7 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 10 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD
# 14 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_NPCSchedules
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 11 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_EventScript_SpawnBirds
# 12 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_DrawMetatiles
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/ChiiTown/scripts.pory"
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_EventScript_SpawnBirds::
# 22 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_1
# 23 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_2
# 25 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_3
# 26 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_4
# 28 "data/maps/ChiiTown/scripts.pory"
	gettime
# 30 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 5
	goto_if_ge ChiiTown_EventScript_SpawnBirds_6
ChiiTown_EventScript_SpawnBirds_4:
# 39 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 9
	goto_if_ge ChiiTown_EventScript_SpawnBirds_3
	return

ChiiTown_EventScript_SpawnBirds_1:
# 31 "data/maps/ChiiTown/scripts.pory"
	random 2
# 32 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 33 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_10
# 35 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_11
	return

ChiiTown_EventScript_SpawnBirds_2:
# 40 "data/maps/ChiiTown/scripts.pory"
	random 2
# 41 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 42 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_13
# 44 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_14
	return

ChiiTown_EventScript_SpawnBirds_3:
# 39 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 17
	goto_if_le ChiiTown_EventScript_SpawnBirds_2
	return

ChiiTown_EventScript_SpawnBirds_6:
# 30 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 8
	goto_if_le ChiiTown_EventScript_SpawnBirds_1
	goto ChiiTown_EventScript_SpawnBirds_4

ChiiTown_EventScript_SpawnBirds_10:
# 34 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_1
	return

ChiiTown_EventScript_SpawnBirds_11:
# 36 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_2
	return

ChiiTown_EventScript_SpawnBirds_13:
# 43 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_3
	return

ChiiTown_EventScript_SpawnBirds_14:
# 45 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_4
	return


ChiiTown_EventScript_WatchfulMom::
# 51 "data/maps/ChiiTown/scripts.pory"
	gettimeofday
# 52 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_WatchfulMom_Text_0
# 53 "data/maps/ChiiTown/scripts.pory"
	switch VAR_0x8000
# 54 "data/maps/ChiiTown/scripts.pory"
	case TIME_MORNING, ChiiTown_EventScript_WatchfulMom_3
# 59 "data/maps/ChiiTown/scripts.pory"
	case TIME_NOONTIME, ChiiTown_EventScript_WatchfulMom_4
ChiiTown_EventScript_WatchfulMom_1:
# 65 "data/maps/ChiiTown/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 66 "data/maps/ChiiTown/scripts.pory"
	waitmovement 0
	return

ChiiTown_EventScript_WatchfulMom_3:
# 55 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_WatchfulMom_Text_1, MSGBOX_NPC
	goto ChiiTown_EventScript_WatchfulMom_1

ChiiTown_EventScript_WatchfulMom_4:
# 60 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_WatchfulMom_Text_2, MSGBOX_NPC
	goto ChiiTown_EventScript_WatchfulMom_1


ChiiTown_EventScript_Shopper::
# 70 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_WatchfulMom_Text_0
# 71 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Shopper_Text_0, MSGBOX_NPC
# 75 "data/maps/ChiiTown/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 76 "data/maps/ChiiTown/scripts.pory"
	waitmovement 0
	return


ChiiTown_EventScript_Kecleon::
# 80 "data/maps/ChiiTown/scripts.pory"
	lock
# 81 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 82 "data/maps/ChiiTown/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 83 "data/maps/ChiiTown/scripts.pory"
	ismonseen SPECIES_KECLEON
# 84 "data/maps/ChiiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_EventScript_Kecleon_2
# 87 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_1
ChiiTown_EventScript_Kecleon_1:
# 89 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Kecleon_Text_2
# 90 "data/maps/ChiiTown/scripts.pory"
	waitmoncry
# 91 "data/maps/ChiiTown/scripts.pory"
	closemessage
# 92 "data/maps/ChiiTown/scripts.pory"
	release
	return

ChiiTown_EventScript_Kecleon_2:
# 85 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_0
	goto ChiiTown_EventScript_Kecleon_1


ChiiTown_EventScript_PlantingFlowers::
# 96 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
# 97 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_PlantingFlowers_Text_1, MSGBOX_NPC
# 100 "data/maps/ChiiTown/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 101 "data/maps/ChiiTown/scripts.pory"
	waitmovement 0
	return


ChiiTown_EventScript_AlsoPlantingFlowers::
# 105 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_AlsoPlantingFlowers_Text_0
# 106 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_AlsoPlantingFlowers_Text_1, MSGBOX_NPC
# 110 "data/maps/ChiiTown/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 111 "data/maps/ChiiTown/scripts.pory"
	waitmovement 0
	return


ChiiTown_EventScript_WatchingTheChildren::
# 115 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_WatchingTheChildren_Text_0
# 116 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_WatchingTheChildren_Text_1, MSGBOX_NPC
# 119 "data/maps/ChiiTown/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 120 "data/maps/ChiiTown/scripts.pory"
	waitmovement 0
	return


ChiiTown_EventScript_EatingBerries::
# 124 "data/maps/ChiiTown/scripts.pory"
	lock
# 125 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 126 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_EatingBerries_Text_0
# 127 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_EatingBerries_Text_1, MSGBOX_DEFAULT
# 131 "data/maps/ChiiTown/scripts.pory"
	closemessage
# 132 "data/maps/ChiiTown/scripts.pory"
	checkitem 520, 1
# 133 "data/maps/ChiiTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChiiTown_EventScript_EatingBerries_2
ChiiTown_EventScript_EatingBerries_1:
# 145 "data/maps/ChiiTown/scripts.pory"
	closemessage
# 146 "data/maps/ChiiTown/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 147 "data/maps/ChiiTown/scripts.pory"
	waitmovement 0
# 148 "data/maps/ChiiTown/scripts.pory"
	release
	return

ChiiTown_EventScript_EatingBerries_2:
# 134 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_EatingBerries_Text_2, MSGBOX_YESNO
# 137 "data/maps/ChiiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChiiTown_EventScript_EatingBerries_4
	goto ChiiTown_EventScript_EatingBerries_1

ChiiTown_EventScript_EatingBerries_4:
# 138 "data/maps/ChiiTown/scripts.pory"
	removeitem 520, 1
# 139 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_EatingBerries_Text_0
# 140 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_EatingBerries_Text_3, MSGBOX_DEFAULT
	goto ChiiTown_EventScript_EatingBerries_1


ChiiTown_EventScript_BerryEnthusiast::
# 152 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_BerryEnthusiast_Text_0
# 153 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_BerryEnthusiast_Text_1, MSGBOX_NPC
# 157 "data/maps/ChiiTown/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 158 "data/maps/ChiiTown/scripts.pory"
	waitmovement 0
	return


ChiiTown_EventScript_Mart::
# 162 "data/maps/ChiiTown/scripts.pory"
	lock
# 163 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 164 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 165 "data/maps/ChiiTown/scripts.pory"
	message ChiiTown_EventScript_Mart_Text_1
# 166 "data/maps/ChiiTown/scripts.pory"
	waitmessage
# 167 "data/maps/ChiiTown/scripts.pory"
	pokemart ChiiTown_Mart
# 168 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 169 "data/maps/ChiiTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 170 "data/maps/ChiiTown/scripts.pory"
	release
	return


	.align 2
# 173 "data/maps/ChiiTown/scripts.pory"
ChiiTown_Mart:
# 174 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 175 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 176 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 177 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 178 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 179 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 180 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

ChiiTown_EventScript_Samurai::
# 184 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Samurai_Text_0
# 185 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Samurai_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_TownSign::
# 191 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
# 195 "data/maps/ChiiTown/scripts.pory"
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_WatchfulMom_Text_0:
# 52 "data/maps/ChiiTown/scripts.pory"
	.string "Woman$"

ChiiTown_EventScript_WatchfulMom_Text_1:
# 56 "data/maps/ChiiTown/scripts.pory"
	.string "I'm dropping off my children to\n"
	.string "school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_WatchfulMom_Text_2:
# 61 "data/maps/ChiiTown/scripts.pory"
	.string "I'm waiting to pick up my children\n"
	.string "after school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_Shopper_Text_0:
# 72 "data/maps/ChiiTown/scripts.pory"
	.string "The lady who keeps the town's market\n"
	.string "has started selling Pokémon medicine\l"
	.string "and Pokéballs!\p"
	.string "Be careful, though: the ointments she\n"
	.string "sells can't be used in the middle of a\l"
	.string "battle.$"

ChiiTown_EventScript_Kecleon_Text_0:
# 85 "data/maps/ChiiTown/scripts.pory"
	.string "Kecleon$"

ChiiTown_EventScript_Kecleon_Text_1:
# 87 "data/maps/ChiiTown/scripts.pory"
	.string "Weird lizard$"

ChiiTown_EventScript_Kecleon_Text_2:
# 89 "data/maps/ChiiTown/scripts.pory"
	.string "Kleeeeh!$"

ChiiTown_EventScript_PlantingFlowers_Text_0:
# 96 "data/maps/ChiiTown/scripts.pory"
	.string "Little girl$"

ChiiTown_EventScript_PlantingFlowers_Text_1:
# 98 "data/maps/ChiiTown/scripts.pory"
	.string "I'm planting flowers so that the wild\n"
	.string "Pokémon become happy again!$"

ChiiTown_EventScript_AlsoPlantingFlowers_Text_0:
# 105 "data/maps/ChiiTown/scripts.pory"
	.string "Little boy$"

ChiiTown_EventScript_AlsoPlantingFlowers_Text_1:
# 107 "data/maps/ChiiTown/scripts.pory"
	.string "She's making me plant flowers so that\n"
	.string "the wild Pokémon become happy again.\p"
	.string "I'm not though…$"

ChiiTown_EventScript_WatchingTheChildren_Text_0:
# 115 "data/maps/ChiiTown/scripts.pory"
	.string "Sensei$"

ChiiTown_EventScript_WatchingTheChildren_Text_1:
# 117 "data/maps/ChiiTown/scripts.pory"
	.string "To make sure the children's energy\n"
	.string "isn't pent up too much, I bring them\l"
	.string "out for recess.$"

ChiiTown_EventScript_EatingBerries_Text_0:
# 126 "data/maps/ChiiTown/scripts.pory"
	.string "Twin girl$"

ChiiTown_EventScript_EatingBerries_Text_1:
# 128 "data/maps/ChiiTown/scripts.pory"
	.string "Sensei said that we should eat\n"
	.string "berries to grow big and strong!\p"
	.string "But how are we supposed to get them\n"
	.string "if we aren't big and strong yet?$"

ChiiTown_EventScript_EatingBerries_Text_2:
# 135 "data/maps/ChiiTown/scripts.pory"
	.string "Give the girl an Oran Berry?$"

ChiiTown_EventScript_EatingBerries_Text_3:
# 141 "data/maps/ChiiTown/scripts.pory"
	.string "Oh my gosh, thank you!$"

ChiiTown_EventScript_BerryEnthusiast_Text_0:
# 152 "data/maps/ChiiTown/scripts.pory"
	.string "Twin boy$"

ChiiTown_EventScript_BerryEnthusiast_Text_1:
# 154 "data/maps/ChiiTown/scripts.pory"
	.string "I've been eating berries just like\n"
	.string "Sensei said, but I haven't grown yet.\p"
	.string "I don't care though. They're\n"
	.string "delicious!$"

ChiiTown_EventScript_Mart_Text_0:
# 164 "data/maps/ChiiTown/scripts.pory"
	.string "Saleswoman$"

ChiiTown_EventScript_Mart_Text_1:
# 165 "data/maps/ChiiTown/scripts.pory"
	.string "Welcome to Chii Town's market! How may\n"
	.string "I help you?$"

ChiiTown_EventScript_Samurai_Text_0:
# 184 "data/maps/ChiiTown/scripts.pory"
	.string "Samurai$"

ChiiTown_EventScript_Samurai_Text_1:
# 186 "data/maps/ChiiTown/scripts.pory"
	.string "There's been reports of some shady\n"
	.string "men dressed in blue loitering around\l"
	.string "the area.\p"
	.string "Be careful when traveling!$"

ChiiTown_EventScript_TownSign_Text_0:
# 191 "data/maps/ChiiTown/scripts.pory"
	.string "Chii Town\n"
	.string "“The smallest town, with the biggest\l"
	.string "heart.”$"
