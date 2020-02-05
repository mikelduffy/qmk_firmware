#ifndef ERGOBT_H
#define ERGOBT_H

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2c_master.h"
#include <util/delay.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

// I2C aliases and register addresses (see "mcp23018.md")
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern i2c_status_t mcp23018_status;
#define ERGOBT_I2C_TIMEOUT 100

void init_ergodox(void);
void ergodox_blink_all_leds(void);
uint8_t init_mcp23018(void);
uint8_t ergodox_left_leds_update(void);

#ifndef LED_BRIGHTNESS_LO
#define LED_BRIGHTNESS_LO       15
#endif
#ifndef LED_BRIGHTNESS_HI
#define LED_BRIGHTNESS_HI       255
#endif

bool ergodox_left_led_1;         // left top
bool ergodox_left_led_2;         // left middle
bool ergodox_left_led_3;         // left bottom

inline void ergodox_left_led_1_on(void)     { ergodox_left_led_1 = 1; }
inline void ergodox_left_led_2_on(void)     { ergodox_left_led_2 = 1; }
inline void ergodox_left_led_3_on(void)     { ergodox_left_led_3 = 1; }

inline void ergodox_left_led_1_off(void)    { ergodox_left_led_1 = 0; }
inline void ergodox_left_led_2_off(void)    { ergodox_left_led_2 = 0; }
inline void ergodox_left_led_3_off(void)    { ergodox_left_led_3 = 0; }

inline void ergodox_led_all_on(void)
{
  ergodox_left_led_1_on();
  ergodox_left_led_2_on();
  ergodox_left_led_3_on();
  ergodox_left_leds_update();
}

inline void ergodox_led_all_off(void)
{
  ergodox_left_led_1_off();
  ergodox_left_led_2_off();
  ergodox_left_led_3_off();
  ergodox_left_leds_update();
}

#define LAYOUT(                               \
                                                            \
    /* left hand, spatial positions */        \
    k00,k01,k02,k03,k04,k05,k06,         \
    k10,k11,k12,k13,k14,k15,k16,          \
    k20,k21,k22,k23,k24,k25, k26,         \
    k30,k31,k32,k33,k34,k35,                 \
    k40,k41,k42,k43,k44,                        \
                                      k45, k36,         \
             /* Thumb Cluster */  k46,         \
                               k54,k55, k56,          \
                                                              \
    /* right hand, spatial positions */        \
        k60,k61,k62,k63,k64,k65,k66,     \
        k70,k71,k72,k73,k74,k75,k76,     \
        k80,k81,k82,k83,k84,k85,k86,     \
               k91,k92,k93,k94,k95,k96,     \
                      kA2,kA3,kA4,kA5,kA6,     \
        k90,kA1,                                          \
        kA0,  /* Thumb Cluster */                \
        kB6,kB5,kB4 )                                  \
                                                                \
   /* matrix positions */                              \
   /* Columns are mirrored to make wiring easier */ \
   {                                                            \
      { k06, k05, k04, k03, k02, k01, k00 },   \
      { k16, k15, k14, k13, k12, k11, k10 },   \
      { k26, k25, k24, k23, k22, k21, k20 },   \
      { k36, k35, k34, k33, k32, k31, k30 },   \
      { k46, k45, k44, k43, k42, k41, k40 },          \
      { k56, k55, k54, KC_NO, KC_NO, KC_NO, KC_NO },          \
      \
      { k66, k65, k64, k63, k62, k61, k60},\
      { k76, k75, k74, k73, k72, k71, k70},\
      { k86, k85, k84, k83, k82, k81, k80},\
      { k96, k95, k94, k93, k92, k91, k90},\
      { kA6, kA5, kA4, kA3, kA2, kA1, kA0},\
      { KC_NO, KC_NO, KC_NO, KC_NO, kB4, kB5, kB6}\
   }

#endif
