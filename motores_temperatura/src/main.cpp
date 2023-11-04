#include "Adafruit_MLX90614.h"
#include "ESP32MotorControl.h"
#include <Arduino.h>

// Instância do sensor de temperatura
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// Inicialização dos motores
ESP32MotorControl MotorControl = ESP32MotorControl();

unsigned long previousMillis = 0;
float objTemp = 0;

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
    Serial.begin(115200);
    // while (!Serial){Serial.println("Error serial");}

    if (!mlx.begin()) {
        Serial.println("Error connecting to MLX sensor. Check wiring.");
        // Se não houver ligação paramos aqui
        while (1)
            ;
    };
    // 17,18,26,27 pinos dos motores no ESP32
    // correspondentes aos motores esquerdos e direitos
    MotorControl.attachMotors(17, 18, 26, 27);
    delay(200);
}

void loop() {
    // Exemplo - o robo vai em frente até encontrar
    // um objecto com temperatura maior que 22º
    // nessa altura para durante 5 segundos

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 200) {        
        previousMillis = currentMillis;
        objTemp = mlx.readObjectTempC();
        Serial.println(objTemp);
    }
    
    if (objTemp > 22) {
        robot_stop();
        delay(5000);
        robot_forward(50, 50);
    } else {
        robot_forward(50, 50);
    }
}
