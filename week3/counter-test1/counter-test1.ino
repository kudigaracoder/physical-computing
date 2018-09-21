const int ledPin = 8;
const int buttonPin = 2;

int buttonState = 0;
int buttonCount = 0;
int lastButtonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonCount++;
      Serial.println("ON");
      Serial.println("No of Button pushes:");
      Serial.print(buttonCount);
    } else {
      Serial.println("OFF");
    }
    delay (100);  
  }
  lastButtonState = buttonState;

  if (buttonCount % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
