#define BUILDING_NODE_EXTENSION

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
Handle <Value> node_swe_houses (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	int rflag;

	Local <Object> result = Object::New ();
	Local <Array> house = Array::New ();

	rflag = ::swe_houses (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(* String::AsciiValue (args [3]->ToString ())) [0],
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New ("Can't calculate houses."));
	} else {
		for (size_t i = 0; i < 12; i ++) {
			house->Set (Number::New (i), Number::New (cusps [i + 1]));
		};

		result->Set (String::NewSymbol ("house"), house);
		result->Set (String::NewSymbol ("ascendant"), Number::New (ascmc [SE_ASC]));
		result->Set (String::NewSymbol ("mc"), Number::New (ascmc [SE_MC]));
		result->Set (String::NewSymbol ("armc"), Number::New (ascmc [SE_ARMC]));
		result->Set (String::NewSymbol ("vertex"), Number::New (ascmc [SE_VERTEX]));
		result->Set (String::NewSymbol ("equatorialAscendant"), Number::New (ascmc [SE_COASC1]));
		result->Set (String::NewSymbol ("kochCoAscendant"), Number::New (ascmc [SE_COASC2]));
		result->Set (String::NewSymbol ("munkaseyCoAscendant"), Number::New (ascmc [SE_POLASC]));
		result->Set (String::NewSymbol ("munkaseyPolarAscendant"), Number::New (ascmc [SE_NASCMC]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_houses_ex (const Arguments & args) {
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
		!args [4]->IsString ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	int rflag;

	Local <Object> result = Object::New ();
	Local <Array> house = Array::New ();

	rflag = ::swe_houses_ex (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		args [2]->NumberValue (),
		args [3]->NumberValue (),
		(* String::AsciiValue (args [4]->ToString ())) [0],
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New ("Can't calculate houses."));
	} else {
		for (size_t i = 0; i < 12; i ++) {
			house->Set (Number::New (i), Number::New (cusps [i + 1]));
		};

		result->Set (String::NewSymbol ("house"), house);
		result->Set (String::NewSymbol ("ascendant"), Number::New (ascmc [SE_ASC]));
		result->Set (String::NewSymbol ("mc"), Number::New (ascmc [SE_MC]));
		result->Set (String::NewSymbol ("armc"), Number::New (ascmc [SE_ARMC]));
		result->Set (String::NewSymbol ("vertex"), Number::New (ascmc [SE_VERTEX]));
		result->Set (String::NewSymbol ("equatorialAscendant"), Number::New (ascmc [SE_COASC1]));
		result->Set (String::NewSymbol ("kochCoAscendant"), Number::New (ascmc [SE_COASC2]));
		result->Set (String::NewSymbol ("munkaseyCoAscendant"), Number::New (ascmc [SE_POLASC]));
		result->Set (String::NewSymbol ("munkaseyPolarAscendant"), Number::New (ascmc [SE_NASCMC]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_houses_armc (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	int rflag;

	Local <Object> result = Object::New ();
	Local <Array> house = Array::New ();

	rflag = ::swe_houses (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(* String::AsciiValue (args [3]->ToString ())) [0],
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New ("Can't calculate houses."));
	} else {
		for (size_t i = 0; i < 12; i ++) {
			house->Set (Number::New (i), Number::New (cusps [i + 1]));
		};

		result->Set (String::NewSymbol ("house"), house);
		result->Set (String::NewSymbol ("ascendant"), Number::New (ascmc [SE_ASC]));
		result->Set (String::NewSymbol ("mc"), Number::New (ascmc [SE_MC]));
		result->Set (String::NewSymbol ("armc"), Number::New (ascmc [SE_ARMC]));
		result->Set (String::NewSymbol ("vertex"), Number::New (ascmc [SE_VERTEX]));
		result->Set (String::NewSymbol ("equatorialAscendant"), Number::New (ascmc [SE_COASC1]));
		result->Set (String::NewSymbol ("kochCoAscendant"), Number::New (ascmc [SE_COASC2]));
		result->Set (String::NewSymbol ("munkaseyCoAscendant"), Number::New (ascmc [SE_POLASC]));
		result->Set (String::NewSymbol ("munkaseyPolarAscendant"), Number::New (ascmc [SE_NASCMC]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double *xpin, char *serr)
 * =>
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double lon, double lat) {
 *   housePosition: double,
 *   error: string
 * }
 */
Handle <Value> node_swe_houses_pos (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 6) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double cusps [20] = {0};
	double ascmc [40] = {0};
	double xpin [2] = {args [4]->NumberValue (), args [5]->NumberValue ()};
	char serr [AS_MAXCH];
	double rflag;

	Local <Object> result = Object::New ();
	Local <Array> house = Array::New ();

	rflag = ::swe_house_pos (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(* String::AsciiValue (args [3]->ToString ())) [0],
		xpin, serr
	);

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New ("Can't calculate houses."));
	} else {
		result->Set (String::NewSymbol ("housePosition"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};
