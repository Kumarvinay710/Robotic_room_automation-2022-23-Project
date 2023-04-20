//This code is uploaded in the Arduino.
 
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
String UID[5] = {"79 ED 52 99","19 AF 66 40","09 F1 57 98","89 69 61 98","59 E8 47 99"};     //UIDs of all tags are stored
byte lock = 0;

String ID = ""; // scanned id

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);


void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("Welcome!!");
  lcd.setCursor(1, 1);
  lcd.print("Robotics Club");

  SPI.begin();
  rfid.PCD_Init();
}

void loop() {

  if(rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
    rfScanning();
    if(rfMatching()){
      servo.attach(3);
      if(lock){
        servo.write(0);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Door is open");
        lock = 0;
        Serial.println("open");
      } else if(!lock){
        servo.write(135);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Door is closed");
        lock = 1;
        Serial.println("closed");
      }
      delay(1500);
      servo.detach();
      lcd.clear();
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Access denied");
      delay(1500);
      lcd.clear();
    }
    lcd.setCursor(4, 0);
    lcd.print("Welcome!!");
    lcd.setCursor(1, 1);
    lcd.print("Robotics Club");
  }

  

}

void rfScanning(){
  ID = "";
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning");
  
  Serial.println("NUID tag is :");
  
  for (byte i = 0; i < rfid.uid.size; i++) {
    lcd.print(".");
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  ID.toUpperCase();
  Serial.println(ID);
}

bool rfMatching(){
  for(int i=0;i<5;i++)
  {
    if(ID.substring(1) == UID[i])
    {
      return 1;
    }
  }
  return 0;
}
