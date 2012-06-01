#define BUILDING_NODE_EXTENSION

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
Handle <Value> node_swe_date_conversion (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 5) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		(!args [4]->IsString () && args [4]->ToString ()->Length () > 0)
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double tjd;
	int rflag;

	Local <Object> result = Object::New ();

	rflag = ::swe_date_conversion (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		args [3]->NumberValue (),
		(* String::AsciiValue (args [4]->ToString ())) [0],
		&tjd
	);

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New ("Input date is illegal."));
	} else {
		result->Set (String::NewSymbol ("julianDay"), Number::New (tjd));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * swe_julday(int year, int month, int day, double hour, int gregflag[, function callback (result)])
 */
Handle <Value> node_swe_julday (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 5) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	Local <Number> result = Number::New (::swe_julday (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		args [3]->NumberValue (),
		(int)args [4]->NumberValue ()
	));

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_revjul (const Arguments & args) {
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

	double hour;
	int year, month, day;

	Local <Object> result = Object::New ();

	::swe_revjul (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour
	);

	result->Set (String::NewSymbol ("year"), Number::New (year));
	result->Set (String::NewSymbol ("month"), Number::New (month));
	result->Set (String::NewSymbol ("day"), Number::New (day));
	result->Set (String::NewSymbol ("hour"), Number::New (hour));

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_utc_to_jd (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 7) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
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
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double tjd [2];
	char serr [AS_MAXCH];
	int rflag;

	Local <Object> result = Object::New ();

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
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("julianDayUT"), Number::New (tjd [0]));
		result->Set (String::NewSymbol ("julianDayET"), Number::New (tjd [1]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_jdet_to_utc (const Arguments & args) {
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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Object::New ();

	::swe_jdet_to_utc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour, &minute, &second
	);

	result->Set (String::NewSymbol ("year"), Number::New (year));
	result->Set (String::NewSymbol ("month"), Number::New (month));
	result->Set (String::NewSymbol ("day"), Number::New (day));
	result->Set (String::NewSymbol ("hour"), Number::New (hour));
	result->Set (String::NewSymbol ("minute"), Number::New (minute));
	result->Set (String::NewSymbol ("second"), Number::New (second));

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_jdut1_to_utc (const Arguments & args) {
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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Object::New ();

	::swe_jdut1_to_utc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour, &minute, &second
	);

	result->Set (String::NewSymbol ("year"), Number::New (year));
	result->Set (String::NewSymbol ("month"), Number::New (month));
	result->Set (String::NewSymbol ("day"), Number::New (day));
	result->Set (String::NewSymbol ("hour"), Number::New (hour));
	result->Set (String::NewSymbol ("minute"), Number::New (minute));
	result->Set (String::NewSymbol ("second"), Number::New (second));

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_utc_time_zone (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 7) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
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
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Object::New ();

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

	result->Set (String::NewSymbol ("year"), Number::New (year));
	result->Set (String::NewSymbol ("month"), Number::New (month));
	result->Set (String::NewSymbol ("day"), Number::New (day));
	result->Set (String::NewSymbol ("hour"), Number::New (hour));
	result->Set (String::NewSymbol ("minute"), Number::New (minute));
	result->Set (String::NewSymbol ("second"), Number::New (second));

    HandleCallback (args, result);

	return scope.Close (result);
};
