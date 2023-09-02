#include <Wire.h>

int button1=2; //pin2
int button2=3; //pin3
int button1state=0;
int button2state=0;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Wire.begin();
  // put your setup code here, to run once:

}

void loop() {
  button1state= digitalRead(button1);
  button2state= digitalRead(button2);

  Wire.beginTransmission(10);
  Wire.write(button1state);
  Wire.write(button2state);
  Wire.endTransmission();

  

  // put your main code here, to run repeatedly:

}
