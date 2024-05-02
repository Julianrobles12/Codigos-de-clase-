/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Auto-fantastico
   Dev: Josue Julian de Jesus Robles Larios 
   Fecha: 26 de abril
*/
int pines[] = {4, 5, 6, 7, 8, 9, 10, 11, 12}; 
int tiempo = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT); 
  for (int p = 0; p < 9; p++) {
    pinMode(pines[p], OUTPUT);}
}
 
void loop() {
  if(digitalRead(2)==HIGH){
    tiempo = 500;
    Serial.println("Secuencia - Velocidad 1");
    for (int p = 0; p<9 ; p++){
    digitalWrite(pines[p], HIGH);
    delay(tiempo);
    digitalWrite(pines[p], LOW);
    delay(tiempo);}
    for (int p = 9; p>=0 ; p--){
    digitalWrite(pines[p], HIGH);
    delay(tiempo);
    digitalWrite(pines[p], LOW);
    delay(tiempo);}
  }
  if(digitalRead(3)==HIGH){
    tiempo = 1000;
    Serial.println("Secuencia - Velocidad 2");
    for (int p = 0; p<9 ; p++){
    digitalWrite(pines[p], HIGH);
    delay(tiempo);
    digitalWrite(pines[p], LOW);
    delay(tiempo);}
    for (int p = 9; p>=0 ; p--){
    digitalWrite(pines[p], HIGH);
    delay(tiempo);
    digitalWrite(pines[p], LOW);
    delay(tiempo);}
  }
}  
      
