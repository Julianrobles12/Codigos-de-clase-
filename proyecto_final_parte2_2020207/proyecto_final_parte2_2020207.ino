//Librerías a utilizar
#include <DHT.h> 
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

//Variables
#define DHTYPE DHT11
#define DHTPIN 12
#define SENSOR_HUMEDAD A0  // Pin del sensor YL-69
#define BOMBA 2
#define ENFRIAMIENTO 3
#define CALOR 4
#define VENTILACION 6
#define PIN_NEO 5          // Pin donde está conectado el IN de la rueda NeoPixel
#define NUMPIXELS 7        // Número de LEDs en la rueda NeoPixel

//Constructores
DHT dht(DHTPIN, DHTYPE);
SoftwareSerial Bluetooth(10, 11);    // RX=10, TX=11
Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NEO, NEO_GRB + NEO_KHZ800);
Servo ServoRobles;

bool controlManual = false;  // Variable para controlar el estado de la bomba (manual o automático)
unsigned long previousMillis = 0;      // Para no bloquear el sensor
unsigned long servoMillis = 0;         // Para controlar el tiempo del servo
const long interval = 1000;            // Tiempo para mandar la temperatura a la app
const long servoInterval = 1500;       // Tiempo  para mover el servo (1.5 segundos)

bool servoEnMovimiento = false;        // Variable para controlar el movimiento del servo

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(38400);                // Inicializar Bluetooth
  pinMode(SENSOR_HUMEDAD, INPUT);
  pinMode(BOMBA, OUTPUT);
  digitalWrite(BOMBA, HIGH);            // Apagar la bomba al inicio
  pinMode(ENFRIAMIENTO, OUTPUT);
  digitalWrite(ENFRIAMIENTO, HIGH); 
  pinMode(CALOR, OUTPUT);
  digitalWrite(CALOR, HIGH); 
  pinMode(VENTILACION, OUTPUT);
  digitalWrite(VENTILACION, HIGH); 
  dht.begin();
  ServoRobles.attach(9);                 // Conectar el servomotor al pin 9

  pixels.begin();                        // Inicializar la rueda NeoPixel
  apagarNeoPixel();                      // Apagar los LEDs al inicio
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Actualizar la lectura del sensor DHT cada 'interval' milisegundos
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sensor_dht();                        // Solo se ejecuta cada 'interval'
  }

  manejarBluetooth();                    // Manejar todos los comandos de Bluetooth
  controlar_bomba();                     // Controlar la bomba basado en los sensores y modo
  controlar_servo();                     // Controlar el movimiento del servomotor
}

// Función para leer y manejar comandos de Bluetooth
void manejarBluetooth() {
  while (Bluetooth.available()) {
    char Mensaje = Bluetooth.read();
    Serial.print("Comando recibido: ");
    Serial.println(Mensaje);

    switch (Mensaje) {
      case '0':
        // Enciende la bomba manualmente
        controlManual = true;
        digitalWrite(BOMBA, LOW);
        break;

      case '1':
        // Apaga la bomba manualmente
        controlManual = true;
        digitalWrite(BOMBA, HIGH);
        break;

      case 'A':
        // Habilita el control automático
        controlManual = false;
        Serial.println("Control automático habilitado");
        break;

      case 'N':
        encenderNeoPixelAzul();
        break;

      case 'M':
        apagarNeoPixel();
        break;

      case 'Q':
        moverServo(180);  // Mover el servo a 180 grados
        break;

      case 'R':
        moverServo(0);    // Mover el servo a 0 grados
        break;

      case 'O':
        digitalWrite(VENTILACION, LOW);
        break;

      case 'P':
        digitalWrite(VENTILACION, HIGH);
        break;  

      default:
        Serial.println("Comando no reconocido");
        break;
    }
  }
}

void moverServo(int angulo) {
  if (!servoEnMovimiento) {          // Verificar si el servo ya está en movimiento
    servoEnMovimiento = true;        // Iniciar el movimiento del servo
    servoMillis = millis();          // Guardar el tiempo actual para controlar el movimiento
    ServoRobles.write(angulo);       // Mover el servo al ángulo especificado
    Serial.print("Servo movido a ");
    Serial.print(angulo);
    Serial.println(" grados");
  }
}

void controlar_servo() {
  // Solo realizar acciones si el servo está en movimiento
  if (servoEnMovimiento && millis() - servoMillis >= servoInterval) {
    servoEnMovimiento = false;   // Detener el movimiento tras el intervalo
    Serial.println("Movimiento del servo completado");
  }
}

void sensor_dht() {
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error en el sensor DHT");
    Bluetooth.println("Error en el sensor DHT");
    return;
  }
  Bluetooth.print("Temperatura:       ");
  Bluetooth.println(temperatura);

  // Controlar sistemas de enfriamiento y calor
  if (temperatura > 30) {
    digitalWrite(ENFRIAMIENTO, LOW);  // Encender enfriamiento
    digitalWrite(CALOR, HIGH);        // Apagar el sistema de calor
    Serial.println("Sistema de enfriamiento activado");
  } 
  else if (temperatura < 18) {
    digitalWrite(CALOR, LOW);         // Encender sistema de calor
    digitalWrite(ENFRIAMIENTO, HIGH); // Apagar enfriamiento
    Serial.println("Sistema de calor activado");
  } 
  else {
    // Si la temperatura está entre 18 y 30 grados, apagar ambos sistemas
    digitalWrite(ENFRIAMIENTO, HIGH); //sistema de enfriamiento se apagan
    digitalWrite(CALOR, HIGH);//sistema de calor se apaga
  }
}

void controlar_bomba() {
  int valorYL69 = analogRead(SENSOR_HUMEDAD);
  int porcentajeHumedadSuelo = map(valorYL69, 0, 1023, 100, 0);  // Mapeamos el valor a porcentaje

  if (!controlManual) {
    if (porcentajeHumedadSuelo < 20) {
      digitalWrite(BOMBA, LOW);  
    } else {
      digitalWrite(BOMBA, HIGH);
    }
  }
}

void encenderNeoPixelAzul() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255)); // Azul
  }
  pixels.show();  // Actualiza la rueda NeoPixel
}

void apagarNeoPixel() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Apagar
  }
  pixels.show();  // Actualiza la rueda NeoPixel
}
