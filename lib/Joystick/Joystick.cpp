/*
 * Joystick.cpp
 *
 *  Created on: 2016. okt. 20.
 *      Author: Berco
 */

#include <Joystick.h>


Joystick::Joystick(int forwardPin, int backwardPin, int leftPin, int rightPin) {
	this->forwardPin = forwardPin;
	this->backwardPin = backwardPin;
	this->leftPin = leftPin;
	this->rightPin = rightPin;
   	pinMode(forwardPin, INPUT_PULLUP);
    pinMode(backwardPin, INPUT_PULLUP);
    pinMode(leftPin, INPUT_PULLUP);
    pinMode(rightPin, INPUT_PULLUP);
}


double* Joystick::getValues() {
	state[0] = !digitalRead(forwardPin);
	state[1] = !digitalRead(backwardPin);
	state[2] = !digitalRead(leftPin);
	state[3] = !digitalRead(rightPin);
	return state;
}



Joystick::~Joystick() {
	// TODO Auto-generated destructor stub
}
