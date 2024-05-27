/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto Final
   Dev: Josue Julian de Jesús Robles Larios
   Fecha: 24 de mayo
*/


#include <Wire.h>               
#include <LiquidCrystal_I2C.h>  
#include <Servo.h>              
#include <Keypad.h>             


//Directivas de preprocesador para la LCD
#define direccion_lcd 0x21     
#define filas 2                
#define columnas 16            

//Directicas de proceprocesador para el teclado matricial
#define filas_teclado 2      
#define columnas_teclado 3     
#define f1_teclado 13          
#define f2_teclado 12          
#define c1_teclado 11           
#define c2_teclado 10           
#define c3_teclado 9         

//Directicas de proceprocesador para el servomotor y leds 
int secuencia [] = {A0, A1, A3, A2};
#define pin_servo 3                     
#define led_azul  A0
#define led_rojo  A1           
#define led_amar  A3           
#define led_verd  A2            
#define ON(pin)     	digitalWrite(pin, HIGH);
#define OFF(pin)    	digitalWrite(pin, LOW);

//Segmentos del display
#define A 8
#define B 7
#define C 6
#define D 5
#define E 4
#define F 2
int display [] = {8,7,6,5,4,2};


//Variables para el uso del teclado
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3'},
  {'4','5','6'},
};

byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado};



//Constructor
LiquidCrystal_I2C lcdRobles(direccion_lcd, columnas, filas);   
Servo ServoRobles;                                             
Keypad tecladoCerradura = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);   


void setup()
{
  Serial.begin(9600);               
  config_outputs();               
  config_HMI();                   
  OFF(led_azul);
  OFF(led_amar);                  
  OFF(led_rojo);                  
  OFF(led_verd);                 
  ServoRobles.write(0);
}

void loop()
{
  //Obtengo el valor de la tecla presionada
  char key = tecladoCerradura.getKey(); 
  
  if (key =='1'){
    Serial.println("Iniciando conteo");
    for(int i=0; i<100; i++){
      Serial.println(i);
      delay(50);}
      Serial.println("conteo finalizado");	
       
  } else if (key =='2'){
    Serial.println("Iniciando conteo");
  	for(int i=99; i>=0; i--){
      Serial.println(i);
      delay(50);}
      Serial.println("conteo finalizado");	
    
  } else if (key =='3'){
    int t=100;
	Serial.println("Autofantastico");
    for(int p=0; p<3;p++){
      for(int s=0; s<4;s++){
        digitalWrite(secuencia[s],HIGH);
        delay(t);
        digitalWrite(secuencia[s],LOW);
        delay(t);}
      delay(300);
      for(int s=3; s>=0;s--){
        digitalWrite(secuencia[s],HIGH);
        delay(t);
        digitalWrite(secuencia[s],LOW);
        delay(t);}
      for(int s=0; s<4;s++){
        digitalWrite(secuencia[s],HIGH);}
      	delay(500);
      for(int s=3; s>=0;s--){
        digitalWrite(secuencia[s],LOW);}
      	delay(500);}// cierre de for 3 veces
    
  } else if (key == '4'){
    int t=250;
    for (int d=0; d<6; d++){
      digitalWrite(display[d], HIGH);
      delay(t); 
      digitalWrite(display[d], LOW);}
    for (int s=5; s>=0; s--){
      digitalWrite(display[s], HIGH);
      delay(t);
      digitalWrite(display[s], LOW);}
      delay(300);
    for (int d=0; d<6; d++){
      digitalWrite(display[d], HIGH);
      delay(t);}
    for (int d=5; d>=0; d--){
      digitalWrite(display[d], LOW);
      delay(t);}
    for (int x=0; x<3; x++){
      for (int d=0; d<6; d++){
      	digitalWrite(display[d], HIGH);}
      	delay(500);
      for (int d=0; d<6; d++){
         digitalWrite(display[d], LOW);}
     	 delay(500);}// cierre de for 3 veces
 
  } else if (key=='5'){
  		Serial.println("Inicio de servomotor");
  		ServoRobles.write(0);
    	delay(1500);
   		ServoRobles.write(180);
    	delay(1500);
    	ServoRobles.write(0);}
     
}// Cierre de loop  

void config_outputs(void)
{
  pinMode(pin_servo, OUTPUT);
  pinMode(led_amar, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verd, OUTPUT);
}

void config_HMI(void)
{
  ServoRobles.attach(pin_servo);
  lcdRobles.init();
  lcdRobles.backlight();
  lcdRobles.setCursor(5,0);
  lcdRobles.print("Julian");
  lcdRobles.setCursor(0,1);
  lcdRobles.print(" Proyecto Final");
}
