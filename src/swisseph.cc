#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

void Initialize (Handle <Object> target) {
	// date
	NODE_SET_METHOD (target, "swe_julday", node_swe_julday);

	// pos
	NODE_SET_METHOD (target, "swe_calc_ut", node_swe_calc_ut);
	NODE_SET_METHOD (target, "swe_calc", node_swe_calc);
	NODE_SET_METHOD (target, "swe_calc", node_swe_calc);
	NODE_SET_METHOD (target, "swe_fixstar", node_swe_fixstar);
	NODE_SET_METHOD (target, "swe_fixstar_ut", node_swe_fixstar_ut);
	NODE_SET_METHOD (target, "swe_set_ephe_path", node_swe_set_ephe_path);
}

NODE_MODULE (swisseph, Initialize);
