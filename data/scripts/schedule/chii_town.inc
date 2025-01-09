ChiiTown_NPCSchedules::
# 3 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 4 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 5 "data/scripts/schedule/chii_town.pory"
	case TIME_DEAD_NIGHT, ChiiTown_NPCSchedules_2
# 7 "data/scripts/schedule/chii_town.pory"
	case TIME_EARLY_MORNING, ChiiTown_NPCSchedules_3
# 9 "data/scripts/schedule/chii_town.pory"
	case TIME_MORNING, ChiiTown_NPCSchedules_4
# 11 "data/scripts/schedule/chii_town.pory"
	case TIME_LUNCHTIME, ChiiTown_NPCSchedules_5
# 13 "data/scripts/schedule/chii_town.pory"
	case TIME_NOONTIME, ChiiTown_NPCSchedules_6
# 15 "data/scripts/schedule/chii_town.pory"
	case TIME_EVENING, ChiiTown_NPCSchedules_7
# 17 "data/scripts/schedule/chii_town.pory"
	case TIME_NIGHT, ChiiTown_NPCSchedules_8
	return

ChiiTown_NPCSchedules_2:
# 6 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_DeadNightSchedules
	return

ChiiTown_NPCSchedules_3:
# 8 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EarlySchedules
	return

ChiiTown_NPCSchedules_4:
# 10 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_MorningSchedules
	return

ChiiTown_NPCSchedules_5:
# 12 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_LunchtimeSchedules
	return

ChiiTown_NPCSchedules_6:
# 14 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_AfternoonSchedules
	return

ChiiTown_NPCSchedules_7:
# 16 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EveningSchedules
	return

ChiiTown_NPCSchedules_8:
# 18 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_NightSchedules
	return


ChiiTown_DeadNightSchedules:
	return


ChiiTown_EarlySchedules:
	return


ChiiTown_MorningSchedules:
	return


ChiiTown_LunchtimeSchedules:
	return


ChiiTown_AfternoonSchedules:
	return


ChiiTown_EveningSchedules:
	return


ChiiTown_NightSchedules:
	return

