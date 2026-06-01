# Project 16 Bluetooth Speed Control Smart Car

![](media/A327.jpeg)

**1.Description**

In this project, we will use a Bluetooth to adjust the speed of the smart car. We empower to define a variable speeds and change it to change the speed of the smart car. 

**2.Flow Chart**

![image-20250513095810478](media/A340.png)

**3.Wiring Diagram**

![](media/A329.png)

1). GND, VCC, SDA and SCL of the 8\*8 LED board are connected to G（GND), V（VCC), A4 and A5 of the expansion board.

2). The RXD, TXD, GND and VCC of the Bluetooth module are respectively connected to TX, RX, G and 5V on the 8833 motor driver expansion board, while the STATE and BRK pins of the Bluetooth module do not need to be connected. 

3). The servo is connected to G, V and A3. The brown wire is interfaced with Gnd(G), the red wire is interfaced with 5V(V) and the orange wire is interfaced with A3.

4). The power is connected to the BAT port

 **4.Test Code**

Before writing the code, it is necessary to import the library files of the 8x16 LED board and the servo. The specific steps are as follows: 

Click ![](media/A29.png)to enter the extension library interface of sensors/modules/components, then search for“Matrix 8\*16 Aip1640”module![](media/A236.png)and click it. In this way, "**Not loaded**" changes to "**loaded**", indicating that the“**Matrix 8\*16 Aip1640**”module was added successfully. 

![Img](media/A237.png)

![](media/A238.png)

Click ![](media/A33.png)to return to the code editor interface, the instruction block of the added “**Matrix 8\*16 Aip1640**”module and “**Servo**”component can be seen in the module area. 

![](media/A330.png)

You can drag blocks to edit. Blocks listed below are for your reference

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

(10).![](media/A341.png)

**Complete Test Code**

<span style="color: rgb(255, 76, 65);">**Note:** Before uploading the test code, you need to remove the Bluetooth module, otherwise the code will fail to be uploaded.Connect the Bluetooth module after uploading the code successfully.</span>


![](media/A342.png)

![](media/A343.png)

![](media/A344.png)

![](media/A345.png)

![](media/A346.png)

![](media/A346.png)

**5.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, power on the external power then turn the DIP switch to ON. Pairing the APP with Bluetooth, the smart car can be controlled to move by the APP.

Press![](media/A347.png), the car will speed up, press ![](media/A348.png), the car will slow down, and the 8\*16 LED board will display the corresponding status pattern of the smart car.

