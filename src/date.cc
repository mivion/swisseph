#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * double swe_julday(int year, int month, int day, double hour, int gregflag[, function callback (result)])
 */
Handle <Value> node_swe_julday (const Arguments & args) {
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

	Local <Number> result = Number::New (::swe_julday (
		(int)args [0]->NumberValue (),
		(int)args [1]->NumberValue (),
		(int)args [2]->NumberValue (),
		args [3]->NumberValue (),
		(int)args [4]->NumberValue ()
	));

    HandleCallback (args, result);

	return scope.Close (result);
};
