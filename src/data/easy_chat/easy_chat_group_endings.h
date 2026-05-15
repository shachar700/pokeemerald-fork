const u8 gEasyChatWord_Will[] = _("יהיה");
const u8 gEasyChatWord_IWill[] = _("אהיה");
const u8 gEasyChatWord_WillBeHere[] = _("יהיה כאן");
const u8 gEasyChatWord_Or[] = _("או");
const u8 gEasyChatWord_Times[] = _("פעמים");
const u8 gEasyChatWord_Wonder[] = _("תוהה");
const u8 gEasyChatWord_IsItQues[] = _("האם זה?");
const u8 gEasyChatWord_Be[] = _("להיות");
const u8 gEasyChatWord_Gimme[] = _("תן לי");
const u8 gEasyChatWord_Could[] = _("יכול");
const u8 gEasyChatWord_LikelyTo[] = _("סביר ש");
const u8 gEasyChatWord_Would[] = _("היה");
const u8 gEasyChatWord_Is[] = _("הוא");
const u8 gEasyChatWord_IsntItQues[] = _("נכון?");
const u8 gEasyChatWord_Lets[] = _("בוא");
const u8 gEasyChatWord_Other[] = _("אחר");
const u8 gEasyChatWord_Are[] = _("הם");
const u8 gEasyChatWord_Was[] = _("היה");
const u8 gEasyChatWord_Were[] = _("היו");
const u8 gEasyChatWord_Those[] = _("אלה");
const u8 gEasyChatWord_Isnt[] = _("אינו");
const u8 gEasyChatWord_Wont[] = _("לא יהיה");
const u8 gEasyChatWord_Cant[] = _("לא יכול");
const u8 gEasyChatWord_Can[] = _("יכול");
const u8 gEasyChatWord_Dont[] = _("לא");
const u8 gEasyChatWord_Do[] = _("לעשות");
const u8 gEasyChatWord_Does[] = _("עושה");
const u8 gEasyChatWord_Whom[] = _("את מי");
const u8 gEasyChatWord_Which[] = _("איזה");
const u8 gEasyChatWord_Wasnt[] = _("לא היה");
const u8 gEasyChatWord_Werent[] = _("לא היו");
const u8 gEasyChatWord_Have[] = _("יש");
const u8 gEasyChatWord_Havent[] = _("אין");
const u8 gEasyChatWord_A[] = _("");
const u8 gEasyChatWord_An[] = _("");
const u8 gEasyChatWord_Not[] = _("לא");
const u8 gEasyChatWord_There[] = _("שם");
const u8 gEasyChatWord_OkQues[] = _("בסדר?");
const u8 gEasyChatWord_So[] = _("ככה");
const u8 gEasyChatWord_Maybe[] = _("אולי");
const u8 gEasyChatWord_About[] = _("על");
const u8 gEasyChatWord_Over[] = _("מעל");
const u8 gEasyChatWord_It[] = _("זה");
const u8 gEasyChatWord_All[] = _("הכל");
const u8 gEasyChatWord_For[] = _("בשביל");
const u8 gEasyChatWord_On[] = _("דלוק");
const u8 gEasyChatWord_Off[] = _("כבוי");
const u8 gEasyChatWord_As[] = _("כ");
const u8 gEasyChatWord_To[] = _("אל");
const u8 gEasyChatWord_With[] = _("עם");
const u8 gEasyChatWord_Better[] = _("יותר טוב");
const u8 gEasyChatWord_Ever[] = _("אי פעם");
const u8 gEasyChatWord_Since[] = _("מאז");
const u8 gEasyChatWord_Of[] = _("של");
const u8 gEasyChatWord_BelongsTo[] = _("שייך ל");
const u8 gEasyChatWord_At[] = _("ב");
const u8 gEasyChatWord_In[] = _("ב");
const u8 gEasyChatWord_Out[] = _("בחוץ");
const u8 gEasyChatWord_Too[] = _("גם");
const u8 gEasyChatWord_Like[] = _("כאילו");
const u8 gEasyChatWord_Did[] = _("עשה");
const u8 gEasyChatWord_Didnt[] = _("לא עשה");
const u8 gEasyChatWord_Doesnt[] = _("לא עושה");
const u8 gEasyChatWord_Without[] = _("בלי");
const u8 gEasyChatWord_After[] = _("אחרי");
const u8 gEasyChatWord_Before[] = _("לפני");
const u8 gEasyChatWord_While[] = _("בזמן ש");
const u8 gEasyChatWord_Than[] = _("מאשר");
const u8 gEasyChatWord_Once[] = _("פעם אחת");
const u8 gEasyChatWord_Anywhere[] = _("בכל מקום");

const struct EasyChatWordInfo gEasyChatGroup_Endings[] = {
    [EC_INDEX(EC_WORD_WILL)] =
    {
        .text = gEasyChatWord_Will,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IWILL)] =
    {
        .text = gEasyChatWord_IWill,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WILL_BE_HERE)] =
    {
        .text = gEasyChatWord_WillBeHere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OR)] =
    {
        .text = gEasyChatWord_Or,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AFTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIMES)] =
    {
        .text = gEasyChatWord_Times,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WONDER)] =
    {
        .text = gEasyChatWord_Wonder,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IS_IT_QUES)] =
    {
        .text = gEasyChatWord_IsItQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANYWHERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BE)] =
    {
        .text = gEasyChatWord_Be,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIMME)] =
    {
        .text = gEasyChatWord_Gimme,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COULD)] =
    {
        .text = gEasyChatWord_Could,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKELY_TO)] =
    {
        .text = gEasyChatWord_LikelyTo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOULD)] =
    {
        .text = gEasyChatWord_Would,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEFORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IS)] =
    {
        .text = gEasyChatWord_Is,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELONGS_TO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ISN_T_IT_QUES)] =
    {
        .text = gEasyChatWord_IsntItQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BETTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LET_S)] =
    {
        .text = gEasyChatWord_Lets,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OTHER)] =
    {
        .text = gEasyChatWord_Other,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARE)] =
    {
        .text = gEasyChatWord_Are,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COULD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAS)] =
    {
        .text = gEasyChatWord_Was,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WERE)] =
    {
        .text = gEasyChatWord_Were,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIDN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE)] =
    {
        .text = gEasyChatWord_Those,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ISN_T)] =
    {
        .text = gEasyChatWord_Isnt,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WON_T)] =
    {
        .text = gEasyChatWord_Wont,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOESN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_T)] =
    {
        .text = gEasyChatWord_Cant,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DON_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN)] =
    {
        .text = gEasyChatWord_Can,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DON_T)] =
    {
        .text = gEasyChatWord_Dont,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DO)] =
    {
        .text = gEasyChatWord_Do,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIMME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOES)] =
    {
        .text = gEasyChatWord_Does,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOM)] =
    {
        .text = gEasyChatWord_Whom,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAVEN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHICH)] =
    {
        .text = gEasyChatWord_Which,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WASN_T)] =
    {
        .text = gEasyChatWord_Wasnt,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEREN_T)] =
    {
        .text = gEasyChatWord_Werent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IS_IT_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAVE)] =
    {
        .text = gEasyChatWord_Have,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ISN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAVEN_T)] =
    {
        .text = gEasyChatWord_Havent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ISN_T_IT_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A)] =
    {
        .text = gEasyChatWord_A,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AN)] =
    {
        .text = gEasyChatWord_An,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LET_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOT)] =
    {
        .text = gEasyChatWord_Not,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THERE)] =
    {
        .text = gEasyChatWord_There,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKELY_TO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OK_QUES)] =
    {
        .text = gEasyChatWord_OkQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAYBE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SO)] =
    {
        .text = gEasyChatWord_So,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAYBE)] =
    {
        .text = gEasyChatWord_Maybe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOUT)] =
    {
        .text = gEasyChatWord_About,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OFF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVER)] =
    {
        .text = gEasyChatWord_Over,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OK_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IT)] =
    {
        .text = gEasyChatWord_It,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALL)] =
    {
        .text = gEasyChatWord_All,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ONCE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOR)] =
    {
        .text = gEasyChatWord_For,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ON)] =
    {
        .text = gEasyChatWord_On,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OTHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OFF)] =
    {
        .text = gEasyChatWord_Off,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS)] =
    {
        .text = gEasyChatWord_As,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO)] =
    {
        .text = gEasyChatWord_To,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SINCE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WITH)] =
    {
        .text = gEasyChatWord_With,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BETTER)] =
    {
        .text = gEasyChatWord_Better,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVER)] =
    {
        .text = gEasyChatWord_Ever,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SINCE)] =
    {
        .text = gEasyChatWord_Since,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OF)] =
    {
        .text = gEasyChatWord_Of,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIMES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELONGS_TO)] =
    {
        .text = gEasyChatWord_BelongsTo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AT)] =
    {
        .text = gEasyChatWord_At,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IN)] =
    {
        .text = gEasyChatWord_In,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUT)] =
    {
        .text = gEasyChatWord_Out,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WASN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO)] =
    {
        .text = gEasyChatWord_Too,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKE)] =
    {
        .text = gEasyChatWord_Like,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEREN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DID)] =
    {
        .text = gEasyChatWord_Did,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHICH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIDN_T)] =
    {
        .text = gEasyChatWord_Didnt,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHILE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOESN_T)] =
    {
        .text = gEasyChatWord_Doesnt,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WITHOUT)] =
    {
        .text = gEasyChatWord_Without,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AFTER)] =
    {
        .text = gEasyChatWord_After,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILL_BE_HERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEFORE)] =
    {
        .text = gEasyChatWord_Before,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WITH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHILE)] =
    {
        .text = gEasyChatWord_While,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WITHOUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAN)] =
    {
        .text = gEasyChatWord_Than,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WON_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ONCE)] =
    {
        .text = gEasyChatWord_Once,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WONDER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANYWHERE)] =
    {
        .text = gEasyChatWord_Anywhere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOULD),
        .enabled = TRUE,
    },
};
