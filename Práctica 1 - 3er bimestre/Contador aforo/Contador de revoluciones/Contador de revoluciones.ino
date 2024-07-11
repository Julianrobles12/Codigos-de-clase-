#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define direccion_lcd 0x27
#define filas 2
#define columnas 16

#define canal0_pot A0
#define sensor_IR 2 
#define sensor_hall 3
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12

bool state_IF;
unsigned int valor_adc_pot;
unsigned int speed_motor;
volatile int contador = 0;
unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempo_pasado = 0;
int resultado = 0;

LiquidCrystal_I2C LCDrobles(direccion_lcd, columnas, filas);

int paso[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup() {
  Serial.begin(9600);
  pinMode(canal0_pot, INPUT);
  pinMode(sensor_IR, INPUT);
  pinMode(sensor_hall, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  LCDrobles.init();
  LCDrobles.backlight();
  LCDrobles.print("Contador de rev.");
  LCDrobles.setCursor(0, 1);
  LCDrobles.print("No de rev");

  attachInterrupt(digitalPinToInterrupt(sensor_hall), Interrupcion, RISING); 
  attachInterrupt(digitalPinToInterrupt(sensor_hall), Interrupcion_reset, FALLING); 
}

void loop() {
  sensor();
}

void moverMotor() {
  valor_adc_pot = analogRead(canal0_pot);
  speed_motor = map(valor_adc_pot, 0, 1023, 1, 3);

  for (int i = 0; i < 8; i++) {
    digitalWrite(IN1, paso[i][0]);
    digitalWrite(IN2, paso[i][1]);
    digitalWrite(IN3, paso[i][2]);
    digitalWrite(IN4, paso[i][3]);
    delay(speed_motor);
  }
  LCDrobles.setCursor(13, 1);
  LCDrobles.print(resultado);
}

void sensor() {
  state_IF = digitalRead(sensor_IR);
  if (state_IF == LOW) {
    moverMotor();
  }
}


/*void Interrupcion() {
  tiempo2 = millis();
  unsigned long tiempo_pasado = tiempo2 - tiempo1;
  tiempo1 = tiempo2;
  
  resultado = (contador * 60000) / tiempo_pasado;
}

void Interrupcion_reset(){
  contador = 0;
  resultado = 0;
}
*/
