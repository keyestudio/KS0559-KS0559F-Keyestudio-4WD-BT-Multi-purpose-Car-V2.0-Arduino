# Project 8 モーター駆動と速度制御

![image-20250510090044895](media/A77.png)

### **1.説明**

モーターを駆動する方法は多くあります。私たちの車は最も一般的に使用されているDRV8833モータードライバーチップを使用しており、これはおもちゃ、プリンターなどの統合モーターアプリケーション向けに2チャネルのブリッジ電気駆動ソリューションを提供します。

4.0開発ボードにShieldを重ねてBATに電源を入れ、DIPスイッチをON端に設定すると、外部電源が2つのボードに同時に電力を供給します。配線接続を容易にするために、Shieldには逆接続防止ポート（PH2.0-2P-3P-4P-5P）が付いています。モーター、電源、センサーモジュールを直接Shieldに接続できます。

ShieldのBluetoothインターフェースはDX-BT24 5.1 Bluetoothモジュールと完全互換です。Bluetoothモジュールを接続する際は、対応するインターフェースに差し込むだけで済みます。同時に、2.54ピッチのピン列を使ってShield上の未使用のデジタルおよびアナログポートを引き出しており、他のセンサーの追加や拡張実験が可能です。

拡張ボードは4つのDCモーターに接続できます。ジャンパーキャップがデフォルトで接続されている場合、ポートAとA1、BとB1のモーターは並列接続され、同じ動作をします。8つのジャンパーキャップで4つのモーターインターフェースの回転方向を制御できます。

例えば、M1モーターのB1前の2つのジャンパーキャップを横方向接続から縦方向接続に変更すると、M1モーターの回転方向は元の回転方向と逆になります。

### **2.仕様**

- ロジック入力電圧：DC 5V

- 駆動入力電圧：DC 6-9 V

- ロジック動作電流：\<36mA

- 駆動動作電流：\<2A

- 最大消費電力：25W（T=75℃）

- 制御信号入力レベル：高レベルは2.3V\<Vin\<5V、低レベルは-0.3V\<Vin\<1.5V

- 動作温度：-25＋130℃

**Keyestudio 8833 モータードライバー拡張ボード**

![image-20250510090404192](media/A78.png)

### **3.動作原理**

4つのモーターは同じ側の並列接続モードを使用し、2つのモーターグループと見なせます。配線図のように、BとB1が1グループ、AとA1がもう1グループです。

同じグループのモーターは同じ方向に回転する必要があります。異なる場合は、端子横の対応するジャンパーキャップを調整して方向を変更してください。

下図のように、AとA1の方向が異なる場合は、ジャンパーキャップの方向を調整して同じグループのモーターの動作方向を一致させます。

![image-20250510090532851](media/A79.png)

上図から、Aモーターの方向ピンはD4、速度ピンはD6であることがわかります。D2はBモーターの方向ピン、D6は速度ピンです。

<span style="color:red;">PWMはロボットカーを駆動します。PWM値は0-255の範囲です。方向をHIGHに設定すると、PWMの数値が小さいほどモーターの回転が速くなります。</span>

|            | D2   | D5（PWM） | Bモーター（左）       | D4   | D6（PWM） | Aモーター（右）       |
| ---------- | ---- | --------- | -------------------- | ---- | --------- | -------------------- |
| 前進       | HIGH | 255-200   | 時計回り回転         | HIGH | 255-200   | 時計回り回転         |
| 後退       | LOW  | 200       | 反時計回り回転       | LOW  | 200       | 反時計回り回転       |
| 左折       | HIGH | 255-200   | 時計回り回転         | LOW  | 200       | 反時計回り回転       |
| 右折       | LOW  | 200       | 反時計回り回転       | HIGH | 255-200   | 時計回り回転         |

### **4.コンポーネント**

| Development Board *1      | 8833 Motor Driver *1      | USB Cable*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A80.jpg) | ![img](media/A81.jpg) | ![img](media/A82.jpg)         |
| 18650 Battery Holder*1    | Motor*4                   | 18650 Battery *2（self-provided） |
| ![img](media/A83.png) | ![img](media/A84.jpg) | ![img](media/A85.png)         |

### **5.配線図**

![image-20250510090733191](media/A86.png)

電源をBATポートに接続します。

### **6.テストコード**

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.1
 Motor driver shield
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //グループBモーターの回転方向制御ピンを定義
#define ML_PWM 5   //グループBモーターのPWM制御ピンを定義
#define MR_Ctrl 4    //グループAモーターの回転方向制御ピンを定義
#define MR_PWM 6   //グループAモーターのPWM制御ピンを定義

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//グループBモーターの回転方向制御ピンを出力に設定
  pinMode(ML_PWM, OUTPUT);//グループBモーターのPWM制御ピンを出力に設定
  pinMode(MR_Ctrl, OUTPUT);//グループAモーターの回転方向制御ピンを出力に設定
  pinMode(MR_PWM, OUTPUT);//グループAモーターのPWM制御ピンを出力に設定
}
void loop()
{ 
  //前進
  digitalWrite(ML_Ctrl,HIGH);//グループBモーターの回転方向制御ピンをHIGHに設定
  analogWrite(ML_PWM,55);//グループBモーターのPWM制御速度を55に設定
  digitalWrite(MR_Ctrl,HIGH);//グループAモーターの回転方向制御ピンをHIGHに設定
  analogWrite(MR_PWM,55);//グループAモーターのPWM制御速度を55に設定
  delay(2000);//2000ms待機
  //後退
  digitalWrite(ML_Ctrl,LOW);//グループBモーターの回転方向制御ピンをLOWに設定
  analogWrite(ML_PWM,200);//グループBモーターのPWM制御速度を200に設定
  digitalWrite(MR_Ctrl,LOW);//グループAモーターの回転方向制御ピンをLOWに設定
  analogWrite(MR_PWM,200);//グループAモーターのPWM制御速度を200に設定
  delay(2000);//2000ms待機
  //左折
  digitalWrite(ML_Ctrl,LOW);//グループBモーターの回転方向制御ピンをLOWに設定
  analogWrite(ML_PWM,200);//グループBモーターのPWM制御速度を200に設定
  digitalWrite(MR_Ctrl,HIGH);//グループAモーターの回転方向制御ピンをHIGHに設定
  analogWrite(MR_PWM,55);//グループAモーターのPWM制御速度を55に設定
  delay(2000);//2000ms待機
  //右折
  digitalWrite(ML_Ctrl,HIGH);//グループBモーターの回転方向制御ピンをHIGHに設定
  analogWrite(ML_PWM,55);//グループBモーターのPWM制御速度を55に設定
  digitalWrite(MR_Ctrl,LOW);//グループAモーターの回転方向制御ピンをLOWに設定
  analogWrite(MR_PWM,200);//グループAモーターのPWM制御速度を200に設定
  delay(2000);//2000ms待機
  //停止
  digitalWrite(ML_Ctrl, LOW);//グループBモーターの回転方向制御ピンをLOWに設定
  analogWrite(ML_PWM,0);//グループBモーターのPWM制御速度を0に設定
  digitalWrite(MR_Ctrl, LOW);//グループAモーターの回転方向制御ピンをLOWに設定
  analogWrite(MR_PWM,0);//グループAモーターのPWM制御速度を0に設定
  delay(2000);//2000ms待機
}
//****************************************************************************
```

### **7.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源をオンにしてDIPスイッチをONにすると、車は2秒間前進し、2秒間後退し、2秒間左折し、2秒間右折し、2秒間停止します。

### **8.コード説明**

**digitalWrite(ML\_Ctrl,LOW):** モーターの回転方向はHIGH/LOWレベルによって決まり、回転方向を決定するピンはデジタルピンです。

**analogWrite(ML\_PWM,200):** モーターの速度はPWMで調整され、速度を決定するピンはPWMピンでなければなりません。

### **9.コード説明**

PWMでモーターの速度を調整します。配線は同じ方法で接続してください。

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.2
 Motor driver
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //グループBモーターの方向制御ピンを定義
#define ML_PWM 5   //グループBモーターのPWM制御ピンを定義
#define MR_Ctrl 4    //グループAモーターの方向制御ピンを定義
#define MR_PWM 6   //グループAモーターのPWM制御ピンを定義

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//グループBモーターの方向制御ピンを出力に設定
  pinMode(ML_PWM, OUTPUT);//グループBモーターのPWM制御ピンを出力に設定
  pinMode(MR_Ctrl, OUTPUT);//グループAモーターの方向制御ピンを出力に設定
  pinMode(MR_PWM, OUTPUT);//グループAモーターのPWM制御ピンを出力に設定
}
void loop()
{ 
  //前進
  digitalWrite(ML_Ctrl,HIGH);//グループBモーターの方向制御ピンをHIGHに設定
  analogWrite(ML_PWM,105);//グループBモーターのPWM制御速度を105に設定
  digitalWrite(MR_Ctrl,HIGH);//グループAモーターの方向制御ピンをHIGHに設定
  analogWrite(MR_PWM,105);//グループAモーターのPWM制御速度を105に設定
  delay(2000);//2000ms待機
  //後退
  digitalWrite(ML_Ctrl,LOW);//グループBモーターの方向制御ピンをLOWに設定
  analogWrite(ML_PWM,150);//グループBモーターのPWM制御速度を150に設定
  digitalWrite(MR_Ctrl,LOW);//グループAモーターの方向制御ピンをLOWに設定
  analogWrite(MR_PWM,150);//グループAモーターのPWM制御速度を150に設定
  delay(2000);//2000ms待機
  //左折
  digitalWrite(ML_Ctrl,LOW);//グループBモーターの方向制御ピンをLOWに設定
  analogWrite(ML_PWM,150);//グループBモーターのPWM制御速度を150に設定
  digitalWrite(MR_Ctrl,HIGH);//グループAモーターの方向制御ピンをHIGHに設定
  analogWrite(MR_PWM,105);//グループAモーターのPWM制御速度を105に設定
  delay(2000);//2000ms待機
  //右折
  digitalWrite(ML_Ctrl,HIGH);//グループBモーターの方向制御ピンをHIGHに設定
  analogWrite(ML_PWM,105);//グループBモーターのPWM制御速度を105に設定
  digitalWrite(MR_Ctrl,LOW);//グループAモーターの方向制御ピンをLOWに設定
  analogWrite(MR_PWM,150);//グループAモーターのPWM制御速度を150に設定
  delay(2000);//2000ms待機
  //停止
  digitalWrite(ML_Ctrl, LOW);//グループBモーターの方向制御ピンをLOWに設定
  analogWrite(ML_PWM,0);//グループBモーターのPWM制御速度を0に設定
  digitalWrite(MR_Ctrl, LOW);//グループAモーターの方向制御ピンをLOWに設定
  analogWrite(MR_PWM,0);//グループAモーターのPWM制御速度を0に設定
  delay(2000);//2000ms待機
}
//************************************************************************
```

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線を接続し、外部電源の電源を入れ、DIPスイッチをONにすると、モーターの速度がかなり遅くなっていることがわかります。

<span style="color: rgb(255, 76, 65);">注意: バッテリー残量が低いとモーターの速度が遅くなります。</span> 
