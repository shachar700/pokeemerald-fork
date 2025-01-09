ChiiTown_MapScripts::
# 7 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 10 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD
# 13 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_NPCSchedules
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 11 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_EventScript_SpawnBirds
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/ChiiTown/scripts.pory"
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_EventScript_MomNPCDialogue::
	return


ChiiTown_EventScript_MomDroppingOff::
# 23 "data/maps/ChiiTown/scripts.pory"
	gettimeofday
# 24 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_MomDroppingOff_Text_0
# 25 "data/maps/ChiiTown/scripts.pory"
	switch VAR_TIME_OF_DAY
# 26 "data/maps/ChiiTown/scripts.pory"
	case TIME_MORNING, ChiiTown_EventScript_MomDroppingOff_2
# 31 "data/maps/ChiiTown/scripts.pory"
	case TIME_NOONTIME, ChiiTown_EventScript_MomDroppingOff_3
	return

ChiiTown_EventScript_MomDroppingOff_2:
# 27 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_MomDroppingOff_Text_1, MSGBOX_NPC
	return

ChiiTown_EventScript_MomDroppingOff_3:
# 32 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_MomDroppingOff_Text_2, MSGBOX_NPC
	return


ChiiTown_EventScript_MomWaiting::
# 40 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_MomDroppingOff_Text_0
	return


ChiiTown_EventScript_SpawnBirds::
# 47 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_1
# 48 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_2
# 50 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_3
# 51 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_4
# 53 "data/maps/ChiiTown/scripts.pory"
	gettime
# 55 "data/maps/ChiiTown/scripts.pory"
	compare VAR_TIME_HOUR, 5
	goto_if_ge ChiiTown_EventScript_SpawnBirds_6
ChiiTown_EventScript_SpawnBirds_4:
# 64 "data/maps/ChiiTown/scripts.pory"
	compare VAR_TIME_HOUR, 9
	goto_if_ge ChiiTown_EventScript_SpawnBirds_3
	return

ChiiTown_EventScript_SpawnBirds_1:
# 56 "data/maps/ChiiTown/scripts.pory"
	random 2
# 57 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 58 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_10
# 60 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_11
	return

ChiiTown_EventScript_SpawnBirds_2:
# 65 "data/maps/ChiiTown/scripts.pory"
	random 2
# 66 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 67 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_13
# 69 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_14
	return

ChiiTown_EventScript_SpawnBirds_3:
# 64 "data/maps/ChiiTown/scripts.pory"
	compare VAR_TIME_HOUR, 17
	goto_if_le ChiiTown_EventScript_SpawnBirds_2
	return

ChiiTown_EventScript_SpawnBirds_6:
# 55 "data/maps/ChiiTown/scripts.pory"
	compare VAR_TIME_HOUR, 8
	goto_if_le ChiiTown_EventScript_SpawnBirds_1
	goto ChiiTown_EventScript_SpawnBirds_4

ChiiTown_EventScript_SpawnBirds_10:
# 59 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_1
	return

ChiiTown_EventScript_SpawnBirds_11:
# 61 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_2
	return

ChiiTown_EventScript_SpawnBirds_13:
# 68 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_3
	return

ChiiTown_EventScript_SpawnBirds_14:
# 70 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_4
	return


ChiiTown_EventScript_Shopper::
# 76 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_MomDroppingOff_Text_0
# 77 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Shopper_Text_0, MSGBOX_NPC
	return


ChiiTown_EventScript_Kecleon::
# 84 "data/maps/ChiiTown/scripts.pory"
	lock
# 85 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 86 "data/maps/ChiiTown/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 87 "data/maps/ChiiTown/scripts.pory"
	ismonseen SPECIES_KECLEON
# 88 "data/maps/ChiiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_EventScript_Kecleon_2
# 91 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_1
ChiiTown_EventScript_Kecleon_1:
# 93 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Kecleon_Text_2
# 94 "data/maps/ChiiTown/scripts.pory"
	waitmoncry
# 95 "data/maps/ChiiTown/scripts.pory"
	closemessage
# 96 "data/maps/ChiiTown/scripts.pory"
	release
	return

ChiiTown_EventScript_Kecleon_2:
# 89 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_0
	goto ChiiTown_EventScript_Kecleon_1


ChiiTown_EventScript_PlantingFlowers::
# 100 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
# 101 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_PlantingFlowers_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_Mart::
# 107 "data/maps/ChiiTown/scripts.pory"
	lock
# 108 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 109 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 110 "data/maps/ChiiTown/scripts.pory"
	message ChiiTown_EventScript_Mart_Text_1
# 111 "data/maps/ChiiTown/scripts.pory"
	waitmessage
# 112 "data/maps/ChiiTown/scripts.pory"
	pokemart ChiiTown_Mart
# 113 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 114 "data/maps/ChiiTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 115 "data/maps/ChiiTown/scripts.pory"
	release
	return


	.align 2
# 118 "data/maps/ChiiTown/scripts.pory"
ChiiTown_Mart:
# 119 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 120 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 121 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 122 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 123 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 124 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 125 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

ChiiTown_EventScript_Samurai::
# 129 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Samurai_Text_0
# 130 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Samurai_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_TownSign::
# 136 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
# 140 "data/maps/ChiiTown/scripts.pory"
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_MomDroppingOff_Text_0:
# 24 "data/maps/ChiiTown/scripts.pory"
	.string "Woman$"

ChiiTown_EventScript_MomDroppingOff_Text_1:
# 28 "data/maps/ChiiTown/scripts.pory"
	.string "I'm dropping off my children to\n"
	.string "school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_MomDroppingOff_Text_2:
# 33 "data/maps/ChiiTown/scripts.pory"
	.string "I'm waiting to pick up my children\n"
	.string "after school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_Shopper_Text_0:
# 78 "data/maps/ChiiTown/scripts.pory"
	.string "The lady who keeps the town's market\n"
	.string "has started selling Pokémon medicine\l"
	.string "and Pokéballs!\p"
	.string "Be careful, though: the ointments she\n"
	.string "sells can't be used in the middle of a\l"
	.string "battle.$"

ChiiTown_EventScript_Kecleon_Text_0:
# 89 "data/maps/ChiiTown/scripts.pory"
	.string "Kecleon$"

ChiiTown_EventScript_Kecleon_Text_1:
# 91 "data/maps/ChiiTown/scripts.pory"
	.string "Weird lizard$"

ChiiTown_EventScript_Kecleon_Text_2:
# 93 "data/maps/ChiiTown/scripts.pory"
	.string "Kleeeeh!$"

ChiiTown_EventScript_PlantingFlowers_Text_0:
# 100 "data/maps/ChiiTown/scripts.pory"
	.string "Little girl$"

ChiiTown_EventScript_PlantingFlowers_Text_1:
# 102 "data/maps/ChiiTown/scripts.pory"
	.string "I'm planting flowers so that the wild\n"
	.string "Pokémon become happy again!$"

ChiiTown_EventScript_Mart_Text_0:
# 109 "data/maps/ChiiTown/scripts.pory"
	.string "Saleswoman$"

ChiiTown_EventScript_Mart_Text_1:
# 110 "data/maps/ChiiTown/scripts.pory"
	.string "Welcome to Chii Town's market! How may\n"
	.string "I help you?$"

ChiiTown_EventScript_Samurai_Text_0:
# 129 "data/maps/ChiiTown/scripts.pory"
	.string "Samurai$"

ChiiTown_EventScript_Samurai_Text_1:
# 131 "data/maps/ChiiTown/scripts.pory"
	.string "There's been reports of some shady\n"
	.string "men dressed in blue loitering around\l"
	.string "the area.\p"
	.string "Be careful when traveling!$"

ChiiTown_EventScript_TownSign_Text_0:
# 136 "data/maps/ChiiTown/scripts.pory"
	.string "Chii Town\n"
	.string "“The smallest town, with the biggest\l"
	.string "heart.”$"
