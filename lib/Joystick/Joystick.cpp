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
   	pinMode(forwardPin, INPUT);
    pinMode(backwardPin, INPUT);
    pinMode(leftPin, INPUT);
    pinMode(rightPin, INPUT);
}


double* Joystick::getValues() {
	state[0] = digitalRead(forwardPin);
	state[1] = digitalRead(backwardPin);
	state[2] = digitalRead(leftPin);
	state[3] = digitalRead(rightPin);
	return state;
}



Joystick::~Joystick() {
	// TODO Auto-generated destructor stub
}
