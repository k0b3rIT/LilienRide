#include "ODrive.h"

ODrive::ODrive(int rxpin, int txpin):
    rxpin(rxpin),
    txpin(txpin),
    serial(rxpin, txpin),
    odrive(serial)
{}

void ODrive::init() {
    serial.begin(115200);
    odrive.SetVelocity(0, 0);
    odrive.SetVelocity(1, 0);
    odrive.run_state(0, AXIS_STATE_CLOSED_LOOP_CONTROL, false, 1);
    odrive.run_state(1, AXIS_STATE_CLOSED_LOOP_CONTROL, false, 1);
}

void ODrive::setSpeed(int lsp, int rsp) {
    int lspeed = lsp;

    if (lspeed > 100) {
        lspeed = 100;
    }
    if (lspeed < -100) {
        lspeed = -100;
    }

    int rspeed = rsp;

    if (rspeed > 100) {
        rspeed = 100;
    }
    if (rspeed < -100) {
        rspeed = -100;
    }

    int powerLimit = int(400 * (this->limit/100.0));

    odrive.SetVelocity(0, map(lspeed, 0, 100, 0, powerLimit) / 100.0 * -1);
    odrive.SetVelocity(1, map(rspeed, 0, 100, 0, powerLimit) / 100.0);
}

void ODrive::setLimit(int limit) {
    this->limit = limit;
}

ODrive::~ODrive() {
	// TODO Auto-generated destructor stub
}