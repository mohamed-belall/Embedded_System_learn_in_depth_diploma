# CANoe Accelerator Simulation

This project utilizes Vector CANoe for virtual implementation, featuring two virtual Electronic Control Units (ECUs).



### ECU1
- Periodically monitors the status of the accelerometer to determine whether it is pressed or not. Subsequently, ECU1 transmits this state information to ECU2 via the CAN bus.

### ECU2
- Receives the state information from ECU1 and dynamically adjusts the speed based on the accelerometer's status.


### In this project:<br>
- 🔴 I have developed a database using CANdb to include ECUs, messages, and signals. <br>
- 🔴 Each ECU has a dedicated CAPL script for accurate simulation actions. <br>
- 🔴 Additionally, a user-friendly GUI has been implemented to visualize and interact with the bus data effectively.<br>


