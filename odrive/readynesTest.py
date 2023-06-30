import sys
import time

import odrive
from odrive.enums import *

dev0 = odrive.find_any()


def readyness():
    print('======= ERRORS ========')
    print(f"dev0.error: {dev0.error}")
    print(f"dev0.axis0.error: {dev0.axis0.error}")
    print(f"dev0.axis1.error: {dev0.axis1.error}")
    print(f"dev0.axis0.motor.error: {dev0.axis0.motor.error}")
    print(f"dev0.axis1.motor.error: {dev0.axis1.motor.error}")
    print(f"dev0.axis0.encoder.error: {dev0.axis0.encoder.error}")
    print(f"dev0.axis1.encoder.error: {dev0.axis1.encoder.error}")

    print('====== CALIB STATE ========')
    print(f"dev0.axis0.encoder.config.pre_calibrated: {dev0.axis0.encoder.config.pre_calibrated}")
    print(f"dev0.axis1.encoder.config.pre_calibrated: {dev0.axis1.encoder.config.pre_calibrated}")
    print(f"dev0.axis0.encoder.is_ready: {dev0.axis0.encoder.is_ready}")
    print(f"dev0.axis1.encoder.is_ready: {dev0.axis1.encoder.is_ready}")
    print(f"dev0.axis0.motor.config.pre_calibrated: {dev0.axis0.motor.config.pre_calibrated}")
    print(f"dev0.axis1.motor.config.pre_calibrated: {dev0.axis1.motor.config.pre_calibrated}")
    print(f"dev0.axis0.motor.is_calibrated: {dev0.axis0.motor.is_calibrated}")
    print(f"dev0.axis1.motor.is_calibrated: {dev0.axis1.motor.is_calibrated}")

    print('====== ARM STATE ========')
    print(f"dev0.axis0.motor.is_armed: {dev0.axis0.motor.is_armed}")
    print(f"dev0.axis1.motor.is_armed: {dev0.axis1.motor.is_armed}")

    print('======= MODES ========')
    print(f"dev0.axis0.current_state: {dev0.axis0.current_state}")
    print(f"dev0.axis1.current_state: {dev0.axis1.current_state}")
    print(f"dev0.axis0.controller.config.control_mode: {dev0.axis0.controller.config.control_mode}")
    print(f"dev0.axis1.controller.config.control_mode: {dev0.axis1.controller.config.control_mode}")

def configs():
    print('====== AXIS0 ========')
    print(f"dev0.axis0.motor.config.pole_pairs: {dev0.axis0.motor.config.pole_pairs}")
    print(f"dev0.axis0.motor.config.resistance_calib_max_voltage: {dev0.axis0.motor.config.resistance_calib_max_voltage}")
    print(f"dev0.axis0.motor.config.requested_current_range: {dev0.axis0.motor.config.requested_current_range}")
    print(f"dev0.axis0.motor.config.current_control_bandwidth: {dev0.axis0.motor.config.current_control_bandwidth}")
    print(f"dev0.axis0.motor.config.torque_constant: {dev0.axis0.motor.config.torque_constant}")
    print(f"dev0.axis0.encoder.config.mode: {dev0.axis0.encoder.config.mode}")
    print(f"dev0.axis0.encoder.config.cpr: {dev0.axis0.encoder.config.cpr}")
    print(f"dev0.axis0.encoder.config.calib_scan_distance: {dev0.axis0.encoder.config.calib_scan_distance}")
    print(f"dev0.config.gpio9_mode: {dev0.config.gpio9_mode}")
    print(f"dev0.config.gpio10_mode:  {dev0.config.gpio10_mode}")
    print(f"dev0.config.gpio11_mode: {dev0.config.gpio11_mode}")
    print(f"dev0.axis0.encoder.config.bandwidth: {dev0.axis0.encoder.config.bandwidth}")
    print(f"dev0.axis0.controller.config.pos_gain: {dev0.axis0.controller.config.pos_gain}")
    print(f"dev0.axis0.controller.config.vel_gain: {dev0.axis0.controller.config.vel_gain}")
    print(f"dev0.axis0.controller.config.vel_integrator_gain: {dev0.axis0.controller.config.vel_integrator_gain}")
    print(f"dev0.axis0.controller.config.vel_limit: {dev0.axis0.controller.config.vel_limit}")

    print('====== AXIS1 ========')
    print(f"dev0.axis1.motor.config.pole_pairs: {dev0.axis1.motor.config.pole_pairs}")
    print(f"dev0.axis1.motor.config.resistance_calib_max_voltage: {dev0.axis1.motor.config.resistance_calib_max_voltage}")
    print(f"dev0.axis1.motor.config.requested_current_range: {dev0.axis1.motor.config.requested_current_range}")
    print(f"dev0.axis1.motor.config.current_control_bandwidth: {dev0.axis1.motor.config.current_control_bandwidth}")
    print(f"dev0.axis1.motor.config.torque_constant: {dev0.axis1.motor.config.torque_constant}")
    print(f"dev0.axis1.encoder.config.mode: {dev0.axis1.encoder.config.mode}")
    print(f"dev0.axis1.encoder.config.cpr: {dev0.axis1.encoder.config.cpr}")
    print(f"dev0.axis1.encoder.config.calib_scan_distance: {dev0.axis1.encoder.config.calib_scan_distance}")
    print(f"dev0.config.gpio12_mode: {dev0.config.gpio12_mode}")
    print(f"dev0.config.gpio13_mode:  {dev0.config.gpio13_mode}")
    print(f"dev0.config.gpio14_mode: {dev0.config.gpio14_mode}")
    print(f"dev0.axis1.encoder.config.bandwidth: {dev0.axis1.encoder.config.bandwidth}")
    print(f"dev0.axis1.controller.config.pos_gain: {dev0.axis1.controller.config.pos_gain}")
    print(f"dev0.axis1.controller.config.vel_gain: {dev0.axis1.controller.config.vel_gain}")
    print(f"dev0.axis1.controller.config.vel_integrator_gain: {dev0.axis1.controller.config.vel_integrator_gain}")
    print(f"dev0.axis1.controller.config.vel_limit: {dev0.axis1.controller.config.vel_limit}")

def calibration():

    print("Motor calibration")

    dev0.axis0.requested_state = AxisState.MOTOR_CALIBRATION
    dev0.axis1.requested_state = AxisState.MOTOR_CALIBRATION

    time.sleep(6)

    print(f"dev0.axis0.motor.error {dev0.axis0.motor.error}")
    print(f"dev0.axis1.motor.error {dev0.axis1.motor.error}")

    print("Encoder hall polarity calibration")

    dev0.axis0.requested_state = AxisState.ENCODER_HALL_POLARITY_CALIBRATION

    time.sleep(10)

    dev0.axis1.requested_state = AxisState.ENCODER_HALL_POLARITY_CALIBRATION

    time.sleep(10)

    print(f"dev0.axis0.encoder.error {dev0.axis0.encoder.error}")
    print(f"dev0.axis1.encoder.error {dev0.axis1.encoder.error}")

    print("Encoder offset calibration")

    dev0.axis0.requested_state = AxisState.ENCODER_OFFSET_CALIBRATION
    dev0.axis1.requested_state = AxisState.ENCODER_OFFSET_CALIBRATION

    time.sleep(10)

    print(f"dev0.axis0.encoder.error {dev0.axis0.encoder.error}")
    print(f"dev0.axis1.encoder.error {dev0.axis1.encoder.error}")

    # dev0.axis0.requested_state = AxisState.FULL_CALIBRATION_SEQUENCE
    # dev0.axis1.requested_state = AxisState.FULL_CALIBRATION_SEQUENCE

def saveState():
    dev0.save_configuration()

def start():
    dev0.axis0.requested_state = AxisState.CLOSED_LOOP_CONTROL
    dev0.axis1.requested_state = AxisState.CLOSED_LOOP_CONTROL

def setSpeed(speed):
    dev0.axis0.controller.input_vel = speed
    dev0.axis1.controller.input_vel = speed

def reboot():
    dev0.reboot()

def errors():
    odrive.dump_errors(dev0)


def main(argv):
    # print(argv)
    # print('ok')
    if (len(argv) < 2):
        raise Exception("Invalid param length")

    if (argv[1] == 'readyness'):
        readyness()

    if (argv[1] == 'configs'):
        configs()

    if (argv[1] == 'calibration'):
        calibration()

    if (argv[1] == 'save'):
        saveState()

    if (argv[1] == 'start'):
        start()

    if (argv[1] == 'speed'):
        setSpeed(argv[2])

    if (argv[1] == 'reboot'):
        reboot()
    if (argv[1] == 'errors'):
        errors()


if __name__ == '__main__':
    main(sys.argv)