#include <Arduino.h>
#include "ESP32MotorControl.h"

// Inicialização dos motores
ESP32MotorControl MotorControl = ESP32MotorControl();

void setup() {
  MotorControl.attachMotors(17, 18, 26, 27);
}

void loop() {
  // Mover em frente
  MotorControl.motorForward(0, 50);
  MotorControl.motorForward(1, 50);
  delay(1000);
  // Parar
  MotorControl.motorStop(0);
  MotorControl.motorStop(1);
  delay(200);
  // Recuar
  MotorControl.motorReverse(0, 50);
  MotorControl.motorReverse(1, 50);
  delay(1000);
  // Parar
  MotorControl.motorStop(0);
  MotorControl.motorStop(1);
  delay(200);
}