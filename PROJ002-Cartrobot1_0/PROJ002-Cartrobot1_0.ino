/*
   CARTROTECH  (https://cartrotech.wordpress.com)

   Projecte nº: P002
   Data: 22/08/21
   Descripcio: Cartrobot v1.0
   Nota:

*/

#include <Servo.h>
#include <SoftwareSerial.h>

#define ServoActiu 12
SoftwareSerial BT1(4, 2); // RX, TX Recorda encreuar-los

// creem objectes Servo per cada servo
Servo CamaE;
Servo CamaD;
Servo PeuE;
Servo PeuD;

// variables per guardar la posicio centrada dels servos
int CEcentre = 85;
int CDcentre = 85;
int PEcentre = 85;
int PDcentre = 85;

// variables per guardar l'angle dels servos
int iAngle = 30; //inclinacio
int gAngle = 25; //gir
int bAngle = 35; //balanceig

int velocitat = 50; //factor de velocitat del moviment
  
void setup() 
{
  Serial.begin(9600);
  // assigna pins
  pinMode(ServoActiu, OUTPUT);

  ActivaServos();  
  CentraServos();  //centra els servos
  DesactivaServos();  
  delay(1000);
  BT1.begin(9600);  // Velocitat per defecte del HC-05

}

void loop() 
{
  OrdreBluetooth();
  delay(200);  
}

void OrdreBluetooth()
{
  if (BT1.available())
  {
    char c;
    String s;
    c = BT1.read();
    Serial.println(c);
    s = c;
    int m = s.toInt();
    Serial.println(m);

    switch (m)
    {
      case 5:
        Endavant(1,velocitat);
        break;

      case 6:
        Recula(1, velocitat);
        break;

      case 7:
        GiraEsquerra(1, velocitat);
        break;

      case 8:
        GiraDreta(1, velocitat);
        break;

      case 0:
        
        break;
    }
  }
}

void CentraServos()
{
  CamaE.write(CEcentre);
  CamaD.write(CDcentre);
  PeuE.write(PEcentre);
  PeuD.write(PDcentre);
  delay(100);
}

void ActivaServos()
{
  // assigna el pin x a l'objecte Servo
  CamaE.attach(10);
  CamaD.attach(7);
  PeuE.attach(8);
  PeuD.attach(9);
}

void DesactivaServos()
{
  CamaE.detach();
  CamaD.detach();
  PeuE.detach();
  PeuD.detach();
}
