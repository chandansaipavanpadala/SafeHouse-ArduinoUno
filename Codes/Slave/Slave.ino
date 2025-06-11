//Slave Code
#include <SoftwareSerial.h>
#include <Servo.h>

#define enA 9
#define in1 2
#define in2 4

SoftwareSerial mySerial(A4, A5);

Servo doorServo;
Servo extinguisherServo;
Servo windowServo;

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  doorServo.attach(3);
  doorServo.write(80);
  extinguisherServo.attach(5);
  extinguisherServo.write(90);
  windowServo.attach(6);
  windowServo.write(50);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() 
{
  if (mySerial.available() > 0) 
  {
    String command = mySerial.readString(); 
    Serial.println("Received from Bluetooth: " + command);
    if (command.startsWith("DO"))
    {
      for (int j = 80; j <= 170; j++) 
      {
        doorServo.write(j);
        delay(20);
      }
    }
    else if (command.startsWith("DC"))
    {
      for (int j = 170; j >= 80; j--) 
      {
        doorServo.write(j);
        delay(20);
      } 
    }
    else if (command.startsWith("EO"))
    {
      for (int j = 90; j >= 0; j--) 
      {
        extinguisherServo.write(j);
        delay(20);
      }
    }
    else if (command.startsWith("EC"))
    {
      for (int j = 0; j <= 90; j++) 
      {
        extinguisherServo.write(j);
        delay(20);
      }
    }
    else if (command.startsWith("WO"))
    {
      for (int j = 50; j <= 170; j++) 
      {
        windowServo.write(j);
        delay(20);
      }
    }
    else if (command.startsWith("WC"))
    {
      for (int j = 170; j >= 50; j--) 
      {
        windowServo.write(j);
        delay(20);
      } 
    }
    else if (command.startsWith("FO"))
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW); 
      analogWrite(enA, 255);
    }
    else if (command.startsWith("FF"))
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
    else if (command.startsWith("GF"))
    {
      for (int j = 80; j <= 170; j++) 
      {
        doorServo.write(j);
        delay(20);
      }
      
      for (int j = 90; j >= 0; j--) 
      {
        extinguisherServo.write(j);
        delay(20);
      }
      
      for (int j = 50; j <= 170; j++) 
      {
        windowServo.write(j);
        delay(20);
      }

      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW); 
      analogWrite(enA, 255);
    }
  }
}