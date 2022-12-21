**Project 11 Line Tracking Smart Car**

![](/media/eff7a15e697e8b78bde391f806ea024d.png)

**1.Description**

Based on the working principle of the line tracking sensor, we empower
to make a line tracking smart car.

In this project, we detect whether there is a black line at the bottom
of the smart car through a line tracking sensor, and then control the
rotation of the two groups of motors according to the detection results
in a way that control the smart car to walk along the black line. 

**2.Flow Chart**

<table>
<tbody>
<tr class="odd">
<td><strong>Detection</strong></td>
<td>Middle tracking sensor</td>
<td>detects black line：HIGH</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>detects white line：LOW</td>
</tr>
<tr class="odd">
<td></td>
<td>Left tracking sensor</td>
<td>detects black line：HIGH</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>detects white line：LOW</td>
</tr>
<tr class="odd">
<td></td>
<td>Right tracking sensor</td>
<td>detects black line：HIGH</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>detects white line：LOW</td>
</tr>
<tr class="odd">
<td><strong>Condition 1</strong></td>
<td><strong>Condition</strong> 2 Detect the left and the right tracking sensor</td>
<td>Status</td>
</tr>
<tr class="even">
<td>Middle tracking sensor detects black line</td>
<td>left tracking sensor detects black line; right sensor detects white line</td>
<td>Turn left</td>
</tr>
<tr class="odd">
<td></td>
<td>left tracking sensor detects white line; right sensor detects black line</td>
<td>Turn right</td>
</tr>
<tr class="even">
<td></td>
<td>left and right tracking sensor detect black line</td>
<td>Advance</td>
</tr>
<tr class="odd">
<td></td>
<td>left and right tracking sensor detect white line</td>
<td>Advance</td>
</tr>
<tr class="even">
<td>Middle tracking sensor detects white line</td>
<td>left tracking sensor detects black line; right sensor detects white line</td>
<td>Turn left</td>
</tr>
<tr class="odd">
<td></td>
<td>left tracking sensor detects white line; right sensor detects black line</td>
<td>Turn right</td>
</tr>
<tr class="even">
<td></td>
<td>left and right tracking sensor detect black line</td>
<td>Stop</td>
</tr>
<tr class="odd">
<td></td>
<td>left and right tracking sensor detect white line</td>
<td>Stop</td>
</tr>
</tbody>
</table>

**3.Wiring Diagram**

![](/media/88422b5f1464ad447e28ccbb8c39a8d4.png)

G, V, S1, S2 and S3 of the line tracking sensor are connected to G（GND),
V（VCC), D11, D7 and D8 of the sensor expansion board.

The power is connected to the BAT port

**4.Test Code**

<table>
<tbody>
<tr class="odd">
<td><p>//*************************************************************************</p>
<p>/*</p>
<p>keyestudio 4wd BT Car</p>
<p>lesson 11</p>
<p>Tracking Car</p>
<p>http://www.keyestudio.com</p>
<p>*/</p>
<p>//Data from the smile pattern obtained from the touch tool</p>
<p>unsigned char start01[] = ;</p>
<p>#define SDA_Pin A4 //Set data pin to A4</p>
<p>#define SCL_Pin A5 //Set the clock pin to A5</p>
<p>int left_ctrl = 2;//define the direction control pins of group B motor</p>
<p>int left_pwm = 5;//define the PWM control pins of group B motor</p>
<p>int right_ctrl = 4;//define the direction control pins of group A motor</p>
<p>int right_pwm = 6;//define the PWM control pins of group A motor</p>
<p>int sensor_L = 11;//define the pin of left line tracking sensor</p>
<p>int sensor_M = 7;//define the pin of middle line tracking sensor</p>
<p>int sensor_R = 8;//define the pin of right line tracking sensor</p>
<p>int L_val,M_val,R_val;//define these variables</p>
<p>void setup() </p>
<p>void loop()</p>
<p></p>
<p>void tracking()</p>
<p></p>
<p>else if (L_val == 0 &amp;&amp; R_val == 1) </p>
<p>else </p>
<p>}</p>
<p>else </p>
<p>else if (L_val == 0 &amp;&amp; R_val == 1) </p>
<p>else </p>
<p>}</p>
<p>}</p>
<p>void front()//define the status of going forward</p>
<p></p>
<p>void back()//define the state of going back</p>
<p></p>
<p>void left()//define the left-turning state</p>
<p></p>
<p>void right()//define the right-turning state</p>
<p></p>
<p>void Stop()//define the state of stop</p>
<p></p>
<p>//this function is used for dot matrix display</p>
<p>void matrix_display(unsigned char matrix_value[])</p>
<p></p>
<p>IIC_end(); //End pattern data transmission</p>
<p>IIC_start();</p>
<p>IIC_send(0x8A); //Display control, select 4/16 pulse width</p>
<p>IIC_end();</p>
<p>}</p>
<p>//Conditions under which data transmission begins</p>
<p>void IIC_start()</p>
<p></p>
<p>//Indicates the end of data transmission</p>
<p>void IIC_end()</p>
<p></p>
<p>//transmit data</p>
<p>void IIC_send(unsigned char send_data)</p>
<p> else </p>
<p>delayMicroseconds(3);</p>
<p>digitalWrite(SCL_Pin, HIGH); //Pull the clock pin SCL_Pin high to stop data transmission</p>
<p>delayMicroseconds(3);</p>
<p>digitalWrite(SCL_Pin, LOW); //pull the clock pin SCL_Pin low to change the SIGNAL of SDA</p>
<p>}</p>
<p>}</p>
<p>//*************************************************************************</p></td>
</tr>
</tbody>
</table>

**5.Test Result**

After successfully uploading the code to the V4.0 board, connect the
wirings according to the wiring diagram, power on the external power
then turn the DIP switch to ON. Then the smart car will walk along the
lines.
