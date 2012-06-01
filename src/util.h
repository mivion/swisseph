#ifndef __swisseph_util_h__
#define __swisseph_util_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * double swe_deltat(double tjd)
 */
Handle <Value> node_swe_deltat (const Arguments & args);

/**
 * int swe_time_equ(double tjd, double *te, char *serr)
 */
Handle <Value> node_swe_time_equ (const Arguments & args);

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 */
Handle <Value> node_swe_sidtime0 (const Arguments & args);

/**
 * double swe_sidtime(double tjd_ut)
 */
Handle <Value> node_swe_sidtime (const Arguments & args);

/**
 * void swe_cotrans(double *xpo, double *xpn, double eps)
 */
Handle <Value> node_swe_cotrans (const Arguments & args);

/**
 * void swe_cotrans_sp(double *xpo, double *xpn, double eps)
 */
Handle <Value> node_swe_cotrans_sp (const Arguments & args);

/**
 * double swe_get_tid_acc(void)
 */
Handle <Value> node_swe_get_tid_acc (const Arguments & args);

/**
 * void swe_set_tid_acc(double t_acc)
 */
Handle <Value> node_swe_set_tid_acc (const Arguments & args);

/**
 * double swe_degnorm(double x)
 */
Handle <Value> node_swe_degnorm (const Arguments & args);

/**
 * double swe_radnorm(double x)
 */
Handle <Value> node_swe_radnorm (const Arguments & args);

/**
 * double swe_rad_midp(double x1, double x0)
 */
Handle <Value> node_swe_rad_midp (const Arguments & args);

/**
 * double swe_deg_midp(double x1, double x0)
 */
Handle <Value> node_swe_deg_midp (const Arguments & args);

/**
 * void swe_split_deg(double ddeg, int32 roundflag, int32 *ideg, int32 *imin, int32 *isec, double *dsecfr, int32 *isgn)
 */
Handle <Value> node_swe_split_deg (const Arguments & args);

/**
 * centisec swe_csnorm(centisec p)
 */
Handle <Value> node_swe_csnorm (const Arguments & args);

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 */
Handle <Value> node_swe_difcsn  (const Arguments & args);

/**
 * double swe_difdegn (double p1, double p2)
 */
Handle <Value> node_swe_difdegn  (const Arguments & args);

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 */
Handle <Value> node_swe_difcs2n (const Arguments & args);

/**
 * double swe_difdeg2n(double p1, double p2)
 */
Handle <Value> node_swe_difdeg2n (const Arguments & args);

/**
 * double swe_difrad2n(double p1, double p2)
 */
Handle <Value> node_swe_difrad2n (const Arguments & args);

/**
 * centisec swe_csroundsec(centisec x)
 */
Handle <Value> node_swe_csroundsec (const Arguments & args);

/**
 * int32 swe_d2l(double x)
 */
Handle <Value> node_swe_d2l (const Arguments & args);

/**
 * int swe_day_of_week(double jd)
 */
Handle <Value> node_swe_day_of_week (const Arguments & args);

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a)
 */
Handle <Value> node_swe_cs2timestr (const Arguments & args);

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s)
 */
Handle <Value> node_swe_cs2lonlatstr (const Arguments & args);

/**
 * char * swe_cs2degstr(CSEC t, char *a)
 */
Handle <Value> node_swe_cs2degstr (const Arguments & args);

#endif // __swisseph_util_h__
