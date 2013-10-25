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

AP_RangeFinder_MaxsonarI2CXL::AP_RangeFinder_HC-SR04( FilterInt16 *filter ) :
    RangeFinder(NULL, filter),
    healthy(true),
{
    min_distance = AP_RANGE_FINDER_HC-SR04_MIN_DISTANCE;
    max_distance = AP_RANGE_FINDER_HC-SR04_MAX_DISTANCE;
}

// Public Methods //////////////////////////////////////////////////////////////

// read - return last value measured by sensor
int AP_RangeFinder_HC-SR04::read()
{
    long duration, inches, cm;

    hal.gpio->pinMode(trigPin, OUTPUT);
    hal.gpio->write(trigPin, LOW);
    delayMicroseconds(2);
    hal.gpip->write(trigPin, HIGH);
    delayMicroseconds(10);
    hal.gpio->write(trigPin, LOW);

    hal.gpio->pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
 
    // convert the time into a distance
    cm = microsecondsToCentimeters(duration);
    
    return cm
}
