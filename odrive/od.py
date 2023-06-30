import odrive
from odrive.enums import *


odrv0 = odrive.find_any()

odrv0.axis0.motor.config.pole_pairs = 15

odrv0.axis0.motor.config.resistance_calib_max_voltage = 4
odrv0.axis0.motor.config.requested_current_range = 25
odrv0.axis0.motor.config.current_control_bandwidth = 100
odrv0.axis0.motor.config.torque_constant = 8.27 / 16


odrv0.axis0.encoder.config.mode = EncoderMode.HALL
odrv0.axis0.encoder.config.cpr = 90
odrv0.axis0.encoder.config.calib_scan_distance = 150
odrv0.config.gpio9_mode = GpioMode.DIGITAL
odrv0.config.gpio10_mode = GpioMode.DIGITAL
odrv0.config.gpio11_mode = GpioMode.DIGITAL

odrv0.axis0.encoder.config.bandwidth = 100
odrv0.axis0.controller.config.pos_gain = 1
odrv0.axis0.controller.config.vel_gain = 0.02 * odrv0.axis0.motor.config.torque_constant * odrv0.axis0.encoder.config.cpr
odrv0.axis0.controller.config.vel_integrator_gain = 0.1 * odrv0.axis0.motor.config.torque_constant * odrv0.axis0.encoder.config.cpr
odrv0.axis0.controller.config.vel_limit = 10
odrv0.axis0.controller.config.control_mode = ControlMode.VELOCITY_CONTROL

# axis1

odrv0.axis1.motor.config.pole_pairs = 15

odrv0.axis1.motor.config.resistance_calib_max_voltage = 4
odrv0.axis1.motor.config.requested_current_range = 25
odrv0.axis1.motor.config.current_control_bandwidth = 100
odrv0.axis1.motor.config.torque_constant = 8.27 / 16

odrv0.axis1.encoder.config.mode = EncoderMode.HALL
odrv0.axis1.encoder.config.cpr = 90
odrv0.axis1.encoder.config.calib_scan_distance = 150
odrv0.config.gpio12_mode = GpioMode.DIGITAL
odrv0.config.gpio13_mode = GpioMode.DIGITAL
odrv0.config.gpio14_mode = GpioMode.DIGITAL

odrv0.axis1.encoder.config.bandwidth = 100
odrv0.axis1.controller.config.pos_gain = 1
odrv0.axis1.controller.config.vel_gain = 0.02 * odrv0.axis1.motor.config.torque_constant * odrv0.axis1.encoder.config.cpr
odrv0.axis1.controller.config.vel_integrator_gain = 0.1 * odrv0.axis1.motor.config.torque_constant * odrv0.axis1.encoder.config.cpr
odrv0.axis1.controller.config.vel_limit = 10
odrv0.axis1.controller.config.control_mode = ControlMode.VELOCITY_CONTROL


odrv0.axis0.requested_state = AxisState.MOTOR_CALIBRATION

# axis1

odrv0.axis1.requested_state = AxisState.MOTOR_CALIBRATION
