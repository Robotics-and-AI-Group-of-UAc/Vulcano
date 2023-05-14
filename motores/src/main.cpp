#include <Arduino.h>
#include "ESP32MotorControl.h"

// Motor Pins
#define IN1 27
#define IN2 26
#define IN3 18
#define IN4 17

int velD = 30; // Velocidade motor direito
int velE = 30; // velocidade motor esquerdo

// MotorControl instance
ESP32MotorControl MotorControl = ESP32MotorControl();

void robotFwd() {
    MotorControl.motorForward(0, velE);
    MotorControl.motorForward(1, velD);
}

void robotRev() {
    MotorControl.motorReverse(0, velE);
    MotorControl.motorReverse(1, velD);
}

void robotStop() {
    MotorControl.motorsStop();
}

void setup() {
    Serial.begin(115200);
    pinMode(sensors[0], INPUT);
    pinMode(sensors[1], INPUT);
    pinMode(sensors[2], INPUT);
    // Attach 2 motors
    MotorControl.attachMotors(IN1, IN2, IN3, IN4, 1000);
}

void loop() {
    robotFwd();
    delay(1000);
    robotStop();
    delay(1000);
    robotRev();
    delay(1000);
    robotStop();
    delay(1000);
}