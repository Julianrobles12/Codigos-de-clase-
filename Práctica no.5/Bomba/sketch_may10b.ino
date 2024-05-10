int pines[] = {2,3,4,5,6,7,8};
int no9 [] = {8,7,6,3,2};
int no8 [] = {8,7,6,5,4,3,2};
int no7 [] = {8,7,6};
int no6 [] = {8,6,5,4,3,2};
int no5 [] = {8,6,5,3,2};
int no4 [] = {7,6,3,2};
int no3 [] = {8,7,6,5,2};
int no2 [] = {8,7,5,4,2};
int no1 [] = {7,6}; 
int no0 [] = {8,7,6,5,4,3};              
int buzzer = 9;

void setup (){
salidas();
pinMode(10,OUTPUT); 
digitalWrite(10,HIGH); 
pinMode(buzzer,OUTPUT);
conteo();
}


void loop(){
}

void conteo(){
  for (int i =0; i<5; i++){
  digitalWrite(no9[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no9[i], LOW);}

  for (int i =0; i<7; i++){
  digitalWrite(no8[i], HIGH);}
  delay(1000);
  for (int i =7; i>=0; i--){
  digitalWrite(no8[i], LOW);} 

  for (int i =0; i<3; i++){
  digitalWrite(no7[i], HIGH);}
  delay(1000);
  for (int i =3; i>=0; i--){
  digitalWrite(no7[i], LOW);}
  
  for (int i =0; i<6; i++){
  digitalWrite(no6[i], HIGH);}
  delay(1000);
  for (int i =6; i>=0; i--){
  digitalWrite(no6[i], LOW);}
  
  for (int i =0; i<5; i++){
  digitalWrite(no5[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no5[i], LOW);}
  
  for (int i =0; i<4; i++){
  digitalWrite(no4[i], HIGH);}
  delay(1000);
  for (int i =4; i>=0; i--){
  digitalWrite(no4[i], LOW);}

  for (int i =0; i<5; i++){
  digitalWrite(no3[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no3[i], LOW);}
  
  for (int i =0; i<5; i++){
  digitalWrite(no2[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no2[i], LOW);}

  for (int i =0; i<2; i++){
  digitalWrite(no1[i], HIGH);}
  delay(1000);
  for (int i =2; i>=0; i--){
  digitalWrite(no1[i], LOW);}

  for (int i =0; i<6; i++){
  digitalWrite(no0[i], HIGH);}
  delay(1000);
  for (int i =6; i>=0; i--){
  digitalWrite(no0[i], LOW);}
  ruido(); 
    
}
void ruido() {
  digitalWrite(10,LOW);
  delay(25);
  tone(buzzer,250);
  delay(500);
  noTone(buzzer);
  }

void salidas(){
  for(int p=0; p<7; p++){
  pinMode(pines[p],OUTPUT);}
}
  
