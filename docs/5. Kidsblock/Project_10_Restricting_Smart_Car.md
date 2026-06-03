# Project 10 Restricting Smart Car

![](media/A261.jpeg)

### **1.Description**

In this project, we look to combine the knowledge of a line tracking sensor and motor driver modules to make a restricting smart car.  In the experiment, we aim to use the line tracking sensor to detect whether there is a black line around the smart car, and then control the rotation of the two motors according to the detection results in a way that lock the smart car in a circle drawn in black line.

### **2.Flow Chart**

![img](media/A262.png)

The specific logic of the restricting 4WD smart car is shown in the table.

![Img](media/A263.png)

### **3.Wiring Diagram**

![](media/A264.png)

G, V, S1, S2 and S3 of the line tracking sensor are connected to G（GND), V（VCC), D11, D7 and D8 of the sensor expansion board.

The power is connected to the BAT port

### **4.Test Code**

You can drag blocks to edit. Blocks listed below are for your reference.

(1).![](media/A126.png)

(2).![](media/A265.png)

(3).![](media/A266.png)

(4).![](media/A267.png)

(5).![](media/A268.png)

(6).![](media/A269.png)

**Complete Test Code**

![KidsBlock Project-1747127137354](media/A270.png)



### **5.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, power on the external power then turn the DIP switch to ON. Put the smart car in the black circle, then it will move solely in the circle.

