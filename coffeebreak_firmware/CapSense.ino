const byte sendPin = 7;
const byte receivePin = A5; // Pin 16
const long capSensorActiveThreshold = 1500; // Arbitrary units
CapacitiveSensor capSensor = CapacitiveSensor(sendPin, receivePin);

boolean isCapSensorActive() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  return sensorValue >= capSensorActiveThreshold;
}
