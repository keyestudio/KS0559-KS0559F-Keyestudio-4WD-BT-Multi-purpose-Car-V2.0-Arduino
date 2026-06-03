# Project 12 超音波追従スマートカー

![a3beaada39eb1471b7df6d9788e2bea3](media/A116.png)

### **1.説明**

このプロジェクトでは、超音波センサーを使って4WDスマートカーと前方の障害物との距離を検出し、2つのモーターを制御して車を動かし、8\*8 LEDボードに笑顔のパターンを表示させます。

### **2.フローチャート**

![img](media/A117.png)

<table border="1">
<tbody>
<tr class="odd">
<td>検出</td>
<td>前方障害物の測定距離</td>
<td>距離（単位：cm）</td>
</tr>
<tr class="even">
<td>設定</td>
<td>8*16 LEDボードに笑顔のパターンを表示</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>サーボを90°に設定</td>
<td></td>
</tr>
<tr class="even">
<td>条件</td>
<td>距離≥20 かつ 距離≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>状態</td>
<td>前進</td>
<td></td>
</tr>
<tr class="even">
<td>条件</td>
<td>距離＞10 かつ 距離＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>距離＞50</td>
<td></td>
</tr>
<tr class="even">
<td>条件</td>
<td>停止</td>
<td></td>
</tr>
<tr class="odd">
<td>条件</td>
<td>距離≤10</td>
<td></td>
</tr>
<tr class="even">
<td>条件</td>
<td>後退</td>
<td></td>
</tr>
</tbody>
</table>


### **3.配線図**

![568a66655a14dd34afd8cb1e6ae5951c](media/A118.png)

**配線方法：**

1). 8\*8 LEDボードのGND、VCC、SDA、SCLを拡張ボードのG（GND）、V（VCC）、A4、A5に接続します。

2). 超音波センサーのVCC、Trig、Echo、Gndをそれぞれ5V(V)、D12(S)、D13(S)、Gnd(G)に接続します。

3). サーボはG、V、A3に接続します。茶色の線はGnd(G)、赤色の線は5V(V)、オレンジ色の線はA3に接続します。

4). 電源はBATポートに接続します。

### **4.テストコード**

```c
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 12
 Flowing Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  // クロックピンをA5に設定
#define SDA_Pin  A4  // データピンをA4に設定

// パターンのデータを格納する配列。自分で計算するかモジュールツールから取得可能
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};

const int servopin = A3; // サーボのピンを設定
 
#include "SR04.h" // 超音波センサーの関数ライブラリを定義
#define TRIG_PIN 12 // 超音波センサーのTrig信号をD12に設定
#define ECHO_PIN 13 // 超音波センサーのEcho信号をD13に設定
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int left_ctrl = 2;  // グループBモーターの方向制御ピンを定義
int left_pwm = 5;   // グループBモーターのPWM制御ピンを定義
int right_ctrl = 4; // グループAモーターの方向制御ピンを定義
int right_pwm = 6;  // グループAモーターのPWM制御ピンを定義

void setup() {
  pinMode(left_ctrl,OUTPUT);  // グループBモーターの方向制御ピンを出力に設定
  pinMode(left_pwm,OUTPUT);   // グループBモーターのPWM制御ピンを出力に設定
  pinMode(right_ctrl,OUTPUT); // グループAモーターの方向制御ピンを出力に設定
  pinMode(right_pwm,OUTPUT);  // グループAモーターのPWM制御ピンを出力に設定
  pinMode(TRIG_PIN, OUTPUT);  // Trigピンを出力に設定
  pinMode(ECHO_PIN, INPUT);   // Echoピンを入力に設定
  pinMode(SCL_Pin,OUTPUT);    // クロックピンを出力に設定
  pinMode(SDA_Pin,OUTPUT);    // データピンを出力に設定
  servopulse(servopin,90);    // 初期のサーボ角度を90°に設定
  delay(500);                 // 500ms待機
  matrix_display(smile);      // 笑顔のパターンを表示  
}

void loop() {
  distance = sr04.Distance(); // 超音波センサーで距離を検出
   if(distance <= 10) // 距離が10以下の場合
  {
    back(); // 後退
  }
  else if((distance > 10)&&(distance< 20 )) // 10 < 距離 < 20 の場合
  {
    Stop(); // 停止
  }
  else if((distance >= 20)&&(distance <= 50)) // 20 ≤ 距離 ≤ 50 の場合  
{
    front(); // 追従（前進）
  }
  else // それ以外の場合
  {
    Stop(); // 停止
  }
}

void front()//前進の状態を定義
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,100);
}
void back()//後退の状態を定義
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void left()//左折の状態を定義
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//右折の状態を定義
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

void servopulse(int servopin,int myangle)//サーボの動作角度
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

//この関数はドットマトリックス表示に使用されます
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

### **5.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源をオンにします。  
次にDIPスイッチをONに切り替えます。サーボを90°に設定すると、スマートカーは障害物を避けて動き、8X16 LEDボードに「smile」が表示されます。