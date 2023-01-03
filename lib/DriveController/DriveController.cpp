#include "DriveController.h"


DriveController::DriveController() {
      leftMotor = JYQD_MSC(9, 8, 12, false);
      rightMotor = JYQD_MSC(6, 4, 7, true);
}

void DriveController::enable() {
    leftMotor.enable();
    rightMotor.enable();
}

void DriveController::disable() {
    leftMotor.disable();
    rightMotor.disable();
}

void DriveController::setLimit(int limit) {
    leftMotor.setLimit(limit);
    rightMotor.setLimit(limit);
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

    this->leftMotor.setSpeed(lSpeed);
    this->rightMotor.setSpeed(rSpeed);
}

