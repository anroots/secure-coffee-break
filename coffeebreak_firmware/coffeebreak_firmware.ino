

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  
  Keyboard.print("Hello World "); 
  Keyboard.println(count);

  
  delay(5000);
}
