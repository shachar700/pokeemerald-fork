KuraTown_MapScripts::
# 4 "data/maps/KuraTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 10 "data/maps/KuraTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD
# 7 "data/maps/KuraTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KuraTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/KuraTown/scripts.pory"
	call KuraVillage_NPCSchedules
	return

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 12 "data/maps/KuraTown/scripts.pory"
	goto_if_set FLAG_KURA_DOJO_CLOSED, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_2
KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 15 "data/maps/KuraTown/scripts.pory"
	call KuraVillage_DrawMetatiles
	return

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 13 "data/maps/KuraTown/scripts.pory"
	setmetatile 40, 16, METATILE_SakuKura_ClosedDojoDoor, TRUE
	goto KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_1

KuraTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	.2byte 0


KuraTown_EventScript_GuardStopsYou::
# 20 "data/maps/KuraTown/scripts.pory"
	lock
# 22 "data/maps/KuraTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 24 "data/maps/KuraTown/scripts.pory"
	compare VAR_TEMP_0, 14
	goto_if_le KuraTown_EventScript_GuardStopsYou_2
# 33 "data/maps/KuraTown/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterRight
# 34 "data/maps/KuraTown/scripts.pory"
	waitmovement 0
# 35 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_GuardStopsYou_Text_0
# 36 "data/maps/KuraTown/scripts.pory"
	closemessage
# 37 "data/maps/KuraTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 38 "data/maps/KuraTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
KuraTown_EventScript_GuardStopsYou_1:
# 40 "data/maps/KuraTown/scripts.pory"
	delay 20
# 42 "data/maps/KuraTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 1
	goto_if_eq KuraTown_EventScript_GuardStopsYou_6
# 50 "data/maps/KuraTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto_if_eq KuraTown_EventScript_GuardStopsYou_7
KuraTown_EventScript_GuardStopsYou_5:
# 59 "data/maps/KuraTown/scripts.pory"
	release
	return

KuraTown_EventScript_GuardStopsYou_2:
# 25 "data/maps/KuraTown/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
# 26 "data/maps/KuraTown/scripts.pory"
	waitmovement 0
# 27 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_GuardStopsYou_Text_0
# 28 "data/maps/KuraTown/scripts.pory"
	closemessage
# 29 "data/maps/KuraTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 30 "data/maps/KuraTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto KuraTown_EventScript_GuardStopsYou_1

KuraTown_EventScript_GuardStopsYou_6:
# 43 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_GuardStopsYou_Text_1
# 48 "data/maps/KuraTown/scripts.pory"
	closemessage
# 49 "data/maps/KuraTown/scripts.pory"
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto KuraTown_EventScript_GuardStopsYou_5

KuraTown_EventScript_GuardStopsYou_7:
# 51 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_GuardStopsYou_Text_2
# 56 "data/maps/KuraTown/scripts.pory"
	closemessage
# 57 "data/maps/KuraTown/scripts.pory"
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 3
	goto KuraTown_EventScript_GuardStopsYou_5


KuraTown_EventScript_DojoChallenger::
# 63 "data/maps/KuraTown/scripts.pory"
	lock
# 64 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 65 "data/maps/KuraTown/scripts.pory"
	goto_if_set FLAG_KURA_DOJO_CLOSED, KuraTown_EventScript_DojoChallenger_2
# 74 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_DojoChallenger_Text_1
KuraTown_EventScript_DojoChallenger_1:
# 83 "data/maps/KuraTown/scripts.pory"
	closemessage
# 84 "data/maps/KuraTown/scripts.pory"
	release
	return

KuraTown_EventScript_DojoChallenger_2:
# 66 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_DojoChallenger_Text_0
	goto KuraTown_EventScript_DojoChallenger_1


KuraTown_EventScript_Farmer::
# 88 "data/maps/KuraTown/scripts.pory"
	lock
# 89 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 90 "data/maps/KuraTown/scripts.pory"
	speakername KuraTown_EventScript_Farmer_Text_0
# 91 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_Farmer_Text_1, MSGBOX_DEFAULT
# 98 "data/maps/KuraTown/scripts.pory"
	release
	return


KuraTown_EventScript_FarmerScyther::
# 102 "data/maps/KuraTown/scripts.pory"
	lock
# 103 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 104 "data/maps/KuraTown/scripts.pory"
	speakername KuraTown_EventScript_Farmer_Text_0
# 105 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_FarmerScyther_Text_0, MSGBOX_DEFAULT
# 111 "data/maps/KuraTown/scripts.pory"
	release
	return


KuraTown_EventScript_Scyther::
# 115 "data/maps/KuraTown/scripts.pory"
	lock
# 116 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 117 "data/maps/KuraTown/scripts.pory"
	playmoncry SPECIES_SCYTHER, CRY_MODE_NORMAL
# 118 "data/maps/KuraTown/scripts.pory"
	speakername KuraTown_EventScript_Scyther_Text_0
# 119 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_Scyther_Text_1
# 120 "data/maps/KuraTown/scripts.pory"
	waitmoncry
# 121 "data/maps/KuraTown/scripts.pory"
	closemessage
# 122 "data/maps/KuraTown/scripts.pory"
	release
	return


KuraTown_EventScript_Guard::
# 126 "data/maps/KuraTown/scripts.pory"
	lock
# 127 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 128 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_Guard_Text_0, MSGBOX_DEFAULT
# 136 "data/maps/KuraTown/scripts.pory"
	release
	return


SakuTown_EventScript_ClosedGymDoor::
# 141 "data/maps/KuraTown/scripts.pory"
	goto_if_set FLAG_KURA_DOJO_CLOSED, SakuTown_EventScript_ClosedGymDoor_1
	return

SakuTown_EventScript_ClosedGymDoor_1:
# 142 "data/maps/KuraTown/scripts.pory"
	msgbox SakuTown_EventScript_ClosedGymDoor_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_TownSign::
# 150 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_TrainerTips::
# 154 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_DirectionsSign::
# 158 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_GymSign::
# 162 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_GymSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_GuardStopsYou_Text_0:
# 27 "data/maps/KuraTown/scripts.pory"
	.string "Hey!$"

KuraTown_EventScript_GuardStopsYou_Text_1:
# 44 "data/maps/KuraTown/scripts.pory"
	.string "You think I don't see you trying to\n"
	.string "sneak in from Saku Village?\p"
	.string "…Wait, you're a regular traveler,\n"
	.string "aren't you…\p"
	.string "Welcome to Kura Village then!$"

KuraTown_EventScript_GuardStopsYou_Text_2:
# 52 "data/maps/KuraTown/scripts.pory"
	.string "You're not trying to sneak into Saku\n"
	.string "Village, are you?\p"
	.string "…My bad, you're that traveler again.\n"
	.string "Didn't recognize ya.\p"
	.string "You can go through, though I'm not\n"
	.string "sure why you'd want to.$"

KuraTown_EventScript_DojoChallenger_Text_0:
# 68 "data/maps/KuraTown/scripts.pory"
	.string "Looks like the dojo is closed again…\p"
	.string "Gah, when will I get a chance to crush\n"
	.string "Hana in a fiery battle?\p"
	.string "Could it be that she is scared of me?$"

KuraTown_EventScript_DojoChallenger_Text_1:
# 76 "data/maps/KuraTown/scripts.pory"
	.string "The dojo is open! I can finally defeat\n"
	.string "its leader in a fiery battle!\p"
	.string "…Hm? When, you ask?\p"
	.string "In… In a minute…\p"
	.string "No, go right ahead, I'm just…\n"
	.string "preparing…$"

KuraTown_EventScript_Farmer_Text_0:
# 90 "data/maps/KuraTown/scripts.pory"
	.string "Farmer$"

KuraTown_EventScript_Farmer_Text_1:
# 93 "data/maps/KuraTown/scripts.pory"
	.string "Why do we hate the Saku Village folks,\n"
	.string "y'ask?\p"
	.string "To be honest, I don't quite rememb'r.\n"
	.string "But who needs a reas'n, right?$"

KuraTown_EventScript_FarmerScyther_Text_0:
# 107 "data/maps/KuraTown/scripts.pory"
	.string "Our Scyther harvest the crops once\n"
	.string "they've grown.$"

KuraTown_EventScript_Scyther_Text_0:
# 118 "data/maps/KuraTown/scripts.pory"
	.string "Scyther$"

KuraTown_EventScript_Scyther_Text_1:
# 119 "data/maps/KuraTown/scripts.pory"
	.string "Gyooo!$"

KuraTown_EventScript_Guard_Text_0:
# 130 "data/maps/KuraTown/scripts.pory"
	.string "Hope you didn't have too much trouble\n"
	.string "passing the gate.\p"
	.string "That Saku Village guard is such a\n"
	.string "jerk, he won't let anyone from our\l"
	.string "village cross to theirs.\p"
	.string "So of course we're not gonna let\n"
	.string "anyone from theirs in ours! Hah!$"

SakuTown_EventScript_ClosedGymDoor_Text_0:
# 143 "data/maps/KuraTown/scripts.pory"
	.string "“BE BACK SOON\n"
	.string "- Hana”$"

KuraTown_EventScript_TownSign_Text_0:
# 150 "data/maps/KuraTown/scripts.pory"
	.string "Kura Village\n"
	.string "“A village where the mountains meet\l"
	.string "the woods.”$"

KuraTown_EventScript_TrainerTips_Text_0:
# 154 "data/maps/KuraTown/scripts.pory"
	.string "Did you know?\p"
	.string "The people from Saku Village can and\n"
	.string "will eat your children!$"

KuraTown_EventScript_DirectionsSign_Text_0:
# 158 "data/maps/KuraTown/scripts.pory"
	.string "{UP_ARROW} Silver Tunnel\n"
	.string "This way for Silveridge$"

KuraTown_EventScript_GymSign_Text_0:
# 164 "data/maps/KuraTown/scripts.pory"
	.string "Kura Village Pokémon Dojo\n"
	.string "Leader: Hana\p"
	.string "“Strong as a maple rooted in wisdom.”$"
