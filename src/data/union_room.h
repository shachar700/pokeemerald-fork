ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("נא להתחיל מחדש מההתחלה.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("חיפוש מערכת התקשורת\nהאלחוטית בוטל.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("ממתין לתקשורת\nמשחקן אחר."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! ממתין\nלתקשורת משחקן אחר.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! ממתין לקישור!\nנא ללחוץ על TRATS כשכולם מוכנים.");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる"); // Unused
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる"); // Unused
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする"); // Unused

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("נדרש\nשחקן אחד.");
static const u8 sText_2PlayersNeeded[] = _("נדרשים\n2 שחקנים.");
static const u8 sText_3PlayersNeeded[] = _("נדרשים\n3 שחקנים.");
static const u8 sText_4PlayersNeeded[] = _("נדרשים\n4 שחקנים.");
static const u8 sText_2PlayerMode[] = _("מצב\nשחקנים 2");
static const u8 sText_3PlayerMode[] = _("מצב\n3 שחקנים");
static const u8 sText_4PlayerMode[] = _("מצב\n4 שחקנים");
static const u8 sText_5PlayerMode[] = _("מצב\n5 שחקנים");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}ביטול");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} יצר איתך קשר עבור\n{STR_VAR_1}. לאשר?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} יצר איתך קשר.\nהאם תשת{SWAP_PEY}{ADD_YUD} {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} יצר איתך קשר.\nלהוסיף לחברים?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nהאם החברים האלה בסדר?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("לבטל מצב {STR_VAR_1}\nעם החברים האלה?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("”בסדר“ נשלח\nל{STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("המאמן האחר נראה\nלא זמין כרגע…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("לא ניתן להעביר למאמן\nשנמצא רחוק מדי.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("המאמן)ים( האחר)ים( עדיין\nלא מוכן)ים(.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("מצב {STR_VAR_1} עם\nהחברים האלה יבוטל.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("יש חבר שכבר אינו\nיכול להישאר זמין.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("המאמן האחר נראה\nלא זמין…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} שלח חזרה ”בסדר“!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} אישר את הרשמתך\nכחבר.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} ענה, ”לא…“\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nממתין לחברים נוספים!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("להפסיק להיות חבר?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("הפסקת להיות חבר.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("קישור מערכת התקשורת\nהאלחוטית נוצר.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("קישור מערכת התקשורת\nהאלחוטית נותק…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("הקישור עם החבר נותק…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} ענה, ”לא…“");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("האם רוצה את\nמצב {STR_VAR_2}?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("האם רוצה את\nמצב {STR_VAR_2}?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("מתקשר…\nנא להמתין."); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("ממתין לתגובת {STR_VAR_1}\nלגבי ההחלפה…");
ALIGNED(4) static const u8 sText_Communicating[] = _("מתקשר{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                     "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("מתקשר עם {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                               "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("נא להמתין מעט{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                        "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("הייאה! יש משהו שרצית\nלעשות?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("שלום!\nרוצה לעשות משהו?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: הייאה, נפגשים שוב!\nמה רוצה לעשות הפעם?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: או! {PLAYER}, שלום!\nרוצה לעשות משהו?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("רוצה לעשות משהו?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("תרצי לעשות משהו?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: מה תרצה\nלעשות עכשיו?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: רוצה לעשות עוד משהו?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("מישהו יצר איתך קשר.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} יצר איתך קשר.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("ממתין לתגובה מהמאמן האחר…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("ממתין לתגובה\nמ{STR_VAR_1}…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("המאמן האחר הראה לך\nאת כרטיס המאמן שלו.\pהאם בא לך להראות את\nכרטיס המאמן שלך?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("המאמן האחר מאתגר אותך\nלקרב.\pהאם תקבל את\nהאתגר לקרב?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("המאמן האחר מזמין אותך\nלשוחח.\pהאם תקבל את\nההזמנה לשוחח?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("יש הצעה להחליף את\nהפוקימון הרשום שלך ברמה {DYNAMIC 0} {DYNAMIC 1}\nבתמורה לפוקימון\nברמה {DYNAMIC 2} {DYNAMIC 3}.\pהאם תקבל את\nהצעת ההחלפה?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("יש הצעה להחליף את\nהביצה הרשומה שלך.\lהאם תקבל את הצעת ההחלפה?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("השיחה הסתיימה.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("דחית את ההצעה.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("דחית את ההצעה.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("השיחה הסתיימה.\p");

// Unused
static const u8 *const sInvitationTexts[] = { //here i am
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("או, היי! אנחנו בשיחה עכשיו.\nרוצה להצטרף אלינו?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: היי, {PLAYER}!\nאנחנו בשיחה עכשיו.\lרוצה להצטרף אלינו?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("או, היי! אנחנו בשיחה עכשיו.\nרוצה להצטרף אלינו?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: או, היי, {PLAYER}!\nאנחנו בשיחה עכשיו.\lרוצה להצטרף אלינו?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nהמאמן נראה עסוק…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("קרב, הא?\nבסדר, רק שנייה, קצת זמן.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("רוצה לשוחח, הא?\nברור, פשוט המתן קצת.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("ברור לחלוטין! בתור ”ברכות,“\nהנה כרטיס המאמן שלי.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("קרב? בוודאי, אבל אני צריך\nזמן להתכונן.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("רצית לשוחח?\nבסדר, אבל נא להמתין רגע.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("כהיכרות, אראה לך\nאת כרטיס המאמן שלי.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("רצית לשוחח, הא?\nברור, פשוט נא להמתין קצת."); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("תודה שהמתנת!\nנתחיל את הקרב!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("מעולה!\nנשוחח!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("סליחה שגרמתי לך לחכות!\nנתחיל!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("סליחה שגרמתי לך לחכות!\nנשוחח.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("ההחלפה תתחיל.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("הקרב יתחיל.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("נכנס לשיחה…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("סליחה! הפוקימונים שלי לא\nמרגישים טוב עכשיו.\lנלחם בפעם אחרת.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("מצטערת מאוד, אבל הפוקימונים\nשלי לא מרגישים טוב…\pנלחם בפעם אחרת.\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("הא? כרטיס המאמן שלי…\nלאן הוא נעלם עכשיו?\lסליחה! אראה לך בפעם אחרת!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("הא? אז איפה שמתי את\nכרטיס המאמן?…\lסליחה! אראה לך אחר כך!\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("אם תרצה לעשות משהו איתי,\nפשוט תקרא לי!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("אם תרצי לעשות משהו איתי,\nאל תתביישי.\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("וופס! סליחה, אבל אני צריך\nלעשות משהו אחר.\lבפעם אחרת, בסדר?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("כדי להילחם, אתה צריך\nשני פוקימון שמתחת לרמה 03.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("כדי להילחם, אתה צריך\nשני פוקימון שמתחת לרמה 03.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("או, בסדר.\nתבוא לראות אותי בכל זמן, בסדר?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("או…\nתבואי בכל זמן.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("או, סליחה!\nפשוט אני לא יכול ברגע זה.\lנשוחח בפעם אחרת.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("או, אני מצטערת.\nיש לי יותר מדי לעשות עכשיו.\lנשוחח בפעם אחרת.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("וואה!\nאני רואה שאתה די חזק!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("השתמשת במהלך הזה?\nזו אסטרטגיה מצוינת!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("כל הכבוד לך!\nזה הפתיע אותי!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("או! איך יכולת להשתמש בפוקימון\nהזה במצב הזה?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("הפוקימון הזה…\nהוא גודל ממש טוב!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("זהו!\nזה המהלך הנכון עכשיו!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("זה מדהים!\nאפשר להילחם ככה?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("יש לך תזמון מעולה להחלפת\nפוקימונים!\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("או, אני רואה!\nזה מלמד!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("אל תגיד שום דבר מצחיק יותר!\nכואב לי מרוב צחוק!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("או?\nמשהו כזה קרה.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("המהמ… מה?\nאז זה מה שאתה אומר?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("באמת?\nלא ידעתי את זה.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("אהאהא!\nעל מה זה?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("כן, בדיוק זה!\nזה מה שהתכוונתי.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("במילים אחרות…\nכן! זה נכון!\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("אני פשוט מראה את כרטיס\nהמאמן שלי כברכת שלום.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("מקווה שאכיר אותך טוב יותר!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("אנחנו מראים אחד לשני את\nכרטיסי המאמן כדי להכיר.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("שמחה להכיר.\nאל תהיה זר!\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("יאהאהא!\nבאמת רציתי את הפוקימון הזה!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("סוף סוף, החלפה הביא לי את\nהפוקימון שרציתי הרבה זמן.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("אני מחליפה פוקימון עכשיו.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("לבסוף קיבלתי את הפוקימון\nשרציתי בהחלפה!\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} בדק את\nלוח ההחלפה.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("ברוכים הבאים ללוח ההחלפה.\pניתן לרשום את הפוקימון\nשלך להחלפה.\pהאם לרשום אחד\nמהפוקימונים שלך?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("לוח ההחלפה הזה משמש להצעת\n"
                                                        "פוקימון להחלפה.\p"
                                                        "כל מה שצריך זה לרשום\n"
                                                        "פוקימון להחלפה.\p"
                                                        "מאמן אחר עלול להציע פוקימון\n"
                                                        "לצוות עבור ההחלפה.\p"
                                                        "אנחנו מקווים שתרשמו פוקימון\n"
                                                        "ותחליפו עם הרבה, הרבה\l"
                                                        "מאמנים אחרים.\p"
                                                        "האם תרצו לרשום את אחד\nמהפוקימונים שלכם?");
                                                        
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("רשמנו את הפוקימון שלך\nלהחלפה בלוח ההחלפה.\pתודה שהשתמשת בשירות זה!\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("אף אחד לא רשם פוקימון\nלהחליף בלוח ההחלפה.\p\n"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("נא לבחור את סוג הפוקימון\nשהיית רוצה בהחלפה.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("איזה מהפוקימונים שלך\nתציע להחלפה?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("ההרשמה בוטלה.\p");
ALIGNED(4) static const u8 sText_RegistrationCompleted[] = _("ההרשמה הושלמה.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("ההחלפה בוטלה.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("לבטל את ההרשמה של הפוקימון\nברמה {STR_VAR_2} {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("לבטל את ההרשמה של\nהביצה?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("ההרשמה בוטלה.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("מאמנים שרוצים להחליף\nיופיעו ברשימה."); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("נא לבחור את המאמן איתו\nתרצו להחליף פוקימון."); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("האם תרצה לבקש מ{STR_VAR_1}\nלהחליף?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("ממתין לתגובה מהמאמן האחר…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("לא רשמת פוקימון להחלפה.\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("אין לך פוקימון מסוג {STR_VAR_2}\nש{STR_VAR_1} רוצה.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("אין לך ביצה\nש{STR_VAR_1} רוצה.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} לא יכול להחליף עבור\nהפוקימון שלך עכשיו.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("לא ניתן להחליף עבור \nהפוקימון של {STR_VAR_1} עכשיו.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("הצעת ההחלפה שלך נדחתה.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("החלפת ביצים");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}בחר  {A_BUTTON}הצטרף  {B_BUTTON}בטל");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("נא לבחור מאמן.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("נא לבחור מאמן לקרב\nיחיד.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("נא לבחור מאמן לקרב\nכפול.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("נא לבחור את המנהיג\nלקרב מרובה.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("נא לבחור את המאמן להחלפה איתו.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("נא לבחור את המאמן שמשתף\nכרטיסי פלא.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("נא לבחור את המאמן שמשתף\nחדשות פלא.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("לקפוץ עם פוקימון קטן!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("מעיכת פירות!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("אסיפת פירות דודריו!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("בלנדר פירות!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("פינת ההקלטות!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("תחרות מגניבות!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("תחרות יופי!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("תחרות חמידות!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("תחרות חוכמה!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("תחרות קשיחות!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("מגדל הקרבות רמה 05!\nנא לבחור את המנהיג.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("מגדל הקרבות רמה פתוחה!\nנא לבחור את המנהיג.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("מחפש מערכת תקשורת\nאלחוטית. להמתין…");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("כדי לקרב כפול, חייבים\nלפחות שני פוקימונים.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("ממתין לתגובת {STR_VAR_1}…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} נשאל לרשום\nאותך כחבר. נא להמתין.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("ממתין לתגובה ממערכת\nהתקשורת האלחוטית.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("נא להמתין למאמנים נוספים\nלהתאסף ולהתכונן."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("לא נראים כרטיסים משותפים\nעכשיו.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("לא נראות חדשות משותפות\nעכשיו.");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("קרב");
ALIGNED(4) static const u8 sText_Chat2[] = _("שיחה");
ALIGNED(4) static const u8 sText_Greetings[] = _("ברכות");
ALIGNED(4) static const u8 sText_Exit[] = _("יציאה");
ALIGNED(4) static const u8 sText_Exit2[] = _("יציאה");
ALIGNED(4) static const u8 sText_Info[] = _("מידע");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("שם{CLEAR_TO 60}מבוקש{CLEAR_TO 110}הצעה{CLEAR_TO 198}רמה.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("קרב יחיד");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("קרב כפול");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("קרב מרובה");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("החלפת פוקימון");
ALIGNED(4) static const u8 sText_Chat[] = _("שיחה");
ALIGNED(4) static const u8 sText_Cards[] = _("כרטיסים");
ALIGNED(4) static const u8 sText_WonderCards[] = _("כרטיסי פלא");
ALIGNED(4) static const u8 sText_WonderNews[] = _("חדשות פלא");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("קפיצת פוקימון");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("מעיכת פירות");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("איסוף פירות");
ALIGNED(4) static const u8 sText_Search[] = _("חיפוש");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("בלנדר פירות");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("פינת ההקלטות");
ALIGNED(4) static const u8 sText_CoolContest[] = _("תחרות מגניבות");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("תחרות יופי");
ALIGNED(4) static const u8 sText_CuteContest[] = _("תחרות חמידות");
ALIGNED(4) static const u8 sText_SmartContest[] = _("תחרות חוכמה");
ALIGNED(4) static const u8 sText_ToughContest[] = _("תחרות קשיחות");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("מגדל קרבות רמה 05");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("מגדל קרבות רמה פתוחה");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("זה כרטיס רגיל.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("זה כרטיס ארד!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("זה כרטיס נחושת!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("זה כרטיס כסף!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("זה כרטיס זהב!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("זה כרטיס המאמן של {DYNAMIC 1}\n{DYNAMIC 0}…\l{DYNAMIC 2}\pפוקידע: {DYNAMIC 3}\nזמן:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("קרבות: נצחונות: {DYNAMIC 0}  הפסדים: {DYNAMIC 2}\nהחלפות: {DYNAMIC 3}\p”{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}“\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: שמח שהכרתי אותך!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: שמחה להכיר אותך!{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("סיימתי לבדוק את כרטיס\nהמאמן של {DYNAMIC 1}.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
