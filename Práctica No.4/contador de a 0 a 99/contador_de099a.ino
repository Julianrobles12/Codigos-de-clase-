/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Contador 0 - 99 
   Dev: Josue Julian de Jesus Robles Larios 
   Fecha: 26 de abril
*/
int tiempo = 200;
int contador = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.print("PULSADOR IZQUIERDO RESTA              ");
  Serial.println("PULSADOR DERECHO SUMA");
  Serial.println(contador);
    
}

void loop()
{
  if (digitalRead(3)==HIGH){
    delay(tiempo);
     contador++;
    if (contador >=100){
    contador = 0;
    }
    Serial.println(contador);
    
  } else if (digitalRead(2)==HIGH){
    delay(tiempo);
    contador--;
    if(contador <0){
    contador = 99;
    }
    Serial.println(contador);
    }

}
