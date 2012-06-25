$app.copy = function (target /*, source ... */) {
	if (target) {
		for (var i = arguments.length - 1; i > 0; i --) {
			var source = arguments [i];
			if (source && source.hasOwnProperty) {
				for (var key in source) {
					if (source.hasOwnProperty (key)) {
						if ($app.is (target [key], Object) && $app.is (source [key], Object)) {
							$app.copy (target [key], source [key]);
						} else {
							target [key] = source [key];
						}
					}
				}
			}
		}
	}
    return target;
};

$app.is = function (object, type) {
	var typeName = Object.prototype.toString.call (object).slice (8, -1);
	return (
		object !== undefined &&
		object !== null &&
		type.name === typeName
	);
};

$app.make = function (context, path) {
	if ($is (context, String)) {
		path = context;
		context = window;
	}

	if (path) {
		var paths = path.split ('.');
		var key = paths.shift ();
		context [key] = context [key] || {};
		context = $make (context [key], paths.join ('.'));
	}
	return context;
};

$app.define = function (context, path, object) {
	$copy ($make (context, path), object);
};

$app.xpath = function (xpath, context) {
	var xpathSelector;
	var element;
	var result = [];

	context = context || document;

	if (document.evaluate) {
		xpathSelector = document.evaluate (xpath, context, null, XPathResult.ANY_TYPE, null);
	} else {
		xpathSelector = document.selectNodes (xpath);
	}

	for (element = xpathSelector.iterateNext (); element; element = xpathSelector.iterateNext ()) {
		result.push (element);
	}

	return result;
};

$app.assert = function (variable, value) {
	if (variable != value) {
		throw 'Assertion failed: ' + variable + ' != ' + value + '!';
	}
};