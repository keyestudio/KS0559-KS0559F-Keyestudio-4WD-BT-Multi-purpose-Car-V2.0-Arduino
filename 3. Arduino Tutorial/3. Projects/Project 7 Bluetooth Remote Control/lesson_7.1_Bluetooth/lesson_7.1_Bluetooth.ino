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
