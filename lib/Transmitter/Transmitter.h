/*
 * Transmitter.h
 *
 *  Created on: 2016. okt. 20.
 *      Author: Berco
 */

#ifndef LIB_TRANSMITTER_H_
#define LIB_TRANSMITTER_H_

#include <Arduino.h>
#include <Wire.h>

class Transmitter {
public:
	Transmitter();
	virtual ~Transmitter();
	void refreshValues();
	uint16_t* getValues();

	const int NUMBER_OF_TRANSMITTER_CHANNELS = 8;
	const int I2C_ADDRESS_OF_CONVERTER = 8;

private:
	boolean isArmed = false;
	boolean isMovedBackToMiddle = false;
	boolean isMovedDown = false;
	TwoWire i2cWire;
	uint16_t trasmitter[8];
	uint16_t mappedValues[8];
	int mapToFullRange(int low, int high, int pData, bool invert);
	int mapToRange(int pData, int low, int high, int rangeLow, int rangeHigh, bool invert);
	void i2cWrite(uint8_t address, uint8_t registerAddress, uint8_t data);
	void i2cRead(uint8_t address, uint8_t nbytes, uint8_t* buffer);
};

#endif /* LIB_TRANSMITTER_H_ */
