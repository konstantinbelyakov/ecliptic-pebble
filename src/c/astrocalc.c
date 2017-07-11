#include <time.h>
#include <pebble.h>
#include "astrocalc.h"
#include "my_math.h"

  
double getJulianDay() {
	time_t ltime;
	time(&ltime);
	return (ltime / 86400.0) + 2440587.5;
}


double getDayFrom2000() {
  return getJulianDay() - 2451543.5; 
}

float Ls = 0, Ms = 0; // Sun's  mean longitude and anomaly required to compute Moon perturbations
float sunX = 0, sunY = 0; // Solar rect. ecl coord, required to calc geocentric position of planets


float getEccentricAnomaly(float e, float M) {
	float E0 = 0, E1 = 0;
	E0 = M + (180 / M_PI) * e * sind(M) * (1 + e * cosd(M));
	while (1) {
		E1 = E0 - (E0 - (180 / M_PI) * e * sind(E0) - M) / (1 - e * cosd(E0));
		if (my_fabs(E0 - E1) < 0.005) break;
		E0 = E1;
	}
  return E0;
}

float getSunLongitude(float d) {
	float w = 282.9404 + 4.70935e-5 * d; //longitude of perihelion, degrees
	// float a = 1.000000;                            // mean distance
	float e = 0.016709 - 1.151e-9 * d; // eccentricity
	float M = 356.0470 + 0.9856002585 * d; // mean anomaly, degrees
	float L = w + M; //mean longitude
	// angles normalization:
	L = rev(L);
	w = rev(w);
	M = rev(M);

	// eccentric anomaly
	float E = getEccentricAnomaly(e, M);
	float x = cosd(E) - e;
	float y = sind(E) * my_sqrt(1 - e*e);
	float r = my_sqrt(x*x + y*y); //distance
	float v = atan2d(y, x);  //true anomaly
	float lon = v + w;

	// pass to globals for latter Moon perturbation calculations:

	Ls = rev(L); Ms = rev(M);

	// pass to globals for latter geocentric calculations:

	sunX = r * cosd(lon);
	sunY = r * sind(lon);
	return rev(lon);
}

float getMoonLongitude(float d) {
	float N = 125.1228 - 0.0529538083  * d; // (Long asc.node)
	float i = 5.1454;							// (Inclination)
	float w = 318.0634 + 0.1643573223 * d;  //(Arg.of perigee)
	float a = 60.2666;                           //     Mean distance in Earth radii
	float e = 0.054900;                              //Eccentricity
	float M = 115.3654 + 13.0649929509 * d; // (Mean anomaly)

	// angles normalization:
	N = rev(N);
	w = rev(w);
	M = rev(M);

	float E = getEccentricAnomaly(e, M);
  
	float x = a * (cosd(E) - e);
	float y = a * my_sqrt(1 - e*e) * sind(E);

	float r = my_sqrt(x*x + y*y); // distance in Earth radii
	float v = atan2d(y, x);   // true anomaly

	float xeclip = r * (cosd(N) * cosd(v + w) - sind(N) * sind(v + w) * cosd(i));
	float yeclip = r * (sind(N) * cosd(v + w) + cosd(N) * sind(v + w) * cosd(i));
	//float zeclip = r * sind(v + w) * sind(i);

	float lonecl = rev(atan2d(yeclip, xeclip));


	// perturbations
	
	float L = N + w + M; // Moon's mean longitude
	float D = L - Ls; // Moon's mean elongation
	float F = L - N; // Moon's argument of latitude

	lonecl = lonecl - 1.274 * sind(M - 2 * D);    //Evection
	lonecl = lonecl + 0.658 * sind(2 * D);         //Variation
	lonecl = lonecl - 0.186 * sind(Ms);          //Yearly equation
	lonecl = lonecl - 0.059 * sind(2 * M - 2 * D);
	lonecl = lonecl - 0.057 * sind(M - 2 * D + Ms);
	lonecl = lonecl + 0.053 * sind(M + 2 * D);
	lonecl = lonecl + 0.046 * sind(2 * D - Ms);
	lonecl = lonecl + 0.041 * sind(M - Ms);
	lonecl = lonecl - 0.035 * sind(D);            //Parallactic equation
	lonecl = lonecl - 0.031 * sind(M + Ms);
	lonecl = lonecl - 0.015 * sind(2 * F - 2 * D);
	lonecl = lonecl + 0.011 * sind(M - 4 * D);

	return rev(lonecl); 
}

float getPlanetLongitude(float N, float i, float w, float a, float e, float M) {
	// angles normalization:
	N = rev(N);
	w = rev(w);
	M = rev(M);

	float E = getEccentricAnomaly(e, M);

	float x = a * (cosd(E) - e);
	float y = a * (sind(E) * my_sqrt(1 - e*e));
	float r = my_sqrt(x*x + y*y); //distance
	float v = atan2d(y, x);  //true anomaly

	float xeclip = r * (cosd(N) * cosd(v + w) - sind(N) * sind(v + w) * cosd(i)) + sunX;
	float yeclip = r * (sind(N) * cosd(v + w) + cosd(N) * sind(v + w) * cosd(i)) + sunY;
	
	float lonecl = rev(atan2d(yeclip, xeclip));

	return lonecl;
}


float getMercuryLongitude(float d) {
	float N = 48.3313 + 3.24587e-5 * d; // (Long of asc.node)
	float i = 7.0047 + 5.00e-8 * d; //(Inclination)
	float w = 29.1241 + 1.01444e-5 * d; //(Argument of perihelion)
	float a = 0.387098; //                               (Semi - major axis)
	float e = 0.205635 + 5.59e-10 * d; //(Eccentricity)
	float M = 168.6562 + 4.0923344368 * d; //(Mean anonaly)

	float lonecl = getPlanetLongitude(N, i, w, a, e, M);

	return lonecl;
}


float getVenusLongitude(float d) {
	float N = 76.6799 + 2.46590e-5 * d; // (Long of asc.node)
	float i = 3.3946 + 2.75E-8 * d; //(Inclination)
	float w = 54.8910 + 1.38374E-5 * d; //(Argument of perihelion)
	float a = 0.723330; //                               (Semi - major axis)
	float e = 0.006773 - 1.302E-9; //(Eccentricity)
	float M = 48.0052 + 1.6021302244 * d; //(Mean anonaly)

	float lonecl = getPlanetLongitude(N, i, w, a, e, M);

	return lonecl;
}

float getMarsLongitude(float d) {
	float N = 49.5574 + 2.11081E-5 * d; // (Long of asc.node)
	float i = 1.8497 - 1.78E-8 * d; //(Inclination)
	float w = 286.5016 + 2.92961E-5 * d; //(Argument of perihelion)
	float a = 1.523688; //                               (Semi - major axis)
	float e = 0.093405 + 2.516E-9 * d; //(Eccentricity)
	float M = 18.6021 + 0.5240207766 * d; //(Mean anonaly)

	float lonecl = getPlanetLongitude(N, i, w, a, e, M);

	return lonecl;
}

float getJupiterLongitude(float d) {
	float N = 100.4542 + 2.76854E-5 * d; // (Long of asc.node)
	float i = 1.3030 - 1.557E-7 * d; //(Inclination)
	float w = 273.8777 + 1.64505E-5 * d; //(Argument of perihelion)
	float a = 5.20256; //                               (Semi - major axis)
	float e = 0.048498 + 4.469e-9 * d; //(Eccentricity)
	float M = 19.8950 + 0.0830853001 * d; //(Mean anonaly)

	float lonecl = getPlanetLongitude(N, i, w, a, e, M);

	return lonecl;
}

float getSaturnLongitude(float d) {
	float N = 113.6634 + 2.38980E-5 * d; // (Long of asc.node)
	float i = 2.4886 - 1.081E-7 * d; //(Inclination)
	float w = 339.3939 + 2.97661e-5 * d; //(Argument of perihelion)
	float a = 9.55475; //                               (Semi - major axis)
	float e = 0.055546 - 9.499E-9 * d; //(Eccentricity)
	float M = 316.9670 + 0.0334442282 * d; //(Mean anonaly)
	 
	float lonecl = getPlanetLongitude(N, i, w, a, e, M);

	return lonecl;
}


