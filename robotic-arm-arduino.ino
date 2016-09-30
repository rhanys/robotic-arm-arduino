#include <SoftwareSerial.h>
#include <Servo.h>

#define SERVO_01 6 //Servo base
#define SERVO_02 5 //Braço principal
#define SERVO_03 9 //Articulação secundária
#define SERVO_04 10 //Garra

Servo s_base, s_arm, s_secartic, s_hand;

int pos = 0;

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
  s_base.write(0);
  s_arm.write(0);
  
  BTserial.begin(38400);
  
}

void loop() 
{
  //It will be deleted soon
  if(Serial.available() > 0)
  {
  }

  else if(BTserial.available())
  {
    data = BTserial.read();
    for(pos = 0; pos < 180; pos++)
    {
      s_base.write(pos);
      delay(100);
    }
    delay(1000);  for(pos = 180; pos >= 0; pos--)
    {
      s_base.write(pos);
      delay(100);
    }
    delay(1000);
  }
}
