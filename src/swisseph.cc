#include <node.h>
#include <v8.h>

#include "swephexp.h"
#include "callback.h"
#include "pos.h"
#include "date.h"

using namespace v8;

void Initialize (Handle <Object> target) {
	NODE_SET_METHOD (target, "swe_julday", node_swe_julday);
	NODE_SET_METHOD (target, "swe_calc_ut", node_swe_calc_ut);
}

NODE_MODULE (swisseph, Initialize);
