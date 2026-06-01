# Project 14 IR Remote Control Smart Car

![](media/A307.jpeg)

**1.Description**

In this project, we will make an IR remote control smart car and press the button on the IR remote control to drive the car to move.

**2.Flow Chart**

![img](media/A308.png)

**The specific logic of IR remote control smart car is shown below:**

| Initial setup                                               |           | LED board displays smile face                     |
| ----------------------------------------------------------- | --------- | ------------------------------------------------- |
| Remote control                                              | Key value | Key state                                         |
| ![wps6-1747037981476-25](media/A309.jpg) | FF629D    | Go front8*8 LED board shows front icon            |
| ![wps7-1747037985784-27](media/A310.jpg) | FFA857    | Back8*8 LED board shows back icon                 |
| ![wps8](media/A311.jpg)                  | FF22DD    | Rotate to left8*8 LED board shows leftward icon   |
| ![wps9](media/A312.jpg)                  | FFC23D    | Rotate to right8*8 LED board shows rightward icon |
| ![wps10](media/A313.jpg)                                 | FF02FD    | Stop8*8 LED board shows“STOP”                     |



**3.Wiring Diagram**

![](media/A314.png)

1). GND, VCC, SDA and SCL of the 8\*8 LED board module are connected to G（GND), V（VCC), A4 and A5 of the expansion board.
    
2). As the IR receiver is integrated on the 8833 motor driver expansion board, there is no need for additional wiring. The pins of the IR receiver on the 8833 board are G (GND), V (VCC) and D3 respectively. 
    
3). The servo is connected to G, V and A3. The brown wire is interfaced with Gnd(G), the red wire is interfaced with 5V(V) and the orange wire is interfaced with A3.
    
4). The power is connected to the BAT port
    

**4.Test Code**

<span style="color: rgb(255, 76, 65);">Please note: The infrared module shown in the software demonstration is already integrated into the expansion board and is not supplied separately. Consequently, you will not find the module depicted in the image below within the product.![](media/A144.png)</span>

Before writing the code, it is necessary to import the library files of the ultrasonic sensor, 8x16 LED board and the servo. The specific steps are as follows: 
    
Click ![](media/A29.png)to enter the extension library interface of sensors/modules/components, then search for“ir remote”sensor![](media/A144.png)and click it. In this way, "**Not loaded**" changes to "**loaded**", indicating that the“**ir remote**”sensor was added successfully. 

![Img](media/A315.png)

![](media/A146.png)

Click ![](media/A33.png)to return to the code editor interface, the instruction block of the added “**ir remote**”sensor,“**Matrix 8\*16 Aip1640**”module and “**Servo**”component can be seen in the module area. 

![](media/A316.png)

You can drag blocks to edit. Blocks listed below are for your reference

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A318.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A320.png)

(7).![](media/A291.png)

(8).![](media/A321.png)

**Complete Test Code**

![](media/A322.png)

![](media/A323.png)

![](media/A324.png)

![](media/A325.png)

![](media/A326.png)

**5.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, power on the external power then turn the DIP switch to ON. Then we enable to use the IR remote control drive the car to move to and the 8X16 LED board will display the corresponding status pattern.


