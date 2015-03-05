#ifndef __swisseph_pos_h__
#define __swisseph_pos_h__

#include <node.h>

using namespace v8;

/**
 * char swe_version(char *);
 * =>
 * string swe_version([function callback (result)]);
 */
NAN_METHOD(node_swe_version);

/**
 * int32 swe_calc_ut(double tjd_ut, int32 ipl, int32 iflag, double *xx, char *serr)
 * =>
 * swe_calc_ut(double tjd_ut, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_calc_ut);

/**
 * int32 swe_calc(double tjd, int ipl, int32 iflag, double *xx, char *serr)
 * =>
 * swe_calc(double tjd, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_calc);

/**
 * int32 swe_fixstar(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar);

/**
 * int32 swe_fixstar_ut(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar_ut(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   longitude: double,
 *   latitude: double,
 *   distance: double,
 *   longitudeSpeed: double,
 *   latitudeSpeed: double,
 *   distanceSpeed: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar_ut);

/**
 * int32 swe_fixstar_mag(char *star, double *mag, char *serr);
 * =>
 * swe_fixstar_mag(string star[, function callback (result)]) = {
 *   name: string,
 *   magnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar_mag);

/**
 * void swe_close(void);
 * =>
 * swe_close()
 */
NAN_METHOD(node_swe_close);

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * swe_set_ephe_path(string path)
 */
NAN_METHOD(node_swe_set_ephe_path);

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * swe_set_jpl_file(string fname)
 */
NAN_METHOD(node_swe_set_jpl_file);

/**
 * char * swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) {
 *   name: string
 * }
 */
NAN_METHOD(node_swe_get_planet_name);

/**
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * swe_set_topo(double geolon, double geolat, double geoalt)
 */
NAN_METHOD(node_swe_set_topo);

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 */
NAN_METHOD(node_swe_set_sid_mode);

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * double swe_get_ayanamsa(double tjd_et)
 */
NAN_METHOD(node_swe_get_ayanamsa);

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * double swe_get_ayanamsa_ut(double tjd_ut)
 */
NAN_METHOD(node_swe_get_ayanamsa_ut);

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * string swe_get_ayanamsa_name(int32 isidmode)
 */
NAN_METHOD(node_swe_get_ayanamsa_name);

#endif // __swisseph_pos_h__
