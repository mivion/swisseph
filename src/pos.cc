#include "swisseph.h"

using namespace v8;

/**
 * char swe_version(char *);
 * =>
 * string swe_version();
 */
void node_swe_version (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	char version [AS_MAXCH];

	::swe_version (version);

	Local <String> result = String::NewFromUtf8 (isolate, version);

    HandleCallback (isolate, args, result);


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
void node_swe_calc_ut (const FunctionCallbackInfo <Value> & args) {
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

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc_ut (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "longitude"), Number::New (isolate, x [0]));
		result->Set (String::NewFromUtf8 (isolate, "latitude"), Number::New (isolate, x [1]));
		result->Set (String::NewFromUtf8 (isolate, "distance"), Number::New (isolate, x [2]));
		result->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"), Number::New (isolate, x [3]));
		result->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"), Number::New (isolate, x [4]));
		result->Set (String::NewFromUtf8 (isolate, "distanceSpeed"), Number::New (isolate, x [5]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_calc (const FunctionCallbackInfo <Value> & args) {
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

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "longitude"), Number::New (isolate, x [0]));
		result->Set (String::NewFromUtf8 (isolate, "latitude"), Number::New (isolate, x [1]));
		result->Set (String::NewFromUtf8 (isolate, "distance"), Number::New (isolate, x [2]));
		result->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"), Number::New (isolate, x [3]));
		result->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"), Number::New (isolate, x [4]));
		result->Set (String::NewFromUtf8 (isolate, "distanceSpeed"), Number::New (isolate, x [5]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_fixstar (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 3) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsString () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double x [6];
	char serr [AS_MAXCH];
	long rflag = 0;
	char star [AS_MAXCH];

	::strcpy (star, * String::Utf8Value (args [0]->ToString ()));

	rflag = ::swe_fixstar (
		star,
		args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, star));
		result->Set (String::NewFromUtf8 (isolate, "longitude"), Number::New (isolate, x [0]));
		result->Set (String::NewFromUtf8 (isolate, "latitude"), Number::New (isolate, x [1]));
		result->Set (String::NewFromUtf8 (isolate, "distance"), Number::New (isolate, x [2]));
		result->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"), Number::New (isolate, x [3]));
		result->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"), Number::New (isolate, x [4]));
		result->Set (String::NewFromUtf8 (isolate, "distanceSpeed"), Number::New (isolate, x [5]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_fixstar_ut (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 3) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsString () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	double x [6];
	char serr [AS_MAXCH];
	long rflag = 0;
	char star [AS_MAXCH];

	::strcpy (star, *String::Utf8Value (args [0]->ToString ()));

	rflag = ::swe_fixstar_ut (
		star,
		args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, star));
		result->Set (String::NewFromUtf8 (isolate, "longitude"), Number::New (isolate, x [0]));
		result->Set (String::NewFromUtf8 (isolate, "latitude"), Number::New (isolate, x [1]));
		result->Set (String::NewFromUtf8 (isolate, "distance"), Number::New (isolate, x [2]));
		result->Set (String::NewFromUtf8 (isolate, "longitudeSpeed"), Number::New (isolate, x [3]));
		result->Set (String::NewFromUtf8 (isolate, "latitudeSpeed"), Number::New (isolate, x [4]));
		result->Set (String::NewFromUtf8 (isolate, "distanceSpeed"), Number::New (isolate, x [5]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_fixstar_mag (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsString ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	char serr [AS_MAXCH];
	char star [AS_MAXCH];
	long rflag;
	double magnitude;

	::strcpy (star, *String::Utf8Value (args [0]->ToString ()));

	rflag = ::swe_fixstar_mag (star, &magnitude, serr);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, star));
		result->Set (String::NewFromUtf8 (isolate, "magnitude"), Number::New (isolate, magnitude));
	};

    HandleCallback (isolate, args, result);


};

/**
 * void swe_close(void);
 * =>
 * swe_close()
 */
void node_swe_close (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	::swe_close ();

    HandleCallback (isolate, args, Undefined (isolate));

	return;
};

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * void swe_set_ephe_path(string path)
 */
void node_swe_set_ephe_path (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsString ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	::swe_set_ephe_path (
		*String::Utf8Value (args [0]->ToString ())
	);

	Local <Object> result = args [0]->ToObject ();

    HandleCallback (isolate, args, result);


};

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * void swe_set_jpl_file(string fname)
 */
void node_swe_set_jpl_file (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 1) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsString ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
	};

	::swe_set_jpl_file (
		*String::Utf8Value (args [0]->ToString ())
	);

	Local <Object> result = args [0]->ToObject ();

    HandleCallback (isolate, args, result);


};

/**
 * char swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) {
 *   name: string
 * }
 */
void node_swe_get_planet_name (const FunctionCallbackInfo <Value> & args) {
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

	char name [AS_MAXCH] = {0};

	::swe_get_planet_name ((int)args [0]->NumberValue (), name);

	Local <Object> result = Object::New (isolate);

	result->Set (String::NewFromUtf8 (isolate, "name"), String::NewFromUtf8 (isolate, name));

    HandleCallback (isolate, args, result);


};

/**
 * ext_def (void) swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 */
void node_swe_set_topo (const FunctionCallbackInfo <Value> & args) {
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

	::swe_set_topo (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

    HandleCallback (isolate, args, Undefined (isolate));

	return;
};

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 */
void node_swe_set_sid_mode (const FunctionCallbackInfo <Value> & args) {
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

	::swe_set_sid_mode (
		(int)args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

    HandleCallback (isolate, args, Undefined (isolate));

	return;
};

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * double swe_get_ayanamsa(double tjd_et)
 */
void node_swe_get_ayanamsa (const FunctionCallbackInfo <Value> & args) {
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

	double val;

	val = ::swe_get_ayanamsa (
		args [0]->NumberValue ()
	);

	Local <Number> result = Number::New (isolate, val);

    HandleCallback (isolate, args, result);


};

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * double swe_get_ayanamsa_ut(double tjd_ut)
 */
void node_swe_get_ayanamsa_ut (const FunctionCallbackInfo <Value> & args) {
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

	double val;

	val = ::swe_get_ayanamsa_ut (
		args [0]->NumberValue ()
	);

	Local <Number> result = Number::New (isolate, val);

    HandleCallback (isolate, args, result);


};

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * string swe_get_ayanamsa_name(int32 isidmode)
 */
void node_swe_get_ayanamsa_name (const FunctionCallbackInfo <Value> & args) {
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

	char * val;

	val = ::swe_get_ayanamsa_name (
		(int)args [0]->NumberValue ()
	);

	Local <String> result = String::NewFromUtf8 (isolate, val);

    HandleCallback (isolate, args, result);


};
