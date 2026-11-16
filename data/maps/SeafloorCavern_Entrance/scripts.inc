SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt::
	lockall
	goto_if_eq VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1, SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_Delay48
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterUp
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort::
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterUp
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast::
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest::
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterRight
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth::
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterDown
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep:
	.string "היי!\n"
	.string "אני זוכר את הפנים שלך!\p"
	.string "אם את{EMIT_HEY} כאן, זה בטח אומר\n"
	.string "שאת{EMIT_HEY} עומד{ADD_TAF} שוב להתעסק איתנו!\p"
	.string "פאנק כמוך, את{EMIT_HEY} באמת חושב{ADD_TAF}\n"
	.string "שאת{EMIT_HEY} יכול{ADD_HEY} להתמודד מול צוות אקווה?\p"
	.string "הייתי אומר שאת{EMIT_HEY} מקדי{SWAP_MEM}{ADD_HEY} מדי בערך\n"
	.string "בטריליון שנים!\p"
	.string "את{EMIT_HEY} מתאי{SWAP_MEM}{ADD_HEY} בדיוק לחברי\n"
	.string "צוות מגמה!\p"
	.string "אם כבר מדברים על צוות מגמה, שמעתי שהם\n"
	.string "נצפו ליד מוסדיפ.\p"
	.string "החבר'ה האלה של גולמים, הם בטח לא\n"
	.string "נראים טוב ליד הים!$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort:
	.string "פאנק כמוך, את{EMIT_HEY} באמת חושב{ADD_TAF}\n"
	.string "שאת{EMIT_HEY} יכול{ADD_HEY} להתמודד מול צוות אקווה?\p"
	.string "הייתי אומר שאת{EMIT_HEY} מקדי{SWAP_MEM}{ADD_HEY} מדי בערך\n"
	.string "בטריליון שנים!\p"
	.string "את{EMIT_HEY} מתאי{SWAP_MEM}{ADD_HEY} בדיוק לחברי\n"
	.string "צוות מגמה!\p"
	.string "אם כבר מדברים על צוות מגמה, שמעתי שהם\n"
	.string "נצפו ליד מוסדיפ.\p"
	.string "החבר'ה האלה של גולמים, הם בטח לא\n"
	.string "נראים טוב ליד הים!$"

