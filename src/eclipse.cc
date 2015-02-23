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
void node_swe_gauquelin_sector (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 10) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber () ||
		!args [7]->IsNumber () ||
		!args [8]->IsNumber () ||
		!args [9]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double dgsect;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (args [2]->ToString ()));

	geopos [0] = args [5]->NumberValue ();
	geopos [1] = args [6]->NumberValue ();
	geopos [2] = args [7]->NumberValue ();

	rflag = ::swe_gauquelin_sector (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		star,
		(int)args [3]->NumberValue (),
		(int)args [4]->NumberValue (),
		geopos,
		args [8]->NumberValue (),
		args [9]->NumberValue (),
		&dgsect, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, star));
		result->Set (String::NewFromUtf8 (isolate, "gauquelinSector"), Number::New (isolate, dgsect));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_sol_eclipse_where (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 2) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_sol_eclipse_where (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "longitude"),	Number::New (isolate, geopos [0]));
		result->Set (String::NewFromUtf8 (isolate, "latitude"),	Number::New (isolate, geopos [1]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiameterFraction"),		Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "lonarToSolarDiameterRatio"),	Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiscFraction"),			Number::New (isolate, attr [2]));
		result->Set (String::NewFromUtf8 (isolate, "coreShadow"),					Number::New (isolate, attr [3]));
		result->Set (String::NewFromUtf8 (isolate, "azimuth"),						Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),				Number::New (isolate, attr [5]));
		result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),			Number::New (isolate, attr [6]));
		result->Set (String::NewFromUtf8 (isolate, "moonToSunAngularDistance"),	Number::New (isolate, attr [7]));
		result->Set (String::NewFromUtf8 (isolate, "eclipseMagnitude"),			Number::New (isolate, attr [8]));
		result->Set (String::NewFromUtf8 (isolate, "sarosNumber"),					Number::New (isolate, attr [9]));
		result->Set (String::NewFromUtf8 (isolate, "sarosMember"),					Number::New (isolate, attr [10]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_lun_occult_where (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double attr [20] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (args [2]->ToString ()));

	rflag = ::swe_lun_occult_where (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		star,
		(int)args [3]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "longitude"),	Number::New (isolate, geopos [0]));
		result->Set (String::NewFromUtf8 (isolate, "latitude"),	Number::New (isolate, geopos [1]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiameterFraction"),		Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "lonarToSolarDiameterRatio"),	Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiscFraction"),			Number::New (isolate, attr [2]));
		result->Set (String::NewFromUtf8 (isolate, "coreShadow"),					Number::New (isolate, attr [3]));
		result->Set (String::NewFromUtf8 (isolate, "azimuth"),						Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),				Number::New (isolate, attr [5]));
		result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),			Number::New (isolate, attr [6]));
		result->Set (String::NewFromUtf8 (isolate, "moonToSunAngularDistance"),	Number::New (isolate, attr [7]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_sol_eclipse_how (const FunctionCallbackInfo <Value> & args) {
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
		!args [4]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	geopos [0] = args [2]->NumberValue ();
	geopos [1] = args [3]->NumberValue ();
	geopos [2] = args [4]->NumberValue ();

	rflag = ::swe_sol_eclipse_how (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "solarDiameterFraction"),		Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "lonarToSolarDiameterRatio"),	Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiscFraction"),			Number::New (isolate, attr [2]));
		result->Set (String::NewFromUtf8 (isolate, "coreShadow"),					Number::New (isolate, attr [3]));
		result->Set (String::NewFromUtf8 (isolate, "azimuth"),						Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),				Number::New (isolate, attr [5]));
		result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),			Number::New (isolate, attr [6]));
		result->Set (String::NewFromUtf8 (isolate, "moonToSunAngularDistance"),	Number::New (isolate, attr [7]));
		result->Set (String::NewFromUtf8 (isolate, "eclipseMagnitude"),			Number::New (isolate, attr [8]));
		result->Set (String::NewFromUtf8 (isolate, "sarosNumber"),					Number::New (isolate, attr [9]));
		result->Set (String::NewFromUtf8 (isolate, "sarosMember"),					Number::New (isolate, attr [10]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_sol_eclipse_when_loc (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 6) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double tret [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	geopos [0] = args [2]->NumberValue ();
	geopos [1] = args [3]->NumberValue ();
	geopos [2] = args [4]->NumberValue ();

	rflag = ::swe_sol_eclipse_when_loc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		geopos, tret, attr,
		(int)args [5]->NumberValue (),
		serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "maximum"),		Number::New (isolate, tret [0]));
		result->Set (String::NewFromUtf8 (isolate, "first"),		Number::New (isolate, tret [1]));
		result->Set (String::NewFromUtf8 (isolate, "second"),		Number::New (isolate, tret [2]));
		result->Set (String::NewFromUtf8 (isolate, "third"),		Number::New (isolate, tret [3]));
		result->Set (String::NewFromUtf8 (isolate, "forth"),		Number::New (isolate, tret [4]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiameterFraction"),		Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "lonarToSolarDiameterRatio"),	Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiscFraction"),			Number::New (isolate, attr [2]));
		result->Set (String::NewFromUtf8 (isolate, "coreShadow"),					Number::New (isolate, attr [3]));
		result->Set (String::NewFromUtf8 (isolate, "azimuth"),						Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),				Number::New (isolate, attr [5]));
		result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),			Number::New (isolate, attr [6]));
		result->Set (String::NewFromUtf8 (isolate, "moonToSunAngularDistance"),	Number::New (isolate, attr [7]));
		result->Set (String::NewFromUtf8 (isolate, "eclipseMagnitude"),			Number::New (isolate, attr [8]));
		result->Set (String::NewFromUtf8 (isolate, "sarosNumber"),					Number::New (isolate, attr [9]));
		result->Set (String::NewFromUtf8 (isolate, "sarosMember"),					Number::New (isolate, attr [10]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_lun_occult_when_loc (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 8) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber () ||
		!args [7]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double tret [10] = {0};
	double attr [20] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (args [2]->ToString ()));

	geopos [0] = args [4]->NumberValue ();
	geopos [1] = args [5]->NumberValue ();
	geopos [2] = args [6]->NumberValue ();

	rflag = ::swe_lun_occult_when_loc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		star,
		(int)args [3]->NumberValue (),
		geopos, tret, attr,
		(int)args [7]->NumberValue (),
		serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, star));
		result->Set (String::NewFromUtf8 (isolate, "maximum"),		Number::New (isolate, tret [0]));
		result->Set (String::NewFromUtf8 (isolate, "first"),		Number::New (isolate, tret [1]));
		result->Set (String::NewFromUtf8 (isolate, "second"),		Number::New (isolate, tret [2]));
		result->Set (String::NewFromUtf8 (isolate, "third"),		Number::New (isolate, tret [3]));
		result->Set (String::NewFromUtf8 (isolate, "forth"),		Number::New (isolate, tret [4]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiameterFraction"),		Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "lonarToSolarDiameterRatio"),	Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "solarDiscFraction"),			Number::New (isolate, attr [2]));
		result->Set (String::NewFromUtf8 (isolate, "coreShadow"),					Number::New (isolate, attr [3]));
		result->Set (String::NewFromUtf8 (isolate, "azimuth"),						Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),				Number::New (isolate, attr [5]));
		result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),			Number::New (isolate, attr [6]));
		result->Set (String::NewFromUtf8 (isolate, "moonToSunAngularDistance"),	Number::New (isolate, attr [7]));
		result->Set (String::NewFromUtf8 (isolate, "eclipseMagnitude"),			Number::New (isolate, attr [8]));
		result->Set (String::NewFromUtf8 (isolate, "sarosNumber"),					Number::New (isolate, attr [9]));
		result->Set (String::NewFromUtf8 (isolate, "sarosMember"),					Number::New (isolate, attr [10]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_sol_eclipse_when_glob (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double tret [10] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_sol_eclipse_when_glob (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		tret,
		(int)args [3]->NumberValue (),
		serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "maximum"),		Number::New (isolate, tret [0]));
		result->Set (String::NewFromUtf8 (isolate, "noon"),		Number::New (isolate, tret [1]));
		result->Set (String::NewFromUtf8 (isolate, "begin"),		Number::New (isolate, tret [2]));
		result->Set (String::NewFromUtf8 (isolate, "end"),			Number::New (isolate, tret [3]));
		result->Set (String::NewFromUtf8 (isolate, "totalBegin"),	Number::New (isolate, tret [4]));
		result->Set (String::NewFromUtf8 (isolate, "totalEnd"),	Number::New (isolate, tret [5]));
		result->Set (String::NewFromUtf8 (isolate, "centerBegin"),	Number::New (isolate, tret [6]));
		result->Set (String::NewFromUtf8 (isolate, "centerEnd"),	Number::New (isolate, tret [7]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_lun_occult_when_glob (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 6) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double tret [10] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (args [2]->ToString ()));

	rflag = ::swe_lun_occult_when_glob (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		star,
		(int)args [3]->NumberValue (),
		(int)args [4]->NumberValue (),
		tret,
		(int)args [5]->NumberValue (),
		serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, star));
		result->Set (String::NewFromUtf8 (isolate, "maximum"),		Number::New (isolate, tret [0]));
		result->Set (String::NewFromUtf8 (isolate, "noon"),		Number::New (isolate, tret [1]));
		result->Set (String::NewFromUtf8 (isolate, "begin"),		Number::New (isolate, tret [2]));
		result->Set (String::NewFromUtf8 (isolate, "end"),			Number::New (isolate, tret [3]));
		result->Set (String::NewFromUtf8 (isolate, "totalBegin"),	Number::New (isolate, tret [4]));
		result->Set (String::NewFromUtf8 (isolate, "totalEnd"),	Number::New (isolate, tret [5]));
		result->Set (String::NewFromUtf8 (isolate, "centerBegin"),	Number::New (isolate, tret [6]));
		result->Set (String::NewFromUtf8 (isolate, "centerEnd"),	Number::New (isolate, tret [7]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_lun_eclipse_how (const FunctionCallbackInfo <Value> & args) {
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
		!args [4]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double attr [20] = {0};
	char serr [AS_MAXCH];
	long rflag;

	geopos [0] = args [2]->NumberValue ();
	geopos [1] = args [3]->NumberValue ();
	geopos [2] = args [4]->NumberValue ();

	rflag = ::swe_lun_eclipse_how (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "umbralMagnitude"),		Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "penumbralMagnitude"),	Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "azimuth"),				Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),		Number::New (isolate, attr [5]));
		result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),	Number::New (isolate, attr [6]));
		result->Set (String::NewFromUtf8 (isolate, "oppositeDegreeDist"),	Number::New (isolate, attr [7]));
		result->Set (String::NewFromUtf8 (isolate, "magnitude"),			Number::New (isolate, attr [8]));
		result->Set (String::NewFromUtf8 (isolate, "sarosNumber"),			Number::New (isolate, attr [9]));
		result->Set (String::NewFromUtf8 (isolate, "sarosMember"),			Number::New (isolate, attr [10]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_lun_eclipse_when (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double tret [10] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_lun_eclipse_when (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		tret,
		(int)args [3]->NumberValue (),
		serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "maximum"),			Number::New (isolate, tret [0]));
		result->Set (String::NewFromUtf8 (isolate, "partialBegin"),	Number::New (isolate, tret [2]));
		result->Set (String::NewFromUtf8 (isolate, "partialEnd"),		Number::New (isolate, tret [3]));
		result->Set (String::NewFromUtf8 (isolate, "totalBegin"),		Number::New (isolate, tret [4]));
		result->Set (String::NewFromUtf8 (isolate, "totalEnd"),		Number::New (isolate, tret [5]));
		result->Set (String::NewFromUtf8 (isolate, "penumbralBegin"),	Number::New (isolate, tret [6]));
		result->Set (String::NewFromUtf8 (isolate, "penumbralEnd"),	Number::New (isolate, tret [7]));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_pheno (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 3) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double attr [20];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_pheno (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		attr, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "phaseAngle"), Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "phase"), Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "elongation"), Number::New (isolate, attr [2]));
		result->Set (String::NewFromUtf8 (isolate, "apparentDiameter"), Number::New (isolate, attr [3]));
		result->Set (String::NewFromUtf8 (isolate, "apparentMagnitude"), Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_pheno_ut (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 3) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double attr [20];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_pheno_ut (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		attr, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "phaseAngle"), Number::New (isolate, attr [0]));
		result->Set (String::NewFromUtf8 (isolate, "phase"), Number::New (isolate, attr [1]));
		result->Set (String::NewFromUtf8 (isolate, "elongation"), Number::New (isolate, attr [2]));
		result->Set (String::NewFromUtf8 (isolate, "apparentDiameter"), Number::New (isolate, attr [3]));
		result->Set (String::NewFromUtf8 (isolate, "apparentMagnitude"), Number::New (isolate, attr [4]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


};

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 * =>
 * swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double
 * }
 */
void node_swe_refrac (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double refraction;

	refraction = ::swe_refrac (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(int)args [3]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "refraction"), Number::New (isolate, refraction));

    HandleCallback (isolate, args, result);


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
void node_swe_refrac_extended (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 6) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double refraction;
	double dret [4];

	refraction = ::swe_refrac_extended (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		args [3]->NumberValue (),
		args [4]->NumberValue (),
		(int)args [5]->NumberValue (),
		dret
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "refraction"), Number::New (isolate, refraction));
	result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),		Number::New (isolate, dret [0]));
	result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),	Number::New (isolate, dret [1]));
	result->Set (String::NewFromUtf8 (isolate, "horizonDip"),			Number::New (isolate, dret [3]));

    HandleCallback (isolate, args, result);


};

/**
 * void swe_set_lapse_rate(double lapse_rate)
 * =>
 * swe_set_lapse_rate(double lapse_rate[, function callback (result)]) = {
 * }
 */
void node_swe_set_lapse_rate (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	::swe_set_lapse_rate (
        args [0]->NumberValue ()
	);

	Local <Object> result = Object::New (isolate);

    HandleCallback (isolate, args, result);


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
void node_swe_azalt (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 10) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber () ||
		!args [7]->IsNumber () ||
		!args [8]->IsNumber () ||
		!args [9]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double xin [3] = {0};
	double xaz [3] = {0};

	geopos [0] = args [2]->NumberValue ();
	geopos [1] = args [3]->NumberValue ();
	geopos [2] = args [4]->NumberValue ();

	xin [0] = args [7]->NumberValue ();
	xin [1] = args [8]->NumberValue ();
	xin [2] = args [9]->NumberValue ();

	::swe_azalt (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		geopos,
		args [5]->NumberValue (),
		args [6]->NumberValue (),
		xin, xaz
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "azimuth"),				Number::New (isolate, xaz [0]));
	result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),		Number::New (isolate, xaz [1]));
	result->Set (String::NewFromUtf8 (isolate, "apparentAltitude"),	Number::New (isolate, xaz [2]));

    HandleCallback (isolate, args, result);


};

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos (in[3]), double *xin (in[3]), double *xout (out[3]))
 * =>
 * swe_azalt_rev(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double bodyAzimuth, double bodyTrueAltitude[, function callback (result)]) = {
 *   azimuth: double,      // xout [0]
 *   trueAltitude: double  // xout [1]
 * }
 */
void node_swe_azalt_rev (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 7) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double xin [3] = {0};
	double xout [3] = {0};

	geopos [0] = args [2]->NumberValue ();
	geopos [1] = args [3]->NumberValue ();
	geopos [2] = args [4]->NumberValue ();

	xin [0] = args [5]->NumberValue ();
	xin [1] = args [6]->NumberValue ();

	::swe_azalt_rev (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		geopos, xin, xout
	);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "azimuth"),			Number::New (isolate, xout [0]));
	result->Set (String::NewFromUtf8 (isolate, "trueAltitude"),	Number::New (isolate, xout [1]));

    HandleCallback (isolate, args, result);


};

/**
 * int32 swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos (in[3]), double atpress, double attemp, double *tret (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   transitTime: double, // tret [0]
 *   error: string
 * }
 */
void node_swe_rise_trans (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 10) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber () ||
		!args [7]->IsNumber () ||
		!args [8]->IsNumber () ||
		!args [9]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double geopos [10] = {0};
	double tret;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::Utf8Value (args [2]->ToString ()));

	geopos [0] = args [5]->NumberValue ();
	geopos [1] = args [6]->NumberValue ();
	geopos [2] = args [7]->NumberValue ();

	rflag = ::swe_rise_trans (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		star,
		(int)args [3]->NumberValue (),
		(int)args [4]->NumberValue (),
		geopos,
		args [8]->NumberValue (),
		args [9]->NumberValue (),
		&tret, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, star));
		result->Set (String::NewFromUtf8 (isolate, "transitTime"), Number::New (isolate, tret));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_nod_aps (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double xnasc [6] = {0};
	double xndsc [6] = {0};
	double xperi [6] = {0};
	double xaphe [6] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_nod_aps (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		(int)args [3]->NumberValue (),
		xnasc, xndsc, xperi, xaphe, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		Local <Object> ascending = Object::New (isolate);
		ascending->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xnasc [0]));
		ascending->Set (String::NewFromUtf8 (isolate, "latitude"), 		Number::New (isolate, xnasc [1]));
		ascending->Set (String::NewFromUtf8 (isolate, "distance"), 		Number::New (isolate, xnasc [2]));
		ascending->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xnasc [3]));
		ascending->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),	Number::New (isolate, xnasc [4]));
		ascending->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),	Number::New (isolate, xnasc [5]));
		result->Set (String::NewFromUtf8 (isolate, "ascending"), ascending);

		Local <Object> descending = Object::New (isolate);
		descending->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xndsc [0]));
		descending->Set (String::NewFromUtf8 (isolate, "latitude"), 		Number::New (isolate, xndsc [1]));
		descending->Set (String::NewFromUtf8 (isolate, "distance"), 		Number::New (isolate, xndsc [2]));
		descending->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xndsc [3]));
		descending->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),	Number::New (isolate, xndsc [4]));
		descending->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),	Number::New (isolate, xndsc [5]));
		result->Set (String::NewFromUtf8 (isolate, "descending"), descending);

		Local <Object> perihelion = Object::New (isolate);
		perihelion->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xperi [0]));
		perihelion->Set (String::NewFromUtf8 (isolate, "latitude"), 		Number::New (isolate, xperi [1]));
		perihelion->Set (String::NewFromUtf8 (isolate, "distance"), 		Number::New (isolate, xperi [2]));
		perihelion->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xperi [3]));
		perihelion->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),	Number::New (isolate, xperi [4]));
		perihelion->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),	Number::New (isolate, xperi [5]));
		result->Set (String::NewFromUtf8 (isolate, "perihelion"), perihelion);

		Local <Object> aphelion = Object::New (isolate);
		aphelion->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xaphe [0]));
		aphelion->Set (String::NewFromUtf8 (isolate, "latitude"), 			Number::New (isolate, xaphe [1]));
		aphelion->Set (String::NewFromUtf8 (isolate, "distance"), 			Number::New (isolate, xaphe [2]));
		aphelion->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xaphe [3]));
		aphelion->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),		Number::New (isolate, xaphe [4]));
		aphelion->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),		Number::New (isolate, xaphe [5]));
		result->Set (String::NewFromUtf8 (isolate, "aphelion"), aphelion);
	};

    HandleCallback (isolate, args, result);


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
void node_swe_nod_aps_ut (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 4) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double xnasc [6] = {0};
	double xndsc [6] = {0};
	double xperi [6] = {0};
	double xaphe [6] = {0};
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_nod_aps_ut (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		(int)args [3]->NumberValue (),
		xnasc, xndsc, xperi, xaphe, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		Local <Object> ascending = Object::New (isolate);
		ascending->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xnasc [0]));
		ascending->Set (String::NewFromUtf8 (isolate, "latitude"), 		Number::New (isolate, xnasc [1]));
		ascending->Set (String::NewFromUtf8 (isolate, "distance"), 		Number::New (isolate, xnasc [2]));
		ascending->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xnasc [3]));
		ascending->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),	Number::New (isolate, xnasc [4]));
		ascending->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),	Number::New (isolate, xnasc [5]));
		result->Set (String::NewFromUtf8 (isolate, "ascending"), ascending);

		Local <Object> descending = Object::New (isolate);
		descending->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xndsc [0]));
		descending->Set (String::NewFromUtf8 (isolate, "latitude"), 		Number::New (isolate, xndsc [1]));
		descending->Set (String::NewFromUtf8 (isolate, "distance"), 		Number::New (isolate, xndsc [2]));
		descending->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xndsc [3]));
		descending->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),	Number::New (isolate, xndsc [4]));
		descending->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),	Number::New (isolate, xndsc [5]));
		result->Set (String::NewFromUtf8 (isolate, "descending"), descending);

		Local <Object> perihelion = Object::New (isolate);
		perihelion->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xperi [0]));
		perihelion->Set (String::NewFromUtf8 (isolate, "latitude"), 		Number::New (isolate, xperi [1]));
		perihelion->Set (String::NewFromUtf8 (isolate, "distance"), 		Number::New (isolate, xperi [2]));
		perihelion->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xperi [3]));
		perihelion->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),	Number::New (isolate, xperi [4]));
		perihelion->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),	Number::New (isolate, xperi [5]));
		result->Set (String::NewFromUtf8 (isolate, "perihelion"), perihelion);

		Local <Object> aphelion = Object::New (isolate);
		aphelion->Set (String::NewFromUtf8 (isolate, "longitude"), 		Number::New (isolate, xaphe [0]));
		aphelion->Set (String::NewFromUtf8 (isolate, "latitude"), 			Number::New (isolate, xaphe [1]));
		aphelion->Set (String::NewFromUtf8 (isolate, "distance"), 			Number::New (isolate, xaphe [2]));
		aphelion->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"),	Number::New (isolate, xaphe [3]));
		aphelion->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"),		Number::New (isolate, xaphe [4]));
		aphelion->Set (String::NewFromUtf8 (isolate, "distanceSpeed"),		Number::New (isolate, xaphe [5]));
		result->Set (String::NewFromUtf8 (isolate, "aphelion"), aphelion);
	};

    HandleCallback (isolate, args, result);


};
