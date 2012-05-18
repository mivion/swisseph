var assert = require ('assert');
var util = require ('util');
var swisseph = require ('..');

var date;
var julday_ut;
var sun;

// Test date
date = {
	year: 2012,
	month: 1,
	day: 1,
	hour: 0,
};
console.log ('Test date: ' + util.inspect (date));

// Julian day
julday_ut = swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL, function (result) {
	console.log ('Julian UT day for date from callback: ', result);
});
assert.equal (julday_ut, 2455927.5);
console.log ('Julian UT day for date: ', julday_ut);

// Sun position
sun = swisseph.swe_calc_ut (
	julday_ut,
	swisseph.SE_SUN,
	swisseph.SEFLG_SPEED |
	swisseph.SEFLG_MOSEPH,
	function (result) {
		console.log ('Moon position for date (callback): ', result);
	}
);
console.log ('Sun position for date: ', sun);

// Moon position
moon = swisseph.swe_calc_ut (
	julday_ut,
	swisseph.SE_MOON,
	swisseph.SEFLG_SPEED |
	swisseph.SEFLG_MOSEPH,
	function (result) {
		console.log ('Moon position for date (callback): ', result);
	}
);
console.log ('Moon position for date: ', moon);
