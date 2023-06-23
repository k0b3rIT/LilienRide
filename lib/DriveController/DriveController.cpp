#include "DriveController.h"
#include <ODrive.h>


DriveController::DriveController():
 odrive(8, 9)
{}

void DriveController::enable() {
    odrive.init();
}

void DriveController::disable() {
    // leftMotor.disable();
    // rightMotor.disable();
}

void DriveController::setLimit(int limit) {
    odrive.setLimit(limit);
}

void DriveController::applyThrust(int forwardBackward, int leftRight) {

    int lSpeed = forwardBackward;
    int rSpeed = forwardBackward;

    int absLRSpeed = abs(leftRight);

    if (leftRight > 0) {
        rSpeed += absLRSpeed;
        // lSpeed -= absLRSpeed/2;
    } else {
        // rSpeed -= absLRSpeed/2;
        lSpeed += absLRSpeed;
    }

    int rangeMax = 100;
    int rangeMin = -100;

    int max = max(lSpeed, rSpeed);
    if (max > rangeMax) {
        rangeMax = max;
    }

    int min = min(lSpeed, rSpeed);
    if (min < rangeMin) {
        rangeMin = min;
    }

    lSpeed = map(lSpeed, rangeMin, rangeMax, -100, 100);
    rSpeed = map(rSpeed, rangeMin, rangeMax, -100, 100);

    String a;
    a += lSpeed;
    a += " ";
    a += rSpeed;
    // Serial.println(a);

    // this->leftMotor.setSpeed(lSpeed);
    // this->rightMotor.setSpeed(rSpeed);
    this->odrive.setSpeed(lSpeed, rSpeed);
}

