declare namespace swisseph {
    // #region Constants
    const SE_AUNIT_TO_KM = 149597870.7;
    const SE_AUNIT_TO_LIGHTYEAR = 1.5812507409819728411242766893179e-5; // = 1.0 / 63241.07708427
    const SE_AUNIT_TO_PARSEC = 4.8481368110952742659276431719005e-6; // = 1.0 / 206264.8062471

    const SE_MAX_STNAME = 256;

    const SE_SIDBITS = 256;
    const SE_SIDBIT_ECL_T0 = 256;
    const SE_SIDBIT_SSY_PLANE = 512;
    const SE_SIDBIT_USER_UT = 1024;

    const SE_BIT_DISC_CENTER = 256;
    const SE_BIT_DISC_BOTTOM = 8192;
    const SE_BIT_GEOCTR_NO_ECL_LAT = 128;
    const SE_BIT_NO_REFRACTION = 512;
    const SE_BIT_CIVIL_TWILIGHT = 1024;
    const SE_BIT_NAUTIC_TWILIGHT = 2048;
    const SE_BIT_ASTRO_TWILIGHT = 4096;
    const SE_BIT_FIXED_DISC_SIZE = 16384; // = 16 * 1024

    const TJD_INVALID = 99999999.0;
    const SIMULATE_VICTORVB = 1;

    const SE_PHOTOPIC_FLAG = 0;
    const SE_SCOTOPIC_FLAG = 1;
    const SE_MIXEDOPIC_FLAG = 2;

    const ephemeris: {
        swisseph: 2; // = SEFLG_SWIEPH
        moshier: 4; // = SEFLG_MOSEPH
        de200: "de200.eph";
        de405: "de405.eph";
        de406: "de406.eph";
        de406e: "de406e.eph";
        de414: "de414.eph";
        de421: "de421.eph";
        de422: "de422.eph";
        de430: "de430.eph";
        de431: "de431.eph";
    };

    // Calendar types
    const SE_JUL_CAL = 0;
    const SE_GREG_CAL = 1;

    // Planet numbers
    const SE_SUN = 0;
    const SE_MOON = 1;
    const SE_MERCURY = 2;
    const SE_VENUS = 3;
    const SE_EARTH = 14;
    const SE_MARS = 4;
    const SE_JUPITER = 5;
    const SE_SATURN = 6;
    const SE_URANUS = 7;
    const SE_NEPTUNE = 8;
    const SE_PLUTO = 9;

    // Moon nodes
    const SE_MEAN_NODE = 10;
    const SE_TRUE_NODE = 11;
    const SE_MEAN_APOG = 12;
    const SE_OSCU_APOG = 13;
    const SE_INTP_APOG = 21;
    const SE_INTP_PERG = 22;

    // Base asteroids
    const SE_CHIRON = 15;
    const SE_PHOLUS = 16;
    const SE_CERES = 17;
    const SE_PALLAS = 18;
    const SE_JUNO = 19;
    const SE_VESTA = 20;

    const SE_NPLANETS = 23;
    const SE_AST_OFFSET = 10000;
    const SE_VARUNA = 30000; // = SE_AST_OFFSET + 20000
    const SE_FICT_OFFSET = 40;
    const SE_FICT_OFFSET_1 = 39;
    const SE_FICT_MAX = 999;
    const SE_NFICT_ELEM = 15;
    const SE_COMET_OFFSET = 1000;
    const SE_NALL_NAT_POINTS = 38; // = SE_NPLANETS + SE_NFICT_ELEM

    // Hamburger or Uranian "planets"
    const SE_CUPIDO = 40;
    const SE_HADES = 41;
    const SE_ZEUS = 42;
    const SE_KRONOS = 43;
    const SE_APOLLON = 44;
    const SE_ADMETOS = 45;
    const SE_VULKANUS = 46;
    const SE_POSEIDON = 47;

    // Other fictitious bodies
    const SE_ISIS = 48;
    const SE_NIBIRU = 49;
    const SE_HARRINGTON = 50;
    const SE_NEPTUNE_LEVERRIER = 51;
    const SE_NEPTUNE_ADAMS = 52;
    const SE_PLUTO_LOWELL = 53;
    const SE_PLUTO_PICKERING = 54;
    const SE_VULCAN = 55;
    const SE_WHITE_MOON = 56;
    const SE_PROSERPINA = 57;
    const SE_WALDEMATH = 58;

    const SE_FIXSTAR = -10;
    const SE_ASC = 0;
    const SE_MC = 1;
    const SE_ARMC = 2;
    const SE_VERTEX = 3;
    const SE_EQUASC = 4;
    const SE_COASC1 = 5;
    const SE_COASC2 = 6;
    const SE_POLASC = 7;
    const SE_NASCMC = 8;

    // Flag bits for "iflag" parameter of the "swe_calc" functions
    const SEFLG_JPLEPH = 1;
    const SEFLG_SWIEPH = 2;
    const SEFLG_MOSEPH = 4;
    const SEFLG_HELCTR = 8;
    const SEFLG_TRUEPOS = 16;
    const SEFLG_J2000 = 32;
    const SEFLG_NONUT = 64;
    const SEFLG_SPEED3 = 128;
    const SEFLG_SPEED = 256;
    const SEFLG_NOGDEFL = 512;
    const SEFLG_NOABERR = 1024;
    const SEFLG_ASTROMETRIC = 1536; // = SEFLG_NOABERR | SEFLG_NOGDEFL
    const SEFLG_EQUATORIAL = 2048; // = 2  *1024
    const SEFLG_XYZ = 4096; // = 4 * 1024
    const SEFLG_RADIANS = 8192; // = 8 * 1024
    const SEFLG_BARYCTR = 16384; // = 16 * 1024
    const SEFLG_TOPOCTR = 32768; // = 32 * 1024
    const SEFLG_ORBEL_AA = 32768; // = SEFLG_TOPOCTR
    const SEFLG_SIDEREAL = 65536; // = 64 * 1024
    const SEFLG_ICRS = 131072; // = 128 * 1024
    const SEFLG_DPSIDEPS_1980 = 262144; // = 256*1024
    const SEFLG_JPLHOR = 262144; // = SEFLG_DPSIDEPS_1980
    const SEFLG_JPLHOR_APPROX = 524288; // = 512*1024
    const SEFLG_DEFAULTEPH = 2; // = SEFLG_SWIEPH

    // Sidereal modes
    const SE_SIDM_FAGAN_BRADLEY = 0;
    const SE_SIDM_LAHIRI = 1;
    const SE_SIDM_DELUCE = 2;
    const SE_SIDM_RAMAN = 3;
    const SE_SIDM_USHASHASHI = 4;
    const SE_SIDM_KRISHNAMURTI = 5;
    const SE_SIDM_DJWHAL_KHUL = 6;
    const SE_SIDM_YUKTESHWAR = 7;
    const SE_SIDM_JN_BHASIN = 8;
    const SE_SIDM_BABYL_KUGLER1 = 9;
    const SE_SIDM_BABYL_KUGLER2 = 10;
    const SE_SIDM_BABYL_KUGLER3 = 11;
    const SE_SIDM_BABYL_HUBER = 12;
    const SE_SIDM_BABYL_ETPSC = 13;
    const SE_SIDM_ALDEBARAN_15TAU = 14;
    const SE_SIDM_HIPPARCHOS = 15;
    const SE_SIDM_SASSANIAN = 16;
    const SE_SIDM_GALCENT_0SAG = 17;
    const SE_SIDM_J2000 = 18;
    const SE_SIDM_J1900 = 19;
    const SE_SIDM_B1950 = 20;
    const SE_SIDM_SURYASIDDHANTA = 21;
    const SE_SIDM_SURYASIDDHANTA_MSUN = 22;
    const SE_SIDM_ARYABHATA = 23;
    const SE_SIDM_ARYABHATA_MSUN = 24;
    const SE_SIDM_SS_REVATI = 25;
    const SE_SIDM_SS_CITRA = 26;
    const SE_SIDM_TRUE_CITRA = 27;
    const SE_SIDM_TRUE_REVATI = 28;
    const SE_SIDM_TRUE_PUSHYA = 29;
    const SE_SIDM_GALCENT_RGILBRAND = 30;
    const SE_SIDM_GALEQU_IAU1958 = 31;
    const SE_SIDM_GALEQU_TRUE = 32;
    const SE_SIDM_GALEQU_MULA = 33;
    const SE_SIDM_GALALIGN_MARDYKS = 34;
    const SE_SIDM_TRUE_MULA = 35;
    const SE_SIDM_GALCENT_MULA_WILHELM = 36;
    const SE_SIDM_ARYABHATA_522 = 37;
    const SE_SIDM_BABYL_BRITTON = 38;
    const SE_SIDM_TRUE_SHEORAN = 39;
    const SE_SIDM_GALCENT_COCHRANE = 40;
    const SE_SIDM_GALEQU_FIORENZA = 41;
    const SE_SIDM_VALENS_MOON = 42;
    const SE_SIDM_USER = 255;
    const SE_NSIDM_PREDEF = 43;

    // Used for "swe_nod_aps" function
    const SE_NODBIT_MEAN = 1;
    const SE_NODBIT_OSCU = 2;
    const SE_NODBIT_OSCU_BAR = 4;
    const SE_NODBIT_FOPOINT = 256;

    // Used for eclipse computations
    const SE_ECL_NUT = -1;
    const SE_ECL_CENTRAL = 1;
    const SE_ECL_NONCENTRAL = 2;
    const SE_ECL_TOTAL = 4;
    const SE_ECL_ANNULAR = 8;
    const SE_ECL_PARTIAL = 16;
    const SE_ECL_ANNULAR_TOTAL = 32;
    const SE_ECL_PENUMBRAL = 64;
    const SE_ECL_ALLTYPES_SOLAR = 63; // = SE_ECL_CENTRAL | SE_ECL_NONCENTRAL | SE_ECL_TOTAL | SE_ECL_ANNULAR | SE_ECL_PARTIAL | SE_ECL_ANNULAR_TOTAL
    const SE_ECL_ALLTYPES_LUNAR = 84; // = SE_ECL_TOTAL | SE_ECL_PARTIAL | SE_ECL_PENUMBRAL
    const SE_ECL_VISIBLE = 128;
    const SE_ECL_MAX_VISIBLE = 256;
    const SE_ECL_1ST_VISIBLE = 512;
    const SE_ECL_PARTBEG_VISIBLE = 512;
    const SE_ECL_2ND_VISIBLE = 1024;
    const SE_ECL_TOTBEG_VISIBLE = 1024;
    const SE_ECL_3RD_VISIBLE = 2048;
    const SE_ECL_TOTEND_VISIBLE = 2048;
    const SE_ECL_4TH_VISIBLE = 4096;
    const SE_ECL_PARTEND_VISIBLE = 4096;
    const SE_ECL_PENUMBBEG_VISIBLE = 8192;
    const SE_ECL_PENUMBEND_VISIBLE = 16384;
    const SE_ECL_OCC_BEG_DAYLIGHT = 8192;
    const SE_ECL_OCC_END_DAYLIGHT = 16384;
    const SE_ECL_ONE_TRY = 32768; // = 32 * 1024

    // Used for "swe_rise_transit"
    const SE_CALC_RISE = 1;
    const SE_CALC_SET = 2;
    const SE_CALC_MTRANSIT = 4;
    const SE_CALC_ITRANSIT = 8;

    // Used for "swe_azalt" and "swe_azalt_rev" functions
    const SE_ECL2HOR = 0;
    const SE_EQU2HOR = 1;
    const SE_HOR2ECL = 0;
    const SE_HOR2EQU = 1;

    // Used for "swe_refrac" function
    const SE_TRUE_TO_APP = 0;
    const SE_APP_TO_TRUE = 1;

    // Rounding flags for "swe_split_deg" function
    const SE_SPLIT_DEG_ROUND_SEC = 1;
    const SE_SPLIT_DEG_ROUND_MIN = 2;
    const SE_SPLIT_DEG_ROUND_DEG = 4;
    const SE_SPLIT_DEG_ZODIACAL = 8;
    const SE_SPLIT_DEG_KEEP_SIGN = 16;
    const SE_SPLIT_DEG_KEEP_DEG: 32;
    const SE_SPLIT_DEG_NAKSHATRA = 1024;

    // Used for heliacal functions
    const SE_HELIACAL_RISING = 1;
    const SE_HELIACAL_SETTING = 2;
    const SE_MORNING_FIRST = 1; // = SE_HELIACAL_RISING
    const SE_EVENING_LAST = 2; // = SE_HELIACAL_SETTING
    const SE_EVENING_FIRST = 3;
    const SE_MORNING_LAST = 4;
    const SE_ACRONYCHAL_RISING = 5;
    const SE_ACRONYCHAL_SETTING = 6;
    const SE_COSMICAL_SETTING = 6; // = SE_ACRONYCHAL_SETTING

    const SE_HELFLAG_LONG_SEARCH = 128;
    const SE_HELFLAG_HIGH_PRECISION = 256;
    const SE_HELFLAG_OPTICAL_PARAMS = 512;
    const SE_HELFLAG_NO_DETAILS = 1024;
    const SE_HELFLAG_SEARCH_1_PERIOD = 2048; // = 1 << 11
    const SE_HELFLAG_VISLIM_DARK = 4096; // = 1 << 12
    const SE_HELFLAG_VISLIM_NOMOON = 8192; // = 1 << 13
    const SE_HELFLAG_VISLIM_PHOTOPIC = 16384; // = 1 << 14
    const SE_HELFLAG_AVKIND_VR = 32768; // = 1 << 15
    const SE_HELFLAG_AVKIND_PTO = 65536; // = 1 << 16
    const SE_HELFLAG_AVKIND_MIN7 = 131072; // = 1 << 17
    const SE_HELFLAG_AVKIND_MIN9 = 262144; // = 1 << 18
    const SE_HELFLAG_AVKIND = 491520; // = SE_HELFLAG_AVKIND_VR | SE_HELFLAG_AVKIND_PTO | SE_HELFLAG_AVKIND_MIN7 | SE_HELFLAG_AVKIND_MIN9
    // #endregion Constants

    /**
     * All functions that return a value have an optional callback parameter as their last parameter.
     * That callback has a result argument with the same type as the return type of the function.
     * This type simplifies the type definition of that callback argument.
     */
    type ResultCallback<T extends (...args: any) => any> = (result: ReturnType<T>) => void;

    // #region Util
    /**
     * Computes the difference between Universal Time (UT, GMT) and Ephemeris time.
     * @param tjd The Julian day.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_deltat(tjd: number, callback?: ResultCallback<typeof swe_deltat>): { delta: number };

    /**
     * Returns the difference between local apparent and local mean time.
     * @param tjd The Julian day.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_time_equ(
        tjd: number,
        callback?: ResultCallback<typeof swe_time_equ>
    ): { timeEquation: number } | { error: string };

    /**
     * Returns sidereal time for a Julian day, obliquity and nutation.
     * @param tjd_ut The Julian day.
     * @param eps The obliquity.
     * @param nut The nutation.
     * @param callback Optional callback called with the result.
     * @returns Sidereal time at the Greenwich Meridian, measured in hours.
     */
    function swe_sidtime0(
        tjd_ut: number,
        eps: number,
        nut: number,
        callback?: ResultCallback<typeof swe_sidtime0>
    ): {
        siderialTime: number;
    };

    /**
     * Returns sidereal time for a Julian day. Computes obliquity and nutation internally.
     * @param tjd_ut The Julian day.
     * @param callback Optional callback called with the result.
     * @returns Sidereal time at the Greenwich Meridian, measured in hours.
     */
    function swe_sidtime(tjd_ut: number, callback?: ResultCallback<typeof swe_sidtime>): { siderialTime: number };

    /**
     * Coordinate transformation, from ecliptic to equator or vice-versa.
     * - equator -> ecliptic: eps must be positive
     * - ecliptic -> equator: eps must be negative
     * Note: eps, longitude and latitude are in positive degrees!
     * @param xpo 3 doubles: long., lat., dist. to be converted; distance remains unchanged, can be set to 1.00.
     * @param eps Obliquity of ecliptic, in degrees.
     * @param callback Optional callback called with the result.
     * @returns Result of the conversion. 3 doubles: long., lat., dist.
     */
    function swe_cotrans(
        xpo: number[],
        eps: number,
        callback?: ResultCallback<typeof swe_cotrans>
    ): {
        longitude: number;
        latitude: number;
        distance: number;
    };

    /**
     * Coordinate transformation of position and speed, from ecliptic to equator or vice-versa.
     * - equator -> ecliptic: eps must be positive
     * - ecliptic -> equator: eps must be negative
     * Note: eps, long., lat., and speeds in long. and lat. are in degrees!
     * @param xpo 6 doubles, input: long., lat., dist. and speeds in long., lat and dist.
     * @param eps Obliquity of ecliptic, in degrees.
     * @param callback Optional callback called with the result.
     * @returns Result of the conversion. 6 doubles, position and speed in new coordinate system.
     */
    function swe_cotrans_sp(
        xpo: number[],
        eps: number,
        callback?: ResultCallback<typeof swe_cotrans_sp>
    ): {
        longitude: number;
        latitude: number;
        distance: number;
        longitudeSpeed: number;
        latitudeSpeed: number;
        distanceSpeed: number;
    };

    /**
     * Returns the tidal acceleration used in swe_deltat().
     * @param callback Optional callback called with the result.
     * @returns The tidal acceleration.
     */
    function swe_get_tid_acc(callback?: ResultCallback<typeof swe_get_tid_acc>): { acceleration: number };

    /**
     * Sets the tidal acceleration to be used in swe_deltat().
     * @param t_acc The tidal acceleration.
     * @param callback Optional callback called with an empty object.
     * @returns An empty object.
     */
    function swe_set_tid_acc(t_acc: number, callback?: ResultCallback<typeof swe_set_tid_acc>): {};

    /**
     * Normalizes a degree to the range 0 - 360.
     * @param x The degree to normalize.
     * @param callback Optional callback called with the result.
     * @returns The result of the normalization.
     */
    function swe_degnorm(x: number, callback?: ResultCallback<typeof swe_degnorm>): { x360: number };

    /**
     * Normalizes a radian to the range 0 - 2 PI.
     * @param x The radian to normalize.
     * @param callback Optional callback called with the result.
     * @returns The result of the normalization.
     */
    function swe_radnorm(x: number, callback?: ResultCallback<typeof swe_radnorm>): { x2Pi: number };

    /**
     * Return the mid point between two radians.
     * @param x1 The first radian.
     * @param x0 The second radian.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_rad_midp(x1: number, x0: number, callback?: ResultCallback<typeof swe_rad_midp>): { xMid2Pi: number };

    /**
     * Return the mid point between two degrees.
     * @param x1 The first degree.
     * @param x0 The second degree.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_deg_midp(x1: number, x0: number, callback?: ResultCallback<typeof swe_deg_midp>): { xMid360: number };

    /**
     * Split degrees to sign/nakshatra, degrees, minutes, seconds of arc.
     * @param ddeg Decimal degrees, ecliptic longitude.
     * @param roundflag By default there is no rounding. If rounding is required, the following bits can be set:
     *                  SE_SPLIT_DEG_ROUND_SEC, SE_SPLIT_DEG_ROUND_MIN, SE_SPLIT_DEG_ROUND_DEG,
     *                  SE_SPLIT_DEG_ZODIACAL, SE_SPLIT_DEG_KEEP_SIGN and SE_SPLIT_DEG_NAKSHATRA.
     * @param callback Optional callback called with the result.
     * @returns The result of the splitting.
     *          (degree = degree integer, min = degree minutes, second = degree seconds,
     *           secondFraction = degree fraction of seconds, sign = zodiac sign number)
     */
    function swe_split_deg(
        ddeg: number,
        roundflag: number,
        callback?: ResultCallback<typeof swe_split_deg>
    ): {
        degree: number;
        min: number;
        second: number;
        secondFraction: number;
        sign: number;
    };

    /**
     * Normalize a centisecond value into the interval 0 - 360 DEG.
     * @param p The centisecond value.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_csnorm(p: number, callback?: ResultCallback<typeof swe_csnorm>): { centisec360: number };

    /**
     * Distance in centisecs between p1 and p2 normalized to 0 - 360.
     * @param p1 The first centisecond value
     * @param p2 The second centisecond value
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_difcsn(p1: number, p2: number, callback?: ResultCallback<typeof swe_difcsn>): { centisecDiff: number };

    /**
     * Distance in degrees between p1 and p2.
     * @param p1 The first degree value.
     * @param p2 The second degree value.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_difdegn(p1: number, p2: number, callback?: ResultCallback<typeof swe_difdegn>): { degreeDiff: number };

    /**
     * Distance in centisecs between p1 and p2 normalized to -180 - 180.
     * @param p1 The first centisecond value
     * @param p2 The second centisecond value
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_difcs2n(
        p1: number,
        p2: number,
        callback?: ResultCallback<typeof swe_difcs2n>
    ): { centisecDistance180: number };

    /**
     * Distance in degrees between p1 and p2 normalized to -180 - 180.
     * @param p1 The first degree value.
     * @param p2 The second degree value.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_difdeg2n(
        p1: number,
        p2: number,
        callback?: ResultCallback<typeof swe_difdeg2n>
    ): { degreeDistance180: number };

    /**
     * Distance in radians between p1 and p2 normalized to -PI - PI.
     * @param p1 The first radian value.
     * @param p2 The second radian value.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_difrad2n(
        p1: number,
        p2: number,
        callback?: ResultCallback<typeof swe_difrad2n>
    ): { degreeDistancePi: number };

    /**
     * Round centisecond value, but at 29.5959 always down.
     * @param x The centisecond value to round.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_csroundsec(x: number, callback?: ResultCallback<typeof swe_csroundsec>): { centisecRound: number };

    /**
     * Convert double to long with rounding, no overflow check.
     * @param x The double value to convert.
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_d2l(x: number, callback?: ResultCallback<typeof swe_d2l>): { xRound: number };

    /**
     * Returns the day of week for a Julian day.
     * @param jd The Julian day.
     * @param callback Optional callback called with the result.
     * @returns Monday = 0, ... Sunday = 6.
     */
    function swe_day_of_week(jd: number, callback?: ResultCallback<typeof swe_day_of_week>): { dayOfWeek: number };

    /**
     * Converts a centisecond value to a time string.
     * @param t The centisecond value.
     * @param sep Separator value.
     * @param suppressZero Specifies whether to suppress zero values. (0 = no, 1 = yes)
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_cs2timestr(
        t: number,
        sep: number,
        suppressZero: number,
        callback?: ResultCallback<typeof swe_cs2timestr>
    ): { timeString: string };

    /**
     * Converts a centisecond value to a longitude or latitude string.
     * @param t The centisecond value.
     * @param pchar Character used for positive values.
     * @param mchar Character used for negative values.
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_cs2lonlatstr(
        t: number,
        pchar: string,
        mchar: string,
        callback?: ResultCallback<typeof swe_cs2lonlatstr>
    ): { lonlatString: string };

    /**
     * Converts a centisecond value to a degree string.
     * @param t The centisecond value.
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_cs2degstr(t: number, callback?: ResultCallback<typeof swe_cs2degstr>): { degreeString: string };
    // #endregion Util

    // #region Date
    /**
     * Conversion from day, month, year, time to Julian day with error handling.
     * @param year The year of the date.
     * @param month The month of the date.
     * @param day The day of the date.
     * @param hour The hour of the date.
     * @param gregflag Specifies whether the input date is Julian calendar ('j') or Gregorian calendar ('g').
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion or an error.
     */
    function swe_date_conversion(
        year: number,
        month: number,
        day: number,
        hour: number,
        gregflag: "g" | "j",
        callback?: ResultCallback<typeof swe_date_conversion>
    ): { julianDay: number } | { error: string };

    /**
     * Conversion from day, month, year, time to Julian day.
     * @param year The year of the date.
     * @param month The month of the date.
     * @param day The day of the date.
     * @param hour The hour of the date.
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_julday(
        year: number,
        month: number,
        day: number,
        hour: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: ResultCallback<typeof swe_julday>
    ): number;

    /**
     * Reverse conversion of a Julian day value to a date object.
     * @param jd The Julian day.
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_revjul(
        jd: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: ResultCallback<typeof swe_revjul>
    ): {
        year: number;
        month: number;
        day: number;
        hour: number;
    };

    /**
     * Conversion from day, month, year, time in Coordinated Universal Time (UTC) to Julian day.
     * @param iyear The year of the date.
     * @param imonth The month of the date.
     * @param iday The day of the date.
     * @param ihour The hour of the date.
     * @param imin The minute of the date.
     * @param dsec The second of the date.
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion or an error.
     */
    function swe_utc_to_jd(
        iyear: number,
        imonth: number,
        iday: number,
        ihour: number,
        imin: number,
        dsec: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: ResultCallback<typeof swe_utc_to_jd>
    ):
        | {
              julianDayET: number;
              julianDayUT: number;
          }
        | { error: string };

    /**
     * Reverse conversion of a Julian day value to a date object in Coordinated Universal Time (UTC).
     * @param tjd_et The Julian day number in ET (TT).
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_jdet_to_utc(
        tjd_et: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: ResultCallback<typeof swe_jdet_to_utc>
    ): {
        year: number;
        month: number;
        day: number;
        hour: number;
        minute: number;
        second: number;
    };

    /**
     * Reverse conversion of a Julian day value to a date object in Coordinated Universal Time (UTC).
     * @param tjd_ut The Julian day number in UT (UT1).
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_jdut1_to_utc(
        tjd_ut: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: ResultCallback<typeof swe_jdut1_to_utc>
    ): {
        year: number;
        month: number;
        day: number;
        hour: number;
        minute: number;
        second: number;
    };

    /**
     * Converts a UTC date value to a local date value using the specified time zone offset.
     * @param iyear The year of the date.
     * @param imonth The month of the date.
     * @param iday The day of the date.
     * @param ihour The hour of the date.
     * @param imin The minute of the date.
     * @param dsec The second of the date.
     * @param d_timezone The time zone offset.
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_utc_time_zone(
        iyear: number,
        imonth: number,
        iday: number,
        ihour: number,
        imin: number,
        dsec: number,
        d_timezone: number,
        callback?: ResultCallback<typeof swe_utc_time_zone>
    ): {
        year: number;
        month: number;
        day: number;
        hour: number;
        minute: number;
        second: number;
    };
    // #endregion Date

    // #region Pos
    /**
     * Returns a string with the version number of your Swiss Ephemeris.
     * @param callback Optional callback called with the result.
     * @returns The version number of your Swiss Ephemeris.
     */
    function swe_version(callback?: ResultCallback<typeof swe_version>): string;

    /**
     * Computes the position of a planet, asteroid, lunar node or an apogee for a specified Universal Time.
     * @param tjd_ut The Julian day in Universal Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_calc_ut(
        tjd_ut: number,
        ipl: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_calc_ut>
    ):
        | {
              longitude: number;
              latitude: number;
              distance: number;
              longitudeSpeed: number;
              latitudeSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              rectAscension: number;
              declination: number;
              distance: number;
              rectAscensionSpeed: number;
              declinationSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              x: number;
              y: number;
              z: number;
              dx: number;
              dy: number;
              dz: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the position of a planet, asteroid, lunar node or an apogee for a specified Terrestrial Time.
     * @param tjd The Julian day in Terrestrial Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_calc(
        tjd: number,
        ipl: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_calc>
    ):
        | {
              longitude: number;
              latitude: number;
              distance: number;
              longitudeSpeed: number;
              latitudeSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              rectAscension: number;
              declination: number;
              distance: number;
              rectAscensionSpeed: number;
              declinationSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              x: number;
              y: number;
              z: number;
              dx: number;
              dy: number;
              dz: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the position of a fixed star for a specified Terrestrial Time.
     * @param star The search string used to find the fixed star by name.
     *             The search string is treated as having a wildcard at the end.
     * @param tjd The Julian day in Terrestrial Time.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     * @see {@link swe_fixstar} for a newer and faster implementation.
     */
    function swe_fixstar(
        star: string,
        tjd: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_fixstar>
    ):
        | {
              name: string;
              longitude: number;
              latitude: number;
              distance: number;
              longitudeSpeed: number;
              latitudeSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              rectAscension: number;
              declination: number;
              distance: number;
              rectAscensionSpeed: number;
              declinationSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              x: number;
              y: number;
              z: number;
              dx: number;
              dy: number;
              dz: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the position of a fixed star for a specified Universal Time.
     * @param star The search string used to find the fixed star by name.
     *             The search string is treated as having a wildcard at the end.
     * @param tjd_ut The Julian day in Universal Time.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     * @see {@link swe_fixstar2_ut} for a newer and faster implementation.
     */
    function swe_fixstar_ut(
        star: string,
        tjd_ut: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_fixstar_ut>
    ):
        | {
              name: string;
              longitude: number;
              latitude: number;
              distance: number;
              longitudeSpeed: number;
              latitudeSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              rectAscension: number;
              declination: number;
              distance: number;
              rectAscensionSpeed: number;
              declinationSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              x: number;
              y: number;
              z: number;
              dx: number;
              dy: number;
              dz: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Returns the magnitude of a fixed star.
     * @param star The search string used to find the fixed star by name.
     *             The search string is treated as having a wildcard at the end.
     * @param callback Optional callback called with the result.
     * @returns The magnitude of the fixed star or an error.
     * @see {@link swe_fixstar2_mag} for a newer and faster implementation.
     */
    function swe_fixstar_mag(
        star: string,
        callback?: ResultCallback<typeof swe_fixstar_mag>
    ):
        | {
              name: string;
              magnitude: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the position of a fixed star for a specified Terrestrial Time.
     * @param star The name of fixed star to be searched. You can specify a '%' sign at the end as a wildcard.
     * @param tjd The Julian day in Terrestrial Time.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_fixstar2(
        star: string,
        tjd: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_fixstar2>
    ):
        | {
              name: string;
              longitude: number;
              latitude: number;
              distance: number;
              longitudeSpeed: number;
              latitudeSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              rectAscension: number;
              declination: number;
              distance: number;
              rectAscensionSpeed: number;
              declinationSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              x: number;
              y: number;
              z: number;
              dx: number;
              dy: number;
              dz: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the position of a fixed star for a specified Universal Time.
     * @param star The name of fixed star to be searched. You can specify a '%' sign at the end as a wildcard.
     * @param tjd_ut The Julian day in Universal Time.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_fixstar2_ut(
        star: string,
        tjd_ut: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_fixstar2_ut>
    ):
        | {
              name: string;
              longitude: number;
              latitude: number;
              distance: number;
              longitudeSpeed: number;
              latitudeSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              rectAscension: number;
              declination: number;
              distance: number;
              rectAscensionSpeed: number;
              declinationSpeed: number;
              distanceSpeed: number;
              rflag: number;
          }
        | {
              name: string;
              x: number;
              y: number;
              z: number;
              dx: number;
              dy: number;
              dz: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Returns the magnitude of a fixed star.
     * @param star The name of fixed star to be searched. You can specify a '%' sign at the end as a wildcard.
     * @param callback Optional callback called with the result.
     * @returns The magnitude of the fixed star or an error.
     */
    function swe_fixstar2_mag(
        star: string,
        callback?: ResultCallback<typeof swe_fixstar2_mag>
    ):
        | {
              name: string;
              magnitude: number;
          }
        | {
              error: string;
          };

    /**
     * Releases most resources used by the Swiss Ephemeris library.
     * @param callback Optional callback called with undefined as parameter.
     * @returns Always undefined.
     */
    function swe_close(callback?: ResultCallback<typeof swe_close>): undefined;

    /**
     * Sets application's own ephemeris path.
     * @param path Path to ephemeris data files.
     * @param callback Optional callback called with the path as a String object.
     * @returns The path as a String object.
     */
    function swe_set_ephe_path(path: string, callback?: ResultCallback<typeof swe_set_ephe_path>): String;

    /**
     * Sets the name of the JPL ephemeris file.
     * @param fname JPL ephemeris filename.
     * @param callback Optional callback called with the filename as a String object.
     * @returns The filename as a String object.
     */
    function swe_set_jpl_file(fname: string, callback?: ResultCallback<typeof swe_set_jpl_file>): String;

    /**
     * Returns the planetary or asteroid name for a given planet number.
     * @param ipl The planet number.
     * @param callback Optional callback called with the result.
     * @returns The name of the planet or asteroid.
     */
    function swe_get_planet_name(
        ipl: number,
        callback?: ResultCallback<typeof swe_get_planet_name>
    ): {
        name: string;
    };

    /**
     * Sets the geographic location for topocentric planet computations.
     * @param geolon Geographic longitude in degress.
     * @param geolat Geographic latitude in degress.
     * @param geoalt Altitude above sea in meters.
     * @param callback Optional callback called with undefined as parameter.
     * @returns Always undefined.
     */
    function swe_set_topo(
        geolon: number,
        geolat: number,
        geoalt: number,
        callback?: ResultCallback<typeof swe_set_topo>
    ): undefined;

    /**
     * Sets the mode for sidereal computations.
     * @param sid_mode The sidereal mode to set.
     * @param t0 Reference epoch.
     * @param ayan_t0 Initial ayanamsha at t0.
     * @param callback Optional callback called with undefined as parameter.
     * @returns Always undefined.
     */
    function swe_set_sid_mode(
        sid_mode: number,
        t0: number,
        ayan_t0: number,
        callback?: ResultCallback<typeof swe_set_sid_mode>
    ): undefined;

    /**
     * Returns the ayanamsha for a date in Ephemeris Time.
     * @param tjd_et The Julian day in Ephemeris Time.
     * @param callback Optional callback called with the result.
     * @returns The ayanamsha for the given date.
     * @see {@link swe_get_ayanamsa_ex} for a newer and better implementation.
     */
    function swe_get_ayanamsa(tjd_et: number, callback?: ResultCallback<typeof swe_get_ayanamsa>): number;

    /**
     * Returns the ayanamsha for a date in Universal Time.
     * @param tjd_ut The Julian day in Universal Time.
     * @param callback Optional callback called with the result.
     * @returns The ayanamsha for the given date.
     * @see {@link swe_get_ayanamsa_ex_ut} for a newer and better implementation.
     */
    function swe_get_ayanamsa_ut(tjd_ut: number, callback?: ResultCallback<typeof swe_get_ayanamsa_ut>): number;

    /**
     * Returns the ayanamsha for a date in Ephemeris Time.
     * @param tjd_et The Julian day in Ephemeris Time.
     * @param iflag Ephemeris flag (one of SEFLG_SWIEPH, SEFLG_JPLEPH, SEFLG_MOSEPH).
     * @param callback Optional callback called with the result.
     * @returns The ayanamsha for the given date or an error.
     */
    function swe_get_ayanamsa_ex(
        tjd_et: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_get_ayanamsa_ex>
    ):
        | {
              ayanamsa: number;
          }
        | { error: string };

    /**
     * Returns the ayanamsha for a date in Universal Time.
     * @param tjd_ut The Julian day in Universal Time.
     * @param iflag Ephemeris flag (one of SEFLG_SWIEPH, SEFLG_JPLEPH, SEFLG_MOSEPH).
     * @param callback Optional callback called with the result.
     * @returns The ayanamsha for the given date or an error.
     */
    function swe_get_ayanamsa_ex_ut(
        tjd_ut: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_get_ayanamsa_ex_ut>
    ):
        | {
              ayanamsa: number;
          }
        | { error: string };

    /**
     * Returns the name of an ayanamsha.
     * @param isidmode The sidereal mode.
     * @param callback Optional callback called with the result.
     * @returns The name of the ayanamsha.
     */
    function swe_get_ayanamsa_name(isidmode: number, callback?: ResultCallback<typeof swe_get_ayanamsa_name>): string;

    /**
     * Computes the position of planetary nodes and aspides for a specified Terrestrial Time.
     * @param tjd_et The Julian day in Terrestrial Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param method The method used for the compuation. (SE_NODBIT_... constants)
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_nod_aps(
        tjd_et: number,
        ipl: number,
        iflag: number,
        method: number,
        callback?: ResultCallback<typeof swe_nod_aps>
    ):
        | {
              ascending: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
              descending: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
              perihelion: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
              aphelion: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
          }
        | {
              ascending: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
              descending: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
              perihelion: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
              aphelion: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
          }
        | {
              ascending: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
              descending: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
              perihelion: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
              aphelion: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
          }
        | {
              error: string;
          };

    /**
     * Computes the position of planetary nodes and aspides for a specified Universal Time.
     * @param tjd_ut The Julian day in Universal Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param method The method used for the compuation. (SE_NODBIT_... constants)
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_nod_aps_ut(
        tjd_ut: number,
        ipl: number,
        iflag: number,
        method: number,
        callback?: ResultCallback<typeof swe_nod_aps_ut>
    ):
        | {
              ascending: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
              descending: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
              perihelion: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
              aphelion: {
                  longitude: number;
                  latitude: number;
                  distance: number;
                  longitudeSpeed: number;
                  latitudeSpeed: number;
                  distanceSpeed: number;
              };
          }
        | {
              ascending: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
              descending: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
              perihelion: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
              aphelion: {
                  rectAscension: number;
                  declination: number;
                  distance: number;
                  rectAscensionSpeed: number;
                  declinationSpeed: number;
                  distanceSpeed: number;
              };
          }
        | {
              ascending: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
              descending: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
              perihelion: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
              aphelion: {
                  x: number;
                  y: number;
                  z: number;
                  dx: number;
                  dy: number;
                  dz: number;
              };
          }
        | {
              error: string;
          };

    /**
     * Computes Kepler orbital elements of a planet or asteroid.
     * @param tjd_et The Julian day in Terrestrial Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_get_orbital_elements(
        tjd_et: number,
        ipl: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_get_orbital_elements>
    ):
        | {
              aphelionDistance: number;
              ascendingNode: number;
              eccentricAnomaly: number;
              eccentricity: number;
              inclination: number;
              meanAnomaly: number;
              meanDailyMotion: number;
              meanLongitude: number;
              periapsis: number;
              periapsisArg: number;
              perihelionDistance: number;
              perihelionPassage: number;
              semimajorAxis: number;
              siderealPeriod: number;
              synodicPeriod: number;
              tropicalPeriod: number;
              trueAnomaly: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the maximum, minimum and current distance of a planet or asteroid.
     * @param tjd_et The Julian day in Terrestrial Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_orbit_max_min_true_distance(
        tjd_et: number,
        ipl: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_orbit_max_min_true_distance>
    ):
        | {
              maxDistance: number;
              minDistance: number;
              trueDistance: number;
              rflag: number;
          }
        | {
              error: string;
          };
    // #endregion Pos

    // #region Hel
    /**
     * Computes the Julian day of the next heliacal phenomenon after a given start date.
     * It works between geographic latitudes 60s – 60n.
     * @param tjdstart_ut The Julian day number of start date for the search of the heliacal event.
     * @param geopos The geographic position: [0] = longitude, [1] = latitude, [2] = altitude (eye height) in meters
     * @param datm The atmospheric conditions: [0] = pressure in mbar (hPa), [1] = temperature in degrees Celsius,
     *             [2] = relative humidity in %, [3] = meteorological range (km) or total atmospheric coefficient (ktot)
     * @param dobs The observer description: [0] = age of observer in years, [1] = Snellen ratio of observers eyes,
     *             [2] = 0 = monocular, 1 = binocular, [3] = telescope magnification,
     *             [4] = optical aperture (telescope diameter) in mm, [5] = optical transmission
     * @param ObjectName The name string of fixed star or planet.
     * @param TypeEvent The event type.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_heliacal_ut(
        tjdstart_ut: number,
        geopos: [number, number, number],
        datm: [number, number, number, number],
        dobs: [number, number, number, number, number, number],
        ObjectName: string,
        TypeEvent: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_heliacal_ut>
    ):
        | {
              startVisible: number;
              bestVisible: number;
              endVisible: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Computes data that is relevant for the calculation of heliacal risings and settings.
     * @param tjd_ut The Julian day number of the event.
     * @param geopos The geographic position: [0] = longitude, [1] = latitude, [2] = altitude (eye height) in meters
     * @param datm The atmospheric conditions: [0] = pressure in mbar (hPa), [1] = temperature in degrees Celsius,
     *             [2] = relative humidity in %, [3] = meteorological range (km) or total atmospheric coefficient (ktot)
     * @param dobs The observer description: [0] = age of observer in years, [1] = Snellen ratio of observers eyes,
     *             [2] = 0 = monocular, 1 = binocular, [3] = telescope magnification,
     *             [4] = optical aperture (telescope diameter) in mm, [5] = optical transmission
     * @param ObjectName The name string of fixed star or planet.
     * @param TypeEvent The event type.
     * @param helflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_heliacal_pheno_ut(
        tjd_ut: number,
        geopos: [number, number, number],
        datm: [number, number, number, number],
        dobs: [number, number, number, number, number, number],
        ObjectName: string,
        TypeEvent: number,
        helflag: number,
        callback?: ResultCallback<typeof swe_heliacal_pheno_ut>
    ):
        | {
              tcAltitude: number;
              tcApparentAltitude: number;
              gcAltitude: number;
              azimuth: number;
              tcSunAltitude: number;
              sunAzimuth: number;
              tcActualVisibleArc: number;
              gcActualVisibleArc: number;
              objectToSunAzimuth: number;
              objectToSunLongitude: number;
              extinction: number;
              tcMinVisibleArc: number;
              firstVisible: number;
              bestVisible: number;
              endVisible: number;
              yallopBestVisible: number;
              moonCresentWidth: number;
              yallopValue: number;
              yallopCriterion: number;
              parallax: number;
              magnitude: number;
              rise: number;
              riseSet: number;
              riseObjectToSun: number;
              visibleDuration: number;
              moonCresetLength: number;
              elong: number;
              illumination: number;
              kOZ: number;
              ka: number;
              ksumm: number;
              rflag: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the limiting visual magnitude in dark skies for heliacal phenomenon.
     * @param tjdut The Julian day number of the event.
     * @param geopos The geographic position: [0] = longitude, [1] = latitude, [2] = altitude (eye height) in meters
     * @param datm The atmospheric conditions: [0] = pressure in mbar (hPa), [1] = temperature in degrees Celsius,
     *             [2] = relative humidity in %, [3] = meteorological range (km) or total atmospheric coefficient (ktot)
     * @param dobs The observer description: [0] = age of observer in years, [1] = Snellen ratio of observers eyes,
     *             [2] = 0 = monocular, 1 = binocular, [3] = telescope magnification,
     *             [4] = optical aperture (telescope diameter) in mm, [5] = optical transmission
     * @param ObjectName The name string of fixed star or planet.
     * @param helflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_vis_limit_mag(
        tjdut: number,
        geopos: [number, number, number],
        datm: [number, number, number, number],
        dobs: [number, number, number, number, number, number],
        ObjectName: string,
        helflag: number,
        callback?: ResultCallback<typeof swe_vis_limit_mag>
    ):
        | {
              vissualMagnitudeLimit: number;
              AltO: number;
              AziO: number;
              AltS: number;
              AziS: number;
              AltM: number;
              AziM: number;
              rflag: number;
          }
        | {
              error: string;
          };
    // #endregion Hel

    // #region House
    /**
     * Calculates houses for a given date and geographic position.
     * @param tjd_ut The Julian day in Universal Time.
     * @param geolat The geographic latitude.
     * @param geolon The geographic longitude.
     * @param hsys A letter defining the house method used for the calculation.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_houses(
        tjd_ut: number,
        geolat: number,
        geolon: number,
        hsys: string,
        callback?: ResultCallback<typeof swe_houses>
    ):
        | {
              house: number[];
              ascendant: number;
              mc: number;
              armc: number;
              vertex: number;
              equatorialAscendant: number;
              kochCoAscendant: number;
              munkaseyCoAscendant: number;
              munkaseyPolarAscendant: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates houses and tropical or sidereal positions for a given date and geographic position.
     * @param tjd_ut The Julian day in Universal Time.
     * @param iflag 0 or SEFLG_SIDEREAL or SEFLG_RADIANS.
     * @param geolat The geographic latitude.
     * @param geolon The geographic longitude.
     * @param hsys A letter defining the house method used for the calculation.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_houses_ex(
        tjd_ut: number,
        iflag: number,
        geolat: number,
        geolon: number,
        hsys: string,
        callback?: ResultCallback<typeof swe_houses_ex>
    ):
        | {
              house: number[];
              ascendant: number;
              mc: number;
              armc: number;
              vertex: number;
              equatorialAscendant: number;
              kochCoAscendant: number;
              munkaseyCoAscendant: number;
              munkaseyPolarAscendant: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates houses and tropical or sidereal positions for a given date and geographic position.
     * This function also returns the speeds (daily motions) of the ascendant, midheaven and house cusps.
     * @param tjd_ut The Julian day in Universal Time.
     * @param iflag 0 or SEFLG_SIDEREAL or SEFLG_RADIANS or SEFLG_NONUT.
     * @param geolat The geographic latitude.
     * @param geolon The geographic longitude.
     * @param hsys A letter defining the house method used for the calculation.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_houses_ex2(
        tjd_ut: number,
        iflag: number,
        geolat: number,
        geolon: number,
        hsys: string,
        callback?: ResultCallback<typeof swe_houses_ex2>
    ):
        | {
              house: number[];
              ascendant: number;
              mc: number;
              armc: number;
              vertex: number;
              equatorialAscendant: number;
              kochCoAscendant: number;
              munkaseyCoAscendant: number;
              munkaseyPolarAscendant: number;
              houseSpeed: number[];
              ascendantSpeed: number;
              mcSpeed: number;
              armcSpeed: number;
              vertexSpeed: number;
              equatorialAscendantSpeed: number;
              kochCoAscendantSpeed: number;
              munkaseyCoAscendantSpeed: number;
              munkaseyPolarAscendantSpeed: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates houses from a given ARMC (e.g. from a composite horoscope) when the date is not known.
     * @param armc The Ascensio Recta Medii Coeli value.
     * @param geolat The geographic latitude.
     * @param eps The ecliptic obliquity, in degrees.
     * @param hsys A letter defining the house method used for the calculation.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_houses_armc(
        armc: number,
        geolat: number,
        eps: number,
        hsys: string,
        callback?: ResultCallback<typeof swe_houses_armc>
    ):
        | {
              house: number[];
              ascendant: number;
              mc: number;
              armc: number;
              vertex: number;
              equatorialAscendant: number;
              kochCoAscendant: number;
              munkaseyCoAscendant: number;
              munkaseyPolarAscendant: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates houses from a given ARMC (e.g. from a composite horoscope) when the date is not known.
     * This function also returns the speeds (daily motions) of the ascendant, midheaven and house cusps.
     * @param armc The Ascensio Recta Medii Coeli value.
     * @param geolat The geographic latitude.
     * @param eps The ecliptic obliquity, in degrees.
     * @param hsys A letter defining the house method used for the calculation.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_houses_armc_ex2(
        armc: number,
        geolat: number,
        eps: number,
        hsys: string,
        callback?: ResultCallback<typeof swe_houses_armc_ex2>
    ):
        | {
              house: number[];
              ascendant: number;
              mc: number;
              armc: number;
              vertex: number;
              equatorialAscendant: number;
              kochCoAscendant: number;
              munkaseyCoAscendant: number;
              munkaseyPolarAscendant: number;
              houseSpeed: number[];
              ascendantSpeed: number;
              mcSpeed: number;
              armcSpeed: number;
              vertexSpeed: number;
              equatorialAscendantSpeed: number;
              kochCoAscendantSpeed: number;
              munkaseyCoAscendantSpeed: number;
              munkaseyPolarAscendantSpeed: number;
          }
        | {
              error: string;
              message: string;
          };

    /**
     * Computes the house position of a given body for a given ARMC.
     * @param armc The Ascensio Recta Medii Coeli value.
     * @param geolat The geographic latitude.
     * @param eps The ecliptic obliquity, in degrees.
     * @param hsys A letter defining the house method used for the calculation.
     * @param lon The ecliptic longitude of the planet, in degrees.
     * @param lat The ecliptic latitude of the planet, in degrees.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_houses_pos(
        armc: number,
        geolat: number,
        eps: number,
        hsys: string,
        lon: number,
        lat: number,
        callback?: ResultCallback<typeof swe_houses_pos>
    ):
        | {
              housePosition: number;
          }
        | {
              error: string;
          };
    // #endregion House

    // #region Eclipse
    /**
     * Calculates the Gauquelin sector position of a planet.
     * @param t_ut The Julian day in Universal Time.
     * @param ipl The planet number, if planet, or moon. This value is ignored if the parameter "starname" is set.
     * @param starname The star name, if star.
     * @param iflag Flag for ephemeris and SEFLG_TOPOCTR.
     * @param imeth The calculation method used. Possible values: 0 to 5.
     * @param longitude The geographic longitude.
     * @param latitude The geographic latitude.
     * @param height The height of the observer.
     * @param atpress The atmospheric pressure. Only useful with imeth = 3.
     * @param attemp The atmospheric temperature in degrees Celsius. Only useful with imeth = 3.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_gauquelin_sector(
        t_ut: number,
        ipl: number,
        starname: string,
        iflag: number,
        imeth: number,
        longitude: number,
        latitude: number,
        height: number,
        atpress: number,
        attemp: number,
        callback?: ResultCallback<typeof swe_gauquelin_sector>
    ):
        | {
              name: string;
              gauquelinSector: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the geographic position where an eclipse is central or maximal.
     * @param tjd_ut The Julian day in Universal Time.
     * @param ifl The ephemeris flag.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_sol_eclipse_where(
        tjd_ut: number,
        ifl: number,
        callback?: ResultCallback<typeof swe_sol_eclipse_where>
    ):
        | {
              rflag: number;
              longitude: number;
              latitude: number;
              solarDiameterFraction: number;
              lonarToSolarDiameterRatio: number;
              solarDiscFraction: number;
              coreShadow: number;
              azimuth: number;
              trueAltitude: number;
              apparentAltitude: number;
              moonToSunAngularDistance: number;
              eclipseMagnitude: number;
              sarosNumber: number;
              sarosMember: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the geographic position, where, for a given time, a central eclipse is central or
     * where a non-central eclipse is maximal.
     * @param tjd_ut The Julian day in Universal Time.
     * @param ipl The planet number.
     * @param starname The star name. Must be null or "" if not a star.
     * @param ifl The ephemeris flag.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_lun_occult_where(
        tjd_ut: number,
        ipl: number,
        starname: string,
        ifl: number,
        callback?: ResultCallback<typeof swe_lun_occult_where>
    ):
        | {
              rflag: number;
              longitude: number;
              latitude: number;
              solarDiameterFraction: number;
              lonarToSolarDiameterRatio: number;
              solarDiscFraction: number;
              coreShadow: number;
              azimuth: number;
              trueAltitude: number;
              apparentAltitude: number;
              moonToSunAngularDistance: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the solar eclipse attributes for a given geographic position and time.
     * @param tjd_ut The Julian day in Universal Time.
     * @param ifl The ephemeris flag.
     * @param longitude The geographic longitude.
     * @param latitude The geographic latitude.
     * @param height The height above sea.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_sol_eclipse_how(
        tjd_ut: number,
        ifl: number,
        longitude: number,
        latitude: number,
        height: number,
        callback?: ResultCallback<typeof swe_sol_eclipse_how>
    ):
        | {
              rflag: number;
              solarDiameterFraction: number;
              lonarToSolarDiameterRatio: number;
              solarDiscFraction: number;
              coreShadow: number;
              azimuth: number;
              trueAltitude: number;
              apparentAltitude: number;
              moonToSunAngularDistance: number;
              eclipseMagnitude: number;
              sarosNumber: number;
              sarosMember: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the next solar eclipse for a given geographic position.
     * @param tjd_start The start date to search from. A Julian day in Universal Time.
     * @param ifl The ephemeris flag.
     * @param longitude The geographic longitude.
     * @param latitude The geographic latitude.
     * @param height The height above sea.
     * @param backward 1 for backward search, 0 otherwise.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_sol_eclipse_when_loc(
        tjd_start: number,
        ifl: number,
        longitude: number,
        latitude: number,
        height: number,
        backward: 0 | 1,
        callback?: ResultCallback<typeof swe_sol_eclipse_when_loc>
    ):
        | {
              rflag: number;
              maximum: number;
              first: number;
              second: number;
              third: number;
              forth: number;
              solarDiameterFraction: number;
              lonarToSolarDiameterRatio: number;
              solarDiscFraction: number;
              coreShadow: number;
              azimuth: number;
              trueAltitude: number;
              apparentAltitude: number;
              moonToSunAngularDistance: number;
              eclipseMagnitude: number;
              sarosNumber: number;
              sarosMember: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the next occultation of a planet or star by the moon for a given location.
     * @param tjd_start The start date to search from. A Julian day in Universal Time.
     * @param ipl The planet number of the occulted body.
     * @param starname The name of the occulted star. Must be null or "" if a planetary occultation is calculated.
     * @param ifl The ephemeris flag.
     * @param longitude The geographic longitude.
     * @param latitude The geographic latitude.
     * @param height The height above sea.
     * @param backward 1 for backward search, 0 otherwise.
     *                 Set flag SE_ECL_ONE_TRY to prevent infinite loops for impossible events.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_lun_occult_when_loc(
        tjd_start: number,
        ipl: number,
        starname: string,
        ifl: number,
        longitude: number,
        latitude: number,
        height: number,
        backward: number,
        callback?: ResultCallback<typeof swe_lun_occult_when_loc>
    ):
        | {
              rflag: number;
              name: string;
              maximum: number;
              first: number;
              second: number;
              third: number;
              forth: number;
              solarDiameterFraction: number;
              lonarToSolarDiameterRatio: number;
              solarDiscFraction: number;
              coreShadow: number;
              azimuth: number;
              trueAltitude: number;
              apparentAltitude: number;
              moonToSunAngularDistance: number;
              eclipseMagnitude: number;
              sarosNumber: number;
              sarosMember: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the next solar eclipse globally.
     * @param tjd_start The start date to search from. A Julian day in Universal Time.
     * @param ifl The ephemeris flag.
     * @param ifltype Flags for the wanted eclipse type. (e.g. SE_ECL_TOTAL)
     * @param backward 1 for backward search, 0 otherwise.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_sol_eclipse_when_glob(
        tjd_start: number,
        ifl: number,
        ifltype: number,
        backward: 0 | 1,
        callback?: ResultCallback<typeof swe_sol_eclipse_when_glob>
    ):
        | {
              rflag: number;
              maximum: number;
              noon: number;
              begin: number;
              end: number;
              totalBegin: number;
              totalEnd: number;
              centerBegin: number;
              centerEnd: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the next occultation of a planet or star by the moon globally.
     * @param tjd_start The start date to search from. A Julian day in Universal Time.
     * @param ipl The planet number of the occulted body.
     * @param starname The name of the occulted star. Must be null or "" if a planetary occultation is calculated.
     * @param ifl The ephemeris flag.
     * @param ifltype Flags for the wanted eclipse type. (e.g. SE_ECL_TOTAL)
     * @param backward 1 for backward search, 0 otherwise.
     *                 Set flag SE_ECL_ONE_TRY to prevent infinite loops for impossible events.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_lun_occult_when_glob(
        tjd_start: number,
        ipl: number,
        starname: string,
        ifl: number,
        ifltype: number,
        backward: number,
        callback?: ResultCallback<typeof swe_lun_occult_when_glob>
    ):
        | {
              rflag: number;
              name: string;
              maximum: number;
              noon: number;
              begin: number;
              end: number;
              totalBegin: number;
              totalEnd: number;
              centerBegin: number;
              centerEnd: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the attributes of a lunar eclipse for a given time.
     * @param tjd_ut The Julian day in Universal Time.
     * @param ifl The ephemeris flag.
     * @param longitude The geographic longitude.
     * @param latitude The geographic latitude.
     * @param height The height above sea.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_lun_eclipse_how(
        tjd_ut: number,
        ifl: number,
        longitude: number,
        latitude: number,
        height: number,
        callback?: ResultCallback<typeof swe_lun_eclipse_how>
    ):
        | {
              rflag: number;
              umbralMagnitude: number;
              penumbralMagnitude: number;
              azimuth: number;
              trueAltitude: number;
              apparentAltitude: number;
              oppositeDegreeDistance: number;
              magnitude: number;
              sarosNumber: number;
              sarosMember: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the next lunar eclipse globally.
     * @param tjd_start The start date to search from. A Julian day in Universal Time.
     * @param ifl The ephemeris flag.
     * @param ifltype Flags for the wanted eclipse type. (e.g. SE_ECL_TOTAL)
     * @param backward 1 for backward search, 0 otherwise.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_lun_eclipse_when(
        tjd_start: number,
        ifl: number,
        ifltype: number,
        backward: 0 | 1,
        callback?: ResultCallback<typeof swe_lun_eclipse_when>
    ):
        | {
              rflag: number;
              maximum: number;
              partialBegin: number;
              partialEnd: number;
              totalBegin: number;
              totalEnd: number;
              penumbralBegin: number;
              penumbralEnd: number;
          }
        | {
              error: string;
          };

    /**
     * Calculates the next lunar eclipse observable from a given location.
     * @param tjd_start The start date to search from. A Julian day in Universal Time.
     * @param ifl The ephemeris flag.
     * @param longitude The geographic longitude.
     * @param latitude The geographic latitude.
     * @param height The height above sea.
     * @param backward 1 for backward search, 0 otherwise.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_lun_eclipse_when_loc(
        tjd_start: number,
        ifl: number,
        longitude: number,
        latitude: number,
        height: number,
        backward: 0 | 1,
        callback?: ResultCallback<typeof swe_lun_eclipse_when_loc>
    ):
        | {
              rflag: number;
              maximum: number;
              partialBegin: number;
              partialEnd: number;
              totalBegin: number;
              totalEnd: number;
              penumbralBegin: number;
              penumbralEnd: number;
              moonRise: number;
              moonSet: number;
              umbralMagnitude: number;
              penumbralMagnitude: number;
              azimuth: number;
              trueAltitude: number;
              apparentAltitude: number;
              moonDistanceFromOpposition: number;
              sarosNumber: number;
              sarosMember: number;
          }
        | {
              error: string;
          };

    /**
     * Computes data for planetary phenomena at a specified Terrestrial Time.
     * @param tjd The Julian day in Terrestrial Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_pheno(
        tjd: number,
        ipl: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_pheno>
    ):
        | {
              rflag: number;
              phaseAngle: number;
              phase: number;
              elongation: number;
              apparentDiameter: number;
              apparentMagnitude: number;
          }
        | {
              error: string;
          };

    /**
     * Computes data for planetary phenomena at a specified Universal Time.
     * @param tjd_ut The Julian day in Universal Time.
     * @param ipl The body number.
     * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_pheno_ut(
        tjd_ut: number,
        ipl: number,
        iflag: number,
        callback?: ResultCallback<typeof swe_pheno_ut>
    ):
        | {
              rflag: number;
              phaseAngle: number;
              phase: number;
              elongation: number;
              apparentDiameter: number;
              apparentMagnitude: number;
          }
        | {
              error: string;
          };

    /**
     * Converts true to apparent altitude and vice versa.
     * @param inalt The altitude value to convert.
     * @param atpress The atmospheric pressure in mbar (hPa).
     * @param attemp The atmospheric temperature in degrees Celsius.
     * @param calc_flag Either SE_TRUE_TO_APP or SE_APP_TO_TRUE.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_refrac(
        inalt: number,
        atpress: number,
        attemp: number,
        calc_flag: typeof SE_TRUE_TO_APP | typeof SE_APP_TO_TRUE,
        callback?: ResultCallback<typeof swe_refrac>
    ): {
        refraction: number;
    };

    /**
     * Converts true to apparent altitude and vice versa, supporting negative apparent heights.
     * @param inalt The altitude of object above geometric horizon in degrees,
     *              where geometric horizon = plane perpendicular to gravity.
     * @param geoalt The altitude of observer above sea level in meters.
     * @param atpress The atmospheric pressure in mbar (hPa).
     * @param attemp The atmospheric temperature in degrees Celsius.
     * @param lapse_rate The (dattemp/dgeoalt) value in °K/m.
     * @param calc_flag Either SE_TRUE_TO_APP or SE_APP_TO_TRUE.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_refrac_extended(
        inalt: number,
        geoalt: number,
        atpress: number,
        attemp: number,
        lapse_rate: number,
        calc_flag: typeof SE_TRUE_TO_APP | typeof SE_APP_TO_TRUE,
        callback?: ResultCallback<typeof swe_refrac_extended>
    ): {
        refraction: number;
        trueAltitude: number;
        apparentAltitude: number;
        horizonDip: number;
    };

    /**
     * Sets the lapse rate value.
     * @param lapse_rate The new lapse rate value.
     * @param callback Optional callback called with an empty object.
     * @returns An empty object.
     */
    function swe_set_lapse_rate(lapse_rate: number, callback?: ResultCallback<typeof swe_set_lapse_rate>): {};

    /**
     * Computes the horizontal coordinates (azimuth and altitude) of a planet or
     * a star from either ecliptical or equatorial coordinates.
     * @param tjd_ut The Julian day in Universal Time.
     * @param calc_flag Either SE_ECL2HOR or SE_EQU2HOR.
     * @param longitude The geographic longitude.
     * @param latitude The geographic latitude.
     * @param height The height above sea.
     * @param atpress The atmospheric pressure in mbar (hPa).
     * @param attemp The atmospheric temperature in degrees Celsius.
     * @param bodyX X coordinate of body in either ecliptical or equatorial coordinates, depending on calc_flag.
     * @param bodyY Y coordinate of body in either ecliptical or equatorial coordinates, depending on calc_flag.
     * @param bodyZ Z coordinate of body in either ecliptical or equatorial coordinates, depending on calc_flag.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_azalt(
        tjd_ut: number,
        calc_flag: typeof SE_ECL2HOR | typeof SE_EQU2HOR,
        longitude: number,
        latitude: number,
        height: number,
        atpress: number,
        attemp: number,
        bodyX: number,
        bodyY: number,
        bodyZ: number,
        callback?: ResultCallback<typeof swe_azalt>
    ): {
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
    };

    /**
     * Computes either ecliptical or equatorial coordinates from azimuth and true altitude.
     * @param tjd_ut The Julian day in Universal Time.
     * @param calc_flag Either SE_HOR2ECL or SE_HOR2EQU.
     * @param longitude The geographic longitude of the observer.
     * @param latitude The geographic latitude of the observer.
     * @param height The height of the observer.
     * @param bodyAzimuth The azimuth of the planet.
     * @param bodyTrueAltitude The true altitude of the planet.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_azalt_rev(
        tjd_ut: number,
        calc_flag: typeof SE_HOR2ECL | typeof SE_HOR2EQU,
        longitude: number,
        latitude: number,
        height: number,
        bodyAzimuth: number,
        bodyTrueAltitude: number,
        callback?: ResultCallback<typeof swe_azalt_rev>
    ): {
        azimuth: number;
        trueAltitude: number;
    };

    /**
     * Computes the times of rising, setting and meridian transits for planets, asteroids, the moon and the fixed stars.
     * @param tjd_ut Search after this Universal Time.
     * @param ipl The planet number, if planet or moon.
     * @param starname The name of the star. Must be null or "" if ipl is used.
     * @param epheflag The ephemeris flag.
     * @param rsmi Integer specifying that rise, set, or one of the two meridian transits is wanted.
     * @param longitude The geographic longitudeof the observer.
     * @param latitude The geographic latitudeof the observer.
     * @param height The height of the observer.
     * @param atpress The atmospheric pressure in mbar (hPa).
     * @param attemp The atmospheric temperature in degrees Celsius.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_rise_trans(
        tjd_ut: number,
        ipl: number,
        starname: string,
        epheflag: number,
        rsmi: number,
        longitude: number,
        latitude: number,
        height: number,
        atpress: number,
        attemp: number,
        callback?: ResultCallback<typeof swe_rise_trans>
    ):
        | {
              name: string;
              transitTime: number;
          }
        | {
              error: string;
          };

    /**
     * Computes the times of rising, setting and meridian transits for planets, asteroids, the moon and the fixed stars
     * relative to the true horizon.
     * @param tjd_ut Search after this Universal Time.
     * @param ipl The planet number, if planet or moon.
     * @param starname The name of the star. Must be null or "" if ipl is used.
     * @param epheflag The ephemeris flag.
     * @param rsmi Integer specifying that rise, set, or one of the two meridian transits is wanted.
     * @param longitude The geographic longitudeof the observer.
     * @param latitude The geographic latitudeof the observer.
     * @param height The height of the observer.
     * @param atpress The atmospheric pressure in mbar (hPa).
     * @param horhgt Height of local horizon in deg at the point where the body rises or sets.
     * @param attemp The atmospheric temperature in degrees Celsius.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_rise_trans_true_hor(
        tjd_ut: number,
        ipl: number,
        starname: string,
        epheflag: number,
        rsmi: number,
        longitude: number,
        latitude: number,
        height: number,
        atpress: number,
        horhgt: number,
        attemp: number,
        callback?: ResultCallback<typeof swe_rise_trans_true_hor>
    ):
        | {
              name: string;
              transitTime: number;
          }
        | {
              error: string;
          };
    // #endregion Eclipse
}

export = swisseph;
