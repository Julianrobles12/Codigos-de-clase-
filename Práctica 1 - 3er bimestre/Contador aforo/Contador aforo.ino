/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Contador Aforo 
   Dev: Josue Julian de Jesus Robles Larios 
   Fecha: 
*/

#include <Adafruit_NeoPixel.h>

#define trig 10 
#define echo 9
#define neo 11
#define cantidad_led 1


Adafruit_NeoPixel pixels(cantidad_led, neo, NEO_GRB + NEO_KHZ800);

int pines[] = {8, 7, 6, 5, 4, 3, 2};
long sensor;
long distancia;
int contador_personas = 0;

void setup() {
    Serial.begin(9600);
    pixels.begin();
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trig, LOW);
    for (int s = 0; s < 9; s++) {
        pinMode(pines[s], OUTPUT);
    }
}

void loop() {
    sensor_ultra();
    conteo_de_personas();
}

long sensor_ultra() {
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    sensor = pulseIn(echo, HIGH);
    distancia = sensor / 59;
}

float conteo_de_personas() {
    if (distancia > 5 && distancia < 11) {
        contador_personas++;
        delay(500);

        if (contador_personas == 1) {
            pixels.setPixelColor(0, pixels.Color(0, 255, 0));
            pixels.show();
            digitalWrite(7, HIGH);  
            digitalWrite(6, HIGH);

        } else if (contador_personas == 2) { 
            digitalWrite(8, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(2, HIGH);

        } else if (contador_personas == 3) {
            digitalWrite(4, LOW);
            digitalWrite(8, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(2, HIGH);

        } else if (contador_personas == 4) {
            digitalWrite(8, LOW);
            digitalWrite(5, LOW);
            digitalWrite(7, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(2, HIGH);

        } else if (contador_personas == 5) {
            digitalWrite(7, LOW);
            digitalWrite(8, HIGH);
            digitalWrite(5, HIGH);

        } else if (contador_personas == 6) {
            digitalWrite(8, LOW);
            digitalWrite(2, HIGH);
            digitalWrite(4, HIGH);

        } else if (contador_personas == 7) {
            digitalWrite(5, LOW);
            digitalWrite(4, LOW);
            digitalWrite(3, LOW);
            digitalWrite(2, LOW);
            digitalWrite(8, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(6, HIGH);

        } else if (contador_personas == 8) {
            digitalWrite(5, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(2, HIGH);

        } else if (contador_personas == 9) {
            digitalWrite(5, LOW);
            digitalWrite(4, LOW);
            delay(1500);
            digitalWrite(8, LOW);
            digitalWrite(7, LOW);
            digitalWrite(6, LOW);
            digitalWrite(3, LOW);
            digitalWrite(2, LOW);
            digitalWrite(2, HIGH);
            pixels.setPixelColor(0, pixels.Color(255, 0, 0));
            pixels.show();
        }
    }
}
