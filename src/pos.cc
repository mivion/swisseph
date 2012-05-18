#include <node.h>
#include <v8.h>

#include "swephexp.h"
#include "callback.h"

using namespace v8;

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
