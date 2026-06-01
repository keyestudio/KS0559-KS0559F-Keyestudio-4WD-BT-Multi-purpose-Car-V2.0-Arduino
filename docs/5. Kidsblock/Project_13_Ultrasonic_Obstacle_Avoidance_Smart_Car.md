# Project 13 Ultrasonic Obstacle Avoidance Smart Car

![](media/A296.png)

**1.Description**

In this project, we aim to make an ultrasonic obstacle avoidance smart car. We will use the ultrasonic to detect the distance from the obstacle, which can be used to control the servo to rotate so as to make the car move. Meanwhile, the 8X16 LED board will display the corresponding status pattern.

**2.Flow Chart**

![img](media/A297.png)

**The specific logic of ultrasonic obstacle avoidance smart car is shown below:**

![Img](media/A298.png)

![Img](media/A299.png)

**3.Wiring Diagram**

![](media/A282.png)

1). GND, VCC, SDA and SCL of the 8\*8 LED board module are connected to G（GND), V（VCC), A4 and A5 of the expansion board.

2). VCC, Trig, Echo and Gnd of the ultrasonic sensor are connected to 5V(V), D12(S), D13(S) and Gnd(G).

3). The servo is connected to G, V and A3. The brown wire is interfaced with Gnd(G), the red wire is interfaced with 5V(V) and the orange wire is interfaced with A3.

4). The power is connected to the BAT port

**4.Test Code**

Before writing the code, it is necessary to import the library files of the ultrasonic sensor , 8x16 LED board and the servo. The specific steps are as follows: 

Click ![](media/A29.png)to enter the extension library interface of sensors/modules/components, then search for“Ultrasonic”sensor ![](media/A122.png)and click it. In this way, "**Not loaded**" changes to "**loaded**", indicating that the“**Ultrasonic**”sensor was added successfully. 

![Img](media/A300.png)

![](/media/A284.png)

Click ![](media/A33.png)to return to the code editor interface, the instruction block of the added “**Ultrasonic”sensor**,“**Matrix 8\*16 Aip1640**”module and “**Servo**”component can be seen in the module area. 

![](media/A285.png)

You can drag blocks to edit. Blocks listed below are for your reference.

(1).![](media/A126.png)

(2).![](media/A301.png)

(3).![](media/A302.png)

(4).![](media/A287.png)

(5).![](media/A288.png)

(6).![](media/A268.png)

(7).![](media/A289.png)

(8).![](media/A292.png)

(9).![](media/A290.png)

(10).![](media/A291.png)

**Complete Test Code**

![](media/A303.png)

![](media/A304.png)

![](media/A305.png)

![](media/A306.png)

**5.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, power on the external power then turn the DIP switch to ON.

The smart car moves forward and automatically avoids obstacles. When there is no road ahead, the servo will drive the ultrasonic sensor to scan the left, middle and right distances, and the car will turn to the open side. Meanwhile, the 8X16 LED board will display the corresponding status pattern.

