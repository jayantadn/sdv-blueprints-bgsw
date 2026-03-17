# Dreamkit Simulink + KUKSA Integration

This folder contains the current Simulink prototype for pothole hazard detection using:

- a generated model script in `model/PotholeAlert.m`
- C Caller blocks for KUKSA I/O
- a small C bridge in `c_caller/`
- Python socket bridge processes that connect KUKSA to the C code

## Folder Layout

```text
dreamkit/
├── c_caller/
│   ├── kuksa_connector.h
│   ├── kuksa_connector.c
│   ├── pothole_feeder.py
│   ├── steering_feeder.py
│   └── hazard_listener.py
├── model/
│   ├── PotholeAlert.m
│   └── PotholeAlertModel.slx   (generated)
└── README.md
```

## What `PotholeAlert.m` Does

`model/PotholeAlert.m` builds a Simulink model named `PotholeAlertModel` from scratch.

When `USE_KUKSA = true`, the script:

- locates `dreamkit/c_caller`
- configures Simulation Target and Custom Code settings
- adds five C Caller blocks
- wires the hazard logic
- saves and simulates the model

When `USE_KUKSA = false`, the script instead creates test signal sources:

- pulse generators for left / center / right pothole detections
- a sine wave for steering angle
- a terminator for the hazard output

## Current Hazard Logic

The implemented logic matches the script in `model/PotholeAlert.m`:

```text
hazard = (pothole_left  AND steering_angle < -5)
      OR (pothole_right AND steering_angle > +5)
```

Center-lane potholes are logged but do not trigger the hazard signal.

## C Caller Functions

The C API is defined in `c_caller/kuksa_connector.h`.

### Read functions

- `double kuksa_get_pothole_left()`
- `double kuksa_get_pothole_center()`
- `double kuksa_get_pothole_right()`
- `double kuksa_get_steering_angle()`

### Write function

- `void kuksa_set_hazard_signal(bool value)`

The write path now uses `bool`, which matches the logical hazard output in Simulink.

## Runtime Architecture

```text
Simulink model
   │
   ├── C Caller: kuksa_get_pothole_left()
   ├── C Caller: kuksa_get_pothole_center()
   ├── C Caller: kuksa_get_pothole_right()
   ├── C Caller: kuksa_get_steering_angle()
   └── C Caller: kuksa_set_hazard_signal(bool)
            │
            ▼
     c_caller/kuksa_connector.c
            │
            ▼
      Unix domain sockets
            │
            ▼
 Python bridge processes ↔ KUKSA Databroker
```

## Socket Mapping

### Inputs read by the C code

| Function | Socket | Meaning |
|---|---|---|
| `kuksa_get_pothole_left()` | `/tmp/kuksa_pothole_left.sock` | Left-lane pothole present |
| `kuksa_get_pothole_center()` | `/tmp/kuksa_pothole_center.sock` | Center-lane pothole present |
| `kuksa_get_pothole_right()` | `/tmp/kuksa_pothole_right.sock` | Right-lane pothole present |
| `kuksa_get_steering_angle()` | `/tmp/kuksa_steering_angle.sock` | Steering wheel angle |

### Output written by the C code

| Function | Socket | Meaning |
|---|---|---|
| `kuksa_set_hazard_signal(bool)` | `/tmp/kuksa_hazard_signal.sock` | Hazard on/off |

`kuksa_connector.c` writes the hazard signal as the strings `true` or `false`.

## How To Run

### 1. Start the bridge scripts

Run these from `dreamkit/c_caller` on Linux:

```bash
python3 pothole_feeder.py
python3 steering_feeder.py
python3 hazard_listener.py
```

These scripts bridge between KUKSA and the Unix domain sockets used by `kuksa_connector.c`.

### 2. Open MATLAB / Simulink

Open and run:

```matlab
cd('matlab-connector/dreamkit/model')
PotholeAlert
```

### 3. Choose mode in the script

Inside `model/PotholeAlert.m`:

- `USE_KUKSA = true` uses the C Caller integration
- `USE_KUKSA = false` uses synthetic test sources

## Current Simulink Blocks Created by the Script

### Input side

- `pothole_left`
- `pothole_center`
- `pothole_right`
- `steering_angle`

### Logic side

- `steer_left`
- `steer_right`
- `and_left`
- `and_right`
- `or`

### Output side

- `hazard_signal`
- `hazard_out_port`

### Logging side

- `log_pothole_left`
- `log_pothole_center`
- `log_pothole_right`
- `log_steering`
- `hazard_log`

## Summary

Use `model/PotholeAlert.m` as the entry point.

Use `c_caller/kuksa_connector.{h,c}` as the Simulink C interface.

Use the Python scripts in `c_caller/` to bridge KUKSA and the Unix sockets.

If you update the signal interface, keep these in sync:

- `model/PotholeAlert.m`
- `c_caller/kuksa_connector.h`
- `c_caller/kuksa_connector.c`
- the Python bridge scripts
