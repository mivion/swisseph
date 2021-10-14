#ifndef __swisseph_date_h__
#define __swisseph_date_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * int swe_date_conversion(int y , int m , int d , double utime, char gregflag, double *tjd)
 * =>
 * swe_date_conversion(int year, int month, int day, double hour, int gregflag[, function callback (result)]) = {
 *   julianDay: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_date_conversion);

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * swe_julday(int year, int month, int day, double hour, int gregflag[, function callback (result)]) = double
 */
NAN_METHOD(node_swe_julday);

/**
 * void swe_revjul (double jd, int gregflag, int *jyear, int *jmon, int *jday, double *jut)
 * =>
 * swe_revjul (double jd, int gregflag[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: double
 * }
 */
NAN_METHOD(node_swe_revjul);

/**
 * int32 swe_utc_to_jd(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, int32 gregflag, double *dret, char *serr)
 * =>
 * swe_utc_to_jd(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, int32 gregflag[, function callback (result)]) = {
 *   julianDayET: double,
 *   julianDayUT: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_utc_to_jd);

/**
 * void swe_jdet_to_utc(double tjd_et, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * swe_jdet_to_utc(double tjd_et, int32 gregflag[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   minute: int,
 *   second: double
 * }
 */
NAN_METHOD(node_swe_jdet_to_utc);

/**
 * void swe_jdut1_to_utc(double tjd_ut, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * swe_jdut1_to_utc(double tjd_ut, int32 gregflag[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   minute: int,
 *   second: double
 * }
 */
NAN_METHOD(node_swe_jdut1_to_utc);

/**
 * void swe_utc_time_zone(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, double d_timezone, int32 *iyear_out, int32 *imonth_out, int32 *iday_out, int32 *ihour_out, int32 *imin_out, double *dsec_out)
 * =>
 * swe_utc_time_zone(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, double d_timezone[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   minute: int,
 *   second: double
 * }
 */
NAN_METHOD(node_swe_utc_time_zone);

#endif // __swisseph_date_h__
