# Project 11 ライントラッキングスマートカー

![eff7a15e697e8b78bde391f806ea024d](media/A112.png)

### **1.説明**

ライントラッキングセンサーの動作原理に基づき、ライントラッキングスマートカーを作成します。

このプロジェクトでは、スマートカーの底部に黒い線があるかどうかをライントラッキングセンサーで検出し、その検出結果に応じて2つのモーターグループの回転を制御し、スマートカーが黒い線に沿って走行するように制御します。

### **2.フローチャート**

![img](media/A113.png)

![Img](media/A114.png)

### **3.配線図**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A115.png)

ライントラッキングセンサーのG、V、S1、S2、S3はセンサー拡張ボードのG（GND）、V（VCC）、D11、D7、D8に接続します。

電源はBATポートに接続します。

### **4.テストコード**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 11
 Tracking Car
 http://www.keyestudio.com
*/ 
//Data from the smile pattern obtained from the touch tool
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //データピンをA4に設定
#define SCL_Pin  A5  //クロックピンをA5に設定

int left_ctrl = 2;//グループBモーターの方向制御ピンを定義
int left_pwm = 5;//グループBモーターのPWM制御ピンを定義
int right_ctrl = 4;//グループAモーターの方向制御ピンを定義
int right_pwm = 6;//グループAモーターのPWM制御ピンを定義
int sensor_L = 11;//左ライントラッキングセンサーのピンを定義
int sensor_M = 7;//中央ライントラッキングセンサーのピンを定義
int sensor_R = 8;//右ライントラッキングセンサーのピンを定義
int L_val,M_val,R_val;//これらの変数を定義

void setup() {
  Serial.begin(9600);//シリアルモニターを開始し、ボーレートを9600に設定
  pinMode(left_ctrl,OUTPUT);//グループBモーターの方向制御ピンをOUTPUTに設定
  pinMode(left_pwm,OUTPUT);//グループBモーターのPWM制御ピンをOUTPUTに設定
  pinMode(right_ctrl,OUTPUT);//グループAモーターの方向制御ピンをOUTPUTに設定
  pinMode(right_pwm,OUTPUT);//グループAモーターのPWM制御ピンをOUTPUTに設定
  pinMode(sensor_L,INPUT);//左ライントラッキングセンサーのピンをINPUTに設定
  pinMode(sensor_M,INPUT);//中央ライントラッキングセンサーのピンをINPUTに設定
  pinMode(sensor_R,INPUT);//右ライントラッキングセンサーのピンをINPUTに設定
  //ピンを出力に設定
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(start01);//スタートパターンを表示
}

void loop() 
{
  tracking(); //メインプログラムを実行
}

void tracking()
{
  L_val = digitalRead(sensor_L);//左ライントラッキングセンサーの値を読み取る
  M_val = digitalRead(sensor_M);//中央ライントラッキングセンサーの値を読み取る
  R_val = digitalRead(sensor_R);//右ライントラッキングセンサーの値を読み取る

  if(M_val == 1){//中央のセンサーの状態が1の場合、黒い線を検出していることを意味する

```cpp
     if (L_val == 1 && R_val == 0) { //左側に黒い線が検出され、右側には検出されていない場合、左に曲がる
        left();
    }
     else if (L_val == 0 && R_val == 1) { //それ以外で、右側に黒い線が検出され、左側には検出されていない場合、右に曲がる
      right();
    }
     else { //それ以外は前進
      front();
    }
  }
  else { //中央に黒い線が検出されていない場合
    if (L_val == 1 && R_val == 0) { //左側に黒い線が検出され、右側には検出されていない場合、左に曲がる
      left();
    }
    else if (L_val == 0 && R_val == 1) { //それ以外で、右側に黒い線が検出され、左側には検出されていない場合、右に曲がる
      right();
    }
    else { //それ以外は停止
      Stop();
    }
  }
}
void front()//前進状態を定義
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void back()//後退状態を定義
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void left()//左折状態を定義
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//右折状態を定義
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//停止状態を定義
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
}

//この関数はドットマトリックス表示に使用される
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //データ転送開始条件を呼び出す関数
  IIC_send(0xc0);  //アドレス選択

  for (int i = 0; i < 16; i++) //パターンデータは16バイト
  {
    IIC_send(matrix_value[i]); //パターンのデータを送信
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //各バイトは8ビットで、最下位からビットごとにチェック
  {
    if (send_data & mask) { //バイトの各ビットが1か0かに応じてSDA_Pinの高低レベルを設定
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //クロックピンSCL_Pinを高レベルにしてデータ送信を停止
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //クロックピンSCL_Pinを低レベルにしてSDAの信号を変化させる
  }
}
//*************************************************************************
```

### **5.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源をオンにしてからDIPスイッチをONにします。すると、スマートカーはラインに沿って走行します。