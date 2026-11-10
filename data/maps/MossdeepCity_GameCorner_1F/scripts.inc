MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "כשהייתי צעיר, טיילתי בעולם\n"
	.string "כמאמן פוקימונים.\p"
	.string "עכשיו, כשנהייתי זקן בלה,\n"
	.string "הבידור היחיד שלי הוא לצפות\l"
	.string "במאמנים צעירים נלחמים.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "נראה שהדלת נעולה.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "מאמן בשם {STR_VAR_1}\n"
	.string "מתארח בביתי.\p"
	.string "האם ברצונך לאתגר את\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "לא תילח{SWAP_MEM}{ADD_YUD}? חבל לי מאוד\n"
	.string "שלא אזכה לראות אותך בקרב…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "אה, טוב, טוב!\p"
	.string "אבל הבית שלי לא כל כך יציב.\p"
	.string "אפשר לבקש שתסתפקו\n"
	.string "בקרב של 3 מול 3?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "לפני שתילחמו, כדאי לך\n"
	.string "לשמור את המשחק.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "אני מקווה לראות קרב טוב!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "אז זה נגמר בתיקו.\p"
	.string "זה היה קרב מבריק שבו\n"
	.string "אף צד לא ויתר על צעד!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "זה היה מעולה!\p"
	.string "כאילו ראיתי את עצמי\n"
	.string "בצעירותי שוב!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "אה, חבל!\p"
	.string "אבל זה היה קרב טוב.\n"
	.string "אני מקווה שתנצח{ADD_YUD} בפעם הבאה.$"
