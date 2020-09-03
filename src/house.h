#ifndef __swisseph_house_h__
#define __swisseph_house_h__

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * int swe_houses(double tjd_ut, double geolat, double geolon, int hsys, double *cusps, double *ascmc)
 * =>
 * int swe_houses(double tjd_ut, double geolat, double geolon, int hsys, double *cusps, double *ascmc) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses);

/**
 * int swe_houses_ex(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc)
 * =>
 * int swe_houses_ex(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses_ex);

/**
 * int swe_houses_ex2(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr)
 * =>
 * int swe_houses_ex2(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   houseSpeed: [double],
 *   ascendantSpeed: double,
 *   mcSpeed: double,
 *   armcSpeed: double,
 *   vertexSpeed: double,
 *   equatorialAscendantSpeed: double,
 *   kochCoAscendantSpeed: double,
 *   munkaseyCoAscendantSpeed: double,
 *   munkaseyPolarAscendantSpeed: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses_ex2);

/**
 * int swe_houses_armc(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc)
 * =>
 * int swe_houses_armc(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses_armc);

/**
 * int swe_houses_armc2(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr)
 * =>
 * int swe_houses_armc2(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr) {
 *   house: [double],
 *   ascendant: double,
 *   mc: double,
 *   armc: double,
 *   vertex: double,
 *   equatorialAscendant: double,
 *   kochCoAscendant: double,
 *   munkaseyCoAscendant: double,
 *   munkaseyPolarAscendant: double,
 *   houseSpeed: [double],
 *   ascendantSpeed: double,
 *   mcSpeed: double,
 *   armcSpeed: double,
 *   vertexSpeed: double,
 *   equatorialAscendantSpeed: double,
 *   kochCoAscendantSpeed: double,
 *   munkaseyCoAscendantSpeed: double,
 *   munkaseyPolarAscendantSpeed: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses_armc_ex2);

/**
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double *xpin, char *serr)
 * =>
 * double swe_house_pos(double armc, double geolat, double eps, int hsys, double lon, double lat) {
 *   housePosition: double,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_houses_pos);

#endif // __swisseph_house_h__
