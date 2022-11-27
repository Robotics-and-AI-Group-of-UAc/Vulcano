#include <Arduino.h>
#include "ESP32MotorControl.h"

// Motor control Class initialization
ESP32MotorControl MotorControl = ESP32MotorControl();

void setup() {
  // 17,18,26,27 ESP32 motor pins
  // 17,18->Left; 26,27->Right
  MotorControl.attachMotors(17, 18, 27, 26);
}

void loop() {  
  // motor ForwardLeft/Right(speed)
  MotorControl.motorForwardLeft(20);
  MotorControl.motorForwardRight(20);
  delay(5000);
  // motor ReverseLeft/Right(speed)
  MotorControl.motorReverseLeft(20);
  MotorControl.motorReverseRight(20);
  delay(5000); 
  //motor STOP(0-Left; 1-Right)
  MotorControl.motorSTOP(0);
  MotorControl.motorSTOP(1);
  delay(5000);
}
