var assert = require ('assert');
var swisseph = require ('..');

var version = swisseph.swe_version ();

console.log ('Swiss Ephemeris version:', version);

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

	// Date conversion
	swisseph.swe_date_conversion (date.year, date.month, date.day, date.hour, 'g', function (result) {
		assert (!result.error, result.error);
		assert.equal (julday_ut, result.julianDay);
		console.log ('Julian UT day for date:', result);
	});

	// Reverse date conversion
	swisseph.swe_revjul (julday_ut, swisseph.SE_GREG_CAL, function (result) {
		assert.equal (date.year, result.year);
		assert.equal (date.month, result.month);
		assert.equal (date.day, result.day);
		assert.equal (date.hour, result.hour);
		console.log ('Date from Julian UT day:', result);
	});

	// Julian UT|ET days
	swisseph.swe_utc_to_jd (date.year, date.month, date.day, date.hour, 0, 0, swisseph.SE_GREG_CAL, function (result) {
		assert (!result.error, result.error);
		console.log ('Julian UT|ET days for date:', result);
	});

	// Reverse date conversion from ET
	swisseph.swe_jdet_to_utc (julday_ut, swisseph.SE_GREG_CAL, function (result) {
		console.log ('UTC Date from ET Julian day:', result);
	});

	// Reverse date conversion from UT
	swisseph.swe_jdut1_to_utc (julday_ut, swisseph.SE_GREG_CAL, function (result) {
		console.log ('UTC Date from UT Julian day:', result);
	});

	// Time zone
	swisseph.swe_utc_time_zone (date.year, date.month, date.day, date.hour, 0, 0, 5.5, function (result) {
		console.log ('Date from +5.5 Time Zone:', result);
	});

	// Setting topocentric coordinates
	swisseph.swe_set_topo (0, 0, 0);

	// Sun name
	swisseph.swe_get_planet_name (swisseph.SE_SUN, function (body) {
		assert (!body.error, body.error);
		console.log ('Sun name:', body);
	});

	// Sun position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_SUN, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Sun position:', body);
	});

	// Chiron position
/*
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_CHIRON, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Chiron position:', body);
	});
*/

	// Moon position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_MOON, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Moon position:', body);

		// Moon house position
	    swisseph.swe_houses_pos (24, 0, 23, 'K', body.longitude,  body.latitude, function (result) {
			assert (!result.error, result.error);
			console.log ('Moon house position:', result);
	    });
	});

	// Mars phenomena
	swisseph.swe_pheno_ut (julday_ut, swisseph.SE_MARS, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Mars phenomena:', body);
	});

	// Chiron name
	swisseph.swe_get_planet_name (swisseph.SE_CHIRON, function (body) {
		assert (!body.error, body.error);
		console.log ('Chiron name:', body);
	});

	// Aldebaran position
	swisseph.swe_fixstar_ut ('Aldebaran', julday_ut, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Aldebaran position:', body);
	});

	// Aldebaran magnitude
	swisseph.swe_fixstar_mag ('Aldebaran', function (body) {
		assert (!body.error, body.error);
		console.log ('Aldebaran magnitude:', body);
	});

	// Mercury heliacal
    swisseph.swe_heliacal_ut (julday_ut, [-71.13, 42.27, 0], [0, 0, 0, 0], [36, 1, 0, 0, 0, 0], 'Mercury', swisseph.SE_HELIACAL_RISING, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Mercury heliacal:', body);
    });

	// Mars heliacal phenomen
    swisseph.swe_heliacal_pheno_ut (julday_ut, [-71.13, 42.27, 0], [0, 0, 0, 0], [36, 1, 0, 0, 0, 0], 'Mars', swisseph.SE_HELIACAL_RISING, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Mars heliacal phenomen:', body);
    });

	// Neptune visible magnitude limit
    swisseph.swe_vis_limit_mag (julday_ut, [-71.13, 42.27, 0], [0, 0, 0, 0], [36, 1, 0, 0, 0, 0], 'Neptune', flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Neptune visible magnitude limit:', body);
    });

	// Houses
    swisseph.swe_houses (julday_ut, 0, 0, 'K', function (result) {
		assert (!result.error, result.error);
		console.log ('Houses for date:', result);
    });

    swisseph.swe_houses (julday_ut, 0, 0, 'G', function (result) {
		assert (!result.error, result.error);
		console.log ('Gauquelin houses for date:', result);
    });

	// Siderial houses
    swisseph.swe_houses_ex (julday_ut, 0, 0, 0, 'K', function (result) {
		assert (!result.error, result.error);
		console.log ('Siderial houses for date:', result);
    });

    swisseph.swe_houses_ex (julday_ut, 0, 0, 0, 'G', function (result) {
		assert (!result.error, result.error);
		console.log ('Siderial Gauquelin houses for date:', result);
    });

	// ARMC houses
	swisseph.swe_get_ayanamsa (julday_ut, function (ayanamsa) {
		console.log ('Ayanamsa for date:', ayanamsa);
	    swisseph.swe_houses_armc (ayanamsa, 0, 23, 'K', function (result) {
			assert (!result.error, result.error);
			console.log ('ARMC houses for date:', result);
	    });
	    
	    swisseph.swe_houses_armc (ayanamsa, 0, 23, 'G', function (result) {
			assert (!result.error, result.error);
			console.log ('ARMC Gauquelin houses for date:', result);
	    });
	});
});
