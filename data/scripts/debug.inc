# 1 "data/scripts/debug.pory"

# 2 "data/scripts/debug.pory"
Debug_MessageEnd:
# 3 "data/scripts/debug.pory"
	waitmessage
# 4 "data/scripts/debug.pory"
	waitbuttonpress
# 5 "data/scripts/debug.pory"
	releaseall
# 6 "data/scripts/debug.pory"
	end
# 7 "data/scripts/debug.pory"

# 8 "data/scripts/debug.pory"
Debug_ShowFieldMessageStringVar4::
# 9 "data/scripts/debug.pory"
	special ShowFieldMessageStringVar4
# 10 "data/scripts/debug.pory"
	goto Debug_MessageEnd
# 11 "data/scripts/debug.pory"

# 12 "data/scripts/debug.pory"
Debug_CheatStart::
# 13 "data/scripts/debug.pory"
	setflag FLAG_SYS_POKEMON_GET
# 14 "data/scripts/debug.pory"
	setflag FLAG_RESCUED_BIRCH
# 15 "data/scripts/debug.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 16 "data/scripts/debug.pory"
	setflag FLAG_ADVENTURE_STARTED
# 17 "data/scripts/debug.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 18 "data/scripts/debug.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 19 "data/scripts/debug.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 20 "data/scripts/debug.pory"
	setvar VAR_ROUTE101_STATE, 3
# 21 "data/scripts/debug.pory"
	givemon SPECIES_TREECKO, 20, ITEM_NONE
# 22 "data/scripts/debug.pory"
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
# 23 "data/scripts/debug.pory"
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
# 24 "data/scripts/debug.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 25 "data/scripts/debug.pory"
	special SetUnlockedPokedexFlags
# 26 "data/scripts/debug.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 27 "data/scripts/debug.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
# 28 "data/scripts/debug.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 29 "data/scripts/debug.pory"
	special EnableNationalPokedex
# 30 "data/scripts/debug.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 31 "data/scripts/debug.pory"
	setflag FLAG_SYS_B_DASH
# 32 "data/scripts/debug.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
# 33 "data/scripts/debug.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
# 34 "data/scripts/debug.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
# 35 "data/scripts/debug.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
# 36 "data/scripts/debug.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
# 37 "data/scripts/debug.pory"
	setflag FLAG_RECEIVED_BIKE
# 38 "data/scripts/debug.pory"
	additem ITEM_ACRO_BIKE
# 39 "data/scripts/debug.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 40 "data/scripts/debug.pory"
	setvar VAR_ROUTE116_STATE, 2
# 41 "data/scripts/debug.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 42 "data/scripts/debug.pory"
	setflag FLAG_BADGE01_GET
# 43 "data/scripts/debug.pory"
	setflag FLAG_BADGE02_GET
# 44 "data/scripts/debug.pory"
	setflag FLAG_BADGE03_GET
# 45 "data/scripts/debug.pory"
	setflag FLAG_BADGE04_GET
# 46 "data/scripts/debug.pory"
	setflag FLAG_BADGE05_GET
# 47 "data/scripts/debug.pory"
	setflag FLAG_BADGE06_GET
# 48 "data/scripts/debug.pory"
	setflag FLAG_BADGE07_GET
# 49 "data/scripts/debug.pory"
	setflag FLAG_BADGE08_GET
# 50 "data/scripts/debug.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 51 "data/scripts/debug.pory"
	setflag FLAG_VISITED_CHII_TOWN
# 52 "data/scripts/debug.pory"
	setflag FLAG_VISITED_SAKU_TOWN
# 53 "data/scripts/debug.pory"
	setflag FLAG_VISITED_KURA_TOWN
# 54 "data/scripts/debug.pory"
	setflag FLAG_VISITED_FALLARBOR_TOWN
# 55 "data/scripts/debug.pory"
	setflag FLAG_VISITED_VERDANTURF_TOWN
# 56 "data/scripts/debug.pory"
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
# 57 "data/scripts/debug.pory"
	setflag FLAG_VISITED_PETALBURG_CITY
# 58 "data/scripts/debug.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 59 "data/scripts/debug.pory"
	setflag FLAG_VISITED_MAUVILLE_CITY
# 60 "data/scripts/debug.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 61 "data/scripts/debug.pory"
	setflag FLAG_VISITED_FORTREE_CITY
# 62 "data/scripts/debug.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 63 "data/scripts/debug.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 64 "data/scripts/debug.pory"
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
# 65 "data/scripts/debug.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 66 "data/scripts/debug.pory"
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
# 67 "data/scripts/debug.pory"
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
# 68 "data/scripts/debug.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 69 "data/scripts/debug.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 70 "data/scripts/debug.pory"

# 71 "data/scripts/debug.pory"
	@ Custom Hearth flags
# 72 "data/scripts/debug.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
# 73 "data/scripts/debug.pory"
	setflag FLAG_HIDE_SUNRISE_BEACH_RIVAL
# 74 "data/scripts/debug.pory"
	setflag FLAG_RECEIVED_STARTER
# 75 "data/scripts/debug.pory"
	release
# 76 "data/scripts/debug.pory"
	end
# 77 "data/scripts/debug.pory"

# 78 "data/scripts/debug.pory"
Debug_FlagsNotSetOverworldConfigMessage::
# 79 "data/scripts/debug.pory"
	message Debug_FlagsNotSetOverworldConfigMessage_Text
# 80 "data/scripts/debug.pory"
	goto Debug_MessageEnd
# 81 "data/scripts/debug.pory"

# 82 "data/scripts/debug.pory"
Debug_FlagsNotSetOverworldConfigMessage_Text:
# 83 "data/scripts/debug.pory"
	.string "Feature unavailable!\n"
# 84 "data/scripts/debug.pory"
	.string "Please define a usable flag in:\l"
# 85 "data/scripts/debug.pory"
	.string "'include/config/overworld.h'!$"
# 86 "data/scripts/debug.pory"

# 87 "data/scripts/debug.pory"
Debug_FlagsNotSetBattleConfigMessage::
# 88 "data/scripts/debug.pory"
	message Debug_FlagsNotSetBattleConfigMessage_Text
# 89 "data/scripts/debug.pory"
	goto Debug_MessageEnd
# 90 "data/scripts/debug.pory"

# 91 "data/scripts/debug.pory"
Debug_FlagsNotSetBattleConfigMessage_Text:
# 92 "data/scripts/debug.pory"
	.string "Feature unavailable!\n"
# 93 "data/scripts/debug.pory"
	.string "Please define a usable flag in:\l"
# 94 "data/scripts/debug.pory"
	.string "'include/config/battle.h'!$"
# 95 "data/scripts/debug.pory"

# 96 "data/scripts/debug.pory"
Debug_BoxFilledMessage::
# 97 "data/scripts/debug.pory"
	message Debug_BoxFilledMessage_Text
# 98 "data/scripts/debug.pory"
	goto Debug_MessageEnd
# 99 "data/scripts/debug.pory"

# 100 "data/scripts/debug.pory"
Debug_BoxFilledMessage_Text:
# 101 "data/scripts/debug.pory"
	.string "Storage boxes filled!$"
# 102 "data/scripts/debug.pory"

# 103 "data/scripts/debug.pory"
Debug_EventScript_CheckEVs::
# 104 "data/scripts/debug.pory"
	lockall
# 105 "data/scripts/debug.pory"
	getpartysize
# 106 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
# 107 "data/scripts/debug.pory"
	special ChoosePartyMon
# 108 "data/scripts/debug.pory"
	waitstate
# 109 "data/scripts/debug.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckEVs_End
# 110 "data/scripts/debug.pory"
	callnative Script_GetChosenMonOffensiveEVs
# 111 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Text_OffensiveEVs, MSGBOX_DEFAULT
# 112 "data/scripts/debug.pory"
	callnative Script_GetChosenMonDefensiveEVs
# 113 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Text_DefensiveEVs, MSGBOX_DEFAULT
# 114 "data/scripts/debug.pory"
Debug_EventScript_CheckEVs_End::
# 115 "data/scripts/debug.pory"
	releaseall
# 116 "data/scripts/debug.pory"
	end
# 117 "data/scripts/debug.pory"

# 118 "data/scripts/debug.pory"
Debug_EventScript_Text_OffensiveEVs:
# 119 "data/scripts/debug.pory"
	.string "ATK EVs: {STR_VAR_1}, SPATK EVs: {STR_VAR_2}, SPEED EVs: {STR_VAR_3}$"
# 120 "data/scripts/debug.pory"

# 121 "data/scripts/debug.pory"
Debug_EventScript_Text_DefensiveEVs:
# 122 "data/scripts/debug.pory"
	.string "HP EVs: {STR_VAR_1}, DEF EVs: {STR_VAR_2}, SPDEF EVs: {STR_VAR_3}$"
# 123 "data/scripts/debug.pory"

# 124 "data/scripts/debug.pory"
Debug_EventScript_CheckIVs::
# 125 "data/scripts/debug.pory"
	lockall
# 126 "data/scripts/debug.pory"
	getpartysize
# 127 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
# 128 "data/scripts/debug.pory"
	special ChoosePartyMon
# 129 "data/scripts/debug.pory"
	waitstate
# 130 "data/scripts/debug.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckIVs_End
# 131 "data/scripts/debug.pory"
	callnative Script_GetChosenMonOffensiveIVs
# 132 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Text_OffensiveIVs, MSGBOX_DEFAULT
# 133 "data/scripts/debug.pory"
	callnative Script_GetChosenMonDefensiveIVs
# 134 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Text_DefensiveIVs, MSGBOX_DEFAULT
# 135 "data/scripts/debug.pory"
Debug_EventScript_CheckIVs_End::
# 136 "data/scripts/debug.pory"
	releaseall
# 137 "data/scripts/debug.pory"
	end
# 138 "data/scripts/debug.pory"

# 139 "data/scripts/debug.pory"
Debug_EventScript_Text_OffensiveIVs:
# 140 "data/scripts/debug.pory"
	.string "ATK IVs: {STR_VAR_1}, SPATK IVs: {STR_VAR_2}, SPEED IVs: {STR_VAR_3}$"
# 141 "data/scripts/debug.pory"

# 142 "data/scripts/debug.pory"
Debug_EventScript_Text_DefensiveIVs:
# 143 "data/scripts/debug.pory"
	.string "HP IVs: {STR_VAR_1}, DEF IVs: {STR_VAR_2}, SPDEF IVs: {STR_VAR_3}$"

Debug_EventScript_Script_1::
# 146 "data/scripts/debug.pory"
	fwdtime 8, 0
# 147 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Script_1_Text_0, MSGBOX_DEFAULT
# 148 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_2::
# 153 "data/scripts/debug.pory"
	fwdtime 12, 0
# 154 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Script_2_Text_0, MSGBOX_DEFAULT
# 155 "data/scripts/debug.pory"
	closemessage
# 156 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_3::
# 161 "data/scripts/debug.pory"
	fwdtime 14, 0
# 162 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Script_3_Text_0, MSGBOX_DEFAULT
# 163 "data/scripts/debug.pory"
	closemessage
# 164 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_4::
# 169 "data/scripts/debug.pory"
	fwdtime 5, 0
# 170 "data/scripts/debug.pory"
	msgbox Debug_EventScript_Script_4_Text_0, MSGBOX_DEFAULT
# 171 "data/scripts/debug.pory"
	closemessage
# 172 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_5::
# 177 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_6::
# 182 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_7::
# 187 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_8::
# 192 "data/scripts/debug.pory"
	release
	end


# 196 "data/scripts/debug.pory"

# 197 "data/scripts/debug.pory"
Debug_CheckSaveBlock::
# 198 "data/scripts/debug.pory"
	callnative CheckSaveBlock1Size
# 199 "data/scripts/debug.pory"
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
# 200 "data/scripts/debug.pory"
	callnative CheckSaveBlock2Size
# 201 "data/scripts/debug.pory"
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
# 202 "data/scripts/debug.pory"
	callnative CheckSaveBlock3Size
# 203 "data/scripts/debug.pory"
	msgbox Debug_SaveBlock3Size, MSGBOX_DEFAULT
# 204 "data/scripts/debug.pory"
	callnative CheckPokemonStorageSize
# 205 "data/scripts/debug.pory"
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
# 206 "data/scripts/debug.pory"
	release
# 207 "data/scripts/debug.pory"
	end
# 208 "data/scripts/debug.pory"

# 209 "data/scripts/debug.pory"
Debug_SaveBlock1Size::
# 210 "data/scripts/debug.pory"
	.string "SaveBlock1 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 211 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 212 "data/scripts/debug.pory"

# 213 "data/scripts/debug.pory"
Debug_SaveBlock2Size::
# 214 "data/scripts/debug.pory"
	.string "SaveBlock2 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 215 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 216 "data/scripts/debug.pory"

# 217 "data/scripts/debug.pory"
Debug_SaveBlock3Size::
# 218 "data/scripts/debug.pory"
	.string "SaveBlock3 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 219 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 220 "data/scripts/debug.pory"

# 221 "data/scripts/debug.pory"
Debug_PokemonStorageSize::
# 222 "data/scripts/debug.pory"
	.string "{PKMN}Storage size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 223 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 224 "data/scripts/debug.pory"

# 225 "data/scripts/debug.pory"
Debug_CheckROMSpace::
# 226 "data/scripts/debug.pory"
	callnative CheckROMSize
# 227 "data/scripts/debug.pory"
	msgbox Debug_ROMSize, MSGBOX_DEFAULT
# 228 "data/scripts/debug.pory"
	release
# 229 "data/scripts/debug.pory"
	end
# 230 "data/scripts/debug.pory"

# 231 "data/scripts/debug.pory"
Debug_ROMSize::
# 232 "data/scripts/debug.pory"
	.string "ROM size: {STR_VAR_1}MB/32MB.\n"
# 233 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_2}MB.$"
# 234 "data/scripts/debug.pory"

# 235 "data/scripts/debug.pory"
Debug_HatchAnEgg::
# 236 "data/scripts/debug.pory"
	lockall
# 237 "data/scripts/debug.pory"
	getpartysize
# 238 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
# 239 "data/scripts/debug.pory"
	special ChoosePartyMon
# 240 "data/scripts/debug.pory"
	waitstate
# 241 "data/scripts/debug.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_HatchAnEgg_End
# 242 "data/scripts/debug.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 243 "data/scripts/debug.pory"
	goto_if_ne VAR_RESULT, SPECIES_EGG, DebugScript_HatchAnEgg_CantForceHatch
# 244 "data/scripts/debug.pory"
	special EggHatch
# 245 "data/scripts/debug.pory"
	waitstate
# 246 "data/scripts/debug.pory"
Debug_HatchAnEgg_End::
# 247 "data/scripts/debug.pory"
	releaseall
# 248 "data/scripts/debug.pory"
	end
# 249 "data/scripts/debug.pory"

# 250 "data/scripts/debug.pory"
Debug_NoPokemon::
# 251 "data/scripts/debug.pory"
	msgbox DebugScript_Text_EmptyParty, MSGBOX_DEFAULT
# 252 "data/scripts/debug.pory"
	releaseall
# 253 "data/scripts/debug.pory"
	end
# 254 "data/scripts/debug.pory"

# 255 "data/scripts/debug.pory"
DebugScript_HatchAnEgg_CantForceHatch::
# 256 "data/scripts/debug.pory"
	msgbox DebugScript_HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
# 257 "data/scripts/debug.pory"
	releaseall
# 258 "data/scripts/debug.pory"
	end
# 259 "data/scripts/debug.pory"

# 260 "data/scripts/debug.pory"
DebugScript_Text_EmptyParty::
# 261 "data/scripts/debug.pory"
	.string "You have no Pokémon nor Eggs.$"
# 262 "data/scripts/debug.pory"

# 263 "data/scripts/debug.pory"
DebugScript_HatchAnEgg_Text_NotAnEgg::
# 264 "data/scripts/debug.pory"
	.string "That's not a Pokémon Egg.$"
# 265 "data/scripts/debug.pory"

# 266 "data/scripts/debug.pory"
DebugScript_ZeroDaycareMons::
# 267 "data/scripts/debug.pory"
	msgbox DebugText_DaycareNoPokemon, MSGBOX_DEFAULT
# 268 "data/scripts/debug.pory"
	releaseall
# 269 "data/scripts/debug.pory"
	end
# 270 "data/scripts/debug.pory"

# 271 "data/scripts/debug.pory"
DebugScript_OneDaycareMons::
# 272 "data/scripts/debug.pory"
	msgbox DebugText_DaycareOnePokemon, MSGBOX_DEFAULT
# 273 "data/scripts/debug.pory"
	releaseall
# 274 "data/scripts/debug.pory"
	end
# 275 "data/scripts/debug.pory"

# 276 "data/scripts/debug.pory"
DebugScript_DaycareMonsNotCompatible::
# 277 "data/scripts/debug.pory"
	msgbox DebugText_DaycarePokemonNotCompatible, MSGBOX_DEFAULT
# 278 "data/scripts/debug.pory"
	releaseall
# 279 "data/scripts/debug.pory"
	end
# 280 "data/scripts/debug.pory"

# 281 "data/scripts/debug.pory"
DebugText_DaycareNoPokemon:
# 282 "data/scripts/debug.pory"
	.string "You have no Pokémon at Daycare.$"
# 283 "data/scripts/debug.pory"

# 284 "data/scripts/debug.pory"
DebugText_DaycareOnePokemon:
# 285 "data/scripts/debug.pory"
	.string "You have only one Pokémon at Daycare.$"
# 286 "data/scripts/debug.pory"

# 287 "data/scripts/debug.pory"
DebugText_DaycarePokemonNotCompatible:
# 288 "data/scripts/debug.pory"
	.string "Your Pokémon at Daycare can't\nhave babies together!$"
# 289 "data/scripts/debug.pory"

# 290 "data/scripts/debug.pory"
Debug_ShowExpansionVersion::
# 291 "data/scripts/debug.pory"
	callnative BufferExpansionVersion
# 292 "data/scripts/debug.pory"
	msgbox Debug_ExpansionVersion, MSGBOX_DEFAULT
# 293 "data/scripts/debug.pory"
	release
# 294 "data/scripts/debug.pory"
	end
# 295 "data/scripts/debug.pory"

# 296 "data/scripts/debug.pory"
Debug_ExpansionVersion:
# 297 "data/scripts/debug.pory"
	.string "pokeemerald-expansion {STR_VAR_1}$"
# 298 "data/scripts/debug.pory"

# 299 "data/scripts/debug.pory"
Debug_BerryPestsDisabled::
# 300 "data/scripts/debug.pory"
	msgbox DebugText_BerryPestsDisabled, MSGBOX_DEFAULT
# 301 "data/scripts/debug.pory"
	release
# 302 "data/scripts/debug.pory"
	end
# 303 "data/scripts/debug.pory"

# 304 "data/scripts/debug.pory"
DebugText_BerryPestsDisabled:
# 305 "data/scripts/debug.pory"
	.string "OW_BERRY_PESTS is disabled.\n"
# 306 "data/scripts/debug.pory"
	.string "Unable to force pests onto berry trees.$"
# 307 "data/scripts/debug.pory"

# 308 "data/scripts/debug.pory"
Debug_BerryWeedsDisabled::
# 309 "data/scripts/debug.pory"
	msgbox DebugText_BerryWeedsDisabled, MSGBOX_DEFAULT
# 310 "data/scripts/debug.pory"
	release
# 311 "data/scripts/debug.pory"
	end
# 312 "data/scripts/debug.pory"

# 313 "data/scripts/debug.pory"
DebugText_BerryWeedsDisabled:
# 314 "data/scripts/debug.pory"
	.string "OW_BERRY_WEEDS is disabled.\n"
# 315 "data/scripts/debug.pory"
	.string "Unable to force weeds onto berry trees.$"
# 316 "data/scripts/debug.pory"

# 317 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1::
# 318 "data/scripts/debug.pory"
	lockall
# 319 "data/scripts/debug.pory"
	getpartysize
# 320 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
# 321 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
# 322 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
# 323 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
# 324 "data/scripts/debug.pory"
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
# 325 "data/scripts/debug.pory"
	switch VAR_RESULT
# 326 "data/scripts/debug.pory"
	case 0, Debug_EventScript_InflictStatus1_Single
# 327 "data/scripts/debug.pory"
	case 1, Debug_EventScript_InflictStatus1_Party
# 328 "data/scripts/debug.pory"
	case 2, Debug_EventScript_InflictStatus1_Close
# 329 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Close:
# 330 "data/scripts/debug.pory"
	releaseall
# 331 "data/scripts/debug.pory"
	end
# 332 "data/scripts/debug.pory"

# 333 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single:
# 334 "data/scripts/debug.pory"
	special ChoosePartyMon
# 335 "data/scripts/debug.pory"
	waitstate
# 336 "data/scripts/debug.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
# 337 "data/scripts/debug.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 338 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
# 339 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
# 340 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
# 341 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
# 342 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
# 343 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
# 344 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
# 345 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
# 346 "data/scripts/debug.pory"
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
# 347 "data/scripts/debug.pory"
	switch VAR_RESULT
# 348 "data/scripts/debug.pory"
	case 0, Debug_EventScript_InflictStatus1_Single_Poison
# 349 "data/scripts/debug.pory"
	case 1, Debug_EventScript_InflictStatus1_Single_Paralysis
# 350 "data/scripts/debug.pory"
	case 2, Debug_EventScript_InflictStatus1_Single_Sleep
# 351 "data/scripts/debug.pory"
	case 3, Debug_EventScript_InflictStatus1_Single_Burn
# 352 "data/scripts/debug.pory"
	case 4, Debug_EventScript_InflictStatus1_Single_Freeze
# 353 "data/scripts/debug.pory"
	case 5, Debug_EventScript_InflictStatus1_Single_Frostbite
# 354 "data/scripts/debug.pory"
	case 6, Debug_EventScript_InflictStatus1_Close
# 355 "data/scripts/debug.pory"
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
# 356 "data/scripts/debug.pory"
	releaseall
# 357 "data/scripts/debug.pory"
	end
# 358 "data/scripts/debug.pory"

# 359 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Poison:
# 360 "data/scripts/debug.pory"
	setstatus1 STATUS1_POISON, VAR_0x8004
# 361 "data/scripts/debug.pory"
	releaseall
# 362 "data/scripts/debug.pory"
	end
# 363 "data/scripts/debug.pory"

# 364 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Paralysis:
# 365 "data/scripts/debug.pory"
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
# 366 "data/scripts/debug.pory"
	releaseall
# 367 "data/scripts/debug.pory"
	end
# 368 "data/scripts/debug.pory"

# 369 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Sleep:
# 370 "data/scripts/debug.pory"
	setstatus1 STATUS1_SLEEP, VAR_0x8004
# 371 "data/scripts/debug.pory"
	releaseall
# 372 "data/scripts/debug.pory"
	end
# 373 "data/scripts/debug.pory"

# 374 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Burn:
# 375 "data/scripts/debug.pory"
	setstatus1 STATUS1_BURN, VAR_0x8004
# 376 "data/scripts/debug.pory"
	releaseall
# 377 "data/scripts/debug.pory"
	end
# 378 "data/scripts/debug.pory"

# 379 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Freeze:
# 380 "data/scripts/debug.pory"
	setstatus1 STATUS1_FREEZE, VAR_0x8004
# 381 "data/scripts/debug.pory"
	releaseall
# 382 "data/scripts/debug.pory"
	end
# 383 "data/scripts/debug.pory"

# 384 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Frostbite:
# 385 "data/scripts/debug.pory"
	setstatus1 STATUS1_FROSTBITE, VAR_0x8004
# 386 "data/scripts/debug.pory"
	releaseall
# 387 "data/scripts/debug.pory"
	end
# 388 "data/scripts/debug.pory"

# 389 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party:
# 390 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
# 391 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
# 392 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
# 393 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
# 394 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
# 395 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
# 396 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
# 397 "data/scripts/debug.pory"
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
# 398 "data/scripts/debug.pory"
	switch VAR_RESULT
# 399 "data/scripts/debug.pory"
	case 0, Debug_EventScript_InflictStatus1_Party_Poison
# 400 "data/scripts/debug.pory"
	case 1, Debug_EventScript_InflictStatus1_Party_Paralysis
# 401 "data/scripts/debug.pory"
	case 2, Debug_EventScript_InflictStatus1_Party_Sleep
# 402 "data/scripts/debug.pory"
	case 3, Debug_EventScript_InflictStatus1_Party_Burn
# 403 "data/scripts/debug.pory"
	case 4, Debug_EventScript_InflictStatus1_Party_Freeze
# 404 "data/scripts/debug.pory"
	case 5, Debug_EventScript_InflictStatus1_Party_Frostbite
# 405 "data/scripts/debug.pory"
	case 6, Debug_EventScript_InflictStatus1_Close
# 406 "data/scripts/debug.pory"
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
# 407 "data/scripts/debug.pory"
	releaseall
# 408 "data/scripts/debug.pory"
	end
# 409 "data/scripts/debug.pory"

# 410 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Poison:
# 411 "data/scripts/debug.pory"
	setstatus1 STATUS1_POISON, PARTY_SIZE
# 412 "data/scripts/debug.pory"
	releaseall
# 413 "data/scripts/debug.pory"
	end
# 414 "data/scripts/debug.pory"

# 415 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Paralysis:
# 416 "data/scripts/debug.pory"
	setstatus1 STATUS1_PARALYSIS, PARTY_SIZE
# 417 "data/scripts/debug.pory"
	releaseall
# 418 "data/scripts/debug.pory"
	end
# 419 "data/scripts/debug.pory"

# 420 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Sleep:
# 421 "data/scripts/debug.pory"
	setstatus1 STATUS1_SLEEP, PARTY_SIZE
# 422 "data/scripts/debug.pory"
	releaseall
# 423 "data/scripts/debug.pory"
	end
# 424 "data/scripts/debug.pory"

# 425 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Burn:
# 426 "data/scripts/debug.pory"
	setstatus1 STATUS1_BURN, PARTY_SIZE
# 427 "data/scripts/debug.pory"
	releaseall
# 428 "data/scripts/debug.pory"
	end
# 429 "data/scripts/debug.pory"

# 430 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Freeze:
# 431 "data/scripts/debug.pory"
	setstatus1 STATUS1_FREEZE, PARTY_SIZE
# 432 "data/scripts/debug.pory"
	releaseall
# 433 "data/scripts/debug.pory"
	end
# 434 "data/scripts/debug.pory"

# 435 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Frostbite:
# 436 "data/scripts/debug.pory"
	setstatus1 STATUS1_FROSTBITE, PARTY_SIZE
# 437 "data/scripts/debug.pory"
	releaseall
# 438 "data/scripts/debug.pory"
	end
# 439 "data/scripts/debug.pory"

# 440 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Single:
# 441 "data/scripts/debug.pory"
	.string "Single$"
# 442 "data/scripts/debug.pory"

# 443 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_PartyWide:
# 444 "data/scripts/debug.pory"
	.string "Party-wide$"
# 445 "data/scripts/debug.pory"

# 446 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Close:
# 447 "data/scripts/debug.pory"
	.string "Close$"
# 448 "data/scripts/debug.pory"

# 449 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Poison:
# 450 "data/scripts/debug.pory"
	.string "Poison$"
# 451 "data/scripts/debug.pory"

# 452 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Paralysis:
# 453 "data/scripts/debug.pory"
	.string "Paralysis$"
# 454 "data/scripts/debug.pory"

# 455 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Sleep:
# 456 "data/scripts/debug.pory"
	.string "Sleep$"
# 457 "data/scripts/debug.pory"

# 458 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Burn:
# 459 "data/scripts/debug.pory"
	.string "Burn$"
# 460 "data/scripts/debug.pory"

# 461 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Freeze:
# 462 "data/scripts/debug.pory"
	.string "Freeze$"
# 463 "data/scripts/debug.pory"

# 464 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Frostbite:
# 465 "data/scripts/debug.pory"
	.string "Frostbite$"
# 466 "data/scripts/debug.pory"

# 467 "data/scripts/debug.pory"
Debug_EventScript_EWRAMCounters::
# 468 "data/scripts/debug.pory"
	callnative CheckEWRAMCounters
# 469 "data/scripts/debug.pory"
	msgbox Debug_EventScript_EWRAMCounters_Text, MSGBOX_DEFAULT
# 470 "data/scripts/debug.pory"
	release
# 471 "data/scripts/debug.pory"
	end
# 472 "data/scripts/debug.pory"

# 473 "data/scripts/debug.pory"
Debug_EventScript_EWRAMCounters_Text::
# 474 "data/scripts/debug.pory"
	.string "Follower Steps: {STR_VAR_1}.\n"
# 475 "data/scripts/debug.pory"
	.string "Fishing Chain: {STR_VAR_2}.$"

Debug_EventScript_Script_1_Text_0:
# 147 "data/scripts/debug.pory"
	.string "Forwards to 8am$"

Debug_EventScript_Script_2_Text_0:
# 154 "data/scripts/debug.pory"
	.string "Forwards to 12NN$"

Debug_EventScript_Script_3_Text_0:
# 162 "data/scripts/debug.pory"
	.string "Forwards to 2pm$"

Debug_EventScript_Script_4_Text_0:
# 170 "data/scripts/debug.pory"
	.string "Forwards to 5AM$"
