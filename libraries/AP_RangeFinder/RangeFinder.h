#ifndef __RANGEFINDER_H__
#define __RANGEFINDER_H__

#include <AP_Common.h>
#include <AP_HAL.h>
#include <Filter.h> // Filter library

/*
 * #define AP_RANGEFINDER_ORIENTATION_FRONT		  0, 10,  0
 * #define AP_RANGEFINDER_ORIENTATION_RIGHT		-10,  0,  0
 * #define AP_RANGEFINDER_ORIENTATION_BACK			  0,-10,  0
 * #define AP_RANGEFINDER_ORIENTATION_LEFT			 10,  0,  0
 * #define AP_RANGEFINDER_ORIENTATION_UP			  0,  0,-10
 * #define AP_RANGEFINDER_ORIENTATION_DOWN			  0,  0, 10
 * #define AP_RANGEFINDER_ORIENTATION_FRONT_RIGHT    -5, -5,  0
 * #define AP_RANGEFINDER_ORIENTATION_BACK_RIGHT     -5, -5,  0
 * #define AP_RANGEFINDER_ORIENTATION_BACK_LEFT       5, -5,  0
 * #define AP_RANGEFINDER_ORIENTATION_FRONT_LEFT      5,  5,  0
 */

class AP_RangeFinder
{
    public:
    virtual float read(void) = 0;
};
#endif // __RANGEFINDER_H__
