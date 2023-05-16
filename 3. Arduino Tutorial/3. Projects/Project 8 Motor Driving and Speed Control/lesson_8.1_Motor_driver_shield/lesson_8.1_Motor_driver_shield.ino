//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.1
 Motor driver shield
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //define the direction control pins of group B motor
#define ML_PWM 5   //define the PWM control pins of group B motor
#define MR_Ctrl 4    //define the direction control pins of group A motor
#define MR_PWM 6   //define the PWM control pins of group A motor

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//set direction control pins of group B motor to output
  pinMode(ML_PWM, OUTPUT);//set PWM control pins of group B motor to output
  pinMode(MR_Ctrl, OUTPUT);//set direction control pins of group A motor to output
  pinMode(MR_PWM, OUTPUT);//set PWM control pins of group A motor to output
}
void loop()
{ 
  //front
  digitalWrite(ML_Ctrl,HIGH);//set the direction control pins of group B motor to HIGH
  analogWrite(ML_PWM,55);//set the PWM control speed of group B motor to 55
  digitalWrite(MR_Ctrl,HIGH);//set the direction control pins of group A motor to HIGH
  analogWrite(MR_PWM,55);// set the PWM control speed of group A motor to 55
  delay(2000);//delay in 2000ms
  //back
  digitalWrite(ML_Ctrl,LOW);//set the direction control pins of group B motor to LOW level
  analogWrite(ML_PWM,200);// set the PWM control speed of group B motor to 200 
  digitalWrite(MR_Ctrl,LOW);//set the direction control pins of group A motor to LOW level
  analogWrite(MR_PWM,200);//set the PWM control speed of group A motor to 200
  delay(2000);//delay in 2000ms
  //left
  digitalWrite(ML_Ctrl,LOW);//set the direction control pins of group B motor to LOW level
  analogWrite(ML_PWM,200);//set the PWM control speed of group B motor to 200 
  digitalWrite(MR_Ctrl,HIGH);//set the direction control pins of group A motor to HIGH level
  analogWrite(MR_PWM,55);//set the PWM control speed of group A motor to 200
  delay(2000);//delay in 2000ms
  //right
  digitalWrite(ML_Ctrl,HIGH);//set the direction control pins of group B motor to HIGH level
  analogWrite(ML_PWM,55);//set the PWM control speed of group B motor to 55 
  digitalWrite(MR_Ctrl,LOW);// set the direction control pins of group A motor to LOW level
  analogWrite(MR_PWM,200);//set the PWM control speed of group A motor to 200
  delay(2000);//delay in 2000ms
  //stop
  digitalWrite(ML_Ctrl, LOW);// set the direction control pins of group B motor to LOW level
  analogWrite(ML_PWM,0);//set the PWM control speed of group B motor to 0
  digitalWrite(MR_Ctrl, LOW);// set the direction control pins of group A motor to LOW level
  analogWrite(MR_PWM,0);//set the PWM control speed of group A motor to 0
  delay(2000);// delay in 2000ms
}
//****************************************************************************
