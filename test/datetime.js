var assert = require ('assert');
var swisseph = require ('..');

var version = swisseph.swe_version ();

console.log ('Swiss Ephemeris version:', version);

// Test date
var testdate = new Date(); // !!! javascript Date 
console.log ('Test date:', testdate, testdate.getMilliseconds(), 'ms');

var flag = swisseph.SEFLG_SPEED | swisseph.SEFLG_MOSEPH;

// Time zone
var t, et, ut;
with (testdate)
swisseph.swe_utc_time_zone (
    getFullYear(), 
    getMonth() + 1, 
    getDate(), 
    getHours(), 
    getMinutes(), 
    getSeconds() + getMilliseconds() / 1000, 
    5.5, 
    function (result) {t = result;}
    );

// Julian UT and ET date
with (t)
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
        et = result.julianDayET;
        ut = result.julianDayUT;
    });
console.log('ET =', et);
console.log('UT =', ut);

// Reverse date conversion from ET
swisseph.swe_jdet_to_utc (
    et, 
    swisseph.SE_GREG_CAL, 
    function (result) {t = result;}
    );
console.log('Julian ET -> UTC date:', t);

with (t)
swisseph.swe_utc_time_zone (
    year, 
    month, 
    day, 
    hour, 
    minute, 
    second, 
    -5.5, 
    function (result) {t = result;}
    );

var intS = Math.round(t.second);
if(intS > t.second)
    intS = intS - 1;

var mS = Math.round(1000 * (t.second - intS));

with (t)
var d = new Date(year, month - 1, day, hour, minute, intS, mS);

console.log('ET to Test date:', d, d.getMilliseconds(), 'ms');
assert.equal(d.getTime(), testdate.getTime());

// Reverse date conversion from UT
swisseph.swe_jdut1_to_utc (
    ut, 
    swisseph.SE_GREG_CAL, 
    function (result) {t = result;}
    );
console.log('Julian UT -> UTC date:', t);

with (t)
swisseph.swe_utc_time_zone (
    year, 
    month, 
    day, 
    hour, 
    minute, 
    second, 
    -5.5, 
    function (result) {t = result;}
    );

var intS = Math.round(t.second);
if(intS > t.second)
    intS = intS - 1;

var mS = Math.round(1000 * (t.second - intS));

with (t)
var d = new Date(year, month - 1, day, hour, minute, intS, mS);

console.log('UT to Test date:', d, d.getMilliseconds(), 'ms');
assert.equal(d.getTime(), testdate.getTime());

console.log('This test was successfully completed');