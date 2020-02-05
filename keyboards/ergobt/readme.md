# Keyboard Description
These keyboard firmware files were based off of the ErgoDox EZ that is distributed with the QMK firmware. Left hand LED code adapted from cub-uanic's TMK ErgoDox firmware.

# Hardware
* Teensy 2.0 ATMEGA32U4
* Micro USB breakout board

# Power
Switch positions:
* Off Unattached – No power to keyboard. Bluetooth off. No battery drain.
* Off Attached – USB keyboard. Battery charging. Bluetooth off.
* On Unattached – Bluetooth on. Battery draining.
* On Attached – ??? Battery charging. Battery draining. Bluetooth on. USB keyboard. ???

# Hand Wiring
The custom layout is a 12 rows x 7 columns matrix for 38 keys on each hand (see row/col layout below). Diodes were soldered on the rows. The columns on the I/O expander hand have been reversed to assist with less overlapping wiring.

* + indicates connected pin
* o indicates unconnected pin
* = is used to list other things the pin is connected to
* -s inserted between some of the pin functions for readability



### Teensy  Wiring
         power_negative GND +---..............---+ Vcc power_positive
                          row_6  PB0 +                     + PF0  column_0
                          row_7  PB1 +                     + PF1  column_1
                          row_8  PB2 +                     + PF4  column_2
                          row_9  PB3 +    o        o     + PF5  column_3
                                      PB7 o PE6  AREF + PF6  column_4
                    (SCL)   I2C  PD0 +                     + PF7  column_5
                  (SDA)   I2C  PD1 +                     + PB6  column_6
                          BT TX  PD2 +                     o PB5
                          BT RX  PD3 +                     + PB4  = Vcc
                         row_0A  PC6 +                     o PD7
                         row_0B  PC7   +-o-o-o-o-o-+   PD6  onboardLED = GND
                                          PD5 --/   |  |  |   \-- PD4
                                          Vcc -----/    |   \---- RST
                                          GND-------/

### MCP23018 Wiring
        power_negative  Vss(GND) +01---.---28o NC
                                               NC o02       27+ GPA7   LED2
                     column_6      GPB0 +03       26+ GPA6   LED1
                     column_5      GPB1 +04       25+ GPA5   row_5
                     column_4      GPB2 +05       24+ GPA4   row_4
                     column_3      GPB3 +06       23+ GPA3   row_3
                     column_2      GPB4 +07       22+ GPA2   row_2
                     column_1      GPB5 +08       21+ GPA1   row_1
                     column_0      GPB6 o09       20+ GPA0   row_0
                           LED3       GPB7 +10       19o INTA
                             VCC  Vdd(Vcc) +11       18o INTB
    VCC 2.2k resistor I2C       SCL +12       17o NC
    VCC 2.2k resistor I2C       SDA +13       16+ RESET  = Vdd(Vcc)
                                                NC o14------15+ ADDR    = Vss(GND)

### TTRS Connector Wiring
Leads facing up.
                                          input
    power_negative (GND) x   x power_positive (VCC)
                                              x SCL
                                  SDA x

### Row Pin Configuration
 * Teensy
 * row: 6    7     8    9    10   11
 * pin: B0  B1  B2  B3  C6  C7

 * MCP23018
 * row: 0     1    2    3     4    5
 * pin: A0  A1  A2  A3  A4  A5

### Column Pin Configuration
* Teensy
  * col:  0    1     2    3    4     5    6
  * pin: F0  F1  F4  F5  F6  F7  B6

* MCP23018
  * col:  0    1     2     3    4    5     6
  * pin: B0  B1  B2  B3  B4  B5  B6

# Todo
  1. Integrate RN42 Bluetooth code from HHKB
  2. Diagonal mouse keys
  3. Add decoupling capacitor connected to Vcc and GND on the MCP23018

# Misc Notes
* Lines 80 and 90 of bt_ergodox.c were edited to allow an extra column
* LEDs wired with pull up resistors connnected to Vcc and ground connected to pins GPA6, GPA7, and GPB7.

## Finding the keycodes you need
Let's say you want a certain key in your layout to send a colon; to figure out what keycode to use to make it do that, you're going to need `quantum/keymap_common.h`. That file contains a big list of all of the special, fancy keys (like, being able to send % on its own and whatnot). If you want to send a plain vanilla key, you can look up its code under `doc/keycode.txt`. That's where all the boring keys hang out.
