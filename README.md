Swiss Ephemeris binding for node.js
===================================

## About

Swiss Ephemeris binding for node.js under GNU GPL 2.0.

See [Swiss Ephemeris](http://www.astro.com/swisseph/swephinfo_e.htm) for more details.

Supported platforms: **Mac OS X** | **Windows** | **Linux**

## Getting started

To install run:

```
$ npm install swisseph
```

## Usage

Example:

```javascript
var swisseph = require ('swisseph');

// Date for test
var date = {year: 2012, month: 1, day: 1, hour: 0};
console.log ('Test date: ', date);

// UT Julian day
var julday_ut = swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL);
console.log ('Julian UT day for date: ', julday_ut);

// Sun positon
var sun = swisseph.swe_calc_ut (
	julday_ut,
	swisseph.SE_SUN,
	swisseph.SEFLG_SPEED |
	swisseph.SEFLG_MOSEPH
);
console.log ('Sun position for date: ', sun);
```

## Status

Under construction.

Implemented:
 - swe_julday ()
 - swe_calc_ut ()
 - swe_calc ()
 - swe_fixstar ()
 - swe_set_ephe_path ()

## License

This software licensed under GNU GPL 2.0 license.

See http://www.gnu.org/licenses/old-licenses/gpl-2.0.html for more details.
