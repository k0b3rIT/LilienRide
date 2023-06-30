### Check the errors, readyness
```
python readynessTest.py readyness
```

on odirve you can execute the `dev0.dump_errors()` for text based error messages

### Make sure both axis is calibrated and using the appropriate control modes
```
dev0.axis0.encoder.config.pre_calibrated = True
dev0.axis0.current_state = 8 //AXIS_STATE_CLOSED_LOOP_CONTROL
dev0.axis0.controller.config.control_mode = 2 //CONTROL_MODE_VELOCITY_CONTROL

```

### If you change any of the wires, do a motor and encoder recalibration