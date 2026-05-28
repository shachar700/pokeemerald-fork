const u8 gEasyChatWord_MatchUp[] = _("התמודדות");
const u8 gEasyChatWord_Go[] = _("לך");
const u8 gEasyChatWord_No1[] = _("מס' 1");
const u8 gEasyChatWord_Decide[] = _("להחליט");
const u8 gEasyChatWord_LetMeWin[] = _("תן לי לנצח");
const u8 gEasyChatWord_Wins[] = _("מנצח");
const u8 gEasyChatWord_Win[] = _("לנצח");
const u8 gEasyChatWord_Won[] = _("ניצח");
const u8 gEasyChatWord_IfIWin[] = _("אם אנצח");
const u8 gEasyChatWord_WhenIWin[] = _("כשאנצח");
const u8 gEasyChatWord_CantWin[] = _("לא יכול לנצח");
const u8 gEasyChatWord_CanWin[] = _("יכול לנצח");
const u8 gEasyChatWord_NoMatch[] = _("אין סיכוי");
const u8 gEasyChatWord_Spirit[] = _("רוח");
const u8 gEasyChatWord_Decided[] = _("הוחלט");
const u8 gEasyChatWord_TrumpCard[] = _("קלף מנצח");
const u8 gEasyChatWord_TakeThat[] = _("קח את זה");
const u8 gEasyChatWord_ComeOn[] = _("קדימה");
const u8 gEasyChatWord_Attack[] = _("לתקוף");
const u8 gEasyChatWord_Surrender[] = _("להיכנע");
const u8 gEasyChatWord_Gutsy[] = _("אמיץ");
const u8 gEasyChatWord_Talent[] = _("כישרון");
const u8 gEasyChatWord_Strategy[] = _("אסטרטגיה");
const u8 gEasyChatWord_Smite[] = _("להכות");
const u8 gEasyChatWord_Match[] = _("משחק");
const u8 gEasyChatWord_Victory[] = _("ניצחון");
const u8 gEasyChatWord_Offensive[] = _("התקפי");
const u8 gEasyChatWord_Sense[] = _("חוש");
const u8 gEasyChatWord_Versus[] = _("נגד");
const u8 gEasyChatWord_Fights[] = _("נלחם");
const u8 gEasyChatWord_Power[] = _("כוח");
const u8 gEasyChatWord_Challenge[] = _("אתגר");
const u8 gEasyChatWord_Strong[] = _("חזק");
const u8 gEasyChatWord_TooStrong[] = _("חזק מדי");
const u8 gEasyChatWord_GoEasy[] = _("לך בקלות");
const u8 gEasyChatWord_Foe[] = _("אויב");
const u8 gEasyChatWord_Genius[] = _("גאון");
const u8 gEasyChatWord_Legend[] = _("אגדה");
const u8 gEasyChatWord_Escape[] = _("לברוח");
const u8 gEasyChatWord_Aim[] = _("לכוון");
const u8 gEasyChatWord_Battle[] = _("קרב");
const u8 gEasyChatWord_Fight[] = _("להילחם");
const u8 gEasyChatWord_Resuscitate[] = _("להחיות");
const u8 gEasyChatWord_Points[] = _("נקודות");
const u8 gEasyChatWord_Serious[] = _("רציני");
const u8 gEasyChatWord_GiveUp[] = _("לוותר");
const u8 gEasyChatWord_Loss[] = _("הפסד");
const u8 gEasyChatWord_IfILose[] = _("אם אפסיד");
const u8 gEasyChatWord_Lost[] = _("הפסיד");
const u8 gEasyChatWord_Lose[] = _("להפסיד");
const u8 gEasyChatWord_Guard[] = _("להגן");
const u8 gEasyChatWord_Partner[] = _("שותף");
const u8 gEasyChatWord_Reject[] = _("לדחות");
const u8 gEasyChatWord_Accept[] = _("לקבל");
const u8 gEasyChatWord_Invincible[] = _("בלתי מנוצח");
const u8 gEasyChatWord_Received[] = _("התקבל");
const u8 gEasyChatWord_Easy[] = _("קל");
const u8 gEasyChatWord_Weak[] = _("חלש");
const u8 gEasyChatWord_TooWeak[] = _("חלש מדי");
const u8 gEasyChatWord_Pushover[] = _("פראייר");
const u8 gEasyChatWord_Leader[] = _("מנהיג");
const u8 gEasyChatWord_Rule[] = _("חוק");
const u8 gEasyChatWord_Move[] = _("מהלך");

const struct EasyChatWordInfo gEasyChatGroup_Battle[] = {
	[EC_INDEX(EC_WORD_MATCH_UP)] =
	{
		.text = gEasyChatWord_MatchUp,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LEGEND),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GO)] =
	{
		.text = gEasyChatWord_Go,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FOE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_NO_1)] =
	{
		.text = gEasyChatWord_No1,
		.alphabeticalOrder = EC_INDEX(EC_WORD_NO_MATCH),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_DECIDE)] =
	{
		.text = gEasyChatWord_Decide,
		.alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_WIN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LET_ME_WIN)] =
	{
		.text = gEasyChatWord_LetMeWin,
		.alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_LOSE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WINS)] =
	{
		.text = gEasyChatWord_Wins,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GUTSY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WIN)] =
	{
		.text = gEasyChatWord_Win,
		.alphabeticalOrder = EC_INDEX(EC_WORD_STRATEGY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WON)] =
	{
		.text = gEasyChatWord_Won,
		.alphabeticalOrder = EC_INDEX(EC_WORD_CHALLENGE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_IF_I_WIN)] =
	{
		.text = gEasyChatWord_IfIWin,
		.alphabeticalOrder = EC_INDEX(EC_WORD_INVINCIBLE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WHEN_I_WIN)] =
	{
		.text = gEasyChatWord_WhenIWin,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GENIUS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_CAN_T_WIN)] =
	{
		.text = gEasyChatWord_CantWin,
		.alphabeticalOrder = EC_INDEX(EC_WORD_DECIDED),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_CAN_WIN)] =
	{
		.text = gEasyChatWord_CanWin,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LOSS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_NO_MATCH)] =
	{
		.text = gEasyChatWord_NoMatch,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LOST),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SPIRIT)] =
	{
		.text = gEasyChatWord_Spirit,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MATCH_UP),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_DECIDED)] =
	{
		.text = gEasyChatWord_Decided,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RECEIVED),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TRUMP_CARD)] =
	{
		.text = gEasyChatWord_TrumpCard,
		.alphabeticalOrder = EC_INDEX(EC_WORD_OFFENSIVE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TAKE_THAT)] =
	{
		.text = gEasyChatWord_TakeThat,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RULE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_COME_ON)] =
	{
		.text = gEasyChatWord_ComeOn,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SENSE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ATTACK)] =
	{
		.text = gEasyChatWord_Attack,
		.alphabeticalOrder = EC_INDEX(EC_WORD_STRONG),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SURRENDER)] =
	{
		.text = gEasyChatWord_Surrender,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TOO_STRONG),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GUTSY)] =
	{
		.text = gEasyChatWord_Gutsy,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WEAK),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TALENT)] =
	{
		.text = gEasyChatWord_Talent,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TOO_WEAK),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_STRATEGY)] =
	{
		.text = gEasyChatWord_Strategy,
		.alphabeticalOrder = EC_INDEX(EC_WORD_CAN_WIN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SMITE)] =
	{
		.text = gEasyChatWord_Smite,
		.alphabeticalOrder = EC_INDEX(EC_WORD_POWER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MATCH)] =
	{
		.text = gEasyChatWord_Match,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TALENT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_VICTORY)] =
	{
		.text = gEasyChatWord_Victory,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WHEN_I_WIN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_OFFENSIVE)] =
	{
		.text = gEasyChatWord_Offensive,
		.alphabeticalOrder = EC_INDEX(EC_WORD_CAN_T_WIN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SENSE)] =
	{
		.text = gEasyChatWord_Sense,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ESCAPE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_VERSUS)] =
	{
		.text = gEasyChatWord_Versus,
		.alphabeticalOrder = EC_INDEX(EC_WORD_REJECT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FIGHTS)] =
	{
		.text = gEasyChatWord_Fights,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GUARD),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_POWER)] =
	{
		.text = gEasyChatWord_Power,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RESUSCITATE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_CHALLENGE)] =
	{
		.text = gEasyChatWord_Challenge,
		.alphabeticalOrder = EC_INDEX(EC_WORD_DECIDE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_STRONG)] =
	{
		.text = gEasyChatWord_Strong,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SURRENDER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TOO_STRONG)] =
	{
		.text = gEasyChatWord_TooStrong,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FIGHT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GO_EASY)] =
	{
		.text = gEasyChatWord_GoEasy,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SMITE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FOE)] =
	{
		.text = gEasyChatWord_Foe,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LOSE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GENIUS)] =
	{
		.text = gEasyChatWord_Genius,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_UP),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LEGEND)] =
	{
		.text = gEasyChatWord_Legend,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GO),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ESCAPE)] =
	{
		.text = gEasyChatWord_Escape,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GO_EASY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_AIM)] =
	{
		.text = gEasyChatWord_Aim,
		.alphabeticalOrder = EC_INDEX(EC_WORD_AIM),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BATTLE)] =
	{
		.text = gEasyChatWord_Battle,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WIN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FIGHT)] =
	{
		.text = gEasyChatWord_Fight,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ACCEPT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RESUSCITATE)] =
	{
		.text = gEasyChatWord_Resuscitate,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ATTACK),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_POINTS)] =
	{
		.text = gEasyChatWord_Points,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MOVE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SERIOUS)] =
	{
		.text = gEasyChatWord_Serious,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LEADER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GIVE_UP)] =
	{
		.text = gEasyChatWord_GiveUp,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WINS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LOSS)] =
	{
		.text = gEasyChatWord_Loss,
		.alphabeticalOrder = EC_INDEX(EC_WORD_NO_1),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_IF_I_LOSE)] =
	{
		.text = gEasyChatWord_IfILose,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MATCH),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LOST)] =
	{
		.text = gEasyChatWord_Lost,
		.alphabeticalOrder = EC_INDEX(EC_WORD_VERSUS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LOSE)] =
	{
		.text = gEasyChatWord_Lose,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WON),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GUARD)] =
	{
		.text = gEasyChatWord_Guard,
		.alphabeticalOrder = EC_INDEX(EC_WORD_VICTORY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_PARTNER)] =
	{
		.text = gEasyChatWord_Partner,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FIGHTS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_REJECT)] =
	{
		.text = gEasyChatWord_Reject,
		.alphabeticalOrder = EC_INDEX(EC_WORD_POINTS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ACCEPT)] =
	{
		.text = gEasyChatWord_Accept,
		.alphabeticalOrder = EC_INDEX(EC_WORD_PUSHOVER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_INVINCIBLE)] =
	{
		.text = gEasyChatWord_Invincible,
		.alphabeticalOrder = EC_INDEX(EC_WORD_COME_ON),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RECEIVED)] =
	{
		.text = gEasyChatWord_Received,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TAKE_THAT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_EASY)] =
	{
		.text = gEasyChatWord_Easy,
		.alphabeticalOrder = EC_INDEX(EC_WORD_EASY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WEAK)] =
	{
		.text = gEasyChatWord_Weak,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TRUMP_CARD),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TOO_WEAK)] =
	{
		.text = gEasyChatWord_TooWeak,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_PUSHOVER)] =
	{
		.text = gEasyChatWord_Pushover,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SPIRIT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LEADER)] =
	{
		.text = gEasyChatWord_Leader,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RULE)] =
	{
		.text = gEasyChatWord_Rule,
		.alphabeticalOrder = EC_INDEX(EC_WORD_PARTNER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MOVE)] =
	{
		.text = gEasyChatWord_Move,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LET_ME_WIN),
		.enabled = TRUE,
	},
};
