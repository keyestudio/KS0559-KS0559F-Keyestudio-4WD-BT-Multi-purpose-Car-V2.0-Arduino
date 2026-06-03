# Project 3: ライントラッキングセンサー

![](media/A17.png)

### **1.説明**

トラッキングセンサーは実際には赤外線センサーです。ここで使用されているコンポーネントはTCRT5000赤外線チューブです。その動作原理は、赤外線の反射率の違いを色で検出し、反射信号の強さを電流信号に変換することです。

検出の過程では、黒はHIGHレベルでアクティブ、白はLOWレベルでアクティブとなります。検出高さは0〜3cmです。

Keyestudioの3チャンネルライントラッキングモジュールは、3セットのTCRT5000赤外線チューブを基板上に統合しており、配線と制御がより便利です。

センサー上の調整可能なポテンショメーターを回すことで、センサーの検出感度を調整できます。

### **2.仕様**

- 動作電圧：3.3-5V（DC）
- インターフェース：5PIN
- 出力信号：デジタル信号
- 検出高さ：0〜3cm

![image-20250508163247479](media/A18.png)

<span style="color: rgb(255, 76, 65);">注意：テスト前にセンサー上のポテンショメーターを回して検出感度を調整してください。LEDがONとOFFの境界にあるときが最適な感度です。</span>

### **3.コンポーネント**

| 開発ボード *1                     | 8833 モータードライバー *1                     | 赤色LEDモジュール*1         | ライントラッキングセンサー*1   |
| -------------------------------- | ---------------------------------------------- | ---------------------------- | ------------------------------ |
| ![img](media/A8.jpg)             | ![img](media/A9.jpg)                           | ![img](media/A10.jpg)        | ![img](media/A19.png)          |
| 5P デュポンワイヤー*1            | USBケーブル*1                                 | 3P デュポンワイヤー*1        |                                |
| ![img](media/A20.png)            | ![img](media/A12.jpg)                          | ![img](media/A11.jpg)        |                                |

### **4.配線図**

![image-20250508164243044](media/A21.png)

ライントラッキングセンサーのG、V、S1、S2、S3は、それぞれセンサー拡張ボードのG（GND）、V（VCC）、D11、D7、D8に接続します。

### **5.テストコード**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 3.1 
 Line Track sensor
 http://www.keyestudio.com
*/
int L_pin = 11;  // 左側ライントラッキングセンサーのピン
int M_pin = 7;   // 中央ライントラッキングセンサーのピン
int R_pin = 8;   // 右側ライントラッキングセンサーのピン
int val_L,val_R,val_M; // 3つのセンサーの値を格納する変数を定義

void setup()
{
  Serial.begin(9600); // シリアル通信を9600ボーで初期化
  pinMode(L_pin,INPUT); // L_pinを入力モードに設定
  pinMode(M_pin,INPUT); // M_pinを入力モードに設定
  pinMode(R_pin,INPUT); // R_pinを入力モードに設定
}

void loop() 
{ 
  val_L = digitalRead(L_pin); // L_pinの状態を読み取る
  val_R = digitalRead(R_pin); // R_pinの状態を読み取る
  val_M = digitalRead(M_pin); // M_pinの状態を読み取る
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500); // 安定のため読み取り間隔を遅延
}
//****************************************************************************
```

### **6.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線し、USBケーブルでコンピューターと接続してボードに電源を供給します。

電源を入れたらシリアルモニターを開くと、3つのライントラッキングセンサーの状態が表示されます。信号が受信されていない場合は値が1になります。センサーを白い紙で覆うと値は0になります。

![image-20250508164424571](media/A22.png)

![image-20250508164453274](media/A23.png)

### **7.コード説明**

Serial.begin(9600) - シリアルポートを初期化し、ボーレートを9600に設定

pinMode - ピンを入力または出力モードに定義

digitalRead - ピンの状態を読み取る（通常はHIGHまたはLOWレベル）

**8.拡張練習**

動作原理を理解した後、LEDをD9に接続して、センサーでLEDを制御することができます。

![image-20250508164527429](media/A24.png)

```c
/*
keyestudio 4wd BT Car
lesson 3.2
 Line Track Sensor LED
 http://www.keyestudio.com
*/
int L_pin = 11;  // 左側ライン追跡センサーのピン
int M_pin = 7;  // 中央ライン追跡センサーのピン
int R_pin = 8;  // 右側ライン追跡センサーのピン
int val_L,val_R,val_M;// 3つのセンサーの変数を定義

void setup()
{
  Serial.begin(9600); // 9600ビット毎秒でシリアル通信を初期化
  pinMode(L_pin,INPUT); // L_pinを入力に設定
  pinMode(M_pin,INPUT); // M_pinを入力に設定
  pinMode(R_pin,INPUT); // R_pinを入力に設定
  pinMode(9, OUTPUT);
}

void loop() 
{ 
  val_L = digitalRead(L_pin);// L_pinの読み取り
  val_R = digitalRead(R_pin);// R_pinの読み取り
  val_M = digitalRead(M_pin);// M_pinの読み取り
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// 安定のため読み取り間に遅延
  if ((val_L == LOW) || (val_M == LOW) || (val_R == LOW))// 左ライン追跡センサーが信号を検出した場合
  { 
    Serial.println("HIGH");
    digitalWrite(9, HIGH);// LEDが点灯
  }
  else// 左ライン追跡センサーが信号を検出しなかった場合
  { 
    Serial.println("LOW");
    digitalWrite(9, LOW);// LEDが消灯
  }
 }
//****************************************************************************
```

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、USBケーブルでコンピューターと接続してボードに電源を供給します。

電源を入れた後、センサーの近くに紙を置くと、ライン追跡センサーを覆ったときにLEDが点灯するのが確認できます。