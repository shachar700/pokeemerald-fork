ChiiTown_NPCSchedules::
# 11 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_5
# 12 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_6
# 13 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_7
# 14 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_8
# 15 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 16 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 17 "data/scripts/schedule/chii_town.pory"
	case TIME_DEAD_NIGHT, ChiiTown_NPCSchedules_2
# 19 "data/scripts/schedule/chii_town.pory"
	case TIME_EARLY_MORNING, ChiiTown_NPCSchedules_3
# 21 "data/scripts/schedule/chii_town.pory"
	case TIME_MORNING, ChiiTown_NPCSchedules_4
# 23 "data/scripts/schedule/chii_town.pory"
	case TIME_LUNCHTIME, ChiiTown_NPCSchedules_5
# 25 "data/scripts/schedule/chii_town.pory"
	case TIME_NOONTIME, ChiiTown_NPCSchedules_6
# 27 "data/scripts/schedule/chii_town.pory"
	case TIME_EVENING, ChiiTown_NPCSchedules_7
# 29 "data/scripts/schedule/chii_town.pory"
	case TIME_NIGHT, ChiiTown_NPCSchedules_8
	return

ChiiTown_NPCSchedules_2:
# 18 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_DeadNightSchedules
	return

ChiiTown_NPCSchedules_3:
# 20 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EarlySchedules
	return

ChiiTown_NPCSchedules_4:
# 22 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_MorningSchedules
	return

ChiiTown_NPCSchedules_5:
# 24 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_LunchtimeSchedules
	return

ChiiTown_NPCSchedules_6:
# 26 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_AfternoonSchedules
	return

ChiiTown_NPCSchedules_7:
# 28 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EveningSchedules
	return

ChiiTown_NPCSchedules_8:
# 30 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_NightSchedules
	return


ChiiTown_DrawMetatiles::
# 35 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 36 "data/scripts/schedule/chii_town.pory"
	case TIME_DEAD_NIGHT, ChiiTown_DrawMetatiles_2
# 39 "data/scripts/schedule/chii_town.pory"
	case TIME_EARLY_MORNING, ChiiTown_DrawMetatiles_3
# 40 "data/scripts/schedule/chii_town.pory"
	case TIME_MORNING, ChiiTown_DrawMetatiles_3
# 41 "data/scripts/schedule/chii_town.pory"
	case TIME_LUNCHTIME, ChiiTown_DrawMetatiles_3
# 42 "data/scripts/schedule/chii_town.pory"
	case TIME_NOONTIME, ChiiTown_DrawMetatiles_3
# 43 "data/scripts/schedule/chii_town.pory"
	case TIME_EVENING, ChiiTown_DrawMetatiles_3
# 44 "data/scripts/schedule/chii_town.pory"
	case TIME_NIGHT, ChiiTown_DrawMetatiles_3
ChiiTown_DrawMetatiles_3:
	end

ChiiTown_DrawMetatiles_2:
# 37 "data/scripts/schedule/chii_town.pory"
	setmetatile 14, 6, METATILE_PorytilesPrimaryTutorial_DoorPlaceholder, TRUE
# 38 "data/scripts/schedule/chii_town.pory"
	setmetatile 24, 20, METATILE_PorytilesPrimaryTutorial_DoorPlaceholder, TRUE
	return


ChiiTown_DeadNightSchedules:
	return


ChiiTown_EarlySchedules:
# 55 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_8
	return


ChiiTown_MorningSchedules:
# 59 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_6
# 60 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_8
	return


ChiiTown_LunchtimeSchedules:
# 63 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_5
# 64 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_8
	return


ChiiTown_AfternoonSchedules:
# 67 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_6
# 68 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_7
# 69 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_8
	return


ChiiTown_EveningSchedules:
# 72 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_8
	return


ChiiTown_NightSchedules:
# 75 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_8
	return


ChiiTownSchool_NPCSchedules::
# 87 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_1
# 88 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_2
# 89 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_3
# 90 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 91 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 92 "data/scripts/schedule/chii_town.pory"
	case TIME_DEAD_NIGHT, ChiiTownSchool_NPCSchedules_2
# 94 "data/scripts/schedule/chii_town.pory"
	case TIME_EARLY_MORNING, ChiiTownSchool_NPCSchedules_3
# 96 "data/scripts/schedule/chii_town.pory"
	case TIME_MORNING, ChiiTownSchool_NPCSchedules_4
# 98 "data/scripts/schedule/chii_town.pory"
	case TIME_LUNCHTIME, ChiiTownSchool_NPCSchedules_5
# 100 "data/scripts/schedule/chii_town.pory"
	case TIME_NOONTIME, ChiiTownSchool_NPCSchedules_6
# 102 "data/scripts/schedule/chii_town.pory"
	case TIME_EVENING, ChiiTownSchool_NPCSchedules_7
# 104 "data/scripts/schedule/chii_town.pory"
	case TIME_NIGHT, ChiiTownSchool_NPCSchedules_8
	return

ChiiTownSchool_NPCSchedules_2:
# 93 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_DeadNightSchedules
	return

ChiiTownSchool_NPCSchedules_3:
# 95 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_EarlySchedules
	return

ChiiTownSchool_NPCSchedules_4:
# 97 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_MorningSchedules
	return

ChiiTownSchool_NPCSchedules_5:
# 99 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_LunchtimeSchedules
	return

ChiiTownSchool_NPCSchedules_6:
# 101 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_AfternoonSchedules
	return

ChiiTownSchool_NPCSchedules_7:
# 103 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_EveningSchedules
	return

ChiiTownSchool_NPCSchedules_8:
# 105 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_NightSchedules
	return


ChiiTownSchool_DeadNightSchedules:
	return


ChiiTownSchool_EarlySchedules:
# 135 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_MorningSchedules:
# 139 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_1
# 140 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
# 141 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_LunchtimeSchedules:
# 144 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
	return


ChiiTownSchool_AfternoonSchedules:
# 147 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_1
# 148 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
# 149 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_EveningSchedules:
# 152 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_NightSchedules:
	return

