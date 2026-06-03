# Project 9 Facial Expression LED Board

![image-20250510090912741](media/A87.png)

### **1.説明**

ロボットに表情ボードが追加されたらどれほど楽しいでしょうか。Keyestudioの8\*16 LEDボードがその役割を果たします。これを使えば、自分で表情、画像、パターンなどの表示をデザインできます。

8\*16 LEDボードは128個のLEDを搭載しています。マイクロプロセッサ（Arduino）のデータは2線式バスインターフェースを通じてAiP1640と通信します。これにより、モジュール上の128個のLEDのオン・オフを制御し、モジュール上のドットマトリックスに必要なパターンを表示できます。配線の便宜のためにHX-2.54 4ピンケーブルが付属しています。

### **2.仕様**

- 動作電圧: DC 3.3-5V

- 消費電力: 400mW

- 発振周波数: 450KHz

- 駆動電流: 200mA

- 動作温度: -40〜80℃

- 通信方式: I2C

### **3.回路図**

![image-20250510091309725](media/A88.png)

### **4.動作原理**

8\*16ドットマトリックスの各LEDをどのように制御するか？1バイトは8ビットで、それぞれのビットは0か1です。0のときはLEDが消灯、1のときは点灯します。1バイトでLEDの1列を制御でき、16バイトで16列のLEDを制御できます。これが8\*16ドットマトリックスです。

### **5.ピンの説明と通信プロトコル**

マイクロプロセッサ（Arduino）のデータは2線式バスケーブルを通じてAiP1640と通信します。

通信プロトコル図は以下の通りです。（SCLK）はSCL、（DIN）はSDAです。

![image-20250510091407219](media/A89.png)

①データ入力の開始条件：SCLが高レベルで、SDAが高から低に変化する。

②データコマンド設定には以下の方法があります。

サンプルプログラムでは**アドレスを自動的に1ずつ加算する方法**を選択し、2進数は0100 0000、対応する16進数は0x40です。

![Img](media/A90.png)

③アドレスコマンド設定は以下のように選択できます。

サンプルプログラムでは最初の00Hを選択し、2進数1100 0000は16進数0xc0に対応します。

![Img](media/A91.png)

④データ入力の要件は、SCLが高レベルのときにSDAの信号は変化してはいけません。SCLが低レベルのときのみSDAの信号を変化させることができます。データは下位ビットから入力し、その後上位ビットです。

⑤データ送信終了の条件は、SCLが低レベル、SDAが低レベルの状態からSCLが高レベルになったときにSDAが高レベルになることです。

⑥表示制御では異なるパルス幅を設定できます。パルス幅は以下の図のように選択可能です。

例ではパルス幅は4/16で、2進数1000 1010に対応する16進数は0x8Aです。

![Img](media/A92.png)

**モジュールツールの使用方法**

ドットマトリックスツールはオンライン版を使用し、リンクは：[http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

①リンクにアクセスすると以下のページが表示されます。

![image-20250510091438524](media/A93.png)

②ドットマトリックスは8\*16なので、高さを8、幅を16に調整します。以下の図のように設定してください。

![image-20250510091446519](media/A94.png)

③パターンから16進データを生成する

以下の図のように、左クリックで選択、右クリックでキャンセルし、表示したいパターンを描きます。生成ボタンをクリックすると必要な16進データが生成されます。

![image-20250510091457463](media/A95.png)

### **6.部品**

| Development Board *1                                         | 8833 Motor Driver *1                                         | USB Cable*1               |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------- |
| ![img](media/A80.jpg)                                    | ![img](media/A81.jpg)                                    | ![img](media/A82.jpg) |
| USB Cable*1                                                  | HX-2.54 4P Dupont Wire 200mm *1                              |                           |
| ![image-20250512155818434](media/A96.png) | ![image-20250512155822969](media/A97.png) |                           |

### **7.配線図**

![cec50fec4a335b6922e4c6694a133bc1](media/A98.png)

8x16 LEDライトボードのGND、VCC、SDA、SCLはそれぞれkeyestudioセンサー拡張ボードの-(GND)、+ (VCC)、A4、A5に接続され、2線式シリアル通信を行います。

(<span style="color: rgb(255, 76, 65);">注意：</span> ArduinoのIICピンに接続されていますが、このモジュールはIIC通信用ではありません。ここでのIOポートはI2C通信をシミュレートするもので、任意の2つのピンに接続可能です)。

### **8.テストコード**  

このコードはスマイルフェイスを表示します。

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lesson 9.1
  Matrix face
  http://www.keyestudio.com
*/
//Data from the smile pattern obtained from the touch tool
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
#define SCL_Pin  A5  //クロックピンをA5に設定
#define SDA_Pin  A4  //データピンをA4に設定
void setup() {
  //ピンを出力に設定
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //クリア
  //matrix_display(clear);
}
void loop() {
  matrix_display(smile);  //笑顔のパターンを表示
}
//この関数はドットマトリックス表示用
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
//データ送信開始条件
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //各バイトは8ビットで、最下位ビットから順にチェック
  {
    if (send_data & mask) { //バイトの各ビットが1か0かに応じてSDA_Pinの高低レベルを設定
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //クロックピンSCL_PinをHIGHにしてデータ送信を停止
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //クロックピンSCL_PinをLOWにしてSDAの信号を変更
  }
}
//************************************************************************
```

### **9.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、DIPスイッチをONにすると、LEDボードにスマイル型のパターンが表示されます。

![95bb011957896b12285fc6763137bb9a](media/A99.png)

### **10.コード説明**

私たちは、先ほど学んだモジュールツール、[http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#) を使って、ドットマトリックスにスタートパターン、前進パターン、停止パターンを表示し、その後パターンをクリアします。時間間隔は2000 msです。

![image-20250512155957415](media/A100.png)![image-20250512160002378](media/A101.png)![image-20250512160006841](media/A102.png)![image-20250512160010543](media/A103.png)

**モジュールツールから得られたコード：**

**スタートパターンのコード：**

0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01

**前進パターンのコード：**

0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**後退パターンのコード：**

0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**左折パターンのコード：**

0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00

**右折パターンのコード：**

0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00

**停止パターンのコード：**

0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00

**画面クリアのコード：**

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

![cec50fec4a335b6922e4c6694a133bc1](media/A104.png)

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lesson 9.2
  Matrix face
  http://www.keyestudio.com
*/
//タッチツールから取得したスマイルパターンのデータ
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char front[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char back[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char left[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00};
unsigned char right[] = {0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP01[] = {0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define SCL_Pin  A5  //クロックピンをA5に設定
#define SDA_Pin  A4  //データピンをA4に設定
void setup() {
  //ピンを出力に設定
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //クリア
  //matrix_display(clear);
}
void loop() {
    matrix_display(start01);  //スタートパターンを表示
    delay(2000);
    matrix_display(front);    //前進パターンを表示
    delay(2000);
    matrix_display(STOP01);   //停止パターンを表示
    delay(2000);
    matrix_display(clear);    //画面をクリア
    delay(2000);
}
//この関数はドットマトリックス表示用
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //データ転送開始条件を呼び出す関数
  IIC_send(0xc0);  //アドレスを選択

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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //各バイトは8ビットで、最下位からビット単位でチェックします
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
//************************************************************************
```

テストコードをアップロードすると、表情ボードはこれらのパターンを順番に表示し、このシーケンスを繰り返します。

![image-20250512160131674](media/A105.png)![image-20250512160135717](media/A106.png)![image-20250512160139283](media/A107.png)