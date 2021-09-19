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
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_calc_ut);

/**
 * int32 swe_calc(double tjd, int ipl, int32 iflag, double *xx, char *serr)
 * =>
 * swe_calc(double tjd, int32 ipl, int32 iflag[, function callback (result)]) = {
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_calc);

/**
 * int32 swe_fixstar(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar);

/**
 * int32 swe_fixstar_ut(char *star, double tjd_ut, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar_ut(string star, double tjd_ut, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
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
 * int32 swe_fixstar2(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar2(string star, double tjd, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar2);

/**
 * int32 swe_fixstar2_ut(char *star, double tjd_ut, int32 iflag, double *xx, char *serr)
 * =>
 * swe_fixstar2_ut(string star, double tjd_ut, int32 iflag[, function callback (result)]) = {
 *   name: string,
 *   longitude:      | rectAscension:      | x:  double,
 *   latitude:       | declination:        | y:  double,
 *   distance:       | distance:           | z:  double,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *   latitudeSpeed:  | declinationSpeed:   | dy: double,
 *   distanceSpeed:  | distanceSpeed:      | dz: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar2_ut);

/**
 * int32 swe_fixstar2_mag(char *star, double *mag, char *serr);
 * =>
 * swe_fixstar2_mag(string star[, function callback (result)]) = {
 *   name: string,
 *   magnitude: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_fixstar2_mag);

/**
 * void swe_close(void);
 * =>
 * swe_close([function callback (undefined)]) = undefined
 */
NAN_METHOD(node_swe_close);

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * swe_set_ephe_path(string path[, function callback (path)]) = String
 */
NAN_METHOD(node_swe_set_ephe_path);

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * swe_set_jpl_file(string fname[, function callback (fname)]) = String
 */
NAN_METHOD(node_swe_set_jpl_file);

/**
 * char * swe_get_planet_name(int ipl, char *spname)
 * =>
 * swe_get_planet_name(int ipl) = {
 *   name: string
 * }
 */
NAN_METHOD(node_swe_get_planet_name);

/**
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * swe_set_topo(double geolon, double geolat[, function callback (undefined)]) = undefined
 */
NAN_METHOD(node_swe_set_topo);

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0[, function callback (undefined)]) = undefined
 */
NAN_METHOD(node_swe_set_sid_mode);

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * swe_get_ayanamsa(double tjd_et[, function callback (result)]) = double
 */
NAN_METHOD(node_swe_get_ayanamsa);

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * swe_get_ayanamsa_ut(double tjd_ut[, function callback (result)]) = double
 */
NAN_METHOD(node_swe_get_ayanamsa_ut);

/**
 * int32 swe_get_ayanamsa_ex(double tjd_et, int32 iflag, double *daya, char *serr);
 * =>
 * swe_get_ayanamsa_ex(double tjd_et, int32 iflag[, function callback (result)]) = {
 *   ayanamsa: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_get_ayanamsa_ex);

/**
 * int32 swe_get_ayanamsa_ex_ut(double tjd_ut, int32 iflag, double *daya, char *serr);
 * =>
 * swe_get_ayanamsa_ex_ut(double tjd_ut, int32 iflag[, function callback (result)]) = {
 *   ayanamsa: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_get_ayanamsa_ex_ut);

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * swe_get_ayanamsa_name(int32 isidmode[, function callback (result)]) = string
 */
NAN_METHOD(node_swe_get_ayanamsa_name);

/**
 * int32 swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32  method, double *xnasc, double *xndsc, double *xperi, double *xaphe, char *serr)
 * =>
 * swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32 method[, function callback (result)]) = {
 *   ascending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   descending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   perihelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   aphelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   error: string
 * }
 */
NAN_METHOD(node_swe_nod_aps);

/**
 * int32 swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32 method, double *xnasc, double *xndsc, double *xperi, double *xaphe, char *serr)
 * =>
 * swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32 method[, function callback (result)]) = {
 *   ascending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   descending: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   perihelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   aphelion: {
 *     longitude:      | rectAscension:      | x:  double,
 *     latitude:       | declination:        | y:  double,
 *     distance:       | distance:           | z:  double,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: double,
 *     latitudeSpeed:  | declinationSpeed:   | dy: double,
 *     distanceSpeed:  | distanceSpeed:      | dz: double
 *   },
 *   error: string
 * }
 */
NAN_METHOD(node_swe_nod_aps_ut);

/**
 * int32 swe_get_orbital_elements(double tjd_et, int32 ipl, in32 iflag, double *dret, char *serr)
 * =>
 * swe_get_orbital_elements(double tjd_et, int32 ipl, in32 iflag[, function callback (result)]) = {
 *   aphelionDistance: double
 *   ascendingNode: double
 *   eccentricAnomaly: double
 *   eccentricity: double
 *   inclination: double
 *   meanAnomaly: double
 *   meanDailyMotion: double
 *   meanLongitude: double
 *   periapsis: double
 *   periapsisArg: double
 *   perihelionDistance: double
 *   perihelionPassage: double
 *   semimajorAxis: double
 *   siderealPeriod: double
 *   synodicPeriod: double
 *   tropicalPeriod: double
 *   trueAnomaly: double
 *   rflag: int
 *   error: string
 * }
 */
NAN_METHOD(node_swe_get_orbital_elements);

/**
 * int32 swe_orbit_max_min_true_distance(double tjd_et, int32 ipl, int32 iflag, double *dmax, double *dmin, double *dtrue, char *serr)
 * =>
 * swe_orbit_max_min_true_distance(double tjd_et, int32 ipl, in32 iflag[, function callback (result)]) = {
 *   maxDistance: double
 *   minDistance: double
 *   trueDistance: double
 *   rflag: int
 *   error: string
 * }
 */
NAN_METHOD(node_swe_orbit_max_min_true_distance);

#endif // __swisseph_pos_h__
