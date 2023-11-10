# Assemble Robot

1.1. Components Needed.

![Img](./media/img-20231030144203.png)

1.2. Installation Diagram.

![Img](./media/img-20231030144628.png)

1.3. Prototype.

![Img](./media/img-20231030144718.png)

2.1. Components Needed.

![Img](./media/img-20231030144955.png)

2.2. Installation Diagram.

![Img](./media/img-20231030145034.png)

![Img](./media/img-20231030145102.png)

![Img](./media/img-20231030145109.png)

2.3. Prototype.

![Img](./media/img-20231030145230.png)

3.1. Components Needed.

![Img](./media/img-20231030145508.png)

![Img](./media/img-20231030145518.png)

3.2. Installation Diagram.

![Img](./media/img-20231030145624.png)

3.3. Plug Wire.

![Img](./media/img-20231030145642.png)

3.4. Prototype.

![Img](./media/img-20231030145659.png)

4.1. Components Needed.

![Img](./media/img-20231030145754.png)

4.2. Rotate the servo to 90 degrees.

![Img](./media/img-20231030152952.png)

```c
//*****************************************************************
/*
Set the 90-degree code,Copy the code and upload it to the development board. The steering gear connected to port A3 will rotate to 90 °
*/
#define servoPin A3  //servo Pin
int pos; //the angle variable of servo
int pulsewidth; // pulse width variable of servo
void setup() {
  pinMode(servoPin, OUTPUT);  //set servo pin to OUTPUT
  procedure(0); //set the angle of servo to 0°
}
void loop() {

    procedure(90);              // tell servo to go to position in variable 90°

}
// function to control servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //calculate the value of pulse width
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   //The duration of high level is pulse width
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  // the cycle is 20ms, the low level last for the rest of time
}
//*****************************************************************
```

<span style="color: rgb(255, 76, 65);">**Copy the above code to arduino IDE, then upload the code to the V4.0 motherboard, after uploading it successfully, the servo will rotate to the 90° position**.</span>
<br>
<br>

4.3. Installation Diagram.

![Img](./media/img-20231030150427.png)

![Img](./media/img-20231030150435.png)

![Img](./media/img-20231030150500.png)

![Img](./media/img-20231030150519.png)

4.4. Prototype.

![Img](./media/img-20231030150546.png)

5.1. Components Needed.

![Img](./media/img-20231030150735.png)

5.2. Installation Diagram.

![Img](./media/img-20231030150830.png)

![Img](./media/img-20231030150837.png)

5.3. Prototype.

![Img](./media/img-20231030150855.png)

6.1. Components Needed.

![Img](./media/img-20231030150916.png)

![Img](./media/img-20231030150919.png)

6.2. Installation Diagram.

![Img](./media/img-20231030150939.png)

![Img](./media/img-20231030150947.png)

6.3. Prototype.

![Img](./media/img-20231030151008.png)

7.1. Components Needed.

![Img](./media/img-20231030151039.png)

7.2. Installation Diagram.

![Img](./media/img-20231030151152.png)

![Img](./media/img-20231030151215.png)

7.3. Prototype.

![Img](./media/img-20231030151703.png)

8.1. Wiring Diagram.

![Img](./media/img-20231030151721.png)

8.2. M2 Motor is connected to B interface,，M3 Motor is connected to A interface.

![Img](./media/img-20231030151819.png)

8.3. M1 Motor is connected to B1 interface，M4 Motor is connected to A1 interface.

![Img](./media/img-20231030151838.png)

8.4. The wiring of the 3-channel line-tracking sensor.

![Img](./media/img-20231030151903.png)

8.5. The power supply is connected to BAT.

![Img](./media/img-20231030151923.png)

8.6. The wiring of the ultrasonic sensor.

![Img](./media/img-20231030153533.png)

![Img](./media/img-20231030152013.png)

8.7. The wiring of the 8*16 LED Board.

![Img](./media/img-20231030153640.png)

![Img](./media/img-20231030154056.png)

8.8. The wiring of the servo.

![Img](./media/img-20231030154247.png)

![Img](./media/img-20231030154300.png)

8.9. Plug in the Bluetooth module and jumper caps.

![Img](./media/img-20231030152216.png)

<span style="color: rgb(255, 76, 65);">**Note:** Before uploading the test code, you need to remove the Bluetooth module, otherwise the code will fail to be uploaded.Connect the Bluetooth module after uploading the code successfully.</span>

<br>
<br>

8.10. Complete Prototype.

![Img](./media/img-20231030152243.png)














                    