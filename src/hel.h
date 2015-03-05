#ifndef __swisseph_hel_h__
#define __swisseph_hel_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * int32 swe_heliacal_ut(double tjdstart_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 iflag, double *dret, char *serr);
 * =>
 * swe_heliacal_ut(double tjdstart_ut, double *geopos, double *datm, double *dobs, string ObjectName, int32 TypeEvent, int32 iflag) {
 *   start: double,
 *   optimum: double,
 *   end: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_heliacal_ut);

/**
 * int32 swe_heliacal_pheno_ut(double tjd_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 helflag, double *darr, char *serr)
 * =>
 * swe_heliacal_pheno_ut(double tjd_ut, double *geopos, double *datm, double *dobs, string ObjectName, int32 TypeEvent, int32 helflag) {
 *   AltO: double,
 *   AppAltO: double,
 *   GeoAltO: double,
 *   AziO: double,
 *   AltS: double,
 *   AziS: double,
 *   TAVact: double,
 *   ARCVact: double,
 *   DAZact: double,
 *   ARCLact: double,
 *   kact: double,
 *   MinTAV: double,
 *   TfirstVR: double,
 *   TbVR: double,
 *   TlastVR: double,
 *   TbYallop: double,
 *   WMoon: double,
 *   qYal: double,
 *   qCrit: double,
 *   ParO: double,
 *   MagnO: double,
 *   RiseSetO: double,
 *   RiseSetS: double,
 *   Lag: double,
 *   TvisVR: double,
 *   LMoon: double,
 *   elong: double,
 *   illum: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_heliacal_pheno_ut);

/**
 * int32 swe_vis_limit_mag(double tjdut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 helflag, double *dret, char *serr)
 * =>
 * swe_vis_limit_mag(double tjdut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 helflag) {
 *   VisLimMagn: double,
 *   AltO: double,
 *   AziO: double,
 *   AltS: double,
 *   AziS: double,
 *   AltM: double,
 *   AziM: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_vis_limit_mag);

#endif // __swisseph_hel_h__
