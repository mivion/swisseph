#ifndef __swisseph_eclipse_h__
#define __swisseph_eclipse_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * int32 swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double *geopos, double atpress, double attemp, double *dgsect, char *serr)
 * =>
 * swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   name: string,            //star
 *   gauquelinSector: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_gauquelin_sector);

/**
 * int32 swe_sol_eclipse_where(double tjd_ut, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * swe_sol_eclipse_where(double tjd_ut, int32 ifl[, function callback (result)]) = {
 *   rflag: long,
 *   longitude: double,                    // geopos [0]
 *   latitude: double,                     // geopos [1]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_where);

/**
 * int32 swe_lun_occult_where(double tjd_ut, int32 ipl, char *starname, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * swe_lun_occult_where(double tjd_ut, int32 ipl, char *starname, int32 ifl[, function callback (result)]) = {
 *   rflag: long,
 *   longitude: double,                    // geopos [0]
 *   latitude: double,                     // geopos [1]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_occult_where);

/**
 * int32 swe_sol_eclipse_how(double tjd_ut, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * swe_sol_eclipse_how(double tjd_ut, int32 ifl, double longitude, double latitude, double height[, function callback (result)]) = {
 *   rflag: long,
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_how);

/**
 * int32 swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos, double *tret, double *attr, int32 backward, char *serr)
 * =>
 * swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   maximum: double,                      // tret [0]
 *   first: double,                        // tret [1]
 *   second: double,                       // tret [2]
 *   third: double,                        // tret [3]
 *   forth: double,                        // tret [4]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_when_loc);

/**
 * int32 swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double *geopos, double *tret, double *attr, int32 backward, char *serr)
 * =>
 * swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   name: string,                         // star 
 *   maximum: double,                      // tret [0]
 *   first: double,                        // tret [1]
 *   second: double,                       // tret [2]
 *   third: double,                        // tret [3]
 *   forth: double,                        // tret [4]
 *   solarDiameterFraction: double,        // attr [0]
 *   lonarToSolarDiameterRatio: double,    // attr [1]
 *   solarDiscFraction: double,            // attr [2]
 *   coreShadow: double, // km             // attr [3]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonToSunAngularDistance: double,     // attr [7]
 *   eclipseMagnitude: double,             // attr [8]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_occult_when_loc);

/**
 * int32 swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 * =>
 * swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   maximum: double,      // tret [0]
 *   noon: double,         // tret [1]
 *   begin: double,        // tret [2]
 *   end: double,          // tret [3]
 *   totalBegin: double,   // tret [4]
 *   totalEnd: double,     // tret [5]
 *   centerBegin: double,  // tret [6]
 *   centerEnd: double,    // tret [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_sol_eclipse_when_glob);

/**
 * int32 swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 * =>
 * swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   name: string,         // star
 *   maximum: double,      // tret [0]
 *   noon: double,         // tret [1]
 *   begin: double,        // tret [2]
 *   end: double,          // tret [3]
 *   totalBegin: double,   // tret [4]
 *   totalEnd: double,     // tret [5]
 *   centerBegin: double,  // tret [6]
 *   centerEnd: double,    // tret [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_occult_when_glob);

/**
 * int32 swe_lun_eclipse_how(double tjd_ut, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * swe_lun_eclipse_how(double tjd_ut, int32 ifl, double longitude, double latitude, double height[, function callback (result)]) = {
 *   rflag: long,
 *   umbralMagnitude: double,          // attr [0]
 *   penumbralMagnitude: double,       // attr [1]
 *   azimuth: double,                  // attr [4] not implemented
 *   trueAltitude: double,             // attr [5] not implemented
 *   apparentAltitude: double,         // attr [6] not implemented
 *   oppositeDegreeDistance: double,   // attr [7]
 *   magnitude: double,                // attr [8]
 *   sarosNumber: double,              // attr [9]
 *   sarosMember: double,              // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_eclipse_how);

/**
 * int32 swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 * =>
 * swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   maximum: double,        // tret [0]
 *   partialBegin: double,   // tret [2]
 *   partialEnd: double,     // tret [3]
 *   totalBegin: double,     // tret [4]
 *   totalEnd: double,       // tret [5]
 *   penumbralBegin: double, // tret [6]
 *   penumbralEnd: double,   // tret [7]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_eclipse_when);

/**
 * int32 swe_lun_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * swe_lun_eclipse_when_loc(double tjd_start, int32 ifl, double longitude, double latitude, double height, int32 backward[, function callback (result)]) = {
 *   rflag: long,
 *   maximum: double,                      // tret [0]
 *   partialBegin: double,                 // tret [2]
 *   partialEnd: double,                   // tret [3]
 *   totalBegin: double,                   // tret [4]
 *   totalEnd: double,                     // tret [5]
 *   penumbralBegin: double,               // tret [6]
 *   penumbralEnd: double,                 // tret [7]
 *   moonRise: double                      // tret [8]
 *   moonSet: double,                      // tret [9]
 *   umbralMagnitude: double,              // attr [0]
 *   penumbralMagnitude: double,           // attr [1]
 *   azimuth: double,                      // attr [4]
 *   trueAltitude: double,                 // attr [5]
 *   apparentAltitude: double,             // attr [6]
 *   moonDistanceFromOpposition: double,   // attr [7]
 *   sarosNumber: double,                  // attr [9]
 *   sarosMember: double,                  // attr [10]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_lun_eclipse_when_loc);

/**
 * int32 swe_pheno(double tjd, int32 ipl, int32 iflag, double *attr, char *serr)
 * =>
 * swe_pheno(double tjd, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   rflag: number,
 *   phaseAngle: double,
 *   phase: double,
 *   elongation: double,
 *   apparentDiameter: double,
 *   apparentMagnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_pheno);

/**
 * int32 swe_pheno_ut(double tjd_ut, int32 ipl, int32 iflag, double *attr, char *serr)
 * =>
 * swe_pheno_ut(double tjd_ut, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   rflag: number,
 *   phaseAngle: double,
 *   phase: double,
 *   elongation: double,
 *   apparentDiameter: double,
 *   apparentMagnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_pheno_ut);

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 * =>
 * swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double
 * }
 */
NAN_METHOD(node_swe_refrac);

/**
 * double swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag, double *dret)
 * =>
 * swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag[, function callback (result)]) = {
 *   refraction: double,
 *   trueAltitude: double,      // dret [0]
 *   apparentAltitude: double,  // dret [1]
 *   horizonDip: double         // dret [3]
 * }
 */
NAN_METHOD(node_swe_refrac_extended);

/**
 * void swe_set_lapse_rate(double lapse_rate)
 * =>
 * swe_set_lapse_rate(double lapse_rate[, function callback (result)]) = {
 * }
 */
NAN_METHOD(node_swe_set_lapse_rate);

/**
 * void swe_azalt(double tjd_ut, int32 calc_flag, double *geopos, double atpress, double attemp, double *xin, double *xaz)
 * =>
 * swe_azalt(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double atpress, double attemp, double bodyX, double bodyY, double bodyZ[, function callback (result)]) = {
 *   azimuth: double,            // xaz [0]
 *   trueAltitude: double,       // xaz [1]
 *   apparentAltitude: double    // xaz [2]
 * }
 */
NAN_METHOD(node_swe_azalt);

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos, double *xin, double *xout)
 * =>
 * swe_azalt_rev(double tjd_ut, int32 calc_flag, double longitude, double latitude, double height, double bodyAzimuth, double bodyTrueAltitude[, function callback (result)]) = {
 *   azimuth: double,      // xout [0]
 *   trueAltitude: double  // xout [1]
 * }
 */
NAN_METHOD(node_swe_azalt_rev);

/**
 * int32 swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos, double atpress, double attemp, double *tret, char *serr)
 * =>
 * swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double longitude, double latitude, double height, double atpress, double attemp[, function callback (result)]) = {
 *   name: string,        // star
 *   transitTime: double, // tret [0]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_rise_trans);

/**
 * int32 swe_rise_trans_true_hor(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos (in[3]), double atpress, double attemp, double horhgt, double *tret (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * swe_rise_trans_true_hor(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double longitude, double latitude, double height, double atpress, double horhgt, double attemp[, function callback (result)]) = {
 *   name: string,        // star
 *   transitTime: double, // tret [0]
 *   error: string
 * }
 */
NAN_METHOD(node_swe_rise_trans_true_hor);

#endif // __swisseph_eclipse_h__
