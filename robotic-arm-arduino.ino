#include <SoftwareSerial.h>
#include <Servo.h>

#define SERVO_01 6 //Servo base
#define SERVO_02 10 //Braço principal
#define SERVO_03 3 //Articulação secundária
#define SERVO_04 11 //Garra

Servo s_base, s_arm, s_secartic, s_hand;

int pos = 0;

SoftwareSerial BTserial(2, 4);

char data = "s";

void setup() 
{
  s_base.attach(SERVO_01);
  s_arm.attach(SERVO_02);
  s_secartic.attach(SERVO_03);
  s_hand.attach(SERVO_04);
  
  Serial.begin(9600);

  //Necessário Inicializar a posição inicial de cada servo
  s_base.write(100); // intervalo 0 a 180 
  s_arm.write(175); // intervalo 125 a 175
  s_secartic.write(30); // intervalo 0 a 30 
  s_hand.write(90); // intervalo entre 60 a 90
  
  BTserial.begin(38400);
  
}

void loop() 
{
   
    //data = BTserial.read();
    if (data=="OC")
     s_hand.write(90);
   
}
