# Proyecto 7 Control Remoto Bluetooth

### **1.Descripción**

![image-20250510083107283](media/A47.png)

En este kit hay un módulo Bluetooth DX-BT24 5.1. Este módulo bluetooth cuenta con un espacio de 256Kb y cumple con la especificación Bluetooth V5.1BLE, que soporta comandos AT. Los usuarios pueden cambiar parámetros como la velocidad en baudios y el nombre del dispositivo del puerto serial según sea necesario.

Además, soporta interfaz UART y transmisión transparente por puerto serial bluetooth, lo que también contiene las ventajas de bajo costo, tamaño pequeño, bajo consumo de energía y alta sensibilidad para enviar y recibir. Notablemente, solo necesita unos pocos componentes periféricos para realizar sus potentes funciones.

### **2.Especificaciones**

- Protocolo Bluetooth: Especificación Bluetooth V5.1 BLE

- Distancia de trabajo: En un entorno abierto, puede alcanzar comunicación de ultra larga distancia de 40m

- Frecuencia de operación: Banda ISM de 2.4GHz

- Interfaz de comunicación: UART

- Certificación Bluetooth: Conforme con los estándares de certificación FCC CE ROHS REACH

- Parámetros del puerto serial: 9600, 8 bits de datos, 1 bit de parada, bit inválido, sin control de flujo

- Alimentación: 5V DC

- Temperatura de operación: –10℃ a +65℃

### **3.Aplicación**

El módulo DX-BT24 también soporta el protocolo BT5.1 BLE, que puede conectarse directamente a dispositivos iOS con función Bluetooth BLE, y soporta la ejecución residente de programas en segundo plano. Se utiliza principalmente en el campo de transmisión inalámbrica de datos a corta distancia. Permite evitar conexiones de cables engorrosas y puede reemplazar directamente cables seriales.

**Áreas de aplicación exitosas de los módulos BT24:**

※ Transmisión inalámbrica de datos Bluetooth;

※ Equipos periféricos para teléfonos móviles y computadoras;

※ Equipos POS portátiles;

※ Transmisión inalámbrica de datos en equipos médicos;

※ Control de hogares inteligentes;

※ Impresoras Bluetooth;

※ Juguetes con control remoto Bluetooth;

※ Bicicletas compartidas;

### **4.Puertos**

![420af966-aaa4-4736-9d35-2a9ccc7215f3](media/A48.png)

①STATE：Pin de estado

②RX：Pin receptor

③TX：Pin transmisor

④GND：Tierra (GND)

⑤VCC：Alimentación

⑥EN：Pin de habilitación

Conecta el módulo BT a la placa de desarrollo.

| Uno  | BT24 |
| :--: | :--: |
|  TX  |  RX  |
|  RX  |  TX  |
| VCC  |  5V  |
| GND  | GND  |

### **5.Componentes**

|           Placa de Desarrollo *1           |           Driver de Motor 8833 *1           |                       Módulo LED Rojo *1                       |
| :----------------------------------------: | :------------------------------------------: | :------------------------------------------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) |                   ![img](media/A10.jpg)                   |
|             Cable Dupont 3P *1             |               Cable USB *1                |                  Módulo Bluetooth DX-BT24 *1                  |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         | ![image-20250510083534209](media/A49.png) |

### **6.Diagrama de Conexiones**

![image-20250510083927915](media/A50.png)

RXD, TXD, GND y VCC del módulo BT están conectados a TX, RX, G y 5V.

STATE y BRK del módulo BT no necesitan conexión.

<span style="color: rgb(255, 76, 65);">Nota: la dirección del módulo BT al insertarlo en la placa 8833. Y no lo inserte antes de subir el código.</span> 

### **7.Código de Prueba**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, debe retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecte el módulo Bluetooth después de subir el código con éxito.</span>

```c
//***********************************************************************
/*
keyestudio 4wd BT Car
lesson 7.1
Bluetooth 
http://www.keyestudio.com
*/
char ble_val; //variable de carácter, usada para almacenar el valor recibido por Bluetooth 

```cpp
void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0)  //asegúrate de que haya datos en el buffer serial
  {
    ble_val = Serial.read();  //Leer datos del buffer serial
    Serial.println(ble_val);  //Imprimir
  }
}
//***********************************************************************
```

### **8. Resultado de la prueba**

Después de subir con éxito el código a la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, inserta el módulo BT y el LED parpadeará, luego necesitamos descargar la aplicación BT.

### **9. Descargar la APP de Bluetooth**

**Sistema Apple**

(1). Abre la App Store en el iPhone.

(2). Busca keyes BT car y descarga la APP en tu teléfono.

![image-20250510084716811](media/A51.png)
    
(3). Después de la instalación, entra en su interfaz.

![image-20250510084812821](media/A52.png)
    
(4). Haz clic en el botón "**Connect**" en la esquina superior izquierda para buscar automáticamente Bluetooth. Cuando se encuentre **BT24**, haz clic en "**Connect**" para conectar Bluetooth, y luego haz clic en ![image-20250510084833837](media/A53.png) para entrar en la interfaz de control del coche inteligente 4WD.

![image-20250510084902641](media/A54.png)

**Sistema Android**

(1). Entra en Google Play Store para buscar “keyes 4wd”.

![image-20250510084916086](media/A55.png)

(2). El icono de la app se muestra a continuación después de la instalación.

![image-20250510084933465](media/A56.png)

(3). Haz clic en la app para entrar en la siguiente página.

![image-20250510084946146](media/A57.png)

(4). Después de conectar Bluetooth, conecta la alimentación y el indicador LED del módulo Bluetooth parpadeará. Pulsa “**Connect**” para buscar el Bluetooth.

![image-20250510085007028](media/A58.png)

(5). Cuando se encuentre **BT24**, haz clic en "Connect" para conectar Bluetooth. Cuando "**Connect**" cambie a "**is Connected**", indica que la conexión Bluetooth fue exitosa. Como se muestra en la imagen a continuación, el LED de Bluetooth permanecerá encendido.

![image-20250510085026219](media/A59.png)

(6). Después de conectar el módulo Bluetooth, abre el monitor serial y configura la velocidad en 9600 baudios. Al presionar el botón de la APP Bluetooth, se mostrarán los caracteres correspondientes, como se muestra a continuación:

![image-20250510085039562](media/A60.png)

| Tecla                     | Función                          |
| ------------------------- | --------------------------------- |
| ![img](./media/A61.jpg)   | Emparejar módulo Bluetooth DX-BT24 5.1 |
| ![img](./media/A62.jpg)   | Desconectar Bluetooth              |

|                           | Carácter de control                                         | Carácter de control                                         |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Pulsar: F  <br />Soltar: S                                   | Pulsar el botón, el coche avanza; <br />soltar para parar    |
| ![img](media/A64.jpg) | Pulsar: L  <br />Soltar: S                                   | Pulsar el botón, el coche gira a la izquierda; <br />soltar para parar  |
| ![img](media/A65.jpg) | Pulsar: R  <br />Soltar: S                                   | Pulsar el botón, el coche gira a la derecha; <br />soltar para parar |
| ![img](media/A66.jpg) | Pulsar: B  <br />Soltar: S                                   | Pulsar el botón, el coche retrocede; <br />soltar para parar   |
| ![img](media/A67.jpg) | Pulsar: “a”  <br />Soltar: “S”                               | Pulsar para acelerar (máximo:255)                            |
| ![img](media/A68.jpg) | Pulsar: “d”  <br />Soltar: “S”                               | Pulsar para desacelerar (mínimo:0)                           |
| ![img](media/A69.jpg) | Pulsar para iniciar la función de detección de gravedad <br />del teléfono móvil: pulsar de nuevo para <br />salir del control por detección de gravedad |                                                              |
| ![img](media/A70.jpg) | Pulsar para enviar “X”, <br />pulsar de nuevo para enviar “S” | Iniciar función de seguimiento de línea; <br />pulsar de nuevo para salir |
| ![img](media/A71.jpg) | Pulsar para enviar “Y”, <br />pulsar de nuevo para enviar “S” | Iniciar función de evitación ultrasónica; <br />pulsar de nuevo para salir |
| ![img](media/A72.jpg) | Pulsar para enviar “U”, <br />pulsar de nuevo para enviar “S” | Iniciar función de seguimiento ultrasónico; <br />pulsar de nuevo para salir |
| ![img](media/A73.jpg) | Pulsar para enviar “G”, <br />pulsar de nuevo para enviar “S” | Iniciar función de restricción; <br />pulsar de nuevo para salir |

### **9. Explicación del Código**

**Serial.available()** : Devuelve el número de caracteres que quedan actualmente en el búfer del puerto serial. Generalmente, esta función se usa para determinar si hay datos en el búfer del puerto serial. Cuando Serial.available() > 0, significa que el puerto serial ha recibido datos y se pueden leer;

**Serial.read() :** Se refiere a extraer y leer un Byte de datos del búfer del puerto serial. Por ejemplo, si un dispositivo envía datos a Arduino a través del puerto serial, podemos usar Serial.read() para leer los datos enviados.

### **10. Práctica de Extensión**

Aquí buscamos usar el comando enviado por el teléfono móvil para encender o apagar un LED. Observando el diagrama de conexiones, un LED está conectado al pin D9.

![image-20250510085856954](media/A74.png)

```c
//****************************************************************************
/*
 keyestudio smart turtle robot
 lesson 7.2
 Bluetooth LED
 http://www.keyestudio.com
*/ 
int ledpin=9;
char ble_val;// Una variable entera usada para almacenar el valor recibido por Bluetooth

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop()
{ 
  if (Serial.available() > 0) //Comprobar si hay datos en el caché del puerto serial
  {
    ble_val = Serial.read();  //Leer datos del caché del puerto serial
    Serial.print("DATOS RECIBIDOS:");
    Serial.println(ble_val);
    if (ble_val == 'F') {
      digitalWrite(ledpin, HIGH);
      Serial.println("led encendido");
    }
    if (ble_val == 'B') {
      digitalWrite(ledpin, LOW);
      Serial.println("led apagado");
    }
   }
}
//****************************************************************************
```

Después de cargar correctamente el código en la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, haz clic en ![image-20250510085919039](media/A75.png) y ![image-20250510085931709](media/A76.png) para controlar el encendido y apagado del LED.