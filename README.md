Swiss Ephemeris binding for node.js [![Build Status](https://travis-ci.org/mivion/swisseph.svg?branch=master)](https://travis-ci.org/mivion/swisseph)
===================================

**NOTE: Need help to mantain this project. Please write me.**

## About

Swiss Ephemeris binding for node.js.

See [Swiss Ephemeris](http://www.astro.com/swisseph/swephinfo_e.htm) for more details.

Supported platforms: **Mac OS X** | **Windows** | **Linux** | **FreeBSD**

## Getting started

To install run:

```
$ npm install swisseph
```

## Requirements

From version 0.5.x only nodejs 0.12 or newer supported.

To use with older nodejs version use swisseph 0.4.x or older.

## Version 0.5.x Notes

From version 0.5.x only nodejs 0.12 supported, because of C addons API compatibility.

Also, project splited to [swisseph](https://github.com/mivion/swisseph) and [swisseph-api](https://github.com/mivion/swisseph-api).

[swisseph](https://github.com/mivion/swisseph) responsible only for nodejs binding, but [swisseph-api](https://github.com/mivion/swisseph-api)
to access over the web.

## Usage

### Getting julian day

```javascript
var swisseph = require ('swisseph');

var date = {year: 2015, month: 1, day: 1, hour: 0};

var julday = swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL);

```

### Getting Sun and Moon position

Example:

```javascript
var swisseph = require ('swisseph');

// Test date
var date = {year: 2012, month: 1, day: 1, hour: 0};
console.log ('Test date:', date);

var flag = swisseph.SEFLG_SPEED;

// path to ephemeris data
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

For more examples see *examples* and *test* folders.

### Using ecliptic, equatorial or rectangular coordinates

On computing planet, star, node or apside positions, and [using SEFLG_EQUATORIAL or SEFLG_XYZ in flag bits](http://www.astro.com/swisseph/swephprg.htm#_Toc433200761), name of the resulting property will be different from the case with ecliptic coordinates. Run *examples/issue-23.js* in details, please.

### Ephemeris settings

There are 3 different types of ephemeris supported:

- *Steve Moshier* interpolation, covers 3000 BC – 3000 AD, preision 0.1 arcsec, no data files required.
- *Swiss Ephemeris* is compressed version of DE431, covers 13000 BC - 17000 AD, precision 0.001 arcseconds, requires data files about 90MB. Download from [ftp://www.astro.com/pub/swisseph/ephe](ftp://www.astro.com/pub/swisseph/ephe).
- JPL NASA ephemeris is the state of the art ephemeris, DE431 covers 13000 BC - 17000 AD, maximum possible precision, requires data files 2.9GB. Download from [ftp://www.astro.com/pub/jplfiles](ftp://www.astro.com/pub/jplfiles).

To use data files download them and put in folder then set path to the ephemeris folder by:

```javascript
swisseph.swe_set_ephe_path ('/path/to/downloaded/ephemeris');
```

And select ephemeris by setting the flag:

```javascript

// for Moshier
body = swisseph.swe_calc_ut (julday_ut, swisseph.SE_SUN, swisseph.SEFLG_SPEED | swisseph.SEFLG_MOSEPH)

// for Swiss Ephemeris
body = swisseph.swe_calc_ut (julday_ut, swisseph.SE_SUN, swisseph.SEFLG_SPEED | swisseph.SEFLG_SWIEPH)

// for JPL NASA ephemeris
body = swisseph.swe_calc_ut (julday_ut, swisseph.SE_SUN, swisseph.SEFLG_SPEED | swisseph.SEFLG_JPLEPH)

```

## Tests

To execute tests run from the root folder:

> npm test

## Documentation

See [Programming interface](http://www.astro.com/swisseph/swephprg.htm) to the Swiss Ephemeris for more details.

This javascript programming interface is little different from the original api, basically for return values.
For more details see src/*.h.

## Feedback

Please feel free to fill [issues](http://github.com/mivion/swisseph/issues) for bugs, erros and features.

## License

The license for this project is the same as original [Swiss Ephemeris](http://www.astro.com/swisseph/swephinfo_e.htm).
