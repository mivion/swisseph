#include "swisseph.h"

using namespace v8;

void HandleCallback (Nan::NAN_METHOD_ARGS_TYPE info, Handle <Value> result) {
	if (info [info.Length () - 1]->IsFunction ()) {
		Local <Function> callback = Local <Function>::Cast (info [info.Length () - 1]);
		Local <Value> argv [1] = { Nan::New<Value> (result) };
		callback->Call (Nan::GetCurrentContext ()->Global (), 1, argv);
	};
};
