#include "swisseph.h"

using namespace v8;

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

	double geopos [10] = {0};
	double dgsect;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	geopos [0] = info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [7]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_gauquelin_sector (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		star,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos,
		info [8]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [9]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&dgsect, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("gauquelinSector").ToLocalChecked(), Nan::New<Number> (dgsect));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_sol_eclipse_where(double tjd_ut, int32 ifl, double *geopos (out[10]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_where(double tjd_ut, int32 ifl[, function callback (result)]) = {
 *   rflag: long,
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
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	                    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(),	                Nan::New<Number> (geopos [0]));
		Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(),	                Nan::New<Number> (geopos [1]));
		Nan::Set(result,Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		Nan::Set(result,Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		Nan::Set(result,Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		Nan::Set(result,Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		Nan::Set(result,Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		Nan::Set(result,Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_lun_occult_where(double tjd_ut, int32 ipl, char *starname, int32 ifl, double *geopos (out[10]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_where(double tjd_ut, int32 ipl, char *starname, int32 ifl[, function callback (result)]) = {
 *   rflag: long,
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

	::strcpy (star, * String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_lun_occult_where (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		star,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	                    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("longitude").ToLocalChecked(),	                Nan::New<Number> (geopos [0]));
		Nan::Set(result,Nan::New<String> ("latitude").ToLocalChecked(),	                Nan::New<Number> (geopos [1]));
		Nan::Set(result,Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		Nan::Set(result,Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		Nan::Set(result,Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_sol_eclipse_how(double tjd_ut, int32 ifl, double *geopos (in[3]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_how(double tjd_ut, int32 ifl, double longitude, double latitude, double height[, function callback (result)]) = {
 *   rflag: long,
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

	geopos [0] = info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_sol_eclipse_how (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	                    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		Nan::Set(result,Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		Nan::Set(result,Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		Nan::Set(result,Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		Nan::Set(result,Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		Nan::Set(result,Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   rflag: long,
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

	geopos [0] = info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_sol_eclipse_when_loc (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, tret, attr,
		(int)info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	                    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("maximum").ToLocalChecked(),		Nan::New<Number> (tret [0]));
		Nan::Set(result,Nan::New<String> ("first").ToLocalChecked(),		Nan::New<Number> (tret [1]));
		Nan::Set(result,Nan::New<String> ("second").ToLocalChecked(),		Nan::New<Number> (tret [2]));
		Nan::Set(result,Nan::New<String> ("third").ToLocalChecked(),		Nan::New<Number> (tret [3]));
		Nan::Set(result,Nan::New<String> ("forth").ToLocalChecked(),		Nan::New<Number> (tret [4]));
		Nan::Set(result,Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		Nan::Set(result,Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		Nan::Set(result,Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		Nan::Set(result,Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		Nan::Set(result,Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		Nan::Set(result,Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   name: string,                         // star 
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

	::strcpy (star, * String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	geopos [0] = info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_lun_occult_when_loc (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		star,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, tret, attr,
		(int)info [7]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	                    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(),                        Nan::New<String> (star).ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("maximum").ToLocalChecked(),		                Nan::New<Number> (tret [0]));
		Nan::Set(result,Nan::New<String> ("first").ToLocalChecked(),		                Nan::New<Number> (tret [1]));
		Nan::Set(result,Nan::New<String> ("second").ToLocalChecked(),		                Nan::New<Number> (tret [2]));
		Nan::Set(result,Nan::New<String> ("third").ToLocalChecked(),		                Nan::New<Number> (tret [3]));
		Nan::Set(result,Nan::New<String> ("forth").ToLocalChecked(),		                Nan::New<Number> (tret [4]));
		Nan::Set(result,Nan::New<String> ("solarDiameterFraction").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("lonarToSolarDiameterRatio").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("solarDiscFraction").ToLocalChecked(),			Nan::New<Number> (attr [2]));
		Nan::Set(result,Nan::New<String> ("coreShadow").ToLocalChecked(),					Nan::New<Number> (attr [3]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),						Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		Nan::Set(result,Nan::New<String> ("moonToSunAngularDistance").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		Nan::Set(result,Nan::New<String> ("eclipseMagnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		Nan::Set(result,Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		Nan::Set(result,Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, double *tret (out[10]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   rflag: long,
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
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		tret,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("maximum").ToLocalChecked(),		Nan::New<Number> (tret [0]));
		Nan::Set(result,Nan::New<String> ("noon").ToLocalChecked(),		Nan::New<Number> (tret [1]));
		Nan::Set(result,Nan::New<String> ("begin").ToLocalChecked(),		Nan::New<Number> (tret [2]));
		Nan::Set(result,Nan::New<String> ("end").ToLocalChecked(),			Nan::New<Number> (tret [3]));
		Nan::Set(result,Nan::New<String> ("totalBegin").ToLocalChecked(),	Nan::New<Number> (tret [4]));
		Nan::Set(result,Nan::New<String> ("totalEnd").ToLocalChecked(),	Nan::New<Number> (tret [5]));
		Nan::Set(result,Nan::New<String> ("centerBegin").ToLocalChecked(),	Nan::New<Number> (tret [6]));
		Nan::Set(result,Nan::New<String> ("centerEnd").ToLocalChecked(),	Nan::New<Number> (tret [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, double *tret (out[10]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   name: string,         // star
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

	::strcpy (star, * String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_lun_occult_when_glob (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		star,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		tret,
		(int)info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(),        Nan::New<String> (star).ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("maximum").ToLocalChecked(),		Nan::New<Number> (tret [0]));
		Nan::Set(result,Nan::New<String> ("noon").ToLocalChecked(),		Nan::New<Number> (tret [1]));
		Nan::Set(result,Nan::New<String> ("begin").ToLocalChecked(),		Nan::New<Number> (tret [2]));
		Nan::Set(result,Nan::New<String> ("end").ToLocalChecked(),			Nan::New<Number> (tret [3]));
		Nan::Set(result,Nan::New<String> ("totalBegin").ToLocalChecked(),	Nan::New<Number> (tret [4]));
		Nan::Set(result,Nan::New<String> ("totalEnd").ToLocalChecked(),	Nan::New<Number> (tret [5]));
		Nan::Set(result,Nan::New<String> ("centerBegin").ToLocalChecked(),	Nan::New<Number> (tret [6]));
		Nan::Set(result,Nan::New<String> ("centerEnd").ToLocalChecked(),	Nan::New<Number> (tret [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_lun_eclipse_how(double tjd_ut, int32 ifl, double *geopos (in[3]), double *attr (out[20]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_eclipse_how(double tjd_ut, int32 ifl, double longitude, double latitude, double height[, function callback (result)]) = {
 *   rflag: long,
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

	geopos [0] = info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_lun_eclipse_how (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	            Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("umbralMagnitude").ToLocalChecked(),		Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("penumbralMagnitude").ToLocalChecked(),	Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),				Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),		Nan::New<Number> (attr [5]));
		Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),	Nan::New<Number> (attr [6]));
		Nan::Set(result,Nan::New<String> ("oppositeDegreeDist").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		Nan::Set(result,Nan::New<String> ("magnitude").ToLocalChecked(),			Nan::New<Number> (attr [8]));
		Nan::Set(result,Nan::New<String> ("sarosNumber").ToLocalChecked(),			Nan::New<Number> (attr [9]));
		Nan::Set(result,Nan::New<String> ("sarosMember").ToLocalChecked(),			Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, double *tret (out[10]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   rflag: long,
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
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		tret,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	        Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("maximum").ToLocalChecked(),			Nan::New<Number> (tret [0]));
		Nan::Set(result,Nan::New<String> ("partialBegin").ToLocalChecked(),	Nan::New<Number> (tret [2]));
		Nan::Set(result,Nan::New<String> ("partialEnd").ToLocalChecked(),		Nan::New<Number> (tret [3]));
		Nan::Set(result,Nan::New<String> ("totalBegin").ToLocalChecked(),		Nan::New<Number> (tret [4]));
		Nan::Set(result,Nan::New<String> ("totalEnd").ToLocalChecked(),		Nan::New<Number> (tret [5]));
		Nan::Set(result,Nan::New<String> ("penumbralBegin").ToLocalChecked(),	Nan::New<Number> (tret [6]));
		Nan::Set(result,Nan::New<String> ("penumbralEnd").ToLocalChecked(),	Nan::New<Number> (tret [7]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_lun_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_eclipse_when_loc(double tjd_start, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   maximum: double,                      // tret [0]
 *   partialBegin: double,                 // tret [2]
 *   partialEnd: double,                   // tret [3]
 *   totalBegin: double,                   // tret [4]
 *   totalEnd: double,                     // tret [5]
 *   penumbralBegin: double,               // tret [6]
 *   penumbralEnd: double,                 // tret [7]
 *   moonRise: double                      // tret [8]
 *   moonSet: double,                      // tret [9]
 *   umbralMagnitude: double,              // attr [0]
 *   penumbralMagnitude: double,           // attr [1]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonDistanceFromOpposition: double,   // attr [7]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_eclipse_when_loc) {
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

	geopos [0] = info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_lun_eclipse_when_loc (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, tret, attr,
		(int)info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),	                    Nan::New<Number> (rflag));
		Nan::Set(result,Nan::New<String> ("maximum").ToLocalChecked(),			            Nan::New<Number> (tret [0]));
		Nan::Set(result,Nan::New<String> ("partialBegin").ToLocalChecked(),	            Nan::New<Number> (tret [2]));
		Nan::Set(result,Nan::New<String> ("partialEnd").ToLocalChecked(),		            Nan::New<Number> (tret [3]));
		Nan::Set(result,Nan::New<String> ("totalBegin").ToLocalChecked(),		            Nan::New<Number> (tret [4]));
		Nan::Set(result,Nan::New<String> ("totalEnd").ToLocalChecked(),		            Nan::New<Number> (tret [5]));
		Nan::Set(result,Nan::New<String> ("penumbralBegin").ToLocalChecked(),	            Nan::New<Number> (tret [6]));
		Nan::Set(result,Nan::New<String> ("penumbralEnd").ToLocalChecked(),	            Nan::New<Number> (tret [7]));
		Nan::Set(result,Nan::New<String> ("moonRise").ToLocalChecked(),	                Nan::New<Number> (tret [8]));
		Nan::Set(result,Nan::New<String> ("moonSet").ToLocalChecked(),	                    Nan::New<Number> (tret [9]));
		Nan::Set(result,Nan::New<String> ("umbralMagnitude").ToLocalChecked(),		        Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("penumbralMagnitude").ToLocalChecked(),	        Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),			            Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),				Nan::New<Number> (attr [5]));
		Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),			Nan::New<Number> (attr [6]));
		Nan::Set(result,Nan::New<String> ("moonDistanceFromOpposition").ToLocalChecked(),	Nan::New<Number> (attr [7]));
		Nan::Set(result,Nan::New<String> ("sarosNumber").ToLocalChecked(),					Nan::New<Number> (attr [9]));
		Nan::Set(result,Nan::New<String> ("sarosMember").ToLocalChecked(),					Nan::New<Number> (attr [10]));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_pheno(double tjd, int32 ipl, int32 iflag, double *attr, char *serr (out[AS_MAXCH]))
 * =>
 * swe_pheno(double tjd, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   rflag: number,
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
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("phaseAngle").ToLocalChecked(), Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("phase").ToLocalChecked(), Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("elongation").ToLocalChecked(), Nan::New<Number> (attr [2]));
		Nan::Set(result,Nan::New<String> ("apparentDiameter").ToLocalChecked(), Nan::New<Number> (attr [3]));
		Nan::Set(result,Nan::New<String> ("apparentMagnitude").ToLocalChecked(), Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_pheno_ut(double tjd_ut, int32 ipl, int32 iflag, double *attr, char *serr (out[AS_MAXCH]))
 * =>
 * swe_pheno_ut(double tjd_ut, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   rflag: number,
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
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		attr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("phaseAngle").ToLocalChecked(), Nan::New<Number> (attr [0]));
		Nan::Set(result,Nan::New<String> ("phase").ToLocalChecked(), Nan::New<Number> (attr [1]));
		Nan::Set(result,Nan::New<String> ("elongation").ToLocalChecked(), Nan::New<Number> (attr [2]));
		Nan::Set(result,Nan::New<String> ("apparentDiameter").ToLocalChecked(), Nan::New<Number> (attr [3]));
		Nan::Set(result,Nan::New<String> ("apparentMagnitude").ToLocalChecked(), Nan::New<Number> (attr [4]));
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
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
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("refraction").ToLocalChecked(), Nan::New<Number> (refraction));

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
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
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		dret
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("refraction").ToLocalChecked(), Nan::New<Number> (refraction));
	Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),		Nan::New<Number> (dret [0]));
	Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),	Nan::New<Number> (dret [1]));
	Nan::Set(result,Nan::New<String> ("horizonDip").ToLocalChecked(),			Nan::New<Number> (dret [3]));

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
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
        info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked()
	);

	Local <Object> result = Nan::New<Object> ();

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
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

	geopos [0] = info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	xin [0] = info [7]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xin [1] = info [8]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xin [2] = info [9]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	::swe_azalt (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos,
		info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		xin, xaz
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),				Nan::New<Number> (xaz [0]));
	Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),		Nan::New<Number> (xaz [1]));
	Nan::Set(result,Nan::New<String> ("apparentAltitude").ToLocalChecked(),	Nan::New<Number> (xaz [2]));

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
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

	geopos [0] = info [2]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	xin [0] = info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	xin [1] = info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	::swe_azalt_rev (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos, xin, xout
	);

	Local <Object> result = Nan::New<Object> ();

	Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),			Nan::New<Number> (xout [0]));
	Nan::Set(result,Nan::New<String> ("trueAltitude").ToLocalChecked(),	Nan::New<Number> (xout [1]));

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos (in[3]), double atpress, double attemp, double *tret (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   name: string,        // star
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

	::strcpy (star, * String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	geopos [0] = info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [7]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_rise_trans (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		star,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos,
		info [8]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [9]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&tret, serr
	);

	Local <Object> result = Nan::New<Object> ();
	
	// http://www.astro.com/swisseph/swephprg.htm#_Toc433200782
	if (rflag == -1) {     //  if an error occurred (usually an ephemeris problem)
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		if (rflag == -2) { // if a rising or setting event was not found because the object is circumpolar  
			tret = -2;
		};
		Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("transitTime").ToLocalChecked(), Nan::New<Number> (tret));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};

/**
 * int32 swe_rise_trans_true_hor(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos (in[3]), double atpress, double attemp, double horhgt, double *tret (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_rise_trans_true_hor(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double longitude, double latitude, double height, double atpress, double horhgt, double attemp[, function callback (result)]) = {
 *   name: string,        // star
 *   transitTime: double, // tret [0]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_rise_trans_true_hor) {
	Nan::HandleScope scope;

	if (info.Length () < 11) {
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
		!info [9]->IsNumber () ||
		!info [10]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double geopos [10] = {0};
	double tret;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (Isolate::GetCurrent(), info [2]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	geopos [0] = info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [1] = info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked();
	geopos [2] = info [7]->NumberValue (Nan::GetCurrentContext()).ToChecked();

	rflag = ::swe_rise_trans_true_hor (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [1]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		star,
		(int)info [3]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [4]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		geopos,
		info [8]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [9]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		info [10]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		&tret, serr
	);

	Local <Object> result = Nan::New<Object> ();

	// http://www.astro.com/swisseph/swephprg.htm#_Toc433200782
	if (rflag == -1) {     //  if an error occurred (usually an ephemeris problem)
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		if (rflag == -2) { // if a rising or setting event was not found because the object is circumpolar  
			tret = -2;
		};
		Nan::Set(result,Nan::New<String> ("name").ToLocalChecked(), Nan::New<String> (star).ToLocalChecked());
		Nan::Set(result,Nan::New<String> ("transitTime").ToLocalChecked(), Nan::New<Number> (tret));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set(result);
};