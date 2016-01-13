var swisseph = require('..');
var assert   = require('assert');

// Moscow, Russian Federation
var longitude = 37.61556;
var latitude  = 55.75222;
var altitude  = 156; // meters above sea
var tzone     = 3;   // GMT+3

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
	var name;
	swisseph.swe_get_planet_name(Body, function(result) {
		assert (!result.error, result.error);
		name = result.name;
	});
	return name;
};

function SunEclipseWhenLoc(jET) {
	var loc = [];
	swisseph.swe_sol_eclipse_when_loc(jET, 
		iflag,
		longitude,
		latitude,
		altitude,
		0, /* TRUE, if backward search */
		function (result) {
			assert (!result.error, result.error);
			loc.et   = result.maximum;
			loc.flag = result.rflag;
		});
	return loc;
};

function SunEclipseWhenGlob(jET) {
	var glob = [];
	swisseph.swe_sol_eclipse_when_glob(jET, 
		iflag,
		0, // any eclipse type
		0, /* TRUE, if backward search */
		function (result) {
			assert (!result.error, result.error);
			glob.et   = result.maximum;
			glob.flag = result.rflag;
		});
	var loc = SunEclipseWhenLoc(glob.et - 1);
	glob.loc = Math.abs(glob.et - loc.et) < 1;
	if(glob.loc) {
		glob.et    = loc.et;
		glob.flag += loc.flag;
	};
	return glob;
};

function MoonEclipseWhenLoc(jET) {
	var loc = [];
	swisseph.swe_lun_eclipse_when_loc(jET, 
		iflag, 
		longitude,
		latitude,
		altitude,
		0, /* TRUE, if backward search */
		function (result) {
			assert (!result.error, result.error);
			loc.et   = result.maximum;
			loc.flag = result.rflag;
		});
	return loc;
};

function MoonEclipseWhenGlob(jET) {
	var glob = [];
	swisseph.swe_lun_eclipse_when(jET, 
		iflag, 
		0, // any eclipse type
		0, /* TRUE, if backward search */
		function (result) {
			assert (!result.error, result.error);
			glob.et   = result.maximum;
			glob.flag = result.rflag;
		});
	var loc = MoonEclipseWhenLoc(glob.et - 1);
	glob.loc = Math.abs(glob.et - loc.et) < 1;
	if(glob.loc) {
		glob.et    = loc.et;
		glob.flag += loc.flag;
	};
	return glob;
};

function MoonOccultWhenLoc(jET, Planet, Star) {
	var loc = [];
	swisseph.swe_lun_occult_when_loc(jET, 
		Planet,
		Star,
		iflag, 
		longitude,
		latitude,
		altitude,
		0, /* TRUE, if backward search */
		function (result) {
			assert (!result.error, result.error);
			loc.et   = result.maximum;
			loc.flag = result.rflag;
		});
	return loc;
};

function MoonOccultWhenGlob(jET, Planet, Star) {
	var glob = [];
	swisseph.swe_lun_occult_when_glob(jET,
		Planet, 
		Star,	
		iflag, 
		0, // any eclipse type
		0, /* TRUE, if backward search */
		function (result) {
			assert (!result.error, result.error);
			glob.et   = result.maximum;
			glob.flag = result.rflag;
		});
	if(glob.flag > 0) {
		var loc = MoonOccultWhenLoc(glob.et - 1, Planet, Star);
		glob.loc = Math.abs(glob.et - loc.et) < 1;
		if(glob.loc) {
			glob.et    = loc.et;
			glob.flag += loc.flag;
		};
	};
	return glob;
};

function eclipseDesc(Flag) {
	var n = 0;
	var s = '';
	[
		'central',
		'noncentral',
		'total',
		'annular',
		'partial',
		'annular total',
		'penumbral',
		'visible',
		'max visible',
		'1st visible',
		'2nd visible',
		'3rd visible',
		'4th visible'
	].forEach(function(desc, i) {
		if(Flag & Math.pow(2, i)) {
			s += ((n > 0) ? ', ' : '') + desc;
			n++;
		};
	});
	return s;
};

//--- main --- //
console.log('NOTE: This example using Moshier ephemeris!')
console.log('--- eclipses:');
[
	function (start) {return  SunEclipseWhenGlob(JulianDate(start));}, 
	function (start) {return MoonEclipseWhenGlob(JulianDate(start));} 
].forEach(function(ecl, b) {
	var dloc = new Date(year.start);
	var jloc;
	do {
		jloc = ecl(dloc);
		dloc = new Date(LocalDate(jloc.et));
		if(dloc.getTime() > year.end.getTime())
			break;

		console.log({
			body: BodyName(b),
			time: dloc,
			kind: (jloc.loc) ? 'local' : 'global',
			desc: eclipseDesc(jloc.flag)
		});
		
		dloc.setTime(dloc.getTime() + msPerDay);
	} while(true);
});

console.log('--- occultations:');
[
	swisseph.SE_MERCURY,      
	swisseph.SE_VENUS,      
	swisseph.SE_MARS,      
	swisseph.SE_JUPITER,      
	swisseph.SE_SATURN,      
	swisseph.SE_URANUS,      
	swisseph.SE_NEPTUNE,      
	swisseph.SE_PLUTO
].forEach(function(b) {
	var dloc = new Date(year.start);
	var jloc;
	do {
		jloc = MoonOccultWhenGlob(JulianDate(dloc), b, '');
		dloc = new Date(LocalDate(jloc.et));
		if(dloc.getTime() > year.end.getTime())
			break;

		console.log({
			body: BodyName(b),
			time: dloc,
			kind: (jloc.loc) ? 'local' : 'global',
			desc: eclipseDesc(jloc.flag)
		});
		
		dloc.setTime(dloc.getTime() + msPerDay);
	} while(true);
});
