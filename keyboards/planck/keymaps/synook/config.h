#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(COLEMAK_SOUND), \
          SONG(QWERTY_SOUND), \
          SONG(DVORAK_SOUND), \
          SONG(DVORAK_SOUND), \
          SONG(DVORAK_SOUND), \
          SONG(DVORAK_SOUND), \
          SONG(DVORAK_SOUND), \
          SONG(WORKMAN_SOUND), \
        }
#endif

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
#define MIDI_BASIC

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// Tap-hold settings
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING_PER_KEY

