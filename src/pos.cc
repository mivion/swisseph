#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

/**
 * char swe_version(char *);
 * =>
 * string swe_version();
 */
Handle <Value> node_swe_version (const Arguments & args) {
	HandleScope scope;

	char version [AS_MAXCH];

	::swe_version (version);

	Local <String> result = String::New (version);

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_calc_ut(double tjd_ut, int32 ipl, int32 iflag, double *xx, char *serr)
 * =>
 * swe_calc_ut(double tjd_ut, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
Handle <Value> node_swe_calc_ut (const Arguments & args) {
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

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc_ut (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("longitude"), Number::New (x [0]));
		result->Set (String::NewSymbol ("latitude"), Number::New (x [1]));
		result->Set (String::NewSymbol ("distance"), Number::New (x [2]));
		result->Set (String::NewSymbol ("longitudeSpeed"), Number::New (x [3]));
		result->Set (String::NewSymbol ("latitudeSpeed"), Number::New (x [4]));
		result->Set (String::NewSymbol ("distanceSpeed"), Number::New (x [5]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_calc(double tjd, int ipl, int32 iflag, double *xx, char *serr)
 * =>
 * swe_calc(double tjd, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
Handle <Value> node_swe_calc (const Arguments & args) {
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

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("longitude"), Number::New (x [0]));
		result->Set (String::NewSymbol ("latitude"), Number::New (x [1]));
		result->Set (String::NewSymbol ("distance"), Number::New (x [2]));
		result->Set (String::NewSymbol ("longitudeSpeed"), Number::New (x [3]));
		result->Set (String::NewSymbol ("latitudeSpeed"), Number::New (x [4]));
		result->Set (String::NewSymbol ("distanceSpeed"), Number::New (x [5]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_fixstar(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
Handle <Value> node_swe_fixstar (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 3) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsString () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double x [6];
	char serr [AS_MAXCH];
	long rflag = 0;
	char star [AS_MAXCH];

	::strcpy (star, * String::AsciiValue (args [0]->ToString ()));

	rflag = ::swe_fixstar (
		star,
		args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("name"), String::New (star));
		result->Set (String::NewSymbol ("longitude"), Number::New (x [0]));
		result->Set (String::NewSymbol ("latitude"), Number::New (x [1]));
		result->Set (String::NewSymbol ("distance"), Number::New (x [2]));
		result->Set (String::NewSymbol ("longitudeSpeed"), Number::New (x [3]));
		result->Set (String::NewSymbol ("latitudeSpeed"), Number::New (x [4]));
		result->Set (String::NewSymbol ("distanceSpeed"), Number::New (x [5]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_fixstar_ut(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar_ut(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
Handle <Value> node_swe_fixstar_ut (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 3) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsString () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double x [6];
	char serr [AS_MAXCH];
	long rflag = 0;
	char star [AS_MAXCH];

	::strcpy (star, *String::AsciiValue (args [0]->ToString ()));

	rflag = ::swe_fixstar_ut (
		star,
		args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("name"), String::New (star));
		result->Set (String::NewSymbol ("longitude"), Number::New (x [0]));
		result->Set (String::NewSymbol ("latitude"), Number::New (x [1]));
		result->Set (String::NewSymbol ("distance"), Number::New (x [2]));
		result->Set (String::NewSymbol ("longitudeSpeed"), Number::New (x [3]));
		result->Set (String::NewSymbol ("latitudeSpeed"), Number::New (x [4]));
		result->Set (String::NewSymbol ("distanceSpeed"), Number::New (x [5]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
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
Handle <Value> node_swe_fixstar_mag (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsString ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	char serr [AS_MAXCH];
	char star [AS_MAXCH];
	long rflag;
	double magnitude;

	::strcpy (star, *String::AsciiValue (args [0]->ToString ()));

	rflag = ::swe_fixstar_mag (star, &magnitude, serr);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("name"), String::New (star));
		result->Set (String::NewSymbol ("magnitude"), Number::New (magnitude));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_close(void);
 * =>
 * swe_close()
 */
Handle <Value> node_swe_close (const Arguments & args) {
	HandleScope scope;

	::swe_close ();

    HandleCallback (args, Undefined ());

	return scope.Close (Undefined ());
};

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * void swe_set_ephe_path(string path)
 */
Handle <Value> node_swe_set_ephe_path (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsString ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	::swe_set_ephe_path (
		*String::AsciiValue (args [0]->ToString ())
	);

	Local <Object> result = args [0]->ToObject ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * void swe_set_jpl_file(string fname)
 */
Handle <Value> node_swe_set_jpl_file (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 1) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsString ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	::swe_set_jpl_file (
		*String::AsciiValue (args [0]->ToString ())
	);

	Local <Object> result = args [0]->ToObject ();

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * char swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) {
 *   name: string
 * }
 */
Handle <Value> node_swe_get_planet_name (const Arguments & args) {
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

	char name [AS_MAXCH] = {0};

	::swe_get_planet_name ((int)args [0]->NumberValue (), name);

	Local <Object> result = Object::New ();

	result->Set (String::NewSymbol ("name"), String::New (name));

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * ext_def (void) swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 */
Handle <Value> node_swe_set_topo (const Arguments & args) {
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

	::swe_set_topo (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

    HandleCallback (args, Undefined ());

	return scope.Close (Undefined ());
};

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 */
Handle <Value> node_swe_set_sid_mode (const Arguments & args) {
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

	::swe_set_sid_mode (
		(int)args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

    HandleCallback (args, Undefined ());

	return scope.Close (Undefined ());
};

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * double swe_get_ayanamsa(double tjd_et)
 */
Handle <Value> node_swe_get_ayanamsa (const Arguments & args) {
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

	double val;

	val = ::swe_get_ayanamsa (
		args [0]->NumberValue ()
	);

	Local <Number> result = Number::New (val);

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * double swe_get_ayanamsa_ut(double tjd_ut)
 */
Handle <Value> node_swe_get_ayanamsa_ut (const Arguments & args) {
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

	double val;

	val = ::swe_get_ayanamsa_ut (
		args [0]->NumberValue ()
	);

	Local <Number> result = Number::New (val);

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * string swe_get_ayanamsa_name(int32 isidmode)
 */
Handle <Value> node_swe_get_ayanamsa_name (const Arguments & args) {
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

	char * val;

	val = ::swe_get_ayanamsa_name (
		(int)args [0]->NumberValue ()
	);

	Local <String> result = String::New (val);

    HandleCallback (args, result);

	return scope.Close (result);
};
