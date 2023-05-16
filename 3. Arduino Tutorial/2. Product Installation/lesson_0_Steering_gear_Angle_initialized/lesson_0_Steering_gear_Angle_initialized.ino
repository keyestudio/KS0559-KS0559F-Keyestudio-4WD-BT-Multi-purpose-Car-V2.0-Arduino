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
