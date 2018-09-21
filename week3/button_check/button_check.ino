int switchPosA = 10;
int switchPosB = 8;
int val1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(switchPosA, INPUT);
  pinMode(switchPosB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   val1 = digitalRead(switchPosB);
  Serial.print(val1);
  delay(1000);

  digitalWrite(switchPosA, LOW);
  delay(1000);
  
}
