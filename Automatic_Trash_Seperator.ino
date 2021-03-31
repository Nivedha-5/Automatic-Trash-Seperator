// Include Libraries
#include "Arduino.h"
#include "Button.h"
// Pin Definitions
#define REFLECTIVEIR_PIN_COLL  A3
#define REFLECTIVEIR_PIN_COLL_M  A5
// object initialization
Button ReflectiveIR(REFLECTIVEIR_PIN_COLL);
Button ReflectiveIR_M(REFLECTIVEIR_PIN_COLL_M);
// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

#include <Servo.h>
#define redpin 5
#define bluepin 6
#define greenpin 7
#define redpin_M 8
#define bluepin_M 9
#define greenpin_M 10
int plasticsensor=A0;
int anothersensor=A2;
int metalsensor=A4;
int metalsensor_M=A6;

Servo myservo;  // create servo object to control a servo
Servo myservo_M;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 165;    // variable to store the servo position
int pos_M = 158;    // variable to store the servo position

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo_M.attach(12);  // attaches the servo on pin 9 to the servo object
  pinMode(redpin,OUTPUT);
  pinMode(bluepin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  //metal sensor
   pinMode(redpin_M,OUTPUT);
  pinMode(bluepin_M,OUTPUT);
  pinMode(greenpin_M,OUTPUT);
  
  pinMode(plasticsensor,INPUT_PULLUP);
  pinMode(metalsensor,INPUT_PULLUP);
  pinMode(anothersensor,INPUT_PULLUP);
  pinMode(metalsensor_M,INPUT_PULLUP);
  Serial.begin(9600);
  analogWrite(redpin,255);
  analogWrite(bluepin,0255);
  analogWrite(greenpin,255);
  analogWrite(redpin_M,255);
  analogWrite(bluepin_M,0255);
  analogWrite(greenpin_M,255);
  ReflectiveIR.init();
  ReflectiveIR_M.init();
}

void loop() {

  int sensor_read=digitalRead(plasticsensor);
  int sensor_read_m=digitalRead(metalsensor);
  int sensor_read_mm=digitalRead(metalsensor_M);
   Serial.println("plastic sensor");
  Serial.println(sensor_read);
  Serial.println("metal sensor");
  Serial.println(sensor_read_m);
  Serial.println(sensor_read_mm);

 bool ReflectiveIR_Val = ReflectiveIR.read();
 bool ReflectiveIR_Val_M = ReflectiveIR_M.read();
 //Plastic bin
  if((sensor_read==0)&&(sensor_read_m!=1)){
    for (pos = 160; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
     }
     analogWrite(redpin,255);
     analogWrite(bluepin,0);
      analogWrite(greenpin,255);
      delay(2500);
      for (pos = 90; pos <= 160; pos += 1) { // goes from 180 degrees to 0 degrees
       myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(1);                       // waits 15ms for the servo to reach the position
    
         }
     analogWrite(redpin,0);
     analogWrite(bluepin,0);
      analogWrite(greenpin,0);

    }

    else if(ReflectiveIR_Val==1){ //checking the volume of the trash
     analogWrite(redpin,0);
    analogWrite(bluepin,255);
    analogWrite(greenpin,255);
    
    }

    else{
      // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
    
    
    analogWrite(redpin,255);
    analogWrite(bluepin,255);
    analogWrite(greenpin,255);
    
    }

//metal sensor

      if(sensor_read_mm==1){
  for (pos_M = 160; pos_M >= 90; pos_M -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo_M.write(pos_M);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
     }
     analogWrite(redpin_M,255);
     analogWrite(bluepin_M,0);
     analogWrite(greenpin_M,255);
      delay(2500);
     for (pos_M = 90; pos_M <= 160; pos_M += 1) { // goes from 180 degrees to 0 degrees
    myservo_M.write(pos_M);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
    
     }
      analogWrite(redpin_M,0);
      analogWrite(bluepin_M,0);
  analogWrite(greenpin_M,0);

  }

  else if(ReflectiveIR_Val_M==1){
     analogWrite(redpin_M,0);
    analogWrite(bluepin_M,255);
    analogWrite(greenpin_M,255);
    
    }

  else{
      // goes from 180 degrees to 0 degrees
    myservo_M.write(pos_M);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
    
    
    analogWrite(redpin_M,255);
    analogWrite(bluepin_M,255);
    analogWrite(greenpin_M,255);
    
    }
  

}
