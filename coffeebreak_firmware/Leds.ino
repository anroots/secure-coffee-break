
const byte redLedPin = A6; // Pin 15
const byte greenLedPin = A7; // Pin 14
const byte powerLedPin = 11; // Buikt-in LED, TODO



unsigned long greenLedPowerOffTime = 0;
unsigned long redLedPowerOffTime = 0;


void setupLeds() {
   pinMode(powerLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  digitalWrite(powerLedPin, HIGH);
  redLedOff();
  greenLedOff();
}

void manageLeds() {
  
  if (greenLedPowerOffTime == 0 && redLedPowerOffTime == 0) {
    return;
  }
  
  if (greenLedPowerOffTime < millis()) {
    greenLedPowerOffTime = 0;
    greenLedOff();
  }

  if (redLedPowerOffTime < millis()) {
    redLedPowerOffTime = 0;
    redLedOff();

  }
  
}

void greenLedOn(){
  digitalWrite(greenLedPin, HIGH); 
}

void greenLedOff(){
  digitalWrite(greenLedPin, LOW); 
}

void redLedOn() {
  digitalWrite(redLedPin, HIGH); 
}

void redLedOff() {
  digitalWrite(redLedPin, LOW);
}

void greenLedOn(int milliSeconds) {
  greenLedOn();
  greenLedPowerOffTime = millis() + milliSeconds;
}

void redLedOn(int milliSeconds) {
  redLedOn();
  redLedPowerOffTime = millis() + milliSeconds;
}
