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
    function swe_deltat(tjd: number, callback?: (result: { delta: number }) => void): { delta: number };

    /**
     * Returns the difference between local apparent and local mean time.
     * @param tjd The Julian day.
     * @param callback Optional callback called with the result.
     * @returns The result of the computation.
     */
    function swe_time_equ(
        tjd: number,
        callback?: (result: { timeEquation: number; error: string }) => void
    ): {
        timeEquation: number;
        error: string;
    };
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
