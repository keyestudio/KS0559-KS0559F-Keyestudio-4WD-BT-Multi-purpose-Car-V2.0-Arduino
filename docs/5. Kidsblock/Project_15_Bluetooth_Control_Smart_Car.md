# Project 15 Bluetooth Control Smart Car

![](media/A327.jpeg)

**1.Description**

We’ve learned the basic knowledge of Bluetooth. And in this lesson, we will make a Bluetooth control smart car. In this project, we aim to regard the mobile phone as the transmitter (host), and the smart car connected to the BT24 Bluetooth module (slave) as the receiver and use the mobile APP to control the smart car via the Bluetooth. 

**2.APP Control Button**

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

**3.Flow Chart**

![img](media/A328.png)

**4.Wiring Diagram**

![](media/A329.png)

1). GND, VCC, SDA and SCL of the 8\*8 LED board are connected to G（GND), V（VCC), A4 and A5 of the expansion board.
    
2). The RXD, TXD, GND and VCC of the Bluetooth module are respectively connected to TX, RX, G and 5V on the 8833 motor driver expansion board, while the STATE and BRK pins of the Bluetooth module do not need to be connected. 
    
3). The servo is connected to G, V and A3. The brown wire is interfaced with Gnd(G), the red wire is interfaced with 5V(V) and the orange wire is interfaced with A3.
    
4). The power is connected to the BAT port
    

**5.Test Code**

Before writing the code, it is necessary to import the library files of the 8x16 LED board and the servo. The specific steps are as follows: 
    
Click ![](media/A29.png)to enter the extension library interface of sensors/modules/components, then search for“**Matrix 8\*16 Aip1640**”module![](media/A236.png)and click it. In this way, "**Not loaded**" changes to "**loaded**", indicating that the“**Matrix 8\*16 Aip1640**”module was added successfully. 

![Img](media/A237.png)  

![](media/A238.png)

Click ![](media/A33.png)to return to the code editor interface, the instruction block of the added“**Matrix 8\*16 Aip1640**”module and “**Servo**”component can be seen in the module area. 

![](media/A330.png)

You can drag blocks to edit. Blocks listed below are for your reference.

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

**Complete Test Code**

<span style="color: rgb(255, 76, 65);">**Note:** Before uploading the test code, you need to remove the Bluetooth module, otherwise the code will fail to be uploaded.Connect the Bluetooth module after uploading the code successfully.</span>

![](media/A335.png)

![](media/A336.png)

![](media/A337.png)

![](media/A338.png)

![](media/A339.png)

**6.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, power on the external power then turn the DIP switch to ON.

Inset the BT module and open your cellphone to connect the Bluetooth to control the smart car. The can will move forward, backward, turn left and right and stop. Also the 8\*8 LED board will show the corresponding patterns.


