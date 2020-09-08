#include "swisseph.h"

using namespace v8;

void Initialize (Local <Object> exports) {
	// util
	Nan::SetMethod (exports, "swe_deltat", node_swe_deltat);
	Nan::SetMethod (exports, "swe_time_equ", node_swe_time_equ);
	Nan::SetMethod (exports, "swe_sidtime0", node_swe_sidtime0);
	Nan::SetMethod (exports, "swe_sidtime", node_swe_sidtime);
	Nan::SetMethod (exports, "swe_cotrans", node_swe_cotrans);
	Nan::SetMethod (exports, "swe_cotrans_sp", node_swe_cotrans_sp);
	Nan::SetMethod (exports, "swe_get_tid_acc", node_swe_get_tid_acc);
	Nan::SetMethod (exports, "swe_set_tid_acc", node_swe_set_tid_acc);
	Nan::SetMethod (exports, "swe_degnorm", node_swe_degnorm);
	Nan::SetMethod (exports, "swe_radnorm", node_swe_radnorm);
	Nan::SetMethod (exports, "swe_rad_midp", node_swe_rad_midp);
	Nan::SetMethod (exports, "swe_deg_midp", node_swe_deg_midp);
	Nan::SetMethod (exports, "swe_split_deg", node_swe_split_deg);
	Nan::SetMethod (exports, "swe_csnorm", node_swe_csnorm);
	Nan::SetMethod (exports, "swe_difcsn", node_swe_difcsn);
	Nan::SetMethod (exports, "swe_difdegn", node_swe_difdegn);
	Nan::SetMethod (exports, "swe_difcs2n", node_swe_difcs2n);
	Nan::SetMethod (exports, "swe_difdeg2n", node_swe_difdeg2n);
	Nan::SetMethod (exports, "swe_difrad2n", node_swe_difrad2n);
	Nan::SetMethod (exports, "swe_csroundsec", node_swe_csroundsec);
	Nan::SetMethod (exports, "swe_d2l", node_swe_d2l);
	Nan::SetMethod (exports, "swe_day_of_week", node_swe_day_of_week);
	Nan::SetMethod (exports, "swe_cs2timestr", node_swe_cs2timestr);
	Nan::SetMethod (exports, "swe_cs2lonlatstr", node_swe_cs2lonlatstr);
	Nan::SetMethod (exports, "swe_cs2degstr", node_swe_cs2degstr);

	// date
	Nan::SetMethod (exports, "swe_date_conversion", node_swe_date_conversion);
	Nan::SetMethod (exports, "swe_julday", node_swe_julday);
	Nan::SetMethod (exports, "swe_revjul", node_swe_revjul);
	Nan::SetMethod (exports, "swe_utc_to_jd", node_swe_utc_to_jd);
	Nan::SetMethod (exports, "swe_jdet_to_utc", node_swe_jdet_to_utc);
	Nan::SetMethod (exports, "swe_jdut1_to_utc", node_swe_jdut1_to_utc);
	Nan::SetMethod (exports, "swe_utc_time_zone", node_swe_utc_time_zone);

	// pos
	Nan::SetMethod (exports, "swe_version", node_swe_version);
	Nan::SetMethod (exports, "swe_calc_ut", node_swe_calc_ut);
	Nan::SetMethod (exports, "swe_calc", node_swe_calc);
	Nan::SetMethod (exports, "swe_fixstar", node_swe_fixstar);
	Nan::SetMethod (exports, "swe_fixstar_ut", node_swe_fixstar_ut);
	Nan::SetMethod (exports, "swe_fixstar_mag", node_swe_fixstar_mag);
	Nan::SetMethod (exports, "swe_fixstar2", node_swe_fixstar2);
	Nan::SetMethod (exports, "swe_fixstar2_ut", node_swe_fixstar2_ut);
	Nan::SetMethod (exports, "swe_fixstar2_mag", node_swe_fixstar2_mag);
	Nan::SetMethod (exports, "swe_close", node_swe_close);
	Nan::SetMethod (exports, "swe_set_ephe_path", node_swe_set_ephe_path);
	Nan::SetMethod (exports, "swe_set_jpl_file", node_swe_set_jpl_file);
	Nan::SetMethod (exports, "swe_get_planet_name", node_swe_get_planet_name);
	Nan::SetMethod (exports, "swe_set_topo", node_swe_set_topo);
	Nan::SetMethod (exports, "swe_set_sid_mode", node_swe_set_sid_mode);
	Nan::SetMethod (exports, "swe_get_ayanamsa", node_swe_get_ayanamsa);
	Nan::SetMethod (exports, "swe_get_ayanamsa_ut", node_swe_get_ayanamsa_ut);
	Nan::SetMethod (exports, "swe_get_ayanamsa_ex", node_swe_get_ayanamsa_ex);
	Nan::SetMethod (exports, "swe_get_ayanamsa_ex_ut", node_swe_get_ayanamsa_ex_ut);
	Nan::SetMethod (exports, "swe_get_ayanamsa_name", node_swe_get_ayanamsa_name);
	Nan::SetMethod (exports, "swe_nod_aps", node_swe_nod_aps);
	Nan::SetMethod (exports, "swe_nod_aps_ut", node_swe_nod_aps_ut);
	Nan::SetMethod (exports, "swe_get_orbital_elements", node_swe_get_orbital_elements);
	Nan::SetMethod (exports, "swe_orbit_max_min_true_distance", node_swe_orbit_max_min_true_distance);

	// hel
	Nan::SetMethod (exports, "swe_heliacal_ut", node_swe_heliacal_ut);
	Nan::SetMethod (exports, "swe_heliacal_pheno_ut", node_swe_heliacal_pheno_ut);
	Nan::SetMethod (exports, "swe_vis_limit_mag", node_swe_vis_limit_mag);

	// house
	Nan::SetMethod (exports, "swe_houses", node_swe_houses);
	Nan::SetMethod (exports, "swe_houses_ex", node_swe_houses_ex);
	Nan::SetMethod (exports, "swe_houses_ex2", node_swe_houses_ex2);
	Nan::SetMethod (exports, "swe_houses_armc", node_swe_houses_armc);
	Nan::SetMethod (exports, "swe_houses_armc_ex2", node_swe_houses_armc_ex2);
	Nan::SetMethod (exports, "swe_houses_pos", node_swe_houses_pos);

	// eclipse
	Nan::SetMethod (exports, "swe_gauquelin_sector", node_swe_gauquelin_sector);
	Nan::SetMethod (exports, "swe_sol_eclipse_where", node_swe_sol_eclipse_where);
	Nan::SetMethod (exports, "swe_lun_occult_where", node_swe_lun_occult_where);
	Nan::SetMethod (exports, "swe_sol_eclipse_how", node_swe_sol_eclipse_how);
	Nan::SetMethod (exports, "swe_sol_eclipse_when_loc", node_swe_sol_eclipse_when_loc);
	Nan::SetMethod (exports, "swe_lun_occult_when_loc", node_swe_lun_occult_when_loc);
	Nan::SetMethod (exports, "swe_sol_eclipse_when_glob", node_swe_sol_eclipse_when_glob);
	Nan::SetMethod (exports, "swe_lun_occult_when_glob", node_swe_lun_occult_when_glob);
	Nan::SetMethod (exports, "swe_lun_eclipse_how", node_swe_lun_eclipse_how);
	Nan::SetMethod (exports, "swe_lun_eclipse_when", node_swe_lun_eclipse_when);
	Nan::SetMethod (exports, "swe_lun_eclipse_when_loc", node_swe_lun_eclipse_when_loc);
	Nan::SetMethod (exports, "swe_pheno", node_swe_pheno);
	Nan::SetMethod (exports, "swe_pheno_ut", node_swe_pheno_ut);
	Nan::SetMethod (exports, "swe_refrac", node_swe_refrac);
	Nan::SetMethod (exports, "swe_refrac_extended", node_swe_refrac_extended);
	Nan::SetMethod (exports, "swe_set_lapse_rate", node_swe_set_lapse_rate);
	Nan::SetMethod (exports, "swe_azalt", node_swe_azalt);
	Nan::SetMethod (exports, "swe_azalt_rev", node_swe_azalt_rev);
	Nan::SetMethod (exports, "swe_rise_trans", node_swe_rise_trans);
	Nan::SetMethod (exports, "swe_rise_trans_true_hor", node_swe_rise_trans_true_hor);
}

NODE_MODULE (swisseph, Initialize);
