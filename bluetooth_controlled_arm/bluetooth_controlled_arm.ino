// Analog Potentiometer Connected A8, A10, A12, A14
// Servo Connected to 3, 7 , 11, 13 

#include <Servo.h>

#define NEWLINE Serial.println();

Servo myservo;
Servo myservo1;
Servo myservo2;
Servo myservo3; 

void read_potentiometer(void);  // function prototyping 

int val = 90, val1 = 10, val2 = 90, val3 = 0;

void setup()
{
  Serial.begin(9600);
  
  myservo.attach(13);
  myservo1.attach(11);  
  myservo2.attach(7);  
  myservo3.attach(3);  

  myservo.write(val);                  // sets the servo position according to the scaled value
  myservo1.write(val1);                  // sets the servo position according to the scaled value
  myservo2.write(val2);                  // sets the servo position according to the scaled value
  myservo3.write(val3);                  // sets the servo position according to the scaled value
    
}
  


void loop() 
{
  
}


void serialEvent() 
{
 while (Serial.available())
   {
     char x = Serial.read();
     
     switch(x)
     {
       case 'a':
            val += 1;
            break;
       case 'd': 
            val -= 1;
            break;
       case 'w':
            val1 += 1;
            break;  
       case 's':
            val1 -= 1;
            break;    
      
       case '1':
            val2 += 1;
            break;
       case '2': 
            val2 -= 1;
            break;
       case '3':
            val3 += 1;
            break;  
       case '4':
            val3, -= 1;
            break; 
                     
     }

     write_servo();
   
   }
  
}

void write_servo()
{
  
  myservo.write(val);                  // sets the servo position according to the scaled value
  myservo1.write(val1);                  // sets the servo position according to the scaled value
  myservo2.write(val2);                  // sets the servo position according to the scaled value
  myservo3.write(val3);                  // sets the servo position according to the scaled value
  delay(15);   
}
