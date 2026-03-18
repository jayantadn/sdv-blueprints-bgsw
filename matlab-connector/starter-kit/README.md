<<<<<<< HEAD
# MATLAB External Mode - Haptic Force Controller Starter Kit
=======
>>>>>>> c53c1b3bf0e093ebcaed6406f6916306a48ad361

## Overview
- This example demonstrates the implementation of the control of smart actuators (SW on the Central Computer) in Simulink as a variant of the haptic force controller based on the "MiX / Digital.auto StarterKit Demonstrator" (see https://github.boschdevcloud.com/bios-integration-of-xDomain-systems).
- The motor position setpoint for the right motor is provided as a parameter. The left motor is synchronized with the actual position of the right motor.
- The Central Computer, on which the application is deployed using the MATLAB external mode, communicates with the zone microcontrollers using UDP/IP. The SW runs in a cyclic 1 ms process.
- The serializer and deserializer are taken over from https://github.boschdevcloud.com/bios-integration-of-xDomain-systems/ros2_haptic_force_controller and are integrated in Simulink using the "C Caller" block, the UDP/IP communication is implemented in C++ and integrated in Simulink using the "C Caller" block as well (see source and header files in ./src directory of the project).


<<<<<<< HEAD
## Run the Example
- 0. Prerequesit: "MiX / Digital.auto StarterKit Demonstrator" set-up deployed on hardware.
- 1. Open the project and update the external mode configuration.
- 2. Click on the shortcut "Open Model" and start the external mode in Simulink (HARDWARE Tab -> Monitor & Tune).
- 3. Enable the controllers by setting the parameter "flag_enable_controller" to 1. Change the motor angle setpoint by setting the parameter "Angle_setpoint_right". Tune the parameters of the 2DOF PID controllers during runtime.
=======
## Architecture
* **Logic Layer (Simulink):** Generates standard C++ code from the `.slx` model.
* **Connector Layer (Custom Code):** Utilizes `da_connector.c` and `client.cpp` to interface the Simulink execution step with the gRPC framework.
* **Transport Layer (gRPC/Protobuf):** Communicates with the Kuksa Databroker using standard VSS (Vehicle Signal Specification) protobuf definitions.
* **Dependencies:** Uses pre-compiled, portable Raspberry Pi binaries (`rpi_libs`) linked dynamically via Simulink's `$(START_DIR)` token, ensuring the project builds immediately upon cloning without complex path configuration.

## Getting Started

### Prerequisites
1. **Hardware:** The use case is tested on a **Raspberry Pi 5** running the Legacy OS.
2. **Host Software:** MATLAB (Tested on R2025b) with the **Simulink Support Package for Raspberry Pi Hardware** installed.

### 1. Clone the Repository
Clone this repository to your local host machine. Because the project utilizes relative paths, you can place the cloned folder anywhere on your system.

### 2. Sync Protobuf Headers to the Target (Crucial Step)
MATLAB's automatic file sync mechanism deploys `.cpp` files but often ignores directory structures containing header (`.h`) files. Before building, you must manually sync the `local/protogen` directory to the target Raspberry Pi.

Open a terminal or PowerShell on your host machine and run the following command (replace `<pi_username>`, `<pi_ip_address>`, and `<Path_To_Your_Cloned_Repo>` with your actual details):

```bash
scp -r .\local <pi_username>@<pi_ip_address>:/home/<pi_username>/MATLAB_ws/R2025b/C/<Path_To_Your_Cloned_Repo>/matlab-connector/
```
*(Example: `scp -r .\local mseti@192.168.88.17:/home/mseti/MATLAB_ws/R2025b/C/Users/GXC2KOR/Desktop/check/sdv-blueprints-fork/matlab-connector/`)*

### 3. Build and Deploy
1. Open the Simulink model (`hapticForceCtrlr_hack.slx`) in MATLAB.
2. Navigate to **Hardware** -> **Hardware Settings** and verify the Raspberry Pi IP address and credentials.
3. Click **Build, Deploy & Start**. The build process will automatically link the provided `rpi_libs` and compile the executable on the Pi.

## digital.auto Playgrounds Runtime Setup
To execute the **Smart Wipers with Starter Kit** prototype and enable the physical motor control runtime on the Raspberry Pi, you must run the initialization script on the Pi hardware.

1. Copy the repository contents to the guest folder `$HOME/digital.auto` on the Raspberry Pi.
2. Execute the setup script to initialize the Kuksa databroker and the motor control runtime:
```bash
$HOME/digital.auto/scripts/setup_rpi.sh
```

## Trial build for host machine
If you wish to compile or test the gRPC components locally on a Debian/Ubuntu host machine rather than deploying via Simulink, install the standard development packages:

```bash
sudo apt install -y libgrpc++-dev libprotobuf-dev protobuf-compiler protobuf-compiler-grpc pkg-config
```
```
>>>>>>> c53c1b3bf0e093ebcaed6406f6916306a48ad361
