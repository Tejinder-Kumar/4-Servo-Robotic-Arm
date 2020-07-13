// Analog Potentiometer Connected A8, A10, A12, A14
// Servo Connected to 3, 7 , 11, 13 

#include <Servo.h>
#define POT1 A8
#define POT2 A10
#define POT3 A12
#define POT4 A14
#define NEWLINE Serial.println();

Servo myservo;
Servo myservo1;
Servo myservo2;
Servo myservo3; 

void read_potentiometer(void);  // function prototyping 

int val, val1, val2, val3;

void setup()
{
  Serial.begin(9600);
  Serial.print("Hello Welcome to Robotic Arm Control Using Potentiometer ");
  
  myservo.attach(13);
  myservo1.attach(11);  
  myservo2.attach(7);  
  myservo3.attach(3);  
    
}
  


void loop() 
{
  read_potentiometer();  
}


void read_potentiometer()
{
  val  = analogRead(POT1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = analogRead(POT2);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = analogRead(POT3);            // reads the value of the potentiometer (value between 0 and 1023)
  val3 = analogRead(POT4);            // reads the value of the potentiometer (value between 0 and 1023)
  
   val = map(val, 0, 1023, 10, 170);     // scale it to use it with the servo (value between 0 and 180)
  val1 = map(val1, 0, 1023, 10, 170);     // scale it to use it with the servo (value between 0 and 180)
  val2 = map(val2, 0, 1023, 10, 170);     // scale it to use it with the servo (value between 0 and 180)
  val3 = map(val3, 0, 1023, 3, 178);     // scale it to use it with the servo (value between 0 and 180)
  
  myservo.write(val);                  // sets the servo position according to the scaled value
  myservo1.write(val1);                  // sets the servo position according to the scaled value
  myservo2.write(val2);                  // sets the servo position according to the scaled value
  myservo3.write(val3);                  // sets the servo position according to the scaled value
  delay(15);   
}
