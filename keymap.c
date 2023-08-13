#include QMK_KEYBOARD_H
//#include "bootloader.h"
//#ifdef PROTOCOL_LUFA
//  #include "lufa.h"
//  #include "split_util.h"
//#endif
//#ifdef SSD1306OLED
//  #include "ssd1306.h"
//#endif
//#include "quantum.h"

//#ifdef RGBLIGHT_ENABLE
////Following line allows macro to read current RGB settings
//extern rgblight_config_t rgblight_config;
//#endif

extern uint8_t is_master;

enum corny_layers {
  _QWERTY,
  _VIM,
  _NUMS,
  _SPECS0,
  _SPECS1,
  _FKEYS,
  _ADJST,
  _BACKLIT,
  _RGBRST
};

enum corny_keycodes {
  QWERTY = SAFE_RANGE,
  VIM,
  NUMS,
  SPECS0,
  SPECS1,
  FKEYS,
  ADJST,
  BACKLIT,
  RGBRST
};

//#define KC______  KC_TRNS
//#define KC_XXXXX KC_NO
//
//#define KC_VIM    VIM
//#define KC_NUMS   NUMS
//#define KC_SPECS0 SPECS0
//#define KC_SPECS1 SPECS1
//#define KC_FKEYS  FKEYS
//#define KC_ADJST  ADJST
//
#define KC_FK_QT  MT(FKEYS, KC_QUOT)
//#define KC_RST    RESET
//#define KC_LRST   RGBRST
//#define KC_LTOG   RGB_TOG
//#define KC_LHUI   RGB_HUI
//#define KC_LHUD   RGB_HUD
//#define KC_LSAI   RGB_SAI
//#define KC_LSAD   RGB_SAD
//#define KC_LVAI   RGB_VAI
//#define KC_LVAD   RGB_VAD
//#define KC_LMOD   RGB_MOD
//
#define KC_CTLW   LCTL(KC_W)
#define KC_ALTF2  LALT(KC_F2)
#define KC_UNDO   LCTL(KC_Z)

#define KC_ALTSL  ALT_T(KC_SLASH)
#define KC_ALTD   ALT_T(KC_D)
#define KC_CTLESC CTL_T(KC_ESC)
#define KC_CTLS   CTL_T(KC_S)
#define KC_CTLX   CTL_T(KC_X)
#define KC_CTLSC  CTL_T(KC_SCLN)
#define KC_SFTA   SFT_T(KC_A)
#define KC_SFTZ   SFT_T(KC_Z)
#define KC_SFTSL  SFT_T(KC_SLSH)
#define KC_WINX   LWIN_T(KC_X)
#define KC_WINDO  RWIN_T(KC_DOT)

//#define KC_MBTN1  MBTN1
//#define KC_SCRL   SCRL


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,     KC_Q,     KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,     ADJST,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_ESC,  KC_SFTA,  KC_CTLS,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN,  KC_FK_QT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_LSFT, KC_SFTZ,  KC_CTLX,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,  KC_COMM, KC_DOT, KC_ALTSL, KC_LCTL,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                    SPECS0,   VIM,   KC_SPC,    SPECS1, NUMS,  QK_LEAD //`--------------------'  `--------------------'
  )
//  ),

//  [_VIM] = LAYOUT(
//  //,-----------------------------------------.                ,-----------------------------------------.
//        TAB, XXXXX,  CTLW,   END, XXXXX, XXXXX,                   COPY,  UNDO, XXXXX,   ENT,  PSTE, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        ESC, XXXXX,   TAB,   CUT,  PGDN,  PGUP,                   LEFT,  DOWN,    UP, RIGHT, ALTF2, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LSFT,  HOME,  BSPC,   DEL, XXXXX, XXXXX,                    TAB, XXXXX, XXXXX, XXXXX,  FIND,  RCTL,
//  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                  XXXXX, XXXXX,   SPC,    XXXXX, XXXXX, XXXXX
//                              //`--------------------'  `--------------------'
//    ),
//
//  [_NUMS] = LAYOUT(
//  //,-----------------------------------------.                ,-----------------------------------------.
//        ESC, XXXXX,     7,     8,     9, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LCTL, XXXXX,     4,     5,     6, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LSFT,     0,     1,     2,     3, XXXXX,                  XXXXX, XXXXX,  COMM,   DOT,  SLSH, XXXXX,
//  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                  XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX
//                              //`--------------------'  `--------------------'
//  ),
//
//  [_SPECS0] = LAYOUT(
//  //,-----------------------------------------.                ,-----------------------------------------.
//        TAB,    AT, XXXXX,  LCBR,  RCBR, XXXXX,                  XXXXX,  UNDS, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        ESC,  HASH,   DLR,  LPRN,  RPRN,   GRV,                   TILD,  AMPR,  PERC,  PIPE,   EQL, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LSFT, XXXXX,  PERC,  LBRC,  RBRC, XXXXX,                  XXXXX, XXXXX,  COMM,   DOT,  BSLS, XXXXX,
//  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                  XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX
//                              //`--------------------'  `--------------------'
//  ),
//
//  [_SPECS1] = LAYOUT(
//  //,-----------------------------------------.                ,-----------------------------------------.
//        TAB,  AMPR, XXXXX,  CIRC,  ASTR,  EXLM,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        ESC,    AT,  AMPR,  MINS,  PLUS,   EQL,                  XXXXX,  MINS,  PLUS,  EXLM, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LSFT, XXXXX,  PERC,  LABK,  RABK,  PIPE,                  XXXXX, XXXXX, XXXXX, XXXXX,  BSLS, XXXXX,
//  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                  XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX
//                              //`--------------------'  `--------------------'
//  ),
//
//  [_FKEYS] = LAYOUT(
//  //,-----------------------------------------.                ,-----------------------------------------.
//        ESC, XXXXX,    F7,    F8,    F9,   F12,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LCTL, XXXXX,    F4,    F5,    F6,   F11,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LSFT, XXXXX,    F1,    F2,    F3,   F10,                  XXXXX, XXXXX,  COMM,   DOT,  SLSH, XXXXX,
//  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                  XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX
//                              //`--------------------'  `--------------------'
//  ),
//
////  [_ADJST] = LAYOUT(
////  //,-----------------------------------------.                ,-----------------------------------------.
////        RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
////  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
////      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXX, XXXXX,          XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
////  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
////      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXX, XXXXX,          XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
////  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
////                                   LGUI,   VIM,   SPC,     ENT,   NUMS,  RALT
////                              //`--------------------'  `--------------------'
////  )
////};
//  [_ADJST] = LAYOUT(
//  //,-----------------------------------------.                ,-----------------------------------------.
//        RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,   RST,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                   LGUI,   VIM,   SPC,      ENT,  NUMS,  RALT
//                              //`--------------------'  `--------------------'
//  )
};


////SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
//#ifdef SSD1306OLED
//
//// When add source files to SRC in rules.mk, you can use functions.
//const char *read_layer_state(void);
//const char *read_logo(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);
//
//// const char *read_mode_icon(bool swap);
//// const char *read_host_led_state(void);
//// void set_timelog(void);
//// const char *read_timelog(void);
//
//LEADER_EXTERNS();
//void matrix_scan_user(void) {
//   iota_gfx_task();
//
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();
//     // Replace the sequences below with your own sequences.
//     SEQ_ONE_KEY(KC_W) {
//       // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
//       SEND_STRING(SS_LCTRL("w"));
//     }
//     // Note: This is not an array, you don't need to put any commas
//     // or semicolons between sequences.
//     SEQ_TWO_KEYS(KC_N, KC_T) {
//       // When I press KC_LEAD and then N followed by T, this sends CTRL + T
//       SEND_STRING(SS_LCTRL("t"));
//     }
//   }
//}
//
//void matrix_render_user(struct CharacterMatrix *matrix) {
//  if (is_master) {
//    // If you want to change the display of OLED, you need to change here
//    matrix_write_ln(matrix, read_layer_state());
//    matrix_write_ln(matrix, read_keylog());
//    //matrix_write_ln(matrix, read_keylogs());
//    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
//    //matrix_write_ln(matrix, read_host_led_state());
//    //matrix_write_ln(matrix, read_timelog());
//  } else {
//    matrix_write(matrix, read_logo());
//  }
//}
//
//void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
//  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
//    memcpy(dest->display, source->display, sizeof(dest->display));
//    dest->dirty = true;
//  }
//}
//
//void iota_gfx_task_user(void) {
//  struct CharacterMatrix matrix;
//  matrix_clear(&matrix);
//  matrix_render_user(&matrix);
//  matrix_update(&display, &matrix);
//}
//#endif//SSD1306OLED

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_get_mode();
    #endif
}

#ifdef OLED_ENABLE

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write(read_layer_state(), false);
    oled_write(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
  return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      //rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 1);
      return false;
    case VIM:
      if (record->event.pressed) {
        layer_on(_VIM);
        update_tri_layer_RGB(_VIM, _NUMS, _ADJST);
      } else {
        layer_off(_VIM);
        update_tri_layer_RGB(_VIM, _NUMS, _ADJST);
      }
      return false;
    case NUMS:
      if (record->event.pressed) {
        layer_on(_NUMS);
        update_tri_layer_RGB(_VIM, _NUMS, _ADJST);
      } else {
        layer_off(_NUMS);
        update_tri_layer_RGB(_VIM, _NUMS, _ADJST);
      }
      return false;
    case SPECS0:
        if (record->event.pressed) {
          layer_on(_SPECS0);
        } else {
          layer_off(_SPECS0);
        }
        return false;
    case SPECS1:
        if (record->event.pressed) {
          layer_on(_SPECS1);
        } else {
          layer_off(_SPECS1);
        }
        return false;
    case FKEYS:
        if (record->event.pressed) {
          layer_on(_FKEYS);
        } else {
          layer_off(_FKEYS);
        }
        return false;
    case ADJST:
        if (record->event.pressed) {
          layer_on(_ADJST);
        } else {
          layer_off(_ADJST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      break;
  }
  return true;
}
