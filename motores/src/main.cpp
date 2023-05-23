#include "ESP32MotorControl.h"
#include <Arduino.h>

// Inicialização dos motores
ESP32MotorControl MotorControl = ESP32MotorControl();

/* Nas seguintes funções assumimos que:
** Motor esquerdo - 0
** Motor direito - 1
*/
void robot_forward(int speedLeft, int speedRight) {
    MotorControl.motorForward(0, speedLeft);
    MotorControl.motorForward(1, speedRight);
}
void robot_reverse(int speedLeft, int speedRight) {
    MotorControl.motorReverse(0, speedLeft);
    MotorControl.motorReverse(1, speedRight);
}
void robot_turn_left(int speedLeft, int speedRight) {
    MotorControl.motorForward(1, speedRight);
    MotorControl.motorReverse(0, speedLeft);
}
void robot_turn_right(int speedLeft, int speedRight) {
    MotorControl.motorForward(0, speedLeft);
    MotorControl.motorReverse(1, speedRight);
}
void robot_stop() {
    MotorControl.motorStop(0);
    MotorControl.motorStop(1);
}

void setup() {
    // 17,18,26,27 pinos dos motores no ESP32
    // correspondentes aos motores esquerdos e direitos
    MotorControl.attachMotors(17, 18, 26, 27);
}

void loop() {
    robot_forward(50,50);
    delay(5000);
    robot_turn_left(50,50);
    delay(5000);
    robot_turn_right(50,50);
    delay(5000);
    robot_stop();
    delay(2000);
}
