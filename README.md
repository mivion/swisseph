Swiss Ephemeris binding for node.js [![Build Status](https://travis-ci.org/mivion/swisseph.svg?branch=master)](https://travis-ci.org/mivion/swisseph)
===================================

## About

Swiss Ephemeris binding for node.js.

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

See [Programming interface](http://www.astro.com/swisseph/swephprg.htm) to the Swiss Ephemeris for more details.

This javascript programming interface is little different from the original api, basically for return values.
For more details see src/*.h.

## Feedback

Please feel free to fill [issues](http://github.com/mivion/swisseph/issues) for bugs, erros and features.

## License

The license for this project is the same as original [Swiss Ephemeris](http://www.astro.com/swisseph/swephinfo_e.htm).

[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/mivion/swisseph/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

