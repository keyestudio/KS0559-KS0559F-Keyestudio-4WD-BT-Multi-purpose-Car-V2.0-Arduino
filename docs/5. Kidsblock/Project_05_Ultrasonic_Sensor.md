# Project 5 Ultrasonic Sensor

**1.Description**

![](media/A109.png)

The HC-SR04 ultrasonic sensor uses sonar to determine distance to an object like what bats do. It offers excellent non-contact range detection with high accuracy and stable readings in an easy-to-use package. It comes complete with an ultrasonic transmitter and receiver modules.

![Img](media/A110.png)

The HC-SR04 or the ultrasonic sensor is being used in a wide range of electronics projects for creating obstacle detection and distance measuring application as well as various other applications. Here we have brought the simple method to measure the distance with arduino and an ultrasonic sensor and how to use the ultrasonic sensor with Arduino.

**2.Specification**

- Working Voltage :+5V DC

- Quiescent Current : \<2mA

- Working Current: 15mA

- Effectual Angle: \<15°

- Distance Range : 2cm – 300 cm

- Precision : 0.3 cm

- Measuring Angle: 30 degree

- Trigger Input Pulse width: 10uS

![](media/A111.png)

**3.Components**

| Development Board *1      | 8833 Motor Driver *1      | Red LED Module*1          | Ultrasonic Sensor*1       |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A112.jpg) | ![img](media/A113.jpg) | ![img](media/A114.jpg) | ![img](media/A115.jpg) |
| 4P Dupont Wire*1          | USB Cable*1               | 3P Dupont Wire*1          |                           |
| ![img](media/A116.jpg) | ![img](media/A117.jpg) | ![img](media/A118.jpg) |                           |

**4.Working Principle**

As the above picture shown, it is like two eyes. One is transmitting end, the other is receiving end.

The ultrasonic module will emit the ultrasonic waves after triggering a signal. When the ultrasonic waves encounter the object and are reflected back, the module outputs an echo signal, so it can determine the distance of the object from the time difference between the trigger signal and the echo signal.

The t is the time that emitting signal meets obstacle and returns. And the propagation speed of sound in the air is about 343m/s, and distance = speed \* time. However, the ultrasonic wave emits and comes back, which is 2 times of distance. Therefore, it needs to be divided by 2, the distance measured by ultrasonic wave = (speed \* time)/2.

**Use method and chart of ultrasonic module:**

1).Use the GPIO pin to give a high level signal of at least 10μs to the Trig pin of SR04, which can trigger it to detect distance.

2).After triggering, the module will automatically send eight 40KHz ultrasonic pulses and detect whether there is a signal return. This step will be completed automatically by the module.

3).If the signal returns, the Echo pin will output a high level, and the duration of the high level is the time from the transmission of the ultrasonic wave to the return.

![image-20250509143833078](media/A119.png)


**Circuit diagram of ultrasonic sensor:**

![](media/A120.jpeg)

**5.Wiring Diagram**

![](media/A121.png)

VCC, Trig, Echo and Gnd of the ultrasonic sensor are connected to 5V(V), D12, D13 and Gnd(G)

**6.Test Code**

Before writing the code, it is necessary to import the library file of the ultrasonic sensor. The specific steps are as follows: 

Click ![](media/A29.png)to enter the extension library interface of sensors/modules/components, then search for "**Ultrasonic**" sensor ![](media/A122.png)and click it. In this way, "**Not loaded**" changes to "**loaded**", indicating that "**Ultrasonic**" sensor was added successfully. 

![Img](media/A123.png)

![](media/A124.png)

Click ![](media/A33.png)to return to the code editor interface, the instruction block of the added "**Ultrasonic**" sensor can be seen in the module area. 

![](media/A125.png)

You can drag blocks to edit. Blocks listed below are for your reference.

（1).![](media/A126.png)

(2).![](media/A127.png)

(3).![](media/A128.png)

(4).![](media/A129.png)

(5).![](media/A130.png)

(6).![](media/A131.png)

(7).![](media/A132.png)

**Complete Test Code**

![](media/A133.png)

**7.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. After powering on, click ![](media/A80.png)to set baud rate to 9600.

The detected distance will be displayed, and the unit is cm and inch. Hinder the ultrasonic sensor by hand, the displayed distance value gets smaller.

![](media/A134.png)

**8.Extension Practice**

We have just measured the distance displayed by the ultrasonic. How about controlling the LED with the measured distance? Let's try it and connect an LED light module to the D9 pin.

![](media/A135.png)

You can drag blocks to edit. Blocks listed below are for your reference.

(1).![](media/A126.png)

(2).![](media/A136.png)

(3).![](media/A128.png)

(4).![](media/A137.png)

(5).![](media/A130.png)

(6).![](media/A138.png)

(7).![](media/A132.png)

**Complete Test Code**

![](media/A139.png)

![](media/A140.png)

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then connect the computer via a USB cable to power the board. After powering on, block the ultrasonic sensor by hand(the distance is between 2-10cm), then check if the LED is on.

