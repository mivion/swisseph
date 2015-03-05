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
	NanScope();

	if (args.Length () < 10) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("name"), NanNew<String> (star));
		result->Set (NanNew<String> ("gauquelinSector"), NanNew<Number> (dgsect));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 2) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("longitude"),	NanNew<Number> (geopos [0]));
		result->Set (NanNew<String> ("latitude"),	NanNew<Number> (geopos [1]));
		result->Set (NanNew<String> ("solarDiameterFraction"),		NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("lonarToSolarDiameterRatio"),	NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("solarDiscFraction"),			NanNew<Number> (attr [2]));
		result->Set (NanNew<String> ("coreShadow"),					NanNew<Number> (attr [3]));
		result->Set (NanNew<String> ("azimuth"),						NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("trueAltitude"),				NanNew<Number> (attr [5]));
		result->Set (NanNew<String> ("apparentAltitude"),			NanNew<Number> (attr [6]));
		result->Set (NanNew<String> ("moonToSunAngularDistance"),	NanNew<Number> (attr [7]));
		result->Set (NanNew<String> ("eclipseMagnitude"),			NanNew<Number> (attr [8]));
		result->Set (NanNew<String> ("sarosNumber"),					NanNew<Number> (attr [9]));
		result->Set (NanNew<String> ("sarosMember"),					NanNew<Number> (attr [10]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("longitude"),	NanNew<Number> (geopos [0]));
		result->Set (NanNew<String> ("latitude"),	NanNew<Number> (geopos [1]));
		result->Set (NanNew<String> ("solarDiameterFraction"),		NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("lonarToSolarDiameterRatio"),	NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("solarDiscFraction"),			NanNew<Number> (attr [2]));
		result->Set (NanNew<String> ("coreShadow"),					NanNew<Number> (attr [3]));
		result->Set (NanNew<String> ("azimuth"),						NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("trueAltitude"),				NanNew<Number> (attr [5]));
		result->Set (NanNew<String> ("apparentAltitude"),			NanNew<Number> (attr [6]));
		result->Set (NanNew<String> ("moonToSunAngularDistance"),	NanNew<Number> (attr [7]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 5) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("solarDiameterFraction"),		NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("lonarToSolarDiameterRatio"),	NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("solarDiscFraction"),			NanNew<Number> (attr [2]));
		result->Set (NanNew<String> ("coreShadow"),					NanNew<Number> (attr [3]));
		result->Set (NanNew<String> ("azimuth"),						NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("trueAltitude"),				NanNew<Number> (attr [5]));
		result->Set (NanNew<String> ("apparentAltitude"),			NanNew<Number> (attr [6]));
		result->Set (NanNew<String> ("moonToSunAngularDistance"),	NanNew<Number> (attr [7]));
		result->Set (NanNew<String> ("eclipseMagnitude"),			NanNew<Number> (attr [8]));
		result->Set (NanNew<String> ("sarosNumber"),					NanNew<Number> (attr [9]));
		result->Set (NanNew<String> ("sarosMember"),					NanNew<Number> (attr [10]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 6) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("maximum"),		NanNew<Number> (tret [0]));
		result->Set (NanNew<String> ("first"),		NanNew<Number> (tret [1]));
		result->Set (NanNew<String> ("second"),		NanNew<Number> (tret [2]));
		result->Set (NanNew<String> ("third"),		NanNew<Number> (tret [3]));
		result->Set (NanNew<String> ("forth"),		NanNew<Number> (tret [4]));
		result->Set (NanNew<String> ("solarDiameterFraction"),		NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("lonarToSolarDiameterRatio"),	NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("solarDiscFraction"),			NanNew<Number> (attr [2]));
		result->Set (NanNew<String> ("coreShadow"),					NanNew<Number> (attr [3]));
		result->Set (NanNew<String> ("azimuth"),						NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("trueAltitude"),				NanNew<Number> (attr [5]));
		result->Set (NanNew<String> ("apparentAltitude"),			NanNew<Number> (attr [6]));
		result->Set (NanNew<String> ("moonToSunAngularDistance"),	NanNew<Number> (attr [7]));
		result->Set (NanNew<String> ("eclipseMagnitude"),			NanNew<Number> (attr [8]));
		result->Set (NanNew<String> ("sarosNumber"),					NanNew<Number> (attr [9]));
		result->Set (NanNew<String> ("sarosMember"),					NanNew<Number> (attr [10]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 8) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("name"), NanNew<String> (star));
		result->Set (NanNew<String> ("maximum"),		NanNew<Number> (tret [0]));
		result->Set (NanNew<String> ("first"),		NanNew<Number> (tret [1]));
		result->Set (NanNew<String> ("second"),		NanNew<Number> (tret [2]));
		result->Set (NanNew<String> ("third"),		NanNew<Number> (tret [3]));
		result->Set (NanNew<String> ("forth"),		NanNew<Number> (tret [4]));
		result->Set (NanNew<String> ("solarDiameterFraction"),		NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("lonarToSolarDiameterRatio"),	NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("solarDiscFraction"),			NanNew<Number> (attr [2]));
		result->Set (NanNew<String> ("coreShadow"),					NanNew<Number> (attr [3]));
		result->Set (NanNew<String> ("azimuth"),						NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("trueAltitude"),				NanNew<Number> (attr [5]));
		result->Set (NanNew<String> ("apparentAltitude"),			NanNew<Number> (attr [6]));
		result->Set (NanNew<String> ("moonToSunAngularDistance"),	NanNew<Number> (attr [7]));
		result->Set (NanNew<String> ("eclipseMagnitude"),			NanNew<Number> (attr [8]));
		result->Set (NanNew<String> ("sarosNumber"),					NanNew<Number> (attr [9]));
		result->Set (NanNew<String> ("sarosMember"),					NanNew<Number> (attr [10]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("maximum"),		NanNew<Number> (tret [0]));
		result->Set (NanNew<String> ("noon"),		NanNew<Number> (tret [1]));
		result->Set (NanNew<String> ("begin"),		NanNew<Number> (tret [2]));
		result->Set (NanNew<String> ("end"),			NanNew<Number> (tret [3]));
		result->Set (NanNew<String> ("totalBegin"),	NanNew<Number> (tret [4]));
		result->Set (NanNew<String> ("totalEnd"),	NanNew<Number> (tret [5]));
		result->Set (NanNew<String> ("centerBegin"),	NanNew<Number> (tret [6]));
		result->Set (NanNew<String> ("centerEnd"),	NanNew<Number> (tret [7]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 6) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsString () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("name"), NanNew<String> (star));
		result->Set (NanNew<String> ("maximum"),		NanNew<Number> (tret [0]));
		result->Set (NanNew<String> ("noon"),		NanNew<Number> (tret [1]));
		result->Set (NanNew<String> ("begin"),		NanNew<Number> (tret [2]));
		result->Set (NanNew<String> ("end"),			NanNew<Number> (tret [3]));
		result->Set (NanNew<String> ("totalBegin"),	NanNew<Number> (tret [4]));
		result->Set (NanNew<String> ("totalEnd"),	NanNew<Number> (tret [5]));
		result->Set (NanNew<String> ("centerBegin"),	NanNew<Number> (tret [6]));
		result->Set (NanNew<String> ("centerEnd"),	NanNew<Number> (tret [7]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 5) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("umbralMagnitude"),		NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("penumbralMagnitude"),	NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("azimuth"),				NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("trueAltitude"),		NanNew<Number> (attr [5]));
		result->Set (NanNew<String> ("apparentAltitude"),	NanNew<Number> (attr [6]));
		result->Set (NanNew<String> ("oppositeDegreeDist"),	NanNew<Number> (attr [7]));
		result->Set (NanNew<String> ("magnitude"),			NanNew<Number> (attr [8]));
		result->Set (NanNew<String> ("sarosNumber"),			NanNew<Number> (attr [9]));
		result->Set (NanNew<String> ("sarosMember"),			NanNew<Number> (attr [10]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("maximum"),			NanNew<Number> (tret [0]));
		result->Set (NanNew<String> ("partialBegin"),	NanNew<Number> (tret [2]));
		result->Set (NanNew<String> ("partialEnd"),		NanNew<Number> (tret [3]));
		result->Set (NanNew<String> ("totalBegin"),		NanNew<Number> (tret [4]));
		result->Set (NanNew<String> ("totalEnd"),		NanNew<Number> (tret [5]));
		result->Set (NanNew<String> ("penumbralBegin"),	NanNew<Number> (tret [6]));
		result->Set (NanNew<String> ("penumbralEnd"),	NanNew<Number> (tret [7]));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 3) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("phaseAngle"), NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("phase"), NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("elongation"), NanNew<Number> (attr [2]));
		result->Set (NanNew<String> ("apparentDiameter"), NanNew<Number> (attr [3]));
		result->Set (NanNew<String> ("apparentMagnitude"), NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 3) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("phaseAngle"), NanNew<Number> (attr [0]));
		result->Set (NanNew<String> ("phase"), NanNew<Number> (attr [1]));
		result->Set (NanNew<String> ("elongation"), NanNew<Number> (attr [2]));
		result->Set (NanNew<String> ("apparentDiameter"), NanNew<Number> (attr [3]));
		result->Set (NanNew<String> ("apparentMagnitude"), NanNew<Number> (attr [4]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 * =>
 * swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double
 * }
 */
NAN_METHOD(node_swe_refrac) {
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double refraction;

	refraction = ::swe_refrac (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue (),
		(int)args [3]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("refraction"), NanNew<Number> (refraction));

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 6) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber () ||
		!args [4]->IsNumber () ||
		!args [5]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("refraction"), NanNew<Number> (refraction));
	result->Set (NanNew<String> ("trueAltitude"),		NanNew<Number> (dret [0]));
	result->Set (NanNew<String> ("apparentAltitude"),	NanNew<Number> (dret [1]));
	result->Set (NanNew<String> ("horizonDip"),			NanNew<Number> (dret [3]));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * void swe_set_lapse_rate(double lapse_rate)
 * =>
 * swe_set_lapse_rate(double lapse_rate[, function callback (result)]) = {
 * }
 */
NAN_METHOD(node_swe_set_lapse_rate) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_lapse_rate (
        args [0]->NumberValue ()
	);

	Local <Object> result = NanNew<Object> ();

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 10) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("azimuth"),				NanNew<Number> (xaz [0]));
	result->Set (NanNew<String> ("trueAltitude"),		NanNew<Number> (xaz [1]));
	result->Set (NanNew<String> ("apparentAltitude"),	NanNew<Number> (xaz [2]));

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 7) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("azimuth"),			NanNew<Number> (xout [0]));
	result->Set (NanNew<String> ("trueAltitude"),	NanNew<Number> (xout [1]));

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 10) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("name"), NanNew<String> (star));
		result->Set (NanNew<String> ("transitTime"), NanNew<Number> (tret));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		Local <Object> ascending = NanNew<Object> ();
		ascending->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xnasc [0]));
		ascending->Set (NanNew<String> ("latitude"), 		NanNew<Number> (xnasc [1]));
		ascending->Set (NanNew<String> ("distance"), 		NanNew<Number> (xnasc [2]));
		ascending->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xnasc [3]));
		ascending->Set (NanNew<String> ("latitudeSpeed"),	NanNew<Number> (xnasc [4]));
		ascending->Set (NanNew<String> ("distanceSpeed"),	NanNew<Number> (xnasc [5]));
		result->Set (NanNew<String> ("ascending"), ascending);

		Local <Object> descending = NanNew<Object> ();
		descending->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xndsc [0]));
		descending->Set (NanNew<String> ("latitude"), 		NanNew<Number> (xndsc [1]));
		descending->Set (NanNew<String> ("distance"), 		NanNew<Number> (xndsc [2]));
		descending->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xndsc [3]));
		descending->Set (NanNew<String> ("latitudeSpeed"),	NanNew<Number> (xndsc [4]));
		descending->Set (NanNew<String> ("distanceSpeed"),	NanNew<Number> (xndsc [5]));
		result->Set (NanNew<String> ("descending"), descending);

		Local <Object> perihelion = NanNew<Object> ();
		perihelion->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xperi [0]));
		perihelion->Set (NanNew<String> ("latitude"), 		NanNew<Number> (xperi [1]));
		perihelion->Set (NanNew<String> ("distance"), 		NanNew<Number> (xperi [2]));
		perihelion->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xperi [3]));
		perihelion->Set (NanNew<String> ("latitudeSpeed"),	NanNew<Number> (xperi [4]));
		perihelion->Set (NanNew<String> ("distanceSpeed"),	NanNew<Number> (xperi [5]));
		result->Set (NanNew<String> ("perihelion"), perihelion);

		Local <Object> aphelion = NanNew<Object> ();
		aphelion->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xaphe [0]));
		aphelion->Set (NanNew<String> ("latitude"), 			NanNew<Number> (xaphe [1]));
		aphelion->Set (NanNew<String> ("distance"), 			NanNew<Number> (xaphe [2]));
		aphelion->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xaphe [3]));
		aphelion->Set (NanNew<String> ("latitudeSpeed"),		NanNew<Number> (xaphe [4]));
		aphelion->Set (NanNew<String> ("distanceSpeed"),		NanNew<Number> (xaphe [5]));
		result->Set (NanNew<String> ("aphelion"), aphelion);
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 4) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber () ||
		!args [3]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		Local <Object> ascending = NanNew<Object> ();
		ascending->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xnasc [0]));
		ascending->Set (NanNew<String> ("latitude"), 		NanNew<Number> (xnasc [1]));
		ascending->Set (NanNew<String> ("distance"), 		NanNew<Number> (xnasc [2]));
		ascending->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xnasc [3]));
		ascending->Set (NanNew<String> ("latitudeSpeed"),	NanNew<Number> (xnasc [4]));
		ascending->Set (NanNew<String> ("distanceSpeed"),	NanNew<Number> (xnasc [5]));
		result->Set (NanNew<String> ("ascending"), ascending);

		Local <Object> descending = NanNew<Object> ();
		descending->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xndsc [0]));
		descending->Set (NanNew<String> ("latitude"), 		NanNew<Number> (xndsc [1]));
		descending->Set (NanNew<String> ("distance"), 		NanNew<Number> (xndsc [2]));
		descending->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xndsc [3]));
		descending->Set (NanNew<String> ("latitudeSpeed"),	NanNew<Number> (xndsc [4]));
		descending->Set (NanNew<String> ("distanceSpeed"),	NanNew<Number> (xndsc [5]));
		result->Set (NanNew<String> ("descending"), descending);

		Local <Object> perihelion = NanNew<Object> ();
		perihelion->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xperi [0]));
		perihelion->Set (NanNew<String> ("latitude"), 		NanNew<Number> (xperi [1]));
		perihelion->Set (NanNew<String> ("distance"), 		NanNew<Number> (xperi [2]));
		perihelion->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xperi [3]));
		perihelion->Set (NanNew<String> ("latitudeSpeed"),	NanNew<Number> (xperi [4]));
		perihelion->Set (NanNew<String> ("distanceSpeed"),	NanNew<Number> (xperi [5]));
		result->Set (NanNew<String> ("perihelion"), perihelion);

		Local <Object> aphelion = NanNew<Object> ();
		aphelion->Set (NanNew<String> ("longitude"), 		NanNew<Number> (xaphe [0]));
		aphelion->Set (NanNew<String> ("latitude"), 			NanNew<Number> (xaphe [1]));
		aphelion->Set (NanNew<String> ("distance"), 			NanNew<Number> (xaphe [2]));
		aphelion->Set (NanNew<String> ("longitudeSpeed"),	NanNew<Number> (xaphe [3]));
		aphelion->Set (NanNew<String> ("latitudeSpeed"),		NanNew<Number> (xaphe [4]));
		aphelion->Set (NanNew<String> ("distanceSpeed"),		NanNew<Number> (xaphe [5]));
		result->Set (NanNew<String> ("aphelion"), aphelion);
	};

    HandleCallback (args, result);
    NanReturnValue (result);
};
