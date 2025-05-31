const struct BattleFrontierTrainer gBattleFrontierTrainers[FRONTIER_TRAINERS_COUNT] =
{
    [FRONTIER_TRAINER_BRADY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("BRADY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NEVER, EC_WORD_GOING, EC_WORD_TO, EC_WORD_LOSE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_STRONG, EC_WORD_AREN_T, EC_WORD_I, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHAT, EC_WORD_QUES, EC_EMPTY_WORD, EC_WORD_BUT, EC_WORD_HOW, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Brady
=======
        .speechBefore = COMPOUND_STRING("I am never going to lose!"),
        .speechWin = COMPOUND_STRING("I am strong aren't I?"),
        .speechLose = COMPOUND_STRING("What? But how?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CONNER] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("CONNER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LOSING, EC_WORD_DOESN_T, EC_WORD_BUG, EC_WORD_ME, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A, EC_WORD_WIN, EC_WORD_IS, EC_WORD_JUST, EC_WORD_AWESOME, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_DARN, EC_WORD_ELLIPSIS, EC_WORD_LOSING, EC_WORD_DOES, EC_WORD_BUG, EC_WORD_ME},
        .monSet = gBattleFrontierTrainerMons_Conner
=======
        .speechBefore = COMPOUND_STRING("Losing doesn't bug me."),
        .speechWin = COMPOUND_STRING("A win is just awesome."),
        .speechLose = COMPOUND_STRING("Darn… Losing does bug me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRADLEY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("BRADLEY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_EXCL, EC_WORD_YOU_RE, EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_TODAY},
        .speechWin = {EC_WORD_HAHAHA, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_SEE_YA, EC_WORD_LATER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_TOMORROW, EC_WORD_IS, EC_WORD_WHEN, EC_WORD_WE, EC_WORD_REALLY, EC_WORD_BATTLE},
        .monSet = gBattleFrontierTrainerMons_Bradley
=======
        .speechBefore = COMPOUND_STRING("Hey there! You're my opponent today."),
        .speechWin = COMPOUND_STRING("Hahaha! See ya later!"),
        .speechLose = COMPOUND_STRING("Tomorrow is when we really battle."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CYBIL] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("CYBIL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_NOT_VERY, EC_WORD_SCARY, EC_WORD_AT, EC_WORD_ALL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SAD, EC_WORD_TO, EC_WORD_SEE, EC_WORD_YOU, EC_MOVE2(STRUGGLE)},
        .speechLose = {EC_WORD_THIS, EC_WORD_CAN_T, EC_WORD_BE, EC_WORD_HAPPENING, EC_WORD_TO_ME, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Cybil
=======
        .speechBefore = COMPOUND_STRING("You're really not very scary at all."),
        .speechWin = COMPOUND_STRING("It's sad to see you struggle."),
        .speechLose = COMPOUND_STRING("This can't be happening to me!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RODETTE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("RODETTE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_OH, EC_WORD_THIS, EC_WORD_IS, EC_WORD_SO, EC_WORD_EXCITING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_INCREDIBLE, EC_WORD_HOW, EC_WORD_STRONG, EC_WORD_I_AM, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OH_DEAR, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_NO, EC_WORD_GOOD},
        .monSet = gBattleFrontierTrainerMons_Rodette
=======
        .speechBefore = COMPOUND_STRING("Oh this is so exciting!"),
        .speechWin = COMPOUND_STRING("It's incredible how strong I am!"),
        .speechLose = COMPOUND_STRING("Oh, dear… I am just no good."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PEGGY] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("PEGGY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_GET, EC_WORD_READY, EC_WORD_TO, EC_WORD_BE, EC_WORD_DESTROYED, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HAHAHA, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_LOLLING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_SAD, EC_WORD_THANKS, EC_WORD_TO, EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Peggy
=======
        .speechBefore = COMPOUND_STRING("Get ready to be destroyed!"),
        .speechWin = COMPOUND_STRING("Hahaha!! I am lolling!"),
        .speechLose = COMPOUND_STRING("I am feeling sad thanks to you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KEITH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("KEITH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_JUST, EC_WORD_STUDY, EC_WORD_YOU, EC_WORD_KNOW},
        .speechWin = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_STUDY, EC_WORD_ENOUGH, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_NEED, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_MORE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Keith
=======
        .speechBefore = COMPOUND_STRING("I don't just study you know."),
        .speechWin = COMPOUND_STRING("You don't study enough…"),
        .speechLose = COMPOUND_STRING("I need to study more…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GRAYSON] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("GRAYSON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_BATTLE, EC_WORD_ISN_T, EC_WORD_CHILD_S_PLAY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_DONE, EC_WORD_AREN_T, EC_WORD_YOU, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WE, EC_WORD_WERE, EC_WORD_LIKE, EC_WORD_TOYS, EC_WORD_TO, EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Grayson
=======
        .speechBefore = COMPOUND_STRING("A Pokémon battle isn't child's play!"),
        .speechWin = COMPOUND_STRING("You're done aren't you?"),
        .speechLose = COMPOUND_STRING("We were like toys to you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GLENN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("GLENN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WOULD, EC_WORD_BE, EC_WORD_COOL, EC_WORD_IF_I_WIN, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_COOL, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_GOING, EC_WORD_TO, EC_WORD_BE, EC_WORD_COOL},
        .monSet = gBattleFrontierTrainerMons_Glenn
=======
        .speechBefore = COMPOUND_STRING("I would be cool if I win."),
        .speechWin = COMPOUND_STRING("Cool! That's what I am."),
        .speechLose = COMPOUND_STRING("I am not going to be cool."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LILIANA] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("LILIANA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WON_T, EC_WORD_GIVE_UP, EC_WORD_UNTIL, EC_WORD_I, EC_WORD_WIN},
        .speechWin = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NO, EC_WORD_SURRENDER, EC_WORD_IN, EC_WORD_ME},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_IT, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_GIVE_UP, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Liliana
=======
        .speechBefore = COMPOUND_STRING("I won't give up until I win."),
        .speechWin = COMPOUND_STRING("There is no surrender in me."),
        .speechLose = COMPOUND_STRING("That's it… I give up…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ELISE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ELISE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_STRATEGY, EC_WORD_IS, EC_WORD_FROM, EC_WORD_MY, EC_WORD_FATHER},
        .speechWin = {EC_WORD_I, EC_WORD_WIN, EC_WORD_EXCL, EC_WORD_FATHER, EC_WORD_I_VE, EC_WORD_WON},
        .speechLose = {EC_WORD_FORGIVE, EC_WORD_ME, EC_WORD_FATHER, EC_WORD_FOR, EC_WORD_I_VE, EC_WORD_LOST},
        .monSet = gBattleFrontierTrainerMons_Elise
=======
        .speechBefore = COMPOUND_STRING("My strategy is from my father."),
        .speechWin = COMPOUND_STRING("I win! Father I've won."),
        .speechLose = COMPOUND_STRING("Forgive me father for I've lost."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ZOEY] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ZOEY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_PLEASE, EC_WORD_BATTLE, EC_WORD_LIKE, EC_WORD_YOU, EC_WORD_MEAN, EC_WORD_IT},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_WORD_THANK_YOU, EC_WORD_SO, EC_WORD_MUCH},
        .speechLose = {EC_WORD_WERE, EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_BEING, EC_WORD_SERIOUS, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Zoey
=======
        .speechBefore = COMPOUND_STRING("Please battle like you mean it."),
        .speechWin = COMPOUND_STRING("Thank you!! Thank you so much."),
        .speechLose = COMPOUND_STRING("Were you really being serious?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MANUEL] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("MANUEL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_ME, EC_WORD_LOSE, EC_WORD_QUES, EC_WORD_THAT_S, EC_WORD_PREPOSTEROUS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NATURALLY, EC_WORD_I, EC_WORD_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_LOST, EC_WORD_MOTHER},
        .monSet = gBattleFrontierTrainerMons_Manuel
=======
        .speechBefore = COMPOUND_STRING("Me lose? That's preposterous!"),
        .speechWin = COMPOUND_STRING("Naturally I win."),
        .speechLose = COMPOUND_STRING("Waaah! I lost mother."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RUSS] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("RUSS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THEY, EC_WORD_ALL, EC_WORD_WANT, EC_WORD_MY, EC_WORD_FABULOUS, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_I, EC_WORD_WILL, EC_WORD_HAVE, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_PARTY},
        .speechLose = {EC_WORD_HOW, EC_WORD_COULD, EC_WORD_YOU, EC_WORD_DO, EC_WORD_THAT, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Russ
=======
        .speechBefore = COMPOUND_STRING("They all want my fabulous Pokémon."),
        .speechWin = COMPOUND_STRING("I will have a Pokémon party."),
        .speechLose = COMPOUND_STRING("How could you do that?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DUSTIN] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("DUSTIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_REALLY, EC_WORD_LIKE, EC_WORD_COOL, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_MYSELF, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_MYSELF, EC_WORD_IF_I_LOSE, EC_WORD_TOO, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dustin
=======
        .speechBefore = COMPOUND_STRING("I really like cool Pokémon."),
        .speechWin = COMPOUND_STRING("I like myself when I win!"),
        .speechLose = COMPOUND_STRING("I like myself if I lose too."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TINA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("TINA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_YOU, EC_WORD_CAN, EC_WORD_HAVE, EC_WORD_A, EC_MOVE2(SWEET_KISS)},
        .speechWin = {EC_WORD_HERE_IT_IS, EC_WORD_YOUR, EC_MOVE2(SWEET_KISS), EC_WORD_FROM, EC_WORD_MY, EC_POKEMON_NATIONAL(JYNX)},
        .speechLose = {EC_WORD_YOU, EC_WORD_WANT, EC_WORD_A, EC_MOVE(SWIFT), EC_MOVE2(MEGA_KICK), EC_WORD_INSTEAD},
        .monSet = gBattleFrontierTrainerMons_Tina
=======
        .speechBefore = COMPOUND_STRING("If I win you can have a sweet kiss."),
        .speechWin = COMPOUND_STRING("Here it is your sweet kiss from my Jynx."),
        .speechLose = COMPOUND_STRING("You want a swift mega kick instead."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GILLIAN1] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("GILLIAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THE, EC_WORD_GOURMET, EC_WORD_THING, EC_WORD_IS, EC_WORD_SO, EC_WORD_YESTERDAY},
        .speechWin = {EC_WORD_POKEMON, EC_WORD_NEVER, EC_WORD_GO, EC_WORD_OUT, EC_WORD_OF, EC_WORD_FASHION},
        .speechLose = {EC_WORD_LOSING, EC_WORD_DOESN_T, EC_WORD_DISAPPOINT, EC_WORD_ME, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gillian
=======
        .speechBefore = COMPOUND_STRING("The gourmet thing is so yesterday."),
        .speechWin = COMPOUND_STRING("Pokémon never go out of fashion."),
        .speechLose = COMPOUND_STRING("Losing doesn't disappoint me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ZOE] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("ZOE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_HAVEN_T, EC_WORD_A, EC_WORD_WORRY, EC_WORD_AT, EC_WORD_ALL},
        .speechWin = {EC_WORD_LIFE, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_GOOD, EC_WORD_TO_ME, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_WORRY, EC_WORD_ABOUT, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_SKILL},
        .monSet = gBattleFrontierTrainerMons_Zoe
=======
        .speechBefore = COMPOUND_STRING("I haven't a worry at all."),
        .speechWin = COMPOUND_STRING("Life is always good to me."),
        .speechLose = COMPOUND_STRING("I worry about my Pokémon skill."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CHEN] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("CHEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_TOTALLY, EC_WORD_READY, EC_WORD_TO, EC_WORD_ROCK, EC_WORD_TODAY},
        .speechWin = {EC_WORD_I_AM, EC_WORD_READY, EC_WORD_TO, EC_WORD_GO, EC_WORD_ON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_MY, EC_MOVE(FOCUS_ENERGY), EC_WORD_AND, EC_WORD_TOUGHNESS},
        .monSet = gBattleFrontierTrainerMons_Chen
=======
        .speechBefore = COMPOUND_STRING("I am totally ready to rock today."),
        .speechWin = COMPOUND_STRING("I am ready to go on!"),
        .speechLose = COMPOUND_STRING("I've lost my focus energy and toughness."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AL] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("AL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOUR, EC_WORD_LOOK, EC_WORD_SAYS, EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_TOUGH},
        .speechWin = {EC_WORD_IT_S, EC_WORD_ME, EC_WORD_WHO_IS, EC_WORD_REALLY, EC_WORD_TOUGH, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_RIGHT, EC_WORD_EXCL, EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_TOUGH},
        .monSet = gBattleFrontierTrainerMons_Al
=======
        .speechBefore = COMPOUND_STRING("Your look says you're really tough."),
        .speechWin = COMPOUND_STRING("It's me who is really tough."),
        .speechLose = COMPOUND_STRING("I am right! You're really tough."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MITCH] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("MITCH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_IS, EC_WORD_MY, EC_WORD_ALLY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WAS, EC_WORD_THAT, EC_WORD_ENOUGH, EC_WORD_FOR, EC_WORD_YOU, EC_WORD_QUES},
        .speechLose = {EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_DIDN_T, EC_WORD_LET_ME_WIN, EC_WORD_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Mitch
=======
        .speechBefore = COMPOUND_STRING("Mother nature is my ally!"),
        .speechWin = COMPOUND_STRING("Was that enough for you?"),
        .speechLose = COMPOUND_STRING("Mother nature didn't let me win?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ANNE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("ANNE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_LET_S, EC_WORD_BATTLE, EC_WORD_NOW},
        .speechWin = {EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_IS, EC_WORD_OVERWHELMING, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_DESTROYED, EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anne
=======
        .speechBefore = COMPOUND_STRING("I can't wait let's battle now."),
        .speechWin = COMPOUND_STRING("My happiness is overwhelming!"),
        .speechLose = COMPOUND_STRING("You've destroyed my happiness…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALIZE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("ALIZE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_CUTE, EC_WORD_AND, EC_WORD_AWFULLY, EC_WORD_STRONG, EC_WORD_THAT_S, EC_WORD_ME},
        .speechWin = {EC_WORD_YUP, EC_WORD_I_AM, EC_WORD_CUTE, EC_WORD_AND, EC_WORD_AWFULLY, EC_WORD_STRONG},
        .speechLose = {EC_WORD_I_AM, EC_WORD_WEAK, EC_WORD_ELLIPSIS, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_CUTE},
        .monSet = gBattleFrontierTrainerMons_Alize
=======
        .speechBefore = COMPOUND_STRING("Cute and awfully strong that's me."),
        .speechWin = COMPOUND_STRING("Yup I am cute and awfully strong."),
        .speechLose = COMPOUND_STRING("I am weak… But I am cute."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LAUREN] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("LAUREN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_OLD, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_ALSO, EC_WORD_GOOD},
        .speechWin = {EC_WORD_I, EC_WORD_SAID, EC_WORD_I_WAS, EC_WORD_OLD, EC_WORD_BUT, EC_WORD_GOOD},
        .speechLose = {EC_WORD_WHAT, EC_WORD_A, EC_WORD_WEIRD, EC_WORD_DREAM, EC_WORD_THAT_WAS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Lauren
=======
        .speechBefore = COMPOUND_STRING("I am old but I am also good."),
        .speechWin = COMPOUND_STRING("I said I was old but good."),
        .speechLose = COMPOUND_STRING("What a weird dream that was!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KIPP] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("KIPP"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_GO, EC_MOVE2(SURF)},
        .speechWin = {EC_WORD_YEAH, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_OFF, EC_WORD_TO, EC_MOVE2(SURF)},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_EXCL, EC_WORD_A, EC_MOVE(WHIRLPOOL), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kipp
=======
        .speechBefore = COMPOUND_STRING("If I win I am going to go surf."),
        .speechWin = COMPOUND_STRING("Yeah! I am off to surf."),
        .speechLose = COMPOUND_STRING("Oh no! A whirlpool!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JASON] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("JASON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_TEACH, EC_WORD_ME, EC_WORD_A, EC_WORD_GOOD, EC_WORD_STRATEGY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_YOUR, EC_WORD_GOOD, EC_WORD_STRATEGY, EC_WORD_QUES_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WOW, EC_WORD_THAT, EC_WORD_IS, EC_WORD_AN, EC_WORD_AWESOME, EC_WORD_STRATEGY},
        .monSet = gBattleFrontierTrainerMons_Jason
=======
        .speechBefore = COMPOUND_STRING("Teach me a good strategy."),
        .speechWin = COMPOUND_STRING("That was your good strategy?!"),
        .speechLose = COMPOUND_STRING("Wow that is an awesome strategy."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JOHN] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("JOHN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_PRETTY, EC_WORD_NEW, EC_WORD_TRAINER, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_NEW, EC_WORD_BUT, EC_WORD_I, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NEW, EC_WORD_SO, EC_WORD_WHAT, EC_WORD_IF_I_LOSE, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_John
=======
        .speechBefore = COMPOUND_STRING("I am a pretty new trainer."),
        .speechWin = COMPOUND_STRING("I am new but I won!"),
        .speechLose = COMPOUND_STRING("I am new so what if I lose?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ANN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ANN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IT_S, EC_WORD_SO, EC_WORD_EXCITING, EC_WORD_IT, EC_WORD_REALLY, EC_WORD_IS},
        .speechWin = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_HAPPY, EC_WORD_I, EC_WORD_CAN, EC_WORD_CRY},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SAD, EC_WORD_I, EC_WORD_WILL, EC_WORD_CRY},
        .monSet = gBattleFrontierTrainerMons_Ann
=======
        .speechBefore = COMPOUND_STRING("It's so exciting it really is."),
        .speechWin = COMPOUND_STRING("I am so happy I can cry."),
        .speechLose = COMPOUND_STRING("I am so sad I will cry."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EILEEN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("EILEEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_S, EC_WORD_PRETEND, EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_SO, EC_WORD_THIS, EC_WORD_IS, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_FEELING},
        .speechLose = {EC_WORD_AN, EC_WORD_ADULT, EC_WORD_CAN_T, EC_WORD_BEAT, EC_WORD_YOU, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Eileen
=======
        .speechBefore = COMPOUND_STRING("Let's pretend I am an adult ok ques."),
        .speechWin = COMPOUND_STRING("So this is an adult feeling."),
        .speechLose = COMPOUND_STRING("An adult can't beat you?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CARLIE] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("CARLIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_SUMMER, EC_WORD_VACATION, EC_WORD_IS, EC_WORD_FOR, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_MY, EC_WORD_SUMMER, EC_WORD_VACATION, EC_WORD_WILL, EC_WORD_BE, EC_WORD_AWESOME},
        .speechLose = {EC_WORD_I, EC_WORD_CAN_T_WIN, EC_WORD_LIKE, EC_WORD_THIS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Carlie
=======
        .speechBefore = COMPOUND_STRING("My summer vacation is for Pokémon."),
        .speechWin = COMPOUND_STRING("My summer vacation will be awesome."),
        .speechLose = COMPOUND_STRING("I can't win like this…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GORDON] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("GORDON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_VICTORY, EC_WORD_WILL, EC_WORD_COME, EC_WORD_TO_ME, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OH_YEAH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_REALLY, EC_WORD_WON},
        .speechLose = {EC_WORD_NOTHING, EC_WORD_IS, EC_WORD_WORKING, EC_WORD_OUT, EC_WORD_FOR, EC_WORD_ME},
        .monSet = gBattleFrontierTrainerMons_Gordon
=======
        .speechBefore = COMPOUND_STRING("Victory will come to me!"),
        .speechWin = COMPOUND_STRING("Oh, yeah! I really won."),
        .speechLose = COMPOUND_STRING("Nothing is working out for me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AYDEN] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("AYDEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_WORD_HOT, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_I, EC_WORD_NEED, EC_WORD_WATER, EC_WORD_TO, EC_WORD_COOL, EC_WORD_DOWN},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_ME, EC_WORD_FEELING, EC_WORD_ICE, EC_WORD_COLD},
        .monSet = gBattleFrontierTrainerMons_Ayden
=======
        .speechBefore = COMPOUND_STRING("Come on I need a hot battle."),
        .speechWin = COMPOUND_STRING("I need water to cool down."),
        .speechLose = COMPOUND_STRING("You have me feeling ice cold."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MARCO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("MARCO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE2(SURF), EC_WORD_IN, EC_WORD_THE, EC_WORD_WINTER, EC_WORD_TOO},
        .speechWin = {EC_WORD_I, EC_WORD_WILL, EC_WORD_GO, EC_MOVE2(SURF), EC_WORD_RIGHT, EC_WORD_NOW},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_MOVE2(BEAT_UP), EC_WORD_MY, EC_MOVE2(SURF), EC_WORD_BOARD},
        .monSet = gBattleFrontierTrainerMons_Marco
=======
        .speechBefore = COMPOUND_STRING("I surf in the winter too."),
        .speechWin = COMPOUND_STRING("I will go surf right now."),
        .speechLose = COMPOUND_STRING("I will beat up my surf board."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CIERRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("CIERRA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_SYNCHRONIZE, EC_WORD_MY, EC_WORD_SWIFT_SWIM},
        .speechWin = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_SYNCHRONIZE, EC_WORD_WITH, EC_WORD_ME, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_NEED, EC_WORD_TO, EC_WORD_SYNCHRONIZE, EC_WORD_BETTER, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Cierra
=======
        .speechBefore = COMPOUND_STRING("I like to synchronize my swift swim."),
        .speechWin = COMPOUND_STRING("My Pokémon synchronize with me."),
        .speechLose = COMPOUND_STRING("I need to synchronize better…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MARCY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("MARCY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_KNOCKOUT, EC_WORD_YOU, EC_WORD_CAN_T_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AFTER, EC_WORD_ALL, EC_WORD_I_AM, EC_WORD_A, EC_WORD_KNOCKOUT, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_NOT, EC_WORD_THE, EC_WORD_KNOCKOUT, EC_WORD_I, EC_WORD_MEAN},
        .monSet = gBattleFrontierTrainerMons_Marcy
=======
        .speechBefore = COMPOUND_STRING("I am a knockout you can't win!"),
        .speechWin = COMPOUND_STRING("After all I am a knockout!"),
        .speechLose = COMPOUND_STRING("That's not the knockout I mean."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KATHY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("KATHY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_VE, EC_WORD_WON, EC_WORD_EVERY, EC_WORD_MATCH, EC_WORD_TODAY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SO, EC_WORD_GREAT, EC_WORD_TO, EC_WORD_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_HUH_QUES, EC_WORD_I, EC_WORD_SHOULD, EC_WORD_NOT, EC_WORD_HAVE, EC_WORD_LOST},
        .monSet = gBattleFrontierTrainerMons_Kathy
=======
        .speechBefore = COMPOUND_STRING("I've won every match today!"),
        .speechWin = COMPOUND_STRING("It's so great to win!"),
        .speechLose = COMPOUND_STRING("Huh ques I should not have lost."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PEYTON] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("PEYTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NEVER, EC_WORD_DISAPPOINTED, EC_WORD_WITH, EC_WORD_MY, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_IF, EC_WORD_WE, EC_WORD_WIN, EC_WORD_TOGETHER},
        .speechLose = {EC_WORD_I, EC_WORD_ADORE, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_MORE, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Peyton
=======
        .speechBefore = COMPOUND_STRING("I am never disappointed with my Pokémon."),
        .speechWin = COMPOUND_STRING("I am happy if we win together."),
        .speechLose = COMPOUND_STRING("I adore my Pokémon more if I lose."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JULIAN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("JULIAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_ADORE, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_RIGHT, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOTALLY, EC_WORD_OUT, EC_WORD_OF, EC_WORD_THE, EC_WORD_QUESTION},
        .speechLose = {EC_WORD_YOU, EC_WORD_DO, EC_WORD_ADORE, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Julian
=======
        .speechBefore = COMPOUND_STRING("You adore your Pokémon right?"),
        .speechWin = COMPOUND_STRING("You're totally out of the question."),
        .speechLose = COMPOUND_STRING("You do adore your Pokémon!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_QUINN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("QUINN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_BUT, EC_WORD_A, EC_WORD_DREAM},
        .speechWin = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_A, EC_WORD_BEAUTIFUL, EC_WORD_DREAM, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_AN, EC_WORD_AWFUL, EC_MOVE(NIGHTMARE), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Quinn
=======
        .speechBefore = COMPOUND_STRING("My Pokémon are but a dream."),
        .speechWin = COMPOUND_STRING("This is a beautiful dream!"),
        .speechLose = COMPOUND_STRING("This is an awful nightmare!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HAYLEE] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("HAYLEE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_HOW, EC_WORD_I_AM, EC_WORD_FEELING},
        .speechWin = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_OVERWHELMING, EC_WORD_JOY, EC_WORD_OVER, EC_WORD_THIS},
        .speechLose = {EC_WORD_DESTROYED, EC_WORD_IS, EC_WORD_THE, EC_WORD_WAY, EC_WORD_I_AM, EC_WORD_FEELING},
        .monSet = gBattleFrontierTrainerMons_Haylee
=======
        .speechBefore = COMPOUND_STRING("I don't know how I am feeling."),
        .speechWin = COMPOUND_STRING("I am feeling overwhelming joy over this."),
        .speechLose = COMPOUND_STRING("Destroyed is the way I am feeling."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AMANDA] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("AMANDA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_COME, EC_WORD_FROM, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_FAMILY},
        .speechWin = {EC_WORD_I, EC_WORD_WILL, EC_WORD_TREASURE, EC_WORD_THIS, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_GO_HOME, EC_WORD_RIGHT, EC_WORD_NOW},
        .monSet = gBattleFrontierTrainerMons_Amanda
=======
        .speechBefore = COMPOUND_STRING("I come from a trainer family."),
        .speechWin = COMPOUND_STRING("I will treasure this win."),
        .speechLose = COMPOUND_STRING("I want to go home right now."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_STACY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("STACY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_HAVE, EC_WORD_THEIR, EC_WORD_OWN, EC_WORD_CUTE_CHARM},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_WHAT, EC_WORD_I, EC_WORD_MEAN, EC_WORD_QUES},
        .speechLose = {EC_WORD_SHOULD, EC_WORD_I, EC_WORD_NOT, EC_WORD_ADORE, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Stacy
=======
        .speechBefore = COMPOUND_STRING("All Pokémon have their own cute charm."),
        .speechWin = COMPOUND_STRING("You see what I mean?"),
        .speechLose = COMPOUND_STRING("Should I not adore Pokémon?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RAFAEL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("RAFAEL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_EXCL, EC_WORD_LET_S, EC_WORD_SEE, EC_WORD_SOME, EC_WORD_SPIRIT},
        .speechWin = {EC_WORD_THAT_S_IT_EXCL, EC_WORD_THAT_S, EC_WORD_THE, EC_WORD_SPIRIT, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WELL, EC_WORD_SO, EC_WORD_MUCH, EC_WORD_FOR, EC_WORD_OUR, EC_WORD_SPIRIT},
        .monSet = gBattleFrontierTrainerMons_Rafael
=======
        .speechBefore = COMPOUND_STRING("Come on! Let's see some spirit."),
        .speechWin = COMPOUND_STRING("That's it excl that's the spirit!"),
        .speechLose = COMPOUND_STRING("Well so much for our spirit."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_OLIVER] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("OLIVER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_GENIUS, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_HOW, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_WORKS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MORE, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_THAN, EC_WORD_I_AM},
        .monSet = gBattleFrontierTrainerMons_Oliver
=======
        .speechBefore = COMPOUND_STRING("A genius that's what I am!"),
        .speechWin = COMPOUND_STRING("That's how a genius works!"),
        .speechLose = COMPOUND_STRING("You're more a genius than I am."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PAYTON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("PAYTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_TRAIN, EC_WORD_FROM, EC_WORD_THE, EC_WORD_EGG, EC_WORD_UP},
        .speechWin = {EC_WORD_WELL, EC_WORD_DONE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_A, EC_MOVE2(SOFT_BOILED), EC_WORD_LOSS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Payton
=======
        .speechBefore = COMPOUND_STRING("I train from the egg up."),
        .speechWin = COMPOUND_STRING("Well done!"),
        .speechLose = COMPOUND_STRING("That was a soft boiled loss…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PAMELA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("PAMELA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_ADORE, EC_WORD_A, EC_WORD_KIND, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_IT_S, EC_WORD_TOO, EC_WORD_BAD, EC_WORD_YOU, EC_WORD_LOST, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_KIND, EC_WORD_AND, EC_WORD_YOU_RE, EC_WORD_ALSO, EC_WORD_STRONG},
        .monSet = gBattleFrontierTrainerMons_Pamela
=======
        .speechBefore = COMPOUND_STRING("All Pokémon adore a kind trainer."),
        .speechWin = COMPOUND_STRING("It's too bad you lost."),
        .speechLose = COMPOUND_STRING("You're kind and you're also strong."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ELIZA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("ELIZA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_ADORE, EC_WORD_POKEMON, EC_WORD_LIKE, EC_WORD_MY, EC_WORD_CHILDREN},
        .speechWin = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_HAPPY, EC_WORD_FOR, EC_WORD_MY, EC_WORD_POKEMON},
        .speechLose = {EC_WORD_OH_DEAR, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SORRY, EC_WORD_ABOUT, EC_WORD_THIS},
        .monSet = gBattleFrontierTrainerMons_Eliza
=======
        .speechBefore = COMPOUND_STRING("I adore Pokémon like my children."),
        .speechWin = COMPOUND_STRING("I am so happy for my Pokémon."),
        .speechLose = COMPOUND_STRING("Oh, dear I am so sorry about this."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MARISA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("MARISA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_PROMISE, EC_WORD_TO, EC_WORD_BATTLE, EC_WORD_SERIOUSLY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_PROMISE, EC_WORD_ME, EC_WORD_YOU, EC_WORD_WILL, EC_WORD_DO, EC_WORD_BETTER},
        .speechLose = {EC_WORD_PROMISE, EC_WORD_ME, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_PLEASE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Marisa
=======
        .speechBefore = COMPOUND_STRING("I promise to battle seriously."),
        .speechWin = COMPOUND_STRING("Promise me you will do better."),
        .speechLose = COMPOUND_STRING("Promise me another battle please!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LEWIS] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("LEWIS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A_LITTLE, EC_WORD_BUG, EC_WORD_IS, EC_WORD_SCARY, EC_WORD_QUES, EC_WORD_HAHAHA},
        .speechWin = {EC_WORD_LOOK, EC_WORD_LOOK, EC_WORD_EXCL, EC_WORD_A, EC_WORD_SCARY, EC_WORD_BUG},
        .speechLose = {EC_WORD_OH, EC_WORD_A, EC_WORD_BUG, EC_WORD_ISN_T, EC_WORD_SCARY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Lewis
=======
        .speechBefore = COMPOUND_STRING("A little bug is scary? Hahaha."),
        .speechWin = COMPOUND_STRING("Look look! A scary bug."),
        .speechLose = COMPOUND_STRING("Oh a bug isn't scary…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_YOSHI] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("YOSHI"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_FEELING, EC_WORD_LOVEY_DOVEY},
        .speechWin = {EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_THE, EC_WORD_BEST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_IGNORANT, EC_WORD_ABOUT, EC_WORD_BUG, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Yoshi
=======
        .speechBefore = COMPOUND_STRING("Bug Pokémon make me feeling lovey dovey."),
        .speechWin = COMPOUND_STRING("Bug Pokémon are the best!"),
        .speechLose = COMPOUND_STRING("You're ignorant about bug Pokémon."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DESTIN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("DESTIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IT_S, EC_WORD_WAY, EC_WORD_TOO, EC_WORD_HOT, EC_WORD_HERE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_ABOUT, EC_WORD_TO, EC_MOVE(OVERHEAT), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_I, EC_WORD_NEED, EC_WORD_SOME, EC_WORD_WATER, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Destin
=======
        .speechBefore = COMPOUND_STRING("It's way too hot here."),
        .speechWin = COMPOUND_STRING("I am about to overheat."),
        .speechLose = COMPOUND_STRING("Please I need some water."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KEON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("KEON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_FORGIVE, EC_WORD_ME, EC_WORD_BUT, EC_WORD_HERE_I_COME, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FORGIVE, EC_WORD_ME, EC_WORD_FOR, EC_WORD_MY, EC_WORD_OVERWHELMING, EC_WORD_POWER},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Keon
=======
        .speechBefore = COMPOUND_STRING("Forgive me but here I come!"),
        .speechWin = COMPOUND_STRING("Forgive me for my overwhelming power."),
        .speechLose = COMPOUND_STRING("I am sorry…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_STUART] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("STUART"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_PROMISE, EC_WORD_YOU, EC_WORD_A, EC_WORD_HOT, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_THE, EC_WORD_MASTER, EC_WORD_OF, EC_WORD_COOL, EC_WORD_THAT_S, EC_WORD_ME},
        .speechLose = {EC_WORD_I, EC_WORD_SEE, EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_SO, EC_WORD_COOL},
        .monSet = gBattleFrontierTrainerMons_Stuart
=======
        .speechBefore = COMPOUND_STRING("I promise you a hot battle."),
        .speechWin = COMPOUND_STRING("The master of cool that's me."),
        .speechLose = COMPOUND_STRING("I see I am not so cool."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_NESTOR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("NESTOR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_A, EC_WORD_REALLY, EC_WORD_SMOOTH, EC_WORD_MOVE},
        .speechWin = {EC_WORD_THERE, EC_WORD_WAS, EC_WORD_NOTHING, EC_WORD_SMOOTH, EC_WORD_ABOUT, EC_WORD_THAT},
        .speechLose = {EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_ARE, EC_WORD_SMOOTH, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Nestor
=======
        .speechBefore = COMPOUND_STRING("Show me a really smooth move."),
        .speechWin = COMPOUND_STRING("There was nothing smooth about that."),
        .speechLose = COMPOUND_STRING("You really are smooth!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DERRICK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("DERRICK"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_S, EC_WORD_SEE, EC_WORD_YOU, EC_MOVE2(MEDITATE), EC_WORD_LIKE, EC_WORD_ME},
        .speechWin = {EC_WORD_HOW, EC_WORD_I, EC_MOVE2(MEDITATE), EC_WORD_IS, EC_WORD_JUST, EC_WORD_BEAUTIFUL},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_MOVE2(MEDITATE), EC_WORD_FOR, EC_WORD_A, EC_MOVE2(CALM_MIND)},
        .monSet = gBattleFrontierTrainerMons_Derrick
=======
        .speechBefore = COMPOUND_STRING("Let's see you meditate like me."),
        .speechWin = COMPOUND_STRING("How I meditate is just beautiful."),
        .speechLose = COMPOUND_STRING("I will meditate for a calm mind."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRYSON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("BRYSON"),
<<<<<<< HEAD
        .speechBefore = {EC_MOVE2(POISON_POWDER), EC_WORD_IS, EC_WORD_IN, EC_WORD_OUR, EC_MOVE2(COTTON_SPORE), EC_WORD_MOVE},
        .speechWin = {EC_WORD_HOW_DO, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_OUR, EC_MOVE2(POISON_POWDER), EC_WORD_QUES},
        .speechLose = {EC_WORD_MY, EC_MOVE2(COTTON_SPORE), EC_WORD_WAS, EC_WORD_USELESS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bryson
=======
        .speechBefore = COMPOUND_STRING("Poison powder is in our cotton spore move."),
        .speechWin = COMPOUND_STRING("How do you like our poison powder?"),
        .speechLose = COMPOUND_STRING("My cotton spore was useless."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CLAYTON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("CLAYTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HUH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_WHERE, EC_WORD_IS_IT_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_IS_IT_QUES, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_MY, EC_WORD_POKENAV},
        .speechLose = {EC_WORD_WHERE, EC_WORD_IS_IT_QUES, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_MY, EC_WORD_SENSE},
        .monSet = gBattleFrontierTrainerMons_Clayton
=======
        .speechBefore = COMPOUND_STRING("Huh ques where is it ques."),
        .speechWin = COMPOUND_STRING("Where is it ques I've lost my pokenav."),
        .speechLose = COMPOUND_STRING("Where is it ques I've lost my sense."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TRENTON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("TRENTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME_OVER, EC_WORD_FOR, EC_WORD_SOME, EC_WORD_TASTY, EC_WORD_WATER, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MMM, EC_WORD_DO, EC_WORD_YOU, EC_WORD_WANT, EC_WORD_SOME, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_GOT, EC_WORD_THIS, EC_WORD_TASTY, EC_WORD_WATER, EC_WORD_SHOPPING},
        .monSet = gBattleFrontierTrainerMons_Trenton
=======
        .speechBefore = COMPOUND_STRING("Come over for some tasty water."),
        .speechWin = COMPOUND_STRING("Mmm do you want some?"),
        .speechLose = COMPOUND_STRING("I got this tasty water shopping."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JENSON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("JENSON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_DOWNCAST},
        .speechWin = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_DON_T, EC_WORD_MAKE, EC_WORD_THE, EC_MOVE(CUT)},
        .speechLose = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_TRAINER, EC_WORD_WHO_IS, EC_WORD_FEELING, EC_WORD_DOWNCAST},
        .monSet = gBattleFrontierTrainerMons_Jenson
=======
        .speechBefore = COMPOUND_STRING("My Pokémon will make you downcast."),
        .speechWin = COMPOUND_STRING("Your Pokémon don't make the cut."),
        .speechLose = COMPOUND_STRING("I am the trainer who is feeling downcast."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_WESLEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("WESLEY"),
<<<<<<< HEAD
        .speechBefore = {EC_POKEMON_NATIONAL(MEW), EC_POKEMON_NATIONAL(MEW), EC_WORD_IS, EC_WORD_HOW, EC_WORD_I, EC_WORD_CRY},
        .speechWin = {EC_WORD_YES, EC_WORD_I, EC_WORD_KNOW, EC_WORD_I_AM, EC_WORD_CUTE, EC_WORD_EXCL},
        .speechLose = {EC_POKEMON_NATIONAL(MEW), EC_POKEMON_NATIONAL(MEW), EC_WORD_EXCL, EC_POKEMON_NATIONAL(MEW), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Wesley
=======
        .speechBefore = COMPOUND_STRING("Mew Mew is how I cry."),
        .speechWin = COMPOUND_STRING("Yes I know I am cute!"),
        .speechLose = COMPOUND_STRING("Mew Mew! Mew!!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ANTON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("ANTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_GET, EC_WORD_READY, EC_WORD_FOR, EC_WORD_ME, EC_WORD_TO, EC_MOVE(THRASH)},
        .speechWin = {EC_WORD_WAHAHAHA, EC_WORD_EXCL, EC_WORD_SORRY, EC_WORD_ABOUT, EC_WORD_THAT, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_TOUGH, EC_WORD_LOSS, EC_WORD_TO, EC_MOVE2(SWALLOW)},
        .monSet = gBattleFrontierTrainerMons_Anton
=======
        .speechBefore = COMPOUND_STRING("Get ready for me to thrash."),
        .speechWin = COMPOUND_STRING("Wahahaha! Sorry about that!"),
        .speechLose = COMPOUND_STRING("It's a tough loss to swallow."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LAWSON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("LAWSON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_YOUNG, EC_WORD_AT, EC_WORD_HEART, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NOT, EC_WORD_COOL, EC_WORD_EXCL, EC_WORD_NOT, EC_WORD_AT, EC_WORD_ALL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_OLD, EC_WORD_AND, EC_WORD_FEELING, EC_WORD_SHAKY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Lawson
=======
        .speechBefore = COMPOUND_STRING("I am young at heart!"),
        .speechWin = COMPOUND_STRING("Not cool! Not at all."),
        .speechLose = COMPOUND_STRING("I am old and feeling shaky…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SAMMY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("SAMMY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_PARTY, EC_WORD_IS, EC_WORD_READY, EC_WORD_TO, EC_WORD_ROCK},
        .speechWin = {EC_WORD_MY, EC_WORD_PARTY, EC_WORD_IS, EC_WORD_JUST, EC_WORD_INCREDIBLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_CRY, EC_WORD_FOR, EC_WORD_MY, EC_WORD_PARTY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Sammy
=======
        .speechBefore = COMPOUND_STRING("My party is ready to rock."),
        .speechWin = COMPOUND_STRING("My party is just incredible!"),
        .speechLose = COMPOUND_STRING("I cry for my party…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ARNIE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("ARNIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NO_1, EC_WORD_I, EC_WORD_HAVE, EC_WORD_NO, EC_WORD_RIVAL},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_I, EC_WORD_CAN_T, EC_WORD_LOSE},
        .speechLose = {EC_WORD_NO, EC_WORD_EXCL, EC_WORD_I, EC_WORD_WON_T, EC_WORD_ACCEPT, EC_WORD_THIS},
        .monSet = gBattleFrontierTrainerMons_Arnie
=======
        .speechBefore = COMPOUND_STRING("I am no 1 I have no rival."),
        .speechWin = COMPOUND_STRING("You see? I can't lose."),
        .speechLose = COMPOUND_STRING("No! I won't accept this."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ADRIAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("ADRIAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YAHOO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_YAHOO, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_THANK_YOU, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GOOD_BYE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_GOOD_BYE, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Adrian
=======
        .speechBefore = COMPOUND_STRING("Yahoo! Yahoo!!"),
        .speechWin = COMPOUND_STRING("Thank you! Thank you!!"),
        .speechLose = COMPOUND_STRING("Good bye! Good bye!!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TRISTAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("TRISTAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_CONFUSED, EC_WORD_QUES, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS},
        .speechWin = {EC_WORD_SEE, EC_WORD_QUES, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_IN, EC_WORD_BATTLE},
        .monSet = gBattleFrontierTrainerMons_Tristan
=======
        .speechBefore = COMPOUND_STRING("Confused? I am a genius."),
        .speechWin = COMPOUND_STRING("See? I am a genius."),
        .speechLose = COMPOUND_STRING("I am not a genius in battle."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JULIANA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("JULIANA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_THINK, EC_WORD_I_AM, EC_WORD_SHOPPING, EC_WORD_TOO, EC_WORD_MUCH},
        .speechWin = {EC_WORD_BUT, EC_WORD_I, EC_WORD_WANT, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_PLUSH_DOLL},
        .speechLose = {EC_WORD_I, EC_WORD_SO, EC_WORD_WANT, EC_WORD_ANOTHER, EC_WORD_POKEMON, EC_WORD_PLUSH_DOLL},
        .monSet = gBattleFrontierTrainerMons_Juliana
=======
        .speechBefore = COMPOUND_STRING("I think I am shopping too much."),
        .speechWin = COMPOUND_STRING("But I want a Pokémon plush doll."),
        .speechLose = COMPOUND_STRING("I so want another Pokémon plush doll."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RYLEE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("RYLEE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_THAT, EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_GUTS},
        .speechWin = {EC_WORD_BYE_BYE, EC_WORD_EXCL, EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_NO, EC_WORD_GUTS},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_GUTSY, EC_WORD_ELLIPSIS, EC_WORD_YOU_RE, EC_WORD_QUITE, EC_WORD_SUPER},
        .monSet = gBattleFrontierTrainerMons_Rylee
=======
        .speechBefore = COMPOUND_STRING("Show me that you have guts."),
        .speechWin = COMPOUND_STRING("Bye bye! You have no guts."),
        .speechLose = COMPOUND_STRING("That was gutsy… You're quite super."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CHELSEA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("CHELSEA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_SERIOUSLY, EC_WORD_MEAN, EC_WORD_TO, EC_WORD_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_MY, EC_WORD_WILL, EC_WORD_TO, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_FAR, EC_WORD_TOO_STRONG, EC_WORD_FOR, EC_WORD_ME, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Chelsea
=======
        .speechBefore = COMPOUND_STRING("I seriously mean to win!"),
        .speechWin = COMPOUND_STRING("That was my will to win."),
        .speechLose = COMPOUND_STRING("You're far too strong for me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DANELA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("DANELA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_MUST_BE, EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_NOW, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OH_DEAR, EC_WORD_TOO_WEAK, EC_WORD_EXCL, EC_WORD_DON_T, EC_WORD_GIVE_UP, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_GOOD, EC_WORD_AND, EC_WORD_THIS, EC_WORD_IS, EC_WORD_GOOD_BYE},
        .monSet = gBattleFrontierTrainerMons_Danela
=======
        .speechBefore = COMPOUND_STRING("You must be my opponent now!"),
        .speechWin = COMPOUND_STRING("Oh, dear too weak! Don't give up!"),
        .speechLose = COMPOUND_STRING("That was good and this is good bye."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LIZBETH] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("LIZBETH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IF_I_LOSE, EC_WORD_YOU, EC_WORD_CAN, EC_WORD_HAVE, EC_WORD_A, EC_MOVE2(PRESENT)},
        .speechWin = {EC_WORD_HERE_IT_IS, EC_WORD_A_LITTLE, EC_WORD_PRAISE, EC_WORD_AS, EC_WORD_YOUR, EC_MOVE2(PRESENT)},
        .speechLose = {EC_WORD_YOUR, EC_MOVE2(PRESENT), EC_WORD_QUES_EXCL, EC_WORD_HERE_IT_IS, EC_WORD_A, EC_MOVE(DOUBLE_SLAP)},
        .monSet = gBattleFrontierTrainerMons_Lizbeth
=======
        .speechBefore = COMPOUND_STRING("If I lose you can have a present."),
        .speechWin = COMPOUND_STRING("Here it is a little praise as your present."),
        .speechLose = COMPOUND_STRING("Your present?! Here it is a double slap."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AMELIA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("AMELIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_BELIEVE, EC_WORD_IN, EC_WORD_CUTE, EC_WORD_FASHION, EC_WORD_APPEAL},
        .speechWin = {EC_WORD_YOUR, EC_WORD_FASHION, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_A, EC_WORD_DISASTER},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_AWFUL, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_HOME},
        .monSet = gBattleFrontierTrainerMons_Amelia
=======
        .speechBefore = COMPOUND_STRING("I believe in cute fashion appeal."),
        .speechWin = COMPOUND_STRING("Your fashion sense is a disaster."),
        .speechLose = COMPOUND_STRING("That was awful! I am going home."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JILLIAN] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("JILLIAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WHAT, EC_WORD_IS, EC_WORD_THAT, EC_WORD_I, EC_WORD_SMELL, EC_WORD_QUES},
        .speechWin = {EC_WORD_IT_S, EC_WORD_THE, EC_MOVE(SWEET_SCENT), EC_WORD_OF, EC_WORD_TASTY, EC_WORD_WATER},
        .speechLose = {EC_WORD_IT_S, EC_WORD_YOUR, EC_WORD_OFFENSIVE, EC_WORD_STENCH, EC_WORD_THAT_S, EC_WORD_WHAT},
        .monSet = gBattleFrontierTrainerMons_Jillian
=======
        .speechBefore = COMPOUND_STRING("What is that I smell?"),
        .speechWin = COMPOUND_STRING("It's the sweet scent of tasty water."),
        .speechLose = COMPOUND_STRING("It's your offensive stench that's what."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ABBIE] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("ABBIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_TRY, EC_WORD_MY, EC_WORD_SECRET, EC_MOVE(AROMATHERAPY), EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_MY, EC_MOVE(AROMATHERAPY), EC_WORD_IS, EC_WORD_TERRIBLE, EC_WORD_FOR, EC_WORD_YOU},
        .speechLose = {EC_WORD_DIDN_T, EC_WORD_YOU, EC_WORD_SMELL, EC_WORD_A, EC_WORD_THING, EC_WORD_QUES_EXCL},
        .monSet = gBattleFrontierTrainerMons_Abbie
=======
        .speechBefore = COMPOUND_STRING("You try my secret aromatherapy ok ques."),
        .speechWin = COMPOUND_STRING("My aromatherapy is terrible for you."),
        .speechLose = COMPOUND_STRING("Didn't you smell a thing?!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRIANA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("BRIANA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_BOY, EC_WORD_FRIEND, EC_WORD_WORKS, EC_WORD_TOO, EC_WORD_MUCH},
        .speechWin = {EC_WORD_I, EC_WORD_ONLY, EC_WORD_MISS, EC_WORD_HIM, EC_WORD_MORE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_LONESOME, EC_WORD_WITHOUT, EC_WORD_HIM, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Briana
=======
        .speechBefore = COMPOUND_STRING("My boy friend works too much."),
        .speechWin = COMPOUND_STRING("I only miss him more…"),
        .speechLose = COMPOUND_STRING("I am so lonesome without him…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ANTONIO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("ANTONIO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_HOW, EC_WORD_TO, EC_WORD_GO, EC_WORD_GO},
        .speechWin = {EC_WORD_BUT, EC_WORD_I, EC_WORD_DON_T, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_DANCE},
        .speechLose = {EC_WORD_GO, EC_WORD_GO, EC_WORD_ELLIPSIS, EC_WORD_JUST, EC_MOVE(FLAIL), EC_WORD_ABOUT},
        .monSet = gBattleFrontierTrainerMons_Antonio
=======
        .speechBefore = COMPOUND_STRING("I know how to go go."),
        .speechWin = COMPOUND_STRING("But I don't like to dance."),
        .speechLose = COMPOUND_STRING("Go go… Just flail about."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JADEN] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("JADEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HELLO, EC_WORD_I, EC_WORD_THINK, EC_WORD_I, EC_WORD_ADORE, EC_WORD_YOU},
        .speechWin = {EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_ME, EC_MOVE(THRASH), EC_WORD_IN, EC_MOVE2(FRUSTRATION)},
        .speechLose = {EC_WORD_THIS_IS_IT_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_GOOD_BYE, EC_WORD_FOREVER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jaden
=======
        .speechBefore = COMPOUND_STRING("Hello I think I adore you."),
        .speechWin = COMPOUND_STRING("You make me thrash in frustration."),
        .speechLose = COMPOUND_STRING("This is it excl good bye forever!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DAKOTA] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("DAKOTA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_DANCE, EC_WORD_WITH, EC_WORD_POWER},
        .speechWin = {EC_WORD_GOT, EC_WORD_IT, EC_WORD_QUES, EC_WORD_DANCE, EC_WORD_WITH, EC_WORD_POWER},
        .speechLose = {EC_WORD_OKAY, EC_WORD_YOU, EC_WORD_UNDERSTAND, EC_WORD_ALL_RIGHT, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dakota
=======
        .speechBefore = COMPOUND_STRING("You have to dance with power."),
        .speechWin = COMPOUND_STRING("Got it? Dance with power."),
        .speechLose = COMPOUND_STRING("Okay you understand all right!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRAYDEN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("BRAYDEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COLOR_CHANGE, EC_WORD_VERSION, EC_WORD_TOYS, EC_WORD_ARE, EC_WORD_USELESS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_ONLY, EC_WORD_COLLECT, EC_WORD_NORMAL, EC_WORD_VERSION, EC_WORD_TOYS},
        .speechLose = {EC_WORD_I, EC_MOVE2(ATTRACT), EC_WORD_COLOR_CHANGE, EC_WORD_VERSION, EC_WORD_TOYS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Brayden
=======
        .speechBefore = COMPOUND_STRING("Color change version toys are useless!"),
        .speechWin = COMPOUND_STRING("I only collect normal version toys."),
        .speechLose = COMPOUND_STRING("I attract color change version toys…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CORSON] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("CORSON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_GET, EC_WORD_TO, EC_MOVE2(BEAT_UP), EC_WORD_ON, EC_WORD_YOU},
        .speechWin = {EC_WORD_TOO, EC_WORD_EASY, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_COOL},
        .speechLose = {EC_WORD_WHY, EC_WORD_QUES_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_MOVE2(CURSE), EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Corson
=======
        .speechBefore = COMPOUND_STRING("I get to beat up on you."),
        .speechWin = COMPOUND_STRING("Too easy! I am so cool."),
        .speechLose = COMPOUND_STRING("Why?! I curse you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TREVIN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("TREVIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NONE, EC_WORD_BETTER, EC_WORD_THAN, EC_WORD_ME},
        .speechWin = {EC_WORD_YES_SIR_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST},
        .speechLose = {EC_WORD_SERIOUS, EC_WORD_QUES_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Trevin
=======
        .speechBefore = COMPOUND_STRING("There is none better than me."),
        .speechWin = COMPOUND_STRING("Yes sir excl I am the best."),
        .speechLose = COMPOUND_STRING("Serious?!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PATRICK] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("PATRICK"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_PERFECT, EC_WORD_EXCL, EC_WORD_GIVE_UP, EC_WORD_NOW, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DON_T, EC_WORD_BE, EC_WORD_DISAPPOINTED, EC_WORD_I_AM, EC_WORD_PERFECT, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BUT, EC_WORD_HOW, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_PERFECT, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Patrick
=======
        .speechBefore = COMPOUND_STRING("I am perfect! Give up now."),
        .speechWin = COMPOUND_STRING("Don't be disappointed I am perfect."),
        .speechLose = COMPOUND_STRING("But how? I am perfect…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KADEN] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("KADEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WHAT, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_UP, EC_WORD_TO, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_WERE, EC_WORD_A, EC_WORD_SURPRISE, EC_WORD_TO_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_WHO, EC_WORD_I_AM, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kaden
=======
        .speechBefore = COMPOUND_STRING("What are you up to?"),
        .speechWin = COMPOUND_STRING("You were a surprise to me!"),
        .speechLose = COMPOUND_STRING("I don't know who I am…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MAXWELL] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("MAXWELL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_WHO_IS, EC_WORD_YOUR, EC_WORD_RIVAL, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MY, EC_WORD_RIVAL, EC_WORD_IS, EC_WORD_MY, EC_WORD_GIRL, EC_WORD_FRIEND},
        .speechLose = {EC_WORD_I_AM, EC_WORD_MAKING, EC_WORD_YOU, EC_WORD_MY, EC_WORD_RIVAL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Maxwell
=======
        .speechBefore = COMPOUND_STRING("Hey there who is your rival?"),
        .speechWin = COMPOUND_STRING("My rival is my girl friend."),
        .speechLose = COMPOUND_STRING("I am making you my rival."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DARYL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("DARYL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_ONLY, EC_WORD_KNOW, EC_WORD_HOW, EC_WORD_TO, EC_MOVE(CHARGE)},
        .speechWin = {EC_WORD_AM, EC_WORD_I, EC_WORD_OVERWHELMING, EC_WORD_OR, EC_WORD_WHAT, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_GOING, EC_WORD_TO, EC_WORD_A, EC_WORD_LEGEND, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Daryl
=======
        .speechBefore = COMPOUND_STRING("I only know how to charge."),
        .speechWin = COMPOUND_STRING("Am I overwhelming or what?"),
        .speechLose = COMPOUND_STRING("You're going to a legend!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KENNETH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("KENNETH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_BETTER, EC_WORD_NOT, EC_MOVE2(SLACK_OFF), EC_WORD_WITH, EC_WORD_ME},
        .speechWin = {EC_WORD_DID, EC_WORD_MY, EC_MOVE2(TAUNT), EC_WORD_INTIMIDATE, EC_WORD_YOU, EC_WORD_QUES},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kenneth
=======
        .speechBefore = COMPOUND_STRING("You better not slack off with me."),
        .speechWin = COMPOUND_STRING("Did my taunt intimidate you?"),
        .speechLose = COMPOUND_STRING("I am sorry…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RICH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("RICH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOUR, EC_MOVE(FACADE), EC_WORD_DOESN_T, EC_MOVE2(TRICK), EC_WORD_ME, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SERIOUSLY, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_OK_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_REALLY, EC_WORD_TOUGH, EC_WORD_ON, EC_WORD_ME, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rich
=======
        .speechBefore = COMPOUND_STRING("Your facade doesn't trick me."),
        .speechWin = COMPOUND_STRING("Seriously are you really ok ques."),
        .speechLose = COMPOUND_STRING("That was really tough on me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CADEN] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("CADEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_BE, EC_WORD_DEFEATED, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FIRE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_FIRE, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_SO, EC_WORD_HOT},
        .monSet = gBattleFrontierTrainerMons_Caden
=======
        .speechBefore = COMPOUND_STRING("I can't be defeated!"),
        .speechWin = COMPOUND_STRING("Fire! Fire!!"),
        .speechLose = COMPOUND_STRING("I am tired… It's so hot."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MARLON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("MARLON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_A_LITTLE, EC_WORD_RADIO, EC_WORD_QUES},
        .speechWin = {EC_WORD_A_LITTLE, EC_WORD_RADIO, EC_WORD_HUH_QUES, EC_WORD_THAT_S, EC_WORD_TOTALLY, EC_WORD_COOL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_QUES, EC_WORD_IS, EC_WORD_POKENAV, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Marlon
=======
        .speechBefore = COMPOUND_STRING("A pokedex is a little radio?"),
        .speechWin = COMPOUND_STRING("A little radio huh ques that's totally cool."),
        .speechLose = COMPOUND_STRING("It's not? Is pokenav?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_NASH] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("NASH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ON, EC_WORD_FIRE, EC_WORD_BABY, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_LEFT, EC_WORD_YOU, EC_WORD_JUST, EC_WORD_AN, EC_MOVE2(EMBER)},
        .speechLose = {EC_WORD_AIYEEH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_WORD_NO, EC_WORD_WATER, EC_WORD_PLEASE},
        .monSet = gBattleFrontierTrainerMons_Nash
=======
        .speechBefore = COMPOUND_STRING("I am on fire baby!"),
        .speechWin = COMPOUND_STRING("I left you just an ember."),
        .speechLose = COMPOUND_STRING("Aiyeeh!! No water please."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ROBBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("ROBBY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HAHAHA, EC_WORD_EXCL, EC_WORD_HAPPY, EC_WORD_TO, EC_WORD_MEET_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_LEADER, EC_WORD_WITH, EC_WORD_REFRESHING, EC_WORD_SERENE_GRACE},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_MOVE(THRASH), EC_WORD_MY, EC_WORD_TOYS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Robby
=======
        .speechBefore = COMPOUND_STRING("Hahaha! Happy to meet you!"),
        .speechWin = COMPOUND_STRING("I am the leader with refreshing serene grace."),
        .speechLose = COMPOUND_STRING("I will thrash my toys!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_REECE] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("REECE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_MOVE2(QUICK_ATTACK), EC_WORD_CAN, EC_WORD_BEAT, EC_WORD_A, EC_MOVE2(TELEPORT)},
        .speechWin = {EC_WORD_LIKE, EC_WORD_I, EC_WORD_SAID, EC_WORD_I_AM, EC_WORD_DARN, EC_WORD_FAST},
        .speechLose = {EC_WORD_I_WAS, EC_WORD_KIDDING, EC_WORD_ABOUT, EC_WORD_THAT, EC_MOVE2(TELEPORT), EC_WORD_THING},
        .monSet = gBattleFrontierTrainerMons_Reece
=======
        .speechBefore = COMPOUND_STRING("My quick attack can beat a teleport."),
        .speechWin = COMPOUND_STRING("Like I said I am darn fast."),
        .speechLose = COMPOUND_STRING("I was kidding about that teleport thing."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KATHRYN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("KATHRYN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_TRAIN, EC_WORD_GOOD, EC_WORD_ENOUGH, EC_WORD_QUES},
        .speechWin = {EC_WORD_DON_T, EC_MOVE2(TAUNT), EC_WORD_ME, EC_WORD_LIKE, EC_WORD_THAT, EC_WORD_OK_QUES},
        .speechLose = {EC_WORD_WHY, EC_WORD_COULDN_T, EC_WORD_I, EC_WORD_WIN, EC_WORD_THIS, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Kathryn
=======
        .speechBefore = COMPOUND_STRING("I don't train good enough?"),
        .speechWin = COMPOUND_STRING("Don't taunt me like that ok ques."),
        .speechLose = COMPOUND_STRING("Why couldn't I win this?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ELLEN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("ELLEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_CRUSH, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_AN, EC_WORD_EGG, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_TASTY, EC_WORD_VICTORY, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_TOO, EC_WORD_TOUGH, EC_WORD_TO, EC_WORD_CRUSH, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ellen
=======
        .speechBefore = COMPOUND_STRING("Crush you like an egg!"),
        .speechWin = COMPOUND_STRING("That was a tasty victory for me."),
        .speechLose = COMPOUND_STRING("Too tough to crush!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RAMON] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("RAMON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_OKAY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_THIS, EC_WORD_IS, EC_WORD_PERFECTION},
        .speechWin = {EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_THAT, EC_WORD_I, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_SECRET, EC_WORD_WHY, EC_WORD_I_AM, EC_WORD_HAPPY},
        .monSet = gBattleFrontierTrainerMons_Ramon
=======
        .speechBefore = COMPOUND_STRING("Okay! This is perfection."),
        .speechWin = COMPOUND_STRING("I am happy that I won!"),
        .speechLose = COMPOUND_STRING("It's a secret why I am happy."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ARTHUR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ARTHUR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HERE_I_COME, EC_WORD_FEELING, EC_WORD_READY, EC_WORD_FOR, EC_WORD_IT, EC_WORD_ALL},
        .speechWin = {EC_WORD_THAT_S_IT_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_THAT_WAS, EC_WORD_FABULOUS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_NOT, EC_WORD_WHAT, EC_WORD_I, EC_WORD_NEED, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Arthur
=======
        .speechBefore = COMPOUND_STRING("Here I come feeling ready for it all."),
        .speechWin = COMPOUND_STRING("That's it excl that was fabulous!"),
        .speechLose = COMPOUND_STRING("That was not what I need."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALONDRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ALONDRA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_EVERY, EC_WORD_DAY, EC_WORD_IS, EC_WORD_A, EC_WORD_GREAT, EC_WORD_DAY},
        .speechWin = {EC_WORD_MY, EC_MOVE2(DIVE), EC_WORD_WILL, EC_WORD_BE, EC_WORD_A, EC_WORD_LEGEND},
        .speechLose = {EC_WORD_MY, EC_MOVE2(DIVE), EC_WORD_LEFT, EC_WORD_ME, EC_WORD_COLD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Alondra
=======
        .speechBefore = COMPOUND_STRING("Every day is a great day."),
        .speechWin = COMPOUND_STRING("My dive will be a legend."),
        .speechLose = COMPOUND_STRING("My dive left me cold…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ADRIANA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ADRIANA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME, EC_WORD_SEE, EC_WORD_AN, EC_WORD_INCREDIBLE, EC_WORD_SWIFT_SWIM, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_MAKE, EC_WORD_IT, EC_WORD_LOOK, EC_WORD_SO, EC_WORD_EASY},
        .speechLose = {EC_WORD_I_AM, EC_WORD_FEELING, EC_MOVE2(BEAT_UP), EC_WORD_AND, EC_WORD_TIRED, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Adriana
=======
        .speechBefore = COMPOUND_STRING("Come see an incredible swift swim!"),
        .speechWin = COMPOUND_STRING("I make it look so easy."),
        .speechLose = COMPOUND_STRING("I am feeling beat up and tired."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MALIK] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("MALIK"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_OH, EC_WORD_NOT, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_PLEASE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_I, EC_WORD_FINALLY, EC_WORD_WON, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_TIRED},
        .speechLose = {EC_WORD_I, EC_WORD_FINALLY, EC_WORD_LOST, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_TIRED},
        .monSet = gBattleFrontierTrainerMons_Malik
=======
        .speechBefore = COMPOUND_STRING("Oh not another battle please…"),
        .speechWin = COMPOUND_STRING("I finally won… I am tired."),
        .speechLose = COMPOUND_STRING("I finally lost… I am tired."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JILL] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("JILL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_MOVE2(QUICK_ATTACK), EC_WORD_TRAINER, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THE, EC_MOVE2(QUICK_ATTACK), EC_WORD_TRAINER, EC_WORD_WINS, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THE, EC_MOVE2(QUICK_ATTACK), EC_WORD_TRAINER, EC_WORD_GIVES, EC_WORD_UP, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jill
=======
        .speechBefore = COMPOUND_STRING("I am the quick attack trainer!"),
        .speechWin = COMPOUND_STRING("The quick attack trainer wins!"),
        .speechLose = COMPOUND_STRING("The quick attack trainer gives up!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ERIK] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("ERIK"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_SPEED_BOOST, EC_WORD_HERO, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_FROM, EC_WORD_THE, EC_WORD_SPEED_BOOST, EC_WORD_HERO, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_WORD_NO, EC_WORD_NO, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Erik
=======
        .speechBefore = COMPOUND_STRING("I am the speed boost hero!"),
        .speechWin = COMPOUND_STRING("Thank you from the speed boost hero!"),
        .speechLose = COMPOUND_STRING("Waaah!! No no!!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_YAZMIN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("YAZMIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WOULD, EC_WORD_RATHER, EC_WORD_RUN, EC_WORD_THAN, EC_WORD_BIKE},
        .speechWin = {EC_WORD_YES, EC_WORD_I, EC_WORD_WOULD, EC_WORD_MUCH, EC_WORD_RATHER, EC_WORD_RUN},
        .speechLose = {EC_WORD_BYE_BYE, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_RUN_AWAY},
        .monSet = gBattleFrontierTrainerMons_Yazmin
=======
        .speechBefore = COMPOUND_STRING("I would rather run than bike."),
        .speechWin = COMPOUND_STRING("Yes I would much rather run."),
        .speechLose = COMPOUND_STRING("Bye bye! I am going to run away."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JAMAL] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("JAMAL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_BE, EC_WORD_A, EC_WORD_FATHER},
        .speechWin = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_FOR, EC_WORD_MY, EC_WORD_BABY},
        .speechLose = {EC_WORD_MY, EC_WORD_BABY, EC_WORD_WILL, EC_WORD_BE, EC_WORD_TOTALLY, EC_WORD_AWESOME},
        .monSet = gBattleFrontierTrainerMons_Jamal
=======
        .speechBefore = COMPOUND_STRING("I am going to be a father."),
        .speechWin = COMPOUND_STRING("I can't wait for my baby."),
        .speechLose = COMPOUND_STRING("My baby will be totally awesome."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LESLIE] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("LESLIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_BE, EC_WORD_A, EC_WORD_MOTHER},
        .speechWin = {EC_WORD_A, EC_WORD_BABY, EC_WORD_WILL, EC_WORD_BE, EC_WORD_A_LITTLE, EC_WORD_CHALLENGE},
        .speechLose = {EC_WORD_I_AM, EC_WORD_TOO, EC_WORD_HAPPY, EC_WORD_TO, EC_WORD_BE, EC_WORD_ANGRY},
        .monSet = gBattleFrontierTrainerMons_Leslie
=======
        .speechBefore = COMPOUND_STRING("I am going to be a mother."),
        .speechWin = COMPOUND_STRING("A baby will be a little challenge."),
        .speechLose = COMPOUND_STRING("I am too happy to be angry."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DAVE] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("DAVE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WHAT, EC_WORD_SHOULD, EC_WORD_I, EC_WORD_DO, EC_WORD_TODAY, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_SHOULD, EC_WORD_ENJOY, EC_WORD_SOME, EC_WORD_SPORTS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_GO, EC_WORD_PLAY, EC_WORD_A, EC_WORD_GAME},
        .monSet = gBattleFrontierTrainerMons_Dave
=======
        .speechBefore = COMPOUND_STRING("What should I do today?"),
        .speechWin = COMPOUND_STRING("I should enjoy some sports!"),
        .speechLose = COMPOUND_STRING("I will go play a game."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CARLO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("CARLO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HAH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_WORD_YEAH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_DO, EC_WORD_THINGS, EC_WORD_AT, EC_MOVE(EXTREME_SPEED), EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_LOST, EC_WORD_AT, EC_MOVE(EXTREME_SPEED), EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Carlo
=======
        .speechBefore = COMPOUND_STRING("Hah!! Yeah!!"),
        .speechWin = COMPOUND_STRING("I do things at extreme speed!"),
        .speechLose = COMPOUND_STRING("I lost at extreme speed…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EMILIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("EMILIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_ME, EC_WORD_WORRY, EC_WORD_QUES, EC_WORD_I, EC_WORD_HAVE, EC_WORD_NONE},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_THAT_WAS, EC_WORD_FANTASTIC, EC_WORD_EXCL},
        .speechLose = {EC_WORD_AHAHA, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_THAT_WAS, EC_WORD_ENTERTAINING, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Emilia
=======
        .speechBefore = COMPOUND_STRING("Me worry? I have none."),
        .speechWin = COMPOUND_STRING("Ahaha see? That was fantastic!"),
        .speechLose = COMPOUND_STRING("Ahaha see? That was entertaining!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DALIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("DALIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_VERY, EC_WORD_EXPENSIVE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DON_T, EC_WORD_COME, EC_WORD_NEAR, EC_WORD_MY, EC_WORD_BIKE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_MY, EC_WORD_BEST, EC_WORD_FRIEND},
        .monSet = gBattleFrontierTrainerMons_Dalia
=======
        .speechBefore = COMPOUND_STRING("My bike is very expensive."),
        .speechWin = COMPOUND_STRING("Don't come near my bike!"),
        .speechLose = COMPOUND_STRING("My bike is my best friend."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HITOMI] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("HITOMI"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YEAH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_WORD_HAH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHAT, EC_WORD_QUES_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_WON, EC_WORD_QUES_EXCL},
        .speechLose = {EC_WORD_AIYEEH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Hitomi
=======
        .speechBefore = COMPOUND_STRING("Yeah!! Hah!!"),
        .speechWin = COMPOUND_STRING("What?! I won?!"),
        .speechLose = COMPOUND_STRING("Aiyeeh!! I am sorry!!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RICARDO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("RICARDO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_EXCL, EC_WORD_PLAY, EC_WORD_TIME, EC_WORD_IS, EC_WORD_OVER},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_OUT, EC_WORD_OF, EC_WORD_HERE, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_DON_T, EC_WORD_HIT, EC_WORD_ME, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ricardo
=======
        .speechBefore = COMPOUND_STRING("Come on! Play time is over."),
        .speechWin = COMPOUND_STRING("You're out of here!"),
        .speechLose = COMPOUND_STRING("Please don't hit me!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SHIZUKA] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("SHIZUKA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_THAT, EC_WORD_YOU_RE, EC_WORD_SERIOUS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_WON_T, EC_WORD_FORGET, EC_WORD_ABOUT, EC_WORD_YOU, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_PERFECT, EC_WORD_IN, EC_WORD_EVERY, EC_WORD_WAY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Shizuka
=======
        .speechBefore = COMPOUND_STRING("Show me that you're serious!"),
        .speechWin = COMPOUND_STRING("I won't forget about you."),
        .speechLose = COMPOUND_STRING("You're perfect in every way!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JOANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("JOANA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_GOING, EC_WORD_TO, EC_WORD_LOSE, EC_WORD_RIGHT, EC_WORD_AWAY},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_WINNER, EC_WORD_HEAR, EC_WORD_ME, EC_MOVE2(ROAR)},
        .speechLose = {EC_WORD_I, EC_WORD_REFUSE, EC_WORD_TO, EC_WORD_ACCEPT, EC_WORD_THAT, EC_MOVE(OUTRAGE)},
        .monSet = gBattleFrontierTrainerMons_Joana
=======
        .speechBefore = COMPOUND_STRING("You're going to lose right away."),
        .speechWin = COMPOUND_STRING("I am the winner hear me roar."),
        .speechLose = COMPOUND_STRING("I refuse to accept that outrage."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KELLY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("KELLY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_NIGHT, EC_WORD_SCHOOL, EC_WORD_IS, EC_WORD_REALLY, EC_WORD_SCARY},
        .speechWin = {EC_WORD_A, EC_WORD_LADY, EC_WORD_GHOST, EC_WORD_APPEARS, EC_WORD_THERE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THE, EC_WORD_HOME, EC_WORD_WORK, EC_WORD_IS, EC_WORD_AWFULLY, EC_WORD_SCARY},
        .monSet = gBattleFrontierTrainerMons_Kelly
=======
        .speechBefore = COMPOUND_STRING("My night school is really scary."),
        .speechWin = COMPOUND_STRING("A lady ghost appears there."),
        .speechLose = COMPOUND_STRING("The home work is awfully scary."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RAYNA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("RAYNA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NO_1, EC_WORD_WHEN, EC_WORD_IT_S, EC_WORD_ABOUT, EC_WORD_POWER},
        .speechWin = {EC_WORD_UNDERSTAND, EC_WORD_MY, EC_WORD_POWER, EC_WORD_NOW, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_TERRIBLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_TERRIBLE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Rayna
=======
        .speechBefore = COMPOUND_STRING("I am no 1 when it's about power."),
        .speechWin = COMPOUND_STRING("Understand my power now?"),
        .speechLose = COMPOUND_STRING("Terrible… I am terrible…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EVAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("EVAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_EVERY, EC_WORD_BATTLE, EC_WORD_HAS, EC_WORD_A, EC_WORD_SMELL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_THE, EC_MOVE(SWEET_SCENT), EC_WORD_OF, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_THE, EC_WORD_AWFUL, EC_WORD_STENCH, EC_WORD_OF, EC_WORD_A, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Evan
=======
        .speechBefore = COMPOUND_STRING("Every battle has a smell."),
        .speechWin = COMPOUND_STRING("Oh! The sweet scent of victory."),
        .speechLose = COMPOUND_STRING("The awful stench of a loss."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JORDAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JORDAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_GOOD, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_COME_ON, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_BEAT, EC_WORD_ME, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHAT, EC_WORD_QUES_EXCL, EC_EMPTY_WORD, EC_WORD_BUT, EC_WORD_HOW, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jordan
=======
        .speechBefore = COMPOUND_STRING("Good! Come on!!"),
        .speechWin = COMPOUND_STRING("You can't beat me!"),
        .speechLose = COMPOUND_STRING("What?! But how?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JOEL] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JOEL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joel
=======
        .speechBefore = COMPOUND_STRING("Fufufu…"),
        .speechWin = COMPOUND_STRING("Giggle…"),
        .speechLose = COMPOUND_STRING("Hahaha…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KRISTEN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("KRISTEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_A, EC_WORD_KID, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_JUST, EC_WORD_A_LITTLE, EC_WORD_KID, EC_WORD_AFTER, EC_WORD_ALL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_A, EC_WORD_TOUGH, EC_WORD_KID, EC_WORD_HUH_QUES, EC_WORD_HUMPH, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kristen
=======
        .speechBefore = COMPOUND_STRING("Hahaha… A kid…"),
        .speechWin = COMPOUND_STRING("Just a little kid after all!"),
        .speechLose = COMPOUND_STRING("A tough kid huh ques humph!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SELPHY] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("SELPHY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HUH_QUES, EC_WORD_WHAT, EC_WORD_IS_IT_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OH, EC_WORD_YES, EC_WORD_EXCL, EC_WORD_WHY, EC_WORD_NOT, EC_WORD_QUES},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_EXCL, EC_WORD_WHY, EC_WORD_NOT, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Selphy
=======
        .speechBefore = COMPOUND_STRING("Huh ques what is it ques."),
        .speechWin = COMPOUND_STRING("Oh yes! Why not?"),
        .speechLose = COMPOUND_STRING("Oh no! Why not?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CHLOE] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("CHLOE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME, EC_WORD_WE, EC_WORD_WILL, EC_WORD_DO, EC_WORD_BATTLE, EC_WORD_NOW},
        .speechWin = {EC_WORD_MORE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_STRONG, EC_WORD_YOU, EC_WORD_ARE},
        .monSet = gBattleFrontierTrainerMons_Chloe
=======
        .speechBefore = COMPOUND_STRING("Come we will do battle now."),
        .speechWin = COMPOUND_STRING("More! Another battle!"),
        .speechLose = COMPOUND_STRING("Oh! Strong you are."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_NORTON] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("NORTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_ONLY, EC_WORD_YOU, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCUSE_ME, EC_WORD_BUT, EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_PUSHOVER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_SOME, EC_WORD_KIND, EC_WORD_OF, EC_WORD_AWESOME, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Norton
=======
        .speechBefore = COMPOUND_STRING("I know only you."),
        .speechWin = COMPOUND_STRING("Excuse me but you're a pushover!"),
        .speechLose = COMPOUND_STRING("You're some kind of awesome!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LUKAS] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("LUKAS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_JOKING, EC_WORD_IS, EC_WORD_PRETTY, EC_WORD_TERRIBLE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_YOUR, EC_WORD_ROCK_HEAD, EC_WORD_EXISTS, EC_WORD_TO, EC_WORD_SHINE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOUR, EC_WORD_ROCK_HEAD, EC_WORD_COME, EC_WORD_TO, EC_WORD_SHINE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lukas
=======
        .speechBefore = COMPOUND_STRING("My joking is pretty terrible…"),
        .speechWin = COMPOUND_STRING("Your rock head exists to shine!"),
        .speechLose = COMPOUND_STRING("Your rock head come to shine."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ZACH] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("ZACH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_EXCELLENT, EC_MOVE2(MIMIC), EC_WORD_OF, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_LIKE, EC_WORD_A_LITTLE, EC_POKEMON_NATIONAL(TOGEPI), EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ANGRY, EC_WORD_LIKE, EC_WORD_A, EC_POKEMON_NATIONAL(MANKEY), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zach
=======
        .speechBefore = COMPOUND_STRING("I am an excellent mimic of Pokémon."),
        .speechWin = COMPOUND_STRING("I am happy like a little Togepi!"),
        .speechLose = COMPOUND_STRING("I am angry like a Mankey!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KAITLYN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("KAITLYN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_CRUSH, EC_WORD_THINGS, EC_WORD_WITH, EC_WORD_PSYCHIC, EC_WORD_POWER},
        .speechWin = {EC_WORD_MY, EC_WORD_VICTORY, EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_THE, EC_WORD_NEWS},
        .speechLose = {EC_WORD_NO, EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_THIS, EC_WORD_WON_T, EC_WORD_DO},
        .monSet = gBattleFrontierTrainerMons_Kaitlyn
=======
        .speechBefore = COMPOUND_STRING("I crush things with psychic power."),
        .speechWin = COMPOUND_STRING("My victory will make the news."),
        .speechLose = COMPOUND_STRING("No no… This won't do."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BREANNA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("BREANNA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_WILL, EC_WORD_CRUSH, EC_WORD_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HAVE, EC_WORD_SOME, EC_WORD_MORE, EC_WORD_OF, EC_WORD_THIS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_GUTS, EC_WORD_AND, EC_WORD_SKILL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Breanna
=======
        .speechBefore = COMPOUND_STRING("My Pokémon will crush you!"),
        .speechWin = COMPOUND_STRING("Have some more of this!"),
        .speechLose = COMPOUND_STRING("You have guts and skill."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KENDRA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("KENDRA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IF, EC_WORD_YOU_RE, EC_WORD_SMART, EC_WORD_STOP, EC_WORD_RIGHT, EC_WORD_NOW},
        .speechWin = {EC_WORD_I, EC_WORD_SAID, EC_WORD_THAT, EC_WORD_YOU, EC_WORD_SHOULD, EC_WORD_STOP},
        .speechLose = {EC_WORD_WHY, EC_WORD_DIDN_T, EC_WORD_YOU, EC_WORD_STOP, EC_WORD_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kendra
=======
        .speechBefore = COMPOUND_STRING("If you're smart stop right now."),
        .speechWin = COMPOUND_STRING("I said that you should stop."),
        .speechLose = COMPOUND_STRING("Why didn't you stop?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MOLLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("MOLLY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WILL, EC_WORD_MY, EC_WORD_CUTE_CHARM, EC_MOVE2(ATTRACT), EC_WORD_YOU, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_MY, EC_WORD_TOYS, EC_WORD_NOW},
        .speechLose = {EC_WORD_OH, EC_WORD_HOW, EC_WORD_COULD, EC_WORD_YOU, EC_WORD_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Molly
=======
        .speechBefore = COMPOUND_STRING("Will my cute charm attract you?"),
        .speechWin = COMPOUND_STRING("Your Pokémon are my toys now."),
        .speechLose = COMPOUND_STRING("Oh how could you?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JAZMIN] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("JAZMIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_FORECAST, EC_WORD_TERRIBLE, EC_WORD_THINGS, EC_WORD_FOR, EC_WORD_YOU},
        .speechWin = {EC_WORD_THERE, EC_WORD_WASN_T, EC_WORD_MY, EC_WORD_FORECAST, EC_WORD_RIGHT, EC_WORD_QUES},
        .speechLose = {EC_WORD_MY, EC_MOVE2(FORESIGHT), EC_WORD_DIDN_T, EC_WORD_SHOW, EC_WORD_ME, EC_WORD_THIS},
        .monSet = gBattleFrontierTrainerMons_Jazmin
=======
        .speechBefore = COMPOUND_STRING("I forecast terrible things for you."),
        .speechWin = COMPOUND_STRING("There wasn't my forecast right?"),
        .speechLose = COMPOUND_STRING("My foresight didn't show me this."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KELSEY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("KELSEY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_HAVEN_T, EC_WORD_SLEPT, EC_WORD_IN, EC_WORD_DAYS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_MY, EC_WORD_SLEEP, EC_WORD_WILL, EC_WORD_BE, EC_WORD_EXCELLENT, EC_WORD_NOW},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_DESTROYED, EC_WORD_MY, EC_WORD_SLEEP, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kelsey
=======
        .speechBefore = COMPOUND_STRING("I haven't slept in days…"),
        .speechWin = COMPOUND_STRING("My sleep will be excellent now."),
        .speechLose = COMPOUND_STRING("You have destroyed my sleep…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JALEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("JALEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_ALLOW, EC_WORD_POKEMON, EC_WORD_TO, EC_MOVE(THRASH)},
        .speechWin = {EC_WORD_HAHAHA, EC_WORD_EXCL, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_ANGRY, EC_WORD_QUES},
        .speechLose = {EC_WORD_WHY, EC_WORD_IS, EC_WORD_THIS, EC_WORD_SO, EC_WORD_HARD, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jalen
=======
        .speechBefore = COMPOUND_STRING("I don't allow Pokémon to thrash."),
        .speechWin = COMPOUND_STRING("Hahaha! Are you angry?"),
        .speechLose = COMPOUND_STRING("Why is this so hard?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GRIFFEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("GRIFFEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE2(SWALLOW), EC_MOVE2(SLUDGE), EC_WORD_TO, EC_MOVE2(TRANSFORM), EC_WORD_MYSELF},
        .speechWin = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_A, EC_MOVE(GROWTH), EC_WORD_OF, EC_MOVE2(ACID_ARMOR)},
        .speechLose = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_A, EC_MOVE(GROWTH), EC_WORD_OF, EC_WORD_SUCTION_CUPS},
        .monSet = gBattleFrontierTrainerMons_Griffen
=======
        .speechBefore = COMPOUND_STRING("I swallow sludge to transform myself."),
        .speechWin = COMPOUND_STRING("I have a growth of acid armor."),
        .speechLose = COMPOUND_STRING("I have a growth of suction cups."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_XANDER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("XANDER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_GOT, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ON, EC_WORD_RENTAL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_INCREDIBLE, EC_WORD_MY, EC_WORD_RENTAL, EC_WORD_POKEMON, EC_WORD_WON},
        .speechLose = {EC_WORD_RENTAL, EC_WORD_POKEMON, EC_WORD_AREN_T, EC_WORD_UP, EC_WORD_TO, EC_MOVE2(SCRATCH)},
        .monSet = gBattleFrontierTrainerMons_Xander
=======
        .speechBefore = COMPOUND_STRING("I got my Pokémon on rental."),
        .speechWin = COMPOUND_STRING("It's incredible my rental Pokémon won."),
        .speechLose = COMPOUND_STRING("Rental Pokémon aren't up to scratch."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MARVIN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("MARVIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_UP, EC_WORD_TO, EC_WORD_THE, EC_WORD_CHALLENGE, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_THINK, EC_WORD_YOU_RE, EC_WORD_GOOD, EC_WORD_ENOUGH},
        .speechLose = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_PERFECT, EC_WORD_THANK_YOU, EC_WORD_SO, EC_WORD_MUCH},
        .monSet = gBattleFrontierTrainerMons_Marvin
=======
        .speechBefore = COMPOUND_STRING("You're up to the challenge?"),
        .speechWin = COMPOUND_STRING("I didn't think you're good enough."),
        .speechLose = COMPOUND_STRING("I am feeling perfect thank you so much."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRENNAN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("BRENNAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE2(WISH), EC_WORD_TO, EC_WORD_SEE, EC_WORD_THE, EC_WORD_NEWS},
        .speechWin = {EC_WORD_COMICS, EC_WORD_GET, EC_WORD_DAMP, EC_WORD_FROM, EC_WORD_DRIZZLE, EC_WORD_QUES},
        .speechLose = {EC_WORD_THE, EC_WORD_TIGHT, EC_WORD_MONEY, EC_WORD_LIVING, EC_WORD_CHANNEL, EC_WORD_QUES_EXCL},
        .monSet = gBattleFrontierTrainerMons_Brennan
=======
        .speechBefore = COMPOUND_STRING("I wish to see the news."),
        .speechWin = COMPOUND_STRING("Comics get damp from drizzle?"),
        .speechLose = COMPOUND_STRING("The tight money living channel?!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BALEY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("BALEY"),
<<<<<<< HEAD
        .speechBefore = {EC_MOVE(SCREECH), EC_WORD_IS, EC_WORD_LIKE, EC_WORD_MUSIC, EC_WORD_TO_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_MY, EC_MOVE(SCREECH), EC_WORD_STRATEGY, EC_WORD_IS, EC_WORD_THE, EC_WORD_BEST},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_SOUNDPROOF, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Baley
=======
        .speechBefore = COMPOUND_STRING("Screech is like music to me!"),
        .speechWin = COMPOUND_STRING("My screech strategy is the best."),
        .speechLose = COMPOUND_STRING("You're soundproof?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ZACKARY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("ZACKARY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_CAN, EC_WORD_YOU, EC_MOVE(DIG), EC_WORD_IT, EC_WORD_YO, EC_WORD_QUES},
        .speechWin = {EC_MOVE2(TAKE_DOWN), EC_WORD_TAKE, EC_WORD_A, EC_MOVE2(DIVE), EC_WORD_YO, EC_WORD_YO},
        .speechLose = {EC_WORD_BREAK, EC_WORD_DOWN, EC_MOVE2(DIVE), EC_WORD_TIME, EC_WORD_FOR, EC_WORD_ME},
        .monSet = gBattleFrontierTrainerMons_Zackary
=======
        .speechBefore = COMPOUND_STRING("Can you dig it yo?"),
        .speechWin = COMPOUND_STRING("Take down take a dive yo yo."),
        .speechLose = COMPOUND_STRING("Break down dive time for me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GABRIEL] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("GABRIEL"),
<<<<<<< HEAD
        .speechBefore = {EC_MOVE2(POUND), EC_WORD_THE, EC_WORD_THICK_FAT, EC_WORD_ON, EC_WORD_MY, EC_MOVE2(BELLY_DRUM)},
        .speechWin = {EC_MOVE2(POUND), EC_WORD_MY, EC_MOVE2(BELLY_DRUM), EC_MOVE2(POUND), EC_WORD_MY, EC_MOVE2(BELLY_DRUM)},
        .speechLose = {EC_WORD_MY, EC_MOVE2(BELLY_DRUM), EC_WORD_WAS, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gabriel
=======
        .speechBefore = COMPOUND_STRING("Pound the thick fat on my belly drum."),
        .speechWin = COMPOUND_STRING("Pound my belly drum pound my belly drum."),
        .speechLose = COMPOUND_STRING("My belly drum was too weak…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EMILY] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("EMILY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HOW, EC_WORD_ABOUT, EC_WORD_A_TINY_BIT, EC_WORD_OF, EC_MOVE(HYPNOSIS), EC_WORD_QUES},
        .speechWin = {EC_WORD_MY, EC_MOVE(HYPNOSIS), EC_WORD_STRATEGY, EC_WORD_WORKS, EC_WORD_TO, EC_WORD_PERFECTION},
        .speechLose = {EC_WORD_MY, EC_MOVE(HYPNOSIS), EC_WORD_STRATEGY, EC_WORD_WENT, EC_WORD_BADLY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Emily
=======
        .speechBefore = COMPOUND_STRING("How about a tiny bit of hypnosis?"),
        .speechWin = COMPOUND_STRING("My hypnosis strategy works to perfection."),
        .speechLose = COMPOUND_STRING("My hypnosis strategy went badly…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JORDYN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("JORDYN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_MY, EC_WORD_SECRET, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_AS, EC_WORD_I, EC_WORD_APPEAR, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BUT, EC_WORD_HOW, EC_WORD_DID, EC_WORD_YOU, EC_WORD_KNOW, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jordyn
=======
        .speechBefore = COMPOUND_STRING("You don't know my secret…"),
        .speechWin = COMPOUND_STRING("I am not as I appear…"),
        .speechLose = COMPOUND_STRING("But how did you know?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SOFIA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("SOFIA"),
<<<<<<< HEAD
        .speechBefore = {EC_POKEMON(LOUDRED), EC_WORD_PROBABLY, EC_WORD_HAS, EC_WORD_A, EC_MOVE(SWEET_SCENT), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_THE, EC_WORD_FEELING, EC_WORD_THAT, EC_WORD_I, EC_WORD_GET},
        .speechLose = {EC_WORD_I, EC_WORD_WORK, EC_WORD_AT, EC_WORD_THE, EC_WORD_DEPT_STORE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Sofia
=======
        .speechBefore = COMPOUND_STRING("Loudred probably has a sweet scent."),
        .speechWin = COMPOUND_STRING("That's the feeling that I get."),
        .speechLose = COMPOUND_STRING("I work at the dept store."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRADEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("BRADEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_CHOOSE_YOU, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_THIS_IS_IT_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_PRETTY, EC_WORD_AWESOME, EC_WORD_ABOUT, EC_WORD_MYSELF},
        .speechLose = {EC_WORD_ALL_RIGHT, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_SURRENDER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Braden
=======
        .speechBefore = COMPOUND_STRING("I choose you! This is it excl."),
        .speechWin = COMPOUND_STRING("I am feeling pretty awesome about myself."),
        .speechLose = COMPOUND_STRING("All right! I surrender!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KAYDEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("KAYDEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THEY, EC_WORD_OVERDO, EC_WORD_THAT, EC_WORD_GOURMET, EC_WORD_THING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_THAT, EC_WORD_GOURMET, EC_WORD_THING, EC_WORD_ISN_T, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_HEY, EC_WORD_THIS, EC_WORD_IS, EC_WORD_PRETTY, EC_WORD_TASTY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kayden
=======
        .speechBefore = COMPOUND_STRING("They overdo that gourmet thing…"),
        .speechWin = COMPOUND_STRING("That gourmet thing isn't for me."),
        .speechLose = COMPOUND_STRING("Hey this is pretty tasty."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_COOPER] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("COOPER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THIS, EC_WORD_SHOULD, EC_WORD_ABSOLUTELY, EC_WORD_BE, EC_WORD_A, EC_WORD_PUSHOVER},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_TOO, EC_WORD_EXCITING, EC_WORD_FOR, EC_WORD_ME, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_SORRY, EC_WORD_I_AM, EC_WORD_SORRY},
        .monSet = gBattleFrontierTrainerMons_Cooper
=======
        .speechBefore = COMPOUND_STRING("This should absolutely be a pushover."),
        .speechWin = COMPOUND_STRING("That was too exciting for me…"),
        .speechLose = COMPOUND_STRING("Please! Sorry I am sorry."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JULIA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("JULIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SPIRIT, EC_WORD_ALONE, EC_WORD_WON_T, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_WIN},
        .speechWin = {EC_WORD_YOU, EC_WORD_SHOULD, EC_WORD_ACCEPT, EC_WORD_THIS, EC_WORD_WITH, EC_WORD_SERENE_GRACE},
        .speechLose = {EC_WORD_FOR_NOW, EC_WORD_GOOD_BYE, EC_WORD_BUT, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_OVER},
        .monSet = gBattleFrontierTrainerMons_Julia
=======
        .speechBefore = COMPOUND_STRING("Spirit alone won't make you win."),
        .speechWin = COMPOUND_STRING("You should accept this with serene grace."),
        .speechLose = COMPOUND_STRING("For now good bye but it's not over."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AMARA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("AMARA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WROOOAAR_EXCL, EC_WORD_EXCL_EXCL, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_READY, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_LOSE, EC_WORD_MYSELF, EC_WORD_IF, EC_WORD_IT_S, EC_WORD_EXCITING},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_TO, EC_MOVE2(TACKLE), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Amara
=======
        .speechBefore = COMPOUND_STRING("Wroooaar!!! I am so ready!!"),
        .speechWin = COMPOUND_STRING("I lose myself if it's exciting."),
        .speechLose = COMPOUND_STRING("That's too much to tackle!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LYNN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("LYNN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOUR, EC_WORD_SECRET, EC_WORD_CAN_T, EC_WORD_BE, EC_WORD_HIDDEN, EC_WORD_FOREVER},
        .speechWin = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_YOUR, EC_WORD_SECRET, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_CAN_T, EC_MOVE(SAFEGUARD), EC_WORD_YOUR, EC_WORD_OWN, EC_WORD_SECRET},
        .monSet = gBattleFrontierTrainerMons_Lynn
=======
        .speechBefore = COMPOUND_STRING("Your secret can't be hidden forever."),
        .speechWin = COMPOUND_STRING("I know your secret now!"),
        .speechLose = COMPOUND_STRING("You can't safeguard your own secret."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JOVAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("JOVAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOUR, EC_WORD_BATTLE, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_SADLY, EC_WORD_LACKING},
        .speechWin = {EC_WORD_MY, EC_WORD_BATTLE, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_COOL, EC_WORD_ISN_T_IT_QUES},
        .speechLose = {EC_WORD_I_WAS, EC_WORD_MINUS, EC_WORD_MY, EC_WORD_NORMAL, EC_WORD_POWER, EC_WORD_TODAY},
        .monSet = gBattleFrontierTrainerMons_Jovan
=======
        .speechBefore = COMPOUND_STRING("Your battle sense is sadly lacking."),
        .speechWin = COMPOUND_STRING("My battle sense is cool isn't it ques."),
        .speechLose = COMPOUND_STRING("I was minus my normal power today."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DOMINIC] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("DOMINIC"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_THIS, EC_WORD_EXCELLENT, EC_WORD_CAMERA, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MY, EC_WORD_CAMERA, EC_WORD_WAS, EC_WORD_AWFULLY, EC_WORD_EXPENSIVE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MY, EC_WORD_CAMERA, EC_WORD_DOESN_T, EC_WORD_MISS, EC_WORD_A, EC_WORD_THING},
        .monSet = gBattleFrontierTrainerMons_Dominic
=======
        .speechBefore = COMPOUND_STRING("I have this excellent camera."),
        .speechWin = COMPOUND_STRING("My camera was awfully expensive."),
        .speechLose = COMPOUND_STRING("My camera doesn't miss a thing."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_NIKOLAS] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("NIKOLAS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE2(MIMIC), EC_WORD_POKEMON, EC_WORD_AFTER, EC_WORD_EVERY, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_I, EC_WORD_PRETEND, EC_WORD_I_AM, EC_WORD_A, EC_POKEMON_NATIONAL(TAUROS)},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_I, EC_WORD_PRETEND, EC_WORD_I_AM, EC_WORD_A, EC_POKEMON_NATIONAL(MILTANK)},
        .monSet = gBattleFrontierTrainerMons_Nikolas
=======
        .speechBefore = COMPOUND_STRING("I mimic Pokémon after every battle."),
        .speechWin = COMPOUND_STRING("If I win I pretend I am a Tauros."),
        .speechLose = COMPOUND_STRING("If I lose I pretend I am a Miltank."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_VALERIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("VALERIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE2(WISH), EC_WORD_YOU, EC_WORD_WOULD, EC_WORD_NOT, EC_MOVE2(GLARE)},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_MEAN, EC_WORD_EXCL, EC_WORD_I, EC_WORD_MEAN, EC_WORD_REALLY},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_A, EC_WORD_REALLY, EC_MOVE(SCARY_FACE), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Valeria
=======
        .speechBefore = COMPOUND_STRING("I wish you would not glare."),
        .speechWin = COMPOUND_STRING("You're mean! I mean really."),
        .speechLose = COMPOUND_STRING("You have a really scary face!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DELANEY] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("DELANEY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SCHOOL, EC_WORD_IS, EC_WORD_OVER, EC_WORD_TIME, EC_WORD_TO, EC_WORD_PLAY},
        .speechWin = {EC_WORD_MY, EC_WORD_BOY, EC_WORD_FRIEND, EC_WORD_IS, EC_WORD_FROM, EC_WORD_SCHOOL},
        .speechLose = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_WORK, EC_WORD_NEXT, EC_WORD_WEEK},
        .monSet = gBattleFrontierTrainerMons_Delaney
=======
        .speechBefore = COMPOUND_STRING("School is over time to play."),
        .speechWin = COMPOUND_STRING("My boy friend is from school."),
        .speechLose = COMPOUND_STRING("I have to work next week."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MEGHAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("MEGHAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SCHOOL, EC_WORD_IS, EC_WORD_OUT, EC_WORD_TIME, EC_WORD_TO, EC_WORD_PLAY},
        .speechWin = {EC_WORD_MY, EC_WORD_BOY, EC_WORD_FRIEND, EC_WORD_LIKES, EC_WORD_COMICS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IT_S, EC_WORD_BACK, EC_WORD_TO, EC_WORD_SCHOOL, EC_WORD_SOON, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Meghan
=======
        .speechBefore = COMPOUND_STRING("School is out time to play."),
        .speechWin = COMPOUND_STRING("My boy friend likes comics."),
        .speechLose = COMPOUND_STRING("It's back to school soon."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ROBERTO] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("ROBERTO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_INVINCIBLE, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YOU, EC_WORD_WEREN_T, EC_WORD_BAD, EC_WORD_I_WAS, EC_WORD_JUST, EC_WORD_BETTER},
        .speechLose = {EC_WORD_AREN_T, EC_WORD_YOU, EC_WORD_SATISFIED, EC_WORD_YET, EC_WORD_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Roberto
=======
        .speechBefore = COMPOUND_STRING("Dragon Pokémon are invincible!"),
        .speechWin = COMPOUND_STRING("You weren't bad I was just better."),
        .speechLose = COMPOUND_STRING("Aren't you satisfied yet?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DAMIAN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DAMIAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_PURE_POWER, EC_WORD_IS, EC_WORD_MACHINE, EC_WORD_LIKE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_MY, EC_MOVE2(MACH_PUNCH), EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_A, EC_MOVE(BRICK_BREAK)},
        .speechLose = {EC_WORD_ARRGH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_NO, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Damian
=======
        .speechBefore = COMPOUND_STRING("My pure power is machine like!"),
        .speechWin = COMPOUND_STRING("My mach punch will make a brick break."),
        .speechLose = COMPOUND_STRING("Arrgh! No!!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRODY] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("BRODY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_FASHION, EC_WORD_SENSE, EC_WORD_SEEMS, EC_POKEMON(ODDISH), EC_WORD_QUES},
        .speechWin = {EC_WORD_IT_S, EC_WORD_MY, EC_WORD_FAMILY, EC_WORD_STAY_AT_HOME, EC_WORD_LOOK, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_QUESTION, EC_WORD_YOUR, EC_WORD_FASHION, EC_WORD_SENSE, EC_WORD_SERIOUSLY},
        .monSet = gBattleFrontierTrainerMons_Brody
=======
        .speechBefore = COMPOUND_STRING("My fashion sense seems Oddish?"),
        .speechWin = COMPOUND_STRING("It's my family stay at home look!"),
        .speechLose = COMPOUND_STRING("I question your fashion sense seriously."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GRAHAM] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("GRAHAM"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YEAH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_YEAH_YEAH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_EXCL, EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_MY, EC_WORD_BAD},
        .monSet = gBattleFrontierTrainerMons_Graham
=======
        .speechBefore = COMPOUND_STRING("Yeah! Yeah yeah!!"),
        .speechWin = COMPOUND_STRING("Wahahaha wahahaha! Wahahaha wahahaha!!"),
        .speechLose = COMPOUND_STRING("I am sorry… It's my bad."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TYLOR] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("TYLOR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_ARE, EC_WORD_YOU, EC_WORD_FEELING, EC_WORD_MY, EC_MOVE2(HEAT_WAVE), EC_WORD_QUES},
        .speechWin = {EC_WORD_YES, EC_WORD_I_AM, EC_WORD_ON, EC_WORD_FIRE, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BUT, EC_WORD_I_WAS, EC_WORD_ON, EC_WORD_FIRE, EC_WORD_FOR, EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Tylor
=======
        .speechBefore = COMPOUND_STRING("Are you feeling my heat wave?"),
        .speechWin = COMPOUND_STRING("Yes I am on fire!"),
        .speechLose = COMPOUND_STRING("But I was on fire for you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JAREN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("JAREN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_FIGHTING, EC_WORD_SPIRIT, EC_WORD_QUES, EC_WORD_ME, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WANT, EC_WORD_MORE, EC_WORD_CUTE, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_LOOK, EC_WORD_QUITE, EC_WORD_CUTE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jaren
=======
        .speechBefore = COMPOUND_STRING("Fighting spirit? Me?"),
        .speechWin = COMPOUND_STRING("I want more cute Pokémon."),
        .speechLose = COMPOUND_STRING("Your Pokémon look quite cute."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CORDELL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("CORDELL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_BATTLE, EC_WORD_IS, EC_WORD_DECIDED, EC_WORD_ON, EC_WORD_SPIRIT},
        .speechWin = {EC_WORD_CAN_T, EC_WORD_YOU, EC_WORD_ACCEPT, EC_WORD_THAT, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_BE, EC_WORD_ON, EC_WORD_MY, EC_WORD_WAY},
        .monSet = gBattleFrontierTrainerMons_Cordell
=======
        .speechBefore = COMPOUND_STRING("A battle is decided on spirit."),
        .speechWin = COMPOUND_STRING("Can't you accept that?"),
        .speechLose = COMPOUND_STRING("I will be on my way."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JAZLYN] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("JAZLYN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IS, EC_WORD_YOUR, EC_WORD_POKEDEX, EC_WORD_REALLY, EC_WORD_AWESOME, EC_WORD_QUES},
        .speechWin = {EC_WORD_OH_YEAH, EC_WORD_WOW, EC_WORD_YOUR, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_SUPER},
        .speechLose = {EC_WORD_AN, EC_WORD_AVANT_GARDE, EC_WORD_POKEDEX, EC_WORD_WOULD, EC_WORD_BE, EC_WORD_AWESOME},
        .monSet = gBattleFrontierTrainerMons_Jazlyn
=======
        .speechBefore = COMPOUND_STRING("Is your pokedex really awesome?"),
        .speechWin = COMPOUND_STRING("Oh, yeah wow your pokedex is super."),
        .speechLose = COMPOUND_STRING("An avant garde pokedex would be awesome."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ZACHERY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("ZACHERY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_MY, EC_WORD_OWN, EC_WORD_PLACE, EC_WORD_YEEHAW_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_AN, EC_WORD_EXCITING, EC_WORD_TIME, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_FLATTEN, EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zachery
=======
        .speechBefore = COMPOUND_STRING("I have my own place yeehaw excl."),
        .speechWin = COMPOUND_STRING("It's an exciting time for me."),
        .speechLose = COMPOUND_STRING("You can't flatten my happiness!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JOHAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("JOHAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WINTER, EC_WORD_WILL, EC_WORD_SOON, EC_WORD_BE, EC_WORD_HERE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MY, EC_WORD_ALLOWANCE, EC_WORD_COULD, EC_WORD_USE, EC_WORD_A, EC_MOVE2(HELPING_HAND)},
        .speechLose = {EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_USE, EC_WORD_MY, EC_WORD_ALLOWANCE, EC_WORD_UP},
        .monSet = gBattleFrontierTrainerMons_Johan
=======
        .speechBefore = COMPOUND_STRING("Winter will soon be here."),
        .speechWin = COMPOUND_STRING("My allowance could use a helping hand."),
        .speechLose = COMPOUND_STRING("I always use my allowance up."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SHEA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("SHEA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_DO, EC_WORD_YOU, EC_WORD_BATTLE, EC_WORD_WITH, EC_WORD_BEAUTY, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_BATTLE, EC_WORD_IN, EC_WORD_AN, EC_WORD_UGLY, EC_WORD_WAY},
        .speechLose = {EC_WORD_WHAT, EC_WORD_IS, EC_WORD_BEAUTY, EC_WORD_TO, EC_WORD_YOU, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Shea
=======
        .speechBefore = COMPOUND_STRING("Do you battle with beauty?"),
        .speechWin = COMPOUND_STRING("You battle in an ugly way."),
        .speechLose = COMPOUND_STRING("What is beauty to you?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KAILA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("KAILA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_THIRSTY, EC_WORD_RIGHT, EC_WORD_NOW, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_I, EC_WORD_COULD, EC_WORD_USE, EC_WORD_A, EC_WORD_COLD, EC_WORD_DRINK},
        .speechLose = {EC_WORD_THAT, EC_WORD_LOSS, EC_WORD_IS, EC_WORD_HARD, EC_WORD_TO, EC_MOVE2(SWALLOW)},
        .monSet = gBattleFrontierTrainerMons_Kaila
=======
        .speechBefore = COMPOUND_STRING("I am feeling thirsty right now…"),
        .speechWin = COMPOUND_STRING("I could use a cold drink."),
        .speechLose = COMPOUND_STRING("That loss is hard to swallow."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ISIAH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("ISIAH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_PRETEND, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_A_LOT, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_MOVE2(TRICK), EC_WORD_MOTHER, EC_WORD_FOR, EC_WORD_MY, EC_WORD_ALLOWANCE},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_WANT, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_MORE},
        .monSet = gBattleFrontierTrainerMons_Isiah
=======
        .speechBefore = COMPOUND_STRING("I pretend to study a lot."),
        .speechWin = COMPOUND_STRING("I trick mother for my allowance."),
        .speechLose = COMPOUND_STRING("I don't want to study more."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GARRETT] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("GARRETT"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_ENJOY, EC_WORD_COMICS, EC_WORD_AND, EC_WORD_THIS, EC_WORD_GAME},
        .speechWin = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_THIS, EC_WORD_MUSIC, EC_WORD_IDOL, EC_WORD_TOO},
        .speechLose = {EC_WORD_BUT, EC_WORD_I, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_MORE},
        .monSet = gBattleFrontierTrainerMons_Garrett
=======
        .speechBefore = COMPOUND_STRING("I enjoy comics and this game."),
        .speechWin = COMPOUND_STRING("I like this music idol too."),
        .speechLose = COMPOUND_STRING("But I have to study more."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HAYLIE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("HAYLIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WORRY, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_TO, EC_WORD_SLEEP},
        .speechWin = {EC_WORD_A, EC_WORD_WIN, EC_WORD_GIVES, EC_WORD_ME, EC_WORD_A, EC_MOVE2(CALM_MIND)},
        .speechLose = {EC_WORD_MY, EC_WORD_INSOMNIA, EC_WORD_WILL, EC_WORD_GET, EC_WORD_BAD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Haylie
=======
        .speechBefore = COMPOUND_STRING("I worry too much to sleep."),
        .speechWin = COMPOUND_STRING("A win gives me a calm mind."),
        .speechLose = COMPOUND_STRING("My insomnia will get bad…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MEGAN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("MEGAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_BELIEVE, EC_WORD_IN, EC_WORD_AN, EC_MOVE(AROMATHERAPY), EC_WORD_BATH},
        .speechWin = {EC_WORD_I, EC_WORD_WANT, EC_WORD_A, EC_WORD_HEALTHY, EC_WORD_CLEAR_BODY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IF, EC_WORD_ONLY, EC_MOVE(AROMATHERAPY), EC_WORD_WERE, EC_WORD_LESS, EC_WORD_EXPENSIVE},
        .monSet = gBattleFrontierTrainerMons_Megan
=======
        .speechBefore = COMPOUND_STRING("I believe in an aromatherapy bath."),
        .speechWin = COMPOUND_STRING("I want a healthy clear body."),
        .speechLose = COMPOUND_STRING("If only aromatherapy were less expensive."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ISSAC] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("ISSAC"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_HOBBY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_ANY, EC_WORD_KIND, EC_WORD_OF, EC_MOVE2(WATER_SPORT)},
        .speechLose = {EC_WORD_I, EC_WORD_DISLIKE, EC_WORD_ANY, EC_WORD_KIND, EC_WORD_OF, EC_MOVE2(MUD_SPORT)},
        .monSet = gBattleFrontierTrainerMons_Issac
=======
        .speechBefore = COMPOUND_STRING("My hobby?"),
        .speechWin = COMPOUND_STRING("I like any kind of water sport."),
        .speechLose = COMPOUND_STRING("I dislike any kind of mud sport."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_QUINTON] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("QUINTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_SAD, EC_WORD_CAUSE, EC_WORD_I_AM, EC_WORD_TOO_WEAK, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YOU, EC_WORD_AREN_T, EC_WORD_TOO_STRONG, EC_WORD_FOR, EC_WORD_ME, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HEY, EC_WORD_WHAT, EC_WORD_DID, EC_WORD_I, EC_WORD_DO, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Quinton
=======
        .speechBefore = COMPOUND_STRING("I am sad cause I am too weak."),
        .speechWin = COMPOUND_STRING("You aren't too strong for me."),
        .speechLose = COMPOUND_STRING("Hey what did I do?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SALMA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("SALMA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU_VE, EC_WORD_GOT, EC_WORD_YOUR, EC_WORD_HUSTLE, EC_WORD_ON, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_WIN, EC_WORD_YOU, EC_WORD_HUSTLE, EC_WORD_ON, EC_WORD_OUT},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_GET, EC_WORD_HOW, EC_WORD_I, EC_WORD_LOST},
        .monSet = gBattleFrontierTrainerMons_Salma
=======
        .speechBefore = COMPOUND_STRING("You've got your hustle on!"),
        .speechWin = COMPOUND_STRING("I win you hustle on out."),
        .speechLose = COMPOUND_STRING("I don't get how I lost."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ANSLEY] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("ANSLEY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_BORED, EC_WORD_ELLIPSIS, EC_WORD_DANCE, EC_WORD_FOR, EC_WORD_ME},
        .speechWin = {EC_WORD_YOU_VE, EC_WORD_BORED, EC_WORD_ME, EC_WORD_SOME, EC_WORD_MORE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_TAKE, EC_WORD_YOUR, EC_MOVE2(FRUSTRATION), EC_WORD_SOME, EC_WORD_OTHER, EC_WORD_PLACE},
        .monSet = gBattleFrontierTrainerMons_Ansley
=======
        .speechBefore = COMPOUND_STRING("I am bored… Dance for me."),
        .speechWin = COMPOUND_STRING("You've bored me some more."),
        .speechLose = COMPOUND_STRING("Take your frustration some other place."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HOLDEN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("HOLDEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_S, EC_WORD_COMMEMORATE, EC_WORD_MY, EC_WORD_COOLNESS, EC_WORD_IN, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOO_WEAK, EC_WORD_FOR, EC_WORD_ANY, EC_WORD_PRAISE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOUR, EC_WORD_BATTLE, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_AMUSING, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Holden
=======
        .speechBefore = COMPOUND_STRING("Let's commemorate my coolness in battle."),
        .speechWin = COMPOUND_STRING("You're too weak for any praise."),
        .speechLose = COMPOUND_STRING("Your battle sense is amusing."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LUCA] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("LUCA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WE, EC_WORD_WILL, EC_WORD_HAVE, EC_WORD_A, EC_WORD_COOL, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_I, EC_WORD_WON, EC_WORD_IN, EC_WORD_A, EC_WORD_COOL, EC_WORD_WAY},
        .speechLose = {EC_WORD_HELLO, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_A, EC_WORD_KID},
        .monSet = gBattleFrontierTrainerMons_Luca
=======
        .speechBefore = COMPOUND_STRING("We will have a cool battle."),
        .speechWin = COMPOUND_STRING("I won in a cool way."),
        .speechLose = COMPOUND_STRING("Hello? I am just a kid."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JAMISON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("JAMISON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_MOVE2(SECRET_POWER), EC_WORD_IS, EC_WORD_OVERWHELMING, EC_WORD_TO, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_DID, EC_WORD_YOU, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_USE, EC_MOVE(SMOKESCREEN), EC_WORD_TO, EC_WORD_ESCAPE},
        .monSet = gBattleFrontierTrainerMons_Jamison
=======
        .speechBefore = COMPOUND_STRING("My secret power is overwhelming to Pokémon."),
        .speechWin = COMPOUND_STRING("Did you see that?"),
        .speechLose = COMPOUND_STRING("I will use smokescreen to escape."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GUNNAR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("GUNNAR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE(CUT), EC_WORD_DOWN, EC_WORD_EVERY, EC_WORD_OPPONENT, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DON_T, EC_MOVE(GRUDGE), EC_WORD_ME, EC_WORD_FOR, EC_WORD_YOUR, EC_WORD_LOSS},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_LOSE, EC_WORD_THAT, EC_MOVE(SCARY_FACE), EC_WORD_OF, EC_WORD_YOURS},
        .monSet = gBattleFrontierTrainerMons_Gunnar
=======
        .speechBefore = COMPOUND_STRING("I cut down every opponent."),
        .speechWin = COMPOUND_STRING("Don't grudge me for your loss."),
        .speechLose = COMPOUND_STRING("Please lose that scary face of yours."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CRAIG] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("CRAIG"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_FOR, EC_WORD_MY, EC_WORD_TRAIN},
        .speechWin = {EC_WORD_MY, EC_WORD_TRAIN, EC_WORD_ISN_T, EC_WORD_HERE, EC_WORD_YET, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HERE_IT_IS, EC_WORD_MY, EC_WORD_TRAIN, EC_WORD_SEE_YA, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Craig
=======
        .speechBefore = COMPOUND_STRING("I can't wait for my train."),
        .speechWin = COMPOUND_STRING("My train isn't here yet…"),
        .speechLose = COMPOUND_STRING("Here it is my train see ya!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PIERCE] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("PIERCE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THERE, EC_WORD_WAS, EC_WORD_A, EC_MOVE2(HEAT_WAVE), EC_WORD_LAST, EC_WORD_WEEK},
        .speechWin = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_TAKE, EC_WORD_A, EC_MOVE2(HEAT_WAVE), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_DIDN_T, EC_WORD_IT, EC_MOVE(HAIL), EC_WORD_TOO, EC_WORD_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Pierce
=======
        .speechBefore = COMPOUND_STRING("There was a heat wave last week."),
        .speechWin = COMPOUND_STRING("I can't take a heat wave."),
        .speechLose = COMPOUND_STRING("Didn't it hail too?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_REGINA] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("REGINA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_PLAY, EC_WORD_IN, EC_WORD_WATER},
        .speechWin = {EC_WORD_I, EC_WORD_REFUSE, EC_WORD_TO, EC_WORD_COME, EC_WORD_OUT, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_NOT, EC_WORD_MUCH, EC_WORD_GOOD, EC_WORD_IN, EC_WORD_WATER},
        .monSet = gBattleFrontierTrainerMons_Regina
=======
        .speechBefore = COMPOUND_STRING("I like to play in water."),
        .speechWin = COMPOUND_STRING("I refuse to come out."),
        .speechLose = COMPOUND_STRING("You're not much good in water."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALISON] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ALISON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THIS, EC_WORD_KINDERGARTEN, EC_WORD_MAGAZINE, EC_WORD_IS, EC_WORD_TOO, EC_WORD_MUCH},
        .speechWin = {EC_WORD_HOW, EC_WORD_TO, EC_WORD_BUG, EC_WORD_YOUR, EC_WORD_TEACHER, EC_WORD_QUES},
        .speechLose = {EC_WORD_ENJOY, EC_WORD_A, EC_WORD_TASTY, EC_WORD_SCHOOL, EC_WORD_DIET, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Alison
=======
        .speechBefore = COMPOUND_STRING("This kindergarten magazine is too much."),
        .speechWin = COMPOUND_STRING("How to bug your teacher?"),
        .speechLose = COMPOUND_STRING("Enjoy a tasty school diet?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HANK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("HANK"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_A, EC_WORD_BUG, EC_WORD_EVENT, EC_WORD_SOON},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_BUG, EC_WORD_FASHION, EC_WORD_SHOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_DON_T, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Hank
=======
        .speechBefore = COMPOUND_STRING("There is a bug event soon."),
        .speechWin = COMPOUND_STRING("It's a bug fashion show!"),
        .speechLose = COMPOUND_STRING("Don't you like bug Pokémon?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EARL] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("EARL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THE, EC_WORD_INVINCIBLE, EC_WORD_BUG, EC_WORD_TRAINER, EC_WORD_IS, EC_WORD_HERE},
        .speechWin = {EC_WORD_THE, EC_WORD_INVINCIBLE, EC_WORD_BUG, EC_WORD_TRAINER, EC_WORD_AM, EC_WORD_I},
        .speechLose = {EC_WORD_SEE, EC_WORD_HOW, EC_WORD_FAST, EC_WORD_I, EC_WORD_RUN_AWAY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Earl
=======
        .speechBefore = COMPOUND_STRING("The invincible bug trainer is here."),
        .speechWin = COMPOUND_STRING("The invincible bug trainer am I."),
        .speechLose = COMPOUND_STRING("See how fast I run away!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RAMIRO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("RAMIRO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WENT, EC_WORD_TO, EC_WORD_A, EC_WORD_FISHING, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_SERIOUSLY, EC_WORD_I_AM, EC_WORD_IN, EC_WORD_THE, EC_WORD_FISHING, EC_WORD_HALL_OF_FAME},
        .speechLose = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_GO, EC_WORD_BACK, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ramiro
=======
        .speechBefore = COMPOUND_STRING("I went to a fishing school."),
        .speechWin = COMPOUND_STRING("Seriously I am in the fishing hall of fame."),
        .speechLose = COMPOUND_STRING("I want to go back…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HUNTER] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("HUNTER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_A, EC_WORD_TOTALLY, EC_WORD_COOL, EC_MOVE(CROSS_CHOP)},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOO_WEAK, EC_WORD_TO, EC_WORD_DO, EC_WORD_A, EC_MOVE(CROSS_CHOP)},
        .speechLose = {EC_WORD_WAS, EC_WORD_IT, EC_WORD_A, EC_WORD_MISTAKE, EC_WORD_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hunter
=======
        .speechBefore = COMPOUND_STRING("Show me a totally cool cross chop."),
        .speechWin = COMPOUND_STRING("You're too weak to do a cross chop."),
        .speechLose = COMPOUND_STRING("Was it a mistake?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AIDEN] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("AIDEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_WORK, EC_WORD_IS, EC_WORD_MAKING, EC_WORD_ME, EC_WORD_HEALTHY},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_HEALTHY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MORE, EC_WORD_HEALTHY, EC_WORD_THAN, EC_WORD_I_AM, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Aiden
=======
        .speechBefore = COMPOUND_STRING("My work is making me healthy."),
        .speechWin = COMPOUND_STRING("You see? I am healthy!"),
        .speechLose = COMPOUND_STRING("You're more healthy than I am…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_XAVIER] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("XAVIER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_LOOK, EC_WORD_LOOK, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_GOOD_BYE, EC_WORD_AND, EC_WORD_THANK_YOU, EC_WORD_THAT_WAS, EC_WORD_FUNNY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WOWEE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_NO, EC_WORD_NO, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Xavier
=======
        .speechBefore = COMPOUND_STRING("Hey there! Look look!!"),
        .speechWin = COMPOUND_STRING("Good bye and thank you that was funny."),
        .speechLose = COMPOUND_STRING("Wowee! No no!!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CLINTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("CLINTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WANT, EC_WORD_TO, EC_WORD_SEE, EC_WORD_MY, EC_MOVE(HYPNOSIS), EC_WORD_QUES},
        .speechWin = {EC_WORD_YOUR, EC_MOVE2(FURY_SWIPES), EC_WORD_YOUR, EC_MOVE(STRENGTH), EC_WORD_YOUNG, EC_WORD_TRAINER},
        .speechLose = {EC_WORD_TCH, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Clinton
=======
        .speechBefore = COMPOUND_STRING("Want to see my hypnosis?"),
        .speechWin = COMPOUND_STRING("Your fury swipes your strength young trainer."),
        .speechLose = COMPOUND_STRING("Tch… I am too weak…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JESSE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("JESSE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THIS, EC_WORD_BATTLE, EC_WORD_IS, EC_WORD_FOR, EC_WORD_MY, EC_WORD_MOTHER},
        .speechWin = {EC_WORD_MOTHER, EC_WORD_WILL, EC_WORD_BE, EC_WORD_HAPPY, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_I, EC_WORD_WANT, EC_WORD_MY, EC_WORD_MOTHER, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jesse
=======
        .speechBefore = COMPOUND_STRING("This battle is for my mother."),
        .speechWin = COMPOUND_STRING("Mother will be happy for me."),
        .speechLose = COMPOUND_STRING("I want my mother!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EDUARDO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("EDUARDO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_OUR, EC_WORD_MUSIC, EC_WORD_WILL, EC_WORD_PLAY, EC_WORD_ALL, EC_WORD_NIGHT},
        .speechWin = {EC_WORD_NIGHTTIME, EC_WORD_IS, EC_WORD_WHEN, EC_WORD_I, EC_WORD_PLAY, EC_WORD_BEST},
        .speechLose = {EC_WORD_LET_S, EC_WORD_PARTY, EC_WORD_UNTIL, EC_WORD_THE, EC_MOVE(MORNING_SUN), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Eduardo
=======
        .speechBefore = COMPOUND_STRING("Our music will play all night."),
        .speechWin = COMPOUND_STRING("Nighttime is when I play best."),
        .speechLose = COMPOUND_STRING("Let's party until the morning sun!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HAL] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("HAL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_TRENDY, EC_WORD_AREN_T, EC_WORD_I, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_HIP_AND, EC_WORD_HAPPENING, EC_WORD_OH_YEAH, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_TRENDY, EC_WORD_THANK_YOU, EC_WORD_VERY, EC_WORD_MUCH},
        .monSet = gBattleFrontierTrainerMons_Hal
=======
        .speechBefore = COMPOUND_STRING("I am trendy aren't I?"),
        .speechWin = COMPOUND_STRING("I am feeling hip and happening oh, yeah!"),
        .speechLose = COMPOUND_STRING("I am always trendy thank you very much."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GAGE] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("GAGE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HERE_IT_IS, EC_WORD_A, EC_WORD_FLYING, EC_WORD_TYPE, EC_WORD_HIDDEN, EC_WORD_MOVE},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_FLYING, EC_WORD_TYPE, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_I, EC_WORD_JUST, EC_MOVE(FLY), EC_WORD_AWAY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gage
=======
        .speechBefore = COMPOUND_STRING("Here it is a flying type hidden move."),
        .speechWin = COMPOUND_STRING("It's a flying type victory!"),
        .speechLose = COMPOUND_STRING("If I lose I just fly away."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ARNOLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("ARNOLD"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_WEIRD, EC_WORD_FROM, EC_WORD_A, EC_WORD_DREAM},
        .speechWin = {EC_WORD_YOUR, EC_MOVE(SCARY_FACE), EC_WORD_WAS, EC_WORD_IN, EC_WORD_MY, EC_WORD_DREAM},
        .speechLose = {EC_WORD_MY, EC_WORD_INCREDIBLE, EC_WORD_DREAM, EC_WORD_WAS, EC_WORD_SO, EC_WORD_WEIRD},
        .monSet = gBattleFrontierTrainerMons_Arnold
=======
        .speechBefore = COMPOUND_STRING("I am feeling weird from a dream."),
        .speechWin = COMPOUND_STRING("Your scary face was in my dream."),
        .speechLose = COMPOUND_STRING("My incredible dream was so weird."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JARRETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("JARRETT"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_LET_S, EC_WORD_DANCE, EC_WORD_LIKE, EC_WORD_IT_S, EC_WORD_YESTERDAY},
        .speechWin = {EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_HOW, EC_WORD_I, EC_WORD_DANCE, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_APPRECIATE, EC_WORD_HOW, EC_WORD_I, EC_WORD_DANCE},
        .monSet = gBattleFrontierTrainerMons_Jarrett
=======
        .speechBefore = COMPOUND_STRING("Come on let's dance like it's yesterday."),
        .speechWin = COMPOUND_STRING("You like how I dance?"),
        .speechLose = COMPOUND_STRING("You don't appreciate how I dance."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GARETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("GARETT"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_GIRL, EC_WORD_GIVES, EC_WORD_ME, EC_WORD_A_LITTLE, EC_MOVE2(SWEET_KISS)},
        .speechWin = {EC_WORD_MY, EC_WORD_GIRL, EC_WORD_FRIEND, EC_WORD_IS, EC_WORD_MY, EC_WORD_TREASURE},
        .speechLose = {EC_WORD_A, EC_WORD_TREASURE, EC_WORD_ISN_T, EC_WORD_ALWAYS, EC_WORD_ABOUT, EC_WORD_MONEY},
        .monSet = gBattleFrontierTrainerMons_Garett
=======
        .speechBefore = COMPOUND_STRING("My girl gives me a little sweet kiss."),
        .speechWin = COMPOUND_STRING("My girl friend is my treasure."),
        .speechLose = COMPOUND_STRING("A treasure isn't always about money."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EMANUEL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("EMANUEL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SMARTNESS, EC_WORD_ALONE, EC_WORD_WON_T, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_WIN},
        .speechWin = {EC_WORD_I_AM, EC_WORD_NOT_VERY, EC_WORD_SMART, EC_WORD_BUT, EC_WORD_I, EC_WORD_WON},
        .speechLose = {EC_WORD_HOW, EC_WORD_DID, EC_WORD_YOU, EC_MOVE2(FAKE_OUT), EC_WORD_ME, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Emanuel
=======
        .speechBefore = COMPOUND_STRING("Smartness alone won't make you win."),
        .speechWin = COMPOUND_STRING("I am not very smart but I won."),
        .speechLose = COMPOUND_STRING("How did you fake out me?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GUSTAVO] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("GUSTAVO"),
<<<<<<< HEAD
        .speechBefore = {EC_MOVE(CHARGE), EC_WORD_EXCL, EC_EMPTY_WORD, EC_MOVE(CHARGE), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SURRENDER, EC_WORD_QUES, EC_EMPTY_WORD, EC_WORD_SO, EC_WORD_SOON, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_SURRENDER, EC_WORD_YET},
        .monSet = gBattleFrontierTrainerMons_Gustavo
=======
        .speechBefore = COMPOUND_STRING("Charge! Charge!!"),
        .speechWin = COMPOUND_STRING("Surrender? So soon?"),
        .speechLose = COMPOUND_STRING("You can't make me surrender yet."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KAMERON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("KAMERON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_TAKE_THAT, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_MY, EC_WORD_FIERY, EC_MOVE2(TRICK)},
        .speechWin = {EC_WORD_DID, EC_WORD_MY, EC_WORD_FIERY, EC_MOVE2(TRICK), EC_MOVE(ASTONISH), EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_FALL, EC_WORD_FOR, EC_WORD_MY, EC_MOVE2(TRICK)},
        .monSet = gBattleFrontierTrainerMons_Kameron
=======
        .speechBefore = COMPOUND_STRING("Take that! It's my fiery trick."),
        .speechWin = COMPOUND_STRING("Did my fiery trick astonish?"),
        .speechLose = COMPOUND_STRING("You didn't fall for my trick."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALFREDO] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("ALFREDO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_FIERY, EC_WORD_GOURMET, EC_WORD_AM, EC_WORD_I, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_TASTY, EC_WORD_GOURMET, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHAT, EC_WORD_A, EC_WORD_DISASTER, EC_WORD_THAT_WAS, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alfredo
=======
        .speechBefore = COMPOUND_STRING("A fiery gourmet am I!"),
        .speechWin = COMPOUND_STRING("It's a tasty gourmet victory!"),
        .speechLose = COMPOUND_STRING("What a disaster that was!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RUBEN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("RUBEN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_TO, EC_WORD_GET, EC_WORD_GOING},
        .speechWin = {EC_WORD_GET, EC_WORD_GOING, EC_WORD_EXCL, EC_WORD_THIS, EC_WORD_IS, EC_WORD_GOOD_BYE},
        .speechLose = {EC_WORD_I_VE, EC_WORD_GOT, EC_WORD_TO, EC_WORD_GET, EC_WORD_GOING, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ruben
=======
        .speechBefore = COMPOUND_STRING("I can't wait to get going."),
        .speechWin = COMPOUND_STRING("Get going! This is good bye."),
        .speechLose = COMPOUND_STRING("I've got to get going."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LAMAR] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("LAMAR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_FOR, EC_WORD_ME, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MMM, EC_WORD_THIS, EC_WORD_IS, EC_WORD_QUITE, EC_WORD_TASTY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_OH, EC_WORD_IT_S, EC_WORD_A, EC_WORD_GAME, EC_WORD_IS_IT_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lamar
=======
        .speechBefore = COMPOUND_STRING("A present for me?"),
        .speechWin = COMPOUND_STRING("Mmm this is quite tasty…"),
        .speechLose = COMPOUND_STRING("Oh it's a game is it ques."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JAXON] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("JAXON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_SHELL_ARMOR, EC_WORD_IS, EC_WORD_WHAT, EC_WORD_I, EC_WORD_WANT},
        .speechWin = {EC_WORD_MY, EC_WORD_FATHER, EC_WORD_AND, EC_WORD_MOTHER, EC_WORD_WON_T, EC_WORD_ACCEPT},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_WORD_SHELL_ARMOR, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jaxon
=======
        .speechBefore = COMPOUND_STRING("A shell armor is what I want."),
        .speechWin = COMPOUND_STRING("My father and mother won't accept."),
        .speechLose = COMPOUND_STRING("Please I need a shell armor!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LOGAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("LOGAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IF_I_LOSE, EC_WORD_I, EC_WORD_WILL, EC_WORD_STUDY, EC_WORD_FOR, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_ME, EC_WORD_STUDY, EC_WORD_QUES, EC_WORD_NOT_VERY, EC_WORD_LIKELY_TO, EC_WORD_SEE},
        .speechLose = {EC_WORD_NO, EC_WORD_THANKS, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_SLEEP},
        .monSet = gBattleFrontierTrainerMons_Logan
=======
        .speechBefore = COMPOUND_STRING("If I lose I will study for school."),
        .speechWin = COMPOUND_STRING("Me study? Not very likely to see."),
        .speechLose = COMPOUND_STRING("No thanks I am going to sleep."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EMILEE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("EMILEE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IS, EC_WORD_THIS, EC_WORD_KIND, EC_WORD_OF, EC_WORD_BATTLE, EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_LET_S, EC_WORD_GO, EC_WORD_FOR, EC_WORD_AN, EC_MOVE(ICY_WIND), EC_MOVE2(SURF)},
        .speechLose = {EC_WORD_HOW, EC_WORD_ABOUT, EC_WORD_A, EC_MOVE(ROCK_SLIDE), EC_WORD_SHOW, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Emilee
=======
        .speechBefore = COMPOUND_STRING("Is this kind of battle ok ques."),
        .speechWin = COMPOUND_STRING("Let's go for an icy wind surf."),
        .speechLose = COMPOUND_STRING("How about a rock slide show?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JOSIE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("JOSIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_FASHION, EC_WORD_CONTEST, EC_WORD_IS, EC_WORD_PRETTY},
        .speechWin = {EC_WORD_I, EC_WORD_REALLY, EC_WORD_LIKE, EC_WORD_MODE, EC_WORD_FASHION, EC_WORD_THINGS},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_TOTALLY, EC_WORD_LACKING, EC_WORD_IN, EC_WORD_FASHION, EC_WORD_SENSE},
        .monSet = gBattleFrontierTrainerMons_Josie
=======
        .speechBefore = COMPOUND_STRING("A Pokémon fashion contest is pretty."),
        .speechWin = COMPOUND_STRING("I really like mode fashion things."),
        .speechLose = COMPOUND_STRING("You're totally lacking in fashion sense."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ARMANDO] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("ARMANDO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_NEED, EC_WORD_MORE, EC_WORD_GRASS, EC_WORD_TYPE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_TRADE, EC_WORD_ME, EC_WORD_A, EC_WORD_GRASS, EC_WORD_POKEMON, EC_WORD_PLEASE},
        .speechLose = {EC_WORD_THERE, EC_WORD_AREN_T, EC_WORD_ENOUGH, EC_WORD_GRASS, EC_WORD_TYPE, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Armando
=======
        .speechBefore = COMPOUND_STRING("I need more grass type Pokémon."),
        .speechWin = COMPOUND_STRING("Trade me a grass Pokémon please."),
        .speechLose = COMPOUND_STRING("There aren't enough grass type Pokémon."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SKYLER] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("SKYLER"),
<<<<<<< HEAD
        .speechBefore = {EC_MOVE2(INGRAIN), EC_WORD_IS, EC_WORD_MY, EC_WORD_CHOICE, EC_WORD_BATTLE, EC_WORD_MOVE},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_MOVE, EC_WORD_ME, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_MOVE(CUT), EC_WORD_ME, EC_WORD_DOWN, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Skyler
=======
        .speechBefore = COMPOUND_STRING("Ingrain is my choice battle move."),
        .speechWin = COMPOUND_STRING("You can't move me now!"),
        .speechLose = COMPOUND_STRING("You cut me down…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RUTH] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("RUTH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_ENJOY, EC_WORD_THIS, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_MUCH, EC_WORD_TOO, EC_WORD_EASY, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_STOP, EC_WORD_I, EC_WORD_DON_T, EC_WORD_ENJOY, EC_WORD_THIS},
        .monSet = gBattleFrontierTrainerMons_Ruth
=======
        .speechBefore = COMPOUND_STRING("I want to enjoy this battle."),
        .speechWin = COMPOUND_STRING("That was much too easy!"),
        .speechLose = COMPOUND_STRING("Please stop I don't enjoy this."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MELODY] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("MELODY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE2(WISH), EC_WORD_SUNDAY, EC_WORD_IS, EC_WORD_A, EC_MOVE2(SUNNY_DAY)},
        .speechWin = {EC_WORD_SUNDAY, EC_WORD_SEEMS, EC_WORD_FOREVER, EC_WORD_TO, EC_WORD_COME, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THE, EC_WORD_FORECAST, EC_WORD_SAYS, EC_WORD_IT, EC_WORD_WILL, EC_MOVE(HAIL)},
        .monSet = gBattleFrontierTrainerMons_Melody
=======
        .speechBefore = COMPOUND_STRING("I wish sunday is a sunny day."),
        .speechWin = COMPOUND_STRING("Sunday seems forever to come…"),
        .speechLose = COMPOUND_STRING("The forecast says it will hail."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PEDRO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("PEDRO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_SWIFT_SWIM, EC_WORD_WILL, EC_WORD_DO, EC_WORD_YOU, EC_WORD_GOOD},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_HOW, EC_WORD_I, EC_WORD_SINK, EC_WORD_AN, EC_WORD_OPPONENT},
        .speechLose = {EC_WORD_UH_OH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_A, EC_MOVE(WHIRLPOOL), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Pedro
=======
        .speechBefore = COMPOUND_STRING("A swift swim will do you good."),
        .speechWin = COMPOUND_STRING("That's how I sink an opponent."),
        .speechLose = COMPOUND_STRING("Uh-oh! A whirlpool!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ERICK] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("ERICK"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_MOVE2(TACKLE), EC_WORD_YOU, EC_WORD_DOWN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_DON_T, EC_WORD_YOU, EC_WORD_RUN_AWAY, EC_WORD_YOU, EC_WORD_LOSER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_THINK, EC_WORD_YOU, EC_WORD_WOULD, EC_MOVE(COUNTER)},
        .monSet = gBattleFrontierTrainerMons_Erick
=======
        .speechBefore = COMPOUND_STRING("I will tackle you down!"),
        .speechWin = COMPOUND_STRING("Don't you run away you loser!"),
        .speechLose = COMPOUND_STRING("I didn't think you would counter."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ELAINE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("ELAINE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_HEROINE, EC_WORD_ADVENTURE, EC_WORD_ISN_T, EC_WORD_GOING, EC_WORD_WELL},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I, EC_WORD_NEED},
        .speechLose = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_HEROINE},
        .monSet = gBattleFrontierTrainerMons_Elaine
=======
        .speechBefore = COMPOUND_STRING("My heroine adventure isn't going well."),
        .speechWin = COMPOUND_STRING("Thank you! That's what I need."),
        .speechLose = COMPOUND_STRING("I know I am not a heroine."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JOYCE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("JOYCE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_GO, EC_WORD_AHAHA, EC_WORD_EXCL},
        .speechWin = {EC_WORD_LALALA, EC_WORD_NO, EC_WORD_LOSING, EC_WORD_FOR, EC_WORD_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LALALA, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_HUH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joyce
=======
        .speechBefore = COMPOUND_STRING("You make me go ahaha!"),
        .speechWin = COMPOUND_STRING("Lalala no losing for me!"),
        .speechLose = COMPOUND_STRING("Lalala… Huh ques."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TODD] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("TODD"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_LIGHTNINGROD, EC_WORD_FOR, EC_WORD_MY, EC_WORD_POWER},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_ALL, EC_WORD_YOU, EC_WORD_COULD, EC_MOVE(ABSORB), EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_MOVE2(REFLECT), EC_WORD_MY, EC_WORD_POWER, EC_WORD_BACK, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Todd
=======
        .speechBefore = COMPOUND_STRING("You're a lightningrod for my power."),
        .speechWin = COMPOUND_STRING("That's all you could absorb?"),
        .speechLose = COMPOUND_STRING("You reflect my power back?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GAVIN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("GAVIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_MOVE(BIDE), EC_WORD_MY, EC_WORD_TIME, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT_S, EC_WORD_OVER, EC_WORD_SO, EC_WORD_SOON, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MY, EC_WORD_MISTAKE, EC_WORD_WAS, EC_WORD_TOO, EC_WORD_EXPENSIVE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Gavin
=======
        .speechBefore = COMPOUND_STRING("I will bide my time."),
        .speechWin = COMPOUND_STRING("It's over so soon?"),
        .speechLose = COMPOUND_STRING("My mistake was too expensive…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MALORY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("MALORY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_PROMISE, EC_WORD_TO, EC_WORD_SHOW, EC_WORD_ME, EC_WORD_CUTE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_THANK_YOU, EC_WORD_SO, EC_WORD_MUCH},
        .speechLose = {EC_WORD_TCH, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_AREN_T, EC_WORD_VERY, EC_WORD_NICE},
        .monSet = gBattleFrontierTrainerMons_Malory
=======
        .speechBefore = COMPOUND_STRING("Promise to show me cute Pokémon."),
        .speechWin = COMPOUND_STRING("Giggle… Thank you so much."),
        .speechLose = COMPOUND_STRING("Tch your Pokémon aren't very nice."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ESTHER] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("ESTHER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WANT, EC_WORD_A, EC_WORD_NICE, EC_MOVE2(PRESENT), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_PLEASE, EC_WORD_GET, EC_WORD_ME, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_GAME},
        .speechLose = {EC_WORD_MESSAGE, EC_WORD_CARDS, EC_WORD_MAKE, EC_WORD_A, EC_WORD_WEAK, EC_MOVE2(PRESENT)},
        .monSet = gBattleFrontierTrainerMons_Esther
=======
        .speechBefore = COMPOUND_STRING("I want a nice present…"),
        .speechWin = COMPOUND_STRING("Please get me a Pokémon game."),
        .speechLose = COMPOUND_STRING("Message cards make a weak present."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_OSCAR] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("OSCAR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_S, EC_WORD_SEE, EC_WORD_YOUR, EC_WORD_POWER, EC_WORD_IN, EC_WORD_FULL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_NOT, EC_WORD_YOUR, EC_WORD_FULL, EC_WORD_POWER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NOT, EC_WORD_FUNNY, EC_WORD_ELLIPSIS, EC_WORD_YOU_RE, EC_WORD_TOO_STRONG, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Oscar
=======
        .speechBefore = COMPOUND_STRING("Let's see your power in full."),
        .speechWin = COMPOUND_STRING("That was not your full power!"),
        .speechLose = COMPOUND_STRING("Not funny… You're too strong."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_WILSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("WILSON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WORK, EC_WORD_IS, EC_WORD_MAKING, EC_WORD_ME, EC_WORD_AN, EC_WORD_EARLY_BIRD},
        .speechWin = {EC_WORD_ALL, EC_WORD_WORK, EC_WORD_AND, EC_WORD_NO, EC_WORD_PLAY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_MOVE(ENDURE), EC_WORD_IS, EC_WORD_ALL, EC_WORD_I, EC_WORD_CAN, EC_WORD_DO},
        .monSet = gBattleFrontierTrainerMons_Wilson
=======
        .speechBefore = COMPOUND_STRING("Work is making me an early bird."),
        .speechWin = COMPOUND_STRING("All work and no play…"),
        .speechLose = COMPOUND_STRING("Endure is all I can do."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CLARE] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("CLARE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YAY, EC_WORD_EXCL, EC_WORD_A, EC_WORD_TOUGH, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AWW, EC_WORD_EXCL, EC_WORD_A, EC_WORD_WIMPY, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_COOL, EC_WORD_EXCL, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_TRAINER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Clare
=======
        .speechBefore = COMPOUND_STRING("Yay! A tough trainer!"),
        .speechWin = COMPOUND_STRING("Aww! A wimpy trainer!"),
        .speechLose = COMPOUND_STRING("Cool! A genius trainer!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TESS] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("TESS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WANT, EC_WORD_SOME, EC_POKEMON(GULPIN), EC_WORD_DESIGN, EC_WORD_SWEETS, EC_WORD_QUES},
        .speechWin = {EC_WORD_THEY_RE, EC_WORD_A, EC_WORD_SECRET, EC_WORD_POKEMON, EC_WORD_GOURMET, EC_WORD_ITEM},
        .speechLose = {EC_WORD_THEY_RE, EC_WORD_TASTY, EC_WORD_EXCL, EC_WORD_REFRESHING, EC_WORD_TOO, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Tess
=======
        .speechBefore = COMPOUND_STRING("Want some Gulpin design sweets?"),
        .speechWin = COMPOUND_STRING("They're a secret Pokémon gourmet item."),
        .speechLose = COMPOUND_STRING("They're tasty! Refreshing too!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LEON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("LEON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_BETTER, EC_WORD_THAN, EC_WORD_ANY, EC_WORD_OTHER, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_I, EC_WORD_DID, EC_WORD_IT, EC_MOVE2(JUMP_KICK), EC_WORD_FOR, EC_WORD_JOY},
        .speechLose = {EC_WORD_BACK, EC_WORD_HOME, EC_WORD_I, EC_WORD_WILL, EC_WORD_GO, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Leon
=======
        .speechBefore = COMPOUND_STRING("I am better than any other trainer."),
        .speechWin = COMPOUND_STRING("I did it jump kick for joy."),
        .speechLose = COMPOUND_STRING("Back home I will go…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALONZO] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("ALONZO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_LOST, EC_WORD_ONCE, EC_WORD_YET, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOUR, EC_WORD_SAD, EC_WORD_LOOK, EC_WORD_BECOMES, EC_WORD_YOU, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_BELIEVE, EC_WORD_THIS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alonzo
=======
        .speechBefore = COMPOUND_STRING("I've not lost once yet!"),
        .speechWin = COMPOUND_STRING("Your sad look becomes you."),
        .speechLose = COMPOUND_STRING("I don't believe this…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_VINCE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("VINCE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THE, EC_WORD_TOP, EC_WORD_TRAINER, EC_WORD_THAT_S, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THE, EC_WORD_TOP, EC_WORD_RANK, EC_WORD_BELONGS_TO, EC_WORD_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_APPEAL, EC_WORD_THIS, EC_MOVE(OUTRAGE), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Vince
=======
        .speechBefore = COMPOUND_STRING("The top trainer that's me!"),
        .speechWin = COMPOUND_STRING("The top rank belongs to me!"),
        .speechLose = COMPOUND_STRING("I will appeal this outrage!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRYON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("BRYON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_MOVE2(BARRAGE), EC_WORD_WILL, EC_MOVE2(SLAM), EC_WORD_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_COUNT_ON, EC_WORD_ANY, EC_WORD_LESS, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_JUST, EC_WORD_DON_T, EC_WORD_GET, EC_WORD_IT, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Bryon
=======
        .speechBefore = COMPOUND_STRING("My barrage will slam you!"),
        .speechWin = COMPOUND_STRING("You didn't count on any less?"),
        .speechLose = COMPOUND_STRING("I just don't get it…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AVA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("AVA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_TREASURE, EC_WORD_OF, EC_WORD_THIS, EC_WORD_WORLD},
        .speechWin = {EC_WORD_MY, EC_WORD_WORLD, EC_WORD_IS, EC_WORD_FULL, EC_WORD_OF, EC_WORD_WONDER},
        .speechLose = {EC_WORD_WHY, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_SO, EC_WORD_TERRIBLE, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Ava
=======
        .speechBefore = COMPOUND_STRING("I am a treasure of this world."),
        .speechWin = COMPOUND_STRING("My world is full of wonder."),
        .speechLose = COMPOUND_STRING("Why are you so terrible?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MIRIAM] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("MIRIAM"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_OH, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_WITH, EC_WORD_A, EC_MOVE(SCARY_FACE)},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_YOU, EC_WORD_ONLY, EC_WORD_LOOK, EC_WORD_SCARY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_AIYEEH, EC_WORD_EXCL, EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_ARE, EC_WORD_SCARY},
        .monSet = gBattleFrontierTrainerMons_Miriam
=======
        .speechBefore = COMPOUND_STRING("Oh a trainer with a scary face."),
        .speechWin = COMPOUND_STRING("Ahaha you only look scary!"),
        .speechLose = COMPOUND_STRING("Aiyeeh! You really are scary."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CARRIE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("CARRIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_WORD_SHOW, EC_WORD_YOU, EC_WORD_GUTSY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_ALL, EC_WORD_ABOUT, EC_WORD_GUTS, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_ELLIPSIS, EC_MOVE(SELF_DESTRUCT), EC_WORD_MODE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Carrie
=======
        .speechBefore = COMPOUND_STRING("I will show you gutsy!"),
        .speechWin = COMPOUND_STRING("It's all about guts!"),
        .speechLose = COMPOUND_STRING("Oh no… Self destruct mode!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GILLIAN2] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("GILLIAN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_SEEK, EC_WORD_A, EC_WORD_TRULY, EC_WORD_GREAT, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_I, EC_WORD_NEED, EC_WORD_A_LOT, EC_WORD_BETTER, EC_WORD_BATTLE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_A_LITTLE, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_TO, EC_WORD_TAKE},
        .monSet = gBattleFrontierTrainerMons_Gillian2
=======
        .speechBefore = COMPOUND_STRING("I seek a truly great battle."),
        .speechWin = COMPOUND_STRING("I need a lot better battle…"),
        .speechLose = COMPOUND_STRING("That was a little too much to take."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TYLER] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("TYLER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_LET_S, EC_WORD_GO, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_YO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_WON, EC_WORD_YO},
        .speechLose = {EC_WORD_YO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_LOST, EC_WORD_YO},
        .monSet = gBattleFrontierTrainerMons_Tyler
=======
        .speechBefore = COMPOUND_STRING("Yo! Let's go!!"),
        .speechWin = COMPOUND_STRING("Yo! I won yo."),
        .speechLose = COMPOUND_STRING("Yo! I lost yo."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CHAZ] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("CHAZ"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_HAVE, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_POWER},
        .speechWin = {EC_WORD_THEY, EC_WORD_HAVE, EC_WORD_MORE, EC_WORD_POWER, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YEAH, EC_MOVE2(TAKE_DOWN), EC_WORD_THEIR, EC_WORD_POWER, EC_WORD_A_TINY_BIT, EC_WORD_PLEASE},
        .monSet = gBattleFrontierTrainerMons_Chaz
=======
        .speechBefore = COMPOUND_STRING("My Pokémon have too much power."),
        .speechWin = COMPOUND_STRING("They have more power now!"),
        .speechLose = COMPOUND_STRING("Yeah take down their power a tiny bit please."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_NELSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("NELSON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WELL_THEN, EC_WORD_WILL, EC_WORD_THIS, EC_WORD_POKEMON, EC_WORD_WORK, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_IT, EC_WORD_WAS, EC_WORD_TOO_STRONG},
        .speechLose = {EC_WORD_IT, EC_WORD_DIDN_T, EC_WORD_MATCH_UP, EC_WORD_WELL, EC_WORD_I, EC_WORD_THINK},
        .monSet = gBattleFrontierTrainerMons_Nelson
=======
        .speechBefore = COMPOUND_STRING("Well then will this Pokémon work?"),
        .speechWin = COMPOUND_STRING("I see that it was too strong."),
        .speechLose = COMPOUND_STRING("It didn't match up well I think."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SHANIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("SHANIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_ALL, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ABSOLUTELY, EC_WORD_ADORE, EC_WORD_ME},
        .speechWin = {EC_WORD_HAPPINESS, EC_WORD_IS, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_WITH, EC_WORD_CUTE_CHARM},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_SO, EC_WORD_MEAN, EC_WORD_TO, EC_WORD_CUTE, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Shania
=======
        .speechBefore = COMPOUND_STRING("All my Pokémon absolutely adore me."),
        .speechWin = COMPOUND_STRING("Happiness is a Pokémon with cute charm."),
        .speechLose = COMPOUND_STRING("You're so mean to cute Pokémon."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_STELLA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("STELLA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_SEE, EC_WORD_YOUR, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_WELL, EC_WORD_AREN_T, EC_WORD_THEY, EC_WORD_BORING, EC_WORD_QUES, EC_WORD_AHAHA},
        .speechLose = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_SOMETHING, EC_WORD_ELSE, EC_WORD_ALL_RIGHT},
        .monSet = gBattleFrontierTrainerMons_Stella
=======
        .speechBefore = COMPOUND_STRING("I want to see your Pokémon."),
        .speechWin = COMPOUND_STRING("Well aren't they boring? Ahaha."),
        .speechLose = COMPOUND_STRING("Your Pokémon are something else all right."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DORINE] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("DORINE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_YOUNG, EC_WORD_AND, EC_WORD_STRONG, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SEE, EC_WORD_QUES, EC_WORD_AREN_T, EC_WORD_I, EC_WORD_GOOD, EC_WORD_QUES},
        .speechLose = {EC_WORD_THIS, EC_WORD_ISN_T, EC_WORD_WORKING, EC_WORD_OUT, EC_WORD_AT, EC_WORD_ALL},
        .monSet = gBattleFrontierTrainerMons_Dorine
=======
        .speechBefore = COMPOUND_STRING("I am young and strong!"),
        .speechWin = COMPOUND_STRING("See? Aren't I good?"),
        .speechLose = COMPOUND_STRING("This isn't working out at all."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MADDOX] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("MADDOX"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_MY, EC_WORD_NO_1, EC_WORD_CHOICE},
        .speechWin = {EC_WORD_IT_S, EC_WORD_NO, EC_WORD_SECRET, EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_WIN},
        .speechLose = {EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_SHOULD, EC_WORD_NOT, EC_WORD_LOSE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Maddox
=======
        .speechBefore = COMPOUND_STRING("Dragon Pokémon are my no 1 choice."),
        .speechWin = COMPOUND_STRING("It's no secret dragon Pokémon win."),
        .speechLose = COMPOUND_STRING("Dragon Pokémon should not lose!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DAVIN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DAVIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_S, EC_WORD_HEAR, EC_WORD_YOU, EC_MOVE2(ROAR), EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WROOOAAR_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_VICTORY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WROOOAAR_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_WHY, EC_WORD_QUES_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Davin
=======
        .speechBefore = COMPOUND_STRING("Let's hear you roar!"),
        .speechWin = COMPOUND_STRING("Wroooaar! Victory!!"),
        .speechLose = COMPOUND_STRING("Wroooaar! Why?!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TREVON] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("TREVON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_LIVING, EC_WORD_ONLY, EC_WORD_WITH, EC_WORD_DRAGON, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_THE, EC_WORD_WAY, EC_WORD_I_AM, EC_WORD_LIVING, EC_WORD_IS, EC_WORD_PERFECT},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_DESTROYED, EC_WORD_THE, EC_WORD_WAY, EC_WORD_I_AM, EC_WORD_LIVING},
        .monSet = gBattleFrontierTrainerMons_Trevon
=======
        .speechBefore = COMPOUND_STRING("I am living only with dragon Pokémon."),
        .speechWin = COMPOUND_STRING("The way I am living is perfect."),
        .speechLose = COMPOUND_STRING("You've destroyed the way I am living."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MATEO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("MATEO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THIS, EC_WORD_SHOULD, EC_WORD_BE, EC_WORD_OVER, EC_WORD_SOON, EC_WORD_ENOUGH},
        .speechWin = {EC_WORD_WELL, EC_WORD_THAT, EC_WORD_DIDN_T, EC_WORD_TAKE, EC_WORD_VERY, EC_WORD_MUCH},
        .speechLose = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_LOSE, EC_WORD_SO, EC_WORD_SOON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Mateo
=======
        .speechBefore = COMPOUND_STRING("This should be over soon enough."),
        .speechWin = COMPOUND_STRING("Well that didn't take very much."),
        .speechLose = COMPOUND_STRING("I can't lose so soon!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRET] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("BRET"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_ROCK_SOLID, EC_WORD_POKEMON, EC_WORD_THE, EC_WORD_BEST},
        .speechWin = {EC_WORD_TOUGHNESS, EC_WORD_IS, EC_WORD_THE, EC_WORD_WAY, EC_WORD_TO, EC_WORD_GO},
        .speechLose = {EC_WORD_I, EC_WORD_ALSO, EC_WORD_HAVE, EC_WORD_A, EC_WORD_PLUSH_DOLL, EC_WORD_COLLECTION},
        .monSet = gBattleFrontierTrainerMons_Bret
=======
        .speechBefore = COMPOUND_STRING("I like rock solid Pokémon the best."),
        .speechWin = COMPOUND_STRING("Toughness is the way to go."),
        .speechLose = COMPOUND_STRING("I also have a plush doll collection."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RAUL] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("RAUL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_REJECT, EC_WORD_EVERY, EC_WORD_WEAK, EC_WORD_TRAINER, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HUMPH, EC_WORD_EXCL, EC_WORD_ANOTHER, EC_WORD_WEAK, EC_WORD_TRAINER, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NOTHING, EC_WORD_WEAK, EC_WORD_ABOUT, EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Raul
=======
        .speechBefore = COMPOUND_STRING("I reject every weak trainer."),
        .speechWin = COMPOUND_STRING("Humph! Another weak trainer…"),
        .speechLose = COMPOUND_STRING("There is nothing weak about you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KAY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("KAY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_AND, EC_WORD_YET, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WON, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_GOOD, EC_WORD_IT_S, EC_WORD_OVER, EC_WORD_AT, EC_WORD_LAST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kay
=======
        .speechBefore = COMPOUND_STRING("And yet another battle?"),
        .speechWin = COMPOUND_STRING("I won but I am tired…"),
        .speechLose = COMPOUND_STRING("Good it's over at last…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ELENA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ELENA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_BATTLE, EC_WORD_GIRL, EC_WORD_THAT_S, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ISN_T, EC_WORD_A, EC_WORD_BATTLE, EC_WORD_GIRL, EC_WORD_AWESOME, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_DISLIKE, EC_WORD_A, EC_WORD_BATTLE, EC_WORD_GIRL, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Elena
=======
        .speechBefore = COMPOUND_STRING("A battle girl that's me!"),
        .speechWin = COMPOUND_STRING("Isn't a battle girl awesome?"),
        .speechLose = COMPOUND_STRING("You dislike a battle girl?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ALANA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_EAT, EC_WORD_MY, EC_WORD_INVINCIBLE, EC_WORD_ATTACK, EC_WORD_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_MUCH, EC_WORD_TO, EC_WORD_LEARN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SO, EC_WORD_MUCH, EC_WORD_FOR, EC_WORD_MY, EC_WORD_INVINCIBLE, EC_WORD_ATTACK},
        .monSet = gBattleFrontierTrainerMons_Alana
=======
        .speechBefore = COMPOUND_STRING("Eat my invincible attack you!"),
        .speechWin = COMPOUND_STRING("You have much to learn."),
        .speechLose = COMPOUND_STRING("So much for my invincible attack."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALEXAS] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("ALEXAS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_GOOD, EC_WORD_TO, EC_WORD_MEET_YOU, EC_WORD_YOUNG, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WAHAHAHA, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_GIVE, EC_WORD_IT, EC_WORD_UP},
        .speechLose = {EC_WORD_YOU, EC_WORD_ARE, EC_WORD_A, EC_WORD_STRONG, EC_WORD_TRAINER, EC_WORD_KID},
        .monSet = gBattleFrontierTrainerMons_Alexas
=======
        .speechBefore = COMPOUND_STRING("Good to meet you young trainer!"),
        .speechWin = COMPOUND_STRING("Wahahaha! Give it up."),
        .speechLose = COMPOUND_STRING("You are a strong trainer kid."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_WESTON] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("WESTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_PLAY, EC_WORD_DOWN, EC_WORD_ALL_RIGHT, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_FAR, EC_WORD_TOO, EC_WORD_EASY, EC_WORD_TO, EC_WORD_ATTACK},
        .speechLose = {EC_WORD_WELL, EC_WORD_WELL, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_SURRENDER, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Weston
=======
        .speechBefore = COMPOUND_STRING("I don't play down all right?"),
        .speechWin = COMPOUND_STRING("You're far too easy to attack."),
        .speechLose = COMPOUND_STRING("Well well… I surrender…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JASPER] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JASPER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_OLD, EC_WORD_I_AM, EC_WORD_SKILLED, EC_WORD_EXCL},
        .speechWin = {EC_WORD_SKILLED, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SHOCKED, EC_WORD_EXCL, EC_WORD_DOWN, EC_WORD_I, EC_WORD_GO},
        .monSet = gBattleFrontierTrainerMons_Jasper
=======
        .speechBefore = COMPOUND_STRING("I am not old I am skilled!"),
        .speechWin = COMPOUND_STRING("Skilled that's what I am!"),
        .speechLose = COMPOUND_STRING("I am shocked! Down I go."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_NADIA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("NADIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_BEAT, EC_WORD_ME, EC_WORD_DOWN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HAH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_BEAT, EC_WORD_YOU},
        .speechLose = {EC_WORD_I_AM, EC_MOVE2(BEAT_UP), EC_WORD_AND, EC_WORD_DOWNCAST, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Nadia
=======
        .speechBefore = COMPOUND_STRING("You can't beat me down!"),
        .speechWin = COMPOUND_STRING("Hah! I beat you."),
        .speechLose = COMPOUND_STRING("I am beat up and downcast…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MIRANDA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("MIRANDA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WELL, EC_WORD_WELL, EC_EMPTY_WORD, EC_WORD_LET_S, EC_WORD_START, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHAT, EC_WORD_QUES, EC_WORD_DONE, EC_WORD_SO, EC_WORD_SOON, EC_WORD_QUES},
        .speechLose = {EC_WORD_WELL, EC_WORD_I, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_I_AM, EC_WORD_TOO_WEAK},
        .monSet = gBattleFrontierTrainerMons_Miranda
=======
        .speechBefore = COMPOUND_STRING("Well well let's start."),
        .speechWin = COMPOUND_STRING("What? Done so soon?"),
        .speechLose = COMPOUND_STRING("Well I see that I am too weak."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_EMMA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("EMMA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_VE, EC_WORD_BEEN, EC_WORD_HEARING, EC_WORD_ABOUT, EC_WORD_YOU, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_THINK, EC_WORD_I_VE, EC_WORD_MISHEARD, EC_WORD_THINGS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHAT, EC_WORD_I_VE, EC_WORD_BEEN, EC_WORD_HEARING, EC_WORD_IS, EC_WORD_RIGHT},
        .monSet = gBattleFrontierTrainerMons_Emma
=======
        .speechBefore = COMPOUND_STRING("I've been hearing about you."),
        .speechWin = COMPOUND_STRING("I think I've misheard things."),
        .speechLose = COMPOUND_STRING("What I've been hearing is right."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ROLANDO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("ROLANDO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_SUPER, EC_WORD_POKEMON, EC_WORD_HERO, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WAS, EC_WORD_THAT, EC_WORD_ENOUGH, EC_WORD_FOR, EC_WORD_YOU, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_SHOULD, EC_WORD_NOT, EC_WORD_BEAT, EC_WORD_A, EC_WORD_HERO},
        .monSet = gBattleFrontierTrainerMons_Rolando
=======
        .speechBefore = COMPOUND_STRING("I am a super Pokémon hero!"),
        .speechWin = COMPOUND_STRING("Was that enough for you?"),
        .speechLose = COMPOUND_STRING("You should not beat a hero."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_STANLY] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("STANLY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THIS, EC_WORD_SHOULD, EC_WORD_BE, EC_WORD_AN, EC_WORD_EASY, EC_WORD_MATCH},
        .speechWin = {EC_WORD_IT, EC_WORD_REALLY, EC_WORD_WAS, EC_WORD_EASY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARE, EC_WORD_YOU, EC_WORD_HAPPY, EC_WORD_NOW, EC_WORD_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stanly
=======
        .speechBefore = COMPOUND_STRING("This should be an easy match."),
        .speechWin = COMPOUND_STRING("It really was easy."),
        .speechLose = COMPOUND_STRING("Are you happy now?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DARIO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("DARIO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_MOVE2(FORESIGHT), EC_WORD_SAYS, EC_WORD_I, EC_WORD_WILL, EC_WORD_WIN},
        .speechWin = {EC_WORD_MY, EC_MOVE2(FORESIGHT), EC_WORD_HAS, EC_WORD_BEEN, EC_WORD_PERFECT, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_SEE, EC_WORD_THIS, EC_MOVE(REVERSAL), EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Dario
=======
        .speechBefore = COMPOUND_STRING("My foresight says I will win."),
        .speechWin = COMPOUND_STRING("My foresight has been perfect."),
        .speechLose = COMPOUND_STRING("I didn't see this reversal…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_KARLEE] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("KARLEE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_SOMETHING, EC_WORD_GOOD, EC_WORD_WILL, EC_WORD_COME, EC_WORD_OF, EC_WORD_THIS},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_FANTASTIC, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT, EC_WORD_SOMETHING, EC_WORD_GOOD, EC_WORD_WENT, EC_WORD_TO, EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Karlee
=======
        .speechBefore = COMPOUND_STRING("Something good will come of this."),
        .speechWin = COMPOUND_STRING("You see? Fantastic!"),
        .speechLose = COMPOUND_STRING("That something good went to you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JAYLIN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("JAYLIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_EVERY, EC_WORD_TRAINER, EC_WORD_HAS, EC_WORD_BEEN, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT_S, EC_WORD_MAKING, EC_WORD_ME, EC_MOVE(YAWN), EC_WORD_THAT, EC_WORD_BATTLE},
        .speechLose = {EC_WORD_I, EC_WORD_SLEPT, EC_WORD_AND, EC_WORD_SO, EC_WORD_I, EC_WORD_LOST},
        .monSet = gBattleFrontierTrainerMons_Jaylin
=======
        .speechBefore = COMPOUND_STRING("Every trainer has been too weak…"),
        .speechWin = COMPOUND_STRING("It's making me yawn that battle."),
        .speechLose = COMPOUND_STRING("I slept and so I lost."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_INGRID] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("INGRID"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_VERY, EC_WORD_MEAN, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_WASN_T, EC_WORD_THAT, EC_WORD_A, EC_WORD_GOOD, EC_WORD_MATCH, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_LOST, EC_WORD_CAUSE, EC_WORD_YOU_RE, EC_WORD_MEAN, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ingrid
=======
        .speechBefore = COMPOUND_STRING("I am not a very mean trainer."),
        .speechWin = COMPOUND_STRING("Wasn't that a good match?"),
        .speechLose = COMPOUND_STRING("I lost cause you're mean…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DELILAH] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("DELILAH"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_DON_T, EC_MOVE(GRUDGE), EC_WORD_ME, EC_WORD_IF_I_WIN, EC_WORD_OK_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_TO, EC_WORD_SEE, EC_WORD_YOU, EC_WORD_ANGRY},
        .speechLose = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_A, EC_MOVE(GRUDGE), EC_WORD_WITH, EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Delilah
=======
        .speechBefore = COMPOUND_STRING("Don't grudge me if I win ok ques."),
        .speechWin = COMPOUND_STRING("I am sorry to see you angry."),
        .speechLose = COMPOUND_STRING("I have a grudge with you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CARLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("CARLY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_WORD_SCATTER, EC_WORD_SOME, EC_MOVE2(POISON_POWDER), EC_WORD_ABOUT},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SCARY, EC_WORD_HOW, EC_WORD_MY, EC_WORD_STRATEGY, EC_WORD_WORKS},
        .speechLose = {EC_WORD_I, EC_WORD_DISLIKE, EC_WORD_YOU, EC_WORD_AND, EC_WORD_YOUR, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Carly
=======
        .speechBefore = COMPOUND_STRING("I will scatter some poison powder about."),
        .speechWin = COMPOUND_STRING("It's scary how my strategy works."),
        .speechLose = COMPOUND_STRING("I dislike you and your Pokémon."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LEXIE] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("LEXIE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WANT, EC_WORD_TO, EC_WORD_SEE, EC_WORD_SCARY, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_WASN_T, EC_WORD_THAT, EC_WORD_SCARY, EC_WORD_EH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MORE, EC_WORD_SCARY, EC_WORD_THAN, EC_WORD_MY, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Lexie
=======
        .speechBefore = COMPOUND_STRING("Want to see scary Pokémon?"),
        .speechWin = COMPOUND_STRING("Wasn't that scary eh?"),
        .speechLose = COMPOUND_STRING("You're more scary than my Pokémon."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MILLER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("MILLER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_HELLO, EC_WORD_QUES, EC_EMPTY_WORD, EC_WORD_HELLO, EC_WORD_QUES_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HELLO, EC_WORD_MOTHER, EC_WORD_EXCL, EC_WORD_I, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MY, EC_WORD_PHONE, EC_WORD_ISN_T, EC_WORD_WORKING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Miller
=======
        .speechBefore = COMPOUND_STRING("Hello? Hello?!"),
        .speechWin = COMPOUND_STRING("Hello mother! I won!"),
        .speechLose = COMPOUND_STRING("My phone isn't working…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MARV] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("MARV"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_YOU, EC_WORD_CAN, EC_WORD_LOSE, EC_WORD_YOUR, EC_MOVE(SWAGGER), EC_WORD_NOW},
        .speechWin = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NO, EC_MOVE(SWAGGER), EC_WORD_LEFT, EC_WORD_EH_QUES},
        .speechLose = {EC_WORD_GO, EC_WORD_ON, EC_MOVE(SWAGGER), EC_WORD_ALL, EC_WORD_YOU, EC_WORD_WANT},
        .monSet = gBattleFrontierTrainerMons_Marv
=======
        .speechBefore = COMPOUND_STRING("You can lose your swagger now."),
        .speechWin = COMPOUND_STRING("There is no swagger left eh?"),
        .speechLose = COMPOUND_STRING("Go on swagger all you want."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LAYTON] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("LAYTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_I_AM, EC_WORD_TOTALLY, EC_WORD_COOL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN, EC_WORD_LOOK, EC_WORD_UP, EC_WORD_TO, EC_WORD_ME},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_COOL, EC_WORD_EXCL, EC_WORD_NO, EC_WORD_REALLY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Layton
=======
        .speechBefore = COMPOUND_STRING("I know I am totally cool!"),
        .speechWin = COMPOUND_STRING("You can look up to me."),
        .speechLose = COMPOUND_STRING("You're cool! No really!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BROOKS] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("BROOKS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_A, EC_WORD_HIGH, EC_WORD_LEVEL, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_HIGH, EC_WORD_LEVEL, EC_WORD_AND, EC_WORD_EXCITING, EC_WORD_TOO},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_TOO, EC_WORD_HIGH, EC_WORD_IN, EC_WORD_LEVEL, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Brooks
=======
        .speechBefore = COMPOUND_STRING("This is a high level battle."),
        .speechWin = COMPOUND_STRING("That was high level and exciting too."),
        .speechLose = COMPOUND_STRING("You're too high in level…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GREGORY] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("GREGORY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_THAT, EC_WORD_OLD, EC_WORD_YET, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHO, EC_WORD_SAYS, EC_WORD_I_AM, EC_WORD_TOO, EC_WORD_OLD, EC_WORD_QUES},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_NOT, EC_WORD_THAT, EC_WORD_OLD},
        .monSet = gBattleFrontierTrainerMons_Gregory
=======
        .speechBefore = COMPOUND_STRING("I am not that old yet."),
        .speechWin = COMPOUND_STRING("Who says I am too old?"),
        .speechLose = COMPOUND_STRING("Please I am really not that old."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_REESE] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("REESE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_VE, EC_WORD_A, EC_WORD_COUPLE, EC_WORD_THINGS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DON_T, EC_WORD_DIET, EC_WORD_PLAY, EC_WORD_SPORTS, EC_WORD_INSTEAD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_INSTEAD, EC_WORD_OF, EC_WORD_TELEVISION, EC_WORD_GET, EC_WORD_A, EC_WORD_BOOK},
        .monSet = gBattleFrontierTrainerMons_Reese
=======
        .speechBefore = COMPOUND_STRING("I've a couple things."),
        .speechWin = COMPOUND_STRING("Don't diet play sports instead."),
        .speechLose = COMPOUND_STRING("Instead of television get a book."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_MASON] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("MASON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_PLEASE, EC_WORD_DON_T, EC_WORD_MAKE, EC_WORD_THIS, EC_WORD_SCARY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_NOW},
        .speechLose = {EC_WORD_I_AM, EC_WORD_DISAPPOINTED, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Mason
=======
        .speechBefore = COMPOUND_STRING("Please don't make this scary."),
        .speechWin = COMPOUND_STRING("Thank you… I am happy now."),
        .speechLose = COMPOUND_STRING("I am disappointed…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TOBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("TOBY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LISTEN, EC_WORD_UP, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_WIN},
        .speechWin = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_OR, EC_WORD_WHAT, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_CAN, EC_WORD_BEAT, EC_WORD_YOU, EC_WORD_AT, EC_WORD_SMARTNESS},
        .monSet = gBattleFrontierTrainerMons_Toby
=======
        .speechBefore = COMPOUND_STRING("Listen up I always win."),
        .speechWin = COMPOUND_STRING("I am a genius or what?"),
        .speechLose = COMPOUND_STRING("I can beat you at smartness."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DOROTHY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("DOROTHY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_THE, EC_WORD_SPORTS, EC_WORD_WORLD, EC_WORD_SHOULD, EC_WORD_ACCEPT, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_THAT, EC_WORD_WIN, EC_WORD_WAS, EC_WORD_REFRESHING},
        .speechLose = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_THAT, EC_WORD_LOSS, EC_WORD_WAS, EC_WORD_REFRESHING},
        .monSet = gBattleFrontierTrainerMons_Dorothy
=======
        .speechBefore = COMPOUND_STRING("The sports world should accept Pokémon."),
        .speechWin = COMPOUND_STRING("Thank you! That win was refreshing."),
        .speechLose = COMPOUND_STRING("Thank you! That loss was refreshing."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PIPER] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("PIPER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_YOU, EC_WORD_NEED, EC_WORD_A, EC_WORD_SPEED_BOOST, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_NEED, EC_WORD_TO, EC_WORD_SHOW, EC_WORD_MORE, EC_WORD_GUTS},
        .speechLose = {EC_WORD_OH, EC_WORD_YOU, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Piper
=======
        .speechBefore = COMPOUND_STRING("Come on you need a speed boost?"),
        .speechWin = COMPOUND_STRING("You need to show more guts."),
        .speechLose = COMPOUND_STRING("Oh you!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_FINN] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("FINN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_NOT, EC_WORD_ANOTHER, EC_WORD_TRAINER, EC_WORD_BATTLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WON_T, EC_WORD_THIS, EC_WORD_EVER, EC_WORD_END, EC_WORD_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_FINALLY, EC_WORD_GET, EC_WORD_TO, EC_MOVE2(REST), EC_WORD_A_LITTLE},
        .monSet = gBattleFrontierTrainerMons_Finn
=======
        .speechBefore = COMPOUND_STRING("Not another trainer battle…"),
        .speechWin = COMPOUND_STRING("Won't this ever end?"),
        .speechLose = COMPOUND_STRING("I finally get to rest a little."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_SAMIR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("SAMIR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_MOVE2(DIVE), EC_WORD_BELOW, EC_WORD_THE, EC_MOVE2(SURF), EC_WORD_EXCL},
        .speechWin = {EC_WORD_YAHOO, EC_WORD_TAKE, EC_WORD_A, EC_MOVE2(DIVE), EC_WORD_YOU, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_SINK, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Samir
=======
        .speechBefore = COMPOUND_STRING("I dive below the surf!"),
        .speechWin = COMPOUND_STRING("Yahoo take a dive you!"),
        .speechLose = COMPOUND_STRING("I am going to sink…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_FIONA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("FIONA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_DID, EC_WORD_YOU, EC_WORD_LIMBER, EC_WORD_UP, EC_WORD_BEFORE, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_NEED, EC_WORD_TO, EC_WORD_BE, EC_WORD_MORE, EC_WORD_READY},
        .speechLose = {EC_WORD_BEING, EC_WORD_LIMBER, EC_WORD_DIDN_T, EC_WORD_WORK, EC_WORD_FOR, EC_WORD_ME},
        .monSet = gBattleFrontierTrainerMons_Fiona
=======
        .speechBefore = COMPOUND_STRING("Did you limber up before?"),
        .speechWin = COMPOUND_STRING("You need to be more ready."),
        .speechLose = COMPOUND_STRING("Being limber didn't work for me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GLORIA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("GLORIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_ATTACK, EC_WORD_WITH, EC_WORD_SUCTION_CUPS},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_OVER, EC_WORD_FOR, EC_WORD_YOU},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_GET, EC_WORD_HOW, EC_WORD_SUCTION_CUPS, EC_WORD_WORK},
        .monSet = gBattleFrontierTrainerMons_Gloria
=======
        .speechBefore = COMPOUND_STRING("I like to attack with suction cups."),
        .speechWin = COMPOUND_STRING("Giggle… It's over for you."),
        .speechLose = COMPOUND_STRING("I don't get how suction cups work."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_NICO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("NICO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LIKE, EC_WORD_A, EC_MOVE(SONIC_BOOM), EC_WORD_I_VE_ARRIVED, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SORRY, EC_WORD_TO, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_SO, EC_WORD_DOWNCAST},
        .speechLose = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_WITH, EC_WORD_A, EC_MOVE2(SUPERSONIC), EC_WORD_SPEED_BOOST},
        .monSet = gBattleFrontierTrainerMons_Nico
=======
        .speechBefore = COMPOUND_STRING("Like a sonic boom I've arrived."),
        .speechWin = COMPOUND_STRING("Sorry to make you so downcast."),
        .speechLose = COMPOUND_STRING("I am going with a supersonic speed boost."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_JEREMY] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("JEREMY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_MASTER, EC_WORD_THAT_S, EC_WORD_MY, EC_WORD_DREAM},
        .speechWin = {EC_WORD_MY, EC_WORD_DREAM, EC_WORD_ISN_T, EC_WORD_FAR, EC_WORD_OFF, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHAT, EC_WORD_I, EC_WORD_DREAM, EC_WORD_ISN_T, EC_WORD_HAPPENING, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jeremy
=======
        .speechBefore = COMPOUND_STRING("A Pokémon master that's my dream."),
        .speechWin = COMPOUND_STRING("My dream isn't far off!"),
        .speechLose = COMPOUND_STRING("What I dream isn't happening…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CAITLIN] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("CAITLIN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_DON_T, EC_WORD_YOU, EC_WORD_THINK, EC_WORD_I_AM, EC_WORD_CUTE, EC_WORD_QUES},
        .speechWin = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_MORE, EC_WORD_TO_ME, EC_WORD_THAN, EC_WORD_CUTENESS},
        .speechLose = {EC_WORD_MY, EC_WORD_CUTE_CHARM, EC_WORD_DOESN_T, EC_MOVE2(ATTRACT), EC_WORD_YOU, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Caitlin
=======
        .speechBefore = COMPOUND_STRING("Don't you think I am cute?"),
        .speechWin = COMPOUND_STRING("There is more to me than cuteness."),
        .speechLose = COMPOUND_STRING("My cute charm doesn't attract you?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_REENA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("REENA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_HAPPY, EC_WORD_HAPPY, EC_WORD_HAPPY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OH, EC_WORD_YAY, EC_WORD_EXCL, EC_WORD_YAHOO, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_YAHOO, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_FOR, EC_WORD_YOU},
        .monSet = gBattleFrontierTrainerMons_Reena
=======
        .speechBefore = COMPOUND_STRING("I am always happy happy happy!"),
        .speechWin = COMPOUND_STRING("Oh yay! Yahoo for me."),
        .speechLose = COMPOUND_STRING("Yahoo! I am happy for you."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_AVERY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("AVERY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_VE, EC_WORD_GOT, EC_WORD_A_LOT, EC_WORD_OF, EC_WORD_BUG, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_MY, EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ALL, EC_WORD_UNBELIEVABLE},
        .speechLose = {EC_WORD_MY, EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ALL, EC_WORD_UPSIDE_DOWN},
        .monSet = gBattleFrontierTrainerMons_Avery
=======
        .speechBefore = COMPOUND_STRING("I've got a lot of bug Pokémon."),
        .speechWin = COMPOUND_STRING("My bug Pokémon are all unbelievable."),
        .speechLose = COMPOUND_STRING("My bug Pokémon are all upside down."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_LIAM] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("LIAM"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WE, EC_WORD_REALLY, EC_WORD_DISLIKE, EC_WORD_FIRE, EC_WORD_AND, EC_WORD_FLYING},
        .speechWin = {EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_AREN_T, EC_WORD_BAD, EC_WORD_HEY_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU, EC_WORD_KNOW, EC_WORD_WHAT, EC_WORD_WE, EC_WORD_DISLIKE, EC_WORD_HEY_QUES},
        .monSet = gBattleFrontierTrainerMons_Liam
=======
        .speechBefore = COMPOUND_STRING("We really dislike fire and flying."),
        .speechWin = COMPOUND_STRING("Bug Pokémon aren't bad hey ques."),
        .speechLose = COMPOUND_STRING("You know what we dislike hey ques."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_THEO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("THEO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_FISHING, EC_WORD_IS, EC_WORD_MY, EC_WORD_CHOICE, EC_WORD_IN, EC_WORD_LIFE},
        .speechWin = {EC_WORD_WATER, EC_WORD_POKEMON, EC_MOVE2(ATTRACT), EC_WORD_ME, EC_WORD_WITHOUT, EC_WORD_END},
        .speechLose = {EC_WORD_DON_T, EC_WORD_COUNT_ON, EC_WORD_THAT, EC_WORD_HAPPENING, EC_WORD_ANOTHER, EC_WORD_TIME},
        .monSet = gBattleFrontierTrainerMons_Theo
=======
        .speechBefore = COMPOUND_STRING("Fishing is my choice in life."),
        .speechWin = COMPOUND_STRING("Water Pokémon attract me without end."),
        .speechLose = COMPOUND_STRING("Don't count on that happening another time."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BAILEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("BAILEY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_I, EC_WORD_BATTLE, EC_WORD_EASY},
        .speechWin = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_I, EC_MOVE2(SWALLOW), EC_WORD_JOY},
        .speechLose = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_I, EC_MOVE2(SWALLOW), EC_MOVE2(FRUSTRATION)},
        .monSet = gBattleFrontierTrainerMons_Bailey
=======
        .speechBefore = COMPOUND_STRING("I am an adult I battle easy."),
        .speechWin = COMPOUND_STRING("I am an adult I swallow joy."),
        .speechLose = COMPOUND_STRING("I am an adult I swallow frustration."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HUGO] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("HUGO"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_TRY, EC_WORD_THE, EC_WORD_BEST, EC_WORD_I, EC_WORD_CAN},
        .speechWin = {EC_WORD_I, EC_WORD_CAN_WIN, EC_WORD_IF, EC_WORD_I, EC_WORD_TRY, EC_WORD_ENOUGH},
        .speechLose = {EC_WORD_I, EC_WORD_DID, EC_WORD_TRY, EC_WORD_DIDN_T, EC_WORD_I, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Hugo
=======
        .speechBefore = COMPOUND_STRING("I try the best I can."),
        .speechWin = COMPOUND_STRING("I can win if I try enough."),
        .speechLose = COMPOUND_STRING("I did try didn't I?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_BRYCE] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("BRYCE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_WAS, EC_WORD_ON, EC_WORD_VACATION, EC_WORD_UNTIL, EC_WORD_ONLY, EC_WORD_YESTERDAY},
        .speechWin = {EC_WORD_I, EC_WORD_HAVEN_T, EC_WORD_LOST, EC_WORD_MY, EC_WORD_SKILL, EC_WORD_YET},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_IT, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_NEED, EC_WORD_SLEEP},
        .monSet = gBattleFrontierTrainerMons_Bryce
=======
        .speechBefore = COMPOUND_STRING("I was on vacation until only yesterday."),
        .speechWin = COMPOUND_STRING("I haven't lost my skill yet."),
        .speechLose = COMPOUND_STRING("That's it… I need sleep."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GIDEON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("GIDEON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WHAT_S_UP_QUES, EC_WORD_YOU, EC_WORD_THINK, EC_WORD_I_AM, EC_WORD_SCARY, EC_WORD_QUES},
        .speechWin = {EC_WORD_I_AM, EC_WORD_COOL, EC_WORD_BUT, EC_WORD_NOT, EC_WORD_SCARY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_MY, EC_WORD_FABULOUS, EC_WORD_FASHION, EC_WORD_SENSE},
        .monSet = gBattleFrontierTrainerMons_Gideon
=======
        .speechBefore = COMPOUND_STRING("What's up ques you think I am scary?"),
        .speechWin = COMPOUND_STRING("I am cool but not scary!"),
        .speechLose = COMPOUND_STRING("Look at my fabulous fashion sense."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_TRISTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("TRISTON"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_WOULD, EC_WORD_RATHER, EC_WORD_LOOK, EC_WORD_AT, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_HUH_QUES, EC_WORD_YOU, EC_WORD_MEAN, EC_WORD_I, EC_WORD_WON, EC_WORD_QUES_EXCL},
        .speechLose = {EC_WORD_SEE, EC_WORD_QUES, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_LOSE},
        .monSet = gBattleFrontierTrainerMons_Triston
=======
        .speechBefore = COMPOUND_STRING("I would rather look at Pokémon."),
        .speechWin = COMPOUND_STRING("Huh ques you mean I won?!"),
        .speechLose = COMPOUND_STRING("See? I always lose."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_CHARLES] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("CHARLES"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_IT_S, EC_WORD_HOPELESS, EC_WORD_TO, EC_MOVE2(STRUGGLE), EC_WORD_WITH, EC_WORD_ME},
        .speechWin = {EC_MOVE(SUBMISSION), EC_WORD_WAS, EC_WORD_YOUR, EC_WORD_ONLY, EC_WORD_CHOICE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_DOWN, EC_WORD_DOWN, EC_WORD_DOWN, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Charles
=======
        .speechBefore = COMPOUND_STRING("It's hopeless to struggle with me."),
        .speechWin = COMPOUND_STRING("Submission was your only choice."),
        .speechLose = COMPOUND_STRING("I am going down down down!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_RAYMOND] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("RAYMOND"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_WANT, EC_WORD_TO, EC_WORD_HEAR, EC_WORD_MY, EC_WORD_SONG, EC_WORD_QUES},
        .speechWin = {EC_WORD_SATISFIED, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SATISFIED, EC_WORD_IS, EC_WORD_WHAT, EC_WORD_I, EC_WORD_CAN_T, EC_WORD_BE},
        .monSet = gBattleFrontierTrainerMons_Raymond
=======
        .speechBefore = COMPOUND_STRING("Want to hear my song?"),
        .speechWin = COMPOUND_STRING("Satisfied that's what I am!"),
        .speechLose = COMPOUND_STRING("Satisfied is what I can't be."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DIRK] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("DIRK"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_FLYING, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ABOVE, EC_WORD_THE, EC_MOVE2(REST)},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN_T_WIN, EC_WORD_EXCL, EC_WORD_FLYING, EC_WORD_POKEMON, EC_WORD_RULE},
        .speechLose = {EC_WORD_AREN_T, EC_WORD_THERE, EC_WORD_MORE, EC_WORD_FLYING, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Dirk
=======
        .speechBefore = COMPOUND_STRING("Flying Pokémon are above the rest."),
        .speechWin = COMPOUND_STRING("You can't win! Flying Pokémon rule."),
        .speechLose = COMPOUND_STRING("Aren't there more flying Pokémon?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_HAROLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("HAROLD"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_APPEAL, EC_WORD_TO, EC_WORD_YOU, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_DO, EC_WORD_LIKE, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechLose = {EC_WORD_SO, EC_WORD_YOU, EC_WORD_DISLIKE, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Harold
=======
        .speechBefore = COMPOUND_STRING("My Pokémon appeal to you?"),
        .speechWin = COMPOUND_STRING("You do like my Pokémon?"),
        .speechLose = COMPOUND_STRING("So you dislike my Pokémon?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_OMAR] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("OMAR"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_ME_WIN, EC_WORD_IN, EC_MOVE(RETURN), EC_WORD_FOR, EC_WORD_A, EC_MOVE2(PRESENT)},
        .speechWin = {EC_WORD_HERE, EC_WORD_YOU, EC_WORD_ARE, EC_WORD_SOME, EC_MOVE2(TOXIC), EC_WORD_SWEETS},
        .speechLose = {EC_WORD_YOUR, EC_MOVE2(PRESENT), EC_WORD_QUES, EC_WORD_WHAT, EC_WORD_FOR, EC_WORD_QUES_EXCL},
        .monSet = gBattleFrontierTrainerMons_Omar
=======
        .speechBefore = COMPOUND_STRING("Let me win in return for a present."),
        .speechWin = COMPOUND_STRING("Here you are some toxic sweets."),
        .speechLose = COMPOUND_STRING("Your present? What for?!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PETER] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("PETER"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_BRAG, EC_WORD_ABOUT, EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_LISTEN, EC_WORD_TO_ME, EC_WORD_BRAG},
        .speechLose = {EC_WORD_I_AM, EC_WORD_DISAPPOINTED, EC_WORD_YOU, EC_WORD_WON_T, EC_WORD_LISTEN, EC_WORD_TO_ME},
        .monSet = gBattleFrontierTrainerMons_Peter
=======
        .speechBefore = COMPOUND_STRING("I brag about my happiness ok ques."),
        .speechWin = COMPOUND_STRING("You have to listen to me brag."),
        .speechLose = COMPOUND_STRING("I am disappointed you won't listen to me."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DEV] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("DEV"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_LET_S, EC_WORD_GET, EC_WORD_A, EC_WORD_MOVE, EC_WORD_ON},
        .speechWin = {EC_WORD_I, EC_WORD_GET, EC_WORD_TO, EC_WORD_NAP, EC_WORD_AFTER, EC_WORD_THAT},
        .speechLose = {EC_WORD_I, EC_WORD_NEED, EC_WORD_TO, EC_WORD_NAP, EC_WORD_AFTER, EC_WORD_THAT},
        .monSet = gBattleFrontierTrainerMons_Dev
=======
        .speechBefore = COMPOUND_STRING("Come on let's get a move on."),
        .speechWin = COMPOUND_STRING("I get to nap after that."),
        .speechLose = COMPOUND_STRING("I need to nap after that."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_COREY] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("COREY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_S, EC_WORD_TEACH, EC_WORD_YOU, EC_WORD_HOW, EC_WORD_TOUGH, EC_WORD_I_AM},
        .speechWin = {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_ME, EC_WORD_MAKE, EC_WORD_A, EC_MOVE(BRICK_BREAK)},
        .speechLose = {EC_WORD_MY, EC_MOVE2(FRUSTRATION), EC_WORD_IS, EC_WORD_CLOSE, EC_WORD_TO, EC_MOVE2(ERUPTION)},
        .monSet = gBattleFrontierTrainerMons_Corey
=======
        .speechBefore = COMPOUND_STRING("Let's teach you how tough I am."),
        .speechWin = COMPOUND_STRING("Look at me make a brick break."),
        .speechLose = COMPOUND_STRING("My frustration is close to eruption."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ANDRE] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("ANDRE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_NOW, EC_WORD_THIS, EC_WORD_IS, EC_WORD_A, EC_WORD_PERFECT, EC_WORD_FLAME_BODY},
        .speechWin = {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_MY, EC_WORD_FIERY, EC_WORD_DANCE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_WANT, EC_WORD_AN, EC_MOVE2(EXPLOSION), EC_WORD_HERE, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Andre
=======
        .speechBefore = COMPOUND_STRING("Now this is a perfect flame body."),
        .speechWin = COMPOUND_STRING("Look at my fiery dance!"),
        .speechLose = COMPOUND_STRING("You want an explosion here?"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_FERRIS] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("FERRIS"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NO_1, EC_WORD_IN, EC_WORD_THE, EC_WORD_OLD, EC_WORD_CLASS},
        .speechWin = {EC_WORD_NO_1, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_NO_1, EC_WORD_ANY, EC_WORD_MORE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ferris
=======
        .speechBefore = COMPOUND_STRING("I am no 1 in the old class."),
        .speechWin = COMPOUND_STRING("No 1 that's what I am!"),
        .speechLose = COMPOUND_STRING("I am not no 1 any more…"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ALIVIA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("ALIVIA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_GIDDY, EC_WORD_SO, EC_WORD_SHOULD, EC_WORD_YOU},
        .speechWin = {EC_WORD_IT, EC_WORD_WAS, EC_WORD_ALL, EC_WORD_TOGETHER, EC_WORD_TOO, EC_WORD_EASY},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_GIDDY, EC_WORD_UP, EC_WORD_AND, EC_WORD_AWAY},
        .monSet = gBattleFrontierTrainerMons_Alivia
=======
        .speechBefore = COMPOUND_STRING("I am feeling giddy so should you."),
        .speechWin = COMPOUND_STRING("It was all together too easy."),
        .speechLose = COMPOUND_STRING("I will giddy up and away."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_PAIGE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("PAIGE"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_LET_S, EC_WORD_ENJOY, EC_WORD_OUR, EC_WORD_BATTLE, EC_WORD_TOGETHER, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_S_IT_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_THANK_YOU, EC_WORD_VERY, EC_WORD_MUCH},
        .speechLose = {EC_WORD_THAT_S_IT_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_DO, EC_WORD_GO, EC_WORD_ON},
        .monSet = gBattleFrontierTrainerMons_Paige
=======
        .speechBefore = COMPOUND_STRING("Let's enjoy our battle together."),
        .speechWin = COMPOUND_STRING("That's it excl thank you very much."),
        .speechLose = COMPOUND_STRING("That's it excl do go on."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ANYA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("ANYA"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_DISLIKE, EC_WORD_OH, EC_WORD_SO, EC_WORD_PRETTY, EC_WORD_FASHION},
        .speechWin = {EC_WORD_FASHION, EC_WORD_SHOULD, EC_WORD_MATCH, EC_WORD_THE, EC_WORD_PERSON, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PRETTY, EC_WORD_COULD, EC_WORD_BE, EC_WORD_GOOD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anya
=======
        .speechBefore = COMPOUND_STRING("I dislike oh so pretty fashion."),
        .speechWin = COMPOUND_STRING("Fashion should match the person."),
        .speechLose = COMPOUND_STRING("Pretty could be good."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_DAWN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("DAWN"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_GO, EC_WORD_ALL, EC_WORD_OUT, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DON_T, EC_WORD_BE, EC_WORD_A, EC_WORD_BABY, EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU, EC_WORD_WON, EC_WORD_EXCL, EC_WORD_MOVE, EC_WORD_ON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Dawn
=======
        .speechBefore = COMPOUND_STRING("I go all out!"),
        .speechWin = COMPOUND_STRING("Don't be a baby!"),
        .speechLose = COMPOUND_STRING("You won! Move on!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_ABBY] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("ABBY"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_THAT_S, EC_WORD_REFRESHING},
        .speechWin = {EC_WORD_VICTORY, EC_WORD_HAS, EC_WORD_A, EC_MOVE(SWEET_SCENT), EC_WORD_EXCL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHAT, EC_WORD_AN, EC_WORD_AWFUL, EC_WORD_STENCH, EC_WORD_EXCL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Abby
=======
        .speechBefore = COMPOUND_STRING("I like a trainer that's refreshing."),
        .speechWin = COMPOUND_STRING("Victory has a sweet scent!"),
        .speechLose = COMPOUND_STRING("What an awful stench!"),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    },
    [FRONTIER_TRAINER_GRETEL] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("GRETEL"),
<<<<<<< HEAD
        .speechBefore = {EC_WORD_I, EC_WORD_CAUSE, EC_MOVE(OUTRAGE), EC_WORD_AS, EC_WORD_A, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_IT_S, EC_WORD_ONLY, EC_WORD_NATURAL, EC_WORD_SEE_YA, EC_WORD_BYE_BYE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_HARD, EC_WORD_TO, EC_WORD_BELIEVE, EC_WORD_BUT, EC_WORD_CONGRATS},
        .monSet = gBattleFrontierTrainerMons_Gretel
=======
        .speechBefore = COMPOUND_STRING("I cause outrage as a trainer."),
        .speechWin = COMPOUND_STRING("It's only natural see ya bye bye!"),
        .speechLose = COMPOUND_STRING("It's hard to believe but congrats."),
        .monSet = sUniversalMonSet,
>>>>>>> caf732dc3d (Battle Frontier no longer uses EC WORDs!)
    }
};
