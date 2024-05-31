#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#define DHTPIN D4 
#define DHTTYPE DHT11
int SensorPin = A0;
int dt;
String Data;
DHT dht(DHTPIN, DHTTYPE);
char ssid[] = "Password";
char password[] = "Passwo4d";
unsigned long channelID = 2267935;
const char *apiKey = "Q0937KTQGA1ID6HB";

WiFiClient client;

void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D6,OUTPUT);
  digitalWrite(D0,1);
  digitalWrite(D1,1);
  Serial.begin(9600);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi"); 
  ThingSpeak.begin(client);
}

void loop() {
  float temperature = dht.readTemperature(true);
  int sensorValue = analogRead(SensorPin);
  int soilMoistPercentage = map(sensorValue,205,700,100,0);
  //Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(soilMoistPercentage);
  


  ThingSpeak.setField(1, sensorValue);
  ThingSpeak.setField(2, soilMoistPercentage);
  ThingSpeak.setField(3, temperature);
   
  int response = ThingSpeak.writeFields(channelID, apiKey);
  if (response == 200) {
    //Serial.println("Data sent to ThingSpeak successfully.");
  } else {
    //Serial.println("Error sending data to ThingSpeak. HTTP error code: " + String(response));
  }

 while(Serial.available()==0){
}
Data=Serial.readStringUntil('\r');
if(Data == "2"){
  digitalWrite(D6,HIGH);
}
if(Data == "0"){
     digitalWrite(D0,1);
     digitalWrite(D1,1);
     

   }
   else{
     digitalWrite(D0,0);
     digitalWrite(D1,0);
     dt=Data.toInt();
     dt = dt*1000;
     delay(dt);
     digitalWrite(D0,1);
     digitalWrite(D1,1);
   }
  delay(16000);
}