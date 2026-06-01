# Project 9 Facial Expression LED Board

![](media/A221.png)

**1.Description** 

How fun it is if a expression board is added to the robot. And the Keyestudio 8\*16 LED board can do the trick. With the help of it, you could design facial expressions, images, patterns and other displays by yourselves.

The 8\*16 LED board comes with 128 LEDs. The data of the microprocessor(Arduino) communicates with the AiP1640 through a two-wire bus interface. Therefore, it can control the on and off of 128 LEDs on the module, so as to make the dot matrix on the module to display the pattern you need. A HX-2.54 4Pin cable is provided for your convenience of wiring.

**2.Specification**

- Working voltage: DC 3.3-5V

- Power loss: 400mW

- Oscillation frequency: 450KHz

- Drive current: 200mA

- Working temperature: -40\~80℃

- Communication mode: I2C
  

**3.Circuit Diagram**

![](media/A222.png)

**4.Working Principle**

How to control each LED of the 8\*16 dot matrix? It is known that each byte has 8 bits and each bit is 0 or 1. when it is 0, LED is off while when it is 1 LED is on. One byte can control one column of the LED,and naturally 16 bytes can control 16 columns of LEDs, that’s the 8\*16 dot matrix.

**5.Pins description and communication protocol**

The data of the microprocessor (Arduino) communicates with the AiP1640 through a two-wire bus cable.

The communication protocol diagram is as follows (SCLK) is SCL, (DIN) is SDA.

![](media/A223.png)

①The starting condition for data input: SCL is high level and SDA changes from high to low.

②For data command setting, there are methods as shown in the figure below.

In our sample program, select the way to **add 1 to the address automatically**, the binary value is 0100 0000 and the corresponding hexadecimal value is 0x40.

![Img](media/A224.png)

③For address command setting, the address can be selected as shown below.

The first 00H is selected in our sample program, and the binary number 1100 0000 corresponds to the hexadecimal 0xc0.

![Img](media/A225.png)

④The requirement for data input is that when SCL is at high level when inputting data, the signal on SDA must remain unchanged. Only when the clock signal on SCL is at low level, can the signal on SDA be changed. The input of data is the low bit first, and the high bit later.

⑤The condition for the end of data transmission is that when SCL is at low level, SDA at low level and SCL at high level, the level of SDA becomes high.

⑥Display control, set different pulse width, pulse width can be selected as shown in the figure below.

In the example, the pulse width is 4/16, and the hexadecimal corresponding to 1000 1010 is 0x8A.

![Img](media/A226.png)

**Instructions for the use of modulus tool**

The dot matrix tool uses the online version, and the link is :[http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

①Enter the link and the page appears as shown below

![](media/A227.png)

②The dot matrix is 8\*16, so adjust the height to 8 and width to 16, as shown in the figure below.

![](media/A228.png)

③Generate hexadecimal data from the pattern

As shown in the figure below, press the left mouse button to select, right click to cancel; draw the pattern you want, click Generate, and the hexadecimal data we need will be generated.

![](media/A229.png)

**6.Components**

| Development Board *1      | 8833 Motor Driver *1            | 8x16 LED Panel*1          |
| ------------------------- | ------------------------------- | ------------------------- |
| ![img](media/A230.jpg) | ![img](media/A231.jpg)       | ![img](media/A232.jpg) |
| USB Cable*1               | HX-2.54 4P Dupont Wire 200mm *1 |                           |
| ![img](media/A233.jpg) | ![img](media/A234.jpg)       |                           |



**7.Wiring Diagram**

![](media/A235.png)

The GND, VCC, SDA, and SCL of the 8x16 LED light board are respectively connected to the keyestudio sensor expansion board-(GND), + (VCC), A4, A5 for two-wire serial communication.

(<span style="color: rgb(255, 76, 65);">Note:</span> Though it is connected with the IIC pin of Arduino, this module is not for IIC communication. And the IO port here is to simulate I2C communication and can be connected with any two pins ).

**8.Test Code**

Before writing the code, it is necessary to import the library file of the 8x16 LED board. The specific steps are as follows: 

Click ![](media/A29.png)to enter the extension library interface of sensors/modules/components, then search for“**Matrix 8\*16 Aip1640**”module ![](media/A236.png) and click it. In this way, "**Not loaded**" changes to "**loaded**", indicating that“**Matrix 8\*16 Aip1640**”module was added successfully. 

![Img](media/A237.png)

![](media/A238.png)

Click ![](media/A33.png)to return to the code editor interface, the instruction block of the added “**Matrix 8\*16 Aip1640**”module can be seen in the module area. 

![](media/A239.png)

You can drag blocks to edit. Blocks listed below are for your reference.

(1).![](media/A126.png)

(2).![](media/A240.png)

**Complete Test Code**

![](media/A241.png)

**9.Test Result**

After successfully uploading the code to the V4.0 board, connect the wirings according to the wiring diagram, then turn the DIP switch to ON, a smile-shaped pattern will be displayed on the LED board.

![](media/A242.png)

**10.Code Explanation**

We use the modulus tool we just learned, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), to make the dot matrix display the start pattern, going forward, and stop and then clear the pattern. The time interval is 2000 ms.

![image-20250513092102687](media/A243.png)![image-20250513092107293](media/A244.png)![image-20250513092113035](media/A245.png)![image-20250513092116952](media/A246.png)


Instruction block for smiley face![](media/A247.png)

Instruction block for expression：![](media/A248.png)

Instruction block for heart ![](media/A249.png)

Instruction block for going forward![](media/A250.png)

Instruction block for **stepping back** ![](media/A251.png)

Instruction block for **turning left** ![](media/A252.png)

Instruction block for **turning right** ![](media/A253.png)

Instruction block for **stop**![](media/A254.png)

Instruction block for **clearing screen**![](media/A255.png)

![](media/A235.png)

You can drag blocks to edit. Blocks listed below are for your reference.

（1).![](media/A126.png)

（2).![](media/A240.png)

(3).![](media/A256.png)

**Complete Test Code**

![](media/A257.png)

After uploading test code, the facial expression board shows these patterns orderly and repeats this sequence.

![image-20250513092222972](media/A258.png)![image-20250513092233711](media/A259.png)![image-20250513092238552](media/A260.png)



