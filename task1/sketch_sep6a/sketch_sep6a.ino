
#include <Wire.h>
const int MPU = 0x68; // MPU6050 I2C address
float GyroZ;
float yaw;
float elapsedTime, currentTime, previousTime;
float GyroErrorZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);
  calculate_IMU_error();
}

void loop() {
  previousTime = currentTime;
  currentTime = millis();
  elapsedTime = (currentTime - previousTime) / 1000;
  
  Wire.beginTransmission(MPU);
  Wire.write(0x47);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true);
  
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = GyroZ + GyroErrorZ;
  
  yaw = yaw + GyroZ * elapsedTime;

  Serial.println(yaw);
}

void calculate_IMU_error() {
    // Code to calibrate the MPU6050 sensor and calculate the error values
}
