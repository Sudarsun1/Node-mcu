#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>

WiFiClient client;
HTTPClient http;

//https://api.thingspeak.com/update?api_key=UD1YE4H28ZK7KL6I&field1=0

int httpcode;
int randomNumber;
String url;
String API = "UD1YE4H28ZK7KL6I";
String fieldNo = "1";

void ConnectToWifi(void);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
ConnectToWifi();
pinMode(D6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
randomNumber = random(0,100);
sendGetRequest(randomNumber);
delay(16000);
 while(Serial.available()==0){
}
Data=Serial.readStringUntil('\r');
if(Data == 2){
  
}
}

void sendGetRequest(int data){

url = "http://api.thingspeak.com/update?api_key=";
url = url + API;
url = url + "&field";
url = url + fieldNo;
url = url + "=";
url = url + data;

http.begin(client,url);
Serial.println("Waiting For Response");
httpcode = http.GET();
if(httpcode > 0){
  Serial.print(data);
  Serial.println(" - Data sent sucessfully");
}
else{
  Serial.println("Error in sending");
}
http.end();

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