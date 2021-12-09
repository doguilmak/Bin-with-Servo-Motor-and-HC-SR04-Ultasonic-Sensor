#include <Servo.h>

Servo motor; 

#define echo 5
#define trig 6

void setup() {
	
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  motor.attach(8); 
  Serial.begin(9600);
  
}

void loop() {
	
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  
  float time = pulseIn(echo, HIGH);
  float cm = time/58.2;
  delay(250);

  if (cm < 10){
    motor.write(90);
    delay(5000);
    motor.write(0);
  }
  
}
