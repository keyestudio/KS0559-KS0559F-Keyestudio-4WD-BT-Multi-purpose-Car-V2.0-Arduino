# Proyecto 3: Sensor de Seguimiento de Línea

![](media/A17.png)

### **1. Descripción**

El sensor de seguimiento es en realidad un sensor infrarrojo. El componente utilizado aquí es el tubo infrarrojo TCRT5000. Su principio de funcionamiento es usar la diferente reflectividad de la luz infrarroja en los colores, y luego convertir la intensidad de la señal reflejada en una señal de corriente.

Durante el proceso de detección, el negro es activo en nivel ALTO mientras que el blanco es activo en nivel BAJO. La altura de detección es de 0-3 cm.

El módulo de seguimiento de línea de 3 canales de Keyestudio integra 3 conjuntos de tubos infrarrojos TCRT5000 en una placa, lo que facilita el cableado y control.

Girando el potenciómetro ajustable en el sensor, se puede ajustar la sensibilidad de detección del sensor.

### **2. Especificaciones**

- Voltaje de operación: 3.3-5V (DC)

- Interfaz: 5PIN

- Señal de salida: Señal digital

- Altura de detección: 0-3 cm

![image-20250508163247479](media/A18.png)

<span style="color: rgb(255, 76, 65);">Nota: Antes de la prueba, gire el potenciómetro en el sensor para ajustar la sensibilidad de detección. La sensibilidad es óptima cuando se ajusta el LED a un umbral entre ENCENDIDO y APAGADO.</span> 

### **3. Componentes**

| Placa de Desarrollo *1                  | Driver de Motor 8833 *1                  | Módulo LED Rojo *1       | Sensor de Seguimiento de Línea *1 |
| -------------------------------------- | --------------------------------------- | ------------------------ | --------------------------------- |
| ![img](media/A8.jpg)                   | ![img](media/A9.jpg)                     | ![img](media/A10.jpg)    | ![img](media/A19.png)             |
| Cable Dupont 5P *1                     | Cable USB *1                            | Cable Dupont 3P *1       |                                   |
| ![img](media/A20.png)                  | ![img](media/A12.jpg)                    | ![img](media/A11.jpg)    |                                   |

### **4. Diagrama de Conexiones**

![image-20250508164243044](media/A21.png)

G, V, S1, S2 y S3 del sensor de seguimiento de línea están conectados a G (GND), V (VCC), D11, D7 y D8 de la placa de expansión del sensor.

### **5. Código de Prueba**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 3.1 
 Line Track sensor
 http://www.keyestudio.com
*/
int L_pin = 11;  //pines del sensor de seguimiento de línea izquierdo
int M_pin = 7;  //pines del sensor de seguimiento de línea medio
int R_pin = 8;  //pines del sensor de seguimiento de línea derecho
int val_L,val_R,val_M;// definir las variables de valor de los tres sensores

void setup()
{
  Serial.begin(9600); // inicializar comunicación serial a 9600 bits por segundo
  pinMode(L_pin,INPUT); // configurar L_pin como entrada
  pinMode(M_pin,INPUT); // configurar M_pin como entrada
  pinMode(R_pin,INPUT); // configurar R_pin como entrada
}

void loop() 
{ 
  val_L = digitalRead(L_pin);//leer L_pin:
  val_R = digitalRead(R_pin);//leer R_pin:
  val_M = digitalRead(M_pin);//leer M_pin:
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// retardo entre lecturas para estabilidad
}
//****************************************************************************
```

### **6. Resultado de la Prueba**

Después de subir el código exitosamente a la placa V4.0, conecta los cables según el diagrama de conexiones y usa un cable USB para conectar la computadora y alimentar la placa.

Al encender, abre el monitor serial y verás el estado de los tres sensores de seguimiento de línea. Cuando no se reciben señales, el valor es 1. Si cubrimos el sensor con un papel blanco, el valor será 0.

![image-20250508164424571](media/A22.png)

![image-20250508164453274](media/A23.png)

### **7. Explicación del Código**

Serial.begin(9600) - Inicializa el puerto serial, establece la velocidad en baudios a 9600

pinMode - Define el pin como modo entrada o salida

digitalRead - Lee el estado del pin, que generalmente es nivel ALTO o BAJO

### **8. Práctica de Extensión**

Después de conocer su principio de funcionamiento, puedes conectar un LED al pin D9 para controlar el LED con el sensor.

![image-20250508164527429](media/A24.png)

```c
/*
keyestudio 4wd BT Car
lesson 3.2
 Line Track Sensor LED
 http://www.keyestudio.com
*/
int L_pin = 11;  //pines del sensor de seguimiento de línea izquierdo
int M_pin = 7;  //pines del sensor de seguimiento de línea central
int R_pin = 8;  //pines del sensor de seguimiento de línea derecho
int val_L,val_R,val_M;// definir las variables de los tres sensores 

void setup()
{
  Serial.begin(9600); // inicializar comunicación serial a 9600 bits por segundo
  pinMode(L_pin,INPUT); // configurar L_pin como entrada
  pinMode(M_pin,INPUT); // configurar M_pin como entrada
  pinMode(R_pin,INPUT); // configurar R_pin como entrada
  pinMode(9, OUTPUT);
}

void loop() 
{ 
  val_L = digitalRead(L_pin);//leer el L_pin:
  val_R = digitalRead(R_pin);//leer el R_pin:
  val_M = digitalRead(M_pin);//leer el M_pin:
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// retardo entre lecturas para estabilidad
  if ((val_L == LOW) || (val_M == LOW) || (val_R == LOW))//si el sensor de seguimiento de línea izquierdo detecta señales
  { 
    Serial.println("HIGH");
    digitalWrite(9, HIGH);//LED está encendido
  }
  else//si el sensor de seguimiento de línea izquierdo no detecta señales
  { 
    Serial.println("LOW");
    digitalWrite(9, LOW);//LED está apagado
  }
 }
//****************************************************************************
```

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones y usa un cable USB para conectar la computadora y alimentar la placa.

Después de encender, acerca un papel al sensor, entonces podremos ver que el LED se enciende al cubrir el sensor de seguimiento de línea.