const u8 gEasyChatWord_Opponent[] = _("יריב");
const u8 gEasyChatWord_I[] = _("אני");
const u8 gEasyChatWord_You[] = _("אתה");
const u8 gEasyChatWord_Yours[] = _("שלך");
const u8 gEasyChatWord_Son[] = _("בן");
const u8 gEasyChatWord_Your[] = _("שלך");
const u8 gEasyChatWord_Youre[] = _("אתה");
const u8 gEasyChatWord_Youve[] = _("יש לך");
const u8 gEasyChatWord_Mother[] = _("אמא");
const u8 gEasyChatWord_Grandfather[] = _("סבא");
const u8 gEasyChatWord_Uncle[] = _("דוד");
const u8 gEasyChatWord_Father[] = _("אבא");
const u8 gEasyChatWord_Boy[] = _("ילד");
const u8 gEasyChatWord_Adult[] = _("מבוגר");
const u8 gEasyChatWord_Brother[] = _("אח");
const u8 gEasyChatWord_Sister[] = _("אחות");
const u8 gEasyChatWord_Grandmother[] = _("סבתא");
const u8 gEasyChatWord_Aunt[] = _("דודה");
const u8 gEasyChatWord_Parent[] = _("הורה");
const u8 gEasyChatWord_Man[] = _("איש");
const u8 gEasyChatWord_Me[] = _("אותי");
const u8 gEasyChatWord_Girl[] = _("ילדה");
const u8 gEasyChatWord_Babe[] = _("מותק");
const u8 gEasyChatWord_Family[] = _("משפחה");
const u8 gEasyChatWord_Her[] = _("אותה");
const u8 gEasyChatWord_Him[] = _("אותו");
const u8 gEasyChatWord_He[] = _("הוא");
const u8 gEasyChatWord_Place[] = _("מקום");
const u8 gEasyChatWord_Daughter[] = _("בת");
const u8 gEasyChatWord_His[] = _("שלו");
const u8 gEasyChatWord_Hes[] = _("הוא");
const u8 gEasyChatWord_Arent[] = _("אינו");
const u8 gEasyChatWord_Siblings[] = _("ילדים");
const u8 gEasyChatWord_Kid[] = _("ילד");
const u8 gEasyChatWord_Children[] = _("ילדים");
const u8 gEasyChatWord_Mr[] = _("מר");
const u8 gEasyChatWord_Mrs[] = _("גברת");
const u8 gEasyChatWord_Myself[] = _("עצמי");
const u8 gEasyChatWord_IWas[] = _("אני");
const u8 gEasyChatWord_ToMe[] = _("אליי");
const u8 gEasyChatWord_My[] = _("שלי");
const u8 gEasyChatWord_IAm[] = _("אני");
const u8 gEasyChatWord_Ive[] = _("יש לי");
const u8 gEasyChatWord_Who[] = _("מי");
const u8 gEasyChatWord_Someone[] = _("מישהו");
const u8 gEasyChatWord_WhoWas[] = _("מי היה");
const u8 gEasyChatWord_ToWhom[] = _("למי");
const u8 gEasyChatWord_Whose[] = _("של מי");
const u8 gEasyChatWord_WhoIs[] = _("מי זה");
const u8 gEasyChatWord_Its[] = _("זה");
const u8 gEasyChatWord_Lady[] = _("עלמה");
const u8 gEasyChatWord_Friend[] = _("חבר");
const u8 gEasyChatWord_Ally[] = _("בעל ברית");
const u8 gEasyChatWord_Person[] = _("אדם");
const u8 gEasyChatWord_Dude[] = _("אח");
const u8 gEasyChatWord_They[] = _("הם");
const u8 gEasyChatWord_TheyWere[] = _("הם היו");
const u8 gEasyChatWord_ToThem[] = _("אליהם");
const u8 gEasyChatWord_Their[] = _("שלהם");
const u8 gEasyChatWord_Theyre[] = _("הם");
const u8 gEasyChatWord_Theyve[] = _("יש להם");
const u8 gEasyChatWord_We[] = _("אנחנו");
const u8 gEasyChatWord_Been[] = _("היינו");
const u8 gEasyChatWord_ToUs[] = _("אלינו");
const u8 gEasyChatWord_Our[] = _("שלנו");
const u8 gEasyChatWord_WeRe[] = _("אנחנו");
const u8 gEasyChatWord_Rival[] = _("יריב");
const u8 gEasyChatWord_Weve[] = _("יש לנו");
const u8 gEasyChatWord_Woman[] = _("אישה");
const u8 gEasyChatWord_She[] = _("היא");
const u8 gEasyChatWord_SheWas[] = _("היא הייתה");
const u8 gEasyChatWord_ToHer[] = _("אליה");
const u8 gEasyChatWord_Hers[] = _("שלה");
const u8 gEasyChatWord_SheIs[] = _("היא");
const u8 gEasyChatWord_Some[] = _("כמה");

const struct EasyChatWordInfo gEasyChatGroup_People[] = {
	[EC_INDEX(EC_WORD_OPPONENT)] =
	{
		.text = gEasyChatWord_Opponent,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FATHER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_I)] =
	{
		.text = gEasyChatWord_I,
		.alphabeticalOrder = EC_INDEX(EC_WORD_PERSON),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_YOU)] =
	{
		.text = gEasyChatWord_You,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_YOURS)] =
	{
		.text = gEasyChatWord_Yours,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HIM),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SON)] =
	{
		.text = gEasyChatWord_Son,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ME),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_YOUR)] =
	{
		.text = gEasyChatWord_Your,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BROTHER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_YOU_RE)] =
	{
		.text = gEasyChatWord_Youre,
		.alphabeticalOrder = EC_INDEX(EC_WORD_DUDE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_YOU_VE)] =
	{
		.text = gEasyChatWord_Youve,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SISTER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MOTHER)] =
	{
		.text = gEasyChatWord_Mother,
		.alphabeticalOrder = EC_INDEX(EC_WORD_AREN_T),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GRANDFATHER)] =
	{
		.text = gEasyChatWord_Grandfather,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MAN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_UNCLE)] =
	{
		.text = gEasyChatWord_Uncle,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WOMAN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FATHER)] =
	{
		.text = gEasyChatWord_Father,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TO_HER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BOY)] =
	{
		.text = gEasyChatWord_Boy,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TO_THEM),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ADULT)] =
	{
		.text = gEasyChatWord_Adult,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TO_ME),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BROTHER)] =
	{
		.text = gEasyChatWord_Brother,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TO_US),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SISTER)] =
	{
		.text = gEasyChatWord_Sister,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MOTHER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GRANDMOTHER)] =
	{
		.text = gEasyChatWord_Grandmother,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_AUNT)] =
	{
		.text = gEasyChatWord_Aunt,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WE_RE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_PARENT)] =
	{
		.text = gEasyChatWord_Parent,
		.alphabeticalOrder = EC_INDEX(EC_WORD_I),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MAN)] =
	{
		.text = gEasyChatWord_Man,
		.alphabeticalOrder = EC_INDEX(EC_WORD_I_WAS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ME)] =
	{
		.text = gEasyChatWord_Me,
		.alphabeticalOrder = EC_INDEX(EC_WORD_I_AM),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GIRL)] =
	{
		.text = gEasyChatWord_Girl,
		.alphabeticalOrder = EC_INDEX(EC_WORD_YOU),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BABE)] =
	{
		.text = gEasyChatWord_Babe,
		.alphabeticalOrder = EC_INDEX(EC_WORD_YOU_RE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FAMILY)] =
	{
		.text = gEasyChatWord_Family,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SON),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HER)] =
	{
		.text = gEasyChatWord_Her,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ALLY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HIM)] =
	{
		.text = gEasyChatWord_Him,
		.alphabeticalOrder = EC_INDEX(EC_WORD_DAUGHTER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HE)] =
	{
		.text = gEasyChatWord_He,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MRS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_PLACE)] =
	{
		.text = gEasyChatWord_Place,
		.alphabeticalOrder = EC_INDEX(EC_WORD_UNCLE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_DAUGHTER)] =
	{
		.text = gEasyChatWord_Daughter,
		.alphabeticalOrder = EC_INDEX(EC_WORD_AUNT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HIS)] =
	{
		.text = gEasyChatWord_His,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HE_S)] =
	{
		.text = gEasyChatWord_Hes,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HE_S),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_AREN_T)] =
	{
		.text = gEasyChatWord_Arent,
		.alphabeticalOrder = EC_INDEX(EC_WORD_PARENT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SIBLINGS)] =
	{
		.text = gEasyChatWord_Siblings,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SHE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_KID)] =
	{
		.text = gEasyChatWord_Kid,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SHE_IS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_CHILDREN)] =
	{
		.text = gEasyChatWord_Children,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SHE_WAS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MR)] =
	{
		.text = gEasyChatWord_Mr,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BEEN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MRS)] =
	{
		.text = gEasyChatWord_Mrs,
		.alphabeticalOrder = EC_INDEX(EC_WORD_THEY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MYSELF)] =
	{
		.text = gEasyChatWord_Myself,
		.alphabeticalOrder = EC_INDEX(EC_WORD_THEY_RE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_I_WAS)] =
	{
		.text = gEasyChatWord_IWas,
		.alphabeticalOrder = EC_INDEX(EC_WORD_THEY_WERE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TO_ME)] =
	{
		.text = gEasyChatWord_ToMe,
		.alphabeticalOrder = EC_INDEX(EC_WORD_IT_S),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_MY)] =
	{
		.text = gEasyChatWord_My,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FRIEND),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_I_AM)] =
	{
		.text = gEasyChatWord_IAm,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BOY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_I_VE)] =
	{
		.text = gEasyChatWord_Ive,
		.alphabeticalOrder = EC_INDEX(EC_WORD_KID),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WHO)] =
	{
		.text = gEasyChatWord_Who,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GIRL),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SOMEONE)] =
	{
		.text = gEasyChatWord_Someone,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SIBLINGS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WHO_WAS)] =
	{
		.text = gEasyChatWord_WhoWas,
		.alphabeticalOrder = EC_INDEX(EC_WORD_CHILDREN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TO_WHOM)] =
	{
		.text = gEasyChatWord_ToWhom,
		.alphabeticalOrder = EC_INDEX(EC_WORD_OPPONENT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WHOSE)] =
	{
		.text = gEasyChatWord_Whose,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RIVAL),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WHO_IS)] =
	{
		.text = gEasyChatWord_WhoIs,
		.alphabeticalOrder = EC_INDEX(EC_WORD_THEY_VE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_IT_S)] =
	{
		.text = gEasyChatWord_Its,
		.alphabeticalOrder = EC_INDEX(EC_WORD_I_VE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LADY)] =
	{
		.text = gEasyChatWord_Lady,
		.alphabeticalOrder = EC_INDEX(EC_WORD_YOU_VE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FRIEND)] =
	{
		.text = gEasyChatWord_Friend,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WE_VE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ALLY)] =
	{
		.text = gEasyChatWord_Ally,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SOME),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_PERSON)] =
	{
		.text = gEasyChatWord_Person,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TO_WHOM),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_DUDE)] =
	{
		.text = gEasyChatWord_Dude,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ADULT),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_THEY)] =
	{
		.text = gEasyChatWord_They,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BABE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_THEY_WERE)] =
	{
		.text = gEasyChatWord_TheyWere,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WHO),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TO_THEM)] =
	{
		.text = gEasyChatWord_ToThem,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WHO_WAS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_THEIR)] =
	{
		.text = gEasyChatWord_Their,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WHO_IS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_THEY_RE)] =
	{
		.text = gEasyChatWord_Theyre,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SOMEONE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_THEY_VE)] =
	{
		.text = gEasyChatWord_Theyve,
		.alphabeticalOrder = EC_INDEX(EC_WORD_PLACE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WE)] =
	{
		.text = gEasyChatWord_We,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MR),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_BEEN)] =
	{
		.text = gEasyChatWord_Been,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FAMILY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TO_US)] =
	{
		.text = gEasyChatWord_ToUs,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GRANDFATHER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_OUR)] =
	{
		.text = gEasyChatWord_Our,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GRANDMOTHER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WE_RE)] =
	{
		.text = gEasyChatWord_WeRe,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LADY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RIVAL)] =
	{
		.text = gEasyChatWord_Rival,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MYSELF),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WE_VE)] =
	{
		.text = gEasyChatWord_Weve,
		.alphabeticalOrder = EC_INDEX(EC_WORD_WHOSE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_WOMAN)] =
	{
		.text = gEasyChatWord_Woman,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HERS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SHE)] =
	{
		.text = gEasyChatWord_She,
		.alphabeticalOrder = EC_INDEX(EC_WORD_THEIR),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SHE_WAS)] =
	{
		.text = gEasyChatWord_SheWas,
		.alphabeticalOrder = EC_INDEX(EC_WORD_HIS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TO_HER)] =
	{
		.text = gEasyChatWord_ToHer,
		.alphabeticalOrder = EC_INDEX(EC_WORD_MY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_HERS)] =
	{
		.text = gEasyChatWord_Hers,
		.alphabeticalOrder = EC_INDEX(EC_WORD_YOURS),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SHE_IS)] =
	{
		.text = gEasyChatWord_SheIs,
		.alphabeticalOrder = EC_INDEX(EC_WORD_YOUR),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SOME)] =
	{
		.text = gEasyChatWord_Some,
		.alphabeticalOrder = EC_INDEX(EC_WORD_OUR),
		.enabled = TRUE,
	},
};
