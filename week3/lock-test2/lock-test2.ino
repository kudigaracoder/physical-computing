
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
}

void loop() {
  
  // Getting the Red Button State
  RButtonState = digitalRead(RedButton);
  GButtonState = digitalRead(GreenButton);
  BButtonState = digitalRead(BlueButton);

  if (RButtonState != RlastButtonState) {
    if (RButtonState == HIGH) {
      RbuttonCount++;
    }
    delay (100);
  }
  RlastButtonState = RButtonState;

  if (RbuttonCount % 5 == 0) {
    digitalWrite(Rled, HIGH);
    } else {
    digitalWrite (Rled, LOW);
  }

  if (GButtonState != GlastButtonState) {
    if (GButtonState == HIGH) {
      GbuttonCount++;
    }
    delay (100);
  }
  GlastButtonState = GButtonState;

  if (GbuttonCount % 2 == 0) {
    digitalWrite(Gled, HIGH);
    } else {
    digitalWrite (Gled, LOW);
  }

  if (BButtonState != BlastButtonState) {
    if (BButtonState == HIGH) {
      BbuttonCount++;
    }
    delay (100);
  }
  BlastButtonState = BButtonState;

  if (BbuttonCount % 2 == 0) {
    digitalWrite(Bled, HIGH);
    } else {
    digitalWrite (Bled, LOW);
  }  
}
