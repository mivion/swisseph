#include "swisseph.h"

using namespace v8;

/**
 * int swe_houses(double tjd_ut, double geolat, double geolon, string hsys, double *cusps, double *ascmc)
 * =>
 * swe_houses(double tjd_ut, double geolat, double geolon, string hsys[, function callback (result)]) = {
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

	hsys = (* String::Utf8Value (Isolate::GetCurrent(), info [3]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}

	rflag = ::swe_houses (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			Nan::Set(house,Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
		};

		Nan::Set(result,Nan::New<String> ("house").ToLocalChecked(), house);
		Nan::Set(result,Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		Nan::Set(result,Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		Nan::Set(result,Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		Nan::Set(result,Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		Nan::Set(result,Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_EQUASC]));
		Nan::Set(result,Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		Nan::Set(result,Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		Nan::Set(result,Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int swe_houses_ex(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc)
 * =>
 * swe_houses_ex(double tjd_ut, int32 iflag, double geolat, double geolon, string hsys[, function callback (result)]) = {
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

	hsys = (* String::Utf8Value (Isolate::GetCurrent(), info [4]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}

	rflag = ::swe_houses_ex (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			Nan::Set(house,Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
		};

		Nan::Set(result,Nan::New<String> ("house").ToLocalChecked(), house);
		Nan::Set(result,Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		Nan::Set(result,Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		Nan::Set(result,Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		Nan::Set(result,Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		Nan::Set(result,Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_EQUASC]));
		Nan::Set(result,Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		Nan::Set(result,Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		Nan::Set(result,Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int swe_houses_ex2(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr)
 * =>
 * swe_houses_ex2(double tjd_ut, int32 iflag, double geolat, double geolon, string hsys[, function callback (result)]) = {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   houseSpeed: [double],
 *   ascendantSpeed: double,
 *   mcSpeed: double,
 *   armcSpeed: double,
 *   vertexSpeed: double,
 *   equatorialAscendantSpeed: double,
 *   kochCoAscendantSpeed: double,
 *   munkaseyCoAscendantSpeed: double,
 *   munkaseyPolarAscendantSpeed: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses_ex2) {
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
	double cusps_speed [40] = {0};
	double ascmc_speed [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;
	char serr [AS_MAXCH];

	Local <Object> result = Nan::New<Object> ();
	Local <Array> house = Nan::New<Array> ();
	Local <Array> houseSpeed = Nan::New<Array> ();

	hsys = (* String::Utf8Value (Isolate::GetCurrent(), info [4]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}

	rflag = ::swe_houses_ex2 (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		hsys,
		cusps, ascmc, cusps_speed, ascmc_speed,
		serr
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("message").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			Nan::Set(house,Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
			Nan::Set(houseSpeed,Nan::New<Number> (i), Nan::New<Number> (cusps_speed [i + 1]));
		};

		Nan::Set(result,Nan::New<String> ("house").ToLocalChecked(), house);
		Nan::Set(result,Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		Nan::Set(result,Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		Nan::Set(result,Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		Nan::Set(result,Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		Nan::Set(result,Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_EQUASC]));
		Nan::Set(result,Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		Nan::Set(result,Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		Nan::Set(result,Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));

		Nan::Set(result,Nan::New<String> ("houseSpeed").ToLocalChecked(), houseSpeed);
		Nan::Set(result,Nan::New<String> ("ascendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_ASC]));
		Nan::Set(result,Nan::New<String> ("mcSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_MC]));
		Nan::Set(result,Nan::New<String> ("armcSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_ARMC]));
		Nan::Set(result,Nan::New<String> ("vertexSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_VERTEX]));
		Nan::Set(result,Nan::New<String> ("equatorialAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_EQUASC]));
		Nan::Set(result,Nan::New<String> ("kochCoAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_COASC1]));
		Nan::Set(result,Nan::New<String> ("munkaseyCoAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_COASC2]));
		Nan::Set(result,Nan::New<String> ("munkaseyPolarAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_POLASC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int swe_houses_armc(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc)
 * =>
 * swe_houses_armc(double armc, double geolat, double eps, string hsys[, function callback (result)]) = {
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

	hsys = (* String::Utf8Value (Isolate::GetCurrent(), info [3]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}
	
	rflag = ::swe_houses_armc (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		hsys,
		cusps, ascmc
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			Nan::Set(house,Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
		};

		Nan::Set(result,Nan::New<String> ("house").ToLocalChecked(), house);
		Nan::Set(result,Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		Nan::Set(result,Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		Nan::Set(result,Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		Nan::Set(result,Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		Nan::Set(result,Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_EQUASC]));
		Nan::Set(result,Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		Nan::Set(result,Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		Nan::Set(result,Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int swe_houses_armc_ex2(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr)
 * =>
 * swe_houses_armc_ex2(double armc, double geolat, double eps, string hsys[, function callback (result)]) = {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   houseSpeed: [double],
 *   ascendantSpeed: double,
 *   mcSpeed: double,
 *   armcSpeed: double,
 *   vertexSpeed: double,
 *   equatorialAscendantSpeed: double,
 *   kochCoAscendantSpeed: double,
 *   munkaseyCoAscendantSpeed: double,
 *   munkaseyPolarAscendantSpeed: double,
 *   error: string,
 *   message: string
 * }
 */
NAN_METHOD(node_swe_houses_armc_ex2) {
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
	double cusps_speed [40] = {0};
	double ascmc_speed [40] = {0};
	int rflag;
	size_t cuspsCount;
	int hsys;
	char serr [AS_MAXCH];

	Local <Object> result = Nan::New<Object> ();
	Local <Array> house = Nan::New<Array> ();
	Local <Array> houseSpeed = Nan::New<Array> ();

	hsys = (* String::Utf8Value (Isolate::GetCurrent(), info [3]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0];
	
	if (hsys == 'G') {
		cuspsCount = 36;
	} else {
		cuspsCount = 12;
	}
	
	rflag = ::swe_houses_armc_ex2 (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		hsys,
		cusps, ascmc, cusps_speed, ascmc_speed,
		serr
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("message").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		for (size_t i = 0; i < cuspsCount; i ++) {
			Nan::Set(house,Nan::New<Number> (i), Nan::New<Number> (cusps [i + 1]));
			Nan::Set(houseSpeed,Nan::New<Number> (i), Nan::New<Number> (cusps_speed [i + 1]));
		};

		Nan::Set(result,Nan::New<String> ("house").ToLocalChecked(), house);
		Nan::Set(result,Nan::New<String> ("ascendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ASC]));
		Nan::Set(result,Nan::New<String> ("mc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_MC]));
		Nan::Set(result,Nan::New<String> ("armc").ToLocalChecked(), Nan::New<Number> (ascmc [SE_ARMC]));
		Nan::Set(result,Nan::New<String> ("vertex").ToLocalChecked(), Nan::New<Number> (ascmc [SE_VERTEX]));
		Nan::Set(result,Nan::New<String> ("equatorialAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_EQUASC]));
		Nan::Set(result,Nan::New<String> ("kochCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC1]));
		Nan::Set(result,Nan::New<String> ("munkaseyCoAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_COASC2]));
		Nan::Set(result,Nan::New<String> ("munkaseyPolarAscendant").ToLocalChecked(), Nan::New<Number> (ascmc [SE_POLASC]));

		Nan::Set(result,Nan::New<String> ("houseSpeed").ToLocalChecked(), houseSpeed);
		Nan::Set(result,Nan::New<String> ("ascendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_ASC]));
		Nan::Set(result,Nan::New<String> ("mcSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_MC]));
		Nan::Set(result,Nan::New<String> ("armcSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_ARMC]));
		Nan::Set(result,Nan::New<String> ("vertexSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_VERTEX]));
		Nan::Set(result,Nan::New<String> ("equatorialAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_EQUASC]));
		Nan::Set(result,Nan::New<String> ("kochCoAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_COASC1]));
		Nan::Set(result,Nan::New<String> ("munkaseyCoAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_COASC2]));
		Nan::Set(result,Nan::New<String> ("munkaseyPolarAscendantSpeed").ToLocalChecked(), Nan::New<Number> (ascmc_speed [SE_POLASC]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_houses_pos(double armc, double geolat, double eps, int hsys, double *xpin, char *serr)
 * =>
 * swe_houses_pos(double armc, double geolat, double eps, string hsys, double lon, double lat[, function callback (result)]) = {
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

	double xpin [2] = {info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(), info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked()};
	char serr [AS_MAXCH];
	double rflag;

	Local <Object> result = Nan::New<Object> ();

	rflag = ::swe_house_pos (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(* String::Utf8Value (Isolate::GetCurrent(), info [3]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>()))) [0],
		xpin, serr
	);

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> ("Can't calculate houses.").ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("housePosition").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};
