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
NAN_METHOD(node_swe_houses) {
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double cusps [40] = {0};
	double ascmc [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;

	Local <Object> result = NanNew<Object> ();
	Local <Array> house = NanNew<Array> ();

	hsys = (* String::Utf8Value (args [3]->ToString ())) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}

	rflag = ::swe_houses (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> ("Can't calculate houses."));
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			house->Set (NanNew<Number> (i), NanNew<Number> (cusps [i + 1]));
		};

		result->Set (NanNew<String> ("house"), house);
		result->Set (NanNew<String> ("ascendant"), NanNew<Number> (ascmc [SE_ASC]));
		result->Set (NanNew<String> ("mc"), NanNew<Number> (ascmc [SE_MC]));
		result->Set (NanNew<String> ("armc"), NanNew<Number> (ascmc [SE_ARMC]));
		result->Set (NanNew<String> ("vertex"), NanNew<Number> (ascmc [SE_VERTEX]));
		result->Set (NanNew<String> ("equatorialAscendant"), NanNew<Number> (ascmc [SE_COASC1]));
		result->Set (NanNew<String> ("kochCoAscendant"), NanNew<Number> (ascmc [SE_COASC2]));
		result->Set (NanNew<String> ("munkaseyCoAscendant"), NanNew<Number> (ascmc [SE_POLASC]));
		result->Set (NanNew<String> ("munkaseyPolarAscendant"), NanNew<Number> (ascmc [SE_NASCMC]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_houses_ex) {
	NanScope();

	if (args.Length () < 5) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsString ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double cusps [40] = {0};
	double ascmc [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;

	Local <Object> result = NanNew<Object> ();
	Local <Array> house = NanNew<Array> ();

	hsys = (* String::Utf8Value (args [4]->ToString ())) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}

	rflag = ::swe_houses_ex (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		args [2]->NumberValue (),
		args [3]->NumberValue (),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> ("Can't calculate houses."));
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			house->Set (NanNew<Number> (i), NanNew<Number> (cusps [i + 1]));
		};

		result->Set (NanNew<String> ("house"), house);
		result->Set (NanNew<String> ("ascendant"), NanNew<Number> (ascmc [SE_ASC]));
		result->Set (NanNew<String> ("mc"), NanNew<Number> (ascmc [SE_MC]));
		result->Set (NanNew<String> ("armc"), NanNew<Number> (ascmc [SE_ARMC]));
		result->Set (NanNew<String> ("vertex"), NanNew<Number> (ascmc [SE_VERTEX]));
		result->Set (NanNew<String> ("equatorialAscendant"), NanNew<Number> (ascmc [SE_COASC1]));
		result->Set (NanNew<String> ("kochCoAscendant"), NanNew<Number> (ascmc [SE_COASC2]));
		result->Set (NanNew<String> ("munkaseyCoAscendant"), NanNew<Number> (ascmc [SE_POLASC]));
		result->Set (NanNew<String> ("munkaseyPolarAscendant"), NanNew<Number> (ascmc [SE_NASCMC]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_houses_armc) {
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double cusps [40] = {0};
	double ascmc [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;

	Local <Object> result = NanNew<Object> ();
	Local <Array> house = NanNew<Array> ();

	hsys = (* String::Utf8Value (args [3]->ToString ())) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}
	
	rflag = ::swe_houses (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> ("Can't calculate houses."));
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			house->Set (NanNew<Number> (i), NanNew<Number> (cusps [i + 1]));
		};

		result->Set (NanNew<String> ("house"), house);
		result->Set (NanNew<String> ("ascendant"), NanNew<Number> (ascmc [SE_ASC]));
		result->Set (NanNew<String> ("mc"), NanNew<Number> (ascmc [SE_MC]));
		result->Set (NanNew<String> ("armc"), NanNew<Number> (ascmc [SE_ARMC]));
		result->Set (NanNew<String> ("vertex"), NanNew<Number> (ascmc [SE_VERTEX]));
		result->Set (NanNew<String> ("equatorialAscendant"), NanNew<Number> (ascmc [SE_COASC1]));
		result->Set (NanNew<String> ("kochCoAscendant"), NanNew<Number> (ascmc [SE_COASC2]));
		result->Set (NanNew<String> ("munkaseyCoAscendant"), NanNew<Number> (ascmc [SE_POLASC]));
		result->Set (NanNew<String> ("munkaseyPolarAscendant"), NanNew<Number> (ascmc [SE_NASCMC]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double *xpin, char *serr)
 * =>
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double lon, double lat) {
 *   housePosition: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses_pos) {
	NanScope();

	if (args.Length () < 6) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsString () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double xpin [2] = {args [4]->NumberValue (), args [5]->NumberValue ()};
	char serr [AS_MAXCH];
	double rflag;

	Local <Object> result = NanNew<Object> ();

	rflag = ::swe_house_pos (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(* String::Utf8Value (args [3]->ToString ())) [0],
		xpin, serr
	);

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> ("Can't calculate houses."));
	} else {
		result->Set (NanNew<String> ("housePosition"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
};
