void ringOutPins() {

  int delayMs = 1000;

  Serial.println("ringing out input pins...");
  for (byte biti = 0; biti < 4; biti = biti + 1) {
    Serial.print("ringing out input pins for board/bit ");
    Serial.println(biti);

    Serial.println("toggling A");
    writeBit(inputAPins[biti], 1);
    delay(delayMs);
    writeBit(inputAPins[biti], 0);
    delay(delayMs);

    Serial.println("toggling B");
    writeBit(inputBPins[biti], 1);
    delay(delayMs);
    writeBit(inputBPins[biti], 0);
    delay(delayMs);
  }

  Serial.println("ringing out control pins...");
  Serial.println("toggling s0");
  writeBit(controlPins[0], 1);
  delay(delayMs);
  writeBit(controlPins[0], 0);
  delay(delayMs);
  Serial.println("toggling s1");
  writeBit(controlPins[1], 1);
  delay(delayMs);
  writeBit(controlPins[1], 0);
  delay(delayMs);
  Serial.println("toggling binv");
  writeBit(controlPins[2], 1);
  delay(delayMs);
  writeBit(controlPins[2], 0);
  delay(delayMs);
  Serial.println("toggling cin");
  writeBit(controlPins[3], 1);
  delay(delayMs);
  writeBit(controlPins[3], 0);
  delay(delayMs);
}
