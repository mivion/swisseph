#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

void HandleCallback (const Arguments & args, Handle <Value> result) {
	if (args [args.Length () - 1]->IsFunction ()) {
		Local <Function> callback = Local <Function>::Cast (args [args.Length () - 1]);
		Local <Value> argv [1] = { Local <Value>::New (result) };
		callback->Call (Context::GetCurrent ()->Global (), 1, argv);
	};
};
