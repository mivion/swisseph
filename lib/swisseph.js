var swisseph = require (__dirname + '/../build/Release/swisseph.node');
var merge = require ('merge');


swisseph.SE_AUNIT_TO_KM = (149597870.700);
swisseph.SE_AUNIT_TO_LIGHTYEAR = (1.0/63241.07708427);
swisseph.SE_AUNIT_TO_PARSEC = (1.0/206264.8062471);

// Calendar types
swisseph.SE_JUL_CAL = 0;
swisseph.SE_GREG_CAL = 1;

// Planet numbers
swisseph.SE_ECL_NUT = -1;

swisseph.SE_SUN = 0;

// Base planets
swisseph.SE_MOON = 1;
swisseph.SE_MERCURY = 2;
swisseph.SE_VENUS = 3;
swisseph.SE_EARTH = 14;
swisseph.SE_MARS = 4;
swisseph.SE_JUPITER = 5;
swisseph.SE_SATURN = 6;
swisseph.SE_URANUS = 7;
swisseph.SE_NEPTUNE = 8;
swisseph.SE_PLUTO = 9;

// Moon nodes
swisseph.SE_MEAN_NODE = 10;
swisseph.SE_TRUE_NODE = 11;
swisseph.SE_MEAN_APOG = 12;
swisseph.SE_OSCU_APOG = 13;
swisseph.SE_INTP_APOG = 21;
swisseph.SE_INTP_PERG = 22;

// Base asteroids
swisseph.SE_CHIRON = 15;
swisseph.SE_PHOLUS = 16;
swisseph.SE_CERES = 17;
swisseph.SE_PALLAS = 18;
swisseph.SE_JUNO = 19;
swisseph.SE_VESTA = 20;

swisseph.SE_NPLANETS = 23;

swisseph.SE_AST_OFFSET = 10000;
swisseph.SE_VARUNA = (swisseph.SE_AST_OFFSET + 20000);

swisseph.SE_FICT_OFFSET = 40;
swisseph.SE_FICT_OFFSET_1 = 39;
swisseph.SE_FICT_MAX = 999;
swisseph.SE_NFICT_ELEM = 15;

swisseph.SE_COMET_OFFSET = 1000;

swisseph.SE_NALL_NAT_POINTS = (swisseph.SE_NPLANETS + swisseph.SE_NFICT_ELEM);

// Hamburger or Uranian "planets"
swisseph.SE_CUPIDO = 40;
swisseph.SE_HADES = 41;
swisseph.SE_ZEUS = 42;
swisseph.SE_KRONOS = 43;
swisseph.SE_APOLLON = 44;
swisseph.SE_ADMETOS = 45;
swisseph.SE_VULKANUS = 46;
swisseph.SE_POSEIDON = 47;

// Other fictitious bodies
swisseph.SE_ISIS = 48;
swisseph.SE_NIBIRU = 49;
swisseph.SE_HARRINGTON = 50;
swisseph.SE_NEPTUNE_LEVERRIER = 51;
swisseph.SE_NEPTUNE_ADAMS = 52;
swisseph.SE_PLUTO_LOWELL = 53;
swisseph.SE_PLUTO_PICKERING = 54;
swisseph.SE_VULCAN = 55;
swisseph.SE_WHITE_MOON = 56;
swisseph.SE_PROSERPINA = 57;
swisseph.SE_WALDEMATH = 58;

swisseph.SE_FIXSTAR = -10;

swisseph.SE_ASC = 0;
swisseph.SE_MC = 1;
swisseph.SE_ARMC = 2;
swisseph.SE_VERTEX = 3;
swisseph.SE_EQUASC = 4; // "equatorial ascendant"
swisseph.SE_COASC1 = 5;	// "co-ascendant" (W. Koch)
swisseph.SE_COASC2 = 6;	// "co-ascendant" (M. Munkasey)
swisseph.SE_POLASC = 7;	// "polar ascendant" (M. Munkasey)
swisseph.SE_NASCMC = 8;

/**
 * flag bits for parameter iflag in function swe_calc ()
 * The flag bits are defined in such a way that iflag = 0 delivers what one
 * usually wants:
 *  - the default ephemeris (SWISS EPHEMERIS) is used,
 *  - apparent geocentric positions referring to the true equinox of date
 *    are returned.
 * If not only coordinates, but also speed values are required, use 
 * flag = SEFLG_SPEED.
 *
 * The 'L' behind the number indicates that 32-bit integers (Long) are used.
 */
swisseph.SEFLG_JPLEPH = 1; // use JPL ephemeris
swisseph.SEFLG_SWIEPH = 2; // use SWISSEPH ephemeris
swisseph.SEFLG_MOSEPH = 4; // use Moshier ephemeris

swisseph.SEFLG_HELCTR = 8; // return heliocentric position
swisseph.SEFLG_TRUEPOS = 16; // return true positions, not apparent
swisseph.SEFLG_J2000 = 32; // no precession, i.e. give J2000 equinox
swisseph.SEFLG_NONUT = 64; // no nutation, i.e. mean equinox of date
swisseph.SEFLG_SPEED3 = 128; // speed from 3 positions (do not use it, SEFLG_SPEED is faster and more precise.)
swisseph.SEFLG_SPEED = 256; // high precision speed
swisseph.SEFLG_NOGDEFL = 512; // turn off gravitational deflection
swisseph.SEFLG_NOABERR = 1024; // turn off 'annual' aberration of light
swisseph.SEFLG_ASTROMETRIC = (swisseph.SEFLG_NOABERR | swisseph.SEFLG_NOGDEFL); // astrometric position, i.e. with light-time, but without aberration and light deflection
swisseph.SEFLG_EQUATORIAL = (2  *1024); // equatorial positions are wanted
swisseph.SEFLG_XYZ = (4 * 1024); // cartesian, not polar, coordinates
swisseph.SEFLG_RADIANS = (8 * 1024); // coordinates in radians, not degrees
swisseph.SEFLG_BARYCTR = (16 * 1024); // barycentric positions
swisseph.SEFLG_TOPOCTR = (32 * 1024); // topocentric positions
swisseph.SEFLG_ORBEL_AA = swisseph.SEFLG_TOPOCTR; // used for Astronomical Almanac mode in calculation of Kepler elipses
swisseph.SEFLG_SIDEREAL = (64 * 1024); // sidereal positions
swisseph.SEFLG_ICRS = (128 * 1024); // ICRS (DE406 reference frame)
swisseph.SEFLG_DPSIDEPS_1980 = (256*1024); // reproduce JPL Horizons 1962 - today to 0.002 arcsec.
swisseph.SEFLG_JPLHOR = swisseph.SEFLG_DPSIDEPS_1980;
swisseph.SEFLG_JPLHOR_APPROX = (512*1024); // approximate JPL Horizons 1962 - today


swisseph.SE_SIDBITS = 256;
swisseph.SE_SIDBIT_ECL_T0 = 256; // for projection onto ecliptic of t0
swisseph.SE_SIDBIT_SSY_PLANE = 512; // for projection onto solar system plane
swisseph.SE_SIDBIT_USER_UT = 1024; // with user-defined ayanamsha, t0 is UT

// Sidereal modes (ayanamsas)
swisseph.SE_SIDM_FAGAN_BRADLEY = 0;
swisseph.SE_SIDM_LAHIRI = 1;
swisseph.SE_SIDM_DELUCE = 2;
swisseph.SE_SIDM_RAMAN = 3;
swisseph.SE_SIDM_USHASHASHI = 4;
swisseph.SE_SIDM_KRISHNAMURTI = 5;
swisseph.SE_SIDM_DJWHAL_KHUL = 6;
swisseph.SE_SIDM_YUKTESHWAR = 7;
swisseph.SE_SIDM_JN_BHASIN = 8;
swisseph.SE_SIDM_BABYL_KUGLER1 = 9;
swisseph.SE_SIDM_BABYL_KUGLER2 = 10;
swisseph.SE_SIDM_BABYL_KUGLER3 = 11;
swisseph.SE_SIDM_BABYL_HUBER = 12;
swisseph.SE_SIDM_BABYL_ETPSC = 13;
swisseph.SE_SIDM_ALDEBARAN_15TAU = 14;
swisseph.SE_SIDM_HIPPARCHOS = 15;
swisseph.SE_SIDM_SASSANIAN = 16;
swisseph.SE_SIDM_GALCENT_0SAG = 17;
swisseph.SE_SIDM_J2000 = 18;
swisseph.SE_SIDM_J1900 = 19;
swisseph.SE_SIDM_B1950 = 20;
swisseph.SE_SIDM_SURYASIDDHANTA = 21;
swisseph.SE_SIDM_SURYASIDDHANTA_MSUN = 22;
swisseph.SE_SIDM_ARYABHATA = 23;
swisseph.SE_SIDM_ARYABHATA_MSUN = 24;
swisseph.SE_SIDM_SS_REVATI = 25;
swisseph.SE_SIDM_SS_CITRA = 26;
swisseph.SE_SIDM_TRUE_CITRA = 27;
swisseph.SE_SIDM_TRUE_REVATI = 28;
swisseph.SE_SIDM_TRUE_PUSHYA = 29;
swisseph.SE_SIDM_GALCENT_RGILBRAND = 30;
swisseph.SE_SIDM_GALEQU_IAU1958 = 31;
swisseph.SE_SIDM_GALEQU_TRUE = 32;
swisseph.SE_SIDM_GALEQU_MULA = 33;
swisseph.SE_SIDM_GALALIGN_MARDYKS = 34;
swisseph.SE_SIDM_TRUE_MULA = 35;
swisseph.SE_SIDM_GALCENT_MULA_WILHELM = 36;
swisseph.SE_SIDM_ARYABHATA_522 = 37;
swisseph.SE_SIDM_BABYL_BRITTON = 38;
swisseph.SE_SIDM_TRUE_SHEORAN = 39;
swisseph.SE_SIDM_GALCENT_COCHRANE = 40;
swisseph.SE_SIDM_GALEQU_FIORENZA = 41;
swisseph.SE_SIDM_VALENS_MOON = 42;

swisseph.SE_SIDM_USER = 255;
swisseph.SE_NSIDM_PREDEF = 43;

// used for swe_nod_aps ()
swisseph.SE_NODBIT_MEAN = 1; // mean nodes/apsides
swisseph.SE_NODBIT_OSCU = 2; // osculating nodes/apsides
swisseph.SE_NODBIT_OSCU_BAR = 4; // same, but motion about solar system barycenter is considered
swisseph.SE_NODBIT_FOPOINT = 256; // focal point of orbit instead of aphelion

// default ephemeris used when no ephemeris flagbit is set
swisseph.SEFLG_DEFAULTEPH = swisseph.SEFLG_SWIEPH;

// Maximum size of fixstar name.
// The parameter star in swe_fixstar () must allow twice this space for
// the returned star name.
swisseph.SE_MAX_STNAME = 256;

// defines for eclipse computations
swisseph.SE_ECL_CENTRAL = 1;
swisseph.SE_ECL_NONCENTRAL = 2;
swisseph.SE_ECL_TOTAL = 4;
swisseph.SE_ECL_ANNULAR = 8;
swisseph.SE_ECL_PARTIAL = 16;
swisseph.SE_ECL_ANNULAR_TOTAL = 32;
swisseph.SE_ECL_PENUMBRAL = 64;
swisseph.SE_ECL_ALLTYPES_SOLAR = (
	swisseph.SE_ECL_CENTRAL |
	swisseph.SE_ECL_NONCENTRAL |
	swisseph.SE_ECL_TOTAL |
	swisseph.SE_ECL_ANNULAR |
	swisseph.SE_ECL_PARTIAL |
	swisseph.SE_ECL_ANNULAR_TOTAL
);
swisseph.SE_ECL_ALLTYPES_LUNAR = (
	swisseph.SE_ECL_TOTAL |
	swisseph.SE_ECL_PARTIAL |
	swisseph.SE_ECL_PENUMBRAL
);
swisseph.SE_ECL_VISIBLE = 128;
swisseph.SE_ECL_MAX_VISIBLE = 256;
swisseph.SE_ECL_1ST_VISIBLE = 512; // begin of partial eclipse
swisseph.SE_ECL_PARTBEG_VISIBLE = 512;	// begin of partial eclipse
swisseph.SE_ECL_2ND_VISIBLE = 1024;	// begin of total eclipse
swisseph.SE_ECL_TOTBEG_VISIBLE = 1024; // begin of total eclipse
swisseph.SE_ECL_3RD_VISIBLE = 2048; // end of total eclipse
swisseph.SE_ECL_TOTEND_VISIBLE = 2048; // end of total eclipse
swisseph.SE_ECL_4TH_VISIBLE = 4096; // end of partial eclipse
swisseph.SE_ECL_PARTEND_VISIBLE = 4096; // end of partial eclipse
swisseph.SE_ECL_PENUMBBEG_VISIBLE = 8192; // begin of penumbral eclipse
swisseph.SE_ECL_PENUMBEND_VISIBLE = 16384; // end of penumbral eclipse
swisseph.SE_ECL_OCC_BEG_DAYLIGHT = 8192; // occultation begins during the day
swisseph.SE_ECL_OCC_END_DAYLIGHT = 16384; // occultation ends during the day
// check if the next conjunction of the moon with a planet is an occultation; don't search further
swisseph.SE_ECL_ONE_TRY = (32 * 1024);

// for swe_rise_transit()
swisseph.SE_CALC_RISE = 1;
swisseph.SE_CALC_SET = 2;
swisseph.SE_CALC_MTRANSIT = 4;
swisseph.SE_CALC_ITRANSIT = 8;
// to be or'ed to SE_CALC_RISE/SET, if rise or set of disc center is required
swisseph.SE_BIT_DISC_CENTER = 256; 
// to be or'ed to SE_CALC_RISE/SET, if rise or set of lower limb of disc is requried
swisseph.SE_BIT_DISC_BOTTOM = 8192;
// use geocentric rather than topocentric position of object and ignore its ecliptic latitude
swisseph.SE_BIT_GEOCTR_NO_ECL_LAT = 128;
// to be or'ed to SE_CALC_RISE/SET, if refraction is to be ignored
swisseph.SE_BIT_NO_REFRACTION = 512;
swisseph.SE_BIT_CIVIL_TWILIGHT = 1024; // to be or'ed to SE_CALC_RISE/SET
swisseph.SE_BIT_NAUTIC_TWILIGHT = 2048; // to be or'ed to SE_CALC_RISE/SET
swisseph.SE_BIT_ASTRO_TWILIGHT = 4096; // to be or'ed to SE_CALC_RISE/SET
// or'ed to SE_CALC_RISE/SET: neglect the effect of distance on disc size
swisseph.SE_BIT_FIXED_DISC_SIZE = (16 * 1024);

// for swe_azalt () and swe_azalt_rev ()
swisseph.SE_ECL2HOR = 0;
swisseph.SE_EQU2HOR = 1;
swisseph.SE_HOR2ECL = 0;
swisseph.SE_HOR2EQU = 1;

// for swe_refrac ()
swisseph.SE_TRUE_TO_APP = 0;
swisseph.SE_APP_TO_TRUE = 1;

// defines for function swe_split_deg () (in swephlib.c)
swisseph.SE_SPLIT_DEG_ROUND_SEC = 1;
swisseph.SE_SPLIT_DEG_ROUND_MIN = 2;
swisseph.SE_SPLIT_DEG_ROUND_DEG = 4;
swisseph.SE_SPLIT_DEG_ZODIACAL = 8;
swisseph.SE_SPLIT_DEG_NAKSHATRA = 1024;
// don't round to next sign, e.g. 29.9999999 will be rounded to 29d59'59" (or 29d59' or 29d)
swisseph.SE_SPLIT_DEG_KEEP_SIGN = 16;
// don't round to next degree e.g. 13.9999999 will be rounded to 13d59'59" (or 13d59' or 13d)
swisseph.SE_SPLIT_DEG_KEEP_DEG = 32;

// for heliacal functions
swisseph.SE_HELIACAL_RISING = 1;
swisseph.SE_HELIACAL_SETTING = 2;
swisseph.SE_MORNING_FIRST = swisseph.SE_HELIACAL_RISING;
swisseph.SE_EVENING_LAST = swisseph.SE_HELIACAL_SETTING;
swisseph.SE_EVENING_FIRST = 3;
swisseph.SE_MORNING_LAST = 4;
swisseph.SE_ACRONYCHAL_RISING = 5; // still not implemented
swisseph.SE_ACRONYCHAL_SETTING = 6; // still not implemented
swisseph.SE_COSMICAL_SETTING = swisseph.SE_ACRONYCHAL_SETTING;

swisseph.SE_HELFLAG_LONG_SEARCH = 128;
swisseph.SE_HELFLAG_HIGH_PRECISION = 256;
swisseph.SE_HELFLAG_OPTICAL_PARAMS = 512;
swisseph.SE_HELFLAG_NO_DETAILS = 1024;
swisseph.SE_HELFLAG_SEARCH_1_PERIOD = (1 << 11);
swisseph.SE_HELFLAG_VISLIM_DARK = (1 << 12);
swisseph.SE_HELFLAG_VISLIM_NOMOON = (1 << 13);
swisseph.SE_HELFLAG_VISLIM_PHOTOPIC = (1 << 14);
swisseph.SE_HELFLAG_AVKIND_VR = (1 << 15);
swisseph.SE_HELFLAG_AVKIND_PTO = (1 << 16);
swisseph.SE_HELFLAG_AVKIND_MIN7 = (1 << 17);
swisseph.SE_HELFLAG_AVKIND_MIN9 = (1 << 18);
swisseph.SE_HELFLAG_AVKIND = (
	swisseph.SE_HELFLAG_AVKIND_VR |
	swisseph.SE_HELFLAG_AVKIND_PTO |
	swisseph.SE_HELFLAG_AVKIND_MIN7 |
	swisseph.SE_HELFLAG_AVKIND_MIN9
);
swisseph.TJD_INVALID = 99999999.0;
swisseph.SIMULATE_VICTORVB = 1;

swisseph.SE_PHOTOPIC_FLAG = 0;
swisseph.SE_SCOTOPIC_FLAG = 1;
swisseph.SE_MIXEDOPIC_FLAG = 2;

swisseph.ephemeris = {
	'swisseph': swisseph.SEFLG_SWIEPH,
	'moshier': swisseph.SEFLG_MOSEPH,
	'de200': 'de200.eph',
	'de405': 'de405.eph',
	'de406': 'de406.eph',
	'de406e': 'de406e.eph',
	'de414': 'de414.eph',
	'de421': 'de421.eph',
	'de422': 'de422.eph',
	'de430': 'de430.eph',
	'de431': 'de431.eph'
};

swisseph.calc = function (options, callback) {
	var flags;

	flags = swisseph.SEFLG_SPEED;

	var date;

	options.date.gregorian = options.date.gregorian || {};
	options.date.julian = options.date.julian || {};

	if (options.date.gregorian.terrestrial) {
		date = options.date.gregorian.terrestrial;
		options.date.julian.terrestrial = swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL);
		options.date.julian.delta = swisseph.swe_deltat (options.date.julian.terrestrial).delta;
		options.date.julian.universal = options.date.julian.terrestrial - options.date.julian.delta;
		options.date.gregorian.universal = options.date.gregorian.universal || {};
		merge (options.date.gregorian.universal, swisseph.swe_revjul (options.date.julian.universal, swisseph.SE_GREG_CAL));
	} else if (options.date.gregorian.universal) {
		date = options.date.gregorian.universal;
		options.date.julian.universal = swisseph.swe_julday (date.year, date.month, date.day, date.hour, swisseph.SE_GREG_CAL);
		options.date.julian.delta = swisseph.swe_deltat (options.date.julian.universal).delta;
		options.date.julian.terrestrial = options.date.julian.universal + options.date.julian.delta;
		options.date.gregorian.terrestrial = options.date.gregorian.terrestrial || {};
		merge (options.date.gregorian.terrestrial, swisseph.swe_revjul (options.date.julian.terrestrial, swisseph.SE_GREG_CAL));
	} else if (options.date.julian.terrestrial) {
		options.date.julian.delta = swisseph.swe_deltat (options.date.julian.terrestrial).delta;
		options.date.julian.universal = options.date.julian.terrestrial - options.date.julian.delta;
		options.date.gregorian.universal = options.date.gregorian.universal || {};
		options.date.gregorian.terrestrial = options.date.gregorian.terrestrial || {};
		merge (options.date.gregorian.terrestrial, swisseph.swe_revjul (options.date.julian.terrestrial, swisseph.SE_GREG_CAL));
		merge (options.date.gregorian.universal, swisseph.swe_revjul (options.date.julian.universal, swisseph.SE_GREG_CAL));
	} else if (options.date.julian.universal) {
		options.date.julian.delta = swisseph.swe_deltat (options.date.julian.universal).delta;
		options.date.julian.terrestrial = options.date.julian.universal + options.date.julian.delta;
		options.date.gregorian.universal = options.date.gregorian.universal || {};
		options.date.gregorian.terrestrial = options.date.gregorian.terrestrial || {};
		merge (options.date.gregorian.terrestrial, swisseph.swe_revjul (options.date.julian.terrestrial, swisseph.SE_GREG_CAL));
		merge (options.date.gregorian.universal, swisseph.swe_revjul (options.date.julian.universal, swisseph.SE_GREG_CAL));
	}

	options.date.gregorian.delta = options.date.julian.delta * 86400;

	options.body.name = swisseph.swe_get_planet_name (parseInt (options.body.id)).name;

	options.observer.ephemeris = options.observer.ephemeris || 'moshier';

	if (swisseph.ephemeris [options.observer.ephemeris].length) {
		flags |= swisseph.SEFLG_JPLEPH;
		swisseph.swe_set_jpl_file (swisseph.ephemeris [options.observer.ephemeris]);
	} else {
		flags |= swisseph.ephemeris [options.observer.ephemeris];
	}

	if (
		options.observer.geographic.longitude != 0 ||
		options.observer.geographic.latitude != 0 ||
		options.observer.geographic.height != 0
	) {
		swisseph.swe_set_topo (
			options.observer.geographic.longitude,
			options.observer.geographic.latitude,
			options.observer.geographic.height
		);
		flags |= swisseph.SEFLG_TOPOCTR;
	}

	merge (options.body.position, swisseph.swe_calc_ut (options.date.julian.universal, parseInt (options.body.id), flags));
	options.body.position.longitude = {decimalDegree: options.body.position.longitude};
	options.body.position.latitude = {decimalDegree: options.body.position.latitude};

	swisseph.swe_close ();

	if (callback) {
		callback (options);
	};

	return options;
};

module.exports = swisseph;
