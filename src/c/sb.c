#include <pebble.h>
  
static Layer *s_sb_layer;
static uint8_t charge_percent;
static bool is_charging;
static bool is_connected;
static const int sb_layer_size_x = 32; 


static void sb_layer_update(Layer *layer, GContext *ctx) {
  #ifdef PBL_COLOR
  graphics_context_set_antialiased(ctx, false);
  #endif
  graphics_context_set_stroke_color(ctx, GColorWhite);
  graphics_context_set_fill_color(ctx, GColorWhite);
  int right_indent = 0;
  if (is_charging) {
    // draw charge icon
    right_indent += 7;
    GBitmap *charge_bitmap;
    charge_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CHARGE);
    graphics_draw_bitmap_in_rect(ctx, charge_bitmap, GRect(sb_layer_size_x - right_indent, 0, 5, 7));
    gbitmap_destroy(charge_bitmap);
  }
  // draw battery
  right_indent += 18;  
  graphics_draw_rect(ctx, GRect(sb_layer_size_x - right_indent, 0, 14, 7));
  graphics_draw_rect(ctx, GRect(sb_layer_size_x - right_indent + 14, 2, 2, 3));
  graphics_fill_rect(ctx, GRect(sb_layer_size_x - right_indent + 2, 2, charge_percent/10, 3), 0, GCornerNone);
  if (is_connected) {
    // draw bluetooth icon
    right_indent += 9;
    GBitmap *connection_bitmap;
    connection_bitmap = gbitmap_create_with_resource(RESOURCE_ID_BT);
    graphics_draw_bitmap_in_rect(ctx, connection_bitmap, GRect(sb_layer_size_x - right_indent, 0, 5, 7));
    gbitmap_destroy(connection_bitmap);
  }
 
}

static void sb_layer_create(Window *window) {
  s_sb_layer = layer_create(GRect(110, 2, sb_layer_size_x, 7));
  layer_set_update_proc(s_sb_layer, sb_layer_update);
  layer_set_clips(s_sb_layer, false);
  layer_add_child(window_get_root_layer(window), s_sb_layer);
}

static void battery_handler(BatteryChargeState charge_state) {
  charge_percent = charge_state.charge_percent;
  is_charging = charge_state.is_charging;
  layer_mark_dirty(s_sb_layer);
}


