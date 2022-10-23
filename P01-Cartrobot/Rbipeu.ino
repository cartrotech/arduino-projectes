#include <Servo.h>

// creem objectes Servo per cada servo
Servo CamaE;
Servo CamaD;
Servo PeuE;
Servo PeuD;

// variables per guardar la posicio centrada dels servos
int CEcentre = 90;
int CDcentre = 90;
int PEcentre = 90;
int PDcentre = 90;

// variables per guardar l'angle dels servos
int iAngle = 30; //inclinacio
int gAngle = 35; //gir
int bAngle = 35; //balanceig

int velocitat = 50; //factor de velocitat del moviment

void setup() 
{
  // assigna el pin x a l'objecte Servo
  CamaE.attach(7);
  CamaD.attach(10);
  PeuE.attach(8);
  PeuD.attach(9);

  CentraServos();  //centra els servos
  delay(500);

}

void loop() 
{
/*InclinaDretaAmunt(iAngle, velocitat);
  delay(1000);
  InclinaDretaAvall(iAngle, velocitat);
  delay(1000);
  InclinaEsquerraAmunt(iAngle, velocitat);
  delay(1000);
  InclinaEsquerraAvall(iAngle, velocitat);
  delay(1000);
*/
  Endavant(1,velocitat);
  delay(500);
}

void CentraServos()
{
  CamaE.write(CEcentre);
  CamaD.write(CDcentre);
  PeuE.write(PEcentre);
  PeuD.write(PDcentre);
  delay(100);
}
