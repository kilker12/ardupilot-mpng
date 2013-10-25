// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef __AP_RANGEFINDER_HC-SR04_H__
#define __AP_RANGEFINDER_HC-SR04_H__

#include "RangeFinder.h"

#define AP_RANGE_FINDER_HC-SR04_DEFAULT_ADDR   0x70

#define AP_RANGEFINDER_HC-SR04               5
#define AP_RANGE_FINDER_HC-SR04_MIN_DISTANCE  5
#define AP_RANGE_FINDER_HC-SR04_MAX_DISTANCE  200

class AP_RangeFinder_HC-SR04 : public RangeFinder
{

public:

    // constructor
    AP_RangeFinder_HC-SR04(FilterInt16 *filter);

    // read value from sensor and return distance in cm
    int             read();

    // heath
    bool            healthy;

protected:
    uint8_t _addr;

};
#endif  // __AP_RANGEFINDER_HC-SR04_H__
