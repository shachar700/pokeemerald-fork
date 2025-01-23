SakuTown_MapScripts::
# 8 "data/maps/SakuTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 17 "data/maps/SakuTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 9 "data/maps/SakuTown/scripts.pory"
	call SakuVillage_NPCSchedules
# 10 "data/maps/SakuTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 13 "data/maps/SakuTown/scripts.pory"
	setmetatile 19, 2, METATILE_SakuKura_BoardGame, TRUE
# 14 "data/maps/SakuTown/scripts.pory"
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 18 "data/maps/SakuTown/scripts.pory"
	call SakuVillage_DrawMetatiles
	return


SakuTown_EventScript_RivalAtSakuWall::
# 24 "data/maps/SakuTown/scripts.pory"
	lock
# 25 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_0
# 26 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_1
# 27 "data/maps/SakuTown/scripts.pory"
	closemessage
# 29 "data/maps/SakuTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 30 "data/maps/SakuTown/scripts.pory"
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
# 32 "data/maps/SakuTown/scripts.pory"
	clearflag FLAG_HIDE_RIVAL_SAKU
# 33 "data/maps/SakuTown/scripts.pory"
	addobject 10
# 34 "data/maps/SakuTown/scripts.pory"
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_2
# 37 "data/maps/SakuTown/scripts.pory"
	setobjectxy 10, 17, 10
SakuTown_EventScript_RivalAtSakuWall_1:
# 39 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_0
# 40 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 42 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_2
# 43 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_3
# 50 "data/maps/SakuTown/scripts.pory"
	switch VAR_STARTER_MON
# 51 "data/maps/SakuTown/scripts.pory"
	case SPECIES_SNIVY, SakuTown_EventScript_RivalAtSakuWall_7
# 53 "data/maps/SakuTown/scripts.pory"
	case SPECIES_FROAKIE, SakuTown_EventScript_RivalAtSakuWall_8
# 55 "data/maps/SakuTown/scripts.pory"
	case SPECIES_CYNDAQUIL, SakuTown_EventScript_RivalAtSakuWall_9
SakuTown_EventScript_RivalAtSakuWall_5:
# 59 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_2
# 60 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_4
# 72 "data/maps/SakuTown/scripts.pory"
	closemessage
# 75 "data/maps/SakuTown/scripts.pory"
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_11
# 79 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_2
SakuTown_EventScript_RivalAtSakuWall_10:
# 81 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 83 "data/maps/SakuTown/scripts.pory"
	removeobject 10
# 84 "data/maps/SakuTown/scripts.pory"
	setflag FLAG_HIDE_RIVAL_SAKU
# 86 "data/maps/SakuTown/scripts.pory"
	setvar VAR_RIVAL_ENCOUNTER_STATE, 1
# 88 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_RivalAtSakuWall_2:
# 35 "data/maps/SakuTown/scripts.pory"
	setobjectxy 10, 16, 10
	goto SakuTown_EventScript_RivalAtSakuWall_1

SakuTown_EventScript_RivalAtSakuWall_7:
# 52 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_SNIVY, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_8:
# 54 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_FROAKIE, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_9:
# 56 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_CYNDAQUIL, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_11:
# 76 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_1
	goto SakuTown_EventScript_RivalAtSakuWall_10


SakuTown_EventScript_Farmer::
# 96 "data/maps/SakuTown/scripts.pory"
	lock
# 97 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 98 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Farmer_Text_0
# 99 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer_Text_1
# 102 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Farmer2::
# 106 "data/maps/SakuTown/scripts.pory"
	lock
# 107 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Farmer_Text_0
# 108 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer2_Text_0
# 112 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Woman::
# 116 "data/maps/SakuTown/scripts.pory"
	lock
# 117 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 118 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Woman_Text_0
# 119 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Woman_Text_1
# 123 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Karateka::
# 127 "data/maps/SakuTown/scripts.pory"
	lock
# 128 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 129 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Karateka_Text_0
# 130 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_1
# 133 "data/maps/SakuTown/scripts.pory"
	closemessage
# 134 "data/maps/SakuTown/scripts.pory"
	applymovement 6, Common_Movement_WalkInPlaceFasterUp
# 135 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 136 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Karateka_Text_0
# 137 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_2
# 140 "data/maps/SakuTown/scripts.pory"
	closemessage
# 143 "data/maps/SakuTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 144 "data/maps/SakuTown/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 145 "data/maps/SakuTown/scripts.pory"
	waitmovement 1
# 146 "data/maps/SakuTown/scripts.pory"
	waitmovement 2
# 148 "data/maps/SakuTown/scripts.pory"
	delay 24
# 150 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 151 "data/maps/SakuTown/scripts.pory"
	applymovement 1, SakuTown_EventScript_Karateka_Movement_0
# 152 "data/maps/SakuTown/scripts.pory"
	waitmovement 1
# 153 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 154 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 155 "data/maps/SakuTown/scripts.pory"
	applymovement 2, SakuTown_EventScript_Karateka_Movement_0
# 156 "data/maps/SakuTown/scripts.pory"
	waitmovement 2
# 157 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 159 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Guard::
# 163 "data/maps/SakuTown/scripts.pory"
	lock
# 164 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_Guard_2
# 171 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 172 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 173 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Guard_Text_2
# 177 "data/maps/SakuTown/scripts.pory"
	closemessage
# 178 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_FaceOriginalDirection
# 179 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
SakuTown_EventScript_Guard_1:
# 181 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_Guard_2:
# 165 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 166 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Guard_Text_1
# 169 "data/maps/SakuTown/scripts.pory"
	closemessage
	goto SakuTown_EventScript_Guard_1


SakuTown_EventScript_KuraGuard::
# 185 "data/maps/SakuTown/scripts.pory"
	lock
# 186 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 187 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_KuraGuard_Text_0
# 190 "data/maps/SakuTown/scripts.pory"
	closemessage
# 191 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_GuardSeesYou::
# 195 "data/maps/SakuTown/scripts.pory"
	lock
# 197 "data/maps/SakuTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 200 "data/maps/SakuTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 0
	goto_if_eq SakuTown_EventScript_GuardSeesYou_2
# 203 "data/maps/SakuTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto_if_eq SakuTown_EventScript_GuardSeesYou_4
SakuTown_EventScript_GuardSeesYou_1:
# 207 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_GuardSeesYou_2:
# 201 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_3:
# 204 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_4:
# 203 "data/maps/SakuTown/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardSeesYou_3
	goto SakuTown_EventScript_GuardSeesYou_1


SakuTown_EventScript_GuardStopsYou::
# 211 "data/maps/SakuTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 212 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceFasterLeft
# 213 "data/maps/SakuTown/scripts.pory"
	waitmovement 8
# 214 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 215 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_0
# 216 "data/maps/SakuTown/scripts.pory"
	closemessage
# 217 "data/maps/SakuTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 218 "data/maps/SakuTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 219 "data/maps/SakuTown/scripts.pory"
	delay 20
# 221 "data/maps/SakuTown/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardStopsYou_2
# 231 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 232 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_2
# 237 "data/maps/SakuTown/scripts.pory"
	closemessage
# 238 "data/maps/SakuTown/scripts.pory"
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 1
SakuTown_EventScript_GuardStopsYou_1:
# 241 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_FaceDown
	return

SakuTown_EventScript_GuardStopsYou_2:
# 222 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 223 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_1
# 228 "data/maps/SakuTown/scripts.pory"
	closemessage
# 229 "data/maps/SakuTown/scripts.pory"
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 3
	goto SakuTown_EventScript_GuardStopsYou_1


SakuTown_EventScript_TownSign::
# 246 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips::
# 250 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips2::
# 254 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_FloristSign::
# 258 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_FloristSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_BoardGame::
# 262 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_BoardGame_1
	return

SakuTown_EventScript_BoardGame_1:
# 263 "data/maps/SakuTown/scripts.pory"
	lock
# 264 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_BoardGame_Text_0, MSGBOX_DEFAULT
# 265 "data/maps/SakuTown/scripts.pory"
	closemessage
# 266 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Mart::
# 271 "data/maps/SakuTown/scripts.pory"
	lock
# 272 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 273 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Mart_Text_0
# 274 "data/maps/SakuTown/scripts.pory"
	message gText_HowMayIServeYou
# 275 "data/maps/SakuTown/scripts.pory"
	waitmessage
# 276 "data/maps/SakuTown/scripts.pory"
	pokemart SakuTown_Mart
# 277 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Mart_Text_0
# 278 "data/maps/SakuTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 279 "data/maps/SakuTown/scripts.pory"
	release
	return


	.align 2
# 282 "data/maps/SakuTown/scripts.pory"
SakuTown_Mart:
# 283 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 284 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 285 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 286 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 287 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 288 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 289 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

SakuTown_EventScript_Makuhita::
# 293 "data/maps/SakuTown/scripts.pory"
	lock
# 294 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 295 "data/maps/SakuTown/scripts.pory"
	waitse
# 296 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 297 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Makuhita_Text_0
# 298 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Makuhita_Text_1
# 299 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 300 "data/maps/SakuTown/scripts.pory"
	release
	return


# 39 "data/maps/SakuTown/scripts.pory"
SakuTown_EventScript_RivalAtSakuWall_Movement_0:
# 39 "data/maps/SakuTown/scripts.pory"
	walk_up
# 39 "data/maps/SakuTown/scripts.pory"
	walk_up
# 39 "data/maps/SakuTown/scripts.pory"
	walk_up
# 39 "data/maps/SakuTown/scripts.pory"
	walk_up
# 39 "data/maps/SakuTown/scripts.pory"
	walk_up
	step_end

# 76 "data/maps/SakuTown/scripts.pory"
SakuTown_EventScript_RivalAtSakuWall_Movement_1:
# 76 "data/maps/SakuTown/scripts.pory"
	walk_faster_right
# 76 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 76 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 76 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 76 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 76 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
	step_end

# 79 "data/maps/SakuTown/scripts.pory"
SakuTown_EventScript_RivalAtSakuWall_Movement_2:
# 79 "data/maps/SakuTown/scripts.pory"
	walk_faster_left
# 79 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 79 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 79 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 79 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 79 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
	step_end

# 151 "data/maps/SakuTown/scripts.pory"
SakuTown_EventScript_Karateka_Movement_0:
# 151 "data/maps/SakuTown/scripts.pory"
	jump_in_place_down
	step_end

SakuTown_EventScript_RivalAtSakuWall_Text_0:
# 25 "data/maps/SakuTown/scripts.pory"
	.string "???$"

SakuTown_EventScript_RivalAtSakuWall_Text_1:
# 26 "data/maps/SakuTown/scripts.pory"
	.string "Wait up, {PLAYER}!$"

SakuTown_EventScript_RivalAtSakuWall_Text_2:
# 42 "data/maps/SakuTown/scripts.pory"
	.string "Natsuki$"

SakuTown_EventScript_RivalAtSakuWall_Text_3:
# 44 "data/maps/SakuTown/scripts.pory"
	.string "I was wondering if you'd already\n"
	.string "reached Saku Village by now. Looks\l"
	.string "like we almost missed each other!\p"
	.string "Have you caught any Pokémon on your\n"
	.string "way here?\p"
	.string "Me? Oh, I can show you my Pokémon\n"
	.string "alright!$"

SakuTown_EventScript_RivalAtSakuWall_Text_4:
# 61 "data/maps/SakuTown/scripts.pory"
	.string "Okay, I… I didn't think you'd go that\n"
	.string "hard, honestly!\p"
	.string "Hahaha…\p"
	.string "Clearly I underestimated you. That's\n"
	.string "alright. I won't make that mistake\l"
	.string "next time!\p"
	.string "I can see your Pokémon are really\n"
	.string "growing to like you, it's great!\p"
	.string "You definitely stand a chance\n"
	.string "against the Dojo that's in the next\l"
	.string "village.\p"
	.string "Me? Actually, I just fought the Dojo's\n"
	.string "master and got a token from her!\p"
	.string "You'll have to hurry up if you wanna\n"
	.string "catch up!\p"
	.string "Well, it was good to see you. Until\n"
	.string "next time then.\p"
	.string "I bet you I'll get to Silveridge first!\p"
	.string "See you later, Feraligatr!$"

SakuTown_EventScript_Farmer_Text_0:
# 98 "data/maps/SakuTown/scripts.pory"
	.string "Farmer$"

SakuTown_EventScript_Farmer_Text_1:
# 100 "data/maps/SakuTown/scripts.pory"
	.string "We're cultivatin' Mifan berries. Saku\n"
	.string "Village exports its berries to many\l"
	.string "towns.$"

SakuTown_EventScript_Farmer2_Text_0:
# 109 "data/maps/SakuTown/scripts.pory"
	.string "Whew…\p"
	.string "Working in the fields sure is tiring…$"

SakuTown_EventScript_Woman_Text_0:
# 118 "data/maps/SakuTown/scripts.pory"
	.string "Woman$"

SakuTown_EventScript_Woman_Text_1:
# 120 "data/maps/SakuTown/scripts.pory"
	.string "Those thugs in Kura Village may have\n"
	.string "their own Dojo, but their town is\l"
	.string "nothing but an ugly pile of rocks!\p"
	.string "They don't even have a Pokémon\n"
	.string "refuge!$"

SakuTown_EventScript_Karateka_Text_0:
# 129 "data/maps/SakuTown/scripts.pory"
	.string "Man$"

SakuTown_EventScript_Karateka_Text_1:
# 131 "data/maps/SakuTown/scripts.pory"
	.string "I let the Pokémon Council borrow my\n"
	.string "super-strong Pokémon to help build\l"
	.string "the new Pokémon refuges throughout\l"
	.string "the region.$"

SakuTown_EventScript_Karateka_Text_2:
# 138 "data/maps/SakuTown/scripts.pory"
	.string "Come on, Mama, Kuku! Daddy loves you!!$"

SakuTown_EventScript_Guard_Text_0:
# 165 "data/maps/SakuTown/scripts.pory"
	.string "Guard$"

SakuTown_EventScript_Guard_Text_1:
# 167 "data/maps/SakuTown/scripts.pory"
	.string "Damn, where did that Mareep come\n"
	.string "from?!$"

SakuTown_EventScript_Guard_Text_2:
# 174 "data/maps/SakuTown/scripts.pory"
	.string "One can never be too careful.\p"
	.string "The safety of the whole village rests\n"
	.string "on my shoulders.$"

SakuTown_EventScript_KuraGuard_Text_0:
# 188 "data/maps/SakuTown/scripts.pory"
	.string "Hah, got two of your Tauros in my\n"
	.string "herd!$"

SakuTown_EventScript_GuardStopsYou_Text_0:
# 215 "data/maps/SakuTown/scripts.pory"
	.string "Hey!$"

SakuTown_EventScript_GuardStopsYou_Text_1:
# 224 "data/maps/SakuTown/scripts.pory"
	.string "Are you trying to sneak in from Kura\n"
	.string "Village?\p"
	.string "…Oh, you're that traveler from before.\n"
	.string "You can go through.\p"
	.string "How was it? Awful, right? Welcome back\n"
	.string "to Saku Village!$"

SakuTown_EventScript_GuardStopsYou_Text_2:
# 233 "data/maps/SakuTown/scripts.pory"
	.string "Are you trying to sneak into Kura\n"
	.string "Village?\p"
	.string "…Oh, you're just a traveler. Nevermind\n"
	.string "then, you can go through.\p"
	.string "Though I wouldn't recommend visiting\n"
	.string "the next village, there's really\l"
	.string "nothing interesting there.$"

SakuTown_EventScript_TownSign_Text_0:
# 246 "data/maps/SakuTown/scripts.pory"
	.string "Saku Village\n"
	.string "“A village of tender flower petals.”$"

SakuTown_EventScript_TrainerTips_Text_0:
# 250 "data/maps/SakuTown/scripts.pory"
	.string "Did you know?\p"
	.string "Saku Village is in all ways superior to\n"
	.string "Kura Village!$"

SakuTown_EventScript_TrainerTips2_Text_0:
# 254 "data/maps/SakuTown/scripts.pory"
	.string "Did you know?\p"
	.string "The folks from Kura Village are a\n"
	.string "bunch of mean jerks!$"

SakuTown_EventScript_FloristSign_Text_0:
# 258 "data/maps/SakuTown/scripts.pory"
	.string "Humble Blossom\n"
	.string "Bonsai & flower shop$"

SakuTown_EventScript_BoardGame_Text_0:
# 264 "data/maps/SakuTown/scripts.pory"
	.string "They're playing Tauros Herder, a\n"
	.string "popular board game!$"

SakuTown_EventScript_Mart_Text_0:
# 273 "data/maps/SakuTown/scripts.pory"
	.string "Saleswoman$"

SakuTown_EventScript_Makuhita_Text_0:
# 297 "data/maps/SakuTown/scripts.pory"
	.string "Makuhita$"

SakuTown_EventScript_Makuhita_Text_1:
# 298 "data/maps/SakuTown/scripts.pory"
	.string "Kuhi!$"

SakuTown_Text_RivalDefeat::
# 91 "data/maps/SakuTown/scripts.pory"
	.string "Oh, wow, okay.$"
