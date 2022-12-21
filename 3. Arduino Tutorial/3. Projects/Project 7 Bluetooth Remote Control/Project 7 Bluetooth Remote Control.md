# Project 7 Bluetooth Remote Control

**1.Description**

![](/media/aa5546baeb5afe1adfe9fff51f497fe8.png)There is a DX-BT24 5.1 Bluetooth module in this
kit. This bluetooth module comes with 256Kb space and complies with
V5.1BLE bluetooth specification, which supports AT commands. Users can
change parameters such as the baud rate and device name of the serial
port as required.

Furthermore, it supports UART interface and bluetooth serial port
transparent transmission, which also contains the advantages of low
cost, small size, low power consumption and high sensitivity for sending
and receiving. Notably, it solely needs a few peripheral components to
realize its powerful functions.  

**2.Specification**

  - Bluetooth protocol: Bluetooth Specification V5.1 BLE

  - Working distance: In an open environment, it can achieve 40m
    ultra-long distance communication

  - Operating frequency: 2.4GHz ISM band

  - Communication interface: UART

  - Bluetooth certification: [Accord](javascript:;) with FCC CE ROHS
    REACH certification standard

  - Serial port parameters: 9600, 8 data bits, 1 stop bit, invalid bit,
    no flow control

  - Power: 5V DC

  - Operating temperature: –10℃ to +65℃
    
    **3.Application**

The DX-BT24 module also supports the BT5.1 BLE protocol, which can be
directly connected to iOS devices with BLE Bluetooth function, and
supports resident running of background programs. It is mainly used in
the field of short-distance data wireless transmission. It enables to
avoid cumbersome cable connections and can directly replace serial
cables. Successful application areas of BT24 modules:

※ Bluetooth wireless data transmission;

※ Mobile phone, computer peripheral equipment;

※ Handheld POS equipment;

※ Wireless data transmission of medical equipment;

※ Smart home control;

※ Bluetooth printer;

※ Bluetooth remote control toys;

※ Shared bicycles;

**4.Ports**

![](/media/cd97cf79ff5cdd5bbd78f4cc960d38e5.png)①STATE：Status pin

②RX：Receiving pin

③TX：sending pin

④GND：GND

⑤VCC：Power

⑥EN：Enable pin

Connect the BT module to the development board.

<table>
<tbody>
<tr class="odd">
<td>Uno</td>
<td>BT24</td>
</tr>
<tr class="even">
<td>TX</td>
<td>RX</td>
</tr>
<tr class="odd">
<td>RX</td>
<td>TX</td>
</tr>
<tr class="even">
<td>VCC</td>
<td>5V</td>
</tr>
<tr class="odd">
<td>GND</td>
<td>GND</td>
</tr>
</tbody>
</table>

**5.Components**

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
<td>DX-BT24 Bluetooth Module*1</td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/e9aaac06e62418ecca6eaba97a9ec518.png" style="width:1.03056in;height:0.66667in" /></td>
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/4f8d5af6dee9016b45d975adb2391d37.png" style="width:1.38611in;height:0.5125in" /></td>
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/0c5987e68104f7bd84cc971a52c3d3db.png" style="width:1.41736in;height:0.54167in" /></td>
</tr>
</tbody>
</table>

**6.Wiring Diagram**

![](/media/63b96e5b26ee18337fb6e0dced5bbbe3.png)

RXD, TXD, GND and VCC of the BT module are connected to TX, RX, G and
5V.

STATE and BRK of the BT module don’t need connection.

Note the direction of the BT module when inserting it onto the 8833
board. And don’t insert it before uploading the code.

**7.Test Code**

    //***********************************************************************
    /*
    keyestudio 4wd BT Car
    lesson 7.1
    Bluetooth 
    http://www.keyestudio.com
    */
    char ble_val; //character variable, used to store the value received by Bluetooth 
    
    
    void setup() {
      Serial.begin(9600);
    }
    void loop() {
      if(Serial.available() > 0)  //make sure if there is data in serial buffer
      {
        ble_val = Serial.read();  //Read data from serial buffer
        Serial.println(ble_val);  //Print
      }
    }
    //***********************************************************************


**8.Test Result**

Don’t connect the BT module when uploading the code because serial
communication port will be occupied when uploading code and inserting
the BT module.

After successfully uploading the code to the V4.0 board, connect the
wirings according to the wiring diagram, then connect the computer via a
USB cable to power the board. After powering on, insert the BT module
and the LED will flash, then we need to download the BT app.

**9.Download Bluetooth APP**

**Apple system**

1.  Open the App Store on the iPhone.

2.  Search keyes BT car and download the APP to your phone.
    
    ![](/media/b3e1a209b1dbe6800c327a868379b1de.png)
    
    After installation, enter its interface.
    
    ![](/media/e6d0abe92ad337a425af6cb0d63e4954.png)
    
    Click "Connect" button in the upper left corner to automatically
    search for Bluetooth. When BT24 is found, click "Connect" to connect
    Bluetooth, and then click ![](/media/e3b7b4c2ed5b85ce402998208ab0bb1e.png)to enter the
    control interface of 4WD smart car. 
    
    ![](/media/8a3a43db2709f3231fcc78f3e5fec26f.png)
    
    [**Android System**](javascript:;)
    
    Enter google play store to search for“keyes 4wd”

![](/media/66cce2fc4a3ae3f88db1b56a5b341fac.png)

The app icon is shown below after installation.

![](/media/c2a01ef689e3134df31f6d25f7acb946.png)

Click app to enter the following page.

![](/media/b0ab7f5ddd031e3f50565fcb06a88fce.png)

After connecting Bluetooth, plug in power and LED indicator of Bluetooth
module will flicker. Tap“Connect”to search the Bluetooth.

![](/media/585be11142e72188c4ebabe13b32ed43.jpeg)

When BT24 is found, click "connect" to connect Bluetooth. When "connect"
turns into "is connected", it indicates that the Bluetooth connection is
successful. As shown in the picture below, the Bluetooth LED becomes
will stay on.

![](/media/e2469e9e301ba17962382942a697892d.jpeg)

After connecting Bluetooth module, open serial monitor to set baud rate
to 9600. Pressing the button of the Bluetooth APP, and the corresponding
characters will be displayed, as shown below:

![](/media/c4c99cc8f66d33243e62bbeba71a0807.png)

<table>
<tbody>
<tr class="odd">
<td>Key</td>
<td>Function</td>
<td></td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/3b4076135ebca73f47c4ff8d7785dc17.png" style="width:0.86736in;height:0.29514in" /></td>
<td>Pair DX-BT24 5.1 Bluetooth module</td>
<td></td>
</tr>
<tr class="odd">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/3b4076135ebca73f47c4ff8d7785dc17.png" style="width:0.99653in;height:0.28403in" /></td>
<td>Disconnect Bluetooth</td>
<td></td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/3b4076135ebca73f47c4ff8d7785dc17.png" style="width:0.46806in;height:0.48611in" /></td>
<td>Control character</td>
<td>Function</td>
</tr>
<tr class="odd">
<td></td>
<td><p>Press: F</p>
<p>Release: S</p></td>
<td>Press the button, the car goes front; release to stop</td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/3b4076135ebca73f47c4ff8d7785dc17.png" style="width:0.46875in;height:0.46597in" /></td>
<td><p>Press: L</p>
<p>Release: S</p></td>
<td>Press the button, the car turns left; release to stop</td>
</tr>
<tr class="odd">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/3b4076135ebca73f47c4ff8d7785dc17.png" style="width:0.45069in;height:0.46736in" /></td>
<td><p>Press: R</p>
<p>Release: S</p></td>
<td>Press the button, the car turns right; release to stop</td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/3b4076135ebca73f47c4ff8d7785dc17.png" style="width:0.45208in;height:0.475in" /></td>
<td><p>Press: B</p>
<p>Release: S</p></td>
<td>Press the button, the car goes back; release to stop</td>
</tr>
<tr class="odd">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/049343f587e0e7cf19fe8b665d735321.png" style="width:0.95833in;height:0.52153in" /></td>
<td><p>Press: “a”</p>
<p>Release: “S”</p></td>
<td>Click to speed up(maximum:255)</td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/264f77cce6018584b54f46676fee4247.png" style="width:0.96875in;height:0.53819in" /></td>
<td><p>Press: “d”</p>
<p>Release: “S”</p></td>
<td><p>Click to slow down</p>
<p>(minimum:0)</p></td>
</tr>
<tr class="odd">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/3b4076135ebca73f47c4ff8d7785dc17.png" style="width:0.59931in;height:0.59514in" /></td>
<td>Click to start the gravity sensing function of the mobile phone: click again to exit the gravity sensing control </td>
<td></td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/98b616f6b64e044150932624040ba20b.png" style="width:0.59097in;height:0.61319in" /></td>
<td>Click to send“X”, click again to send“S”</td>
<td>Start line tracking function; click again to exit</td>
</tr>
<tr class="odd">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/84d5bb67fc8d6dfcc2aa950adc71dd21.png" style="width:0.59028in;height:0.6125in" /></td>
<td>Click to send“Y”, click again to send“S”</td>
<td>Start ultrasonic avoiding function; click again to exit</td>
</tr>
<tr class="even">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/070f44577bcc6532cda2d9fdcfaf455f.png" style="width:0.59028in;height:0.64653in" /></td>
<td>Click to send“U”, click again to send“S”</td>
<td>Start ultrasonic follow function; click again to exit</td>
</tr>
<tr class="odd">
<td><img src="https://raw.githubusercontent.com/keyestudio/KS0559-KS0559F-Keyestudio-4WD-BT-Multi-purpose-Car-V2.0-Arduino/master/media/6eed80e22c0b1264f2407fc6a5e93af2.png" style="width:0.56597in;height:0.64583in" /></td>
<td>Click to send“G”, click again to send“S”</td>
<td>Start restricting function; click again to exit</td>
</tr>
</tbody>
</table>

**10.Code Explanation**

**Serial.available()** : Return the number of characters currently
remaining in the serial port buffer. Generally, this function is used to
judge whether there is data in the buffer of the serial port. When
Serial.available()\>0, it means that the serial port has received data
and can be read;

**Serial.read() :** Refers to taking out and reading a Byte of data from
the serial port buffer. For example, if a device sends data to Arduino
through the serial port, we can use Serial.read() to read the sent data.

**11.Extension Practice**

Here we look to use the command sent by the mobile phone to turn on or
off an LED light. Looking at the wiring diagram, an LED is connected to
the D9 pin.

![](/media/1a719bb514db5eb134cfa943bd138e52.png)

    //****************************************************************************
    /*
     keyestudio smart turtle robot
     lesson 7.2
     Bluetooth LED
     http://www.keyestudio.com
    */ 
    int ledpin=9;
    char ble_val;// An integer variable used to store the value received by Bluetooth
    
    void setup()
    {
      Serial.begin(9600);
      pinMode(ledpin,OUTPUT);
    }
    
    void loop()
    { 
      if (Serial.available() > 0) //Check whether there is data in the serial port cache
      {
        ble_val = Serial.read();  //Read data from the serial port cache
        Serial.print("DATA RECEIVED:");
        Serial.println(ble_val);
        if (ble_val == 'F') {
          digitalWrite(ledpin, HIGH);
          Serial.println("led on");
        }
        if (ble_val == 'B') {
          digitalWrite(ledpin, LOW);
          Serial.println("led off");
        }
       }
    }
    //****************************************************************************


After successfully uploading the code to the V4.0 board, connect the
wirings according to the wiring diagram, then connect the computer via a
USB cable to power the board. After powering on,
click![](/media/3b4076135ebca73f47c4ff8d7785dc17.png)to
control the LED**.**
