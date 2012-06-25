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
		object !== null && (
			type === object.constructor ||
			type.name === typeName
		)
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

$app.findNodesByAttr = function (node, attrName, result) {
	result = result || [];

	for (var i = 0; i < node.childNodes.length; i ++) {
		if (node.childNodes [i].getAttribute && node.childNodes [i].getAttribute (attrName)) {
			result.push (node.childNodes [i]);
		} else if (node.childNodes [i].childNodes) {
			$app.findNodesByAttr (node.childNodes [i], attrName, result);
		}
	}

	return result;
};

$app.assert = function (variable, value) {
	if (variable != value) {
		throw 'Assertion failed: ' + variable + ' != ' + value + '!';
	}
};