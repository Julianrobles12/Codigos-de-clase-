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
#include <Wire.h>
#include <SparkFun_ADXL345.h>

ADXL345 acelerometro_ADXL345 = ADXL345();
SoftwareSerial DFPlayerSerial(11, 10);
DFRobotDFPlayerMini tilin;

int pines[] = {2, 3, 4, 5, 6, 7, 8, 9};
int x, y, z;
float resultante;
float gravedad;
unsigned int barra_led;
unsigned long previousMillis = 0;
const long interval = 10000;
unsigned long alarmMillis = 0;
const long alarmInterval = 2000; // Intervalo para asegurar que la alarma suene correctamente

void setup() {
  Serial.begin(9600);
  DFPlayerSerial.begin(9600);
  tilin.begin(DFPlayerSerial);
  tilin.volume(20);
  acelerometro_ADXL345.powerOn();
  acelerometro_ADXL345.setRangeSetting(2);

  for (int i = 0; i < 8; i++)
    pinMode(pines[i], OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop() {
  acelerometro_ADXL345.readAccel(&x, &y, &z);

  float valorx = x * 9.81 / 256;
  float valory = y * 9.81 / 256;
  float valorz = z * 9.81 / 256;

  resultante = ((valorx * valorx) + (valory * valory) + (valorz * valorz));
  gravedad = sqrt(resultante);
  Serial.println(gravedad);

  barra_led = map(gravedad, 11.20, 25, 1, 10);

  if (barra_led > 0) {
    digitalWrite(pines[0], HIGH); // Según la escala, un led debería de mantenerse encendido
  }

  for (int i = 1; i < 8; i++) {
    if (barra_led >= i + 1) {
      digitalWrite(pines[i], HIGH);
    } else {
      digitalWrite(pines[i], LOW);
    }
  }

  if (barra_led >= 6) { // Si es mayor a 6 suena la alarma
    unsigned long currentMillis = millis();  // Obtengo el tiempo de cuando comenzó a ejecutarse
    if (currentMillis - alarmMillis >= alarmInterval) { // Compruebo el tiempo de activación de alarma para comparar con el intervalo
      alarmMillis = currentMillis; // actualiza el tiempo de la última activación
      tilin.play(1);
    }
  }

  unsigned long currentMillis = millis(); // obtengo el tiempo actualal
  if (currentMillis - previousMillis >= interval) { // Se comprueba el tiempo para ver si se resetea o no
    previousMillis = currentMillis; // se actualiza el tiempo
    resetSystem(); // Llamo a la función para apagar todo
  }

  delay(2500); // Aumenta el tiempo de espera para que los LEDs permanezcan encendidos por más tiempo, esto tambien afecta a las lecturas
}

void resetSystem() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pines[i], LOW);
  }
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
}


