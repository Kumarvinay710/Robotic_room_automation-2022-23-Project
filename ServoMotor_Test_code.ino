// This is basic code of ServoMotor to understand the working of Servo motor.

#include<Servo.h>
Servo s1;

void setup() {

  s1.attach(3); // define pin that attach with servo

}

void loop() {
  
  s1.write(135); // define angle of rotation of servo
  delay(5000);
  s1.write(45);
  delay(5000);
}
