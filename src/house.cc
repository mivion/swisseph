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
	Nan::HandleScope scope;

	if (info.Length () < 4) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double cusps [40] = {0};
	double ascmc [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;

	Local <Object> result = Nan::New<Object> ();
	Local <Array> house = Nan::New<Array> ();

	hsys = (* String::Utf8Value (info [3]->ToString ())) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}

	rflag = ::swe_houses (
		info [0]->NumberValue (),
		info [1]->NumberValue (),
		info [2]->NumberValue (),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			house->Set (Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
		};

		result->Set (Nan::New<String> ("house").ToLocalChecked(), house);
		result->Set (Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		result->Set (Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		result->Set (Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		result->Set (Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		result->Set (Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		result->Set (Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		result->Set (Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));
		result->Set (Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_NASCMC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
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
	Nan::HandleScope scope;

	if (info.Length () < 5) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber () ||
		!info [4]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double cusps [40] = {0};
	double ascmc [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;

	Local <Object> result = Nan::New<Object> ();
	Local <Array> house = Nan::New<Array> ();

	hsys = (* String::Utf8Value (info [4]->ToString ())) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}

	rflag = ::swe_houses_ex (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		info [2]->NumberValue (),
		info [3]->NumberValue (),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			house->Set (Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
		};

		result->Set (Nan::New<String> ("house").ToLocalChecked(), house);
		result->Set (Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		result->Set (Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		result->Set (Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		result->Set (Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		result->Set (Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		result->Set (Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		result->Set (Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));
		result->Set (Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_NASCMC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
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
	Nan::HandleScope scope;

	if (info.Length () < 4) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double cusps [40] = {0};
	double ascmc [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;

	Local <Object> result = Nan::New<Object> ();
	Local <Array> house = Nan::New<Array> ();

	hsys = (* String::Utf8Value (info [3]->ToString ())) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}
	
	rflag = ::swe_houses (
		info [0]->NumberValue (),
		info [1]->NumberValue (),
		info [2]->NumberValue (),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			house->Set (Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
		};

		result->Set (Nan::New<String> ("house").ToLocalChecked(), house);
		result->Set (Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		result->Set (Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		result->Set (Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		result->Set (Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		result->Set (Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		result->Set (Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		result->Set (Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));
		result->Set (Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_NASCMC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
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
	Nan::HandleScope scope;

	if (info.Length () < 6) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsString () ||
		!info [4]->IsNumber () ||
		!info [5]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double xpin [2] = {info [4]->NumberValue (), info [5]->NumberValue ()};
	char serr [AS_MAXCH];
	double rflag;

	Local <Object> result = Nan::New<Object> ();

	rflag = ::swe_house_pos (
		info [0]->NumberValue (),
		info [1]->NumberValue (),
		info [2]->NumberValue (),
		(* String::Utf8Value (info [3]->ToString ())) [0],
		xpin, serr
	);

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("housePosition").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};
