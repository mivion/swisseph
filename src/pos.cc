#include "swisseph.h"

using namespace v8;

/**
 * char swe_version(char *);
 * =>
 * string swe_version();
 */
NAN_METHOD(node_swe_version) {
	Nan::HandleScope scope;

	char version [AS_MAXCH];

	::swe_version (version);

	Local <String> result = Nan::New<String> (version).ToLocalChecked();

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_calc_ut(double tjd_ut, int32 ipl, int32 iflag, double *xx, char *serr)
 * =>
 * swe_calc_ut(double tjd_ut, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_calc_ut) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc_ut (
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<int32_t>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		x, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_EQUATORIAL) {
			Nan::Set(result,Nan::New<String> ("rectAscension").ToLocalChecked(), Nan::New<Number> (x [0]));
			Nan::Set(result,Nan::New<String> ("declination").ToLocalChecked(), Nan::New<Number> (x [1]));
			Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
			Nan::Set(result,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
			Nan::Set(result,Nan::New<String> ("declinationSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
			Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
			Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
		} else
			if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_XYZ) {
				Nan::Set(result,Nan::New<String> ("x").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("y").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("z").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("dx").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("dy").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("dz").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			} else {
				Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("longitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("latitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_calc(double tjd, int ipl, int32 iflag, double *xx, char *serr)
 * =>
 * swe_calc(double tjd, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_calc) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc (
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<int32_t>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		x, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_EQUATORIAL) {
			Nan::Set(result,Nan::New<String> ("rectAscension").ToLocalChecked(), Nan::New<Number> (x [0]));
			Nan::Set(result,Nan::New<String> ("declination").ToLocalChecked(), Nan::New<Number> (x [1]));
			Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
			Nan::Set(result,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
			Nan::Set(result,Nan::New<String> ("declinationSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
			Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
			Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
		} else
			if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_XYZ) {
				Nan::Set(result,Nan::New<String> ("x").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("y").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("z").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("dx").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("dy").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("dz").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			} else {
				Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("longitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("latitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_fixstar(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x [6];
	char serr [AS_MAXCH];
 char star [AS_MAXCH];
	long rflag = 0;
 
 ::strcpy (star, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_fixstar (
		star,
		Nan::To<double>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		x, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_EQUATORIAL) {
			Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
			Nan::Set(result,Nan::New<String> ("rectAscension").ToLocalChecked(), Nan::New<Number> (x [0]));
			Nan::Set(result,Nan::New<String> ("declination").ToLocalChecked(), Nan::New<Number> (x [1]));
			Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
			Nan::Set(result,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
			Nan::Set(result,Nan::New<String> ("declinationSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
			Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
			Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
		} else
			if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_XYZ) {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("x").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("y").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("z").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("dx").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("dy").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("dz").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			} else {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("longitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("latitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_fixstar_ut(char *star, double tjd_ut, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar_ut(string star, double tjd_ut, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar_ut) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x [6];
	char serr [AS_MAXCH];
 char star [AS_MAXCH];
	long rflag = 0;
 
 ::strcpy (star, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_fixstar_ut (
		star,
		Nan::To<double>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		x, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_EQUATORIAL) {
			Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
			Nan::Set(result,Nan::New<String> ("rectAscension").ToLocalChecked(), Nan::New<Number> (x [0]));
			Nan::Set(result,Nan::New<String> ("declination").ToLocalChecked(), Nan::New<Number> (x [1]));
			Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
			Nan::Set(result,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
			Nan::Set(result,Nan::New<String> ("declinationSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
			Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
			Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
		} else
			if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_XYZ) {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("x").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("y").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("z").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("dx").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("dy").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("dz").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			} else {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("longitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("latitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * ext_def(int32) swe_fixstar_mag(char *star, double *mag, char *serr);
 * =>
 * swe_fixstar_mag(string star[, function callback (result)]) = {
 *   name: string,
 *   magnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar_mag) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	char serr [AS_MAXCH];
 char star [AS_MAXCH];
	long rflag;
	double magnitude;

::strcpy (star, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_fixstar_mag (
    star,
    &magnitude,
    serr
 );

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("magnitude").ToLocalChecked(), Nan::New<Number> (magnitude));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_fixstar2(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar2(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar2) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x [6];
	char serr [AS_MAXCH];
 char star [AS_MAXCH];
	long rflag = 0;
 
 ::strcpy (star, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_fixstar2 (
		star,
		Nan::To<double>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		x, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_EQUATORIAL) {
			Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
			Nan::Set(result,Nan::New<String> ("rectAscension").ToLocalChecked(), Nan::New<Number> (x [0]));
			Nan::Set(result,Nan::New<String> ("declination").ToLocalChecked(), Nan::New<Number> (x [1]));
			Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
			Nan::Set(result,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
			Nan::Set(result,Nan::New<String> ("declinationSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
			Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
			Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
		} else
			if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_XYZ) {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("x").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("y").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("z").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("dx").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("dy").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("dz").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			} else {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("longitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("latitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_fixstar2_ut(char *star, double tjd_ut, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar2_ut(string star, double tjd_ut, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar2_ut) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double x [6];
	char serr [AS_MAXCH];
 char star [AS_MAXCH];
	long rflag = 0;
 
 ::strcpy (star, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_fixstar2_ut (
		star,
		Nan::To<double>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		x, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_EQUATORIAL) {
			Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
			Nan::Set(result,Nan::New<String> ("rectAscension").ToLocalChecked(), Nan::New<Number> (x [0]));
			Nan::Set(result,Nan::New<String> ("declination").ToLocalChecked(), Nan::New<Number> (x [1]));
			Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
			Nan::Set(result,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
			Nan::Set(result,Nan::New<String> ("declinationSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
			Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
			Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
		} else
			if (Nan::To<int32_t>(info[2]).FromJust() & SEFLG_XYZ) {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("x").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("y").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("z").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("dx").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("dy").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("dz").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			} else {
				Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
				Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(), Nan::New<Number> (x [0]));
				Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(), Nan::New<Number> (x [1]));
				Nan::Set(result,Nan::New<String> ("distance").ToLocalChecked(), Nan::New<Number> (x [2]));
				Nan::Set(result,Nan::New<String> ("longitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [3]));
				Nan::Set(result,Nan::New<String> ("latitudeSpeed").ToLocalChecked(), Nan::New<Number> (x [4]));
				Nan::Set(result,Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (x [5]));
				Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * ext_def(int32) swe_fixstar2_mag(char *star, double *mag, char *serr);
 * =>
 * swe_fixstar2_mag(string star[, function callback (result)]) = {
 *   name: string,
 *   magnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar2_mag) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	char serr [AS_MAXCH];
 char star [AS_MAXCH];
	long rflag;
	double magnitude;
 
 ::strcpy (star, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_fixstar2_mag (
   star,
   &magnitude,
   serr
 );

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("magnitude").ToLocalChecked(), Nan::New<Number> (magnitude));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_close(void);
 * =>
 * swe_close([function callback (undefined)]) = undefined
 */
NAN_METHOD(node_swe_close) {
	Nan::HandleScope scope;

	::swe_close ();

    HandleCallback (info, Nan::Undefined());
    info.GetReturnValue().Set (Nan::Undefined());
};

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * swe_set_ephe_path(string path[, function callback (path)]) = String
 */
NAN_METHOD(node_swe_set_ephe_path) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};
 
 char path [AS_MAXCH];
 
 ::strcpy (path, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	::swe_set_ephe_path (
		path
	);

 Local <Object> result = Nan::To<v8::Object>(info[0]).ToLocalChecked();

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * swe_set_jpl_file(string fname[, function callback (fname)]) = String
 */
NAN_METHOD(node_swe_set_jpl_file) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsString ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

 char path [AS_MAXCH];
 
 ::strcpy (path, *String::Utf8Value (Isolate::GetCurrent(), info [0]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));
 
	::swe_set_jpl_file (
		path
	);

	Local <Object> result = Nan::To<v8::Object>(info[0]).ToLocalChecked();

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * char swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) = {
 *   name: string
 * }
 */
NAN_METHOD(node_swe_get_planet_name) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	char name [AS_MAXCH] = {0};

	::swe_get_planet_name (Nan::To<int32_t>(info[0]).FromJust(), name);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (name).ToLocalChecked());

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * ext_def (void) swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * swe_set_topo(double geolon, double geolat[, function callback (undefined)]) = undefined
 */
NAN_METHOD(node_swe_set_topo) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_topo (
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<double>(info[1]).FromJust(),
		Nan::To<double>(info[2]).FromJust()
	);

    HandleCallback (info, Nan::Undefined());
    info.GetReturnValue().Set (Nan::Undefined());
};

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0[, function callback (undefined)]) = undefined
 */
NAN_METHOD(node_swe_set_sid_mode) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_sid_mode (
		Nan::To<int32_t>(info[0]).FromJust(),
		Nan::To<double>(info[1]).FromJust(),
		Nan::To<double>(info[2]).FromJust()
	);

    HandleCallback (info, Nan::Undefined());
    info.GetReturnValue().Set (Nan::Undefined());
};

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * swe_get_ayanamsa(double tjd_et[, function callback (result)]) = double
 */
NAN_METHOD(node_swe_get_ayanamsa) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double val;

	val = ::swe_get_ayanamsa (
		Nan::To<double>(info[0]).FromJust()
	);

	Local <Number> result = Nan::New<Number> (val);

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * swe_get_ayanamsa_ut(double tjd_ut[, function callback (result)]) = double
 */
NAN_METHOD(node_swe_get_ayanamsa_ut) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double val;

	val = ::swe_get_ayanamsa_ut (
		Nan::To<double>(info[0]).FromJust()
	);

	Local <Number> result = Nan::New<Number> (val);

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_get_ayanamsa_ex(double tjd_et, int32 iflag, double *daya, char *serr);
 * =>
 * swe_get_ayanamsa_ex(double tjd_et, int32 iflag[, function callback (result)]) = {
 *   ayanamsa: double,
 *   error: string
 * }
 */

NAN_METHOD(node_swe_get_ayanamsa_ex) {
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

	double daya [1];
	char serr [AS_MAXCH];
	long val;

	val = ::swe_get_ayanamsa_ex (
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<int32_t>(info[1]).FromJust(),
		daya, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (val < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		Nan::Set(result,Nan::New<String> ("ayanamsa").ToLocalChecked(), Nan::New<Number> (daya [0]));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_get_ayanamsa_ex_ut(double tjd_ut, int32 iflag, double *daya, char *serr);
 * =>
 * swe_get_ayanamsa_ex_ut(double tjd_ut, int32 iflag[, function callback (result)]) = {
 *   ayanamsa: double,
 *   error: string
 * }
 */

NAN_METHOD(node_swe_get_ayanamsa_ex_ut) {
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

	double daya [1];
	char serr [AS_MAXCH];
	long val;

	val = ::swe_get_ayanamsa_ex_ut (
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<int32_t>(info[1]).FromJust(),
		daya, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (val < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		Nan::Set(result,Nan::New<String> ("ayanamsa").ToLocalChecked(), Nan::New<Number> (daya [0]));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};


/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * swe_get_ayanamsa_name(int32 isidmode[, function callback (result)]) = string
 */
NAN_METHOD(node_swe_get_ayanamsa_name) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	const char * val;

	val = ::swe_get_ayanamsa_name (
		Nan::To<int32_t>(info[0]).FromJust()
	);

	Local <String> result = Nan::New<String> (val).ToLocalChecked();

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32 method, double *xnasc (out[6]), double *xndsc (out[6]), double *xperi (out[6]), double *xaphe (out[6]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32 method[, function callback (result)]) = {
 *   ascending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   descending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   perihelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   aphelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   error: string
 * }
 */
NAN_METHOD(node_swe_nod_aps) {
	Nan::HandleScope scope;

	if (info.Length () < 4) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double xnasc [6] = {0};
	double xndsc [6] = {0};
	double xperi [6] = {0};
	double xaphe [6] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_nod_aps (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		xnasc, xndsc, xperi, xaphe, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if ((int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked() & SEFLG_EQUATORIAL) {
			Local <Object> ascending = Nan::New<Object> ();
			Nan::Set(ascending,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
			Nan::Set(ascending,Nan::New<String> ("declination").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
			Nan::Set(ascending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
			Nan::Set(ascending,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
			Nan::Set(ascending,Nan::New<String> ("declinationSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
			Nan::Set(ascending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
			Nan::Set(result,Nan::New<String> ("ascending").ToLocalChecked(), ascending);

			Local <Object> descending = Nan::New<Object> ();
			Nan::Set(descending,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
			Nan::Set(descending,Nan::New<String> ("declination").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
			Nan::Set(descending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
			Nan::Set(descending,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
			Nan::Set(descending,Nan::New<String> ("declinationSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
			Nan::Set(descending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
			Nan::Set(result,Nan::New<String> ("descending").ToLocalChecked(), descending);

			Local <Object> perihelion = Nan::New<Object> ();
			Nan::Set(perihelion,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
			Nan::Set(perihelion,Nan::New<String> ("declination").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
			Nan::Set(perihelion,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
			Nan::Set(perihelion,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
			Nan::Set(perihelion,Nan::New<String> ("declinationSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
			Nan::Set(perihelion,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
			Nan::Set(result,Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

			Local <Object> aphelion = Nan::New<Object> ();
			Nan::Set(aphelion,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
			Nan::Set(aphelion,Nan::New<String> ("declination").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
			Nan::Set(aphelion,Nan::New<String> ("distance").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
			Nan::Set(aphelion,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
			Nan::Set(aphelion,Nan::New<String> ("declinationSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
			Nan::Set(aphelion,Nan::New<String> ("distanceSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [5]));
			Nan::Set(result,Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
		} else
			if ((int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked() & SEFLG_XYZ) {
				Local <Object> ascending = Nan::New<Object> ();
				Nan::Set(ascending,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
				Nan::Set(ascending,Nan::New<String> ("y").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
				Nan::Set(ascending,Nan::New<String> ("z").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
				Nan::Set(ascending,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
				Nan::Set(ascending,Nan::New<String> ("dy").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
				Nan::Set(ascending,Nan::New<String> ("dz").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
				Nan::Set(result,Nan::New<String> ("ascending").ToLocalChecked(), ascending);

				Local <Object> descending = Nan::New<Object> ();
				Nan::Set(descending,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
				Nan::Set(descending,Nan::New<String> ("y").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
				Nan::Set(descending,Nan::New<String> ("z").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
				Nan::Set(descending,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
				Nan::Set(descending,Nan::New<String> ("dy").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
				Nan::Set(descending,Nan::New<String> ("dz").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
				Nan::Set(result,Nan::New<String> ("descending").ToLocalChecked(), descending);

				Local <Object> perihelion = Nan::New<Object> ();
				Nan::Set(perihelion,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
				Nan::Set(perihelion,Nan::New<String> ("y").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
				Nan::Set(perihelion,Nan::New<String> ("z").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
				Nan::Set(perihelion,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
				Nan::Set(perihelion,Nan::New<String> ("dy").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
				Nan::Set(perihelion,Nan::New<String> ("dz").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
				Nan::Set(result,Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

				Local <Object> aphelion = Nan::New<Object> ();
				Nan::Set(aphelion,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
				Nan::Set(aphelion,Nan::New<String> ("y").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
				Nan::Set(aphelion,Nan::New<String> ("z").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
				Nan::Set(aphelion,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
				Nan::Set(aphelion,Nan::New<String> ("dy").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
				Nan::Set(aphelion,Nan::New<String> ("dz").ToLocalChecked(),		Nan::New<Number> (xaphe [5]));
				Nan::Set(result,Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
			} else {
				Local <Object> ascending = Nan::New<Object> ();
				Nan::Set(ascending,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
				Nan::Set(ascending,Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
				Nan::Set(ascending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
				Nan::Set(ascending,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
				Nan::Set(ascending,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
				Nan::Set(ascending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
				Nan::Set(result,Nan::New<String> ("ascending").ToLocalChecked(), ascending);

				Local <Object> descending = Nan::New<Object> ();
				Nan::Set(descending,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
				Nan::Set(descending,Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
				Nan::Set(descending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
				Nan::Set(descending,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
				Nan::Set(descending,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
				Nan::Set(descending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
				Nan::Set(result,Nan::New<String> ("descending").ToLocalChecked(), descending);

				Local <Object> perihelion = Nan::New<Object> ();
				Nan::Set(perihelion,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
				Nan::Set(perihelion,Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
				Nan::Set(perihelion,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
				Nan::Set(perihelion,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
				Nan::Set(perihelion,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
				Nan::Set(perihelion,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
				Nan::Set(result,Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

				Local <Object> aphelion = Nan::New<Object> ();
				Nan::Set(aphelion,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
				Nan::Set(aphelion,Nan::New<String> ("latitude").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
				Nan::Set(aphelion,Nan::New<String> ("distance").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
				Nan::Set(aphelion,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
				Nan::Set(aphelion,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
				Nan::Set(aphelion,Nan::New<String> ("distanceSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [5]));
				Nan::Set(result,Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32 method, double *xnasc (out[6]), double *xndsc (out[6]), double *xperi (out[6]), double *xaphe (out[6]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32 method[, function callback (result)]) = {
 *   ascending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   descending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   perihelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   aphelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   error: string
 * }
 */
NAN_METHOD(node_swe_nod_aps_ut) {
	Nan::HandleScope scope;

	if (info.Length () < 4) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double xnasc [6] = {0};
	double xndsc [6] = {0};
	double xperi [6] = {0};
	double xaphe [6] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_nod_aps_ut (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		xnasc, xndsc, xperi, xaphe, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else 
		if ((int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked() & SEFLG_EQUATORIAL) {
			Local <Object> ascending = Nan::New<Object> ();
			Nan::Set(ascending,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
			Nan::Set(ascending,Nan::New<String> ("declination").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
			Nan::Set(ascending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
			Nan::Set(ascending,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
			Nan::Set(ascending,Nan::New<String> ("declinationSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
			Nan::Set(ascending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
			Nan::Set(result,Nan::New<String> ("ascending").ToLocalChecked(), ascending);

			Local <Object> descending = Nan::New<Object> ();
			Nan::Set(descending,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
			Nan::Set(descending,Nan::New<String> ("declination").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
			Nan::Set(descending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
			Nan::Set(descending,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
			Nan::Set(descending,Nan::New<String> ("declinationSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
			Nan::Set(descending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
			Nan::Set(result,Nan::New<String> ("descending").ToLocalChecked(), descending);

			Local <Object> perihelion = Nan::New<Object> ();
			Nan::Set(perihelion,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
			Nan::Set(perihelion,Nan::New<String> ("declination").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
			Nan::Set(perihelion,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
			Nan::Set(perihelion,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
			Nan::Set(perihelion,Nan::New<String> ("declinationSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
			Nan::Set(perihelion,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
			Nan::Set(result,Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

			Local <Object> aphelion = Nan::New<Object> ();
			Nan::Set(aphelion,Nan::New<String> ("rectAscension").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
			Nan::Set(aphelion,Nan::New<String> ("declination").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
			Nan::Set(aphelion,Nan::New<String> ("distance").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
			Nan::Set(aphelion,Nan::New<String> ("rectAscensionSpeed").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
			Nan::Set(aphelion,Nan::New<String> ("declinationSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
			Nan::Set(aphelion,Nan::New<String> ("distanceSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [5]));
			Nan::Set(result,Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
		} else
			if ((int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked() & SEFLG_XYZ) {
				Local <Object> ascending = Nan::New<Object> ();
				Nan::Set(ascending,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
				Nan::Set(ascending,Nan::New<String> ("y").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
				Nan::Set(ascending,Nan::New<String> ("z").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
				Nan::Set(ascending,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
				Nan::Set(ascending,Nan::New<String> ("dy").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
				Nan::Set(ascending,Nan::New<String> ("dz").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
				Nan::Set(result,Nan::New<String> ("ascending").ToLocalChecked(), ascending);

				Local <Object> descending = Nan::New<Object> ();
				Nan::Set(descending,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
				Nan::Set(descending,Nan::New<String> ("y").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
				Nan::Set(descending,Nan::New<String> ("z").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
				Nan::Set(descending,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
				Nan::Set(descending,Nan::New<String> ("dy").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
				Nan::Set(descending,Nan::New<String> ("dz").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
				Nan::Set(result,Nan::New<String> ("descending").ToLocalChecked(), descending);

				Local <Object> perihelion = Nan::New<Object> ();
				Nan::Set(perihelion,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
				Nan::Set(perihelion,Nan::New<String> ("y").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
				Nan::Set(perihelion,Nan::New<String> ("z").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
				Nan::Set(perihelion,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
				Nan::Set(perihelion,Nan::New<String> ("dy").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
				Nan::Set(perihelion,Nan::New<String> ("dz").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
				Nan::Set(result,Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

				Local <Object> aphelion = Nan::New<Object> ();
				Nan::Set(aphelion,Nan::New<String> ("x").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
				Nan::Set(aphelion,Nan::New<String> ("y").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
				Nan::Set(aphelion,Nan::New<String> ("z").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
				Nan::Set(aphelion,Nan::New<String> ("dx").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
				Nan::Set(aphelion,Nan::New<String> ("dy").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
				Nan::Set(aphelion,Nan::New<String> ("dz").ToLocalChecked(),		Nan::New<Number> (xaphe [5]));
				Nan::Set(result,Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
			} else {
				Local <Object> ascending = Nan::New<Object> ();
				Nan::Set(ascending,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
				Nan::Set(ascending,Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
				Nan::Set(ascending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
				Nan::Set(ascending,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
				Nan::Set(ascending,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
				Nan::Set(ascending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
				Nan::Set(result,Nan::New<String> ("ascending").ToLocalChecked(), ascending);

				Local <Object> descending = Nan::New<Object> ();
				Nan::Set(descending,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
				Nan::Set(descending,Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
				Nan::Set(descending,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
				Nan::Set(descending,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
				Nan::Set(descending,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
				Nan::Set(descending,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
				Nan::Set(result,Nan::New<String> ("descending").ToLocalChecked(), descending);

				Local <Object> perihelion = Nan::New<Object> ();
				Nan::Set(perihelion,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
				Nan::Set(perihelion,Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
				Nan::Set(perihelion,Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
				Nan::Set(perihelion,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
				Nan::Set(perihelion,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
				Nan::Set(perihelion,Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
				Nan::Set(result,Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

				Local <Object> aphelion = Nan::New<Object> ();
				Nan::Set(aphelion,Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
				Nan::Set(aphelion,Nan::New<String> ("latitude").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
				Nan::Set(aphelion,Nan::New<String> ("distance").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
				Nan::Set(aphelion,Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
				Nan::Set(aphelion,Nan::New<String> ("latitudeSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
        Nan::Set(aphelion, Nan::New<String> ("distanceSpeed").ToLocalChecked(), Nan::New<Number> (xaphe [5]));
        Nan::Set(result, Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
			};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * void swe_get_orbital_elements(double tjd_et, int32 ipl, in32 iflag, double *dret, char *serr)
 * =>
 * swe_get_orbital_elements(double tjd_et, int32 ipl, in32 iflag[, function callback (result)]) = {
 *   aphelionDistance: double
 *   ascendingNode: double
 *   eccentricAnomaly: double
 *   eccentricity: double
 *   inclination: double
 *   meanAnomaly: double
 *   meanDailyMotion: double
 *   meanLongitude: double
 *   periapsis: double
 *   periapsisArg: double
 *   perihelionDistance: double
 *   perihelionPassage: double
 *   semimajorAxis: double
 *   siderealPeriod: double
 *   synodicPeriod: double
 *   tropicalPeriod: double
 *   trueAnomaly: double
 *   rflag: int
 * }
 */
NAN_METHOD(node_swe_get_orbital_elements) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double dret [50];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_get_orbital_elements (
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<int32_t>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		dret, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("semimajorAxis").ToLocalChecked(), Nan::New<Number> (dret [0]));
		Nan::Set(result,Nan::New<String> ("eccentricity").ToLocalChecked(), Nan::New<Number> (dret [1]));
		Nan::Set(result,Nan::New<String> ("inclination").ToLocalChecked(), Nan::New<Number> (dret [2]));
		Nan::Set(result,Nan::New<String> ("ascendingNode").ToLocalChecked(), Nan::New<Number> (dret [3]));
		Nan::Set(result,Nan::New<String> ("periapsisArg").ToLocalChecked(), Nan::New<Number> (dret [4]));
		Nan::Set(result,Nan::New<String> ("periapsis").ToLocalChecked(), Nan::New<Number> (dret [5]));
		Nan::Set(result,Nan::New<String> ("meanAnomaly").ToLocalChecked(), Nan::New<Number> (dret [6]));
		Nan::Set(result,Nan::New<String> ("trueAnomaly").ToLocalChecked(), Nan::New<Number> (dret [7]));
		Nan::Set(result,Nan::New<String> ("eccentricAnomaly").ToLocalChecked(), Nan::New<Number> (dret [8]));
		Nan::Set(result,Nan::New<String> ("meanLongitude").ToLocalChecked(), Nan::New<Number> (dret [9]));
		Nan::Set(result,Nan::New<String> ("siderealPeriod").ToLocalChecked(), Nan::New<Number> (dret [10]));
		Nan::Set(result,Nan::New<String> ("meanDailyMotion").ToLocalChecked(), Nan::New<Number> (dret [11]));
		Nan::Set(result,Nan::New<String> ("tropicalPeriod").ToLocalChecked(), Nan::New<Number> (dret [12]));
		Nan::Set(result,Nan::New<String> ("synodicPeriod").ToLocalChecked(), Nan::New<Number> (dret [13]));
		Nan::Set(result,Nan::New<String> ("perihelionPassage").ToLocalChecked(), Nan::New<Number> (dret [14]));
		Nan::Set(result,Nan::New<String> ("perihelionDistance").ToLocalChecked(), Nan::New<Number> (dret [15]));
		Nan::Set(result,Nan::New<String> ("aphelionDistance").ToLocalChecked(), Nan::New<Number> (dret [16]));
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	}
    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};


/**
 * int32 swe_orbit_max_min_true_distance(double tjd_et, int32 ipl, int32 iflag, double *dmax, double *dmin, double *dtrue, char *serr)
 * =>
 * swe_orbit_max_min_true_distance(double tjd_et, int32 ipl, in32 iflag[, function callback (result)]) = {
 *   maxDistance: double
 *   minDistance: double
 *   trueDistance: double
 *   rflag: int
 *   error: string
 * }
 */
NAN_METHOD(node_swe_orbit_max_min_true_distance) {
	Nan::HandleScope scope;

	if (info.Length () < 3) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double dmax [1];
	double dmin [1];
	double dtrue [1];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_orbit_max_min_true_distance(
		Nan::To<double>(info[0]).FromJust(),
		Nan::To<int32_t>(info[1]).FromJust(),
		Nan::To<int32_t>(info[2]).FromJust(),
		dmax, dmin, dtrue, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("maxDistance").ToLocalChecked(), Nan::New<Number> (dmax[0]));
		Nan::Set(result,Nan::New<String> ("minDistance").ToLocalChecked(), Nan::New<Number> (dmin[0]));
		Nan::Set(result,Nan::New<String> ("trueDistance").ToLocalChecked(), Nan::New<Number> (dtrue[0]));
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	}
    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};