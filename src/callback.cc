#include "swisseph.h"

using namespace v8;

void HandleCallback (_NAN_METHOD_ARGS_TYPE args, Handle <Value> result) {
	if (args [args.Length () - 1]->IsFunction ()) {
		Local <Function> callback = Local <Function>::Cast (args [args.Length () - 1]);
		Local <Value> argv [1] = { NanNew<Value> (result) };
		callback->Call (NanGetCurrentContext ()->Global (), 1, argv);
	};
};
