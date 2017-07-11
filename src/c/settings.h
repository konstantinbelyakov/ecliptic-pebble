#include <pebble.h>
  
#define SCREEN_STYLE_PKEY 1
#define VIBRATE_HOURLY_PKEY 2
#define VIBRATE_DISCONNECTED_PKEY 3
#define FLIP_HORIZONTALLY_PKEY 4
  
enum Settings { setting_screen = 1, setting_vibrate_hourly, setting_vibrate_disconnected, setting_flip_horizontally };

static enum SettingScreen { screen_black = 0, screen_white, screen_count } screen;
static enum SettingVibrateHourly { vibrate_hourly_no = 0, vibrate_hourly_yes, vibrate_hourly_count } vibrate_hourly;
static enum SettingVibrateDisconnected { vibrate_disconnected_no = 0, vibrate_disconnected_yes, vibrate_disconnected_count } vibrate_disconnected;
static enum SettingFlipHorizontally { flip_horizontally_no = 0, flip_horizontally_yes, flip_horizontally_count } flip_horizontally;