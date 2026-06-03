# Project 7 Bluetooth Remote Control

![](media/A161.png)

### **1.Description**

There is a DX-BT24 5.1 Bluetooth module in this kit. This bluetooth module comes with 256Kb space and complies with V5.1BLE bluetooth specification, which supports AT commands. Users can change parameters such as the baud rate and device name of the serial port as required.

Furthermore, it supports UART interface and bluetooth serial port transparent transmission, which also contains the advantages of low cost, small size, low power consumption and high sensitivity for sending and receiving. Notably, it solely needs a few peripheral components to realize its powerful functions.  

### **2.Specification**

- Bluetooth protocol: Bluetooth Specification V5.1 BLE

- Working distance: In an open environment, it can achieve 40m ultra-long distance communication
  
- Operating frequency: 2.4GHz ISM band

- Communication interface: UART

- Bluetooth certification: Accord with FCC CE ROHS REACH certification standard
  
- Serial port parameters: 9600, 8 data bits, 1 stop bit, invalid bit, no flow control
  
- Power: 5V DC

- Operating temperature: –10℃ to +65℃
  

### **3.Application**

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

**Ports**

![](media/A162.png)

①STATE：Status pin

②RX：Receiving pin

③TX：sending pin

④GND：GND

⑤VCC：Power

⑥EN： Enable pin

Connect the BT module to the development board.

<table border="1">
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


### **4.Components**

| Development Board *1      | 8833 Motor Driver *1      | Red LED Module*1           |
| ------------------------- | ------------------------- | -------------------------- |
| ![img](media/A163.jpg) | ![img](media/A164.jpg) | ![img](media/A165.jpg)  |
| 3P F-F Dupont Wire*1      | USB Cable*1               | DX-BT24 Bluetooth Module*1 |
| ![img](media/A166.jpg) | ![img](media/A167.jpg) | ![img](media/A168.jpg)  |

### **5.Wiring Diagram**

![](media/A169.png)

RXD, TXD, GND and VCC of the BT module are connected to TX, RX, G and 5V.

STATE and BRK of the BT module don’t need connection.

<span style="color: rgb(255, 76, 65);">Note:</span> the direction of the BT module when inserting it onto the 8833 board. And don’t insert it before uploading the code.

### **6.Test Code**

You can drag blocks to edit. Blocks listed below are for your reference.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A172.png)

(5).![](media/A173.png)

**Complete Test Code**

<span style="color: rgb(255, 76, 65);">**Note:** Before uploading the test code, you need to remove the Bluetooth module, otherwise the code will fail to be uploaded.Connect the Bluetooth module after uploading the code successfully.</span>

![](media/A174.png)

### **7.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. After powering on, insert the BT module and the LED will flash, then we need to download the BT app.

### **8.Download Bluetooth APP**

**Apple system**

(1).Open the App Store on the iPhone.

(2).Search keyes BT car and download the APP to your phone.

![](media/A175.png)
    

(3).After installation, enter its interface.

![](media/A176.png)
    

(4).Click "**Connect**" button in the upper left corner to automatically search for Bluetooth. When **BT24** is found, click "**Connect**" to connect Bluetooth, and then click ![](media/A177.png)to enter the control interface of 4WD smart car. 

![](media/A178.png)
    
**Android System**
    

(1).Enter google play store to search for“**keyes 4wd**”.

![](media/A179.png)

(2).The app icon is shown below after installation.

![](media/A180.png)

(3).Click app to enter the following page.

![](media/A181.png)

(4).After connecting Bluetooth, plug in power and LED indicator of Bluetooth module will flicker. Tap“Connect”to search the Bluetooth.

![](media/A182.jpeg)

(5).When **BT24** is found, click "**connect**" to connect Bluetooth. When "**connect**" turns into "**is connected**", it indicates that the Bluetooth connection is successful. As shown in the picture below, the Bluetooth LED becomes will stay on.

![](media/A183.jpeg)

(6).After connecting Bluetooth module, click ![](media/A80.png)to set baud rate to 9600. Pressing the button of the Bluetooth APP, and the corresponding characters will be displayed, as shown below:

![](media/A184.png)

| Key                                          | Function                          |
| -------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Pair DX-BT24 5.1 Bluetooth module |
| ![wps15](media/A186.jpg) | Disconnect Bluetooth              |

|                                                              | Control character                                            | Function                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Press: F  <br />Release: S                                   | Press the button, the car  goes front; <br />release to stop |
| ![wps17](media/A188.jpg)                 | Press: L  <br />Release: S                                   | Press the button, the car turns left; <br />release to stop  |
| ![wps18](media/A189.jpg)                 | Press: R  <br />Release: S                                   | Press the button, the car turns right; <br />release to stop |
| ![wps19](media/A190.jpg)                 | Press: B  <br />Release: S                                   | Press the button, the car goes back; <br />release to stop   |
| ![wps20](media/A191.jpg)                 | Press: “a”  <br />Release: “S”                               | Click to speed up(maximum:255)                               |
| ![wps21](media/A192.jpg)                 | Press: “d”  <br />Release: “S”                               | Click to slow down(minimum:0)                                |
| ![wps22](media/A193.jpg)                 | Click to start the gravity <br />sensing function of the <br />mobile phone: click again to <br />exit the gravity sensing control |                                                              |
| ![wps23](media/A194.jpg)                 | Click to send“X”,<br /> click again to send“S”               | Start line tracking function; <br />click again to exit      |
| ![wps24](media/A195.jpg)                 | Click to send“Y”, <br />click again to send“S”               | Start ultrasonic avoiding function;<br /> click again to exit |
| ![wps25](media/A196.jpg) | Click to send“U”, <br />click again to send“S”               | Start ultrasonic follow function;<br /> click  again to exit |
| ![wps26](media/A197.jpg)                 | Click to send“G”,<br />click again to send“S”                | Start restricting function;<br /> click  again to exit       |

### **9.Extension Practice**

Here we look to use the command sent by the mobile phone to turn on or off an LED light. Looking at the wiring diagram, an LED is connected to the D9 pin.

![](media/A198.png)

You can drag blocks to edit. Blocks listed below are for your reference.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A199.png)

(5).![](media/A173.png)

(6).![](media/A200.png)

(7).![](media/A201.png)

**Complete Test Code**

![](media/A202.png)

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. After powering on, click<td>![](media/A203.png)</td> and <td>![](media/A204.png)</td> to control the LED turn on and turn off.

