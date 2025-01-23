MaguroHarbor_Dojo_MapScripts::
	.byte 0


MaguroHarbor_Dojo_EventScript_Koishi::
# 8 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	trainerbattle_single TRAINER_KOISHI_1, MaguroHarbor_Dojo_EventScript_Koishi_Text_0, MaguroHarbor_Dojo_EventScript_Koishi_Text_1, MaguroHarbor_Dojo_EventScript_KoishiDefeated, NO_MUSIC
# 24 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_Koishi_Text_2
	end


MaguroHarbor_Dojo_EventScript_KoishiDefeated::
# 31 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	message MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_0
# 34 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	waitmessage
# 35 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 36 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_1, MSGBOX_DEFAULT
# 45 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	giveitem ITEM_TM_WATER_PULSE
# 47 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_2, MSGBOX_DEFAULT
# 55 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	closemessage
# 57 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setflag FLAG_BADGE01_GET
# 58 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setvar VAR_0x8008, 1
# 59 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 60 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	addvar VAR_PLAYER_REPUTATION, 5
# 62 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 1
# 64 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setflag FLAG_KURA_DOJO_CLOSED
# 66 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	clearflag FLAG_HIDE_BONSAI_SHOP_OWNER
# 75 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	delay 48
# 78 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setvar VAR_0x8004, 1
# 79 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setvar VAR_0x8005, 2
# 80 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setvar VAR_0x8006, 40
# 81 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setvar VAR_0x8007, 4
# 82 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	special ShakeCamera
# 83 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	delay 16
# 84 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	playse SE_PIN
# 85 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 86 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	delay 16
# 87 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	playse SE_PIN
# 88 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 89 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	waitstate
# 90 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 91 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	waitmovement 4
# 92 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	delay 60
# 94 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	speakername MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_3
# 95 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_4
# 99 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	closemessage
# 101 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 102 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq MaguroHarbor_Dojo_EventScript_KoishiDefeated_2
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	applymovement 4, MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_1
MaguroHarbor_Dojo_EventScript_KoishiDefeated_1:
# 107 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	waitmovement 4
# 108 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	removeobject 4
# 109 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	setflag FLAG_HIDE_KOISHI
# 111 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	release
	end

MaguroHarbor_Dojo_EventScript_KoishiDefeated_2:
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	applymovement 4, MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_0
	goto MaguroHarbor_Dojo_EventScript_KoishiDefeated_1


MaguroHarbor_Dojo_EventScript_Izumi::
# 118 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	trainerbattle_single TRAINER_IZUMI, MaguroHarbor_Dojo_EventScript_Izumi_Text_0, MaguroHarbor_Dojo_EventScript_Izumi_Text_1
# 123 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_Izumi_Text_2, MSGBOX_AUTOCLOSE
	return


MaguroHarbor_Dojo_EventScript_Ren::
# 129 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	trainerbattle_single TRAINER_REN, MaguroHarbor_Dojo_EventScript_Ren_Text_0, MaguroHarbor_Dojo_EventScript_Ren_Text_1
# 134 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_Ren_Text_2, MSGBOX_AUTOCLOSE
	return


MaguroHarbor_Dojo_EventScript_Mizu::
# 140 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	trainerbattle_single TRAINER_MIZU, MaguroHarbor_Dojo_EventScript_Mizu_Text_0, MaguroHarbor_Dojo_EventScript_Mizu_Text_1
# 145 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_Mizu_Text_2, MSGBOX_AUTOCLOSE
	return


MaguroHarbor_Dojo_EventScript_Advice::
# 152 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	lock
# 153 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	faceplayer
# 154 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, MaguroHarbor_Dojo_EventScript_Advice_2
# 159 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_Advice_Text_1
MaguroHarbor_Dojo_EventScript_Advice_1:
# 167 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	release
	return

MaguroHarbor_Dojo_EventScript_Advice_2:
# 155 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_Advice_Text_0
	goto MaguroHarbor_Dojo_EventScript_Advice_1


MaguroHarbor_Dojo_EventScript_DojoStatue::
# 171 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	lockall
# 172 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, MaguroHarbor_Dojo_EventScript_DojoStatue_2
# 181 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_DojoStatue_Text_1, MSGBOX_SIGN
MaguroHarbor_Dojo_EventScript_DojoStatue_1:
# 188 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	releaseall
	return

MaguroHarbor_Dojo_EventScript_DojoStatue_2:
# 173 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	msgbox MaguroHarbor_Dojo_EventScript_DojoStatue_Text_0, MSGBOX_SIGN
	goto MaguroHarbor_Dojo_EventScript_DojoStatue_1


# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_0:
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_right
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_right
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_right
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 103 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
	step_end

# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_1:
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_right
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_right
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_right
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_left
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
# 105 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	walk_down
	step_end

MaguroHarbor_Dojo_EventScript_Koishi_Text_0:
# 11 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Welcome to Maguro's Koi Pond Dojo, one\n"
	.string "of the eight Dojos officially\l"
	.string "appointed by the Toku Council.\p"
	.string "We Dojo Masters fight wielders that\n"
	.string "have taken on the Pokémon Council's\l"
	.string "challenge.\p"
	.string "We each give out a different Token to\n"
	.string "anyone who succeeds in defeating us.\p"
	.string "I am Koishi. I began raising elegant,\n"
	.string "graceful Pokémon when I was even\l"
	.string "younger than you are now.\p"
	.string "I may behave and speak in a soft\n"
	.string "manner, but do not for one second\l"
	.string "mistake soft-spokenness for\l"
	.string "weakness.\p"
	.string "Now… Shall we battle?$"

MaguroHarbor_Dojo_EventScript_Koishi_Text_1:
# 18 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "I see…$"

MaguroHarbor_Dojo_EventScript_Koishi_Text_2:
# 25 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "You shall achieve great things. I hope\n"
	.string "we meet again.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_0:
# 32 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "{PLAYER} received the Flowing\n"
	.string "Token from Koishi.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_1:
# 38 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "I applaud your skill. You are still a\n"
	.string "child, yet you obviously have a\l"
	.string "natural aptitude for battle.\p"
	.string "With the Token I just gave you, your\n"
	.string "Pokémon will obey you without\l"
	.string "question, even those you trade with\l"
	.string "others.\p"
	.string "I am also supposed to give you this.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_2:
# 49 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "This scroll contains Water Pulse, a\n"
	.string "water-type move that can confuse\l"
	.string "your foes.\p"
	.string "Going through the Toku Council's\n"
	.string "challenge is no easy undertaking, but\l"
	.string "I can feel your spirit overflowing\l"
	.string "with determination.\p"
	.string "Good luck, {PLAYER}.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_3:
# 94 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Koishi$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_4:
# 96 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "That… That was a big one!…\p"
	.string "I'm going outside to make sure\n"
	.string "everyone's alright.$"

MaguroHarbor_Dojo_EventScript_Izumi_Text_0:
# 120 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "My Pokémon are the daintiest there\n"
	.string "is!$"

MaguroHarbor_Dojo_EventScript_Izumi_Text_1:
# 121 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "My poor Feebas!$"

MaguroHarbor_Dojo_EventScript_Izumi_Text_2:
# 124 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "You'll go far. I can tell.$"

MaguroHarbor_Dojo_EventScript_Ren_Text_0:
# 131 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Come in! The water's nice and toasty!$"

MaguroHarbor_Dojo_EventScript_Ren_Text_1:
# 132 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Nooo!$"

MaguroHarbor_Dojo_EventScript_Ren_Text_2:
# 135 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "I l-lied. I'm f-f-freezing in h-here.$"

MaguroHarbor_Dojo_EventScript_Mizu_Text_0:
# 142 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Do not disturb the koi pond!$"

MaguroHarbor_Dojo_EventScript_Mizu_Text_1:
# 143 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Stop making so much noise!$"

MaguroHarbor_Dojo_EventScript_Mizu_Text_2:
# 147 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "These are sophisticated fish. They\n"
	.string "need peace and quiet to thrive.$"

MaguroHarbor_Dojo_EventScript_Advice_Text_0:
# 156 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "You swept me away with that battle!$"

MaguroHarbor_Dojo_EventScript_Advice_Text_1:
# 160 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Hello, young challenger! Are you going\n"
	.string "to be fighting for your first Token?\p"
	.string "Welcome to the Koi Pond Dojo!\p"
	.string "Koishi, the Master of this place,\n"
	.string "favors water-type moves. Her\l"
	.string "battling style is strong, yet\l"
	.string "graceful… Sigh…\p"
	.string "I am her biggest fan! It's true! Maybe\n"
	.string "one day, I'll become your biggest fan,\l"
	.string "who knows?\p"
	.string "Go get 'em!$"

MaguroHarbor_Dojo_EventScript_DojoStatue_Text_0:
# 174 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Dojo of Maguro Harbor\p"
	.string "Certified wielders:\n"
	.string "Natsuki,"
	.string "{PLAYER}$"

MaguroHarbor_Dojo_EventScript_DojoStatue_Text_1:
# 182 "data/maps/MaguroHarbor_Dojo/scripts.pory"
	.string "Dojo of Maguro Harbor\p"
	.string "Certified wielders:\n"
	.string "Natsuki$"
