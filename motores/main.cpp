#include <Arduino.h>
#include "ESP32MotorControl.h"

// Inicialização dos motores
ESP32MotorControl MotorControl = ESP32MotorControl();

void setup() {
  // 17,18,26,27 pinos dos motores no ESP32 
  // correspondentes aos motores esquerdos e direitos
  MotorControl.attachMotors(17, 18, 27, 26);
}

void loop() {  
  MotorControl.motorForwardLeft(20);
  MotorControl.motorForwardRight(20);
  delay(5000);
  MotorControl.motorReverseLeft(20);
  MotorControl.motorReverseRight(20);
  delay(5000); 
  MotorControl.motorSTOP(0);
  MotorControl.motorSTOP(1);
  delay(5000);
}
