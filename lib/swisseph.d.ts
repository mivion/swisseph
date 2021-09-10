declare namespace swisseph {
    // #region constants
    // Calendar types
    const SE_JUL_CAL = 0;
    const SE_GREG_CAL = 1;

    // Planet numbers
    const SE_ECL_NUT = -1;
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
    const SE_FICT_OFFSET = 40;
    const SE_FICT_OFFSET_1 = 39;
    const SE_FICT_MAX = 999;
    const SE_NFICT_ELEM = 15;
    const SE_COMET_OFFSET = 1000;

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
    const SEFLG_ASTROMETRIC = 1536;
    const SEFLG_EQUATORIAL = 2048;
    const SEFLG_XYZ = 4096;
    const SEFLG_RADIANS = 8192;
    const SEFLG_BARYCTR = 16384;
    const SEFLG_TOPOCTR = 32768;
    const SEFLG_ORBEL_AA = 32768;
    const SEFLG_SIDEREAL = 65536;
    const SEFLG_ICRS = 131072;
    const SEFLG_DPSIDEPS_1980 = 262144;
    const SEFLG_JPLHOR = 262144;
    const SEFLG_JPLHOR_APPROX = 524288;

    // Rounding flags for "swe_split_deg" function
    const SE_SPLIT_DEG_ROUND_SEC = 1;
    const SE_SPLIT_DEG_ROUND_MIN = 2;
    const SE_SPLIT_DEG_ROUND_DEG = 4;
    const SE_SPLIT_DEG_ZODIACAL = 8;
    const SE_SPLIT_DEG_KEEP_SIGN = 16;
    const SE_SPLIT_DEG_KEEP_DEG: 32;
    const SE_SPLIT_DEG_NAKSHATRA = 1024;
    // #endregion constants

    // #region util
    /**
     * Computes the difference between Universal Time (UT, GMT) and Ephemeris time.
     * @param tjd The Julian day.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_deltat(tjd: number, callback?: (result: ReturnType<typeof swe_deltat>) => void): { delta: number };

    /**
     * Returns the difference between local apparent and local mean time.
     * @param tjd The Julian day.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation or an error.
     */
    function swe_time_equ(
        tjd: number,
        callback?: (result: ReturnType<typeof swe_time_equ>) => void
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
        callback?: (result: ReturnType<typeof swe_sidtime0>) => void
    ): {
        siderialTime: number;
    };

    /**
     * Returns sidereal time for a Julian day. Computes obliquity and nutation internally.
     * @param tjd_ut The Julian day.
     * @param callback Optional callback called with the result.
     * @returns Sidereal time at the Greenwich Meridian, measured in hours.
     */
    function swe_sidtime(
        tjd_ut: number,
        callback?: (result: ReturnType<typeof swe_sidtime>) => void
    ): { siderialTime: number };

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
        callback?: (result: ReturnType<typeof swe_cotrans>) => void
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
        callback?: (result: ReturnType<typeof swe_cotrans_sp>) => void
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
    function swe_get_tid_acc(callback?: (result: ReturnType<typeof swe_get_tid_acc>) => void): { acceleration: number };

    /**
     * Sets the tidal acceleration to be used in swe_deltat().
     * @param t_acc The tidal acceleration.
     * @param callback Optional callback called with an empty object.
     * @returns An empty object.
     */
    function swe_set_tid_acc(t_acc: number, callback?: (result: ReturnType<typeof swe_set_tid_acc>) => void): {};

    /**
     * Normalizes a degree to the range 0 - 360.
     * @param x The degree to normalize.
     * @param callback Optional callback called with the result.
     * @returns The result of the normalization.
     */
    function swe_degnorm(x: number, callback?: (result: ReturnType<typeof swe_degnorm>) => void): { x360: number };

    /**
     * Normalizes a radian to the range 0 - 2 PI.
     * @param x The radian to normalize.
     * @param callback Optional callback called with the result.
     * @returns The result of the normalization.
     */
    function swe_radnorm(x: number, callback?: (result: ReturnType<typeof swe_radnorm>) => void): { x2Pi: number };

    /**
     * Return the mid point between two radians.
     * @param x1 The first radian.
     * @param x0 The second radian.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_rad_midp(
        x1: number,
        x0: number,
        callback?: (result: ReturnType<typeof swe_rad_midp>) => void
    ): { xMid2Pi: number };

    /**
     * Return the mid point between two degrees.
     * @param x1 The first degree.
     * @param x0 The second degree.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_deg_midp(
        x1: number,
        x0: number,
        callback?: (result: ReturnType<typeof swe_rad_midp>) => void
    ): { xMid360: number };

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
        callback?: (result: ReturnType<typeof swe_split_deg>) => void
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
    function swe_csnorm(p: number, callback?: (result: ReturnType<typeof swe_csnorm>) => void): { centisec360: number };

    /**
     * Distance in centisecs between p1 and p2 normalized to 0 - 360.
     * @param p1 The first centisecond value
     * @param p2 The second centisecond value
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_difcsn(
        p1: number,
        p2: number,
        callback?: (result: ReturnType<typeof swe_difcsn>) => void
    ): { centisecDiff: number };

    /**
     * Distance in degrees between p1 and p2.
     * @param p1 The first degree value.
     * @param p2 The second degree value.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_difdegn(
        p1: number,
        p2: number,
        callback?: (result: ReturnType<typeof swe_difdegn>) => void
    ): { degreeDiff: number };

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
        callback?: (result: ReturnType<typeof swe_difcs2n>) => void
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
        callback?: (result: ReturnType<typeof swe_difdeg2n>) => void
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
        callback?: (result: ReturnType<typeof swe_difrad2n>) => void
    ): { degreeDistancePi: number };

    /**
     * Round centisecond value, but at 29.5959 always down.
     * @param x The centisecond value to round.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_csroundsec(
        x: number,
        callback?: (result: ReturnType<typeof swe_csroundsec>) => void
    ): { centisecRound: number };

    /**
     * Convert double to long with rounding, no overflow check.
     * @param x The double value to convert.
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_d2l(x: number, callback?: (result: ReturnType<typeof swe_d2l>) => void): { xRound: number };

    /**
     * Returns the day of week for a Julian date.
     * @param jd The Julian date.
     * @param callback Optional callback called with the result.
     * @returns Monday = 0, ... Sunday = 6.
     */
    function swe_day_of_week(
        jd: number,
        callback?: (result: ReturnType<typeof swe_day_of_week>) => void
    ): { dayOfWeek: number };

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
        callback?: (result: ReturnType<typeof swe_cs2timestr>) => void
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
        callback?: (result: ReturnType<typeof swe_cs2lonlatstr>) => void
    ): { lonlatString: string };

    /**
     * Converts a centisecond value to a degree string.
     * @param t The centisecond value.
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_cs2degstr(
        t: number,
        callback?: (result: ReturnType<typeof swe_cs2degstr>) => void
    ): { degreeString: string };
    // #endregion util

    // #region date
    /**
     * Conversion from day, month, year, time to Julian date with error handling.
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
        callback?: (result: ReturnType<typeof swe_date_conversion>) => void
    ): { julianDay: number } | { error: string };

    /**
     * Conversion from day, month, year, time to Julian date.
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
        callback?: (result: ReturnType<typeof swe_julday>) => void
    ): number;

    /**
     * Reverse conversion of a Julian date value to a date object.
     * @param jd The Julian date.
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_revjul(
        jd: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: (result: ReturnType<typeof swe_revjul>) => void
    ): {
        year: number;
        month: number;
        day: number;
        hour: number;
    };

    /**
     * Conversion from day, month, year, time in Coordinated Universal Time (UTC) to Julian date.
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
        callback?: (result: ReturnType<typeof swe_utc_to_jd>) => void
    ):
        | {
              julianDayET: number;
              julianDayUT: number;
          }
        | { error: string };

    /**
     * Reverse conversion of a Julian date value to a date object in Coordinated Universal Time (UTC).
     * @param tjd_et The Julian day number in ET (TT).
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_jdet_to_utc(
        tjd_et: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: (result: ReturnType<typeof swe_jdet_to_utc>) => void
    ): {
        year: number;
        month: number;
        day: number;
        hour: number;
        minute: number;
        second: number;
    };

    /**
     * Reverse conversion of a Julian date value to a date object in Coordinated Universal Time (UTC).
     * @param tjd_ut The Julian day number in UT (UT1).
     * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
     * @param callback Optional callback called with the result.
     * @returns The result of the conversion.
     */
    function swe_jdut1_to_utc(
        tjd_ut: number,
        gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL,
        callback?: (result: ReturnType<typeof swe_jdut1_to_utc>) => void
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
        callback?: (result: ReturnType<typeof swe_utc_time_zone>) => void
    ): {
        year: number;
        month: number;
        day: number;
        hour: number;
        minute: number;
        second: number;
    };
    // #endregion date

    // #region pos
    /**
     * Returns a string with the version number of your Swiss Ephemeris.
     * @param callback Optional callback called with the result.
     * @returns The version number of your Swiss Ephemeris.
     */
    function swe_version(callback?: (result: ReturnType<typeof swe_version>) => void): string;

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
        callback?: (result: ReturnType<typeof swe_calc_ut>) => void
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
        callback?: (result: ReturnType<typeof swe_calc>) => void
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
        callback?: (result: ReturnType<typeof swe_fixstar>) => void
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
        callback?: (result: ReturnType<typeof swe_fixstar_ut>) => void
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
        callback?: (result: ReturnType<typeof swe_fixstar_mag>) => void
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
        callback?: (result: ReturnType<typeof swe_fixstar2>) => void
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
        callback?: (result: ReturnType<typeof swe_fixstar2_ut>) => void
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
        callback?: (result: ReturnType<typeof swe_fixstar2_mag>) => void
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
     */
    function swe_close(): void;

    /**
     * Sets application's own ephemeris path.
     * @param path Path to ephemeris data files.
     */
    function swe_set_ephe_path(path: string): void;

    /**
     * Sets the name of the JPL ephemeris file.
     * @param fname JPL ephemeris filename.
     */
    function swe_set_jpl_file(fname: string): void;

    /**
     * Returns the planetary or asteroid name for a given planet number.
     * @param ipl The planet number.
     * @param callback Optional callback called with the result.
     * @returns The name of the planet or asteroid.
     */
    function swe_get_planet_name(
        ipl: number,
        callback?: (result: ReturnType<typeof swe_get_planet_name>) => void
    ): {
        name: string;
    };
    // #endregion pos

    // #region hel
    // #endregion hel

    // #region house
    // #endregion house

    // #region eclipse
    // #endregion eclipse
}

export = swisseph;
