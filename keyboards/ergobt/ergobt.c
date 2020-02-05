#include QMK_KEYBOARD_H

extern inline void ergodox_left_led_1_off(void);
extern inline void ergodox_left_led_2_off(void);
extern inline void ergodox_left_led_3_off(void);
extern inline void ergodox_led_all_on(void);
extern inline void ergodox_led_all_off(void);

bool i2c_initialized = 0;
i2c_status_t mcp23018_status = 0x20;

void matrix_init_kb(void) {
    // (tied to Vcc for hardware convenience)
    DDRB  &= ~(1<<4);  // set B(4) as input
    PORTB &= ~(1<<4);  // set B(4) internal pull-up disabled

    // unused pins - D4, D5, D7, E6, B5, B7
    // set as input with internal pull-ip enabled
    DDRD  &= ~(1<<7 | 1<<5 | 1<<4);
    DDRE  &= ~(1<<6);
    DDRB  &= ~(1<<7 | 1<<5);
    PORTD |=  (1<<7 | 1<<5 | 1<<4);
    PORTE |=  (1<<6);
    PORTB |=  (1<<7 | 1<<5);

    ergodox_blink_all_leds();

    matrix_init_user();
}

void ergodox_blink_all_leds(void)
{
    // ergodox_led_all_off();

    // ergodox_left_led_1_on();
    // _delay_ms(50);
    // if (!mcp23018_status) {
    //   mcp23018_status = ergodox_left_leds_update();
    // }
    // ergodox_left_led_2_on();
    // _delay_ms(50);
    // if (!mcp23018_status) {
    //   mcp23018_status = ergodox_left_leds_update();
    // }
    // ergodox_left_led_3_on();
    // _delay_ms(50);
    // if (!mcp23018_status) {
    //   mcp23018_status = ergodox_left_leds_update();
    // }
    // _delay_ms(50);
    // ergodox_left_led_1_off();
    // if (!mcp23018_status) {
    //   mcp23018_status = ergodox_left_leds_update();
    // }
    // _delay_ms(50);
    // ergodox_left_led_2_off();
    // if (!mcp23018_status) {
    //   mcp23018_status = ergodox_left_leds_update();
    // }
    // _delay_ms(50);
    // ergodox_left_led_3_off();
    // if (!mcp23018_status) {
    //   mcp23018_status = ergodox_left_leds_update();
    // }

    ergodox_led_all_off();
}

uint8_t init_mcp23018(void) {
    mcp23018_status = 0x20;

    // I2C subsystem
    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        _delay_ms(1000);
    }

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, ERGOBT_I2C_TIMEOUT);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(IODIRA, ERGOBT_I2C_TIMEOUT);            if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000, ERGOBT_I2C_TIMEOUT);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b01111111, ERGOBT_I2C_TIMEOUT);        if (mcp23018_status) goto out;
    i2c_stop();

    // set pull-up
    // - unused  : on  : 1
    // - input   : on  : 1
    // - driving : off : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, ERGOBT_I2C_TIMEOUT);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(GPPUA, ERGOBT_I2C_TIMEOUT);             if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000, ERGOBT_I2C_TIMEOUT);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b01111111, ERGOBT_I2C_TIMEOUT);        if (mcp23018_status) goto out;

out:
    i2c_stop();

    if (!mcp23018_status) mcp23018_status = ergodox_left_leds_update();

    return mcp23018_status;
}

uint8_t ergodox_left_leds_update(void) {
    if (mcp23018_status) { // if there was an error
        return mcp23018_status;
    }

    #define LEFT_LED_1_SHIFT        6       // in MCP23018 port A6
    #define LEFT_LED_2_SHIFT        7       // in MCP23018 port A7
    #define LEFT_LED_3_SHIFT        7       // in MCP23018 port B7

    // set logical value (doesn't matter on inputs)
    // - unused  : hi-Z : 1
    // - input   : hi-Z : 1
    // - driving : hi-Z : 1
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, ERGOBT_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(OLATA, ERGOBT_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111111
                                & ~(ergodox_left_led_1<<LEFT_LED_1_SHIFT)
                                & ~(ergodox_left_led_2<<LEFT_LED_2_SHIFT),
                                ERGOBT_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111111
                                & ~(ergodox_left_led_3<<LEFT_LED_3_SHIFT),
                                ERGOBT_I2C_TIMEOUT);
    if (mcp23018_status) goto out;

out:
    i2c_stop();
    return mcp23018_status;
}
