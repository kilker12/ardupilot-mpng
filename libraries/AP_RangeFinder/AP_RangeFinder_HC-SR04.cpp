// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *       AP_RangeFinder_HC-SR04.cpp - Arduino Library for HC-SR04
 *
 *
 *       Variables:
 *               bool healthy : indicates whether last communication with sensor was successful
 *
 *       Methods:
 *               read() : read last distance measured (in cm)
 *
 */

// AVR LibC Includes
#include "AP_RangeFinder_HC-SR04.h"
#include <AP_HAL.h>

extern const AP_HAL::HAL& hal;

// Constructor //////////////////////////////////////////////////////////////

AP_RangeFinder_HC-SR04::AP_RangeFinder_HC-SR04( FilterInt16 *filter ) :
    RangeFinder(NULL, filter),
    healthy(true),
{
    min_distance = AP_RANGE_FINDER_HC-SR04_MIN_DISTANCE;
    max_distance = AP_RANGE_FINDER_HC-SR04_MAX_DISTANCE;
}

// Public Methods //////////////////////////////////////////////////////////////
// init - setup sonar stuffs
void AP_RangeFinder_HC-SR04::init(void)
{
        // Sonar INIT
        //=======================
        PORTH&=B10111111; // H6 -d9  - sonar TX
        DDRH |=B01000000;

        PORTB&=B11101111; // B4 -d10 - sonar Echo
        DDRB &=B11101111;
        
        // Timer5 initialized in APM_RC library
/*
        // div64 = 0.5 us/bit
        // Using timer5, warning! Timer5 also share with RC PPM decoder
        TCCR5A = 0; //standard mode with overflow at A and OC B and C interrupts
        TCCR5B |= (1<<CS11); //Prescaler set to 8, resolution of 0.5us
        TIMSK5 |= B00000111; // ints: overflow, capture, compareA
        OCR5A = 65510; // approx 10m limit, 33ms period
        OCR5B = 3000;*/
}

// read - return last value measured by sensor
float AP_RangeFinder_HC-SR04::read(void)
{
   float result;
   if (((sonar_data < 590) || (sonar_data > 59000)) && (pre_sonar_data > 0) ) {        //value must be 5cm > X < 5m
      if (sonar_error_cnt > 50) {
         result = 65490; // set as maximum value 5.55m - fallback to Baro (in arducopter.pde)
      } else {
         sonar_error_cnt++;
         result = pre_sonar_data; // use previous valid data
      }
   } else {
      sonar_error_cnt = 0; // Valid data received, reset counter
      pre_sonar_data = sonar_data;
      result = sonar_data;
   }
   return(result/118);
}
