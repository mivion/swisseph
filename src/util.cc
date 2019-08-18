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
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double deltat;

	deltat = ::swe_deltat (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("delta").ToLocalChecked(), Nan::New<Number> (deltat));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
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
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double te;
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_time_equ (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&te, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("timeEquation").ToLocalChecked(), Nan::New<Number> (te));
	}

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 * =>
 * swe_sidtime0(double tjd_ut, double eps, double nut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
NAN_METHOD(node_swe_sidtime0) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double st;

	st = ::swe_sidtime0 (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("siderialTime").ToLocalChecked(), Nan::New<Number> (st));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_sidtime(double tjd_ut)
 * =>
 * swe_sidtime(double tjd_ut[, function callback (result)]) = {
 *   siderialTime: double
 * }
 */
NAN_METHOD(node_swe_sidtime) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double st;

	st = ::swe_sidtime (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("siderialTime").ToLocalChecked(), Nan::New<Number> (st));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
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
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsArray () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double xpn [3] = {0};
	double xpo [3] = {0};

	xpo [0] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xpo [1] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xpo [2] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	::swe_cotrans (
		xpo, xpn,
        info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (xpn [0]));
	Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (xpn [1]));
	Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (xpn [2]));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
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
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsArray () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double xpn [6] = {0};
	double xpo [6] = {0};

	xpo [0] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xpo [1] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xpo [2] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xpo [3] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),3).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xpo [4] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),4).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xpo [5] = info [0]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),5).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();


	::swe_cotrans_sp (
		xpo, xpn,
        info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (xpn [0]));
	Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (xpn [1]));
	Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (xpn [2]));
	Nan::Set(result,Nan::New<String> ("longitudeSpeed").ToLocalChecked(), Nan::New<Number> (xpn [3]));
	Nan::Set(result,Nan::New<String> ("latitudeSpeed").ToLocalChecked(), Nan::New<Number> (xpn [4]));
	Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (xpn [5]));


    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_get_tid_acc(void)
 * =>
 * swe_get_tid_acc(void[, function callback (result)]) = {
 *   acceleration: double
 * }
 */
NAN_METHOD(node_swe_get_tid_acc) {
	Nan::HandleScope scope;

	double acceleration;

	acceleration = ::swe_get_tid_acc ();

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("acceleration").ToLocalChecked(), Nan::New<Number> (acceleration));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_set_tid_acc(double t_acc)
 * =>
 * swe_set_tid_acc(double t_acc[, function callback (result)]) = {
 * }
 */
NAN_METHOD(node_swe_set_tid_acc) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_tid_acc (
        info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_degnorm(double x)
 * =>
 * swe_degnorm(double x[, function callback (result)]) = {
 *   x360: double
 * }
 */
NAN_METHOD(node_swe_degnorm) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x360;

	x360 = ::swe_degnorm (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("x360").ToLocalChecked(), Nan::New<Number> (x360));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_radnorm(double x)
 * =>
 * swe_radnorm(double x[, function callback (result)]) = {
 *   x2Pi: double
 * }
 */
NAN_METHOD(node_swe_radnorm) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x2Pi;

	x2Pi = ::swe_radnorm (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("x2Pi").ToLocalChecked(), Nan::New<Number> (x2Pi));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_rad_midp(double x1, double x0)
 * =>
 * swe_rad_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid2Pi: double
 * }
 */
NAN_METHOD(node_swe_rad_midp) {
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double xMid2Pi;

	xMid2Pi = ::swe_rad_midp (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("xMid2Pi").ToLocalChecked(), Nan::New<Number> (xMid2Pi));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_deg_midp(double x1, double x0)
 * =>
 * swe_deg_midp(double x1, double x0[, function callback (result)]) = {
 *   xMid360: double
 * }
 */
NAN_METHOD(node_swe_deg_midp) {
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double xMid360;

	xMid360 = ::swe_deg_midp (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("xMid360").ToLocalChecked(), Nan::New<Number> (xMid360));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
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
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	int ideg;
	int imin;
	int isec;
	double dsecfr;
	int isgn;

	::swe_split_deg (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&ideg, &imin, &isec, &dsecfr, &isgn
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("degree").ToLocalChecked(), Nan::New<Number> (ideg));
	Nan::Set(result,Nan::New<String> ("min").ToLocalChecked(), Nan::New<Number> (imin));
	Nan::Set(result,Nan::New<String> ("second").ToLocalChecked(), Nan::New<Number> (isec));
	Nan::Set(result,Nan::New<String> ("secondFraction").ToLocalChecked(), Nan::New<Number> (dsecfr));
	Nan::Set(result,Nan::New<String> ("sign").ToLocalChecked(), Nan::New<Number> (isgn));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * centisec swe_csnorm(centisec p)
 * =>
 * swe_csnorm(centisec p[, function callback (result)]) = {
 *   centisec360: double
 * }
 */
NAN_METHOD(node_swe_csnorm) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	int centisec360;

	centisec360 = ::swe_csnorm (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("centisec360").ToLocalChecked(), Nan::New<Number> (centisec360));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 * =>
 * swe_difcsn (centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDiff: double
 * }
 */
NAN_METHOD(node_swe_difcsn ) {
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	int centisecDiff;

	centisecDiff = ::swe_difcsn (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("centisecDiff").ToLocalChecked(), Nan::New<Number> (centisecDiff));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_difdegn (double p1, double p2)
 * =>
 * swe_difdegn (double p1, double p2[, function callback (result)]) = {
 *   degreeDiff: double
 * }
 */
NAN_METHOD(node_swe_difdegn ) {
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double degreeDiff;

	degreeDiff = ::swe_difdegn (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("degreeDiff").ToLocalChecked(), Nan::New<Number> (degreeDiff));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 * =>
 * swe_difcs2n(centisec p1, centisec p2[, function callback (result)]) = {
 *   centisecDistance180: double
 * }
 */
NAN_METHOD(node_swe_difcs2n) {
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	int centisecDistance180;

	centisecDistance180 = ::swe_difcs2n (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("centisecDistance180").ToLocalChecked(), Nan::New<Number> (centisecDistance180));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_difdeg2n(double p1, double p2)
 * =>
 * swe_difdeg2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistance180: double
 * }
 */
NAN_METHOD(node_swe_difdeg2n) {
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double degreeDistance180;

	degreeDistance180 = ::swe_difdeg2n (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("degreeDistance180").ToLocalChecked(), Nan::New<Number> (degreeDistance180));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_difrad2n(double p1, double p2)
 * =>
 * swe_difrad2n(double p1, double p2[, function callback (result)]) = {
 *   degreeDistancePi: double
 * }
 */
NAN_METHOD(node_swe_difrad2n) {
	Nan::HandleScope scope;

	if (info.Length () < 2) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double degreeDistancePi;

	degreeDistancePi = ::swe_difrad2n (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("degreeDistancePi").ToLocalChecked(), Nan::New<Number> (degreeDistancePi));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * centisec swe_csroundsec(centisec x)
 * =>
 * swe_csroundsec(centisec x[, function callback (result)]) = {
 *   centisecRound: double
 * }
 */
NAN_METHOD(node_swe_csroundsec) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	int centisecRound;

	centisecRound = ::swe_csroundsec (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("centisecRound").ToLocalChecked(), Nan::New<Number> (centisecRound));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_d2l(double x)
 * =>
 * swe_d2l(double x[, function callback (result)]) = {
 *   xRound: int
 * }
 */
NAN_METHOD(node_swe_d2l) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	int xRound;

	xRound = ::swe_d2l (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("xRound").ToLocalChecked(), Nan::New<Number> (xRound));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int swe_day_of_week(double jd)
 * =>
 * swe_day_of_week(double jd[, function callback (result)]) = {
 *   dayOfWeek: int
 * }
 */
NAN_METHOD(node_swe_day_of_week) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	int dayOfWeek;

	dayOfWeek = ::swe_day_of_week (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("dayOfWeek").ToLocalChecked(), Nan::New<Number> (dayOfWeek));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero[, function callback (result)]) = {
 *   timeString: string
 * }
 */
NAN_METHOD(node_swe_cs2timestr) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	char timeString [AS_MAXCH] = {0};

	::swe_cs2timestr (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		timeString
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("timeString").ToLocalChecked(), Nan::New<String> (timeString).ToLocalChecked());

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s (out[AS_MAXCH]))
 * =>
 * swe_cs2lonlatstr(CSEC t, char pchar, char mchar[, function callback (result)]) = {
 *   lonlatString: string
 * }
 */
NAN_METHOD(node_swe_cs2lonlatstr) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsString () ||
		!info [2]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	char lonlatString [AS_MAXCH] = {0};

	::swe_cs2lonlatstr (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(* String::Utf8Value (Isolate::GetCurrent(), info [1]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0],
		(* String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0],
		lonlatString
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("lonlatString").ToLocalChecked(), Nan::New<String> (lonlatString).ToLocalChecked());

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * char * swe_cs2degstr(CSEC t, char *a (out[AS_MAXCH]))
 * =>
 * swe_cs2degstr(CSEC t[, function callback (result)]) = {
 *   degreeString: string
 * }
 */
NAN_METHOD(node_swe_cs2degstr) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	char degreeString [AS_MAXCH] = {0};

	::swe_cs2degstr (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		degreeString
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String>("degreeString").ToLocalChecked(), Nan::New<String>(degreeString).ToLocalChecked());

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

