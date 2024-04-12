/*
	Fundacion Kinal
    Centro educativo tecnico laboral Kinal
    Quinto Perito
    Quinto electronica
    Código Técnico: EB5AM
    Curso: Taller de electronica digital y reparacion de computadoras I
    Proyecto: Escritura en un pin digital (Encender o apagar un pin digital)
    Dev: Josue Julian de Jesus Robles Larios
    Fecha: 12 de abri
*/

//Directivas de preprocesador
#define LedNaranja 4		//pin4 conectado a un led 
#define tiempo_espera 500	//tiempo entre estados

void setup()
{
  pinMode(LedNaranja, OUTPUT); 	//Pin4 como salida.
  digitalWrite(LedNaranja, LOW);  //LED conectado al Pin3 inicia apagado
}

void loop()
{
  digitalWrite(LedNaranja, HIGH); //Enciendo el led conectado al pin4
  delay(tiempo_espera); //espera 500 milisegundos.
  digitalWrite(LedNaranja, LOW); //Apago el led conectado al pin4
  delay(tiempo_espera); //espera de 500 milisegundos
}