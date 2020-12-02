#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
int joyX = 0;
int joyY = 1;

int servoVal;

void setup()
{

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo1.write(50);
  servo2.write(100);
  servo3.write(100);
  Serial.begin(9600);
}

void loop()
{
  
  if (Serial.available() > 0)
  {
    char data = Serial.read(); // reading the data received from the bluetooth module
    switch (data)
    {
      case 'h':
        {
          for (int i = 240; i >= 80; i--)
          {

            servo3.write(i);// when h is pressed on the app on your smart phone
          }
          break;
        }
      case 'd':
        {
          for (int i = 80; i <= 240; i++)
          {

            servo3.write(i);// when d is pressed on the app on your smart phone
          }
          break;
        }

      default : break;
    }
    Serial.println(data);
  }
  delay(50);
  servoVal = analogRead(joyX);
  servoVal = map(servoVal, 0, 1023, 50, 180);
  servo1.write(servoVal);

  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 1023, 50, 150);
  servo2 .write(servoVal);
  delay(0);
}