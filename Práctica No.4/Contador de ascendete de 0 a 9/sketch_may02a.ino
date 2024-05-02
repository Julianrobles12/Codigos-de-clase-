/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Contador ascendente de 0 a 9
   Dev: Josue Julian de Jesús Robles Larios
   Fecha: 25 de abril 
*/

int contador = 0;
void setup() {
  Serial.begin(9600);     
  Serial.println("Contador ascendete de 0 a 9");     
  pinMode(2, INPUT);     
  pinMode(3, INPUT);   
  pinMode(4, INPUT);
}

void loop(){
  for(int c = 0; c<=9; c++){
    contador = 500;
    if(digitalRead(2)==HIGH){
       contador = 1000;}
    else if (digitalRead(3)==HIGH){
      contador = 2000; 
    } else if (digitalRead(4)==HIGH){
       contador =3000;} 
    if (digitalRead(2)==HIGH && digitalRead(3)==HIGH && digitalRead(4)==HIGH){
      contador = 500;}  
    Serial.println(c);
    delay(contador);
  }//cierre for 
} // cierre de loop 
  
