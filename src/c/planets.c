#include <pebble.h>
#include "astrocalc.h"
#include "my_math.h"
#include "colordefs.h"
#include "screencalc.h"

  
static Layer *s_planets_layer;

static PlanetsData *planets_data;


#include "stars.c"

  
static int flip_x(int x) {
    if (flip_horizontally == flip_horizontally_yes) {
        return 144 - x;
    }
    else return x;
}


static void draw_planet(GContext *ctx, GPoint *point, uint32_t resource_id, GColor color) {
  int x = flip_x(point->x);
  int y = point->y;
  GBitmap *planet_bitmap = gbitmap_create_with_resource(resource_id);
  
  #ifdef PBL_COLOR
  GColor *current_palette = gbitmap_get_palette(planet_bitmap);
  for(int i = 0; i < 16; i++){
		if ((GColorWhite.argb & 0x3F)==(current_palette[i].argb & 0x3F)){

			current_palette[i].argb = (current_palette[i].argb & 0xC0)| (color.argb & 0x3F);
			
		}

	}
  #endif
  graphics_context_set_fill_color(ctx, color);
  graphics_fill_circle(ctx, GPoint(x, y), 5);
  graphics_draw_bitmap_in_rect(ctx, planet_bitmap, GRect(x - 4, y - 4, 9, 9));
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_draw_circle(ctx, GPoint(x, y), 6);
  gbitmap_destroy(planet_bitmap);
}


static void draw_sun(GContext *ctx) {
    graphics_context_set_fill_color(ctx, SUN_COLOR);
    graphics_fill_circle(ctx, GPoint(72, 18), 10);
    graphics_context_set_stroke_color(ctx, GColorBlack);
    graphics_draw_circle(ctx, GPoint(72, 18), 9);
    graphics_draw_pixel(ctx, GPoint(72, 18));
    graphics_context_set_stroke_color(ctx, GColorWhite);
}     

static void draw_moon(GContext *ctx, GPoint *point, int angle) {
    int x = flip_x(point->x);
    int y = point->y;
    // full moon disk
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_fill_circle(ctx, GPoint(x, y), 7);
    graphics_context_set_fill_color(ctx, MOON_COLOR);
    graphics_fill_circle(ctx, GPoint(x, y), 6);
    
    if ((angle >= 192) || (angle < 168)) {
        // if not full, add shadow
        graphics_context_set_fill_color(ctx, MOON_BG_COLOR);
        graphics_fill_circle(ctx, GPoint(x, y), 5);
      
        if ((angle >= 10) && (angle < 350)) {
           // draw  crescent
          int i; int cx;
#ifdef PBL_COLOR
          graphics_context_set_stroke_color(ctx, GColorYellow);
#else
          graphics_context_set_stroke_color(ctx, GColorWhite);
#endif
           for (i = 0; i <= 10; i++) {
             
            if (angle < 180) {
                    cx = flip_x(point->x - 5 + i);
                    if (i <= (angle + 10)/20) {
                      graphics_draw_line(ctx, GPoint(x, point->y-6), GPoint(cx, y-3));
                      graphics_draw_line(ctx, GPoint(cx, point->y-3), GPoint(cx, y+3));
                      graphics_draw_line(ctx, GPoint(cx, point->y+3), GPoint(x, y+6));
                }
             }
             else {
                    cx = flip_x(point->x + 5 - i);
                    if (i <= (370 - angle)/20) {
                      graphics_draw_line(ctx, GPoint(x, y-6), GPoint(cx, point->y-3));
                      graphics_draw_line(ctx, GPoint(cx, y-3), GPoint(cx, y+3));
                      graphics_draw_line(ctx, GPoint(cx, y+3), GPoint(x, y+6));
             }
           }
        } 
    }
  }
  #ifdef PBL_COLOR
   else {
    GBitmap *moon_bitmap = gbitmap_create_with_resource(RESOURCE_ID_MOON);
    graphics_draw_bitmap_in_rect(ctx, moon_bitmap, GRect(x - 6, y - 6, 13, 13));
    gbitmap_destroy(moon_bitmap);
  }
  #endif
}


static void planets_layer_draw(Layer *layer, GContext *ctx) {
  #ifdef PBL_COLOR
  graphics_context_set_antialiased(ctx, false);
  #endif
  (void)layer;
  double d = getDayFrom2000();
  planets_data_update(planets_data, d);
  draw_const_lines(ctx, planets_data->sun_longhitude);
  #ifdef PBL_COLOR
  draw_stars(ctx, planets_data->sun_longhitude);
  #endif
  draw_sun(ctx);
  draw_planet(ctx, &(planets_data->saturn_point), RESOURCE_ID_SATURN, SATURN_COLOR);
  draw_planet(ctx, &(planets_data->jupiter_point), RESOURCE_ID_JUPITER, JUPITER_COLOR);
  draw_planet(ctx, &(planets_data->mars_point), RESOURCE_ID_MARS, MARS_COLOR);
  draw_planet(ctx, &(planets_data->mercury_point), RESOURCE_ID_MERCURY, MERCURY_COLOR);
  draw_planet(ctx, &(planets_data->venus_point), RESOURCE_ID_VENUS, VENUS_COLOR);
  draw_moon(ctx, &(planets_data->moon_point), planets_data->moon_angle);
  
}


static void planets_layer_create(Window *window) {
  s_planets_layer = layer_create(GRect(0, 0, 144, 168));
  layer_set_update_proc(s_planets_layer, planets_layer_draw);
  layer_add_child(window_get_root_layer(window), s_planets_layer);
}
