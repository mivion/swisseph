$app.AppInAttribute = 'data-in';
$app.AppOutAttribute = 'data-out';
$app.AppVarAttribute = 'data-var';
$app.AppInOutAttribute = 'data-inout';

$app.update = function (event) {
	$app.varElements = $app.findNodesByAttr (document, $app.AppVarAttribute);

	$app.getVar ();

	if (event) {
		try {
			eval (event.target.getAttribute ($app.AppVarAttribute) + '.changed = true');
		} catch (exception) {
		}
	} else {
		$app.date.gregorian.terrestrial.changed = true;
	}

	now.ready (function () {
		now.swisseph.calc ({
			date: $app.date,
			observer: $app.observer,
			body: $app.body
		}, function (result) {
			$copy ($app, result);

			$app.setVar ();
		});
	});
};

$app.getVar = function () {
	for (var i = 0; i < $app.varElements.length; i ++) {
		var element = $app.varElements [i];
		var varName = element.getAttribute ($app.AppVarAttribute);
		try {
			$make (varName);
			if (
				element.tagName == 'INPUT' || element.tagName == 'SELECT'
			) {
				eval ('' + varName + '.value = ' + varName + '.string = "' + element.value + '"');
			}
		} catch (exception) {
		}
		element.setAttribute ('onchange', '$app.update (event)');
	}

	$app.date.gregorian.terrestrial.value = $app.parseDate ($app.date.gregorian.terrestrial.string);
	$app.date.gregorian.universal.value = $app.parseDate ($app.date.gregorian.universal.string);
	$app.date.gregorian.delta.value = parseFloat ($app.date.gregorian.delta.string);

	$app.date.julian.terrestrial.value = parseFloat ($app.date.julian.terrestrial.string);
	$app.date.julian.universal.value = parseFloat ($app.date.julian.universal.string);
	$app.date.julian.delta.value = parseFloat ($app.date.julian.delta.string);

	$app.observer.geographic.longitude.value = parseFloat ($app.observer.geographic.longitude.string);
	$app.observer.geographic.latitude.value = parseFloat ($app.observer.geographic.latitude.string);
	$app.observer.geographic.height.value = parseFloat ($app.observer.geographic.height.string);
};

$app.setVar = function () {
	$app.date.gregorian.terrestrial.changed = false;
	$app.date.gregorian.universal.changed = false;
	$app.date.julian.terrestrial.changed = false;
	$app.date.julian.universal.changed = false;

	$app.date.gregorian.terrestrial.string = $app.formatDate ($app.date.gregorian.terrestrial.value);
	$app.date.gregorian.universal.string = $app.formatDate ($app.date.gregorian.universal.value);
	$app.date.gregorian.delta.value = $app.date.julian.delta.value * 86400;

	$app.date.julian.terrestrial.string = $app.date.julian.terrestrial.value;
	$app.date.julian.universal.string = $app.date.julian.universal.value;

	$app.body.position.longitude.degreeMinuteSecond.string = $app.formatDegreeMinuteSecond ($app.body.position.longitude.decimalDegree.value);
	$app.body.position.latitude.degreeMinuteSecond.string = $app.formatDegreeMinuteSecond ($app.body.position.latitude.decimalDegree.value);

	for (var i = 0; i < $app.varElements.length; i ++) {
		var element = $app.varElements [i];
		try {
			if (
				element.tagName == 'INPUT' || element.tagName == 'SELECT'
			) {
				element.value = eval ('(' + element.getAttribute ($app.AppVarAttribute) + '.string || ' + element.getAttribute ($app.AppVarAttribute) + '.value)');
			} else {
				element.innerText = eval ('(' + element.getAttribute ($app.AppVarAttribute) + '.string || ' + element.getAttribute ($app.AppVarAttribute) + '.value)');
			}
		} catch (exception) {
		}
	}
};

$app.getIn = function () {
	for (var i = 0; i < $app.inElements.length; i ++) {
		var element = $app.inElements [i];
		var inAttribute = element.getAttribute ($app.AppInAttribute);
		try {
			$make (inAttribute);
			eval ('' + inAttribute + ' = "' + element.value + '"');
		} catch (exception) {
		}
		element.setAttribute ('onchange', '$app.update (event)');
	}

	$app.date = $app.parseDate ($app.date);
	if ($app.date.universal.string) {
		$copy ($app.date.universal, $app.parseDate ($app.date.universal.string));
	}
	$app.observer.geographic.longitude = parseFloat ($app.observer.geographic.longitude);
	$app.observer.geographic.latitude = parseFloat ($app.observer.geographic.latitude);
	$app.observer.geographic.height = parseFloat ($app.observer.geographic.height);
};

$app.setOut = function () {
	for (var i = 0; i < $app.outElements.length; i ++) {
		var element = $app.outElements [i];
		try {
			if (
				element.tagName == 'INPUT' ||
				element.tagName == 'SELECT'
			) {
				element.value = eval ('(' + element.getAttribute ($app.AppOutAttribute) + ')');
			} else {
				element.innerText = eval ('(' + element.getAttribute ($app.AppOutAttribute) + ')');
			}
		} catch (exception) {
		}
	}
};