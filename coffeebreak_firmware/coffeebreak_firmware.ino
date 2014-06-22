
#include <Bounce.h>
#include <CapacitiveSensor.h>

Bounce button = Bounce(10, 10);

const String UNLOCK_CODE = "SecretPassword";



void setup() {

  setupLeds();
  setupBuzzer();

  pinMode(10, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  manageLeds();

  if (isCapSensorActive()) {
    lock();
  }
  
  button.update();
  if (button.fallingEdge()) {

    boolean validUID = (boolean)random(0,2);

    if (validUID) {
      unlock();
    } 
    else {
      invalidUID();
    }
  }
  delay(100);
}

void invalidUID() {
  redLedOn(2000);
  buzzFailure();
  Serial.println("INVALID");
}

void unlock(){
  greenLedOn(2000);

  buzzSuccess();
  //Keyboard.print(UNLOCK_CODE); 
  Serial.println(UNLOCK_CODE);
  delay(1000);
}

void lock() {
  greenLedOn(2000);
  buzzSuccess();
  Serial.println("LOCK");
  delay(1000);
}

