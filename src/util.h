#ifndef __swisseph_util_h__
#define __swisseph_util_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * double swe_deltat(double tjd)
 */
NAN_METHOD(node_swe_deltat);

/**
 * int swe_time_equ(double tjd, double *te, char *serr)
 */
NAN_METHOD(node_swe_time_equ);

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 */
NAN_METHOD(node_swe_sidtime0);

/**
 * double swe_sidtime(double tjd_ut)
 */
NAN_METHOD(node_swe_sidtime);

/**
 * void swe_cotrans(double *xpo, double *xpn, double eps)
 */
NAN_METHOD(node_swe_cotrans);

/**
 * void swe_cotrans_sp(double *xpo, double *xpn, double eps)
 */
NAN_METHOD(node_swe_cotrans_sp);

/**
 * double swe_get_tid_acc(void)
 */
NAN_METHOD(node_swe_get_tid_acc);

/**
 * void swe_set_tid_acc(double t_acc)
 */
NAN_METHOD(node_swe_set_tid_acc);

/**
 * double swe_degnorm(double x)
 */
NAN_METHOD(node_swe_degnorm);

/**
 * double swe_radnorm(double x)
 */
NAN_METHOD(node_swe_radnorm);

/**
 * double swe_rad_midp(double x1, double x0)
 */
NAN_METHOD(node_swe_rad_midp);

/**
 * double swe_deg_midp(double x1, double x0)
 */
NAN_METHOD(node_swe_deg_midp);

/**
 * void swe_split_deg(double ddeg, int32 roundflag, int32 *ideg, int32 *imin, int32 *isec, double *dsecfr, int32 *isgn)
 */
NAN_METHOD(node_swe_split_deg);

/**
 * centisec swe_csnorm(centisec p)
 */
NAN_METHOD(node_swe_csnorm);

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 */
NAN_METHOD(node_swe_difcsn );

/**
 * double swe_difdegn (double p1, double p2)
 */
NAN_METHOD(node_swe_difdegn );

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 */
NAN_METHOD(node_swe_difcs2n);

/**
 * double swe_difdeg2n(double p1, double p2)
 */
NAN_METHOD(node_swe_difdeg2n);

/**
 * double swe_difrad2n(double p1, double p2)
 */
NAN_METHOD(node_swe_difrad2n);

/**
 * centisec swe_csroundsec(centisec x)
 */
NAN_METHOD(node_swe_csroundsec);

/**
 * int32 swe_d2l(double x)
 */
NAN_METHOD(node_swe_d2l);

/**
 * int swe_day_of_week(double jd)
 */
NAN_METHOD(node_swe_day_of_week);

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a)
 */
NAN_METHOD(node_swe_cs2timestr);

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s)
 */
NAN_METHOD(node_swe_cs2lonlatstr);

/**
 * char * swe_cs2degstr(CSEC t, char *a)
 */
NAN_METHOD(node_swe_cs2degstr);

#endif // __swisseph_util_h__
