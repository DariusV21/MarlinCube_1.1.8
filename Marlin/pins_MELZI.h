/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Melzi pin assignments
 */

#define BOARD_NAME "Melzi"
//#define IS_MELZI
//#include "pins_SANGUINOLOLU_12.h"

//#ifndef __AVR_ATmega1284P__
  //#define __AVR_ATmega1284P__
#define LARGE_FLASH true
#define SANGUINOLOLU_V_1_2

// Limit Switches
#define X_STOP_PIN        18
#define Y_STOP_PIN        19
#define Z_STOP_PIN        20

// Steppers
#define X_STEP_PIN        15
#define X_DIR_PIN         21
#define Y_STEP_PIN        22
#define Y_DIR_PIN         23
#define Z_STEP_PIN        3
#define Z_DIR_PIN         2
#define E0_STEP_PIN       1
#define E0_DIR_PIN        0

// Temperature Sensors
#define TEMP_0_PIN        7   // Analog Input (pin 33 extruder)
#define TEMP_BED_PIN      6   // Analog Input (pin 34 bed)

// Heaters / Fans
#define HEATER_0_PIN      13 // (extruder)
#define HEATER_BED_PIN    12 // (bed)
#define FAN_PIN           4

#define X_ENABLE_PIN     14
#define Y_ENABLE_PIN     14
#define Z_ENABLE_PIN     26
#define E0_ENABLE_PIN    14

/**
 * On some broken versions of the Sanguino libraries the pin definitions are wrong,
 * which then needs SDSS as pin 24 and LED_PIN may also needs to be 28. But you should upgrade your Sanguino libraries! See #368.
 */
//#define SDSS        24
#define SDSS          29 // ckmod was 31
#define LED_PIN       27

// LCD / Controller
#if ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL)
  #if ENABLED(DOGLCD)
    #if ENABLED(U8GLIB_ST7920)  // SPI GLCD 12864 ST7920 [Digiole.com] Melzi V2.0
        #define LCD_PINS_RS     28 // ckmod orig 30 // CS chip select /SS chip slave select
        #define LCD_PINS_ENABLE 17 // ckmod orig 29 // SID (MOSI)
        #define LCD_PINS_D4     30 // ckmod LCD_RW? // SCK (CLK) clock
        #define BEEPER_PIN      27
    #else // DOGM SPI LCD Support
        #define DOGLCD_A0         30
        #define LCD_CONTRAST       1
          #if ENABLED(MAKRPANEL)
            #define BEEPER_PIN      27
            #define DOGLCD_CS       28 // ckmod
            #define LCD_BACKLIGHT_PIN 28 // PA3
          #else // Not MAKRPANEL
            #define DOGLCD_CS       28 // ckmod
          #endif
    #endif
  #define LCD_SCREEN_ROT_0 // Or... //#define LCD_SCREEN_ROT_90 //#define LCD_SCREEN_ROT_180 //#define LCD_SCREEN_ROT_270
  #endif // !DOGLCD
#define BTN_EN1               11
#define BTN_EN2               10
#define BTN_ENC               16 //ckmod
#define SD_DETECT_PIN         -1 // Doesn't appear connected on my board!
#endif // ULTRA_LCD && NEWPANEL
