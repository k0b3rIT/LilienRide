/*
 * ODrive.h
 *
 *  Created on: 2016. okt. 20.
 *      Author: Berco
 */

#ifndef LIB_ODrive_H_
#define LIB_ODrive_H_

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <ODriveArduino.h>

class ODrive {
public:
	ODrive(int rxpin, int txpin);
	virtual ~ODrive();
	void init();
	void setSpeed(int lspeed, int rspeed);
	void setLimit(int limit);

private:
	int rxpin;
	int txpin;
	int limit;
	SoftwareSerial serial;
	ODriveArduino odrive;
};

#endif /* LIB_ODrive_H_ */
