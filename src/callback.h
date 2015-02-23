#ifndef __swisseph_callback_h__
#define __swisseph_callback_h__

#include <node.h>
#include <v8.h>

using namespace v8;

void HandleCallback (Isolate * isolate, const FunctionCallbackInfo <Value> & args, Handle <Value> result);

#endif // __swisseph_callback_h__
