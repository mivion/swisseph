#include "swisseph.h"

using namespace v8;

/**
 * double swe_deltat(double tjd)
 * =>
 * swe_deltat(double tjd[, function callback (result)]) = {
 *   delta: double
 * }
 */
void node_swe_deltat (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double deltat;

	deltat = ::swe_deltat (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "delta"), Number::New (isolate, deltat));

    HandleCallback (isolate, args, result);
};

/**
 * int swe_time_equ(double tjd, double *te (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_time_equ(double tjd[, function callback (result)]) = {
 *   timeEquation: double,
 *   error: string
 * }
 */
void node_swe_time_equ (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double te;
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_time_equ (
		args [0]->NumberValue (),
		&te, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "timeEquation"), Number::New (isolate, te));
	}

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 * =>
 * swe_sidtime0(double tjd_ut, double eps, double nut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
void node_swe_sidtime0 (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 3) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double st;

	st = ::swe_sidtime0 (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "siderialTime"), Number::New (isolate, st));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_sidtime(double tjd_ut)
 * =>
 * swe_sidtime(double tjd_ut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
void node_swe_sidtime (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double st;

	st = ::swe_sidtime (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "siderialTime"), Number::New (isolate, st));

    HandleCallback (isolate, args, result);

	
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
void node_swe_cotrans (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsArray () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
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

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "longitude"), Number::New (isolate, xpn [0]));
	result->Set (String::NewFromUtf8 (isolate, "latitude"), Number::New (isolate, xpn [1]));
	result->Set (String::NewFromUtf8 (isolate, "distance"), Number::New (isolate, xpn [2]));

    HandleCallback (isolate, args, result);

	
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
void node_swe_cotrans_sp (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsArray () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
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

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "longitude"), Number::New (isolate, xpn [0]));
	result->Set (String::NewFromUtf8 (isolate, "latitude"), Number::New (isolate, xpn [1]));
	result->Set (String::NewFromUtf8 (isolate, "distance"), Number::New (isolate, xpn [2]));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_get_tid_acc(void)
 * =>
 * swe_get_tid_acc(void[, function callback (result)]) = {
 *   acceleration: double
 * }
 */
void node_swe_get_tid_acc (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	double acceleration;

	acceleration = ::swe_get_tid_acc ();

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "acceleration"), Number::New (isolate, acceleration));

    HandleCallback (isolate, args, result);

	
};

/**
 * void swe_set_tid_acc(double t_acc)
 * =>
 * swe_set_tid_acc(double t_acc[, function callback (result)]) = {
 * }
 */
void node_swe_set_tid_acc (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	::swe_set_tid_acc (
        args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_degnorm(double x)
 * =>
 * swe_degnorm(double x[, function callback (result)]) = {
 *   x360: double
 * }
 */
void node_swe_degnorm (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double x360;

	x360 = ::swe_degnorm (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "x360"), Number::New (isolate, x360));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_radnorm(double x)
 * =>
 * swe_radnorm(double x[, function callback (result)]) = {
 *   x2Pi: double
 * }
 */
void node_swe_radnorm (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double x2Pi;

	x2Pi = ::swe_radnorm (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "x2Pi"), Number::New (isolate, x2Pi));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_rad_midp(double x1, double x0)
 * =>
 * swe_rad_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid2Pi: double
 * }
 */
void node_swe_rad_midp (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double xMid2Pi;

	xMid2Pi = ::swe_rad_midp (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "xMid2Pi"), Number::New (isolate, xMid2Pi));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_deg_midp(double x1, double x0)
 * =>
 * swe_deg_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid360: double
 * }
 */
void node_swe_deg_midp (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double xMid360;

	xMid360 = ::swe_deg_midp (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "xMid360"), Number::New (isolate, xMid360));

    HandleCallback (isolate, args, result);

	
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
void node_swe_split_deg (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
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

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "degree"), Number::New (isolate, ideg));
	result->Set (String::NewFromUtf8 (isolate, "min"), Number::New (isolate, imin));
	result->Set (String::NewFromUtf8 (isolate, "second"), Number::New (isolate, isec));
	result->Set (String::NewFromUtf8 (isolate, "secondFraction"), Number::New (isolate, dsecfr));
	result->Set (String::NewFromUtf8 (isolate, "sign"), Number::New (isolate, isgn));

    HandleCallback (isolate, args, result);

	
};

/**
 * centisec swe_csnorm(centisec p)
 * =>
 * swe_csnorm(centisec p[, function callback (result)]) = {
 *   centisec360: double
 * }
 */
void node_swe_csnorm (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	int centisec360;

	centisec360 = ::swe_csnorm (
		(int)args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "centisec360"), Number::New (isolate, centisec360));

    HandleCallback (isolate, args, result);

	
};

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 * =>
 * swe_difcsn (centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDiff: double
 * }
 */
void node_swe_difcsn  (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	int centisecDiff;

	centisecDiff = ::swe_difcsn (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "centisecDiff"), Number::New (isolate, centisecDiff));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_difdegn (double p1, double p2)
 * =>
 * swe_difdegn (double p1, double p2[, function callback (result)]) = {
 *   degreeDiff: double
 * }
 */
void node_swe_difdegn  (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double degreeDiff;

	degreeDiff = ::swe_difdegn (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "degreeDiff"), Number::New (isolate, degreeDiff));

    HandleCallback (isolate, args, result);

	
};

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 * =>
 * swe_difcs2n(centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDistance180: double
 * }
 */
void node_swe_difcs2n (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	int centisecDistance180;

	centisecDistance180 = ::swe_difcs2n (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "centisecDistance180"), Number::New (isolate, centisecDistance180));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_difdeg2n(double p1, double p2)
 * =>
 * swe_difdeg2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistance180: double
 * }
 */
void node_swe_difdeg2n (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double degreeDistance180;

	degreeDistance180 = ::swe_difdeg2n (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "degreeDistance180"), Number::New (isolate, degreeDistance180));

    HandleCallback (isolate, args, result);

	
};

/**
 * double swe_difrad2n(double p1, double p2)
 * =>
 * swe_difrad2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistancePi: double
 * }
 */
void node_swe_difrad2n (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double degreeDistancePi;

	degreeDistancePi = ::swe_difrad2n (
		args [0]->NumberValue (),
		args [1]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "degreeDistancePi"), Number::New (isolate, degreeDistancePi));

    HandleCallback (isolate, args, result);

	
};

/**
 * centisec swe_csroundsec(centisec x)
 * =>
 * swe_csroundsec(centisec x[, function callback (result)]) = {
 *   centisecRound: double
 * }
 */
void node_swe_csroundsec (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	int centisecRound;

	centisecRound = ::swe_csroundsec (
		(int)args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "centisecRound"), Number::New (isolate, centisecRound));

    HandleCallback (isolate, args, result);

	
};

/**
 * int32 swe_d2l(double x)
 * =>
 * swe_d2l(double x[, function callback (result)]) = {
 *   xRound: int
 * }
 */
void node_swe_d2l (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	int xRound;

	xRound = ::swe_d2l (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "xRound"), Number::New (isolate, xRound));

    HandleCallback (isolate, args, result);

	
};

/**
 * int swe_day_of_week(double jd)
 * =>
 * swe_day_of_week(double jd[, function callback (result)]) = {
 *   dayOfWeek: int
 * }
 */
void node_swe_day_of_week (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	int dayOfWeek;

	dayOfWeek = ::swe_day_of_week (
		args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "dayOfWeek"), Number::New (isolate, dayOfWeek));

    HandleCallback (isolate, args, result);

	
};

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero[, function callback (result)]) = {
 *   timeString: string
 * }
 */
void node_swe_cs2timestr (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 3) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	char timeString [AS_MAXCH] = {0};

	::swe_cs2timestr (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		timeString
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "timeString"), String::NewFromUtf8 (isolate, timeString));

    HandleCallback (isolate, args, result);

	
};

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s (out[AS_MAXCH]))
 * =>
 * swe_cs2lonlatstr(CSEC t, char pchar, char mchar[, function callback (result)]) = {
 *   lonlatString: string
 * }
 */
void node_swe_cs2lonlatstr (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 3) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsString () ||
		!args [2]->IsString ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	char lonlatString [AS_MAXCH] = {0};

	::swe_cs2lonlatstr (
		(int)args [0]->NumberValue (),
		(* String::Utf8Value (args [1]->ToString ())) [0],
		(* String::Utf8Value (args [2]->ToString ())) [0],
		lonlatString
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "lonlatString"), String::NewFromUtf8 (isolate, lonlatString));

    HandleCallback (isolate, args, result);

	
};

/**
 * char * swe_cs2degstr(CSEC t, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2degstr(CSEC t[, function callback (result)]) = {
 *   degreeString: string
 * }
 */
void node_swe_cs2degstr (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);
	

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	char degreeString [AS_MAXCH] = {0};

	::swe_cs2degstr (
		(int)args [0]->NumberValue (),
		degreeString
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "degreeString"), String::NewFromUtf8 (isolate, degreeString));

    HandleCallback (isolate, args, result);

	
};
