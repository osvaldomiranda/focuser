// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(200, 1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  motor.setSpeed(20);  // 10 rpm   
}

void loop() {

  if(Serial.available() > 0) {
    char data = Serial.read();
    char str[2];
    str[0] = data;
    str[1] = '\0';
    Serial.print(str);

    if(str[0]=='a'){
      Serial.println("Micrsostep steps");
      motor.step(200, FORWARD, MICROSTEP); 
    }
    if(str[0]=='r'){
      Serial.println("Micrsostep steps");
      motor.step(200, BACKWARD, MICROSTEP); 
    }
  }
}
