const int ResetButton = 7;
const int ledPin = 5;

int buttonCount = 0;

void setup () {
    Serial.begin (9600);
    pinMode (ledPin, OUTPUT);
    pinMode (ResetButton, INPUT);
}

void loop () {
    Serial.println("Running main loop...");
    
    // Checking for reset button being pressed 
    int ResetCount = 0;
    int buttonCombination;
    Serial.println("Checking Reset Button Count...");
    ResetCount = getButtonCount();

    Serial.println("Printing ResetCount...");
    Serial.println(ResetCount);
    
    if (ResetCount == 2) {
        Serial.println("Resetting Button Combination");
        buttonCombination = 0;

        Serial.println("Lighting LED...");
        digitalWrite(ledPin, HIGH);

        delay (100);
        digitalWrite(ledPin, LOW);        
        Serial.println("Calling resetCombination...");
        // resetCombination();
    } else {
        Serial.println("Dimming LED...");
        digitalWrite(ledPin, LOW);
    }
}

int getButtonCount() {
     Serial.println("Running getButtonCount...");
     int buttonState;
     int lastButtonState = 0;
     
     Serial.println("Reading Reset Button State...");
     buttonState = digitalRead(ResetButton);

     Serial.println("Printing buttonState");
     Serial.println(buttonState);
     
     Serial.println("Checking Button State...");
     if (buttonState != lastButtonState) {
         if (buttonState == HIGH) {
            buttonCount++;
            Serial.println("No of button pushes:");
            Serial.println(buttonCount);
        }
        delay(200);
    }
    lastButtonState = buttonState;
    return buttonCount;
}
