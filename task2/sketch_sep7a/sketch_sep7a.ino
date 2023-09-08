#define PinA 2
#define PinB 3

volatile long counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);

  // Attach interrupts to the encoder pins
  attachInterrupt(digitalPinToInterrupt(PinA), encoderA_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PinB), encoderB_ISR, CHANGE);
}

void loop() {
 
  static unsigned long lastPrintTime = 0;
  if (millis() - lastPrintTime >= 100) {
    Serial.println(counter);
    lastPrintTime = millis();
  }
}

void encoderA_ISR() {
  // Check the state of PinA
  if (digitalRead(PinA) == LOW) {
    // PinA is LOW
    if (digitalRead(PinB) == LOW) {
      // PinB is also LOW, clockwise rotation
      counter++;
    } else {
      // PinB is HIGH, counter-clockwise rotation
      counter--;
    }
  } else {
    // PinA is HIGH
    if (digitalRead(PinB) == LOW) {
      // PinB is LOW, counter-clockwise rotation
      counter--;
    } else {
      // PinB is HIGH, clockwise rotation
      counter++;
    }
  }
}

void encoderB_ISR() {
  // Check the state of PinB
  if (digitalRead(PinB) == LOW) {
    // PinB is LOW
    if (digitalRead(PinA) == LOW) {
      // PinA is also LOW, counter-clockwise rotation
      counter--;
    } else {
      // PinA is HIGH, clockwise rotation
      counter++;
    }
  } else {
    // PinB is HIGH
    if (digitalRead(PinA) == LOW) {
      // PinA is LOW, clockwise rotation
      counter++;
    } else {
      // PinA is HIGH, counter-clockwise rotation
      counter--;
    }
  }
}