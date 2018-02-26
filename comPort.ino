#include<AFMotor.h>
AF_DCMotor right_motor(1,MOTOR12_8KHZ);
AF_DCMotor left_motor(2,MOTOR12_8KHZ);

int val = 0;
int ledpin = 13;
int del = 0;

void setup()
{
//pinMode(ledpin, OUTPUT);

  Serial.begin(9600);

  right_motor.setSpeed(250);
  left_motor.setSpeed(250);
  Serial.println("Starting...");
}

void loop() {

  if ( Serial.available() ) {
           // read it and store it in 'val'
   val = Serial.read(); 
  }
      Serial.println(val);

  if (val == 0 || val == 48)

  {
    Serial.println("STOP");
    right_motor.run(RELEASE);
    left_motor.run(RELEASE);
    delay(del);
  }

  if (val == 1 || val == 49)

  {
    digitalWrite(ledpin, LOW);
    right_motor.run(FORWARD);
    left_motor.run(FORWARD);
    Serial.println("1 off");
    delay(del);
  }

  if (val == 2 || val == 50)
  {
    digitalWrite(ledpin, HIGH);
    right_motor.run(BACKWARD);
    left_motor.run(BACKWARD);
    Serial.println("2 on");
    delay(del);
  }

  if (val == 3 || val == 51)
  {
    digitalWrite(ledpin, LOW);
    right_motor.run(FORWARD);
    left_motor.run(BACKWARD);
    Serial.println("3 off");
    delay(del);
  }

  if (val == 4 || val == 52)
  {
    digitalWrite(ledpin, HIGH);
    right_motor.run(BACKWARD);
    left_motor.run(FORWARD);
    Serial.println("4 on");
    delay(del);
  }
}

