var swisseph = require('..');
var assert   = require('assert');

// Moscow, Russian Federation
var longitude = 37.61556;
var latitude  = 55.75222;
var altitude  = 156; // meters above sea
var tzone     = 3;   // GMT+3

var pressure    = 1000; // in hPa
var temperature = 10;   // in Celsius degree
var angle       = 10;   // in degree above horizont

var iflag = swisseph.SEFLG_SPEED | swisseph.SEFLG_MOSEPH | swisseph.SEFLG_TOPOCTR;

swisseph.swe_set_ephe_path (__dirname + '/../ephe');
swisseph.swe_set_topo(longitude, latitude, altitude);

var year = {
	start: new Date(2016,  0,  1),
	end:   new Date(2016, 11, 31, 23, 59, 59, 999)
};

var msPerDay = 1000 * 60 * 60 * 24;

function JulianDate(jsDate) {
	var jET;
	with(jsDate)
		swisseph.swe_utc_time_zone (
			getFullYear(), 
			getMonth() + 1, 
			getDate(), 
			getHours(), 
			getMinutes(), 
			getSeconds() + getMilliseconds() / 1000, 
			tzone, 
			function (result) {jET = result;}
			);
	with(jET)
		swisseph.swe_utc_to_jd (
			year, 
			month, 
			day, 
			hour, 
			minute, 
			second, 
			swisseph.SE_GREG_CAL, 
			function (result) {
				assert (!result.error, result.error);
				jET = result.julianDayET;
			});
	return jET;
};

function LocalDate(jET) {
	swisseph.swe_jdet_to_utc (
		jET, 
		swisseph.SE_GREG_CAL, 
		function (result) {jET = result;}
		);
	with(jET)
		swisseph.swe_utc_time_zone (
			year, 
			month, 
			day, 
			hour, 
			minute, 
			second, 
			-tzone, 
			function (result) {jET = result;}
			);
	var intS = Math.floor(jET.second);
	var mS   = Math.round(1000 * (jET.second - intS));
	with(jET)
		var jsDate = new Date(year, month - 1, day, hour, minute, intS, mS);
	return jsDate;
};

function BodyName(Body) {
	if(typeof(Body) === 'string')
		return Body;
	var name;
	swisseph.swe_get_planet_name(Body, function(result) {
		assert (!result.error, result.error);
		name = result.name;
	});
	return name;
};

function TransName(Trans) {
	var names = [
		'rise',           // swisseph.SE_CALC_RISE
		'set',            // swisseph.SE_CALC_SET
		'upper meridian', // swisseph.SE_CALC_MTRANSIT
		'lower meridian'  // swisseph.SE_CALC_ITRANSIT
	];
	return names[Math.log2(Trans)] + ' transit';
};

function RiseTrans(jET, Planet, Star, TransKind, HorzAngle) {
	var et;
	if(HorzAngle == undefined) {
		swisseph.swe_rise_trans(jET, 
			Planet,
			Star,
			iflag,
			TransKind,
			longitude,
			latitude,
			altitude,
			pressure,
			temperature,
			function (result) {
				assert (!result.error, result.error);
				et = result.transitTime
			});
		return et;
	};
		
	swisseph.swe_rise_trans_true_hor(jET, 
		Planet,
		Star,
		iflag,
		TransKind,
		longitude,
		latitude,
		altitude,
		pressure,
		temperature,
		HorzAngle,
		function (result) {
			assert (!result.error, result.error);
			et = result.transitTime
		});
	return et;
};

//--- main --- //
console.log('NOTE: This example using Moshier ephemeris!')
console.log('Some stars and bodies maybe not rise or not set under horizont!');
var dh, dt;
var jd = JulianDate(new Date());

var bodyList = [
	swisseph.SE_SUN, 
	swisseph.SE_MOON, 
	'Sirius', 
	'Algol'
];

bodyList.forEach(function(b) {
	[swisseph.SE_CALC_RISE, swisseph.SE_CALC_MTRANSIT].forEach(function(trans) {
		var et = RiseTrans(jd, 
			(typeof(b) === 'string') ? 0 : b, 
			(typeof(b) === 'string') ? b : '', 
			trans);
		if(et === -2) 
			dh = 'never going to happen'
		else 
			dh = new Date(LocalDate(et));
		
		et = RiseTrans(jd, 
			(typeof(b) === 'string') ? 0 : b, 
			(typeof(b) === 'string') ? b : '', 
			trans,
			angle);
		if(et === -2) 
			dt = 'never going to happen'
		else 
			dt = new Date(LocalDate(et));
		
		console.log({
			body: BodyName(b),
			kind: TransName(trans),
			horz: dh,
			angl: dt
		});
	});	
});
