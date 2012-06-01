#define BUILDING_NODE_EXTENSION

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
Handle <Value> node_swe_gauquelin_sector (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 10) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
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
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double geopos [10] = {0};
	double dgsect;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::AsciiValue (args [2]->ToString ()));

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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("name"), String::New (star));
		result->Set (String::NewSymbol ("gauquelinSector"), Number::New (dgsect));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_sol_eclipse_where (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 2) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("longitude"),	Number::New (geopos [0]));
		result->Set (String::NewSymbol ("latitude"),	Number::New (geopos [1]));
		result->Set (String::NewSymbol ("solarDiameterFraction"),		Number::New (attr [0]));
		result->Set (String::NewSymbol ("lonarToSolarDiameterRatio"),	Number::New (attr [1]));
		result->Set (String::NewSymbol ("solarDiscFraction"),			Number::New (attr [2]));
		result->Set (String::NewSymbol ("coreShadow"),					Number::New (attr [3]));
		result->Set (String::NewSymbol ("azimuth"),						Number::New (attr [4]));
		result->Set (String::NewSymbol ("trueAltitude"),				Number::New (attr [5]));
		result->Set (String::NewSymbol ("apparentAltitude"),			Number::New (attr [6]));
		result->Set (String::NewSymbol ("moonToSunAngularDistance"),	Number::New (attr [7]));
		result->Set (String::NewSymbol ("eclipseMagnitude"),			Number::New (attr [8]));
		result->Set (String::NewSymbol ("sarosNumber"),					Number::New (attr [9]));
		result->Set (String::NewSymbol ("sarosMember"),					Number::New (attr [10]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_lun_occult_where (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double geopos [10] = {0};
	double attr [20] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::AsciiValue (args [2]->ToString ()));

	rflag = ::swe_lun_occult_where (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		star,
		(int)args [3]->NumberValue (),
		geopos, attr, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("longitude"),	Number::New (geopos [0]));
		result->Set (String::NewSymbol ("latitude"),	Number::New (geopos [1]));
		result->Set (String::NewSymbol ("solarDiameterFraction"),		Number::New (attr [0]));
		result->Set (String::NewSymbol ("lonarToSolarDiameterRatio"),	Number::New (attr [1]));
		result->Set (String::NewSymbol ("solarDiscFraction"),			Number::New (attr [2]));
		result->Set (String::NewSymbol ("coreShadow"),					Number::New (attr [3]));
		result->Set (String::NewSymbol ("azimuth"),						Number::New (attr [4]));
		result->Set (String::NewSymbol ("trueAltitude"),				Number::New (attr [5]));
		result->Set (String::NewSymbol ("apparentAltitude"),			Number::New (attr [6]));
		result->Set (String::NewSymbol ("moonToSunAngularDistance"),	Number::New (attr [7]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_sol_eclipse_how (const Arguments & args) {
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
		!args [4]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("solarDiameterFraction"),		Number::New (attr [0]));
		result->Set (String::NewSymbol ("lonarToSolarDiameterRatio"),	Number::New (attr [1]));
		result->Set (String::NewSymbol ("solarDiscFraction"),			Number::New (attr [2]));
		result->Set (String::NewSymbol ("coreShadow"),					Number::New (attr [3]));
		result->Set (String::NewSymbol ("azimuth"),						Number::New (attr [4]));
		result->Set (String::NewSymbol ("trueAltitude"),				Number::New (attr [5]));
		result->Set (String::NewSymbol ("apparentAltitude"),			Number::New (attr [6]));
		result->Set (String::NewSymbol ("moonToSunAngularDistance"),	Number::New (attr [7]));
		result->Set (String::NewSymbol ("eclipseMagnitude"),			Number::New (attr [8]));
		result->Set (String::NewSymbol ("sarosNumber"),					Number::New (attr [9]));
		result->Set (String::NewSymbol ("sarosMember"),					Number::New (attr [10]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_sol_eclipse_when_loc (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 6) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("maximum"),		Number::New (tret [0]));
		result->Set (String::NewSymbol ("first"),		Number::New (tret [1]));
		result->Set (String::NewSymbol ("second"),		Number::New (tret [2]));
		result->Set (String::NewSymbol ("third"),		Number::New (tret [3]));
		result->Set (String::NewSymbol ("forth"),		Number::New (tret [4]));
		result->Set (String::NewSymbol ("solarDiameterFraction"),		Number::New (attr [0]));
		result->Set (String::NewSymbol ("lonarToSolarDiameterRatio"),	Number::New (attr [1]));
		result->Set (String::NewSymbol ("solarDiscFraction"),			Number::New (attr [2]));
		result->Set (String::NewSymbol ("coreShadow"),					Number::New (attr [3]));
		result->Set (String::NewSymbol ("azimuth"),						Number::New (attr [4]));
		result->Set (String::NewSymbol ("trueAltitude"),				Number::New (attr [5]));
		result->Set (String::NewSymbol ("apparentAltitude"),			Number::New (attr [6]));
		result->Set (String::NewSymbol ("moonToSunAngularDistance"),	Number::New (attr [7]));
		result->Set (String::NewSymbol ("eclipseMagnitude"),			Number::New (attr [8]));
		result->Set (String::NewSymbol ("sarosNumber"),					Number::New (attr [9]));
		result->Set (String::NewSymbol ("sarosMember"),					Number::New (attr [10]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_lun_occult_when_loc (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 8) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
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
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double geopos [10] = {0};
	double tret [10] = {0};
	double attr [20] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::AsciiValue (args [2]->ToString ()));

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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("name"), String::New (star));
		result->Set (String::NewSymbol ("maximum"),		Number::New (tret [0]));
		result->Set (String::NewSymbol ("first"),		Number::New (tret [1]));
		result->Set (String::NewSymbol ("second"),		Number::New (tret [2]));
		result->Set (String::NewSymbol ("third"),		Number::New (tret [3]));
		result->Set (String::NewSymbol ("forth"),		Number::New (tret [4]));
		result->Set (String::NewSymbol ("solarDiameterFraction"),		Number::New (attr [0]));
		result->Set (String::NewSymbol ("lonarToSolarDiameterRatio"),	Number::New (attr [1]));
		result->Set (String::NewSymbol ("solarDiscFraction"),			Number::New (attr [2]));
		result->Set (String::NewSymbol ("coreShadow"),					Number::New (attr [3]));
		result->Set (String::NewSymbol ("azimuth"),						Number::New (attr [4]));
		result->Set (String::NewSymbol ("trueAltitude"),				Number::New (attr [5]));
		result->Set (String::NewSymbol ("apparentAltitude"),			Number::New (attr [6]));
		result->Set (String::NewSymbol ("moonToSunAngularDistance"),	Number::New (attr [7]));
		result->Set (String::NewSymbol ("eclipseMagnitude"),			Number::New (attr [8]));
		result->Set (String::NewSymbol ("sarosNumber"),					Number::New (attr [9]));
		result->Set (String::NewSymbol ("sarosMember"),					Number::New (attr [10]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_sol_eclipse_when_glob (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("maximum"),		Number::New (tret [0]));
		result->Set (String::NewSymbol ("noon"),		Number::New (tret [1]));
		result->Set (String::NewSymbol ("begin"),		Number::New (tret [2]));
		result->Set (String::NewSymbol ("end"),			Number::New (tret [3]));
		result->Set (String::NewSymbol ("totalBegin"),	Number::New (tret [4]));
		result->Set (String::NewSymbol ("totalEnd"),	Number::New (tret [5]));
		result->Set (String::NewSymbol ("centerBegin"),	Number::New (tret [6]));
		result->Set (String::NewSymbol ("centerEnd"),	Number::New (tret [7]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_lun_occult_when_glob (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 6) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double tret [10] = {0};
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::AsciiValue (args [2]->ToString ()));

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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("name"), String::New (star));
		result->Set (String::NewSymbol ("maximum"),		Number::New (tret [0]));
		result->Set (String::NewSymbol ("noon"),		Number::New (tret [1]));
		result->Set (String::NewSymbol ("begin"),		Number::New (tret [2]));
		result->Set (String::NewSymbol ("end"),			Number::New (tret [3]));
		result->Set (String::NewSymbol ("totalBegin"),	Number::New (tret [4]));
		result->Set (String::NewSymbol ("totalEnd"),	Number::New (tret [5]));
		result->Set (String::NewSymbol ("centerBegin"),	Number::New (tret [6]));
		result->Set (String::NewSymbol ("centerEnd"),	Number::New (tret [7]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_lun_eclipse_how (const Arguments & args) {
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
		!args [4]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("umbralMagnitude"),		Number::New (attr [0]));
		result->Set (String::NewSymbol ("penumbralMagnitude"),	Number::New (attr [1]));
		result->Set (String::NewSymbol ("azimuth"),				Number::New (attr [4]));
		result->Set (String::NewSymbol ("trueAltitude"),		Number::New (attr [5]));
		result->Set (String::NewSymbol ("apparentAltitude"),	Number::New (attr [6]));
		result->Set (String::NewSymbol ("oppositeDegreeDist"),	Number::New (attr [7]));
		result->Set (String::NewSymbol ("magnitude"),			Number::New (attr [8]));
		result->Set (String::NewSymbol ("sarosNumber"),			Number::New (attr [9]));
		result->Set (String::NewSymbol ("sarosMember"),			Number::New (attr [10]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_lun_eclipse_when (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("maximum"),			Number::New (tret [0]));
		result->Set (String::NewSymbol ("partialBegin"),	Number::New (tret [2]));
		result->Set (String::NewSymbol ("partialEnd"),		Number::New (tret [3]));
		result->Set (String::NewSymbol ("totalBegin"),		Number::New (tret [4]));
		result->Set (String::NewSymbol ("totalEnd"),		Number::New (tret [5]));
		result->Set (String::NewSymbol ("penumbralBegin"),	Number::New (tret [6]));
		result->Set (String::NewSymbol ("penumbralEnd"),	Number::New (tret [7]));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_pheno (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 3) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("phaseAngle"), Number::New (attr [0]));
		result->Set (String::NewSymbol ("phase"), Number::New (attr [1]));
		result->Set (String::NewSymbol ("elongation"), Number::New (attr [2]));
		result->Set (String::NewSymbol ("apparentDiameter"), Number::New (attr [3]));
		result->Set (String::NewSymbol ("apparentMagnitude"), Number::New (attr [4]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_pheno_ut (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 3) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("phaseAngle"), Number::New (attr [0]));
		result->Set (String::NewSymbol ("phase"), Number::New (attr [1]));
		result->Set (String::NewSymbol ("elongation"), Number::New (attr [2]));
		result->Set (String::NewSymbol ("apparentDiameter"), Number::New (attr [3]));
		result->Set (String::NewSymbol ("apparentMagnitude"), Number::New (attr [4]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 * =>
 * swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double
 * }
 */
Handle <Value> node_swe_refrac (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double refraction;

	refraction = ::swe_refrac (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(int)args [3]->NumberValue ()
	);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("refraction"), Number::New (refraction));

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_refrac_extended (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 6) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("refraction"), Number::New (refraction));
	result->Set (String::NewSymbol ("trueAltitude"),		Number::New (dret [0]));
	result->Set (String::NewSymbol ("apparentAltitude"),	Number::New (dret [1]));
	result->Set (String::NewSymbol ("horizonDip"),			Number::New (dret [3]));

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_set_lapse_rate(double lapse_rate)
 * =>
 * swe_set_lapse_rate(double lapse_rate[, function callback (result)]) = {
 * }
 */
Handle <Value> node_swe_set_lapse_rate (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	::swe_set_lapse_rate (
        args [0]->NumberValue ()
	);

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_azalt (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 10) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
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
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("azimuth"),				Number::New (xaz [0]));
	result->Set (String::NewSymbol ("trueAltitude"),		Number::New (xaz [1]));
	result->Set (String::NewSymbol ("apparentAltitude"),	Number::New (xaz [2]));

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos (in[3]), double *xin (in[3]), double *xout (out[3]))
 * =>
 * swe_azalt_rev(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double bodyAzimuth, double bodyTrueAltitude[, function callback (result)]) = {
 *   azimuth: double,      // xout [0]
 *   trueAltitude: double  // xout [1]
 * }
 */
Handle <Value> node_swe_azalt_rev (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 7) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
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
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("azimuth"),			Number::New (xout [0]));
	result->Set (String::NewSymbol ("trueAltitude"),	Number::New (xout [1]));

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos (in[3]), double atpress, double attemp, double *tret (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   transitTime: double, // tret [0]
 *   error: string
 * }
 */
Handle <Value> node_swe_rise_trans (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 10) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
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
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double geopos [10] = {0};
	double tret;
	char star [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	::strcpy (star, * String::AsciiValue (args [2]->ToString ()));

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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("name"), String::New (star));
		result->Set (String::NewSymbol ("transitTime"), Number::New (tret));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_nod_aps (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		Local <Object> ascending = Object::New ();
		ascending->Set (String::NewSymbol ("longitude"), 		Number::New (xnasc [0]));
		ascending->Set (String::NewSymbol ("latitude"), 		Number::New (xnasc [1]));
		ascending->Set (String::NewSymbol ("distance"), 		Number::New (xnasc [2]));
		ascending->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xnasc [3]));
		ascending->Set (String::NewSymbol ("latitudeSpeed"),	Number::New (xnasc [4]));
		ascending->Set (String::NewSymbol ("distanceSpeed"),	Number::New (xnasc [5]));
		result->Set (String::NewSymbol ("ascending"), ascending);

		Local <Object> descending = Object::New ();
		descending->Set (String::NewSymbol ("longitude"), 		Number::New (xndsc [0]));
		descending->Set (String::NewSymbol ("latitude"), 		Number::New (xndsc [1]));
		descending->Set (String::NewSymbol ("distance"), 		Number::New (xndsc [2]));
		descending->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xndsc [3]));
		descending->Set (String::NewSymbol ("latitudeSpeed"),	Number::New (xndsc [4]));
		descending->Set (String::NewSymbol ("distanceSpeed"),	Number::New (xndsc [5]));
		result->Set (String::NewSymbol ("descending"), descending);

		Local <Object> perihelion = Object::New ();
		perihelion->Set (String::NewSymbol ("longitude"), 		Number::New (xperi [0]));
		perihelion->Set (String::NewSymbol ("latitude"), 		Number::New (xperi [1]));
		perihelion->Set (String::NewSymbol ("distance"), 		Number::New (xperi [2]));
		perihelion->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xperi [3]));
		perihelion->Set (String::NewSymbol ("latitudeSpeed"),	Number::New (xperi [4]));
		perihelion->Set (String::NewSymbol ("distanceSpeed"),	Number::New (xperi [5]));
		result->Set (String::NewSymbol ("perihelion"), perihelion);

		Local <Object> aphelion = Object::New ();
		aphelion->Set (String::NewSymbol ("longitude"), 		Number::New (xaphe [0]));
		aphelion->Set (String::NewSymbol ("latitude"), 			Number::New (xaphe [1]));
		aphelion->Set (String::NewSymbol ("distance"), 			Number::New (xaphe [2]));
		aphelion->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xaphe [3]));
		aphelion->Set (String::NewSymbol ("latitudeSpeed"),		Number::New (xaphe [4]));
		aphelion->Set (String::NewSymbol ("distanceSpeed"),		Number::New (xaphe [5]));
		result->Set (String::NewSymbol ("aphelion"), aphelion);
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_nod_aps_ut (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 4) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
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

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		Local <Object> ascending = Object::New ();
		ascending->Set (String::NewSymbol ("longitude"), 		Number::New (xnasc [0]));
		ascending->Set (String::NewSymbol ("latitude"), 		Number::New (xnasc [1]));
		ascending->Set (String::NewSymbol ("distance"), 		Number::New (xnasc [2]));
		ascending->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xnasc [3]));
		ascending->Set (String::NewSymbol ("latitudeSpeed"),	Number::New (xnasc [4]));
		ascending->Set (String::NewSymbol ("distanceSpeed"),	Number::New (xnasc [5]));
		result->Set (String::NewSymbol ("ascending"), ascending);

		Local <Object> descending = Object::New ();
		descending->Set (String::NewSymbol ("longitude"), 		Number::New (xndsc [0]));
		descending->Set (String::NewSymbol ("latitude"), 		Number::New (xndsc [1]));
		descending->Set (String::NewSymbol ("distance"), 		Number::New (xndsc [2]));
		descending->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xndsc [3]));
		descending->Set (String::NewSymbol ("latitudeSpeed"),	Number::New (xndsc [4]));
		descending->Set (String::NewSymbol ("distanceSpeed"),	Number::New (xndsc [5]));
		result->Set (String::NewSymbol ("descending"), descending);

		Local <Object> perihelion = Object::New ();
		perihelion->Set (String::NewSymbol ("longitude"), 		Number::New (xperi [0]));
		perihelion->Set (String::NewSymbol ("latitude"), 		Number::New (xperi [1]));
		perihelion->Set (String::NewSymbol ("distance"), 		Number::New (xperi [2]));
		perihelion->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xperi [3]));
		perihelion->Set (String::NewSymbol ("latitudeSpeed"),	Number::New (xperi [4]));
		perihelion->Set (String::NewSymbol ("distanceSpeed"),	Number::New (xperi [5]));
		result->Set (String::NewSymbol ("perihelion"), perihelion);

		Local <Object> aphelion = Object::New ();
		aphelion->Set (String::NewSymbol ("longitude"), 		Number::New (xaphe [0]));
		aphelion->Set (String::NewSymbol ("latitude"), 			Number::New (xaphe [1]));
		aphelion->Set (String::NewSymbol ("distance"), 			Number::New (xaphe [2]));
		aphelion->Set (String::NewSymbol ("longitudeSpeed"),	Number::New (xaphe [3]));
		aphelion->Set (String::NewSymbol ("latitudeSpeed"),		Number::New (xaphe [4]));
		aphelion->Set (String::NewSymbol ("distanceSpeed"),		Number::New (xaphe [5]));
		result->Set (String::NewSymbol ("aphelion"), aphelion);
	};

    HandleCallback (args, result);

	return scope.Close (result);
};
