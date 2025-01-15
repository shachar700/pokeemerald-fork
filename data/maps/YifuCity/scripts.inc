YifuCity_MapScripts::
# 7 "data/maps/YifuCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, YifuCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

YifuCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/YifuCity/scripts.pory"
	map_script_2 VAR_CROBAT_HIDEOUT_STATE, 3, YifuCity_EscapedCrobatHideoutWithSamurai
	.2byte 0


YifuCity_EscapedCrobatHideoutWithSamurai::
	return


YifuCity_EventScript_StoleMyMon::
# 17 "data/maps/YifuCity/scripts.pory"
	lock
# 18 "data/maps/YifuCity/scripts.pory"
	faceplayer
# 19 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_StoleMyMon_Text_0
# 20 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_StoleMyMon_Text_1
# 24 "data/maps/YifuCity/scripts.pory"
	closemessage
# 25 "data/maps/YifuCity/scripts.pory"
	release
	return


YifuCity_EventScript_IDontFeelSafe::
# 29 "data/maps/YifuCity/scripts.pory"
	lock
# 30 "data/maps/YifuCity/scripts.pory"
	faceplayer
# 31 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_IDontFeelSafe_Text_0
# 32 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_IDontFeelSafe_Text_1
# 36 "data/maps/YifuCity/scripts.pory"
	closemessage
# 37 "data/maps/YifuCity/scripts.pory"
	release
	return


YifuCity_EventScript_Samurai::
# 41 "data/maps/YifuCity/scripts.pory"
	lock
# 42 "data/maps/YifuCity/scripts.pory"
	faceplayer
# 43 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_Samurai_Text_0
# 44 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_Samurai_Text_1
# 47 "data/maps/YifuCity/scripts.pory"
	closemessage
# 48 "data/maps/YifuCity/scripts.pory"
	release
	return


YifuCity_EventScript_Samurai2::
# 52 "data/maps/YifuCity/scripts.pory"
	lock
# 53 "data/maps/YifuCity/scripts.pory"
	faceplayer
# 54 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_Samurai_Text_0
# 55 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_Samurai2_Text_0
# 58 "data/maps/YifuCity/scripts.pory"
	closemessage
# 59 "data/maps/YifuCity/scripts.pory"
	release
	return


YifuCity_EventScript_ShinySeller::
# 63 "data/maps/YifuCity/scripts.pory"
	lock
# 64 "data/maps/YifuCity/scripts.pory"
	faceplayer
# 65 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 66 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_ShinySeller_Text_1
# 70 "data/maps/YifuCity/scripts.pory"
	showmonpic SPECIES_CATERPIE, 10, 3, TRUE
# 71 "data/maps/YifuCity/scripts.pory"
	playmoncry SPECIES_CATERPIE, CRY_MODE_NORMAL
# 72 "data/maps/YifuCity/scripts.pory"
	waitmoncry
# 74 "data/maps/YifuCity/scripts.pory"
	waitbuttonpress
# 75 "data/maps/YifuCity/scripts.pory"
	hidemonpic
# 77 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 78 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_ShinySeller_Text_2
# 83 "data/maps/YifuCity/scripts.pory"
	goto YifuCity_ShinySellerChoice
# 85 "data/maps/YifuCity/scripts.pory"
	release
	return


YifuCity_ShinySellerChoice::
# 89 "data/maps/YifuCity/scripts.pory"
	showmoneybox 18, 0
# 91 "data/maps/YifuCity/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_ShinySellerChoice_Text_0, YifuCity_ShinySellerChoice_Text_1, YifuCity_ShinySellerChoice_Text_2
# 103 "data/maps/YifuCity/scripts.pory"
	closemessage
# 105 "data/maps/YifuCity/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/YifuCity/scripts.pory"
	case 0, YifuCity_ShinySellerChoice_3
# 208 "data/maps/YifuCity/scripts.pory"
	case 1, YifuCity_ShinySellerChoice_4
# 215 "data/maps/YifuCity/scripts.pory"
	case 2, YifuCity_ShinySellerChoice_5
YifuCity_ShinySellerChoice_1:
# 225 "data/maps/YifuCity/scripts.pory"
	hidemoneybox
# 226 "data/maps/YifuCity/scripts.pory"
	release
	return

YifuCity_ShinySellerChoice_3:
	checkmoney 10000
# 0 "data/maps/YifuCity/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_ShinySellerChoice_6
# 202 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 203 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_ShinySellerChoice_Text_8
# 206 "data/maps/YifuCity/scripts.pory"
	closemessage
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_4:
# 209 "data/maps/YifuCity/scripts.pory"
	hidemoneybox
# 210 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 211 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_ShinySellerChoice_Text_9
# 214 "data/maps/YifuCity/scripts.pory"
	closemessage
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_5:
# 216 "data/maps/YifuCity/scripts.pory"
	hidemoneybox
# 217 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 218 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_ShinySellerChoice_Text_10
# 222 "data/maps/YifuCity/scripts.pory"
	goto YifuCity_ShinySellerChoice
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_6:
# 108 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 109 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_ShinySellerChoice_Text_3
# 113 "data/maps/YifuCity/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CATERPIE
# 114 "data/maps/YifuCity/scripts.pory"
	givemon SPECIES_CATERPIE, 5, isShiny = FALSE
# 116 "data/maps/YifuCity/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq YifuCity_ShinySellerChoice_10
YifuCity_ShinySellerChoice_9:
# 120 "data/maps/YifuCity/scripts.pory"
	removemoney 10000
# 121 "data/maps/YifuCity/scripts.pory"
	updatemoneybox
# 123 "data/maps/YifuCity/scripts.pory"
	closemessage
# 125 "data/maps/YifuCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 126 "data/maps/YifuCity/scripts.pory"
	message YifuCity_ShinySellerChoice_Text_4
# 127 "data/maps/YifuCity/scripts.pory"
	waitmessage
# 128 "data/maps/YifuCity/scripts.pory"
	waitfanfare
# 130 "data/maps/YifuCity/scripts.pory"
	hidemoneybox
# 132 "data/maps/YifuCity/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CATERPIE
# 133 "data/maps/YifuCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq YifuCity_ShinySellerChoice_13
# 139 "data/maps/YifuCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq YifuCity_ShinySellerChoice_14
YifuCity_ShinySellerChoice_12:
# 147 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 148 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_ShinySellerChoice_Text_5
# 151 "data/maps/YifuCity/scripts.pory"
	closemessage
# 153 "data/maps/YifuCity/scripts.pory"
	compare VAR_FACING, DIR_EAST
	goto_if_eq YifuCity_ShinySellerChoice_18
# 156 "data/maps/YifuCity/scripts.pory"
	applymovement VAR_LAST_TALKED, YifuCity_ShinySellerChoice_Movement_1
YifuCity_ShinySellerChoice_17:
# 158 "data/maps/YifuCity/scripts.pory"
	delay 24
# 159 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 160 "data/maps/YifuCity/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 161 "data/maps/YifuCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 163 "data/maps/YifuCity/scripts.pory"
	delay 48
# 164 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 165 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 167 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_ShinySellerChoice_Text_6
# 170 "data/maps/YifuCity/scripts.pory"
	closemessage
# 172 "data/maps/YifuCity/scripts.pory"
	playse SE_PIN
# 173 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 174 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 175 "data/maps/YifuCity/scripts.pory"
	waitse
# 176 "data/maps/YifuCity/scripts.pory"
	delay 48
# 178 "data/maps/YifuCity/scripts.pory"
	showmonpic SPECIES_CATERPIE, 10, 3, TRUE
# 179 "data/maps/YifuCity/scripts.pory"
	playmoncry SPECIES_CATERPIE, CRY_MODE_NORMAL
# 180 "data/maps/YifuCity/scripts.pory"
	waitmoncry
# 182 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_ShinySellerChoice_Text_7
# 186 "data/maps/YifuCity/scripts.pory"
	playse SE_M_MIST
# 187 "data/maps/YifuCity/scripts.pory"
	hidemonpic
# 188 "data/maps/YifuCity/scripts.pory"
	showmonpic SPECIES_CATERPIE, 10, 3
# 189 "data/maps/YifuCity/scripts.pory"
	waitse
# 191 "data/maps/YifuCity/scripts.pory"
	waitbuttonpress
# 192 "data/maps/YifuCity/scripts.pory"
	closemessage
# 193 "data/maps/YifuCity/scripts.pory"
	hidemonpic
# 195 "data/maps/YifuCity/scripts.pory"
	goto_if_set FLAG_TEMP_1, YifuCity_ShinySellerChoice_27
YifuCity_ShinySellerChoice_26:
# 199 "data/maps/YifuCity/scripts.pory"
	setflag FLAG_BOUGHT_FAKE_SHINY
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_10:
# 117 "data/maps/YifuCity/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto YifuCity_ShinySellerChoice_9

YifuCity_ShinySellerChoice_13:
# 134 "data/maps/YifuCity/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 135 "data/maps/YifuCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_ne YifuCity_ShinySellerChoice_21
	goto YifuCity_ShinySellerChoice_12

YifuCity_ShinySellerChoice_14:
# 140 "data/maps/YifuCity/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 141 "data/maps/YifuCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_ne YifuCity_ShinySellerChoice_24
YifuCity_ShinySellerChoice_23:
# 144 "data/maps/YifuCity/scripts.pory"
	setflag FLAG_TEMP_1
	goto YifuCity_ShinySellerChoice_12

YifuCity_ShinySellerChoice_18:
# 154 "data/maps/YifuCity/scripts.pory"
	applymovement VAR_LAST_TALKED, YifuCity_ShinySellerChoice_Movement_0
	goto YifuCity_ShinySellerChoice_17

YifuCity_ShinySellerChoice_21:
# 136 "data/maps/YifuCity/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 137 "data/maps/YifuCity/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto YifuCity_ShinySellerChoice_12

YifuCity_ShinySellerChoice_24:
# 142 "data/maps/YifuCity/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto YifuCity_ShinySellerChoice_23

YifuCity_ShinySellerChoice_27:
# 196 "data/maps/YifuCity/scripts.pory"
	call Common_EventScript_TransferredToPC
	goto YifuCity_ShinySellerChoice_26


YifuCity_Trigger_CrobatGruntsScram::
# 230 "data/maps/YifuCity/scripts.pory"
	lockall
# 232 "data/maps/YifuCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 233 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 235 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 236 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_0
# 239 "data/maps/YifuCity/scripts.pory"
	closemessage
# 241 "data/maps/YifuCity/scripts.pory"
	playse SE_PIN
# 242 "data/maps/YifuCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 243 "data/maps/YifuCity/scripts.pory"
	delay 16
# 244 "data/maps/YifuCity/scripts.pory"
	playse SE_PIN
# 245 "data/maps/YifuCity/scripts.pory"
	applymovement 10, Common_Movement_ExclamationMark
# 246 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 247 "data/maps/YifuCity/scripts.pory"
	waitse
# 248 "data/maps/YifuCity/scripts.pory"
	delay 48
# 249 "data/maps/YifuCity/scripts.pory"
	turnobject 9, DIR_WEST
# 250 "data/maps/YifuCity/scripts.pory"
	turnobject 10, DIR_WEST
# 251 "data/maps/YifuCity/scripts.pory"
	delay 48
# 253 "data/maps/YifuCity/scripts.pory"
	playse SE_LEDGE
# 254 "data/maps/YifuCity/scripts.pory"
	applymovement 9, YifuCity_Trigger_CrobatGruntsScram_Movement_0
# 255 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 256 "data/maps/YifuCity/scripts.pory"
	waitse
# 258 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 259 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_1
# 263 "data/maps/YifuCity/scripts.pory"
	closemessage
# 265 "data/maps/YifuCity/scripts.pory"
	playse SE_BALL_OPEN
# 266 "data/maps/YifuCity/scripts.pory"
	addobject 11
# 267 "data/maps/YifuCity/scripts.pory"
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
# 268 "data/maps/YifuCity/scripts.pory"
	applymovement 11, YifuCity_Trigger_CrobatGruntsScram_Movement_1
# 281 "data/maps/YifuCity/scripts.pory"
	waitmoncry
# 282 "data/maps/YifuCity/scripts.pory"
	waitse
# 283 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 285 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_CrobatGruntsScram_Movement_2
# 286 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 288 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 289 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_2
# 292 "data/maps/YifuCity/scripts.pory"
	closemessage
# 294 "data/maps/YifuCity/scripts.pory"
	delay 24
# 295 "data/maps/YifuCity/scripts.pory"
	addobject 11
# 296 "data/maps/YifuCity/scripts.pory"
	applymovement 11, YifuCity_Trigger_CrobatGruntsScram_Movement_3
# 297 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 299 "data/maps/YifuCity/scripts.pory"
	turnobject 9, DIR_SOUTH
# 300 "data/maps/YifuCity/scripts.pory"
	turnobject 10, DIR_NORTH
# 302 "data/maps/YifuCity/scripts.pory"
	releaseall
	return


YifuCity_Trigger_CrobatGruntsEavesdropPassword::
# 306 "data/maps/YifuCity/scripts.pory"
	lockall
# 308 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
# 309 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_0
# 312 "data/maps/YifuCity/scripts.pory"
	closemessage
# 314 "data/maps/YifuCity/scripts.pory"
	delay 24
# 316 "data/maps/YifuCity/scripts.pory"
	special SpawnCameraObject
# 317 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_0
# 318 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 319 "data/maps/YifuCity/scripts.pory"
	delay 48
# 321 "data/maps/YifuCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 322 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 324 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 325 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_1
# 329 "data/maps/YifuCity/scripts.pory"
	closemessage
# 331 "data/maps/YifuCity/scripts.pory"
	applymovement 10, Common_Movement_WalkInPlaceFasterUp
# 332 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 334 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 335 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_2
# 338 "data/maps/YifuCity/scripts.pory"
	closemessage
# 340 "data/maps/YifuCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 341 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 343 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 344 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_3
# 347 "data/maps/YifuCity/scripts.pory"
	closemessage
# 349 "data/maps/YifuCity/scripts.pory"
	applymovement 10, Common_Movement_WalkInPlaceFasterUp
# 350 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 352 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 353 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_4
# 358 "data/maps/YifuCity/scripts.pory"
	playse SE_LEDGE
# 359 "data/maps/YifuCity/scripts.pory"
	applymovement 10, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_1
# 360 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 361 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_5
# 364 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 365 "data/maps/YifuCity/scripts.pory"
	waitse
# 366 "data/maps/YifuCity/scripts.pory"
	closemessage
# 368 "data/maps/YifuCity/scripts.pory"
	playse SE_LEDGE
# 369 "data/maps/YifuCity/scripts.pory"
	applymovement 9, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_2
# 370 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_ShinySeller_Text_0
# 371 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_6
# 376 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 377 "data/maps/YifuCity/scripts.pory"
	waitse
# 378 "data/maps/YifuCity/scripts.pory"
	closemessage
# 380 "data/maps/YifuCity/scripts.pory"
	applymovement 9, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_3
# 381 "data/maps/YifuCity/scripts.pory"
	applymovement 10, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_4
# 382 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 384 "data/maps/YifuCity/scripts.pory"
	removeobject 9
# 385 "data/maps/YifuCity/scripts.pory"
	removeobject 10
# 386 "data/maps/YifuCity/scripts.pory"
	setflag FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF
# 388 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_5
# 389 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 390 "data/maps/YifuCity/scripts.pory"
	special RemoveCameraObject
# 392 "data/maps/YifuCity/scripts.pory"
	releaseall
	return


YifuCity_EventScript_HearEcho::
# 396 "data/maps/YifuCity/scripts.pory"
	lock
# 397 "data/maps/YifuCity/scripts.pory"
	faceplayer
# 398 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_HearEcho_Text_0
# 399 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_HearEcho_Text_1
# 403 "data/maps/YifuCity/scripts.pory"
	closemessage
# 404 "data/maps/YifuCity/scripts.pory"
	release
	return


YifuCity_Trigger_CrobatGruntStuckInHole::
# 408 "data/maps/YifuCity/scripts.pory"
	lockall
# 410 "data/maps/YifuCity/scripts.pory"
	goto_if_set FLAG_GOT_CROBAT_PASSWORD_SECOND_HALF, YifuCity_Trigger_CrobatGruntStuckInHole_2
# 445 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
# 446 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_4
# 449 "data/maps/YifuCity/scripts.pory"
	closemessage
# 451 "data/maps/YifuCity/scripts.pory"
	delay 24
# 453 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_CrobatGruntStuckInHole_Movement_0
# 454 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 456 "data/maps/YifuCity/scripts.pory"
	delay 24
# 458 "data/maps/YifuCity/scripts.pory"
	playse SE_PIN
# 459 "data/maps/YifuCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_CrobatGruntStuckInHole_Movement_1
# 460 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
# 461 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_5
# 468 "data/maps/YifuCity/scripts.pory"
	waitmovement 0
# 469 "data/maps/YifuCity/scripts.pory"
	waitse
# 470 "data/maps/YifuCity/scripts.pory"
	closemessage
# 472 "data/maps/YifuCity/scripts.pory"
	setflag FLAG_GOT_CROBAT_PASSWORD_SECOND_HALF
YifuCity_Trigger_CrobatGruntStuckInHole_1:
# 475 "data/maps/YifuCity/scripts.pory"
	releaseall
	return

YifuCity_Trigger_CrobatGruntStuckInHole_2:
# 411 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
# 413 "data/maps/YifuCity/scripts.pory"
	random 5
# 414 "data/maps/YifuCity/scripts.pory"
	switch VAR_RESULT
# 415 "data/maps/YifuCity/scripts.pory"
	case 0, YifuCity_Trigger_CrobatGruntStuckInHole_7
# 419 "data/maps/YifuCity/scripts.pory"
	case 1, YifuCity_Trigger_CrobatGruntStuckInHole_8
# 423 "data/maps/YifuCity/scripts.pory"
	case 2, YifuCity_Trigger_CrobatGruntStuckInHole_9
# 429 "data/maps/YifuCity/scripts.pory"
	case 3, YifuCity_Trigger_CrobatGruntStuckInHole_10
# 435 "data/maps/YifuCity/scripts.pory"
	case 4, YifuCity_Trigger_CrobatGruntStuckInHole_11
YifuCity_Trigger_CrobatGruntStuckInHole_5:
# 442 "data/maps/YifuCity/scripts.pory"
	closemessage
	goto YifuCity_Trigger_CrobatGruntStuckInHole_1

YifuCity_Trigger_CrobatGruntStuckInHole_7:
# 416 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_0
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5

YifuCity_Trigger_CrobatGruntStuckInHole_8:
# 420 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_1
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5

YifuCity_Trigger_CrobatGruntStuckInHole_9:
# 424 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_2
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5

YifuCity_Trigger_CrobatGruntStuckInHole_10:
# 430 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_2
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5

YifuCity_Trigger_CrobatGruntStuckInHole_11:
# 436 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_3
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5


YifuCity_EventScript_Surskit::
# 479 "data/maps/YifuCity/scripts.pory"
	lock
# 480 "data/maps/YifuCity/scripts.pory"
	faceplayer
# 481 "data/maps/YifuCity/scripts.pory"
	speakername YifuCity_EventScript_Surskit_Text_0
# 482 "data/maps/YifuCity/scripts.pory"
	msgbox YifuCity_EventScript_Surskit_Text_1
# 485 "data/maps/YifuCity/scripts.pory"
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
# 486 "data/maps/YifuCity/scripts.pory"
	waitmoncry
# 487 "data/maps/YifuCity/scripts.pory"
	release
	end


# 154 "data/maps/YifuCity/scripts.pory"
YifuCity_ShinySellerChoice_Movement_0:
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_down
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 154 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
	step_end

# 156 "data/maps/YifuCity/scripts.pory"
YifuCity_ShinySellerChoice_Movement_1:
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
# 156 "data/maps/YifuCity/scripts.pory"
	walk_faster_up
	step_end

# 254 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsScram_Movement_0:
# 254 "data/maps/YifuCity/scripts.pory"
	jump_in_place_left
	step_end

# 268 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsScram_Movement_1:
# 271 "data/maps/YifuCity/scripts.pory"
	exit_pokeball
# 272 "data/maps/YifuCity/scripts.pory"
	face_left
# 273 "data/maps/YifuCity/scripts.pory"
	lock_anim
# 274 "data/maps/YifuCity/scripts.pory"
	lock_facing_direction
# 275 "data/maps/YifuCity/scripts.pory"
	walk_faster_left
# 276 "data/maps/YifuCity/scripts.pory"
	walk_faster_right
# 277 "data/maps/YifuCity/scripts.pory"
	unlock_anim
# 278 "data/maps/YifuCity/scripts.pory"
	unlock_facing_direction
	step_end

# 285 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsScram_Movement_2:
# 285 "data/maps/YifuCity/scripts.pory"
	lock_facing_direction
# 285 "data/maps/YifuCity/scripts.pory"
	walk_left
# 285 "data/maps/YifuCity/scripts.pory"
	walk_left
# 285 "data/maps/YifuCity/scripts.pory"
	unlock_facing_direction
	step_end

# 296 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsScram_Movement_3:
# 296 "data/maps/YifuCity/scripts.pory"
	enter_pokeball
	step_end

# 317 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_0:
# 317 "data/maps/YifuCity/scripts.pory"
	walk_up
# 317 "data/maps/YifuCity/scripts.pory"
	walk_up
# 317 "data/maps/YifuCity/scripts.pory"
	walk_up
	step_end

# 359 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_1:
# 359 "data/maps/YifuCity/scripts.pory"
	jump_in_place_up
	step_end

# 369 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_2:
# 369 "data/maps/YifuCity/scripts.pory"
	jump_in_place_down
	step_end

# 380 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_3:
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
# 380 "data/maps/YifuCity/scripts.pory"
	walk_left
	step_end

# 381 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_4:
# 381 "data/maps/YifuCity/scripts.pory"
	walk_up
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
# 381 "data/maps/YifuCity/scripts.pory"
	walk_left
	step_end

# 388 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_5:
# 388 "data/maps/YifuCity/scripts.pory"
	walk_down
# 388 "data/maps/YifuCity/scripts.pory"
	walk_down
# 388 "data/maps/YifuCity/scripts.pory"
	walk_down
	step_end

# 453 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntStuckInHole_Movement_0:
# 453 "data/maps/YifuCity/scripts.pory"
	face_left
# 453 "data/maps/YifuCity/scripts.pory"
	delay_16
# 453 "data/maps/YifuCity/scripts.pory"
	face_up
# 453 "data/maps/YifuCity/scripts.pory"
	delay_16
# 453 "data/maps/YifuCity/scripts.pory"
	face_down
# 453 "data/maps/YifuCity/scripts.pory"
	delay_16
# 453 "data/maps/YifuCity/scripts.pory"
	face_right
# 453 "data/maps/YifuCity/scripts.pory"
	delay_16
# 453 "data/maps/YifuCity/scripts.pory"
	face_up
# 453 "data/maps/YifuCity/scripts.pory"
	delay_16
# 453 "data/maps/YifuCity/scripts.pory"
	delay_16
# 453 "data/maps/YifuCity/scripts.pory"
	delay_16
	step_end

# 459 "data/maps/YifuCity/scripts.pory"
YifuCity_Trigger_CrobatGruntStuckInHole_Movement_1:
# 459 "data/maps/YifuCity/scripts.pory"
	emote_exclamation_mark
# 459 "data/maps/YifuCity/scripts.pory"
	face_down
	step_end

YifuCity_EventScript_StoleMyMon_Text_0:
# 19 "data/maps/YifuCity/scripts.pory"
	.string "Man$"

YifuCity_EventScript_StoleMyMon_Text_1:
# 21 "data/maps/YifuCity/scripts.pory"
	.string "When I got my Shiftry back from the\n"
	.string "nurse, it had somehow changed into a\l"
	.string "Pidgey…\p"
	.string "Each day, Pokémon never cease to\n"
	.string "amaze me!$"

YifuCity_EventScript_IDontFeelSafe_Text_0:
# 31 "data/maps/YifuCity/scripts.pory"
	.string "Woman$"

YifuCity_EventScript_IDontFeelSafe_Text_1:
# 33 "data/maps/YifuCity/scripts.pory"
	.string "I don't feel safe with those Crobat\n"
	.string "weirdos creeping around the city…\p"
	.string "I can't imagine how much worse it'd be\n"
	.string "were it not for the patrolling\l"
	.string "Samurai!$"

YifuCity_EventScript_Samurai_Text_0:
# 43 "data/maps/YifuCity/scripts.pory"
	.string "Samurai$"

YifuCity_EventScript_Samurai_Text_1:
# 45 "data/maps/YifuCity/scripts.pory"
	.string "The Crobat Shadows' reign of terror\n"
	.string "will cease!$"

YifuCity_EventScript_Samurai2_Text_0:
# 56 "data/maps/YifuCity/scripts.pory"
	.string "Please be vigilant! Should you\n"
	.string "witness any suspicious situation,\l"
	.string "report it immediately!$"

YifuCity_EventScript_ShinySeller_Text_0:
# 65 "data/maps/YifuCity/scripts.pory"
	.string "Shady man$"

YifuCity_EventScript_ShinySeller_Text_1:
# 67 "data/maps/YifuCity/scripts.pory"
	.string "Hey, uh… Wanna buy this Pokémon 'ere?\n"
	.string "'Parently it's super rare or somethin',\l"
	.string "but I don't really need it, so…$"

YifuCity_EventScript_ShinySeller_Text_2:
# 79 "data/maps/YifuCity/scripts.pory"
	.string "So whaddyasay?\n"
	.string "It's yours for only ¥10000.$"

YifuCity_ShinySellerChoice_Text_0:
# 98 "data/maps/YifuCity/scripts.pory"
	.string "I'll buy it!$"

YifuCity_ShinySellerChoice_Text_1:
# 99 "data/maps/YifuCity/scripts.pory"
	.string "No, thanks.$"

YifuCity_ShinySellerChoice_Text_2:
# 100 "data/maps/YifuCity/scripts.pory"
	.string "Are you a criminal?$"

YifuCity_ShinySellerChoice_Text_3:
# 110 "data/maps/YifuCity/scripts.pory"
	.string "Alright yeah, gimme the cash.$"

YifuCity_ShinySellerChoice_Text_4:
# 126 "data/maps/YifuCity/scripts.pory"
	.string "{PLAYER} received the Pokémon\n"
	.string "Caterpie!$"

YifuCity_ShinySellerChoice_Text_5:
# 149 "data/maps/YifuCity/scripts.pory"
	.string "Heheheehe… I'm rich! Finally rich!$"

YifuCity_ShinySellerChoice_Text_6:
# 168 "data/maps/YifuCity/scripts.pory"
	.string "… … … … … …\n"
	.string "… … … … … …$"

YifuCity_ShinySellerChoice_Text_7:
# 183 "data/maps/YifuCity/scripts.pory"
	.string "Some gold paint came off the\n"
	.string "Caterpie…$"

YifuCity_ShinySellerChoice_Text_8:
# 204 "data/maps/YifuCity/scripts.pory"
	.string "You, uh… You don't got enough cash,\n"
	.string "kid.$"

YifuCity_ShinySellerChoice_Text_9:
# 212 "data/maps/YifuCity/scripts.pory"
	.string "Then why are ya botherin' me? Scram,\n"
	.string "kid!$"

YifuCity_ShinySellerChoice_Text_10:
# 219 "data/maps/YifuCity/scripts.pory"
	.string "What? No! Why would ya even say that?\n"
	.string "Do I not look respectable to ya?\p"
	.string "So uh… You gonna buy it or not?$"

YifuCity_Trigger_CrobatGruntsScram_Text_0:
# 237 "data/maps/YifuCity/scripts.pory"
	.string "I tell ya man, damn password keeps\n"
	.string "changin'…$"

YifuCity_Trigger_CrobatGruntsScram_Text_1:
# 260 "data/maps/YifuCity/scripts.pory"
	.string "Are ya kiddin' me? Lookaddis\n"
	.string "eavesdroppin' moron!\p"
	.string "Want a taste of this?$"

YifuCity_Trigger_CrobatGruntsScram_Text_2:
# 290 "data/maps/YifuCity/scripts.pory"
	.string "Yeah, that's right, hightail it outta\n"
	.string "here!$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0:
# 308 "data/maps/YifuCity/scripts.pory"
	.string "???$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_1:
# 326 "data/maps/YifuCity/scripts.pory"
	.string "Last time, I got it wrong and he didn'\n"
	.string "let me through!\p"
	.string "Like, brother, why I gotta tell ya\n"
	.string "some password for ya to let me in, we\l"
	.string "wen' to school together!$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_2:
# 336 "data/maps/YifuCity/scripts.pory"
	.string "Wait, ya didn't go to school though,\n"
	.string "didja?$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_3:
# 345 "data/maps/YifuCity/scripts.pory"
	.string "Who cares! It's a figger of speech!\n"
	.string "What's the newest password anyway?$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_4:
# 354 "data/maps/YifuCity/scripts.pory"
	.string "It's uh…\n"
	.string "Somethin' with Crobat…\l"
	.string "“{COLOR RED}Crobat is{COLOR DARK_GRAY}”… Uh…$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_5:
# 362 "data/maps/YifuCity/scripts.pory"
	.string "Aw man! I forgot it too!$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_6:
# 372 "data/maps/YifuCity/scripts.pory"
	.string "Ya idjet! How're we gunna get back in\n"
	.string "now??\p"
	.string "Now we gotta find another Zubat an'\n"
	.string "hope he's got enough brains to\l"
	.string "remember the full sent'nce!\p"
	.string "C'mon, lessgo!$"

YifuCity_EventScript_HearEcho_Text_0:
# 398 "data/maps/YifuCity/scripts.pory"
	.string "Boy$"

YifuCity_EventScript_HearEcho_Text_1:
# 400 "data/maps/YifuCity/scripts.pory"
	.string "There's a ghost haunting the sewers!\n"
	.string "I swear I heard a voice calling when I\l"
	.string "was walking along the canal!$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_0:
# 417 "data/maps/YifuCity/scripts.pory"
	.string "Yawn… I'm bored…$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_1:
# 421 "data/maps/YifuCity/scripts.pory"
	.string "Sure hope there ain't no Sharpedo in\n"
	.string "here…$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_2:
# 425 "data/maps/YifuCity/scripts.pory"
	.string "Echo! … … …\n"
	.string "… … …{FONT_SMALL}echo{FONT_NORMAL}…\p"
	.string "Hehe…\p"
	.string "…Sigh…$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_3:
# 437 "data/maps/YifuCity/scripts.pory"
	.string "“{COLOR RED}Crime is awesome{COLOR DARK_GRAY}”!\n"
	.string "Hmm…\p"
	.string "“{COLOR RED}Stealing is awesome{COLOR DARK_GRAY}”?\n"
	.string "Nah… That's not it.$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_4:
# 447 "data/maps/YifuCity/scripts.pory"
	.string "Heyyy!! Help!$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_5:
# 462 "data/maps/YifuCity/scripts.pory"
	.string "I fell down the canal! I'm stuck down\n"
	.string "'ere!\p"
	.string "Damn me, couldn't remember the first\n"
	.string "half of the damn password…\l"
	.string "“Something something… {COLOR RED}is awesome{COLOR DARK_GRAY}”!\l"
	.string "But what?!\l"
	.string "And why'd I think it was a good idea to\l"
	.string "try gettin' in through the canal?\l"
	.string "This is a dead end!$"

YifuCity_EventScript_Surskit_Text_0:
# 481 "data/maps/YifuCity/scripts.pory"
	.string "Surskit$"

YifuCity_EventScript_Surskit_Text_1:
# 483 "data/maps/YifuCity/scripts.pory"
	.string "Sksksksk…$"
