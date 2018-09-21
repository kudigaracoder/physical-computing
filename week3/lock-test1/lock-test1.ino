
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

  // Checking RED BUTTON state & taking action
  if (RButtonState == HIGH) {
    // turning RED LED ON:
    digitalWrite(Rled, HIGH);
  } else {
    digitalWrite (Rled, LOW);
  }

  // Checking GREEN BUTTON state & taking action
  if (GButtonState == HIGH) {
    // turning GREEN LED ON:
    digitalWrite(Gled, HIGH);
  } else {
    digitalWrite (Gled, LOW);
  }

  // Checking RED BUTTON state & taking action
  if (BButtonState == HIGH) {
    // turning BLUE LED ON:
    digitalWrite(Bled, HIGH);
  } else {
    digitalWrite (Bled, LOW);
  }
  
}
