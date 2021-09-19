#include "swisseph.h"

using namespace v8;

/**
 * int32 swe_heliacal_ut(double tjdstart_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 iflag, double *dret, char *serr);
 * =>
 * swe_heliacal_ut(double tjdstart_ut, double *geopos, double *datm, double *dobs, string ObjectName, int32 TypeEvent, int32 iflag[, function callback (result)]) = {
 *   startVisible: double,
 *   bestVisible: double,
 *   endVisible: double,
 *   rflag: int32,
 *   error: string
 * }
 */
NAN_METHOD(node_swe_heliacal_ut) {
	Nan::HandleScope scope;

	if (info.Length () < 7) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsArray () ||
		!info [2]->IsArray () ||
		!info [3]->IsArray () ||
		!info [4]->IsString () ||
		!info [5]->IsNumber () ||
		!info [6]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double dret [50] = {0};
	char serr [AS_MAXCH];
	char name [AS_MAXCH];
	long rflag;

	dgeo [0] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dgeo [1] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dgeo [2] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	datm [0] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [1] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [2] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [3] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),3).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	dobs [0] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [1] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [2] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [3] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),3).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [4] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),4).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [5] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),5).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	::strcpy (name, *String::Utf8Value (Isolate::GetCurrent(), info [4]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_heliacal_ut (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		dgeo, datm, dobs, name,
		(int)info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		dret, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("startVisible").ToLocalChecked(), Nan::New<Number> (dret [0]));
		Nan::Set(result,Nan::New<String> ("bestVisible").ToLocalChecked(), Nan::New<Number> (dret [1]));
		Nan::Set(result,Nan::New<String> ("endVisible").ToLocalChecked(), Nan::New<Number> (dret [2]));
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_heliacal_pheno_ut(double tjd_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 helflag, double *darr, char *serr)
 * =>
 * swe_heliacal_pheno_ut(double tjd_ut, double *geopos, double *datm, double *dobs, string ObjectName, int32 TypeEvent, int32 helflag[, function callback (result)]) = {
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
	Nan::HandleScope scope;

	if (info.Length () < 7) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsArray () ||
		!info [2]->IsArray () ||
		!info [3]->IsArray () ||
		!info [4]->IsString () ||
		!info [5]->IsNumber () ||
		!info [6]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double darr [50] = {0};
	char serr [AS_MAXCH];
	char name [AS_MAXCH];
	long rflag;

	dgeo [0] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dgeo [1] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dgeo [2] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	datm [0] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [1] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [2] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [3] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),3).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	dobs [0] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [1] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [2] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [3] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),3).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [4] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),4).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [5] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),5).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	::strcpy (name, *String::Utf8Value (Isolate::GetCurrent(), info [4]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_heliacal_ut (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		dgeo, datm, dobs, name,
		(int)info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		(int)info [6]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		darr, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("tcAltitude").ToLocalChecked(),			Nan::New<Number> (darr [0]));
		Nan::Set(result,Nan::New<String> ("tcApparentAltitude").ToLocalChecked(),	Nan::New<Number> (darr [1]));
		Nan::Set(result,Nan::New<String> ("gcAltitude").ToLocalChecked(),			Nan::New<Number> (darr [2]));
		Nan::Set(result,Nan::New<String> ("azimuth").ToLocalChecked(),				Nan::New<Number> (darr [3]));
		Nan::Set(result,Nan::New<String> ("tcSunAltitude").ToLocalChecked(),		Nan::New<Number> (darr [4]));
		Nan::Set(result,Nan::New<String> ("sunAzimuth").ToLocalChecked(),			Nan::New<Number> (darr [5]));
		Nan::Set(result,Nan::New<String> ("tcActualVisibleArc").ToLocalChecked(),	Nan::New<Number> (darr [6]));
		Nan::Set(result,Nan::New<String> ("gcActualVisibleArc").ToLocalChecked(),	Nan::New<Number> (darr [7]));
		Nan::Set(result,Nan::New<String> ("objectToSunAzimuth").ToLocalChecked(),	Nan::New<Number> (darr [8]));
		Nan::Set(result,Nan::New<String> ("objectToSunLongitude").ToLocalChecked(),Nan::New<Number> (darr [9]));
		Nan::Set(result,Nan::New<String> ("extinction").ToLocalChecked(),			Nan::New<Number> (darr [10]));
		Nan::Set(result,Nan::New<String> ("tcMinVisibleArc").ToLocalChecked(),		Nan::New<Number> (darr [11]));
		Nan::Set(result,Nan::New<String> ("firstVisible").ToLocalChecked(),		Nan::New<Number> (darr [12]));
		Nan::Set(result,Nan::New<String> ("bestVisible").ToLocalChecked(),			Nan::New<Number> (darr [13]));
		Nan::Set(result,Nan::New<String> ("endVisible").ToLocalChecked(),			Nan::New<Number> (darr [14]));
		Nan::Set(result,Nan::New<String> ("yallopBestVisible").ToLocalChecked(),	Nan::New<Number> (darr [15]));
		Nan::Set(result,Nan::New<String> ("moonCresentWidth").ToLocalChecked(),	Nan::New<Number> (darr [16]));
		Nan::Set(result,Nan::New<String> ("yallopValue").ToLocalChecked(),			Nan::New<Number> (darr [17]));
		Nan::Set(result,Nan::New<String> ("yallopCriterion").ToLocalChecked(),		Nan::New<Number> (darr [18]));
		Nan::Set(result,Nan::New<String> ("parallax").ToLocalChecked(),			Nan::New<Number> (darr [19]));
		Nan::Set(result,Nan::New<String> ("magnitude").ToLocalChecked(),			Nan::New<Number> (darr [20]));
		Nan::Set(result,Nan::New<String> ("rise").ToLocalChecked(),				Nan::New<Number> (darr [21]));
		Nan::Set(result,Nan::New<String> ("riseSet").ToLocalChecked(),				Nan::New<Number> (darr [22]));
		Nan::Set(result,Nan::New<String> ("riseObjectToSun").ToLocalChecked(),		Nan::New<Number> (darr [23]));
		Nan::Set(result,Nan::New<String> ("visibleDuration").ToLocalChecked(),		Nan::New<Number> (darr [24]));
		Nan::Set(result,Nan::New<String> ("moonCresetLength").ToLocalChecked(),	Nan::New<Number> (darr [25]));
		Nan::Set(result,Nan::New<String> ("elong").ToLocalChecked(),				Nan::New<Number> (darr [26]));
		Nan::Set(result,Nan::New<String> ("illumination").ToLocalChecked(),		Nan::New<Number> (darr [27]));
		Nan::Set(result,Nan::New<String> ("kOZ").ToLocalChecked(),					Nan::New<Number> (darr [28]));
		Nan::Set(result,Nan::New<String> ("ka").ToLocalChecked(),					Nan::New<Number> (darr [29]));
		Nan::Set(result,Nan::New<String> ("ksumm").ToLocalChecked(),				Nan::New<Number> (darr [30]));
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(),               Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};

/**
 * int32 swe_vis_limit_mag(double tjdut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 helflag, double *dret, char *serr)
 * =>
 * swe_vis_limit_mag(double tjdut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 helflag[, function callback (result)]) = {
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
	Nan::HandleScope scope;

	if (info.Length () < 6) {
		Nan::ThrowTypeError ("Wrong number of arguments");
	};

	if (
		!info [0]->IsNumber () ||
		!info [1]->IsArray () ||
		!info [2]->IsArray () ||
		!info [3]->IsArray () ||
		!info [4]->IsString () ||
		!info [5]->IsNumber ()
	) {
		Nan::ThrowTypeError ("Wrong type of arguments");
	};

	double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double dret [50] = {0};
	char serr [AS_MAXCH];
	char name [AS_MAXCH];
	long rflag;

	dgeo [0] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dgeo [1] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dgeo [2] = info [1]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	datm [0] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [1] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [2] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	datm [3] = info [2]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),3).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	dobs [0] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),0).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [1] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),1).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [2] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),2).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [3] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),3).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [4] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),4).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();
	dobs [5] = info [3]->ToObject (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::Object>())->Get (Nan::GetCurrentContext(),5).ToLocalChecked()->NumberValue (Nan::GetCurrentContext()).ToChecked();

	::strcpy (name, *String::Utf8Value (Isolate::GetCurrent(), info [4]->ToString (Nan::GetCurrentContext()).FromMaybe(v8::Local<v8::String>())));

	rflag = ::swe_vis_limit_mag (
		info [0]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		dgeo, datm, dobs, name,
		(int)info [5]->NumberValue (Nan::GetCurrentContext()).ToChecked(),
		dret, serr
	);

	Local <Object> result = Nan::New<Object> ();

	if (rflag < 0) {
		Nan::Set(result,Nan::New<String> ("error").ToLocalChecked(), Nan::New<String> (serr).ToLocalChecked());
	} else {
		Nan::Set(result,Nan::New<String> ("vissualMagnitudeLimit").ToLocalChecked(), Nan::New<Number> (dret [0]));
		Nan::Set(result,Nan::New<String> ("AltO").ToLocalChecked(), Nan::New<Number> (dret [1]));
		Nan::Set(result,Nan::New<String> ("AziO").ToLocalChecked(), Nan::New<Number> (dret [2]));
		Nan::Set(result,Nan::New<String> ("AltS").ToLocalChecked(), Nan::New<Number> (dret [3]));
		Nan::Set(result,Nan::New<String> ("AziS").ToLocalChecked(), Nan::New<Number> (dret [4]));
		Nan::Set(result,Nan::New<String> ("AltM").ToLocalChecked(), Nan::New<Number> (dret [5]));
		Nan::Set(result,Nan::New<String> ("AziM").ToLocalChecked(), Nan::New<Number> (dret [6]));
		Nan::Set(result,Nan::New<String> ("rflag").ToLocalChecked(), Nan::New<Number> (rflag));
	};

    HandleCallback (info, result);
    info.GetReturnValue().Set (result);
};
