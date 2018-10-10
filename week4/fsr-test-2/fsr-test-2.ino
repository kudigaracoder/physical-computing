/*
  Keyboard

  Plays a pitch that changes based on a changing analog input

  circuit:
  - three force-sensing resistors from +5V to analog in 0 through 5
  - three 10 kilohm resistors from analog in 0 through 5 to ground
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone3
*/

#include <pitches.h>

int fsr_pin[] = {A0, A1, A2};

// notes to play, corresponding to the 3 sensors:
int notes[] = {440, 494, 131};

const int threshold = 100;    // minimum reading of the sensors that generates a note

int buzzPin = 8;

void setup() {
  pinMode(fsr_pin[0], INPUT);
  pinMode(fsr_pin[1], INPUT);
  pinMode(fsr_pin[2], INPUT);

  Serial.begin(9600);
}

void loop() {
  for (int fsr_pin = 0; fsr_pin < 3; fsr_pin++) {
    // get a sensor reading:
    int sensorReading = analogRead(fsr_pin);
   // delay(100);
    if (sensorReading != 0) {
      Serial.println(sensorReading);
    }

    // if the sensor is pressed hard enough:
    if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(buzzPin, notes[fsr_pin],5);
      Serial.println(notes[fsr_pin]);
    }
  }
}
