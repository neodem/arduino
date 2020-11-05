void ringOutPins() {

  int delayMs = 1000;

  Serial.println("ringing out input pins...");

  Serial.println("toggling A");
  writePin(aPin, 1);
  delay(delayMs);
  writePin(aPin, 0);
  delay(delayMs);

  Serial.println("toggling B");
  writePin(bPin, 1);
  delay(delayMs);
  writePin(bPin, 0);
  delay(delayMs);

  Serial.println("ringing out control pins...");
  Serial.println("toggling s0");
  writePin(s0Pin, 1);
  delay(delayMs);
  writePin(s0Pin, 0);
  delay(delayMs);
  Serial.println("toggling s1");
  writePin(s1Pin, 1);
  delay(delayMs);
  writePin(s1Pin, 0);
  delay(delayMs);
  Serial.println("toggling binv");
  writePin(binvPin, 1);
  delay(delayMs);
  writePin(binvPin, 0);
  delay(delayMs);
  Serial.println("toggling cin");
  writePin(cinPin, 1);
  delay(delayMs);
  writePin(cinPin, 0);
  delay(delayMs);
}
