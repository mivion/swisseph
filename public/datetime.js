$app.parseHour = function (date) {
	date.hours = date.hour;

	if (Math.floor (date.hours) != date.hours) {
		var current = date.hours;
		date.hours = Math.floor (current);
		current -= date.hours;
		current *= 60;
		date.minutes = Math.floor (current);
		current -= date.minutes;
		current *= 60;
		date.seconds = Math.floor (current);
		current -= date.seconds;
		current *= 1000;
		date.milliseconds = current;
	}
};

$app.formatDate = function (date) {
	var result;

	$app.parseHour (date);

	result =
		$app.twoDigitsString (date.day) + '.' +
		$app.twoDigitsString (date.month) + '.' +
		date.year + ' ' +
		$app.twoDigitsString (date.hours) + ':' +
		$app.twoDigitsString (date.minutes) + ':' +
		$app.twoDigitsString (date.seconds + (date.milliseconds ? date.milliseconds : 0) / 1000)
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
			hour: parseFloat (tokens [1][0]) + (parseFloat (tokens [1][2]) / 60 + parseFloat (tokens [1][1])) / 60,
			hours: parseFloat (tokens [1][0]),
			minutes: parseFloat (tokens [1][1]),
			seconds: parseFloat (tokens [1][2])
		};
	}

	return date;
};