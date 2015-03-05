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
NAN_METHOD(node_swe_date_conversion) {
	    NanScope();

	if (args.Length () < 5) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		(!args [4]->IsString () && args [4]->ToString ()->Length () > 0)
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double tjd;
	int rflag;

	Local <Object> result = NanNew<Object> ();

	rflag = ::swe_date_conversion (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		args [3]->NumberValue (),
		(* String::Utf8Value (args [4]->ToString ())) [0],
		&tjd
	);

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> ("Input date is illegal."));
	} else {
		result->Set (NanNew<String> ("julianDay"), NanNew<Number> (tjd));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * swe_julday(int year, int month, int day, double hour, int gregflag[, function callback (result)])
 */
NAN_METHOD(node_swe_julday) {
	NanScope();

	if (args.Length () < 5) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	Local <Number> result = NanNew<Number> (::swe_julday (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		args [3]->NumberValue (),
		(int)args [4]->NumberValue ()
	));

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_revjul) {
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

	double hour;
	int year, month, day;

	Local <Object> result = NanNew<Object> ();

	::swe_revjul (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour
	);

	result->Set (NanNew<String> ("year"), NanNew<Number> (year));
	result->Set (NanNew<String> ("month"), NanNew<Number> (month));
	result->Set (NanNew<String> ("day"), NanNew<Number> (day));
	result->Set (NanNew<String> ("hour"), NanNew<Number> (hour));

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_utc_to_jd) {
	NanScope();

	if (args.Length () < 7) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
	};

	double tjd [2];
	char serr [AS_MAXCH];
	int rflag;

	Local <Object> result = NanNew<Object> ();

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
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("julianDayUT"), NanNew<Number> (tjd [0]));
		result->Set (NanNew<String> ("julianDayET"), NanNew<Number> (tjd [1]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_jdet_to_utc) {
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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = NanNew<Object> ();

	::swe_jdet_to_utc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour, &minute, &second
	);

	result->Set (NanNew<String> ("year"), NanNew<Number> (year));
	result->Set (NanNew<String> ("month"), NanNew<Number> (month));
	result->Set (NanNew<String> ("day"), NanNew<Number> (day));
	result->Set (NanNew<String> ("hour"), NanNew<Number> (hour));
	result->Set (NanNew<String> ("minute"), NanNew<Number> (minute));
	result->Set (NanNew<String> ("second"), NanNew<Number> (second));

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_jdut1_to_utc) {
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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = NanNew<Object> ();

	::swe_jdut1_to_utc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		&year, &month, &day, &hour, &minute, &second
	);

	result->Set (NanNew<String> ("year"), NanNew<Number> (year));
	result->Set (NanNew<String> ("month"), NanNew<Number> (month));
	result->Set (NanNew<String> ("day"), NanNew<Number> (day));
	result->Set (NanNew<String> ("hour"), NanNew<Number> (hour));
	result->Set (NanNew<String> ("minute"), NanNew<Number> (minute));
	result->Set (NanNew<String> ("second"), NanNew<Number> (second));

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_utc_time_zone) {
	NanScope();

	if (args.Length () < 7) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
	};

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = NanNew<Object> ();

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

	result->Set (NanNew<String> ("year"), NanNew<Number> (year));
	result->Set (NanNew<String> ("month"), NanNew<Number> (month));
	result->Set (NanNew<String> ("day"), NanNew<Number> (day));
	result->Set (NanNew<String> ("hour"), NanNew<Number> (hour));
	result->Set (NanNew<String> ("minute"), NanNew<Number> (minute));
	result->Set (NanNew<String> ("second"), NanNew<Number> (second));

    HandleCallback (args, result);
    NanReturnValue (result);
};
