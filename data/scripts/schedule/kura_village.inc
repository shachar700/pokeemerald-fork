KuraVillage_NPCSchedules::
# 9 "data/scripts/schedule/kura_village.pory"
	setflag FLAG_TEMP_1
# 10 "data/scripts/schedule/kura_village.pory"
	setflag FLAG_TEMP_2
# 11 "data/scripts/schedule/kura_village.pory"
	gettimeofday
# 12 "data/scripts/schedule/kura_village.pory"
	switch VAR_0x8000
# 13 "data/scripts/schedule/kura_village.pory"
	case TIME_DEAD_NIGHT, KuraVillage_NPCSchedules_2
# 15 "data/scripts/schedule/kura_village.pory"
	case TIME_EARLY_MORNING, KuraVillage_NPCSchedules_3
# 17 "data/scripts/schedule/kura_village.pory"
	case TIME_MORNING, KuraVillage_NPCSchedules_4
# 19 "data/scripts/schedule/kura_village.pory"
	case TIME_LUNCHTIME, KuraVillage_NPCSchedules_5
# 21 "data/scripts/schedule/kura_village.pory"
	case TIME_NOONTIME, KuraVillage_NPCSchedules_6
# 23 "data/scripts/schedule/kura_village.pory"
	case TIME_EVENING, KuraVillage_NPCSchedules_7
# 25 "data/scripts/schedule/kura_village.pory"
	case TIME_NIGHT, KuraVillage_NPCSchedules_8
	return

KuraVillage_NPCSchedules_2:
# 14 "data/scripts/schedule/kura_village.pory"
	call KuraVillage_DeadNightSchedules
	return

KuraVillage_NPCSchedules_3:
# 16 "data/scripts/schedule/kura_village.pory"
	call KuraVillage_EarlySchedules
	return

KuraVillage_NPCSchedules_4:
# 18 "data/scripts/schedule/kura_village.pory"
	call KuraVillage_MorningSchedules
	return

KuraVillage_NPCSchedules_5:
# 20 "data/scripts/schedule/kura_village.pory"
	call KuraVillage_LunchtimeSchedules
	return

KuraVillage_NPCSchedules_6:
# 22 "data/scripts/schedule/kura_village.pory"
	call KuraVillage_AfternoonSchedules
	return

KuraVillage_NPCSchedules_7:
# 24 "data/scripts/schedule/kura_village.pory"
	call KuraVillage_EveningSchedules
	return

KuraVillage_NPCSchedules_8:
# 26 "data/scripts/schedule/kura_village.pory"
	call KuraVillage_NightSchedules
	return


KuraVillage_DrawMetatiles::
# 31 "data/scripts/schedule/kura_village.pory"
	gettimeofday
# 32 "data/scripts/schedule/kura_village.pory"
	switch VAR_0x8000
# 33 "data/scripts/schedule/kura_village.pory"
	case TIME_DEAD_NIGHT, KuraVillage_DrawMetatiles_2
# 38 "data/scripts/schedule/kura_village.pory"
	case TIME_EARLY_MORNING, KuraVillage_DrawMetatiles_3
# 39 "data/scripts/schedule/kura_village.pory"
	case TIME_MORNING, KuraVillage_DrawMetatiles_3
# 40 "data/scripts/schedule/kura_village.pory"
	case TIME_LUNCHTIME, KuraVillage_DrawMetatiles_3
# 41 "data/scripts/schedule/kura_village.pory"
	case TIME_NOONTIME, KuraVillage_DrawMetatiles_3
# 42 "data/scripts/schedule/kura_village.pory"
	case TIME_EVENING, KuraVillage_DrawMetatiles_3
# 43 "data/scripts/schedule/kura_village.pory"
	case TIME_NIGHT, KuraVillage_DrawMetatiles_3
KuraVillage_DrawMetatiles_3:
	end

KuraVillage_DrawMetatiles_2:
# 34 "data/scripts/schedule/kura_village.pory"
	setmetatile 40, 16, METATILE_SakuKura_Door, TRUE
# 35 "data/scripts/schedule/kura_village.pory"
	setmetatile 43, 23, METATILE_SakuKura_Door, TRUE
# 36 "data/scripts/schedule/kura_village.pory"
	setmetatile 34, 25, METATILE_SakuKura_Door, TRUE
# 37 "data/scripts/schedule/kura_village.pory"
	setmetatile 18, 7, METATILE_SakuKura_Door, TRUE
	return


KuraVillage_DeadNightSchedules:
	return


KuraVillage_EarlySchedules:
# 55 "data/scripts/schedule/kura_village.pory"
	clearflag FLAG_TEMP_1
	return


KuraVillage_MorningSchedules:
# 59 "data/scripts/schedule/kura_village.pory"
	clearflag FLAG_TEMP_1
	return


KuraVillage_LunchtimeSchedules:
# 62 "data/scripts/schedule/kura_village.pory"
	clearflag FLAG_TEMP_2
	return


KuraVillage_AfternoonSchedules:
# 65 "data/scripts/schedule/kura_village.pory"
	clearflag FLAG_TEMP_1
	return


KuraVillage_EveningSchedules:
	return


KuraVillage_NightSchedules:
	return

