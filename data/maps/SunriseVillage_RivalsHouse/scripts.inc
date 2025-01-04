SunriseVillage_RivalsHouse_MapScripts::
# 6 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_ne SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	setflag FLAG_TEMP_1
	return


SunriseVillage_RivalsHouse_EventScript_Woman::
# 15 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	lock
# 16 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	faceplayer
# 17 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	speakername SunriseVillage_RivalsHouse_EventScript_Woman_Text_0
# 18 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_RivalsHouse_EventScript_Woman_2
# 24 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Woman_Text_2
SunriseVillage_RivalsHouse_EventScript_Woman_1:
# 29 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	release
	return

SunriseVillage_RivalsHouse_EventScript_Woman_2:
# 19 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Woman_Text_1
	goto SunriseVillage_RivalsHouse_EventScript_Woman_1


SunriseVillage_RivalsHouse_EventScript_Natsuki::
# 33 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	lock
# 34 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	applymovement 5, Common_Movement_FaceUp
# 35 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	waitmovement 0
# 37 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	goto_if_set FLAG_TEMP_2, SunriseVillage_RivalsHouse_EventScript_Natsuki_2
# 44 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	speakername SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0
# 45 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_2
# 48 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	closemessage
# 50 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	delay 48
# 52 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	faceplayer
# 53 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	speakername SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0
# 54 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_3
# 59 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	closemessage
# 61 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	applymovement 5, Common_Movement_FaceUp
# 62 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	waitmovement 0
# 64 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	setflag FLAG_TEMP_2
SunriseVillage_RivalsHouse_EventScript_Natsuki_1:
# 67 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	release
	return

SunriseVillage_RivalsHouse_EventScript_Natsuki_2:
# 38 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	speakername SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0
# 39 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_1
# 42 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	closemessage
	goto SunriseVillage_RivalsHouse_EventScript_Natsuki_1


SunriseVillage_RivalsHouse_EventScript_Man::
# 71 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	lock
# 72 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	faceplayer
# 73 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	speakername SunriseVillage_RivalsHouse_EventScript_Man_Text_0
# 74 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_RivalsHouse_EventScript_Man_2
# 80 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Man_Text_2
SunriseVillage_RivalsHouse_EventScript_Man_1:
# 84 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	release
	return

SunriseVillage_RivalsHouse_EventScript_Man_2:
# 75 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Man_Text_1
	goto SunriseVillage_RivalsHouse_EventScript_Man_1


SunriseVillage_RivalsHouse_EventScript_Meowth::
# 88 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	speakername SunriseVillage_RivalsHouse_EventScript_Meowth_Text_0
# 89 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Meowth_Text_1, MSGBOX_NPC
	return


SunriseVillage_RivalsHouse_EventScript_Meowth2::
# 95 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	lock
# 96 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	faceplayer
# 97 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	waitse
# 98 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
# 99 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	speakername SunriseVillage_RivalsHouse_EventScript_Meowth_Text_0
# 100 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	msgbox SunriseVillage_RivalsHouse_EventScript_Meowth2_Text_0
# 103 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	waitmoncry
# 104 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	release
	end


SunriseVillage_RivalsHouse_EventScript_Woman_Text_0:
# 17 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Natsuki's mom$"

SunriseVillage_RivalsHouse_EventScript_Woman_Text_1:
# 20 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "The house feels a little empty\n"
	.string "now that Natsuki has left home.\p"
	.string "I'm glad for our Pokémon and the\n"
	.string "companionship they provide us.$"

SunriseVillage_RivalsHouse_EventScript_Woman_Text_2:
# 25 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Good morning, {PLAYER}!\n"
	.string "Today's the big day, huh?\p"
	.string "Break a leg! Don't talk to strangers!$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0:
# 38 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Natsuki$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_1:
# 40 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Region map, check…\n"
	.string "Favorite plushie, check…$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_2:
# 46 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Poké Balls, check…\n"
	.string "Medicine, check…\l"
	.string "Spare pair of underwear, check…$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_3:
# 55 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Oh, hey, {PLAYER}. I'm just sorting\n"
	.string "out my stuff for the journey.\p"
	.string "I'm traveling as light as possible!\p"
	.string "See you around, yeah?$"

SunriseVillage_RivalsHouse_EventScript_Man_Text_0:
# 73 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Natsuki's dad$"

SunriseVillage_RivalsHouse_EventScript_Man_Text_1:
# 76 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Hello, {PLAYER}.\n"
	.string "How is your adventure going?\p"
	.string "Make sure you come back home\n"
	.string "to see your sister sometimes,\l"
	.string "I'm sure she misses you.$"

SunriseVillage_RivalsHouse_EventScript_Man_Text_2:
# 81 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Hello, {PLAYER}! How are you doing?\n"
	.string "Off to some trouble with Natsuki, I\l"
	.string "bet?$"

SunriseVillage_RivalsHouse_EventScript_Meowth_Text_0:
# 88 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Meowth$"

SunriseVillage_RivalsHouse_EventScript_Meowth_Text_1:
# 90 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Purrr…$"

SunriseVillage_RivalsHouse_EventScript_Meowth2_Text_0:
# 101 "data/maps/SunriseVillage_RivalsHouse/scripts.pory"
	.string "Meow!$"
