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
void node_swe_heliacal_ut (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 7) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
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
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
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

	::strcpy (name, *String::Utf8Value (args [4]->ToString ()));

	rflag = ::swe_heliacal_ut (
		args [0]->NumberValue (),
		dgeo, datm, dobs, name,
		(int)args [5]->NumberValue (),
		(int)args [6]->NumberValue (),
		dret, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "startVisible"), Number::New (isolate, dret [0]));
		result->Set (String::NewFromUtf8 (isolate, "bestVisible"), Number::New (isolate, dret [1]));
		result->Set (String::NewFromUtf8 (isolate, "endVisible"), Number::New (isolate, dret [2]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_heliacal_pheno_ut (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 7) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
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
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
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

	::strcpy (name, *String::Utf8Value (args [4]->ToString ()));

	rflag = ::swe_heliacal_ut (
		args [0]->NumberValue (),
		dgeo, datm, dobs, name,
		(int)args [5]->NumberValue (),
		(int)args [6]->NumberValue (),
		darr, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "tcAltitude"),			Number::New (isolate, darr [0]));
		result->Set (String::NewFromUtf8 (isolate, "tcApparentAltitude"),	Number::New (isolate, darr [1]));
		result->Set (String::NewFromUtf8 (isolate, "gcAltitude"),			Number::New (isolate, darr [2]));
		result->Set (String::NewFromUtf8 (isolate, "azimuth"),				Number::New (isolate, darr [3]));
		result->Set (String::NewFromUtf8 (isolate, "tcSunAltitude"),		Number::New (isolate, darr [4]));
		result->Set (String::NewFromUtf8 (isolate, "sunAzimuth"),			Number::New (isolate, darr [5]));
		result->Set (String::NewFromUtf8 (isolate, "tcActualVisibleArc"),	Number::New (isolate, darr [6]));
		result->Set (String::NewFromUtf8 (isolate, "gcActualVisibleArc"),	Number::New (isolate, darr [7]));
		result->Set (String::NewFromUtf8 (isolate, "objectToSunAzimuth"),	Number::New (isolate, darr [8]));
		result->Set (String::NewFromUtf8 (isolate, "objectToSunLongitude"),Number::New (isolate, darr [9]));
		result->Set (String::NewFromUtf8 (isolate, "extinction"),			Number::New (isolate, darr [10]));
		result->Set (String::NewFromUtf8 (isolate, "tcMinVisibleArc"),		Number::New (isolate, darr [11]));
		result->Set (String::NewFromUtf8 (isolate, "firstVisible"),		Number::New (isolate, darr [12]));
		result->Set (String::NewFromUtf8 (isolate, "bestVisible"),			Number::New (isolate, darr [13]));
		result->Set (String::NewFromUtf8 (isolate, "endVisible"),			Number::New (isolate, darr [14]));
		result->Set (String::NewFromUtf8 (isolate, "yallopBestVisible"),	Number::New (isolate, darr [15]));
		result->Set (String::NewFromUtf8 (isolate, "moonCresentWidth"),	Number::New (isolate, darr [16]));
		result->Set (String::NewFromUtf8 (isolate, "yallopValue"),			Number::New (isolate, darr [17]));
		result->Set (String::NewFromUtf8 (isolate, "yallopCriterion"),		Number::New (isolate, darr [18]));
		result->Set (String::NewFromUtf8 (isolate, "parallax"),			Number::New (isolate, darr [19]));
		result->Set (String::NewFromUtf8 (isolate, "magnitude"),			Number::New (isolate, darr [20]));
		result->Set (String::NewFromUtf8 (isolate, "rise"),				Number::New (isolate, darr [21]));
		result->Set (String::NewFromUtf8 (isolate, "riseSet"),				Number::New (isolate, darr [22]));
		result->Set (String::NewFromUtf8 (isolate, "riseObjectToSun"),		Number::New (isolate, darr [23]));
		result->Set (String::NewFromUtf8 (isolate, "visibleDuration"),		Number::New (isolate, darr [24]));
		result->Set (String::NewFromUtf8 (isolate, "moonCresetLength"),	Number::New (isolate, darr [25]));
		result->Set (String::NewFromUtf8 (isolate, "elong"),				Number::New (isolate, darr [26]));
		result->Set (String::NewFromUtf8 (isolate, "illumination"),		Number::New (isolate, darr [27]));
		result->Set (String::NewFromUtf8 (isolate, "kOZ"),					Number::New (isolate, darr [28]));
		result->Set (String::NewFromUtf8 (isolate, "ka"),					Number::New (isolate, darr [29]));
		result->Set (String::NewFromUtf8 (isolate, "ksumm"),				Number::New (isolate, darr [30]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


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
void node_swe_vis_limit_mag (const FunctionCallbackInfo <Value> & args) {
	Isolate * isolate = Isolate::GetCurrent (); HandleScope scope (isolate);

	if (args.Length () < 6) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong number of arguments")));
		return;
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsArray () ||
		!args [2]->IsArray () ||
		!args [3]->IsArray () ||
		!args [4]->IsString () ||
		!args [5]->IsNumber ()
	) {
		isolate->ThrowException (Exception::TypeError (String::NewFromUtf8 (isolate, "Wrong type of arguments")));
		return;
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

	::strcpy (name, *String::Utf8Value (args [4]->ToString ()));

	rflag = ::swe_vis_limit_mag (
		args [0]->NumberValue (),
		dgeo, datm, dobs, name,
		(int)args [5]->NumberValue (),
		dret, serr
	);

	Local <Object> result = Object::New (isolate);

	if (rflag < 0) {
		result->Set (String::NewFromUtf8 (isolate, "error"), String::NewFromUtf8 (isolate, serr));
	} else {
		result->Set (String::NewFromUtf8 (isolate, "vissualMagnitudeLimit"), Number::New (isolate, dret [0]));
		result->Set (String::NewFromUtf8 (isolate, "AltO"), Number::New (isolate, dret [1]));
		result->Set (String::NewFromUtf8 (isolate, "AziO"), Number::New (isolate, dret [2]));
		result->Set (String::NewFromUtf8 (isolate, "AltS"), Number::New (isolate, dret [3]));
		result->Set (String::NewFromUtf8 (isolate, "AziS"), Number::New (isolate, dret [4]));
		result->Set (String::NewFromUtf8 (isolate, "AltM"), Number::New (isolate, dret [5]));
		result->Set (String::NewFromUtf8 (isolate, "AziM"), Number::New (isolate, dret [6]));
		result->Set (String::NewFromUtf8 (isolate, "rflag"), Number::New (isolate, rflag));
	};

    HandleCallback (isolate, args, result);


};
