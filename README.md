# Smart Parking System

An Arduino-based automated parking gate system that detects vehicle presence and parking availability, controlling gate access and providing visual/audio feedback.

## Features

- **Vehicle Detection**: Infrared sensor to detect when a vehicle approaches the gate
- **Parking Status Monitoring**: Light sensor to detect if parking space is available (occupied/vacant)
- **Automated Gate Control**: Servo motor to open and close the parking gate
- **Visual Status Indicator**: RGB LED that displays parking status:
  - **Green**: Parking space is available
  - **Red**: Parking space is occupied
- **Audio Feedback**: Buzzer that sounds when gate opens/closes
- **Serial Monitoring**: Real-time sensor readings via serial port

## Hardware Requirements

- Arduino microcontroller (Uno recommended)
- Servo motor (SG90 or similar)
- Infrared motion/distance sensor
- Light sensor (LDR or similar)
- RGB LED
- Buzzer
- External power supply
- Jumper wires and breadboard

## Pin Configuration

| Component | Pin | Type |
|-----------|-----|------|
| Parking Sensor (IR) | A0 | Analog Input |
| Light Sensor | A1 | Analog Input |
| Power Sensor | A5 | Analog Input |
| Servo Motor | 9 | PWM Output |
| Red LED | 11 | PWM Output |
| Green LED | 5 | PWM Output |
| Blue LED | 6 | PWM Output |
| Buzzer | 8 | Digital Output |

## How It Works

1. **Parking Status Display**: The system continuously monitors the light sensor to determine if the parking space is occupied or available
   - Light value ≥ 850: Space is available (Green LED on)
   - Light value < 850: Space is occupied (Red LED on)

2. **Vehicle Entry**:
   - When a vehicle approaches (parking sensor < 850) AND the space is available (light value ≥ 850):
   - Gate opens smoothly (servo rotates 0° to 90°)
   - Buzzer beeps during gate opening
   - Gate remains open for 4 seconds
   - Gate closes automatically
   - Buzzer beeps during gate closing

3. **Serial Output**: Sensor readings are printed to serial port for monitoring and debugging

## Installation

1. Connect all components according to the pin configuration above
2. Upload the `smart_parking.ino` sketch to your Arduino
3. Open the Serial Monitor (9600 baud) to view sensor readings
4. Adjust sensor thresholds (850) based on your specific sensors if needed

## Sensor Calibration

You may need to adjust the threshold value (850) in the code based on your specific sensors:
- Read the serial output with different conditions
- Modify the threshold in the conditional statements if needed

## License

This project is open source and available for educational and personal use.
