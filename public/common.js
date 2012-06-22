$ns.copy = function (target /*, source ... */) {
	if (target) {
		for (var i = arguments.length - 1; i > 0; i --) {
			var source = arguments [i];
			if (source && source.hasOwnProperty) {
				for (var key in source) {
					if (source.hasOwnProperty (key)) {
						target [key] = source [key];
					}
				}
			}
		}
	}
    return target;
};

$ns.is = function (object, type) {
	var typeName = Object.prototype.toString.call (object).slice (8, -1);
	return (
		object !== undefined &&
		object !== null &&
		type.name === typeName
	);
};

$ns.make = function (context, path) {
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

$ns.define = function (context, path, object) {
	$copy ($make (context, path), object);
};

$ns.assert = function (variable, value) {
	if (variable != value) {
		throw 'Assertion failed: ' + variable + ' != ' + value + '!';
	}
};