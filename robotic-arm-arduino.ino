#include <SoftwareSerial.h>
#include <Servo.h>

#define SERVO_01 6 //Servo base 
#define SERVO_02 10 //Braço principal MOTOR2
#define SERVO_03 3 //Articulação secundária MOTOR3
#define SERVO_04 11 //Garra

Servo s_base, s_arm, s_secartic, s_hand;

int base = 100;
int esticador = 30;
int elevador = 175;
int pinca = 90;

SoftwareSerial BTserial(2, 4);

char *data = "";

void setup() 
{
  s_base.attach(SERVO_01);
  s_arm.attach(SERVO_02);
  s_secartic.attach(SERVO_03);
  s_hand.attach(SERVO_04);
  
  Serial.begin(9600);

  //Necessário Inicializar a posição inicial de cada servo
  s_base.write(base); // intervalo 0(esquerda) a 180(direita 
  s_arm.write(elevador); // intervalo 125(desce) a 175(sobe)
  s_secartic.write(esticador); // intervalo 0(estica) a 30(encolhe) 
  s_hand.write(pinca); // intervalo entre 60(abre) a 90(fecha)
  
  BTserial.begin(38400);
  
}

void loop() 
{
  /*Base = B1 ou B0
    2 motor = S21 ou S20
    3 motor = S31 ou S30
    Garra = CO ou CC
    OC abre a garra e CC fecha*/
   
    data = BTserial.read();
    
    if ((strcmp (data, "OC") == 0)&&(pinca != 60))
    {
     pinca = 60;
     s_hand.write(pinca);
    }
    if ((strcmp (data, "CC") == 0)&&(pinca != 90))
    {
     pinca = 90;
     s_hand.write(pinca);
    }
    if ((strcmp (data, "B1") == 0)&&(base <= 180))
    {
     base += 10;
     s_base.write(base);
    }
    if ((strcmp (data, "B1") == 0)&&(base >= 0))
    {
     base -= 10;
     s_base.write(base);
    }
    if ((strcmp (data, "S21") == 0)&& (elevador <= 175))
    {
     elevador += 10;
     s_arm.write(elevador);
    }
    if ((strcmp (data, "S20") == 0)&& (elevador >= 125))
    {
     elevador -= 10;
     s_arm.write(elevador);
    }
    if ((strcmp (data, "S31") == 0)&& (esticador <= 30))
    {
     esticador += 10;
     s_secartic.write(esticador);
    }
    if ((strcmp (data, "S30") == 0)&& (esticador >= 0))
    {
     esticador -= 10;
     s_secartic.write(esticador);
    }
}
