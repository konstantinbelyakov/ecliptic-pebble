#include <pebble.h>
#include "colordefs.h"

static TextLayer *s_time_layer;
  
static TextLayer *s_date_layer;

static char date_text[] = "Wednesday AM\n\r\n\r\n\rSeptember 03\n\r2014";

static char time_text[] = "00:00";  

static void date_layer_create(Window *window) {
  s_date_layer = text_layer_create(GRect(0, 40, 144, 90));
  text_layer_set_background_color(s_date_layer, GColorClear);
  text_layer_set_text_color(s_date_layer, GColorWhite);
  text_layer_set_font(s_date_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_date_layer));
}

static void time_layer_create(Window *window) {
  s_time_layer = text_layer_create(GRect(0, 52, 144, 44));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, TIME_COLOR);
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
}

static void update_date_time(struct tm* pbltime) {
  time_t now;
  if (pbltime == NULL) {
    now = time(NULL);
    pbltime = localtime(&now);
  }
  if(clock_is_24h_style()) {
    strftime(time_text, sizeof(time_text), "%H:%M", pbltime);
    strftime(date_text, sizeof(date_text), "%A\n\r\n\r\n\r%B %d\n\r%Y", pbltime);
  }
  else {
    strftime(time_text, sizeof(time_text), "%l:%M", pbltime);
    if (time_text[0] == ' ') memmove(time_text, &time_text[1], sizeof(time_text) - 1);
    strftime(date_text, sizeof(date_text), "%A %p\n\r\n\r\n\r%B %d\n\r%Y", pbltime);
  }
  text_layer_set_text(s_time_layer, time_text);
  text_layer_set_text(s_date_layer, date_text);  
}
