#include <LedControl.h>
 
//Directivas de preprocesador
#define din_matrix  3  //Pin 3 del ardu al din 
#define cs_matrix   2  //Pin 2 del ardu al cs
#define clk_matrix  4  //Pin 4 del ardu al clk
#define canal0_pot A0 // Pin A0 del arduino
 
// Constructores
LedControl matrixJulian = LedControl(din_matrix, clk_matrix, cs_matrix, 1);
 
 
// Variables
unsigned int valor_adc_pot;
unsigned int tiempo_ajustable;

byte pacman_open[8]= { 

  B00000000,
  B00011100,
  B00100010,
  B01000100,
  B01001000,
  B01000100,
  B00100010,
  B00011100,

};

byte pacman_close[8] = {
  B00000000,
  B00011100,
  B00100010,
  B01000001,
  B01000111,
  B01000001,
  B00100010,
  B00011100,
};
 

 
 
void setup() {

  Serial.begin(9600); 
  matrixJulian.shutdown(0, false); 
  matrixJulian.setIntensity(0,15); 
  matrixJulian.clearDisplay(0); 
  Serial.println("Uso de matriz");

}
 
void loop() {
  
  valor_adc_pot = analogRead(canal0_pot);
  tiempo_ajustable = map(valor_adc_pot, 0, 1023, 100, 1700);

  boca_abierta();
  delay(tiempo_ajustable);
  boca_cerrada();
  delay(tiempo_ajustable);
  
}

void boca_abierta () {

  for(int i=0; i<8; i++) {

      matrixJulian.setRow(0,i, pacman_open[i]);

   }

}

void boca_cerrada (){

    for(int i=0; i<8; i++) {

      matrixJulian.setRow(0,i, pacman_close[i]);

    }

}
 