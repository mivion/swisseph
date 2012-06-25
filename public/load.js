$app.AppInAttribute = 'data-in';
$app.AppOutAttribute = 'data-out';
$app.AppInSelector = '//*[@' + $app.AppInAttribute + ']';
$app.AppOutSelector = '//*[@' + $app.AppOutAttribute + ']';

$app.load = function () {
	$app.inElements = $app.findNodesByAttr (document, $app.AppInAttribute);
	$app.outElements = $app.findNodesByAttr (document, $app.AppOutAttribute);

	$app.getIn ();

	now.ready (function () {
		now.swisseph.calc ({
			date: $app.date,
			body: $app.body,
			observer: $app.observer
		}, function (result) {
			$copy ($app, result);

			$app.date.universal.string = $app.timeToString ($app.date.universal);
			$app.degreeMinuteSecond ($app.body.position.longitude);
			$app.degreeMinuteSecond ($app.body.position.latitude);

			$app.setOut ();
		});
	});
};

$app.lock = function () {

};

$app.getIn = function () {
	for (var i = 0; i < $app.inElements.length; i ++) {
		var inAttribute = $app.inElements [i].getAttribute ($app.AppInAttribute);
		try {
			$make (inAttribute);
			eval ('' + inAttribute + ' = "' + $app.inElements [i].value + '"');
		} catch (exception) {
		}
	}

	$app.date = $app.parseDate ($app.date);
	$app.observer.geographic.longitude = parseFloat ($app.observer.geographic.longitude);
	$app.observer.geographic.latitude = parseFloat ($app.observer.geographic.latitude);
	$app.observer.geographic.height = parseFloat ($app.observer.geographic.height);
};

$app.setOut = function () {
	for (var i = 0; i < $app.outElements.length; i ++) {
		try {
			$app.outElements [i].value = eval ('(' + $app.outElements [i].getAttribute ($app.AppOutAttribute) + ')');
		} catch (exception) {
		}
	}
};