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
	    Nan::HandleScope scope;

	if (info.Length () < 5) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber () ||
		(!info [4]->IsString () && info [4]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())->Length () > 0)
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double tjd;
	int rflag;

	Local <Object> result = Nan::New<Object> ();

	rflag = ::swe_date_conversion (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(* String::Utf8Value (Isolate::GetCurrent(), info [4]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0],
		&tjd
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Input date is illegal.").ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("julianDay").ToLocalChecked(), Nan::New<Number> (tjd));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * swe_julday(int year, int month, int day, double hour, int gregflag[, function callback (result)]) = double
 */
NAN_METHOD(node_swe_julday) {
	Nan::HandleScope scope;

	if (info.Length () < 5) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber () ||
		!info [4]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	Local <Number> result = Nan::New<Number> (::swe_julday (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_revjul (double jd, int gregflag, int *jyear, int *jmon, int *jday, double *jut)
 * =>
 * swe_revjul (double jd, int gregflag[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: double
 * }
 */
NAN_METHOD(node_swe_revjul) {
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

	double hour;
	int year, month, day;

	Local <Object> result = Nan::New<Object> ();

	::swe_revjul (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&year, &month, &day, &hour
	);

	Nan::Set(result,Nan::New<String> ("year").ToLocalChecked(), Nan::New<Number> (year));
	Nan::Set(result,Nan::New<String> ("month").ToLocalChecked(), Nan::New<Number> (month));
	Nan::Set(result,Nan::New<String> ("day").ToLocalChecked(), Nan::New<Number> (day));
	Nan::Set(result,Nan::New<String> ("hour").ToLocalChecked(), Nan::New<Number> (hour));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_utc_to_jd(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, int32 gregflag, double *dret, char *serr)
 * =>
 * swe_utc_to_jd(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, int32 gregflag[, function callback (result)]) = {
 *   julianDayET: double,
 *   julianDayUT: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_utc_to_jd) {
	Nan::HandleScope scope;

	if (info.Length () < 7) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber () ||
		!info [4]->IsNumber () ||
		!info [5]->IsNumber () ||
		!info [6]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double tjd [2];
	char serr [AS_MAXCH];
	int rflag;

	Local <Object> result = Nan::New<Object> ();

	rflag = ::swe_utc_to_jd (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		tjd, serr
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("julianDayET").ToLocalChecked(), Nan::New<Number> (tjd [0]));
		Nan::Set(result,Nan::New<String> ("julianDayUT").ToLocalChecked(), Nan::New<Number> (tjd [1]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_jdet_to_utc(double tjd_et, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * swe_jdet_to_utc(double tjd_et, int32 gregflag[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   minute: int,
 *   second: double
 * }
 */
NAN_METHOD(node_swe_jdet_to_utc) {
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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Nan::New<Object> ();

	::swe_jdet_to_utc (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&year, &month, &day, &hour, &minute, &second
	);

	Nan::Set(result,Nan::New<String> ("year").ToLocalChecked(), Nan::New<Number> (year));
	Nan::Set(result,Nan::New<String> ("month").ToLocalChecked(), Nan::New<Number> (month));
	Nan::Set(result,Nan::New<String> ("day").ToLocalChecked(), Nan::New<Number> (day));
	Nan::Set(result,Nan::New<String> ("hour").ToLocalChecked(), Nan::New<Number> (hour));
	Nan::Set(result,Nan::New<String> ("minute").ToLocalChecked(), Nan::New<Number> (minute));
	Nan::Set(result,Nan::New<String> ("second").ToLocalChecked(), Nan::New<Number> (second));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_jdut1_to_utc(double tjd_ut, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * swe_jdut1_to_utc(double tjd_ut, int32 gregflag[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   minute: int,
 *   second: double
 * }
 */
NAN_METHOD(node_swe_jdut1_to_utc) {
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

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Nan::New<Object> ();

	::swe_jdut1_to_utc (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&year, &month, &day, &hour, &minute, &second
	);

	Nan::Set(result,Nan::New<String> ("year").ToLocalChecked(), Nan::New<Number> (year));
	Nan::Set(result,Nan::New<String> ("month").ToLocalChecked(), Nan::New<Number> (month));
	Nan::Set(result,Nan::New<String> ("day").ToLocalChecked(), Nan::New<Number> (day));
	Nan::Set(result,Nan::New<String> ("hour").ToLocalChecked(), Nan::New<Number> (hour));
	Nan::Set(result,Nan::New<String> ("minute").ToLocalChecked(), Nan::New<Number> (minute));
	Nan::Set(result,Nan::New<String> ("second").ToLocalChecked(), Nan::New<Number> (second));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_utc_time_zone(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, double d_timezone, int32 *iyear_out, int32 *imonth_out, int32 *iday_out, int32 *ihour_out, int32 *imin_out, double *dsec_out)
 * =>
 * swe_utc_time_zone(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, double d_timezone[, function callback (result)]) = {
 *   year: int,
 *   month: int,
 *   day: int,
 *   hour: int,
 *   minute: int,
 *   second: double
 * }
 */
NAN_METHOD(node_swe_utc_time_zone) {
	Nan::HandleScope scope;

	if (info.Length () < 7) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber () ||
		!info [4]->IsNumber () ||
		!info [5]->IsNumber () ||
		!info [6]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double second;
	int year, month, day, hour, minute;

	Local <Object> result = Nan::New<Object> ();

	::swe_utc_time_zone (
		(int)info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&year, &month, &day, &hour, &minute, &second
	);

	Nan::Set(result,Nan::New<String> ("year").ToLocalChecked(), Nan::New<Number> (year));
	Nan::Set(result,Nan::New<String> ("month").ToLocalChecked(), Nan::New<Number> (month));
	Nan::Set(result,Nan::New<String> ("day").ToLocalChecked(), Nan::New<Number> (day));
	Nan::Set(result,Nan::New<String> ("hour").ToLocalChecked(), Nan::New<Number> (hour));
	Nan::Set(result,Nan::New<String> ("minute").ToLocalChecked(), Nan::New<Number> (minute));
	Nan::Set(result,Nan::New<String> ("second").ToLocalChecked(), Nan::New<Number> (second));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};
