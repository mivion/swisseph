Swiss Ephemeris binding for node.js
===================================

## About

Swiss Ephemeris binding for node.js under GNU GPL 2.0.

See [Swiss Ephemeris](http://www.astro.com/swisseph/swephinfo_e.htm) for more details.

Supported platforms: **Mac OS X** | **Windows** | **Linux** | **FreeBSD**

## Getting started

To install run:

```
$ npm install swisseph
```

## Usage

Example:

```javascript
var swisseph = require ('swisseph');

// Test date
var date = {year: 2012, month: 1, day: 1, hour: 0};
console.log ('Test date:', date);

var flag = swisseph.SEFLG_SPEED | swisseph.SEFLG_MOSEPH;

// don't work at test server
swisseph.swe_set_ephe_path (__dirname + '/../ephe');

// Julian day
swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL, function (julday_ut) {
	assert.equal (julday_ut, 2455927.5);
	console.log ('Julian UT day for date:', julday_ut);

	// Sun position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_SUN, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Sun position:', body);
	});

	// Moon position
	swisseph.swe_calc_ut (julday_ut, swisseph.SE_MOON, flag, function (body) {
		assert (!body.error, body.error);
		console.log ('Moon position:', body);
	});
});
```

## Status

Under construction.

Now implemented:
 - all flags
 - swe_julday
 - swe_version
 - swe_calc_ut
 - swe_calc
 - swe_fixstar
 - swe_fixstar_ut
 - swe_fixstar_mag
 - swe_close
 - swe_set_ephe_path
 - swe_set_jpl_file
 - swe_get_planet_name
 - swe_set_topo
 - swe_set_sid_mode
 - swe_get_ayanamsa
 - swe_get_ayanamsa_ut
 - swe_get_ayanamsa_name

## License

This software licensed under GNU GPL 2.0 license.

See http://www.gnu.org/licenses/old-licenses/gpl-2.0.html for more details.
