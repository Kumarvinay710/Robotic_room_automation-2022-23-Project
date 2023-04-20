#include<Servo.h>
Servo s1;
void setup() {

  s1.attach(3);
  Serial.begin(9600);
}

void loop() {
 
  String str = "";
  if(Serial.available()){
    str = Serial.readStringUntil("\n");
    Serial.println(str);
    String data1 = str.substring(0, str.indexOf('/'));
    Serial.println(data1);
    int angle = data1.toInt();
    Serial.println(angle);
    s1.write(angle);
  }
}
