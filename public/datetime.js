$app.formatHour = function (hour) {
	var result;
	var hours;
	var minutes;
	var seconds;

	hours = Math.floor (hour);
	hour -= hours;
	hour *= 60;
	minutes = Math.floor (hour);
	hour -= minutes;
	hour *= 60;
	seconds = hour;

	result =
		$app.twoDigitsString (hours) + ':' +
		$app.twoDigitsString (minutes) + ':' +
		$app.twoDigitsString (seconds)
	;

	return result;
};

$app.formatDate = function (date) {
	var result;

	result =
		$app.twoDigitsString (date.day) + '.' +
		$app.twoDigitsString (date.month) + '.' +
		date.year + ' ' +
		$app.formatHour (date.hour)
	;

	return result;
};

$app.twoDigitsString = function (value) {
	return value < 10 ? '0' + value : value;
};

$app.formatDegreeMinuteSecond = function (value) {
	var deg = Math.abs (value);
	var min = (60.0 * (deg - Math.floor (deg)));
	var sec = 60.0 * (min - Math.floor (min));
	var result = '';
	deg = Math.floor (deg);
	min = Math.floor (min);
	result += deg + '° ';
	result += min + '\' ';
	result += sec + '"';
	return result;
};

$app.parseDate = function (date) {
	var tokens = date.split (' ');

	if (tokens.length > 1) {
		tokens [0] = tokens [0].split ('.');
		tokens [1] = tokens [1].split (':');

		date = {
			day: parseFloat (tokens [0][0]),
			month: parseFloat (tokens [0][1]),
			year: parseFloat (tokens [0][2]),
			hour: parseFloat (tokens [1][0]) + (parseFloat (tokens [1][2]) / 60 + parseFloat (tokens [1][1])) / 60
		};
	}

	return date;
};