/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Display, auto-fantastico 
   Dev: Josue Julian de Jesus Robles Larios 
   Fecha: 26 de abril
*/
int secuencia[] = {2, 3, 4, 5, 6}; 
int time = 0;
 
void setup() {
  Serial.begin(9600);          
  pinMode(A0, INPUT);     
  pinMode(A1, INPUT);    
  pinMode(A2, INPUT);    
  pinMode(A3, INPUT); 
  for (int s = 0; s < 9; s++) {
    pinMode(secuencia[s], OUTPUT);}
}
 
 
 
void loop() {
  if (digitalRead(A0)==HIGH && digitalRead(A2)==LOW){ 
   Serial.println("Practica No 4 - Julian Robles");
   delay(3000);
  }

  if(digitalRead(A1)==HIGH && digitalRead(A3)==LOW){ 
    time = 500;
    Serial.println("Secuencia");
    for (int s = 0; s<5 ; s++){
    digitalWrite(secuencia[s], HIGH);
    delay(time);
    digitalWrite(secuencia[s], LOW);
    delay(time);}
    for (int s = 5; s>=0 ; s--){
    digitalWrite(secuencia[s], HIGH);
    delay(time);
    digitalWrite(secuencia[s], LOW);
    delay(time);}
  }
    if (digitalRead(A2)==HIGH && digitalRead(A0)==LOW){ 
      time = 2000;
      digitalWrite(7, HIGH); //LETRA C
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      delay(time);
      digitalWrite(7, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(time);
      
      digitalWrite(8, HIGH); //LETRA U
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);  
      digitalWrite(12, HIGH);
      delay(time);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);  
      digitalWrite(12, LOW);
      delay(time);
      
      
      digitalWrite(7, HIGH); //LETRA A
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);  
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      delay(time);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);  
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      delay(time);
      digitalWrite(7, HIGH);// LETRA T
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      delay(time);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      delay(time);
      digitalWrite(7, HIGH); // LETRA R
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      delay(time);
      digitalWrite(7, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(time); 
      digitalWrite(7, HIGH);//LETRA O
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);  
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      delay(time);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);  
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(time);
      }
  if(digitalRead(A0)==HIGH && digitalRead(A2)==HIGH || digitalRead(A1)==HIGH && digitalRead(A3)==HIGH){
    Serial.println("Gracias por su atencion");
    delay(1500);}
   }
      
