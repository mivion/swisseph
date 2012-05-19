#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

void Initialize (Handle <Object> target) {
	// date
	NODE_SET_METHOD (target, "swe_julday", node_swe_julday);

	// pos
	NODE_SET_METHOD (target, "swe_version", node_swe_version);
	NODE_SET_METHOD (target, "swe_calc_ut", node_swe_calc_ut);
	NODE_SET_METHOD (target, "swe_calc", node_swe_calc);
	NODE_SET_METHOD (target, "swe_fixstar", node_swe_fixstar);
	NODE_SET_METHOD (target, "swe_fixstar_ut", node_swe_fixstar_ut);
	NODE_SET_METHOD (target, "swe_fixstar_mag", node_swe_fixstar_mag);
	NODE_SET_METHOD (target, "swe_close", node_swe_close);
	NODE_SET_METHOD (target, "swe_set_ephe_path", node_swe_set_ephe_path);
	NODE_SET_METHOD (target, "swe_set_jpl_file", node_swe_set_jpl_file);
	NODE_SET_METHOD (target, "swe_get_planet_name", node_swe_get_planet_name);
	NODE_SET_METHOD (target, "swe_set_topo", node_swe_set_topo);
	NODE_SET_METHOD (target, "swe_set_sid_mode", node_swe_set_sid_mode);
	NODE_SET_METHOD (target, "swe_get_ayanamsa", node_swe_get_ayanamsa);
	NODE_SET_METHOD (target, "swe_get_ayanamsa_ut", node_swe_get_ayanamsa_ut);
	NODE_SET_METHOD (target, "swe_get_ayanamsa_name", node_swe_get_ayanamsa_name);
}

NODE_MODULE (swisseph, Initialize);
