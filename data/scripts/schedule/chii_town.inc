ChiiTown_NPCSchedules::
# 5 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_5
# 6 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_6
# 7 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 8 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 9 "data/scripts/schedule/chii_town.pory"
	case TIME_DEAD_NIGHT, ChiiTown_NPCSchedules_2
# 11 "data/scripts/schedule/chii_town.pory"
	case TIME_EARLY_MORNING, ChiiTown_NPCSchedules_3
# 13 "data/scripts/schedule/chii_town.pory"
	case TIME_MORNING, ChiiTown_NPCSchedules_4
# 15 "data/scripts/schedule/chii_town.pory"
	case TIME_LUNCHTIME, ChiiTown_NPCSchedules_5
# 17 "data/scripts/schedule/chii_town.pory"
	case TIME_NOONTIME, ChiiTown_NPCSchedules_6
# 19 "data/scripts/schedule/chii_town.pory"
	case TIME_EVENING, ChiiTown_NPCSchedules_7
# 21 "data/scripts/schedule/chii_town.pory"
	case TIME_NIGHT, ChiiTown_NPCSchedules_8
	return

ChiiTown_NPCSchedules_2:
# 10 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_DeadNightSchedules
	return

ChiiTown_NPCSchedules_3:
# 12 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EarlySchedules
	return

ChiiTown_NPCSchedules_4:
# 14 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_MorningSchedules
	return

ChiiTown_NPCSchedules_5:
# 16 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_LunchtimeSchedules
	return

ChiiTown_NPCSchedules_6:
# 18 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_AfternoonSchedules
	return

ChiiTown_NPCSchedules_7:
# 20 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EveningSchedules
	return

ChiiTown_NPCSchedules_8:
# 22 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_NightSchedules
	return


ChiiTown_DeadNightSchedules:
	return


ChiiTown_EarlySchedules:
	return


ChiiTown_MorningSchedules:
# 56 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_6
	return


ChiiTown_LunchtimeSchedules:
# 59 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_5
	return


ChiiTown_AfternoonSchedules:
# 62 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_6
	return


ChiiTown_EveningSchedules:
	return


ChiiTown_NightSchedules:
	return

