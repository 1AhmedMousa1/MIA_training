#include <Wire.h> 
const int ledPin = 9; 
int ledIntensity = 0; 
int button1State = 0; 
int button2State = 0; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); 
  
  Wire.begin(10); 
  Wire.onReceive(receiveEvent); 
}

void loop() {
  if (button1State == 0 && button2State == 0) {
    ledIntensity = 0;
    Serial.println("");
  } else if (button1State == 1 && button2State == 0) {
    ledIntensity = 127;
    Serial.println("Vector focused");
  } else if (button1State == 0 && button2State == 1) {
    ledIntensity = 191;
    Serial.println("Vector distracted");
  } else if (button1State == 1 && button2State == 1) {
    ledIntensity = 255;
    Serial.println("Glitch");
  }
  
  analogWrite(ledPin, ledIntensity); 
}

void receiveEvent(int howMany) {
  while (Wire.available()) { 
    button1State = Wire.read(); 
    button2State = Wire.read(); 
  }
}
