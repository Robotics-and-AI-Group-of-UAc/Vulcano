#include <Arduino.h>

// Pinos Sensor de cor
#define SENSOR_COR_S2 4
#define SENSOR_COR_S3 16
#define SENSOR_COR_OUT 5


unsigned long red = 0;


int cor_vermelho()
{
  digitalWrite(SENSOR_COR_S2, 0);
  digitalWrite(SENSOR_COR_S3, 0);
  unsigned long freq = pulseIn(SENSOR_COR_OUT, 0);
  return freq;
}

void setup()
{
  pinMode(SENSOR_COR_OUT, INPUT);
   // Na função serial o baudrate funciona melhor em 115200
  // Para isso necessitamos alterar o ficheiro platformio.ini
  // Acrescentando a seguinte linha:
  // monitor_speed = 115200 
  Serial.begin(115200);
  
}

void loop()
{
 
  red = cor_vermelho();  
  
  Serial.print("Vermelho: ");
  Serial.println(red); 

  delay(100);
}