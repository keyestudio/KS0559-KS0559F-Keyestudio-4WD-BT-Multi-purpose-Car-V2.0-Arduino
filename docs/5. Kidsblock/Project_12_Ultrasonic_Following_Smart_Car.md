# Project 12 超音波追従スマートカー

![](media/A280.png)

### **1.説明**

このプロジェクトでは、超音波センサーを使って4WDスマートカーと前方の障害物との距離を検出し、2つのモーターを制御して車を動かし、8\*8 LEDボードに笑顔のパターンを表示させます。

### **2.フローチャート**

![img](media/A281.png)

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

![](media/A282.png)

**配線方法：**

1). 8\*8 LEDボードのGND、VCC、SDA、SCLを拡張ボードのG（GND）、V（VCC）、A4、A5に接続します。

2). 超音波センサーのVCC、Trig、Echo、Gndをそれぞれ5V(V)、D12(S)、D13(S)、Gnd(G)に接続します。

3). サーボはG、V、A3に接続します。茶色の線はGnd(G)、赤色の線は5V(V)、オレンジ色の線はA3に接続します。

4). 電源はBATポートに接続します。

### **4.テストコード**

コードを書く前に、超音波センサー、8x16 LEDボード、サーボのライブラリファイルをインポートする必要があります。具体的な手順は以下の通りです：

センサー/モジュール/コンポーネントの拡張ライブラリ画面に入るには ![](media/A29.png) をクリックし、「Ultrasonic」センサーを検索して ![](media/A122.png) をクリックします。

これで「**Not loaded**」が「**loaded**」に変わり、「**Ultrasonic**」センサーが正常に追加されたことを示します。

![Img](media/A283.png)

![](/media/A284.png)

8x16 LEDボードとサーボのライブラリファイルも超音波センサーと同様に追加します。

![](media/A33.png) をクリックしてコードエディタ画面に戻ると、追加した「**Ultrasonic**」センサー、「**Matrix 8\*16 Aip1640**」モジュール、「**Servo**」コンポーネントの命令ブロックがモジュールエリアに表示されます。

![](media/A285.png)

ブロックをドラッグして編集できます。以下のブロックは参考用です。

(1).![](media/A126.png)

(2).![](media/A286.png)

(3).![](media/A287.png)

(4).![](media/A288.png)

(5).![](media/A268.png)

(6).![](media/A289.png)

(7).![](media/A290.png)

(8).![](media/A291.png)

(9).![](media/A292.png)

**完成したテストコード**

![](media/A293.png)

![](media/A294.png)

![](media/A295.png)

### **5.テスト結果**

コードをV4.0ボードに正常にアップロードした後、配線図に従って配線し、外部電源を入れてDIPスイッチをONにします。サーボを90°に設定すると、スマートカーは障害物に合わせて動き、8X16 LEDボードに「smile」が表示されます。