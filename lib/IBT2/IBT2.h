#include <Arduino.h>

#ifndef IBT2_H
#define IBT2_H

class IBT2 {
    public:
    int _L_pwm;  // Attribute
    int _R_pwm;  // Attribute
    IBT2(int L_pwm, int R_pwm);
    IBT2();

    void setSpeed(int speed);
};

#endif