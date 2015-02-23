#ifndef __swisseph_eclipse_h__
#define __swisseph_eclipse_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * int32 swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double *geopos, double atpress, double attemp, double *dgsect, char *serr)
 */
void node_swe_gauquelin_sector (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_sol_eclipse_where(double tjd, int32 ifl, double *geopos, double *attr, char *serr)
 */
void node_swe_sol_eclipse_where (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_lun_occult_where(double tjd, int32 ipl, char *starname, int32 ifl, double *geopos, double *attr, char *serr)
 */
void node_swe_lun_occult_where (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_sol_eclipse_how(double tjd, int32 ifl, double *geopos, double *attr, char *serr)
 */
void node_swe_sol_eclipse_how (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos, double *tret, double *attr, int32 backward, char *serr)
 */
void node_swe_sol_eclipse_when_loc (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double *geopos, double *tret, double *attr, int32 backward, char *serr)
 */
void node_swe_lun_occult_when_loc (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 */
void node_swe_sol_eclipse_when_glob (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 */
void node_swe_lun_occult_when_glob (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_lun_eclipse_how(double tjd_ut, int32 ifl, double *geopos, double *attr, char *serr)
 */
void node_swe_lun_eclipse_how (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 */
void node_swe_lun_eclipse_when (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_pheno(double tjd, int32 ipl, int32 iflag, double *attr, char *serr)
 * =>
 * swe_pheno(double tjd, int32 ipl, int32 iflag) {
 *   phaseAngle: double,
 *   phase: double,
 *   elongation: double,
 *   apparentDiameter: double,
 *   apparentMagnitude: double,
 *   error: string
 * }
 */
void node_swe_pheno (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_pheno_ut(double tjd, int32 ipl, int32 iflag, double *attr, char *serr)
 * =>
 * swe_pheno_ut(double tjd, int32 ipl, int32 iflag) {
 *   phaseAngle: double,
 *   phase: double,
 *   elongation: double,
 *   apparentDiameter: double,
 *   apparentMagnitude: double,
 *   error: string
 * }
 */
void node_swe_pheno_ut (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 */
void node_swe_refrac (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag, double *dret)
 */
void node_swe_refrac_extended (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_set_lapse_rate(double lapse_rate)
 */
void node_swe_set_lapse_rate (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_azalt(double tjd_ut, int32 calc_flag, double *geopos, double atpress, double attemp, double *xin, double *xaz)
 */
void node_swe_azalt (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos, double *xin, double *xout)
 */
void node_swe_azalt_rev (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos, double atpress, double attemp, double *tret, char *serr)
 */
void node_swe_rise_trans (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32  method, double *xnasc, double *xndsc, double *xperi, double *xaphe, char *serr)
 */
void node_swe_nod_aps (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32  method, double *xnasc, double *xndsc, double *xperi, double *xaphe, char *serr)
 */
void node_swe_nod_aps_ut (const FunctionCallbackInfo <Value> & args);

#endif // __swisseph_eclipse_h__
