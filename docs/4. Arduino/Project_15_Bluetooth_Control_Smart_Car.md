# Project 15 Bluetooth Control Smart Car

![8abdadfa2fc462bdcc0542df52a793e3](media/A131.jpeg)

### **1.説明**

Bluetoothの基本知識を学びました。このレッスンでは、Bluetooth制御のスマートカーを作成します。このプロジェクトでは、携帯電話を送信機（ホスト）として、BT24 Bluetoothモジュールに接続されたスマートカー（スレーブ）を受信機として扱い、携帯アプリを使ってBluetooth経由でスマートカーを制御することを目指します。

### **2.APP制御ボタン**

|                           | 制御文字                                                    | 制御文字                                                    |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | 押す: F  <br />離す: S                                   | ボタンを押すと車が前進；<br />離すと停止                      |
| ![img](media/A64.jpg) | 押す: L  <br />離す: S                                   | ボタンを押すと車が左折；<br />離すと停止                      |
| ![img](media/A65.jpg) | 押す: R  <br />離す: S                                   | ボタンを押すと車が右折；<br />離すと停止                      |
| ![img](media/A66.jpg) | 押す: B  <br />離す: S                                   | ボタンを押すと車が後退；<br />離すと停止                      |
| ![img](media/A67.jpg) | 押す: “a”  <br />離す: “S”                               | クリックで加速（最大値：255）                                |
| ![img](media/A68.jpg) | 押す: “d”  <br />離す: “S”                               | クリックで減速（最小値：0）                                  |
| ![img](media/A69.jpg) | クリックで携帯電話の重力感知機能を開始<br />もう一度クリックで重力感知制御を終了 |                                                              |
| ![img](media/A70.jpg) | クリックで“X”を送信、<br />もう一度クリックで“S”を送信    | ライントレース機能を開始；<br />もう一度クリックで終了       |
| ![img](media/A71.jpg) | クリックで“Y”を送信、<br />もう一度クリックで“S”を送信    | 超音波回避機能を開始；<br />もう一度クリックで終了           |
| ![img](media/A72.jpg) | クリックで“U”を送信、<br />もう一度クリックで“S”を送信    | 超音波追従機能を開始；<br />もう一度クリックで終了           |
| ![img](media/A73.jpg) | クリックで“G”を送信、<br />もう一度クリックで“S”を送信    | 制限機能を開始；<br />もう一度クリックで終了                 |

### **3.フローチャート**

![img](media/A132.png)

### **4.配線図**

![61be6959693b2111639252ea45ec60fc](media/A133.png)

1). 8\*8 LEDボードのGND、VCC、SDA、SCLは拡張ボードのG（GND）、V（VCC）、A4、A5に接続します。
    
2). BluetoothモジュールのRXD、TXD、GND、VCCはそれぞれ8833モーターシールドのTX、RX、G、5Vに接続します。BluetoothモジュールのSTATEとBRKピンは接続不要です。
    
3). サーボはG、V、A3に接続します。茶色の線はGnd（G）、赤色の線は5V（V）、オレンジ色の線はA3に接続します。
    
4). 電源はBATポートに接続します。
    

### **5.テストコード**

<span style="color: rgb(255, 76, 65);">**注意:** テストコードをアップロードする前にBluetoothモジュールを取り外す必要があります。そうしないとコードのアップロードに失敗します。コードのアップロードが成功したらBluetoothモジュールを接続してください。</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 15
Bluetooth Control Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //クロックピンをA5に設定
#define SDA_Pin  A4  //データピンをA4に設定
//パターンのデータを格納する配列。自分で計算するかモジュールツールから取得可能
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//グループBモーターの方向制御ピンを定義
int left_pwm = 5;//グループBモーターのPWM制御ピンを定義
int right_ctrl = 4;//グループAモーターの方向制御ピンを定義
int right_pwm = 6;//グループAモーターのPWM制御ピンを定義

const int servopin = A3;//サーボのピンをA3に設定

char BLE_val;

void setup() {
  Serial.begin(9600);//
  pinMode(left_ctrl,OUTPUT);//グループBモーターの方向制御ピンをOUTPUTに設定
  pinMode(left_pwm,OUTPUT);//グループBモーターのPWM制御ピンをOUTPUTに設定
  pinMode(right_ctrl,OUTPUT);//グループAモーターの方向制御ピンをOUTPUTに設定
  pinMode(right_pwm,OUTPUT);//グループAモーターのPWM制御ピンをOUTPUTに設定
  servopulse(servopin,90);//サーボの角度を90度に設定
  delay(300);
  pinMode(SCL_Pin,OUTPUT);//クロックピンを出力に設定
  pinMode(SDA_Pin,OUTPUT);//データピンを出力に設定
  matrix_display(clear);
  matrix_display(start01); //start01の表現パターンを表示
}

void loop() {
   if(Serial.available()>0) {
    BLE_val = Serial.read();
    Serial.println(BLE_val);
  } 
    switch(BLE_val)
    {
      case 'F' : car_front(); // 'F'を受信したら前進
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); // 'B'を受信したら後退
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); // 'L'を受信したら左回転
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();// 'R'を受信したら右回転
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();// 'S'を受信したら停止
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
}
}

void car_front()//前進状態を定義
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//後退状態を定義
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//左回転状態を設定
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//右回転状態を設定
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//停止状態を定義
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//サーボモーターの動作角度
{
  for(int i=0; i<30; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  }  
}

//この関数はドットマトリックスディスプレイ用です
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
    digitalWrite(SCL_Pin, LOW); //クロックピンSCL_Pinを低レベルにしてSDAの信号を変更
  }
}
//*******************************************************************************
```

### **6.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源を入れてからDIPスイッチをONにしてください。

BTモジュールを挿入し、携帯電話のBluetoothを開いて接続すると、スマートカーを制御できます。車は前進、後退、左折、右折、停止します。また、8\*8 LEDボードは対応するパターンを表示します。