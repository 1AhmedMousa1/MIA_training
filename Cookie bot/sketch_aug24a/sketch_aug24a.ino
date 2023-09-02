// this method i used depends on HC-SR04 sensor because it is the simplest way to locate the object

int trigPin1 = 9; //trig=trigger
int echoPin1 = 10;
int trigPin2 = 11;
int echoPin2 = 12;
int trigPin3 = 13;
int echoPin3 = 14;
int trigPin4 = 15;
int echoPin4 = 16;


float chamberWidth = 5.0;
float chamberLength = 6.0;

void setup() {
 
  Serial.begin(9600);
  
 
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
}

void loop() {
  
  float distance1 = measureDistance(trigPin1, echoPin1);
  float distance2 = measureDistance(trigPin2, echoPin2);
  float distance3 = measureDistance(trigPin3, echoPin3);
  float distance4 = measureDistance(trigPin4, echoPin4);

  //using trig to locate the object
  float x = (chamberLength + distance1 - distance3) / 2.0;
  float y = (chamberWidth + distance2 - distance4) / 2.0;

 
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("m, y: ");
  Serial.print(y);
  Serial.println("m");

  
  delay(1000);
}

float measureDistance(int trigPin, int echoPin) {
    long duration;
    float distance;
    
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

  
    duration = pulseIn(echoPin, HIGH);

    
    distance = (duration/2) / 29.1;

    return distance;
}
