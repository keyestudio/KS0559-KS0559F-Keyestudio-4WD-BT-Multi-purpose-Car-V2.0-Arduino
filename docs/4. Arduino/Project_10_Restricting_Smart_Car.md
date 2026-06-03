# Project 10 制限付きスマートカー

![644a1976bf17a6b64e0aed1a7240ff1e](media/A108.jpeg)

### **1.説明**

このプロジェクトでは、ライン追跡センサーとモータードライバーモジュールの知識を組み合わせて、制限付きスマートカーを作成します。実験では、ライン追跡センサーを使ってスマートカーの周囲に黒い線があるかどうかを検出し、その検出結果に基づいて2つのモーターの回転を制御し、黒い線で描かれた円の中にスマートカーをロックすることを目指します。

### **2.フローチャート**

![img](media/A109.png)

制限付き4WDスマートカーの具体的なロジックは以下の表に示されています。

![Img](media/A110.png)

### **3.配線図**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A111.png)

ライン追跡センサーのG、V、S1、S2、S3はセンサー拡張ボードのG（GND）、V（VCC）、D11、D7、D8に接続します。

電源はBATポートに接続します。

### **4.テストコード**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 10
 Restricting Smart Car
 http://www.keyestudio.com
*/ 
//タッチツールから取得したスマイルパターンのデータ
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //データピンをA4に設定
#define SCL_Pin  A5  //クロックピンをA5に設定

int left_ctrl = 2;//グループBモーターの方向制御ピンを定義
int left_pwm = 5;//グループBモーターのPWM制御ピンを定義
int right_ctrl = 4;//グループAモーターの方向制御ピンを定義
int right_pwm = 6;//グループAモーターのPWM制御ピンを定義
int sensor_L = 11;//左ライン追跡センサーのピンを定義
int sensor_M = 7;//中央ライン追跡センサーのピンを定義
int sensor_R = 8;//右ライン追跡センサーのピンを定義
int L_val,M_val,R_val;//これらの変数を定義

void setup() {
  Serial.begin(9600);//シリアルモニターを開始し、ボーレートを9600に設定
  pinMode(left_ctrl,OUTPUT);//グループBモーターの方向制御ピンをOUTPUTに設定
  pinMode(left_pwm,OUTPUT);//グループBモーターのPWM制御ピンをOUTPUTに設定
  pinMode(right_ctrl,OUTPUT);//グループAモーターの方向制御ピンをOUTPUTに設定
  pinMode(right_pwm,OUTPUT);//グループAモーターのPWM制御ピンをOUTPUTに設定
  pinMode(sensor_L,INPUT);//左ライン追跡センサーのピンをINPUTに設定
  pinMode(sensor_M,INPUT);//中央ライン追跡センサーのピンをINPUTに設定
  pinMode(sensor_R,INPUT);//右ライン追跡センサーのピンをINPUTに設定
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
  L_val = digitalRead(sensor_L);//左ライン追跡センサーの値を読み取る
  M_val = digitalRead(sensor_M);//中央ライン追跡センサーの値を読み取る
  R_val = digitalRead(sensor_R);//右ライン追跡センサーの値を読み取る
  if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //黒い線が検出されない場合、カメカーは前進
    Car_front();
  }
  else { //それ以外の場合、いずれかのセンサーが黒い線を検出したら、後退して左に曲がる
    Car_back();
    delay(500);
    Car_left();
    delay(500);
  }
}

void Car_front()
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 180);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 180);
}
void Car_back()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 80);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 80);
}
void Car_left()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 150);
}

void Car_Stop()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 0);
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
//*************************************************************************
```

### **5.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源を入れ、
DIPスイッチをONにします。スマートカーを黒い円の中に置くと、円の中を単独で移動します。