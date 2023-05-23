#include "Adafruit_MLX90614.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "wifi/WiFiMulti.h"
#include <Arduino.h>
#include <Wire.h>

#define WLAN_SSID "robotica_2"
#define WLAN_PASS "passwordrt"
#define AIO_SERVER "10.129.35.194"
#define AIO_SERVERPORT 1883

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT);
Adafruit_MQTT_Publish temperatureObj = Adafruit_MQTT_Publish(&mqtt, "temperatureOBJ");
Adafruit_MQTT_Publish temperatureAmb = Adafruit_MQTT_Publish(&mqtt, "temperatureAMB");

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

    mlx.begin();

    // mqtt.subscribe(&ledControl);
}

float ambientCelsius = 0.0;
float objectCelsius = 0.0;

void loop() {
    MQTT_connect();
  
  //Adafruit_MQTT_Subscribe *subscription;

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