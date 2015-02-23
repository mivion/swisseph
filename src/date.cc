#include "swisseph.h"

using namespace v8;

/**
 * int swe_date_conversion(int y , int m , int d , double utime, char c, double *tjd)
 * =>
 * swe_date_conversion(int year, int month, int day, double hour, char c[, function callback (result)]) = {
 *   julianDay: double,
 *   error: string
 * }
 */
void node_swe_date_conversion (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent ();
	HandleScope scope (isolate);

	if (args.Length () < 5) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		(!args [4]->IsString () && args [4]->ToString ()->Length () > 0)
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double tjd;
	int rflag;

	Local <Object> result = Object::New (isolate);

	rflag = ::swe_date_conversion (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		args [3]->NumberValue (),
		(* String::Utf8Value (args [4]->ToString ())) [0],
		&tjd
	);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, "Input date is illegal."));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "julianDay"), Number::New (isolate, tjd));
	};

    HandleCallback (isolate, args, result);


};

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * swe_julday(int year, int month, int day, double hour, int gregflag[, function callback (result)])
 */
void node_swe_julday (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 5) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	Local <Number> result = Number::New (isolate, ::swe_julday (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		args [3]->NumberValue (),
		(int)args [4]->NumberValue ()
	));

    HandleCallback (isolate, args, result);


};

/**
 * void swe_revjul (double jd, int gregflag, int *jyear, int *jmon, int *jday, double *jut)
 * =>
 * swe_revjul (double jd, int gregflag) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: double
 * }
 */
void node_swe_revjul (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

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

	double hour;
	int year, month, day;

	Local <Object> result = Object::New (isolate);

	::swe_revjul (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour
	);

	result->Set (String::NewFromUtf8 (isolate, "year"), Number::New (isolate, year));
	result->Set (String::NewFromUtf8 (isolate, "month"), Number::New (isolate, month));
	result->Set (String::NewFromUtf8 (isolate, "day"), Number::New (isolate, day));
	result->Set (String::NewFromUtf8 (isolate, "hour"), Number::New (isolate, hour));

    HandleCallback (isolate, args, result);


};

/**
 * int32 swe_utc_to_jd(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, int32 gregflag, double *dret, char *serr)
 * =>
 * swe_utc_to_jd(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, int32 gregflag) {
 *   julianDayUT: double,
 *   julianDayET: double,
 *   error: string
 * }
 */
void node_swe_utc_to_jd (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 7) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double tjd [2];
	char serr [AS_MAXCH];
	int rflag;

	Local <Object> result = Object::New (isolate);

	rflag = ::swe_utc_to_jd (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		(int)args [3]->NumberValue (),
		(int)args [4]->NumberValue (),
		args [5]->NumberValue (),
		(int)args [6]->NumberValue (),
		tjd, serr
	);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "julianDayUT"), Number::New (isolate, tjd [0]));
		result->Set (String::NewFromUtf8 (isolate, "julianDayET"), Number::New (isolate, tjd [1]));
	};

    HandleCallback (isolate, args, result);


};

/**
 * void swe_jdet_to_utc(double tjd_et, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * swe_jdet_to_utc(double tjd_et, int32 gregflag) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   min: int,
 *   second: double
 * }
 */
void node_swe_jdet_to_utc (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Object::New (isolate);

	::swe_jdet_to_utc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour, &minute, &second
	);

	result->Set (String::NewFromUtf8 (isolate, "year"), Number::New (isolate, year));
	result->Set (String::NewFromUtf8 (isolate, "month"), Number::New (isolate, month));
	result->Set (String::NewFromUtf8 (isolate, "day"), Number::New (isolate, day));
	result->Set (String::NewFromUtf8 (isolate, "hour"), Number::New (isolate, hour));
	result->Set (String::NewFromUtf8 (isolate, "minute"), Number::New (isolate, minute));
	result->Set (String::NewFromUtf8 (isolate, "second"), Number::New (isolate, second));

    HandleCallback (isolate, args, result);


};

/**
 * void swe_jdut1_to_utc(double tjd_et, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * swe_jdut1_to_utc(double tjd_et, int32 gregflag) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   min: int,
 *   second: double
 * }
 */
void node_swe_jdut1_to_utc (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Object::New (isolate);

	::swe_jdut1_to_utc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour, &minute, &second
	);

	result->Set (String::NewFromUtf8 (isolate, "year"), Number::New (isolate, year));
	result->Set (String::NewFromUtf8 (isolate, "month"), Number::New (isolate, month));
	result->Set (String::NewFromUtf8 (isolate, "day"), Number::New (isolate, day));
	result->Set (String::NewFromUtf8 (isolate, "hour"), Number::New (isolate, hour));
	result->Set (String::NewFromUtf8 (isolate, "minute"), Number::New (isolate, minute));
	result->Set (String::NewFromUtf8 (isolate, "second"), Number::New (isolate, second));

    HandleCallback (isolate, args, result);


};

/**
 * void swe_utc_time_zone(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, double d_timezone, int32 *iyear_out, int32 *imonth_out, int32 *iday_out, int32 *ihour_out, int32 *imin_out, double *dsec_out)
 * =>
 * swe_utc_time_zone(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, double d_timezone) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   min: int,
 *   second: double
 * }
 */
void node_swe_utc_time_zone (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 7) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Object::New (isolate);

	::swe_utc_time_zone (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		(int)args [3]->NumberValue (),
		(int)args [4]->NumberValue (),
		args [5]->NumberValue (),
		args [6]->NumberValue (),
		&year, &month, &day, &hour, &minute, &second
	);

	result->Set (String::NewFromUtf8 (isolate, "year"), Number::New (isolate, year));
	result->Set (String::NewFromUtf8 (isolate, "month"), Number::New (isolate, month));
	result->Set (String::NewFromUtf8 (isolate, "day"), Number::New (isolate, day));
	result->Set (String::NewFromUtf8 (isolate, "hour"), Number::New (isolate, hour));
	result->Set (String::NewFromUtf8 (isolate, "minute"), Number::New (isolate, minute));
	result->Set (String::NewFromUtf8 (isolate, "second"), Number::New (isolate, second));

    HandleCallback (isolate, args, result);


};
