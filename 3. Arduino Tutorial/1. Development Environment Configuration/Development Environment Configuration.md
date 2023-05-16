# 4.Development Environment Configuration

## 1.Get Started With Arduino 

### **1.1 Install the Arduino IDE**

![](/media/6cf6312dc7c7db27794b54d58a8bf80c.png)

When you get control board, you need to download Arduino IDE and driver firstly.

You could download Arduino IDE from the official website:

<https://www.arduino.cc/>, click the **SOFTWARE** on the browse bar, click“DOWNLOADS” to enter download page, as shown below:

![](/media/4636aac9aca9b3aa9d86580caac51b81.png)

There are various versions of IDE for Arduino such as Windows，Mac as well as Linux(as shown below). Just download a version compatible with your system.

![](/media/a964bfdcfb4a1ae25e5698623c5fc6bf.png)

Here we will show you how to download and install the windows version of Arduino IDE.

There are two versions of IDE for Windows system. You can choose between the installer (.exe) and the Zip file. For installer, it can be directly downloaded, without the need of installing it manually. However, for Zip package, you will need to install the driver manually.

![](/media/3d3e36e47f8c7009155f0e8cc256ead1.png)

![](/media/745910f7138b08d5cbcb557f194b0679.png)

You just need to click JUST DOWNLOAD.

### **1.2 Install the Driver of the V4.0 Board**

Let’s install the driver of keyestudio V4.0 development board. The USB-TTL chip on the V4.0 board adopts the CP2102 serial chip. The driver program of this chip is included in Arduino 1.8 version and above (<https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers>), which is convenient. Plugging on USB port of board, the computer can recognize the hardware and automatically install the driver of CP2102.

If you install unsuccessfully, or intend to install manually, please open the device manager of computer. Right click Computer----- Properties----- Device Manager. 

![](/media/9af2e34bf9bdd6675bdf5fa8cd291971.png)

The yellow exclamation mark on the page implies an unsuccessful installation and you should double click ![](/media/a2455b26773cb8d6cb3fccc605ea4dd7.png), then click “**Update Drive...**”to update the driver.

![](/media/a122cd6fef74eb5c0c7fe16fac2fed59.png)

Click“**Browse my computer for drivers**”to find the downloaded Arduino software.

![](/media/a02d3e643231cfe267d4debf0ef258c4.png)

There is a DRIVERS folder in Arduino software installed package, open the driver folder and check the driver of CP210X series chips.

Click “Browse”, then search the driver of CP2102 and click“Next”,

![](/media/eb6ca318005b5c570ad4fbef73024351.png)

After a while, the driver is installed successfully

![](/media/4f2af46602a5ef73985914170911c519.png)

When opening the device manager, we will find the yellow exclamation mark disappear. The driver of CP2102 is installed successfully.

![](/media/af2324b73308f1796b8b7c9dc14878e7.png)

### **1.3 Install Other Visions of Driver**

If your board is an Arduino UNO development board, follow these steps to install the driver: 

First, click Computer Properties - Device Manager , then the unknown hardware will be displayed.

![](/media/e492989170473f2e77a97902f996d1ba.png)

Second, click “Update Drive...”to update the driver

![](/media/d7f62064e3eef1a4926cbc609253af5c.png)

Then click“**Browse my computer for driver software**”

![](/media/9fd75e90e09605342e00b47bdd416654.png)

Click "Browse..."  to find the location where the Arduino software is installed on your computer, then open the drivers folder, and click "Next".

![](/media/9e9be87771ff1b78050d7f05f48063df.png)

The driver is installed successfully

![](/media/56f5dff1b1242a47b9244357f5519ede.png)

At this time, open the computer device manager, which will display Arduino serial port. 

![](/media/09e91fee277b7a69b8ad57ffa3294d48.png)

### **1.4 Arduino IDE** **Setting**

Click![](/media/675ae7298ce0973df720b2fbbb514caa.png)icon，and open Arduino IDE.

![](/media/e9a2d59afcff8121d18d8767326baa42.png)

To avoid any errors when uploading the program to the board, you must select the correct name of Arduino board that matches the board connected to your computer. As shown below:

![](/media/84317a7babddff172520b99756dc1f85.png)

Then select the correct COM port (you can see the corresponding COM port after the driver is successfully installed)

![](/media/af2324b73308f1796b8b7c9dc14878e7.png)

![](/media/bcd36a3d3e1209c16866e554089832d5.png)

![](/media/2598b31529ac4bff88630522b97b6c41.png)

A- Used to verify whether there is any compiling mistakes or not.

B- Used to upload the sketch to your Arduino board.

C- Used to create shortcut window of a new sketch.

D- Used to directly open an example sketch.

E- Used to save the sketch.

F- Used to send the serial data received from board to the serial monitor.

### **1.5 Start First Program**

Open the file to select **Example**, and click **BASIC**\>**BLINK**, as shown below:

![](/media/2a6a0b8b8e2585776e01873caf10a1b0.png)

![](/media/6030cde1341c3432f0f4b1fb6c92e49e.png)

Set the correct **COM port,** and the corresponding board and COM port are shown on the lower right of IDE.

![](/media/5c4521f3fa5c4f4c0a5c9d1581ab1580.png)

Click ![](/media/ddd21c81338ae1f6b7f84de2a3caecf0.png) to start compiling the program

![](/media/9948cd36a3b39cb57fd2bea79540c4b7.png)

Click![](/media/9c9158a5d49baa740ea2f0048f655017.png)to upload the program

![](/media/60e002aacf662c1ecf88ad3ecd85e6ca.png)

After the program is uploaded successfully, the onboard LED will be on for 1s and off for 1s. Congratulation, you have finished the first program.

## 2. Install the Driver on MAC System 

![](/media/a6fc83596009c574d8e29ef383748549.png)

### **2.1 Download Arduino IDE**

![](/media/5d58d3cf67b308423ddb9f286f6cb697.png)

### **2.2 How to Install the CP2102 Driver**

(Note: If you haven’t installed the driver installed, please do the following.) 

(1) Connect the keyestudio V4.0 development board to your MacOS computer using a USB cable and open the Arduino IDE. 

![image-20230420151837146](media/image-20230420151837146.png)

Click **Tools→Board: Arduino Uno** and **/dev/cu.usbserial-0001.**

![](/media/37689ea487b506d66f8ee82a8e1418b9.png)

Click![](/media/9c9158a5d49baa740ea2f0048f655017.png)to upload the test code

![](/media/4c804ad604a9fc682d5c472387039dfc.png)

Note: If the the upload fails, follow the steps below to install the CP2102 driver.  Perform steps (2) to (16). 

(2）Download link for CP2102：

[<span class="underline">https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers</span>](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

（3）Download MacOS version

![](/media/c09e7c279a858574756d1192b3a995aa.png)

（4）Unzip the downloaded package

![](/media/6870a714ddd11015dc43b1d5743e0666.jpeg)

（5）Open the folder and double-click“SiLabsUSBDriverDisk.dmg”file

![](/media/61ae3e706a1c4afa7948d5fb2e797a6d.png)

Then you can see the following file

![](/media/3f1afe9499f6d852492cfb9d6b11e9ab.jpeg)

（6）Double-click**“Install CP210x VCP Driver”，tap**“**Don’t warn me when opening application on this disk image**”and click“**Open**”.

![](/media/14f6ebb088e654abc2f0149645e34ed1.png)

（7）Click“**Continue**”

![](/media/b1cb125dccf6470ebe255f8f65b902eb.jpeg)

（8）Click“**Agree**”，then tap“**Continue**”

![](/media/865dcc76cb7f58854b56f1020233f05e.jpeg)

（9）Click“**Continue**”，then input your user password

![](/media/1ef6d65b61ad7c6e0a3989ba59de74d5.jpeg)

![](/media/29bbca3360d806164717733460574356.png)

10. Select“**Select Open Security Preferences**”
    
    ![](/media/ca6bc6e536202f07a53c09201a0996ff.png)
    
    11. Click on security lock and enter your user password to authorize.
    
    ![](/media/cb6be428257143635fc4f729487549c5.jpeg)
    
    ![](/media/e8f637a3a9510aa8f90c65820d4d1cd8.jpeg)
    
    12. When you see that the lock is opened, click "Allow" 
    
        ![](/media/250a1cbb7f93fc2a572944bea9fe5494.jpeg)
    
    13. Return to the installation interface and wait for the installation as prompted.
    
    ![](/media/0da6d0d4296d6e3de0b30dfd3c615265.jpeg)
    
    14. The installation is successful
    
    ![](/media/7cca827fe946096f228797dadce10661.jpeg)

15. Open arduinoIDE，click“**Tools**”and tap **Arduino Uno** and“**/dev/cu.SLAB\_USBtoUAPT**”

![](/media/607c04e130d93839efb5228623ae0656.jpeg)

16. Click![](/media/9c9158a5d49baa740ea2f0048f655017.png)to upload the program, and you can see the program burned successfully

![](/media/16cee842865ba86e42468b67c17c415c.png)



## 3.How to Add a Library?

### **3.1 What are Libraries ?**

[Libraries ](https://www.arduino.cc/en/Reference/Libraries)are a collection of code that make it easy for you to connect a sensor,display, module, etc.

For example, the built-in LiquidCrystal library helps talk to LCD displays. There are hundreds of additional libraries available on the Internet for download.

The built-in libraries and some of these additional libraries are listed in the reference.

### **3.2 How to Install a Library ?**

Here we will introduce the most simple way to add libraries .

**Step 1：**After downloading well the Arduino IDE, you can right-click the icon of Arduino IDE. Find the option "Open file location"

![](/media/f1d5fd3883e0997ca46dcf8513733c46.png)

**Step 2:** Click Open file location \>libraries

![](/media/d65edbf3dd79595c741e7e7049334e90.png)

**Step 3：**Next, find out the“libraries”folder. Copy them into libraries of Arduino

![](/media/ee8afbe08ef711f08e89e46b42654662.png)

![](/media/d04bfda97a6a2fb11f28a3c78b72700c.png)
