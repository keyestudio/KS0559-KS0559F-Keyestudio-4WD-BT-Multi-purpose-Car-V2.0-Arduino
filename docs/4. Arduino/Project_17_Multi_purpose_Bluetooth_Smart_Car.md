# Project 17 多機能Bluetoothスマートカー

![2c1198e0ebd7c31622b7438469fb572c](media/A138.jpeg)

### **1.説明**

これまでのプロジェクトでは、車は単一の機能のみを実行していました。しかし、このレッスンでは、Bluetoothを介してすべての機能を統合します。

### **2.フローチャート**

![73f4da1e321bc29282d3b2f5cb3168dd](media/A139.png)

### **3.配線図**

![fce8edd349ddbcfe02e6f27feb73e90f](media/A140.png)

1). 8×8 LEDボードのGND、VCC、SDA、SCLは拡張ボードのG（GND）、V（VCC）、A4、A5に接続します。

2). BluetoothモジュールのRXD、TXD、GND、VCCはそれぞれ8833モーターシールドのTX、RX、G、5Vに接続し、BluetoothモジュールのSTATEおよびBRKピンは接続不要です。

3). サーボはG、V、A3に接続します。茶色の線はGnd(G)、赤色の線は5V(V)、オレンジ色の線はA3に接続します。

4). ライントラッキングセンサーのG、V、S1、S2、S3はセンサー拡張ボードのG（GND）、V（VCC）、D11、D7、D8に接続します。

5). 超音波センサーのVCC、Trig、Echo、Gndはそれぞれ5V(V)、D12(S)、D13(S)、Gnd(G)に接続します。

6). 電源はBATポートに接続します。

### **4.テストコード**

<span style="color: rgb(255, 76, 65);">**注意:** テストコードをアップロードする前にBluetoothモジュールを取り外す必要があります。そうしないとコードのアップロードに失敗します。コードのアップロードが成功した後にBluetoothモジュールを接続してください。</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 17
Bluetooth Multifunctional Car
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
unsigned char speed_a[] = 
{0x00,0x40,0x20,0x10,0x08,0x04,0x02,0xff,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00};
unsigned char speed_d[] = 
{0x00,0x02,0x04,0x08,0x10,0x20,0x40,0xff,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00};

int left_ctrl = 2; // グループBモーターの方向制御ピンを定義
int left_pwm = 5;  // グループBモーターのPWM制御ピンを定義
int right_ctrl = 4; // グループAモーターの方向制御ピンを定義
int right_pwm = 6;  // グループAモーターのPWM制御ピンを定義
int speeds = 150;   // 初期速度を150に設定

const int servopin = A3; // サーボのピンをA3に設定

int L_pin = 11; // 左側トラッキングセンサーのピンをD11に定義
int M_pin = 7;  // 中央トラッキングセンサーのピンをD7に定義
int R_pin = 8;  // 右側トラッキングセンサーのピンをD8に定義
int L_val, M_val, R_val;

int trigPin = 12; // TRIGピンをD12に接続
int echoPin = 13; // ECHOピンをD13に接続
int distance, distance_l, distance_r;

char BLE_val;

void setup() {
  Serial.begin(9600);//ボーレートを9600に設定
  pinMode(left_ctrl,OUTPUT);//グループBモーターの方向制御ピンをOUTPUTに設定
  pinMode(left_pwm,OUTPUT);//グループBモーターのPWM制御ピンをOUTPUTに設定
  pinMode(right_ctrl,OUTPUT);//グループAモーターの方向制御ピンをOUTPUTに設定
  pinMode(right_pwm,OUTPUT);//グループAモーターのPWM制御ピンをOUTPUTに設定
  servopulse(servopin,90);//サーボの角度を90度に設定
  delay(300);
  pinMode(L_pin, INPUT); //トラッキングセンサーのピンを入力モードに設定
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(trigPin, OUTPUT); //TRIGを出力モードに定義
  pinMode(echoPin, INPUT); //ECHOを入力モードに定義
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
      case 'F' : car_front(); 
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); 
      matrix_display(clear);
      matrix_display(back); 
      break;
    
      case 'L' : car_left(); 
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    
      case 'a' : speeds_a();
      matrix_display(clear);
      matrix_display(speed_a);  
      break;
     
      case 'd' : speeds_d();
      matrix_display(clear);
      matrix_display(speed_d); 
      break;
    
      case  'U':  follow();  //‘U’を受信し、フォローモードに入る
      break; 
      case  'Y':  avoid(); //‘Y’を受信し、障害物回避モードに入る  
      break;  
      case  'G':  confinement(); //‘G’を受信し、閉じ込めモードに入る
      break;  
      case  'X':  tracking(); //‘X’を受信し、トラッキングモードに入る
      break;  
    }
}

void car_front()//前進状態を定義
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//後退状態を定義
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//左折状態を設定
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//右折状態を設定
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//停止状態を定義
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //加速関数
  while (1) {
    Serial.println(speeds);  //速度情報を表示 
    if (speeds < 255) { //最大255まで
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //成長速度を調整 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //‘S’を受信したら加速を停止
    break;
  }
}
void speeds_d() { //減速関数
  while (1) {
    Serial.println(speeds);  //速度情報を表示
    if (speeds > 0) { //0まで減速
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //減速速度を調整
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //‘S’を受信したら減速を停止
    break;
}
}

int get_distance() {
  int distance = 0;
  digitalWrite(trigPin, LOW);     // Trig/Pinを通じてパルスを送信し、HC-SR04の測距をトリガーするため、超音波信号インターフェースを2μsの低レベルに設定
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // 超音波信号インターフェースを10μsの高レベルに設定（ここでは少なくとも10μs）
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);     // 超音波信号インターフェースを低レベルに維持
  distance = pulseIn(echoPin, HIGH) / 58; // パルス時間を読み取り、距離（単位：cm）に変換
  Serial.println(distance);        // 距離値を出力
  return distance;
}

void follow() {
  servopulse(servopin,90);
  delay(200);
  int follow_flag = 1;
  while (follow_flag) {
    distance = get_distance(); // 測距関数を呼び出す
    if (distance < 8 ) {// 距離が8未満の場合
      car_back();// 車が後退する
      matrix_display(clear);
      matrix_display(back); 
    }
    else if (distance >= 8 && distance < 13) { // 距離が8以上13未満の場合
      car_Stop();// 停止
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    else if (distance >= 13 && distance <= 35 ) { // 距離が13以上35以下の場合
      car_front();// 車が前進する
      matrix_display(clear);
      matrix_display(front);
    }
    else {// 上記のいずれにも該当しない場合
      car_Stop();// 停止
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // 'S'を受信した場合、車を停止する
      follow_flag = 0;
      car_Stop();
    }
  }
}

void avoid() {
  int avoid_flag = 1;
  while (avoid_flag) {
    distance = get_distance(); // 測距関数を呼び出す
    if (distance > 0 && distance < 20) { // 距離が0より大きく20未満の場合
      car_Stop();// 停止
      matrix_display(clear);
      matrix_display(STOP01);   // ドットマトリクスに停止パターンを表示
      delay(1000);
      servopulse(servopin,160); // サーボを180度以上に動かす
      delay(500);
      distance_l = get_distance(); // 左側の距離を取得
      delay(100);
      servopulse(servopin,20); // サーボを0度に回す
      delay(500);
      distance_r = get_distance(); // 右側の距離を取得
      delay(100);
      if (distance_l > distance_r) { // 距離を比較し、左の方が大きい場合
        car_left();  // 車が左に曲がる
        matrix_display(clear);
        matrix_display(left);   // ドットマトリクスに左パターンを表示
        servopulse(servopin,90);// サーボを90度に戻す
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // ドットマトリクスに前進パターンを表示
      } 
      else { // それ以外（右の方が大きい場合）
        car_right();// 車が右に曲がる
        matrix_display(clear);
        matrix_display(right);   // ドットマトリクスに右パターンを表示
        servopulse(servopin,90);// サーボを90度に戻す
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // ドットマトリクスに前進パターンを表示
      }
    }
    else { // 前方距離が20以上の場合
      car_front();// 車が前進する
      matrix_display(clear);
      matrix_display(front);   // ドットマトリクスに前進パターンを表示

    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') {// 'S'を受信した場合、車を停止する
      avoid_flag = 0;
      car_Stop();
    }
  }
}

void confinement() {
  int confinement_flag = 1;
  while (confinement_flag) {
    L_val = digitalRead(L_pin); // 左センサーの値を読み取る
    M_val = digitalRead(M_pin); // 中央センサーの値を読み取る
    R_val = digitalRead(R_pin); // 右センサーの値を読み取る
    if ( L_val == 0 && M_val == 0 && R_val == 0 ) { // 黒線が検出されない場合、車は前進する
      car_front();
    }
    else { // それ以外の場合、いずれかのトラッキングセンサーが黒線を検出したら、車は後退してから左に曲がる
      car_back();
      delay(500);
      car_left();
      delay(800);
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // 'S'を受信したら、車は停止する
      confinement_flag = 0;
      car_Stop();
    }
  }
}

void tracking() {
  int track_flag = 1;
  while (track_flag) {
    L_val = digitalRead(L_pin); // 左センサーの値を読み取る
    M_val = digitalRead(M_pin); // 中央センサーの値を読み取る
    R_val = digitalRead(R_pin); // 右センサーの値を読み取る
    if (M_val == 1) { // 中央で黒線を検出
      if (L_val == 1 && R_val == 0) { // 左に黒線があり右にない場合、左に曲がる
        car_left();
      }
      else if (L_val == 0 && R_val == 1) { // それ以外で右に黒線があり左にない場合、右に曲がる
        car_right();
      }
      else { // それ以外は車は前進する
        car_front();
      }
    }
    else { // 中央で黒線が検出されない場合
      if (L_val == 1 && R_val == 0) { // 左に黒線があり右にない場合、右に曲がる
        car_right();
      }
      else if (L_val == 0 && R_val == 1) { // それ以外で右に黒線があり左にない場合、右に曲がる
        car_right();;
      }
      else { // それ以外は停止する
        car_Stop();
      }
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // 'S'を受信したら、車は停止する
      track_flag = 0;
      car_Stop();
    }
  }
}

void servopulse(int servopin,int myangle)// サーボモーターの動作角度
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

// この関数はドットマトリックス表示に使用される
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  // データ転送開始条件を呼び出す関数
  IIC_send(0xc0);  // アドレスを選択する

  for (int i = 0; i < 16; i++) //パターンデータは16バイトです
  {
    IIC_send(matrix_value[i]); //パターンのデータを送信します
  }
  IIC_end();   //パターンデータ送信終了
  IIC_start();
  IIC_send(0x8A);  //表示制御、4/16パルス幅を選択
  IIC_end();
}
//データ送信が開始される条件
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//データ送信の終了を示す
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
    digitalWrite(SCL_Pin, HIGH); //クロックピンSCL_Pinを高レベルにしてデータ送信を停止します
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //クロックピンSCL_Pinを低レベルにしてSDAの信号を変化させます
  }
}
//*******************************************************************************
```

### **5.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源を入れてからDIPスイッチをONにします。

BluetoothモジュールがAPPに接続され、モバイルAPPがBluetoothに正常に接続されると、モバイルAPPでスマートカーを制御できます。モバイルAPPの対応するボタンを押すことで、対応する機能を実現できます。