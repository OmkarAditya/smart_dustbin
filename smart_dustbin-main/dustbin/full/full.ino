#include <SoftwareSerial.h>

const int triggerPin1 = 2;  // Trigger pin for sensor 1
const int echoPin1 = 3;     // Echo pin for sensor 1
const int triggerPin2 = 4;  // Trigger pin for sensor 2
const int echoPin2 = 5;     // Echo pin for sensor 2
const int thresholdDistance = 5;  // Distance threshold in centimeters


void setup() {
  Serial.begin(9600);
  pinMode(triggerPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  int distance1 = measureDistance(triggerPin1, echoPin1);
  int distance2 = measureDistance(triggerPin2, echoPin2);

  if (distance1 < thresholdDistance) {
    Serial.println("Dustbin 1 is full");
  }

  if (distance2 < thresholdDistance) {
    Serial.println("Dustbin 2 is full");
  }

  delay(1000);  // Wait for 1 second before taking the next measurement
}

int measureDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  // Calculate distance in centimeters
  Serial.println(distance);
  return distance;
}
