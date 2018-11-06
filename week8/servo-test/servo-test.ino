#include <Servo.h>

int servoPosition;

const int triggerPin = 11;
const int echoPin = 12;
float distance = 0;

Servo myservo;


void setup() {
  Serial.begin (9600);

  pinMode(triggerPin, OUTPUT); //Acts as output
  pinMode(echoPin, INPUT); //Measures the duration of pulses coming back
  myservo.attach(9);

}

void loop() {
  //Getting distance from the sensor
  distance = getDistance();
  Serial.println(distance);
  
  servoPosition = map(distance, 0, 1023, 20, 160);
  myservo.write(servoPosition);

}

float getDistance()
{
  //variable to store the time it takes for a ping to bounce off an object
  float echoTime;
  //variable to store the distance calculated from the echo time
  float calcualtedDistance;
  
  //Ultrasonic pulse for 15ms duration?
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(15); 
  digitalWrite(triggerPin, LOW);

  //use the pulsein command to see how long it takes for the
  echoTime = pulseIn(echoPin, HIGH);

  //pulse to bounce back to the sensor
  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
  calcualtedDistance = echoTime / 148.0;

  //send back the distance that was calculated
  return calcualtedDistance;
}
