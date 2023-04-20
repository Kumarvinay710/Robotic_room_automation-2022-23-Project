# Robotic_room_automation-2022-23-Project


![Robotics Club MNNIT](https://user-images.githubusercontent.com/126940912/233314848-bdcfcf6c-c1b3-4a94-881f-2db659a3941f.jpg)

## AIM
To add a certain degree of automation in our robotics club premises. Implemented keyless access to the club.

![image1](https://user-images.githubusercontent.com/126940912/233316813-338e5da4-cc6c-41ea-9351-04fc0412f604.jpg)


## TECH STACK
**1.** Arduino

**2.** RFID Tags and Reader

**3.** Automatic locking System.

## INTRODUCTION

  In the past, doors, and gates were typically secured using traditional lock and key mechanisms. However, in today's modern era, keyless electronic door locks are becoming increasingly popular in homes, hotels, offices, and other establishments. These types of door locks use various access control systems to allow entry.

  As part of our project, we have developed an electronic door lock system that uses RFID technology with an Arduino and RC522 RFID Module. To unlock the door, a specific card or key tag is required, which must be presented to the RFID reader. If an incorrect card or key tag is used, the door will not unlock.

  We have designed the system with a manual override option in case of any hardware issues or power failures. This allows access to the premises using a traditional key if necessary.
  
## COMPONENTS
**1.** Arduino NANO

**2.** RFID Reader(RC522)

**3.** Rfid Tags

**4.** 16×2 LCD Display and I2C module

**5.** Servo Motor (mg995)

**6.** Jumper wires

**7.** Bread board

**8.** IC 7805

**9.** 5V power supply

## Working of the Bot:
RFID systems are composed of three primary components: an RFID reader, an RFID tag or smart label, and an antenna. The RFID tag includes an integrated circuit (IC) and an antenna, which transmit data to the RFID reader, also known as an interrogator. Each RFID tag is programmed with a unique key, which the reader uses to verify authorization. If the key matches an authorized key, the tag can be assigned a specific function, which is accomplished through changes in the code in Arduino IDE.

Once the Arduino confirms the tag's authorization, it sends a signal to the servo motor. The servo motor is attached to the doorknob in a way that allows it to rotate and open or close the door according to the circumstances. This process ensures that only authorized individuals with matching keys can access the designated area.

If we need to manually override an RFID door lock system with a key, we can typically do so by locating the keyhole on the door lock,insert the key into the keyhole and turn it to unlock the door and this will allow you to open the door manually.

It's important to note that manual override of an RFID door lock should only be used in emergency situations or when the electronic system fails. Regular use of the key override can compromise the security of the lock and should be avoided.

## Ciruit Diagram:
![image3](https://user-images.githubusercontent.com/126940912/233317052-5389178b-a0a3-4ff5-94d9-c0b965a1f674.jpg)


## Door Lock System:
![image2](https://user-images.githubusercontent.com/126940912/233317123-4cfa4201-cfd5-48dd-ba7a-40a41e51a222.jpg)

**A.** Door lock for manual override. It's a retractable system, when a key is applied the whole servo+door lock system will be retracted.

**B.** Servo Motor

**C.** 3-D printed module which connects the servo motor with the handle of the door lock.

## Video link:

## The Problem Faced :
**1.** Standard LCD uses a lot of Arduino pins, this problem was solved by using an I2C module.

**2.** The backlight of the LCD was too sharp that the output was not visible, the contrast of the LCD was controlled by the potentiometer present on the I2C module. 

**3.** The address of the I2C module was not known, we got the address by uploading the I2C scanner code to the arduino board which we got from  File > Examples > Wire > i2c_scanner.

**4.** The regular power supply to the servo motor led to a wastage of power in the form of vibration in the servo motor, this problem was solved by detaching the servo motor from the Arduino board using detach() function in starting and attaching attach() function when RFID scan the tags to open or close the door.

**5.** Setting the angle to close and open the door for the servo motor was frustrating to calculate.

**6.** A lot of errors were given by Arduino during uploading the code to the Arduino board resolving those errors was interesting as well as frustrating.

**7.** There was an issue of continuous power supply to the application to stay in ‘ON’  mode in case of unavailability of electricity, this problem was resolved by installing a power bank and providing a power supply through it.

**8.** After making all connections between Arduino, servo motor, RFID reader and LCD, LCD, and servo motor were not able to perform effectively due to lack of sufficient power supply as well as the arduino board started heating up, this was resolved by using voltage regulator IC 7805.

**9.** In the end, after all, the connections between Arduino, servo motor, RFID reader, and LCD, the setup at the door was also challenging with the conditions that the door open and close with both traditional key and tags.

## Real-life applications and Benefits:
**Authentication:** Use the application as a pass to enter your workspace. This will prevent you from unauthorized people in your workspace.

**Convenience:** Convenient for elderly and physically impaired people.

**Cost Savings:** For applications where access is required for a large number of people, for instance, gym members, getting traditional keys cut can be very expensive.

**Easy To Carry:** The size of tags is almost identical to bank or id cards, making them easy to store.

**Uses:** Rfid door lock is the perfect door lock for hotels, hospitals, and large corporations.




