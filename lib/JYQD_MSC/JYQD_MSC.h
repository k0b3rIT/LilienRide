#include <Arduino.h>

#ifndef JYQD_MSC_H
#define JYQD_MSC_H

class JYQD_MSC {
    public:
    int speedPin;  // Attribute
    int directionPin;  // Attribute
    int enablePin;
    int forward;
    int backward;
    int limit = 100;
    JYQD_MSC(int speedPin, int directionPin, int enablePin, boolean reverse);
    JYQD_MSC();

    void setLimit(int limit);
    void setSpeed(int speed);
    void enable();
    void disable();
};

#endif