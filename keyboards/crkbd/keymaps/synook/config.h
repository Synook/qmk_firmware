#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING_PER_KEY


#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
#   define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    undef ENABLE_RGB_MATRIX_BREATHING
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_VAL
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    undef ENABLE_RGB_MATRIX_CYCLE_ALL
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    undef ENABLE_RGB_MATRIX_DUAL_BEACON
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    undef ENABLE_RGB_MATRIX_RAINDROPS
#    undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    undef ENABLE_RGB_MATRIX_SPLASH
#    undef ENABLE_RGB_MATRIX_MULTISPLASH
#   define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#define OLED_TIMEOUT 30000

// Space saving
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT
