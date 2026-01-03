const u8 gEasyChatWord_Listen[] = _("ESCOLTA");
const u8 gEasyChatWord_NotVery[] = _("NO GAIRE");
const u8 gEasyChatWord_Mean[] = _("DOLENT");
const u8 gEasyChatWord_Lie[] = _("MENTIDA");
const u8 gEasyChatWord_Lay[] = _("JEURE");
const u8 gEasyChatWord_Recommend[] = _("RECOMANAR");
const u8 gEasyChatWord_Nitwit[] = _("XIMPLE");
const u8 gEasyChatWord_Quite[] = _("FORÇA");
const u8 gEasyChatWord_From[] = _("DE");
const u8 gEasyChatWord_Feeling[] = _("SENTIMENT");
const u8 gEasyChatWord_But[] = _("PERÒ");
const u8 gEasyChatWord_However[] = _("NO OBSTANT");
const u8 gEasyChatWord_Case[] = _("CAS");
const u8 gEasyChatWord_The[] = _("EL/LA");
const u8 gEasyChatWord_Miss[] = _("FALLAR");
const u8 gEasyChatWord_How[] = _("COM");
const u8 gEasyChatWord_Hit[] = _("COLPEJAR");
const u8 gEasyChatWord_Enough[] = _("PROU");
const u8 gEasyChatWord_ALot[] = _("MOLT");
const u8 gEasyChatWord_ALittle[] = _("UNA MICA");
const u8 gEasyChatWord_Absolutely[] = _("ABSOLUTAMENT");
const u8 gEasyChatWord_And[] = _("I");
const u8 gEasyChatWord_Only[] = _("NOMÉS");
const u8 gEasyChatWord_Around[] = _("AL VOLTANT");
const u8 gEasyChatWord_Probably[] = _("PROBABLEMENT");
const u8 gEasyChatWord_If[] = _("SI");
const u8 gEasyChatWord_Very[] = _("MOLT");
const u8 gEasyChatWord_ATinyBit[] = _("GENS");
const u8 gEasyChatWord_Wild[] = _("SALVATGE");
const u8 gEasyChatWord_Thats[] = _("AIXÒ ÉS");
const u8 gEasyChatWord_Just[] = _("JUST");
const u8 gEasyChatWord_EvenSo[] = _("TOT I AIXÍ");
const u8 gEasyChatWord_MustBe[] = _("HA DE SER");
const u8 gEasyChatWord_Naturally[] = _("NATURALMENT");
const u8 gEasyChatWord_ForNow[] = _("PER ARA");
const u8 gEasyChatWord_Understood[] = _("ENTÈS");
const u8 gEasyChatWord_Joking[] = _("DE BROMA");
const u8 gEasyChatWord_Ready[] = _("A PUNT");
const u8 gEasyChatWord_Something[] = _("ALGUNA COSA");
const u8 gEasyChatWord_Somehow[] = _("D'ALGUNA FORMA");
const u8 gEasyChatWord_Although[] = _("ENCARA QUE");
const u8 gEasyChatWord_Also[] = _("TAMBÉ");
const u8 gEasyChatWord_Perfect[] = _("PERFECTE");
const u8 gEasyChatWord_AsMuchAs[] = _("TANT COM");
const u8 gEasyChatWord_Really[] = _("DE VERITAT");
const u8 gEasyChatWord_Truly[] = _("VERITABLEMENT");
const u8 gEasyChatWord_Seriously[] = _("SERIOSAMENT");
const u8 gEasyChatWord_Totally[] = _("TOTALMENT");
const u8 gEasyChatWord_Until[] = _("FINS");
const u8 gEasyChatWord_AsIf[] = _("COM SI");
const u8 gEasyChatWord_Mood[] = _("HUMOR");
const u8 gEasyChatWord_Rather[] = _("MÉS AVIAT");
const u8 gEasyChatWord_Awfully[] = _("TERRIBLEMENT");
const u8 gEasyChatWord_Mode[] = _("MODE");
const u8 gEasyChatWord_More[] = _("MÉS");
const u8 gEasyChatWord_TooLate[] = _("MASSA TARD");
const u8 gEasyChatWord_Finally[] = _("FINALMENT");
const u8 gEasyChatWord_Any[] = _("QUALSEVOL");
const u8 gEasyChatWord_Instead[] = _("EN CANVI");
const u8 gEasyChatWord_Fantastic[] = _("FANTÀSTIC");

const struct EasyChatWordInfo gEasyChatGroup_Speech[] = {
    [EC_INDEX(EC_WORD_LISTEN)] =
    {
        .text = gEasyChatWord_Listen,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LITTLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOT_VERY)] =
    {
        .text = gEasyChatWord_NotVery,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEAN)] =
    {
        .text = gEasyChatWord_Mean,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_TINY_BIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIE)] =
    {
        .text = gEasyChatWord_Lie,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSOLUTELY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAY)] =
    {
        .text = gEasyChatWord_Lay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALSO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RECOMMEND)] =
    {
        .text = gEasyChatWord_Recommend,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALTHOUGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NITWIT)] =
    {
        .text = gEasyChatWord_Nitwit,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUITE)] =
    {
        .text = gEasyChatWord_Quite,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FROM)] =
    {
        .text = gEasyChatWord_From,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AROUND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEELING)] =
    {
        .text = gEasyChatWord_Feeling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_IF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUT)] =
    {
        .text = gEasyChatWord_But,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_MUCH_AS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOWEVER)] =
    {
        .text = gEasyChatWord_However,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFULLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CASE)] =
    {
        .text = gEasyChatWord_Case,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THE)] =
    {
        .text = gEasyChatWord_The,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISS)] =
    {
        .text = gEasyChatWord_Miss,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENOUGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW)] =
    {
        .text = gEasyChatWord_How,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVEN_SO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIT)] =
    {
        .text = gEasyChatWord_Hit,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FANTASTIC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENOUGH)] =
    {
        .text = gEasyChatWord_Enough,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEELING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_LOT)] =
    {
        .text = gEasyChatWord_ALot,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_LITTLE)] =
    {
        .text = gEasyChatWord_ALittle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOR_NOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSOLUTELY)] =
    {
        .text = gEasyChatWord_Absolutely,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FROM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AND)] =
    {
        .text = gEasyChatWord_And,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ONLY)] =
    {
        .text = gEasyChatWord_Only,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AROUND)] =
    {
        .text = gEasyChatWord_Around,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOWEVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PROBABLY)] =
    {
        .text = gEasyChatWord_Probably,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF)] =
    {
        .text = gEasyChatWord_If,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSTEAD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERY)] =
    {
        .text = gEasyChatWord_Very,
        .alphabeticalOrder = EC_INDEX(EC_WORD_JOKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_TINY_BIT)] =
    {
        .text = gEasyChatWord_ATinyBit,
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WILD)] =
    {
        .text = gEasyChatWord_Wild,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S)] =
    {
        .text = gEasyChatWord_Thats,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUST)] =
    {
        .text = gEasyChatWord_Just,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVEN_SO)] =
    {
        .text = gEasyChatWord_EvenSo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUST_BE)] =
    {
        .text = gEasyChatWord_MustBe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURALLY)] =
    {
        .text = gEasyChatWord_Naturally,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOR_NOW)] =
    {
        .text = gEasyChatWord_ForNow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTOOD)] =
    {
        .text = gEasyChatWord_Understood,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JOKING)] =
    {
        .text = gEasyChatWord_Joking,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUST_BE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_READY)] =
    {
        .text = gEasyChatWord_Ready,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMETHING)] =
    {
        .text = gEasyChatWord_Something,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NITWIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMEHOW)] =
    {
        .text = gEasyChatWord_Somehow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOT_VERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALTHOUGH)] =
    {
        .text = gEasyChatWord_Although,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ONLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALSO)] =
    {
        .text = gEasyChatWord_Also,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECT)] =
    {
        .text = gEasyChatWord_Perfect,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROBABLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS_MUCH_AS)] =
    {
        .text = gEasyChatWord_AsMuchAs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REALLY)] =
    {
        .text = gEasyChatWord_Really,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RATHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRULY)] =
    {
        .text = gEasyChatWord_Truly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_READY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERIOUSLY)] =
    {
        .text = gEasyChatWord_Seriously,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOTALLY)] =
    {
        .text = gEasyChatWord_Totally,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RECOMMEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNTIL)] =
    {
        .text = gEasyChatWord_Until,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUSLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS_IF)] =
    {
        .text = gEasyChatWord_AsIf,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEHOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOOD)] =
    {
        .text = gEasyChatWord_Mood,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMETHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RATHER)] =
    {
        .text = gEasyChatWord_Rather,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFULLY)] =
    {
        .text = gEasyChatWord_Awfully,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODE)] =
    {
        .text = gEasyChatWord_Mode,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_LATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MORE)] =
    {
        .text = gEasyChatWord_More,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOTALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_LATE)] =
    {
        .text = gEasyChatWord_TooLate,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRULY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FINALLY)] =
    {
        .text = gEasyChatWord_Finally,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANY)] =
    {
        .text = gEasyChatWord_Any,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNTIL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSTEAD)] =
    {
        .text = gEasyChatWord_Instead,
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FANTASTIC)] =
    {
        .text = gEasyChatWord_Fantastic,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILD),
        .enabled = TRUE,
    },
};
