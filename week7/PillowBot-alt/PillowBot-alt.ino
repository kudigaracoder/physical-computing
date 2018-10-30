
#include <SPI.h>
#include <CapacitiveSensor.h>

unsigned long timer;
bool pressed = false;
int threshold = 10000; // this value might change depending on the amount of alluminium foil used
int heart_beat = -1;
int Buzzer = 8; // Pin attached to the buzzer

CapacitiveSensor cloth = CapacitiveSensor(5, 4);       // 10M resistor between pins 5 & 4, pin 4 is sensor pin, add a wire and or foil if desired

void setup() {
  Serial.begin(115200);
  cloth.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {

  long start = millis();
  long sensor_value =  cloth.capacitiveSensor(30);

  //   Uncomment this line to debug and calibrate the threshold
  Serial.println(sensor_value);

  if (sensor_value > threshold && !pressed) {
    pressed = true;
  }
  else if (sensor_value > threshold && pressed) {
    HeartBeat();
    heart_beat += 1;
  }
  else if (sensor_value < threshold && pressed) {
    pressed = false;
    Serial.print(heart_beat);
    Serial.println(" heart beats");
    heart_beat = -1;
  }
}

void HeartBeat() {
  tone(Buzzer, 31, 200); // tone(Pin, Note, Duration);
  delay(200);
  tone(Buzzer, 31, 400);
  delay(200);
  noTone(Buzzer);
  delay(1000);
}
