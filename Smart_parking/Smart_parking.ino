#define BLYNK_PRINT Serial 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "u3IDFIvra8BrGUH-DUCkrp-IyDLbS9XW";
char ssid[] = "Androidap4906";
char pswd[] = "lwww3078";

WidgetLED led1 (V1);

int sensor1 = D4;

void setup() 
{

  Serial.begin(9600);
  Blynk.begin(auth,ssid,pswd);
  pinMode(sensor1,INPUT);
  while (Blynk.connect() == false) {
  Serial.println("tidak terkoneksi");
  }
}

void loop() 
{
  int sensorval1 = digitalRead(sensor1);
  delay(1000);
  

  if (sensorval1 == 1)
  {
led1.on();
  }

if (sensorval1 == 0)
  {
led1.off();
  }
  Blynk.run();
}
