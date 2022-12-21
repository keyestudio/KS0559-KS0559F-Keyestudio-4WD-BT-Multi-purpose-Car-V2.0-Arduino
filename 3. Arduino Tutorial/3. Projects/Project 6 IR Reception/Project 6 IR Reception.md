# Project 6 IR Reception

**1.Description** 

![](/media/f247e1010aa68c1e58e16b332680698a.png)There is no doubt that infrared remote control is
ubiquitous in daily life. It is used to control various household
appliances, such as TVs, stereos, video recorders and satellite signal
receivers. Infrared remote control is composed of infrared transmitting
and infrared receiving systems, that is, an infrared remote control and
infrared receiving module and a single-chip microcomputer capable of
decoding.  

![](/media/df5f1c28b8863b42ff94a36a6d81b933.png)

The 38K infrared carrier signal emitted by remote controller is encoded
by the encoding chip in the remote controller. It is composed of a
section of pilot code, user code, user inverse code, data code, and data
inverse code. The time interval of the pulse is used to distinguish
whether it is 0 or 1 signal and the encoding is made up of these 0, 1
signals.

The user code of the same remote control is constant while the data code
can distinguish the key.

When the remote control button is pressed, the remote control sends out
an infrared carrier signal. When the IR receiver receives the signal,
the program will decode the carrier signal and determines which key is
pressed. The MCU decodes the received 01 signal, thereby judging what
key is pressed by the remote control.

Infrared receiver we use is an infrared receiver module. Mainly composed
of an infrared receiver head, which is a device that integrates
reception, amplification, and demodulation. Its internal IC has
completed demodulation, and can achieve from infrared reception to
output and be compatible with TTL signals.

Additionally, it is suitable for infrared remote control and infrared
data transmission. The infrared receiving module made by the receiver
has only three pins, signal line, VCC and GND. It is very convenient to
communicate with Arduino and other microcontrollers.

**2.Specification**

![](/media/f247e1010aa68c1e58e16b332680698a.png)Operating Voltage: 3.3-5V（DC）

Output Signal: Digital signal

Receiving Angle: 90 degrees

![](/media/5ad0f889b39646ecb13664511479efc8.png)Frequency: 38khz

Receiving Distance: 10m

The right picture shows the real product and circuit diagram of the
infrared receiver

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
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/7aacff28b0cb9b99f0dbcbf22eb309e4.png" style="width:0.91111in;height:0.61111in" /></td>
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

Since the 8833 board integrates with the IR receiver, it doesn’t need
wiring up.

Pins of IR receiver module are G(GND）, V（VCC）and D3.

**4.Test Code**

    //*************************************************************************************
    /*
     keyestudio 4wd BT Car
     lesson 6.1
     IR remote
     http://www.keyestudio.com
    */ 
    #include <IRremote.h>     //IRremote library statement  
    int RECV_PIN = 3;        //define the pins of IR receiver as D3
    IRrecv irrecv(RECV_PIN);   
    decode_results results;   // decode results exist in the“result” of “decode results”
    void setup()  
    {  
      Serial.begin(9600);  
      irrecv.enableIRIn(); // Enable receiver 
    }  
      
     void loop() {  
      if (irrecv.decode(&results))//decode successfully, receive a set of infrared signals  
       {  
         Serial.println(results.value, HEX);//Wrap word in 16 HEX to output and receive code 
         irrecv.resume(); // Receive the next value
       }  
       delay(100);  
     } 
    //*************************************************************************************


**5.Test Result**

After successfully uploading the code to the V4.0 board, connect the
wirings according to the wiring diagram, then connect the computer via a
USB cable to power the board. After powering on, open the serial monitor
and set baud rate to 9600.

Take out the remote control, and send signal to the infrared receiver
sensor. You can see the key value of the corresponding key, if the key
time is too long, FFFFFFFF is prone to garbled characters.

![](/media/92887b989e103ef082569bbb34817852.png)

The keys value of Keyestudio remote control are shown below.

> ![](/media/ebcf0cb2055f7784505f76ceeaef9f47.jpeg)

**6.Code Explanation**

**irrecv.enableIRIn():** After enabling IR decoding, the IR signals will
be received,

**decode():** The function“decode()”will check continuously to make sure
if decoding successfully.

**irrecv.decode(\&results):** after decoding successfully, this function
will come back to “true”, and keep result in “results”. After decoding
the IR signals, run the resume()function and continue to receive the
next signal.

**7.Extension Practice**

We have decoded the key value of the IR remote control. How about
controlling LED by the measured value? We could design an experiment.

Attach an LED to D9, then press the keys of remote control to make LED
light on and off.

![](/media/2138e6654076fc28e1715cebf9a87795.png)

    //*************************************************************************************
    /* 
    keyestudio 4wd BT Car
    lesson 6.2
    IR remote LED
    http://www.keyestudio.com
    */ 
    #include <IRremote.h>
    int RECV_PIN = 3;//define the pin of IR receiver as D3
    int LED_PIN = 9;//define the pin of LED as pin 9
    int a=0;
    IRrecv irrecv(RECV_PIN);
    decode_results results;
    
    void setup()
    {Serial.begin(9600);
      irrecv.enableIRIn(); //Initialize the IR receiver
      pinMode(LED_PIN,OUTPUT);//set pin 9 of LED to OUTPUT
    }
    
    void loop() {
      if (irrecv.decode(&results)) 
      {
        if(results.value==0xFF02FD && (a==0)) //according to the above key value, press“OK”on remote control , LED will be controlled
        {
          Serial.println("HIGH");
          digitalWrite(LED_PIN,HIGH);//LED will be on
          a=1;
        }
        else if(results.value==0xFF02FD && (a==1)) //press again
        {
          Serial.println("LOW");
          digitalWrite(LED_PIN,LOW);//LED will go off
          a=0;
        }
        irrecv.resume(); // receive the next value
      }
    }
    //*************************************************************************************


After successfully uploading the code to the V4.0 board, connect the
wirings according to the wiring diagram, then connect the computer via a
USB cable to power the board. After powering on, press the OK key on
remote control can make the LED on and off.
