/*
 * CARTROTECH  (https://cartrotech.wordpress.com)
 * 
 * Projecte nº: P03
 * Data: 22/10/2022
 * Descripcio: Robot quadruped
 * Nota:
 * 
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
int posIniServo3 = 150;
int posIniServo4 = 275;
int posIniServo5 = 450;
int posIniServo6 = 275;
int posIniServo7 = 200;
int posIniServo8 = 275;
int posIniServo9 = 450;

// Sensor IRC
#define trigPin 11
#define echoPin 12
float Duracio = 0;
float Distancia = 0;
int angle = 90;
int sum = 0;

void setup() 
{
  
  Serial.begin(9600);
  servoController.begin();
  servoController.setPWMFreq(frequency );
  
}

void loop() 
{
  posIni();
  avant(1);
  buscaObstacle();

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
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  Duracio = pulseIn(echoPin,HIGH);
  
  if(Duracio>0)
  {
    Distancia = Duracio*340*100/2/1000000;

    if(Distancia<10)
    {
      int dreta = 0;
      int esquerra = 0;
      int sumdreta = 0;
      int sumesquerra = 0;
      
      int i = ServoMinTicks + 10;
      delay(10);
      while(i<=250)
      {
        servoController.setPWM(1, 0, i);
        i=i+20;
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
        Duracio = pulseIn(echoPin,HIGH);
        
        if (Distancia < 15)
        {
          esquerra = 1;
          sumesquerra++;
        }
        else
        {
          esquerra = 0;
        }
        delay(10);
      }

      i = ServoMaxTicks - 10;
      delay(10);
      while(i>=310)
      {
        servoController.setPWM(1, 0, i);
        i=i-20;
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
        Duracio = pulseIn(echoPin,HIGH);
        
        if (Distancia < 15)
        {
          dreta = 1;
          sumdreta++;
        }
        else
        {
          dreta = 0;
        }
        delay(10);
      }

      servoController.setPWM(1, 0, posIniServo1);
      delay(10);

      if (sumdreta > sumesquerra)
      {
        giraEsquerra(3);
      }
      else
      {
        giraDreta(3);
      }

      if (sumdreta >= 20)
      {
        enrere(3);
        giraEsquerra(3);
      }
      else if (sumesquerra >= 20)
      {
        enrere(3);
        giraDreta(3);
      }
    }
  }
  delay(10);
}

void giraDreta (unsigned int passos)
{

}

void giraEsquerra (unsigned int passos)
{

}

void avant (unsigned int passos)
{
  while (passos-- > 0)
  {
    servoController.setPWM(3, 0, posIniServo3+67);
    servoController.setPWM(7, 0, posIniServo7+67);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2+67);
    servoController.setPWM(8, 0, posIniServo8-67);
    servoController.setPWM(4, 0, posIniServo4);
    servoController.setPWM(6, 0, posIniServo6);
    delay(100);
    servoController.setPWM(3, 0, posIniServo3);
    servoController.setPWM(7, 0, posIniServo7);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5-67);
    servoController.setPWM(9, 0, posIniServo9-67);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2);
    servoController.setPWM(8, 0, posIniServo8);
    servoController.setPWM(4, 0, posIniServo4-67);
    servoController.setPWM(6, 0, posIniServo6+67);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5);
    servoController.setPWM(9, 0, posIniServo9);
  }
}

void enrere (unsigned int passos)
{
  while (passos-- > 0)
  {
    servoController.setPWM(3, 0, posIniServo3+67);
    servoController.setPWM(7, 0, posIniServo7+67);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2);
    servoController.setPWM(8, 0, posIniServo8);
    servoController.setPWM(4, 0, posIniServo4-67);
    servoController.setPWM(6, 0, posIniServo6+67);
    delay(100);
    servoController.setPWM(3, 0, posIniServo3);
    servoController.setPWM(7, 0, posIniServo7);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5-67);
    servoController.setPWM(9, 0, posIniServo9-67);
    delay(100);
    servoController.setPWM(2, 0, posIniServo2+67);
    servoController.setPWM(8, 0, posIniServo8-67);
    servoController.setPWM(4, 0, posIniServo4);
    servoController.setPWM(6, 0, posIniServo6);
    delay(100);
    servoController.setPWM(5, 0, posIniServo5);
    servoController.setPWM(9, 0, posIniServo9);
  }
}
