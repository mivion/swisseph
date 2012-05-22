#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

void Initialize (Handle <Object> target) {
	// date
	NODE_SET_METHOD (target, "swe_date_conversion", node_swe_date_conversion);
	NODE_SET_METHOD (target, "swe_julday", node_swe_julday);
	NODE_SET_METHOD (target, "swe_revjul", node_swe_revjul);
	NODE_SET_METHOD (target, "swe_utc_to_jd", node_swe_utc_to_jd);
	NODE_SET_METHOD (target, "swe_jdet_to_utc", node_swe_jdet_to_utc);
	NODE_SET_METHOD (target, "swe_jdut1_to_utc", node_swe_jdut1_to_utc);
	NODE_SET_METHOD (target, "swe_utc_time_zone", node_swe_utc_time_zone);

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

	// hel
	NODE_SET_METHOD (target, "swe_heliacal_ut", node_swe_heliacal_ut);
	NODE_SET_METHOD (target, "swe_heliacal_pheno_ut", node_swe_heliacal_pheno_ut);
	NODE_SET_METHOD (target, "swe_vis_limit_mag", node_swe_vis_limit_mag);

	// house
	NODE_SET_METHOD (target, "swe_houses", node_swe_houses);
	NODE_SET_METHOD (target, "swe_houses_ex", node_swe_houses_ex);
	NODE_SET_METHOD (target, "swe_houses_armc", node_swe_houses_armc);
	NODE_SET_METHOD (target, "swe_houses_pos", node_swe_houses_pos);

	// eclipse
	NODE_SET_METHOD (target, "swe_pheno", node_swe_pheno);
	NODE_SET_METHOD (target, "swe_pheno_ut", node_swe_pheno);
}

NODE_MODULE (swisseph, Initialize);
