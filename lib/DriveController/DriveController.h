#include <Arduino.h>
#include <JYQD_MSC.h>

#ifndef DriveController_H
#define DriveController_H

class DriveController {
    public:
    DriveController();
    void setLimit(int limit);
    void applyThrust(int forwardBackward, int leftRight);
    void enable();
    void disable();
    private:
    JYQD_MSC leftMotor;
    JYQD_MSC rightMotor;
};

#endif