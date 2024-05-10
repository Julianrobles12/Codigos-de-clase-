float kilogramos = 20;
float resultado = 0;
float amperios = 0.8;
float resultado_A = 0;

int numero3 [5] = {8, 7, 6, 5, 2};
int numero5 [5] = {8, 3, 2, 6, 5};
int numero9 [5] = {8, 7, 6, 3, 2};

void setup(){
  Serial.begin(9600);
  Serial.print("20 Kilogramos es igual a: ");
  resultado = conversor_kg_lb(kilogramos);
  Serial.print(resultado);
  Serial.println(" Libras ");

  Serial.print("0.8 Amperios es igual a: ");
  resultado_A = conversor_A_mA(amperios);
  Serial.print(resultado_A);
  Serial.print(" uA");
}

void loop(){
 secuencia_de_nums();
}


float conversor_kg_lb (float kg){
  float resultado1;
  resultado1 = kilogramos * 2.204623;
  return resultado1;
}

float conversor_A_mA (float A){
  float resultado2;
  resultado2 = amperios * 1000000;
  return resultado2;
}

void pinesdesalida(){
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);   
}

int secuencia_de_nums(){
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);  

  for (int i =0; i<5; i++){
  digitalWrite(numero3[i], HIGH);}
  delay(500);
  for (int i =5; i>=0; i--){
  digitalWrite(numero3[i], LOW);}
  
  for (int i =0; i<5; i++){
  digitalWrite(numero5[i], HIGH);}
  delay(500);
  for (int i =5; i>=0; i--){
  digitalWrite(numero5[i], LOW);}
 
  digitalWrite(8, HIGH);    
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);  
  delay(500);
  digitalWrite(8, LOW);  
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);  

  for (int i =0; i<5; i++){
  digitalWrite(numero9[i], HIGH);}
  delay(500);
  for (int i =5; i>=0; i--){
  digitalWrite(numero9[i], LOW);}    
}
