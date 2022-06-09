#include <Arduino.h>

#define Sensor_chama 32

void setup() {
  // Na função serial o baud rate funciona melhor em 115200
  // Para isso necessitamos alterar o ficheiro platformio.ini
  // Acrescentando a seguinte linha:
  // monitor_speed = 115200 
  Serial.begin(115200);
  pinMode(Sensor_chama, INPUT);
}

void loop() {
  int val = digitalRead(Sensor_chama);
  Serial.println(val);
  delay(200);
}