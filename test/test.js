var assert = require ('assert');
var fs = require ('fs');
var swisseph = require ('..');

// Test date
var date = {year: 2012, month: 1, day: 1, hour: 0};
console.log ('Test date: ', date);

// don't work at test server
swisseph.swe_set_ephe_path (__dirname + '/../ephe');

// Julian day
swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL, function (julday_ut) {
	assert.equal (julday_ut, 2455927.5);
	console.log ('Julian UT day for date: ', julday_ut);

	// Sun position UT
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_SUN, swisseph.SEFLG_SPEED, function (sun) {
		assert.ok (!sun.error, sun.error);
		console.log ('Sun position: ', sun);
	});

	// Sun position ET
	swisseph.swe_calc (julday_ut, swisseph.SE_SUN, swisseph.SEFLG_SPEED, function (sun) {
		assert.ok (!sun.error, sun.error);
		console.log ('Sun position ET: ', sun);
	});

	// Moon position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_MOON, swisseph.SEFLG_SPEED, function (moon) {
		assert.ok (!moon.error, moon.error);
		console.log ('Moon position: ', moon);
	});

	// Aldebaran position
	swisseph.swe_fixstar ('Aldebaran', julday_ut, swisseph.SEFLG_SPEED, function (aldebaran) {
		assert.ok (!aldebaran.error, aldebaran.error);
		console.log ('Aldebaran position: ', aldebaran);
	});
});
