#include "swisseph.h"

using namespace v8;

/**
 * int32 swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double *geopos (in[3]), double atpress, double attemp, double *dgsect (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   name: string,
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

	double geopos [10] = {0};
	double dgsect;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (info [2]->ToString ()));

	geopos [0] = info [5]->NumberValue ();
	geopos [1] = info [6]->NumberValue ();
	geopos [2] = info [7]->NumberValue ();

	rflag = ::swe_gauquelin_sector (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		star,
		(int)info [3]->NumberValue (),
		(int)info [4]->NumberValue (),
		geopos,
		info [8]->NumberValue (),
		info [9]->NumberValue (),
		&dgsect, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		result->Set (Nan::New<String> ("gauquelinSector").ToLocalChecked(), Nan::New<Number> (dgsect));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_sol_eclipse_where(double tjd, int32 ifl, double *geopos (out[10]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_where(double tjd, int32 ifl[, function callback (result)]) = {
 *   longitude: double,                    // geopos [0]
 *   latitude: double,                     // geopos [1]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_where) {
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

	double geopos [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_sol_eclipse_where (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("longitude").ToLocalChecked(),	                Nan::New<Number> (geopos [0]));
		result->Set (Nan::New<String> ("latitude").ToLocalChecked(),	                Nan::New<Number> (geopos [1]));
		result->Set (Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		result->Set (Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		result->Set (Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		result->Set (Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		result->Set (Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		result->Set (Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_lun_occult_where(double tjd, int32 ipl, char *starname, int32 ifl, double *geopos (out[10]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_where(double tjd, int32 ipl, char *starname, int32 ifl[, function callback (result)]) = {
 *   longitude: double,                    // geopos [0]
 *   latitude: double,                     // geopos [1]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_occult_where) {
	Nan::HandleScope scope;

	if (info.Length () < 4) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsString () ||
		!info [3]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double geopos [10] = {0};
	double attr [20] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (info [2]->ToString ()));

	rflag = ::swe_lun_occult_where (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		star,
		(int)info [3]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("longitude").ToLocalChecked(),	Nan::New<Number> (geopos [0]));
		result->Set (Nan::New<String> ("latitude").ToLocalChecked(),	Nan::New<Number> (geopos [1]));
		result->Set (Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		result->Set (Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		result->Set (Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_sol_eclipse_how(double tjd, int32 ifl, double *geopos (in[3]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_how(double tjd, int32 ifl, double longitude, double latitude, double height[, function callback (result)]) = {
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_how) {
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

	double geopos [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	geopos [0] = info [2]->NumberValue ();
	geopos [1] = info [3]->NumberValue ();
	geopos [2] = info [4]->NumberValue ();

	rflag = ::swe_sol_eclipse_how (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		result->Set (Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		result->Set (Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		result->Set (Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		result->Set (Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		result->Set (Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   maximum: double,                      // tret [0]
 *   first: double,                        // tret [1]
 *   second: double,                       // tret [2]
 *   third: double,                        // tret [3]
 *   forth: double,                        // tret [4]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_when_loc) {
	Nan::HandleScope scope;

	if (info.Length () < 6) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber () ||
		!info [4]->IsNumber () ||
		!info [5]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double geopos [10] = {0};
	double tret [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	geopos [0] = info [2]->NumberValue ();
	geopos [1] = info [3]->NumberValue ();
	geopos [2] = info [4]->NumberValue ();

	rflag = ::swe_sol_eclipse_when_loc (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		geopos, tret, attr,
		(int)info [5]->NumberValue (),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("maximum").ToLocalChecked(),		Nan::New<Number> (tret [0]));
		result->Set (Nan::New<String> ("first").ToLocalChecked(),		Nan::New<Number> (tret [1]));
		result->Set (Nan::New<String> ("second").ToLocalChecked(),		Nan::New<Number> (tret [2]));
		result->Set (Nan::New<String> ("third").ToLocalChecked(),		Nan::New<Number> (tret [3]));
		result->Set (Nan::New<String> ("forth").ToLocalChecked(),		Nan::New<Number> (tret [4]));
		result->Set (Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		result->Set (Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		result->Set (Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		result->Set (Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		result->Set (Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		result->Set (Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   star: string,
 *   maximum: double,                      // tret [0]
 *   first: double,                        // tret [1]
 *   second: double,                       // tret [2]
 *   third: double,                        // tret [3]
 *   forth: double,                        // tret [4]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_occult_when_loc) {
	Nan::HandleScope scope;

	if (info.Length () < 8) {
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
		!info [7]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double geopos [10] = {0};
	double tret [10] = {0};
	double attr [20] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (info [2]->ToString ()));

	geopos [0] = info [4]->NumberValue ();
	geopos [1] = info [5]->NumberValue ();
	geopos [2] = info [6]->NumberValue ();

	rflag = ::swe_lun_occult_when_loc (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		star,
		(int)info [3]->NumberValue (),
		geopos, tret, attr,
		(int)info [7]->NumberValue (),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		result->Set (Nan::New<String> ("maximum").ToLocalChecked(),		Nan::New<Number> (tret [0]));
		result->Set (Nan::New<String> ("first").ToLocalChecked(),		Nan::New<Number> (tret [1]));
		result->Set (Nan::New<String> ("second").ToLocalChecked(),		Nan::New<Number> (tret [2]));
		result->Set (Nan::New<String> ("third").ToLocalChecked(),		Nan::New<Number> (tret [3]));
		result->Set (Nan::New<String> ("forth").ToLocalChecked(),		Nan::New<Number> (tret [4]));
		result->Set (Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		result->Set (Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		result->Set (Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		result->Set (Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		result->Set (Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		result->Set (Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, double *tret (out[10]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   maximum: double,      // tret [0]
 *   noon: double,         // tret [1]
 *   begin: double,        // tret [2]
 *   end: double,          // tret [3]
 *   totalBegin: double,   // tret [4]
 *   totalEnd: double,     // tret [5]
 *   centerBegin: double,  // tret [6]
 *   centerEnd: double,    // tret [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_when_glob) {
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

	double tret [10] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_sol_eclipse_when_glob (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		(int)info [2]->NumberValue (),
		tret,
		(int)info [3]->NumberValue (),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("maximum").ToLocalChecked(),		Nan::New<Number> (tret [0]));
		result->Set (Nan::New<String> ("noon").ToLocalChecked(),		Nan::New<Number> (tret [1]));
		result->Set (Nan::New<String> ("begin").ToLocalChecked(),		Nan::New<Number> (tret [2]));
		result->Set (Nan::New<String> ("end").ToLocalChecked(),			Nan::New<Number> (tret [3]));
		result->Set (Nan::New<String> ("totalBegin").ToLocalChecked(),	Nan::New<Number> (tret [4]));
		result->Set (Nan::New<String> ("totalEnd").ToLocalChecked(),	Nan::New<Number> (tret [5]));
		result->Set (Nan::New<String> ("centerBegin").ToLocalChecked(),	Nan::New<Number> (tret [6]));
		result->Set (Nan::New<String> ("centerEnd").ToLocalChecked(),	Nan::New<Number> (tret [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, double *tret (out[10]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   name: string,
 *   maximum: double,      // tret [0]
 *   noon: double,         // tret [1]
 *   begin: double,        // tret [2]
 *   end: double,          // tret [3]
 *   totalBegin: double,   // tret [4]
 *   totalEnd: double,     // tret [5]
 *   centerBegin: double,  // tret [6]
 *   centerEnd: double,    // tret [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_occult_when_glob) {
	Nan::HandleScope scope;

	if (info.Length () < 6) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsString () ||
		!info [3]->IsNumber () ||
		!info [4]->IsNumber () ||
		!info [5]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double tret [10] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (info [2]->ToString ()));

	rflag = ::swe_lun_occult_when_glob (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		star,
		(int)info [3]->NumberValue (),
		(int)info [4]->NumberValue (),
		tret,
		(int)info [5]->NumberValue (),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		result->Set (Nan::New<String> ("maximum").ToLocalChecked(),		Nan::New<Number> (tret [0]));
		result->Set (Nan::New<String> ("noon").ToLocalChecked(),		Nan::New<Number> (tret [1]));
		result->Set (Nan::New<String> ("begin").ToLocalChecked(),		Nan::New<Number> (tret [2]));
		result->Set (Nan::New<String> ("end").ToLocalChecked(),			Nan::New<Number> (tret [3]));
		result->Set (Nan::New<String> ("totalBegin").ToLocalChecked(),	Nan::New<Number> (tret [4]));
		result->Set (Nan::New<String> ("totalEnd").ToLocalChecked(),	Nan::New<Number> (tret [5]));
		result->Set (Nan::New<String> ("centerBegin").ToLocalChecked(),	Nan::New<Number> (tret [6]));
		result->Set (Nan::New<String> ("centerEnd").ToLocalChecked(),	Nan::New<Number> (tret [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_lun_eclipse_how(double tjd_ut, int32 ifl, double *geopos (in[3]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_eclipse_how(double tjd_ut, int32 ifl, double longitude, double latitude, double height[, function callback (result)]) = {
 *   umbralMagnitude: double,          // attr [0]
 *   penumbralMagnitude: double,       // attr [1]
 *   azimuth: double,                  // attr [4] not implemented
 *   trueAltitude: double,             // attr [5] not implemented
 *   apparentAltitude: double,         // attr [6] not implemented
 *   oppositeDegreeDistance: double,   // attr [7]
 *   magnitude: double,                // attr [8]
 *   sarosNumber: double,              // attr [9]
 *   sarosMember: double,              // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_eclipse_how) {
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

	double geopos [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	geopos [0] = info [2]->NumberValue ();
	geopos [1] = info [3]->NumberValue ();
	geopos [2] = info [4]->NumberValue ();

	rflag = ::swe_lun_eclipse_how (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("umbralMagnitude").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("penumbralMagnitude").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),				Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),		Nan::New<Number> (attr [5]));
		result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),	Nan::New<Number> (attr [6]));
		result->Set (Nan::New<String> ("oppositeDegreeDist").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		result->Set (Nan::New<String> ("magnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		result->Set (Nan::New<String> ("sarosNumber").ToLocalChecked(),			Nan::New<Number> (attr [9]));
		result->Set (Nan::New<String> ("sarosMember").ToLocalChecked(),			Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, double *tret (out[10]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   maximum: double,        // tret [0]
 *   partialBegin: double,   // tret [2]
 *   partialEnd: double,     // tret [3]
 *   totalBegin: double,     // tret [4]
 *   totalEnd: double,       // tret [5]
 *   penumbralBegin: double, // tret [6]
 *   penumbralEnd: double,   // tret [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_eclipse_when) {
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

	double tret [10] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_lun_eclipse_when (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		(int)info [2]->NumberValue (),
		tret,
		(int)info [3]->NumberValue (),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("maximum").ToLocalChecked(),			Nan::New<Number> (tret [0]));
		result->Set (Nan::New<String> ("partialBegin").ToLocalChecked(),	Nan::New<Number> (tret [2]));
		result->Set (Nan::New<String> ("partialEnd").ToLocalChecked(),		Nan::New<Number> (tret [3]));
		result->Set (Nan::New<String> ("totalBegin").ToLocalChecked(),		Nan::New<Number> (tret [4]));
		result->Set (Nan::New<String> ("totalEnd").ToLocalChecked(),		Nan::New<Number> (tret [5]));
		result->Set (Nan::New<String> ("penumbralBegin").ToLocalChecked(),	Nan::New<Number> (tret [6]));
		result->Set (Nan::New<String> ("penumbralEnd").ToLocalChecked(),	Nan::New<Number> (tret [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_pheno(double tjd, int32 ipl, int32 iflag, double *attr, char *serr (out[AS_MAXCH]))
 * =>
 * swe_pheno(double tjd, int32 ipl, int32 iflag) {
 *   phaseAngle: double,
 *   phase: double,
 *   elongation: double,
 *   apparentDiameter: double,
 *   apparentMagnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_pheno) {
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

	double attr [20];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_pheno (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		(int)info [2]->NumberValue (),
		attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("phaseAngle").ToLocalChecked(), Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("phase").ToLocalChecked(), Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("elongation").ToLocalChecked(), Nan::New<Number> (attr [2]));
		result->Set (Nan::New<String> ("apparentDiameter").ToLocalChecked(), Nan::New<Number> (attr [3]));
		result->Set (Nan::New<String> ("apparentMagnitude").ToLocalChecked(), Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_pheno_ut(double tjd, int32 ipl, int32 iflag, double *attr, char *serr (out[AS_MAXCH]))
 * =>
 * swe_pheno_ut(double tjd, int32 ipl, int32 iflag) {
 *   phaseAngle: double,
 *   phase: double,
 *   elongation: double,
 *   apparentDiameter: double,
 *   apparentMagnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_pheno_ut) {
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

	double attr [20];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_pheno_ut (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		(int)info [2]->NumberValue (),
		attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("phaseAngle").ToLocalChecked(), Nan::New<Number> (attr [0]));
		result->Set (Nan::New<String> ("phase").ToLocalChecked(), Nan::New<Number> (attr [1]));
		result->Set (Nan::New<String> ("elongation").ToLocalChecked(), Nan::New<Number> (attr [2]));
		result->Set (Nan::New<String> ("apparentDiameter").ToLocalChecked(), Nan::New<Number> (attr [3]));
		result->Set (Nan::New<String> ("apparentMagnitude").ToLocalChecked(), Nan::New<Number> (attr [4]));
		result->Set (Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 * =>
 * swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double
 * }
 */
NAN_METHOD(node_swe_refrac) {
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

	double refraction;

	refraction = ::swe_refrac (
		info [0]->NumberValue (),
		info [1]->NumberValue (),
		info [2]->NumberValue (),
		(int)info [3]->NumberValue ()
	);

	Local <Object> result = Nan::New<Object> ();

	result->Set (Nan::New<String> ("refraction").ToLocalChecked(), Nan::New<Number> (refraction));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * double swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag, double *dret)
 * =>
 * swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double,
 *   trueAltitude: double,      // dret [0]
 *   apparentAltitude: double,  // dret [1]
 *   horizonDip: double         // dret [3]
 * }
 */
NAN_METHOD(node_swe_refrac_extended) {
	Nan::HandleScope scope;

	if (info.Length () < 6) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
		!info [3]->IsNumber () ||
		!info [4]->IsNumber () ||
		!info [5]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double refraction;
	double dret [4];

	refraction = ::swe_refrac_extended (
		info [0]->NumberValue (),
		info [1]->NumberValue (),
		info [2]->NumberValue (),
		info [3]->NumberValue (),
		info [4]->NumberValue (),
		(int)info [5]->NumberValue (),
		dret
	);

	Local <Object> result = Nan::New<Object> ();

	result->Set (Nan::New<String> ("refraction").ToLocalChecked(), Nan::New<Number> (refraction));
	result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),		Nan::New<Number> (dret [0]));
	result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),	Nan::New<Number> (dret [1]));
	result->Set (Nan::New<String> ("horizonDip").ToLocalChecked(),			Nan::New<Number> (dret [3]));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_set_lapse_rate(double lapse_rate)
 * =>
 * swe_set_lapse_rate(double lapse_rate[, function callback (result)]) = {
 * }
 */
NAN_METHOD(node_swe_set_lapse_rate) {
	Nan::HandleScope scope;

	if (info.Length () < 1) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_lapse_rate (
        info [0]->NumberValue ()
	);

	Local <Object> result = Nan::New<Object> ();

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_azalt(double tjd_ut, int32 calc_flag, double *geopos (in[3]), double atpress, double attemp, double *xin (in[3]), double *xaz (out[3]))
 * =>
 * swe_azalt(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double atpress, double attemp, double bodyX, double bodyY, double bodyZ[, function callback (result)]) = {
 *   azimuth: double,            // xaz [0]
 *   trueAltitude: double,       // xaz [1]
 *   apparentAltitude: double    // xaz [2]
 * }
 */
NAN_METHOD(node_swe_azalt) {
	Nan::HandleScope scope;

	if (info.Length () < 10) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsNumber () ||
		!info [2]->IsNumber () ||
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

	double geopos [10] = {0};
	double xin [3] = {0};
	double xaz [3] = {0};

	geopos [0] = info [2]->NumberValue ();
	geopos [1] = info [3]->NumberValue ();
	geopos [2] = info [4]->NumberValue ();

	xin [0] = info [7]->NumberValue ();
	xin [1] = info [8]->NumberValue ();
	xin [2] = info [9]->NumberValue ();

	::swe_azalt (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		geopos,
		info [5]->NumberValue (),
		info [6]->NumberValue (),
		xin, xaz
	);

	Local <Object> result = Nan::New<Object> ();

	result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),				Nan::New<Number> (xaz [0]));
	result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),		Nan::New<Number> (xaz [1]));
	result->Set (Nan::New<String> ("apparentAltitude").ToLocalChecked(),	Nan::New<Number> (xaz [2]));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos (in[3]), double *xin (in[3]), double *xout (out[3]))
 * =>
 * swe_azalt_rev(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double bodyAzimuth, double bodyTrueAltitude[, function callback (result)]) = {
 *   azimuth: double,      // xout [0]
 *   trueAltitude: double  // xout [1]
 * }
 */
NAN_METHOD(node_swe_azalt_rev) {
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

	double geopos [10] = {0};
	double xin [3] = {0};
	double xout [3] = {0};

	geopos [0] = info [2]->NumberValue ();
	geopos [1] = info [3]->NumberValue ();
	geopos [2] = info [4]->NumberValue ();

	xin [0] = info [5]->NumberValue ();
	xin [1] = info [6]->NumberValue ();

	::swe_azalt_rev (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		geopos, xin, xout
	);

	Local <Object> result = Nan::New<Object> ();

	result->Set (Nan::New<String> ("azimuth").ToLocalChecked(),			Nan::New<Number> (xout [0]));
	result->Set (Nan::New<String> ("trueAltitude").ToLocalChecked(),	Nan::New<Number> (xout [1]));

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos (in[3]), double atpress, double attemp, double *tret (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   transitTime: double, // tret [0]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_rise_trans) {
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

	double geopos [10] = {0};
	double tret;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (info [2]->ToString ()));

	geopos [0] = info [5]->NumberValue ();
	geopos [1] = info [6]->NumberValue ();
	geopos [2] = info [7]->NumberValue ();

	rflag = ::swe_rise_trans (
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		star,
		(int)info [3]->NumberValue (),
		(int)info [4]->NumberValue (),
		geopos,
		info [8]->NumberValue (),
		info [9]->NumberValue (),
		&tret, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		result->Set (Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		result->Set (Nan::New<String> ("transitTime").ToLocalChecked(), Nan::New<Number> (tret));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32 method, double *xnasc (out[6]), double *xndsc (out[6]), double *xperi (out[6]), double *xaphe (out[6]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32 method[, function callback (result)]) = {
 *   ascending: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
 *   },
 *   descending: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
 *   },
 *   perihelion: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
 *   },
 *   aphelion: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
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
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		(int)info [2]->NumberValue (),
		(int)info [3]->NumberValue (),
		xnasc, xndsc, xperi, xaphe, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Local <Object> ascending = Nan::New<Object> ();
		ascending->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
		ascending->Set (Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
		ascending->Set (Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
		ascending->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
		ascending->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
		ascending->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
		result->Set (Nan::New<String> ("ascending").ToLocalChecked(), ascending);

		Local <Object> descending = Nan::New<Object> ();
		descending->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
		descending->Set (Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
		descending->Set (Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
		descending->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
		descending->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
		descending->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
		result->Set (Nan::New<String> ("descending").ToLocalChecked(), descending);

		Local <Object> perihelion = Nan::New<Object> ();
		perihelion->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
		perihelion->Set (Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
		perihelion->Set (Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
		perihelion->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
		perihelion->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
		perihelion->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
		result->Set (Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

		Local <Object> aphelion = Nan::New<Object> ();
		aphelion->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
		aphelion->Set (Nan::New<String> ("latitude").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
		aphelion->Set (Nan::New<String> ("distance").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
		aphelion->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
		aphelion->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
		aphelion->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [5]));
		result->Set (Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32  method, double *xnasc (out[6]), double *xndsc (out[6]), double *xperi (out[6]), double *xaphe (out[6]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32  method[, function callback (result)]) = {
 *   ascending: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
 *   },
 *   descending: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
 *   },
 *   perihelion: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
 *   },
 *   aphelion: {
 *     longitude: double,
 *     latitude: double,
 *     distance: double,
 *     longitudeSpeed: double,
 *     latitudeSpeed: double,
 *     distanceSpeed: double
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
		info [0]->NumberValue (),
		(int)info [1]->NumberValue (),
		(int)info [2]->NumberValue (),
		(int)info [3]->NumberValue (),
		xnasc, xndsc, xperi, xaphe, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		result->Set (Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Local <Object> ascending = Nan::New<Object> ();
		ascending->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [0]));
		ascending->Set (Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xnasc [1]));
		ascending->Set (Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xnasc [2]));
		ascending->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [3]));
		ascending->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [4]));
		ascending->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xnasc [5]));
		result->Set (Nan::New<String> ("ascending").ToLocalChecked(), ascending);

		Local <Object> descending = Nan::New<Object> ();
		descending->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [0]));
		descending->Set (Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xndsc [1]));
		descending->Set (Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xndsc [2]));
		descending->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [3]));
		descending->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [4]));
		descending->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xndsc [5]));
		result->Set (Nan::New<String> ("descending").ToLocalChecked(), descending);

		Local <Object> perihelion = Nan::New<Object> ();
		perihelion->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xperi [0]));
		perihelion->Set (Nan::New<String> ("latitude").ToLocalChecked(), 		Nan::New<Number> (xperi [1]));
		perihelion->Set (Nan::New<String> ("distance").ToLocalChecked(), 		Nan::New<Number> (xperi [2]));
		perihelion->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [3]));
		perihelion->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [4]));
		perihelion->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),	Nan::New<Number> (xperi [5]));
		result->Set (Nan::New<String> ("perihelion").ToLocalChecked(), perihelion);

		Local <Object> aphelion = Nan::New<Object> ();
		aphelion->Set (Nan::New<String> ("longitude").ToLocalChecked(), 		Nan::New<Number> (xaphe [0]));
		aphelion->Set (Nan::New<String> ("latitude").ToLocalChecked(), 			Nan::New<Number> (xaphe [1]));
		aphelion->Set (Nan::New<String> ("distance").ToLocalChecked(), 			Nan::New<Number> (xaphe [2]));
		aphelion->Set (Nan::New<String> ("longitudeSpeed").ToLocalChecked(),	Nan::New<Number> (xaphe [3]));
		aphelion->Set (Nan::New<String> ("latitudeSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [4]));
		aphelion->Set (Nan::New<String> ("distanceSpeed").ToLocalChecked(),		Nan::New<Number> (xaphe [5]));
		result->Set (Nan::New<String> ("aphelion").ToLocalChecked(), aphelion);
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};
