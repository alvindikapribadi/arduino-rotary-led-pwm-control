/*
===========================================================
PROJECT TITLE  : Arduino Rotary Encoder + LED PWM Control
DESCRIPTION    :
Control LED brightness using a rotary encoder.
Rotate clockwise to increase brightness.
Rotate counterclockwise to decrease brightness.

This project demonstrates how to combine
Rotary Encoder input with PWM LED output.

-----------------------------------------------------------
COMPONENTS :
- Arduino Uno
- Rotary Encoder (CLK, DT, SW)
- LED
- Resistor 220 ohm
- Breadboard
- Jumper wires

-----------------------------------------------------------
WIRING CONNECTION :

ROTARY ENCODER
- CLK  -> Pin 2
- DT   -> Pin 3
- SW   -> Not used (optional)
- +    -> 5V
- GND  -> GND

LED
- LED Positive (Anode) -> Pin 9
- LED Negative (Cathode) -> Resistor 220 ohm -> GND

===========================================================
*/

#define CLK 2
#define DT 3
#define LED_PIN 9

int brightness = 0;        // LED brightness value (0-255)
int lastCLKState;
int currentCLKState;

void setup() {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(LED_PIN, OUTPUT);

  lastCLKState = digitalRead(CLK);
}

void loop() {

  currentCLKState = digitalRead(CLK);

  // Detect rotation
  if (currentCLKState != lastCLKState) {

    if (digitalRead(DT) != currentCLKState) {
      brightness += 5;   // Clockwise
    } else {
      brightness -= 5;   // Counterclockwise
    }

    // Limit brightness value between 0 - 255
    brightness = constrain(brightness, 0, 255);

    analogWrite(LED_PIN, brightness);
  }

  lastCLKState = currentCLKState;
}
