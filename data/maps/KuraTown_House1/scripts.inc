KuraTown_House1_MapScripts::
# 2 "data/maps/KuraTown_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/KuraTown_House1/scripts.pory"
	setrespawn HEAL_LOCATION_KURA_TOWN
	return


KuraTown_House1_OldWoman::
# 8 "data/maps/KuraTown_House1/scripts.pory"
	lock
# 9 "data/maps/KuraTown_House1/scripts.pory"
	faceplayer
# 10 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWoman_Text_0
# 13 "data/maps/KuraTown_House1/scripts.pory"
	closemessage
# 14 "data/maps/KuraTown_House1/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 15 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWoman_Text_1
# 18 "data/maps/KuraTown_House1/scripts.pory"
	closemessage
# 19 "data/maps/KuraTown_House1/scripts.pory"
	release
	return


KuraTown_House1_OldWomansSon::
# 23 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWomansSon_Text_0, MSGBOX_NPC
	return


KuraTown_House1_Growlithe::
# 31 "data/maps/KuraTown_House1/scripts.pory"
	lock
# 32 "data/maps/KuraTown_House1/scripts.pory"
	faceplayer
# 33 "data/maps/KuraTown_House1/scripts.pory"
	waitse
# 34 "data/maps/KuraTown_House1/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 35 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_Growlithe_Text_0
# 38 "data/maps/KuraTown_House1/scripts.pory"
	waitmoncry
# 39 "data/maps/KuraTown_House1/scripts.pory"
	release
	return


KuraTown_House1_OldWoman_Text_0:
# 11 "data/maps/KuraTown_House1/scripts.pory"
	.string "You look like you're tired, young one.\n"
	.string "Please rest a while.$"

KuraTown_House1_OldWoman_Text_1:
# 16 "data/maps/KuraTown_House1/scripts.pory"
	.string "I wish you strength on your journey.$"

KuraTown_House1_OldWomansSon_Text_0:
# 24 "data/maps/KuraTown_House1/scripts.pory"
	.string "The Pokémon league organization\n"
	.string "didn't see fit to build a Pokémon\l"
	.string "refuge in our village, but those jerks\l"
	.string "over at Saku Village won't let us use\l"
	.string "theirs.\p"
	.string "So my mother has to work hard to heal\n"
	.string "all the villager's Pokémon.\p"
	.string "It's not fair!$"

KuraTown_House1_Growlithe_Text_0:
# 36 "data/maps/KuraTown_House1/scripts.pory"
	.string "Wah!$"
