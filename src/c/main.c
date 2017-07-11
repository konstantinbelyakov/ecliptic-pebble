#include <pebble.h>
#include "planets.c"
#include "time.c"
#include "sb.c"
#include "colordefs.h"
  
//#include "settings.h"
  
  
  
static Window *s_main_window;
#ifdef PBL_BW
static InverterLayer* inverter_layer;
#endif
static Layer* ecliptic_layer;



static AppSync app;
static uint8_t buffer[256];


static void tuple_changed_callback(const uint32_t key, const Tuple* tuple_new, const Tuple* tuple_old, void* context) {
  //  we know these values are uint8 format
  int value = tuple_new->value->uint8;
  switch (key) {
    case setting_screen:
      if ((value >= 0) && (value < screen_count) && (screen != value)) {
        //  update value
        screen = value;
        //  relocate inverter layer
        #ifdef PBL_BW
        GRect rect = layer_get_frame(inverter_layer_get_layer(inverter_layer));
        rect.origin.x = (screen == screen_black) ? 144 : 0;
        layer_set_frame(inverter_layer_get_layer(inverter_layer), rect);
        #endif
      }
      break;
    case setting_vibrate_hourly:
      if ((value >= 0) && (value < vibrate_hourly_count) && (vibrate_hourly != value)) {
        //  update value
        vibrate_hourly = value;
      }
      break;
    case setting_vibrate_disconnected:
      if ((value >= 0) && (value < vibrate_disconnected_count) && (vibrate_disconnected != value))
        //  update value
        vibrate_disconnected = value;
      break;
    case setting_flip_horizontally:
      if ((value >= 0) && (value < flip_horizontally_count) && (flip_horizontally != value))
        //  update value
        flip_horizontally = value;
        layer_mark_dirty(window_get_root_layer(s_main_window));
      break;
  }
}
static void app_error_callback(DictionaryResult dict_error, AppMessageResult app_message_error, void* context) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "app error %d", app_message_error);
}

static void ecliptic_layer_draw(Layer *layer, GContext *ctx) {
  //#ifdef PBL_COLOR
  //graphics_context_set_antialiased(ctx, false);
   
  
  //graphics_context_set_fill_color(ctx, GColorOxfordBlue);
  //graphics_fill_circle(ctx, GPoint(72, 18), 120);
  
  //graphics_context_set_fill_color(ctx, GColorDukeBlue);
  //graphics_fill_circle(ctx, GPoint(72, 18), 80);
  
  //graphics_context_set_fill_color(ctx, GColorBlue);
  //graphics_fill_circle(ctx, GPoint(72, 18), 40);

  //for (int x=0; x<144; x++) {
  //  for (int y=0; y<168; y++) {
  //      int r=my_sqrt((x-72)*(x-72) + (y-18)*(y-18));

        //int blue = 255 - (r*1.5) - rand() % 100;
        //if (blue < 0) blue = 0;
        //if (blue > 255) blue = 255;
        //graphics_context_set_stroke_color(ctx, GColorFromRGB(0, 0, blue));
        
        //graphics_draw_pixel(ctx, GPoint(x,y));
    //}
  //}
  
  //graphics_context_set_stroke_color(ctx, GColorSunsetOrange);
  //#else
  //graphics_context_set_stroke_color(ctx, GColorWhite);
  //#endif
  graphics_context_set_stroke_color(ctx, ECLIPTIC_COLOR);
  graphics_draw_circle(ctx, GPoint(72, 84), 66);
}

static void connection_handler(bool connected) {
  is_connected = connected;
  layer_mark_dirty(s_sb_layer);
  if ((vibrate_disconnected == vibrate_disconnected_yes) && !connected) {
    vibes_double_pulse();
  }
}
 
static void main_window_load(Window *window) {
  window_set_background_color(window, GColorBlack);
 
  ecliptic_layer = layer_create(GRect(0, 0, 144, 168));
  layer_set_update_proc(ecliptic_layer, ecliptic_layer_draw);
  layer_add_child(window_get_root_layer(window), ecliptic_layer);
  
  
#ifdef PBL_BW  
  time_layer_create(window);
  date_layer_create(window);
  sb_layer_create(window);
  inverter_layer = inverter_layer_create(GRect((screen == screen_black) ? 144 : 0, 0, 144, 168));
  layer_add_child(window_get_root_layer(window), inverter_layer_get_layer(inverter_layer));
#endif
  planets_layer_create(window);
#ifdef PBL_COLOR  
  time_layer_create(window);
  date_layer_create(window);
  sb_layer_create(window);
#endif
  Tuplet tuples[] = {
    TupletInteger(setting_screen, screen),
    TupletInteger(setting_vibrate_hourly, vibrate_hourly),
    TupletInteger(setting_vibrate_disconnected, vibrate_disconnected),
    TupletInteger(setting_flip_horizontally, flip_horizontally)
  };
  app_message_open(160, 160);
  app_sync_init(&app, buffer, sizeof(buffer), tuples, ARRAY_LENGTH(tuples),
                tuple_changed_callback, app_error_callback, NULL);
  
     
  update_date_time(NULL);
  battery_handler(battery_state_service_peek());
  connection_handler(bluetooth_connection_service_peek());  
  
  
}

static void main_window_unload(Window *window) {
  #ifdef PBL_BW
  inverter_layer_destroy(inverter_layer);
  #endif
  text_layer_destroy(s_time_layer);
  layer_destroy(s_sb_layer);
  text_layer_destroy(s_date_layer);
  layer_destroy(s_planets_layer);
  layer_destroy(ecliptic_layer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_date_time(tick_time);
  layer_mark_dirty(window_get_root_layer(s_main_window));
  //  check for hourly vibration notification
  if ((vibrate_hourly == vibrate_hourly_yes) && (units_changed & HOUR_UNIT)) {
    vibes_short_pulse();
  }
}

static void init() {
  // Load settings from storage:
  
  screen = persist_exists(SCREEN_STYLE_PKEY) ? persist_read_int(SCREEN_STYLE_PKEY) : 0;
  vibrate_hourly = persist_exists(VIBRATE_HOURLY_PKEY) ? persist_read_int(VIBRATE_HOURLY_PKEY) : 0;
  vibrate_disconnected = persist_exists(VIBRATE_DISCONNECTED_PKEY) ? persist_read_int(VIBRATE_DISCONNECTED_PKEY) : 0;
  flip_horizontally = persist_exists(FLIP_HORIZONTALLY_PKEY) ? persist_read_int(FLIP_HORIZONTALLY_PKEY) : 0;
  
  planets_data = (PlanetsData*)malloc(sizeof(PlanetsData));
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  
  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  battery_state_service_subscribe(battery_handler);
  bluetooth_connection_service_subscribe(connection_handler);
}

static void deinit() {
  //Save settings
  
  persist_write_int(SCREEN_STYLE_PKEY, screen);
  persist_write_int(VIBRATE_HOURLY_PKEY, vibrate_hourly);
  persist_write_int(VIBRATE_DISCONNECTED_PKEY, vibrate_disconnected);
  persist_write_int(FLIP_HORIZONTALLY_PKEY, flip_horizontally);
  
  
  // Destroy Window
  accel_tap_service_unsubscribe();
  tick_timer_service_unsubscribe();
  battery_state_service_unsubscribe();
  bluetooth_connection_service_unsubscribe();
  window_destroy(s_main_window);
  free(planets_data);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
