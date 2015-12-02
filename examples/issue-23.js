var swisseph = require("..");
var assert = require("assert");

// Test date 
var date = {year: 2012, month: 1, day: 1, hour: 0};
console.log("Test date:", date);

var julday_ut = swisseph.swe_julday(date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL);

assert.equal(julday_ut, 2455927.5);
console.log("Julian UT day for date:", julday_ut);

var flag = swisseph.SEFLG_MOSEPH;
var body = swisseph.swe_calc_ut(julday_ut, swisseph.SE_SUN, flag);
assert(!body.error, body.error);
console.log("Sun ecliptic position:", body);

flag = swisseph.SEFLG_EQUATORIAL | swisseph.SEFLG_MOSEPH;
body = swisseph.swe_calc_ut(julday_ut, swisseph.SE_SUN, flag);
assert(!body.error, body.error);
console.log("Sun equatorial position:", body);

flag = swisseph.SEFLG_XYZ | swisseph.SEFLG_MOSEPH;
body = swisseph.swe_calc_ut(julday_ut, swisseph.SE_SUN, flag);
assert(!body.error, body.error);
console.log("Sun in cartesian coordinates:", body);