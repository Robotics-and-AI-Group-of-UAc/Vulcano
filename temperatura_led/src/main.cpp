#include <Arduino.h>
#include "Adafruit_MLX90614.h"

#define LED 15
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(115200);  
  pinMode(LED, OUTPUT);
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };  
}

void loop() {
  float ObjTemp = mlx.readObjectTempC();
  if(ObjTemp > 30){
    digitalWrite(LED, 1);
  }else{
    digitalWrite(LED, 0);
  }
}