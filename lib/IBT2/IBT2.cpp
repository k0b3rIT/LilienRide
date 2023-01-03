#include "IBT2.h"


IBT2::IBT2(){
    
}

IBT2::IBT2(int L_pwm, int R_pwm) {
    _L_pwm = L_pwm;
    _R_pwm = R_pwm;

    pinMode(_L_pwm, OUTPUT);
    pinMode(_R_pwm, OUTPUT);
}


void IBT2::setSpeed(int sp) {
    int speed = sp;

    if (speed > 100) {
        speed = 100;
    }
    if (speed < -100) {
        speed = -100;
    }

    if (speed >= 0) {
        analogWrite(_L_pwm, map(speed, 0, 100, 0, 255));
        digitalWrite(_R_pwm, LOW);
    } else {
        analogWrite(_R_pwm, map(abs(speed), 0, 100, 0, 255));
        digitalWrite(_L_pwm, LOW);
    }
}
