#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

/**
 * double swe_deltat(double tjd)
 * =>
 * swe_deltat(double tjd[, function callback (result)]) = {
 *   delta: double
 * }
 */
Handle <Value> node_swe_deltat (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int swe_time_equ(double tjd, double *te, char *serr)
 * =>
 * swe_time_equ(double tjd[, function callback (result)]) = {
 *   timeEquatin: double,
 *   error: string
 * }
 */
Handle <Value> node_swe_time_equ (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 * =>
 * swe_sidtime0(double tjd_ut, double eps, double nut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
Handle <Value> node_swe_sidtime0 (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_sidtime(double tjd_ut)
 * =>
 * swe_sidtime(double tjd_ut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
Handle <Value> node_swe_sidtime (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_cotrans(double *xpo (in[3]), double *xpn (out[3]), double eps)
 * =>
 * swe_cotrans(double xpo [3], double eps[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double
 * }
 */
Handle <Value> node_swe_cotrans (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_cotrans_sp(double *xpo (in[3]), double *xpn (out[3]), double eps)
 * =>
 * swe_cotrans_sp(double *xpo, double eps[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double
 * }
 */
Handle <Value> node_swe_cotrans_sp (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_get_tid_acc(void)
 * =>
 * swe_get_tid_acc(void[, function callback (result)]) = {
 *   acceleration: double
 * }
 */
Handle <Value> node_swe_get_tid_acc (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_set_tid_acc(double t_acc)
 * =>
 * swe_set_tid_acc(double t_acc[, function callback (result)]) = {
 * }
 */
Handle <Value> node_swe_set_tid_acc (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_degnorm(double x)
 * =>
 * swe_degnorm(double x[, function callback (result)]) = {
 *   x360: double
 * }
 */
Handle <Value> node_swe_degnorm (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_radnorm(double x)
 * =>
 * swe_radnorm(double x[, function callback (result)]) = {
 *   x2Pi: double
 * }
 */
Handle <Value> node_swe_radnorm (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_rad_midp(double x1, double x0)
 * =>
 * swe_rad_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid2Pi: double
 * }
 */
Handle <Value> node_swe_rad_midp (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_deg_midp(double x1, double x0)
 * =>
 * swe_deg_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid360: double
 * }
 */
Handle <Value> node_swe_deg_midp (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_split_deg(double ddeg, int32 roundflag, int32 *ideg (out[1]), int32 *imin (out[1]), int32 *isec (out[1]), double *dsecfr (out[1]), int32 *isgn (out[1]))
 * =>
 * swe_split_deg(double ddeg, int32 roundflag[, function callback (result)]) = {
 *   degree: int,
 *   min: int,
 *   second: int,
 *   secondFraction: double,
 *   sign: int
 * }
 */
Handle <Value> node_swe_split_deg (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * centisec swe_csnorm(centisec p)
 * =>
 * swe_csnorm(centisec p[, function callback (result)]) = {
 *   centisec360: double
 * }
 */
Handle <Value> node_swe_csnorm (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 * =>
 * swe_difcsn (centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDiff: double
 * }
 */
Handle <Value> node_swe_difcsn  (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_difdegn (double p1, double p2)
 * =>
 * swe_difdegn (double p1, double p2[, function callback (result)]) = {
 *   degreeDiff: double
 * }
 */
Handle <Value> node_swe_difdegn  (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 * =>
 * swe_difcs2n(centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDistance180: double
 * }
 */
Handle <Value> node_swe_difcs2n (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_difdeg2n(double p1, double p2)
 * =>
 * swe_difdeg2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistance180: double
 * }
 */
Handle <Value> node_swe_difdeg2n (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_difrad2n(double p1, double p2)
 * =>
 * swe_difrad2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistancePi: double
 * }
 */
Handle <Value> node_swe_difrad2n (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * centisec swe_csroundsec(centisec x)
 * =>
 * swe_csroundsec(centisec x[, function callback (result)]) = {
 *   centisecRound: double
 * }
 */
Handle <Value> node_swe_csroundsec (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_d2l(double x)
 * =>
 * swe_d2l(double x[, function callback (result)]) = {
 *   xRound: int
 * }
 */
Handle <Value> node_swe_d2l (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int swe_day_of_week(double jd)
 * =>
 * swe_day_of_week(double jd[, function callback (result)]) = {
 *   dayOfWeek: int
 * }
 */
Handle <Value> node_swe_day_of_week (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero[, function callback (result)]) = {
 *   timeString: string
 * }
 */
Handle <Value> node_swe_cs2timestr (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s (out[AS_MAXCH]))
 * =>
 * swe_cs2lonlatstr(CSEC t, char pchar, char mchar[, function callback (result)]) = {
 *   lonlatString: string
 * }
 */
Handle <Value> node_swe_cs2lonlatstr (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * char * swe_cs2degstr(CSEC t, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2degstr(CSEC t[, function callback (result)]) = {
 *   degreeString: string
 * }
 */
Handle <Value> node_swe_cs2degstr (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};
