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
	release
	end


Debug_EventScript_Script_2::
# 151 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_3::
# 156 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_4::
# 161 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_5::
# 166 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_6::
# 171 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_7::
# 176 "data/scripts/debug.pory"
	release
	end


Debug_EventScript_Script_8::
# 181 "data/scripts/debug.pory"
	release
	end


# 185 "data/scripts/debug.pory"

# 186 "data/scripts/debug.pory"
Debug_CheckSaveBlock::
# 187 "data/scripts/debug.pory"
	callnative CheckSaveBlock1Size
# 188 "data/scripts/debug.pory"
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
# 189 "data/scripts/debug.pory"
	callnative CheckSaveBlock2Size
# 190 "data/scripts/debug.pory"
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
# 191 "data/scripts/debug.pory"
	callnative CheckSaveBlock3Size
# 192 "data/scripts/debug.pory"
	msgbox Debug_SaveBlock3Size, MSGBOX_DEFAULT
# 193 "data/scripts/debug.pory"
	callnative CheckPokemonStorageSize
# 194 "data/scripts/debug.pory"
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
# 195 "data/scripts/debug.pory"
	release
# 196 "data/scripts/debug.pory"
	end
# 197 "data/scripts/debug.pory"

# 198 "data/scripts/debug.pory"
Debug_SaveBlock1Size::
# 199 "data/scripts/debug.pory"
	.string "SaveBlock1 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 200 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 201 "data/scripts/debug.pory"

# 202 "data/scripts/debug.pory"
Debug_SaveBlock2Size::
# 203 "data/scripts/debug.pory"
	.string "SaveBlock2 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 204 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 205 "data/scripts/debug.pory"

# 206 "data/scripts/debug.pory"
Debug_SaveBlock3Size::
# 207 "data/scripts/debug.pory"
	.string "SaveBlock3 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 208 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 209 "data/scripts/debug.pory"

# 210 "data/scripts/debug.pory"
Debug_PokemonStorageSize::
# 211 "data/scripts/debug.pory"
	.string "{PKMN}Storage size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
# 212 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_3}b.$"
# 213 "data/scripts/debug.pory"

# 214 "data/scripts/debug.pory"
Debug_CheckROMSpace::
# 215 "data/scripts/debug.pory"
	callnative CheckROMSize
# 216 "data/scripts/debug.pory"
	msgbox Debug_ROMSize, MSGBOX_DEFAULT
# 217 "data/scripts/debug.pory"
	release
# 218 "data/scripts/debug.pory"
	end
# 219 "data/scripts/debug.pory"

# 220 "data/scripts/debug.pory"
Debug_ROMSize::
# 221 "data/scripts/debug.pory"
	.string "ROM size: {STR_VAR_1}MB/32MB.\n"
# 222 "data/scripts/debug.pory"
	.string "Free space: {STR_VAR_2}MB.$"
# 223 "data/scripts/debug.pory"

# 224 "data/scripts/debug.pory"
Debug_HatchAnEgg::
# 225 "data/scripts/debug.pory"
	lockall
# 226 "data/scripts/debug.pory"
	getpartysize
# 227 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
# 228 "data/scripts/debug.pory"
	special ChoosePartyMon
# 229 "data/scripts/debug.pory"
	waitstate
# 230 "data/scripts/debug.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_HatchAnEgg_End
# 231 "data/scripts/debug.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 232 "data/scripts/debug.pory"
	goto_if_ne VAR_RESULT, SPECIES_EGG, DebugScript_HatchAnEgg_CantForceHatch
# 233 "data/scripts/debug.pory"
	special EggHatch
# 234 "data/scripts/debug.pory"
	waitstate
# 235 "data/scripts/debug.pory"
Debug_HatchAnEgg_End::
# 236 "data/scripts/debug.pory"
	releaseall
# 237 "data/scripts/debug.pory"
	end
# 238 "data/scripts/debug.pory"

# 239 "data/scripts/debug.pory"
Debug_NoPokemon::
# 240 "data/scripts/debug.pory"
	msgbox DebugScript_Text_EmptyParty, MSGBOX_DEFAULT
# 241 "data/scripts/debug.pory"
	releaseall
# 242 "data/scripts/debug.pory"
	end
# 243 "data/scripts/debug.pory"

# 244 "data/scripts/debug.pory"
DebugScript_HatchAnEgg_CantForceHatch::
# 245 "data/scripts/debug.pory"
	msgbox DebugScript_HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
# 246 "data/scripts/debug.pory"
	releaseall
# 247 "data/scripts/debug.pory"
	end
# 248 "data/scripts/debug.pory"

# 249 "data/scripts/debug.pory"
DebugScript_Text_EmptyParty::
# 250 "data/scripts/debug.pory"
	.string "You have no Pokémon nor Eggs.$"
# 251 "data/scripts/debug.pory"

# 252 "data/scripts/debug.pory"
DebugScript_HatchAnEgg_Text_NotAnEgg::
# 253 "data/scripts/debug.pory"
	.string "That's not a Pokémon Egg.$"
# 254 "data/scripts/debug.pory"

# 255 "data/scripts/debug.pory"
DebugScript_ZeroDaycareMons::
# 256 "data/scripts/debug.pory"
	msgbox DebugText_DaycareNoPokemon, MSGBOX_DEFAULT
# 257 "data/scripts/debug.pory"
	releaseall
# 258 "data/scripts/debug.pory"
	end
# 259 "data/scripts/debug.pory"

# 260 "data/scripts/debug.pory"
DebugScript_OneDaycareMons::
# 261 "data/scripts/debug.pory"
	msgbox DebugText_DaycareOnePokemon, MSGBOX_DEFAULT
# 262 "data/scripts/debug.pory"
	releaseall
# 263 "data/scripts/debug.pory"
	end
# 264 "data/scripts/debug.pory"

# 265 "data/scripts/debug.pory"
DebugScript_DaycareMonsNotCompatible::
# 266 "data/scripts/debug.pory"
	msgbox DebugText_DaycarePokemonNotCompatible, MSGBOX_DEFAULT
# 267 "data/scripts/debug.pory"
	releaseall
# 268 "data/scripts/debug.pory"
	end
# 269 "data/scripts/debug.pory"

# 270 "data/scripts/debug.pory"
DebugText_DaycareNoPokemon:
# 271 "data/scripts/debug.pory"
	.string "You have no Pokémon at Daycare.$"
# 272 "data/scripts/debug.pory"

# 273 "data/scripts/debug.pory"
DebugText_DaycareOnePokemon:
# 274 "data/scripts/debug.pory"
	.string "You have only one Pokémon at Daycare.$"
# 275 "data/scripts/debug.pory"

# 276 "data/scripts/debug.pory"
DebugText_DaycarePokemonNotCompatible:
# 277 "data/scripts/debug.pory"
	.string "Your Pokémon at Daycare can't\nhave babies together!$"
# 278 "data/scripts/debug.pory"

# 279 "data/scripts/debug.pory"
Debug_ShowExpansionVersion::
# 280 "data/scripts/debug.pory"
	callnative BufferExpansionVersion
# 281 "data/scripts/debug.pory"
	msgbox Debug_ExpansionVersion, MSGBOX_DEFAULT
# 282 "data/scripts/debug.pory"
	release
# 283 "data/scripts/debug.pory"
	end
# 284 "data/scripts/debug.pory"

# 285 "data/scripts/debug.pory"
Debug_ExpansionVersion:
# 286 "data/scripts/debug.pory"
	.string "pokeemerald-expansion {STR_VAR_1}$"
# 287 "data/scripts/debug.pory"

# 288 "data/scripts/debug.pory"
Debug_BerryPestsDisabled::
# 289 "data/scripts/debug.pory"
	msgbox DebugText_BerryPestsDisabled, MSGBOX_DEFAULT
# 290 "data/scripts/debug.pory"
	release
# 291 "data/scripts/debug.pory"
	end
# 292 "data/scripts/debug.pory"

# 293 "data/scripts/debug.pory"
DebugText_BerryPestsDisabled:
# 294 "data/scripts/debug.pory"
	.string "OW_BERRY_PESTS is disabled.\n"
# 295 "data/scripts/debug.pory"
	.string "Unable to force pests onto berry trees.$"
# 296 "data/scripts/debug.pory"

# 297 "data/scripts/debug.pory"
Debug_BerryWeedsDisabled::
# 298 "data/scripts/debug.pory"
	msgbox DebugText_BerryWeedsDisabled, MSGBOX_DEFAULT
# 299 "data/scripts/debug.pory"
	release
# 300 "data/scripts/debug.pory"
	end
# 301 "data/scripts/debug.pory"

# 302 "data/scripts/debug.pory"
DebugText_BerryWeedsDisabled:
# 303 "data/scripts/debug.pory"
	.string "OW_BERRY_WEEDS is disabled.\n"
# 304 "data/scripts/debug.pory"
	.string "Unable to force weeds onto berry trees.$"
# 305 "data/scripts/debug.pory"

# 306 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1::
# 307 "data/scripts/debug.pory"
	lockall
# 308 "data/scripts/debug.pory"
	getpartysize
# 309 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
# 310 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
# 311 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
# 312 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
# 313 "data/scripts/debug.pory"
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
# 314 "data/scripts/debug.pory"
	switch VAR_RESULT
# 315 "data/scripts/debug.pory"
	case 0, Debug_EventScript_InflictStatus1_Single
# 316 "data/scripts/debug.pory"
	case 1, Debug_EventScript_InflictStatus1_Party
# 317 "data/scripts/debug.pory"
	case 2, Debug_EventScript_InflictStatus1_Close
# 318 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Close:
# 319 "data/scripts/debug.pory"
	releaseall
# 320 "data/scripts/debug.pory"
	end
# 321 "data/scripts/debug.pory"

# 322 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single:
# 323 "data/scripts/debug.pory"
	special ChoosePartyMon
# 324 "data/scripts/debug.pory"
	waitstate
# 325 "data/scripts/debug.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
# 326 "data/scripts/debug.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 327 "data/scripts/debug.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
# 328 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
# 329 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
# 330 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
# 331 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
# 332 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
# 333 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
# 334 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
# 335 "data/scripts/debug.pory"
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
# 336 "data/scripts/debug.pory"
	switch VAR_RESULT
# 337 "data/scripts/debug.pory"
	case 0, Debug_EventScript_InflictStatus1_Single_Poison
# 338 "data/scripts/debug.pory"
	case 1, Debug_EventScript_InflictStatus1_Single_Paralysis
# 339 "data/scripts/debug.pory"
	case 2, Debug_EventScript_InflictStatus1_Single_Sleep
# 340 "data/scripts/debug.pory"
	case 3, Debug_EventScript_InflictStatus1_Single_Burn
# 341 "data/scripts/debug.pory"
	case 4, Debug_EventScript_InflictStatus1_Single_Freeze
# 342 "data/scripts/debug.pory"
	case 5, Debug_EventScript_InflictStatus1_Single_Frostbite
# 343 "data/scripts/debug.pory"
	case 6, Debug_EventScript_InflictStatus1_Close
# 344 "data/scripts/debug.pory"
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
# 345 "data/scripts/debug.pory"
	releaseall
# 346 "data/scripts/debug.pory"
	end
# 347 "data/scripts/debug.pory"

# 348 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Poison:
# 349 "data/scripts/debug.pory"
	setstatus1 STATUS1_POISON, VAR_0x8004
# 350 "data/scripts/debug.pory"
	releaseall
# 351 "data/scripts/debug.pory"
	end
# 352 "data/scripts/debug.pory"

# 353 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Paralysis:
# 354 "data/scripts/debug.pory"
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
# 355 "data/scripts/debug.pory"
	releaseall
# 356 "data/scripts/debug.pory"
	end
# 357 "data/scripts/debug.pory"

# 358 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Sleep:
# 359 "data/scripts/debug.pory"
	setstatus1 STATUS1_SLEEP, VAR_0x8004
# 360 "data/scripts/debug.pory"
	releaseall
# 361 "data/scripts/debug.pory"
	end
# 362 "data/scripts/debug.pory"

# 363 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Burn:
# 364 "data/scripts/debug.pory"
	setstatus1 STATUS1_BURN, VAR_0x8004
# 365 "data/scripts/debug.pory"
	releaseall
# 366 "data/scripts/debug.pory"
	end
# 367 "data/scripts/debug.pory"

# 368 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Freeze:
# 369 "data/scripts/debug.pory"
	setstatus1 STATUS1_FREEZE, VAR_0x8004
# 370 "data/scripts/debug.pory"
	releaseall
# 371 "data/scripts/debug.pory"
	end
# 372 "data/scripts/debug.pory"

# 373 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Single_Frostbite:
# 374 "data/scripts/debug.pory"
	setstatus1 STATUS1_FROSTBITE, VAR_0x8004
# 375 "data/scripts/debug.pory"
	releaseall
# 376 "data/scripts/debug.pory"
	end
# 377 "data/scripts/debug.pory"

# 378 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party:
# 379 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
# 380 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
# 381 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
# 382 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
# 383 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
# 384 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
# 385 "data/scripts/debug.pory"
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
# 386 "data/scripts/debug.pory"
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
# 387 "data/scripts/debug.pory"
	switch VAR_RESULT
# 388 "data/scripts/debug.pory"
	case 0, Debug_EventScript_InflictStatus1_Party_Poison
# 389 "data/scripts/debug.pory"
	case 1, Debug_EventScript_InflictStatus1_Party_Paralysis
# 390 "data/scripts/debug.pory"
	case 2, Debug_EventScript_InflictStatus1_Party_Sleep
# 391 "data/scripts/debug.pory"
	case 3, Debug_EventScript_InflictStatus1_Party_Burn
# 392 "data/scripts/debug.pory"
	case 4, Debug_EventScript_InflictStatus1_Party_Freeze
# 393 "data/scripts/debug.pory"
	case 5, Debug_EventScript_InflictStatus1_Party_Frostbite
# 394 "data/scripts/debug.pory"
	case 6, Debug_EventScript_InflictStatus1_Close
# 395 "data/scripts/debug.pory"
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
# 396 "data/scripts/debug.pory"
	releaseall
# 397 "data/scripts/debug.pory"
	end
# 398 "data/scripts/debug.pory"

# 399 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Poison:
# 400 "data/scripts/debug.pory"
	setstatus1 STATUS1_POISON, PARTY_SIZE
# 401 "data/scripts/debug.pory"
	releaseall
# 402 "data/scripts/debug.pory"
	end
# 403 "data/scripts/debug.pory"

# 404 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Paralysis:
# 405 "data/scripts/debug.pory"
	setstatus1 STATUS1_PARALYSIS, PARTY_SIZE
# 406 "data/scripts/debug.pory"
	releaseall
# 407 "data/scripts/debug.pory"
	end
# 408 "data/scripts/debug.pory"

# 409 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Sleep:
# 410 "data/scripts/debug.pory"
	setstatus1 STATUS1_SLEEP, PARTY_SIZE
# 411 "data/scripts/debug.pory"
	releaseall
# 412 "data/scripts/debug.pory"
	end
# 413 "data/scripts/debug.pory"

# 414 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Burn:
# 415 "data/scripts/debug.pory"
	setstatus1 STATUS1_BURN, PARTY_SIZE
# 416 "data/scripts/debug.pory"
	releaseall
# 417 "data/scripts/debug.pory"
	end
# 418 "data/scripts/debug.pory"

# 419 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Freeze:
# 420 "data/scripts/debug.pory"
	setstatus1 STATUS1_FREEZE, PARTY_SIZE
# 421 "data/scripts/debug.pory"
	releaseall
# 422 "data/scripts/debug.pory"
	end
# 423 "data/scripts/debug.pory"

# 424 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Party_Frostbite:
# 425 "data/scripts/debug.pory"
	setstatus1 STATUS1_FROSTBITE, PARTY_SIZE
# 426 "data/scripts/debug.pory"
	releaseall
# 427 "data/scripts/debug.pory"
	end
# 428 "data/scripts/debug.pory"

# 429 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Single:
# 430 "data/scripts/debug.pory"
	.string "Single$"
# 431 "data/scripts/debug.pory"

# 432 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_PartyWide:
# 433 "data/scripts/debug.pory"
	.string "Party-wide$"
# 434 "data/scripts/debug.pory"

# 435 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Close:
# 436 "data/scripts/debug.pory"
	.string "Close$"
# 437 "data/scripts/debug.pory"

# 438 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Poison:
# 439 "data/scripts/debug.pory"
	.string "Poison$"
# 440 "data/scripts/debug.pory"

# 441 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Paralysis:
# 442 "data/scripts/debug.pory"
	.string "Paralysis$"
# 443 "data/scripts/debug.pory"

# 444 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Sleep:
# 445 "data/scripts/debug.pory"
	.string "Sleep$"
# 446 "data/scripts/debug.pory"

# 447 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Burn:
# 448 "data/scripts/debug.pory"
	.string "Burn$"
# 449 "data/scripts/debug.pory"

# 450 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Freeze:
# 451 "data/scripts/debug.pory"
	.string "Freeze$"
# 452 "data/scripts/debug.pory"

# 453 "data/scripts/debug.pory"
Debug_EventScript_InflictStatus1_Text_Frostbite:
# 454 "data/scripts/debug.pory"
	.string "Frostbite$"
# 455 "data/scripts/debug.pory"

# 456 "data/scripts/debug.pory"
Debug_EventScript_EWRAMCounters::
# 457 "data/scripts/debug.pory"
	callnative CheckEWRAMCounters
# 458 "data/scripts/debug.pory"
	msgbox Debug_EventScript_EWRAMCounters_Text, MSGBOX_DEFAULT
# 459 "data/scripts/debug.pory"
	release
# 460 "data/scripts/debug.pory"
	end
# 461 "data/scripts/debug.pory"

# 462 "data/scripts/debug.pory"
Debug_EventScript_EWRAMCounters_Text::
# 463 "data/scripts/debug.pory"
	.string "Follower Steps: {STR_VAR_1}.\n"
# 464 "data/scripts/debug.pory"
	.string "Fishing Chain: {STR_VAR_2}.$"

Debug_EventScript_FontTest_Text_1::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Angel Adept Blind Bodice Clique\n"
	.string "Coast Dunce Docile Enact Eosin\l"
	.string "Furlong Focal Gnome Gondola Human\l"
	.string "Hoist Inlet Iodine Justin Jocose\l"
	.string "Knoll Koala Linden Loads Milliner\l"
	.string "Modal Number Nodule Onset Oddball\l"
	.string "Pneumo Poncho Quanta Qophs Rhone\l"
	.string "Roman Snout Sodium Tundra Tocsin\l"
	.string "Uncle Udder Vulcan Vocal Whale\l"
	.string "Woman Xmas Xenon Yunnan Young\l"
	.string "Zloty Zodiac.$"

Debug_EventScript_FontTest_Text_2::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Angel angel adept for the nuance loads\n"
	.string "of the arena cocoa and quaalude. Blind\l"
	.string "blind bodice for the submit oboe of the\l"
	.string "club snob and abbot. Clique clique\l"
	.string "coast for the pouch loco of the franc\l"
	.string "assoc and accede. Dunce dunce docile\l"
	.string "for the loudness mastodon of the\l"
	.string "loud statehood and huddle.$"

Debug_EventScript_FontTest_Text_3::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Enact enact eosin for the quench coed\n"
	.string "of the pique canoe and bleep. Furlong\l"
	.string "furlong focal for the genuflect\l"
	.string "profound of the motif aloof and offers.\l"
	.string "Gnome gnome gondola for the impugn\l"
	.string "logos of the unplug analog and smuggle.\l"
	.string "Human human hoist for the buddhist\l"
	.string "alcohol of the riyadh caliph and\l"
	.string "bathhouse.$"

Debug_EventScript_FontTest_Text_4::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Inlet inlet iodine for the quince\n"
	.string "champion of the ennui scampi and shiite.\l"
	.string "Justin justin jocose for the djibouti\l"
	.string "sojourn of the oranj raj and hajjis.\l"
	.string "Knoll knoll koala for the banknote\l"
	.string "lookout of the dybbuk outlook and\l"
	.string "trekked. Linden linden loads for the\l"
	.string "ulna monolog of the consul menthol and\l"
	.string "shallot.$"

Debug_EventScript_FontTest_Text_5::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Milliner milliner modal for the alumna\n"
	.string "solomon of the album custom and summon.\l"
	.string "Number number nodule for the unmade\l"
	.string "economic of the shotgun bison and\l"
	.string "tunnel. Onset onset oddball for the\l"
	.string "abandon podium of the antiquo tempo\l"
	.string "and moonlit. Pneumo pneumo poncho for\l"
	.string "the dauphin opossum of the holdup\l"
	.string "bishop and supplies.$"

Debug_EventScript_FontTest_Text_6::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Quanta quanta qophs for the inquest\n"
	.string "sheqel of the cinq coq and suqqu. Rhone\l"
	.string "rhone roman for the burnt porous of the\l"
	.string "lemur clamor and carrot. Snout snout\l"
	.string "sodium for the ensnare bosom of the\l"
	.string "genus pathos and missing. Tundra\l"
	.string "tundra tocsin for the nutmeg isotope\l"
	.string "of the peasant ingot and ottoman.$"

Debug_EventScript_FontTest_Text_7::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Uncle uncle udder for the dunes cloud\n"
	.string "of the hindu thou and continuum. Vulcan\l"
	.string "vulcan vocal for the alluvial ovoid of\l"
	.string "the yugoslav chekhov and revved. Whale\l"
	.string "whale woman for the meanwhile blowout\l"
	.string "of the forepaw meadow and glowworm.\l"
	.string "Xmas xmas xenon for the bauxite\l"
	.string "doxology of the tableaux equinox and\l"
	.string "exxon.$"

Debug_EventScript_FontTest_Text_8::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Yunnan yunnan young for the dynamo\n"
	.string "coyote of the obloquy employ and\l"
	.string "sayyid. Zloty zloty zodiac for the gizmo\l"
	.string "ozone of the franz laissez and buzzing.$"


Debug_EventScript_FontTest_Text_9::                 @ Special thanks to Nintendo for this nice pangram to test other glyphs
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "42 × 138 = 5796.\n"
	.string "Mr Jock, TV quiz PhD: bags 20% fewer\l"
	.string "lynx at a café; voilà, they're “worth”\l"
	.string "♂1/♀1 = ¥1. That's 10 + 9 - 8 = 11\l"
	.string "Nintendo GBA can connect to a Nintendo\l"
	.string "GameCube console! He claimed-though I don't\l"
	.string "believe him-to have done so in an eyes-shut\l"
	.string "state…?$"

Debug_PrintFontTest::
	msgbox Debug_EventScript_FontTest_Text_1, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_2, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_3, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_4, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_5, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_6, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_7, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_8, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_9, MSGBOX_DEFAULT
	releaseall
	end

Debug_EventScript_FontTest::
	lockall
	goto Debug_PrintFontTest
@	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
@	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
@	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
@	switch VAR_RESULT
@	case 0, Debug_EventScript_InflictStatus1_Single
@	case 1, Debug_EventScript_InflictStatus1_Party
@	case 2, Debug_EventScript_InflictStatus1_Close
@Debug_EventScript_InflictStatus1_Close:
@	releaseall
@	end
