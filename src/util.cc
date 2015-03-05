#include "swisseph.h"

using namespace v8;

/**
 * double swe_deltat(double tjd)
 * =>
 * swe_deltat(double tjd[, function callback (result)]) = {
 *   delta: double
 * }
 */
NAN_METHOD(node_swe_deltat) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double deltat;

	deltat = ::swe_deltat (
		args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("delta"), NanNew<Number> (deltat));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * int swe_time_equ(double tjd, double *te (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_time_equ(double tjd[, function callback (result)]) = {
 *   timeEquation: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_time_equ) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double te;
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_time_equ (
		args [0]->NumberValue (),
		&te, serr
	);

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("timeEquation"), NanNew<Number> (te));
	}

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 * =>
 * swe_sidtime0(double tjd_ut, double eps, double nut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
NAN_METHOD(node_swe_sidtime0) {
	NanScope();

	if (args.Length () < 3) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double st;

	st = ::swe_sidtime0 (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("siderialTime"), NanNew<Number> (st));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_sidtime(double tjd_ut)
 * =>
 * swe_sidtime(double tjd_ut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
NAN_METHOD(node_swe_sidtime) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double st;

	st = ::swe_sidtime (
		args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("siderialTime"), NanNew<Number> (st));

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_cotrans) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsArray () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("longitude"), NanNew<Number> (xpn [0]));
	result->Set (NanNew<String> ("latitude"), NanNew<Number> (xpn [1]));
	result->Set (NanNew<String> ("distance"), NanNew<Number> (xpn [2]));

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_cotrans_sp) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsArray () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("longitude"), NanNew<Number> (xpn [0]));
	result->Set (NanNew<String> ("latitude"), NanNew<Number> (xpn [1]));
	result->Set (NanNew<String> ("distance"), NanNew<Number> (xpn [2]));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_get_tid_acc(void)
 * =>
 * swe_get_tid_acc(void[, function callback (result)]) = {
 *   acceleration: double
 * }
 */
NAN_METHOD(node_swe_get_tid_acc) {
	NanScope();

	double acceleration;

	acceleration = ::swe_get_tid_acc ();

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("acceleration"), NanNew<Number> (acceleration));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * void swe_set_tid_acc(double t_acc)
 * =>
 * swe_set_tid_acc(double t_acc[, function callback (result)]) = {
 * }
 */
NAN_METHOD(node_swe_set_tid_acc) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_tid_acc (
        args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_degnorm(double x)
 * =>
 * swe_degnorm(double x[, function callback (result)]) = {
 *   x360: double
 * }
 */
NAN_METHOD(node_swe_degnorm) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double x360;

	x360 = ::swe_degnorm (
		args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("x360"), NanNew<Number> (x360));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_radnorm(double x)
 * =>
 * swe_radnorm(double x[, function callback (result)]) = {
 *   x2Pi: double
 * }
 */
NAN_METHOD(node_swe_radnorm) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double x2Pi;

	x2Pi = ::swe_radnorm (
		args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("x2Pi"), NanNew<Number> (x2Pi));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_rad_midp(double x1, double x0)
 * =>
 * swe_rad_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid2Pi: double
 * }
 */
NAN_METHOD(node_swe_rad_midp) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double xMid2Pi;

	xMid2Pi = ::swe_rad_midp (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("xMid2Pi"), NanNew<Number> (xMid2Pi));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_deg_midp(double x1, double x0)
 * =>
 * swe_deg_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid360: double
 * }
 */
NAN_METHOD(node_swe_deg_midp) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double xMid360;

	xMid360 = ::swe_deg_midp (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("xMid360"), NanNew<Number> (xMid360));

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_split_deg) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("degree"), NanNew<Number> (ideg));
	result->Set (NanNew<String> ("min"), NanNew<Number> (imin));
	result->Set (NanNew<String> ("second"), NanNew<Number> (isec));
	result->Set (NanNew<String> ("secondFraction"), NanNew<Number> (dsecfr));
	result->Set (NanNew<String> ("sign"), NanNew<Number> (isgn));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * centisec swe_csnorm(centisec p)
 * =>
 * swe_csnorm(centisec p[, function callback (result)]) = {
 *   centisec360: double
 * }
 */
NAN_METHOD(node_swe_csnorm) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	int centisec360;

	centisec360 = ::swe_csnorm (
		(int)args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("centisec360"), NanNew<Number> (centisec360));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 * =>
 * swe_difcsn (centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDiff: double
 * }
 */
NAN_METHOD(node_swe_difcsn ) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	int centisecDiff;

	centisecDiff = ::swe_difcsn (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("centisecDiff"), NanNew<Number> (centisecDiff));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_difdegn (double p1, double p2)
 * =>
 * swe_difdegn (double p1, double p2[, function callback (result)]) = {
 *   degreeDiff: double
 * }
 */
NAN_METHOD(node_swe_difdegn ) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double degreeDiff;

	degreeDiff = ::swe_difdegn (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("degreeDiff"), NanNew<Number> (degreeDiff));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 * =>
 * swe_difcs2n(centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDistance180: double
 * }
 */
NAN_METHOD(node_swe_difcs2n) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	int centisecDistance180;

	centisecDistance180 = ::swe_difcs2n (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("centisecDistance180"), NanNew<Number> (centisecDistance180));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_difdeg2n(double p1, double p2)
 * =>
 * swe_difdeg2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistance180: double
 * }
 */
NAN_METHOD(node_swe_difdeg2n) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double degreeDistance180;

	degreeDistance180 = ::swe_difdeg2n (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("degreeDistance180"), NanNew<Number> (degreeDistance180));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_difrad2n(double p1, double p2)
 * =>
 * swe_difrad2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistancePi: double
 * }
 */
NAN_METHOD(node_swe_difrad2n) {
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double degreeDistancePi;

	degreeDistancePi = ::swe_difrad2n (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("degreeDistancePi"), NanNew<Number> (degreeDistancePi));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * centisec swe_csroundsec(centisec x)
 * =>
 * swe_csroundsec(centisec x[, function callback (result)]) = {
 *   centisecRound: double
 * }
 */
NAN_METHOD(node_swe_csroundsec) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	int centisecRound;

	centisecRound = ::swe_csroundsec (
		(int)args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("centisecRound"), NanNew<Number> (centisecRound));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * int32 swe_d2l(double x)
 * =>
 * swe_d2l(double x[, function callback (result)]) = {
 *   xRound: int
 * }
 */
NAN_METHOD(node_swe_d2l) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	int xRound;

	xRound = ::swe_d2l (
		args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("xRound"), NanNew<Number> (xRound));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * int swe_day_of_week(double jd)
 * =>
 * swe_day_of_week(double jd[, function callback (result)]) = {
 *   dayOfWeek: int
 * }
 */
NAN_METHOD(node_swe_day_of_week) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	int dayOfWeek;

	dayOfWeek = ::swe_day_of_week (
		args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("dayOfWeek"), NanNew<Number> (dayOfWeek));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero[, function callback (result)]) = {
 *   timeString: string
 * }
 */
NAN_METHOD(node_swe_cs2timestr) {
	NanScope();

	if (args.Length () < 3) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	char timeString [AS_MAXCH] = {0};

	::swe_cs2timestr (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		timeString
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("timeString"), NanNew<String> (timeString));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s (out[AS_MAXCH]))
 * =>
 * swe_cs2lonlatstr(CSEC t, char pchar, char mchar[, function callback (result)]) = {
 *   lonlatString: string
 * }
 */
NAN_METHOD(node_swe_cs2lonlatstr) {
	NanScope();

	if (args.Length () < 3) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsString () ||
		!args [2]->IsString ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	char lonlatString [AS_MAXCH] = {0};

	::swe_cs2lonlatstr (
		(int)args [0]->NumberValue (),
		(* String::Utf8Value (args [1]->ToString ())) [0],
		(* String::Utf8Value (args [2]->ToString ())) [0],
		lonlatString
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("lonlatString"), NanNew<String> (lonlatString));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * char * swe_cs2degstr(CSEC t, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2degstr(CSEC t[, function callback (result)]) = {
 *   degreeString: string
 * }
 */
NAN_METHOD(node_swe_cs2degstr) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	char degreeString [AS_MAXCH] = {0};

	::swe_cs2degstr (
		(int)args [0]->NumberValue (),
		degreeString
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("degreeString"), NanNew<String> (degreeString));

    HandleCallback (args, result);
    NanReturnValue (result);
};
