const u8 gEasyChatWord_Appeal[] = _("משיכה");
const u8 gEasyChatWord_Events[] = _("אירועים");
const u8 gEasyChatWord_StayAtHome[] = _("נשאר בבית");
const u8 gEasyChatWord_Berry[] = _("פרי יער");
const u8 gEasyChatWord_Contest[] = _("תחרות");
const u8 gEasyChatWord_Mc[] = _("מנחה");
const u8 gEasyChatWord_Judge[] = _("שופט");
const u8 gEasyChatWord_Super[] = _("סופר");
const u8 gEasyChatWord_Stage[] = _("שלב");
const u8 gEasyChatWord_HallOfFame[] = _("היכל התהילה");
const u8 gEasyChatWord_Evolution[] = _("התפתחות");
const u8 gEasyChatWord_Hyper[] = _("היפר");
const u8 gEasyChatWord_BattleTower[] = _("מגדל קרב");
const u8 gEasyChatWord_Leaders[] = _("מנהיגים");
const u8 gEasyChatWord_BattleRoom[] = _("חדר קרב");
const u8 gEasyChatWord_Hidden[] = _("מוסתר");
const u8 gEasyChatWord_SecretBase[] = _("בסיס סודי");
const u8 gEasyChatWord_Blend[] = _("ערבוב");
const u8 gEasyChatWord_POKEBLOCK[] = _("פוקיגוש");
const u8 gEasyChatWord_Master[] = _("מאסטר");
const u8 gEasyChatWord_Rank[] = _("דרגה");
const u8 gEasyChatWord_Ribbon[] = _("סרט");
const u8 gEasyChatWord_Crush[] = _("מעיכה");
const u8 gEasyChatWord_Direct[] = _("ישיר");
const u8 gEasyChatWord_Tower[] = _("מגדל");
const u8 gEasyChatWord_Union[] = _("איחוד");
const u8 gEasyChatWord_Room[] = _("חדר");
const u8 gEasyChatWord_Wireless[] = _("אלחוטי");
const u8 gEasyChatWord_Frontier[] = _("חזית");

const struct EasyChatWordInfo gEasyChatGroup_Events[] = {
	[EC_INDEX(EC_WORD_APPEAL)] =
	{
		.text = gEasyChatWord_Appeal,
		.alphabeticalOrder = EC_INDEX(EC_WORD_UNION),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_EVENTS)] =
	{
		.text = gEasyChatWord_Events,
		.alphabeticalOrder = EC_INDEX(EC_WORD_EVENTS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_STAY_AT_HOME)] =
	{
		.text = gEasyChatWord_StayAtHome,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WIRELESS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BERRY)] =
	{
		.text = gEasyChatWord_Berry,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SECRET_BASE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_CONTEST)] =
	{
		.text = gEasyChatWord_Contest,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RANK),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MC)] =
	{
		.text = gEasyChatWord_Mc,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HALL_OF_FAME),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_JUDGE)] =
	{
		.text = gEasyChatWord_Judge,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HYPER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SUPER)] =
	{
		.text = gEasyChatWord_Super,
		.alphabeticalOrder = EC_INDEX(EC_WORD_EVOLUTION),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_STAGE)] =
	{
		.text = gEasyChatWord_Stage,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ROOM),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HALL_OF_FAME)] =
	{
		.text = gEasyChatWord_HallOfFame,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ROOM),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_EVOLUTION)] =
	{
		.text = gEasyChatWord_Evolution,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FRONTIER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HYPER)] =
	{
		.text = gEasyChatWord_Hyper,
		.alphabeticalOrder = EC_INDEX(EC_WORD_DIRECT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BATTLE_TOWER)] =
	{
		.text = gEasyChatWord_BattleTower,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MASTER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LEADERS)] =
	{
		.text = gEasyChatWord_Leaders,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TOWER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BATTLE_ROOM)] =
	{
		.text = gEasyChatWord_BattleRoom,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_TOWER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HIDDEN)] =
	{
		.text = gEasyChatWord_Hidden,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HIDDEN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SECRET_BASE)] =
	{
		.text = gEasyChatWord_SecretBase,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LEADERS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BLEND)] =
	{
		.text = gEasyChatWord_Blend,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MC),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_POKEBLOCK)] =
	{
		.text = gEasyChatWord_POKEBLOCK,
		.alphabeticalOrder = EC_INDEX(EC_WORD_CRUSH),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MASTER)] =
	{
		.text = gEasyChatWord_Master,
		.alphabeticalOrder = EC_INDEX(EC_WORD_APPEAL),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RANK)] =
	{
		.text = gEasyChatWord_Rank,
		.alphabeticalOrder = EC_INDEX(EC_WORD_STAY_AT_HOME),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RIBBON)] =
	{
		.text = gEasyChatWord_Ribbon,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SUPER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_CRUSH)] =
	{
		.text = gEasyChatWord_Crush,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RIBBON),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_DIRECT)] =
	{
		.text = gEasyChatWord_Direct,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BLEND),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TOWER)] =
	{
		.text = gEasyChatWord_Tower,
		.alphabeticalOrder = EC_INDEX(EC_WORD_POKEBLOCK),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_UNION)] =
	{
		.text = gEasyChatWord_Union,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BERRY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ROOM)] =
	{
		.text = gEasyChatWord_Room,
		.alphabeticalOrder = EC_INDEX(EC_WORD_JUDGE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WIRELESS)] =
	{
		.text = gEasyChatWord_Wireless,
		.alphabeticalOrder = EC_INDEX(EC_WORD_STAGE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FRONTIER)] =
	{
		.text = gEasyChatWord_Frontier,
		.alphabeticalOrder = EC_INDEX(EC_WORD_CONTEST),
		.enabled = TRUE,
	},
};