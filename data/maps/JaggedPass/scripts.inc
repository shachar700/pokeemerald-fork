JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end
JaggedPass_Text_EricIntro:
	.string "מעבר משונן בהר הארובה…\p"
	.string "זה בדיוק מה שתמיד רציתי\n"
	.string "בהר.\p"
	.string "הקפיצות מהמשונן הזה…\n"
	.string "זה מטלטל את הנשמה שלי!$"

JaggedPass_Text_EricDefeat:
	.string "ההפסד הותיר אותי ממורמר!$"

JaggedPass_Text_EricPostBattle:
	.string "כן, הפסדתי בפוקימון…\p"
	.string "אבל, כשזה מגיע לאהבת\n"
	.string "ההרים, ניצחתי אותך!$"

JaggedPass_Text_DianaIntro:
	.string "המקום הזה אינו טיול רגוע.\n"
	.string "הוא לא מתאים לפיקניק.$"

JaggedPass_Text_DianaDefeat:
	.string "אווו, לא!\n"
	.string "הקרקע יותר מדי קפצנית…$"

JaggedPass_Text_DianaPostBattle:
	.string "האם ידעת?\p"
	.string "יש אנשים שרוכבים בחוכמה על\n"
	.string "האופניים שלהם במעבר הקופצני והנוראי הזה.$"

JaggedPass_Text_DianaRegister:
	.string "האם אי פעם תחז{EMIT_VAV}ר{ADD_YUD} לאזור הזה?\n"
	.string "אם תחז{EMIT_VAV}ר{ADD_YUD}, אני ארצה קרב חוזר.$"

JaggedPass_Text_DianaRematchIntro:
	.string "פיקניקים זה כיף לא משנה לאן אתה הולך.\n"
	.string "בדיוק כמו פוקימונים!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "הפסדתי רק בגלל שהקרקע\n"
	.string "יותר מדי קופצנית!$"

JaggedPass_Text_DianaPostRematch:
	.string "אני אשכח מההפסד ופשוט\n"
	.string "אהנה מהטיול הקופצני הזה.$"

JaggedPass_Text_EthanIntro:
	.string "קשה ללכת במעבר משונן.\n"
	.string "זה מקום טוב לאימונים.$"

JaggedPass_Text_EthanDefeat:
	.string "הכל נגמר עוד בזמן שניסינו\n"
	.string "למצוא אחיזת רגל טובה…$"

JaggedPass_Text_EthanPostBattle:
	.string "אם היו לי אופני אקרו, הייתי יכול\n"
	.string "לקפוץ מעבר לקצוות.$"

JaggedPass_Text_EthanRegister:
	.string "כשאני אתרגל יותר לקופצניות הזאת,\n"
	.string "אני בטוח אנצח!\p"
	.string "תוכל{ADD_YUD} לרשום אותי בפוקינווט שלך?$"

JaggedPass_Text_EthanRematchIntro:
	.string "אני התרגלתי לקופצניות הזאת.\n"
	.string "אני שר בזמן שאני מטפס עכשיו.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "זה עדיין לא קל להילחם על\n"
	.string "הקרקע הקופצנית הזאת…$"

JaggedPass_Text_EthanPostRematch:
	.string "אני צריך להשיג אופני אקרו מרידל\n"
	.string "בעיר מוויל…$"

JaggedPass_Text_GruntIntro:
	.string "וואה!\n"
	.string "מה את{EMIT_HEY} עושה כאן?\p"
	.string "מה אני עושה במקום כזה?\p"
	.string "מה אכפת לך?$"

JaggedPass_Text_GruntDefeat:
	.string "אוחחח…\p"
	.string "הייתי צריך לברוח למחבוא שלנו\n"
	.string "מיד…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "אוקיי, או-קיי!\n"
	.string "אני מודה בזה--את{EMIT_HEY} חזק{ADD_HEY}!\p"
	.string "אל תדאג{ADD_YUD} לי.\n"
	.string "ל{SWAP_CHAF}{ADD_YUD} לאן שאת{EMIT_HEY} רוצה!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "או! הסלע הזה רועד בתגובה\n"
	.string "לסמל מגמה!$"

JaggedPass_Text_JulioIntro:
	.string "אייי! זה נורא מפחיד לדהור\n"
	.string "במורד ההר בבת אחת!$"

JaggedPass_Text_JulioDefeat:
	.string "אני מרגיש שאני מתפרק…$"

JaggedPass_Text_JulioPostBattle:
	.string "האופניים שלי קפצו כל כך הרבה,\n"
	.string "הישבן שלי כואב…$"

JaggedPass_Text_AutumnIntro:
	.string "אני מטפסת על הגבעה הזו כל יום.\n"
	.string "יש לי ביטחון בכוח שלי!$"

JaggedPass_Text_AutumnDefeat:
	.string "הממ…\n"
	.string "מה השתבש?$"

JaggedPass_Text_AutumnPostBattle:
	.string "מהי בליטת הסלע המוזרה ההיא\n"
	.string "קצת במעלי הגבעה מכאן?$"
