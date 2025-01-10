ChiiTown_NPCSchedules::
# 9 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_5
# 10 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_6
# 11 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 12 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 13 "data/scripts/schedule/chii_town.pory"
	case TIME_DEAD_NIGHT, ChiiTown_NPCSchedules_2
# 15 "data/scripts/schedule/chii_town.pory"
	case TIME_EARLY_MORNING, ChiiTown_NPCSchedules_3
# 17 "data/scripts/schedule/chii_town.pory"
	case TIME_MORNING, ChiiTown_NPCSchedules_4
# 19 "data/scripts/schedule/chii_town.pory"
	case TIME_LUNCHTIME, ChiiTown_NPCSchedules_5
# 21 "data/scripts/schedule/chii_town.pory"
	case TIME_NOONTIME, ChiiTown_NPCSchedules_6
# 23 "data/scripts/schedule/chii_town.pory"
	case TIME_EVENING, ChiiTown_NPCSchedules_7
# 25 "data/scripts/schedule/chii_town.pory"
	case TIME_NIGHT, ChiiTown_NPCSchedules_8
	return

ChiiTown_NPCSchedules_2:
# 14 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_DeadNightSchedules
	return

ChiiTown_NPCSchedules_3:
# 16 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EarlySchedules
	return

ChiiTown_NPCSchedules_4:
# 18 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_MorningSchedules
	return

ChiiTown_NPCSchedules_5:
# 20 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_LunchtimeSchedules
	return

ChiiTown_NPCSchedules_6:
# 22 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_AfternoonSchedules
	return

ChiiTown_NPCSchedules_7:
# 24 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EveningSchedules
	return

ChiiTown_NPCSchedules_8:
# 26 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_NightSchedules
	return


ChiiTown_DeadNightSchedules:
	return


ChiiTown_EarlySchedules:
	return


ChiiTown_MorningSchedules:
# 60 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_6
	return


ChiiTown_LunchtimeSchedules:
# 63 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_5
	return


ChiiTown_AfternoonSchedules:
# 66 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_6
	return


ChiiTown_EveningSchedules:
	return


ChiiTown_NightSchedules:
	return


ChiiTownSchool_NPCSchedules::
# 84 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_1
# 85 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_2
# 86 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_3
# 87 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 88 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 89 "data/scripts/schedule/chii_town.pory"
	case TIME_DEAD_NIGHT, ChiiTownSchool_NPCSchedules_2
# 91 "data/scripts/schedule/chii_town.pory"
	case TIME_EARLY_MORNING, ChiiTownSchool_NPCSchedules_3
# 93 "data/scripts/schedule/chii_town.pory"
	case TIME_MORNING, ChiiTownSchool_NPCSchedules_4
# 95 "data/scripts/schedule/chii_town.pory"
	case TIME_LUNCHTIME, ChiiTownSchool_NPCSchedules_5
# 97 "data/scripts/schedule/chii_town.pory"
	case TIME_NOONTIME, ChiiTownSchool_NPCSchedules_6
# 99 "data/scripts/schedule/chii_town.pory"
	case TIME_EVENING, ChiiTownSchool_NPCSchedules_7
# 101 "data/scripts/schedule/chii_town.pory"
	case TIME_NIGHT, ChiiTownSchool_NPCSchedules_8
	return

ChiiTownSchool_NPCSchedules_2:
# 90 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_DeadNightSchedules
	return

ChiiTownSchool_NPCSchedules_3:
# 92 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_EarlySchedules
	return

ChiiTownSchool_NPCSchedules_4:
# 94 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_MorningSchedules
	return

ChiiTownSchool_NPCSchedules_5:
# 96 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_LunchtimeSchedules
	return

ChiiTownSchool_NPCSchedules_6:
# 98 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_AfternoonSchedules
	return

ChiiTownSchool_NPCSchedules_7:
# 100 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_EveningSchedules
	return

ChiiTownSchool_NPCSchedules_8:
# 102 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_NightSchedules
	return


ChiiTownSchool_DeadNightSchedules:
	return


ChiiTownSchool_EarlySchedules:
# 132 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_MorningSchedules:
# 136 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_1
# 137 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
# 138 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_LunchtimeSchedules:
# 141 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
	return


ChiiTownSchool_AfternoonSchedules:
# 144 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_1
# 145 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
# 146 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_EveningSchedules:
# 149 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_NightSchedules:
	return

