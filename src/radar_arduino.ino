/*
  ============================================================
  Automated Ultrasonic Radar - Arduino Side
  Microcontroller: Arduino Uno
  Components      : HC-SR04 Ultrasonic Sensor, SG90 Servo Motor
  Output         : Serial data to Processing IDE (radar display)
  ============================================================

  PIN CONNECTIONS:
  ----------------
  HC-SR04:
    TRIG -> Pin 10
    ECHO -> Pin 11
    VCC  -> 5V
    GND  -> GND

  Servo Motor (SG90):
    Signal -> Pin 12
    VCC    -> 5V
    GND    -> GND
*/

#include <Servo.h>

// ---- Pin Definitions ----
#define TRIG_PIN  10
#define ECHO_PIN  11
#define SERVO_PIN 12

Servo radarServo;
int angle       = 0;
int sweepStep   = 1;   // 1 = forward, -1 = backward

// ============================================================
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  radarServo.attach(SERVO_PIN);
  radarServo.write(0);
  delay(500);
}

// ============================================================
void loop() {
  // Sweep servo from 0 to 180 and back
  for (angle = 15; angle <= 165; angle++) {
    radarServo.write(angle);
    delay(30);
    int distance = measureDistance();
    // Send angle and distance to Processing via Serial
    // Format: "angle,distance."
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  for (angle = 165; angle > 15; angle--) {
    radarServo.write(angle);
    delay(30);
    int distance = measureDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// ============================================================
// Measure distance using HC-SR04
int measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance  = duration * 0.034 / 2;  // Convert to cm

  // Cap at 40 cm max range
  if (distance > 40) distance = 40;
  return distance;
}
