//Master Code
#include <SoftwareSerial.h>

SoftwareSerial mySerial(A4, A5);
SoftwareSerial bluetoothSerial(10, 11);

int flamePin = 5;
int flameState = LOW;
int prevFlameState = LOW;

const int pirPin = 8;
int pirState = LOW;
int prevPirState = LOW;

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  bluetoothSerial.begin(9600);
  pinMode(flamePin, INPUT);
  pinMode(pirPin, INPUT);
  delay(20);
}

void loop() 
{
  flameState = digitalRead(flamePin);
  if (flameState != prevFlameState) 
  {
    if (flameState == HIGH)
    {
      bluetoothSerial.println("|No flame detected|");
      delay(5000);
    }
    else
    {
      mySerial.println("GF");
      bluetoothSerial.println("|Flame detected|");
      delay(5000);
    }
    prevFlameState = flameState;
  }

  pirState = digitalRead(pirPin);
    if (pirState != prevPirState) 
    {
      if (pirState == HIGH)
      {
        bluetoothSerial.println("|Motion end|");
        delay(5000);
      }
      else
      {
        bluetoothSerial.println("|Motion detected|");
        delay(5000);
      }
      prevPirState = pirState;
    }

  if (bluetoothSerial.available() > 0) 
  {
    String message = bluetoothSerial.readString();
    mySerial.println(message);
  }
  
  if (mySerial.available()) 
  {
    String message = mySerial.readString();
    mySerial.println(message);
  }
}