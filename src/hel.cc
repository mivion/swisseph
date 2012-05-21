#define BUILDING_NODE_EXTENSION

#include "swisseph.h"

using namespace v8;

/**
 * int32 swe_heliacal_ut(double tjdstart_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 iflag, double *dret, char *serr);
 * =>
 * swe_heliacal_ut(double tjdstart_ut, double *geopos, double *datm, double *dobs, string ObjectName, int32 TypeEvent, int32 iflag) {
 *   start: double,
 *   optimum: double,
 *   end: double,
 *   rflag: int32,
 *   error: string
 * }
 */
Handle <Value> node_swe_heliacal_ut (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 7) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsArray () ||
		!args [2]->IsArray () ||
		!args [3]->IsArray () ||
		!args [4]->IsString () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double dret [50] = {0};
	char serr [AS_MAXCH];
	char name [AS_MAXCH];
	long rflag;

	dgeo [0] = args [1]->ToObject ()->Get (0)->NumberValue ();
	dgeo [1] = args [1]->ToObject ()->Get (1)->NumberValue ();
	dgeo [2] = args [1]->ToObject ()->Get (2)->NumberValue ();

	datm [0] = args [2]->ToObject ()->Get (0)->NumberValue ();
	datm [1] = args [2]->ToObject ()->Get (1)->NumberValue ();
	datm [2] = args [2]->ToObject ()->Get (2)->NumberValue ();
	datm [3] = args [2]->ToObject ()->Get (3)->NumberValue ();

	dobs [0] = args [3]->ToObject ()->Get (0)->NumberValue ();
	dobs [1] = args [3]->ToObject ()->Get (1)->NumberValue ();
	dobs [2] = args [3]->ToObject ()->Get (2)->NumberValue ();
	dobs [3] = args [3]->ToObject ()->Get (3)->NumberValue ();
	dobs [4] = args [3]->ToObject ()->Get (4)->NumberValue ();
	dobs [5] = args [3]->ToObject ()->Get (5)->NumberValue ();

	::strcpy (name, *String::AsciiValue (args [4]->ToString ()));

	rflag = ::swe_heliacal_ut (
		args [0]->NumberValue (),
		dgeo, datm, dobs, name,
		(int)args [5]->NumberValue (),
		(int)args [6]->NumberValue (),
		dret, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("startVisible"), Number::New (dret [0]));
		result->Set (String::NewSymbol ("bestVisible"), Number::New (dret [1]));
		result->Set (String::NewSymbol ("endVisible"), Number::New (dret [2]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_heliacal_pheno_ut(double tjd_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 helflag, double *darr, char *serr)
 * =>
 * swe_heliacal_pheno_ut(double tjd_ut, double *geopos, double *datm, double *dobs, string ObjectName, int32 TypeEvent, int32 helflag) {
 *   tcAltitude:  			 double, // '0=AltO [deg]		topocentric altitude of object (unrefracted)
 *   tcApparentAltitude:  	 double, // '1=AppAltO [deg]    apparent altitude of object (refracted)
 *   gcAltitude:  			 double, // '2=GeoAltO [deg]    geocentric altitude of object
 *   azimuth:  				 double, // '3=AziO [deg]       azimuth of object
 *   tcSunAltitude:  		 double, // '4=AltS [deg]       topocentric altitude of Sun
 *   sunAzimuth:  			 double, // '5=AziS [deg]       azimuth of Sun
 *   tcActualVisibleArc:  	 double, // '6=TAVact [deg]     actual topocentric arcus visionis
 *   gcActualVisibleArc:  	 double, // '7=ARCVact [deg]    actual (geocentric) arcus visionis
 *   objectToSunAzimuth:  	 double, // '8=DAZact [deg]     actual difference between object's and sun's azimuth
 *   objectToSunLongitude:   double, // '9=ARCLact [deg]    actual longitude difference between object and sun
 *   extinction:  			 double, // '10=kact [-]        extinction coefficient
 *   tcMinVisibleArc:  		 double, // '11=minTAV [deg]    smallest topocentric arcus visionis
 *   firstVisible:  		 double, // '12=TfistVR [JDN]   first time object is visible, according to VR
 *   bestVisible:  			 double, // '13=TbVR [JDN]      optimum time the object is visible, according to VR
 *   endVisible:  			 double, // '14=TlastVR [JDN]   last time object is visible, according to VR
 *   yallopBestVisible:  	 double, // '15=TbYallop[JDN]   best time the object is visible, according to Yallop
 *   moonCresentWidth:  	 double, // '16=WMoon [deg]     cresent width of moon
 *   yallopValue:  			 double, // '17=qYal [-]        q-test value of Yallop
 *   yallopCriterion:  		 double, // '18=qCrit [-]       q-test criterion of Yallop
 *   parallax:  			 double, // '19=ParO [deg]      parallax of object
 *   magnitude:  			 double, // '20 Magn [-]        magnitude of object
 *   rise:  				 double, // '21=RiseO [JDN]     rise/set time of object
 *   riseSet:  				 double, // '22=RiseS [JDN]     rise/set time of sun
 *   riseObjectToSun:  		 double, // '23=Lag [JDN]       rise/set time of object minus rise/set time of sun
 *   visibleDuration:  		 double, // '24=TvisVR [JDN]    visibility duration
 *   moonCresetLength:  	 double, // '25=LMoon [deg]     cresent length of moon
 *   elong:  				 double, // '26=CVAact [deg]
 *   illumination:  		 double, 
 *   kOZ:  					 double, 
 *   ka:  					 double, 
 *   ksumm:  				 double,
 *   rflag: int32,
 *   error: string
 * }
 */
Handle <Value> node_swe_heliacal_pheno_ut (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 7) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsArray () ||
		!args [2]->IsArray () ||
		!args [3]->IsArray () ||
		!args [4]->IsString () ||
		!args [5]->IsNumber () ||
		!args [6]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double darr [50] = {0};
	char serr [AS_MAXCH];
	char name [AS_MAXCH];
	long rflag;

	dgeo [0] = args [1]->ToObject ()->Get (0)->NumberValue ();
	dgeo [1] = args [1]->ToObject ()->Get (1)->NumberValue ();
	dgeo [2] = args [1]->ToObject ()->Get (2)->NumberValue ();

	datm [0] = args [2]->ToObject ()->Get (0)->NumberValue ();
	datm [1] = args [2]->ToObject ()->Get (1)->NumberValue ();
	datm [2] = args [2]->ToObject ()->Get (2)->NumberValue ();
	datm [3] = args [2]->ToObject ()->Get (3)->NumberValue ();

	dobs [0] = args [3]->ToObject ()->Get (0)->NumberValue ();
	dobs [1] = args [3]->ToObject ()->Get (1)->NumberValue ();
	dobs [2] = args [3]->ToObject ()->Get (2)->NumberValue ();
	dobs [3] = args [3]->ToObject ()->Get (3)->NumberValue ();
	dobs [4] = args [3]->ToObject ()->Get (4)->NumberValue ();
	dobs [5] = args [3]->ToObject ()->Get (5)->NumberValue ();

	::strcpy (name, *String::AsciiValue (args [4]->ToString ()));

	rflag = ::swe_heliacal_ut (
		args [0]->NumberValue (),
		dgeo, datm, dobs, name,
		(int)args [5]->NumberValue (),
		(int)args [6]->NumberValue (),
		darr, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("tcAltitude"),			Number::New (darr [0]));
		result->Set (String::NewSymbol ("tcApparentAltitude"),	Number::New (darr [1]));
		result->Set (String::NewSymbol ("gcAltitude"),			Number::New (darr [2]));
		result->Set (String::NewSymbol ("azimuth"),				Number::New (darr [3]));
		result->Set (String::NewSymbol ("tcSunAltitude"),		Number::New (darr [4]));
		result->Set (String::NewSymbol ("sunAzimuth"),			Number::New (darr [5]));
		result->Set (String::NewSymbol ("tcActualVisibleArc"),	Number::New (darr [6]));
		result->Set (String::NewSymbol ("gcActualVisibleArc"),	Number::New (darr [7]));
		result->Set (String::NewSymbol ("objectToSunAzimuth"),	Number::New (darr [8]));
		result->Set (String::NewSymbol ("objectToSunLongitude"),Number::New (darr [9]));
		result->Set (String::NewSymbol ("extinction"),			Number::New (darr [10]));
		result->Set (String::NewSymbol ("tcMinVisibleArc"),		Number::New (darr [11]));
		result->Set (String::NewSymbol ("firstVisible"),		Number::New (darr [12]));
		result->Set (String::NewSymbol ("bestVisible"),			Number::New (darr [13]));
		result->Set (String::NewSymbol ("endVisible"),			Number::New (darr [14]));
		result->Set (String::NewSymbol ("yallopBestVisible"),	Number::New (darr [15]));
		result->Set (String::NewSymbol ("moonCresentWidth"),	Number::New (darr [16]));
		result->Set (String::NewSymbol ("yallopValue"),			Number::New (darr [17]));
		result->Set (String::NewSymbol ("yallopCriterion"),		Number::New (darr [18]));
		result->Set (String::NewSymbol ("parallax"),			Number::New (darr [19]));
		result->Set (String::NewSymbol ("magnitude"),			Number::New (darr [20]));
		result->Set (String::NewSymbol ("rise"),				Number::New (darr [21]));
		result->Set (String::NewSymbol ("riseSet"),				Number::New (darr [22]));
		result->Set (String::NewSymbol ("riseObjectToSun"),		Number::New (darr [23]));
		result->Set (String::NewSymbol ("visibleDuration"),		Number::New (darr [24]));
		result->Set (String::NewSymbol ("moonCresetLength"),	Number::New (darr [25]));
		result->Set (String::NewSymbol ("elong"),				Number::New (darr [26]));
		result->Set (String::NewSymbol ("illumination"),		Number::New (darr [27]));
		result->Set (String::NewSymbol ("kOZ"),					Number::New (darr [28]));
		result->Set (String::NewSymbol ("ka"),					Number::New (darr [29]));
		result->Set (String::NewSymbol ("ksumm"),				Number::New (darr [30]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};

/**
 * int32 swe_vis_limit_mag(double tjdut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 helflag, double *dret, char *serr)
 * =>
 * swe_vis_limit_mag(double tjdut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 helflag) {
 *   vissualMagnitudeLimit: double,
 *   AltO: double,
 *   AziO: double,
 *   AltS: double,
 *   AziS: double,
 *   AltM: double,
 *   AziM: double,
 *   rflag: int32,
 *   error: string
 * }
 */
Handle <Value> node_swe_vis_limit_mag (const Arguments & args) {
	HandleScope scope;

	if (args.Length () < 6) {
		ThrowException (Exception::TypeError (String::New ("Wrong number of arguments")));
		return scope.Close (Undefined ());
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsArray () ||
		!args [2]->IsArray () ||
		!args [3]->IsArray () ||
		!args [4]->IsString () ||
		!args [5]->IsNumber ()
	) {
		ThrowException (Exception::TypeError (String::New ("Wrong type of arguments")));
		return scope.Close (Undefined ());
	};

	double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double dret [50] = {0};
	char serr [AS_MAXCH];
	char name [AS_MAXCH];
	long rflag;

	dgeo [0] = args [1]->ToObject ()->Get (0)->NumberValue ();
	dgeo [1] = args [1]->ToObject ()->Get (1)->NumberValue ();
	dgeo [2] = args [1]->ToObject ()->Get (2)->NumberValue ();

	datm [0] = args [2]->ToObject ()->Get (0)->NumberValue ();
	datm [1] = args [2]->ToObject ()->Get (1)->NumberValue ();
	datm [2] = args [2]->ToObject ()->Get (2)->NumberValue ();
	datm [3] = args [2]->ToObject ()->Get (3)->NumberValue ();

	dobs [0] = args [3]->ToObject ()->Get (0)->NumberValue ();
	dobs [1] = args [3]->ToObject ()->Get (1)->NumberValue ();
	dobs [2] = args [3]->ToObject ()->Get (2)->NumberValue ();
	dobs [3] = args [3]->ToObject ()->Get (3)->NumberValue ();
	dobs [4] = args [3]->ToObject ()->Get (4)->NumberValue ();
	dobs [5] = args [3]->ToObject ()->Get (5)->NumberValue ();

	::strcpy (name, *String::AsciiValue (args [4]->ToString ()));

	rflag = ::swe_vis_limit_mag (
		args [0]->NumberValue (),
		dgeo, datm, dobs, name,
		(int)args [5]->NumberValue (),
		dret, serr
	);

	Local <Object> result = Object::New ();

	if (rflag < 0) {
		result->Set (String::NewSymbol ("error"), String::New (serr));
	} else {
		result->Set (String::NewSymbol ("vissualMagnitudeLimit"), Number::New (dret [0]));
		result->Set (String::NewSymbol ("AltO"), Number::New (dret [1]));
		result->Set (String::NewSymbol ("AziO"), Number::New (dret [2]));
		result->Set (String::NewSymbol ("AltS"), Number::New (dret [3]));
		result->Set (String::NewSymbol ("AziS"), Number::New (dret [4]));
		result->Set (String::NewSymbol ("AltM"), Number::New (dret [5]));
		result->Set (String::NewSymbol ("AziM"), Number::New (dret [6]));
		result->Set (String::NewSymbol ("rflag"), Number::New (rflag));
	};

    HandleCallback (args, result);

	return scope.Close (result);
};
