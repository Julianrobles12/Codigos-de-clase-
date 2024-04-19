/* 
  Fundación Kinal
    Centro educativo Técncico Laboral Kinal
    Quinto Perito
    Quinto Electrónica 
    Codigo Técnico: EB5AM
    Curso: Taller de Electrónica Digital y reparación de computadoras
    Proyecto: Catálogo de productos
    Dev: Josue Julian de Jesús Robles Larios
    Fecha: 18 de abril de 2024
*/ 
byte contador = 0;

struct DULCE_1
{
  char nombre_dulce1 [50]; 
  byte stock_1;
};

struct DULCE_2
{
  char nombre_dulce2 [50];
  byte stock_2;
};

struct DULCE_3
{
  char nombre_dulce3 [50];
  byte stock_3;
};

struct DULCE_4
{
  char nombre_dulce4 [50];
  byte stock_4;
};


DULCE_1 chocolate_1 = {"CHOCOLATE GRANADA", 25};
DULCE_2 hersheys = {"Chocolate Kiss", 25};
DULCE_3 menta = {"MENTOLIN", 25};
DULCE_4 diana = {"CEREZA", 25};

  
  
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.println("Catalogo de productos");
  Serial.print("Izquierda - Retroceder     ");
  Serial.println("Derecha - Avanzar");
}

void loop()
{
  if(digitalRead(2)==HIGH) 
  {
   delay(350);
   contador = contador+1; 
   
    if(contador == 1){
      Serial.print("El nombre del dulce 1 es:  ");
  	  Serial.println(chocolate_1.nombre_dulce1);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(chocolate_1.stock_1);}
    
    if(contador == 2) {
      Serial.print("El nombre del dulce 2 es:  ");
      Serial.println(hersheys.nombre_dulce2);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(hersheys.stock_2);}
       
    if(contador == 3){
      Serial.print("El nombre del dulce 3 es:  ");
      Serial.println(menta.nombre_dulce3);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(menta.stock_3);}
  	
  
    if(contador == 4){
      Serial.print("El nombre del dulce 4 es:  ");
  	  Serial.println(diana.nombre_dulce4);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(diana.stock_4);}
    
    if(contador == 5) { 
      contador = contador-5;
      Serial.println("Catalogo de productos");}
  }  

  else if(digitalRead(3)==HIGH) 
  {
	delay(350);
    contador = contador-1;
	
    if(contador ==0){
      Serial.println("Catalogo de dulce");}
    
    if(contador == 1){
      Serial.print("El nombre del dulce 1 es:  ");
  	  Serial.println(chocolate_1.nombre_dulce1);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(chocolate_1.stock_1);}
    
    if(contador == 2) {
      Serial.print("El nombre del dulce 2 es:  ");
      Serial.println(hersheys.nombre_dulce2);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(hersheys.stock_2);}
       
    if(contador == 3){
      Serial.print("El nombre del dulce 3 es:  ");
      Serial.println(menta.nombre_dulce3);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(menta.stock_3);}
  	
  
    if(contador == 4){
      Serial.print("El nombre del dulce 4 es:  ");
  	  Serial.println(diana.nombre_dulce4);
      Serial.print("La cantidad disponible es:  ");
      Serial.println(diana.stock_4);}
  }
}          