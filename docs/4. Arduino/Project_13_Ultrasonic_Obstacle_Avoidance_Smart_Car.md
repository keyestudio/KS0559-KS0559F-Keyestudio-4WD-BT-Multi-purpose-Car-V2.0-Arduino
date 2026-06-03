# Project 13 超音波障害物回避スマートカー

![fd4044796307f709987b9d2e215e0911](media/A119.png)

### **1.説明**

このプロジェクトでは、超音波を使った障害物回避スマートカーを作成します。超音波センサーで障害物までの距離を検出し、その情報を使ってサーボを回転させ、車を動かします。同時に、8X16 LEDボードに対応する状態パターンを表示します。

### **2.フローチャート**

![img](media/A120.png)

**超音波障害物回避スマートカーの具体的なロジックは以下の通りです：**

![Img](media/A121.png)

![Img](media/A122.png)

### **3.配線図**

![](media/A118.png)

1). 8\*8 LEDボードモジュールのGND、VCC、SDA、SCLは拡張ボードのG（GND）、V（VCC）、A4、A5に接続します。

2). 超音波センサーのVCC、Trig、Echo、GNDはそれぞれ5V(V)、D12(S)、D13(S)、GND(G)に接続します。

3). サーボはG、V、A3に接続します。茶色の線はGND(G)、赤色の線は5V(V)、オレンジ色の線はA3に接続します。

4). 電源はBATポートに接続します。

### **4.テストコード**

```c 
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 13
 Avoiding Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //クロックピンをA5に設定
#define SDA_Pin  A4  //データピンをA4に設定
//パターンのデータを格納する配列。自分で計算するかモジュールツールから取得可能
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//グループBモーターの方向制御ピンを定義
int left_pwm = 5;//グループBモーターのPWM制御ピンを定義
int right_ctrl = 4;//グループAモーターの方向制御ピンを定義
int right_pwm = 6;//グループAモーターのPWM制御ピンを定義

#include "SR04.h"//超音波センサーのライブラリを定義
#define TRIG_PIN 12//超音波センサーの信号出力をD12に設定
#define ECHO_PIN 13//超音波センサーの信号入力をD13に設定
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance,a1,a2;//3つの距離を定義
const int servopin = A3;//サーボのピンをA3に設定

void setup() {
  pinMode(left_ctrl,OUTPUT);//グループBモーターの方向制御ピンを出力に設定
  pinMode(left_pwm,OUTPUT);//グループBモーターのPWM制御ピンを出力に設定
  pinMode(right_ctrl,OUTPUT);//グループAモーターの方向制御ピンを出力に設定
  pinMode(right_pwm,OUTPUT);//グループAモーターのPWM制御ピンを出力に設定
  pinMode(TRIG_PIN, OUTPUT); //Trigピンを出力に設定
  pinMode(ECHO_PIN, INPUT); //Echoピンを入力に設定
  servopulse(servopin,90);//サーボの角度を90度に設定
  delay(300);
  pinMode(SCL_Pin,OUTPUT);//クロックピンを出力に設定
  pinMode(SDA_Pin,OUTPUT);//データピンを出力に設定
  matrix_display(clear);
}
 
void loop()
 {
  avoid();//メインプログラムを実行
}

void avoid()
{
  distance=sr04.Distance(); //超音波センサーで検出した値を取得

  if((distance < 20)&&(distance != 0))//距離が0より大きく20未満の場合  

  {
    car_Stop();//停止
    matrix_display(clear);
    matrix_display(STOP01);//停止パターンを表示
    delay(1000);
    servopulse(servopin,160);//サーボを160°に回転
    delay(500);
    a1=sr04.Distance();//距離を測定
    delay(100);
    servopulse(servopin,20);//20度に回転
    delay(500);
    a2=sr04.Distance();//距離を測定
    delay(100);
    servopulse(servopin,90);  //90度の位置に戻す
    delay(500);
    if(a1 > a2)//距離を比較し、左の距離が右の距離より大きい場合
    {
      car_left();//左に曲がる
      matrix_display(clear);
      matrix_display(left);    //左折パターンを表示
      servopulse(servopin,90);//サーボを90度に回転
      delay(700); //左に700ms回転
      matrix_display(clear);
      matrix_display(front);  //前方パターンを表示
    }
    else//右の距離が左より大きい場合
    {
      car_right();//右に曲がる
      matrix_display(clear);
      matrix_display(right);  //右折パターンを表示
      servopulse(servopin,90);//サーボを90度に回転
      delay(700);
      matrix_display(clear);
      matrix_display(front);  //前方パターンを表示
    }
  }
  else//それ以外の場合
  {
    car_front();//前進
    matrix_display(clear);
    matrix_display(front);  //前方パターンを表示
  }
}

void car_front()//車が前進する
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//後退する
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//車が左に曲がる
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//車が右に曲がる
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//停止
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//サーボの動作角度
{
  for(int i=0; i<20; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  } 
}

//この関数はドットマトリックス表示用
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //データ転送開始条件を呼び出す関数
  IIC_send(0xc0);  //アドレスを選択

```cpp
  for (int i = 0; i < 16; i++) //パターンデータは16バイトです
  {
    IIC_send(matrix_value[i]); //パターンのデータを送信します
  }
  IIC_end();   //パターンデータ送信終了
  IIC_start();
  IIC_send(0x8A);  //表示制御、4/16パルス幅を選択
  IIC_end();
}
//データ送信開始の条件
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//データ送信終了を示す
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
//データ送信
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //各バイトは8ビットで、最下位からビットごとにチェックします
  {
    if (send_data & mask) { //バイトの各ビットが1か0かに応じてSDA_Pinの高低レベルを設定します
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //クロックピンSCL_PinをHIGHにしてデータ送信を停止します
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //クロックピンSCL_PinをLOWにしてSDAの信号を変化させます
  }
}
//*******************************************************************************
```

### **5.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源をオンにしてからDIPスイッチをONにします。

スマートカーは前進し、自動的に障害物を回避します。前方に道がない場合、サーボが超音波センサーを駆動して左、中、右の距離をスキャンし、空いている側に車が旋回します。同時に、8X16 LEDボードには対応する状態パターンが表示されます。