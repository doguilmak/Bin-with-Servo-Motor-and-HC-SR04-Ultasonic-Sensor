
# Bin with Servo Motor and HC-SR04 Ultasonic Sensor

## Statement

The aim of this project is to develop a prototype that opens the trash can lid contactlessly using various tools. Detailed explanations are explained in order. The program was simulated through the Tinkercad program and then applied in practice. 

## Materials

 - 1 Arduino UNO
 - 1 USB 2.0 to USB B Cable
 - 4 Male to Female Jumper Cable
 - 4 Female to Female Jumper Cable (Optional, depends on distance between Arduino to bin!)
 - 1 Servomotor
 - 1 HC-SR06 Distance Sensor
 - 1 Bin
 - 1 Stick or piece of wood (for Servomotor)

## Building Prototype

The following simulation was created via Tinkercad.

<p align="center">
    <img src="bin_servo.jpg"> 
</p>

After the model is created, there is the coding part next.

Pin numbers and libraries are specified:

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

Within a quarter of a second, the ultrasonic sensor scanned whether there was any object close to the sensor. This sensor reads from 2cm to 400cm (0.8inch to 157inch) with an accuracy of 0.3cm (0.1inches), which is good for most hobbyist projects. The distance (in cm) was calculated according to the sound velocity and the distance was calculated over the time variable.

    digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(2);
	digitalWrite(trig, LOW);
	  
	float time = pulseIn(echo, HIGH);
	float cm = time/58.2;
	delay(250);

If the object brought closer to the ultrasonic sensor is closer than 10 centimeters, the motor will move at an angle of 90 degrees. Then it will wait for 5 seconds and the servo motor will return to its original state.

      if (cm < 10){
        motor.write(90);
        delay(5000);
        motor.write(0);
      }

![vid_](bin_servo.gif)

## Contact Me

If you have something to say to me please contact me: 

 - Twitter: [Doguilmak](https://twitter.com/Doguilmak) 
 - Mail address: doguilmak@gmail.com
 