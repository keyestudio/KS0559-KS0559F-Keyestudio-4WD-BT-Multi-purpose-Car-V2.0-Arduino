# Project 1: LED Blink

1.  **Description**

![](/media/7541db758dbca2c2a100b2b0227f9af4.jpeg)For starters and enthusiasts, LED Blink is a
fundamental program. LED, the abbreviation of light emitting diodes,
consists of Ga, As, P, N chemical compounds and so on.

The LED can flash in diverse color by altering the delay time in the
test code. When in control, power on GND and VCC, the LED will be on if
S end is in high level, otherwise it will go off.

**2.Specification**

  - ![](/media/85b2076096371fd9ca03671602b1e5ce.png)Control interface:
    digital port

  - Working voltage: DC 3.3-5V

  - Pin spacing: 2.54mm

  - LED display color: red

**3.Components**

<table>
<tbody>
<tr class="odd">
<td>Keyestudio 4.0 Development Board *1</td>
<td>Keyestudio 8833 Motor Driver Expansion Board *1</td>
<td>Red LED Module*1</td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/6131c8d782756fe051b0ef0210a76d03.png" style="width:1.27292in;height:0.91875in" /></td>
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/5e291db96125e27f380e8caf79e8015a.png" style="width:1.09375in;height:0.95625in" /></td>
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/98dd27f65d3d9a90e07db154910d03ae.png" style="width:0.91111in;height:0.61111in" /></td>
</tr>
<tr class="odd">
<td>3P F-F Dupont Wire*1</td>
<td>USB Cable*1</td>
<td></td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/e9aaac06e62418ecca6eaba97a9ec518.png" style="width:1.03056in;height:0.66667in" /></td>
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/4f8d5af6dee9016b45d975adb2391d37.png" style="width:1.38611in;height:0.5125in" /></td>
<td></td>
</tr>
</tbody>
</table>

**4.Wiring Diagram**

![](/media/d29f513cc3561c7a3c3b05105e8a9ad3.png)

As can be seen from the above figure, the Keyestudio 8833 motor driver
expansion board is stacked on the Keyestudio 4.0 development board.

The pin G, V and S of the LED module are connected to G, 5V and D9 of
the expansion board respectively.

**5.Test Code**

    //****************************************************************************
    /*
     keyestudio 4wd BT Car
     lesson 1.1
     Blink
     http://www.keyestudio.com
    */
    void setup()
    { 
      pinMode(9, OUTPUT);// initialize digital pin 9 as an output.
    }
    
    void loop() // the loop function runs over and over again forever
    {  
      digitalWrite(9, HIGH); // turn the LED on (HIGH is the voltage level)
      delay(1000); // wait for a second
      digitalWrite(9, LOW); // turn the LED off by making the voltage LOW
      delay(1000); // wait for a second
    }
    //****************************************************************************


**6.Test Result**

After successfully uploading the code to the V4.0 board, connect the
wirings according to the wiring diagram, and use a USB cable to connect
the computer to power the board. After powering on, you will see the LED
connected to the D9 will be on and off. 

**7.Code Explanation**

**pinMode(9，OUTPUT) **- This function can denote that the pin is INPUT
or OUTPUT

**digitalWrite(9，HIGH)** - When pin is OUTPUT, we can set it to
HIGH(output 5V) or LOW(output 0V)

**8.Extension Practice**

We have succeeded in blinking LED. Next, let’s observe what will happen
to the LED if we modify the delay time.

    //****************************************************************************
    /*
     keyestudio 4wd BT Car
     lesson 1.2
     delay
     http://www.keyestudio.com
    */
    void setup()
    {  
      // initialize digital pin 11 as an output.
      pinMode(9, OUTPUT);
    }
    // the loop function runs over and over again forever
    void loop()
    { 
      digitalWrite(9, HIGH); // turn the LED on (HIGH is the voltage level)
      delay(100); // wait for 0.1 second
      digitalWrite(9, LOW); // turn the LED off by making the voltage LOW
      delay(100); // wait for 0.1 second
    }
    //*****************************************************************


The test result shows that the LED flashes faster. Therefore, the
delaying time enables to affect the flash frequency of the LED.
