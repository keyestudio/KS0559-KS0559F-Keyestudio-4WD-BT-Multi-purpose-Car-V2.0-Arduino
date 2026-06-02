# Proyecto 7 Control Remoto Bluetooth

![](media/A161.png)

### **1.Descripción**

En este kit hay un módulo Bluetooth DX-BT24 5.1. Este módulo bluetooth cuenta con un espacio de 256Kb y cumple con la especificación Bluetooth V5.1BLE, que soporta comandos AT. Los usuarios pueden cambiar parámetros como la velocidad en baudios y el nombre del dispositivo del puerto serie según sea necesario.

Además, soporta interfaz UART y transmisión transparente del puerto serie bluetooth, lo que también contiene las ventajas de bajo costo, tamaño pequeño, bajo consumo de energía y alta sensibilidad para enviar y recibir. Notablemente, solo necesita unos pocos componentes periféricos para realizar sus potentes funciones.

### **2.Especificaciones**

- Protocolo Bluetooth: Especificación Bluetooth V5.1 BLE

- Distancia de trabajo: En un entorno abierto, puede alcanzar una comunicación de ultra larga distancia de 40m
  
- Frecuencia de operación: Banda ISM de 2.4GHz

- Interfaz de comunicación: UART

- Certificación Bluetooth: Conforme con los estándares de certificación FCC CE ROHS REACH
  
- Parámetros del puerto serie: 9600, 8 bits de datos, 1 bit de parada, bit inválido, sin control de flujo
  
- Alimentación: 5V DC

- Temperatura de operación: –10℃ a +65℃
  

### **3.Aplicación**

El módulo DX-BT24 también soporta el protocolo BT5.1 BLE, que puede conectarse directamente a dispositivos iOS con función Bluetooth BLE, y soporta la ejecución residente de programas en segundo plano. Se usa principalmente en el campo de transmisión inalámbrica de datos a corta distancia. Permite evitar conexiones de cables engorrosas y puede reemplazar directamente cables seriales.

**Áreas de aplicación exitosas de los módulos BT24:**

※ Transmisión inalámbrica de datos Bluetooth;

※ Equipos periféricos para teléfonos móviles y computadoras;

※ Equipos POS portátiles;

※ Transmisión inalámbrica de datos en equipos médicos;

※ Control de hogares inteligentes;

※ Impresoras Bluetooth;

※ Juguetes con control remoto Bluetooth;

※ Bicicletas compartidas;

**Puertos**

![](media/A162.png)

①STATE: Pin de estado

②RX: Pin de recepción

③TX: Pin de envío

④GND: Tierra (GND)

⑤VCC: Alimentación

⑥EN: Pin de habilitación

Conectar el módulo BT a la placa de desarrollo.

<table border="1">
<tbody>
<tr class="odd">
<td>Uno</td>
<td>BT24</td>
</tr>
<tr class="even">
<td>TX</td>
<td>RX</td>
</tr>
<tr class="odd">
<td>RX</td>
<td>TX</td>
</tr>
<tr class="even">
<td>VCC</td>
<td>5V</td>
</tr>
<tr class="odd">
<td>GND</td>
<td>GND</td>
</tr>
</tbody>
</table>


### **4.Componentes**

| Placa de Desarrollo *1      | Driver de Motor 8833 *1      | Módulo LED Rojo*1           |
| ------------------------- | ------------------------- | -------------------------- |
| ![img](media/A163.jpg) | ![img](media/A164.jpg) | ![img](media/A165.jpg)  |
| Cable Dupont 3P F-F *1      | Cable USB *1               | Módulo Bluetooth DX-BT24 *1 |
| ![img](media/A166.jpg) | ![img](media/A167.jpg) | ![img](media/A168.jpg)  |

### **5.Diagrama de Conexiones**

![](media/A169.png)

RXD, TXD, GND y VCC del módulo BT se conectan a TX, RX, G y 5V.

STATE y BRK del módulo BT no necesitan conexión.

<span style="color: rgb(255, 76, 65);">Nota:</span> la dirección del módulo BT al insertarlo en la placa 8833. Y no insertarlo antes de subir el código.

### **6.Código de Prueba**

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A172.png)

(5).![](media/A173.png)

**Código de Prueba Completo**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, necesitas retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecta el módulo Bluetooth después de subir el código exitosamente.</span>

![](media/A174.png)

### **7.Resultado de la Prueba**

Después de subir exitosamente el código a la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encender, inserta el módulo BT y el LED parpadeará, luego necesitamos descargar la app BT.

### **8.Descargar APP Bluetooth**

**Sistema Apple**

(1).Abre la App Store en el iPhone.

(2).Busca keyes BT car y descarga la APP en tu teléfono.

![](media/A175.png)
    

(3).Después de la instalación, entra en su interfaz.

![](media/A176.png)
    

(4).Haz clic en el botón "**Connect**" en la esquina superior izquierda para buscar automáticamente Bluetooth. Cuando se encuentre **BT24**, haz clic en "**Connect**" para conectar Bluetooth, y luego haz clic en ![](media/A177.png) para entrar en la interfaz de control del coche inteligente 4WD. 

![](media/A178.png)
    
**Sistema Android**
    

(1).Entra en google play store para buscar “**keyes 4wd**”.

![](media/A179.png)

(2).El icono de la app se muestra a continuación después de la instalación.

![](media/A180.png)

(3).Haz clic en la app para entrar en la siguiente página.

![](media/A181.png)

(4).Después de conectar Bluetooth, conecta la alimentación y el indicador LED del módulo Bluetooth parpadeará. Pulsa “Connect” para buscar el Bluetooth.

![](media/A182.jpeg)

(5).Cuando se encuentre **BT24**, haz clic en "**connect**" para conectar Bluetooth. Cuando "**connect**" cambie a "**is connected**", indica que la conexión Bluetooth fue exitosa. Como se muestra en la imagen a continuación, el LED de Bluetooth permanecerá encendido.

![](media/A183.jpeg)

(6).Después de conectar el módulo Bluetooth, haz clic en ![](media/A80.png) para configurar la velocidad en baudios a 9600. Al presionar el botón de la APP Bluetooth, se mostrarán los caracteres correspondientes, como se muestra a continuación:

![](media/A184.png)

| Tecla                                         | Función                          |
| -------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Emparejar módulo Bluetooth DX-BT24 5.1 |
| ![wps15](media/A186.jpg) | Desconectar Bluetooth              |

|                                                              | Carácter de control                                            | Función                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Presionar: F  <br />Soltar: S                                   | Presiona el botón, el coche avanza; <br />suéltalo para detener |
| ![wps17](media/A188.jpg)                 | Presionar: L  <br />Soltar: S                                   | Presiona el botón, el coche gira a la izquierda; <br />suéltalo para detener  |
| ![wps18](media/A189.jpg)                 | Presionar: R  <br />Soltar: S                                   | Presiona el botón, el coche gira a la derecha; <br />suéltalo para detener |
| ![wps19](media/A190.jpg)                 | Presionar: B  <br />Soltar: S                                   | Presiona el botón, el coche retrocede; <br />suéltalo para detener   |
| ![wps20](media/A191.jpg)                 | Presionar: “a”  <br />Soltar: “S”                               | Clic para acelerar (máximo: 255)                               |
| ![wps21](media/A192.jpg)                 | Presionar: “d”  <br />Soltar: “S”                               | Clic para desacelerar (mínimo: 0)                                |
| ![wps22](media/A193.jpg)                 | Clic para iniciar la función de detección de gravedad del <br />teléfono móvil: clic de nuevo para <br />salir del control por gravedad |                                                              |
| ![wps23](media/A194.jpg)                 | Clic para enviar “X”,<br />clic de nuevo para enviar “S”               | Iniciar función de seguimiento de línea; <br />clic de nuevo para salir      |
| ![wps24](media/A195.jpg)                 | Clic para enviar “Y”, <br />clic de nuevo para enviar “S”               | Iniciar función de evitación ultrasónica;<br />clic de nuevo para salir |
| ![wps25](media/A196.jpg) | Clic para enviar “U”, <br />clic de nuevo para enviar “S”               | Iniciar función de seguimiento ultrasónico;<br />clic de nuevo para salir |
| ![wps26](media/A197.jpg)                 | Clic para enviar “G”,<br />clic de nuevo para enviar “S”                | Iniciar función de restricción;<br />clic de nuevo para salir       |

### **9.Práctica de extensión**

Aquí vamos a usar el comando enviado por el teléfono móvil para encender o apagar una luz LED. Observando el diagrama de conexiones, un LED está conectado al pin D9.

![](media/A198.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A199.png)

(5).![](media/A173.png)

(6).![](media/A200.png)

(7).![](media/A201.png)

**Código de prueba completo**

![](media/A202.png)

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encender, haz clic en <td>![](media/A203.png)</td> y <td>![](media/A204.png)</td> para controlar el encendido y apagado del LED.