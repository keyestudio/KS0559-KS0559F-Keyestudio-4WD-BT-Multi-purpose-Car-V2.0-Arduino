# Project 7 Bluetooth Remote Control

**1.Description**

![image-20250510083107283](media/A47.png)

There is a DX-BT24 5.1 Bluetooth module in this kit. This bluetooth module comes with 256Kb space and complies with V5.1BLE bluetooth specification, which supports AT commands. Users can change parameters such as the baud rate and device name of the serial port as required.

Furthermore, it supports UART interface and bluetooth serial port transparent transmission, which also contains the advantages of low cost, small size, low power consumption and high sensitivity for sending and receiving. Notably, it solely needs a few peripheral components to realize its powerful functions.  

**2.Specification**

- Bluetooth protocol: Bluetooth Specification V5.1 BLE

- Working distance: In an open environment, it can achieve 40m ultra-long distance communication

- Operating frequency: 2.4GHz ISM band

- Communication interface: UART

- Bluetooth certification: Accord with FCC CE ROHS REACH certification standard

- Serial port parameters: 9600, 8 data bits, 1 stop bit, invalid bit, no flow control

- Power: 5V DC

- Operating temperature: –10℃ to +65℃

**3.Application**

The DX-BT24 module also supports the BT5.1 BLE protocol, which can be directly connected to iOS devices with BLE Bluetooth function, and supports resident running of background programs. It is mainly used in the field of short-distance data wireless transmission. It enables to avoid cumbersome cable connections and can directly replace serial cables.

**Successful application areas of BT24 modules:**

※ Bluetooth wireless data transmission;

※ Mobile phone, computer peripheral equipment;

※ Handheld POS equipment;

※ Wireless data transmission of medical equipment;

※ Smart home control;

※ Bluetooth printer;

※ Bluetooth remote control toys;

※ Shared bicycles;

**4.Ports**

![420af966-aaa4-4736-9d35-2a9ccc7215f3](media/A48.png)

①STATE：Status pin

②RX：Receiving pin

③TX：sending pin

④GND：GND

⑤VCC：Power

⑥EN： Enable pin

Connect the BT module to the development board.

| Uno  | BT24 |
| :--: | :--: |
|  TX  |  RX  |
|  RX  |  TX  |
| VCC  |  5V  |
| GND  | GND  |

**5.Components**

|           Development Board *1           |           8833 Motor Driver *1           |                       Red LED Module*1                       |
| :--------------------------------------: | :--------------------------------------: | :----------------------------------------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) |                   ![img](media/A10.jpg)                   |
|             3P Dupont Wire*1             |               USB Cable*1                |                  DX-BT24 Bluetooth Module*1                  |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         | ![image-20250510083534209](media/A49.png) |

**6.Wiring Diagram**

![image-20250510083927915](media/A50.png)

RXD, TXD, GND and VCC of the BT module are connected to TX, RX, G and 5V.

STATE and BRK of the BT module don’t need connection.

<span style="color: rgb(255, 76, 65);">Note:the direction of the BT module when inserting it onto the 8833 board. And don’t insert it before uploading the code.</span> 

**7.Test Code**

<span style="color: rgb(255, 76, 65);">**Note:** Before uploading the test code, you need to remove the Bluetooth module, otherwise the code will fail to be uploaded.Connect the Bluetooth module after uploading the code successfully.</span>

```c
//***********************************************************************
/*
keyestudio 4wd BT Car
lesson 7.1
Bluetooth 
http://www.keyestudio.com
*/
char ble_val; //character variable, used to store the value received by Bluetooth 


void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0)  //make sure if there is data in serial buffer
  {
    ble_val = Serial.read();  //Read data from serial buffer
    Serial.println(ble_val);  //Print
  }
}
//***********************************************************************
```

**8.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. After powering on, insert the BT module and the LED will flash, then we need to download the BT app.

**9.Download Bluetooth APP**

**Apple system**

(1). Open the App Store on the iPhone.

(2). Search keyes BT car and download the APP to your phone.



![image-20250510084716811](media/A51.png)
    

(3). After installation, enter its interface.

![image-20250510084812821](media/A52.png)
    

(4). Click "**Connect**" button in the upper left corner to automatically search for Bluetooth. When **BT24** is found, click "**Connect**" to connect Bluetooth, and then click ![image-20250510084833837](media/A53.png) to enter the control interface of 4WD smart car. 

![image-20250510084902641](media/A54.png)
    **Android System**
    

(1). Enter google play store to search for“keyes 4wd”.

![image-20250510084916086](media/A55.png)

(2). The app icon is shown below after installation.

![image-20250510084933465](media/A56.png)

(3). Click app to enter the following page.

![image-20250510084946146](media/A57.png)

(4). After connecting Bluetooth, plug in power and LED indicator of Bluetooth module will flicker. Tap“**Connect**”to search the Bluetooth.

![image-20250510085007028](media/A58.png)

(5). When **BT24** is found, click "Connect" to connect Bluetooth. When "**Connect**" turns into "**is Connected**", it indicates that the Bluetooth connection is successful. As shown in the picture below, the Bluetooth LED becomes will stay on.

![image-20250510085026219](media/A59.png)

(6). After connecting Bluetooth module, open serial monitor to set baud rate to 9600. Pressing the button of the Bluetooth APP, and the corresponding characters will be displayed, as shown below:

![image-20250510085039562](media/A60.png)

| Key                       | Function                          |
| ------------------------- | --------------------------------- |
| ![img](./media/A61.jpg) | Pair DX-BT24 5.1 Bluetooth module |
| ![img](./media/A62.jpg) | Disconnect Bluetooth              |



|                           | Control character                                            | Control character                                            |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Press: F  <br />Release: S                                   | Press the button, the car  goes front; <br />release to stop |
| ![img](media/A64.jpg) | Press: L  <br />Release: S                                   | Press the button, the car turns left; <br />release to stop  |
| ![img](media/A65.jpg) | Press: R  <br />Release: S                                   | Press the button, the car turns right; <br />release to stop |
| ![img](media/A66.jpg) | Press: B  <br />Release: S                                   | Press the button, the car goes back; <br />release to stop   |
| ![img](media/A67.jpg) | Press: “a”  <br />Release: “S”                               | Click to speed up(maximum:255)                               |
| ![img](media/A68.jpg) | Press: “d”  <br />Release: “S”                               | Click to slow down(minimum:0)                                |
| ![img](media/A69.jpg) | Click to start the gravity <br />sensing function of the <br />mobile phone: click again to <br />exit the gravity sensing control |                                                              |
| ![img](media/A70.jpg) | Click to send“X”, <br />click again to send“S”               | Start line tracking function; <br />click again to exit      |
| ![img](media/A71.jpg) | Click to send“Y”, <br />click again to send“S”               | Start ultrasonic avoiding function; <br />click again to exit |
| ![img](media/A72.jpg) | Click to send“U”, <br />click again to send“S”               | Start ultrasonic follow function; <br />click  again to exit |
| ![img](media/A73.jpg) | Click to send“G”, <br />click again to send“S”               | Start restricting function;<br /> click  again to exit       |

**9.Code Explanation**

**Serial.available()** : Return the number of characters currently remaining in the serial port buffer. Generally, this function is used to judge whether there is data in the buffer of the serial port. When Serial.available()\>0, it means that the serial port has received data and can be read;

**Serial.read() :** Refers to taking out and reading a Byte of data from the serial port buffer. For example, if a device sends data to Arduino through the serial port, we can use Serial.read() to read the sent data.

**10.Extension Practice**

Here we look to use the command sent by the mobile phone to turn on or off an LED light. Looking at the wiring diagram, an LED is connected to the D9 pin.

![image-20250510085856954](media/A74.png)

```c
//****************************************************************************
/*
 keyestudio smart turtle robot
 lesson 7.2
 Bluetooth LED
 http://www.keyestudio.com
*/ 
int ledpin=9;
char ble_val;// An integer variable used to store the value received by Bluetooth

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop()
{ 
  if (Serial.available() > 0) //Check whether there is data in the serial port cache
  {
    ble_val = Serial.read();  //Read data from the serial port cache
    Serial.print("DATA RECEIVED:");
    Serial.println(ble_val);
    if (ble_val == 'F') {
      digitalWrite(ledpin, HIGH);
      Serial.println("led on");
    }
    if (ble_val == 'B') {
      digitalWrite(ledpin, LOW);
      Serial.println("led off");
    }
   }
}
//****************************************************************************
```

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. After powering on, click![image-20250510085919039](media/A75.png) and ![image-20250510085931709](media/A76.png) to control the LED turn on and turn off.

