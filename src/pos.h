#ifndef __swisseph_pos_h__
#define __swisseph_pos_h__

#include <node.h>

using namespace v8;

/**
 * char swe_version(char *);
 * =>
 * string swe_version([function callback (result)]);
 */
void node_swe_version (const FunctionCallbackInfo <Value> & args);

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
void node_swe_calc_ut (const FunctionCallbackInfo <Value> & args);

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
void node_swe_calc (const FunctionCallbackInfo <Value> & args);

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
void node_swe_fixstar (const FunctionCallbackInfo <Value> & args);

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
void node_swe_fixstar_ut (const FunctionCallbackInfo <Value> & args);

/**
 * int32 swe_fixstar_mag(char *star, double *mag, char *serr);
 * =>
 * swe_fixstar_mag(string star[, function callback (result)]) = {
 *   name: string,
 *   magnitude: double,
 *   error: string
 * }
 */
void node_swe_fixstar_mag (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_close(void);
 * =>
 * swe_close()
 */
void node_swe_close (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * swe_set_ephe_path(string path)
 */
void node_swe_set_ephe_path (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * swe_set_jpl_file(string fname)
 */
void node_swe_set_jpl_file (const FunctionCallbackInfo <Value> & args);

/**
 * char * swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) {
 *   name: string
 * }
 */
void node_swe_get_planet_name (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * swe_set_topo(double geolon, double geolat, double geoalt)
 */
void node_swe_set_topo (const FunctionCallbackInfo <Value> & args);

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 */
void node_swe_set_sid_mode (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * double swe_get_ayanamsa(double tjd_et)
 */
void node_swe_get_ayanamsa (const FunctionCallbackInfo <Value> & args);

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * double swe_get_ayanamsa_ut(double tjd_ut)
 */
void node_swe_get_ayanamsa_ut (const FunctionCallbackInfo <Value> & args);

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * string swe_get_ayanamsa_name(int32 isidmode)
 */
void node_swe_get_ayanamsa_name (const FunctionCallbackInfo <Value> & args);

#endif // __swisseph_pos_h__
