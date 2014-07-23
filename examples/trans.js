var assert = require ('assert');
var fs = require ('fs');
var swisseph = require ('..');

// Test date
var date = {year: 2012, month: 1, day: 1, hour: 0};
console.log ('Test date:', date);

var flag = swisseph.SEFLG_SPEED | swisseph.SEFLG_MOSEPH;

// path to ephemeris data
swisseph.swe_set_ephe_path (__dirname + '/../ephe');

// Julian day
swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL, function (julday_ut) {
	assert.equal (julday_ut, 2455927.5);
	console.log ('Julian UT day for date:', julday_ut);
	
	var long = 64.22;
	var lat = 173.22;
	var height = 0;
	var atpress = 146;
	var attemp = 26;
	
    // Sun rise
	swisseph.swe_rise_trans (julday_ut, swisseph.SE_SUN, '', flag, swisseph.SE_CALC_RISE,
	    long, lat, height, atpress, attemp, function callback (result) {
		assert (!result.error, result.error);
	    console.log (result.transitTime);
	})

    // Moon rise
	swisseph.swe_rise_trans (julday_ut, swisseph.SE_MOON, '', flag, swisseph.SE_CALC_RISE,
	    long, lat, height, atpress, attemp, function (result) {
		assert (!result.error, result.error);
	    console.log (result.transitTime);
	})
});
