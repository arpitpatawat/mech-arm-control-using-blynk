#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "PVVuwLVxVdY15vYelMXN1s0L6NwE1Icc";  //Auth token id from app
char ssid[] = "i"; // Wifi username
char pass[] = "12345678"; //wifi pass
 
Servo servo; //for gripper
Servo servo1;// for forward/reverse
Servo servo2;//left/right
Servo servo3;//up down

BLYNK_WRITE(V0)
{
  servo.write(param.asInt()); //for gripper
}

BLYNK_WRITE(V1)
{
  servo1.write(param.asInt());// for forward/reverse
}

BLYNK_WRITE(V2)
{
  servo2.write(param.asInt());//left/right
}

BLYNK_WRITE(V3)
{
  servo3.write(param.asInt());//up down
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  
  servo.attach(D0); //for gripper
  servo1.attach(D1); // for forward/reverse
  servo2.attach(D2); //left/right
  servo3.attach(D3);//up down
}

void loop()
{
  Blynk.run();
}
