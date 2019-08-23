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

/**
 * int32 swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double *geopos (in[3]), double atpress, double attemp, double *dgsect (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   name: string,            //star
 *   gauquelinSector: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_gauquelin_sector) {
	Nan::HandleScope scope;

	if (info.Length () < 10) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsString () ||
		!info [3]->IsNumber () ||
		!info [4]->IsNumber () ||
		!info [5]->IsNumber () ||
		!info [6]->IsNumber () ||
		!info [7]->IsNumber () ||
		!info [8]->IsNumber () ||
		!info [9]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double geopos [3] = {0};
	double dgsect;
	char starname [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (starname, * String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	geopos [0] = Nan::To<double>(info[5]).FromJust();
	geopos [1] = Nan::To<double>(info[6]).FromJust();
	geopos [2] = Nan::To<double>(info[7]).FromJust();

	rflag = ::swe_gauquelin_sector (
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<int32_t>(info[1]).FromJust(),
		starname,
		Nan::To<int32_t>(info[3]).FromJust(),
		Nan::To<int32_t>(info[4]).FromJust(),
		geopos,
		Nan::To<double>(info[8]).FromJust(),
		Nan::To<double>(info[9]).FromJust(),
		dgsect, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("gauquelinSector").ToLocalChecked(), Nan::New<Number> (dgsect));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};
