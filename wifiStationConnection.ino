#include<ESP8266WiFi.h>
int dt=500;
void setup() {
Serial.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.begin("Dr.Arun","QWERTY12345ASDF!");
Serial.print("Connecting to Wifi");
while(WiFi.status() != WL_CONNECTED){
  Serial.print('.');
  delay(dt);
}
Serial.print("IP Address: ");
Serial.println(WiFi.localIP());
Serial.print("MacAddress: ");
Serial.println(WiFi.macAddress());
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(D0,HIGH);
}
