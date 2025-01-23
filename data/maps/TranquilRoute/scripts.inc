TranquilRoute_MapScripts::
# 15 "data/maps/TranquilRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, TranquilRoute_MapScripts_MAP_SCRIPT_ON_LOAD
# 19 "data/maps/TranquilRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TranquilRoute_EventScript_SetupCutGrassCutscene
# 20 "data/maps/TranquilRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TranquilRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TranquilRoute_MapScripts_MAP_SCRIPT_ON_LOAD:
# 16 "data/maps/TranquilRoute/scripts.pory"
	call TranquilRoute_EventScript_CheckCutGrass
# 17 "data/maps/TranquilRoute/scripts.pory"
	call TranquilRoute_EventScript_SpawnBirds
	return

TranquilRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 21 "data/maps/TranquilRoute/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, TranquilRoute_EventScript_GrassCutscene
	.2byte 0


TranquilRoute_EventScript_SpawnBirds::
# 28 "data/maps/TranquilRoute/scripts.pory"
	setflag FLAG_TEMP_2
# 30 "data/maps/TranquilRoute/scripts.pory"
	gettime
# 32 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_0x8000, 9
	goto_if_ge TranquilRoute_EventScript_SpawnBirds_2
	return

TranquilRoute_EventScript_SpawnBirds_1:
# 33 "data/maps/TranquilRoute/scripts.pory"
	clearflag FLAG_TEMP_2
	return

TranquilRoute_EventScript_SpawnBirds_2:
# 32 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_0x8000, 17
	goto_if_le TranquilRoute_EventScript_SpawnBirds_1
	return


TranquilRoute_EventScript_GrassCutscene::
# 39 "data/maps/TranquilRoute/scripts.pory"
	lock
# 41 "data/maps/TranquilRoute/scripts.pory"
	applymovement 22, TranquilRoute_EventScript_GrassCutscene_Movement_0
# 42 "data/maps/TranquilRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TranquilRoute_EventScript_GrassCutscene_Movement_1
# 43 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 22
# 44 "data/maps/TranquilRoute/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 46 "data/maps/TranquilRoute/scripts.pory"
	delay 24
# 48 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
# 49 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_1
# 52 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 54 "data/maps/TranquilRoute/scripts.pory"
	delay 16
# 56 "data/maps/TranquilRoute/scripts.pory"
	applymovement 22, TranquilRoute_CutMasterWalkLeft
# 57 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 58 "data/maps/TranquilRoute/scripts.pory"
	delay 24
# 59 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
# 60 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_2
# 63 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 65 "data/maps/TranquilRoute/scripts.pory"
	applymovement 22, TranquilRoute_CutMasterWalkRight
# 66 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 67 "data/maps/TranquilRoute/scripts.pory"
	delay 24
# 68 "data/maps/TranquilRoute/scripts.pory"
	delay 24
# 69 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
# 70 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_3
# 73 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 75 "data/maps/TranquilRoute/scripts.pory"
	applymovement 22, TranquilRoute_CutMasterWalkBackToPlayer
# 76 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 77 "data/maps/TranquilRoute/scripts.pory"
	delay 48
# 78 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
# 79 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_4
# 83 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 87 "data/maps/TranquilRoute/scripts.pory"
	setflag FLAG_CUT_QUEST_COMPLETED
# 88 "data/maps/TranquilRoute/scripts.pory"
	setvar VAR_TEMP_0, 0
# 90 "data/maps/TranquilRoute/scripts.pory"
	release
	return


TranquilRoute_EventScript_SetupCutGrassCutscene::
# 95 "data/maps/TranquilRoute/scripts.pory"
	goto_if_unset FLAG_CUT_QUEST_COMPLETED, TranquilRoute_EventScript_SetupCutGrassCutscene_1
# 109 "data/maps/TranquilRoute/scripts.pory"
	gettime
# 110 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_0x8000, 7
	goto_if_lt TranquilRoute_EventScript_SetupCutGrassCutscene_7
# 110 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_0x8000, 19
	goto_if_gt TranquilRoute_EventScript_SetupCutGrassCutscene_7
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_1:
# 96 "data/maps/TranquilRoute/scripts.pory"
	goto_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_EventScript_SetupCutGrassCutscene_4
# 106 "data/maps/TranquilRoute/scripts.pory"
	setflag FLAG_TEMP_1
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_4:
# 99 "data/maps/TranquilRoute/scripts.pory"
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
# 100 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_TEMP_2, 53
	goto_if_eq TranquilRoute_EventScript_SetupCutGrassCutscene_12
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_7:
# 111 "data/maps/TranquilRoute/scripts.pory"
	setflag FLAG_TEMP_1
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_11:
# 101 "data/maps/TranquilRoute/scripts.pory"
	setobjectmovementtype 22, MOVEMENT_TYPE_FACE_LEFT
# 102 "data/maps/TranquilRoute/scripts.pory"
	setobjectxyperm 22, 52, 33
# 103 "data/maps/TranquilRoute/scripts.pory"
	setvar VAR_TEMP_0, 1
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_12:
# 100 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_TEMP_3, 33
	goto_if_eq TranquilRoute_EventScript_SetupCutGrassCutscene_11
	return


TranquilRoute_EventScript_CutMaster::
# 118 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
# 119 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_CutMaster_Text_0, MSGBOX_NPC
	return


TranquilRoute_EventScript_CheckCutGrass::
# 126 "data/maps/TranquilRoute/scripts.pory"
	call_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_EventScript_CutGrass
	return


TranquilRoute_EventScript_CutGrass::
# 132 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 31, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 134 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 30, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 136 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 29, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 137 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 29, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 139 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 28, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 140 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 28, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 141 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 28, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 143 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 27, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 144 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 27, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 145 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 27, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 147 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 26, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 148 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 26, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 150 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 25, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 152 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 24, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 154 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 23, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 155 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 23, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 157 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 41, 22, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 158 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 42, 22, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 159 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 22, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 160 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 22, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 162 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 40, 21, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 163 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 41, 21, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 164 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 42, 21, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 165 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 43, 21, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 166 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 45, 21, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 167 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 21, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 168 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 21, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 169 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 21, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 171 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 41, 20, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 172 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 42, 20, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 173 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 43, 20, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 174 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 44, 20, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 175 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 45, 20, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 176 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 20, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 177 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 20, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 178 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 20, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 180 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 40, 19, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 181 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 42, 19, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 182 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 43, 19, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 183 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 44, 19, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 184 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 45, 19, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 185 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 19, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 186 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 19, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 187 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 19, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 188 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 49, 19, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 190 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 41, 18, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 191 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 43, 18, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 192 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 44, 18, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 193 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 45, 18, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
# 194 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 46, 18, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
# 195 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 47, 18, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
# 196 "data/maps/TranquilRoute/scripts.pory"
	setmetatile 48, 18, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	return


TranquilRoute_EventScript_Chikao::
# 201 "data/maps/TranquilRoute/scripts.pory"
	trainerbattle_single TRAINER_CHIKAO, TranquilRoute_EventScript_Chikao_Text_0, TranquilRoute_EventScript_Chikao_Text_1
# 206 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Chikao_Text_2
# 207 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Chikao_Text_3
# 211 "data/maps/TranquilRoute/scripts.pory"
	closemessage
	end


TranquilRoute_EventScript_Kodomo::
# 216 "data/maps/TranquilRoute/scripts.pory"
	trainerbattle_single TRAINER_KODOMO, TranquilRoute_EventScript_Kodomo_Text_0, TranquilRoute_EventScript_Kodomo_Text_1
# 221 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Kodomo_Text_2
# 222 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Kodomo_Text_3
# 225 "data/maps/TranquilRoute/scripts.pory"
	closemessage
	end


TranquilRoute_EventScript_Takeshi::
# 230 "data/maps/TranquilRoute/scripts.pory"
	trainerbattle_single TRAINER_TAKESHI, TranquilRoute_EventScript_Takeshi_Text_0, TranquilRoute_EventScript_Takeshi_Text_1
# 235 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Takeshi_Text_2
# 236 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Takeshi_Text_3, MSGBOX_AUTOCLOSE
	end


TranquilRoute_EventScript_Hana::
# 241 "data/maps/TranquilRoute/scripts.pory"
	trainerbattle_single TRAINER_HIINA, TranquilRoute_EventScript_Hana_Text_0, TranquilRoute_EventScript_Hana_Text_1
# 246 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Hana_Text_2
# 247 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Hana_Text_3, MSGBOX_AUTOCLOSE
	end


TranquilRoute_EventScript_Kenji::
# 252 "data/maps/TranquilRoute/scripts.pory"
	trainerbattle_single TRAINER_KENJI, TranquilRoute_EventScript_Kenji_Text_0, TranquilRoute_EventScript_Kenji_Text_1
# 257 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Kenji_Text_2
# 258 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Kenji_Text_3, MSGBOX_AUTOCLOSE
	end


# 265 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_Movement_MysteriousSamuraiWalksAway:
# 266 "data/maps/TranquilRoute/scripts.pory"
	walk_right
# 266 "data/maps/TranquilRoute/scripts.pory"
	walk_right
# 266 "data/maps/TranquilRoute/scripts.pory"
	walk_right
# 266 "data/maps/TranquilRoute/scripts.pory"
	walk_right
# 266 "data/maps/TranquilRoute/scripts.pory"
	walk_right
# 266 "data/maps/TranquilRoute/scripts.pory"
	walk_right
	step_end

TranquilRoute_EventScript_Girl::
# 270 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Girl_Text_0
# 271 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Girl_Text_1, MSGBOX_NPC
	return


TranquilRoute_EventScript_WhiteslateRoadblock::
# 275 "data/maps/TranquilRoute/scripts.pory"
	lock
# 276 "data/maps/TranquilRoute/scripts.pory"
	applymovement 21, Common_Movement_WalkInPlaceFasterRight
# 277 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 279 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_WhiteslateRoadblock_Text_0
# 280 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_WhiteslateRoadblock_Text_1
# 281 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 283 "data/maps/TranquilRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TranquilRoute_EventScript_WhiteslateRoadblock_Movement_0
# 284 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 286 "data/maps/TranquilRoute/scripts.pory"
	release
	return


TranquilRoute_EventScript_Shellos::
# 290 "data/maps/TranquilRoute/scripts.pory"
	lock
# 291 "data/maps/TranquilRoute/scripts.pory"
	faceplayer
# 292 "data/maps/TranquilRoute/scripts.pory"
	playmoncry SPECIES_SHELLOS, CRY_MODE_NORMAL
# 293 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne TranquilRoute_EventScript_Shellos_2
# 296 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Shellos_Text_1
TranquilRoute_EventScript_Shellos_1:
# 298 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Shellos_Text_2
# 301 "data/maps/TranquilRoute/scripts.pory"
	waitmoncry
# 302 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 303 "data/maps/TranquilRoute/scripts.pory"
	release
	end

TranquilRoute_EventScript_Shellos_2:
# 294 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Shellos_Text_0
	goto TranquilRoute_EventScript_Shellos_1


TranquilRoute_EventScript_BerryWoman::
# 308 "data/maps/TranquilRoute/scripts.pory"
	lock
# 309 "data/maps/TranquilRoute/scripts.pory"
	faceplayer
# 311 "data/maps/TranquilRoute/scripts.pory"
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, TranquilRoute_EventScript_BerryWoman_2
# 317 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
# 318 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_BerryWoman_Text_2
# 319 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 320 "data/maps/TranquilRoute/scripts.pory"
	applymovement 5, Common_Movement_FaceRight
# 321 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 322 "data/maps/TranquilRoute/scripts.pory"
	delay 48
# 323 "data/maps/TranquilRoute/scripts.pory"
	applymovement 5, Common_Movement_FacePlayer
# 324 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 325 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
# 326 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_BerryWoman_Text_3
# 333 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 334 "data/maps/TranquilRoute/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 3
# 335 "data/maps/TranquilRoute/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 337 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
# 338 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_BerryWoman_Text_4
# 343 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 344 "data/maps/TranquilRoute/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 345 "data/maps/TranquilRoute/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 347 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
# 348 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_BerryWoman_Text_5
# 353 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 355 "data/maps/TranquilRoute/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_PAIL
TranquilRoute_EventScript_BerryWoman_1:
# 357 "data/maps/TranquilRoute/scripts.pory"
	release
	end

TranquilRoute_EventScript_BerryWoman_2:
# 312 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
# 313 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_BerryWoman_Text_1
# 314 "data/maps/TranquilRoute/scripts.pory"
	closemessage
	goto TranquilRoute_EventScript_BerryWoman_1


TranquilRoute_EventScript_Mareep::
# 362 "data/maps/TranquilRoute/scripts.pory"
	lock
# 363 "data/maps/TranquilRoute/scripts.pory"
	playmoncry SPECIES_MAREEP, CRY_MODE_NORMAL
# 364 "data/maps/TranquilRoute/scripts.pory"
	ismonseen SPECIES_MAREEP
# 365 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne TranquilRoute_EventScript_Mareep_2
# 368 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Mareep_Text_1
TranquilRoute_EventScript_Mareep_1:
# 370 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Mareep_Text_2
# 371 "data/maps/TranquilRoute/scripts.pory"
	waitmoncry
# 372 "data/maps/TranquilRoute/scripts.pory"
	release
	return

TranquilRoute_EventScript_Mareep_2:
# 366 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Mareep_Text_0
	goto TranquilRoute_EventScript_Mareep_1


TranquilRoute_EventScript_Mareep2::
# 376 "data/maps/TranquilRoute/scripts.pory"
	lock
# 377 "data/maps/TranquilRoute/scripts.pory"
	playmoncry SPECIES_MAREEP, CRY_MODE_WEAK
# 378 "data/maps/TranquilRoute/scripts.pory"
	ismonseen SPECIES_MAREEP
# 379 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne TranquilRoute_EventScript_Mareep2_2
# 382 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Mareep_Text_1
TranquilRoute_EventScript_Mareep2_1:
# 384 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Mareep2_Text_0
# 385 "data/maps/TranquilRoute/scripts.pory"
	waitmoncry
# 386 "data/maps/TranquilRoute/scripts.pory"
	release
	return

TranquilRoute_EventScript_Mareep2_2:
# 380 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Mareep_Text_0
	goto TranquilRoute_EventScript_Mareep2_1


TranquilRoute_TrainerTips1::
# 390 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_TrainerTips1_Text_0, MSGBOX_SIGN
	return


TranquilRoute_EventScript_CrobatShadows_Camera::
# 398 "data/maps/TranquilRoute/scripts.pory"
	lock
# 399 "data/maps/TranquilRoute/scripts.pory"
	special SpawnCameraObject
# 400 "data/maps/TranquilRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TranquilRoute_EventScript_CrobatShadows_Camera_Movement_0
# 401 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 402 "data/maps/TranquilRoute/scripts.pory"
	call TranquilRoute_EventScript_CrobatShadows_Cutscene
# 403 "data/maps/TranquilRoute/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TranquilRoute_EventScript_CrobatShadows_Camera_Movement_1
# 404 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 405 "data/maps/TranquilRoute/scripts.pory"
	special RemoveCameraObject
# 406 "data/maps/TranquilRoute/scripts.pory"
	release
	return


TranquilRoute_EventScript_CrobatShadows::
# 410 "data/maps/TranquilRoute/scripts.pory"
	lock
# 411 "data/maps/TranquilRoute/scripts.pory"
	call TranquilRoute_EventScript_CrobatShadows_Cutscene
# 412 "data/maps/TranquilRoute/scripts.pory"
	release
	return


TranquilRoute_EventScript_CrobatShadows_Cutscene::
# 416 "data/maps/TranquilRoute/scripts.pory"
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 1
# 418 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_0
# 419 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_1
# 424 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 426 "data/maps/TranquilRoute/scripts.pory"
	delay 20
# 428 "data/maps/TranquilRoute/scripts.pory"
	applymovement 25, Common_Movement_WalkInPlaceFasterUp
# 429 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 431 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_2
# 432 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_3
# 435 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 437 "data/maps/TranquilRoute/scripts.pory"
	applymovement 26, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_0
# 438 "data/maps/TranquilRoute/scripts.pory"
	applymovement 24, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_0
# 439 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 23
# 440 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 26
# 445 "data/maps/TranquilRoute/scripts.pory"
	playse SE_LEDGE
# 446 "data/maps/TranquilRoute/scripts.pory"
	applymovement 24, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1
# 447 "data/maps/TranquilRoute/scripts.pory"
	applymovement 23, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1
# 448 "data/maps/TranquilRoute/scripts.pory"
	applymovement 26, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1
# 449 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 24
# 450 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 23
# 451 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 26
# 452 "data/maps/TranquilRoute/scripts.pory"
	waitse
# 457 "data/maps/TranquilRoute/scripts.pory"
	applymovement 23, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2
# 458 "data/maps/TranquilRoute/scripts.pory"
	applymovement 24, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2
# 459 "data/maps/TranquilRoute/scripts.pory"
	applymovement 26, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2
# 460 "data/maps/TranquilRoute/scripts.pory"
	applymovement 25, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_3
# 461 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 23
# 462 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 24
# 463 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 26
# 464 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 25
# 466 "data/maps/TranquilRoute/scripts.pory"
	removeobject 23
# 467 "data/maps/TranquilRoute/scripts.pory"
	removeobject 24
# 468 "data/maps/TranquilRoute/scripts.pory"
	removeobject 26
# 469 "data/maps/TranquilRoute/scripts.pory"
	removeobject 25
# 470 "data/maps/TranquilRoute/scripts.pory"
	setflag FLAG_HIDE_CROBAT_SHADOWS_TRANQUIL_RT
	return


TranquilRoute_EventScript_TravelingMerchantFirstTime::
# 474 "data/maps/TranquilRoute/scripts.pory"
	lock
# 475 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0
# 476 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_1
# 479 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 481 "data/maps/TranquilRoute/scripts.pory"
	delay 24
# 482 "data/maps/TranquilRoute/scripts.pory"
	playse SE_PIN
# 483 "data/maps/TranquilRoute/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 484 "data/maps/TranquilRoute/scripts.pory"
	waitse
# 485 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 0
# 486 "data/maps/TranquilRoute/scripts.pory"
	delay 48
# 488 "data/maps/TranquilRoute/scripts.pory"
	faceplayer
# 490 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0
# 491 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_2
# 500 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 502 "data/maps/TranquilRoute/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 504 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0
# 505 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_3
# 508 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 510 "data/maps/TranquilRoute/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 511 "data/maps/TranquilRoute/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq TranquilRoute_EventScript_TravelingMerchantFirstTime_2
# 515 "data/maps/TranquilRoute/scripts.pory"
	applymovement VAR_LAST_TALKED, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_2
# 516 "data/maps/TranquilRoute/scripts.pory"
	applymovement 27, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_3
TranquilRoute_EventScript_TravelingMerchantFirstTime_1:
# 518 "data/maps/TranquilRoute/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 519 "data/maps/TranquilRoute/scripts.pory"
	waitmovement 27
# 521 "data/maps/TranquilRoute/scripts.pory"
	removeobject VAR_LAST_TALKED
# 522 "data/maps/TranquilRoute/scripts.pory"
	removeobject 27
# 524 "data/maps/TranquilRoute/scripts.pory"
	setflag FLAG_MET_TRAVELING_MERCHANT
# 525 "data/maps/TranquilRoute/scripts.pory"
	release
	return

TranquilRoute_EventScript_TravelingMerchantFirstTime_2:
# 512 "data/maps/TranquilRoute/scripts.pory"
	applymovement VAR_LAST_TALKED, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_0
# 513 "data/maps/TranquilRoute/scripts.pory"
	applymovement 27, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_1
	goto TranquilRoute_EventScript_TravelingMerchantFirstTime_1


TranquilRoute_EventScript_Kecleon::
# 529 "data/maps/TranquilRoute/scripts.pory"
	lock
# 530 "data/maps/TranquilRoute/scripts.pory"
	faceplayer
# 532 "data/maps/TranquilRoute/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 533 "data/maps/TranquilRoute/scripts.pory"
	speakername TranquilRoute_EventScript_Kecleon_Text_0
# 534 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_EventScript_Kecleon_Text_1
# 537 "data/maps/TranquilRoute/scripts.pory"
	waitmoncry
# 538 "data/maps/TranquilRoute/scripts.pory"
	closemessage
# 540 "data/maps/TranquilRoute/scripts.pory"
	release
	return


TranquilRoute_TrainerTips2::
# 544 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_TrainerTips2_Text_0, MSGBOX_SIGN
	return


TranquilRoute_DirectionSign::
# 557 "data/maps/TranquilRoute/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, TranquilRoute_DirectionSign_1
# 564 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_DirectionSign_Text_1, MSGBOX_SIGN
	return

TranquilRoute_DirectionSign_1:
# 558 "data/maps/TranquilRoute/scripts.pory"
	msgbox TranquilRoute_DirectionSign_Text_0, MSGBOX_SIGN
	return


# 571 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_CutMasterWalkLeft:
# 572 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 572 "data/maps/TranquilRoute/scripts.pory"
	walk_left
	step_end

# 575 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_CutMasterWalkRight:
# 576 "data/maps/TranquilRoute/scripts.pory"
	walk_right
# 576 "data/maps/TranquilRoute/scripts.pory"
	walk_right
# 576 "data/maps/TranquilRoute/scripts.pory"
	walk_right
	step_end

# 579 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_CutMasterWalkBackToPlayer:
# 580 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 581 "data/maps/TranquilRoute/scripts.pory"
	walk_in_place_faster_down
	step_end

# 41 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_GrassCutscene_Movement_0:
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 41 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 41 "data/maps/TranquilRoute/scripts.pory"
	face_up
	step_end

# 42 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_GrassCutscene_Movement_1:
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 42 "data/maps/TranquilRoute/scripts.pory"
	walk_up
	step_end

# 283 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_WhiteslateRoadblock_Movement_0:
# 283 "data/maps/TranquilRoute/scripts.pory"
	walk_right
	step_end

# 400 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_CrobatShadows_Camera_Movement_0:
# 400 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 400 "data/maps/TranquilRoute/scripts.pory"
	walk_up
	step_end

# 403 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_CrobatShadows_Camera_Movement_1:
# 403 "data/maps/TranquilRoute/scripts.pory"
	walk_down
# 403 "data/maps/TranquilRoute/scripts.pory"
	walk_down
	step_end

# 437 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_0:
# 437 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 437 "data/maps/TranquilRoute/scripts.pory"
	face_down
	step_end

# 446 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1:
# 446 "data/maps/TranquilRoute/scripts.pory"
	face_down
# 446 "data/maps/TranquilRoute/scripts.pory"
	zubats_align
# 446 "data/maps/TranquilRoute/scripts.pory"
	delay_16
# 446 "data/maps/TranquilRoute/scripts.pory"
	delay_16
	step_end

# 457 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2:
# 457 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 457 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 457 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 457 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 457 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 457 "data/maps/TranquilRoute/scripts.pory"
	delay_16
	step_end

# 460 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_3:
# 460 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 460 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 460 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 460 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 460 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 460 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 460 "data/maps/TranquilRoute/scripts.pory"
	walk_left
	step_end

# 512 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_0:
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 512 "data/maps/TranquilRoute/scripts.pory"
	walk_up
	step_end

# 513 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_1:
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 513 "data/maps/TranquilRoute/scripts.pory"
	walk_up
	step_end

# 515 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_2:
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 515 "data/maps/TranquilRoute/scripts.pory"
	walk_up
	step_end

# 516 "data/maps/TranquilRoute/scripts.pory"
TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_3:
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_left
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_up
# 516 "data/maps/TranquilRoute/scripts.pory"
	walk_up
	step_end

TranquilRoute_EventScript_GrassCutscene_Text_0:
# 48 "data/maps/TranquilRoute/scripts.pory"
	.string "Cut master$"

TranquilRoute_EventScript_GrassCutscene_Text_1:
# 50 "data/maps/TranquilRoute/scripts.pory"
	.string "… … … … … …\n"
	.string "… … … … … …$"

TranquilRoute_EventScript_GrassCutscene_Text_2:
# 61 "data/maps/TranquilRoute/scripts.pory"
	.string "Was it always this big?$"

TranquilRoute_EventScript_GrassCutscene_Text_3:
# 71 "data/maps/TranquilRoute/scripts.pory"
	.string "It doesn't even look like the same\n"
	.string "garden…$"

TranquilRoute_EventScript_GrassCutscene_Text_4:
# 80 "data/maps/TranquilRoute/scripts.pory"
	.string "I cannot thank you enough for this.\p"
	.string "I shall tend to my garden again,\n"
	.string "thanks to you.$"

TranquilRoute_EventScript_CutMaster_Text_0:
# 120 "data/maps/TranquilRoute/scripts.pory"
	.string "I'm enjoying tending my garden again.\p"
	.string "I like watching it slowly blossom into\n"
	.string "something beautiful.$"

TranquilRoute_EventScript_Chikao_Text_0:
# 203 "data/maps/TranquilRoute/scripts.pory"
	.string "I've been studying Pokémon at school!\n"
	.string "I can't lose!$"

TranquilRoute_EventScript_Chikao_Text_1:
# 204 "data/maps/TranquilRoute/scripts.pory"
	.string "I should have listened in class…$"

TranquilRoute_EventScript_Chikao_Text_2:
# 206 "data/maps/TranquilRoute/scripts.pory"
	.string "Chikao$"

TranquilRoute_EventScript_Chikao_Text_3:
# 208 "data/maps/TranquilRoute/scripts.pory"
	.string "Some Pokémon have more attack, and\n"
	.string "some have more special attack!\p"
	.string "What's the difference? Uhh… It's too\n"
	.string "complicated to explain.$"

TranquilRoute_EventScript_Kodomo_Text_0:
# 218 "data/maps/TranquilRoute/scripts.pory"
	.string "Ha! Are you trying to avoid the tall\n"
	.string "grass?$"

TranquilRoute_EventScript_Kodomo_Text_1:
# 219 "data/maps/TranquilRoute/scripts.pory"
	.string "Go back to the grass, you animal!$"

TranquilRoute_EventScript_Kodomo_Text_2:
# 221 "data/maps/TranquilRoute/scripts.pory"
	.string "Kodomo$"

TranquilRoute_EventScript_Kodomo_Text_3:
# 223 "data/maps/TranquilRoute/scripts.pory"
	.string "I should look for stronger Pokémon in\n"
	.string "the tall grass, but I'm a little scared\l"
	.string "of getting jumped by surprise!$"

TranquilRoute_EventScript_Takeshi_Text_0:
# 232 "data/maps/TranquilRoute/scripts.pory"
	.string "Stay right there! I'll defeat you with\n"
	.string "my ninja skills!$"

TranquilRoute_EventScript_Takeshi_Text_1:
# 233 "data/maps/TranquilRoute/scripts.pory"
	.string "I had the sun in my eyes!$"

TranquilRoute_EventScript_Takeshi_Text_2:
# 235 "data/maps/TranquilRoute/scripts.pory"
	.string "Takeshi$"

TranquilRoute_EventScript_Takeshi_Text_3:
# 236 "data/maps/TranquilRoute/scripts.pory"
	.string "I must hone my ninja skills!$"

TranquilRoute_EventScript_Hana_Text_0:
# 243 "data/maps/TranquilRoute/scripts.pory"
	.string "Ugh, how can Kenji paint a portrait of\n"
	.string "me if people keep walking between us?$"

TranquilRoute_EventScript_Hana_Text_1:
# 244 "data/maps/TranquilRoute/scripts.pory"
	.string "Great, now my hair is all messed up.$"

TranquilRoute_EventScript_Hana_Text_2:
# 246 "data/maps/TranquilRoute/scripts.pory"
	.string "Hiina$"

TranquilRoute_EventScript_Hana_Text_3:
# 247 "data/maps/TranquilRoute/scripts.pory"
	.string "Kenji really is an amazing artist. I\n"
	.string "feel very lucky.$"

TranquilRoute_EventScript_Kenji_Text_0:
# 254 "data/maps/TranquilRoute/scripts.pory"
	.string "You're interrupting my creative flow!!$"

TranquilRoute_EventScript_Kenji_Text_1:
# 255 "data/maps/TranquilRoute/scripts.pory"
	.string "Such beauty! What an artistic fight\n"
	.string "this was!$"

TranquilRoute_EventScript_Kenji_Text_2:
# 257 "data/maps/TranquilRoute/scripts.pory"
	.string "Kenji$"

TranquilRoute_EventScript_Kenji_Text_3:
# 259 "data/maps/TranquilRoute/scripts.pory"
	.string "Hiina is the best subject I could\n"
	.string "dream of.\p"
	.string "…Hey, uh, please don't tell her I said\n"
	.string "that.$"

TranquilRoute_EventScript_Girl_Text_0:
# 270 "data/maps/TranquilRoute/scripts.pory"
	.string "Girl$"

TranquilRoute_EventScript_Girl_Text_1:
# 271 "data/maps/TranquilRoute/scripts.pory"
	.string "What? Oh, I don't fight.\p"
	.string "My Pokémon and I are just strolling.$"

TranquilRoute_EventScript_WhiteslateRoadblock_Text_0:
# 279 "data/maps/TranquilRoute/scripts.pory"
	.string "Samurai$"

TranquilRoute_EventScript_WhiteslateRoadblock_Text_1:
# 280 "data/maps/TranquilRoute/scripts.pory"
	.string "Sorry, you can't go through. The road\n"
	.string "ahead is blocked.$"

TranquilRoute_EventScript_Shellos_Text_0:
# 294 "data/maps/TranquilRoute/scripts.pory"
	.string "Shellos$"

TranquilRoute_EventScript_Shellos_Text_1:
# 296 "data/maps/TranquilRoute/scripts.pory"
	.string "Slug$"

TranquilRoute_EventScript_Shellos_Text_2:
# 299 "data/maps/TranquilRoute/scripts.pory"
	.string "Clelel!$"

TranquilRoute_EventScript_BerryWoman_Text_0:
# 312 "data/maps/TranquilRoute/scripts.pory"
	.string "Woman$"

TranquilRoute_EventScript_BerryWoman_Text_1:
# 313 "data/maps/TranquilRoute/scripts.pory"
	.string "Enjoy gardening!$"

TranquilRoute_EventScript_BerryWoman_Text_2:
# 318 "data/maps/TranquilRoute/scripts.pory"
	.string "Hi, young one! See this?$"

TranquilRoute_EventScript_BerryWoman_Text_3:
# 327 "data/maps/TranquilRoute/scripts.pory"
	.string "You can plant berries in the ground in\n"
	.string "fertile spots like this.\p"
	.string "The seeds will eventually grow into a\n"
	.string "healthy berry tree, ready to be\l"
	.string "harvested!\p"
	.string "I see you're a wielder. Well, different\n"
	.string "berries have different effects when\l"
	.string "they're fed to Pokémon.\p"
	.string "I love berries, hopefully you'll soon\n"
	.string "learn to love them too!\p"
	.string "Here, try planting a few!$"

TranquilRoute_EventScript_BerryWoman_Text_4:
# 339 "data/maps/TranquilRoute/scripts.pory"
	.string "Oh, right, I was almost forgetting!\p"
	.string "You must remember to water them\n"
	.string "regularly, or they won't grow!\p"
	.string "I like you. Take this!$"

TranquilRoute_EventScript_BerryWoman_Text_5:
# 349 "data/maps/TranquilRoute/scripts.pory"
	.string "Isn't it cute? It's friend-shaped!\p"
	.string "Don't worry about it, I have a spare\n"
	.string "one.\p"
	.string "Have fun gardening!$"

TranquilRoute_EventScript_Mareep_Text_0:
# 366 "data/maps/TranquilRoute/scripts.pory"
	.string "Mareep$"

TranquilRoute_EventScript_Mareep_Text_1:
# 368 "data/maps/TranquilRoute/scripts.pory"
	.string "Static sheep$"

TranquilRoute_EventScript_Mareep_Text_2:
# 370 "data/maps/TranquilRoute/scripts.pory"
	.string "Beeeeeh…$"

TranquilRoute_EventScript_Mareep2_Text_0:
# 384 "data/maps/TranquilRoute/scripts.pory"
	.string "Baaaaah…$"

TranquilRoute_TrainerTips1_Text_0:
# 391 "data/maps/TranquilRoute/scripts.pory"
	.string "Did you know?\p"
	.string "Some Pokémon only come out in the\n"
	.string "morning, in the evening, or at night.\p"
	.string "Visit the same spot at different\n"
	.string "times of day to have a chance of\l"
	.string "seeing rare Pokémon!$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_0:
# 418 "data/maps/TranquilRoute/scripts.pory"
	.string "Shady men$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_1:
# 420 "data/maps/TranquilRoute/scripts.pory"
	.string "…Excellent idea…\p"
	.string "…Yeah, and then…\p"
	.string "… … …$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_2:
# 431 "data/maps/TranquilRoute/scripts.pory"
	.string "Shady man$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_3:
# 433 "data/maps/TranquilRoute/scripts.pory"
	.string "Alright boys, let's move.$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0:
# 475 "data/maps/TranquilRoute/scripts.pory"
	.string "Man$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_1:
# 477 "data/maps/TranquilRoute/scripts.pory"
	.string "Mumble mumble… Should restock on\n"
	.string "ointment… Damn, where did I put my\l"
	.string "purse?…$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_2:
# 492 "data/maps/TranquilRoute/scripts.pory"
	.string "Oh, hello! Sorry, shop's closed at the\n"
	.string "moment!\p"
	.string "… …Oh, sorry, we haven't met, have we?\n"
	.string "I'm not good with faces…\p"
	.string "I'm Okada, the traveling merchant! I\n"
	.string "travel through all of Toku on foot,\l"
	.string "selling useful goods and rare finds!\p"
	.string "I'm sold out on, well, pretty much\n"
	.string "everything right now… But you're\l"
	.string "definitely going to see me around!\p"
	.string "What's your name? {PLAYER}? It's\n"
	.string "nice to meet you, {PLAYER}! I see\l"
	.string "you're a young wielder, eh? Maybe we\l"
	.string "can even have a friendly battle next\l"
	.string "time!\p"
	.string "Now if you'll excuse me, I'm running\n"
	.string "late! See you around, {PLAYER}!$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_3:
# 506 "data/maps/TranquilRoute/scripts.pory"
	.string "Come on, Keke.$"

TranquilRoute_EventScript_Kecleon_Text_0:
# 533 "data/maps/TranquilRoute/scripts.pory"
	.string "Kecleon$"

TranquilRoute_EventScript_Kecleon_Text_1:
# 535 "data/maps/TranquilRoute/scripts.pory"
	.string "Keckecke!$"

TranquilRoute_TrainerTips2_Text_0:
# 545 "data/maps/TranquilRoute/scripts.pory"
	.string "Did you know?\p"
	.string "You can swap the Pokémon in your\n"
	.string "party using {R_BUTTON}.\p"
	.string "Set the lead Pokémon with {SELECT_BUTTON}.$"

TranquilRoute_DirectionSign_Text_0:
# 559 "data/maps/TranquilRoute/scripts.pory"
	.string "{LEFT_ARROW} Whiteslate route\n"
	.string "{UP_ARROW} Sakura Village\p"
	.string "It looks like the sign has been\n"
	.string "written over recently…$"

TranquilRoute_DirectionSign_Text_1:
# 565 "data/maps/TranquilRoute/scripts.pory"
	.string "{LEFT_ARROW} Whiteslate route\n"
	.string "{UP_ARROW} Saku and Kura Villages$"
