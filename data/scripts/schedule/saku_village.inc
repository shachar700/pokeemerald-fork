SakuVillage_NPCSchedules::
# 4 "data/scripts/schedule/saku_village.pory"
	setflag FLAG_TEMP_1
# 5 "data/scripts/schedule/saku_village.pory"
	setflag FLAG_TEMP_2
# 6 "data/scripts/schedule/saku_village.pory"
	gettimeofday
# 7 "data/scripts/schedule/saku_village.pory"
	switch VAR_0x8000
# 8 "data/scripts/schedule/saku_village.pory"
	case TIME_DEAD_NIGHT, SakuVillage_NPCSchedules_2
# 10 "data/scripts/schedule/saku_village.pory"
	case TIME_EARLY_MORNING, SakuVillage_NPCSchedules_3
# 12 "data/scripts/schedule/saku_village.pory"
	case TIME_MORNING, SakuVillage_NPCSchedules_4
# 14 "data/scripts/schedule/saku_village.pory"
	case TIME_LUNCHTIME, SakuVillage_NPCSchedules_5
# 16 "data/scripts/schedule/saku_village.pory"
	case TIME_NOONTIME, SakuVillage_NPCSchedules_6
# 18 "data/scripts/schedule/saku_village.pory"
	case TIME_EVENING, SakuVillage_NPCSchedules_7
# 20 "data/scripts/schedule/saku_village.pory"
	case TIME_NIGHT, SakuVillage_NPCSchedules_8
	return

SakuVillage_NPCSchedules_2:
# 9 "data/scripts/schedule/saku_village.pory"
	call SakuVillage_DeadNightSchedules
	return

SakuVillage_NPCSchedules_3:
# 11 "data/scripts/schedule/saku_village.pory"
	call SakuVillage_EarlySchedules
	return

SakuVillage_NPCSchedules_4:
# 13 "data/scripts/schedule/saku_village.pory"
	call SakuVillage_MorningSchedules
	return

SakuVillage_NPCSchedules_5:
# 15 "data/scripts/schedule/saku_village.pory"
	call SakuVillage_LunchtimeSchedules
	return

SakuVillage_NPCSchedules_6:
# 17 "data/scripts/schedule/saku_village.pory"
	call SakuVillage_AfternoonSchedules
	return

SakuVillage_NPCSchedules_7:
# 19 "data/scripts/schedule/saku_village.pory"
	call SakuVillage_EveningSchedules
	return

SakuVillage_NPCSchedules_8:
# 21 "data/scripts/schedule/saku_village.pory"
	call SakuVillage_NightSchedules
	return


SakuVillage_DrawMetatiles::
# 26 "data/scripts/schedule/saku_village.pory"
	gettimeofday
# 27 "data/scripts/schedule/saku_village.pory"
	switch VAR_0x8000
# 28 "data/scripts/schedule/saku_village.pory"
	case TIME_DEAD_NIGHT, SakuVillage_DrawMetatiles_2
# 33 "data/scripts/schedule/saku_village.pory"
	case TIME_EARLY_MORNING, SakuVillage_DrawMetatiles_3
# 34 "data/scripts/schedule/saku_village.pory"
	case TIME_MORNING, SakuVillage_DrawMetatiles_3
# 35 "data/scripts/schedule/saku_village.pory"
	case TIME_LUNCHTIME, SakuVillage_DrawMetatiles_3
# 36 "data/scripts/schedule/saku_village.pory"
	case TIME_NOONTIME, SakuVillage_DrawMetatiles_3
# 37 "data/scripts/schedule/saku_village.pory"
	case TIME_EVENING, SakuVillage_DrawMetatiles_3
# 38 "data/scripts/schedule/saku_village.pory"
	case TIME_NIGHT, SakuVillage_DrawMetatiles_3
SakuVillage_DrawMetatiles_3:
	end

SakuVillage_DrawMetatiles_2:
# 29 "data/scripts/schedule/saku_village.pory"
	setmetatile 16, 20, METATILE_SakuKura_Door, TRUE
# 30 "data/scripts/schedule/saku_village.pory"
	setmetatile 22, 18, METATILE_SakuKura_Door, TRUE
# 31 "data/scripts/schedule/saku_village.pory"
	setmetatile 18, 33, METATILE_SakuKura_Door, TRUE
# 32 "data/scripts/schedule/saku_village.pory"
	setmetatile 35, 31, METATILE_SakuKura_Door, TRUE
	return


SakuVillage_DeadNightSchedules:
	return


SakuVillage_EarlySchedules:
# 50 "data/scripts/schedule/saku_village.pory"
	clearflag FLAG_TEMP_1
	return


SakuVillage_MorningSchedules:
# 54 "data/scripts/schedule/saku_village.pory"
	clearflag FLAG_TEMP_1
	return


SakuVillage_LunchtimeSchedules:
# 57 "data/scripts/schedule/saku_village.pory"
	clearflag FLAG_TEMP_2
	return


SakuVillage_AfternoonSchedules:
# 60 "data/scripts/schedule/saku_village.pory"
	clearflag FLAG_TEMP_1
	return


SakuVillage_EveningSchedules:
	return


SakuVillage_NightSchedules:
	return

