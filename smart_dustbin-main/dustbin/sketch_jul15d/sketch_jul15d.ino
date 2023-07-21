#include <Servo.h>

const int irPin = 2;            // IR sensor pin
const int moisturePin = 3;     // Moisture sensor analog pin
const int servoPin = 8;         // Servo motor pin

Servo servo;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(moisturePin, INPUT);
  servo.attach(servoPin);
  servo.write(90);
}

void loop() {
  // Check if an object is detected by the IR sensor
  if (digitalRead(irPin) == HIGH) {
    // Read moisture sensor value
//    int moistureValue = digitalRead(moisturePin);
delay(1500);
    // Check moisture level
    if (digitalRead(moisturePin) == HIGH) {
      // More wet condition
      servo.write(65);      // Rotate servo to 0 degrees
      delay(1000);              // Delay for 1 second
      servo.write(90);     // Rotate servo back to 90 degrees
      delay(1000);              // Delay for 1 second
    } else {
      // Less wet conditionx
      servo.write(180);    // Rotate servo to 180 degrees
      delay(1000);              // Delay for 1 second
      servo.write(90);     // Rotate servo back to 90 degrees
      delay(1000);              // Delay for 1 second
    }
  }
}
