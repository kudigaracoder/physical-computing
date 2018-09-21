
// Assigning the buttons
const int RedButton = 2;
const int GreenButton = 4;
const int BlueButton = 6;

// Assigning the LEDs
const int Rled = 8;
const int Gled = 10;
const int Bled = 12;

// Setting the initial state of buttons
int RButtonState = 0;
int GButtonState = 0;
int BButtonState = 0;

// Setting the buttonCount for all buttons
int RbuttonCount = 0;
int GbuttonCount = 0;
int BbuttonCount = 0;

// Setting lastButtonStates for all buttons
int RlastButtonState = 0;
int GlastButtonState = 0;
int BlastButtonState = 0;

void setup() {
  // Setting up the LEDs
  pinMode(Rled, OUTPUT);
  pinMode(Gled, OUTPUT);
  pinMode(Bled, OUTPUT);

  // Setting up the buttons
  pinMode(RedButton, INPUT);
  pinMode(GreenButton, INPUT);
  pinMode(BlueButton, INPUT);

  Serial.begin(9600);
}

void loop() {
  
  // Getting the Red Button State
  RButtonState = digitalRead(RedButton);
  GButtonState = digitalRead(GreenButton);
  BButtonState = digitalRead(BlueButton);

  if (RButtonState != RlastButtonState) {
    if (RButtonState == HIGH) {
      RbuttonCount++;
      Serial.println("Red ON");
      Serial.println("No of Red button pushes:");
      Serial.println(RbuttonCount);
    }
    delay (100);
  }
  RlastButtonState = RButtonState;

  if (GButtonState != GlastButtonState) {
    if (GButtonState == HIGH) {
      GbuttonCount++;
      Serial.println("Green ON");
      Serial.println("No of Green button pushes:");
      Serial.println(GbuttonCount);
    }
    delay (100);
  }
  GlastButtonState = GButtonState;

  if (BButtonState != BlastButtonState) {
    if (BButtonState == HIGH) {
      BbuttonCount++;
      Serial.println("Blue ON");
      Serial.println("No of Blue button pushes:");
      Serial.println(BbuttonCount);
    }
    delay (100);
  }
  BlastButtonState = BButtonState;

  if (RbuttonCount % 7 == 0 && GbuttonCount % 4 == 0 && BbuttonCount % 6 == 0) {
    digitalWrite(Rled, HIGH);
    digitalWrite(Gled, HIGH);
    digitalWrite(Bled, HIGH);
    } else {
    digitalWrite (Rled, LOW);
    digitalWrite (Gled, LOW);
    digitalWrite (Bled, LOW);
  }
}
