#include <pebble.h>
#include "my_math.h"
#include "astrocalc.h"
#include "screencalc.h"
#include "settings.h"
  
#define MOON_UPDATE_FREQ 0.05  // 20 times per day
#define PLANETS_UPDATE_FREQ 1.0  // 1 day
 
int scrX(float angle) {
  return my_rint(72 + (sind(angle) * 66));
}

int scrY(float angle) {
    return my_rint(84 - (cosd(angle) * 66));
}


void planets_data_update(PlanetsData *data, double d) {
  //float SunL = 0;
  if ((my_fabs(d - data->moon_date) > MOON_UPDATE_FREQ) || (my_fabs(d - data->planets_date) > PLANETS_UPDATE_FREQ)) {
     //SunL = getSunLongitude(d);
     data->sun_longhitude = getSunLongitude(d);
  }
  if ((my_fabs(d - data->moon_date) > MOON_UPDATE_FREQ)) {
    // update Moon
    data->moon_angle = rev(data->sun_longhitude - getMoonLongitude(d));
    data->moon_point = GPoint(scrX(data->moon_angle), scrY(data->moon_angle));
    data->moon_date = d;
  }
  if ((my_fabs(d - data->planets_date) > PLANETS_UPDATE_FREQ)) {
    // update other planets 1 time per day
    float mercury_angle = rev(data->sun_longhitude - getMercuryLongitude(d));
    float venus_angle = rev(data->sun_longhitude - getVenusLongitude(d));
    float mars_angle = rev(data->sun_longhitude - getMarsLongitude(d));
    float jupiter_angle = rev(data->sun_longhitude - getJupiterLongitude(d));
    float saturn_angle = rev(data->sun_longhitude - getSaturnLongitude(d));
    data->mercury_point = GPoint(scrX(mercury_angle), scrY(mercury_angle));
    data->venus_point = GPoint(scrX(venus_angle), scrY(venus_angle));
    data->mars_point = GPoint(scrX(mars_angle), scrY(mars_angle));
    data->jupiter_point = GPoint(scrX(jupiter_angle), scrY(jupiter_angle));
    data->saturn_point = GPoint(scrX(saturn_angle), scrY(saturn_angle));
    data->planets_date = d;
  }
}

