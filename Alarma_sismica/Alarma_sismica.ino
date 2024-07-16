/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Alarma sismica
   Dev: Josue Julian de Jesús Robles Larios
   Fecha: 15 de Julio 
*/
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <Wire.h>                    // Librería que permite usar el protocolo I2C
#include <SparkFun_ADXL345.h>        // Librería que permite usar el acelerómetro ADXL345

ADXL345 acelerometro_ADXL345 = ADXL345();    // Constructor para poder utilizar el acelerómetro.
SoftwareSerial DFPlayerSerial(11, 10);       // Configuración de pines para comunicación serial con el DFPlayer Mini
DFRobotDFPlayerMini tilin;                   // Objeto para controlar el DFPlayer Mini

int pines[] = {2, 3, 4, 5, 6, 7, 8, 9};
// Variables donde guardo las aceleraciones.
int x, y, z;
float resultante;
float gravedad;
unsigned int barra_led;

void setup() {
  Serial.begin(9600);     // Inicio de la comunicación serial a 9600 baudios.
  DFPlayerSerial.begin(9600); // Comunicación serial para el DFPlayer Mini
  tilin.begin(DFPlayerSerial); // Inicialización del DFPlayer Mini
  tilin.volume(20);     // Configuración del volumen del DFPlayer Mini
  acelerometro_ADXL345.powerOn();             // Enciende el acelerómetro.
  acelerometro_ADXL345.setRangeSetting(2);    // Configura para medir la aceleración con 2g.
  for (int i = 0; i < 8; i++)                 // Configura los pines como salidas
    pinMode(pines[i], OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop() {
  acelerometro_ADXL345.readAccel(&x, &y, &z); // Lee las aceleraciones en los ejes x, y, y z

  float valorx = x * 9.81 / 256; // Conversión de la lectura del acelerómetro a m/s^2
  float valory = y * 9.81 / 256;
  float valorz = z * 9.81 / 256;

  resultante = ((valorx * valorx) + (valory * valory) + (valorz * valorz)); // Cálculo de la resultante
  gravedad = sqrt(resultante); // Cálculo de la magnitud de la gravedad
  Serial.println(gravedad); // Imprime el valor de la gravedad en el monitor serial

  barra_led = map(gravedad, 0.07, 10, 1, 10); // Mapea el valor de gravedad a un rango de 1 a 10
  delay(250);

  if (barra_led == 1) {
    digitalWrite(2, HIGH); // Enciende el LED correspondiente al nivel 1
  } else if (barra_led == 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH); // Enciende los LEDs correspondientes al nivel 2
  } else if (barra_led == 3) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH); // Enciende los LEDs correspondientes al nivel 3
  } else if (barra_led == 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH); // Enciende los LEDs correspondientes al nivel 4
  } else if (barra_led == 5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH); // Enciende los LEDs correspondientes al nivel 5
  } else if (barra_led == 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(6, HIGH); // Enciende los LEDs correspondientes al nivel 6
    tilin.play(1); // Reproduce el archivo de audio 1
    delay(1000); // Espera 1 segundo
  } else if (barra_led == 7) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH); // Enciende los LEDs correspondientes al nivel 7
  } else if (barra_led == 8) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH); // Enciende los LEDs correspondientes al nivel 8
  } else if (barra_led == 9) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(A0, HIGH); // Enciende los LEDs correspondientes al nivel 9
  } else if (barra_led == 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH); // Enciende todos los LEDs correspondientes al nivel 10
  }
}
