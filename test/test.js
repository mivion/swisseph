var assert = require ('assert');
var swisseph = require ('..');


{ // Julian day
	var date = {
		year: 2012,
		month: 1,
		day: 1,
		hour: 0,
	};

	var julday = swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL);

	assert.equal (julday, 2455927.5);

	console.log ('swisseph.swe_julday (' + date.year + ', ' + date.month + ', ' + date.day + ', ' + date.hour + ', SE_GREG_CAL) =', julday);
}
