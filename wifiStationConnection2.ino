#include<ESP8266WiFi.h>

void ConnectToWifi(void);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
ConnectToWifi();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void ConnectToWifi(){

WiFi.mode(WIFI_STA);//configure nodemcu as individual station
WiFi.begin("no name","arunmax100");//here type the name and password of the Wifi connection
Serial.print("Connecting to wifi");
while(WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(200);
}
Serial.print("IP Address : ");
Serial.println(WiFi.localIP());
Serial.print("Mac Address : ");
Serial.println(WiFi.macAddress());


}