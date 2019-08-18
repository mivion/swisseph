#ifndef __swisseph_util_h__
#define __swisseph_util_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * double swe_deltat(double tjd)
 * =>
 * swe_deltat(double tjd[, function callback (result)]) = {
 *   delta: double
 * }
 */
NAN_METHOD(node_swe_deltat);

/**
 * int swe_time_equ(double tjd, double *te, char *serr)
 * =>
 * swe_time_equ(double tjd[, function callback (result)]) = {
 *   timeEquation: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_time_equ);

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 * =>
 * swe_sidtime0(double tjd_ut, double eps, double nut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
NAN_METHOD(node_swe_sidtime0);

/**
 * double swe_sidtime(double tjd_ut)
 * =>
 * swe_sidtime(double tjd_ut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
NAN_METHOD(node_swe_sidtime);

/**
 * void swe_cotrans(double *xpo, double *xpn, double eps)
 * =>
 * swe_cotrans(double xpo [3], double eps[, function callback (result)]) = {
 *   longitude: double, // xpn [0]
 *   latitude: double,  // xpn [1]
 *   distance: double   // xpn [2]
 * }
 */
NAN_METHOD(node_swe_cotrans);

/**
 * void swe_cotrans_sp(double *xpo, double *xpn, double eps)
 * =>
 * swe_cotrans_sp(double *xpo, double eps[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double
 * }
 */
NAN_METHOD(node_swe_cotrans_sp);

/**
 * double swe_get_tid_acc(void)
 * =>
 * swe_get_tid_acc(void[, function callback (result)]) = {
 *   acceleration: double
 * }
 */
NAN_METHOD(node_swe_get_tid_acc);

/**
 * void swe_set_tid_acc(double t_acc)
 * =>
 * swe_set_tid_acc(double t_acc[, function callback (result)]) = {
 * }
 */
NAN_METHOD(node_swe_set_tid_acc);

/**
 * double swe_degnorm(double x)
 * =>
 * swe_degnorm(double x[, function callback (result)]) = {
 *   x360: double
 * }
 */
NAN_METHOD(node_swe_degnorm);

/**
 * double swe_radnorm(double x)
 * =>
 * swe_radnorm(double x[, function callback (result)]) = {
 *   x2Pi: double
 * }
 */
NAN_METHOD(node_swe_radnorm);

/**
 * double swe_rad_midp(double x1, double x0)
 * =>
 * swe_rad_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid2Pi: double
 * }
 */
NAN_METHOD(node_swe_rad_midp);

/**
 * double swe_deg_midp(double x1, double x0)
 * =>
 * swe_deg_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid360: double
 * }
 */
NAN_METHOD(node_swe_deg_midp);

/**
 * void swe_split_deg(double ddeg, int32 roundflag, int32 *ideg, int32 *imin, int32 *isec, double *dsecfr, int32 *isgn)
 * =>
 * swe_split_deg(double ddeg, int32 roundflag[, function callback (result)]) = {
 *   degree: int,
 *   min: int,
 *   second: int,
 *   secondFraction: double,
 *   sign: int
 * }
 */
NAN_METHOD(node_swe_split_deg);

/**
 * centisec swe_csnorm(centisec p)
 * =>
 * swe_csnorm(centisec p[, function callback (result)]) = {
 *   centisec360: double
 * }
 */
NAN_METHOD(node_swe_csnorm);

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 * =>
 * swe_difcsn (centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDiff: double
 * }
 */
NAN_METHOD(node_swe_difcsn );

/**
 * double swe_difdegn (double p1, double p2)
 * =>
 * swe_difdegn (double p1, double p2[, function callback (result)]) = {
 *   degreeDiff: double
 * }
 */
NAN_METHOD(node_swe_difdegn );

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 * =>
 * swe_difcs2n(centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDistance180: double
 * }
 */
NAN_METHOD(node_swe_difcs2n);

/**
 * double swe_difdeg2n(double p1, double p2)
 * =>
 * swe_difdeg2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistance180: double
 * }
 */
NAN_METHOD(node_swe_difdeg2n);

/**
 * double swe_difrad2n(double p1, double p2)
 * =>
 * swe_difrad2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistancePi: double
 * }
 */
NAN_METHOD(node_swe_difrad2n);

/**
 * centisec swe_csroundsec(centisec x)
 * =>
 * swe_csroundsec(centisec x[, function callback (result)]) = {
 *   centisecRound: double
 * }
 */
NAN_METHOD(node_swe_csroundsec);

/**
 * int32 swe_d2l(double x)
 * =>
 * swe_d2l(double x[, function callback (result)]) = {
 *   xRound: int
 * }
 */
NAN_METHOD(node_swe_d2l);

/**
 * int swe_day_of_week(double jd)
 * =>
 * swe_day_of_week(double jd[, function callback (result)]) = {
 *   dayOfWeek: int
 * }
 */
NAN_METHOD(node_swe_day_of_week);

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a)
 * =>
 * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero[, function callback (result)]) = {
 *   timeString: string
 * }
 */
NAN_METHOD(node_swe_cs2timestr);

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s)
 * =>
 * swe_cs2lonlatstr(CSEC t, char pchar, char mchar[, function callback (result)]) = {
 *   lonlatString: string
 * }
 */
NAN_METHOD(node_swe_cs2lonlatstr);

/**
 * char * swe_cs2degstr(CSEC t, char *a)
 * =>
 * swe_cs2degstr(CSEC t[, function callback (result)]) = {
 *   degreeString: string
 * }
 */
NAN_METHOD(node_swe_cs2degstr);

#endif // __swisseph_util_h__
