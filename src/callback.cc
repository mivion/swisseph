#include "swisseph.h"

using namespace v8;

void HandleCallback (Isolate * isolate, const FunctionCallbackInfo <Value> & args, Handle <Value> result) {
	if (args [args.Length () - 1]->IsFunction ()) {
		Local <Function> callback = Local <Function>::Cast (args [args.Length () - 1]);
		Local <Value> argv [1] = { Local <Value>::New (isolate, result) };
		callback->Call (isolate->GetCurrentContext ()->Global (), 1, argv);
	};
	args.GetReturnValue ().Set (result);
};
