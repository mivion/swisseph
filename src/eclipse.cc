#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

/**
 * int32 swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double *geopos, double atpress, double attemp, double *dgsect (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double *geopos, double atpress, double attemp, double *dgsect, char *serr[, function callback (result)]) = {
 *   gauquelinSector: double,
 *   error: string
 * }
 */
Handle <Value> node_swe_gauquelin_sector (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, double *tret (out[10]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag, double *dret)
 * =>
 * swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double,
 *   trueAltitude: double,
 *   apparentAltitude: double,
 *   horizonDip: double
 * }
 */
Handle <Value> node_swe_refrac_extended (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_azalt(double tjd_ut, int32 calc_flag, double *geopos (in[3]), double atpress, double attemp, double *xin (in[3]), double *xaz (out[3]))
 * =>
 * swe_azalt(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double atpress, double attemp, double bodyX, double bodyY, bodyZ[, function callback (result)]) = {
 *   azimuth: double,
 *   trueAltitude: double,
 *   apparentAltitude: double
 * }
 */
Handle <Value> node_swe_azalt (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos (in[3]), double *xin (in[2]), double *xout (out[2]))
 * =>
 * swe_azalt_rev(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double bodyAzimuth, double bodyTrueAltitude[, function callback (result)]) = {
 *   azimuth: double,
 *   trueAltitude: double
 * }
 */
Handle <Value> node_swe_azalt_rev (const Arguments & args) {
	HandleScope scope;

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

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

	Local <Object> result = Object::New ();

    HandleCallback (args, result);

	return scope.Close (result);
};
