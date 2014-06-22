const byte buzzerPin = A9; // Pin 12
const byte successFreq = 32767; 
const byte failureFreq = 1397;


void setupBuzzer() {
  pinMode(buzzerPin, OUTPUT);  
}

void buzzSuccess() {

/*    analogWrite(buzzerPin,50);
    delay(200);
    digitalWrite(buzzerPin,LOW);
return;*/
  
  tone(buzzerPin, successFreq, 200);
}

void buzzFailure() {
  tone(buzzerPin, failureFreq, 120);
  delay(250);
  tone(buzzerPin, failureFreq, 150);  
}
