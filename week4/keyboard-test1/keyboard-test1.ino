int button[] = {A0, 3, 5, 7, 9, 11, 13};
int led[] = {A1, A2, 4, 6, 8, 10, 12};
int tones[] = {262,294,330,349,392};

int buzzPin = 2;

void setup(){

  Serial.begin(9600);

  //Initializing buttons
  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);
  pinMode(button[2], INPUT_PULLUP);
  pinMode(button[3], INPUT_PULLUP);
  pinMode(button[4], INPUT_PULLUP);
  pinMode(button[5], INPUT_PULLUP);
  //pinMode(button[6], INPUT_PULLUP);

  //Initializing LEDs
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);
  pinMode(led[4], OUTPUT);
 // pinMode(led[5], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<=5; i++){
    blinkLight(i);
    delay(500);  
  }
}

void blinkLight(int ledNo){

  //Turning on the LED & playing the corresponding tone
  digitalWrite(led[ledNo], HIGH);
  //Serial.println("Turning on LED...");
  Serial.println(ledNo);

  tone(buzzPin,tones[ledNo]);
  Serial.println("Playing tone...");
  Serial.println(tones[ledNo]);
}

int buttonPressed(){
  
}

void switchOff(){
  
  //Switching off all LEDs. Not sure if this function is needed though
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], LOW);
  digitalWrite(led[5], LOW);
}
