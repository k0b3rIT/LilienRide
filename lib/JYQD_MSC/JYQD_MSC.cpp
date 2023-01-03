#include "JYQD_MSC.h"


JYQD_MSC::JYQD_MSC(){
    
}

JYQD_MSC::JYQD_MSC(int speedPin, int directionPin, int enablePin, boolean reverse) {
    this->speedPin = speedPin;
    this->directionPin = directionPin;
    this->enablePin = enablePin;

    if (reverse) {
        this->forward = 0;
        this->backward = 1;
    } else {
        this->forward = 1;
        this->backward = 0;
    }

    pinMode(enablePin, OUTPUT);
    pinMode(speedPin, OUTPUT);
    pinMode(directionPin, OUTPUT);
}

void JYQD_MSC::enable() {
    digitalWrite(enablePin, HIGH);
}

void JYQD_MSC::disable() {
    digitalWrite(enablePin, LOW);
}

void JYQD_MSC::setLimit(int limit) {
    this->limit = limit;
}

void JYQD_MSC::setSpeed(int sp) {
    int speed = sp;

    if (speed > 100) {
        speed = 100;
    }
    if (speed < -100) {
        speed = -100;
    }

    int powerLimit = int(255 * (this->limit/100.0));

    if (speed >= 0) {
        analogWrite(speedPin, map(speed, 0, 100, 0, powerLimit));
        digitalWrite(directionPin, this->forward);
    } else {
        analogWrite(speedPin, map(abs(speed), 0, 100, 0, powerLimit));
        digitalWrite(directionPin, this->backward);
    }
}
