const u8 gEasyChatWord_Highs[] = _("גבוהים");
const u8 gEasyChatWord_Lows[] = _("נמוכים");
const u8 gEasyChatWord_Um[] = _("אממ");
const u8 gEasyChatWord_Rear[] = _("אחורי");
const u8 gEasyChatWord_Things[] = _("דברים");
const u8 gEasyChatWord_Thing[] = _("דבר");
const u8 gEasyChatWord_Below[] = _("מתחת");
const u8 gEasyChatWord_Above[] = _("מעל");
const u8 gEasyChatWord_Back[] = _("אחורה");
const u8 gEasyChatWord_High[] = _("גבוה");
const u8 gEasyChatWord_Here[] = _("כאן");
const u8 gEasyChatWord_Inside[] = _("בפנים");
const u8 gEasyChatWord_Outside[] = _("בחוץ");
const u8 gEasyChatWord_Beside[] = _("ליד");
const u8 gEasyChatWord_ThisIsItExcl[] = _("זהו!");
const u8 gEasyChatWord_This[] = _("זה");
const u8 gEasyChatWord_Every[] = _("כל");
const u8 gEasyChatWord_These[] = _("אלה");
const u8 gEasyChatWord_TheseWere[] = _("אלה היו");
const u8 gEasyChatWord_Down[] = _("למטה");
const u8 gEasyChatWord_That[] = _("ההוא");
const u8 gEasyChatWord_ThoseAre[] = _("אלה הם");
const u8 gEasyChatWord_ThoseWere[] = _("אלה היו");
const u8 gEasyChatWord_ThatsItExcl[] = _("זהו!");
const u8 gEasyChatWord_Am[] = _("אני");
const u8 gEasyChatWord_ThatWas[] = _("זה היה");
const u8 gEasyChatWord_Front[] = _("קדימה");
const u8 gEasyChatWord_Up[] = _("למעלה");
const u8 gEasyChatWord_Choice[] = _("בחירה");
const u8 gEasyChatWord_Far[] = _("רחוק");
const u8 gEasyChatWord_Away[] = _("הרחק");
const u8 gEasyChatWord_Near[] = _("קרוב");
const u8 gEasyChatWord_Where[] = _("איפה");
const u8 gEasyChatWord_When[] = _("מתי");
const u8 gEasyChatWord_What[] = _("מה");
const u8 gEasyChatWord_Deep[] = _("עמוק");
const u8 gEasyChatWord_Shallow[] = _("רדוד");
const u8 gEasyChatWord_Why[] = _("למה");
const u8 gEasyChatWord_Confused[] = _("מבולבל");
const u8 gEasyChatWord_Opposite[] = _("הפוך");
const u8 gEasyChatWord_Left[] = _("שמאל");
const u8 gEasyChatWord_Right[] = _("ימין");

const struct EasyChatWordInfo gEasyChatGroup_Misc[] = {
    [EC_INDEX(EC_WORD_HIGHS)] =
    {
        .text = gEasyChatWord_Highs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOWS)] =
    {
        .text = gEasyChatWord_Lows,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UM)] =
    {
        .text = gEasyChatWord_Um,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REAR)] =
    {
        .text = gEasyChatWord_Rear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINGS)] =
    {
        .text = gEasyChatWord_Things,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THING)] =
    {
        .text = gEasyChatWord_Thing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BESIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELOW)] =
    {
        .text = gEasyChatWord_Below,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOVE)] =
    {
        .text = gEasyChatWord_Above,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONFUSED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BACK)] =
    {
        .text = gEasyChatWord_Back,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEEP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIGH)] =
    {
        .text = gEasyChatWord_High,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE)] =
    {
        .text = gEasyChatWord_Here,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSIDE)] =
    {
        .text = gEasyChatWord_Inside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUTSIDE)] =
    {
        .text = gEasyChatWord_Outside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BESIDE)] =
    {
        .text = gEasyChatWord_Beside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS_IS_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThisIsItExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS)] =
    {
        .text = gEasyChatWord_This,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGHS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVERY)] =
    {
        .text = gEasyChatWord_Every,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE)] =
    {
        .text = gEasyChatWord_These,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEFT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE_WERE)] =
    {
        .text = gEasyChatWord_TheseWere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWN)] =
    {
        .text = gEasyChatWord_Down,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT)] =
    {
        .text = gEasyChatWord_That,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPOSITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_ARE)] =
    {
        .text = gEasyChatWord_ThoseAre,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUTSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_WERE)] =
    {
        .text = gEasyChatWord_ThoseWere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThatsItExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AM)] =
    {
        .text = gEasyChatWord_Am,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHALLOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_WAS)] =
    {
        .text = gEasyChatWord_ThatWas,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONT)] =
    {
        .text = gEasyChatWord_Front,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UP)] =
    {
        .text = gEasyChatWord_Up,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOICE)] =
    {
        .text = gEasyChatWord_Choice,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAR)] =
    {
        .text = gEasyChatWord_Far,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWAY)] =
    {
        .text = gEasyChatWord_Away,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEAR)] =
    {
        .text = gEasyChatWord_Near,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINGS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHERE)] =
    {
        .text = gEasyChatWord_Where,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN)] =
    {
        .text = gEasyChatWord_When,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS_IS_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT)] =
    {
        .text = gEasyChatWord_What,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_ARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEEP)] =
    {
        .text = gEasyChatWord_Deep,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHALLOW)] =
    {
        .text = gEasyChatWord_Shallow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHY)] =
    {
        .text = gEasyChatWord_Why,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONFUSED)] =
    {
        .text = gEasyChatWord_Confused,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OPPOSITE)] =
    {
        .text = gEasyChatWord_Opposite,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEFT)] =
    {
        .text = gEasyChatWord_Left,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIGHT)] =
    {
        .text = gEasyChatWord_Right,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHY),
        .enabled = TRUE,
    },
};
