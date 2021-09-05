declare namespace swisseph {
    // #region constants
    const SE_JUL_CAL = 0;
    const SE_GREG_CAL = 1;
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
     * @returns The result of the computation.
     */
    function swe_time_equ(
        tjd: number,
        callback?: (result: ReturnType<typeof swe_time_equ>) => void
    ): {
        timeEquation: number;
        error: string;
    };

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
        callback?: (result: number) => void
    ): number;
    // #endregion date

    // #region pos
    /**
     * Sets application's own ephemeris path.
     * @param path Path to ephemeris data files.
     */
    function swe_set_ephe_path(path: string): void;
    // #endregion pos

    // #region hel
    // #endregion hel

    // #region house
    // #endregion house

    // #region eclipse
    // #endregion eclipse
}

export = swisseph;
