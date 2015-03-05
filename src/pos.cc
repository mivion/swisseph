#include "swisseph.h"

using namespace v8;

/**
 * char swe_version(char *);
 * =>
 * string swe_version();
 */
NAN_METHOD(node_swe_version) {
	NanScope();

	char version [AS_MAXCH];

	::swe_version (version);

	Local <String> result = NanNew<String> (version);

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_calc_ut) {
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

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc_ut (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("longitude"), NanNew<Number> (x [0]));
		result->Set (NanNew<String> ("latitude"), NanNew<Number> (x [1]));
		result->Set (NanNew<String> ("distance"), NanNew<Number> (x [2]));
		result->Set (NanNew<String> ("longitudeSpeed"), NanNew<Number> (x [3]));
		result->Set (NanNew<String> ("latitudeSpeed"), NanNew<Number> (x [4]));
		result->Set (NanNew<String> ("distanceSpeed"), NanNew<Number> (x [5]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_calc) {
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

	double x [6];
	char serr [AS_MAXCH];
	long rflag;

	rflag = ::swe_calc (
		args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		x, serr
	);

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("longitude"), NanNew<Number> (x [0]));
		result->Set (NanNew<String> ("latitude"), NanNew<Number> (x [1]));
		result->Set (NanNew<String> ("distance"), NanNew<Number> (x [2]));
		result->Set (NanNew<String> ("longitudeSpeed"), NanNew<Number> (x [3]));
		result->Set (NanNew<String> ("latitudeSpeed"), NanNew<Number> (x [4]));
		result->Set (NanNew<String> ("distanceSpeed"), NanNew<Number> (x [5]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_fixstar) {
	NanScope();

	if (args.Length () < 3) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsString () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("name"), NanNew<String> (star));
		result->Set (NanNew<String> ("longitude"), NanNew<Number> (x [0]));
		result->Set (NanNew<String> ("latitude"), NanNew<Number> (x [1]));
		result->Set (NanNew<String> ("distance"), NanNew<Number> (x [2]));
		result->Set (NanNew<String> ("longitudeSpeed"), NanNew<Number> (x [3]));
		result->Set (NanNew<String> ("latitudeSpeed"), NanNew<Number> (x [4]));
		result->Set (NanNew<String> ("distanceSpeed"), NanNew<Number> (x [5]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_fixstar_ut) {
	NanScope();

	if (args.Length () < 3) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsString () ||
		!args [1]->IsNumber () ||
		!args [2]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("name"), NanNew<String> (star));
		result->Set (NanNew<String> ("longitude"), NanNew<Number> (x [0]));
		result->Set (NanNew<String> ("latitude"), NanNew<Number> (x [1]));
		result->Set (NanNew<String> ("distance"), NanNew<Number> (x [2]));
		result->Set (NanNew<String> ("longitudeSpeed"), NanNew<Number> (x [3]));
		result->Set (NanNew<String> ("latitudeSpeed"), NanNew<Number> (x [4]));
		result->Set (NanNew<String> ("distanceSpeed"), NanNew<Number> (x [5]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsString ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	char serr [AS_MAXCH];
	char star [AS_MAXCH];
	long rflag;
	double magnitude;

	::strcpy (star, *String::Utf8Value (args [0]->ToString ()));

	rflag = ::swe_fixstar_mag (star, &magnitude, serr);

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("name"), NanNew<String> (star));
		result->Set (NanNew<String> ("magnitude"), NanNew<Number> (magnitude));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * void swe_close(void);
 * =>
 * swe_close()
 */
NAN_METHOD(node_swe_close) {
	NanScope();

	::swe_close ();

    HandleCallback (args, NanUndefined());
    NanReturnValue (NanUndefined());
};

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * void swe_set_ephe_path(string path)
 */
NAN_METHOD(node_swe_set_ephe_path) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsString ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_ephe_path (
		*String::Utf8Value (args [0]->ToString ())
	);

	Local <Object> result = args [0]->ToObject ();

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * void swe_set_jpl_file(string fname)
 */
NAN_METHOD(node_swe_set_jpl_file) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsString ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	::swe_set_jpl_file (
		*String::Utf8Value (args [0]->ToString ())
	);

	Local <Object> result = args [0]->ToObject ();

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * char swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) {
 *   name: string
 * }
 */
NAN_METHOD(node_swe_get_planet_name) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	char name [AS_MAXCH] = {0};

	::swe_get_planet_name ((int)args [0]->NumberValue (), name);

	Local <Object> result = NanNew<Object> ();

	result->Set (NanNew<String> ("name"), NanNew<String> (name));

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * ext_def (void) swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 */
NAN_METHOD(node_swe_set_topo) {
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

	::swe_set_topo (
		args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

    HandleCallback (args, NanUndefined());
    NanReturnValue (NanUndefined());
};

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 */
NAN_METHOD(node_swe_set_sid_mode) {
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

	::swe_set_sid_mode (
		(int)args [0]->NumberValue (),
		args [1]->NumberValue (),
		args [2]->NumberValue ()
	);

    HandleCallback (args, NanUndefined());
    NanReturnValue (NanUndefined());
};

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * double swe_get_ayanamsa(double tjd_et)
 */
NAN_METHOD(node_swe_get_ayanamsa) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double val;

	val = ::swe_get_ayanamsa (
		args [0]->NumberValue ()
	);

	Local <Number> result = NanNew<Number> (val);

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * double swe_get_ayanamsa_ut(double tjd_ut)
 */
NAN_METHOD(node_swe_get_ayanamsa_ut) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	double val;

	val = ::swe_get_ayanamsa_ut (
		args [0]->NumberValue ()
	);

	Local <Number> result = NanNew<Number> (val);

    HandleCallback (args, result);
    NanReturnValue (result);
};

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * string swe_get_ayanamsa_name(int32 isidmode)
 */
NAN_METHOD(node_swe_get_ayanamsa_name) {
	NanScope();

	if (args.Length () < 1) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
	};

	char * val;

	val = ::swe_get_ayanamsa_name (
		(int)args [0]->NumberValue ()
	);

	Local <String> result = NanNew<String> (val);

    HandleCallback (args, result);
    NanReturnValue (result);
};
