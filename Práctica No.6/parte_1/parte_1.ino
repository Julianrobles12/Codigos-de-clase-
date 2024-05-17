/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso de la pantalla LCD sin interfaz I2C
   Dev: Josue Julian de Jesús Robles Larios
   Fecha: 16 de mayo de 2024   
*/
#include <LiquidCrystal.h>
String nombre [] = {"Julian", "       Robles"};
String carnet [] = {"2020207","       EB5AM"};
#define RS  6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5


LiquidCrystal JulianLCD(RS, Enable, D4, D5, D6, D7); 

void setup()
{
  JulianLCD.begin(16,2);
  for (int i=0; i<2; i++){
  JulianLCD.setCursor(0,0);
  JulianLCD.print(nombre[i]);
  delay(500);}
  for (int i=0; i<2; i++){
  JulianLCD.setCursor(0,1);
  JulianLCD.print(carnet[i]);
  delay(500);}  
  JulianLCD.setCursor(0,0);
  JulianLCD.print("Julian  Robles");
  JulianLCD.setCursor(0,1);
  JulianLCD.print("2020207 EB5AM");
  delay(2000);
  JulianLCD.clear();
}

void loop()
{

}
