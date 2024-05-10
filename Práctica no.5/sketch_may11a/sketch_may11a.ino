const int buzzer = 3;
float sol = 391.995;
float mib = 311.127;
float sib = 466.164;
float re = 293.665;
float solb = 364.994;
float Fa = 364.994; //sostenido
float fa = 349.328;
float mi = 329.628;
float Re = 311.127; //sostenido
float Sol = 415.105;  //sostenido
float DO = 277.183;//sostenido
float Do = 261.626;
float si = 493.883;
float la = 440.000;
float La = 466.164; //sostenido
int redonda = 2000;
int blanca = 1000;
int negra = 500;
int corchea = 225;
int semicorchea = 113;


void setup()
{
  pinMode(buzzer, OUTPUT); 
  tone(buzzer,sol,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,sol,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,sol,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,Do,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer); //final 1 
    tone(buzzer,mi,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,Do,corchea);
    delay(338);
    noTone(buzzer);
    tone(buzzer,sol,semicorchea);
    delay(225);
    noTone(buzzer);
    tone(buzzer,mi,blanca);
    delay(1000);
    noTone(buzzer);//final 2
  tone(buzzer,re,negra);
    delay(500);
    noTone(buzzer);  
  tone(buzzer,re,negra);
    delay(500);
    noTone(buzzer);  
  tone(buzzer,re,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,Do,corchea);
    delay(338);
    noTone(buzzer);  
  tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer);  //Final 3
    tone(buzzer,Re,negra);
    delay(500);
    noTone(buzzer); 
    tone(buzzer,Do,corchea);
    delay(338);
    noTone(buzzer);
    tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer);
    tone(buzzer,mi,blanca);
    delay(1000);
    noTone(buzzer);//Final 4 
  tone(buzzer,mi,negra);
    delay(500);
    noTone(buzzer);
    tone(buzzer,mi,corchea);
    delay(338);
    noTone(buzzer);
    tone(buzzer,mi,semicorchea);
    delay(113);
    noTone(buzzer);
    tone(buzzer,mi,negra);
    delay(500);
    noTone(buzzer);
    tone(buzzer,Re,corchea);
    delay(338);
    noTone(buzzer);
    tone(buzzer,re,semicorchea);
    delay(113);
    noTone(buzzer);//Final  5
  tone(buzzer,DO,semicorchea);
    delay(113);
    noTone(buzzer);
  tone(buzzer,Do,semicorchea);
    delay(133);
    noTone(buzzer);  
  tone(buzzer,DO,corchea);
    delay(338);
    noTone(buzzer);  
  delay(corchea);
  tone(buzzer,fa,corchea);
    delay(225);
    noTone(buzzer);
  tone(buzzer,La,corchea);
    delay(225);
    noTone(buzzer);
  tone(buzzer,la,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,Sol,semicorchea);
    delay(113);
    noTone(buzzer);//Final parte7
  tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer);
  tone(buzzer,Fa,semicorchea);
    delay(113);
    noTone(buzzer);
  tone(buzzer,sol,corchea);
    delay(225);
    noTone(buzzer);
    delay(corchea);
  tone(buzzer,Do,corchea);
    delay(225);
    noTone(buzzer);
  tone(buzzer,Re,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,Do,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,Re,semicorchea);
    delay(113);
    noTone(buzzer);//Final parte  8
  tone(buzzer,sol,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,mi,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer);
  tone(buzzer,si,blanca);
    delay(1000);
    noTone(buzzer);//Final 9 
  tone(buzzer,mi,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,mi,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,mi,semicorchea);
    delay(113);
    noTone(buzzer);   
  tone(buzzer,mi,negra);
    delay(500);
    noTone(buzzer); 
  tone(buzzer,Re,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,re,semicorchea);
    delay(113);
    noTone(buzzer); //final parte 10
  tone(buzzer,DO,semicorchea);
    delay(225);
    noTone(buzzer);
  tone(buzzer,Do,semicorchea);
    delay(225);
    noTone(buzzer);
  tone(buzzer,DO,corchea);
    delay(225);
    noTone(buzzer);
    delay(225);
  tone(buzzer,fa,corchea);
    delay(225);
    noTone(buzzer);
  tone(buzzer,La,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,la,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,Sol,semicorchea);
    delay(113);
    noTone(buzzer);//final parte 11
  tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer);
  tone(buzzer,Fa,semicorchea);
    delay(113);
    noTone(buzzer);
  tone(buzzer,sol,corchea);
    delay(225);
    noTone(buzzer);
    delay(225);
  tone(buzzer,Do,corchea);
    delay(225);
    noTone(buzzer);
  tone(buzzer,Re,negra);
    delay(225);
    noTone(buzzer);
  tone(buzzer,Do,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer);//final parte 12
  tone(buzzer,mi,negra);
    delay(500);
    noTone(buzzer);
  tone(buzzer,Do,corchea);
    delay(338);
    noTone(buzzer);
  tone(buzzer,sol,semicorchea);
    delay(113);
    noTone(buzzer);
  tone(buzzer,mi,blanca);
    delay(1000);
    noTone(buzzer);//final parte 13
  tone(buzzer,mi,redonda);
    delay(2000);
    noTone(buzzer);
           
}

void loop(){

}
  
