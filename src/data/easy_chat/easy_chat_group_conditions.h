const u8 gEasyChatWord_Hot[] = _("חם");
const u8 gEasyChatWord_Exists[] = _("קיים");
const u8 gEasyChatWord_Excess[] = _("עודף");
const u8 gEasyChatWord_Approved[] = _("מאושר");
const u8 gEasyChatWord_Has[] = _("יש לו");
const u8 gEasyChatWord_Good[] = _("טוב");
const u8 gEasyChatWord_Less[] = _("פחות");
const u8 gEasyChatWord_Momentum[] = _("תנופה");
const u8 gEasyChatWord_Going[] = _("הולך");
const u8 gEasyChatWord_Weird[] = _("מוזר");
const u8 gEasyChatWord_Busy[] = _("עסוק");
const u8 gEasyChatWord_Together[] = _("ביחד");
const u8 gEasyChatWord_Full[] = _("מלא");
const u8 gEasyChatWord_Absent[] = _("נעדר");
const u8 gEasyChatWord_Being[] = _("להיות");
const u8 gEasyChatWord_Need[] = _("צריך");
const u8 gEasyChatWord_Tasty[] = _("טעים");
const u8 gEasyChatWord_Skilled[] = _("מיומן");
const u8 gEasyChatWord_Noisy[] = _("רועש");
const u8 gEasyChatWord_Big[] = _("גדול");
const u8 gEasyChatWord_Late[] = _("מאוחר");
const u8 gEasyChatWord_Close[] = _("קרוב");
const u8 gEasyChatWord_Docile[] = _("צייתן");
const u8 gEasyChatWord_Amusing[] = _("משעשע");
const u8 gEasyChatWord_Entertaining[] = _("מבדר");
const u8 gEasyChatWord_Perfection[] = _("שלמות");
const u8 gEasyChatWord_Pretty[] = _("יפה");
const u8 gEasyChatWord_Healthy[] = _("בריא");
const u8 gEasyChatWord_Excellent[] = _("מצוין");
const u8 gEasyChatWord_UpsideDown[] = _("הפוך");
const u8 gEasyChatWord_Cold[] = _("קר");
const u8 gEasyChatWord_Refreshing[] = _("מרענן");
const u8 gEasyChatWord_Unavoidable[] = _("בלתי נמנע");
const u8 gEasyChatWord_Much[] = _("הרבה");
const u8 gEasyChatWord_Overwhelming[] = _("מוחץ");
const u8 gEasyChatWord_Fabulous[] = _("נהדר");
const u8 gEasyChatWord_Else[] = _("אחר");
const u8 gEasyChatWord_Expensive[] = _("יקר");
const u8 gEasyChatWord_Correct[] = _("נכון");
const u8 gEasyChatWord_Impossible[] = _("בלתי אפשרי");
const u8 gEasyChatWord_Small[] = _("קטן");
const u8 gEasyChatWord_Different[] = _("שונה");
const u8 gEasyChatWord_Tired[] = _("עייף");
const u8 gEasyChatWord_Skill[] = _("מיומנות");
const u8 gEasyChatWord_Top[] = _("עליון");
const u8 gEasyChatWord_NonStop[] = _("בלי הפסקה");
const u8 gEasyChatWord_Preposterous[] = _("מגוחך");
const u8 gEasyChatWord_None[] = _("אף אחד");
const u8 gEasyChatWord_Nothing[] = _("כלום");
const u8 gEasyChatWord_Natural[] = _("טבעי");
const u8 gEasyChatWord_Becomes[] = _("נהיה");
const u8 gEasyChatWord_Lukewarm[] = _("פושר");
const u8 gEasyChatWord_Fast[] = _("מהיר");
const u8 gEasyChatWord_Low[] = _("נמוך");
const u8 gEasyChatWord_Awful[] = _("נורא");
const u8 gEasyChatWord_Alone[] = _("לבד");
const u8 gEasyChatWord_Bored[] = _("משועמם");
const u8 gEasyChatWord_Secret[] = _("סוד");
const u8 gEasyChatWord_Mystery[] = _("תעלומה");
const u8 gEasyChatWord_Lacks[] = _("חסר");
const u8 gEasyChatWord_Best[] = _("הכי טוב");
const u8 gEasyChatWord_Lousy[] = _("גרוע");
const u8 gEasyChatWord_Mistake[] = _("טעות");
const u8 gEasyChatWord_Kind[] = _("אדיב");
const u8 gEasyChatWord_Well[] = _("היטב");
const u8 gEasyChatWord_Weakened[] = _("נחלש");
const u8 gEasyChatWord_Simple[] = _("פשוט");
const u8 gEasyChatWord_Seems[] = _("נראה");
const u8 gEasyChatWord_Badly[] = _("רע");

const struct EasyChatWordInfo gEasyChatGroup_Conditions[] = {
    [EC_INDEX(EC_WORD_HOT)] =
    {
        .text = gEasyChatWord_Hot,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXISTS)] =
    {
        .text = gEasyChatWord_Exists,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCESS)] =
    {
        .text = gEasyChatWord_Excess,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AMUSING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPROVED)] =
    {
        .text = gEasyChatWord_Approved,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPROVED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAS)] =
    {
        .text = gEasyChatWord_Has,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFUL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD)] =
    {
        .text = gEasyChatWord_Good,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BADLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESS)] =
    {
        .text = gEasyChatWord_Less,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BECOMES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOMENTUM)] =
    {
        .text = gEasyChatWord_Momentum,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOING)] =
    {
        .text = gEasyChatWord_Going,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEIRD)] =
    {
        .text = gEasyChatWord_Weird,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUSY)] =
    {
        .text = gEasyChatWord_Busy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOGETHER)] =
    {
        .text = gEasyChatWord_Together,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FULL)] =
    {
        .text = gEasyChatWord_Full,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSENT)] =
    {
        .text = gEasyChatWord_Absent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEING)] =
    {
        .text = gEasyChatWord_Being,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CORRECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEED)] =
    {
        .text = gEasyChatWord_Need,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIFFERENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TASTY)] =
    {
        .text = gEasyChatWord_Tasty,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOCILE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILLED)] =
    {
        .text = gEasyChatWord_Skilled,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOISY)] =
    {
        .text = gEasyChatWord_Noisy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENTERTAINING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIG)] =
    {
        .text = gEasyChatWord_Big,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCELLENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATE)] =
    {
        .text = gEasyChatWord_Late,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLOSE)] =
    {
        .text = gEasyChatWord_Close,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXISTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOCILE)] =
    {
        .text = gEasyChatWord_Docile,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXPENSIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AMUSING)] =
    {
        .text = gEasyChatWord_Amusing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FABULOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENTERTAINING)] =
    {
        .text = gEasyChatWord_Entertaining,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECTION)] =
    {
        .text = gEasyChatWord_Perfection,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FULL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETTY)] =
    {
        .text = gEasyChatWord_Pretty,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEALTHY)] =
    {
        .text = gEasyChatWord_Healthy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCELLENT)] =
    {
        .text = gEasyChatWord_Excellent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPSIDE_DOWN)] =
    {
        .text = gEasyChatWord_UpsideDown,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEALTHY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLD)] =
    {
        .text = gEasyChatWord_Cold,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFRESHING)] =
    {
        .text = gEasyChatWord_Refreshing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPOSSIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNAVOIDABLE)] =
    {
        .text = gEasyChatWord_Unavoidable,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH)] =
    {
        .text = gEasyChatWord_Much,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERWHELMING)] =
    {
        .text = gEasyChatWord_Overwhelming,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FABULOUS)] =
    {
        .text = gEasyChatWord_Fabulous,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELSE)] =
    {
        .text = gEasyChatWord_Else,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXPENSIVE)] =
    {
        .text = gEasyChatWord_Expensive,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CORRECT)] =
    {
        .text = gEasyChatWord_Correct,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LUKEWARM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPOSSIBLE)] =
    {
        .text = gEasyChatWord_Impossible,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISTAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMALL)] =
    {
        .text = gEasyChatWord_Small,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOMENTUM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIFFERENT)] =
    {
        .text = gEasyChatWord_Different,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIRED)] =
    {
        .text = gEasyChatWord_Tired,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSTERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILL)] =
    {
        .text = gEasyChatWord_Skill,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOP)] =
    {
        .text = gEasyChatWord_Top,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NON_STOP)] =
    {
        .text = gEasyChatWord_NonStop,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOISY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PREPOSTEROUS)] =
    {
        .text = gEasyChatWord_Preposterous,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NON_STOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NONE)] =
    {
        .text = gEasyChatWord_None,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOTHING)] =
    {
        .text = gEasyChatWord_Nothing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOTHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURAL)] =
    {
        .text = gEasyChatWord_Natural,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERWHELMING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BECOMES)] =
    {
        .text = gEasyChatWord_Becomes,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LUKEWARM)] =
    {
        .text = gEasyChatWord_Lukewarm,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PREPOSTEROUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAST)] =
    {
        .text = gEasyChatWord_Fast,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOW)] =
    {
        .text = gEasyChatWord_Low,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFRESHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFUL)] =
    {
        .text = gEasyChatWord_Awful,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALONE)] =
    {
        .text = gEasyChatWord_Alone,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEMS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORED)] =
    {
        .text = gEasyChatWord_Bored,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIMPLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET)] =
    {
        .text = gEasyChatWord_Secret,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSTERY)] =
    {
        .text = gEasyChatWord_Mystery,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILLED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKS)] =
    {
        .text = gEasyChatWord_Lacks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMALL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEST)] =
    {
        .text = gEasyChatWord_Best,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TASTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOUSY)] =
    {
        .text = gEasyChatWord_Lousy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIRED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISTAKE)] =
    {
        .text = gEasyChatWord_Mistake,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOGETHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIND)] =
    {
        .text = gEasyChatWord_Kind,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL)] =
    {
        .text = gEasyChatWord_Well,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNAVOIDABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAKENED)] =
    {
        .text = gEasyChatWord_Weakened,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPSIDE_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIMPLE)] =
    {
        .text = gEasyChatWord_Simple,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAKENED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEMS)] =
    {
        .text = gEasyChatWord_Seems,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEIRD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BADLY)] =
    {
        .text = gEasyChatWord_Badly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL),
        .enabled = TRUE,
    },
};
