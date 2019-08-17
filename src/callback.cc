#include "swisseph.h"

using namespace v8;

void HandleCallback (Nan::NAN_METHOD_ARGS_TYPE info, Local <Value> result) {
	if (info [info.Length () - 1]->IsFunction ()) {
		Local <Function> callback = Local <Function>::Cast (info [info.Length () - 1]);
		Local <Value> argv [1] = { result };
		callback->Call(Nan::GetCurrentContext(),Nan::GetCurrentContext()->Global(), 1, argv);
	};
};