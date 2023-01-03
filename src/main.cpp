#include <Arduino.h>
#include <Encoder.h>
#include <DriveController.h>
#include <Transmitter.h>
#include <Joystick.h>
#include <Wire.h>


const int FW_BW = 6;
const int LE_RI = 5;
const int SW = 1;

const int MAX_WITH_JOY = 25;

Transmitter transmitter;
Joystick joystick(10,2,3,11);
DriveController driveController;


void setup() {
  Serial.begin(9600);
  driveController.setLimit(50);
  driveController.applyThrust(0, 0);
  driveController.enable();

  Serial.println("start");


      // pinMode(4, OUTPUT);
    // pinMode(6, OUTPUT);
    // pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  // digitalWrite(4, HIGH);
  // analogWrite(6, map(60, 0, 100, 0, 255));
  // digitalWrite(7, HIGH);

    transmitter.refreshValues();
    double* joystickState = joystick.getValues();

    String a;
	  a += joystickState[0];
    a += " ";
    a += joystickState[1];
    a += " ";
    a += joystickState[2];
    a += " ";
    a += joystickState[3];
    // Serial.println(a);
    

    uint16_t* values = transmitter.getValues();

    int forwardBackward = 0;
    int leftRight = 0;


    if (values != NULL) {
      if (values[SW] < 1800) {
        forwardBackward = (int)map(values[FW_BW], 1050, 1890, -100, 100);
        leftRight = (int)map(values[LE_RI], 1050, 1890, -100, 100) * -1;
      } else {
        int fwbw = 0;
        if (joystickState[0] == 1) {
          fwbw = 1;
        } else if (joystickState[1] == 1) {
          fwbw = -1;
        }
        int lr = 0;
        if (joystickState[2] == 1) {
          lr = 1;
        } else if (joystickState[3] == 1) {
          lr = -1;
        }
        forwardBackward = map(fwbw, -1, 1, MAX_WITH_JOY * -1, MAX_WITH_JOY);
        leftRight = map(lr, -1, 1, MAX_WITH_JOY * -1, MAX_WITH_JOY);
      }
     
    }

    driveController.applyThrust(forwardBackward, leftRight);

}