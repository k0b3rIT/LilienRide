/*
 * Transmitter.cpp
 *
 *  Created on: 2016. okt. 20.
 *      Author: Berco
 */

#include <Transmitter.h>


Transmitter::Transmitter() {
	this->i2cWire.begin();
}

void Transmitter::refreshValues() {
	uint8_t buffer[NUMBER_OF_TRANSMITTER_CHANNELS*2];
	i2cRead(I2C_ADDRESS_OF_CONVERTER, NUMBER_OF_TRANSMITTER_CHANNELS*2, buffer);
	trasmitter[0] = ((uint16_t)buffer[0]) | (((uint16_t)buffer[1]) << 8);
	trasmitter[1] = ((uint16_t)buffer[2]) | (((uint16_t)buffer[3]) << 8);
	trasmitter[2] = ((uint16_t)buffer[4]) | (((uint16_t)buffer[5]) << 8);
	trasmitter[3] = ((uint16_t)buffer[6]) | (((uint16_t)buffer[7]) << 8);
	trasmitter[4] = ((uint16_t)buffer[8]) | (((uint16_t)buffer[9]) << 8);
	trasmitter[5] = ((uint16_t)buffer[10]) | (((uint16_t)buffer[11]) << 8);
	trasmitter[6] = ((uint16_t)buffer[12]) | (((uint16_t)buffer[13]) << 8);
	trasmitter[7] = ((uint16_t)buffer[14]) | (((uint16_t)buffer[15]) << 8);

	if (!isArmed) {
		if (isMovedDown) {
			if (isMovedBackToMiddle) {
				isArmed = true;
			} else {
				if (trasmitter[6] > 1400 && trasmitter[6] < 1500) {
					isMovedBackToMiddle = true;
				}
			}
		} else {
			if (trasmitter[6] > 1000 && trasmitter[6] < 1100) {
				isMovedDown = true;
			}
		}
	}
}

void Transmitter::i2cWrite(uint8_t address, uint8_t registerAddress, uint8_t data) {
	this->i2cWire.beginTransmission(address);
	this->i2cWire.write(registerAddress);
	this->i2cWire.write(data);
	this->i2cWire.endTransmission();
}

void Transmitter::i2cRead(uint8_t address, uint8_t nbytes, uint8_t* buffer) {
	this->i2cWire.beginTransmission(address);
	this->i2cWire.requestFrom(address, nbytes);

	for (uint8_t i = 0; i < nbytes; i++)
		buffer[i] = this->i2cWire.read();

	this->i2cWire.endTransmission();
}


uint16_t* Transmitter::getValues() {

	for (int i = 0; i < NUMBER_OF_TRANSMITTER_CHANNELS; i++) {
				mappedValues[i] = 0;
	}

	String a;
	a += trasmitter[0];
    a += " ";
    a += trasmitter[1];
    a += " ";
    a += trasmitter[2];
    a += " ";
    a += trasmitter[3];
    a += " ";
    a += trasmitter[4];
    a += " ";
    a += trasmitter[5];
    a += " ";
    a += trasmitter[6];
    a += " ";
    a += trasmitter[7];
    // Serial.println(a);
    // Serial.println(values[5]);


	// mappedValues[0] = mapToFullRange(1070, 1900, trasmitter[0], false);
	// mappedValues[1] = mapToFullRange(1070, 1900, trasmitter[1], false);
	// mappedValues[2] = mapToFullRange(1060, 1880, trasmitter[2], false);
	// mappedValues[3] = mapToFullRange(1065, 1910, trasmitter[3], false);
	// mappedValues[4] = mapToFullRange(1047, 1875, trasmitter[4], false);
	// mappedValues[5] = mapToFullRange(1047, 1875, trasmitter[5], false);

	if (isArmed) {
		return trasmitter;
	} else {
		return NULL;
	}


	//CH6 switch purple D9
	//CH5 knob gray
	//ch4 yaw white D6 -> blue
	//ch3 pitch brown -> green
	//ch2 throttle orange D5
	//ch1 roll yellow

	//d3 not working


}

int Transmitter::mapToRange(int pData, int low, int high, int rangeLow, int rangeHigh, bool invert) {
	if (pData == 0) {
		pData = low;
	}
	int data = (int)map(pData, low, high, rangeLow, rangeHigh);
		if (invert)
			data = data * -1;
	return data;
}



int Transmitter::mapToFullRange(int low, int high, int pData, bool invert) {
	if (pData == 0) {
		pData = low;
	}
	int data = (int)map(pData, low, high, -1000, 1000);
		if (invert)
			data = data * -1;
	return data;
}




Transmitter::~Transmitter() {
	// TODO Auto-generated destructor stub
}
