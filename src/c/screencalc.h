typedef struct {
  GPoint mercury_point;
  GPoint venus_point;
  GPoint mars_point;
  GPoint jupiter_point;
  GPoint saturn_point;
  GPoint moon_point;
  int moon_angle;
  double moon_date;
  double planets_date;
  float sun_longhitude;
} PlanetsData;

void planets_data_update(PlanetsData *data, double d);

