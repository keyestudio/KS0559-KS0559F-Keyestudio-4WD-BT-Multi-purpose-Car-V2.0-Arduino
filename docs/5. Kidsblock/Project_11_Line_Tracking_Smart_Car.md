# Project 11 Line Tracking Smart Car

![](media/A271.png)

**1.Description**

Based on the working principle of the line tracking sensor, we empower to make a line tracking smart car.

In this project, we detect whether there is a black line at the bottom of the smart car through a line tracking sensor, and then control the rotation of the two groups of motors according to the detection results in a way that controls the smart car to walk along the black line. 

**2.Flow Chart**

![img](media/A272.png)

![Img](media/A273.png)

**3.Wiring Diagram**

![](media/A264.png)

G, V, S1, S2 and S3 of the line tracking sensor are connected to G（GND), V（VCC), D11, D7 and D8 of the sensor expansion board.

The power is connected to the BAT port

**4.Test Code**

You can drag blocks to edit. Blocks listed below are for your reference

(1).![](media/A126.png)

(2).![](media/A274.png)

(3).![](media/A275.png)

(4).![](media/A268.png)

(5).![](media/A276.png)

**Complete Test Code**

![](media/A277.png)

![](media/A278.png)

![](media/A279.png)

**5.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, power on the external power then turn the DIP switch to ON. Then the smart car will walk along the lines.

