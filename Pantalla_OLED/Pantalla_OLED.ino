/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Pantalla OLED
   Dev: Josue Julian de Jesús Robles Larios 
   Fecha: 18 de julio.
    
*/


//Librerias
#include <Wire.h>             //libreria que me permite usar el protocolo i2c
#include <Adafruit_GFX.h>     //libreria que me permite el uso de graficos en 
#include <Adafruit_SSD1306.h> //libreria que me permite el uso del controlador 

//Directivas del preprocesador
#define widht_oled    128       //128 pixeles de ancho 
#define height_oled   64        //64 pixeles de alto
#define pot_pin       A0        //pin A0 donde conectare el potenciometro

//Constructores
Adafruit_SSD1306 screen_oled(widht_oled,height_oled,&Wire, -1);

//Variables
unsigned int adc_valor;

//Configuraciones
void setup() 
{

 Serial.begin(9600);  //Inicio la comunicación serial
 delay(100);          //pausa de 100 milisegundos
 Serial.println("Uso de la pantalla oled - practica 3 parte 2");
 pinMode(A0, INPUT);

 //Inicio la comunicacion con la pantalla OLEC

 if(!screen_oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  Serial.println("No puedo comunicarme con la pantalla oled");
  Serial.println("Favor de revisar conexiones o alimentacion");
  while(1);   //Ciclo infinito
 }

}

//Ciclo infinito
void loop() 
{
  
  screen_oled.setTextSize(1);
  screen_oled.setTextColor(SSD1306_WHITE);
  screen_oled.setCursor(0, 4);
  screen_oled.println("Valor del ADC");
  screen_oled.display();
  adc_valor = analogRead(A0);
  Serial.print("El valor del ADC es de: ");
  Serial.println(adc_valor);
  screen_oled.setTextSize(3);
  screen_oled.setTextColor(SSD1306_WHITE);
  screen_oled.setCursor(30,25);
  screen_oled.println(adc_valor);
  screen_oled.display();
  delay(20);
  screen_oled.clearDisplay();
}