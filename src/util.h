#ifndef __swisseph_util_h__
#define __swisseph_util_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * double swe_deltat(double tjd)
 */
void node_swe_deltat (const FunctionCallbackInfo <Value> & args);

/**
 * int swe_time_equ(double tjd, double *te, char *serr)
 */
void node_swe_time_equ (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 */
void node_swe_sidtime0 (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_sidtime(double tjd_ut)
 */
void node_swe_sidtime (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_cotrans(double *xpo, double *xpn, double eps)
 */
void node_swe_cotrans (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_cotrans_sp(double *xpo, double *xpn, double eps)
 */
void node_swe_cotrans_sp (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_get_tid_acc(void)
 */
void node_swe_get_tid_acc (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_set_tid_acc(double t_acc)
 */
void node_swe_set_tid_acc (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_degnorm(double x)
 */
void node_swe_degnorm (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_radnorm(double x)
 */
void node_swe_radnorm (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_rad_midp(double x1, double x0)
 */
void node_swe_rad_midp (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_deg_midp(double x1, double x0)
 */
void node_swe_deg_midp (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_split_deg(double ddeg, int32 roundflag, int32 *ideg, int32 *imin, int32 *isec, double *dsecfr, int32 *isgn)
 */
void node_swe_split_deg (const FunctionCallbackInfo <Value> & args);

/**
 * centisec swe_csnorm(centisec p)
 */
void node_swe_csnorm (const FunctionCallbackInfo <Value> & args);

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 */
void node_swe_difcsn  (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_difdegn (double p1, double p2)
 */
void node_swe_difdegn  (const FunctionCallbackInfo <Value> & args);

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 */
void node_swe_difcs2n (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_difdeg2n(double p1, double p2)
 */
void node_swe_difdeg2n (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_difrad2n(double p1, double p2)
 */
void node_swe_difrad2n (const FunctionCallbackInfo <Value> & args);

/**
 * centisec swe_csroundsec(centisec x)
 */
void node_swe_csroundsec (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_d2l(double x)
 */
void node_swe_d2l (const FunctionCallbackInfo <Value> & args);

/**
 * int swe_day_of_week(double jd)
 */
void node_swe_day_of_week (const FunctionCallbackInfo <Value> & args);

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a)
 */
void node_swe_cs2timestr (const FunctionCallbackInfo <Value> & args);

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s)
 */
void node_swe_cs2lonlatstr (const FunctionCallbackInfo <Value> & args);

/**
 * char * swe_cs2degstr(CSEC t, char *a)
 */
void node_swe_cs2degstr (const FunctionCallbackInfo <Value> & args);

#endif // __swisseph_util_h__
