#include "swisseph.h"

using namespace v8;

/**
 * int swe_houses(double tjd_ut, double geolat, double geolon, int hsys, double *cusps, double *ascmc)
 * =>
 * int swe_houses(double tjd_ut, double geolat, double geolon, string hsys) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   error: string
 * }
 */
void node_swe_houses (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	int rflag;

	Local <Object> result = Object::New (isolate);
	Local <Array> house = Array::New (isolate);

	rflag = ::swe_houses (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(* String::Utf8Value (args [3]->ToString ())) [0],
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, "Can't calculate houses."));
	} else {
		for (size_t i = 0; i < 12; i ++) {
			house->Set (Number::New (isolate, i), Number::New (isolate, cusps [i + 1]));
		};

		result->Set (String::NewFromUtf8 (isolate, "house"), house);
		result->Set (String::NewFromUtf8 (isolate, "ascendant"), Number::New (isolate, ascmc [SE_ASC]));
		result->Set (String::NewFromUtf8 (isolate, "mc"), Number::New (isolate, ascmc [SE_MC]));
		result->Set (String::NewFromUtf8 (isolate, "armc"), Number::New (isolate, ascmc [SE_ARMC]));
		result->Set (String::NewFromUtf8 (isolate, "vertex"), Number::New (isolate, ascmc [SE_VERTEX]));
		result->Set (String::NewFromUtf8 (isolate, "equatorialAscendant"), Number::New (isolate, ascmc [SE_COASC1]));
		result->Set (String::NewFromUtf8 (isolate, "kochCoAscendant"), Number::New (isolate, ascmc [SE_COASC2]));
		result->Set (String::NewFromUtf8 (isolate, "munkaseyCoAscendant"), Number::New (isolate, ascmc [SE_POLASC]));
		result->Set (String::NewFromUtf8 (isolate, "munkaseyPolarAscendant"), Number::New (isolate, ascmc [SE_NASCMC]));
	};

    HandleCallback (isolate, args, result);


};

/**
 * int swe_houses_ex(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc)
 * =>
 * int swe_houses_ex(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   error: string
 * }
 */
void node_swe_houses_ex (const FunctionCallbackInfo <Value> & args) {
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
		!args [4]->IsString ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	int rflag;

	Local <Object> result = Object::New (isolate);
	Local <Array> house = Array::New (isolate);

	rflag = ::swe_houses_ex (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		args [2]->NumberValue (),
		args [3]->NumberValue (),
		(* String::Utf8Value (args [4]->ToString ())) [0],
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, "Can't calculate houses."));
	} else {
		for (size_t i = 0; i < 12; i ++) {
			house->Set (Number::New (isolate, i), Number::New (isolate, cusps [i + 1]));
		};

		result->Set (String::NewFromUtf8 (isolate, "house"), house);
		result->Set (String::NewFromUtf8 (isolate, "ascendant"), Number::New (isolate, ascmc [SE_ASC]));
		result->Set (String::NewFromUtf8 (isolate, "mc"), Number::New (isolate, ascmc [SE_MC]));
		result->Set (String::NewFromUtf8 (isolate, "armc"), Number::New (isolate, ascmc [SE_ARMC]));
		result->Set (String::NewFromUtf8 (isolate, "vertex"), Number::New (isolate, ascmc [SE_VERTEX]));
		result->Set (String::NewFromUtf8 (isolate, "equatorialAscendant"), Number::New (isolate, ascmc [SE_COASC1]));
		result->Set (String::NewFromUtf8 (isolate, "kochCoAscendant"), Number::New (isolate, ascmc [SE_COASC2]));
		result->Set (String::NewFromUtf8 (isolate, "munkaseyCoAscendant"), Number::New (isolate, ascmc [SE_POLASC]));
		result->Set (String::NewFromUtf8 (isolate, "munkaseyPolarAscendant"), Number::New (isolate, ascmc [SE_NASCMC]));
	};

    HandleCallback (isolate, args, result);


};

/**
 * int swe_houses_armc(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc)
 * =>
 * int swe_houses_armc(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   error: string
 * }
 */
void node_swe_houses_armc (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	int rflag;

	Local <Object> result = Object::New (isolate);
	Local <Array> house = Array::New (isolate);

	rflag = ::swe_houses (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(* String::Utf8Value (args [3]->ToString ())) [0],
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, "Can't calculate houses."));
	} else {
		for (size_t i = 0; i < 12; i ++) {
			house->Set (Number::New (isolate, i), Number::New (isolate, cusps [i + 1]));
		};

		result->Set (String::NewFromUtf8 (isolate, "house"), house);
		result->Set (String::NewFromUtf8 (isolate, "ascendant"), Number::New (isolate, ascmc [SE_ASC]));
		result->Set (String::NewFromUtf8 (isolate, "mc"), Number::New (isolate, ascmc [SE_MC]));
		result->Set (String::NewFromUtf8 (isolate, "armc"), Number::New (isolate, ascmc [SE_ARMC]));
		result->Set (String::NewFromUtf8 (isolate, "vertex"), Number::New (isolate, ascmc [SE_VERTEX]));
		result->Set (String::NewFromUtf8 (isolate, "equatorialAscendant"), Number::New (isolate, ascmc [SE_COASC1]));
		result->Set (String::NewFromUtf8 (isolate, "kochCoAscendant"), Number::New (isolate, ascmc [SE_COASC2]));
		result->Set (String::NewFromUtf8 (isolate, "munkaseyCoAscendant"), Number::New (isolate, ascmc [SE_POLASC]));
		result->Set (String::NewFromUtf8 (isolate, "munkaseyPolarAscendant"), Number::New (isolate, ascmc [SE_NASCMC]));
	};

    HandleCallback (isolate, args, result);


};

/**
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double *xpin, char *serr)
 * =>
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double lon, double lat) {
 *   housePosition: double,
 *   error: string
 * }
 */
void node_swe_houses_pos (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 6) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	double xpin [2] = {args [4]->NumberValue (), args [5]->NumberValue ()};
	char serr [AS_MAXCH];
	double rflag;

	Local <Object> result = Object::New (isolate);
	Local <Array> house = Array::New (isolate);

	rflag = ::swe_house_pos (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(* String::Utf8Value (args [3]->ToString ())) [0],
		xpin, serr
	);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, "Can't calculate houses."));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "housePosition"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


};
