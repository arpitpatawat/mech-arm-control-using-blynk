#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
const char ssid[] = "i";  // your network SSID (name)
const char pass[] = "12345678";   // your network password         
WiFiClient  client;

//---------Channel Details---------//
unsigned long counterChannelNumber = 1384655;            // Channel ID
const char * myCounterReadAPIKey = "E87YBV08BWJU8C3X"; // Read API Key
const int FieldNumber1 = 1;  // The field in which our object is


void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  
}

void loop()
{
  
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.println(" ....");
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      delay(5000);
    }
    Serial.println("Connected to Wi-Fi Succesfully.");
  }

  long obj = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
  int statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    if(obj==1)
    {
      Serial.print("object is Elephant\n");
      digitalWrite(D5,HIGH);
      digitalWrite(D6,LOW);
    }
    if(obj==2)
    {
      Serial.print("object is Zebra\n");
      digitalWrite(D6,HIGH);
      digitalWrite(D5,LOW);
    }
  }
  else
  {
    Serial.println("Unable to read channel,trying again....");
  }
  delay(100);
}
