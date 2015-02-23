var swisseph = require ('..');

// Test date
var date = {year: 2014, month: 1, day: 1, hour: 0};
console.log ('Date:', date);

var flag = swisseph.SEFLG_SPEED | swisseph.SEFLG_MOSEPH;

// path to ephemeris data
swisseph.swe_set_ephe_path (__dirname + '/../ephe');

strtime = function (value) {
	var hour = Math.floor (value);
	var minFrac = (value - hour) * 60;
	var min = Math.floor (minFrac);
	var sec = Math.floor ((minFrac - min) * 60);
	
	return hour + ' ' + min + ' ' + sec;
};

logbody = function (name, body) {
    var lang = body.longitude;
    var house = Math.floor (lang / 30);
    var lang30 = lang - house * 30;

	console.log (name + ':', body.longitude, '|', strtime (lang30), '|', house, body.longitudeSpeed < 0 ? 'R' : '');
//    console.log (name + ' info:', body);
};

// Julian day
swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL, function (julday_ut) {
	console.log ('Julian UT:', julday_ut);
	
	swisseph.swe_deltat (julday_ut, function (deltat) {
	    console.log ('Delta T:', deltat.delta * 60 * 60 * 24);
	});

	swisseph.swe_sidtime (julday_ut, function (result) {
	    console.log ('Siderial time (dec):', result.siderialTime);
	    console.log ('Sidereal time (time):', strtime (result.siderialTime));
	});

	// Sun position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_SUN, flag, function (body) {
        logbody ('Sun', body);
	});

	// Moon position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_MOON, flag, function (body) {
        logbody ('Moon', body);
	});

	// Mean node position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_MEAN_NODE, flag, function (body) {
        logbody ('Mean node', body);
	});

	swisseph.swe_calc_ut (julday_ut, swisseph.SE_TRUE_NODE, flag, function (body) {
        logbody ('True node', body);
	});

	swisseph.swe_calc_ut (julday_ut, swisseph.SE_MEAN_APOG, flag, function (body) {
        logbody ('Mean apog', body);
	});

	swisseph.swe_calc_ut (julday_ut, swisseph.SE_OSCU_APOG, flag, function (body) {
        logbody ('Oscu apog', body);
	});

	swisseph.swe_calc_ut (julday_ut, swisseph.SE_CHIRON, flag, function (body) {
        logbody ('Chiron', body);
	});
});
