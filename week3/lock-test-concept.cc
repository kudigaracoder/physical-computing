void loop () {
    Serial.println("Running main loop...");
    
    // Checking for reset button being pressed 
    int ResetCount;
    Serial.println("Checking Reset Button Count...")
    ResetCount = getButtonCount();
        
    if (ResetCount == 2) {
        Serial.println("Resetting Button Combination");
        buttonCombination = 0;
        Serial.println("Calling resetCombination...");
        // resetCombination();
    } else {
        Serial.println("Calling verifyCombination...");
        // verifyCombination();
    }
}

 getButtonCount () {
     Serial.println("Running getButtonCount...");
     int buttonState;
     int lastButtonState;
     int buttonCount;
    
     Serial.println("Checking Button State...")
     if (buttonState != lastButtonState) {
         if (buttonState == HIGH) {
            buttonCount++;
            Serial.println("No of button pushes:");
            Serial.println(buttonCount);
        }
        delay(100);
    }
    lastButtonState = buttonState;
    return buttonCount;
}

void ResetCombination() {
    Serial.println("Running resetCombination...");
    
    // Setting the buttonCount for all buttons
    int RbuttonCount = 0;
    int GbuttonCount = 0;
    int BbuttonCount = 0;
    
    // Setting the initial state of buttons
    int RButtonState = 0;
    int GButtonState = 0;
    int BButtonState = 0;

    // Setting lastButtonStates for all buttons
    int RlastButtonState = 0;
    int GlastButtonState = 0;
    int BlastButtonState = 0;
    
    RButtonState = digitalRead(RedButton);
    GButtonState = digitalRead(GreenButton);
    BButtonState = digitalRead(BlueButton);
    
    getButtonCount();
    RbuttonCount = GbuttonCount = BbuttonCount = 0;
    Serial.println("Resetting button counts");
}

void verifyCombination() {
    Serial.println("Running verifyCombination...");
    if (RbuttonCount + GbuttonCount + BbuttonCount == 24) {
    glowLED();
    delay (2000);
    dimLED();
}

glowLED() {
    Serial.println("Running glowLED...");
    digitalWrite(Rled, HIGH);
    Serial.println("RED On");
    digitalWrite(Gled, HIGH);
    Serial.println("GREEN On");
    digitalWrite(Bled, HIGH);
    Serial.println("BLUE On");
}

dimLED() {
    Serial.println("Running dimLED...");
    digitalWrite (Rled, LOW);
    digitalWrite (Gled, LOW);
    digitalWrite (Bled, LOW);
}