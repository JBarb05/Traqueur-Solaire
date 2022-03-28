#include <Servo.h>
#include "Stepper_28BYJ_48.h"
#define Seuil_jour 500
#define ecart 15


Stepper_28BYJ_48 stepper(11,10,9,8);
Servo myservo;
int pos = 90;   // initial position
int sens1 = A1; // photoresistor 1 pin
int sens2 = A0; //photoresistor 2 pin
int tolerance = 2;



void setup()
{
  Serial.begin(9600);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  pinMode(sens1, INPUT);
  pinMode(sens2, INPUT);
  myservo.write(pos);
  delay(2000); // a 2 seconds delay while we position the solar panel
}  
 
void loop()
{
  int val1 = analogRead(sens1); // read the value of sensor 1
  int val2 = analogRead(sens2); // read the value of sensor 2
 
  if((abs(val1 - val2) <= ecart) || (abs(val2 - val1) <= ecart)) {
    //do nothing if the difference between values is within the tolerance limit
  } else {    
    if(val1 > val2)
    {
      pos = --pos;
    }wx
    if(val1 < val2)
    {
      pos = ++pos;
    }
  }
 
       if(digitalRead(val1-val2>ecart) == LOW){
                stepper.step(-5);
         }
         
       if(digitalRead(val2-val1>ecart) == HIGH)  {
                stepper.step(5);
  }
 
  if(pos > 170) { pos = 170; } // reset to 180 if it goes higher
  if(pos < 0) { pos = 0; } // reset to 0 if it goes lower

  myservo.write(pos); // write the position to servo
  Serial.print("Val1:");Serial.print(val1); Serial.print("  Val2:"); Serial.print(val2);Serial.print("  écart:");Serial.println(val2 - val1);
  delay(500);
} 
