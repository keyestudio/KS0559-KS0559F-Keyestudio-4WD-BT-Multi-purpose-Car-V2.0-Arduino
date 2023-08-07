# Project 7 Bluetooth Remote Control

**1.Description**

![](/media/aa5546baeb5afe1adfe9fff51f497fe8.png)

There is a DX-BT24 5.1 Bluetooth module in this kit. This bluetooth module comes with 256Kb space and complies with V5.1BLE bluetooth specification, which supports AT commands. Users can change parameters such as the baud rate and device name of the serial port as required. 

Furthermore, it supports UART interface and bluetooth serial port transparent transmission, which also contains the advantages of low cost, small size, low power consumption and high sensitivity for sending and receiving. Notably, it solely needs a few peripheral components to realize its powerful functions.



**2.Specification**

  - Bluetooth protocol: Bluetooth Specification V5.1 BLE
  - Working distance: In an open environment, it can achieve 40m ultra-long distance communication
  - Operating frequency: 2.4GHz ISM band
  - Communication interface: UART
  - Bluetooth certification: [Accord](javascript:;) with FCC CE ROHS REACH certification standard
  - Serial port parameters: 9600, 8 data bits, 1 stop bit, invalid bit, no flow control
  - Power: 5V DC
  - Operating temperature: –10℃ to +65℃



**3.Application**

The DX-BT24 module also supports the BT5.1 BLE protocol, which can be directly connected to iOS devices with BLE Bluetooth function, and supports resident running of background programs. 

It is mainly used in the field of short-distance data wireless transmission. It enables to avoid cumbersome cable connections and can directly replace serial cables. Successful application areas of BT24 modules:

※ Bluetooth wireless data transmission;

※ Mobile phone, computer peripheral equipment;

※ Handheld POS equipment;

※ Wireless data transmission of medical equipment;

※ Smart home control;

※ Bluetooth printer;

※ Bluetooth remote control toys;

※ Shared bicycles;



**4.Ports**

![](/media/cd97cf79ff5cdd5bbd78f4cc960d38e5.png)

①STATE: Status pin

②RX: Receiving pin

③TX: sending pin

④GND: GND

⑤VCC: Power

⑥EN: Enable pin

Connect the BT module to the development board.

<table>
<tbody>
<tr class="odd">
<td>Uno</td>
<td>BT24</td>
</tr>
<tr class="even">
<td>TX</td>
<td>RX</td>
</tr>
<tr class="odd">
<td>RX</td>
<td>TX</td>
</tr>
<tr class="even">
<td>VCC</td>
<td>5V</td>
</tr>
<tr class="odd">
<td>GND</td>
<td>GND</td>
</tr>
</tbody>
</table>


**5.Components**

| 4.0 Development Board *1                                     | 8833 Motor Driver Expansion Board *1                         | Red LED Module*1                                             |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![image-20230420161135228](media/image-20230420161135228.png) | ![image-20230420161143543](media/image-20230420161143543.png) | ![image-20230420161150007](media/image-20230420161150007.png) |
| **3P F-F Dupont Wire*1**                                     | **USB Cable*1**                                              | **DX-BT24 Bluetooth Module*1**                               |
| ![image-20230420161155609](media/image-20230420161155609.png) | ![image-20230420161202213](media/image-20230420161202213.png) | ![image-20230420161208630](media/image-20230420161208630.png) |



**6.Wiring Diagram**

![](/media/63b96e5b26ee18337fb6e0dced5bbbe3.png)

RXD, TXD, GND and VCC of the BT module are connected to TX, RX, G and 5V.

STATE and BRK of the BT module don’t need connection.

Note the direction of the BT module when inserting it onto the 8833 board. And don’t insert it before uploading the code.



**7.Test Code**

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


​    

**8.Test Result**

Don’t connect the BT module when uploading the code because serial communication port will be occupied when uploading code and inserting the BT module.

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. After powering on, insert the BT module and the LED will flash, then we need to download the BT app.



**9.Download Bluetooth APP**

**Apple system**

Open the App Store on the iPhone. Search keyes BT car and download the APP to your phone.

![](/media/b3e1a209b1dbe6800c327a868379b1de.png)

After installation, enter its interface.

![](/media/e6d0abe92ad337a425af6cb0d63e4954.png)

Click "Connect" button in the upper left corner to automatically search for Bluetooth. When BT24 is found, click "Connect" to connect Bluetooth, and then click <img src="/media/e3b7b4c2ed5b85ce402998208ab0bb1e.png" style="zoom:50%;" />to enter the control interface of 4WD smart car. 

![](/media/8a3a43db2709f3231fcc78f3e5fec26f.png)

Android System

Enter google play store to search for“keyes 4wd”

![](/media/66cce2fc4a3ae3f88db1b56a5b341fac.png)

The app icon is shown below after installation.

![](/media/c2a01ef689e3134df31f6d25f7acb946.png)

Click app to enter the following page.

![](/media/b0ab7f5ddd031e3f50565fcb06a88fce.png)

After connecting Bluetooth, plug in power and LED indicator of Bluetooth module will flicker. 

Tap“Connect”to search the Bluetooth.

![](/media/585be11142e72188c4ebabe13b32ed43.jpeg)

When BT24 is found, click "connect" to connect Bluetooth. When "connect" turns into "is connected", it indicates that the Bluetooth connection is successful. 

As shown in the picture below, the Bluetooth LED becomes will stay on.

![](/media/e2469e9e301ba17962382942a697892d.jpeg)

After connecting Bluetooth module, open serial monitor to set baud rate to 9600. 

Pressing the button of the Bluetooth APP, and the corresponding characters will be displayed, as shown below:

![](/media/c4c99cc8f66d33243e62bbeba71a0807.png)

| Key                                                          | **Control character**                    | Function                                                     |
| ------------------------------------------------------------ | ---------------------------------------- | ------------------------------------------------------------ |
| ![image-20230420160115427](media/image-20230420160115427.png) |                                          | Pair DX-BT24 5.1 Bluetooth module                            |
| ![image-20230420160347345](media/image-20230420160347345.png) |                                          | Disconnect Bluetooth                                         |
| ![image-20230420160357746](media/image-20230420160357746.png) | Press: F<br />Release: S                 | Press the button, the car  goes front; release to stop       |
| ![image-20230420160407870](media/image-20230420160407870.png) | Press: L<br />Release: S                 | Press the button, the car turns left; release to stop        |
| ![image-20230420160418398](media/image-20230420160418398.png) | Press: R<br />Release: S                 | Press the button, the car turns right; release to stop       |
| ![image-20230420160427820](media/image-20230420160427820.png) | Press: B<br />Release: S                 | Press the button, the car goes back; release to stop         |
| ![image-20230420160437700](media/image-20230420160437700.png) | Press: “a”<br />Release: “S”             | Click to speed up(maximum:255)                               |
| ![image-20230420160453532](media/image-20230420160453532.png) | Press: “d”<br />Release: “S”             | Click to slow down(minimum:0)                                |
| ![image-20230420160505859](media/image-20230420160505859.png) |                                          | Click to start the gravity sensing function of the mobile phone: click again to exit the gravity sensing control |
| ![image-20230420160521904](media/image-20230420160521904.png) | Click to send“X”, click again to send“S” | Start line tracking function; click again to exit            |
| ![image-20230420160525851](media/image-20230420160525851.png) | Click to send“Y”, click again to send“S” | Start ultrasonic avoiding function; click again to exit      |
| ![image-20230420160529723](media/image-20230420160529723.png) | Click to send“U”, click again to send“S” | Start ultrasonic follow function; click  again to exit       |
| ![image-20230420160533426](media/image-20230420160533426.png) | Click to send“G”, click again to send“S” | Start restricting function; click  again to exit             |

**10.Code Explanation**

**Serial.available()** 

Return the number of characters currently remaining in the serial port buffer. Generally, this function is used to judge whether there is data in the buffer of the serial port. When Serial.available()>0, it means that the serial port has received data and can be read; 

**Serial.read() **

Refers to taking out and reading a Byte of data from the serial port buffer. For example, if a device sends data to Arduino through the serial port, we can use Serial.read() to read the sent data.



**11.Extension Practice**

Here we look to use the command sent by the mobile phone to turn on or off an LED light. Looking at the wiring diagram, an LED is connected to the D9 pin.![](/media/1a719bb514db5eb134cfa943bd138e52.png)

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

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. 

After powering on, click![img](media/wps258.jpg)and![img](media/wps259.jpg)to control the LED.
