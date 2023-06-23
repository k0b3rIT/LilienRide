#include <Arduino.h>
#include <Encoder.h>
#include <DriveController.h>
#include <Transmitter.h>
#include <Joystick.h>
#include <Wire.h>


const int FW_BW = 6;
const int LE_RI = 5;
const int SW = 1;

const int MAX_WITH_JOY = 20;
const int DEADZONE = 10;

Transmitter transmitter;
Joystick joystick(10,2,3,11);
DriveController driveController;

boolean hadJoyInputInLastLoop;
long lastJoyInputTimestamp;
int lastJoyCtrlValues[2];

void controllByTransmitter(int* ctrlValues, uint16_t* transmitterValues) {
    int val0 = (int)map(transmitterValues[FW_BW], 1050, 1890, -100, 100);
    int val1 = (int)map(transmitterValues[LE_RI], 1050, 1890, -100, 100) * -1;

    if (abs(val0) < DEADZONE) {
      val0 = 0;
    } else {
      if (val0 > 0) {
        val0 = val0 - DEADZONE;
      } else {
        val0 = val0 + DEADZONE;
      }
    }

    if (abs(val1) < DEADZONE) {
      val1 = 0;
    } else {
      if (val1 > 0) {
        val1 = val1 - DEADZONE;
      } else {
        val1 = val1 + DEADZONE;
      }
    }

    ctrlValues[0] = val0;
    ctrlValues[1] = val1;

}

void controllByJoystick(int* ctrlValues, double* joystickState) {
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

    if (!hadJoyInputInLastLoop && (lr !=0 || fwbw != 0)) { //joystick pushed to some direction after a stop
      lastJoyInputTimestamp = millis();
      lastJoyCtrlValues[0] = fwbw;
      lastJoyCtrlValues[1] = lr;
      hadJoyInputInLastLoop = true;
    } else if ((millis() - lastJoyInputTimestamp) < 500) {
      fwbw = lastJoyCtrlValues[0];
      lr = lastJoyCtrlValues[1];
    } else if (lr == 0 && fwbw == 0) { //all zero
      hadJoyInputInLastLoop = false;
    }

    ctrlValues[0] = map(fwbw, -1, 1, MAX_WITH_JOY * -1, MAX_WITH_JOY);
    ctrlValues[1] = map(lr, -1, 1, MAX_WITH_JOY * -1, MAX_WITH_JOY);
}

void setup() {
  Serial.begin(9600);
  driveController.enable();
  driveController.setLimit(50);
  driveController.applyThrust(0, 0);
  
  Serial.println("start");

}

// the loop function runs over and over again forever
void loop() {

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
    
    int ctrlValues[2] = {0, 0};


    if (values != NULL) {
      if (values[SW] < 1800) {
        controllByTransmitter(ctrlValues, values);
      } else {
        controllByJoystick(ctrlValues, joystickState);
      }
    }

    driveController.applyThrust(ctrlValues[0], ctrlValues[1]);

}

