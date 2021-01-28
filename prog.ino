
#include <Wire.h> 
int rxPin = 0;                    // RX PIN 
int txPin = 1;// TX TX
String d;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
unsigned int s;
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if(inches<=6){
    digitalWrite(A0,HIGH);digitalWrite(A1, HIGH);digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(A4, HIGH);delay(500);
    digitalWrite(A1, HIGH);digitalWrite(A2, LOW);digitalWrite(A3, HIGH);digitalWrite(A4, LOW);delay(3000);//obstacle backward
    }
   else {digitalWrite(A0,LOW);
   if(s==1){digitalWrite(A1, LOW);digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(A4, LOW);}
   if(s==2){digitalWrite(A1, HIGH);digitalWrite(A2, LOW);digitalWrite(A3, LOW);digitalWrite(A4, HIGH);}
   if(s==3){digitalWrite(A1, LOW);digitalWrite(A2, HIGH);digitalWrite(A3, LOW);digitalWrite(A4, HIGH);}
   if(s==4){digitalWrite(A1, HIGH);digitalWrite(A2, LOW);digitalWrite(A3, HIGH);digitalWrite(A4, LOW);}
   if(s==0){digitalWrite(A1, HIGH);digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(A4, HIGH);}
   
   }
  
  

  while(Serial.available()>0){
          d=Serial.readString();
       if(d=="a" && inches>6)
       {
        s=1;
         digitalWrite(A1, LOW);digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(A4, LOW);
         
       }//LEFT
       else if(d=="b" && inches>6)
       {
        s=2;
         digitalWrite(A1, HIGH);digitalWrite(A2, LOW);digitalWrite(A3, LOW);digitalWrite(A4, HIGH);
         
       }//RIGHT
       else if(d=="c" && inches>6)
       {
        s=3;
         digitalWrite(A1, LOW);digitalWrite(A2, HIGH);digitalWrite(A3, LOW);digitalWrite(A4, HIGH);
         
       }//FRONT
       else if(d=="d" && inches>6)
       {
        s=4;
         digitalWrite(A1, HIGH);digitalWrite(A2, LOW);digitalWrite(A3, HIGH);digitalWrite(A4, LOW);
         
       }//BACK
       else
       {
        s=0;
        digitalWrite(A1, HIGH);digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(A4, HIGH);
        }
  }
//

}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
