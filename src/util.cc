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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double deltat;

	deltat = ::swe_deltat (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("delta"), Number::New (deltat));

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int swe_time_equ(double tjd, double *te (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_time_equ(double tjd[, function callback (result)]) = {
 *   timeEquation: double,
 *   error: string
 * }
 */
Handle <Value> node_swe_time_equ (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double te;
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_time_equ (
		args [0]->NumberValue (),
		&te, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("timeEquation"), Number::New (te));
	}

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

	if (args.Length () < 3) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double st;

	st = ::swe_sidtime0 (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("siderialTime"), Number::New (st));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double st;

	st = ::swe_sidtime (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("siderialTime"), Number::New (st));

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_cotrans(double *xpo (in[3]), double *xpn (out[3]), double eps)
 * =>
 * swe_cotrans(double xpo [3], double eps[, function callback (result)]) = {
 *   longitude: double, // xpn [0]
 *   latitude: double,  // xpn [1]
 *   distance: double   // xpn [2]
 * }
 */
Handle <Value> node_swe_cotrans (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsArray () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double xpn [3] = {0};
	double xpo [3] = {0};

	xpo [0] = args [0]->ToObject ()->Get (0)->NumberValue ();
	xpo [1] = args [0]->ToObject ()->Get (1)->NumberValue ();
	xpo [2] = args [0]->ToObject ()->Get (2)->NumberValue ();

	::swe_cotrans (
		xpo, xpn,
        args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("longitude"), Number::New (xpn [0]));
	result->Set (String::NewSymbol ("latitude"), Number::New (xpn [1]));
	result->Set (String::NewSymbol ("distance"), Number::New (xpn [2]));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsArray () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double xpn [3] = {0};
	double xpo [3] = {0};

	xpo [0] = args [0]->ToObject ()->Get (0)->NumberValue ();
	xpo [1] = args [0]->ToObject ()->Get (1)->NumberValue ();
	xpo [2] = args [0]->ToObject ()->Get (2)->NumberValue ();

	::swe_cotrans_sp (
		xpo, xpn,
        args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("longitude"), Number::New (xpn [0]));
	result->Set (String::NewSymbol ("latitude"), Number::New (xpn [1]));
	result->Set (String::NewSymbol ("distance"), Number::New (xpn [2]));

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

	double acceleration;

	acceleration = ::swe_get_tid_acc ();

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("acceleration"), Number::New (acceleration));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	::swe_set_tid_acc (
        args [0]->NumberValue ()
	);

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double x360;

	x360 = ::swe_degnorm (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("x360"), Number::New (x360));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double x2Pi;

	x2Pi = ::swe_radnorm (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("x2Pi"), Number::New (x2Pi));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double xMid2Pi;

	xMid2Pi = ::swe_rad_midp (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("xMid2Pi"), Number::New (xMid2Pi));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double xMid360;

	xMid360 = ::swe_deg_midp (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("xMid360"), Number::New (xMid360));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	int ideg;
	int imin;
	int isec;
	double dsecfr;
	int isgn;

	::swe_split_deg (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&ideg, &imin, &isec, &dsecfr, &isgn
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("degree"), Number::New (ideg));
	result->Set (String::NewSymbol ("min"), Number::New (imin));
	result->Set (String::NewSymbol ("second"), Number::New (isec));
	result->Set (String::NewSymbol ("secondFraction"), Number::New (dsecfr));
	result->Set (String::NewSymbol ("sign"), Number::New (isgn));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	int centisec360;

	centisec360 = ::swe_csnorm (
		(int)args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("centisec360"), Number::New (centisec360));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	int centisecDiff;

	centisecDiff = ::swe_difcsn (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("centisecDiff"), Number::New (centisecDiff));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double degreeDiff;

	degreeDiff = ::swe_difdegn (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("degreeDiff"), Number::New (degreeDiff));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	int centisecDistance180;

	centisecDistance180 = ::swe_difcs2n (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("centisecDistance180"), Number::New (centisecDistance180));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double degreeDistance180;

	degreeDistance180 = ::swe_difdeg2n (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("degreeDistance180"), Number::New (degreeDistance180));

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

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double degreeDistancePi;

	degreeDistancePi = ::swe_difrad2n (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("degreeDistancePi"), Number::New (degreeDistancePi));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	int centisecRound;

	centisecRound = ::swe_csroundsec (
		(int)args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("centisecRound"), Number::New (centisecRound));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	int xRound;

	xRound = ::swe_d2l (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("xRound"), Number::New (xRound));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	int dayOfWeek;

	dayOfWeek = ::swe_day_of_week (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("dayOfWeek"), Number::New (dayOfWeek));

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

	if (args.Length () < 3) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	char timeString [AS_MAXCH] = {0};

	::swe_cs2timestr (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		timeString
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("timeString"), String::New (timeString));

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

	if (args.Length () < 3) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsString () ||
		!args [2]->IsString ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	char lonlatString [AS_MAXCH] = {0};

	::swe_cs2lonlatstr (
		(int)args [0]->NumberValue (),
		(* String::AsciiValue (args [1]->ToString ())) [0],
		(* String::AsciiValue (args [2]->ToString ())) [0],
		lonlatString
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("lonlatString"), String::New (lonlatString));

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

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	char degreeString [AS_MAXCH] = {0};

	::swe_cs2degstr (
		(int)args [0]->NumberValue (),
		degreeString
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("degreeString"), String::New (degreeString));

    HandleCallback (args, result);

	return scope.Close (result);
};
