ChiiTown_PokemonCenter_MapScripts::
# 5 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setrespawn HEAL_LOCATION_CHII_TOWN
# 7 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	gettime
# 9 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	compare VAR_0x8000, 5
	goto_if_ge ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 18 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setflag FLAG_TEMP_1
# 20 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	clearflag FLAG_TEMP_2
# 21 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	random 3
# 23 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	switch VAR_RESULT
# 24 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	case 0, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_7
# 26 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	case 1, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
# 28 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	case 2, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 11 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	clearflag FLAG_TEMP_1
# 13 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setflag FLAG_TEMP_2
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 9 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	compare VAR_0x8000, 17
	goto_if_le ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 25 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHAMISEN_RED
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 27 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHAMISEN_BLUE
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
# 29 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHAMISEN_GREEN
	return


ChiiTown_PokemonCenter_EventScript_Nurse::
# 36 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setvar VAR_0x800B, 1
# 37 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
# 38 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitmessage
# 39 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitbuttonpress
# 40 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_Shamisen::
# 45 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 46 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 48 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_Shamisen_Text_0
# 49 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_Shamisen_Text_1
# 54 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 55 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_ShamisenFan::
# 60 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 61 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 62 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_0
# 63 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_1
# 70 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 71 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_Boy::
# 76 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 77 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 78 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_Boy_Text_0
# 79 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_Boy_Text_1
# 83 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 84 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_Mom::
# 89 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 90 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 91 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_Mom_Text_0
# 92 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_Mom_Text_1
# 96 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 97 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_WhereShamisen::
# 102 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 103 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 104 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_0
# 105 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_1
# 108 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 109 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_IveComeALongWay::
# 114 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 115 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 116 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_0
# 117 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_1
# 121 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 122 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_Snorunt::
# 127 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 128 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 129 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	playmoncry SPECIES_SNORUNT, CRY_MODE_NORMAL
# 130 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	ismonseen SPECIES_SNORUNT
# 131 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_PokemonCenter_EventScript_Snorunt_2
# 134 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_Snorunt_Text_1
ChiiTown_PokemonCenter_EventScript_Snorunt_1:
# 136 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_Snorunt_Text_2
# 139 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitmoncry
# 140 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 141 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end

ChiiTown_PokemonCenter_EventScript_Snorunt_2:
# 132 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_Snorunt_Text_0
	goto ChiiTown_PokemonCenter_EventScript_Snorunt_1


ChiiTown_PokemonCenter_EventScript_NeedMarket::
# 146 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 147 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 148 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_0
# 149 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_1
# 152 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 153 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_RefugePresentation::
# 158 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 159 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 160 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	speakername ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_0
# 161 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_1
# 167 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 169 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	switch VAR_FACING
# 170 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	case DIR_NORTH, ChiiTown_PokemonCenter_EventScript_RefugePresentation_3
# 172 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	case DIR_WEST, ChiiTown_PokemonCenter_EventScript_RefugePresentation_4
# 174 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	case DIR_EAST, ChiiTown_PokemonCenter_EventScript_RefugePresentation_5
ChiiTown_PokemonCenter_EventScript_RefugePresentation_1:
# 177 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitmovement 0
# 178 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	removeobject 2
# 179 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	playse SE_EXIT
# 180 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitse
# 182 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setflag FLAG_POKEMON_REFUGE_PRESENTATION
# 183 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end

ChiiTown_PokemonCenter_EventScript_RefugePresentation_3:
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	applymovement 2, ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_0
	goto ChiiTown_PokemonCenter_EventScript_RefugePresentation_1

ChiiTown_PokemonCenter_EventScript_RefugePresentation_4:
# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	applymovement 2, ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_1
	goto ChiiTown_PokemonCenter_EventScript_RefugePresentation_1

ChiiTown_PokemonCenter_EventScript_RefugePresentation_5:
# 175 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	applymovement 2, ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_1
	goto ChiiTown_PokemonCenter_EventScript_RefugePresentation_1


# 187 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
ChiiTown_PokemonCenter_Movement_LeaveWhenFromBottom:
# 188 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_right
# 189 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 189 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 189 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 189 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 189 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 189 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
	step_end

# 192 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
ChiiTown_PokemonCenter_Movement_Leave:
# 193 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 193 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 193 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 193 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 193 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 193 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
	step_end

# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_0:
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_right
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 171 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
	step_end

# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_1:
# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 173 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
	step_end

ChiiTown_PokemonCenter_EventScript_Shamisen_Text_0:
# 48 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Shamisen player$"

ChiiTown_PokemonCenter_EventScript_Shamisen_Text_1:
# 50 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Good evening.\p"
	.string "We blind shamisen players sing to\n"
	.string "survive.\p"
	.string "These Pokémon refuges give us a safe\n"
	.string "place to spend the night.$"

ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_0:
# 62 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Shamisen fan$"

ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_1:
# 64 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Such a beautiful voice…\p"
	.string "Such sorrowful melodies…\p"
	.string "Such ethereal beauty…\p"
	.string "I could listen to her forever…\p"
	.string "Even though she can't see me, I sure\n"
	.string "hope she'll notice me one day…$"

ChiiTown_PokemonCenter_EventScript_Boy_Text_0:
# 78 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Little boy$"

ChiiTown_PokemonCenter_EventScript_Boy_Text_1:
# 80 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "I'm here with my mama!\p"
	.string "The music lady's nice!$"

ChiiTown_PokemonCenter_EventScript_Mom_Text_0:
# 91 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Little boy's mom$"

ChiiTown_PokemonCenter_EventScript_Mom_Text_1:
# 93 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Traveling shamisen players take\n"
	.string "shelter in Pokémon refuges when the\l"
	.string "night falls.\p"
	.string "Their singing makes for such a cosy\n"
	.string "atmosphere!$"

ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_0:
# 104 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Weird man$"

ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_1:
# 106 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Where's that cute shamisen player\n"
	.string "that was here last night?$"

ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_0:
# 116 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Weary traveler$"

ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_1:
# 118 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "I'm so glad I found this refuge. I've\n"
	.string "come a long way and my feet hurt.\p"
	.string "My Pokémon and I wil rest here for a\n"
	.string "while.$"

ChiiTown_PokemonCenter_EventScript_Snorunt_Text_0:
# 132 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Snorunt$"

ChiiTown_PokemonCenter_EventScript_Snorunt_Text_1:
# 134 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Cold dumpling$"

ChiiTown_PokemonCenter_EventScript_Snorunt_Text_2:
# 137 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Glaglaglaglagla!$"

ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_0:
# 148 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Woman$"

ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_1:
# 150 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Berries, potions… Oh, right, I should\n"
	.string "get a few more Poké Balls from the\l"
	.string "town market!$"

ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_0:
# 160 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Talkative man$"

ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_1:
# 162 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Isn't it amazing? This is one of the\n"
	.string "many brand-new Pokémon refuges that\l"
	.string "the Pokémon league council has\l"
	.string "decided to build in towns across all\l"
	.string "Toku!\p"
	.string "With traveling alone becoming more\n"
	.string "dangerous, many people are now\l"
	.string "training a Pokémon of their own for\l"
	.string "protection.\p"
	.string "Towns were starting to be in dire need\n"
	.string "of proper healing and rest spots for\l"
	.string "Pokémon.\p"
	.string "Oh, sorry, I'll get out of your hair\n"
	.string "now. Talk to the nurse whenever you\l"
	.string "want her to heal your Pokémon!$"
