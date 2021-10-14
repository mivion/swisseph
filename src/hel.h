#ifndef __swisseph_hel_h__
#define __swisseph_hel_h__

#include <node.h>
#include <v8.h>

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
NAN_METHOD(node_swe_heliacal_ut);

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
NAN_METHOD(node_swe_heliacal_pheno_ut);

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
NAN_METHOD(node_swe_vis_limit_mag);

#endif // __swisseph_hel_h__
