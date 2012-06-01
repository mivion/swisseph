#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

void Initialize (Handle <Object> target) {
	// util
	NODE_SET_METHOD (target, "swe_deltat", node_swe_deltat);
	NODE_SET_METHOD (target, "swe_time_equ", node_swe_time_equ);
	NODE_SET_METHOD (target, "swe_sidtime0", node_swe_sidtime0);
	NODE_SET_METHOD (target, "swe_sidtime", node_swe_sidtime);
	NODE_SET_METHOD (target, "swe_cotrans", node_swe_cotrans);
	NODE_SET_METHOD (target, "swe_cotrans_sp", node_swe_cotrans_sp);
	NODE_SET_METHOD (target, "swe_get_tid_acc", node_swe_get_tid_acc);
	NODE_SET_METHOD (target, "swe_set_tid_acc", node_swe_set_tid_acc);
	NODE_SET_METHOD (target, "swe_degnorm", node_swe_degnorm);
	NODE_SET_METHOD (target, "swe_radnorm", node_swe_radnorm);
	NODE_SET_METHOD (target, "swe_rad_midp", node_swe_rad_midp);
	NODE_SET_METHOD (target, "swe_deg_midp", node_swe_deg_midp);
	NODE_SET_METHOD (target, "swe_split_deg", node_swe_split_deg);
	NODE_SET_METHOD (target, "swe_csnorm", node_swe_csnorm);
	NODE_SET_METHOD (target, "swe_difcsn", node_swe_difcsn);
	NODE_SET_METHOD (target, "swe_difdegn", node_swe_difdegn);
	NODE_SET_METHOD (target, "swe_difcs2n", node_swe_difcs2n);
	NODE_SET_METHOD (target, "swe_difdeg2n", node_swe_difdeg2n);
	NODE_SET_METHOD (target, "swe_difrad2n", node_swe_difrad2n);
	NODE_SET_METHOD (target, "swe_csroundsec", node_swe_csroundsec);
	NODE_SET_METHOD (target, "swe_d2l", node_swe_d2l);
	NODE_SET_METHOD (target, "swe_day_of_week", node_swe_day_of_week);
	NODE_SET_METHOD (target, "swe_cs2timestr", node_swe_cs2timestr);
	NODE_SET_METHOD (target, "swe_cs2lonlatstr", node_swe_cs2lonlatstr);
	NODE_SET_METHOD (target, "swe_cs2degstr", node_swe_cs2degstr);

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
	NODE_SET_METHOD (target, "swe_gauquelin_sector", node_swe_gauquelin_sector);
	NODE_SET_METHOD (target, "swe_sol_eclipse_where", node_swe_sol_eclipse_where);
	NODE_SET_METHOD (target, "swe_lun_occult_where", node_swe_lun_occult_where);
	NODE_SET_METHOD (target, "swe_sol_eclipse_how", node_swe_sol_eclipse_how);
	NODE_SET_METHOD (target, "swe_sol_eclipse_when_loc", node_swe_sol_eclipse_when_loc);
	NODE_SET_METHOD (target, "swe_lun_occult_when_loc", node_swe_lun_occult_when_loc);
	NODE_SET_METHOD (target, "swe_sol_eclipse_when_glob", node_swe_sol_eclipse_when_glob);
	NODE_SET_METHOD (target, "swe_lun_occult_when_glob", node_swe_lun_occult_when_glob);
	NODE_SET_METHOD (target, "swe_lun_eclipse_how", node_swe_lun_eclipse_how);
	NODE_SET_METHOD (target, "swe_lun_eclipse_when", node_swe_lun_eclipse_when);
	NODE_SET_METHOD (target, "swe_pheno", node_swe_pheno);
	NODE_SET_METHOD (target, "swe_pheno_ut", node_swe_pheno);
	NODE_SET_METHOD (target, "swe_refrac", node_swe_refrac);
	NODE_SET_METHOD (target, "swe_refrac_extended", node_swe_refrac_extended);
	NODE_SET_METHOD (target, "swe_set_lapse_rate", node_swe_set_lapse_rate);
	NODE_SET_METHOD (target, "swe_azalt", node_swe_azalt);
	NODE_SET_METHOD (target, "swe_azalt_rev", node_swe_azalt_rev);
	NODE_SET_METHOD (target, "swe_rise_trans", node_swe_rise_trans);
	NODE_SET_METHOD (target, "swe_nod_aps", node_swe_nod_aps);
	NODE_SET_METHOD (target, "swe_nod_aps_ut", node_swe_nod_aps_ut);
}

NODE_MODULE (swisseph, Initialize);
