const u8 gEasyChatWord_IChooseYou[] = _("אני בוחר בך");
const u8 gEasyChatWord_Gotcha[] = _("הבנתי אותך");
const u8 gEasyChatWord_Trade[] = _("החלפה");
const u8 gEasyChatWord_Sapphire[] = _("ספיר");
const u8 gEasyChatWord_Evolve[] = _("מתפתח");
const u8 gEasyChatWord_Encyclopedia[] = _("אנציקלופדיה");
const u8 gEasyChatWord_Nature[] = _("אופי");
const u8 gEasyChatWord_Center[] = _("מרכז");
const u8 gEasyChatWord_Egg[] = _("ביצה");
const u8 gEasyChatWord_Link[] = _("קישור");
const u8 gEasyChatWord_SpAbility[] = _("יכולת מ.");
const u8 gEasyChatWord_Trainer[] = _("מאמן");
const u8 gEasyChatWord_Version[] = _("גרסה");
const u8 gEasyChatWord_Pokenav[] = _("פוקינווט");
const u8 gEasyChatWord_Pokemon[] = _("פוקימון");
const u8 gEasyChatWord_Get[] = _("משיג");
const u8 gEasyChatWord_Pokedex[] = _("פוקידע");
const u8 gEasyChatWord_Ruby[] = _("רובי");
const u8 gEasyChatWord_Level[] = _("רמה");
const u8 gEasyChatWord_Red[] = _("אדום");
const u8 gEasyChatWord_Green[] = _("ירוק");
const u8 gEasyChatWord_Bag[] = _("תיק");
const u8 gEasyChatWord_Flame[] = _("להבה");
const u8 gEasyChatWord_Gold[] = _("זהב");
const u8 gEasyChatWord_Leaf[] = _("עלה");
const u8 gEasyChatWord_Silver[] = _("כסף");
const u8 gEasyChatWord_Emerald[] = _("ברקת");

const struct EasyChatWordInfo gEasyChatGroup_Trainer[] = {
	[EC_INDEX(EC_WORD_I_CHOOSE_YOU)] =
	{
		.text = gEasyChatWord_IChooseYou,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RED),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GOTCHA)] =
	{
		.text = gEasyChatWord_Gotcha,
		.alphabeticalOrder = EC_INDEX(EC_WORD_NATURE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TRADE)] =
	{
		.text = gEasyChatWord_Trade,
		.alphabeticalOrder = EC_INDEX(EC_WORD_I_CHOOSE_YOU),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SAPPHIRE)] =
	{
		.text = gEasyChatWord_Sapphire,
		.alphabeticalOrder = EC_INDEX(EC_WORD_ENCYCLOPEDIA),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_EVOLVE)] =
	{
		.text = gEasyChatWord_Evolve,
		.alphabeticalOrder = EC_INDEX(EC_WORD_EGG),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_ENCYCLOPEDIA)] =
	{
		.text = gEasyChatWord_Encyclopedia,
		.alphabeticalOrder = EC_INDEX(EC_WORD_EMERALD),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_NATURE)] =
	{
		.text = gEasyChatWord_Nature,
		.alphabeticalOrder = EC_INDEX(EC_WORD_VERSION),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_CENTER)] =
	{
		.text = gEasyChatWord_Center,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GOTCHA),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_EGG)] =
	{
		.text = gEasyChatWord_Egg,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TRADE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LINK)] =
	{
		.text = gEasyChatWord_Link,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GOLD),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_SP_ABILITY)] =
	{
		.text = gEasyChatWord_SpAbility,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SP_ABILITY),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_TRAINER)] =
	{
		.text = gEasyChatWord_Trainer,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GREEN),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_VERSION)] =
	{
		.text = gEasyChatWord_Version,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SILVER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_POKENAV)] =
	{
		.text = gEasyChatWord_Pokenav,
		.alphabeticalOrder = EC_INDEX(EC_WORD_FLAME),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_POKEMON)] =
	{
		.text = gEasyChatWord_Pokemon,
		.alphabeticalOrder = EC_INDEX(EC_WORD_TRAINER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_GET)] =
	{
		.text = gEasyChatWord_Get,
		.alphabeticalOrder = EC_INDEX(EC_WORD_CENTER),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_POKEDEX)] =
	{
		.text = gEasyChatWord_Pokedex,
		.alphabeticalOrder = EC_INDEX(EC_WORD_GET),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RUBY)] =
	{
		.text = gEasyChatWord_Ruby,
		.alphabeticalOrder = EC_INDEX(EC_WORD_EVOLVE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_LEVEL)] =
	{
		.text = gEasyChatWord_Level,
		.alphabeticalOrder = EC_INDEX(EC_WORD_SAPPHIRE),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_RED)] =
	{
		.text = gEasyChatWord_Red,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LEAF),
		.enabled = FALSE,
	},
	[EC_INDEX(EC_WORD_GREEN)] =
	{
		.text = gEasyChatWord_Green,
		.alphabeticalOrder = EC_INDEX(EC_WORD_POKEDEX),
		.enabled = FALSE,
	},
	[EC_INDEX(EC_WORD_BAG)] =
	{
		.text = gEasyChatWord_Bag,
		.alphabeticalOrder = EC_INDEX(EC_WORD_POKEMON),
		.enabled = TRUE,
	},
	[EC_INDEX(EC_WORD_FLAME)] =
	{
		.text = gEasyChatWord_Flame,
		.alphabeticalOrder = EC_INDEX(EC_WORD_POKENAV),
		.enabled = FALSE,
	},
	[EC_INDEX(EC_WORD_GOLD)] =
	{
		.text = gEasyChatWord_Gold,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LINK),
		.enabled = FALSE,
	},
	[EC_INDEX(EC_WORD_LEAF)] =
	{
		.text = gEasyChatWord_Leaf,
		.alphabeticalOrder = EC_INDEX(EC_WORD_RUBY),
		.enabled = FALSE,
	},
	[EC_INDEX(EC_WORD_SILVER)] =
	{
		.text = gEasyChatWord_Silver,
		.alphabeticalOrder = EC_INDEX(EC_WORD_LEVEL),
		.enabled = FALSE,
	},
	[EC_INDEX(EC_WORD_EMERALD)] =
	{
		.text = gEasyChatWord_Emerald,
		.alphabeticalOrder = EC_INDEX(EC_WORD_BAG),
		.enabled = TRUE,
	},
};
