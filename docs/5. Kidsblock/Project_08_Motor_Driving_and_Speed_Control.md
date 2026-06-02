# Proyecto 8 Conducción y Control de Velocidad del Motor

![](media/A205.png)

### **1. Descripción**

Existen muchas formas de conducir motores. Nuestro coche utiliza el chip controlador de motor DRV8833 más comúnmente usado, que proporciona una solución de conducción eléctrica de puente de dos canales para juguetes, impresoras y otras aplicaciones integradas de motores.

Cuando apilamos la placa de expansión del controlador sobre la placa de desarrollo 4.0 y encendemos la alimentación BAT, luego configuramos el interruptor DIP en la posición ON, la fuente de alimentación externa alimentará ambas placas al mismo tiempo. Para facilitar las conexiones de cableado, la placa de expansión del controlador viene con un puerto anti-inversión (PH2.0-2P-3P-4P-5P). Puedes conectar los motores, la fuente de alimentación y los módulos sensores directamente a la placa de expansión del controlador.

La interfaz Bluetooth de la placa de expansión del controlador es totalmente compatible con el módulo Bluetooth DX-BT24 5.1. Al conectar el módulo Bluetooth, solo necesitas enchufarlo en la interfaz correspondiente. Al mismo tiempo, se utilizan pines de fila 2.54 para sacar algunos puertos digitales y analógicos no usados en la placa de expansión del controlador, facilitando que añadas otros sensores y realices experimentos de extensión.

La placa de expansión puede conectarse a cuatro motores DC. Cuando el puente jumper está conectado por defecto, los motores de los puertos A y A1 y B y B1 están conectados en paralelo y tienen la misma ley de movimiento. 8 puentes jumper pueden usarse para controlar la dirección de rotación de las 4 interfaces de motor.

Por ejemplo, cuando los 2 puentes jumper delante de B1 del motor M1 cambian de conexión transversal a conexión longitudinal, la dirección de rotación del motor M1 será opuesta a la dirección original.

### **2. Especificaciones**

- Voltaje de entrada para lógica: DC 5V

- Voltaje de entrada para conducción: DC 6-9 V

- Corriente de trabajo para lógica: \<36mA

- Corriente de trabajo para conducción: \<2A

- Máxima disipación de potencia: 25W (T=75℃)

- Nivel de entrada para señal de control: nivel alto es 2.3V\<Vin\<5V, nivel bajo es -0.3V\<Vin\<1.5V

- Temperatura de trabajo: -25＋130℃

### **3. Placa de expansión del controlador de motor Keyestudio 8833**

![](media/A206.png)

**Principio de funcionamiento**

Usamos el modo de conexión paralela del mismo lado para los cuatro motores, que pueden considerarse dos grupos de motores. Como se muestra en el diagrama de cableado, B y B1 son un grupo, y A y A1 son otro grupo.

Los motores en el mismo grupo deben girar en la misma dirección. Si son diferentes, ajusta los puentes jumper correspondientes junto al terminal para cambiar la dirección.

Como se muestra a continuación, si las direcciones de A y A1 son diferentes, ajusta la dirección de los puentes jumper hasta que la dirección de movimiento de los motores del mismo grupo sea consistente.

![](media/A207.png)

Del diagrama anterior, se sabe que el pin de dirección del motor A es D4, el pin de velocidad es D6; D2 es el pin de dirección del motor B; y D6 es el pin de velocidad.

PWM conduce el coche robot. El valor PWM está en el rango de 0-255. Cuando configuramos la dirección a HIGH, cuanto menor sea el número PWM, más rápida será la rotación del motor.

<table border="1">
<tbody>
<tr class="odd">
<td></td>
<td>D2</td>
<td>D5（PWM）</td>
<td>Motor B（izquierdo）</td>
<td>D4</td>
<td>D6（PWM）</td>
<td>Motor A（derecho）</td>
</tr>
<tr class="even">
<td>Avanzar</td>
<td>HIGH</td>
<td>255-200</td>
<td>Gira en sentido horario</td>
<td>HIGH</td>
<td>255-200</td>
<td>Gira en sentido horario</td>
</tr>
<tr class="odd">
<td>Retroceder</td>
<td>LOW</td>
<td>200</td>
<td>Gira en sentido antihorario</td>
<td>LOW</td>
<td>200</td>
<td>Gira en sentido antihorario</td>
</tr>
<tr class="even">
<td>Girar a la izquierda</td>
<td>HIGH</td>
<td>255-200</td>
<td>Gira en sentido horario</td>
<td>LOW</td>
<td>200</td>
<td>Gira en sentido antihorario</td>
</tr>
<tr class="odd">
<td>Girar a la derecha</td>
<td>LOW</td>
<td>200</td>
<td>Gira en sentido antihorario</td>
<td>HIGH</td>
<td>255-200</td>
<td>Gira en sentido horario</td>
</tr>
</tbody>
</table>
### **4. Componentes**

| Placa de Desarrollo *1      | Driver de Motor 8833 *1      | Cable USB*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A208.jpg) | ![img](media/A209.jpg) | ![img](media/A210.jpg)         |
| Soporte para Batería 18650*1    | Motor*4                   | Batería 18650 *2（auto-proporcionada） |
| ![img](media/A211.png) | ![img](media/A212.jpg) | ![img](media/A213.png)         |



### **5.Diagrama de Conexiones**

![](media/A214.png)

Conecte la fuente de alimentación al puerto BAT.

### **6.Código de Prueba**

Puede arrastrar bloques para editar. Los bloques listados a continuación son para su referencia

(1).![](media/A126.png)

(2).![](media/A215.png)

(3).![](media/A216.png)

**Código de Prueba Completo**

![Img](media/A217.png)

![](media/A218.png)

### **7.Resultado de la Prueba**

Después de cargar el código con éxito en la placa V4.0, conecte los cables según el diagrama de conexiones, luego encienda la fuente de alimentación externa y ponga el interruptor DIP en ON, el coche avanzará durante 2s, retrocederá durante 2s, girará a la izquierda durante 2s y a la derecha durante 2s y se detendrá durante 2s.

### **8.Explicación del Código**

Ajuste la velocidad que controla el motor mediante PWM, conecte de la misma manera.

**Código de Prueba Completo**

![Img](media/A219.png)

![](media/A220.png)

Después de cargar el código con éxito en la placa V4.0, conecte los cables según el diagrama de conexiones, luego encienda la fuente de alimentación externa y ponga el interruptor DIP en ON, entonces notará que la velocidad del motor es mucho más lenta.

<span style="color: rgb(255, 76, 65);">Nota: </span>Una batería baja provocará una velocidad lenta del motor.