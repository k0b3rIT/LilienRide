/*
 * Joystick.h
 *
 *  Created on: 2016. okt. 20.
 *      Author: Berco
 */

#ifndef LIB_Joystick_H_
#define LIB_Joystick_H_

#include <Arduino.h>
#include <Wire.h>

class Joystick {
public:
	Joystick(int forwardPin, int backwardPin, int leftPin, int rightPin);
	virtual ~Joystick();
	double* getValues();

private:
	int forwardPin;
	int backwardPin;
	int leftPin;
	int rightPin;
	double state[4];
};

#endif /* LIB_Joystick_H_ */
