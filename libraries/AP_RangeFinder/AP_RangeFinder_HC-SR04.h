// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include "AnalogSource.h"
#include <inttypes.h>

class AP_RangeFinder_HC-SR04 : public AP_RangeFinder_HC-SR04
{
    public:
    AP_RangeFinder_HC-SR04() {
            first_call = 1;
    }
    float read(void);
    void init(void);
    
    private:
    int first_call;
};
