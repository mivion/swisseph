#ifndef __swisseph_pos_h__
#define __swisseph_pos_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * char swe_version(char *);
 * =>
 * string swe_version([function callback (result)]);
 */
Handle <Value> node_swe_version (const Arguments & args);

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
Handle <Value> node_swe_calc_ut (const Arguments & args);

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
Handle <Value> node_swe_calc (const Arguments & args);

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
Handle <Value> node_swe_fixstar (const Arguments & args);

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
Handle <Value> node_swe_fixstar_ut (const Arguments & args);

/**
 * int32 swe_fixstar_mag(char *star, double *mag, char *serr);
 * =>
 * swe_fixstar_mag(string star[, function callback (result)]) = {
 *   name: string,
 *   magnitude: double,
 *   error: string
 * }
 */
Handle <Value> node_swe_fixstar_mag (const Arguments & args);

/**
 * void swe_close(void);
 * =>
 * swe_close()
 */
Handle <Value> node_swe_close (const Arguments & args);

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * swe_set_ephe_path(string path)
 */
Handle <Value> node_swe_set_ephe_path (const Arguments & args);

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * swe_set_jpl_file(string fname)
 */
Handle <Value> node_swe_set_jpl_file (const Arguments & args);

/**
 * char * swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) {
 *   name: string
 * }
 */
Handle <Value> node_swe_get_planet_name (const Arguments & args);

/**
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * swe_set_topo(double geolon, double geolat, double geoalt)
 */
Handle <Value> node_swe_set_topo (const Arguments & args);

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 */
Handle <Value> node_swe_set_sid_mode (const Arguments & args);

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * double swe_get_ayanamsa(double tjd_et)
 */
Handle <Value> node_swe_get_ayanamsa (const Arguments & args);

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * double swe_get_ayanamsa_ut(double tjd_ut)
 */
Handle <Value> node_swe_get_ayanamsa_ut (const Arguments & args);

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * string swe_get_ayanamsa_name(int32 isidmode)
 */
Handle <Value> node_swe_get_ayanamsa_name (const Arguments & args);

#endif // __swisseph_pos_h__
