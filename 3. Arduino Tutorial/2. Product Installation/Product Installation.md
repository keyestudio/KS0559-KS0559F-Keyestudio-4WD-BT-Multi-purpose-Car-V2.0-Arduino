# 5.Product Installation

Installation

| **Part 1**           |                                                              |
| -------------------- | :----------------------------------------------------------: |
| Components Needed    | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps146.jpg) |
| Installation Diagram | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps147.jpg) |
| Prototype            | **![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps148.jpg)** |
| **Part 2**           |                                                              |
| Components Needed    | **![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps149.jpg)** |
| Installation Diagram | **![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps150.jpg)** ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps151.jpg) ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps152.png) |
| Prototype            | **![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps153.png)** |
| **Part 3**           |                                                              |
| Components Needed    | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps154.jpg)![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps155.png) |
| Installation Diagram | **![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps156.jpg)** |
| Plug Wire            | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps157.png) |
| Prototype            | **![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps158.jpg)** |

| **Part 4**              |                                                              |
| ----------------------- | ------------------------------------------------------------ |
| Components Needed       | ![img](media/wps160.jpg)                                     |
| Rotate the servo to 90° | The below Arduino code is provided in the file. Open the code and burn it to the Keyestudio 4.0 motherboard, as shown below：<br />![img](media/wps161.jpg) |
| Installation Diagram    | ![img](media/wps162.jpg)<br />![img](media/wps164.jpg)<br />![img](media/wps165.jpg)<br />![img](media/wps166.jpg) |
| Prototype               | ![img](media/wps167.jpg)                                     |

| Servo  | 8833 Motor Driver Expansion Board |
| :----: | :-------------------------------: |
| Brown  |                 G                 |
|  Red   |                5V                 |
| Yellow |                A3                 |

```c
//*******************************************************************
/*
Set the 90-degree code,Copy the code and upload it to the development board. The steering gear connected to port A3 will rotate to 90 °
*/
#define servoPin A3  //servo Pin
int pos; //the angle variable of servo
int pulsewidth; // pulse width variable of servo
void setup() {
  pinMode(servoPin, OUTPUT);  //set servo pin to OUTPUT
  procedure(0); //set the angle of servo to 0°
}
void loop() {

    procedure(90);   // tell servo to go to position in variable 90°
}
// function to control servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //calculate the value of pulse width
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   //The duration of high level is pulse width
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  // the cycle is 20ms, the low level last for the rest of time
}
//*******************************************************************
```

| Part 5               |                                                              |
| -------------------- | ------------------------------------------------------------ |
| Components Needed    | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps168.jpg) |
| Installation Diagram | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps169.jpg) |
|                      | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps170.jpg) |
| Prototype            | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps171.jpg) |
| **Part 6**           |                                                              |
| Components Needed    | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps172.jpg)          ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps173.jpg) |
| Installation Diagram | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps174.jpg) ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps175.jpg) |
| Prototype            | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps176.jpg) |
| **Part 7**           |                                                              |
| Components Needed    | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps177.jpg) |
| Installation Diagram | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps178.jpg) ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps179.jpg) |
| Prototype            | ![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml4300\wps180.jpg) |



Wiring

**Wiring Diagram**

![img](media/wps181.jpg)

M2 Motor is connected to B interface,，M3 Motor is connected to A interface.

![img](media/wps182.jpg)

M1 Motor is connected to B1 interface，M4 Motor is connected to A1 interface.

![img](media/wps183.jpg)

The wiring of the 3-channel line-tracking sensor

![img](media/wps184.jpg)

The power supply is connected to BAT

![img](media/wps185.jpg)

The wiring of the ultrasonic sensor

| Ultrasonic Sensor | 8833 Motor Driver Expansion Board |
| ----------------- | --------------------------------- |
| Vcc               | V                                 |
| Trig              | D12                               |
| Echo              | D13                               |
| Gnd               | G                                 |

![img](media/wps188.jpg)

The wiring of the 8*16 LED Board

| 8*16 LED Board | 8833 Motor Driver Expansion Board |
| -------------- | --------------------------------- |
| GND            | G                                 |
| VCC            | 5V                                |
| SDA            | A4                                |
| SCL            | A5                                |

![img](media/wps190.jpg)

The wiring of the servo

| Servo  | 8833 Motor Driver Expansion Board |
| ------ | --------------------------------- |
| Brown  | G                                 |
| Red    | 5V                                |
| Yellow | A3                                |

![img](media/wps191.jpg)

Plug in the Bluetooth module and jumper caps

![img](media/wps192.jpg)

**Complete Prototype**

![img](media/wps193.jpg)







