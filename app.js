var express = require ('express');

var app = module.exports = express.createServer ();

app.configure (function (){
  app.set ('views', __dirname + '/views');
  app.set ('view engine', 'jade');
  app.use (express.bodyParser ());
  app.use (express.methodOverride ());
  app.use (app.router);
  app.use (express.static (__dirname + '/public'));
});

app.configure ('development', function (){
  app.use (express.errorHandler ({ dumpExceptions: true, showStack: true }));
});

app.configure ('production', function (){
  app.use (express.errorHandler ());
});

app.get ('/', function (req, res) {
    res.redirect ('/index.html');
});

app.listen (process.env.SWISSEPH_PORT || 3000, function (){
  console.log ("Swisseph server listening on port %d in %s mode", app.address ().port, app.settings.env);
});

var nowjs = require ("now");
var everyone = nowjs.initialize (
	app,
	{
		host: process.env.SWISSEPH_PUBLIC_HOST || 'localhost',
		port: process.env.SWISSEPH_PUBLIC_PORT || 3000,
		socketio: {
			transports: ['xhr-polling'],
			'browser client minification': true,
        	'browser client gzip': true
		}
	}
);

var swisseph = require ('./');

swisseph.swe_set_ephe_path (process.env.SWISSEPH_EPHEMERIS_PATH || (__dirname + '/ephe'));
everyone.now.swisseph = swisseph;
