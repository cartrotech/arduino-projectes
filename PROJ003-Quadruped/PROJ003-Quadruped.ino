/*
   CARTROTECH  (https://cartrotech.wordpress.com)

   Projecte nº: P003
   Data: 22/10/2022
   Descripcio: Robot quadruped
   Nota:

*/

//SCL -> A5
//SDA -> A4

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servoController = Adafruit_PWMServoDriver(0x40);

const int frequency = 50;       // Freqüència PWM de 50Hz o T=20ms
const int ServoMinTicks = 110; // amplada de pols en ticks per a posició 0°
const int ServoMaxTicks = 510; // amplada de pols en ticks per a posició 180°

// Posicio inicial
int posIniServo1 = 275;
int posIniServo2 = 225;
int posIniServo3 = 200;
int posIniServo4 = 275;
int posIniServo5 = 450;
int posIniServo6 = 275;
int posIniServo7 = 200;
int posIniServo8 = 275;
int posIniServo9 = 450;

// Sensor IRC
#define powerPin 8
#define trigPin 11
#define echoPin 12
long Duracio = 0;
int Distancia = 0;
int angle = 90;
int sum = 0;

void setup()
{
  pinMode(powerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servoController.begin();
  servoController.setPWMFreq(frequency );
  posIni();
}

void loop()
{
  posIni();
  buscaObstacle();
  endavant(2);
  
}

void posIni()
{
  servoController.setPWM(1, 0, posIniServo1);
  servoController.setPWM(2, 0, posIniServo2);
  servoController.setPWM(3, 0, posIniServo3);
  servoController.setPWM(4, 0, posIniServo4);
  servoController.setPWM(5, 0, posIniServo5);
  servoController.setPWM(6, 0, posIniServo6);
  servoController.setPWM(7, 0, posIniServo7);
  servoController.setPWM(8, 0, posIniServo8);
  servoController.setPWM(9, 0, posIniServo9);

}

void assegut()
{
  servoController.setPWM(1, 0, posIniServo1);
  servoController.setPWM(2, 0, posIniServo2);
  servoController.setPWM(3, 0, posIniServo3);
  servoController.setPWM(4, 0, posIniServo4);
  servoController.setPWM(5, 0, posIniServo5);
  servoController.setPWM(6, 0, posIniServo6);
  servoController.setPWM(7, 0, 300);
  servoController.setPWM(8, 0, posIniServo8);
  servoController.setPWM(9, 0, 300);
}

void buscaObstacle()
{
  mesuraDistancia();
  Serial.print("Distancia: ");
  Serial.println(Distancia);
  delay(500);

  if (Distancia < 20)
  {    
    int dreta = 0;
    int esquerra = 0;
    int sumdreta = 0;
    int sumesquerra = 0;

    int i = ServoMinTicks + 10;
    delay(10);
    while (i <= 250)
    {
      servoController.setPWM(1, 0, i);
      i = i + 20;
      mesuraDistancia();
      
      if (Distancia < 25)
      {
        dreta = 1;
        sumdreta++;
      }
      else
      {
        dreta = 0;
      }
      delay(50);
    }
    
    i = ServoMaxTicks - 10;
    delay(10);
    while (i >= 310)
    {
      servoController.setPWM(1, 0, i);
      i = i - 20;
      mesuraDistancia();
      if (Distancia < 25)
      {
        esquerra = 1;
        sumesquerra++;
      }
      else
      {
        esquerra = 0;
      }
      delay(50);
    }
    servoController.setPWM(1, 0, posIniServo1);
    delay(10);
    Serial.println(sumdreta);
    Serial.println(sumesquerra);

    if (sumdreta > sumesquerra)
    {
      girE(3);
    }
    else
    {
      girD(3);
    }
    
    if (sumdreta >= 20)
    {
      enrere(3);
      girE(3);
    }
    else if (sumesquerra >= 20)
    {
      enrere(3);
      girD(3);
    }
  }

}

void mesuraDistancia()
{
  digitalWrite(powerPin, HIGH); //Encenem sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duracio = pulseIn(echoPin, HIGH);
  Distancia = Duracio * 0.034 / 2;
}

void endavant (unsigned int passos)
{
  int angle = 60;
  while (passos-- > 0)
  {
    servoController.setPWM(3, 0, posIniServo3 + angle);
    servoController.setPWM(7, 0, posIniServo7 + angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2 + angle);
    servoController.setPWM(8, 0, posIniServo8 - angle);
    servoController.setPWM(4, 0, posIniServo4);
    servoController.setPWM(6, 0, posIniServo6);
    delay(100);
    servoController.setPWM(3, 0, posIniServo3);
    servoController.setPWM(7, 0, posIniServo7);
    delay(100);
    
    servoController.setPWM(5, 0, posIniServo5 - angle);
    servoController.setPWM(9, 0, posIniServo9 - angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2);
    servoController.setPWM(8, 0, posIniServo8);
    servoController.setPWM(4, 0, posIniServo4 - angle);
    servoController.setPWM(6, 0, posIniServo6 + angle);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5);
    servoController.setPWM(9, 0, posIniServo9);
    delay(100);
  }
}

void enrere (unsigned int passos)
{
  int angle = 60;
  while (passos-- > 0)
  {
    servoController.setPWM(3, 0, posIniServo3 + angle);
    servoController.setPWM(7, 0, posIniServo7 + angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2);
    servoController.setPWM(8, 0, posIniServo8);
    servoController.setPWM(4, 0, posIniServo4 - angle);
    servoController.setPWM(6, 0, posIniServo6 + angle);
    delay(100);
    servoController.setPWM(3, 0, posIniServo3);
    servoController.setPWM(7, 0, posIniServo7);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5 - angle);
    servoController.setPWM(9, 0, posIniServo9 - angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2 + angle);
    servoController.setPWM(8, 0, posIniServo8 - angle);
    servoController.setPWM(4, 0, posIniServo4);
    servoController.setPWM(6, 0, posIniServo6);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5);
    servoController.setPWM(9, 0, posIniServo9);
    delay(100);
  }
}

void girD (unsigned int passos)
{
  giraCapDreta();
  int angle = 60;
  while (passos-- > 0)
  {
    servoController.setPWM(5, 0, posIniServo5 - angle);
    servoController.setPWM(9, 0, posIniServo9 - angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2 + angle);
    servoController.setPWM(8, 0, posIniServo8 - angle);
    servoController.setPWM(4, 0, posIniServo4 - angle);
    servoController.setPWM(6, 0, posIniServo6 + angle);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5);
    servoController.setPWM(9, 0, posIniServo9);
    delay(100);
    servoController.setPWM(3, 0, posIniServo3 + angle);
    servoController.setPWM(7, 0, posIniServo7 + angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2);
    servoController.setPWM(8, 0, posIniServo8);
    servoController.setPWM(4, 0, posIniServo4);
    servoController.setPWM(6, 0, posIniServo6);
    delay(100);
    servoController.setPWM(3, 0, posIniServo3);
    servoController.setPWM(7, 0, posIniServo7);
    delay(100);
  }
  centraCap();
}

void girE (unsigned int passos)
{
  giraCapEsquerra();
  int angle = 60;
  while (passos-- > 0)
  {
    servoController.setPWM(3, 0, posIniServo3 + angle);
    servoController.setPWM(7, 0, posIniServo7 + angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2 + angle);
    servoController.setPWM(8, 0, posIniServo8 - angle);
    servoController.setPWM(4, 0, posIniServo4 - angle);
    servoController.setPWM(6, 0, posIniServo6 + angle);
    delay(100);
    servoController.setPWM(3, 0, posIniServo3);
    servoController.setPWM(7, 0, posIniServo7);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5 - angle);
    servoController.setPWM(9, 0, posIniServo9 - angle);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2);
    servoController.setPWM(8, 0, posIniServo8);
    servoController.setPWM(4, 0, posIniServo4);
    servoController.setPWM(6, 0, posIniServo6);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5);
    servoController.setPWM(9, 0, posIniServo9);
    delay(100);
  }
  centraCap();
}

void giraCapEsquerra()
{
  int i = posIniServo1;
  while (i < 490)
  {
    servoController.setPWM(1, 0, i);
    i = i + 5;
    delay(5);
  }

}

void giraCapDreta()
{
  int i = posIniServo1;
  while (i > 130)
  {
    servoController.setPWM(1, 0, i);
    i = i - 5;
    delay(5);
  }

}

void centraCap()
{
  servoController.setPWM(1, 0, posIniServo1);
}

void menejaCap ()
{
  int i = posIniServo1;
  while (i < 490)
  {
    servoController.setPWM(1, 0, i);
    i = i + 5;
    delay(5);
  }
  while (i > 130)
  {
    servoController.setPWM(1, 0, i);
    i = i - 5;
    delay(5);
  }
  while (i < posIniServo1);
  {
    servoController.setPWM(1, 0, i);
    i = i + 5;
    delay(5);
  }
  servoController.setPWM(1, 0, posIniServo1);
}
