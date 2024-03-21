#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MLX90614.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "wifi/WiFiMulti.h"

// SSID e password da rede wifi
#define WLAN_SSID "robotica"
#define WLAN_PASS "robotica2023"
// IP e porta do servidor MQTT
#define AIO_SERVER "10.129.35.194"
#define AIO_SERVERPORT 1883

//Variáveis da temperatura ambiente e objecto
float ambientCelsius = 0.0;
float objectCelsius = 0.0;

//Instância do sensor de temperatura
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//Instância do cliente de wifi
WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT);
// temperatureOBJ e temperatureAMB são os nomes dos tópicos 
// para onde vamos publicar
// Durante os testes podemos mudar para algo diferente
Adafruit_MQTT_Publish temperatureObj = Adafruit_MQTT_Publish(&mqtt, "temperatureOBJ");
Adafruit_MQTT_Publish temperatureAmb = Adafruit_MQTT_Publish(&mqtt, "temperatureAMB");

//Função para realizar a ligação MQTT
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }

  Serial.println("MQTT Connected!");
}

void setup() {
    Serial.begin(115200);

    // Connect to WiFi access point.
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(WLAN_SSID);

    WiFi.begin(WLAN_SSID, WLAN_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    //Inicializamos o sensor de temperatura
    mlx.begin();    
}

void loop() {
  MQTT_connect();

  ambientCelsius = mlx.readAmbientTempC();
  objectCelsius = mlx.readObjectTempC();
  Serial.print(F("\nSending temperature val "));  

  if (!temperatureObj.publish(objectCelsius)) {
    Serial.println(F("Failed"));
  }
  else {
    Serial.println(F("OK!"));
  }
  if (!temperatureAmb.publish(ambientCelsius)) {
    Serial.println(F("Failed"));
  }
  else {
    Serial.println(F("OK!"));
  }
 delay(2000);
}
