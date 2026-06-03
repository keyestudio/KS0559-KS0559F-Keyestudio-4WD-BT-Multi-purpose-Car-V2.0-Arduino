# Project 14 IRリモコン制御スマートカー

![ff2fec813f8765e1bcd593b37b9c0a4f](media/A123.jpeg)

### **1.説明**

このプロジェクトでは、IRリモコン制御のスマートカーを作成し、IRリモコンのボタンを押して車を動かします。

### **2.フローチャート**

![img](media/A124.png)

**IRリモコン制御スマートカーの具体的なロジックは以下の通りです：**

| 初期設定                             |           | LEDボードにスマイルフェイスを表示                     |
| ----------------------------------------- | --------- | ------------------------------------------------- |
| リモコン                            | キー値 | キー状態                                         |
| ![img](media/A125.jpg) | FF629D    | 前進8*8 LEDボードに前方アイコンを表示            |
| ![img](media/A126.jpg) | FFA857    | 後退8*8 LEDボードに後方アイコンを表示                 |
| ![img](media/A127.jpg)                  | FF22DD    | 左回転8*8 LEDボードに左向きアイコンを表示   |
| ![img](media/A128.jpg)                  | FFC23D    | 右回転8*8 LEDボードに右向きアイコンを表示 |
| ![img](media/A129.jpg)                 | FF02FD    | 停止8*8 LEDボードに「STOP」を表示                     |

### **3.配線図**

![9d8b58dff14fe22b5c87514db944530c](media/A130.png)

1). 8\*8 LEDボードモジュールのGND、VCC、SDA、SCLは拡張ボードのG（GND）、V（VCC）、A4、A5に接続します。

2). IR受信機は8833モーターシールドに統合されているため、追加の配線は不要です。8833ボード上のIR受信機のピンはそれぞれG（GND）、V（VCC）、D3です。

3). サーボはG、V、A3に接続します。茶色の線はGnd（G）、赤色の線は5V（V）、オレンジ色の線はA3に接続します。

4). 電源はBATポートに接続します。
    

### **4.テストコード**

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 14
IR remote Control Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  // クロックピンをA5に設定
#define SDA_Pin  A4  // データピンをA4に設定
// パターンのデータを格納する配列。自分で計算するかモジュールツールから取得可能
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#include <Arduino.h>
#include <IRremote.h>// IRリモコン制御の機能ライブラリ
int RECV_PIN = 3;// IR受信機のピンをD3に設定
IRrecv irrecv(RECV_PIN);
long irr_val;
decode_results results;

int left_ctrl = 2;// グループBモーターの方向制御ピンを定義
int left_pwm = 5;// グループBモーターのPWM制御ピンを定義
int right_ctrl = 4;// グループAモーターの方向制御ピンを定義
int right_pwm = 6;// グループAモーターのPWM制御ピンを定義

#include <Servo.h>
Servo servo_A3;// サーボのピンをA3に設定

unsigned char data_line = 0;
unsigned char delay_count = 0;

void setup() {
  Serial.begin(9600);//
  // 割り込みドライバがセットアップ時にクラッシュする場合に備えて、
  // ユーザーに何が起きているかを知らせる手がかりを与える。
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // 受信機を開始
  Serial.println("Enabled IRin");
  pinMode(left_ctrl,OUTPUT);//グループBモーターの方向制御ピンをOUTPUTに設定
  pinMode(left_pwm,OUTPUT);//グループBモーターのPWM制御ピンをOUTPUTに設定
  pinMode(right_ctrl,OUTPUT);//グループAモーターの方向制御ピンをOUTPUTに設定
  pinMode(right_pwm,OUTPUT);//グループAモーターのPWM制御ピンをOUTPUTに設定
  servo_A3.attach(A3);
  servo_A3.write(90);//サーボの角度を90度に設定
  delay(300);
  pinMode(SCL_Pin,OUTPUT);//クロックピンを出力に設定
  pinMode(SDA_Pin,OUTPUT);//データピンを出力に設定
  matrix_display(clear);
  matrix_display(start01); //start01の表情パターンを表示
}

void loop()
 {
  if (irrecv.decode(&results)) 
 {
    irr_val = results.value;
    Serial.println(irr_val, HEX);//読み取ったIRリモコン信号をシリアル出力
    switch(irr_val)
    {
      case 0xFF629D : car_front(); //0xFF629Dを受信したら、車は前進
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 0xFFA857 : car_back(); //0xFFA857を受信したら、車は後退
      matrix_display(clear);
      matrix_display(back); 
      break;
    
      case 0xFF22DD : car_left(); //0xFF22DDを受信したら、車は左回転
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 0xFFC23D : car_right();//0xFFC23Dを受信したら、車は右回転
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 0xFF02FD : car_Stop();//0xFF02FDを受信したら、車は停止
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    }
        irrecv.resume(); // 次の値を受信
  }
}

void car_front()//前進状態を定義
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,105);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,105);
}
void car_back()//後退状態を定義
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
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

// この関数はドットマトリックス表示用
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //データ転送開始条件を呼び出す関数
  IIC_send(0xc0);  //アドレスを選択

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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //各バイトは8ビットで、最下位からビット単位でチェック
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
//*******************************************************************************
```

### **5.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源の電源を入れてからDIPスイッチをONにします。すると、IRリモコンで車を操作して動かすことができ、8X16 LEDボードには対応する状態パターンが表示されます。