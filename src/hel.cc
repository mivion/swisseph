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
NAN_METHOD(node_swe_heliacal_ut) {
	NanScope();

	if (args.Length () < 7) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("startVisible"), NanNew<Number> (dret [0]));
		result->Set (NanNew<String> ("bestVisible"), NanNew<Number> (dret [1]));
		result->Set (NanNew<String> ("endVisible"), NanNew<Number> (dret [2]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_heliacal_pheno_ut) {
	NanScope();

	if (args.Length () < 7) {
		NanThrowTypeError ("Wrong number of arguments");
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
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("tcAltitude"),			NanNew<Number> (darr [0]));
		result->Set (NanNew<String> ("tcApparentAltitude"),	NanNew<Number> (darr [1]));
		result->Set (NanNew<String> ("gcAltitude"),			NanNew<Number> (darr [2]));
		result->Set (NanNew<String> ("azimuth"),				NanNew<Number> (darr [3]));
		result->Set (NanNew<String> ("tcSunAltitude"),		NanNew<Number> (darr [4]));
		result->Set (NanNew<String> ("sunAzimuth"),			NanNew<Number> (darr [5]));
		result->Set (NanNew<String> ("tcActualVisibleArc"),	NanNew<Number> (darr [6]));
		result->Set (NanNew<String> ("gcActualVisibleArc"),	NanNew<Number> (darr [7]));
		result->Set (NanNew<String> ("objectToSunAzimuth"),	NanNew<Number> (darr [8]));
		result->Set (NanNew<String> ("objectToSunLongitude"),NanNew<Number> (darr [9]));
		result->Set (NanNew<String> ("extinction"),			NanNew<Number> (darr [10]));
		result->Set (NanNew<String> ("tcMinVisibleArc"),		NanNew<Number> (darr [11]));
		result->Set (NanNew<String> ("firstVisible"),		NanNew<Number> (darr [12]));
		result->Set (NanNew<String> ("bestVisible"),			NanNew<Number> (darr [13]));
		result->Set (NanNew<String> ("endVisible"),			NanNew<Number> (darr [14]));
		result->Set (NanNew<String> ("yallopBestVisible"),	NanNew<Number> (darr [15]));
		result->Set (NanNew<String> ("moonCresentWidth"),	NanNew<Number> (darr [16]));
		result->Set (NanNew<String> ("yallopValue"),			NanNew<Number> (darr [17]));
		result->Set (NanNew<String> ("yallopCriterion"),		NanNew<Number> (darr [18]));
		result->Set (NanNew<String> ("parallax"),			NanNew<Number> (darr [19]));
		result->Set (NanNew<String> ("magnitude"),			NanNew<Number> (darr [20]));
		result->Set (NanNew<String> ("rise"),				NanNew<Number> (darr [21]));
		result->Set (NanNew<String> ("riseSet"),				NanNew<Number> (darr [22]));
		result->Set (NanNew<String> ("riseObjectToSun"),		NanNew<Number> (darr [23]));
		result->Set (NanNew<String> ("visibleDuration"),		NanNew<Number> (darr [24]));
		result->Set (NanNew<String> ("moonCresetLength"),	NanNew<Number> (darr [25]));
		result->Set (NanNew<String> ("elong"),				NanNew<Number> (darr [26]));
		result->Set (NanNew<String> ("illumination"),		NanNew<Number> (darr [27]));
		result->Set (NanNew<String> ("kOZ"),					NanNew<Number> (darr [28]));
		result->Set (NanNew<String> ("ka"),					NanNew<Number> (darr [29]));
		result->Set (NanNew<String> ("ksumm"),				NanNew<Number> (darr [30]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
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
NAN_METHOD(node_swe_vis_limit_mag) {
	NanScope();

	if (args.Length () < 6) {
		NanThrowTypeError ("Wrong number of arguments");
	};

	if (
		!args [0]->IsNumber () ||
		!args [1]->IsArray () ||
		!args [2]->IsArray () ||
		!args [3]->IsArray () ||
		!args [4]->IsString () ||
		!args [5]->IsNumber ()
	) {
		NanThrowTypeError ("Wrong type of arguments");
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

	Local <Object> result = NanNew<Object> ();

	if (rflag < 0) {
		result->Set (NanNew<String> ("error"), NanNew<String> (serr));
	} else {
		result->Set (NanNew<String> ("vissualMagnitudeLimit"), NanNew<Number> (dret [0]));
		result->Set (NanNew<String> ("AltO"), NanNew<Number> (dret [1]));
		result->Set (NanNew<String> ("AziO"), NanNew<Number> (dret [2]));
		result->Set (NanNew<String> ("AltS"), NanNew<Number> (dret [3]));
		result->Set (NanNew<String> ("AziS"), NanNew<Number> (dret [4]));
		result->Set (NanNew<String> ("AltM"), NanNew<Number> (dret [5]));
		result->Set (NanNew<String> ("AziM"), NanNew<Number> (dret [6]));
		result->Set (NanNew<String> ("rflag"), NanNew<Number> (rflag));
	};

    HandleCallback (args, result);
    NanReturnValue (result);
};
