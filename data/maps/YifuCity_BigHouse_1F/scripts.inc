YifuCity_BigHouse_1F_MapScripts::
	.byte 0


YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight::
# 6 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	lock
# 7 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	faceplayer
# 8 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	speakername YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_0
# 9 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	msgbox YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1
# 12 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	release
	return


YifuCity_BigHouse_1F_EventScript_Man::
# 16 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	lock
# 17 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	faceplayer
# 18 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	speakername YifuCity_BigHouse_1F_EventScript_Man_Text_0
# 19 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	msgbox YifuCity_BigHouse_1F_EventScript_Man_Text_1
# 23 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	release
	return


YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_0:
# 8 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	.string "Girl$"

YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1:
# 10 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	.string "I stopped going out at night.\n"
	.string "Those fishy Crobat people roam the\l"
	.string "streets, speaking in hush tones…$"

YifuCity_BigHouse_1F_EventScript_Man_Text_0:
# 18 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	.string "Guy$"

YifuCity_BigHouse_1F_EventScript_Man_Text_1:
# 20 "data/maps/YifuCity_BigHouse_1F/scripts.pory"
	.string "Did you know? The Samurai aren't\n"
	.string "actually affiliated with the Elder\l"
	.string "council of Toku. That's a common\l"
	.string "misconception!\p"
	.string "They're their own organization, which\n"
	.string "mostly deals in protecting the\l"
	.string "population and fighting crime.$"
