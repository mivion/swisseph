#ifndef __swisseph_callback_h__
#define __swisseph_callback_h__

#include <node.h>
#include <v8.h>

using namespace v8;

void HandleCallback (_NAN_METHOD_ARGS_TYPE args, Handle <Value> result);

#endif // __swisseph_callback_h__
